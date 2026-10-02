# Advancing the decomp: capture is the binding constraint — plan (2026-10-02)

## The problem, quantified

Current verified C coverage: **765 ports, 129,318 unique C bytes (29.8%)**;
rigorous accounted (C+SDK) **765/2,398 fns / 170,450 B (39.2%)**
(`tools/decomp_stats.py`).

The pipeline credit model is strict: a baseline body earns coverage only after a
**golden replay** against an emulator trace of that exact function (paired
registers, XF/FPUL/GBR, return PC, touched RAM — see
`docs/re/batch_pipeline.md` and `tools/oracle/vf3oracle.cpp`). That makes
**execution the supply line**, and the historical batches show it plainly:

| batch | target | captured | delivery | how |
|---|---|---|---|---|
| 6 (`loader`) | +25,000 B | 32 same-shaped 0x8C0B initializers | +25,118 B | one family, many members |
| 7 (`seventh`) | +4,392 B | 61 individuals | small | individual ports run dry |

The batch-7 story is the pattern: **54 of its 61 functions were single
one-off ports** that added ~80 B each. That route cannot keep the coverage
moving. So I measured the actual headroom instead of guessing.

## Census tools (new)

Three tools now quantify what the trace pipeline can and cannot reach:

- `tools/family_map.py` — groups uncovered baseline bodies by coarse
  control-flow shape so that repeat-structure families (like the 0x8C0B
  initializers that delivered +25 KB) are found before individual ports.
- `tools/reach_census.py` — divides uncovered bodies by observed execution
  (hits) and static closure (`closure_ok`).
- `tools/merge_hits.py` — **unions all 46 archived per-state hit surveys**
  (`hits_*.csv`), because `port_plan_current.csv` predates the batch 6–7
  captures and understates execution.
- `tools/reach_static.py` — the decisive one: a **static reachability walk**
  from every executed root through code-flow xref edges (unconditional/
  conditional/computed call+`jump`, plus `sh4_resolved.csv` STATIC targets)
  marks each baseline body as **live** (real code reachable at run time) or
  **orphan** (no static path from any executed function — a seed artifact or
  genuinely dead/unreachable data).

## Results (merged execution census)

Baseline 2,398 fns / 434,656 B. Covered 523 fns / 128,138 B.

Uncovered: **1,894 fns / 306,518 B**, split by what the pipeline can do:

- **Executed (capture-possible today): 206 fns / 55,556 B (18.1%)** —
  179 of them seen in ≥3 distinct archived surveys (well-sampled).
  This is the **only** pool the current capture-driven method can credit
  without new plumbing.
- **Zero-hit (needs a new scenario OR a synthetic-capture path): 1,688 fns /
  250,962 B (81.9%)** — the bulk of remaining coverage.
- Of the zero-hit mass, static reachability shows **580 fns / 70,034 B**
  are **orphan** — no static path from any executed function. These are
  seed-noise candidates (notably, 100 baseline entries are ≤8 bytes each).

Key structural fact (live reachability from executed roots):
- **live = 1,314 fns / 236,484 B** — real program code that sits behind
  function pointers / scenario gates the current captures never open.
- **orphan = 580 fns / 70,034 B** — no static path from any executed
  function. `tools/orphan_screen.py` splits these further by disassembly
  validity:
  - **270 function-like / 52,614 B** — real callee-shaped code (calls,
    branches, often PR-save) with no *static* call path: reached by computed
    dispatch / function pointers the static walk cannot see (e.g. the
    `0x8C07Dxxx` cluster of ~620-820 B bodies). These are **scenario targets**,
    not phantoms.
  - **310 phantom-like / 17,420 B** — no control flow at all: literal-pool
    data / dead locals misread as code. **Skip** these.

## The strategic conclusion

**The capture-driven pipeline is structurally capped near where it is.** Only
~55 KB of uncovered code ever executes in any archived scenario, and each
existing scenario adds only a few new bodies (batch 7: +4.4 KB). To
"advance considerably," we must **expand what reaches the emulator**, because
the coverage credit model is inseparable from emulator execution.

## Plan, in phases

### Phase 0 — consolidate and sanity-check where we are
- Commit the four census tools + this doc (currently uncommitted).
- Fix `port_plan_current.csv` freshness by folding `hits_merged.csv` in, so
  planning stops treating Oct-1-executed functions as dead.
- Screen the ~580 orphan bodies against **true-image reachability from the
  main entrypoint** (0x8C010000) and the loader/dispatch roots; mark
  confirmed phantoms so nobody wastes effort or garners phony credit.

### Phase 1 — drain the executed pool (capture, no new plumbing)
Target the 206 executed uncovered bodies, prioritizing the 179 multi-survey,
replay-complete ones by size. Batch them as **family runs** where shapes match
(`family_map.py`), mirroring the batch-6 +25 KB success. Expected: the largest
single-feasible-win available to today's pipeline.

### Phase 2 — new scenario/drive campaigns (biggest lever, <2 mo)
The real prize is the ~236 KB of **live** code. Open it by reaching the
functions the current scenarios never do:
1. **Attract / menu / versus / replay modes** — the current corpus is
   fight-dominated; attract and menu drive entirely different dispatcher
   windows.
2. **Function-pointer (dispatch) reachability** — most live-but-unhit code
   sits behind computed calls. Use the port plan's `g_phantom`/dyn sites plus
   `braf_tables.csv` to enumerate **dispatch targets by the object/task
   field**, then construct scenarios that walk those tables.
3. **synthetic-entry capture `VF3_RAM_PATCH`** — already proven
   (`tools/oracle/loader_variants.py` injected RAM at watched entries to run
   the 0x8C0B initializers with never-executed inputs). Extend
   `vf3oracle.cpp` with **`VF3_ENTRY_PATCH`** to override the entry
   registers/PC of a watched `spec` so we can invoke a live function that the
   game never calls, seeded from the surrounding region, and still get an
   oracle (the real interpreter executing the real bytes) — this preserves the
   "against the true image" verification property while decoupling coverage
   from gameplay reach.

### Phase 3 — high-value named closures (choose by reachability, not size)
Fold the walker/task-VM/motion fields already mapped
(`docs/re/task_vm.md`, `docs/re/mt_fields.md`, `docs/re/walker_m35.md`) into
worker ports that dominate live bytes: `0x8C09C1F4` (2084 B), `0x8C0C438E`
(1694 B), `0x8C0C321E` (1574 B), `0x8C05B20E` (1322 B), `0x8C0A1658`
(1176 B). Each needs the synthetic-entry path from Phase 2 to run at all.

### Phase 4 — SDK/corpus only if attributable
The roadmap is right that prior SDK sweeps added zero new bodies. Keep this
as a fallback, not a plank.

## The plan as a sitrep

The simplest way to say it: **the harness can already run any function — the
gate is whether any scenario ever reaches it.** So the plan is ordered "cheap
first, structurally necessary next": (0) freeze the census, (1) capture the
55 KB already reachable, (2) build the synthetic-entry + scenario levers that
unlock the ~236 KB of real code, (3) invest those levers on the largest live
closures. Batch-6 proved one family can add +25 KB; a handful of families plus
synthetic entry is how "considerable" stops being one +4 KB batch at a time.

## Phase 0 results (2026-10-02, executed)

- `tools/port_plan.py` now folds `hits_merged.csv` (all 46 archived hit
  surveys) into its hits/executed columns; `port_plan_current.csv` was
  regenerated. `tools/reach_census.py` therefore now reports the true
  capture-possible pool: **250 executed uncovered fns / 59,786 B**
  (up from the stale 75-fn reading; 44 more than the 206-fn estimate in this
  doc, because trace/backlog heat also folded in). Only 15 of them are
  closure_ok (2,450 B): helpers-first ordering still applies.
- `tools/family_map.py` was broken: the old fingerprint hashed a garbled
  per-word op class (wrong nibble) and required identical-size bodies, so it
  reported 0 families even though batch 6 had ported a 55-member family.
  Rewritten around `tools/sh4.py` decoding with a callee-set family key plus
  exact-skeleton leaf clones. Result on the current uncovered set: **the
  family lever is spent** — the largest executed families are two-member
  leaf-clone pairs in the 0x8C0A page; no uncovered cohort approaches the
  batch-6 shape. Step-2 batches are individuals/pairs.
- `tools/reach_static.py` gained `--roots` for entrypoint-rooted reachability
  (0x8C010000 boot copy, 0x8C020000 CRT0, 0x8C09574E startup):
  924 fns / 172,498 B of uncovered code is statically live from entry alone.
- `tools/orphan_screen.py` now cross-screens orphans against entry roots and
  writes `extract/analysis/phantom_screen.csv`:
  **310 confirmed phantoms / 17,420 B (do not port)**, 269 function-like
  orphans / 52,574 B (dispatch/table reach only), 1 entry-live orphan.
- Campaign bar per user decision: **capture-only first, "as much as
  possible"** with the stop rule (route abandoned when replay-complete yield
  < candidate count; campaign ends when a full batch lands <10 KB).
  Synthetic-entry (`VF3_ENTRY_PATCH`) stays out of scope until the
  capture-only ceiling is measured.

## Phase 1 results (2026-10-02)

- Added `tools/watch/vf3_phase1_closure.txt` and captured two development,
  one held-out, and one fresh fight schedules with complete capsule summaries.
- The generated adapter compiles and routes through `vf3_matrix_family`.
  `0x8C0483F4` passes 509/509 strict cases in each corpus. Its frozen 138-byte
  body is promoted in `docs/decomp_status.csv`.
- Shared off-baseline helpers `0x8C042E44`, `0x8C08D158`, and `0x8C0C9CE6`
  pass 512/512, 390/390, and 135/135 development cases respectively, with
  matching held-out and fresh replays. They enable the caller closure but do
  not receive baseline byte credit.
- The remaining watched callers did not reach the replay threshold in these
  scenarios. They remain uncredited and the next campaign should measure a
  new scenario before expanding this adapter.

## Phase 2 scout results (2026-10-02)

- A capture-only scout watched ten high-hit executed bodies outside the Phase 1
  closure. Only `0x8C0AA446` produced a promotion-sized corpus: 422 complete
  development cases, with 503 held-out and 483 fresh cases.
- The generated Phase 2 adapter compiles and routes through
  `vf3_matrix_family`; strict replay passes every case with zero skips and zero
  out-of-bounds accesses. Its 48-byte body is promoted in the status ledger.
- `0x8C093270` produced only two complete cases; the remaining scout entries
  were absent. They remain uncredited and are not expanded into a batch.

## Phase 3 results (2026-10-02, executed)

Phase 3 asked for the five named live closures, each gated behind the synthetic
entry path. `0x8C05B20E` (1322 B) was taken as the pilot and the result changed
what the phase means.

### The lever works, and it is now measurable

`VF3_ENTRY_PATCH` was extended until a seed campaign was actually usable:

- **Seed variants.** `seed <trigger>` starts a new variant; variants apply
  round-robin over a trigger's firings, so one hot site walks a whole input
  space instead of repeating one input.
- **Gate-aware seed plans.** `tools/oracle/gate_scan.py` extracts the `tst`
  masks and selector switches from a disassembly; `tools/oracle/seed_plan.py`
  turns them into a patch that pairs every selector value with the guard bit
  that opens its switch. The 0x8C05B20E recipe is 974 variants; campaigns step
  `--probe-offset` across runs and merge corpora.
- **Trigger discipline.** Only JSR call sites are safe to redirect (prologue
  sites skip the frame push and kill the run), and reachability has to be
  measured in capsule mode — hit surveys without the memory hooks land in a
  different fight phase. Both measurement traps are documented in
  `docs/re/entry_patch.md`.
- **Exact rollback.** Restoring registers and RAM is not sufficient on this
  fork: the write-back operand cache has to be flushed per restored page, the
  host FP rounding mode re-applied, the resume PC taken from the seeded return
  address, and the already-fetched opcode discarded after an abort
  (`vf3OracleTakeSkip`).
- **Poison seeds cost one case, not the run.** Faults abort the probe
  (`vf3OracleAbortProbe`), non-returning seeds are retired at `VF3_PROBE_OPS`
  instructions, and both are recorded as invalid specimens with no credit.
- **Accounting.** `--probe-debug` reports probes, busy skips and per-trigger
  counts, which is what separates "the seed plan is bad" from "the trigger is
  never reached".

### Coverage went 47.8% -> 94.9%; promotion still fails

`tools/body_cover.py` (new) is the gate this phase was missing: it measures how
much of a frozen body a corpus actually executed, because the ledger credits
whole functions. Without it the 47.8% single-run corpus would have looked like a
port.

| stage | corpus | body bytes covered | strict replay |
|---|---|---|---|
| first probe (1 seed set) | 22 cases | 846/1322 (64.0%) | n/a |
| multi-trigger sweep | 23 cases | 846/1322 (64.0%) | n/a |
| gate-aware plan, 3 offsets | 3×126 cases | 1032/1322 (78.1%) | n/a |
| gate-aware plan, 10 offsets | 14 corpora | **1254/1322 (94.9%)** | **4/204** |

The generated adapter is complete on paper — 704 guest statements, **0
unsupported instructions** — and it is the first Phase 3 body to reach that. It
still fails strict replay, and the reason is structural rather than a bug in the
seeds: the deep arms treat descriptor words as **pointers** and dereference
them. Reaching those arms requires seeding values that point at live game
memory, and the resulting capsules record accesses outside every captured
window (`got R 0989b72c` where the guest did `W 00010de0`). A C port would have
to reproduce pointer-valued descriptor semantics that the corpus does not pin
down; the 34 remaining bytes are the arms behind that dependency.

Decision, per the repo's parking rule: **`0x8C05B20E` is parked, not ported.** A
non-`ported` row records the coverage, the generated adapter
(`extract/analysis/phase3_regenerated.c`) and the failing replay, so the work is
visible and the 1322 bytes are not booked.

### What this says about the remaining four targets

The pilot generalises as a triage, not a delivery:

1. **Descriptor/pure workers** (flag + selector words, no pointer chasing) are
   fully reachable by the seed sweep and should port cleanly at ~95% coverage.
   `0x8C09C1F4`, `0x8C0C438E`, `0x8C0C321E`, `0x8C0A1658` are next; each needs
   its `gate_scan` + `seed_plan` recipe before its first capture.
2. **Pointer-chasing workers** need live-object seeding: the trigger context
   must supply the object the function would really have been called with,
   which means dispatch-table reconstruction (Phase 2 item 2) rather than a
   synthetic register fixture. That is a different lever and was not attempted.
3. **Coverage must be re-measured per body.** 94.9% is not a port, and
   `body_cover.py --min-cover` now says so before the ledger does.

## Plan closure

Phases 0–3 are executed. The quantitative thesis of this document held: the
capture-only ceiling is real (Phase 1 delivered 138 B and the Phase 2 scout
48 B, against a 55 KB executed pool that the tooling says cannot grow much),
and synthetic entry is the only lever that reaches the other ~236 KB. Phase 3
established what that lever costs and what it buys — it makes never-executed
bodies measurable and replayable-in-principle, it does not make them portable
for free.

Phase 4 (SDK/corpus sweeps) stays a fallback: it is the only remaining lever
that needs no emulator work, and it has historically returned zero new bodies.

Standing state: **765 ports, 129,456 unique C bytes (29.8%)**; rigorous
accounted 765/2,398 fns / 170,450 B (39.2%). No Phase 3 bytes are credited.

Next candidates, in order of expected value:

1. `gate_scan` + `seed_plan` recipes for `0x8C09C1F4`, `0x8C0C438E`,
   `0x8C0C321E`, `0x8C0A1658`; promote only what clears
   `body_cover.py --min-cover 100 --strict` and passes strict replay on
   development, held-out and fresh corpora.
2. Dispatch-table reconstruction for the pointer-chasing cluster, so the seeds
   can carry a real object pointer instead of a fabricated one — that is what
   would unlock the last 7% of `0x8C05B20E` and its replay.
3. Done in this phase: `body_cover.py` now runs inside `tools/verify_all.py` as
   an advisory pass over the golden bindings, and `--strict` is the promotion
   gate. It cannot fail historical piecewise ports, which are bound to
   fragment-boundary corpora by design.

