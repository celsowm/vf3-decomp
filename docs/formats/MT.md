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
  cross-skeleton slots at constant offsets - the table is the stable skeleton
  map (8,880 joints masks interpreted as VF3's body-part enum space).

## Play-back trace windows (M18, oracle-verified)

The evaluator (`fight_f_8c09d6e0`/`fight_f_8c09d69a`) reads these regions of
the **active chain** per frame (slot ids: fight capture MTJACLAU, trace
extract/analysis/mt_field_reads.csv; oracle: `vf3test`):

| slot | window(s) at record base + off | class |
|---|---|---|
| 5093 (primary) | `0x736..0x73D` (1B x8)<br>`0x75B..0x77B` (1B x9 tag run)<br>`0x76C..0x77B` (overlap; tagged part rows)<br>`0x7A4..0x7B0` (4 x f32) | per-part modes<br>per-part tags<br>—<br>live output tuple |
| 5096 (link) | `0xE0/0x14C/0x230/0x2A4/0x35C/0x3B0` (u32 ctrl refs)<br>`0x194/0x1C8/0x1F0` (13B triplet-rows)<br>`0x24C..` / `0x2CC..` / `0x314..` (17B rows) | long-term per-part param slots |
| 1304/1307 | `0x41C..`, `0x4A8..` (+1307: `0x0D4`,`0x40C`,`0x498`,`0x4E4`) | chained continuation records |
| 1313 | `0x2C` (u32) | chain hdr link |
| 572 | `0x3E0..0x3E9` bytes, `0x4E4..0x4F8` u32s | second fighter parallel record (other fighter) |

Semantics (oracle-verified read pattern, mnemonic of the port in
`src/fight/mt_play.c`):

1. byte streams at record+0x736/0x75B are read per part (0..7) — mode and tag.
2. quad at +0x7A4 = live u32[4] (float32s, e.g. 1.68e-3, 3e-3, 0, 6e-2).
3. Then the evaluator walks chained links; 5096 +0x194.. is the effective
   per-frame tuple bucket for the dominant contribution.
4. Second fighter runs a parallel record (slot 572) with its own stream +
   tuple windows (same shape at +0x3E0/0x4E4).

Unknown so far: byte-values semantics within streams A/B (timing/mode codes),
and the u32 ctrl refs at 5096 first column (probably anchors/skips).
