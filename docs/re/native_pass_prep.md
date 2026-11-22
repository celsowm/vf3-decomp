# native_pass_prep — 0x8C09DBC0 natively

`pass_prep` is a format_int-pattern sequencer whose four guest callees are all
already natively ported, so the guest calls become direct native calls.  It is
a small pass that runs once at the start of a pose chain: push the current
XMTRX, replace it with its rigid inverse, transform one point through the
inverse into a destination, then pop the stack.

## The guest contract

`vf3_pass_prep_entry` (src/fight/pass_prep.c) takes r4 = the source point and
r5 = the destination.  It uses a 72-byte frame (`f = sp0 - 4 - 72 = sp0 - 0x4C`),
stashes pr at `sp0 - 4`, parks arg0 at `f` and arg1 at `f + 4`, then calls, in
order:

| PC         | guest            | native equivalent      | note                          |
|------------|------------------|------------------------|-------------------------------|
| 0x8C03C4F0 | matrix_push      | `vf3_native_matrix_push` | r4 = 0 (no load)              |
| 0x8C03C5B0 | matrix_invert_rigid | `vf3_aim_invert_rigid` | replaced by the inverse, in place |
| 0x8C03B450 | xform_point      | `vf3_aim_xform_point`  | src = arg0, dst = arg1        |
| 0x8C03C4A0 | matrix_pop       | `vf3_native_matrix_pop` | r4 = 1 (the tail)             |

The tail pop runs with pr0 restored, so `pass_prep` returns straight to the
caller.  On the way out r15 is restored to sp0 and pr to pr0.

## Native port

`src/native/pass_prep.c` (`vf3_native_pass_prep`) reproduces the frame and
register contract exactly: it computes `sp0 = R(15)`, `pr0 = a->pr`,
`f = sp0 - 4 - 72`, saves pr at `sp0 - 4`, parks the two arguments, then
sequences the four native callees.  Two details matter:

- **The invert is not in-place safe.**  `vf3_aim_invert_rigid(m, out)` reads
  and writes the same 16 words, so the native goes through a temporary and
  `memcpy`s back into `a->xm` (the same shape body_capsule.c and
  facing_update.c use).  The readable port does the equivalent.
- **R(15) has to be the live frame pointer during every callee** and sp0
  again at the end, because the callees the guest uses (matrix push/pop go
  through the flat-RAM control block at 0x0C19D2E4) read arguments from the
  register file and write the stack control block into RAM.  The final
  `R(15) = sp0` and `a->pr = pr0` happen *after* the pop so the tail transfer
  sees the restored return state.

## Net observable effect

XMTRX returns to its entry value (push then pop of the same matrix), so the
lasting RAM effects of the round trip are the transformed point at arg1
(`inverse(X0) * arg0`) and the matrix-stack control block, which the native
push/pop carry in the flat RAM and therefore compare byte-for-byte.

## Proof

- `tests/pass_prep_native_replay.c` runs the native port and the readable
  `vf3_pass_prep_entry` from the same seed (source/dest points, the frame,
  the matrix-stack control block, the entry XMTRX) across four points
  (including the origin and a large-magnitude one) and compares the
  destination floats (2e-3), the whole control-block + stack region, the
  frame words, the final XMTRX and the r15/pr/SR.T return contract.  4/4
  cases.
- `tests/pass_prep_native_mutations.json` (10 mutations) — all 10 caught by
  `tools/mutate.py` against `vf3nativepassprep`.  Two of them had to target
  the **trailing** restore: the middle `r15`/`pr` restore (before the pop) is
  overwritten by the one after the pop, so a mutation of the middle one is
  invisible; the observable mutations are the final restores.
