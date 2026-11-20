# native_entry_copy (0x8C06D7D6)

The engine's table-entry-field copy into two places, ported natively in
`src/native/entry_copy.c` (`vf3_native_entry_copy`) as a plain-C transcription
of the readable port `src/fight/entry_copy.c` (`vf3_entry_copy_entry`).

## Why this leaf

The readable authority is a **self-contained leaf** - it calls nobody and keeps
**no stack frame** - but it uses the **FR bank** for the entry's five floats.
It is the native target for the **pool-at-run-time** convention combined with
the **FR-bank** loads/stores and the **sign-extended byte/halfword** reads.

## The body

The engine keeps a table of sixty-four-byte entries and a structure with a
pair of offsets in it.  This function looks an entry up and copies some of its
fields into the structure, twice: once at each offset.

- The entry is picked by the **whole** index byte, so the table has 256
  entries, each sixty-four bytes apart (the guest builds the index with three
  left shifts of the byte - an index of N reads table + 64*N).
- The entry's three bytes - at its +5, +6 and +7 - go into the structure at
  the first offset and at the second one, three bytes apart in each case.
- The entry's five floats go to two groups:

  | first offset | second offset |
  |--------------|---------------|
  | FR5 from +28 at off-20 | FR7 from +24 at off-12 |
  | FR8 from +32 at off-16 | FR4 from +16 at off-16 |
  | FR6 from +36 at off-4  |               |

The two offsets are signed halfwords in the literal pool (`0x0c06d880` and
`0x0c06d882`), so they can point below the structure; the pool's values are
read at run time.  The bytes are sign-extended into the register they travel
through, and the last float is stored in the `rts`'s delay slot.

## Evidence

The **differential** (`tests/entry_copy_native_replay.c`, target
`vf3nativeentry_copy`) runs the native port against the readable guest port
from the same seed.  The pool, the index byte, the table, the structure and
the pointer cell sit at the game's own addresses in one flat buffer (~1.2 MB).
The whole region is compared byte for byte, together with the registers
(r0..r15), the FR bank and the copied fields against an independent
fixture-based model.  The scenarios walk the index from the first entry to the
last (including the high index `0xc8` that only the whole-byte pick reaches)
and vary the two offsets (both positive, both negative, and the same).  The
model's `want` array is the full structure window with the structure at
`STRUCT_AT`, so negative offsets land inside it.  **6/6 PASS.**

The **mutation gate** (`tests/entry_copy_native_mutations.json`) applies
thirteen mutations mapped onto the native lines: the pool entries (four of
them) read from the wrong place; the entry picked at half the stride or by
four bits instead of the whole byte; the two group's source floats swapped;
the first byte read from or landed in the wrong register; and the three
first-group stores and the last store written to the wrong float or the wrong
offset.  The differential catches **all 13**.  (The first version of the gate
had a mutation targeting the `ENTRY_STRIDE` define, which the port does not
use - the guest builds the index with three `<<= 2` shifts - so it was dead;
it now targets the shifts themselves and is caught.)

```text
build\vf3nativeentry_copy.exe ->
  entry_copy_native_replay: PASS
python tools/mutate.py --port src/native/entry_copy.c --exe build/vf3nativeentry_copy.exe \
    --mutations tests/entry_copy_native_mutations.json --target vf3nativeentry_copy \
    --keep-going
  13/13 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated` is closed per the readable authority.

## Notes

* The flat buffer base equals the **pool's** base (`0x0c06d870`, the lowest
  guest address), and the buffer spans the pool, the index byte, the whole
  256-entry table, the structure window and the pointer cell (up to
  `0x0c1a0010`).
* The native FR bank is seeded with the same running pattern the guest's
  untouched (non-written) registers carry, so the full-bank compare is
  meaningful: the leaf only writes FR4/5/6/7/8 and the other eleven must start
  at the guest's seed.
* The float loads/stores are single-precision (the captured FPSCR is `0`), so
  the port uses 4-byte FR reads/writes - the double-width case is not
  exercised by the corpus.
