# RE analysis state (auto + manual notes)

## Ghidra project: extract/ghidra_proj/VF3 (not version controlled; reconstructible)
- GUI: run `ghidra.bat` at repo root.

Programs (all SuperH4 LE @ 0x8C010000, BinaryLoader raw images):
- `1ST_READ.unsc.bin` — retail MK-51001 V1.002
- `VF3TBE3.unsc.bin` — E3 build (second build for diffing)
- `RELOAD.unsc.bin` — reset/init-related second-stage module

Function inventory (post baseline + prologue sweep + name-apply):
- 1ST_READ: **3,696** functions (~278KB bodies) — approx 23% of the 1.15MB image
- VF3TBE3: ~3,664 functions
- RELOAD: 335 functions

Tooling pipeline (tools/gscripts/*.java run via analyzeHeadless):
1. `Vf3Baseline.java` — function inventory CSV to extract/analysis/funcs_*.csv
2. `Vf3Prologue.java` — SHC prologue sweep creating functions at stack pushes
3. `Vf3ApplyNames.java` — applies fingerprint CSV names (creates functions too)
4. `Vf3Disasm.java` — quick disasm print at env-supplied addresses
5. `Vf3SyscallMap.java` — builds 0x8C000000 low-RAM block + labels syscall slots
6. `Vf3Export.java` — mnemonic-sequence dump per function for diffing

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
