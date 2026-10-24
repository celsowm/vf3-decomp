# The band probe (SH-4 0x8C0B0F28)

A readable port of the fight engine's band probe, and the evidence for it.

## The function

`0x8C0B0F28` is handed a point in three registers - `r4`, `r5` and `r6` - and a
band in the literal pool.  It takes the two differences the point makes with
its third coordinate, masks them, and asks whether they are inside the band.
The answer goes into a word the caller leaves in its own frame.

| the difference | how it is made | the band |
| ------------- | -------------- | -------- |
| the first one  | `r4 - r6`, masked, read back as a signed halfword | the high bound first, the low one second |
| the second one | `r5 - r6`, masked, read back as a signed halfword | the same two bounds |

The **mask** is a word in the pool at `0x8C0B0F90`.  It is xored into the
differences *before* the low halfword is read back, so the pool alone decides
what a masked difference is.  The **band** is two halfwords in the pool: the
low one at `0x8C0B0F64` and the high one at `0x8C0B0F66`.

There are three answers:

* **inside** - both differences are inside the band.  The guest sets the
  *inside bit* (`0x8C0B0F68`, a halfword) in the word it was handed and
  answers one.
* **outside, and the gate is closed** - one of the differences is outside, and
  the seventh register has no bit in common with the word in the pool at
  `0x8C0B1088`.  The guest answers zero and writes nothing.
* **outside, and the gate is open** - the seventh register and that word have
  a bit in common.  The guest then looks at the *second* difference twice:
  once as it is and once under the mask.  Each of the two that is inside the
  band sets a bit in the word - the first one (`0x8C0B108C`) for the plain
  difference, the second one (`0x8C0B1090`) for the masked one - and the
  guest answers one.

The word the flags go into is not in a register: the caller hands it over in
its own frame, as the last word it pushed before the call.

The port: `src/fight/band_probe.c`, registered in `src/fight/readable.c` as
`band_probe`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode, and
the original opcode word in a comment.  That makes them a faithful disassembly
of the function they implement, so a readable port can be written against them
without the ROM.

* `tools/adapter_owner.py 0x0c0b0f28 --body` - the body, in the module that
  carries it (`fight_adapters_2`).
* `tools/handwritten_entries.py 0x0c0b0f28` - confirms that no hand-written
  module already serves this entry, so the port is not shadowed.
* The listing below is decoded with `tools/sh4.py`, the repo's authoritative
  decoder, from the opcode words the module carries; the semantics come from
  the translator's emitted C.

The guest code, decoded:

```
0x0c0b0f28  2fd6  mov.l r13,@-r15      ; the saved r13
0x0c0b0f2a  3568  sub r6,r5           ; the second difference
0x0c0b0f2c  3468  sub r6,r4           ; the first difference
0x0c0b0f2e  7ffc  add #-4,r15         ; the frame
0x0c0b0f30  5df2  mov.l @(8,r15),r13  ; the word the caller handed over
0x0c0b0f32  2f52  mov.l r5,@r15       ; the second difference, on the stack
0x0c0b0f34  d116  mov.l @(88,pc),r1   ; the mask
0x0c0b0f36  241a  xor r1,r4           ; the first difference, masked
0x0c0b0f38  664f  exts.w r4,r6
0x0c0b0f3a  9414  mov.w @(40,pc),r4   ; the band's high bound
0x0c0b0f3c  251a  xor r1,r5           ; the second difference, masked
0x0c0b0f3e  605f  exts.w r5,r0
0x0c0b0f40  9510  mov.w @(32,pc),r5   ; the band's low bound
0x0c0b0f42  3647  cmp/gt r4,r6
0x0c0b0f44  8926  bt 0x0c0b0f94
0x0c0b0f46  3653  cmp/ge r5,r6
0x0c0b0f48  8b24  bf 0x0c0b0f94
0x0c0b0f4a  3047  cmp/gt r4,r0
0x0c0b0f4c  8922  bt 0x0c0b0f94
0x0c0b0f4e  3053  cmp/ge r5,r0
0x0c0b0f50  8b20  bf 0x0c0b0f94
0x0c0b0f52  62d2  mov.l @r13,r2       ; inside: the word with the inside bit
0x0c0b0f54  9308  mov.w @(16,pc),r3
0x0c0b0f56  223b  or r3,r2
0x0c0b0f58  a037  bra 0x0c0b0fca       ; (its delay slot stores the word)
0x0c0b0f5a  2d22  mov.l r2,@r13
0x0c0b0fca  e001  mov #1,r0
0x0c0b0fcc  7f04  add #4,r15
0x0c0b0fce  000b  rts                 ; (its delay slot puts r13 back)
0x0c0b0fd0  6df6  mov.l @r15+,r13
0x0c0b0f94  d03c  mov.l @(240,pc),r0   ; outside: the gate
0x0c0b0f96  2708  tst r0,r7
0x0c0b0f98  8b03  bf 0x0c0b0fa2
0x0c0b0f9a  7f04  add #4,r15
0x0c0b0f9c  e000  mov #0,r0
0x0c0b0f9e  000b  rts                 ; (its delay slot puts r13 back)
0x0c0b0fa0  6df6  mov.l @r15+,r13
0x0c0b0fa2  66f2  mov.l @r15,r6        ; the second difference, back from the stack
0x0c0b0fa4  676f  exts.w r6,r7
0x0c0b0fa6  3747  cmp/gt r4,r7
0x0c0b0fa8  8905  bt 0x0c0b0fb6
0x0c0b0faa  3753  cmp/ge r5,r7
0x0c0b0fac  8b03  bf 0x0c0b0fb6
0x0c0b0fae  62d2  mov.l @r13,r2       ; the first outside bit
0x0c0b0fb0  d336  mov.l @(216,pc),r3
0x0c0b0fb2  223b  or r3,r2
0x0c0b0fb4  2d22  mov.l r2,@r13
0x0c0b0fb6  261a  xor r1,r6           ; the second difference, masked
0x0c0b0fb8  666f  exts.w r6,r6
0x0c0b0fba  3647  cmp/gt r4,r6
0x0c0b0fbc  8905  bt 0x0c0b0fca
0x0c0b0fbe  3653  cmp/ge r5,r6
0x0c0b0fc0  8b03  bf 0x0c0b0fca
0x0c0b0fc2  62d2  mov.l @r13,r2       ; the second outside bit
0x0c0b0fc4  d332  mov.l @(200,pc),r3
0x0c0b0fc6  223b  or r3,r2
0x0c0b0fc8  2d22  mov.l r2,@r13
```

Five details of that listing are worth naming, because each one is easy to
lose in a readable port:

* **the plain `bt` and `bf` have no delay slot.**  Only the `/s` forms have
  one.  So the instruction after a plain `bt` is the *next* instruction of the
  guest, not a delay slot: it runs only on the path that falls through.  The
  repo's own decoder says so (`tools/sh4.py`: *"Only the /s conditional forms
  plus the unconditional control transfers have a delay slot.  Plain bf/bt are
  direct jumps (no delay slot)."*), and the translator emits the branch that
  way: the instruction after a plain `bt`/`bf` is a block of its own, and the
  branch goes straight to the target without it.
* **the two return paths drop the frame differently.**  The path that answers
  zero reaches the `rts` through the `add #4,r15` at `0x8C0B0F9A`, so it drops
  the frame word *before* the return; the other two paths reach the same `rts`
  through the `add #4,r15` at `0x8C0B0F8C`... which is the same instruction as
  `0x8C0B0FCC`.  Either way the stack is back where it was, and the saved
  `r13` comes back in the delay slot of the `rts`, after the return itself
  has started.
* **the band is tested high bound first.**  A value below the low bound is
  never tested against the high one, and the T bit the caller sees is the one
  of the *last* comparison the guest made.
* **the gate is tested with `tst`,** which sets the T bit: the T bit is set
  when the seventh register and the gate word have *no* bit in common.
* **the inside bit is a halfword and the two outside bits are words,** so the
  inside bit arrives sign extended and the two outside bits do not.

## The evidence

`tests/band_probe_replay.c` runs the readable port and the retained generated
translation of the same function over twenty scenarios and compares **the
whole register file (the FP registers and SR included), the return PC, the
failed PC, the out-of-window counter and every RAM byte**.  The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
band_probe: 20 differential cases - PASS
```

The scenarios walk the point through the band: inside, on each of the two
bounds, outside in each of the four ways (either difference, above or below),
outside with the gate open and closed, with a mask that leaves the low half
alone and with one that flips the sign bit of the differences, with a band
that is the wrong way round, with a difference that does not fit in sixteen
bits, and with a third number that is not zero.  Two of them exist only to
tell the mask's effect apart: one where the masked second difference is inside
the band and the plain one is not, and one where the seventh register holds a
bit of the mask and none of the gate, so the gate is closed and the T bit
still says so.

The test also checks the result **against the fixture itself**: the answer,
the word the guest was handed, the mask and the two bounds it read, the saved
register, the stack pointer, the difference it kept on the stack and the T
bit all have to be what the scenario says.  A differential alone is not
enough, because a fixture that is not where the guest looks makes both sides
read the same wrong bytes and agree on them.

### The test has teeth, and the mutations were checked

The mutations are checked with `tools/mutate.py`, which applies one at a time
to the port's source, rebuilds and requires the test to fail.  The list lives
in `tests/band_probe_mutations.json`, next to the test it guards.

<!--MUTATIONS-->

* the band's low bound read from the high one's slot fails with the differing
  answer named (`v0 00000001` != `00000000`);
* the band's high bound read from the low one's slot fails with the differing
  answer named (`v0 00000001` != `00000000`);
* the inside bit read from the band's high bound fails with the differing
  flag word named (`v2 00000001` != `00000064`);
* the mask read from the gate's slot fails with the differing mask named
  (`v1 80000000` != `00000010`);
* the gate read from the mask's slot fails with the differing answer named
  (`v0 00000001` != `00000000`);
* the first outside bit read from the second one's slot fails with the
  differing flag word named (`v2 00000006` != `00000004`);
* the second outside bit read from the first one's slot fails with the
  differing flag word named (`v2 00000006` != `00000002`);
* the pool's halfwords read unsigned fails with the differing answer named
  (`v0 00000001` != `00000000`);
* the high bound tested loosely fails with the differing answer named
  (`v0 00000001` != `00000000`);
* the low bound tested strictly fails with the differing answer named
  (`v0 00000001` != `00000000`);
* the T bit inverted on the high test fails with the differing `SR` named
  (`v17 00000301` != `00000300`);
* the T bit inverted on the low test fails with the differing `SR` named
  (`v17 00000301` != `00000300`);
* the band tested low bound first fails with the differing answer named
  (`v0 00000001` != `00000000`);
* the flag word losing its old bits fails with the differing flag word named
  (`v2 00000006` != `00000004`);
* the flag word not written fails with the differing RAM byte named
  (`ram 344 01` != `00`);
* the flag word read from the wrong place fails with the differing flag word
  named (`v2 00000001` != `ffffffe3`);
* the caller's word read from the wrong place fails outright
  (`band probe: inside differs (ok 1/0/0)`);
* the frame not reserved fails outright
  (`band probe: inside differs (ok 1/0/0)`);
* the difference added to the third number instead of taken off it fails with
  the differing answer named (`v0 00000001` != `00000000`);
* the first difference not masked fails with the differing difference named
  (`v6 00007fce` != `ffffffce`);
* the main path's second difference not masked fails with the differing answer
  named (`v0 00000001` != `00000000`);
* the flag path's difference not masked fails with the differing flag word
  named (`v2 00000002` != `00000006`);
* the masked difference not cut to sixteen bits fails with the differing
  answer named (`v0 00000001` != `00000000`);
* the second difference not cut to sixteen bits fails with the differing flag
  word named (`v2 00000006` != `00000002`);
* the gate test inverted fails with the differing answer named
  (`v0 00000000` != `00000001`);
* the gate test against the wrong register fails with the differing `SR` named
  (`v17 00000301` != `00000300`);
* the closed gate answering one fails with the differing answer named
  (`v0 00000000` != `00000001`);
* the open gate answering zero fails with the differing answer named
  (`v0 00000001` != `00000000`);
* the inside case answering zero fails with the differing answer named
  (`v0 00000001` != `00000000`);
* the difference not kept on the stack fails with the differing RAM byte
  named (`ram 320 e2` != `32`);
* the second difference read from the wrong place fails with the differing
  flag word named (`v2 00000006` != `76543212`);
* the saved `r13` not put back fails with the differing `r13` named
  (`v13 7654321d` != `00000000`);
* the stack word not dropped fails with the differing `r13` named
  (`v13 7654321d` != `ffffffe2`);
* the saved `r13` not pushed fails with the differing `r13` named
  (`v13 7654321d` != `00000000`);
* the return address not set fails with the differing return address named
  (`pc 0c0abcde/00000000`).

This is the pattern `tests/state_helpers_replay.c` established: the generated
translation stays in the tree as the reference, and the readable port is proved
against it.  The generated translation of this function was itself proved
against the oracle when it was promoted - `docs/decomp_status.csv` carries
`0x8c0b0f28` with six corpora and 1464 cases - so the chain readable port ==
generated translation == oracle still holds.

**Caveat.** The oracle corpora live under `extract/`, and that tree is gone
from this checkout (see [artifact_gap](artifact_gap.md)).  The oracle replay of
this entry could not be re-run, so the differential above stands on the
generated translation rather than on a fresh oracle run.  The generated
translation is the one the oracle proved, so the chain is intact, but a
session that has the corpora back should re-run the replay gate for
`0x8C0B0F28` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The mask, the band and the three bits are read from the pool, at the
  addresses the guest reads them from.
* The word the flags go into comes from the caller's frame, not from a
  register.
* The plain `bt`/`bf` have no delay slot, so the instruction after them runs
  only on the path that falls through.
* The band is tested high bound first, and the T bit is the one of the last
  comparison.
* The saved `r13` comes back in the delay slot of the return, and the stack
  is back where it was.

## The unknown

What the band means, what the mask in the pool really is and who calls this
are not recoverable offline: the pool's values and the code live in the game's
own image, which is under `extract/`.  The port therefore reads the same
addresses the guest reads, and what the three differences and the three bits
stand for stays open until the image is back.
