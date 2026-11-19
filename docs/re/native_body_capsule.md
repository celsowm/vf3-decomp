# Native capsule-fitting driver (0x8C06F450)

`src/native/body_capsule.c` is a plain-C port of the fight engine's
`vf3_body_capsule_entry` (SH-4 `0x8C06F450`, readable authority
`src/fight/body_capsule.c`) onto the `vf3_native_aim` context.  No guest
SH-4 code runs at runtime: the port reads and writes the flat matrix RAM
through `ram_base`, and every guest callee - the matrix load/push/pop/
invert/concat helpers (`aim_math`/`matrix`), the node-chain relocation loop,
`vf3_native_capsule_chain`, the `chain_frames` strip walk and the
`negate_copy` - is inlined as a plain-C helper.  The contract registers
(r8..r14, fr12..fr15, pr, sp) and the saved-register stack match the guest bit
for bit; the float quads it writes (the end points/axes, the node positions,
the negate_copy destination) match within the native float tolerance.

## What the function does

Given an owner object (r4) and a capsule record (r5), it fits the fighter's
capsule to the current pose and runs the node-chain collision once per chain:

1. **End-point matrices.**  The axis length (`+0xA4`, carried as `x` on a
   zero vector) and the constant axis vector (the ROM word at `0x0C0D3D68`)
   are transformed into the two end-point matrices: end point A (`+0x8C`) /
   axis A (`+0x74`) through the first block (`+12` concatenated with the
   matrix at `+108`), end point B (`+0x98`) / axis B (`+0x80`) through the
   second block (`+112`), each preceded by a load/invert/push.
2. **Chain parameters.**  The push-out vector at `frame+104` (a fixed offset
   up, or sideways when `owner+72` carries `0x21000`; the `0x1000` vs
   `0x20000` bit picks `-2.0*0.1` vs `-2.0*0.05`, and `owner+96 == 21`
   negates it again) and the first chain index `r9` (1 for `owner+97` 8 or
   12, else 2).  The node base is `rec+4 + (r9-1)*n*24`, its neighbour `+n*24`.
3. **Chain loop.**  For every chain, each node is moved onto the capsule
   radius (a reach-capped unit step), the displacement is transformed back,
   the neighbour is relocated, and `capsule_chain` runs on the chain's nodes
   with `part = r8` (the chain index).  A `frame+104` direction transform is
   folded in unless the `0x21000` owner state suppresses it.
4. **Fixups.**  `chain_frames` (`0x8C071694`) writes an orthonormal side
   vector into every node's `+12`; `negate_copy` (`0x8C072B02`) copies the
   record's source to its destination while flipping the sign bit of the
   second three floats.

On the **tail path** (`owner+62 < 2`) the chain loop is skipped and the end
point matrices are restored straight through FINISH (`matrix_copy`).  Both
paths end by copying the matrix at `m32(rec+12)` into `rec+16`.

On exit the port restores r8..r14, fr12..fr15, pr and sp to their entry
values.  SR's T bit stays set: the guest path through the chain loop
(`capsule_chain`'s own `cmp/pl`, then `FIXUP_A`/`FIXUP_B`/`FINISH`) leaves T
set, and the tail path keeps the entry T bit.

## The native transcription

The readable port keeps the guest's frame temporaries (`sp0-168 .. sp0-52`)
identical because it was written byte-faithful against the oracle.  The
native driver follows the family convention instead: its frame slots below
the saved block are **not** compared, so it keeps the whole transient frame
as C locals and only writes what a callee-visible RAM window must see.  The
regions the proof compares are the record, the node array and the
negate_copy destination (float, 2e-3), the saved block and the caller-visible
frame `[sp0-48, sp0+32)` (exact), and the contract registers.

Two helpers deserve note:

- `fixup_a` is a faithful restatement of `chain_frames`' eight-phase strip
  walk; it keeps the counters as locals but writes the same node `+12` side
  vectors, which are in the compared node region.
- The ground-address decode goes through `mir()`, reproducing the guest's
  `vf3_matrix_read` masking (`addr &= 0x1FFFFFFF`, area 3 -> `0x0C000000 |
  (addr & 0x00FFFFFF)`) so the literal-pool constants (`0x8C06F6xx`,
  `0x0C29BCC4`) and the in-RAM data resolve onto the same flat RAM.

## Proof

`tests/body_capsule_native_replay.c` (`vf3nativebodycapsule`) seeds an owner,
a capsule record (with its node array, end-point/join matrices, counts, link
scale, reach and axis length), a matrix-stack control block for the guest and
the literal-pool constants, then runs the readable `vf3_body_capsule_entry`
and the native `vf3_native_body_capsule` from the same seed and compares:

- the **record** (matrix outputs / end points / axes), the **node array**
  (positions and side vectors) and the **negate_copy destination** at the
  2e-3 float tolerance (non-finite words must match exactly);
- the **frame + saved block** `[sp0-48, sp0+32)` bit for bit;
- the **contract registers**: r8..r14, r15, pr, fr12..fr15 and SR's T bit
  (compared as an equality, since the two paths both leave it set).

Nine cases span the paths: the `owner+72` else/`0x1000`/`0x20000` selection,
`owner+96 == 21`, both `capsule_chain` skip doors (`owner+96 == 8` and
`owner+97 == 4`, the latter with a `part`-to-4 boundary), the first-chain
`owner+97 == 8`, the tail path (`owner+62 < 2`) and a single-chain degenerate.
The node worst-case residual is ~4.3e-6, well under 2e-3.

The mutation gate `tests/body_capsule_native_mutations.json` catches **11/11**
mutations: the SR T-bit, the initial `r9`, the first-chain `r9` constant, the
`owner+72` gate mask, the `owner+96 == 21` constant, the node reach scale,
the node-loop stride, the phase-1 cross order in `fixup_a`, the `negate_copy`
sign, the FINISH copy destination and the r12 epilogue restore.

## Care points

- **A near-collinear node seed makes the differential pass vacuously.**  The
  first node seeder laid the nodes out symmetric and collinear, so
  `chain_frames`' two crosses cancelled and both sides normalised a zero
  vector into *different* garbage - the comparison "failed" on nodes the two
  implementations diverge on legitimately.  The nodes are now spread
  irregularly so no two edge vectors are parallel.
- **SR's T bit lives in the `r9`-gated path, not the epilogue.**  The native
  `capsule_chain` clears T, so the driver has to set T again on the non-tail
  path to match the guest (which leaves T set after the chain loop).  The
  tail path never runs `capsule_chain`, so it keeps the entry T bit.  The
  fixture proving the parity is the chain loop that reaches `capsule_chain`.
- **The `part` forwarded to `capsule_chain` is unobservable in these
  fixtures.**  `part` only gates `capsule_chain`'s `skip_first`
  (`+97 == 4 && part <= 4`, `+96 == 8 && part <= 3`), and `capsule_chain` is
  itself proved separately (see `native_capsule_chain.md`).  In the fitted
  capsule geometry the stage result equals the relink, so a `part` mutation
  leaves the compared node region identical; the two skip-door fixtures still
  exercise the driver correctly handing the part through.

## Run it

```
cmake --build build --target vf3nativebodycapsule
build/vf3nativebodycapsule            # (from the repo root; needs extract/exe)
python tools/mutate.py --port src/native/body_capsule.c \
    --exe build/vf3nativebodycapsule.exe \
    --mutations tests/body_capsule_native_mutations.json \
    --target vf3nativebodycapsule
```
