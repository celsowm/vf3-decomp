# Native matrix_translate_by (0x8C03CC60)

## Reading

`matrix_translate_by` is a self-contained FP leaf in the column-major XMTRX
matrix family: it sets XMTRX's translation column (XF12..XF15) to
`XMTRX * (FR4, FR5, FR6, 1)` via `ftrv` - i.e. it moves the origin by the
local offset the caller has left in FR4..FR6.  FR4..FR7 end as the
transformed vector (FR7 is set to `1.0` first).  FR8..FR15, r15 and SR are
untouched.

The readable authority `vf3_matrix_translate_by_entry` lives in
`src/fight/leaf_math.c` (body 0x8C03CC60):

    FR7 = 1.0
    FTRV(FR4..FR7, XMTRX)          # FR4..FR7 = XMTRX * (x, y, z, 1)
    XF12..XF15 = FR4..FR7

The `ftrv` is the SH-4's translate/transform: column-major, the output is
`out[r] = sum_k XMTRX[4k+r] * v[k]`, and with the `w = 1` component the
translation column of XMTRX contributes to the product (unlike
`xform_vector`, which forces `w = 0`).

## The native port

`src/native/matrix_translate_by.c` (`vf3_native_matrix_translate_by`) is a
direct plain-C transcription onto `vf3_native_aim` (XMTRX in `a->xm[16]`, FR
bank in `a->fr[16]`).  It sets `fr[7] = 1.0`, runs the column-major ftrv with
plain float accumulation (the established native ftrv convention), and writes
the result into both FR4..FR7 and XMTRX columns 12..15.  Columns 0..11 and
FR0..FR3/FR8..FR15 are never touched.

`src/native/matrix_translate_by.h` declares the single entry
`vf3_native_matrix_translate_by(vf3_native_aim *a)`.

## Proof

`tests/matrix_translate_by_native_replay.c` (`vf3nativematrixtranslateby`)
differentially replays the native leaf against the readable authority
(`vf3_matrix_translate_by_entry`) on the same flat RAM, XMTRX and FR bank.

The fixture runs four cases: a base rotation+translation matrix, a negative
offset, a zero offset, and the identity XMTRX.  Each case compares the
translation column XF12..XF15 and FR4..FR7 at the 2e-3 FPU tolerance (the
ftrv difference between the column-major accumulate and the guest FPU), and
compares the untouched XF0..XF11, FR0..FR3, FR8..FR15, r15 and SR
bit-exact.  All four cases PASS.

`tests/matrix_translate_by_native_mutations.json` - 5 mutations, **5/5
caught**:

- FR7 set to `0` instead of `1` (drops the translation's contribution)
- the result written to XF0..XF3 instead of XF12..XF15
- the FR result written to FR0..FR3 instead of FR4..FR7
- the ftrv index turned row-major (`4r+k` instead of `4k+r`)
- the `w` term dropped from the ftrv accumulation

## Milestone

Committed and pushed as `matrix_translate_by` (see git log).
