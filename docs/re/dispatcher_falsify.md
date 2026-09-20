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

## Follow-up: fight_f_8c068f86 r14-feed via trace_fight1.bin (same day)

Trace evidence (197M PC records, post-seeding name map):
- 2,282,831 body hits; the literal prologue (+0x00..+0x0A, incl.
  `mov.l @(lit),r14`) never hits — execution lives in the +0x0C..+0xE6 loop;
  loop head at +0x0C (all predecessor edges are in-function addresses).
- Trace mechanism = branch-landing records: de-duplicated fn transitions match
  the block-run structure (verified around fight_f_8c0c7e0e entry at rec
  #34,999,958: caller trampoline FUN_8c0c7e00, callers FUN_8c0971c8/8c09723a).
- Literal pools decode as NEIGHBORING BYTES: 0x8c068fc0.. holds the sequence
  `(0xC7, 0x0C0D533C) (0xC8, ...534C) (0xC9, ...5360) (0xCA, ...536C)` =
  (id, ptr) pairs for a 202-id (0xC7..~0x191) map, stride ~0x10-0x14 bytes.
- The pointed-to RAM region 0x0C0D533C.. is a live table of name strings:
  "A_ds10_kai" / later "sd_Ak_01..28"-prefixed records (ai/b/kuy/kia/kl…
  per-character sub-ids). So the function maps id → "sd"-class string
  constant and the ~101 hits/frame loop = resource-slot lookup during fight.
- Interpretation: the braf block is a 4-way switch (period-4 u16 offsets
  0x640/0x6ab/0x6b9/0x6bd at fn+0x20..) over string-record subtypes; body
  case-blocks are the +0x86..+0xe6 runs (equal hit counts = one pass per
  activation). Renamed to **cand_sd_slot_lookup** in the Ghidra project.
- r14 is set per-activation from the literal 0x0C0D5360 (id 0xC9's record);
  THIS IS NOT a task-struct feed — the M6-era "r14 task struct" question is
  answered for this function: singleton literal, id-indexed.
- Caller-side feeder chain (for r14-bearing functions generally): entry call
  chain ends at FUN_8c0971c8 / FUN_8c09723a (scheduler candidates); the
  fight-region caller pair for the braf-host fight_f_8c0c7e0e is
  trampoline FUN_8c0c7e00. These three are the next naming targets.

### sd_table decode (later same day)

The four referenced records decode to the fight sound-variant names:
- 0xC7: "sd_passing_far"
- 0xC8: "sd_passing_far_off"
- 0xC9: "sd_Ak_01" (Akira slot 1)
- 0xCA: "sd_Ak_02" (Akira slot 2)

(runtime copies held at 0x8C0D533C/534C/5360/536C; per-character ROM source
string table at ROM 0x8C018A00+; RAM verified via shots/ram_r15_*.bin).
So fight_f_8c068f86 (`cand_sd_slot_lookup`) = per-frame lookup yielding the
sound-variant slot for the current fight configuration (camera pass +
character-specific banks). Full table dump: extract/analysis/sd_names.csv.
