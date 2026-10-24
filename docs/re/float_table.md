# The table unpack (SH-4 0x8C06D792)

A readable port of the fight engine's table unpack, and the evidence for it.

## The function

`0x8C06D792` looks a table entry up and unpacks it into two structures.

* the **index byte** is the byte the pool points at (`0x8C06D89C`). The guest
  reads it as a *signed* byte and then as an unsigned one, and the index is
  the low **four** bits of that;
* the **table** is the word in the pool at `0x8C06D8A8`, and its entries are
  **sixty-four bytes apart**;
* the **first structure** is the word in the pool at `0x8C06D8A4`. The entry's
  two halfwords - at the entry's `+12` and `+14` - go into it at its `+32` and
  `+34`, and they are **swapped** on the way: the halfword at the entry's `+12`
  lands at the structure's `+32`;
* the **second structure** is reached through *two* indirections: the pool at
  `0x8C06D890` gives a cell, and the cell gives the structure. The entry's
  three floats - at the entry's `+16`, `+20` and `+24` - go into it at the
  **signed** halfword offset the pool holds at `0x8C06D87E`, at eight bytes
  below that offset and at four below it.

The port: `src/fight/float_table.c`, registered in `src/fight/readable.c` as
`float_table`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode, and
the original opcode word in a comment. That makes them a faithful disassembly
of the function they implement, so a readable port can be written against them
without the ROM.

* `tools/adapter_owner.py 0x0c06d792 --body` - resolves which module the router
  actually serves for a PC. One module carries the copy (`tickgap_adapter`).
* `tools/handwritten_entries.py 0x0c06d792` - confirms that no hand-written
  module already serves this entry, so the port is not shadowed.
* The listing below is decoded with `tools/sh4.py`, the repo's authoritative
  decoder, from the opcode words the module carries; the semantics come from
  the translator's emitted C.

The guest code, decoded:

```
0x0c06d792  d342  mov.l @(264,pc),r3      ; the index byte's address
0x0c06d794  e40f  mov   #15,r4
0x0c06d796  d244  mov.l @(272,pc),r2      ; the table
0x0c06d798  6030  mov.b @r3,r0            ; the index byte
0x0c06d79a  d742  mov.l @(264,pc),r7      ; the first structure
0x0c06d79c  600c  extu.b r0,r0            ; and the byte as an unsigned one
0x0c06d79e  d13c  mov.l @(240,pc),r1      ; the second structure's cell
0x0c06d7a0  2409  and   r0,r4             ; four bits of the index
0x0c06d7a2  4408  shll2 r4
0x0c06d7a4  4408  shll2 r4
0x0c06d7a6  4408  shll2 r4                ; sixty-four bytes apart
0x0c06d7a8  342c  add   r2,r4             ; the entry
0x0c06d7aa  8546  mov.w @(12,r4),r0       ; the entry's first halfword
0x0c06d7ac  6603  mov   r0,r6
0x0c06d7ae  8547  mov.w @(14,r4),r0       ; and its second
0x0c06d7b0  6503  mov   r0,r5
0x0c06d7b2  e010  mov   #16,r0
0x0c06d7b4  f446  fmov.s @(r0,r4),fr4     ; and its three floats
0x0c06d7b6  e014  mov   #20,r0
0x0c06d7b8  f546  fmov.s @(r0,r4),fr5
0x0c06d7ba  e018  mov   #24,r0
0x0c06d7bc  f646  fmov.s @(r0,r4),fr6
0x0c06d7be  e022  mov   #34,r0
0x0c06d7c0  6412  mov.l @r1,r4            ; the second structure
0x0c06d7c2  0755  mov.w r5,@(r0,r7)       ; the second halfword into the first structure
0x0c06d7c4  e020  mov   #32,r0
0x0c06d7c6  0765  mov.w r6,@(r0,r7)       ; and the first
0x0c06d7c8  9059  mov.w @(178,pc),r0      ; where the floats land
0x0c06d7ca  f447  fmov.s fr4,@(r0,r4)
0x0c06d7cc  70f8  add   #-8,r0
0x0c06d7ce  f457  fmov.s fr5,@(r0,r4)
0x0c06d7d0  7004  add   #4,r0
0x0c06d7d2  000b  rts                     ; the third float is the rts's delay slot
```

Five details of that listing are worth naming, because each one is easy to lose
in a readable port:

* **the entry's stride is sixty-four bytes, and it is built out of three
  shifts.** `shll2` three times is sixty-four, and the port has to shift three
  times: a port that shifts four times lands in the wrong entry, and one that
  shifts twice lands in a different wrong entry.
* **the two halfwords are swapped on the way.** The entry's `+12` goes to the
  structure's `+32` and the entry's `+14` to the structure's `+34`.
* **the offset is a signed halfword.** The three floats land at the offset, at
  eight bytes below it and at four below it, and a negative offset puts them
  *below* the structure.
* **the second structure is reached through two indirections**: the pool gives
  a cell, and the cell gives the structure. Reading the pool's word as the
  structure itself is a different access, which the out-of-window counter
  sees.
* **the last float is stored in the `rts`'s delay slot**, so the store happens
  before the function returns and the port has to do it too.

## The evidence

`tests/float_table_replay.c` runs the readable port and the retained generated
translation of the same function over six scenarios and compares **the whole
register file (the FP registers and SR included), the return PC, the failed PC,
the out-of-window counter and every RAM byte**. The port runs twice: once
called directly and once through the readable override, which is how the native
tick reaches it.

```
float_table: 6 differential cases - PASS
```

The test lays the literal pool, the index byte, the table, the two structures
and the pointer cell out the way the guest expects. The scenarios cover the
first and the last entry, an index that the four-bit mask cuts down, an index
byte that is read as an unsigned one, a negative offset for the three floats
and a large one.

The test also checks the result **against the fixture itself**: the first
structure's two halfwords and the second structure's three floats have to be
the ones the entry holds. A differential alone is not enough, because a
fixture that is not where the guest looks makes both sides read the same wrong
bytes and agree on them - the trap the record repack's test fell into.

**The out-of-window counter earned its keep on this one.** The first version
of the port shifted four times instead of three, and the fixture's table was
laid out for a sixteen-byte stride, so both sides read inside the window and
agreed - on the *first* entry, where the index is zero and the stride does not
matter. The scenario for the last entry is what caught it: the port walked
past the end of the table and the counter went to sixteen.

### The test has teeth, and the mutations were checked

The mutations are checked with `tools/mutate.py`, which applies one at a time
to the port's source, rebuilds and requires the test to fail. The list lives
in `tests/float_table_mutations.json`, next to the test it guards.

* the index masked to five bits fails outright - the masked index walks past
  the end of the table;
* the index masked to two bits fails with the differing `r5` named
  (`v5 0000200f` != `00002003`);
* one shift too many in the entry's stride fails outright - the scenario for
  the last entry is what sees it;
* the two halfwords not swapped fails with the differing structure byte named
  (`ram 1129 10` != `20`);
* the first halfword read from the other one fails with the differing `r6`
  named (`v6 00001000` != `00002000`);
* the first float read from the second fails with the differing `FR4` named
  (`v25 3f800000` != `40000000`);
* the third float read from the second fails with the differing `FR6` named
  (`v27 40400000` != `40000000`);
* the first float stored into the second register fails with the differing
  structure byte named (`ram 1226 80` != `00`);
* the second float four bytes too high fails with the differing `r0` named
  (`v0 0000001c` != `00000020`);
* the third float not moved back fails with the differing `r0` named
  (`v0 0000001c` != `00000018`);
* the second structure not dereferenced fails outright;
* the index byte's pool slot wrong fails outright;
* the table's pool slot wrong fails with the differing `r2` named
  (`v2 0c150000` != `0c160000`);
* the offset's pool slot wrong fails with the differing `r0` named
  (`v0 0000001c` != `fffffffc`);
* the first structure's pool slot wrong fails with the differing `r7` named
  (`v7 0c160000` != `0c150000`).

One mutation is *not* caught, and correctly so: dropping the `extu.b` that
makes the index byte an unsigned one changes nothing, because the index is
masked to four bits afterwards and the signed and the unsigned byte have the
same low four bits. The bit is unobservable, so the port's choice there is
free.

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
`0x8C06D792` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The index is the low four bits of the index byte, and the entries are
  sixty-four bytes apart.
* The entry's two halfwords are swapped on the way to the first structure.
* The entry's three floats go into the second structure at the signed offset,
  at eight bytes below it and at four below it.
* The second structure is behind two indirections.

## The unknown

What the table holds and who calls this are not recoverable offline: the
pool's values and the code live in the game's own image, which is under
`extract/`. The port therefore reads the same addresses the guest reads, and
what the entries mean stays open until the image is back.
