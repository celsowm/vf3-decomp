# native_mode_index (0x8C038990)

The fight engine's mode-index switch, ported natively in
`src/native/mode_index.c` (`vf3_native_mode_index`) as a plain-C transcription
of the readable port `src/fight/mode_index.c` (`vf3_mode_index_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody,
uses no FPU and keeps **no stack frame** at all.  Its whole effect is
register-only plus four sign-extended halfword pool reads, so it isolates the
pool-read and T-bit conventions without any frame arithmetic in the way.

## The body

The engine passes a mode **flag** in r4 and this leaf turns it into an
**index** into some table.  Eight flags are known: four are constants (8, 16,
32, 64 -> index 0..3) and four live in the literal pool, read at run time as
sign-extended halfwords from `0x0c038af2/4/6/8` (-> index 4..7).  A flag that
is none of them is **left alone** (the answer is the flag that came in).

Two details the port keeps: the guest compares the four constants against a
**copy** of the flag it made in r0, and the four pool values against the flag
(r4) itself; and the T bit the caller sees is the one of the comparison that
answered, so it is set on a hit and cleared when no flag matched.  The answer
lands in both r4 and r0.

## Evidence

The **differential** (`tests/mode_index_native_replay.c`, target
`vf3nativemodeindex`) runs the native port against the readable guest port from
the same seed over the same nine scenarios as the readable test - the four
constant flags, the four pool flags, one unknown flag - plus an extra
**unknown negative** case (caller flag 0x8444, *not* sign-extended, which must
be left alone, distinguishing it from pool seven whose 0x8444 is sign-extended
to 0xffff8444).  The literal pool sits at the game's own address in one flat
buffer; the test compares the whole region, the answers (r4/r0) and the T bit
against an independent model written into the test.  **10/10 PASS.**

The **mutation gate** (`tests/mode_index_native_mutations.json`) applies
eighteen mutations mapped onto the native lines: each constant's value and
answer wrong, each pool flag taken from the wrong pool entry, each pool answer
the wrong index, the pool flag not sign-extended, the no-match arm setting the
T bit, the answer not copied back to r0, the constants compared against
something other than the r0 copy, and a pool value read as a word instead of a
halfword.  The differential catches **all 18**.  (An early dummy `` `if (0)
return 0u;` `` mutation compiled to nothing and was unobservable; it was
replaced by the word-read mutation, which changes the value read and is
caught.)

```
build\vf3nativemodeindex.exe ->
  mode_index_native_replay: PASS
python tools/mutate.py --port src/native/mode_index.c --exe build/vf3nativemodeindex.exe \
    --mutations tests/mode_index_native_mutations.json --target vf3nativemodeindex \
    --keep-going
  18/18 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority.

## Notes

* The leaf keeps **no stack frame and no callee-saved registers**, so the
  native test only has to check the answers and the T bit, not a frame.
* The four pool reads must be **sign-extended** i16 - pool seven is 0x8444, and
  without the sign extension the negative caller-flag case would collide with
  it.
