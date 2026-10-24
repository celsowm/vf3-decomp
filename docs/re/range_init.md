# The structure init (SH-4 0x8C036A58)

A readable port of the fight engine's structure init, and the evidence for it.

## The function

`0x8C036A58` sets up a forty-four byte structure. Most of it is zeroed, but
four words in the middle carry a *range*, and the range has two shapes:

| the flag word | `+8` | `+12` | `+16` | `+20` |
| ------------- | ---- | ----- | ----- | ----- |
| zero          | 0    | -1    | 0     | 0     |
| not zero      | -1   | 0     | -1    | -1    |

* the **flag word** is the first word of whatever the pool points at. The pool
  gives a *pointer* at `0x8C036AF0`, and the word behind it is what the branch
  is on, so the shape of the range depends on the game's own state;
* the rest of the structure is zeroed: the two words at `+0` and `+4`, the six
  halfwords from `+24` to `+35` and the word at `+40`;
* the word at `+36` comes from the pool, at `0x8C036B0C`.

The port: `src/fight/range_init.c`, registered in `src/fight/readable.c` as
`range_init`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode, and
the original opcode word in a comment. That makes them a faithful disassembly
of the function they implement, so a readable port can be written against them
without the ROM.

* `tools/adapter_body.py 0x0c036a58 --span 100` - the body, in the module that
  carries it (`matrix_adapters`).
* `tools/handwritten_entries.py 0x0c036a58` - confirms that no hand-written
  module already serves this entry, so the port is not shadowed.
* The listing below is decoded with `tools/sh4.py`, the repo's authoritative
  decoder, from the opcode words the module carries; the semantics come from
  the translator's emitted C.

The guest code, decoded:

```
0x0c036a58  e500  mov   #0,r5
0x0c036a5a  2452  mov.l r5,@r4
0x0c036a5c  1451  mov.l r5,@(4,r4)
0x0c036a5e  d224  mov.l @(144,pc),r2       ; the pointer to the flag word
0x0c036a60  6322  mov.l @r2,r3
0x0c036a62  2338  tst   r3,r3              ; the flag word
0x0c036a64  8f05  bf/s  0x0c036a72
0x0c036a66  e6ff  mov   #-1,r6             ; (the branch's delay slot)
0x0c036a68  1452  mov.l r5,@(8,r4)         ; the flag is zero:
0x0c036a6a  1463  mov.l r6,@(12,r4)
0x0c036a6c  1454  mov.l r5,@(16,r4)
0x0c036a6e  a004  bra   0x0c036a7a
0x0c036a70  1455  mov.l r5,@(20,r4)        ; (the bra's delay slot)
0x0c036a72  1462  mov.l r6,@(8,r4)         ; the flag is not zero:
0x0c036a74  1453  mov.l r5,@(12,r4)
0x0c036a76  1464  mov.l r6,@(16,r4)
0x0c036a78  1465  mov.l r6,@(20,r4)
0x0c036a7a  6053  mov   r5,r0
0x0c036a7c  814c  mov.w r0,@(24,r4)
0x0c036a7e  814d  mov.w r0,@(26,r4)
0x0c036a80  e022  mov   #34,r0
0x0c036a82  0455  mov.w r5,@(r0,r4)
0x0c036a84  e020  mov   #32,r0
0x0c036a86  0455  mov.w r5,@(r0,r4)
0x0c036a88  6053  mov   r5,r0
0x0c036a8a  814f  mov.w r0,@(30,r4)
0x0c036a8c  814e  mov.w r0,@(28,r4)
0x0c036a8e  140a  mov.l r0,@(40,r4)
0x0c036a90  d31e  mov.l @(120,pc),r3       ; the word for the structure's +36
0x0c036a92  000b  rts                       ; and it is the rts's delay slot
```

Four details of that listing are worth naming, because each one is easy to lose
in a readable port:

* **the branch's delay slot sets the marker on both paths.** `mov #-1,r6` runs
  before the branch is resolved, so `r6` is -1 whichever way the branch goes.
* **the two paths do not share their writes.** The path that falls through
  writes the structure's `+20` in the delay slot of the `bra` that leaves it,
  while the other path writes it explicitly. A port that hoists the four
  writes into one loop has to keep that difference.
* **the T bit the caller sees is the one of the test the guest branched on**,
  so it is set when the flag word is zero and clear when it is not.
* **the word that lands in the structure's `+36` is stored in the `rts`'s
  delay slot**, so the store happens before the function returns.

## The evidence

`tests/range_init_replay.c` runs the readable port and the retained generated
translation of the same function over four scenarios and compares **the whole
register file (the FP registers and SR included), the return PC, the failed PC,
the out-of-window counter and every RAM byte**. The port runs twice: once
called directly and once through the readable override, which is how the native
tick reaches it.

```
range_init: 4 differential cases - PASS
```

The scenarios walk the flag word through zero, one, a negative word and a large
one - only zero and not-zero are different to the guest.

The test also checks the result **against the fixture itself**: the structure
has to hold the words, the halfwords and the tail word the function is
supposed to put there, and the bytes past the structure's forty-four have to
keep the pattern they started with. A differential alone is not enough,
because a fixture that is not where the guest looks makes both sides read the
same wrong bytes and agree on them.

### The test has teeth, and the mutations were checked

The mutations are checked with `tools/mutate.py`, which applies one at a time
to the port's source, rebuilds and requires the test to fail. The list lives
in `tests/range_init_mutations.json`, next to the test it guards.

* the branch inverted fails with the differing `SR` named
  (`v17 00000301` != `00000300`);
* the marker not -1 fails with the differing `r6` named
  (`v6 ffffffff` != `00000001`);
* the range's first word swapped fails with the differing structure byte named
  (`ram 88 00` != `ff`);
* the range's second word swapped fails with the differing structure byte named
  (`ram 92 ff` != `00`);
* the range's third word swapped fails with the differing structure byte named
  (`ram 96 00` != `ff`);
* the range's fourth word swapped fails with the differing structure byte named
  (`ram 100 00` != `ff`);
* the other path's first word swapped fails with the differing structure byte
  named (`ram 88 ff` != `00`);
* the other path's fourth word swapped fails with the differing structure byte
  named (`ram 100 ff` != `00`);
* the structure's second word not zero fails with the differing structure byte
  named (`ram 84 00` != `ff`);
* a halfword's offset wrong fails with the differing structure byte named
  (`ram 104 00` != `7e`);
* a halfword taking the marker fails with the differing structure byte named
  (`ram 114 00` != `ff`);
* the last word taking the flag word fails with the differing structure byte
  named (`ram 120 00` != `01`);
* the last word written past the structure fails with the differing structure
  byte named (`ram 120 00` != `7e`) - the bytes past the structure keep the
  pattern, and the expectation sees it;
* the flag word not dereferenced fails with the differing `SR` named
  (`v17 00000301` != `00000300`);
* the flag's pool slot wrong fails outright;
* the tail word's pool slot wrong fails with the differing `r3` named
  (`v3 0badf00d` != `00000000`);
* the T bit always set fails with the differing `SR` named
  (`v17 00000300` != `00000301`).

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
`0x8C036A58` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The flag word is behind a pointer, and it decides the range's shape.
* The two paths write the four range words differently.
* The marker is -1, and the branch's delay slot sets it on both paths.
* The T bit is the one of the test the guest branched on.

## The unknown

What the range means and who calls this are not recoverable offline: the
pool's values and the code live in the game's own image, which is under
`extract/`. The port therefore reads the same addresses the guest reads, and
what the four words stand for stays open until the image is back.
