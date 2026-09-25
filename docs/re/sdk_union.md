# SDK union-corpus sweep (Phase A) — 2026-09-25

Goal: stop relying on one ISO's 18 sample ELFs; carve every SH-4 object we
own out of the SDK pressings and match the game against the union.

## What was carved
- `tools/iso_carve.py` (new): ISO9660 walker with auto layout detection
  (2048 plain / 2352+24 Mode2/Form1 / 2352+16 Mode1). Carves every member
  containing an **SH-4 ELF** (`e_machine == 42`) or a SYSROF object, plus
  `.lib`/`.obj` members, into `<prefix>.bin` + `<prefix>.csv` manifest
  (region boundaries recorded; 64-byte seams between regions).
- `European Dreamcast SDK release 8` → `TOC122A.img` (781 MB):
  **1,594 SH-4 ELF regions + 97 libs/objs**, 21.2 MB corpus
  (`extract/analysis/sdk_corpus/sdk8eu.{bin,csv}`). Verified e_machine
  histogram: 1594 × SH-4, 4 × 0, 10 false hits discarded.
  Contains the full release-8 libraries: `NINJA.LIB`, `SHINOBI.LIB`,
  `KAMUI2.LIB`, `SH4NLFZZ.LIB`, `SOFDEC.LIB`, `SG_MW.LIB`, `NINDOWS.LIB`,
  `AUDIO64.LIB`, `CRI_ADXS.LIB`, plus Kamui2 sample programs.

## Matching
- `tools/sdk_sweep.py` (new): the `sdk053_match.py` masked + literal-pool
  wildcard token matcher run over multiple corpora; a match must lie fully
  inside one carved region (no cross-seam false positives). Version banner
  extracted per region when present.
- Corpora: sdk8eu, DCSDK 1.00J sample blob (`sdk053_samples.bin`), Katana
  0.40 Pre.2/Release.4 extracted libs, Katana 1.0B2 SET5 (`tools/katana`),
  Kamui2/Darkness (`tools/kamui`).
- Result: **362 functions matched, 213 full-body**; 31 full-body matches are
  new against the previously credited exact-version set.

## Verification
- `tools/verify_union.py` (new) re-reads the corpus bytes and compares raw
  16-bit words. Classification: a **concrete mismatch** is a word whose
  unmasked fields (opcode + registers) differ, excluding branch targets,
  disp8/imm8 and PC-relative pool slots (which relocation legitimately
  changes). `extract/analysis/sdk_union_verify.txt`: **31/31 new full-body
  matches, 0 concrete mismatches**, with side-by-side capstone disassembly
  of the largest matches.

## Result / coverage
- New bucket `SDK-attributed (union corpus: release-8 SH-4 ELFs/libs)`:
  **29 fns / 1,184 B**, plus 2 union fragments / 442 B.
- Rigorous coverage: **273/2398 (11.4%) fns, 43,804/434,656 (10.1%) bytes**;
  incl-trace 431 (18.0%) / 106,876 (24.6%).

## Ceiling finding
The game links GDFS **0.53 (1998/08/28)**; release 8 carries GDFS 1.02/1.05/
1.07 and Katana 0.40 carries 0.46/0.49, so most GDFS bodies differ. The
exact-version 0.53 code only exists inside the DCSDK 1.00J sample ELFs, and
its page-0x03 fragments do not extend under register-masking (different build
flags / inlining, not register allocation). SDK code is a **bounded** portion
of the 434,656-byte baseline; the remaining ~2,120 functions are custom
engine (M40). Further SDK-only sweeps have sharply diminishing returns.
