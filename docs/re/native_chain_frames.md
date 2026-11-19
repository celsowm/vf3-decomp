# Native chain side-vector walk (0x8C071694)

`src/native/chain_frames.c` is a plain-C port of the fight engine's
`vf3_chain_frames_entry` (SH-4 `0x8C071694`, readable authority
`src/fight/chain_frames.c`) onto the `vf3_native_aim` context.  No guest
SH-4 code runs at runtime: the port reads the chain object and the node
array from the flat matrix RAM through `ram_base` and does every one of its
crosses and normalisations as plain-C float ops.  The contract registers
(r8..r14, pr, sp) and the saved-register stack match the guest bit for bit;
the per-node `+12` side vectors (the routine's only float output) match
within the native float tolerance.

It is the standalone sibling of the inlined `fixup_a` that
`src/native/body_capsule.c` restates over the fitted capsule's nodes; this
port is the same eight-phase walk entered directly as
`vf3_native_chain_frames`.

## What the function does

Given a chain object (r4) - `+4` the node array, `+88` the node count `n`,
`+92` a second count `m` - it gives every node of the closed strip an
orthonormal **side vector** at `node + 12`.  Nodes are 24 bytes: a vec3
position at `+0` and the vec3 this routine writes at `+12`.

The walk builds two edge vectors per node (from the node's previous, next
and further-along neighbours), crosses them with a third, normalises both
crosses, adds them and normalises the sum into the node's `+12`.  The strip
is walked in **eight phases**:

1. **Head nodes** - from the second node while `n-1 > 1`, crossing
   `(E3×E1, E2×E3)`.
2. **First join** - a single-cross node (`E2×E1`) as the runs meet.
3. **The m-run elbow** - one crossing node (`E1×E2, E3×E1`) per outer `m`
   iteration, each followed by:
4. **The counted run** - `n-1` nodes crossing `(E3×E1, E4×E2)`;
5. **The run's join** - crossing `(E1×E3, E2×E1)`.
6. **Second join** - another single-cross node (`E2×E1`), followed by:
7. **The second counted run** - using the `s4` counter, crossing
   `(E3×E2, E1×E3)`.
8. **The last node** - a final single cross (`E1×E2`).

The counts gate which phases run: `n >= 3` and `m >= 3` run all eight;
`m = 1` runs phases 1, 2, 6, 7, 8 only; `n = 2` reduces to just the joins
and the last node.

On exit the port restores r8..r14 and sp to their entry values and clears
**SR's T bit** - the guest's closing `cmp/gt` is false, so T is reset - while
pr is preserved untouched.

## The native transcription

The readable port keeps the guest's frame (`sp0-96 .. sp0-28`) identical
because it was written byte-faithful against the oracle.  The native port
follows the family convention instead: its transient working area lives in C
locals, and only the **saved block** (r8..r14 pushed at `sp0-28..sp0-4`) is
written to RAM, so the frame below the saved block is not compared.  The
regions the proof compares are the node array's `+12` side vectors (float,
2e-3), the saved block + a few words around it (exact) and the contract
registers.

The ground-address decode goes through `mir()`, reproducing the guest's
`vf3_matrix_read` masking (`addr &= 0x1FFFFFFF`, area 3 -> `0x0C000000 |
(addr & 0x00FFFFFF)`) so the node array and object resolve onto the same
flat RAM.

## Proof

`tests/chain_frames_native_replay.c` (`vf3nativechainframes`) seeds a chain
object and an `NNODES`-deep node array whose positions are well-spread and
irregular (so no two edge crosses cancel), seeds the entry registers, the
saved-register stack, pr and a non-zero SR T bit, then runs the readable
`vf3_chain_frames_entry` and the native `vf3_native_chain_frames` from the
same seed and compares:

- the **node `+12` side vectors** at the 2e-3 float tolerance (non-finite
  words must match exactly);
- the **saved stack** `[sp0-32, sp0+8)` bit for bit;
- the **contract registers**: r8..r14, r15, pr, fr12..fr15 and SR's T bit
  (compared as a clear-on-exit equality).

Three fixtures span the count combinations so every phase runs:
`n=6,m=5` (all eight phases), `n=4,m=1` (the joins + runs, no shared `m`
elbow) and `n=2,m=2` (just the joins and the last node).  The +12 vectors
hold well within 2e-3.

The mutation gate `tests/chain_frames_native_mutations.json` catches **12/12**
mutations: the `finish_node` second normalisation, the final normalisation,
the add-vs-sub in the finish sum, the finish write offset (`node+0` instead
of `+12`), the `single_cross` operand order, `unit3` dropping its `sqrtf`,
the phase-1 cross order, the phase-4 `X2` cross order, the phase-5 `X1` cross
order, the phase-2 single-cross order, SR's T bit not being cleared and the
saved-register restore order.

## Care points

- **A near-collinear node seed makes the differential "match" on the wrong
  thing.**  The first node seeder used a deterministic spiral whose two
  consecutive crosses sometimes came out **anti-parallel** (`X2 = -X1`), so
  `X1 + X2 = 0` and the two implementations legitimately diverged when they
  normalised a zero vector differently - the comparison failed on nodes the
  two sides cannot be expected to agree on.  The seed is now a fixed,
  well-spread 3D layout with no three nodes near-collinear, so the crosses
  never cancel.  (This is the same degeneration `body_capsule` documents for
  its own node fixture.)
- **SR's T bit must be *cleared*, not set.**  Unlike `hitbox_overlap` (whose
  closing `cmp/eq` is true), `chain_frames` ends on a false `cmp/gt`, so the
  epilogue does `a->sr &= ~1u`.  The fixture seeds T set (`0x60000001`) and the
  test compares `(sr & 1)` as an equality, so `sr_t_not_cleared` is caught.
- **The saved block is seven registers, not the full set.**  The guest pushes
  r8..r14 only (28 bytes), and the restore must come back in the same order
  - the `saved_restore_reversed` mutation proves the order is pinned.
- **pr is untouched.**  `chain_frames` never writes pr, so the native port
  leaves `a->pr` alone and the test checks it equals the entry pr.  The
  register contract therefore stays closed without a tail-call helper.
