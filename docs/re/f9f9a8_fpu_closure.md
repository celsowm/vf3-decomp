# `0x8C09F9A8` FPU continuation closure

`0x8C09F9A8` begins with a signed guard. When the guard falls through, it
adjusts its integer operands, converts them to floats, computes a scalar ratio
in FPSCR truncate mode, then calls `0x8C09F354` with destination and source
vectors at `r14+0x1D04` and `r14+0x1E00`.

`0x8C09F354` walks 18 vector records and then processes three finishing
vectors. Each vector uses SH-4 fused multiply-add operations. The C mirror
uses the existing truncate-toward-zero helpers and models the stack scratch
word and all writes through the RAM shadow. The parent restores PR and the
saved R14 in its return delay slot.

## Evidence

- Parent: `extract/analysis/goldens_f9f9a8_full/f_0c09f9a8.cases`, 64 paired
  register+RAM cases.
- Helper: `extract/analysis/goldens_f9f9a8_full/f_0c09f354.cases`, 43 paired
  register+RAM cases over eight windows.
- Replay: `f9f9a8_replay` 64/64 and `f9f354_replay` 43/43.
- `0x8C09F9A8` is already counted in the baseline from its verified guard
  path; `0x8C09F354` is an off-baseline helper. This closure adds no baseline
  function credit.
- Instruction checkpoints are in `extract/analysis/goldens_f9f354_pcs/`;
  the exact-boundary RAM recapture is in
  `extract/analysis/goldens_f9f354_exact/`.

The checked path requires FPSCR `0x00240001`; unsupported modes and a zero
conversion denominator return the harness's explicit skip result.
