# RE analysis state (auto + manual notes)

## M13..M22 (2026-09-22/23, autonomous) — vertical sweep closed
- M13 scripted front-to-fight capture: vf3script gains frame-clock events
  (`KEYF/SAVEF/AICAF/MEMF/SHOTF/EXITF`); the suite confirmed the fight SDK
  enters at attract f=24200..25400; menu->load 301 KB full-RAM swap; the
  visible BGM kit region = AICA 0x086E54..0x1CC29D. `VF3_WATCH` selects PCs,
  `VF3_INTERPRETER` toggles dynarec vs interp (trace-fidelity); all state
  files persisted under tools/emu/flycast-build/data/.
- M15 braf_tables.py v2 (resolve_reg width/window lift + fnlit bounds cross),
  8 word tables resolved; remaining BRAF sites are data-islands or struct-
  task indirection (trace-backed); CSV at extract/analysis/braf_tables.csv.
- M14 mem-watch: "mem" lines in VF3_WATCH; interpreter r/w hooks
  (ReadMem*/WriteMem*); record layout (pc<<16)|0xFA20, (size<<48)|(isW<<47),
  addr, value; used in m14 MT census (extract/analysis/mt_field_reads.csv)
  and M19 probe logs.
- M16 task_run_c.c port: 8 jsr call ladder (slots 0x0C0E/0x76AC/76B8/76C4),
  r13/r14/r12 modeled.
- M17 AICA census (0x0..0x86E53 driver+voices / 0x86E54+ kit region, ring
  stream at 0xA0B4..0xCF5D).
- M18 MT motion oracle: tests/mt_oracle.c (vf3test) maps every traced
  read (mt_field_reads.csv, 81 rows) into the port's window registry:
  primary record 5093 (byte streams +0x736/+0x75B, quad @+0x7A4),
  linked 5096 (tuple groups 0x194/...), chains 1304/1307/1313, mirror
  record 572 for the second fighter. docs/formats/MT.md updated.
- M19 static task VM schema via tools/task_vm_map.py: 1,196 r14 sites ->
  26 offsets; typed struct in src/fight/task_vm.h + vf3_task_field_name()
  in task_vm.c. docs/re/task_vm.md holds the full rd/wr histogram.
- M20 src/fight/frame.c: fight frame pipeline (predicate, 6-slot task
  ladder, ring counter tick, sd slot cycle) replays 60 frames host-side.
  tests/frame_replay.c (vf3frame.exe) PASS.
- M21 GDFS name layer: tools/bin_names.py -> extract/analysis/bin_names.csv
  (222 rows) -> src/sys/gdfs.c + src/sys/gdfs_table.h. `vf3tool binname`
  locates names/tags (e.g. MTJACLAU.BIN -> slot 14).
- M22 cross-build name trf: 30 retail-reached names propagated to
  VF3TBE3 via fidhash (`Vf3ApplyNames` run; E3 fresh CSV in
  extract/analysis/funcs_VF3TBE3.unsc.bin.csv; named now 222).

## M10..M11 interim notes preserved in docs/re/probe_mode.md + prior commits.

## Ghidra project: extract/ghidra_proj/VF3 (not version controlled; reconstructible)
- GUI: run `ghidra.bat` at repo root.
- 1ST_READ program was re-imported clean (stock auto-analysis) on 2026-09-17;
  names re-applied from matches_1ST_READ.csv (58) + fuzzy_apply_1ST_READ.csv (3).

## M3 outcomes (per-phase)
- A: tools/fuzzmatch.py — shingle+difflib matching; 964 cross-build pairs
  (606 exact + 358 fuzzy), 13 corpus fuzzy names applied; docs/matches_fuzzy.md.
- B: fnptr_tables.py (146 switch tables), table_readers.py, Vf3Xrefs2.java
  (31K xref dump), callgraph v2 (constant-fold + dispatch-site report).
- C: architecture.md — struct-dispatch model mapped; dispatchers, loader-chain
  fns named (task_run_A/B/C, load_mt_*); boot region breaks documented.
- D: dtpk_extract.py + adpcm_decode.py — container & AICA codec solved,
  69 packages split, ~40k seconds of media verified (incl. all VO packs).

Programs (all SuperH4 LE @ 0x8C010000, BinaryLoader raw images):
- `1ST_READ.unsc.bin` — retail MK-51001 V1.002
- `VF3TBE3.unsc.bin` — E3 build (second build for diffing)
- `RELOAD.unsc.bin` — reset/init-related second-stage module

Function inventory (2026-09-19, after pointer seeding + verdict pass):
- 1ST_READ: **7,628** functions (was 2,552 pre-seed; +3,904 seeded: rounds 3877/27/0).
  Vf3ScoreSeeds verdicts: REAL 1,054 / MAYBE 1,337 / JUNK 1,513 (JUNK renamed to
  `junk_<hex>`, MAYBE commented, REAL pardoned). Verdict rules: clean terminator,
  prologue pushes, knows-calls vs identical-word runs / ascii runs / dead stubs.
  CSVs: seed_1ST_READ / seed_verdict_1ST_READ in extract/analysis.
- VF3TBE3: **8,754** functions (was 3,664; +4,011 seeded: 4009/2/0).
  Verdicts: REAL 1,105 / MAYBE 1,626 / JUNK 1,280 (applied same way).
- RELOAD: 335 functions (not seeded)

Cross-build masked-digest matching (tools/fidhash.py, FID-style):
- 502 digest pairs retail↔E3; anchors self-confirm (memset↔_memset,
  gdFsDaPlaySct, kmChangeContextFlipUV, kmiProcessVertex_12...).
- Known artifact: identical-code twins collide (kmSetEndOfVertexCallback vs
  kmSetStripOverRunCallback type setter bodies are byte-identical) — disambiguate
  via callsite context, unresolved.
- 748 digest collisions on retail side (mostly tiny thunks); union with
  fuzzmatch.py channel recommended.

## M14 (2026-09-22) — MT field capture DONE
- flycast mem-watch mode: `VF3_WATCH` lines `mem 0xADDR 0xLEN` (interpreter
  only; wraps ReadMem*/WriteMem* post- mem_Reset). Emits
  `(pc<<16)|0xFA20, (size<<48)|(isW<<47), addr, value`.
- 95-frame fight capture (vf3_7) over the resident MTJACLAU pack
  (0x8C5F0000+): 4,817 hits, 22 reader PCs. All traffic inside the pack:
  `fight_f_8c09d69a` (helper) + `fight_f_8c09d6e0` (motion-frame evaluator).
- Extract/analysis/mt_field_reads.csv = per-(pc,offset,size) census.
- Behaviour model: record 5093 = active motion; byte-cursor at +0x736
  advances the opcode stream; the u32 quad at +0x7A4.. is the per-frame
  transform; secondary record 5096 provides linked params (+0x194..0x1FC).
  Quad floats confirmed populated: e.g. 0.0067, 0.003, 0, 0.061.
- `src/fight/mt_play.c` = C port of the frame step.

## M16+M17 (2026-09-22) — ports + hw census
- src/fight/task_run_c.c: C port of the per-frame task-slot runner
  (8 mov.w/@r14 jsr site), register-traced; helper-hook parameterization
  keeps it honest (r14 = caller-provided job ctx).
- libvf3core builds green with the new file.
- AICA voice census incorporated into docs/re/sound_bgm.md from the M13
  ladder: code+voices stable ≤ 0x86E53, kit region starts 0x86E54, streaming
  ring 0xA0B4..0xCF5D. RELOAD binary carries no ASCII surface — its detailed
  layout is deferred past current sprint.

## M13 (2026-09-22) — front-to-fight capture: BGM kit boundary RESOLVED
- vf3script now has frame-clock commands (KEYF/AICAF/SAVEF/MEMF/EXITF), and
  EXIT(F) terminates the process properly (quit-request loop flag).
- Fresh-boot KEY run reached arcade-load; AICA ladder produced the grand tour:
  menu->load 301 KB full-RAM swap, load->fight 255 KB, and THE face transition
  1,222,259 B written contiguously at 0x086E54..0x1CC29D = fight BGM kit.
- 0x0..0x86E53 is immortal across all transitions (driver + voice headers).
  Steady-state streaming lives at 0x00A0B4..0x00CF5D (12 KB ring).
- vf3_7 is fight-live via probe hits (ring + sd-lookup). vf3_6 kept as
  pre-fight oracle.

## M15 (2026-09-22) — dispatcher static map, PARs: half-closed honestly
- tools/braf_tables.py v2: +resolve_reg backward-const/scale propagation,
  +widest-window literal-carried jsr/jmp, +fallback sentinel table walk
  (`kind*?` rows). Byte/word case tuning fixed the split(',') op_str bug.
- Net yield: **8 of 309 BRAF sites resolved with table+targets**
  (0x8C015C6A/8C015FAC/8C078EE4/8C09722A/8C0AB91A/8C0B6636/8C0BAE3E/8C0BE88C,
  all word tables). Carred jsr @rN (N=r14-task) sites are struct-field
  indirect — confirmed by trace (r14=0x0CBEFBE0 RAM); not resolvable
  statically without the task VM model. This is consistent with and
  STRONGER evidence of the M3 "struct-C at ~3%" jsr ceiling.
- extract/analysis/braf_tables.csv = current authority for static dispatch.
- Next lever for the remaining 301 brafs: body-by-body probe hits (M10 infra)
  to split data-islands vs real control-flow; deferred (M17+).

## M10 (2026-09-20, autonomous) — probe-mode tracing + first C ports
- flycast patch: `VF3_WATCH=<file>` gawk-style PC probes with register dump
  (r13,r14,r4..r7) injected into the PC-trace stream as marker groups
  0xFA10..0xFA11; new `AICA_DUMP`/`MEMDUMP` commands in vf3script.
- Probe results: FUN_8c0597c2 verified as frame-fixed (r13=0x28, r14=5
  stable); cand_sd_slot_lookup arg-struct pin at r14=0x0C BEFBE0.
- AICA dumps: steady-state streaming observed (BGM refill at 0x44..0xF8 +
  0xA0BC..0xCF5D windows, ~150 B per 15 s); **no song-kit reset captured** —
  needs a front-to-fight state transition capture (TODO next).
- M11 first C ports landed: src/fight/{scene_predicate, sd_slot_lookup,
  state_index}.c annotated with SH4 addresses, trace-derived register facts
  retained in comments. libvf3core builds green.
- sh4dump.py gains `c` recursive mode (works but SH4 dbase-literal layouts
  keep defeating full-CFG on the ring bodies; each function's real decode
  needs per-fn annotation from the trace).

## Fight dispatch chain CONFIRMED (2026-09-19, trace_fight1.bin)
- Fight-scene predicate: `*(*(r13+8)+3) == 0x0A` at 0x8C0B1AC0 (sub-entry of
  cand_is_scene0A). Fight pipeline first-seen order enumerated; FEEDER =
  cand_scene0A_frame_walker (FUN_8c0b24fa). M6 task_run_C hypothesis also
  falsified (6 in-fight activations only). docs/re/fight_dispatch_chain.md.
- Spawn matrix artifact: extract/analysis/fight_spawn_edges.csv.

## M8: frontier sweep outcomes (2026-09-19 autonomous pass)
- sh4dump.py + tools/.venv (capstone SH-4A): annotated literal-pool dumps of any
  function; verified vs katana for _memset body.
- cand_sd_slot_lookup (fight_f_8c068f86) solved: 4-way switch over
  id->sound-string map (0xC7..0xCA: sd_passing_far, sd_passing_far_off,
  sd_Ak_01, sd_Ak_02). Runtime string copies in RAM 0x8C0D533C+; ROM source
  cluster 0x8C018A00+. Full table: extract/analysis/sd_names.csv.
- FUN_8c0597c2 = hottest fn in fight trace (3.95M/160M records): 16-B
  state-index helper r14 = table[5*idx], table base 0x8C059858.
- MT residency: MTJACLAU.BIN byte-verified loaded at 0x8C5F4100 during fight
  (matches JACKY-vs-LAU scene). Record classes: u16-hdr + cmd streams vs pure
  float tracks (1348B); field decode NEXT needs access-trace against the
  resident buffer.
- BGM: 26 BGM_<stage>.BIN names inventoried (docs/re/sound_bgm.md); sound.c
  driver strings (drv_set_dreset_ns etc.) have NO literal refs anywhere —
  mova/base+offset addressing; reset boundaries require a new trace class
  (G2/AICA bus records) — recipe in doc.
- "Main loop body": fight-only traces are post-boot; boot trace shows a dense
  init burst at record ~96M (FUN_8c020000 family entry) and per-frame top
  FUN_8c034984/FUN_8c03486c/f_8c035ca2 cadence; junk_8c035a20 family are
  stale mid-body seed fns.

## Dispatcher falsification pass (2026-09-19, post-SYSROF naming)
- Switch tables split from fight code entirely: 0/146 tables route into fight fns
  → fight dispatch is struct-task indirect-call, confirming architecture.md model.
- Candidates rulled: f_8c07d368 (unmapped), f_8c063f58 (offset-table iterator),
  f_8c0516a8 (5-case non-fight init dispatcher via table 0x8C051740).
- New leads: braf hosts fight_f_8c068f86 (top-3 hot) and fight_f_8c0c7e0e.
- Details: docs/re/dispatcher_falsify.md.

## M4: Katana SYSROF pipeline SOLVED ENOUGH (2026-09-19)
- `lbr.exe` (SHC librarian, native win32) driven interactively:
  `LIBRARY <lib>` / `LIST` / `OUTPUT <file>` / `EXTRACT <module>` / `EXIT`.
  One OUTPUT+EXTRACT per session (second OUTPUT = 204 CONFLICTING). Won't
  overwrite existing files. LIST wraps long module names — parser accumulates
  identifier fragments after the "Number of symbols" header.
- `tools/sysrof.py`: `list`/`extract`/`match`/`names` subcommands.
  Extracted corpuses under extract/analysis/sysrof/: sh4nlfzz 273, shinobi 253,
  ninja 583, kamui2 Flat_zero 330 + Mmu_zero 330.
- match = byte-exact span search of module code windows in the game image
  (windows = non-zero runs after obj 0x300 header pages; 24B probes + extend).
  relocation stops spans at literal-pool refs => spans cluster at ~32B for
  small runtime fns; memset verified: obj bytes == game body (24B window).
- Results per build: 414/1,490 total modules matched in 1ST_READ AND 414 in
  VF3TBE3 independently (0 overlapping addresses; layout fully reshuffled).
  Names applied via Vf3ApplyNames: retail 133 (92 confident), E3 131.
  CSVs: katana_matches(_e3).csv, katana_names_*.csv in extract/analysis.
- Bootstraps named API surface: memset, div/mod kernels, pow/logs, nj* matrix,
  km* context setters, gd*/sy* Shinobi modules.

Katana SDK recon for FIDB (2026-09-19):
- Local `tools/katana/katana/` = installed Katana SDK: shc/ (shc.exe 5.0),
  shinobi/, kamui/, bin/ (dwfcnv, elf2bin). ALL libraries are Hitachi SYSROF/LBR:
  shc/lib/sh4*.lib and shinobi/lib/*.lib (.obj too). Sample *.elf are stripped
  (no symtab). => build_fidb.py (ELF-only) can't consume them; needs a SYSROF
  parser (or libsplit+elfcnv, absent here).
- segakatana.com = screenshots only. sega-dreamcast-info.com has real zips
  (incl. Katana 1.0B2 Oct-06-98 = our local _katana_pkg; 0.40R4 available too,
  likely closer to VF3's Aug-98 build).
- Sega Saturn toolkit CD (archive.org segasaturn-toolkit, fetched 2026-09-19,
  tools/_sdk_src/): SBL 6.21 + SGL 3.20 in pc/SEGALIB (SYSROF SH-2) + era
  Hitachi tools in pc/SH + segahtml manuals — future SYSROF-parser test corpus.

Tooling pipeline (runner: `python tools/ghidra_run.py ..., gscripts dir tools/gscripts`):
1. `Vf3Baseline.java` — function inventory CSV to $VF3_OUT/funcs_*.csv
2. `Vf3Prologue.java` — SHC prologue sweep creating functions at stack pushes
3. `Vf3ApplyNames.java` — applies fingerprint CSV names (creates functions too)
4. `Vf3Disasm.java` — quick disasm print at env-supplied addresses
5. `Vf3SyscallMap.java` — builds 0x8C000000 low-RAM block + labels syscall slots
6. `Vf3Export.java` — mnemonic-sequence dump per function for diffing
7. `Vf3SeedPointers.java` — literal-pool/table pointer seeding (adapted from
   refs/dream-recomp SeedFromPointers.java; adds 0x0C P2-alias mapping +
   $VF3_OUT/seed_*.csv output)
8. `Vf3ScoreSeeds.java` — scores seeded fns (exit-kind, pushes, calls, runs,
   ascii) → seed_verdict_*.csv (REAL/MAYBE/JUNK)
9. `Vf3ApplySeedVerdicts.java` — renames JUNK to junk_*, comments MAYBE
   (non-destructive; rerun-safe)
10. `tools/ghidra_run.py` — Ghidra+Java locator & headless runner
   (subcommands: locate/doctor/list/run; cache extract/analysis/ghidra_locator.json)

## Syscall vector block (0x8C0000A0-0x8C0000FF)
- Slots labeled: SYS_SYSTEM(0xB0), SYS_FONT(0xB4), SYS_FLASHGD(0xB8), SYS_MISC(0xBC)
- `0x8C0000BC` referenced from 0x8C011E02, whose tail is the archetypal
  syscall trampoline: `mov.l @r0,r0; jmp @r0` — i.e. read the vector, jump.

## Entry & start code
- `_start` created at 0x8C010000 (SHC-style C prologue: pushes r8/r9, fr12-15).
- Program has NO default entry recognition in raw import; _start must be forced.

## Load tables
- 182 `*.BIN` filename strings embedded (0x8C0148E0-0x8C0336xx region) —
  fixed-stride records with prefix flag bytes (`_l`/`_r`, `_du`, trailing length
  bytes). **Not addressed by literal pointers** → resource IDs are resolved
  positionally by the loader at runtime. Runner code/TBD via GDFS module.
- character-vs-file relationships visible: e.g. `MTJACLAU.BIN`/`MTJACPAI.BIN`
  groups with `_l/_r` side flags, `BGM_*` clusters, `CP_*` canvas packs.

## Version-banner strings (module bill-of-materials; build-stamped, not xref'd)
| module | banner | file offset |
|---|---|---|
| GDFS | "GDFS Version 0.53  1998/08/28" | 0x49D60 |
| NAOMI | "NAOMI LIBRARY Ver 0.8 AM R&D" | 0x47E04 |
| pd | "pd Ver 1.07..." | 0x460D1 |
| bu | "bu Ver 1.03 ..." | 0x5B1B1 |
| syCache | "syCache Ver 1.0..." | 0x5CD71 |
| syCbl | "syCbl Ver 1..." | 0x5FE95 |
| kd | "kd Ver 1.20 ..." | 0x63171 |

Note: Katana 1.0B2 headers say "GDFS Version 1.00 1998/09/28" — the game (Aug
20 build master) predates our SDK snapshot for the GDFS component.

## Fingerprint-verified named anchors (1ST_READ)
- `_memset` @ 0x8C0179E4 (byte-fill loop verified by disassembly)
- `_gdFsDaPlaySct` @ 0x8C0360C8 (vtable dispatch `jmp @r0` through driver handle)
- ~56 more matches (cand_/an_ prefixes pending verification) in docs/matches_1ST_READ.md

## Build-diff first pass (tools/diff_builds.py over mnemonic exports)
- 604 functions byte-identical in mnemonic stream between retail & E3
  (library/stable core candidates)
- 3,092 retail functions without exact E3 counterpart (game-code candidates),
  largest listed in extract/analysis/unmatched_retail.csv — these are the
  priority RE targets for game logic (fight engine, UI, AI).

## M3 findings: call graph & dispatch structure
- Best-effort static jsr resolution caps at **~3%** (96/3,222 sites) — the game is
  architected around struct-held function pointers (task/vm model), not literal
  pools. Verified uniform across all code regions.
- Literal pools DO resolve correctly when read — the jsr registers simply come
  from struct fields (`mov.l @(disp,r14),r3; jsr @r3`) instead.
- 146 function-pointer tables detected (4-byte runs of image-range pointers,
  0x0C P2 aliases normalized): overwhelmingly **SHC switch jump tables**.
  27 host functions identified = the game's switch dispatchers
  (`docs/re/fntables_*.md`, `extract/analysis/table_readers_*`).
- These switch-heavy dispatchers are the top candidates for the scene/state/core
  task managers; biggest: f_8c07d368 (256B), f_8c063f58 (222B), f_8c0516a8 (196B).

## Known pitfalls / tooling notes
- Ghidra script dirs: ONE broken .java poisons sibling compile ("bundle" error);
  clear %APPDATA%\ghidra\ghidra_12.1.3_PUBLIC\osgi caches when confused.
- analyzeHeadless needs project dir pre-created; `-deleteProject` deletes at END
  of run; import conflicts if program already exists in project.
- shc.exe (Ver 5.0 R28) dies with "Memory overflow" on modern-RAM hosts —
  anchor builds with the real compiler unresolved yet.
- Hitachi LBR1-MW lib/obj formats under reverse; not parsed yet.
