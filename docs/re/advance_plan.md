# Advancing the decomp: capture is the binding constraint — plan (2026-10-02)

## The problem, quantified

Current verified C coverage: **504 ports, 129,270 unique C bytes (29.7%)**;
rigorous accounted (C+SDK) **763/2,398 fns / 170,264 B (39.2%)**
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
