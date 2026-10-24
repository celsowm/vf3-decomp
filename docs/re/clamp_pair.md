# The clamp pair (SH-4 0x8C08DCB0)

A readable port of the fight engine's clamp pair, and the evidence for it.

## The function

`0x8C08DCB0` takes two numbers - the caller's `r4` and `r5` - and writes four
limited values.  A "limit" is a clamp: a value below the low bound becomes the
low bound, a value above the high bound becomes the high bound.

| the number | the range | where it goes |
| ---------- | --------- | ------------- |
| `r4` | `[pool 0x8C08DD48, pool 0x8C08DD4A]` | `r6` and `*(sp+0)` |
| `r5` | `[pool 0x8C08DD4C, pool 0x8C08DD4E]` | `r7` |
| `r5` | `[pool 0x8C08DD50, pool 0x8C08DD52]` | `*(sp+4)` |

The last two destinations are not registers.  The caller leaves two words in
*its own* frame, and the callee reads them from there: the callee's stack
pointer is eight bytes below the caller's, so the two words sit at `sp+0` and
`sp+4` of the callee.

The bounds are signed halfwords in the literal pool, so they can be negative.
The pool's own values are not recoverable offline (the game's image is under
`extract/`), so the port reads the same addresses the guest reads.

The port: `src/fight/clamp_pair.c`, registered in `src/fight/readable.c` as
`clamp_pair`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode, and
the original opcode word in a comment.  That makes them a faithful disassembly
of the function they implement, so a readable port can be written against them
without the ROM.

* `tools/adapter_owner.py 0x8c08dcb0 --body` - the body, in the module that
  carries it (`next_adapters_1`), and the module that serves it.
* `tools/handwritten_entries.py 0x8c08dcb0` - confirms that no hand-written
  module already serves this entry, so the port is not shadowed.
* The listing below is decoded with `tools/sh4.py`, the repo's authoritative
  decoder, from the opcode words the module carries; the semantics come from
  the translator's emitted C.

The guest code, decoded:

```
0x0c08dcb0  2fe6  mov.l r14,@-r15       ; the guest saves r14 and r13
0x0c08dcb2  6143  mov   r4,r1            ; a copy of the first number
0x0c08dcb4  2fd6  mov.l r13,@-r15
0x0c08dcb6  6d43  mov   r4,r13           ; another copy
0x0c08dcb8  9046  mov.w @(140,pc),r0     ; the first range's low bound
0x0c08dcba  6453  mov   r5,r4            ; a copy of the second number
0x0c08dcbc  6e53  mov   r5,r14           ; another copy
0x0c08dcbe  9544  mov.w @(136,pc),r5     ; the first range's high bound
0x0c08dcc0  3d03  cmp/ge r0,r13          ; the low bound first ...
0x0c08dcc2  8901  bt   0x0c08dcc8
0x0c08dcc4  a003  bra  0x0c08dcce
0x0c08dcc6  6d03  mov   r0,r13           ; ... and the high one only then
0x0c08dcc8  3d57  cmp/gt r5,r13
0x0c08dcca  8b00  bf   0x0c08dcce
0x0c08dccc  6d53  mov   r5,r13
0x0c08dcce  953d  mov.w @(122,pc),r5     ; the second range's low bound
0x0c08dcd0  903d  mov.w @(122,pc),r0     ; and its high bound
0x0c08dcd2  3e53  cmp/ge r5,r14          ; the second limit: r5 into r14
0x0c08dcd4  8901  bt   0x0c08dcda
0x0c08dcd6  a003  bra  0x0c08dce0
0x0c08dcd8  6e53  mov   r5,r14
0x0c08dcda  3e07  cmp/gt r0,r14
0x0c08dcdc  8b00  bf   0x0c08dce0
0x0c08dcde  6e03  mov   r0,r14
0x0c08dce0  9532  mov.w @(100,pc),r5     ; the first range again
0x0c08dce2  9032  mov.w @(100,pc),r0
0x0c08dce4  3153  cmp/ge r5,r1           ; the third limit: r4 into r1
0x0c08dce6  8901  bt   0x0c08dcec
0x0c08dce8  a003  bra  0x0c08dcf2
0x0c08dcea  6153  mov   r5,r1
0x0c08dcec  3107  cmp/gt r0,r1
0x0c08dcee  8b00  bf   0x0c08dcf2
0x0c08dcf0  6103  mov   r0,r1
0x0c08dcf2  952d  mov.w @(90,pc),r5      ; the third range
0x0c08dcf4  902d  mov.w @(90,pc),r0
0x0c08dcf6  3453  cmp/ge r5,r4           ; the fourth limit: r5 into r4
0x0c08dcf8  8901  bt   0x0c08dcfe
0x0c08dcfa  a003  bra  0x0c08dd04
0x0c08dcfc  6453  mov   r5,r4
0x0c08dcfe  3407  cmp/gt r0,r4
0x0c08dd00  8b00  bf   0x0c08dd04
0x0c08dd02  6403  mov   r0,r4
0x0c08dd04  26d2  mov.l r13,@r6          ; the four writes
0x0c08dd06  27e2  mov.l r14,@r7
0x0c08dd08  53f2  mov.l @(8,r15),r3      ; the caller's frame
0x0c08dd0a  2312  mov.l r1,@r3
0x0c08dd0c  53f3  mov.l @(12,r15),r3
0x0c08dd0e  2342  mov.l r4,@r3
0x0c08dd10  6df6  mov.l @r15+,r13        ; the saved registers go back
0x0c08dd12  000b  rts                    ; and the last one is the delay slot
```

Four details of that listing are worth naming, because each one is easy to lose
in a readable port:

* **the low bound is tested first.**  The guest compares against the low bound
  and only asks about the high one if the value was not below the low bound,
  so a value below the low bound is *never* compared against the high one.  A
  port that clamps the other way round gives the same answer for a range whose
  bounds are in order, and a different one for a range whose bounds are not.
* **the T bit the caller sees is the last comparison the guest made**, which is
  the one of the fourth limit - not the one of the limit that produced the
  value the caller asked for.
* **the limited values travel in `r13`, `r14`, `r1` and `r4`**, and the guest
  puts the two saved registers back from the stack at the end.  The last pop is
  the delay slot of the return, so it happens after the return has started.
* **the third limit is dead.**  It limits the first number into the first range
  again - the same input, the same bounds - and the fourth limit overwrites the
  T bit it leaves.  Only its two pool reads are left.

## The evidence

`tests/clamp_pair_replay.c` runs the readable port and the retained generated
translation of the same function over fourteen scenarios and compares **the
whole register file (the FP registers and SR included), the return PC, the
failed PC, the out-of-window counter and every RAM byte**.  The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
clamp_pair: 14 differential cases - PASS
```

The scenarios walk the two numbers through the ranges: inside, below the low
bound, above the high bound, exactly on a bound, negative, and both numbers
outside at once.  One scenario puts the third range's bounds the wrong way
round, which is the case where the order of the two comparisons shows.

The test also checks the result **against the fixture itself**: the four
destinations have to hold the limited values, the registers that still hold
them have to hold them too, the bounds the guest read last have to be in `r0`
and `r5`, the saved registers have to be back, and the T bit has to be the one
of the last comparison.  A differential alone is not enough, because a fixture
that is not where the guest looks makes both sides read the same wrong bytes
and agree on them.

### The test has teeth, and the mutations were checked

The mutations are checked with `tools/mutate.py`, which applies one at a time
to the port's source, rebuilds and requires the test to fail.  The list lives
in `tests/clamp_pair_mutations.json`, next to the test it guards.

Every mutation in the list is caught.  The ones worth naming:

* a bound read from the wrong pool slot fails with the differing `r1`, `r5` or
  `r0` named - the limit that reads it lands on another value;
* the bounds read as unsigned fails with the differing `r1` named
  (`v1 00000000` != `0000fc18`) - a negative bound becomes a large positive one;
* the low test made strict (`>=` into `>`) fails with the differing `r4` named
  (`v4 ffffffce` != `00000032`) - it takes the scenario with the inverted range
  to see it, because for a range whose bounds are in order the two ways of
  asking agree;
* the high test made loose (`>` into `>=`) fails with the differing `v17` named
  (`v17 00000300` != `00000301`);
* the T bit inverted on the high test, and the T bit wrong on the low test,
  fail with the differing `v17` named as well;
* the two register destinations swapped, and the two frame destinations
  swapped, fail with the differing RAM byte named (`ram 44 18` != `00`);
* the frame words read from the wrong place fails with the differing RAM byte
  named (`ram 36 18` != `00`);
* the second number written to the first destination fails with the differing
  RAM byte named (`ram 48 30` != `ce`);
* the two numbers copied the wrong way round fails with the differing RAM byte
  named (`ram 48 00` != `30`);
* `r1` and `r4` holding the wrong value fail with the differing register named
  (`v1 fffffc18` != `00000000`);
* `r0` and `r5` holding the wrong bound fail with the differing register named
  (`v0 00000032` != `ffffffce`);
* the saved `r13` not put back fails with the differing `v13` named
  (`v13 7654321d` != `00000000`), and the delay slot's pop missing with the
  differing `v14` named (`v14 7654321e` != `00000000`);
* the frame not reserved fails with the differing return code named;
* the return address not set fails with the differing `pc` named
  (`pc 0c0abcde/00000000`).

This is the pattern `tests/state_helpers_replay.c` established: the generated
translation stays in the tree as the reference, and the readable port is proved
against it.  The generated translation of this function was itself proved
against the oracle when it was promoted, so the chain readable port ==
generated translation == oracle still holds.

**Caveat.** The oracle corpora live under `extract/`, and that tree is gone
from this checkout (see [artifact_gap](artifact_gap.md)).  The oracle replay of
this entry could not be re-run, so the differential above stands on the
generated translation rather than on a fresh oracle run.  The generated
translation is the one the oracle proved, so the chain is intact, but a
session that has the corpora back should re-run the replay gate for
`0x8C08DCB0` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The low bound is tested before the high one.
* The T bit is the one of the last comparison.
* The limited values travel in `r13`, `r14`, `r1` and `r4`, and the saved
  registers are put back from the stack.
* The two frame destinations are read from the caller's frame, eight bytes
  above the callee's stack pointer.
* The bounds are signed halfwords.

## The unknown

What the ranges mean, and who calls this, are not recoverable offline: the
pool's values and the code live in the game's own image, which is under
`extract/`.  The port therefore reads the same addresses the guest reads, and
what the numbers are stays open until the image is back.
