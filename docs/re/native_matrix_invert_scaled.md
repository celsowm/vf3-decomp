# native_matrix_invert_scaled

`matrix_invert_scaled` (`0x8C03B5C0`) ported to plain C in
`src/native/matrix_invert_scaled.c` (`vf3_native_matrix_invert_scaled`), proved
against the readable guest authority (`src/fight/matrix_extra.c`,
`vf3_matrix_invert_scaled_entry`) by
`tests/matrix_invert_scaled_native_replay.c` (differential) and by the
mutation gate (`tests/matrix_invert_scaled_native_mutations.json`, 8/8
caught).

## The leaf

`matrix_invert_scaled` is a self-contained FP leaf (call-free, no stack
frame), in the same column-major matrix family as `matrix_concat` /
`matrix_premul` / `rotation_xmtrx` / `xform_vector`.  It inverts a rotation +
scale + translation XMTRX **in place**.  With `t` the translation (columns
12..15) and `c0`, `c1`, `c2` the three axis columns (groups of four at 0, 4,
8):

1. `tc_i = t . c_i` (four-element FIPR dots, including `t.w * c_i.w`)
2. `t = (tc0, tc1, tc2)`; the axis columns' `w` elements become 0
3. `l_i = |c_i|^2` (now with `w` = 0, so a true axis length squared), and
   `t` is negated (`-(t . c_i)`)
4. `inv_i = 1/sqrt(l_i)` (the `fsrra` 1/sqrt)
5. `c_i`'s first three elements **and** `t`'s `i`-th element are multiplied
   by `inv_i` (normalise the axes; the translation becomes
   `-(t . c_i)/|c_i|`)
6. the 3x3 block is transposed (swap the off-diagonal pairs (1,4) (2,8)
   (6,9) through FPUL) — the rotation inverse
7. the `w` elements (3, 7, 11) are cleared again

## The port

`src/native/matrix_invert_scaled.c` reproduces the seven steps directly on
`a->xm` with plain floats and `1.0f/sqrtf` standing in for `fsrra`.  Operates
purely on XMTRX; the FR bank, r15 and SR are untouched.  The transpose's FPUL
swaps leave `a->fpul` = the value that was in slot 6 just before the last
swap (the readable's `swap_xf` rides FPUL the same way).

One precision note: the guest's `fsrra` is an *approximate* 1/sqrt, so the
resulting floats (including the FPUL side effect, which holds a transposed
axis element) differ from the `sqrtf`-derived native values by a few ulps.
The differential compares the XMTRX and the FPUL value at the 2e-3
tolerance.

## The proof

`tests/matrix_invert_scaled_native_replay.c` seeds the same XMTRX (as
XF0..XF15 for the guest, `a->xm` for the native), runs the readable guest
entry and the native port, and compares the final XMTRX (all sixteen words)
and the FPUL side effect.  Cases: a general rotation+translation, a
scale+translation matrix, identity, and a non-orthonormal scaled matrix with
non-zero `w` elements (which is what makes the length, normalise and
inverse-mutation paths observably exercisable).

## The mutation gate

`tools/mutate.py --port src/native/matrix_invert_scaled.c --exe
build/vf3nativematrixinvertscaled.exe --mutations
tests/matrix_invert_scaled_native_mutations.json --target
vf3nativematrixinvertscaled --keep-going` catches **8/8**: a dot paired
against the wrong `w` element, the first axis length computed from the wrong
component, the translation not negated, the translation normalisation
skipped, the transpose's first swap against the wrong pair, the computed dot
stored into the wrong translation slot, the reciprocal inverted (`sqrtf`
instead of `1/sqrtf`), and the last FPUL swap's side effect dropped.

Two fixture-design lessons: a set of matrices where every axis column happens
to be unit-length (`l_i = 1`) makes reciprocal and normalise mutations
unobservable, and an `f32` bit-exact comparison of a value the guest computes
with `fsrra` flags a few-ulp difference that is really the FPU approximation.
`l_i = 1` hides `1/sqrt` vs `sqrt`; a scaled/non-orthonormal matrix with
non-zero `w` elements is what makes both visible.

No regression to the coverage union (`docs/coverage.md` left untreated).
