# Native matrix_concat_pair (0x8C03DD00)

`src/fight/matrix_concat_pair.c` is the readable authority for the two-matrix
concat leaf at **0x8C03DD00**; `src/native/matrix_concat_pair.c`
(`vf3_native_matrix_concat_pair`) is the bare-C port on the
`vf3_native_aim` context, proved against it by
`tests/matrix_concat_pair_native_replay.c` (differential, 4 scenarios) and by
the mutation gate (`tests/matrix_concat_pair_native_mutations.json`,
10/10 caught).

## Semantics (read the readable + the guest body together)

The function takes no arguments. The **first** matrix A is the 16 floats at
the address held in `[0x0C19D308 + 8]`, the **second** matrix B the 16 floats
at `0x0C19D518`.  It makes **XMTRX = XMTRX * A * B** and leaves FR0..FR11 as
B.  The readable implements it with the SH-4's `ftrv` row-vector semantics
(load A, bank-swap, run every XMTRX row through A, swap back, load B, swap,
run through B), so the XF bank ends up with the **row-major** product
`XMTRX * A * B`.

The native port reproduces that net effect with plain row-major multiply
loops (`rowmajor_prod`), which is why it does **not** use the library's
column-major `vf3_native_matrix_multiply`.  The full guest body then:

- stores FR15..FR12 to sp0-4, -8, -12, -16 and restores them from the same
  slots at the end (they travel through the stack and come back untouched);
- leaves FR0..FR11 as B;
- answers r4 = B + 32, r5 = B + 64;
- returns through `pr` (r15, pr and SR untouched);
- returns 0 immediately when FPSCR carries the SZ bit (0x100000) — the
  body's own `fschg` dance needs SZ clear.

## Proof

The differential seeds the same flat RAM (A at a pointer held in
`[0x0C19D308+8]`, B at `0x0C19D518`, the stack region), the same XMTRX and
the same FR12..FR15 sentinels on both sides, then runs the readable entry and
the native leaf and compares the final XMTRX (2e-3 FPU tolerance), FR0..FR11,
FR12..FR15 (bit-exact — they must be preserved), r4/r5, r15 and the stack
words at sp0-16..-4.  Scenarios: the base product, a zero XMTRX, an identity
XMTRX, negative FR sentinels, and the SZ guard (both sides return without
touching XMTRX).

The first port attempted the column-major product + transpose and diverged on
the rotation-only columns; the row-major `rowmajor_prod` matches all cases.
The mutation gate pins the semantics: the guard, both source addresses, the
FR stack-save order, the FR0..11 source (B, not A), the A/B multiply order,
the dropped-A path, the row/col transpose, both answer registers, and the
copy-into-XMTRX target.
