# Fight worker and shared-helper batch

## Delivered coverage (2026-09-29)

| Measure | Before | After | Gain |
|---|---:|---:|---:|
| Verified C address union | 28,538 B | 48,220 B | **19,682 B** |
| C union / frozen 434,656 B denominator | 6.57% | 11.09% | 4.53 percentage points |
| Ported baseline entries | 80 | 116 | 36 |
| Ported + SDK accounted entries | 348 | 383 | 35 |

The gain exceeds the 15,000-byte target by 4,682 bytes. New ledger bodies sum
to 20,118 bytes; 436 overlapping bytes are removed from the incremental union.
One newly ported 14-byte entry was already SDK attributed, so the combined
accounted count increases by 35. SDK attribution adds no new C-byte credit.

The 55 new strict bindings pass **18,523 distinct complete cases**, with zero
skips and out-of-bounds accesses. They include 36 newly credited baseline entries
and 19 off-baseline helper registrations without additional byte credit.
Each binding has at least 64 cases across at least two distinct state/input
scenarios; repeated captures of the same scenario count once for this threshold.

The previously incomplete `0x8C0C678E` mesh worker now passes 414/414 release
cases, including full registers, FR/XF, FPUL, GBR, exact return PC and touched
RAM. Its ledger row replaces the historical incomplete claim. The older
`c678e.c` model remains a research artifact and is not used by the new dispatcher.

## Final evidence

The release corpus combines **13 captures**: eleven saved-state runs and two
boot schedules. Capture time is 454.399 seconds, producing 4,686,593,556 capsule
bytes; these figures exclude conversion, implementation and verification.
All capture processes exited successfully. Shutdown summaries account for
36,177 started invocations: 36,173 completed and four unfinished. Entries with
unfinished invocations are withheld. Interrupt/device/overflow/asynchronous-copy
samples are rejected and retained in the ignored capture manifests.

Development uses states 7, 30 and 37, with expanded captures from 7 and 37.
Held-out runs use states 10, 24 and 44 plus a boot schedule shifted by 240 frames.
Fresh final states 12, 35 and 43 were captured after the adapter implementation
was frozen. The release discovery passes 55/62 sufficiently sampled entries;
fresh discovery passes 63/70 entries. All seven failing entries are uncredited.
Every valid release case for each selected entry passes, including all earlier
development and held-out cases after input deduplication.

The standard verification gate, corpus SHA-256 audits, eight capture-integrity
checks, five planner/opcode checks, 212,992 arithmetic cases and existing
regression bindings pass. Historical narrower bindings retain their documented
skips and boundaries; they are not reclassified as complete invocations.

```powershell
python -m unittest discover -s tests -p test_batch_pipeline.py
python -m unittest discover -s tests -p test_capsules.py
python tools/oracle/audit_matrix_batch.py --manifest tools/oracle/fight_batch.json --hashes
python tools/verify_all.py --no-build
```

Regeneration from the development corpora reproduces the router and all four
adapter source files exactly. The original matrix adapter remains unchanged.

```powershell
python tools/oracle/translate_adapters.py extract/analysis/fight_dev_cases extract/analysis/fight_extended_cases --watch tools/watch/vf3_fight_batch.txt --function vf3_fight_adapter --reuse-matrix --split-size 12000 --out extract/analysis/fight_regenerated.c
```

## Remaining limits

`0x8C0750BE` has only one eligible release invocation and receives no credit.
`0x8C072B50` still reaches unsupported context-switch code. Entries `0x8C08BB26`,
`0x8C0926CC`, `0x8C0927FA`, `0x8C09635A`, `0x8C0CB9F0` and `0x8C0CBB6A`
have unresolved callback paths and are withheld in full. Failure details and
unfinished entries are recorded in `tools/oracle/fight_batch.json`.

Shared angle and mesh algorithms are readable C. Caller adapters retain per-PC
labels and still require high-level restructuring. Coverage establishes exact
agreement with the interpreter for the recorded scenarios and supported
single-precision modes; it does not prove all inputs or hardware accuracy.

## Target and starting point

Starting verified C union: **28,538 bytes**, frozen denominator **434,656 bytes**.
Delivery requires at least **15,000 newly verified unique bytes** (43,538 total).
Candidate body ranges contain 16,964 primary bytes and 24,390 with reserves;
these forecasts are not coverage credit.

## Pipeline milestone

The previous matrix audit now stores its starting address spans. Future ledger
growth cannot change that historical comparison. Verification and dependency
planning load all tracked `*_batch.json` manifests.

Dependency cost follows original-image control flow beyond fragmented Ghidra
seeds, includes transitive static calls and tails, and charges for unresolved
destinations. Three synthetic checks cover long helpers, tail boundaries and
unresolved indirect calls. Eight existing capture-integrity checks still pass.

Adapter generation accepts explicit roots and a named output module. Matrix
generation retains its defaults and reproduces the prior source SHA-256 exactly:
`f090b61ba8ddfc76d033aec40c2cc4a8001f92186c23fedd61ed2dd3c2f689cf`.
Separate modules reuse known matrix code; ownership is chosen before execution.

Development watches primary callers, reserve callers and required helpers.
Runs use states 7, 30 and 37 plus the 4,800-frame boot-mix input. Held-out runs
use states 10, 24 and 44 and a boot schedule shifted by 240 frames.
No first-transfer exits are configured. Interrupted, device-dependent and
overflow specimens are excluded; unfinished invocations are accounted separately.

No new C-byte credit is claimed by this enabling milestone.

## Worker and helper implementation milestone

Added static caller adapters for original-image code and hand-written angle
lookup and mesh-cell algorithms. The mesh worker reads the real cell table,
walks linked records and calls the classifier; it uses no stubbed node values.
The angle kernel reads the game's complete atan ramp from mapped RAM.

The new adapters are split into four source files at return boundaries.
Whole root control flow takes precedence over fragmented Ghidra seeds, fixing
a copy helper whose jump table previously crossed adapter ownership.
Architecture-specific banked-register code and foreign dynamically installed
code remain unsupported. Failed execution never retries another module.

Build and all existing port regressions pass. The combined ten-run discovery
corpus passes 54/61 entries with at least 64 cases. The seven failing entries
are withheld, along with smaller corpora that do not meet promotion thresholds.
Fresh states 12, 35 and 43 are reserved for the final acceptance check.

The 5,432-byte `0x8C0750BE` worker has only one eligible invocation across the
first four development runs; fifteen other samples touch device memory.
Its body receives no credit. Captures therefore also watch the 65 executed,
unported baseline entries of at least 200 bytes, extending the reserve pool.
Final ledger promotion waits for the complete release replay and byte audit.
