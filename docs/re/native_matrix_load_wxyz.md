# native_matrix_load_wxyz — the wxyz matrix load leaf (0x8C03EFB0)

The readable port `src/fight/matrix_lib.c` (`vf3_matrix_load_wxyz_entry`) is
rewritten as plain C in `src/native/matrix_load_wxyz.c`
(`vf3_native_matrix_load_wxyz`), proved against it by
`tests/matrix_load_wxyz_native_replay.c` (3 differential cases) and by the
mutation gate (`tests/matrix_load_wxyz_native_mutations.json`, 7/7 caught).

## The leaf

A self-contained, call-free, FPU-free, no-stack leaf that loads the matrix at
`r4` into XMTRX with every column rotated to `(w, x, y)` and a negated `w`
behind it.  The guest keeps XMTRX in the XF bank (`s->v[37..52]`); the native
port maps it to `a->xm[16]`.

```
for each column c (stride 16):
    a, b, cc, d = the four words at src + 16c .. +12
    (cc is read but dropped)
    xm[4c+0] = d
    xm[4c+1] = a
    xm[4c+2] = b
    xm[4c+3] = d ^ 0x80000000    (negated w)
r4 += 64
```

A column `(a b c d)` becomes `(d a b -d)`.  Only `r4` and XMTRX move; r15 and
SR are untouched.

## The test

`tests/matrix_load_wxyz_native_replay.c` seeds both sides with the same flat
RAM (a source matrix whose four words per column are all distinct) and the
same XMTRX, runs the leaf and compares the whole XMTRX and `r4` against the
guest, asserts every other general register unchanged, and cross-checks the
result against an independent fixture model (`(d a b -d)` per column).  Three
cases differing only in the seeded XMTRX (including a top-bit seed that
exercises the negated-`w` on negative words).

## The mutation gate

`tests/matrix_load_wxyz_native_mutations.json` applies 7 single mutations:
the negated-`w` mask, the column count one short, each of the three slot
sources `d`/`a`/`b` swapped, the `r4` advance, and the column stride.  All 7
are caught.

## Authority

The readable port is the authority; the chain is *native == readable*.  No
oracle corpus names this exact entry as a watched specimen, so the proof
stands on the differential against the readable translation.

Result: **3/3 PASS**, **7/7 mutations caught**.
