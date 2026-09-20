# Switch-dispatcher certification pass (2026-09-19)

Question (from the frontier list): are f_8c07d368 / f_8c063f58 / f_8c0516a8 the
fight dispatchers? Method: post seeding+naming project state (7,628 fns),
full disasm dump, existing fntables/table_readers CSVs, fight hit set.

## Verdict: NO — switch tables do not route to fight code

1. **0 of 146** switch tables in `fntables_1ST_READ.csv` have any case target
   in the fight set (325 fight_* functions / fight_hits.csv). Table targets
   cluster in the 0x8C0Dxxxx–0x8C10xxxx support-library code band. Fight
   dispatch therefore follows the struct-task indirect-call model
   (docs/re/architecture.md), not SHC switch lowering.
2. The three candidates:
   - `f_8c07d368` — no function contains it in the current project state
     (dead/data region after analysis; not a valid host).
   - `f_8c063f58` — offset-table iterator: unrolled `mov.w @(r0,r0)` reads
     against bases 0x8c063fb4..0x8c064064 by successive immediate index
     constants; NOT a case branch.
   - `f_8c0516a8` — legitimate 5-case dispatcher via table 0x8C051740 →
     targets 0x8c0dc47c/48c/49c/4ac/4bc (all unnamed, non-fight area). A
     real dispatcher, but init/config-scoped, not fight.

## What IS among the fight set (next candidates for the loop's dispatcher)

20 fight functions contain `mova`/`braf`. The two `braf` hosts are also top-3
per-frame workers from the fight trace:

| fn | size | fight hits/frame | note |
|---|---|---|---|
| fight_f_8c068f86 | 241 | 101.4 | braf @ +0x1E, tight loop |
| fight_f_8c0c7e0e | 951 | ~2 | braf @ +0xA6, big body |

`mova-`hosts of interest: fight_f_8c06e90c (823B), fight_f_8c0845c2 (787B),
fight_f_8c073952 (727B).

Next step candidates (needs a picked approach):
- Trace the r14/r13 struct fields feeding `braf rN`/`mova` index in
  fight_f_8c068f86 from the fight savestate (have trace tooling).
- Map `task_run_A/B/C` callsites and see which task type lands on
  fight_f_8c068f86 every frame.

Artifacts: extract/analysis/dispatch_cert.md (generated report),
disasm_1ST_READ.unsc.bin.asm (full listing snapshot).
