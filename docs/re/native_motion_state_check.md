# native motion_state_check (0x8C0355CA)

`src/native/motion_state_check.c` (`vf3_native_motion_state_check`) is the
plain-C port of the readable `src/fight/motion_state_check.c`
(`vf3_motion_state_check_entry`), proved by
`tests/motion_state_check_native_replay.c` (7 differential cases) and the
mutation gate `tests/motion_state_check_native_mutations.json` (7/7 caught).

## The function

A self-contained integer leaf (call-free, no FP, no stack frame):
`r4` -> the motion state record, `r5` -> the destination pointer.

- if `r4 == 0`, tail-transfers to pr with `r0 = 0`;
- else reads the sign-extended halfword at `r4 + 0x48`; if it is zero,
  tail-transfers with `r0 = 0`;
- else reads the word at `r4 + 12`, stores it through `*r5` and tail-transfers
  with `r0 = 1`.

Every path is a **tail transfer** to pr (the caller's return address), so the
native port leaves `pr` untouched and simply returns.

## What the port has to keep

- **The `r0` result per path**: `0` on the two empty paths, `1` on the
  success path.
- **The T bit per path**: `T = (r4 == 0)` then `T = (r3 == 0)`, so T is `1`
  on the two empty paths and `0` on the success path (the last comparison is
  the halfword `!= 0`).
- **`r3` per path**: untouched (its seed) on the null path, `0` on the
  halfword-zero path (it holds the zero halfword read), and the stored word
  on the success path.
- **The store is through `*r5`** (the destination), at the word read from
  `r4 + 12`.
- **`r4`, `r5`, `r15` and `pr` are untouched.**

## One unobservable thing

- **The sign extension of the halfword is unobservable.**  The halfword at
  `r4 + 0x48` is read sign-extended into `r3`, but on the path where that
  value survives (`r3 == 0`) it is `0` either way, and on the other path
  `r3` is overwritten by the stored word before anything reads it.  The T
  bit test (`r3 == 0`) is also unaffected by sign extension.  The
  `(int16_t)` cast is kept for fidelity but is not gated.
