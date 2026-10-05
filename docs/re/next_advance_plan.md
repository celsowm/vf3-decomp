# Next substantial C coverage campaign

Prepared 2026-10-04 at `a280c4d`.

For execution after `70dcb1f`, use [the continuation plan](advance_continuation_plan.md).
The figures and candidate states below describe the initial campaign snapshot;
the current ledger is [advance_progress.md](advance_progress.md).

## Objective and current evidence

Target another **+10 percentage points of verified readable C**, from
**206,062 / 434,656 bytes (47.4081%)** to at least
**249,528 bytes (57.4082%)**. This requires **43,466 new unique bytes**.
The target is a campaign objective, not a forecast of available easy wins.

| Checkpoint | Minimum C address union | New unique bytes |
|---|---:|---:|
| +2 points | 214,756 | 8,694 |
| +5 points | 227,795 | 21,733 |
| +10 points | 249,528 | 43,466 |

`decomp_stats.py` currently reports 54.9% rigorous C+SDK accounting. That
includes library attribution and must not replace the C address union above.
Its legacy C size sum is 206,940 bytes; 878 overlapping bytes are excluded.

The refreshed `extract/analysis/port_plan_next_advance.csv` contains:

| Queue | Functions | Raw body bytes |
|---|---:|---:|
| A: hot, unaccounted | 13 | 2,430 |
| B: observed, unaccounted | 107 | 26,102 |
| C: not observed, unaccounted | 1,167 | 170,622 |

These are inventory sums, not prospective union credit. The A+B ceiling is
already below the objective, even before overlap and failed proof. New scenario
coverage or actual C implementations of attributed library bodies are necessary.
The plan's observation field is historical; it is not complete invocation proof.

The old `remaining_work_plan.md` predates the completed ten-point campaign.
Use its investigations as leads, not its coverage totals or promotion rules.
The old large prizes `0x8c0750be`, `0x8c076c00`, and `0x8c0782ea` are already
ported and cannot contribute another gain.

## Phase 0: freeze and rank the next campaign

1. Audit the existing milestone series with artifact hashes. Freeze the current
   C union, image, inventory and body-range hashes in a separate campaign baseline.
   Preserve the completed ten-point baseline and proof manifests.
2. Parameterize `promote_tenpp_batch.py` to select the campaign baseline; it
   currently reads `tenpp_coverage_baseline.json` directly. Keep the existing
   baseline as its default. Use a distinct milestone filename prefix so
   `audit_series.py --baseline ... --pattern ...` selects the new chain.
3. Produce a deduplicated development corpus and rank marginal address-union
   gains against the new baseline. Record per entry: body gaps, distinct inputs,
   provenance, missing memory windows, unresolved callees, and replay failures.
   Existing candidate JSON files are historical snapshots and require rechecking.
4. Build a dependency graph from the original image, including gap regions and
   unresolved indirect calls. SDK attribution alone does not supply an executable
   C callee. Rank families by callers unlocked and marginal union bytes, rather
   than entry count or the size of a single wrapper.

Deliverables: frozen baseline, ranked queue and initial watch lists. No coverage
gain is claimed during preparation.

## Phase 1: finish existing body gaps

The reusable `capture_report.py` produced
`extract/analysis/next_advance_gaps.json` from three existing development roots.
The leading uncredited candidates are:

| Entry | Body bytes | Executed bytes | Missing bytes | Distinct cases |
|---|---:|---:|---:|---:|
| `0x8c04a4c4` | 506 | 500 | 6 | 852 |
| `0x8c0877ac` | 280 | 272 | 8 | 1,970 |
| `0x8c0c8334` | 638 | 624 | 14 | 1,583 |
| `0x8c0c051a` | 506 | 424 | 82 | 1,023 |
| `0x8c0c0772` | 990 | 874 | 116 | 2,045 |
| `0x8c07dd04` | 714 | 558 | 156 | 562 |
| `0x8c0a67ce` | 640 | 424 | 216 | 2,036 |
| `0x8c05cc38` | 1,290 | 1,072 | 218 | 1,287 |

Each listed corpus has two source scenarios. Counts are per corpus; they cannot
be summed across runs. The eight bodies total **5,564 raw bytes**, at most about
1.28 points before union overlap. This is a starting batch, not the whole target.

For each gap, inspect original annotated disassembly and the preceding branch.
Determine whether the missing PCs belong to a real path, an alternate entry, or
an inventory boundary problem before generating additional fixtures. Build
documented fixtures from the original memory contract, exercise boundary values
and alternate paths, and merge new cases with preserved provenance. Do not
rewrite executable instructions or literal pools to satisfy a coverage gate.

Start with the three smallest gaps, then `0x8c0c051a` and `0x8c0c0772`.
Stop a fixture approach after two well-founded attempts produce no new PCs;
record the blocker and move to the next family. Keep blocked entries in the queue.

## Phase 2: close shared dependencies in observed families

The refreshed A+B queues have these largest address groups:

| Page | Functions | Raw bytes |
|---|---:|---:|
| `0x8c09` | 13 | 5,802 |
| `0x8c05` | 7 | 3,898 |
| `0x8c06` | 10 | 3,840 |
| `0x8c0a` | 18 | 3,246 |
| `0x8c04` | 19 | 3,046 |
| `0x8c03` | 15 | 2,752 |

Pages locate families; they do not establish shared semantics. Reorder the
actual work using the dependency graph from Phase 0.

Start a bounded capture/replay pilot on `0x8c0609b8` (486 bytes), whose refreshed
static closure screen passes. Investigate `0x8c064246` (508 bytes, 292,992 hits)
and `0x8c09575c` (1,780 bytes, 19 unresolved dynamic call sites) for reusable
callee implementations and dispatch-table contracts. The latter is a family
milestone after its dependencies close.

Revisit `0x8c09635a` (616 bytes) with memory windows chosen from actual failing
reads. More windows are useful only when they include the required addresses.
For indirect dispatch, capture table initialization and original destinations;
implement the reachable helpers and reject unknown destinations.

Do not adopt the old plan's `entry == 0` success stub. A null call, unsupported
helper, trap or out-of-window read needs evidence and modeled behavior before
strict replay can accept it. Similarly, select fixture storage only after
checking ownership, lifetime and aliasing; an arbitrary apparently quiet page
does not establish a valid object contract.

Work toward the +2 and +5 checkpoints through independently promotable batches.
All queue byte totals overlap potentially with Phase 1 and are not additive.

## Phase 3: expand the executed universe early

Begin this phase after the first near-gap batch, before the old queue runs out.
Exercise distinct original game states: additional character/match combinations,
attract/demo, training, replay, character selection, and available menu paths.
First confirm which modes and savestates are usable; do not assume all exist.

Use a broad discovery watch for unported entries, then targeted paired captures
for the best families. Retain registers, RAM, FR/XF and entry-to-return or
documented transfer boundaries as required by each body. Preserve original
dispatch initialization so captures represent coherent runtime objects.

Initial unexplored leads include `0x8c09c1f4` (2,084 bytes), `0x8c0831f8`
(1,964), `0x8c08231c` (1,892), and `0x8c0c321e` (1,574). These are static leads,
not promised yields. Confirm genuine paths and helper closure before extensive
seed sweeps. Keep the parked `0x8c05b20e` behind its live-object blocker until
a valid original runtime object reaches the missing path.

After every discovery tranche, rerank by new marginal C bytes and dependencies
unlocked. Aim to maintain a **60,000-byte marginal candidate pool** for the
43,466-byte objective. This is a planning buffer, not proof that the pool exists.
If discovery yield is low, change scenarios or family rather than increasing
random variants of the same blocked fixture.

## Phase 4: library bodies as a measured fallback

Attribution currently accounts for original bodies without readable C ports.
Implementing these bodies can increase C coverage, but matching another SDK
archive cannot. Pilot one coherent library family with a supported capture
contract, original-image behavior analysis and independently derived readable C.
Apply the same body and strict replay gates as game code.

Proceed only if the pilot demonstrates usable input diversity, complete body
execution and practical helper closure. Resolve any clean-room/source provenance
constraint before using reference source. Reserve hardware and asynchronous
services for capture contracts that actually model their state. Do not forecast
the entire attributed byte bucket as available gain.

## Promotion and milestone gates

For every new credited body:

- Frozen original body intervals, with complete development execution.
- At least 64 distinct complete development inputs across two source scenarios.
- Documented fixture and memory contracts, with failures and nondeterminism excluded.
- Strict complete-state replay of every selected development and acceptance case,
  zero skipped cases, using an immutable executable snapshot.
- Independent acceptance with changed inputs and relocated fixtures where valid;
  acceptance cases do not drive implementation changes.
- Proof manifest, artifact hashes, golden binding and ledger update.
- Successful CMake build, repository regression and milestone-chain audit.

Commit each accepted batch. Update the union and remaining shortfall after each
promotion. Generated C is a draft: review control flow and field contracts,
reuse semantic helpers, and give newly understood operations meaningful names.
Unsupported exploratory code receives no credit.

## Reusable execution workflow

Use `watch_union.py`, `isolate_planned.py`, `merge_batches.py --discover`,
`capture_report.py`, `translate_adapters.py`, `verify_matrix.py --executable`,
`promote_tenpp_batch.py`, `audit_series.py` and `campaign_status.py`.
Add recurring analysis operations as tool subcommands rather than inline Python.
Emulator captures remain serial because they share staged states.

Commands already used for this planning snapshot:

```powershell
python tools/decomp_stats.py
python tools/port_plan.py --out extract/analysis/port_plan_next_advance.csv
python tools/oracle/capture_report.py extract/analysis/tenpp_large_random_dev extract/analysis/tenpp_expanded_near_dev extract/analysis/tenpp_boundary_third_dev --limit 25 --out extract/analysis/next_advance_gaps.json
```

First implementation actions: audit and freeze the baseline, parameterize
promotion, merge evidence for the three smallest gaps, inspect their missing
branches, and produce the first focused capture recipes. Planning itself has
not added C bytes or run new emulator captures.
