# The float blend (SH-4 0x8C03E810)

A readable port of the fight engine's float blend, and the evidence for it.

## The function

`0x8C03E810` moves four floats out of an array and into a structure of four
slots, and then writes a weighted sum over three of the four slots back into
the first one.

* the **structure** is the word in the literal pool at `0x8C03E8A4`. It holds
  four slots of one float: the slot at `+0`, the slot at `+4`, the slot at `+8`
  and the slot at `+12`;
* the **array** is the four floats at the address the caller leaves in `r4`.
  They land in the four slots in order;
* the **weights** are three float constants in the literal pool, at
  `0x8C03E8A8`, `0x8C03E8AC` and `0x8C03E8B0`;
* the **blend** is

  ```
  slot0 = weight_a * slot2 + weight_b * slot1 + weight_c * slot3
  ```

  where `slot1`, `slot2` and `slot3` are the slots the array was just copied
  into. The first source float is therefore dropped: it is copied into the
  slot at `+0` and then overwritten by the blend.

The port: `src/fight/float_blend.c`, registered in `src/fight/readable.c` as
`float_blend`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode, and
the original opcode word in a comment. That makes them a faithful disassembly
of the function they implement, so a readable port can be written against them
without the ROM.

* `tools/adapter_owner.py 0x0c03e810 --body` - resolves which module the router
  actually serves for a PC. One module carries the copy (`motion_adapter`).
* `tools/handwritten_entries.py 0x0c03e810` - confirms that no hand-written
  module already serves this entry, so the port is not shadowed.
* The listing below is decoded with `tools/sh4.py`, the repo's authoritative
  decoder, from the opcode words the module carries; the semantics come from
  the translator's emitted C.

The guest code, decoded:

```
0x0c03e810  d524  mov.l @(144,pc),r5     ; the structure
0x0c03e812  c725  mova @(148,pc),r0     ; the first weight's address
0x0c03e814  f349  fmov.s @r4+,fr3        ; the array's first float
0x0c03e816  7ff8  add   #-8,r15          ; the frame
0x0c03e818  6653  mov   r5,r6
0x0c03e81a  6363  mov   r6,r3
0x0c03e81c  f63a  fmov.s fr3,@r6        ; into the slot at +0
0x0c03e81e  7304  add   #4,r3
0x0c03e820  6763  mov   r6,r7
0x0c03e822  7708  add   #8,r7
0x0c03e824  750c  add   #12,r5
0x0c03e826  2f32  mov.l r3,@r15         ; the slot at +4 goes on the stack
0x0c03e828  f349  fmov.s @r4+,fr3
0x0c03e82a  f33a  fmov.s fr3,@r3        ; into the slot at +4
0x0c03e82c  f349  fmov.s @r4+,fr3
0x0c03e82e  f73a  fmov.s fr3,@r7        ; into the slot at +8
0x0c03e830  1f51  mov.l r5,@(4,r15)     ; the slot at +12 goes on the stack
0x0c03e832  f348  fmov.s @r4,fr3         ; the array's fourth float, no post-increment
0x0c03e834  f53a  fmov.s fr3,@r5        ; into the slot at +12
0x0c03e836  f378  fmov.s @r7,fr3         ; and the blend starts
0x0c03e838  f008  fmov.s @r0,fr0         ; the first weight
0x0c03e83a  c71c  mova @(112,pc),r0     ; the second weight's address
0x0c03e83c  62f2  mov.l @r15,r2         ; the slot at +4, off the stack
0x0c03e83e  f302  fmul  fr0,fr3
0x0c03e840  f008  fmov.s @r0,fr0         ; the second weight
0x0c03e842  f228  fmov.s @r2,fr2         ; the slot at +4
0x0c03e844  c71a  mova @(104,pc),r0     ; the third weight's address
0x0c03e846  53f1  mov.l @(4,r15),r3      ; the slot at +12, off the stack
0x0c03e848  f32e  fmac  fr0,fr2,fr3
0x0c03e84a  f008  fmov.s @r0,fr0         ; the third weight
0x0c03e84c  f238  fmov.s @r3,fr2         ; the slot at +12
0x0c03e84e  f32e  fmac  fr0,fr2,fr3
0x0c03e850  f63a  fmov.s fr3,@r6         ; and the blend lands in the slot at +0
0x0c03e852  000b  rts                   ; the frame is popped here
```

Five details of that listing are worth naming, because each one is easy to lose
in a readable port:

* **the two slot addresses travel through the stack.** The function pushes the
  address of the slot at `+4` and the address of the slot at `+12` and reads
  them back after the copies, so the frame is part of the contract and the
  `rts` has to pop it.
* **the blend is a multiply and two *fused* multiply-adds.** `vf3_fpu_mac`
  rounds once, where a multiply and an add round twice, so the port cannot
  write the blend as an expression of C floats.
* **the array's step depends on the FPSCR.** `fmov.s @r4+,fr3` advances `r4` by
  eight bytes when the FPSCR says double precision and by four otherwise, and
  the translator follows the same rule. The port has to step the same way.
* **the fourth float is loaded without the post-increment**, so `r4` ends one
  step short of where a naive port would leave it.
* **the first source float is dead.** It is copied into the slot at `+0` and
  then overwritten by the blend, so the port may keep the copy (it is what the
  guest does) but a test cannot tell the two apart.

## The evidence

`tests/float_blend_replay.c` runs the readable port and the retained generated
translation of the same function over four scenarios and compares **the whole
register file (the FP registers and SR included), the return PC, the failed PC,
the out-of-window counter and every RAM byte**. The port runs twice: once
called directly and once through the readable override, which is how the native
tick reaches it.

```
float_blend: 4 differential cases - PASS
```

The test lays the literal pool, the array, the structure and the caller's
stack out the way the guest expects. The scenarios cover a plain blend, a blend
over negative numbers, a blend whose weights and values do not divide evenly
under the round-toward-zero mode, and the double-precision FPSCR, where the
float loads are eight bytes wide.

The test also checks the result **against the fixture itself**: the
structure's slots have to hold the array's floats, and the first slot has to
hold the blend, which the test computes on its own with the same fused
multiply-adds. A differential alone is not enough, because a fixture that is
not where the guest looks makes both sides read the same wrong bytes and agree
on them - the trap the record repack's test fell into.

The double-precision scenario is a special case for that check: the stores are
eight bytes wide there, so the slot at `+4` and the slot at `+8` overlap and
the blend's own store - eight bytes at the slot at `+0` - reaches over the
slot at `+4`. Only the two slots that survive are checked there.

### The test has teeth, and the mutations were checked

The mutations are checked with `tools/mutate.py`, which applies one at a time
to the port's source, rebuilds and requires the test to fail. The list lives
in `tests/float_blend_mutations.json`, next to the test it guards.

* the first weight replaced by the second fails with the differing `FR3` named
  (`v24 40200000` != `3fe00000`);
* the second weight replaced by the third fails with the differing `FR3` named
  (`v24 40200000` != `40100000`);
* the third weight replaced by the second fails with the differing `r0` named
  (`v0 0c03e8b0` != `0c03e8ac`);
* the blend reading the slot at `+4` instead of the slot at `+8` fails with the
  differing `FR3` named (`v24 40200000` != `40000000`);
* the second weight reading the slot at `+12` instead of the slot at `+4` fails
  with the differing `FR2` named (`v23 40800000` != `40000000`);
* the fused multiply-add turned into a multiply and an add fails with the
  differing `FR3` named (`v24 3ee6ce6d` != `3ee6ce6e`) - one unit in the last
  place, which is exactly what the extra rounding does;
* the multiply reading the wrong register fails with the differing `FR3` named
  (`v24 40200000` != `75d43229`);
* the accumulator reading the wrong register fails with the differing `FR3`
  named (`v24 40200000` != `76543229`);
* the array's step fixed at four bytes fails with the differing `r4` named
  (`v4 0c180018` != `0c18000c`) - the double-precision scenario is what sees
  it;
* the frame grown to sixteen bytes fails with the differing stack byte named
  (`ram 160 00` != `04`);
* the frame pushed as four bytes fails with the differing `sp` named
  (`v15 0c108000` != `0c108004`);
* the frame not popped fails with the differing `sp` named
  (`v15 0c108000` != `0c107ff8`);
* the second copy landing in the slot at `+8` fails with the differing `FR3`
  named (`v24 40200000` != `40000000`);
* the third copy landing in the slot at `+4` fails with the differing `FR3`
  named (`v24 40200000` != `3fa00000`);
* the blend landing in the slot at `+12` fails with the differing structure
  byte named (`ram 98 20` != `80`);
* the first slot's address wrong on the stack fails with the differing `r2`
  named (`v2 0c190004` != `0c190008`);
* the third slot's address wrong on the stack fails with the differing `r3`
  named (`v3 0c19000c` != `0c190000`).

One mutation is *not* caught, and correctly so: skipping the first copy leaves
the slot at `+0` holding the source's first float, and the blend overwrites
that slot before the function returns. The copy is dead in the guest too, so
the bit is unobservable and the port's choice there is free.

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
`0x8C03E810` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The structure is the pool word at `0x8C03E8A4`, and the three weights are
  the pool floats at `0x8C03E8A8`, `0x8C03E8AC` and `0x8C03E8B0`.
* The frame is eight bytes, and the two slot addresses go through it.
* The blend is `weight_a * slot2 + weight_b * slot1 + weight_c * slot3`, fused.
* The array's step is eight bytes when the FPSCR is double and four otherwise.

## The unknown

What the structure holds and who calls this are not recoverable offline: the
pool's values and the code live in the game's own image, which is under
`extract/`. The port therefore reads the same addresses the guest reads, and
what the four floats mean stays open until the image is back.
