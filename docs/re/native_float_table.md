# native_float_table (0x8C06D792)

The engine's table-entry unpack into two structures, ported natively in
`src/native/float_table.c` (`vf3_native_float_table`) as a plain-C
transcription of the readable port `src/fight/float_table.c`
(`vf3_float_table_entry`).  It is the sibling of `entry_copy` (0x8C06D7D6,
`native_entry_copy.md`) and shares its pool slots.

## Why this leaf

The readable authority is a **self-contained leaf** - it calls nobody, keeps
**no stack frame** - and uses the **FR bank** for the entry's three floats.  It
is the native target for the **four-bit index mask** (as opposed to
`entry_copy`'s whole-byte index), the **two-indirection second structure** and
the **signed halfword offset** that can point below the structure.

## The body

The engine keeps a table of sixteen-byte entries and an index byte.  The
function looks an entry up and unpacks it into two structures:

- the entry's two halfwords - at its +12 and +14 - go into the first structure
  at its +32 and its +34 (the entry's +12 lands at +32 and its +14 at +34, the
  guest's swap);
- the entry's three floats - at its +16, +20 and +24 - go into the second
  structure at the signed halfword offset the pool holds (0x0c06d87e), at eight
  bytes below that offset and at four bytes below it.

The index is the low **four** bits of the index byte, the entries are
sixty-four bytes apart, the second structure is reached through **two**
indirections (the pool gives a cell, the cell gives the structure), and the
pool's values are read at run time.

## Evidence

The **differential** (`tests/float_table_native_replay.c`, target
`vf3nativefloat_table`) runs the native port against the readable guest port
from the same seed.  The pool, the index byte, the table, the two structures
and the pointer cell sit at the game's own addresses in one flat buffer (~1.1
MB).  The whole region is compared byte for byte, together with the registers
(r0..r15), the FR bank and the unpacked values against an independent
fixture-based model.  The scenarios walk the index (the first and last entries,
the four-bit masked byte `0xf3`, the unsigned byte `0x93`) and vary the pool
offset (positive `0x20`, negative `-0x10`, large `0x60`).  **6/6 PASS.**

The **mutation gate** (`tests/float_table_native_mutations.json`) applies
thirteen mutations mapped onto the native lines: the five pool entries read
from the wrong place; the index mask widened to five bits; the halfwords read
and stored un-swapped; the three floats read from the wrong entry offsets; and
the three float stores landing at the wrong position.  The differential catches
**all 13**.

```text
build\vf3nativefloat_table.exe ->
  float_table_native_replay: PASS
python tools/mutate.py --port src/native/float_table.c --exe build/vf3nativefloat_table.exe \
    --mutations tests/float_table_native_mutations.json --target vf3nativefloat_table \
    --keep-going
  13/13 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated` is closed per the readable authority.

## Notes

* The flat buffer base equals the **pool's** base (`0x0c06d870`, the lowest
  guest address), and the buffer spans the pool, the index byte, the whole
  16-entry table, both structures and the pointer cell (up to `0x0c180010`).
* The two halfword writes each land one after the other in the first structure;
  the model checks the swap the guest makes (entry +12 -> structure +32, entry
  +14 -> structure +34), which the differential and the mutation gate both pin.
* The float loads/stores are single-precision (the captured FPSCR is `0`).
