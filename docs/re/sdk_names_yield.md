# SDK-symbol naming yield measurement (T5) — 2026-09-25

Question: can the 213 union-corpus full-body matches be bound to real
symbol names from the SDK objects (`tools/elf_symtab.py`)?

## Method
For each full-body match in `extract/analysis/sdk_union_matches.csv`, locate
the containing carved region (`sdk_corpus/sdk8eu.csv`), parse the ELF
program/section headers when the region is a whole-file ELF (`e_machine ==
42`), translate the matched file offset to a vaddr, and look up the
`STT_FUNC` symbol covering it.

## Result: 0 / 213
- `sdk8eu` corpus: 30 whole-file ELF regions, **0 with a symtab**.
  (3,150 `.symtab` string hits in the blob come from debug/tool objects,
  not the sample programs.)
- `sdk053_samples.bin` (exact-version DCSDK 1.00J samples): **0 `.symtab`,
  0 `.strtab` occurrences** — stripped.
- `tools/kamui/BINARIES/KMMARBLE.ELF` (on-disk, 801 KB): **0 `.symtab`**.
- Matches by region source: 159 in `sdk053_samples.bin` (stripped), 38 in
  `SPR_MTN.ELF` (stripped), 8 in `MEM_UTIL.ELF`, 2 in `KMMARBLE.ELF`,
  ~5 in `.LIB` archives (module names recoverable via lbr extraction, same
  as the existing `v040_sdk_names.csv` pipeline).
- `extract/analysis/sdk_union_names.csv` exists as the (empty) output slot;
  the tool stays for re-runs if an unstripped drop ever appears.

## Decision
Do NOT run a full naming pass off ELF symbols — expected yield ~5/213.
Naming continues via:
1. `.lib` module labels already wired (`libmask_matches.csv` by-library
   breakdown; `ninja`, `shinobi`, `sh4nlfzz`, …),
2. behavior-derived names from ports (`orient2`, `poly_classify`,
   `vecpush`; `docs/re/fight_geometry.md`),
3. string/xref evidence for engine functions.
