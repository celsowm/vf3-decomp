# Advancing the decomp: capture is the binding constraint — plan (2026-10-02)

## The problem, quantified

Current verified C coverage: **765 ports, 129,456 unique C bytes (29.8%)**;
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
  that opens its switch. The campaign that produced the clean corpus is
  `tools/oracle/phase3_allpro.patch`: **3258 variants** over 26 prologue
  triggers. Campaigns step `--probe-offset` across runs and merge corpora.
- **Trigger discipline.** Trigger choice is only safe *with* substitution: a JSR
  call site needs `pr = trigger+4` (past the delay slot) and a bare prologue
  needs `pr = trigger+2`; before substitution the call site still ran its
  `jsr` and rewrote `pr` from the redirected PC, and the prologue site killed
  the run outright. Reachability also has to be measured in capsule mode — hit
  surveys without the memory hooks land in a different fight phase. All three
  measurement traps are documented in `docs/re/entry_patch.md`.
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

### Coverage went 47.8% -> 98.3%, but on a broken fixture; clean capture is 44.9%

`tools/body_cover.py` (new) is the gate this phase was missing: it measures how
much of a frozen body a corpus actually executed, because the ledger credits
whole functions. Without it the first 47.8% corpus would have looked like a port.

| corpus | cases | body bytes covered | strict replay |
|---|---|---|---|
| first probe (one seed set) | 22 | 846/1322 (64.0%) | 4/204 FAIL |
| pre-substitution campaign, merged | 5843 | **1300/1322 (98.3%)** | **FAIL** |
| substitution campaign, 24 runs merged | 72 | 594/1322 (44.9%) | **PASS (24/24 corpora)** |

The two rows disagree because the high-coverage corpus was captured with a
**broken fixture**. The hook runs before `ExecuteOpcode`, so redirecting the PC
still let the trigger instruction execute — and a trigger's `jsr` then rewrote
`pr` from the redirected PC, leaving the caller with a broken return chain. The
game spent the run looping through the trigger region, which produced 250+
probes per run and deep path coverage, and also contaminated every exit state
(`reg r8: got 0x65 want <seeded pr>`). The "hot" call sites in that survey were
mostly `rts` instructions picked up by a scan mask that `jsr @Rn` shares.

`vf3OracleTakeSubstitute()` fixes it at the fetch site: the target's first
opcode *replaces* the trigger's, so the trigger never runs. After that:

- every capture replays exactly (24 of 24 independent corpora PASS), and
- the probe rate collapses to the truth — about **3 probes per run**, because
  the earlier 250 was the broken loop. Survey numbers must not be read past
  their sample cap: a `--max-samples 60` survey reported 60 hits for sites that
  fire once per run.

So the campaign's real coverage/coverage-vs-fidelity trade is: 98.3% body
coverage that no port can be bound to, or 44.9% that replays cleanly.

### The last arms are not seed-reachable

Of the 11 instructions the high-coverage corpus still misses, 9 sit behind
`0x8C05B63C: mov.l @(24,r4),r7` — a dereference of a *live game object*, whose
contents must compare equal to `0x28000000` for the `cmp/eq` at `0x8C05B66E` to
take the branch. No register or RAM seed can fabricate that: the target must be
handed the object the game would really have passed. The other 2
(`0x8C05B46C`/`0x8C05B46E`) are gated by flag bit 24 and are reachable — they
simply need the late variants of the plan, which run at 3 probes per run.

**Answer to "can we reach 100%": not with this lever.** Synthetic seeds can
walk everything the *descriptor* selects (44.9% of the body, cleanly replayed,
and 98.3% when the fixture is allowed to corrupt the game). The remainder needs
live-object seeding — dispatch-table reconstruction so the probe receives the
real object pointer — which is Phase 2 item 2, not the seed sweep.

Decision, per the repo's parking rule: **`0x8C05B20E` stays parked.** The
substitution-era adapter (`extract/analysis/phase3_final_regenerated.c`,
704 guest statements, 0 unsupported instructions) replays every clean case but
covers 44.9% of the body, so the 1322 bytes are not booked.

### What this says about the remaining four targets

The pilot was re-tested against all four named targets, and the first useful
result is that **"pointer chasing" was the wrong axis to triage on**. What
actually decides a target is two things: how much of the body is *call setup*
rather than decisions, and *where the chased pointer comes from*.

`jsr` density turned out to be the cheap predictor, because the ledger credits
whole functions while the sweep only moves instructions the function itself
decides:

| target | size | `jsr` | branches | 3-probe body cover | verdict |
|---|---|---|---|---|---|
| `0x8C05B20E` (pilot) | 1322 B | 1 | 98 | 47.8% | leaf worker — the shape the sweep is built for |
| `0x8C0C321E` | 1574 B | 6 | 96 | **31.1%** (490 B) | best candidate |
| `0x8C09C1F4` | 2084 B | 8 | 64 | 11.3% (236 B) | candidate, bigger prize |
| `0x8C0C438E` | 1694 B | **45** | 79 | 1.7% (28 B) | manager — body is mostly call setup |
| `0x8C0A1658` | 1176 B | 18 | 66 | — | indirect `jsr @r13` dispatch table |

`0x8C0C438E` is the cautionary one. It looks ideal on the gate scan — four
literal descriptor offsets and two register-loaded ones — but it immediately
calls eight helpers, so 433 of its 447 executed PCs were *inside callees* and
only 28 bytes of its own body ran. Descriptor offsets say nothing about this;
`jsr` count does.

The pointer-chasing distinction also turned out to be about **provenance, not
dereference**. `0x8C0C438E` chases `r10 = *(0x0C29BB84+44)` and dies there,
because that pointer word is a real game global the probe has no business
fabricating. `0x8C0C321E` chases `r14` just as hard, but `r14` is an *argument
register* — the probe simply sets it to a scratch page. Same instruction, one
seeds and one does not.

Three further corrections to the plan's assumptions, all found by running it:

1. **The descriptor base is often not seedable at all.** `0x8C05B20E` took `r13`
   from a register; `0x8C0C321E` and `0x8C09C1F4` take theirs from a *literal
   pool* (`mov.l <lit>,r13  # lit=0c29b864`), so the seed plan has to write the
   real global. `seed_plan.py` now supports absolute-address seeds for this.
2. **The oracle's `ram` directive is word-granular** and aborts the entire
   capture (not the probe) on an unaligned address, so a byte-granular
   descriptor read has to be seeded through its containing word.
3. **The gate words are usually already open.** `0x8C0C321E`'s first 31.1%
   arrived with no gate seed at all, because the live fight state left
   `*(0x0C29B864) & 0x300` set. Only the *closed* variants need seeding, and
   they are the early-exit arms — so a plan that forgets them silently loses
   whole exits rather than deep arms.

4. **Coverage must be re-measured per body.** Neither 98.3% nor 44.9% is a port
   on its own, and `body_cover.py --min-cover` now says which is which before
   the ledger does.

### The lever is blocked by seed calibration, not by the targets

Porting the sweep to `0x8C0C321E` ran into something bigger than a bad plan, and
it is recorded in full in `docs/re/entry_patch.md`:

- The mechanism works there — probes return complete capsules, no faults, no
  quarantine — and the natural live state alone reaches 490 B / **31.1%**.
- It stalled because **the values that open a gate are not the values the
  disassembly prints.** On `0x8C0C321E`, `lit.w=0300` leaves gate A shut and
  `0x0030` opens it; likewise `0x0018` for gate B and `0x0A00` for the `tst #10`
  on the argument object. With all three, a **single** probe goes from 14 PCs
  pinned at 31.1% to 1064 executed PCs and **560 B / 35.6%** before any
  sweeping.
- **The mechanism is not established.** `sh4dump` reads literal pools with a
  correct little-endian `struct.unpack`, and `tst #10,r0` is encoded as `0xC80A`
  whose imm8 really is `0x0A`. The printed and encoded immediates agree, and both
  disagree with the emulator. The three values are calibration constants to
  re-verify, not a rule to generalise.
- **A second, independent bug: `SCRATCH = 0x0C400000` is live RAM, not
  scratch.** The capsule from the 35.6% run shows that page's first word as
  `0x0c1a58a0`, a live code pointer. Every plan seeding "scratch" has been
  writing over live game heap, which is on its own enough to make seeds look
  inert. The constant must be re-chosen before any campaign is trusted.
- Two things that looked like causes were ruled out by measurement, not argument:
  the seed plumbing (a `VF3_SEED_DEBUG` dump at the target's first instruction
  shows `r0`, `r13` and `pr` landing exactly as seeded) and the operand cache
  (adding the missing `ocache.WriteBack` to the forward seed path and rebuilding
  changed the result not at all).
- So the current state of the lever is: **capture works; seeding works only after
  calibrating masks against a capture and moving off a live scratch page.**

The honest read of Phase 3 shrinks accordingly. What is banked is the harness
(opcode substitution, probe accounting, fault abort, budget, ocache-coherent
rollback), the triage, and one replay-clean capture. What is *not* banked is the
claim that descriptor sweeping walks branch space: that was never demonstrated,
and the flatline on `0x8C0C321E` is the first direct test of it.

**Next step is therefore not a new target, and not a new tool.** It is to
re-measure the masks and re-run. Concretely, in order of expected value:

1. **Re-run the pilot 0x8C05B20E with measured masks.** Its 3258-variant recipe
   was built from the same swapped immediates, so its 44.9% is unattributed.
   Re-running may well clear the 100% promotion gate, and it reuses an existing
   replay-clean adapter.
2. **Re-measure the masks in `gate_scan.py` output** for any other recipe
   before trusting it. The tool emits masks straight from the disassembly, so
   every plan derived from it inherits the swap.
3. Then resume the `0x8C0C321E` sweep (35.6% from one probe is a real
   starting point), and only then `0x8C09C1F4`.

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
   can carry a real object pointer instead of a fabricated one. Be clear about
   the size of this prize: it buys the 9 live-object instructions of
   `0x8C05B20E` — 44.9% -> ~46.3% of that body, not 44.9% -> 100%. It is worth
   doing for the whole pointer-chasing cluster, not as a fix for one function.
3. Scenarios that drive those states *naturally* (long play, specific matchup
   inputs) remain the only thing that could cover the wide branch space the
   descriptor sweep never selects. That is a capture problem, not a seed problem.
4. Done in this phase: `body_cover.py` now runs inside `tools/verify_all.py` as
   an advisory pass over the golden bindings, and `--strict` is the promotion
   gate. It cannot fail historical piecewise ports, which are bound to
   fragment-boundary corpora by design.

