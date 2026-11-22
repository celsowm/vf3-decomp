# native_axis_extract

`axis_extract` (`0x8C03EE40`) ported to plain C in
`src/native/axis_extract.c` (`vf3_native_axis_extract`), proved against the
readable guest authority (`src/fight/axis_extract.c`,
`vf3_axis_extract_entry`) by `tests/axis_extract_native_replay.c`
(differential) and by the mutation gate
(`tests/axis_extract_native_mutations.json`, 8/8 caught).

## The leaf

`axis_extract` is a self-contained FP leaf (call-free, no stack frame).  It
derives the camera/body axes from a three-by-four direction table at
`0x0C0EA624` and writes the result to the vector block at `0x0C1A58A0`:

- `block[+16..+18] = (t0, t1, t2) * M^T` — a transformed copy of row 0
- `block[+0..+2] = norm((t0, t1, t3) * M^T)` — the unit axis

where `M^T` is the transpose of XMTRX's 3x3 part.  The guest achieves the
transpose by swapping the matrix's off-diagonal pairs (1,4) (2,8) (6,9)
through FPUL in the other FP bank (FRCHG), and swaps them back at the end, so
XMTRX is unchanged on exit (the port builds the transposed row products
directly).

## The port

`src/native/axis_extract.c` reads the table's four floats and XMTRX from the
context, computes the row products `result[i] = sum_k M[4i+k]*v[k]` directly
(bypassing the FRCHG / FPUL transpose choreography, which the readable comment
itself calls out as buildable directly), normalises the second row by
`1/sqrt(|.|^2)`, and writes the two row results to the block in flat RAM.
The FPUL side effect of the guest's choreography (the value that was in slot 6
of the transposed matrix at the last put-back swap, i.e. `xm[9]`) is
reproduced, as are `r0 = 8`, `r4 = BLOCK`, `r5 = TABLE + 8`.

## The proof

`tests/axis_extract_native_replay.c` seeds the same flat RAM (the table at
`0x0C0EA624`, the block area) and the same XMTRX (the guest XF bank
`v[37..52]`, the native `a->xm[16]`), runs both sides, and compares the six
block words, the XMTRX (unchanged and equal), `fpul`, and `r0`/`r4`/`r5`.
Cases: a rotated basis with `t3 != t2` (so the two row products differ), an
identity matrix with a full 3D direction, and a Z-rotation with a distinct
table.  The residual is the `fsrra` 1/sqrt against `sqrtf`, tolerated at
3e-3.

## The mutation gate

`tools/mutate.py --port src/native/axis_extract.c --exe
build/vf3nativeaxisextract.exe --mutations
tests/axis_extract_native_mutations.json --target vf3nativeaxisextract
--keep-going` catches **8/8**: a wrong axis component in the row-0 dot, the
unit axis reading `t2` instead of `t3`, the row-0 sources swapped, the
normalisation dropped, the length taken from row 0 instead of the axis, the
row written at block offset 0 instead of +16, the FPUL side effect reading
`xm[8]` instead of `xm[9]`, and `r5` advanced by 12 instead of 8.

No regression to the coverage union (`docs/coverage.md` left untreated).
