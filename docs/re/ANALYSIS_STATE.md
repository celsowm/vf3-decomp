# RE analysis state (auto + manual notes)

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
