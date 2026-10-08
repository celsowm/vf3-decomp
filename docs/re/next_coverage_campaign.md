# Next coverage campaign — 2026-10-08

## Objective

Start from **253,834 / 434,656 verified unique bytes (58.40%)**, commit
`ede49be`. Reach **65%**, then pursue the existing **67.23%** stretch
objective if qualifying families remain. The previous campaign's 5,080-byte
gain is already in this baseline and must not be counted again.

| Checkpoint | Required union | Additional bytes from this baseline |
| --- | ---: | ---: |
| 60% | 260,794 | 6,960 |
| 62.5% | 271,660 | 17,826 |
| 65% | 282,527 | 28,693 |
| Existing stretch (292,220 bytes, about 67.23%) | 292,220 | 38,386 |

These are objectives, not forecasts. The source-port goal also requires
readable C: report semantic rewrites separately from newly verified bytes.
Rewriting an already credited adapter earns no additional coverage.

## Refreshed opportunity and its limits

Regenerated `port_plan.py` against the current ledger, then ranked 100
dependency families while excluding roots from **69 retained percentage
capture progress files**. The result starts at the correct 253,834-byte union.
It contains **44,990 potential additional unique bytes**. Its cumulative
marginal totals are 5,492 bytes for ten families, 9,994 for 25, 25,574 for 50,
and 33,042 for 75. Those totals account for overlap within this ranking.

This is an investigation pool, not a qualified backlog. Exclusion applies to
recorded roots, not every dependency or every historical watch. Previously
blocked bodies can reappear as dependencies or through incomplete history.
Join the queue to the campaign ledger before selecting work. Static call
counts can include unresolved entry/ownership problems; recover the original
callable body before interpreting them as actual runtime boundaries.

Only six ranked families have zero unresolved dynamic sites; together they
offer **1,600 marginal bytes**, well short of the first checkpoint. The full
pool would need roughly **64% acceptance yield** to reach 65%, much higher
than the previous generic pilots support. Larger gains require better caller
contracts and new shared implementations, rather than another generic sweep.

Advisory artifacts under `extract/analysis/`:
`percentage_next_port_plan.csv`, `percentage_next_families.json`, and
`percentage_next_families_watch.txt`. The family JSON SHA-256 at planning is
`b97f2b8a2e5db1574001e4d13b5fc698fed5a4c68cc12913d3adbfda8224c9ce`.
Regenerate in PowerShell from the repository root:

```powershell
python tools/port_plan.py --out extract/analysis/percentage_next_port_plan.csv
$priorProgress = @(Get-ChildItem extract/analysis -Directory -Filter 'percentage*' |
    ForEach-Object { Join-Path $_.FullName 'progress.json' } |
    Where-Object { Test-Path -LiteralPath $_ })
$queueArgs = @('tools/oracle/family_queue.py',
    '--plan','extract/analysis/percentage_next_port_plan.csv',
    '--baseline','tools/oracle/advance_coverage_baseline.json',
    '--out','extract/analysis/percentage_next_families.json',
    '--watch','extract/analysis/percentage_next_families_watch.txt',
    '--limit','100')
foreach ($progressPath in $priorProgress) {
    $queueArgs += @('--exclude-progress',$progressPath)
}
python @queueArgs
```

## Work order

1. **Recover contracts before broad capture.** For each selected family,
   record the original callable prefix, real caller, register/stack inputs,
   object sizes, pointer chains, immutable table sources, indirect targets,
   and the specific missing predicate. Use original disassembly and real
   entry observations; if existing captures lack those observations, add
   bounded call-entry recording to the oracle. Do not patch executable code
   or infer expected outputs into fixtures. Keep development and acceptance
   inputs separate. Track marginal bytes, experiment and result in a durable
   triage ledger; reject historical blockers unless there is a new hypothesis.

2. **Extend the proven motion contract.** Inspect original entries around
   `0x8c09517a`, `0x8c0951d2`, `0x8c0951e4`, `0x8c09528c` and `0x8c0952a4`.
   Establish style-8/21 model references, loop termination and the real render
   helper contracts using the accepted descriptor-chain work. Separate pure
   motion updates from calls that reach hardware. The previously partial
   `0x8c09518c` entry stays uncredited until its original callable attribution
   and complete body pass. Translate accepted motion scaffolding into readable
   object/descriptor operations as a separate quality milestone. This tranche
   has no promised byte allocation before body-union and contract inspection.

3. **Close small shared families toward 60%.** First inspect roots
   `0x8c058a5c` (488 marginal bytes, two members) and `0x8c05f294`
   (236, two members), then helper `0x8c056c66` (564, thirteen members).
   These are refreshed advisory leads with zero unresolved dynamic sites,
   not established caller contracts. Implement missing helpers in dependency
   order and verify real callers together. Continue with low-boundary families
   such as helper `0x8c0ca05c` (492 bytes, six members, two unresolved sites)
   only after identifying its targets. Re-rank after every accepted tranche.

4. **Develop larger families toward 62.5% and 65%.** Investigate one shared
   boundary at a time. Refreshed leads include `0x8c04453a` (1,124 marginal
   bytes, fifteen members, thirteen unresolved sites), `0x8c04c47c` (1,194,
   twenty-four members, thirteen sites), and `0x8c04cece` (5,852, fifty-one
   members, ninety-six sites). These numbers are incremental in the frozen
   ranking, not independent gains to add to other queues. Begin with the
   smallest real caller subset; establish target ownership and valid objects
   before implementing an entire family. Promote readable helpers and expand
   outward only when the pilot closes a real boundary. The formatter at
   `0x8c04b192` and matrix helper at `0x8c0c3982` remain alternatives only with
   new stack/callback contracts. Do not reopen `0x8c0a2e06` on generic inputs.

5. **Investigate the audio scheduler as a separate enabling milestone.**
   Inventory state mutated by scheduler callbacks, ARM7, DSP, DMA and AICA
   timers. Determine whether a full emulator snapshot/restore can preserve
   that state and ordered interactions, or whether deterministic replay from
   an original saved state is required. Build a short differential pilot with
   restore checks and negative controls before permitting longer probes.
   The current sound-RAM journal must continue rejecting scheduler crossings.
   Revisit `0x8c040fa4` only after the wider model passes; successful RAM
   stores alone cannot validate it. This work has **zero coverage credit**
   until actual C bodies qualify, and must not block the motion/shared-helper
   work if the pilot cannot establish safe isolation.

## Bounded experiments and decision points

The first execution batch is contract inspection for the two small roots and
the motion siblings, followed by one small development pilot for each viable
contract. Use 64–128 pilot variants over two development scenarios; measure
completion, new executed body bytes, strict replay failures and storage.
These pilots are diagnostic, not acceptance evidence. Expand only a pilot
that completes original calls and materially closes the missing predicates.

Give a stalled contract one explicit hypothesis and one bounded pilot per
triage pass. Record failures and move on if it produces no new evidence.
Do not reopen the impossible-looking branches at `0x8c0853fe` or
`0x8c0c15f8`, the text wrappers' invalid callback paths, or loaded-state sweeps
without a specific new explanation. Keep the fixed denominator and full-body
rule. No dead-code exemption, generic return stub or SDK label closes a body.

After the first three contract pilots, report actual acceptance yield and
rerank the remaining pool. At 60%, reassess whether the remaining qualified
opportunity supports 65%; if it does not, expand original caller discovery
and record the shortfall instead of representing queue potential as progress.
There is no supported time estimate or guarantee of reaching the target.

## Verification, storage and delivery

Retain the established gates for every newly credited body: complete frozen
body in both corpora; at least 64 distinct complete inputs across two
development scenarios and two disjoint acceptance scenarios; changed holdout
inputs and relocated writable objects; executable frozen before acceptance;
strict architecture, RAM and ordered-device replay with zero skips. An
implementation correction requires fresh acceptance. Hash-audit every
promotion and its union delta.

Commit each accepted family with its C, recipes, proof bindings and ledger.
Run native checks and the current executable's affected bindings, including
known reverse dependencies, per tranche. Run the **entire current binding
inventory against the current executable** at percentage checkpoints and at
campaign completion, along with the milestone-chain audit. The previous
1,295-binding frozen run and 53-binding affected run remain historical evidence,
not substitutes for that final integrated gate. Include the fifty existing
campaign/audit tests and any new platform tests appropriate to the changes.

Measured E: free space at planning is **24.72 GiB** (26,544,975,872 bytes).
Keep the 4 GiB capture reserve, estimate batch size from pilots, and retain
bound proofs and original capsules. Do not delete raw failures to manufacture
a successful corpus. Stop oversized captures before exhausting the reserve.

For each checkpoint publish accepted union and percentage, readable C work,
newly verified existing C, full-body evidence, current regression scope,
remaining target bytes and parked blockers. Planning itself earns no coverage.
Execution of this next campaign has not started.
