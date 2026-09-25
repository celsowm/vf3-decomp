# M41 — decompile gap closed (2026-09-25)

`extract/analysis/decomp_all/_index.csv` = 2398 rows, `ok=1` for 2395,
`ok=0` for 3 (not 2):

| entry | size | reason (sh4full.py clean decode) |
|---|---|---|
| 0x8C070022 | 204 | FPU-heavy + inline data words `0x01B0` at 0x8C070062.. + `mov.b r13,@(r0,r0)` junk sweep confuses decompiler; body valid (sts.l pr, fmov.s ladder, jsr 0x0C042D7C) |
| 0x8C08FE62 | 322 | inline `.word 0x0000` at 0x8C08FE98 + `.word 0xF37D` at 0x8C08FEF4 + `stc r2_bank` + mova/fmac vector math; valid |
| 0x8C0A6642 | 328 | inline `.word 0x4810/0x4E10` at 0x8C0A66F2/0x8C0A6728 (data islands in float loop) + fdiv/fmac nest; valid |

Evidence: `python tools/sh4full.py 8c070022 120` / `8c08fe62 160` /
`8c0a6642 160` all decode coherently on true image
(`extract/exe/1ST_READ.unsc.bin` @0x8C010000). Ghidra decompiler choked on
data-island words, not bad code. No re-run needed; bodies available via
sh4full for manual transliteration.

`_index.csv` is the authority (2398 rows); `.c` file count 2395 + header =
2396 entries on disk.
