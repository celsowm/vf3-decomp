# MT*.BIN — VF3tb motion files (paired-fighter packs)

91 files `MT<abc><def>.BIN`, each covers an "A vs B" pairing.

## Table
- `0x0000..0x22BB`: 8,880 × u32 slot table (≈76% empty = 0)
- every nonzero slot holds a record offset (min is always `0x8AC0`)
- record size = next-nonzero-slot offset − this slot (eof-terminated)
- record sizes cluster 40–150 bytes

Totals: 209,925 records over 91 files
(tools/mtmap.py → extract/analysis/mt_tables/*.csv)

## Record anatomy (observed, not field-mapped)
```
+0  u16-ish header (0x0014/0x0020 dominated)
+2  cmd stream: bytes 0x01/0x02/0x05/0x09 pattern (bone enable/anim class)
    followed by u32 float lookalikes (e.g. ~0.9995, -0.0041, 0.95)
```
This is the VF3 motion VM (per-frame bone-rotation + translation delta tables).
Field-level reversal pending; canonical names respected from the dev tree
(`/pub/data3/vf3/naomi/c/mt*` read by `mt_loader` @ 0x8C02DCEC).

## Validation anchors for future decoding
- `MT*x*x.BIN` (mirror pairs: MTAKIAKI etc.) vs random pairings share
  cross-skeleton slots at constant offsets — the table is the stable skeleton
  map (8,880 joints masks interpreted as VF3's body-part enum space).
