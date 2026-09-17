# POL — VF3tb model packages (80 files, MKAO_*/OB*_/others)

## Header (0x30 bytes)
```
+0x00 u32 0x00000200        size-of-header marker
+0x04 u32 build stamp       0x19981021 (1998-10-21)
+0x08 u32 signature-ish     per-file (e.g. 0x00060323) — likely vertex/prim counts
+0x0C u16/u16              part counters (lo=20-49, hi=10-15)
+0x10 u32 0x30             table base
+0x14 u32                  table row count visible in bytes-to-first-per=0x88/0xF8
+0x18 u32                  geometry-area size (e.g. 0x480B0)
+0x1C u32                  TEX/aux area tag (e.g. 0x26000)
```
## Section table @0x30
Rows of u32 offsets (4-byte tables); adjacent pairs (A,B≈B+0xA80) seen at the
top, then steeply ascending region offsets; each row points into a
sub-record-chain: small header (next-ptr, counts) → float blocks.

## Vertex data
Contiguous 3-float blocks (xyz, |v|≤8) of 74–1,106 triples.
26 blocks in MKAO_AK2 (13,687 points). Verified visually: projected point
cloud shows the crater-dome stage silhouette + part lattices.

The float blocks are PVR vertex payloads; connection chain (BoneID→part→list)
in the chain-heads — precise semantics pending the PVR13 packet walk.

Tools: tools/pol_scan.py (block scan + render), tools/pol_peek.py (historic).
Render sanity: extract/assets/pol_ak2.png (crater-dome), pol_big_xz.png.
