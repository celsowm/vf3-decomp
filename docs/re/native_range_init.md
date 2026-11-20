# native_range_init (0x8C036A58)

The fight engine's structure initialiser, ported natively in
`src/native/range_init.c` (`vf3_native_range_init`) as a plain-C transcription
of the readable port `src/fight/range_init.c` (`vf3_range_init_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody,
uses no FPU and keeps **no stack frame at all**.  Its whole effect is the
writes to a forty-four byte structure (plus the register file and the T bit),
so it isolates the pool-pointer read and the delayed writes without any frame
arithmetic in the way.

## The body

The engine keeps a forty-four byte structure and this function sets it up.
Most of it is zeroed, but four words in the middle (at +8/+12/+16/+20) carry a
range whose shape depends on the first word of whatever the pool at
`0x0c036af0` points at:

- the flag word is zero  ->  `0, -1, 0, 0`
- the flag word is not   ->  `-1, 0, -1, -1`

The word that lands at the structure's +36 comes from the pool at `0x0c036b0c`.
The remaining four halfwords (+24..+34) and the word at +40 are zero.

Two details the port keeps: the branch's **delay slot** sets the marker (r5=0
and r6=-1) on both paths before the branch, the two paths do **not** share
their writes (one of them stores the structure's +20 in the delay slot of the
branch that leaves it), and the word at +36 is stored in the `rts`'s delay
slot.  The T bit is set on the zero path and clear on the non-zero one.

## Evidence

The **differential** (`tests/range_init_native_replay.c`, target
`vf3nativerangeinit`) runs the native port against the readable guest port from
the same seed over the same four scenarios as the readable test - a zero flag,
a set one, a negative one and a large one (all non-zero).  The literal pool,
the flag word and the structure sit at the game's own addresses in one flat
buffer (the structure starts full of a pattern, so a byte the leaf does not
write shows up).  The whole region is compared byte for byte, together with the
registers, the T bit and the structure against an independent model written in
the test.  **4/4 PASS.**

The **mutation gate** (`tests/range_init_native_mutations.json`) applies
fourteen mutations mapped onto the native lines: both pool entries wrong, the
flag read from the second cell word, the two range shapes swapped, the range's
first and last words at the wrong offsets, the marker -2, the zero 1, the second
word written over the first, the first halfword and the second end word at the
wrong offsets, the tail word at the wrong offset, and the T bit of each path
flipped.  The differential catches **all 14**.

```text
build\vf3nativerangeinit.exe ->
  range_init_native_replay: PASS
python tools/mutate.py --port src/native/range_init.c --exe build/vf3nativerangeinit.exe \
    --mutations tests/range_init_native_mutations.json --target vf3nativerangeinit \
    --keep-going
  14/14 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority.

## Notes

* The leaf keeps **no stack frame**, so the native test only has to check the
  output registers, the T bit and the structure.
* The flat buffer base equals the **pool's** base (`0x0c036ae0`, the lowest
  guest address), and the buffer spans three windows that are far apart (the
  flag word sits ~1 MB from the pool at `0x0c140000`), so the allocation has to
  cover from `0x0c036ae0` to the structure's end `0x0c150040`.
