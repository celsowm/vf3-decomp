# The entry copy (SH-4 0x8C06D7D6)

A readable port of the fight engine's entry copy, and the evidence for it.

## The function

`0x8C06D7D6` looks an entry up in the engine's table and copies some of its
fields into a structure, twice: once at each of the two offsets the pool
holds.

* the **index byte** is the byte the pool points at (`0x8C06D89C`), and the
  **whole** byte is the index - the table has 256 entries, not sixteen;
* the **table** is the word in the pool at `0x8C06D8A8`, and its entries are
  **sixty-four bytes apart**;
* the **structure** is reached through *two* indirections: the pool at
  `0x8C06D890` gives a cell, and the cell gives the structure;
* the **offsets** are signed halfwords in the pool, at `0x8C06D880` and
  `0x8C06D882`.

The entry's three bytes - at its `+5`, `+6` and `+7` - go into the structure
at the first offset and at the second one, three bytes apart in each case. The
entry's five floats go to two groups as well:

| group | what | where in the structure |
| ----- | ---- | ---------------------- |
| first | the entry's float at `+28` | offset - 20 |
| first | the entry's float at `+32` | offset - 16 |
| first | the entry's float at `+36` | offset - 4 |
| second | the entry's float at `+24` | offset - 12 |
| second | the entry's float at `+16` | offset - 16 |

The port: `src/fight/entry_copy.c`, registered in `src/fight/readable.c` as
`entry_copy`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode, and
the original opcode word in a comment. That makes them a faithful disassembly
of the function they implement, so a readable port can be written against them
without the ROM.

* `tools/adapter_body.py 0x0c06d7d6 --span 100` - the body, in the module
  that carries it (`fight_adapters_0`).
* `tools/handwritten_entries.py 0x0c06d7d6` - confirms that no hand-written
  module already serves this entry, so the port is not shadowed.
* The listing below is decoded with `tools/sh4.py`, the repo's authoritative
  decoder, from the opcode words the module carries; the semantics come from
  the translator's emitted C.

The guest code, decoded:

```
0x0c06d7d6  d331  mov.l @(196,pc),r3      ; the index byte's address
0x0c06d7d8  d233  mov.l @(204,pc),r2      ; the table
0x0c06d7da  6430  mov.b @r3,r4            ; the index byte
0x0c06d7dc  d12c  mov.l @(176,pc),r1      ; the cell with the structure's address
0x0c06d7de  654c  extu.b r4,r5            ; the byte as an unsigned one
0x0c06d7e0  4508  shll2 r5
0x0c06d7e2  6412  mov.l @r1,r4            ; the structure
0x0c06d7e4  4508  shll2 r5
0x0c06d7e6  4508  shll2 r5                ; sixty-four bytes apart
0x0c06d7e8  352c  add   r2,r5             ; the entry
0x0c06d7ea  8455  mov.b @(5,r5),r0        ; the entry's three bytes
0x0c06d7ec  6603  mov   r0,r6
0x0c06d7ee  8456  mov.b @(6,r5),r0
0x0c06d7f0  6703  mov   r0,r7
0x0c06d7f2  8457  mov.b @(7,r5),r0
0x0c06d7f4  6103  mov   r0,r1
0x0c06d7f6  e01c  mov   #28,r0
0x0c06d7f8  f556  fmov.s @(r0,r5),fr5     ; and its five floats
0x0c06d7fa  e020  mov   #32,r0
0x0c06d7fc  f856  fmov.s @(r0,r5),fr8
0x0c06d7fe  e024  mov   #36,r0
0x0c06d800  f656  fmov.s @(r0,r5),fr6
0x0c06d802  e018  mov   #24,r0
0x0c06d804  f756  fmov.s @(r0,r5),fr7
0x0c06d806  e010  mov   #16,r0
0x0c06d808  f456  fmov.s @(r0,r5),fr4
0x0c06d80a  9039  mov.w @(114,pc),r0      ; the first offset
0x0c06d80c  0464  mov.b r6,@(r0,r4)       ; the three bytes
0x0c06d80e  7001  add   #1,r0
0x0c06d810  0474  mov.b r7,@(r0,r4)
0x0c06d812  7001  add   #1,r0
0x0c06d814  0414  mov.b r1,@(r0,r4)
0x0c06d816  70ea  add   #-22,r0
0x0c06d818  f457  fmov.s fr5,@(r0,r4)      ; and three of the floats
0x0c06d81a  7004  add   #4,r0
0x0c06d81c  f487  fmov.s fr8,@(r0,r4)
0x0c06d81e  700c  add   #12,r0
0x0c06d820  f467  fmov.s fr6,@(r0,r4)
0x0c06d822  902e  mov.w @(92,pc),r0       ; the second offset
0x0c06d824  0464  mov.b r6,@(r0,r4)       ; and the same three bytes
0x0c06d826  7001  add   #1,r0
0x0c06d828  0474  mov.b r7,@(r0,r4)
0x0c06d82a  7001  add   #1,r0
0x0c06d82c  0414  mov.b r1,@(r0,r4)
0x0c06d82e  70f2  add   #-14,r0
0x0c06d830  f477  fmov.s fr7,@(r0,r4)      ; and the other two floats
0x0c06d832  70fc  add   #-4,r0
0x0c06d834  000b  rts                      ; the last one is the rts's delay slot
```

Four details of that listing are worth naming, because each one is easy to lose
in a readable port:

* **the index is the whole byte.** The guest reads it as a signed byte and
  then as an unsigned one, and *all eight bits* index the table - the table
  has 256 entries. The sibling function at `0x8C06D792` masks the same byte to
  four bits, so the two functions read the same table at two different depths.
* **the two groups can overlap.** The offsets are the guest's to choose, and
  the second group is written after the first, so where they collide the
  second one wins. A port that writes the groups in one go has to keep the
  order.
* **the bytes are sign-extended** into the registers they travel through, so
  a byte above `0x7F` shows up in `r6`, `r7` and `r1` as a negative number,
  even though the byte written is the low one.
* **the last float is stored in the `rts`'s delay slot**, so the store happens
  before the function returns.

## The evidence

`tests/entry_copy_replay.c` runs the readable port and the retained generated
translation of the same function over six scenarios and compares **the whole
register file (the FP registers and SR included), the return PC, the failed PC,
the out-of-window counter and every RAM byte**. The port runs twice: once
called directly and once through the readable override, which is how the native
tick reaches it.

```
entry_copy: 6 differential cases - PASS
```

The scenarios walk the index from the first entry to the last, put the two
offsets below the structure, and put them at the same place - which is where
the two groups collide.

The test also checks the result **against the fixture itself**: the structure
has to hold the entry's fields where the guest puts them. The expectation is
built by applying the two groups of writes *in the guest's order*, because
where they overlap the second group wins. A differential alone is not enough,
because a fixture that is not where the guest looks makes both sides read the
same wrong bytes and agree on them.

### The test has teeth, and the mutations were checked

The mutations are checked with `tools/mutate.py`, which applies one at a time
to the port's source, rebuilds and requires the test to fail. The list lives
in `tests/entry_copy_mutations.json`, next to the test it guards.

* the index masked to four bits fails with the differing `r1` named
  (`v1 ffffffc8` != `00000008`) - the whole byte is the index, and the
  scenarios with a high index are what see it;
* one shift too few in the entry's stride fails with the differing `r1` named
  (`v1 00000003` != `00000000`);
* the bytes read from the wrong place fails with the differing `r7` named
  (`v7 00000020` != `ffffff80`);
* the last byte read from the wrong place fails with the differing `r1` named
  (`v1 00000000` != `00000020`);
* the byte not sign-extended fails with the differing `r6` named
  (`v6 ffffff80` != `00000080`);
* the first group's float read from the wrong place fails with the differing
  `FR5` named (`v26 40400000` != `40000000`);
* the second group's float read from the wrong place fails with the differing
  `FR7` named (`v28 40000000` != `40400000`);
* the fifth float read from the wrong place fails with the differing `FR4`
  named (`v25 3f800000` != `40000000`);
* the structure not dereferenced fails outright;
* the first group's first float's offset wrong fails with the differing
  structure byte named (`ram 17044 00` != `5a`);
* the first group's second float's step wrong fails with the differing
  structure byte named (`ram 17048 00` != `5a`);
* the first group's last float's offset wrong fails with the differing
  structure byte named (`ram 17056 5a` != `00`);
* the second group's first float's offset wrong fails with the differing `r0`
  named (`v0 00000030` != `00000032`);
* the second group's last float's offset wrong fails with the differing `r0`
  named (`v0 00000030` != `0000002c`);
* the second group storing the first group's float fails with the differing
  structure byte named (`ram 17022 00` != `40`);
* the first offset's pool slot wrong fails with the differing structure byte
  named (`ram 17012 5a` != `00`);
* the second offset's pool slot wrong fails with the differing `r0` named
  (`v0 00000030` != `00000050`);
* the table's pool slot wrong fails outright;
* the index byte's pool slot wrong fails outright.

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
`0x8C06D7D6` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The index is the whole byte, and the entries are sixty-four bytes apart.
* The two offsets are signed halfwords, and the two groups are written in the
  guest's order.
* The bytes are sign-extended into the registers.
* The structure is behind two indirections.

## The unknown

What the table holds and who calls this are not recoverable offline: the
pool's values and the code live in the game's own image, which is under
`extract/`. The port therefore reads the same addresses the guest reads, and
what the fields mean stays open until the image is back.
