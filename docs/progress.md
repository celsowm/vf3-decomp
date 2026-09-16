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

## M2 — Naming & structure (NEXT)
- [ ] Shinobi symbol fingerprinting (Hitachi `.lib` member/symbol parser in Python) → name `sy/gd/bu/pd` functions in 1ST_READ
- [ ] Locate syscall vector block usage (0x8C0000B0 region) + entry path crt0 analysis
- [ ] Ghidra: import RELOAD.BIN too; Version Tracking between retail and E3 builds
- [ ] DTPK package parser (BGM/VO/LEVEL/PLAYER/ANAUNCE/COIN/ST_*.BIN)
- [ ] POL packet dissector (first bytes `00 02 00 00 21 10 98 19 ...`)
- [ ] Investigate `.CLI` = collision (COLI_S dev path), MOTHEAD/MT* motion tables
- [ ] docs/re/: write-up of entry/GDFS init/main-loop/task system once identified

## M3+ — Fight engine, asset dumps, source-port modules
(see plan text in project history)
