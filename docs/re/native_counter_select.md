# native_counter_select (0x8C0C10A2)

The four-threshold counter selection, ported natively in
`src/native/counter_select.c` (`vf3_native_counter_select`) as a plain-C
transcription of the readable port `src/fight/readable/counter_select.c`
(`vf3_counter_select_entry`).

## Why this leaf

The readable authority is a self-contained 124 B leaf
(0x0C0C10A2..0x0C0C111A), **call-free and integer-only (no FP)**.  Unlike the
earlier stack-free leaves it pushes `r14`/`r13` and allocates a 16-byte frame,
so it is the richest of the integer-only leaves so far - its contract includes
a frame of stack words plus the two saved registers, all of which the
differential must witness.

## The body

`r4` is a mask.  The body keeps two running selection counters - `r6` (even,
starts 0) and `r5` (odd, starts 4) - and for each of four threshold masks
decides which counter to hand out and advances it:

```
if (mN & r4) == 0   -> hand out the odd counter, then r5 += 1
else                -> hand out the even counter, then r6 += 1
```

Tests 1..3 advance the counter they hand out; **test 4 does not** - it only
reads.  The four handed-out values go into `r7` (test 1), two locals (tests 2
and 3) and `r4` (test 4).

The data comes from the literal pool:

```
base  = read32(0x0c0c11e0)
hw_ce = (int16)read16(0x0c0c11ce)
m1..m4 = (int16)read16(0x0c0c11d0/d2/d4/d6)
```

The body pushes `r14` then `r13` (entry `r15` = SP0), allocates a 16-byte
frame at SP0-24 holding `base`, `base+0x58`, `base+hw_ce` and `base+0x2c`, and
writes four 16-bit thresholds at `+0x26` into those four destinations.  `r15`
is net unchanged (the frame is popped before the fourth write and the two
saved registers are restored).

Details the native port keeps (unchanged from the readable authority):

* **`r3` = `base+hw_ce` is a reloaded frame word, not a computed leftover.**
  The fourth write loads its destination address back from the frame at
  `SP0-16` right before popping it, so `r3` and the fourth write's address
  both come from `base+hw_ce`.
* **Test 4 hands out but never advances.**  Tests 1..3 do `hand out;
  counter++`; test 4 only reads.
* **The odd counter is pre-seeded to 4** in the test-1 block.
* **`r13`/`r14` travel through the saved registers but must come back.**  The
  test-2 and test-3 results ride `r13`/`r14` (clobbered then restored), so the
  port keeps them in locals `t2`/`t3` for the writes.
* **The masks and `hw_ce` are sign-extended halfwords.**  `hw_ce = -16`
  moves the fourth threshold *below* base.

## Evidence

The **differential** (`tests/counter_select_native_replay.c`, target
`vf3nativecounterselect`) runs the native port against the readable guest port
from the same seed over the same six layout scenarios as the readable test
(mixed overlap/clear, all-odd, all-even, alternating, negative `hw_ce`, and
two overlapping bits).  It lays the pool, the target structure and the stack
into one flat window, patterns every byte, runs both sides, and compares the
whole RAM region byte for byte plus the contract registers (r0..r7, r13, r14,
r15) and SR's T bit.  It also checks the outcome against the fixture itself:
the four struct halfwords, the stack frame words, the restored `r13`/`r14`,
r15 flat, and the register/T pattern.  **6/6 PASS.**

The **mutation gate** (`tests/counter_select_native_mutations.json`) applies
the same 15 single-site mutations the readable gate does (the two counter
seeds, the two test-1 branches, the test-4 advance, the fourth write's
base/offset, the `hw_ce` sign, a frame slot value, the test-4 T bit, r15 not
restored, r13 from `r14_in`, and the `r0`/`r2`/`r3` answers).  The
differential catches **all 15**.

```
build\vf3nativecounterselect.exe ->
  counter_select_native_replay: PASS
python tools/mutate.py --port src/native/counter_select.c --exe build/vf3nativecounterselect.exe \
    --mutations tests/counter_select_native_mutations.json --target vf3nativecounterselect
  15/15 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed: the readable authority
already replays the oracle corpus `next_combined_cases/f_8c0c10a2.cases` at
70/70 (see docs/re/counter_select.md).

## Notes

* The **`hw_ce` scenario field must be `int16_t`**, exactly as in the readable
  test: `0xFFE0` has to sign-extend to `-32`, so the independent outcome check
  (and the fixture's pointer arithmetic) computes `base-32`, not `base+65440`.
  A `uint32_t`-typed field silently makes `(uint32_t)hw_ce` the positive
  constant and the fourth-struct check reads the wrong address.
