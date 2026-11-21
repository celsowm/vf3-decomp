# native_xmtrx_transpose — the current-transform transpose (0x8C03CC30)

The readable port `src/fight/matrix_extra.c` (`vf3_matrix_transpose_entry`)
is rewritten as plain C in `src/native/xmtrx_transpose.c`
(`vf3_native_matrix_transpose`), proved against it by
`tests/xmtrx_transpose_native_replay.c` (3 differential cases) and by the
mutation gate (`tests/xmtrx_transpose_native_mutations.json`, 7/7 caught).

## The leaf

A self-contained, call-free, no-FPU-math, no-stack leaf that transposes the
4x4 column-major matrix in XMTRX by swapping the six symmetric off-diagonal
pairs:

```
swap XMTRX pairs  (1,4) (2,8) (3,12) (6,9) (7,13) (11,14)
```

No general register, SR, pr or RAM is touched.  The guest keeps XMTRX in the
XF bank (`s->v[37..52]`); the native port maps it straight to `a->xm[16]`.

## The port

```c
void vf3_native_matrix_transpose(vf3_native_aim *a)
{
    float t;
    SWAP(1,4); SWAP(2,8); SWAP(3,12); SWAP(6,9); SWAP(7,13); SWAP(11,14);
}
```

Since a transpose is a pure value reorder (no arithmetic), the 16 floats are
swapped in place and the port needs no FPU wrapper — every bit pattern passes
through as-is, exactly like the guest's word-level `swap_xf`.

## The test

`tests/xmtrx_transpose_native_replay.c` seeds both sides with the same
non-symmetric 16-word matrix (distinct values everywhere, so a wrong pair
shows), runs the leaf, and checks against the guest **and** an independent
transpose model: XMTRX (`a->xm` vs `s->v[37..52]`) must be the transpose,
every general register must equal its entry value, and every RAM byte must
be untouched (checked against a pristine snapshot).  Three cases with
different matrix/seed values.

## The mutation gate

`tests/xmtrx_transpose_native_mutations.json` applies 7 single mutations: a
wrong pair endpoint (or a value off the queue) for each of the six swaps, and
two removed-swap cases.  All 7 are caught against the guest.  Command:

```
python tools/mutate.py --keep-going --port src/native/xmtrx_transpose.c \
  --exe build/vf3nativexmtrxtranspose.exe \
  --mutations tests/xmtrx_transpose_native_mutations.json \
  --target vf3nativexmtrxtranspose
```

## Authority

The readable port is the authority; the chain is *native == readable*.  No
oracle corpus names this exact entry as a watched specimen, so the proof
stands on the differential against the readable translation (the same shape
every readable leaf uses).

Result: **3/3 PASS**, **7/7 mutations caught**.
