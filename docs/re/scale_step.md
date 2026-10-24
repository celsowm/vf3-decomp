# The motion VM's step (SH-4 0x8C0CB8AC)

A readable port of the fight engine's motion-VM step, and the evidence for it.

## The function

`0x8C0CB8AC` is one step of the motion VM. The VM keeps a mode byte, a step
count and two float constants; when the mode says "step", the function scales
the two constants with the count and writes the result twice.

* the **mode byte** is a byte the pool points at (`0x8C0CB9B8`). Its low four
  bits are the mode, and the mode `1` asks for a step;
* the **count** is a halfword in the VM's structure: the structure's `+0x44`
  points at a word, and that word's `+0x54` holds the count. The count is
  reduced by sixty and then made positive;
* the **scale** is the count, and it is parked in **FPUL** - the guest uses the
  FPU's instruction-length register as a scratch word;
* the two **constants** are float constants in the pool, at `0x8C0CB9C0` and
  `0x8C0CB9C4`. The result is `constant_two * count + constant_one`, computed
  as a *fused* multiply-add;
* the result goes into the caller's structure at its `+16`, and into the
  structure the VM's `+0x20` points at, at the offset the pool holds at
  `0x8C0CB9B4`.

The port: `src/fight/scale_step.c`, registered in `src/fight/readable.c` as
`scale_step`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine
translation of the ROM: one label per guest PC, one C statement per executed
opcode, and the original opcode word in a comment. That makes them a faithful
disassembly of the function they implement, so a readable port can be written
against them without the ROM.

* `tools/adapter_owner.py 0x0c0cb8ac --all` - resolves which module the router
  actually serves for a PC. One module carries the copy (`motion_adapter`) and
  the chain serves it.
* `tools/adapter_dump.py 0x0c0cb8ac` - prints the generated function as guest
  disassembly. Its own decoder is crude, so the mnemonics below come from
  `tools/sh4.py`, the repo's authoritative decoder, and the semantics come
  from the translator's emitted C.

The guest code, decoded:

```
0x0c0cb8ac  d342  mov.l @(disp,pc),r3     ; the mode byte
0x0c0cb8ae  6030  mov.b @r3,r0
0x0c0cb8b0  600c  extu.b r0,r0
0x0c0cb8b2  c90f  and   #15,r0            ; the mode is four bits
0x0c0cb8b4  8801  cmp/eq #1,r0
0x0c0cb8b6  8b17  bf    0x0c0cb8e8       ; not a step: nothing happens
0x0c0cb8b8  d640  mov.l @(disp,pc),r6     ; the VM's structure
0x0c0cb8ba  e044  mov   #68,r0
0x0c0cb8bc  056e  mov.l @(r0,r6),r5       ; the word that holds the count
0x0c0cb8be  e054  mov   #84,r0
0x0c0cb8c0  055d  mov.w @(r0,r5),r5       ; the count
0x0c0cb8c2  75c4  add   #-60,r5
0x0c0cb8c4  4511  addc  r5,r0             ; T says whether it is negative
0x0c0cb8c6  8900  bt    0x0c0cb8ca
0x0c0cb8c8  655b  neg   r5,r5             ; ... so it is made positive
0x0c0cb8ca  455a  mov   r5,fpul           ; and parked in FPUL
0x0c0cb8cc  c73c  mov.l @(disp,pc),r0     ; the first constant
0x0c0cb8ce  f508  fmov.s @r0,fr5
0x0c0cb8d0  c73c  mov.l @(disp,pc),r0     ; the second constant
0x0c0cb8d2  f408  fmov.s @r0,fr4
0x0c0cb8d4  e010  mov   #16,r0
0x0c0cb8d6  f32d  fmov  r53,fr3           ; the count as a float
0x0c0cb8d8  f04c  fmov  fr4,fr0
0x0c0cb8da  f63c  fmov  fr3,fr6
0x0c0cb8dc  f56e  fmac  fr0,fr6,fr5       ; constant_two * count + constant_one
0x0c0cb8de  f45c  fmov  fr5,fr4
0x0c0cb8e0  f447  fmov.s fr4,@(r0,r4)     ; the caller's structure
0x0c0cb8e2  9067  mov.w @(disp,pc),r0     ; the offset
0x0c0cb8e4  5468  mov.l @(32,r6),r4       ; the structure the VM names
0x0c0cb8e6  f447  fmov.s fr4,@(r0,r4)
0x0c0cb8e8  000b  rts
```

Four details of that listing are worth naming, because each one is easy to lose
in a readable port:

* **the mode byte is masked to four bits before it is compared**, so the mode
  `17` is the mode `1` and the mode `9` is not.
* **the count is reduced by sixty and then made positive**, and the *positive*
  value is what FPUL gets. The T bit the sign test leaves behind is the one
  the caller sees.
* **the scale is a fused multiply-add**: `vf3_fpu_mac` rounds once, where a
  multiply and an add round twice, so the port cannot write `a * b + c` in C.
* **the count is converted to a float through FPUL**, and the guest uses the
  FPU's instruction-length register as a scratch word - the port has to do the
  same, because the register is part of the contract.

## The evidence

`tests/scale_step_replay.c` runs the readable port and the retained generated
translation of the same function over seven scenarios and compares **the
whole register file (the FP registers and SR included), the return PC, the
failed PC, the out-of-window counter and every RAM byte**. The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
scale_step: 7 differential cases - PASS
```

The test lays the literal pool, the mode byte, the VM's structure, the count
and the two destinations out the way the guest expects. The scenarios cover
the mode that asks for a step, the modes that do not, the mode byte that the
four-bit mask turns into a step, the mode the mask keeps out, the count above
the bias, the count below it and the count that is exactly the bias.

The test has teeth, and the mutations were checked:

* the mode test inverted fails with ten registers named, among them `FPUL`
  (`v53 00000000` != `0000003c`);
* the mode's mask narrowed to three bits fails with the same registers named -
  but only after the scenario for the mode `9` was added: the mode `17` is `1`
  under both masks, so it could not tell them apart;
* the count's bias moved fails with the differing `r5`, `FPUL` and four FP
  registers named (`v5 0000003c` != `00000038`);
* the count's sign dropped fails with the same registers named;
* FPUL off by one fails with the differing `FPUL` and four FP registers named
  (`v53 0000003c` != `0000003d`);
* the two constants swapped fails with the differing `FR5` and `FR6` named
  (`v25 43178000` != `7654322a`);
* the first destination moved fails with the differing object byte named
  (`ram 305 00 != 80`);
* the second destination's pointer moved fails with the out-of-window counter
  named (`ok 1/0/0`);
* the fused multiply-add turned into a plain multiply fails with the differing
  `FR5` and `FR6` named (`v25 43178000` != `43160000`).

This is the pattern `tests/state_helpers_replay.c` established: the generated
translation stays in the tree as the reference, and the readable port is proved
against it. The generated translation of this function was itself proved
against the oracle when it was promoted, so the chain readable port ==
generated translation == oracle still holds.

**Caveat.** The oracle corpora live under `extract/`, and that tree is gone
from this checkout (see [artifact_gap](artifact_gap.md)). The oracle replay of
this entry could not be re-run, so the differential above stands on the
generated translation rather than on a fresh oracle run. The generated
translation is the one the oracle proved, so the chain is intact, but a
session that has the corpora back should re-run the replay gate for
`0x8C0CB8AC` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The mode is the mode byte's low four bits, and only the mode `1` steps.
* The count is the halfword at the word's `+0x54`, less sixty, and positive.
* FPUL holds that positive count, and the scale is the count as a float.
* The result is `constant_two * count + constant_one`, fused.
* It goes into the caller's structure at `+16` and into the VM's structure at
  the pool's offset.

## The unknown

The mode byte, the VM's structure, the offset and the two constants are not
recoverable offline: they live in the code image, which is under `extract/`.
The port therefore reads the same addresses the guest reads, and what the
constants are - and what the step means - stays open until the image is back.
