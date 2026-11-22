# native_project_verts

`project_verts` (`0x8C058EA0`) ported to plain C in
`src/native/project_verts.c` (`vf3_native_project_verts`), proved against the
readable guest authority (`src/fight/project_verts.c`,
`vf3_project_verts_entry`) by `tests/project_verts_native_replay.c`
(differential) and by the mutation gate
(`tests/project_verts_native_mutations.json`, 9/9 caught).

## The leaf

`project_verts` is a self-contained FP leaf (call-free, no stack frame).  It
projects and lights a run of vertices into 16-byte output records:

- `r4` = the source stream (six floats per vertex: position xyz, normal xyz)
- `r6` = the vertex count, `r7` -> the mode word (bit 2 selects the side-list
  variant)
- `XMTRX` = the view/projection matrix; `0x0C16B8A8` = the depth scale (its
  reciprocal scales the light direction table entry at `0x0C19D5B0 + 0x80`);
  `0x0C19E0B0` = the ambient term.

Per vertex, `(x, y, z, 1)` goes through XMTRX (an `ftrv`), the reciprocal of
`w` is formed, and a record is written at the output cursor:

    +0 x/w   +4 y/w   +8 1/w   +C  max(dot(normal, light), 0) + ambient

The side-list variant (`mode bit 2`) additionally normalises a second
direction (the `0x0C058FE0` table times the same scale, plus the light),
writes `dot(normal, direction)` per vertex into a side list at `0x0C16B8B8`
(stride 8), and advances the end pointer at `0x0C16B8BC`.

## The port

`src/native/project_verts.c` mirror-images the guest body: it reads the depth
scale, forms its reciprocal, scales the light (and, in the side variant, the
side direction) with the shared round-toward-zero + FTZ float wrappers, then
loops over the vertices transforming each through `a->xm` (`ftrv`), forming
`1/w`, maxing the normal/light dot at zero, adding the ambient, and writing
the four record words.  The `fsrra` 1/sqrt normalisations are reproduced with
`1.0f / sqrtf`.  On exit it writes the advanced output cursor to
`0x0C16B8B0` (and the side end to `0x0C16B8BC` in the side variant), sets the
register contract (`r0 = CURSOR_OUT`, `r4` = advanced source, `r5` = advanced
cursor, `r6 = 0`, `SR.T` set, plus `r1 = SIDE_END` / `r3` = advanced side
cursor in the side variant), and leaves XMTRX unchanged.

## The proof

`tests/project_verts_native_replay.c` seeds the same flat RAM (all the globals,
the source stream, the mode word, the output area) and the same XMTRX (the
guest XF bank `v[37..52]`, the native `a->xm[16]`), runs both sides, and
compares the output records, the advanced cursor and side-end pointers, the
mode flag, the register contract (`r0/r1/r3/r4/r5/r6`, `SR.T`) and XMTRX.
Because the native run re-seeds the shared RAM, the guest's output records and
side list are snapshotted into buffers *before* the native re-seed - the
record comparison is against the guest's captured bytes, not the native's own
later write.  Cases: three vertices plain, three vertices side-list, one
vertex plain on an identity matrix.  The residual is the `fsrra` 1/sqrt
against `sqrtf`, tolerated at 3e-3.

## The mutation gate

`tools/mutate.py --port src/native/project_verts.c --exe
build/vf3nativeprojectverts.exe --mutations
tests/project_verts_native_mutations.json --target vf3nativeprojectverts
--keep-going` catches **9/9**: the light scale dropped, `1/w` kept at `w`,
the `1/w` record offset wrong, the normal/light dot using position instead of
the normal, the ambient term dropped, the side direction's normalisation
skipped, the output cursor not written back, `r0` named wrong, and the source
stream advanced by half a vertex.

No regression to the coverage union (`docs/coverage.md` left untreated).
