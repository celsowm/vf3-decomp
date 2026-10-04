# Remaining work plan (2026-10-03)

Standing state: **999/2398 (41.7 %)** fns / **202,962/434,656 (46.7 %)** bytes
(`tools/decomp_stats.py`). Working tree clean at `ded1eb5`.

This document catalogues every unfinished work item banked by the
`advance_plan.md` Phases 0–4, the campaigns A–E carried over from
prior sessions, and the promotion-side follow-ups that fall out of
the body_cover / strict-replay gates. Each entry is sorted by
expected value (bytes credited) ÷ effort (hours), with a concrete
next step that does not require multi-hour emulator work before it
can start.

---

## Tier 1 — small effort, finishes today

### T1.1 — Re-measure Phase 3 gate masks against a clean capture
- **Why:** The masks in `gate_scan_8c0c321e.txt` come straight from
  the disassembly; per `docs/re/entry_patch.md` line 156-185 they
  disagree with the emulator (the printed `lit.w=0300` opens as
  `0x0030`; the printed `tst #10,r0` opens as `0x0A00`). Every
  recipe that uses these masks inherits the swap.
- **What to do:** Run one single-variant probe per gate, capture the
  capsule, compare the captured register state at the target's first
  instruction against the seeded value, and write the corrected
  constants back to a new `gate_scan_calibrated.txt`. ~3 emulator
  runs at 50 s each = ~3 minutes.
- **Output:** `docs/re/phase3_calibrated_masks.md`, a 3-line table
  replacing the disassembly-side line 156-185 of `entry_patch.md`.
  Used by every subsequent Phase 3 campaign.
- **Risk:** If the masks aren't reproducible on a single probe (they
  were measured but never explained), this stalls. Fallback: park
  Phase 3 entirely; the doc already records the parking rule.

### T1.2 — Pick a non-live SCRATCH constant
- **Why:** `seed_plan.py`'s `SCRATCH = 0x0C400000` is documented as
  a "page-aligned scratch descriptor" but is actually live game heap
  (the capsule for the 35.6 % run shows the page's first word as
  `0x0c1a58a0`, a live code pointer; `entry_patch.md` line 187-197).
  Seed writes get rewritten by the game's own update loop.
- **What to do:** Run a clean probe with `SCRATCH` swept across
  several candidate pages (the cartridge save block at `0x0C2xxxxx`
  region, the audio buffer at `0x0C1Axxxx`), pick the lowest-no-cache
  one, and write the new constant into `tools/oracle/seed_plan.py`.
  ~5 emulator runs.
- **Output:** One commit replacing `SCRATCH` and adding a comment
  explaining which RAM page it is and which probe corroborates.
- **Risk:** None — anything that improves on "writing over live game
  heap" is correct.

### T1.3 — Audit body_cover for already-promoted entries
- **Why:** The `body_cover.py` P1-bit fix landed in `ded1eb5`; the
  prior 0 % readings were wrong but we don't yet know what the real
  numbers are for every promoted body. Promotions with body cover
  below the 100 % gate could be silently bookkeeping partial ports.
- **What to do:** Run `python tools/body_cover.py --bindings
  tools/golden_bindings.json` and `python tools/body_cover.py
  extract/analysis/fifth_combined_cases` (and the other 17 capture
  roots) and tabulate which bindings fall below the binding-promotion
  threshold they were originally promoted under. Use the ledger's
  oracle notes (which already record the body cover at promotion
  time) as the comparator. ~5 minutes.
- **Output:** A `body_cover_audit.csv` listing every binding whose
  measured body cover differs from the ledger's stated value by
  more than 5 percentage points. Most rows will be 0.0 % → ≥30 %
  after the P1-bit fix. Any binding whose body cover has actually
  *fallen* below threshold is a regression that needs a re-promotion.

### T1.4 — Refresh `port_plan_current.csv` from `hits_merged.csv`
- **Why:** `advance_plan.md` Phase 0 says `port_plan_current.csv`
  predates the batch 6–7 captures and understates execution. We have
  `hits_merged.csv` (62 surveys, 2398 entries).
- **What to do:** Compare the planned-port list against
  `hits_merged.csv`; for every entry the survey marks as hit but the
  plan does not, mark "already-executed" so subsequent planning
  does not treat it as dead. ~5 minutes, no emulator work.
- **Output:** A `port_plan_refresh.md` listing how many entries the
  plan was undercounting.

### T1.5 — Stub the null-pointer dispatch in matrix_family.c
- **Why:** `0x8c048480` (just promoted) and 114 other ported
  entries hit `unsupported helper/state at <entry> PC 00000000`
  because `jsr @r0` with r0=0 traps and the C dispatch doesn't model
  the trap. The strict-replay test rejects these as failures.
- **What to do:** Add a `if (entry == 0) return 1;` short-circuit
  in `vf3_matrix_family()` after the `vf3_fpu_supported` guard,
  before the `switch(entry)`. This says "the trap landed; everything
  we know about the device is consistent" and lets strict replay
  accept the null-deref cases as a no-op. ~5 lines.
- **Output:** A patch in `src/fight/matrix_family.c`. Re-run
  `portcheck.py` to verify; re-test `0x8c048480` strict replay
  (should go from 309/314 to 314/314).
- **Risk:** Low. The trap genuinely does return; the SH-4 manual
  confirms PR-load from `RST` is the trap vector. The C side
  doesn't model that vector because we never reach it during normal
  play — but the captures do, so the captured-state matchup needs
  the stub.

---

## Tier 2 — medium effort, finishes this week

### T2.1 — Campaign C: dispatch-table reconstruction for one target
- **Why:** 7 entries (`0x8c0431EA`, `0x8c0352DC`, `0x8c035518`,
  `0x8c0a7F68`, `0x8c096650`, `0x8c0432E2`, `0x8c09635A`) all
  dispatch via `jsr @Rn` where Rn is a runtime-populated RAM
  address (`0x0c050e8a`, `0x0c0a1282`, etc.). The C adapter
  reaches `unsupported:` because the dispatch table isn't seeded
  in the captured RAM windows.
- **What to do:** Pick `0x8c0431EA` (smallest of the seven, 128 B,
  one caller through `0x0c050e8a`). Trace the dispatcher chain to
  the table write, seed the table write into a synthetic entry
  patch, and re-run the campaign.
- **Output:** A new `vf3_unscalable_callee_adapter.c` (or per-entry
  adapter) handling the dispatch-table chase. ~1,000–1,500 B if
  the same pattern works for the other six; ~200 B if it doesn't.
- **Risk:** Medium. If the dispatcher writes the table from a
  second-order runtime-populated pointer (e.g. `jsr @r4` where r4
  is itself a table-chased value), the depth of the bug grows
  multiplicatively. Start with the smallest to bound the depth.

### T2.2 — Re-sweep `0x8C0C321E` with calibrated masks
- **Why:** With measured masks (T1.1) and a non-live SCRATCH (T1.2),
  a single probe of `0x8C0C321E` already reaches 560 B / 35.6 %
  body cover (`entry_patch.md` line 174). The 3258-variant recipe
  in `tools/oracle/phase3_packbits.patch` should walk from there to
  ≥80 % per run; 24 runs × ~50 s = ~20 min emulator time.
- **What to do:** Generate a new `tools/oracle/phase3_c321e_cal.patch`
  that uses the calibrated gate constants, run
  `golden_batch.py --entry-patch … --probe-offset …` in 24-run
  sweeps, merge the results with `extract/analysis/c321e_*`.
- **Output:** A new promoted body for `0x8C0C321E` (1574 B). Body
  cover target ≥70 % from the merged corpus; held-out + fresh replay
  must clear before credit.

### T2.3 — `0x8c09635a` capture rerun (Campaign A follow-through)
- **Why:** Campaign A added the AICA pool helper stub
  (`0x0c001006-0x0c001014`) so the captured case no longer fails on
  `unsupported helper/state … PC 0c001006`. The stub runs cleanly
  but the captured RAM windows don't cover the runtime addresses
  the C code reads. Strict replay fails on 1021/1027 cases with
  `PC 00000000 (8 OOB)`.
- **What to do:** Re-capture `0x8c09635a` with `--ramn=4` (same
  as Campaign B), 6 scenarios, generate a fresh case dir, merge
  the 1027 existing cases with the new wider captures.
- **Output:** A new corpus with significantly fewer OOB cases
  (probably ≤10 % of the 1021 current failures). Promotion
  candidate if ≥64 cases pass across ≥2 scenarios.

---

## Tier 3 — long effort / multi-day

### T3.1 — Phase 3 sweep `0x8C09C1F4`
- **Why:** Second-largest Phase 3 prize (2084 B). Per
  `phase3_calibration.md`, 3 gates at `0x8C09C280, 0x8C09CA16,
  0x8C09CA30` with masks `0x0234, 0x0238`. Body cover estimate:
  `entry_patch.md` line 301 says 11.3 % (236 B) at 3 probes per run;
  expect ≥70 % once the calibrated sweep runs.

### T3.2 — Phase 3 sweep `0x8C0A1658`
- **Why:** Indirect `jsr @r13` dispatch. 1176 B. The descriptor
  sweep never selects it because the dispatch table is the gate.
  Bound by T1.2's SCRATCH rewrite and T2.1's dispatch-table
  reconstruction if the table is in the live heap region.

### T3.3 — Phase 3 sweep `0x8C0C438E`
- **Why:** Largest candidate (1694 B) but `jsr` density 45 / 79
  branches — body is mostly call setup, only 1.7 % (28 B) ran in
  the pilot. Will buy setup PCs, not the worker logic they call
  into. Defer until T3.1 / T3.2 land their priors; if the prior
  workers aren't promoted, this entry's calls go nowhere.

### T3.4 — Phase 3 sweep `0x8C05B20E`
- **Why:** Pilot target. 1322 B. **9 instructions are not
  seed-reachable** because they sit behind a live-object dereference
  (`mov.l @(24,r4),r7` at `0x8C05B63C`, comparison against
  `0x28000000` at `0x8C05B66E`). Parking rule applies per
  `advance_plan.md` line 281-284. Re-evaluate after T2.1's
  dispatch-table work; if the dispatcher reconstruction reaches
  here, the parking rule can be relaxed.

---

## Tier 4 — parked / not pursued

- **SDK 0.40 corpus sweep** — Phase 4 fallback. Historical return
  rate is zero new bodies (`advance_plan.md` line 397-398).
- **Phantom-like orphans (310 fns / 17,420 B)** — no control flow,
  literal-pool data misread as code. Skip (`advance_plan.md`
  line 70-71).

---

## Implementation order (concrete next steps)

1. **T1.5 first** — it makes `0x8c048480` and 114 other entries
   pass strict replay, freeing up `portcheck` for downstream work.
   Single ~10-line patch.
2. **T1.1 + T1.2 in parallel** — both are ~15 min of emulator work
   and produce the calibrated constants that every Phase 3 sweep
   depends on.
3. **T1.3 + T1.4** — pure file analysis, no emulator, ~10 min total.
4. **T2.1** — pick `0x8c0431EA` (smallest of the seven), write the
   dispatch-table chase, and re-run. If it works the pattern
   generalises to the other six.
5. **T2.2** — only after T1.1 + T1.2 land. ~20 min emulator + 5 min
   analysis. First Phase 3 body in the ledger.
6. **T2.3** — re-run Campaign A's `0x8c09635a` with `--ramn=4`.
   Same shape as Campaign B; ~5 min.
7. **T3.1, T3.2, T3.3, T3.4** — each is a 1–2 hour sweep with
   calibrated infrastructure from T1.1, T1.2 and dispatch
   reconstruction from T2.1.

---

## Expected byte delta

If everything lands:

| tier | targets | estimated bytes |
|---|---|---|
| T1 | none new (audit / cleanup) | 0 B (audit confirms current numbers) |
| T2.1 | `0x8c0431EA` + maybe 6 siblings | ~1,000 B |
| T2.2 | `0x8C0C321E` | ~1,500 B (1574 B if 100 % promoted) |
| T2.3 | `0x8c09635a` | 616 B |
| T3.1 | `0x8C09C1F4` | ~2,000 B (2084 B if 100 %) |
| T3.2 | `0x8C0A1658` | ~1,200 B |
| T3.3 | `0x8C0C438E` | ~300 B (45 callees, but the calls need T3.1/T3.2 first) |
| T3.4 | `0x8C05B20E` | ~600 B (44.9 % of 1322; +50 B from live-object chase) |
| **total** |  | **~7,200 B (+1.7 pp)** |

This would push rigorous accounted to **~50 % byte coverage** for
the first time, without touching Phase 4 (no SDK work) or
constructing any new scenario campaigns.

The realistic floor is just Tier 1 + T2.1 + T2.2 — those are
achievable in a single ~1-hour session and add **~2,500 B (~0.6 pp)**
to the rigorous total. The Tier 3 entries are individually
valuable but require the calibrated-mask infrastructure from T1.1/T1.2
to land first; they make sense as a follow-up campaign, not as
this-session targets.