# VF3tb decomp — progress log

## M1 — Ground truth & environment (COMPLETE)
- [x] git repo + ignore rules (no copyrighted data tracked)
- [x] `tools/extract_iso.py`: track-3 ISO9660 → **412 files** → `extract/gamedata/`, manifest `docs/files.md` (+ sha1 csv)
- [x] `tools/extract_ip.py`: IP.BIN parsed → `docs/ip.md` (MK-51001 V1.002 1999-08-20, area U)
- [x] `tools/dc_scramble.py`: descramble verified (**rescramble == original, byte-exact**);
      outputs: `extract/exe/{1ST_READ,VF3TBE3,RELOAD}.unsc.bin`
- [x] Executables identified: SH-4 main + E3 build + RELOAD module + ARM7 `SNDDRV.BIN` (`docs/executables.md`)
- [x] `DATELIST.ASC` (416 NUL-separated records) parsed → dev-tree taxonomy in `docs/build_manifest_notes.md`
- [x] Katana SDK 1.0B2 extracted via idecomp (IS3 `.Z`) → `tools/katana/`; Kamui → `tools/kamui/` (`docs/sdk_inventory.md`)
- [x] Ghidra 12.1.3 in-workspace; project `extract/ghidra_proj/VF3` with 1ST_READ + VF3TBE3 @ 0x8C010000;
      prologue-sweep script → **2,403 / 2,398 functions** created, CSVs in `extract/analysis/`
- [x] Kamui fingerprint tool built (639-function corpus; negligible matches → **VF3tb does not use Kamui2**)
- [x] Library stack identified in-binary: `NAOMI LIBRARY Ver 0.8`, `GDFS 0.53`, `syCache/syCbl`, `pd 1.07`, `bu 1.03`, `kd 1.20`
- [x] Asset inventory + first format signatures: `DTPK` container magic (u32 + u32 size),
      `CP_*` raw RGBA5551, raw PVR `*.TEX`, `POL` model packet streams, `.CLI` collision tables
      → `docs/formats/INVENTORY.md`
- [x] `src/` + cmake skeleton builds green (gcc, native stub)

## M2 — Naming & structure (IN PROGRESS)
- [x] Katana SDK 1.0B2 **extracted** (idecomp) — Shinobi + SHC Ver5.0R28 present
- [x] `tools/fingerprint.py` corpus widened (Kamui 25 maps + Katana `ip`/`mw_wav`): **1,171 functions**; 58 hits in 1ST_READ (SHC runtime helpers + Shinobi GD + NEC/Kamui driver tails)
- [x] `Vf3ApplyNames.java` applied 57/58 names into Ghidra project (`cand_`/`an_` prefixes mark pending verification)
- [x] RELOAD.BIN imported into Ghidra alongside 1ST_READ + VF3TBE3
- [x] Verify fingerprint matches — `_memset` (correct byte-fill loop) & `_gdFsDaPlaySct` (driver vtable dispatch) verified by disassembly
- [x] Syscall block mapped (0x8C0000Ax-FF block + labels; first ref: 0x8C0000BC at 0x8C011E02) — deeper xref analysis pending
- [x] Cross-build diff v1 (mnemonic streams): 604 identical lib/stable functions, 3,092 game-code candidates cataloged (extract/analysis/build_diff_map.csv)
- [ ] Shinobi rich symbol set: `shc.exe` runs but hits "Memory overflow" on modern-RAM machines — alternative: parse Hitachi `.lib` members or link anchor binaries with `lnk.exe`
- [ ] Hitachi LBR1-MW `.lib` format reverse (shinobi.lib directory seen at low offsets: name+timestamp+two u16 records)
- [x] Offline call-graph v1 (`tools/callgraph.py`): 1,352 resolved call edges; register-indirect handling incl. callee-saved lifetime; caller fn attribution via func CSV
- [x] Hotspots report regenerated per program (docs/re/hotspots_*.md)
- [x] DTPK probe: 69 packages, header fields laid out (`docs/formats/DTPK.md`)
- [ ] Indirect-call group discovery: jsr sites whose target reg is a *caller argument* - cluster by containing function (task-runner pattern at f_8c0198e4 etc.)
- [x] TEX format broken: RGB565 + PVR twiddle — first visually verified decoded asset (AKI face)
- [x] POL format v1: tagged structure + offset map (docs/formats/POL.md)
- [ ] Fuzzy version tracking (similarity hashing over mnemonic streams)
- [ ] DTPK package parser (BGM/VO/LEVEL/PLAYER/ANAUNCE/COIN/ST_*.BIN)
- [ ] POL packet dissector (first bytes `00 02 00 00 21 10 98 19 ...`)
- [ ] Investigate `.CLI` = collision (COLI_S dev path), MOTHEAD/MT* motion tables
- [ ] docs/re/: write-up of entry/GDFS init/main-loop/task system once identified

## M3+ — Fight engine, asset dumps, source-port modules
(see plan text in project history)
