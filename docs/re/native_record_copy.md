# native_record_copy (0x8C043A7C)

The engine's twenty-four-record repack, ported natively in
`src/native/record_copy.c` (`vf3_native_record_copy`) as a plain-C transcription
of the readable port `src/fight/record_copy.c` (`vf3_record_copy_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody,
uses no FPU and keeps **no stack frame** - with a fixed **do-while** loop over
twenty-four records (no branch tree), so it is the simplest possible native
target: pool-pointer indirections plus a loop whose exit test is a T bit the
body itself bumps.

## The body

The function copies twenty-four records from the table (pool `0x0c043b78`) into
the destination array (pool `0x0c043b74`).  The source's records are `0x2c`
apart with the first at `+0x28` of the table's cell (the table is read through
**two** indirections: the pool gives the table, its cell gives the source's
base); the destination's are `0x18` apart.  Per record the two records do not
have the same shape:

| source            | destination        |
|-------------------|--------------------|
| byte  0.. 3       | byte  0.. 3        |
| byte  8..11       | byte  4.. 7        |
| word 16..19       | word  8..11        |
| word 20..23       | word 12..15        |

The destination's last eight bytes of every record are left alone.  Details the
port keeps: the loop's exit test is the **T bit** of a compare the body has
already bumped (set at the top of every iteration), so the T bit the caller
sees is the last iteration's (set); and the bytes are **sign-extended** into
the register they travel through.

## Evidence

The **differential** (`tests/record_copy_native_replay.c`, target
`vf3nativerecord_copy`) runs the native port against the readable guest port
from the same seed.  The pool, the table's cell, the destination array and the
source records sit at the game's own addresses in one flat buffer (~3.6 MB).
The whole region is compared byte for byte, together with the registers
(r0..r15), the T bit (the exit compare leaves it set) and the destination's
records against an independent model written in the test - including the bytes
the leaf does not write (the destination's last eight of every record start as
`0x7e` and must stay that way).  **PASS.**  Every source byte carries its own
offset within the record (`0xa0 + i + b`), so `word16 != word20` and
`byte8 != byte9` and every source-position mistake is visible.

The **mutation gate** (`tests/record_copy_native_mutations.json`) applies twelve
mutations mapped onto the native lines: the two pool pointers swapped, the
record count off by one, the source stride, the destination stride and the
first-record offset off by one, the loop running an extra iteration, the two
words read from the wrong place, the second word group one byte high, the first
byte not written, and the source not advancing.  The differential catches
**all 12**.  (The first version of the gate reported three of these MISSED
because the fixture wrote every byte of a source record with the same value -
so `word16 == word20` and `byte8 == byte9` and swapping them changed nothing.
Giving each offset its own value made them observable.)

```text
build\vf3nativerecord_copy.exe ->
  record_copy_native_replay: PASS
python tools/mutate.py --port src/native/record_copy.c --exe build/vf3nativerecord_copy.exe \
    --mutations tests/record_copy_native_mutations.json --target vf3nativerecord_copy \
    --keep-going
  12/12 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated` is closed per the readable authority.

## Notes

* The flat buffer base equals the **pool's** base (`0x0c043b70`, the lowest
  guest address), and the buffer spans the pool, the destination array, the
  table's cell and all twenty-four source records (up to `0x0c3b0448`).
* A fixed do-while loop needs no scenario table: the test runs the single
  fixture once and relies on the independent model + the full-region byte
  compare for the proof.
