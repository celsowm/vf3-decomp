# native quad_node (0x8C068FE4)

`src/native/quad_node.c` (`vf3_native_quad_node`) is the plain-C port of the
readable `src/fight/geom_readable.c` (`vf3_quad_node_entry`): the
point-in-quad test of one relative polygon node.

## Why it is self-contained

The readable leaf's **only** callee is the triangle winding test
(`0x8C068F92`), which is already natively ported as
`vf3_native_tri_winding` (`src/native/tri_winding.c`).  It is therefore the
same shape as `format_int` (0x8C04AF04, whose only callees were the natively
ported unsigned division helpers): the sole guest call becomes a **direct
native call** into `tri_winding.c`, and the port stays self-contained on
`vf3nativeview` with no runtime dependency on the readable/guest modules.
This is why the earlier exclusion of `terrain_quad_test` (which shares this
entry; the ledger eventually collapses it onto `quad_node`) predates the
native `tri_winding` port — the exclusion was written when the callee was not
yet available natively.

## What it is

```
r4 -> node { u32 flags; u32 rec_off; ... }

  node.flags bit 0 set  -> answer 1 immediately
  else:
      rec = *(u32 *)0x0C113A0C + node.rec_off
      { u32 flags; u32 vtx_off[4]; ...; float live @ +0x18 }
      vertex i at base + rec.vtx_off[i] : { float x @ +0, float z @ +8 }
      query point (FR4, FR5)
      rec.live == 0  -> answer 0
```

Five winding tests are folded into a mask (bit 2 = positive, bit 4 =
negative; a point is inside when all the edges it looked at agree, i.e.
exactly one of the two bits is set):

- `2` inside triangle v0 v1 v2 (diagonal v2->v0 included)
- `4` inside triangle v0 v2 v3 (skipped when `rec.flags` bit 0 is set)
- `0` outside, or `rec.live == 0`

The entry answers in `r0` and restores the callee-saved set (r9..r14,
FR14/FR15, sp, pr) and the 40-byte stack frame it pushes (six saved
registers, FR15, FR14, pr, and one word of locals).

## The register/stack contract

The mask carries `B(0)|B(9..16)|FR(14)|FR(15)`.  On entry the frame is
`sp0 - 40`: the six callee-saved registers r14..r9 are stored at
`sp0-4..sp0-24`, FR15 at `sp0-28`, FR14 at `sp0-32`, pr at `sp0-36`, and the
query point is copied from FR4/FR5 into FR14/FR15 (which are restored on
exit).  The `one_triangle` flag is written to the single local word at
`sp0-40`.  A port that skips any of these dead-stack writes diverges from the
guest's RAM.

## Proof

`tests/quad_node_native_replay.c` (`vf3nativequadnode`) seeds both sides with
the same flat RAM (the base cell at `0x0C113A0C`, a node, a record and four
vertices), the same junk register file and the same FR bank (the query point
in FR4/FR5), then compares the **whole register file** (r0..r15, pr, sr) and
the **whole FR bank** byte for byte with the guest.  The native winding calls
go through `vf3_native_tri_winding`, which is FPU-exact and proved elsewhere.

Scenarios cover every branch: the node-flag short circuit, the `live == 0`
short circuit, a point inside the first triangle, a point inside the second,
a point outside, a one-triangle record whose query disagrees with the
quad fallback, a point on the diagonal, a different `rec_off`, and a
deliberately off-rectangle point (the `edges grind` case) that makes the
`second` mask observable.

All 9 scenarios replay clean, and the mutation gate
(`tests/quad_node_native_mutations.json`, run with
`python tools/mutate.py --keep-going`) catches **12/12** mutations: the node
flag decode, the record base add, the live offset, the one-triangle flag
read, the edge-walk table, the tri1/second masks, the `edges_agree` sense,
the FR14 restore, the pr restore, the r0 store, and the first-winding mask.

Two fixture lessons (`docs/re/quad_node` covers the geometry): the
`live_offset_off` mutation is only observable when the byte a mutated offset
would read is *not* a zero vertex coordinate — the first version of the
"live zero" case had v1 = (0,0), so reading `rec+0x20` (= v1.x) returned 0
and both sides agreed; and the `second & 6u` mask (which drops bit 2 of the
second triangle's folded mask) needs a query point whose windings put a
bit-2 term in `second` that `m` does not already carry — the `edges grind`
point (-1, 1) on the unit square yields windings `[4,4,2,4,2]` where the
correct code folds `m | (second & 6)` to "both bits" (outside, 0) while the
mutated `& 4` leaves only bit 4 (result 4).  A fixture that cannot see a
mutation is a path the fixture never reaches; these two were added precisely
to reach them.
