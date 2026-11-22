# native_matrix_invert_rigid

`matrix_invert_rigid` (`0x8C03C5B0`) ported to plain C in
`src/native/matrix_invert_rigid.c` (`vf3_native_matrix_invert_rigid`), proved
against the readable guest authority (`src/fight/leaf_math.c`,
`vf3_matrix_invert_rigid_entry`) by `tests/matrix_invert_rigid_native_replay.c`
(differential) and by the mutation gate
(`tests/matrix_invert_rigid_native_mutations.json`, 8/8 caught).

## The leaf

`matrix_invert_rigid` is a self-contained FP leaf (call-free, no stack frame),
in the same column-major matrix family as `matrix_concat` / `matrix_premul` /
`rotation_xmtrx` / `xform_vector` / `matrix_invert_scaled`.  It inverts a
*rigid* (rotation + translation) XMTRX **in place**.  With `t` the
translation (columns 12..15) and `c0`, `c1`, `c2` the three axis columns
(groups of four at 0, 4, 8):

1. the axis columns' `w` elements become 0; `t.w` becomes 1
2. `tc_i = t . c_i` (four-element FIPR dots)
3. `t_i = -(tc_i)` — the translation becomes `-(t . c_i)`, i.e. `-(R^T t)`
4. the 3x3 block is transposed (swap the off-diagonal pairs (1,4) (2,8)
   (6,9) through FPUL) — the rotation inverse
5. the `w` elements (3, 7, 11) are cleared again

## The port

`src/native/matrix_invert_rigid.c` reproduces the five steps directly on
`a->xm` with plain floats.  Operates purely on XMTRX; the FR bank, r15 and SR
are untouched.  The transpose's FPUL swaps leave `a->fpul` = the value that
was in slot 6 just before the last swap (the readable's `swap_xf` rides FPUL
the same way).

Unlike `matrix_invert_scaled`, there is no `1/sqrt` normalisation step — a
rigid matrix has unit columns, so the length-normalisation of the scaled
inverse is simply absent.  The residual is therefore only the FPU's rounding
on the dots, well inside the 2e-3 tolerance.

## The proof

`tests/matrix_invert_rigid_native_replay.c` seeds the same XMTRX (as
XF0..XF15 for the guest, `a->xm` for the native), runs the readable guest
entry and the native port, and compares the final XMTRX (all sixteen words)
and the FPUL side effect.  Cases: a general rigid rotation + translation (with
a non-zero column-1 `w`, so the dot's `w` term is exercised), a 90-degree X
rotation composition, identity, and a ~30-degree Z rotation with a translation
that is not an eigen-direction (so the `-(t . c_i)` path is exercised).

## The mutation gate

`tools/mutate.py --port src/native/matrix_invert_rigid.c --exe
build/vf3nativematrixinvertrigid.exe --mutations
tests/matrix_invert_rigid_native_mutations.json --target
vf3nativematrixinvertrigid --keep-going` catches **8/8**: a dot paired
against the wrong `w` element, the first dot's second term read from the
wrong axis component, the translation not negated, the column-1 and column-2
`w` clears dropped, `t.w` set to 0.5 instead of 1, the transpose's first swap
against the wrong pair, the computed dot stored into the wrong translation
slot, and the last FPUL swap's side effect dropped.

No regression to the coverage union (`docs/coverage.md` left untreated).
