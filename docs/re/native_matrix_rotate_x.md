# Native matrix_rotate_x (0x8C03C6C0)

## Reading

`matrix_rotate_x` is a self-contained FP leaf in the column-major XMTRX matrix
family: it post-multiplies XMTRX by the X rotation whose **angle** the caller has
left in r4 (65536 = one turn).  It derives sin/cos from the angle (the fsca step,
FPUL = r4), builds two FV column vectors

    v0 = { 0, cos,  sin, 0 }        (FR0, FR1, FR2, FR3)
    v1 = { 0, -sin, cos, 0 }        (FR4, FR5, FR6, FR7)

runs each through XMTRX with `ftrv`, and writes the two result columns into
XMTRX columns 1 and 2 (XF4..XF11).  FR0..FR7 hold the two ftrv outputs on
return.  FPUL is left as the angle.  FR8..FR15, XF0..XF3, XF12..XF15, r15 and
SR are untouched.

The readable authority `vf3_rotate_x_entry` lives in `src/fight/leaf_math.c`:

    FPUL = r4
    FSCA(FPUL)                 # fr4 = sin, fr5 = cos
    FR0 = 0; FR3 = 0; FR7 = 0
    FR1 = cos; FR2 = sin
    FR5 = -sin; FR6 = cos
    FTRV(FR0..FR3, XMTRX)
    FR4 = 0
    FTRV(FR4..FR7, XMTRX)
    XF4..XF11 = FR0..FR7

The X rotation leaves column 0 (the X axis) as the unit vector, so only columns
1 and 2 change.  `rotate_x` is the sibling of `rotate_z` (0x8C03C940, already
ported and shipped) and `rotate_y` (0x8C03C880); the three share the fsca +
two-column-ftrv shape and differ only in which columns they compose.

The `ftrv` is the SH-4's transform: column-major, the output is
`out[r] = sum_k XMTRX[4k+r] * v[k]`, and with the `w = 0` component of both
vectors the translation column never contributes.  The second vector's
`-sin` is the sign of the post-multiplied X rotation's y component.

## The native port

`src/native/matrix_rotate_x.c` (`vf3_native_matrix_rotate_x`) is a direct
plain-C transcription onto `vf3_native_aim` (XMTRX in `a->xm[16]`, FR bank in
`a->fr[16]`).  The fsca step is reproduced the aim-math way: the angle masked
to 16 bits is converted to radians (`angle * pi / 32768`) and sinf/cosf take
its sine and cosine; FPUL is written with the unmasked angle (the guest sets
FPUL = r4).  Then the two vectors are built, the column-major ftrv runs with
plain float accumulation (the established native ftrv convention), and the
results go into both FR0..FR7 and XMTRX columns 1 and 2.  Columns 0, 3 and
FR8..FR15 are never touched.

`src/native/matrix_rotate_x.h` declares the single entry
`vf3_native_matrix_rotate_x(vf3_native_aim *a)`.

## Proof

`tests/matrix_rotate_x_native_replay.c` (`vf3nativematrixrotatex`)
differentially replays the native leaf against the readable authority
(`vf3_rotate_x_entry`) on the same flat RAM, XMTRX, FR bank and angle.

The fixture runs four cases: 30 degrees, 90 degrees, the 210-degree negative
quadrant, and the identity XMTRX at 90 degrees.  Each case compares the result
columns XF4..XF11 and FR0..FR7 at the 2e-3 FPU tolerance (the
fsca-vs-sinf/cosf and ftrv accumulate difference), and compares the untouched
XF0..XF3/XF12..XF15, FR8..FR15, r15 and SR bit-exact, plus FPUL (must equal the
angle).  All four cases PASS.

`tests/matrix_rotate_x_native_mutations.json` - 7 mutations, **7/7 caught**:

- the angle converted with half the turn constant
- the first vector shifted so its cos lands on the x axis
- the second vector's `-sin` sign flip dropped
- the second column written to column 1 instead of column 2
- the FPUL write dropped (pinned by the FPUL check)
- the ftrv index turned row-major (`4r+k` instead of `4k+r`)
- the two result columns written the wrong way round

## Milestone

Committed and pushed as `matrix_rotate_x` (see git log).
