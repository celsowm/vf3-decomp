# Native matrix_rotate_sc (0x8C03C970)

## Reading

`matrix_rotate_sc` is a self-contained FP leaf in the column-major XMTRX
matrix family: it post-multiplies XMTRX by the Z rotation whose sin/cos the
caller has left in FR4/FR5.  It builds two FV column vectors

    v0 = { cos,  sin, 0, 0 }        (FR0, FR1, FR2, FR3)
    v1 = { -sin, cos, 0, 0 }        (FR4, FR5, FR6, FR7)

runs each through XMTRX with `ftrv`, and writes the two result columns into
XMTRX columns 0 and 1 (XF0..XF7).  FR0..FR7 hold the two ftrv outputs on
return.  FR8..FR15, XF8..XF15, r15 and SR are untouched.

The readable authority `vf3_matrix_rotate_sc_entry` lives in
`src/fight/leaf_math.c` (body 0x8C03C970); it is the shared body of
0x8C03C940:

    FR1 = FR4            # sin -> FR1
    FR4 ^= 0x80000000    # FR4 = -sin   (the negation bit)
    FR0 = FR5            # cos -> FR0
    FR2 = 0; FR3 = 0
    FTRV(FR0..FR3, XMTRX)
    FR6 = 0; FR7 = 0
    FTRV(FR4..FR7, XMTRX)
    XF0..XF7 = FR0..FR7

The `ftrv` is the SH-4's transform: column-major, the output is
`out[r] = sum_k XMTRX[4k+r] * v[k]`, and with the `w = 0` component of both
vectors the translation column never contributes.  The second vector's
`-sin` is the sign of the post-multiplied Z rotation's x component.

## The native port

`src/native/matrix_rotate_sc.c` (`vf3_native_matrix_rotate_sc`) is a direct
plain-C transcription onto `vf3_native_aim` (XMTRX in `a->xm[16]`, FR bank in
`a->fr[16]`).  It builds the two vectors, runs the column-major ftrv with
plain float accumulation (the established native ftrv convention), and writes
the results into both FR0..FR7 and XMTRX columns 0 and 1.  Columns 2,3 and
FR8..FR15 are never touched.

`src/native/matrix_rotate_sc.h` declares the single entry
`vf3_native_matrix_rotate_sc(vf3_native_aim *a)`.

## Proof

`tests/matrix_rotate_sc_native_replay.c` (`vf3nativematrixrotatesc`)
differentially replays the native leaf against the readable authority
(`vf3_matrix_rotate_sc_entry`) on the same flat RAM, XMTRX and FR bank.

The fixture runs four cases: a base rotation+translation matrix at 30
degrees, a negative sin, a zero angle, and the identity XMTRX.  Each case
compares the result columns XF0..XF7 and FR0..FR7 at the 2e-3 FPU tolerance
(the ftrv difference between the column-major accumulate and the guest FPU),
and compares the untouched XF8..XF15, FR8..FR15, r15 and SR bit-exact.  All
four cases PASS.

`tests/matrix_rotate_sc_native_mutations.json` - 6 mutations, **6/6 caught**:

- the second vector's `-sin` sign flip dropped
- the first vector's sin and cos swapped
- the result written to XF8..XF11 instead of XF0..XF3
- the FR result written to the wrong bank half
- the ftrv index turned row-major (`4r+k` instead of `4k+r`)
- the two result columns written the wrong way round

(The `drops_w_term` idea was a no-op here: both vectors carry `w = 0`, so the
`k = 3` term is always zero and removing it changes nothing - unlike the
`translate_by` sibling whose vector has `w = 1`.)

## Milestone

Committed and pushed as `matrix_rotate_sc` (see git log).
