# native_xform_vector

`xform_vector` (`0x8C03B4B0`) ported to plain C in `src/native/xform_vector.c`
(`vf3_native_xform_vector`), proved against the readable guest authority
(`src/fight/matrix_extra.c`, `vf3_xform_vector_entry`) by
`tests/xform_vector_native_replay.c` (differential) and by the mutation gate
(`tests/xform_vector_native_mutations.json`, 8/8 caught).

## The leaf

`xform_vector` is a self-contained FP leaf (call-free, no stack frame), in the
same column-major matrix family as `matrix_concat` / `matrix_premul` /
`rotation_xmtrx`.  It reads the three floats at r4 as a vector, runs it
through XMTRX as `(x, y, z, 0)` via `ftrv` (the column-major product
`out[r] = sum_k xm[4k+r] * v[k]`) and writes the three floats out to r5.  The
`w=0` fourth component drops the translation column, so this is a
rotation-only transform.  r4 advances by 12.

## The port

`src/native/xform_vector.c`:

- loads `v[0..2]` from r4 (and fixes `v[3] = 0`),
- computes the column-major product `out[r] = sum_k xm[4k+r] * v[k]`,
- writes the full four-component `out[0..3]` into `fr[4..7]` (the `ftrv`
  lands its whole FV output back in FR4..FR7, so FR7 is the transformed `w`,
  not zero),
- writes `out[0..2]` to r5,
- advances r4 by 12.

FR8..FR15, r15 and SR are untouched.

## The proof

`tests/xform_vector_native_replay.c` seeds the same flat RAM, XMTRX, FR bank
and input vector, runs the readable guest entry and the native port, and
compares the out words at r5, FR4..FR7, the preserved FR8..FR15, and
r4/r5/r15/SR.  The residual is the FPU difference (`ftrv` against the native
column-major multiply), tolerated at 2e-3.  Cases: base (rotation+translation
XMTRX, an off-axis vector), zero vector, negative vector, and identity XMTRX
(out = the vector's 3x3 part, translation dropped).

## The mutation gate

`tools/mutate.py --port src/native/xform_vector.c --exe
build/vf3nativexformvector.exe --mutations
tests/xform_vector_native_mutations.json --target vf3nativexformvector
--keep-going` catches **8/8**: the translation dropper (`v[3] = 0`) set to 1,
the multiply transposed, the FR results written to the wrong bank offset, the
out write aimed at r4 instead of r5, the out write truncated to two floats,
the r4 advance wrong, FR8..FR11 overwritten by a product, and the vector
loaded from r5 instead of r4.

One test-design lesson: an out-region sentinel that is a quiet NaN does not
catch a mutation that leaves a slot unwritten, because `fabsf(NaN - v) > TOL`
is false.  The fixture has to seed the out region with a large *finite* float
so a missed write shows up as a value difference.

No regression to the coverage union (`docs/coverage.md` left untreated).
