# native_rotation_xmtrx

`rotation_xmtrx` (`0x8C03C8B0`) ported to plain C in `src/native/rotation_xmtrx.c`
(`vf3_native_rotation_xmtrx`), proved against the readable guest authority
(`src/fight/small_leaves.c`, `vf3_rotation_xmtrx_entry`) by
`tests/rotation_xmtrx_native_replay.c` (differential) and by the mutation gate
(`tests/rotation_xmtrx_native_mutations.json`, 7/7 caught).

## The leaf

`rotation_xmtrx` is a self-contained FP leaf (call-free, no stack frame), in
the same column-major matrix family as `matrix_concat` / `matrix_premul` /
`matrix_concat_save`.  It takes two angles that are already in FR4 (sin) and
FR5 (cos) and builds two FV column vectors

    v0 = { cos, 0, -sin, 0 }        (FR0, FR1, FR2, FR3)
    v1 = { sin, 0,  cos, 0 }        (FR4, FR5, FR6, FR7)

and runs each through XMTRX with `ftrv`, the column-major product
`out[r] = sum_k xm[4k+r] * v[k]`.  The results land back in FR0..FR3 and
FR4..FR7, and are written into XMTRX columns 0 and 2 (XF0..XF3 and
XF8..XF11); columns 1 and 3 are untouched.  FR8..FR15, r15 and SR are
untouched.

This is the "rotation from a ready sin/cos" member of the family: it does not
compute the angle from scalar degrees itself (the `rotate_*` angle wrappers in
`aim_math.c` do that), it takes the already-resolved trig values and folds the
two rotational basis vectors through the current XMTRX.

## The port

`src/native/rotation_xmtrx.c`:

- reads `cos` and `sin` from FR5 and FR4,
- builds `v0` and `v1`,
- computes the two column-major products `out0[r] = sum_k xm[4k+r] * v0[k]`
  and `out1[r] = sum_k xm[4k+r] * v1[k]`,
- writes `out0` into `fr[0..3]` and `xm[0..3]`, and `out1` into `fr[4..7]`
  and `xm[8..11]`.

FR8..FR15, r15 and SR are untouched.

## The proof

`tests/rotation_xmtrx_native_replay.c` seeds the same flat RAM, the same
XMTRX and the same FR bank, runs the readable guest entry and the native port,
and compares the final XMTRX (all sixteen words - columns 0 and 2 changed,
columns 1 and 3 must hold their seeds), FR0..FR15 (0..7 are the products,
8..15 are preserved) and r15/SR.  The residual is the FPU difference (`ftrv`
against the native column-major multiply), tolerated at 2e-3.  Cases: base (a
distinct-colums XMTRX, sin/cos = 0.5/0.866), zero sin/cos (both products are
zero), negative sin, identity XMTRX (out = v itself), and FR8..FR11 negative
sentinels that must survive.

## The mutation gate

`tools/mutate.py --port src/native/rotation_xmtrx.c --exe
build/vf3nativerotationxmtrx.exe --mutations
tests/rotation_xmtrx_native_mutations.json --target vf3nativerotationxmtrx
--keep-going` catches **7/7**: v0 built from sin instead of cos, v1's sign
flipped, the multiply transposed, the FR results written to the wrong half of
the bank, XMTRX column 0 fed from the second product, the second product
written to XMTRX column 1 instead of column 2, and FR12..FR15 overwritten by a
product.

No regression to the coverage union (`docs/coverage.md` left untreated).
