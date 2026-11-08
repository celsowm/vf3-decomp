# counter_select (0x8C0C10A2)

The four-threshold counter selection, ported readable in
`src/fight/readable/counter_select.c` and registered as `counter_select`.

## The body

A self-contained leaf, 124 B (0x0C0C10A2..0x0C0C111A), call-free and
integer-only (no FP at all).  `r4` is a mask.  The body keeps two running
selection counters - `r6` (even, starts 0) and `r5` (odd, starts 4) - and for
each of four threshold masks decides which counter to hand out and advances
it:

```
if (mN & r4) == 0   -> hand out the odd counter, then r5 += 1
else                -> hand out the even counter, then r6 += 1
```

Tests 1..3 advance the counter they hand out; **test 4 does not** - it only
reads.  The four handed-out values go into `r7` (test 1), two locals (tests 2
and 3) and `r4` (test 4).

The data comes from the literal pool:

```
base  = read32(0x0c0c11e0)       the target structure's base pointer
hw_ce = (int16)read16(0x0c0c11ce)
m1..m4 = (int16)read16(0x0c0c11d0/d2/d4/d6)
```

The body pushes `r14` then `r13` (entry `r15` = SP0), allocates a 16-byte
frame at SP0-24 holding `base`, `base+0x58`, `base+hw_ce` and `base+0x2c`, and
writes four 16-bit thresholds (the handed-out values) at `+0x26` into those
four destinations:

```
set_u16(base,       + 0x26, t1)
set_u16(base+0x2c,  + 0x26, t2)
set_u16(base+0x58,  + 0x26, t3)
set_u16(base+hw_ce, + 0x26, r4out)
```

`r15` is net unchanged: the frame is popped (`r15 += 0x10`) *before* the
fourth write, and the two saved registers are restored at the tail.

Details the port has to keep:

* **`r3` = `base+hw_ce` is a reloaded frame word, not a computed leftover.**
  The fourth write loads its destination address back from `frame[2]` at
  `r15+8` (0x0C0C1112) right before popping the frame (0x0C0C1114), so the
  port's output `r3` and the fourth write's address both come from
  `base+hw_ce`.  The captured corpus confirms it: `r3` ends as `0x0c29f374`
  = `base + hw_ce`.
* **Test 4 hands out but never advances.**  Tests 1..3 do `hand out; counter++
  `; test 4 only reads (`r4 = r5` or `r6`).  A port that advances in test 4
  changes `r5`/`r6` and the oracle and differential both catch it.
* **The odd counter is pre-seeded to 4 in the test-1 block.**  `r5 = 4` is
  written unconditionally at 0x0C0C10C4 before the branch, so the odd counter
  starts at 4, not at 1.
* **`r13`/`r14` travel through the saved registers but must come back.**  The
  test-2 result rides `r13` and the test-3 result rides `r14` (clobbered then
  restored at the tail), so the port keeps them in locals `t2`/`t3` for the
  writes and leaves `r13`/`r14` at their entry values.
* **The masks and `hw_ce` are sign-extended halfwords.**  `hw_ce = -16`
  (0xFFF0) moves the fourth threshold *below* base, which only works if the
  frame slot and the pointer arithmetic keep the sign.

## Evidence

The **differential** (`tests/counter_select_replay.c`) runs the three arms -
the generated chain, the readable port called directly, and the readable port
reached through `vf3_readable_override` - over six mask/`hw_ce` layouts
(mixed overlap/clear, all-odd, all-even, alternating, negative `hw_ce`, two
overlapping bits) in three windows mirroring the captured corpus (the pool
`0x0c0c1000`, the target structure `0x0c29f000`, the stack `0x0c31f000`),
with every window byte patterned first, and compares the whole register file,
SR/T, the exit PC, the out-of-window counter and every RAM byte.  It also
checks the outcome against the fixture itself: the four struct halfwords, the
stack frame words, the restored `r13`/`r14`, r15 flat, and the register/T
patterns.  **6/6 PASS.**  The **mutation gate**
(`tests/counter_select_mutations.json`) applies 15 single-line mutations - the
two counter seeds, the two test-1 branches, the test-4 advance, the fourth
write's base/offset, the `hw_ce` sign, a frame slot value, the test-4 T bit,
r15 not restored, r13 from `r14_in`, and the `r0`/`r2`/`r3` answers - and the
differential catches all 15.

The **oracle** leg closes directly: `tests/counter_select_oracle.c`
(`vf3counterselectoracle`) routes the readable port itself over the per-entry
`.cases` corpus `next_combined_cases/f_8c0c10a2.cases` and passes **70/70
cases** (whole 37-register file, SR's T bit, every byte of the three windows
and the OOB counter):

```
build\vf3counterselectoracle.exe ->
  counter_select_oracle: 70/70 cases match (0 skipped) - PASS
```

The three windows carry the pool, the target structure and the stack as
captured runtime state, and the leaf touches no device register, so no
sidecars and no supplied pool are needed.  The three-arm chain
`readable == generated == oracle` closes on all three legs.

## Notes

* The entry is `ported-invocation` in the ledger, not `ported`: this readable
  port is the first source-level C for it.  It is off-baseline (the inventory
  jumps `f_8c0c0ff6` to `f_8c0c111c`), so its 124 B are worth their own body
  span.
