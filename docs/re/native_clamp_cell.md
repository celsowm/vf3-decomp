# native clamp_cell (0x8C055B28)

`src/native/clamp_cell.c` (`vf3_native_clamp_cell`) is the plain-C port of the
readable `src/fight/misc_wrappers.c` (`vf3_clamp_cell_entry`), proved by
`tests/clamp_cell_native_replay.c` (10 differential cases) and the mutation
gate `tests/clamp_cell_native_mutations.json` (7/7 caught).

## The function

A self-contained integer leaf (call-free, no FP, no stack frame):
`r4` -> a cell whose halfword at `+2` is the value.

It clamps the **sign-extended** halfword at `r4 + 2` to a cell number - values
below 9 keep themselves, 9..16 become 9, 17 and above become 10 - stores
**four times** the clamped value at the global `0x0C058FDC`, advances `r4` by
4, and tail-transfers to pr.

## What the port has to keep

- **The two comparisons are different bounds with different consequences.**
  The high test (`>= 17`) is the first; the low test (`>= 9`) recomputes the T
  bit and caps at 9.  The high path leaves T = (value >= 17); the low path
  leaves T = (value >= 9).
- **The value is sign-extended from the halfword** into the integer that gets
  shifted: a negative halfword (e.g. `-1` or `0x8000`) is *not* clamped up and
  shifts to a negative result, so the stored word can be `0xFFFFFFFC` etc.
  The sign extension is observable here (unlike in motion_state_check),
  because the negative value survives into `<< 2`.
- **`4 * clamped` and the global**: `r0 = 4 * clamped`, `r1 = 0x0C058FDC`, and
  the global word is written with `r0`.
- **`r4 += 4`**; `r2`, `r3`, `r5..`, `r15` and `pr` untouched.

## Register contract

`r0` = 4 * clamped, `r1` = `0x0C058FDC`, `r4` advanced by 4, `SR.T` per the
last comparison, and the global `0x0C058FDC` stores `r0`.
