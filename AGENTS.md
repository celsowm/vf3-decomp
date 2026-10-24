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
   On the *readable* track a port is proved offline, against the retained
   generated translation, and `tools/mutate.py` proves the proof has teeth:
   it applies one mutation at a time to the port's source, rebuilds and
   requires the port's test to fail.  The mutation list lives next to the test
   it guards, as `tests/<name>_mutations.json`.  A mutation the test cannot
   see is a path the test never reaches.

## Solved formats
- DTPK container + AICA ADPCM audio (tools/dtpk_extract.py, adpcm_decode.py;
  C twins in src/media proven bit-exact)
- TEX: RGB565 + PVR twiddle (tools/tex_peek.py)
- MT motion: 8880-slot offset table (tools/mtmap.py → mt_tables/*.csv)
- POL: header + section table + float-vertex blocks (tools/pol_scan.py)

## Current frontier
- Coverage: 93.35% verified C (405,744 B of 434,656). The 90% bar
  (391,190 B), the 92% bar (401,084 B) and the 93% bar (404,230 B) are all
  reached on the *union* of body ranges, which is the number
  `tools/final_status.py` prints; `tools/decomp_stats.py` counts more because
  it also credits the trace-covered bodies.  The 80%-91% stretch came from the
  device-tape capture work and from bodies ported through the repo's own
  adapter translator (tools/oracle/translate_adapters.py) into
  src/fight/vf3_c80_adapter.c ... vf3_c105_adapter.c.  Recipe, checks and the
  bodies left out: docs/re/coverage_80_generated_adapters.md,
  docs/re/coverage_92_translator_gaps.md, docs/re/coverage_93_c97_batch.md,
  docs/re/coverage_93_low_region.md, docs/re/coverage_93_alias_claim.md,
  docs/re/coverage_93_tail_transfer.md, docs/re/coverage_93_stc_vbr.md and
  docs/re/oracle_device_reads.md.
  Next bar: 94% = 408,576 B (2,832 B more).
- **The REIOS drive is not RAM: its state belongs in the corpus.**
  `GDROM_REQ_CMD` answers with the drive's *request counter* and only accepts
  the command while the drive is idle, so `r0` after the call is external
  state, not something the guest can compute.  The corpus now carries it:
  `tools/oracle/capsules.py` writes `f_<entry>.gd.bin` (16 words per case),
  `tests/matrix_family_replay.c` seeds `vf3_matrix_state.gd_state`, and
  `src/fight/vf3_aica_stub_adapter.c` runs the service model
  (`src/sys/gdrom_hle.c`) forward from that state.  The observer needs the
  state *at the entry* of a specimen, so a synthetic redirect has to record it
  too (docs/re/patches/oracle_drive_state.patch,
  tools/oracle/build_extended_observer_v3.py, `tools/golden_batch.py --gd-log`).
  See docs/re/gd_drive_state.md.
- **A tail transfer is not a failed call.**  A module that reaches a
  register-indirect jump whose target it was not generated with stops at that
  target with the jump already taken; the reference continues there as the tail
  transfer it is.  `vf3_family_tail_retry` (already used by the native tick)
  makes the dispatcher resume at the lost PC; the replay harness now sets it.
  `VF3_TAIL_RETRY=0` restores the strict single-module behaviour.  The gate
  compares the whole register file, XF, FPUL, GBR, the exit PC and the RAM
  windows, so the retry cannot make a wrong port pass.  See
  docs/re/coverage_93_tail_transfer.md.
- **A `jmp @rN` whose register was just loaded from the literal pool has a
  static destination.**  `mov.l @(disp,PC),Rn` + `jmp @Rn` reads a 32-bit
  constant out of the original image, so the target is a property of the code
  (357 such sites).  The translator resolves it, adds the body to the CFG and
  gives the emitted switch one more `case`; the switch keeps its `default`
  arm, so a runtime target that differs from the literal still reaches the
  router.
- **Do not regenerate `src/fight/vf3_c95_adapter.c` from the current
  translator.**  The regeneration with the alias handoff computes the code
  base from the *masked* entry (`vf3_matrix_family_core` masks it to 29
  bits), so a direct `0x8c` entry falls back to the `0x0c` mirror and the
  stored pointers differ (`mem win5 @+0x8bb: got 0c want 8c`).  The alias
  model has to keep the *unmasked* entry's alias first.
- **The address mirror travels with the call.**  The SH-4 mirrors 0x0c000000
  at 0x8c000000 and at 0xac000000, and the loader reaches the same code
  through all three, so a PC-relative `mova` computes a different address
  under each.  The alias is a property of the *run*, not of the instruction:
  the translator keeps a `code_base` that follows the execution (the entry
  sets it, an indirect jump sets it from the branch target, `mova` emits
  `code_base|...`).  The router masks the entry PC to 29 bits, so the mirror
  cannot travel in the entry PC: the caller sets `vf3_matrix_call_alias` /
  `vf3_matrix_call_alias_pc` before it hands control over, the callee reads
  them once on entry, and the harness resets them per case.  See
  docs/re/coverage_93_alias_claim.md.
- **A module serves the PCs no other module *claims*, not the ones no other
  module owns.**  Two modules can own the same PC while neither claims it -
  then nobody serves it and the router has nowhere to send the call
  (`unsupported helper/state at 8c063446 PC 0c0635ec`).  The translator now
  reads the other modules' claim arrays (their owned set for the legacy
  modules, which have none) and treats that as the already-implemented set.
- **A corpus without its RAM shadow is not evidence.**  Three entries had a
  recorded corpus whose `.in.bin`/`.out.bin` shadows were gone, so they were
  excluded (814 B).  The shadows are exactly regenerable from the capsule
  (tools/regen_ram_shadows.py) or from a re-capture with the 1024-page
  observer (tools/oracle/recapture_v2.py).  The re-capture has to raise
  `--max-samples` (the manifest does not record it; the recorded campaigns
  used 256) and the frame count (the bigger page budget makes every probe
  restore costlier, so the campaign needs more frames to reach the same
  seeds).

- **The oracle arms every watched entry it meets, so a callee needs only to be
  watched once.**  A watched entry's `f_<entry>.ops.json` holds the whole call
  tree it executed; the callee ran, but it earned no corpus because it was not
  in the watch list.  tools/oracle/reobserve.py re-runs a recorded batch (its
  manifest carries the state, play script, frame count, RAM patch, probe
  fixture and the exact emulator build) with the callees added to the watch
  file, and `--probe-children` keeps the nested entries armed while a probe
  is active.  The oracle matches a watched entry against the *raw* guest PC,
  so a callee reached through the 0xac mirror must be watched as `pc 0xac...`.
  This turned 90 corpus-less entries into recorded corpora.
- **A probe must not jump into RAM the loader never filled.**  The game runs
  1ST_READ from the RAM copy at 0x0C010000, but the region 0x0C010000-0x0C030000
  stays zero in every captured state, so a synthetic probe aimed there ran
  `MOV R0,@R0` straight through until the erased 0xffff padding raised an
  illegal instruction (flags=1).  tools/oracle/ram_image_seed.py writes the
  image's own bytes into that region as a VF3_RAM_PATCH fixture
  (isolated_probes.py --ram-patch); the low region had 77 unported functions
  because of it.
- **A register the static inference cannot classify is a counter, not a
  pointer.**  Seeding it with an arena pointer never terminates (`dt r5`
  counts down from 0x0c4xxxxx), so isolated_probes.py --counter-variants adds
  seed variants with small values alongside the pointer-style ones.
- **The replay step budget has to cover the reference's own step count.**
  The port spends one step per emulated instruction, exactly like the oracle,
  so a body with a counted loop (0x8c04ba30 copies 50,464 bytes, ~350k steps)
  cannot finish inside a 100k ceiling.  tests/matrix_family_replay.c now
  allows 4,000,000 steps per case.
- **A device store must narrow its value to the access size.**  The SH-4
  store path takes the value already narrowed (WriteMemU8 -> w8(u8)) and the
  oracle journals the narrowed value, so `vf3_matrix_write` masks the value
  before the device hook sees it.  Without it a byte store of a sign-extended
  register reaches the hook as 0xffffffb0 where the reference had 0x000000b0.
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
  docs/re/reios_exec_server.md).  That model now exists and the corpus format
  carries the drive state (docs/re/gd_drive_state.md), but four of the five
  GD-family corpora predate the observer's device-read policy: their capsules
  are gone and the current observer no longer reproduces their specimens (the
  original capsule manifest records started=2/completed=2 and started=8/
  completed=8 where a re-capture gives 1 and 1), so their drive state cannot
  be recovered; the corner-block descriptor loop at
  0x0c0510b6 (its trip count comes from driver state the corpora do not
  carry); STC VBR in the helper 0x0c060eba (now ported, see
  docs/re/coverage_93_stc_vbr.md); an uncaptured write (0x8c0a2a84);
  one byte of a RAM window (0x8c04340c); and the literal-pool family
  (0x8c058780/84/88/8c, whose bodies run into a literal pool and execute data
  in the reference).  The "a device write the reference did not make"
  (0x8c09aa14) cause is **retired**: it was the un-narrowed store value.
- **The 500,000-instruction probe budget is unlocked** (4b09d98).  The v1
  proof pinned a tool-test log that lived in the gitignored extract/ tree, so
  tools/oracle/build_extended_observer_v2.py now builds a *v2* recorder from
  the patched oracle source (device reads + 1024 pages) and
  tools/oracle/extended_observer_controls_audit_v2.py re-validates it against
  the 8 original control windows; tools/oracle/extended_observer_controls_v2.json
  is the new seal.  The v2 sweep of the corpus-less pool captured 8 of the 249
  entries (1,162 B) - the other 241 spin in the REIOS BIOS polling a device
  register, which is a service-model problem, not a budget one.
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
- **The artifacts are gone from this checkout** (2026-10-24): `extract/`
  (the ROM images, the Ghidra project, the capture corpora, the analysis
  CSVs), `tools/emu` (the patched oracle), `refs/dream-recomp`, the ROM
  tracks and the Ghidra/SDK installs are all absent, and `rom/vf3.gdi` is
  only the 175-byte descriptor. The coverage bar (94%) and the oracle
  replay gate wait for them; the tracked tree still builds and the
  self-contained suites still pass. What is left is the *readable* track:
  the generated adapters under `src/fight/*adapter*.c` are a faithful
  disassembly, so a readable port can be written against them and proved
  offline by differential execution against the translation it replaces
  (`tests/state_helpers_replay.c`, `tests/record_state_walk_replay.c`).
  Reading tools: `tools/adapter_dump.py` (a generated function as guest
  disassembly), `tools/adapter_body.py` (the raw source of a PC range,
  module by module - several modules carry the same PC and the router
  serves the first one that owns it), `tools/readable_gap.py` (the
  call-target entries no readable port covers). Full list of what is
  missing and how to rebuild it: docs/re/artifact_gap.md.
- **A generated dump walks the fall-through, so a branch-only arm is
  invisible.**  `tools/adapter_dump.py` follows the *last* `goto` of a
  block, so the arm a conditional branch skips over never appears in the
  listing - and a port written from that listing misses it.  The range
  flag (0x8C0CAA9C) has two arms: the comparisons branch *away* when a
  value is out of range, so the arm that is left is the "everything is
  inside" one, and it clears the flag with a mask rather than by writing
  a zero.  The first version of the port missed it and the differential
  caught it.  Read the *whole* function out of the module source
  (`tools/adapter_body.py`) before porting it, not the dump alone.
- Task-VM field schema: docs/re/task_vm.md (M19).
- Fight-frame composite: src/fight/frame.c + tests/frame_replay.c (M20).
- Record state walk (0x8C03550C) ported readable, with its state getter
  (0x8C035A20): src/fight/record_state_walk.c and
  src/fight/record_state_field.c, proved against the retained generated
  translation by tests/record_state_walk_replay.c (16 differential cases).
  The oracle replay could not be re-run (the corpora are gone, see
  docs/re/artifact_gap.md), so the chain readable == generated == oracle is
  carried by the earlier promotion of the generated translation.
  docs/re/record_state_walk.md.
- Matrix-op dispatcher (0x8C035CE8) ported readable, with its sibling
  (0x8C035C60): src/fight/matrix_op_dispatch.c, proved against the retained
  generated translation by tests/matrix_op_dispatch_replay.c (10 differential
  cases).  The node behind the global at 0x8C035D60 names the operation in
  its word at +0x50 (or +0x38); all eighteen operations it can name are
  already ported readably.  The third member of the family (0x8C035CBA,
  slot +0x44) is already ported as `vtable_trampoline`, and that port does
  not match the retained translation - it does not restore r14 and it reads
  the global 0x8C0EA314 where the translation reads the literal pool slot
  (which holds that address in the image).  It is marked `unexercised` in
  the ledger, so no differential test covers it; worth checking against the
  oracle when the corpora are back.  The readable port hands every pointer to
  the chain, where the translation switches on the eighteen operations it
  knows and stops for anything else - the difference needs the test-only
  `missing` hook to show.  docs/re/matrix_op_dispatch.md.
- Record predicate (0x8C03772A) ported readable: src/fight/record_match.c,
  proved against the retained generated translation by
  tests/record_match_replay.c (8 differential cases).  It asks two helpers
  (the function pointers in the literal pool at 0x8C03779C and 0x8C0377A0)
  and then checks a record and a twelve-byte header: the record's first
  word 14, the header's words 1, the global halfword at 0x8C03778E, 1, and
  its last two bytes 0.  The header sits below the two saved registers, so
  it is twenty bytes under the entry's sp - the port has to keep that.
  docs/re/record_match.md.
- Record lookup (0x8C037788) ported readable: src/fight/record_lookup.c, proved
  against the retained generated translation by tests/record_lookup_replay.c (3
  differential cases).  It picks the record (the index 1 and the table behind the
  global at 0x8C0377A4), asks the record predicate (0x8C03772A) and, when the
  record fits, the table's getter (the function pointer in the literal pool at
  0x8C037798).  The answer is 0 with the record in r4, -1 when the predicate says
  no, or the getter's negative answer.  The frame (the index and the table) and
  the getter's three argument words have to stay where the guest puts them, or
  the RAM the test compares differs.  docs/re/record_lookup.md.
- Table getters (0x8C044068) and its two siblings (0x8C04409C, 0x8C0440C8)
  ported readable: src/fight/table_getter.c, proved against the retained
  generated translation by tests/table_getter_replay.c (8 differential cases).
  A getter hands the caller's frame words to the table's handler (the
  pointer in the literal pool next to it), reads the table's slot (the pool
  at 0x8C044140 and the halfword offset at 0x8C04413A) and, when the slot is
  *taken*, asks the fallback 0x8C043D04 - whose answer is dropped.  The
  handler's answer waits in the frame while the slot is checked, so the
  fallback cannot change it.  The three differ only in their handler and in
  how many frame words they forward (3, 1 and 0).
  **The two younger ones write their continuations with a code base that is
  NOT the `vf3_matrix_call_alias` model**: `vf3_c91_adapter` derives it from
  the caller's return address (`(pr&0xff000000)==0x0c000000 ? 0x0c : 0x8c`),
  so the continuation carries the mirror the run came through.  A readable
  port has to use the rule of the module it replaces, and it cannot use the
  shared `vf3_guest_call` helper for it - that one forces the `0x0c` form.
  tools/adapter_owner.py (new) resolves which module the router really serves
  for a PC - several modules carry the same guest code and model it
  differently.  Its `--body` reports the *file* the copy lives in: the
  router's name and the file's name do not line up (the router calls
  `vf3_fifth_leaf_adapter_contains` while the code lives in
  `fifth_leaf_adapters_0.c` and `fifth_leaf_adapters_1.c`).  docs/re/table_getter.md.
- Node query (0x8C053CA4) ported readable: src/fight/node_query.c, proved
  against the retained generated translation by tests/node_query_replay.c (5
  differential cases).  It looks the node up as table[index*4] and asks two
  handlers about it - the pointers in the literal pool at 0x8C053D48 and
  0x8C053D4C - and answers 1 when the status byte they point at is not zero
  and the flags word they point at carries the bit 1.  **A stub callee that
  only answers hides the continuation**: the epilogue restores pr from the
  stack and the continuation is never pushed, so a port that ignored the
  code base still passed until the stub was made to *record* the return
  address it was called with.  The test does that, and the recorded address
  is what makes the mirror visible.  docs/re/node_query.md.
- Node handler (0x8C0AB870) ported readable: src/fight/node_handler.c, proved
  against the retained generated translation by tests/node_handler_replay.c (3
  differential cases).  It takes an object (r4) and a node (r6) and calls
  the handler the node names - the table's entry at the node's second word,
  the table behind the pool at 0x8C0AB9A0 - with a five-word frame: the
  handler, the object's first word, the node's two words and the float that
  belongs to the object (the pool's offset at 0x8C0AB990).  r5 points at the
  frame's second word.  The float travels through FR3, so the FP registers
  are part of the contract and the port calls the same
  vf3_matrix_load/vf3_matrix_store helpers the translation uses.
  docs/re/node_handler.md.
- Halfword frame (0x8C09D4B0) ported readable: src/fight/halfword_frame.c,
  proved against the retained generated translation by
  tests/halfword_frame_replay.c (3 differential cases).  It puts the argument
  (r5) and the object's three halfwords in a frame (at S-20, S-16, S-12, S-8
  under the entry's sp) and calls three things with values derived from it:
  the first handler (the pool at 0x8C09D580) gets the object's first halfword,
  the second (0x8C09D584) gets the argument plus the object's second halfword,
  and the third (0x8C09D588) gets the object's third halfword as a **tail
  transfer** - the guest pops pr and jumps, so it runs in the caller's frame.
  Two details the port has to keep: the `jsr` **delay slot runs before the
  callee** (the translator merges it into the call block, so the `extu.w` mask
  and the add are visible to the callee), and `mov.w` sign-extends where
  `extu.w` does not.  The third call is a `jmp @r3`, so it needs
  `vf3_guest_tail_call` - the shared `vf3_guest_call` would force the `0x0c`
  form of pr and lose the caller's own return address.  **A stub callee that
  only answers hides the continuation**: it returns to pr, so a port with the
  wrong continuation still comes back "right"; the test's stubs now record the
  return address they were called with, which is what pins it.
  docs/re/halfword_frame.md.
- Status flags (0x8C0961F4) ported readable: src/fight/status_flags.c, proved
  against the retained generated translation by
  tests/status_flags_replay.c (5 differential cases).  It turns a record into a
  bitmask: it reads eight fields of the record (at +8, +12, +0, +4, +24, +20,
  +28 and +32 - the gaps and the order are the guest's) and puts one bit in
  the answer for every field that has a bit in common with the mask (r4).  The
  last bit comes out of the literal pool at 0x8C09630A.  Three details the
  port has to keep: the **delay slot runs before the branch**, so the next
  field is loaded before the current test is resolved; `tst` sets the **T
  bit**, which the caller can read, so the port sets it after every test; and
  the first bit is *assigned* into an answer the guest zeroes first, while the
  rest are or-ed in.  The pool slot is read only when the last bit goes in.
  docs/re/status_flags.md.
- Table grower (0x8C044C7C) ported readable: src/fight/table_grow.c, proved
  against the retained generated translation by tests/table_grow_replay.c (5
  differential cases).  It adds N entries (r4) to two arrays behind one
  header: the first array's pointer moves on by its stride and the new
  entries get the fill value, the second array's count becomes N and its
  pointer moves on by N words.  The header sits behind the global at
  0x8C044D44 and the slots are offsets in the literal pool (0x8C044D16,
  0x8C044D18, 0x8C044D1A).  Two details the port has to keep: **the two
  indirections are not the same** - the global holds the header's address and
  the word at that address holds the base - so reading the base out of the
  base is the same value but a different access, which the out-of-window
  counter sees; and the loop's guard is **signed**, so a negative count skips
  the loop but still moves the second array's pointer backwards.
  docs/re/table_grow.md.
- Out-of-range flag (0x8C0CAA9C) ported readable: src/fight/range_flag.c,
  proved against the retained generated translation by
  tests/range_flag_replay.c (7 differential cases).  It sets the 0x10 bit of a
  flag byte when one of four floats is outside the range the two bounds
  describe, and clears it again when they are all inside.  The byte's own
  0x40 bit gates everything - when it is clear the function does not even
  write the byte back.  Two details the port has to keep: the end of the
  comparison chain has **two arms and they are not symmetric** - the arm that
  is left is the "everything is inside" one, and it clears the flag with a
  *mask* (`& 0xFFFFFFEF`, which takes the neighbouring bit with it) rather
  than by writing a zero; and the comparisons **short-circuit**, so the T bit
  the guest leaves behind is the one of the last comparison it actually
  reached.  The float loads go through the shared helpers, so the test has to
  set the FPSCR the way the reference sees it.  docs/re/range_flag.md.
- Frame counters (0x8C08B338) ported readable: src/fight/counter_advance.c,
  proved against the retained generated translation by
  tests/counter_advance_replay.c (8 differential cases).  It advances three
  counters in a record (seven bits at +12, two bits at +14, four bits at +16)
  and one in a block (at +0x54, wrapping at 127), but only when the value a
  global points at has **no** bit in common with the mask.  Three details the
  port has to keep: the gate is the *absence* of a common bit (the `tst` sets T
  when the two share nothing and the `bf` skips the body when T is clear); the
  carried bit is the low bit of the **incremented** wide counter (`r6 = 1 &
  (wide + 1)`), so the wide counter's own wrap carries *nothing* and the
  narrow counters move on every other step; and the block's wrap test is a
  **signed** comparison on the sign-extended halfword, so a counter of 32767
  that takes the carry becomes -32768 and does not wrap.  The block is reached
  through **two** indirections (the global, then a header whose first word is
  the block).  docs/re/counter_advance.md.
- Word decoder (0x8C04538A) ported readable: src/fight/byte_decode.c, proved
  against the retained generated translation by
  tests/byte_decode_replay.c (10 differential cases).  It pops a word off the
  caller's stack, pushes it on its own stack, copies its four bytes into the
  object at +8..+11 - in the natural order or turned around, as a table's entry
  says - and writes the answer at the object's +20: -1 when the object's first
  byte equals the mark, the caller's *next* word when the byte is at or above
  the limit, and zero otherwise.  Three details the port has to keep: the
  bytes are read back **out of the stack** (the push is part of the contract);
  the table's base is a **signed halfword added to a 32-bit word**, so a port
  that treats it as a stride reads a different address and shows up as an
  out-of-window read rather than a wrong value; and the answer's three arms
  each end in a branch whose **delay slot is the store**.  The byte-order
  test's T bit is *unobservable* - the mark's `cmp/eq` overwrites it - so that
  one is free.  docs/re/byte_decode.md.
- Node rotation (0x8C09F83C) ported readable: src/fight/node_rotate.c, proved
  against the retained generated translation by
  tests/node_rotate_replay.c (6 differential cases).  It turns seven
  twelve-byte records around - each holding two floats eight bytes apart - by
  the angle the caller leaves in FR4 and FR5, and then moves the root's three
  coordinates by FR6.  Two details the port has to keep: the second
  coordinate is a **fused** multiply-add (`vf3_fpu_mac` rounds once, a
  multiply and an add round twice, so the port cannot write `a * b + c` in C);
  and the loop's counter is decremented **at the top** while the branch that
  ends the loop is at the bottom, so the T bit the caller sees is the last
  iteration's.  docs/re/node_rotate.md.
- Motion VM step (0x8C0CB8AC) ported readable: src/fight/scale_step.c, proved
  against the retained generated translation by
  tests/scale_step_replay.c (7 differential cases).  When the mode byte's low
  four bits say 1, it reduces the VM's step count by sixty, makes it positive,
  parks it in **FPUL** and writes `constant_two * count + constant_one` into
  the caller's structure and into the structure the VM names.  Three details
  the port has to keep: the mode byte is **masked to four bits** before it is
  compared (so 17 is a step and 9 is not); the count is made positive and *that*
  value goes into FPUL; and the scale is a **fused** multiply-add.
  docs/re/scale_step.md.
- Record repack (0x8C043A7C) ported readable: src/fight/record_copy.c, proved
  against the retained generated translation by tests/record_copy_replay.c
  (4 differential cases).  It copies twenty-four records out of a table and
  into a destination array, and the two records do not have the same shape:
  the source's bytes 0..3 and 8..11 and its words 16 and 20 become the
  destination's bytes 0..3 and 4..7 and its words 8 and 12.  Four details the
  port has to keep: the table is read through **two indirections** (the pool
  gives the table, the table's cell gives the source's base) and the first
  record is **+0x28** into that base; the source's records are 0x2C apart and
  the destination's 0x18; the loop's exit test is the **T bit** of a compare
  the body has already bumped, so the T bit the caller sees is the last
  iteration's; and the bytes are **sign-extended** into the register they
  travel through.  docs/re/record_copy.md.
- Float blend (0x8C03E810) ported readable: src/fight/float_blend.c, proved
  against the retained generated translation by tests/float_blend_replay.c
  (4 differential cases).  It copies four floats out of an array and into a
  structure of four slots, and then writes a weighted sum over three of the
  slots back into the first one:
  `slot0 = weight_a * slot2 + weight_b * slot1 + weight_c * slot3`.  The first
  source float is therefore dropped.  Three details the port has to keep: the
  two slot addresses the blend reads back are **pushed on the stack** and
  popped again by the `rts`, so the frame is part of the contract; the blend
  is a multiply and two **fused** multiply-adds, so it cannot be written as an
  expression of C floats; and the array's step is **eight bytes when the
  FPSCR is double** and four otherwise.  docs/re/float_blend.md.
- Table unpack (0x8C06D792) ported readable: src/fight/float_table.c, proved
  against the retained generated translation by tests/float_table_replay.c
  (6 differential cases).  It looks a table entry up by the low **four** bits
  of an index byte - the entries are **sixty-four bytes** apart - and unpacks
  it into two structures: the entry's two halfwords go into the first
  structure at its +32 and +34, and they are **swapped** on the way, and the
  entry's three floats go into the second structure at the pool's offset, at
  eight bytes below it and at four below that.  Two details the port has to
  keep: the second structure is reached through **two** indirections (the pool
  gives a cell, the cell gives the structure), and the offset is a **signed**
  halfword, so it can point below the structure.  docs/re/float_table.md.
- Mode index (0x8C038990) ported readable: src/fight/mode_index.c, proved
  against the retained generated translation by tests/mode_index_replay.c
  (9 differential cases).  It turns a mode flag into an index into a table:
  four flags are constants (8, 16, 32 and 64) and four live in the literal
  pool, and a flag that is none of them is **left alone**.  Two details the
  port has to keep: the guest compares the four constants against a **copy** of
  the flag it made in `r0`, while the four pool flags are compared against the
  flag itself; and the **T bit** the caller sees is the one of the comparison
  that answered, so it is set on a hit and cleared when no flag matched.
  docs/re/mode_index.md.
- Structure init (0x8C036A58) ported readable: src/fight/range_init.c, proved
  against the retained generated translation by tests/range_init_replay.c
  (4 differential cases).  It sets up a forty-four byte structure: mostly
  zeros, but four words in the middle carry a range whose shape depends on a
  **word behind a pointer** the pool gives - `0, -1, 0, 0` when that word is
  zero and `-1, 0, -1, -1` when it is not.  Three details the port has to
  keep: the branch's **delay slot** sets the marker on both paths; the two
  paths do **not** share their writes (one of them stores the structure's
  `+20` in the delay slot of the branch that leaves it); and the word that
  lands in the structure's `+36` is stored in the **`rts`'s delay slot**.
  docs/re/range_init.md.
- Entry copy (0x8C06D7D6) ported readable: src/fight/entry_copy.c, proved
  against the retained generated translation by tests/entry_copy_replay.c
  (6 differential cases).  It looks a table entry up and copies some of its
  fields into a structure **twice**, once at each of the two signed halfword
  offsets the pool holds.  Four details the port has to keep: the index is the
  **whole** byte (the table has 256 entries of sixty-four bytes - the sibling
  function at 0x8C06D792 masks the same byte to four bits, so the two read the
  same table at two different depths); the two groups **can overlap** and the
  second one is written later, so it wins; the entry's three bytes are
  **sign-extended** into the registers they travel through; and the last float
  is stored in the **`rts`'s delay slot**.  docs/re/entry_copy.md.
- Clamp pair (0x8C08DCB0) ported readable: src/fight/clamp_pair.c, proved against
  the retained generated translation by tests/clamp_pair_replay.c (14 differential
  cases).  It takes two numbers (r4 and r5) and writes four limited values: the
  first number clamped into one range (twice, to r6 and to the caller's frame)
  and the second number clamped into two *different* ranges.  The bounds are
  signed halfwords in the pool; two of the four destinations are addresses the
  caller leaves in its own frame, eight bytes above the callee's stack pointer.
  Three details the port has to keep: the **low** bound is tested before the
  high one, so a value below the low bound is never compared against the high
  one (a range whose bounds are the wrong way round tells the two apart); the T
  bit the caller sees is the one of the **last** comparison, which is the
  fourth limit's; and the limited values travel in r13, r14, r1 and r4, which
  the guest puts back from the stack - the last pop is the **`rts`'s delay
  slot**.  The third limit is dead: it repeats the first and the fourth
  overwrites the T bit it leaves.  docs/re/clamp_pair.md.
- **The gap tool only counts the generated adapters.**  A call target that one
  of the *hand-written* modules already serves still shows up as unported:
  `0x8C040F1E` (the queue push) is implemented by hand in
  `src/fight/command_encoders.c` (`enqueue`, served as `vf3_audio_queue_c`),
  and the generated copies of it in the phase2, seventh-c and fight modules
  are shadowed.  The hand-written port even *bakes in* the literal pool's
  values (`0x0C19E218`, `0xA0800500`, `0xA0800400`) where the generated copy
  reads them from the pool at `0x0C040F68`.  Check a candidate with
  `tools/handwritten_entries.py <entry>` before porting it.
- **A scan for "not ported yet" has to know the readable registry's shape.**  The
  registry in `src/fight/readable.c` writes its rows as `{ 0x0c..., "name", fn,
  mask }`, so a scan that only looks for `case 0x...` and `entry == 0x...`
  misses every readable port.  The four compiler-runtime division helpers
  (0x8C042C20, 0x8C042CD4, 0x8C042D7C, 0x8C042E44) are ported in
  `src/fight/math_readable.c` and still look unported that way.  The same goes
  for the *call-free* filter: the generated modules follow a branch's **not
  taken** arm when they walk a body, so a walk that follows the last `goto` of
  a block misses the body of every conditional and the calls inside it.
  `tools/adapter_owner.py <entry> --body` shows the whole body, and
  `tools/handwritten_entries.py <entry>` answers the other half.
- **A differential passes even when the fixture is wrong.**  The first version
  of the counter test pointed the block's global straight at the block instead
  of at a header whose first word is the block; the reference then read the
  counter from an address outside every window, and the test still passed -
  both sides read the same uncaptured address and the out-of-window counter
  matched.  The counter was simply never exercised.  The word decoder's test
  walked into the same trap (the table's base laid out as a stride instead of
  a signed halfword), so **both new tests now fail on a non-zero
  out-of-window counter**, and `VF3_REPLAY_OOB=1` names the uncaptured read.
  A fixture that leaves a path reading outside the windows passes silently;
  the way to see it is to read the *translated* body's address chain and lay
  the fixture out for it.  **A read that falls inside a window but on the
  wrong part of it is not caught by any counter.**  The record repack's first
  fixture laid the records one stride too low, so both sides read the zero gap
  between the records and agreed on nothing while the out-of-window counter
  stayed at zero - the address was still inside a captured window.  The guard
  that does catch it is to check the result **against the fixture itself**,
  without consulting the generated translation: the destination's bytes have
  to be the source's bytes where the guest puts them.  A mutation the test
  cannot see is a path the test never reaches.
- **The registry has two entry addresses that are registered twice.**
  `vf3_readable_find` returns the first match, so the second row of each pair
  can never be served: `0x0C042D7C` is registered as both `div_signed` and
  `mod_s32` (two ports of the same signed division), and `0x0C068FE4` as both
  `quad_node` and `terrain_quad_test`.  The dispatcher behaviour is right -
  the first row of each pair is the one the translation matches - but the
  second port of each pair is dead code, and `tools/recomp/readable_ledger.py`
  collapses the two rows into one when it derives the ledger.
- **The `out_regs` mask names registers with `FR(n)`, not `B(21+n)`.**  The
  ledger tool reads `FR(4)` as "FR4" but `B(25)` as "fr4" as well (it maps
  every `B(n)` with n >= 21 through the FR numbering), so a mask written with
  the raw bit numbers is mislabelled in `docs/readable_status.csv`.  The
  range-flag row had it wrong in both directions (it named FR0..FR4 while the
  port writes FR4..FR9); it is fixed now.  Write the FP registers as `FR(n)`.
- MT record field semantics (motion VM)
- BGM song-kit voice reset boundaries
- Main loop body (struct-C model: static jsr ceiling ~3%)

## Conventions
- Byte offsets hex, addresses include 0x8C010000 base
- Verification-first: every decode ships with a visual/CRC check artifact
- Git: commit per milestone; do not commit rom/, extract/, build/, *.zip
