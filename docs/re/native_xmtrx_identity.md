# native_xmtrx_identity — the current-transform identity reset (0x8C03CCB0)

The readable port `src/fight/matrix_lib.c` (`vf3_matrix_identity_entry`) is
rewritten as plain C in `src/native/xmtrx_identity.c`
(`vf3_native_xmtrx_identity`), proved against it by
`tests/xmtrx_identity_native_replay.c` (3 differential cases) and by the
mutation gate (`tests/xmtrx_identity_native_mutations.json`, 6/6 caught).

## The leaf

A self-contained, call-free, no-stack leaf:

```
XMTRX  = the column-major 16-float identity
FR0..FR3 = (1, 0, 0, 1)   (these stay behind)
```

No general register, SR, pr or RAM is touched.  The guest keeps XMTRX in the
XF bank (`s->v[37..52]`) and FR in `s->v[21..24]`; the native port maps them
straight to `a->xm[16]` and `a->fr[0..3]`.

## The port

```c
void vf3_native_xmtrx_identity(vf3_native_aim *a)
{
    vf3_native_matrix_identity(a->xm);   /* shared, already-proved helper */
    a->fr[0] = 1.0f; a->fr[1] = 0.0f; a->fr[2] = 0.0f; a->fr[3] = 1.0f;
}
```

The identity is written through the shared `vf3_native_matrix_identity`
helper (already proved by the native motion/renderer paths), so the port's
own surface is the four FR writes plus the call.

## The test

`tests/xmtrx_identity_native_replay.c` seeds both sides with junk XMTRX,
junk FR0..3 and distinct general registers, runs the leaf, and checks
against the guest: XMTRX (`a->xm` vs `s->v[37..52]`) must be the identity,
FR0..3 (`a->fr` vs `s->v[21..24]`) must be (1, 0, 0, 1), every general
register must equal its entry value, and every RAM byte must be untouched
(checked against a pristine snapshot).  Three cases with different junk/seed
values.

## The mutation gate

`tests/xmtrx_identity_native_mutations.json` applies 6 single mutations: a
skipped identity call and the five FR writes (each value wrong, or a write
removed).  The identity *helper* is not mutated — it is shared and proved
elsewhere, so the gate targets the port's own lines.  All 6 are caught
against the guest.  Command:

```
python tools/mutate.py --keep-going --port src/native/xmtrx_identity.c \
  --exe build/vf3nativexmtrxidentity.exe \
  --mutations tests/xmtrx_identity_native_mutations.json \
  --target vf3nativexmtrxidentity
```

## Authority

The readable port is the authority; the chain is *native == readable*, and
the shared identity helper the port uses is proved independently by the
native matrix/motion paths.  No oracle corpus names this exact entry as a
watched specimen, so the proof stands on the differential against the
readable translation (the same shape every readable leaf uses).

Result: **3/3 PASS**, **6/6 mutations caught**.
