# Native matrix_rotate_y (0x8C03C880)

## Reading

`matrix_rotate_y` is a self-contained FP leaf in the column-major XMTRX matrix
family: it post-multiplies XMTRX by the Y rotation whose **angle** the caller has
left in r4 (65536 = one turn).  It derives sin/cos from the angle (the fsca step,
FPUL = r4), builds two FV column vectors

    v0 = {  cos, 0, -sin, 0 }        (FR0, FR1, FR2, FR3)
    v1 = {  sin, 0,  cos, 0 }        (FR4, FR5, FR6, FR7)

runs each through XMTRX with `ftrv`, and writes the two result columns into
XMTRX columns 0 and 2 (XF0..XF3, XF8..XF11).  FR0..FR7 hold the two ftrv outputs
on return.  FPUL is left as the angle.  FR8..FR15, XF4..XF7, XF12..XF15, r15
and SR are untouched.

The readable authority `vf3_rotate_y_entry` lives in `src/fight/leaf_math.c`:

    FPUL = r4
    FSCA(FPUL)                 # fr4 = sin, fr5 = cos
    FR0 = cos; FR1 = 0; FR2 = -sin; FR3 = 0
    FR6 = cos; FR7 = 0
    FTRV(FR0..FR3, XMTRX)
    FR5 = 0
    FTRV(FR4..FR7, XMTRX)
    XF0..XF3 = FR0..FR3
    XF8..XF11 = FR4..FR7

The Y rotation leaves column 1 (the Y axis) as the unit vector, so only columns
0 and 2 change.  `rotate_y` is the sibling of `rotate_z` (0x8C03C940) and
`rotate_x` (0x8C03C6C0), all shipped natively; the three share the fsca +
two-column-ftrv shape and differ only in which columns they compose.

The `ftrv` is the SH-4's transform: column-major, the output is
`out[r] = sum_k XMTRX[4k+r] * v[k]`, and with the `w = 0` component of both
vectors the translation column never contributes.  The first vector's
`-sin` is the sign of the post-multiplied Y rotation's z component.

## The native port

`src/native/matrix_rotate_y.c` (`vf3_native_matrix_rotate_y`) is a direct
plain-C transcription onto `vf3_native_aim` (XMTRX in `a->xm[16]`, FR bank in
`a->fr[16]`).  The fsca step is reproduced the aim-math way: the angle masked
to 16 bits is converted to radians (`angle * pi / 32768`) and sinf/cosf take
its sine and cosine; FPUL is written with the unmasked angle (the guest sets
FPUL = r4).  Then the two vectors are built, the column-major ftrv runs with
plain float accumulation (the established native ftrv convention), and the
results go into both FR0..FR7 and XMTRX columns 0 and 2.  Columns 1, 3 and
FR8..FR15 are never touched.

`src/native/matrix_rotate_y.h` declares the single entry
`vf3_native_matrix_rotate_y(vf3_native_aim *a)`.

## Proof

`tests/matrix_rotate_y_native_replay.c` (`vf3nativematrixrotatey`)
differentially replays the native leaf against the readable authority
(`vf3_rotate_y_entry`) on the same flat RAM, XMTRX, FR bank and angle.

The fixture runs four cases: 30 degrees, 90 degrees, the 210-degree negative
quadrant, and the identity XMTRX at 90 degrees.  Each case compares the result
columns XF0..XF3/XF8..XF11 and FR0..FR7 at the 2e-3 FPU tolerance (the
fsca-vs-sinf/cosf and ftrv accumulate difference), and compares the untouched
XF4..XF7/XF12..XF15, FR8..FR15, r15 and SR bit-exact, plus FPUL (must equal the
angle).  All four cases PASS.

`tests/matrix_rotate_y_native_mutations.json` - 7 mutations, **7/7 caught**:

- the angle converted with half the turn constant
- the first vector's `-sin` z sign flip dropped
- the second vector's sin and cos swapped
- the second column written to column 1 instead of column 2
- the FPUL write dropped (pinned by the FPUL check)
- the ftrv index turned row-major (`4r+k` instead of `4k+r`)
- the two result columns written the wrong way round

## Milestone

Committed and pushed as `matrix_rotate_y` (see git log).
