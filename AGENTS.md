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
   new module would shadow; `tools/build_promote_csv.py` resolves each
   entry's complete corpora into a promote CSV. Wire the result into
   `src/fight/matrix_family.c` (router chain) + `matrix_family.h` +
   `CMakeLists.txt` (two source lists), then promote with
   `tools/promote_replay.py`. Used for the 80% and 81% milestones: 33 bodies,
   8,418 B — see docs/re/coverage_80_generated_adapters.md.

## Solved formats
- DTPK container + AICA ADPCM audio (tools/dtpk_extract.py, adpcm_decode.py;
  C twins in src/media proven bit-exact)
- TEX: RGB565 + PVR twiddle (tools/tex_peek.py)
- MT motion: 8880-slot offset table (tools/mtmap.py → mt_tables/*.csv)
- POL: header + section table + float-vertex blocks (tools/pol_scan.py)

## Current frontier
- Coverage: 92.05% verified C (400,098 B of 434,656). The 90% bar
  (391,190 B) and the 92% bar (401,084 B) - the 92% bar is reached on the
  *union* of body ranges, which is the number `tools/final_status.py` prints;
  `tools/decomp_stats.py` counts 403,920 B because it also credits the
  trace-covered bodies.  The 80%-91% stretch came from the device-tape
  capture work and from bodies ported through the repo's own adapter
  translator (tools/oracle/translate_adapters.py) into
  src/fight/vf3_c80_adapter.c ... vf3_c96_adapter.c.  Recipe, checks and the
  bodies left out: docs/re/coverage_80_generated_adapters.md,
  docs/re/coverage_92_translator_gaps.md and docs/re/oracle_device_reads.md.
  Next bar: 93% = 404,230 B (4,132 B more).
- **A generated module must claim, not just own.**  The router picks an owner
  by entry PC, and the chain order decides who wins a contested PC.  The
  generator therefore emits two arrays: owned_pcs[] (every PC it implements,
  for the coverage audit) and claim_pcs[] (the PCs it may route: the ones no
  other module owns, plus its own roots).  Without the second array a module
  placed early in the chain takes over entries it only implements partially.
- **The REIOS BIOS vectors are the loader's door.**  0x8C001000 system,
  0x8C001002 font, 0x8C001004 flashrom, 0x8C001006 gdrom, 0x8C001008 misc.
  A missing vector is not a small gap: the legacy adapter used to escalate
  the whole 0x0c0010xx family to the router, which handed it straight back,
  and the call recursed until the C stack overflowed.  Escalate only the
  vectors the stub owns, and mask the target (a caller may hold it in the
  0x8c form).
- **The oracle's RAM page budget was 128 pages (512 KiB) and the arena
  fixture alone used all of it.**  The budget is a memory limit, not a
  semantic one; `docs/re/patches/oracle_device_reads.patch` now raises it to
  1024 pages, and the corpora recorded after that carry every page the
  target touched.  A corpus recorded before the raise can be *truncated* -
  the port then reads a dropped page as zero and the harness's
  out-of-window counter rejects a correct port.  Promotion may drop such a
  corpus only when another corpus of the same entry replays clean
  (extract/analysis/u99_filter_truncated.py).
- **Coverage is a body-range union, not a ledger sum.**  tools/decomp_stats.py
  merges the body ranges of every ported ledger entry, so promoting an entry
  whose body is nested inside another ported entry adds zero bytes.  Use
  extract/analysis/u90_newbytes.py to rank the unported entries by the
  bytes they would *add*; extract/analysis/u90_pools.py only ranks them by
  ledger membership and over-counts.
- **The capture blocker was the oracle's device policy, not the fixture.**
  A synthetic probe that touched a device address was rejected (flags 2|4),
  which is why 383 unported entries had no corpus at all.  The oracle now
  allows a device *read* of a register with no read side effect and
  *suppresses* a device write instead of aborting the specimen; the value is
  journalled in the capsule's device tape and the C replay feeds it back
  through ram->device_read.  The patch also clears SR.FD for the probe: with
  the FPU disabled, every FPU instruction in the target raises
  Sh4Ex_FpuDisabled and the oracle retires the specimen on the RTE.  See docs/re/oracle_device_reads.md and
  docs/re/patches/oracle_device_reads.patch (the oracle lives in the
  gitignored tools/emu tree, so the patch is kept in the repo).
- tools/oracle/isolated_probes.py gained --arena-seeds (seed every register
  the static inference could not classify with a RAM arena pointer) and now
  passes --probe-ops through to tools/golden_batch.py instead of leaving
  every probe on the 20,000-instruction default budget.
- Still unpromoted, by cause: the drive state behind the GD vector (the
  loader polls GET_CMD_STAT until the transfer completes, and the size it
  reports is the byte count the drive has moved - the oracle's VF3_GDLOG
  observer shows the state per invocation, and result[2] in that log is
  exactly the size the corpus expects, so the corpus only has to carry the
  state of each of its cases; two corpora of the same entry can disagree
  about it, so a faithful REIOS service model is needed - see
  docs/re/reios_exec_server.md); the corner-block descriptor loop at
  0x0c0510b6 (its trip count comes from driver state the corpora do not
  carry); STC VBR in the helper 0x0c060eba; a device write the reference did
  not make (0x8c09aa14); an uncaptured write (0x8c0a2a84); one byte of a RAM
  window (0x8c04340c); and the literal-pool family (0x8c058780/84/88/8c,
  whose bodies run into a literal pool and execute data in the reference).
- **The 500,000-instruction probe budget is validated but locked.**
  tools/oracle/extended_observer_controls_v1.json authorises the separate
  recorder flycast_capsule_extended_v1.exe to record 500,000 instructions per
  probe, which is what a spinning probe needs.  The proof pins a reference log
  (extract/analysis/extended_capsule_tool_tests_v1.log) by digest; that file
  lived in the gitignored extract/ tree and is gone, so the proof cannot be
  validated and the budget cannot be used.  Most of the 260 corpus-less
  entries (33,970 B) are waiting for it.
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
