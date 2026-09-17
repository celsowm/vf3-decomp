# POL (VF3 model / stage polygon package — AM2 Model-3 heritage)

Status: **format candidate v0** — read from four sample files (MKAO_AKI.POL,
ST01.POL, ROB_ALP.POL, MKAO_WOL.POL).

## Header (u32 fields, offsets are byte offsets from file start)

| off | example (MKAO_AKI.POL) | meaning |
|---|---|---|
| 0x00 | 0x00000200 | header tag / size class (all files = 0x200) |
| 0x04 | 0x19981021 | **authoring stamp** "1998-10-21" packed decimal (same in all model + stage POL) |
| 0x08 | 0x00060629 | unknown (layout-dependent; varies per file) |
| 0x0C | 0x000A0016 | uint16 pair (A=22?) counts |
| 0x10 | 0x00000030 | **table base** (48) |
| 0x14 | 0x00000088 | unknown (flags?) |
| 0x18 | 0x0004C5B0 | **total file size** |
| 0x1C | 0x00026000 | payload byte count hint |
| 0x20..0x2C | 0 | gap |
| 0x30+ | list of u32 offsets (part/section table) | |

## Table at 0x30

Roughly 20–60 u32 values; most point into the file's data area. Sizes/regions
between consecutive entries are irregular — likely per-part/per-bone section
list (model of the character's body parts), not a uniform stride struct.
Notably sections include both the model's NGON/TA packets and secondary info.

Open questions:
- which table entries are vertex/TA vs aux (skinning, hitbox, collider)
- how the game binds part-table index to bone hash (MT* files give motion)

## Next steps
1. correlation with `MKAO_*.TEX` (texture page count) and ROB_*.POL twins
2. Ghidra: find POL loader via literal `0x00000200` constant usage in code
3. try interpreting section bodies as PowerVR TA packet streams (strip heads)
