# Coverage expansion plan — 2026-10-08

## Objective and accounting

Advance verified unique C coverage from **248,754 / 434,656 (57.23%)** to
**at least 65%**: 282,527 bytes, a gain of **33,773 bytes / 7.77 percentage
points**. Stretch: add 43,466 bytes, reaching 292,220 bytes (**67.23%**).
These are campaign objectives, not forecasts of successful verification.
Finishing the previous target needs only 774 bytes and does not constitute
the substantial advance requested.

Keep the original image and frozen denominator unchanged. Count address
union, not function-size sums, SDK attribution, trace hits or generated C
volume. Report newly verified existing translations separately from newly
written readable C; both can supply verified coverage, but they represent
different progress toward the source-port goal.

## Measured opportunity

The refreshed roadmap uses the current ledger and machine-decoded call
inventory. It excludes credited roots and subtracts the covered address union.
It does **not** exclude all previously attempted or blocked roots, establish
valid caller contracts, or prove that static dependency edges are complete.

| Queue | Potential unique bytes | Meaning |
| --- | ---: | --- |
| 111 roots with existing C implementation closure | 10,640 | No known unresolved call boundary; captures and replay still required |
| First 25 ranked dependency families | 15,572 | Includes both straightforward roots and unresolved-call families |
| First 50 families | 30,770 | Cumulative potential, not accepted coverage |
| First 75 families | 43,628 | Barely exceeds the stretch gain before failures |
| First 100 families | 51,522 | Broader investigation pool with a failure allowance |

The queues overlap; their totals must not be added. The 100-family pool
would need about 66% of its potential accepted to reach 65%, and about 84%
to reach the stretch target. Expand discovery if development evidence does
not support those yields.

Reproducible advisory artifacts under `extract/analysis/`:
`percentage_20261008_port_plan.csv`,
`percentage_20261008_static_queue.json`,
`percentage_20261008_families.json`, and
`percentage_20261008_extended_families.json`.
The roadmap was regenerated with `tools/port_plan.py`; queue construction
uses `tools/oracle/campaign_queue.py` and `family_queue.rank_families` against
`tools/oracle/advance_coverage_baseline.json` and the current ledger.

## Execution sequence

1. **Triage before recapture.** Join the new queues with retained development
   manifests, replay failures and prior probe history. Classify each lead as
   ready for acceptance, missing branches, invalid caller contract, missing C
   dependency, unresolved indirect call, platform boundary or incomplete run.
   Record marginal bytes and the next experiment that can resolve its blocker.
   Recover true original callable entries rather than treating frozen interior
   labels as function prologues. Keep acceptance corpora out of discovery.

2. **Establish the first checkpoint at 60% (+12,040 bytes).** Work through
   retained complete bodies and the 111 implementation-closed roots first.
   Their entire 10,640-byte potential cannot reach 60% alone, so begin small
   dependency families alongside them. Initial inspection leads include
   `0x8c0609b8` (486 bytes), `0x8c0477a4` (366), and `0x8c094e8c` (336).
   Small static families include `0x8c040fa4` (786 marginal bytes, two members),
   helper `0x8c09493c` (760, four members), and `0x8c063d36` (512, two members).
   These are leads, not promises of easy gains. Preserve SDK provenance where
   relevant; SDK identity alone never satisfies a C dependency.

3. **Reach 62.5% (+22,906 cumulative bytes) through shared helpers.** Implement
   real callees in dependency order, then verify their callers as a family.
   Prefer readable C with documented object fields, table bounds and state
   transitions. Use static instruction adapters as comparison evidence and
   integration scaffolding. Re-rank after each accepted batch so overlapping
   families cannot inflate expected yield.

4. **Reach 65% (+33,773 cumulative bytes) by resolving selected boundaries.**
   Investigate families whose shared dependency unlocks multiple bodies.
   Current examples are `0x8c04b192` (1,864 marginal bytes, six members,
   three unresolved dynamic sites), helper `0x8c0c3982` (2,224, eight members,
   five sites), and helper `0x8c0a2e06` (4,300, thirty members, fourteen sites).
   Reconstruct original indirect targets and caller/object contracts before
   broad captures. Platform boundaries require explicit behavioral models
   and ordered device evidence. Generic successful-return stubs cannot close
   a family. Continue toward 67.23% only with qualifying additional bodies.

## Verification and throughput

For each newly credited root, require complete frozen-body execution,
at least 64 distinct complete development inputs across two scenarios,
and strict replay of architecture, captured RAM and ordered device events
with zero skips. Require independent acceptance with at least 64 distinct
inputs across two disjoint scenarios, changed inputs and relocated writable
objects. Freeze the executable before acceptance. Acceptance failures block
promotion; any implementation correction requires fresh acceptance.
Apply callable-body attribution only where its original-image checks pass.

Accept and commit manageable family milestones, typically 2–5 KiB when the
candidate supply allows it. Hash-audit each promotion and run affected replay
and native checks. Run the full binding regression and milestone-chain union
audit at the percentage checkpoints and at campaign completion. Do not repeat
the entire long gate after every exploratory capture.

Give each blocked family one explicit hypothesis and one bounded pilot per
triage pass. If the pilot does not improve complete-body evidence, park it
with the measured blocker and proceed to another family. In particular,
`0x8c0c8334` still needs the live-stack double-dereference zero path;
`0x8c05cc38` still has invalid-pointer taken branches. Repeating broad fuzz
without a new contract is not the proposed route to a large gain.

Free space measured on E: is about **4.9 GiB**, despite the additional space
reported earlier. Start with retained evidence and bounded captures. Estimate
storage from each pilot, enforce the capture reserve, retain original capsules
and bound proof artifacts, and remove only proven rebuildable unbound caches
through the existing journaled tooling. A 20–30 GiB free working budget is a
planning allowance for larger batches, not a measured requirement. If space
stays constrained, use smaller batches and avoid duplicate RAM shadows.

## Completion report

Publish accepted unique-byte gains, resulting percentage, readable C modules,
independent proof manifests, integrated regression results, and unresolved
blockers. Do not claim the campaign target from queue potential or partial
body coverage. Revise the scope after the first checkpoint using actual
acceptance yield; no defensible elapsed-time estimate exists yet.
