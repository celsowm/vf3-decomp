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
6. replay bench: `tools/replay_scan.py` (batch strict-replay probe of unported
   entries against every corpus; `--deep` for >400-case corpora),
   `tools/sweep_top.py` (same probe restricted to the largest N unported
   entries that already own a shadowed corpus; emits a promote-ready CSV with
   a `corpus` column),
   `tools/check_new_bindings.py` (strict-replay gate over a chosen binding
   set, e.g. `--only-new-since HEAD~1`; honours each binding's own test
   binary),
   `tools/promote_replay.py` (re-run gated promotion into
   tools/golden_bindings.json + docs/decomp_status.csv),
   `tools/regen_ram_shadows.py` (restore missing case shadows from capsules),
   `tools/coverage70_audit.py` + `tools/final_status.py` (audit/gap reports).
   The 70% milestone sealed the first full sweep (b04fd0d); the 78% milestone
   was crossed by promoting 23 already-replaying-but-unledgered owners
   (5,764 B). Remaining corpus-blocked clusters are diagnosed in
   docs/re/reios_exec_server.md.
7. porting a body: `tools/oracle/translate_adapters.py` walks the CFG from a
   set of watch roots and emits readable C (0 unsupported instructions per
   batch). `tools/gen_translate.py` resolves each root's capture dirs from the
   recorded `f_<entry>.ops.json` maps and prints the invocation;
   `tools/body_complete.py` proves every PC of the entry's body ranges is
   emitted; `tools/binding_steal.py` lists the pre-existing golden bindings a
   new module would shadow. Wire the result into `src/fight/matrix_family.c`
   (router chain) + `matrix_family.h` + `CMakeLists.txt` (two source lists),
   then promote with `tools/promote_replay.py`. Used for the 80% milestone:
   16 bodies, 5,084 B — see docs/re/coverage_80_generated_adapters.md.

## Solved formats
- DTPK container + AICA ADPCM audio (tools/dtpk_extract.py, adpcm_decode.py;
  C twins in src/media proven bit-exact)
- TEX: RGB565 + PVR twiddle (tools/tex_peek.py)
- MT motion: 8880-slot offset table (tools/mtmap.py → mt_tables/*.csv)
- POL: header + section table + float-vertex blocks (tools/pol_scan.py)

## Current frontier
- Coverage: 80.40% verified C (349,442 B of 434,656). The 80% bar (347,725 B)
  is cleared with 1,717 B of margin. The 78% bar was crossed by promoting 42
  ledger ghosts in 434d22b (bodies whose C already existed and replayed clean
  but had no docs/decomp_status.csv row). That pool is mined out; the 80% bar
  was crossed by *new* C: 16 bodies ported through the repo's own adapter
  translator (tools/oracle/translate_adapters.py) into src/fight/vf3_c80_adapter.c
  and src/fight/vf3_c81_adapter.c — 5,084 B, 16 entries, every one strict-replay
  clean with zero skipped cases. Recipe, checks and the two bodies left out:
  docs/re/coverage_80_generated_adapters.md. Next bar: 82% = 356,418 B
  (6,976 B more).
- The largest remaining unported body, 0x8C0831F8 (1,964 B), is fully
  implemented in vf3_c80_adapter.c and is exercised by 0x8C083AA8's 182-case
  corpus, but it is NOT credited: it has no corpus of its own. The emulator
  reached the entry on all 256 synthetic-patch invocations and rejected every
  specimen with flags=4 — the oracle's RAM window is a compile-time
  `LIMIT = 128` pages (512 KB) in tools/emu/flycast/core/vf3oracle.cpp, and
  --probe-ops is capped at 100000 by tools/golden_batch.py. 0x8C0A8ACA (544 B)
  and 0x8C04C9AE (362 B) are the same shape: their RAM shadows were deleted
  with their capsules, so they replay as "no RAM cases".
- FPU lane: 0x8C06A35C (570 B) is a live FPUL defect, but NOT an FTRC
  semantics bug — the repo oracle (extract/analysis/fsca_modes.bin.ops)
  confirms ftrc(+Inf)=0x7fffffff, ftrc(-Inf)=ftrc(NaN)=0x80000000, which
  src/fight/sh4_fpu.c already matches. The divergence is upstream: the
  reference's r10 at the 0x8c06a3c4 ftrc site is negative (giving -Inf),
  ours is +1 (giving +Inf). r10 comes from the REIOS dispatch stub
  0x0c0c66c8, modelled in matrix_adapters.c as `r0 = *(r4)`, so the real
  fix is a faithful REIOS service model, not a float change.
- Fight dispatcher: switch-table hypothesis FALSIFIED 2026-09-19
  (docs/re/dispatcher_falsify.md); the true chain is the scene-0x0A predicate
  + walker (docs/re/fight_dispatch_chain.md). Probe-mode infrastructure
  (VF3_WATCH / AICA_DUMP) added M10; front-to-fight capture M13 landed the
  BGM voice-kit boundary (docs/re/sound_bgm.md).
- Native fight tick (2026-10-15): `build/vf3 <golden_tickx_vf3_N.bin> --expect ...`
  (src/main.c, src/fight/native_tick.c) runs one scheduler tick (0x8C09616A) on C only
  for 13 captured fight states; 0 unowned calls, RAM equals the reference oracle.
  ~99.9% of state-7 executed steps (159 readable entries) are readable ports (docs/readable_status.csv), the rest
  generated adapters. Plan/limits: docs/re/plan_native_slice.md; verify with
  tools/recomp/run_state.sh and run_native.sh.
- Task-VM field schema: docs/re/task_vm.md (M19).
- Fight-frame composite: src/fight/frame.c + tests/frame_replay.c (M20).
- MT record field semantics (motion VM)
- BGM song-kit voice reset boundaries
- Main loop body (struct-C model: static jsr ceiling ~3%)

## Conventions
- Byte offsets hex, addresses include 0x8C010000 base
- Verification-first: every decode ships with a visual/CRC check artifact
- Git: commit per milestone; do not commit rom/, extract/, build/, *.zip
