# Plan to reach 65% verified C — 2026-10-10

Start at commit `65043ca`: **258,502 / 434,656 unique frozen-body bytes
(59.472778%)**. The goal is at least **282,527 bytes (65%)**, requiring
**24,025 additional verified bytes**. This is an execution objective, not a
claim that the research queue will qualify. Keep the existing denominator,
body ranges and address-union accounting unchanged.

| Checkpoint | Required verified union | Gain from this baseline |
| --- | ---: | ---: |
| 60% | 260,794 | 2,292 |
| 62.5% | 271,660 | 13,158 |
| 65% | 282,527 | 24,025 |

## Refreshed queue and evidence

`port_plan.py` was rerun against today's ledger. `family_queue.py` then
ranked 200 families, preserving previous triage exclusions and adding all
current `percentage_*/progress.json` exclusions. The resulting baseline is
exactly 258,502 bytes. The tracked [queue](coverage_65_queue.csv) preserves
the ranking, original callers, closure members and missing frozen intervals.
Its marginal values are sequential in that ranking; reordered subsets must
be remeasured against the actual accepted union.

| Ranked research pool | Advisory additional union |
| --- | ---: |
| First 10 families | 3,356 |
| First 25 | 9,438 |
| First 50 | 19,414 |
| First 100 | 35,490 |
| First 150 | 48,412 |
| First 200 | 60,780 |

Only three selected families have both zero unresolved dynamic sites and
complete frozen intervals, totaling 222 sequential marginal bytes. Reaching
65% needs about 40% of the expanded potential, or 68% of the first hundred.
Neither is an established acceptance rate. Unknown targets, missing intervals
and reused blocked dependencies remain explicit work.

Local regeneration artifacts under `extract/analysis/` are
`coverage_65_20261010_port_plan.csv`, `coverage_65_20261010_families.json`,
`coverage_65_20261010_watch.txt` and `coverage_65_20261010_provenance.json`.
The provenance records the full generation command and exclusions. The family
JSON SHA-256 is
`824d7e2850270386bcf069024ecc47a53e955754e83a3eaf4a8f2364ef462872`.

## Execution order

### 1. Qualify the existing audio callers; then close the 60% gap

Add explicit promotion contracts for table-dispatched entries and multiple
register saves, retaining the current direct-BSR contract. Require original
dispatch opcodes, the real loaded table and target, complete original prefix
execution, ordered stack saves/restores and unchanged callee-saved registers
and SP. Add negative checks for forged dispatch evidence, missing prefix
instructions, wrong save/restore order and altered targets. No fabricated
second caller or blanket prefix exemption.

Start with fight root `0x8c099060`, frozen owner `0x8c099070` (232 bytes).
Capture the original dispatcher at `0x8c0968d0` selecting real table
`0x0c10baa8`, index 55, slot `0x0c10bb84`. Existing patched full-root entry
captures prove the callable's behavior but do not prove that caller edge.
Use disjoint original caller scenarios and correlate the dispatched prefix,
target and stack evidence with the qualified full-body corpora. Validate the
contract before attempting promotion.

Then qualify input root `0x8c0c9f54`, frozen owner `0x8c0c9f62` (188 bytes),
through its real literal-loaded JSR at `0x8c0c920a`, pool `0x8c0c926c`.
Define and test a separate constant-target JSR attribution contract; one
genuine caller must remain one caller. Fresh qualification must meet the
promotion case/scenario requirements, even where older live pilot corpora
were smaller. Preserve previous frozen executables and proofs.

If both qualify, coverage becomes 258,922 bytes (about 59.57%); **1,872 bytes
still remain to 60%**. Continue with the bounded families below rather than
spending the campaign entirely on attribution tooling.

### 2. Unlock reusable callbacks and motion records

| First pilot | Advisory ranked gain | Contract to recover |
| --- | ---: | --- |
| `0x8c04fe9e` family | 1,002 | Original object callback table `0x0c1b34d4`, target +12, object +36, doubled R5 |
| `0x8c09d5ae` family | 536 | One-based actor +60, table `0x0c29b9f8`, twelve-byte records, VM at actor +0x1d00 |
| `0x8c0991a2` family | 488 | Actual scene caller state and indirect destinations; check audio dependency reuse |
| `0x8c0ca8da` family | 404 | Original caller inputs and four unresolved dynamic sites |
| `0x8c09af6c` family | 1,302 | Packed motion-record decoder and its actual indirect destinations |

These gains are research leads, not additive promises. Join each closure to
the retained triage ledger before running it. For each pilot, inspect original
disassembly, name every missing edge and collect one valid terminating input
from the original game. Implement readable shared C and the actual callback
targets; then expand callers only after the smallest pilot passes. The first
four are the initial route toward 60%; the packed decoder is the next larger
expansion lead.

Keep unbounded seed fragments out of promotion. Attribute their callable
entries to existing frozen owners where original evidence permits it; do not
enlarge the denominator or grant bytes for newly named helper fragments.
Rewrites of already credited encoder, request and submission code earn zero
new bytes.

### 3. Reach 62.5% through several shared contracts

After 60%, target another **10,866 accepted bytes**. Select families from
the first hundred using observed valid inputs, reusable dependencies and
remaining marginal union, rather than score alone. Prefer motion/VM commands,
object-pool callers and scene callbacks whose new helpers close multiple
roots. Work in tranches of roughly 2,000–4,000 accepted bytes; tranche size
is a scheduling goal, not a predicted yield.

When caller state is missing, first reuse natural-call capsules. If absent,
add bounded passive recording of original entry/prefix, return PC, registers,
stack arguments, accessed pages and indirect destinations, starting with one
family and at most 128 entries. Check observer-enabled execution against an
observer-disabled control. Use appropriate menu/front-to-fight playback when
fight states do not contain the scene. Observer infrastructure earns no bytes.

### 4. Finish the remaining 10,867 bytes to 65%

At 62.5%, recompute the queue against accepted spans and select enough
evidence-backed closures to cover the remaining gap with alternatives.
Expand into the second hundred only when a named caller/asset/device contract
has new evidence. The broad `0x8c0c182e` closure is a late option: its 2,638
ranked bytes involve 76 members and 23 unresolved sites, so split it into
independently terminating subsets before implementation.

Do not make standalone ARM7/DSP playback a prerequisite for this percentage
campaign. Existing scheduler-aware one-shot audio comparison can qualify
additional SH-4 callers. AICA firmware outside the frozen SH-4 inventory does
not contribute to this denominator. Keep song/reset semantics and standalone
playback as separate behavior milestones.

## Acceptance, stopping rules and delivery

Every new credited body needs complete frozen-body execution in both
development and acceptance, at least 64 distinct complete inputs in each,
two scenarios per corpus, disjoint states, changed acceptance inputs and
relocated writable objects. Freeze source and executable before acceptance.
Compare the full supported architectural state, RAM and ordered device
effects; audio crossings also require the established live-device comparison.
Require zero skips, original-opcode checks, artifact hashes and marginal-union
audit. A correction after acceptance starts requires fresh acceptance.

Give a stalled contract one new hypothesis and one targeted pilot per triage
pass. After two families stall for missing caller context, switch to original
caller discovery. Retain failed capsules and record the blocking PC/field/edge;
repeat a parked sweep only when new evidence addresses that blocker.

Run affected bindings, known reverse dependencies, native suites and tool
tests per tranche. At 60%, 62.5% and final delivery, run the entire current
binding inventory against the final executable, all native suites, all current
tool tests and the complete milestone hash-chain audit. Record any reuse
explicitly; old passing binaries do not validate changed C.

Store large captures in the established C-drive evidence cache, check available
space before expansion and retain the capture tool's 4 GiB output-drive reserve.
Never overwrite frozen source archives, executables or failed evidence.

Commit and push each accepted milestone with its C, recipes, proof manifests,
bindings and updated ledger. Report verified bytes, percentage and remaining
gap after each tranche. At checkpoints, reassess qualifying opportunity and
change the research order if acceptance yield is poor. Stop successfully only
when the audited union reaches at least 282,527 bytes and final regression
passes. This planning change itself adds **zero coverage bytes**.
