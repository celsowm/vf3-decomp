# RE analysis state (auto + manual notes)

## Ghidra project: extract/ghidra_proj/VF3 (not version controlled; reconstructible)

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
- In-built analysis: direct instruction references found: `0x8C0000BC` referenced
  from code at 0x8C011E02 (likely a bios-misc call wrapper). GD/BU/PD libs call
  syscalls indirectly through the block too; deeper scan planned.

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

## Known pitfalls / tooling notes
- Ghidra script dirs: ONE broken .java poisons sibling compile ("bundle" error);
  clear %APPDATA%\ghidra\ghidra_12.1.3_PUBLIC\osgi caches when confused.
- analyzeHeadless needs project dir pre-created; `-deleteProject` deletes at END
  of run; import conflicts if program already exists in project.
- shc.exe (Ver 5.0 R28) dies with "Memory overflow" on modern-RAM hosts —
  anchor builds with the real compiler unresolved yet.
- Hitachi LBR1-MW lib/obj formats under reverse; not parsed yet.
