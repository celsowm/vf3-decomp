# native_range_flag (0x8C0CAA9C)

The fight engine's out-of-range flag, ported natively in `src/native/range_flag.c`
(`vf3_native_range_flag`) as a plain-C transcription of the readable port
`src/fight/range_flag.c` (`vf3_range_flag_entry`).

## Why this leaf

The readable authority is a **self-contained HP leaf** - it calls nobody and
keeps **no stack frame**, but it reads the literal pool, the record and the
byte of flags, and it uses the **FR bank** for the four float values and the
two bounds.  It is also one of the readable ports whose float loads go through
the shared helpers (so the frame registers are part of the contract), which
is exactly the boundary the native `aim_math` FR bank models.

## The body

The caller hands over a record (r4) that holds a byte of flags and four
floats.  The function sets the byte's 0x10 bit when one of the four floats is
outside the range the two bounds describe, and clears it again when they are
all inside - but only when the byte's own 0x40 bit says the values have to be
looked at at all.

- The offsets of the byte and of the first float, and the two bounds, are the
  literal pool's entries at 0x0c0cab1a/1c/20/24, read at run time.
- The four floats sit at the record + the value offset, +12, -24 and -12 (the
  guest's own offset arithmetic: 6@off, 7@off+12, 8@off+12-36, 9@+12-36+12).
- The **gate**: the byte's 0x40 bit.  When the byte has no bit in common with
  it the function returns immediately - it does **not** even write the byte
  back.
- The chain short-circuits: each value is tested "above the upper bound then
  the running "below the lower bound" test", and the first positive answer
  sets `out` and stops; the later comparisons do not run.  A value on a bound
  is still in range (`>` and `<`, not `>=`/`<=`).
- The two arms are **not symmetric**: when `out` the 0x10 bit is or-ed in;
  when everything is inside the flag is cleared with a **mask**
  (`& 0xffffffef`, which takes the neighbouring bit with it) rather than by
  writing a zero.
- The T bit the guest leaves is the one of the **last comparison that ran**.

## Evidence

The **differential** (`tests/range_flag_native_replay.c`, target
`vf3nativerange_flag`) runs the native port against the readable guest port
from the same seed.  The pool and the record sit at the game's own addresses
(~2.2 MB apart) spanned by one flat buffer.  The whole region is compared
byte for byte, together with the registers (r0..r15), the FR bank and the T
bit, and the flag byte's value against an independent fixture-based model
written in the test.  The scenarios cover the byte's "do not look" bit being
clear, everything in range, a value above the upper bound, a value below the
lower one, a value only the last test catches and a mixture.  **6/6 PASS.**

The **mutation gate** (`tests/range_flag_native_mutations.json`) applies
fourteen mutations mapped onto the native lines: the four pool entries read
from the wrong slot, the check and out bits swapped, the gate inverted, the
values read from a sibling position, the first comparison against the wrong
bound / inverted, the second test against the wrong bound, the chain stopping
at the third value, and the "off" arm clearing with a zero instead of a mask.
The differential catches **all 14**.

```text
build\vf3nativerange_flag.exe ->
  range_flag_native_replay: PASS  (6/6)
python tools/mutate.py --port src/native/range_flag.c --exe build/vf3nativerange_flag.exe \
    --mutations tests/range_flag_native_mutations.json --target vf3nativerange_flag \
    --keep-going
  14/14 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority (the readable port itself is oracle-replayed, `docs/re/range_flag.md`).

## Notes

* The flat buffer base equals the **pool's** base (`0x0c0cab10`), and the
  buffer spans the pool, the record (at `0x0c300000`) and the gap between
  them.
* The fixture's model reads the floats through the guest's own offset
  positions (6@off, 7@+12, 8@-24, 9@-12), and computes the expected flag and
  T bit independently of both the native and the readable code.
* The FR bank is compared as raw 32-bit values, so a sign or rounding
  difference between the two sides would show up as a frame-register
  mismatch as well as a RAM mismatch.
