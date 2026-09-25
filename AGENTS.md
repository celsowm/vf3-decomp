# VF3tb decomp — repo guide for agents

Goal: clean-room C source port of Virtua Fighter 3tb (Dreamcast, MK-51001 V1.002).
Byte-matching is NOT the goal; readable C mirror of behavior is.

## Layout
- `rom/` — untouched ROM tracks (never committed; gitignored)
- `extract/exe/` — descrambled binaries: 1ST_READ.unsc.bin (retail SH-4),
  VF3TBE3.unsc.bin (E3 build), RELOAD.unsc.bin (ARM7 AICA driver)
- `extract/gamedata/` — 412 ISO files as shipped
- `extract/dtpk/` — per-DTPK-package split sections + _dtpk.json
- `extract/ghidra_proj/VF3/` — Ghidra project (headless scripts below drive it)
- `extract/analysis/` — CSVs, decomp logs (gitignored)
- `tools/` — Python RE tools (py3.12, no deps)
- `tools/gscripts/*.java` — Ghidra headless scripts
- `src/` — the actual port (C99); cmake build at `build/`
- `docs/` — progress, format specs, RE notes
- `refs/` — third-party reference clones (gitignored); e.g. `refs/dream-recomp`
  (SH-4 static recompiler: oracle/differential harness, Ghidra headless scripts,
  dcdisc disc tooling), `refs/DreamcastRecompiled` (Duw0ng SH-4 recompiler:
  BRAF/jsr table discovery algorithms mined into tools/braf_tables.py —
  see docs/re/ref_dreamcastrecompiled.md)

## Native tools on hand
- Hitachi SHC toolchain (win32, working): `tools/katana/katana/shc/bin/lbr.exe`
  = interactive librarian (`LIBRARY x.lib` / `LIST` / `OUTPUT x.obj` /
  `EXTRACT modname` / `EXIT`). Extracts SYSROF .obj modules from .lib.
- SDK corpora: `tools/katana/` (Katana 1.0B2 SET5), `tools/kamui/` (Kamui2 +
  Darkness), `tools/katana_raw/` (Katana 0.40 Pre.2 + Release.4 SET4,
  downloaded 2026-09-25; gitignored). The 0.40 `shinobi.lib` carries the
  game's own libraries (GDFS 0.46/0.49, mpdrv_, mpapi_, pdmain_, kdapi_,
  syCache_, syMmu_) — game is GDFS 0.53/NAOMI 0.8. Sweeps land in
  `extract/analysis/sysrof/v040*/` + `v040_*_libmask.csv`; see
  docs/re/sdk_v040.md. `tools/decomp_stats.py` has buckets for masked,
  reloc-aware (libmask2), Katana-0.40-adjacent, and trace-executed.

## Pipeline (proven)
1. image: VF3tb retail ships UNSCRAMBLED — use `extract/gamedata/*.BIN`
   verbatim (identity load at 0x8C010000; proven 100% identical to executed
   traces by `tools/image_truth.py`, docs/re/image_identity.md).
   `tools/dc_scramble.py` is kept only for selfboot MIL-CD titles; do NOT
   re-run it on these binaries.
2. Ghidra (12.1.3 at `tools/ghidra_12.1.3_PUBLIC`, jdk 21 auto-found):
   `python tools/ghidra_run.py run <prog>.unsc.bin -p <X>.java [-D KEY=VAL]`
   (wrapper locates Ghidra+Java, caches in extract/analysis/ghidra_locator.json;
   `doctor`/`list` subcommands; raw analyzeHeadless still works)
3. analysis artifacts into extract/analysis; docs/re/ is the ledger.
4. `tools/callgraph.py`, `fnptr_tables.py`, `fuzzmatch.py`, `string_readers.py`,
   `fidhash.py` (masked-word digests) are the spiders feeding reports;
   `tools/braf_tables.py` resolves BRAF/@Rn switch tables (algorithm ported
   from refs/DreamcastRecompiled; fallback sentinel-walk rows marked
   `kind*?`; see extract/analysis/braf_tables.csv);
   `tools/sysrof.py` drives Hitachi lbr.exe module extraction + byte-exact
   corpus matching (extract/analysis/sysrof/, katana_matches*.csv);
   `tools/task_vm_map.py` produces the fight-engine r14 field map;
   `tools/bin_names.py` emits extract/analysis/bin_names.csv (222 .BIN rows).
5. `tools/sh4dump.py` (needs venv: `tools/.venv/Scripts/python`) - clean SH-4A
   disasm of any address range with literal-pool value annotation; authority
   over the Ghidra dump when bodies are seed-fragmented (2,258 tiny junk fns,
   size<=8). New fn names: re-run `Vf3Baseline.java` to refresh
   `extract/analysis/funcs_1ST_READ.unsc.bin.csv`.

## Solved formats
- DTPK container + AICA ADPCM audio (tools/dtpk_extract.py, adpcm_decode.py;
  C twins in src/media proven bit-exact)
- TEX: RGB565 + PVR twiddle (tools/tex_peek.py)
- MT motion: 8880-slot offset table (tools/mtmap.py → mt_tables/*.csv)
- POL: header + section table + float-vertex blocks (tools/pol_scan.py)

## Current frontier
- Fight dispatcher: switch-table hypothesis FALSIFIED 2026-09-19
  (docs/re/dispatcher_falsify.md); the true chain is the scene-0x0A predicate
  + walker (docs/re/fight_dispatch_chain.md). Probe-mode infrastructure
  (VF3_WATCH / AICA_DUMP) added M10; front-to-fight capture M13 landed the
  BGM voice-kit boundary (docs/re/sound_bgm.md).
- Task-VM field schema: docs/re/task_vm.md (M19).
- Fight-frame composite: src/fight/frame.c + tests/frame_replay.c (M20).
- MT record field semantics (motion VM)
- BGM song-kit voice reset boundaries
- Main loop body (struct-C model: static jsr ceiling ~3%)

## Conventions
- Byte offsets hex, addresses include 0x8C010000 base
- Verification-first: every decode ships with a visual/CRC check artifact
- Git: commit per milestone; do not commit rom/, extract/, build/, *.zip
