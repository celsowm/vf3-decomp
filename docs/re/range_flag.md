# The out-of-range flag (SH-4 0x8C0CAA9C)

A readable port of the fight engine's out-of-range flag, and the evidence for
it.

## The function

`0x8C0CAA9C` keeps a byte of flags honest. The byte sits beside four floats,
and the function sets the byte's `0x10` bit when one of the four floats is
outside the range the two bounds describe - and clears it again when they are
all inside.

* the byte's own `0x40` bit says whether the values have to be looked at at
  all. When it is clear the function does nothing: it does not even write the
  byte back;
* the **upper bound** and the **lower bound** are two float constants in the
  literal pool, at `0x8C0CAB20` and `0x8C0CAB24`;
* the offsets of the byte and of the first float are in the pool too, at
  `0x8C0CAB1A` and `0x8C0CAB1C`;
* the four floats are read at the first float's offset, at that offset plus
  twelve, and at that offset minus thirty-six and minus twenty-four.

When the flag goes **off** the guest clears the neighbouring bit as well: it
masks the byte with `0xFFFFFFEF`, which takes bit 0 with it.

The port: `src/fight/range_flag.c`, registered in `src/fight/readable.c` as
`range_flag`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine
translation of the ROM: one label per guest PC, one C statement per executed
opcode, and the original opcode word in a comment. That makes them a faithful
disassembly of the function they implement, so a readable port can be written
against them without the ROM.

* `tools/adapter_owner.py 0x0c0caa9c` - resolves which module the router
  actually serves for a PC. The PC is carried by `eighth_adapter` and
  `fight_adapter`; the chain serves `eighth_adapter` and the two copies
  agree.
* `tools/adapter_dump.py 0x0c0caa9c` - prints the generated function as guest
  disassembly. Its own decoder is crude, so the mnemonics below come from
  `tools/sh4.py`, the repo's authoritative decoder, and the semantics come
  from the translator's emitted C.

The guest code, decoded:

```
0x0c0caa9c  903d  mov.w  @(122,pc),r0    ; the byte's offset
0x0c0caa9e  e340  mov    #64,r3
0x0c0caaa0  054c  mov.b  @(r0,r4),r5     ; the byte
0x0c0caaa2  655c  extu.b r5,r5
0x0c0caaa4  2358  tst    r5,r3
0x0c0caaa6  8922  bt     0x0c0caaee      ; nothing to do
0x0c0caaa8  9038  mov.w  @(112,pc),r0    ; the first float's offset
0x0c0caaaa  f646  fmov.s @(r0,r4),fr6
0x0c0caac  700c  add    #12,r0
0x0c0caae  f746  fmov.s @(r0,r4),fr7
0x0c0cab0  70dc  add    #-36,r0
0x0c0cab2  f846  fmov.s @(r0,r4),fr8
0x0c0cab4  700c  add    #12,r0
0x0c0cab6  f946  fmov.s @(r0,r4),fr9
0x0c0cab8  c719  mova   @(100,pc),r0
0x0c0caba  f508  fmov.s @r0,fr5          ; the upper bound
0x0c0cabc  c719  mova   @(100,pc),r0
0x0c0cabe  f655  fcmp/gt fr5,fr6
0x0c0cac0  8d0e  bt/s   0x0c0caae0       ; the delay slot loads fr4
0x0c0cac2  f408  fmov.s @r0,fr4          ; the lower bound
0x0c0cac4  f465  fcmp/gt fr6,fr4
0x0c0cac6  890b  bt     0x0c0caae0
0x0c0cac8  f755  fcmp/gt fr5,fr7
0x0c0caca  8909  bt     0x0c0caae0
0x0c0cacc  f475  fcmp/gt fr7,fr4
0x0c0cace  8907  bt     0x0c0caae0
0x0c0cad0  f855  fcmp/gt fr5,fr8
0x0c0cad2  8905  bt     0x0c0caae0
0x0c0cad4  f485  fcmp/gt fr8,fr4
0x0c0cad6  8903  bt     0x0c0caae0
0x0c0cad8  f955  fcmp/gt fr5,fr9
0x0c0cada  8901  bt     0x0c0caae0
0x0c0cadc  f495  fcmp/gt fr9,fr4
0x0c0cade  8b02  bf     0x0c0caae6       ; all inside: clear the flag
0x0c0caae0  e310  mov    #16,r3
0x0c0caae2  a002  bra    0x0c0caaea      ; the delay slot sets the flag
0x0c0caae4  253b  or     r3,r5           ; <- the delay slot
0x0c0caae6  e1ef  mov    #-17,r1
0x0c0caae8  2519  and    r1,r5
0x0c0caaea  9016  mov.w  @(44,pc),r0
0x0c0caaec  0454  mov.b  r5,@(r0,r4)
0x0c0caaee  000b  rts
```

Four details of that listing are worth naming, because each one is easy to
lose in a readable port:

* **the branch at the end has two arms, and they are not symmetric.** The
  comparisons branch *away* when a value is out of range, so the arm that is
  left is the "everything is inside" one - and it clears the flag with a
  mask, not by writing a zero. A port that only handles the "out of range"
  arm leaves a stale flag behind.
* **the delay slot of the first comparison loads the lower bound.** The
  translator merges the slot into the branch block, so `fr4` is loaded after
  the first comparison and before the branch is resolved.
* **the comparisons branch away, so the later ones do not run.** The port has
  to short-circuit the same way: the T bit the guest leaves behind is the
  one of the *last* comparison it actually reached.
* **the float loads go through the shared helpers**, which size the transfer
  by the FPSCR's FPUL bit. The guest's own `fmov.s` is always four bytes
  wide, so the port inherits the helper's behaviour and the test has to set
  the FPSCR the way the reference sees it.

## The evidence

`tests/range_flag_replay.c` runs the readable port and the retained
generated translation of the same function over seven scenarios and compares
**the whole register file (the FP registers and SR included), the return PC,
the failed PC, the out-of-window counter and every RAM byte**. The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
range_flag: 7 differential cases - PASS
```

The test seeds the literal pool with the two bounds and the two offsets, and
lays the four values and the byte out the way the guest expects. The
scenarios cover the byte's "do not look" bit being clear, everything in
range, a value above the upper bound, a value below the lower one, a value
exactly on the bound, a byte that already carries other bits, and a flag that
is already on and has to go off.

The test has teeth, and the mutations were checked:

* the in-range mask widened fails with the differing `r1` named (`v1`
  `fffffefef` != `ffffffff`);
* the third value read from the wrong offset fails with the differing `FR8`
  and `FR9` named (`v29` `40800000` != `00000000`);
* the early exit removed fails with the differing `r1`, `SR` and every FR
  register named;
* the flag's bit changed fails with the differing `r3` and byte named (`v3`
  `00000010` != `00000020`).

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
`0x8C0CAA9C` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The byte's `0x40` bit gates everything, and when it is clear the byte is
  *not* written back.
* The four values are read at the first float's offset, at that offset plus
  twelve, minus thirty-six and minus twenty-four.
* A value is out of range when it is above the upper bound or below the
  lower one, and the comparisons short-circuit.
* The flag goes on with `|= 0x10` and off with `&= 0xFFFFFFEF` - the mask
  takes the neighbouring bit with it, and `r1` holds the mask afterwards.
* The T bit is set after every comparison the guest actually reaches.

## The unknown

The two bounds and the two offsets are not recoverable offline: they live in
the code image, which is under `extract/`. The port therefore reads the same
addresses the guest reads, and what the range actually means stays open until
the image is back.
