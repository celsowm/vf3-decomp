# Reusable capture and coverage tools

The ten-point coverage session repeatedly used inline Python for directory
discovery, watch lists, body-gap ranking, proof audits, and progress summaries.
Those operations now have standard-library commands. Run these from the repository
root. Reports are advisory; promotion still goes through `promote_tenpp_batch.py`
and the existing strict replay and independent acceptance gates.

## Combine capture roots

```powershell
python tools/oracle/watch_union.py tools/watch/vf3_tenpp_medium_roots.txt tools/watch/vf3_tenpp_recovery_roots.txt --entry 8c05dfe6 --out extract/analysis/next_roots.txt
```

`--exclude FILE` subtracts PC roots from another watch file. Both flags are
repeatable. Addresses normalize to the cached SH-4 address space, duplicates are
removed, and output is sorted. Other watch directives are intentionally omitted:
this command generates PC root lists. Read inputs before writing output, so updating
an existing watch in place is supported.

## Discover and merge isolated captures

```powershell
python tools/oracle/merge_batches.py extract/analysis/tenpp_fragment_final --discover --watch extract/analysis/next_roots.txt --out extract/analysis/next_cases
```

`--discover` accepts parent directories or exact `batch_manifest.json` files,
deduplicates their paths, and fails if an input has no batch manifests. Existing
merge behavior still checks capture failures and all capsule records, deduplicates
inputs, and preserves provenance. Use a fresh output directory. Do not merge an
output nested inside an input parent on subsequent runs.

`tenpp_candidates.py` also uses shared discovery. Its `--merge` skips writing a
corpus when no candidates were found. Candidate selection requires whole-body
development execution; independent acceptance keeps its existing invocation gate.

## Inspect body gaps and scenario coverage

```powershell
python tools/oracle/capture_report.py extract/analysis/next_cases --watch extract/analysis/next_roots.txt --out extract/analysis/next_gaps.json
```

Parents and exact `capsule_manifest.json` paths also work. Results rank bodies
with the fewest missing PCs first, then largest body size. Printed rows include
the first eight missing PCs; JSON retains all PCs and exclusion reasons.
`--limit` controls printed rows. `--include-credited` includes already ported roots.

Distinct input counts come from each converted corpus manifest. They are never
summed across corpora, where inputs could overlap; merge first for a combined
count. Scenarios derive from each record's source provenance. Unknown sources,
incomplete invocations, failed captures, quarantined entries, missing bodies,
fewer than 64 inputs, and fewer than two scenarios are reported. Strict replay
and independent acceptance remain separate requirements.

## Audit the complete milestone chain

```powershell
python tools/oracle/audit_series.py --hashes --jobs 4 --out extract/analysis/tenpp_series_audit.json
```

Defaults select the frozen ten-point baseline and its milestone manifests.
`--baseline FILE` and `--pattern GLOB` select another compatible series. The tool
checks frozen inventory/body/image hashes, the cumulative interval union, the chain
of byte totals, the denominator, and duplicate new entries, then invokes
`audit_matrix_batch.py` for every milestone.
That audit verifies proof bindings and interval-union credit; `--hashes` additionally
rehashes archived specimen artifacts. Every invocation audits every selected
milestone again. A failed audit produces a nonzero exit status.

`--jobs` permits one to four concurrent audit subprocesses. These are read-only
audits; emulator captures must remain serial because they share staged savestates.
The JSON report is updated after each audit and includes stdout, stderr, completion,
target status, and percentage-point gain. Target status and audit success are
reported separately, so shorter completed series remain inspectable.

## Read campaign progress

```powershell
python tools/oracle/campaign_status.py extract/analysis/tenpp_fragment_final extract/analysis/tenpp_fragment_final_replay.json extract/analysis/tenpp_series_audit.json
```

Accepts isolated capture directories (`progress.json`), replay JSON from
`verify_matrix.py`, and series audit JSON. Capture progress reports attempts and
case totals, not deduplicated coverage. Replay status describes entries present
in the report; it cannot infer completion of a running replay. Missing or partially
written JSON and recorded failures produce a nonzero exit status; rerun after the
writer finishes updating the file.

## Existing reusable RE steps

Keep using `isolate_planned.py` for serial capture campaigns, `sh4dump.py` for
annotated disassembly, `translate_adapters.py` for adapter generation,
`verify_matrix.py --executable` for replay against an immutable executable copy,
and `promote_tenpp_batch.py` for frozen promotion evidence. The shared
`campaign_io.py` provides discovery and watch I/O for future tools. No new
dependencies are required.

## Start another coverage campaign

Refresh `decomp_stats.py`, then freeze a separate baseline with
`freeze_campaign.py --out tools/oracle/advance_coverage_baseline.json`. The command
refuses overwrite and checks original artifact hashes and the current ledger
against the dashboard. `promote_tenpp_batch.py --baseline FILE` selects that
baseline while preserving its original default.

`campaign_queue.py --plan PLAN.csv --baseline BASELINE.json --out QUEUE.json
--watch ROOTS.txt` ranks unported bodies by dynamic-call count and marginal
address-union bytes. `--min-dynamic`, `--max-dynamic`, `--minimum-size` and
`--limit` bound a cohort. Queue totals are prospective and never grant credit.
`--exclude-watch FILE` omits previously attempted roots; it is repeatable.

`capture_report.py --ready-watch ROOTS.txt` exports entries passing capture
gates in at least one input corpus. Select compatible corpora when merging:
other captures of the same entry can still contain incomplete invocations.
Strict replay and independent acceptance remain required after capture gates.
`--merge-ready DIRECTORY` collects only eligible roots and their compatible
source corpora, checks the raw records again and preserves their provenance.
Unrelated quarantined entries remain in the original evidence, outside the
filtered development corpus.

`campaign_io.py WATCH... --out ROOTS.txt` forms a canonical deduplicated watch
union. `survey_coverage.py --watch ROOTS.txt --minimum-hits N` exports observed
unported roots for natural capture; hit counts remain advisory.

`capture_report.py --retry-watch ROOTS.txt` selects varied, complete-body entries
whose only blockers are capture completion or incomplete invocations. Recapture
them with a larger frame budget; do not drop the incomplete records from a proof.

`isolate_planned.py --group-size N` batches up to 64 roots per fresh state while
retaining serial emulator execution. The default remains one root. `--start` and
`--limit` count roots, and progress records list every member of a group. Increase
the frame budget to finish all variants; grouped captures have the same proof
gates as isolated captures. A STOP file pauses between groups.

`promote_tenpp_batch.py --port-map MAP.json` accepts an entry-to-source ownership
map for existing shared helpers. Unmapped entries use `--port`; every selected
source must exist. The ledger, replay binding and milestone record retain the
actual source owner.
