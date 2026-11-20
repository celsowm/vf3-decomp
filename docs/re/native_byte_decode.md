# native_byte_decode (0x8C04538A)

The word decoder - a word off the caller's stack, turned around or not, and
the answer its first byte carries - ported natively in
`src/native/byte_decode.c` (`vf3_native_byte_decode`) as a plain-C
transcription of the readable port `src/fight/byte_decode.c`
(`vf3_byte_decode_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody
and touches no FPU, but it reads out of the caller's stack *and* its own, a
table's base is a **signed halfword added to a 32-bit word**, and the answer's
three arms each end in a branch whose delay slot is the store.  It is exactly
the boundary the native `aim_math` register file + SR model is built for.

## The body

The engine calls this with a word on the caller's stack (r5 points at it).
The function pops that word, pushes it on its own stack, and copies its four
bytes into the object at +8..+11 - in the natural order, or turned around,
depending on a table.

- The caller's word is read from `[r5]` (r5 then moves on past it) and pushed
  at `r15 - 4`; the four bytes are read back **out of the stack**, so the push
  is part of the contract.
- The table's global (`0x0c045454`) points at a cell holding the table's first
  word; the pool's base (`0x0c04544a`) is a **signed halfword** added to it,
  and the entry there asks whether the bytes turn around (`1`).
- The object's byte at +8 then decides the answer, written at the object's
  +20: the byte equals the mark (`0x0c045448`) - the answer is -1; the byte is
  at or above the limit (`0x0c04544c`), compared **signed** - the answer is
  the caller's *next* word; otherwise the answer is zero.
- The byte-order test's T bit is unobservable - the mark's `cmp/eq` overwrites
  it - so the T bit the caller sees is the mark test's, or the limit test's.

## Evidence

The **differential** (`tests/byte_decode_native_replay.c`, target
`vf3nativebyte_decode`) runs the native port against the readable guest port
from the same seed.  The literal pool, the table's cell, the table, the
caller's stack and the object sit at the game's own addresses, spanned by one
flat buffer (whose base is the *table's* first word, the lowest address the
leaf reads).  The whole region is compared byte for byte, together with the
registers, SR's T bit and an independent fixture model that computes the
object's bytes, the answer and the T bit straight from the fixture.  The
scenarios cover the two byte orders, the mark, the limit, a first byte
exactly at the limit, a limit of 255, a negative limit and an entry that is
not the turned-around one.  **11/11 PASS.**

The **mutation gate** (`tests/byte_decode_native_mutations.json`) applies ten
mutations mapped onto the native lines: the mark, limit, base and table read
from the wrong pool slot, the turned-around test flipped, the decision byte
read from the object's last byte instead of its first, the mark and limit
comparisons inverted, and the answer and the pushed word read from the wrong
stack word.  The differential catches **all 10**.

```text
build\vf3nativebyte_decode.exe ->
  byte_decode_native_replay: PASS  (11/11)
python tools/mutate.py --port src/native/byte_decode.c --exe build/vf3nativebyte_decode.exe \
    --mutations tests/byte_decode_native_mutations.json --target vf3nativebyte_decode \
    --keep-going
  10/10 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority (the readable port itself is differential-and-oracle-replayed,
`docs/re/byte_decode.md`).

## Notes

* The flat buffer base equals the **table's** base (`0x0c030000`), the lowest
  address the leaf reads; the buffer spans the pool (`0x0c045440`), the cell
  (`0x0c050000`), the table, the stack (`0x0c110000`) and the object
  (`0x0c120000`) up to `0x0c120040`.
* The model computes the pushed byte order from the little-endian store: the
  natural order puts the word's low byte at the object's +8.
* The `>=` vs `>` comparison at the limit is pinned by a scenario whose first
  byte sits exactly on the limit, where the two answers differ.
