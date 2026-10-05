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

`isolate_planned.py --preserve-fields` varies register inputs without rotating
the inferred typed memory fixtures. Use `--register-overrides JSON` when a
register holds a scalar index that the memory analyzer inferred as a pointer;
each entry maps register names such as `r0` to a fixed uint32 value or a cyclic
list of values. Use `--memory-overrides JSON` to set aligned RAM words after
fixture generation, including pointers read from global image data and the
objects they reference. RAM addresses and pointer-valued words in the fixture
pool relocate together for held-out runs. Explicit register override values are
literal; provide the already-relocated pointer value when using `--relocation`.
Both override maps accept decimal or `0x` strings and cyclic value lists.
`--play FILE` runs a repository-relative Flycast input script with each selected
state, so scenario provenance includes both the savestate and input script.
These options change probe inputs only; captures and strict replay remain the
promotion evidence.

When a root fails a branch gate, `isolate_planned.py --observe-watch FILE`
records nested helper invocations in the same capsule. Use
`inspect_capsule.py CAPSULE --entry PC --summary r0 r1` to count each helper's
input/output register tuple without dumping every architectural snapshot. Add
`--memory-summary 0xADDR ...` to count distinct initial aligned RAM-word tuples;
this is useful for checking that planned selector overrides actually reached
the invocation fixture. Combine it with `--ops-presence PC` to group field
tuples by whether a branch PC ran, or use `--require-ops PC` to inspect only
invocations containing a selected instruction.

`build_snapshot.py --out build/NAME.exe` builds the core and links a separate
matrix replay executable with the configured GCC/Clang compiler. It refuses
overwrite and leaves live regression executables in place. New replay reports
retain the executable path and SHA-256; hash audits verify that binary too.
When replacing an older proof executable, rerun the same corpus against a new
snapshot and use `rebind_milestone_proofs.py MANIFEST REPORT...` to refresh the
manifest only after confirming each report is strict, hashed and uses the same
corpus path.
Set `VF3_REPLAY_OOB=1` to print the first uncaptured RAM access in a failing
case. Successful replay behavior is unchanged.

## Start another coverage campaign

Refresh `decomp_stats.py`, then freeze a separate baseline with
`freeze_campaign.py --out tools/oracle/advance_coverage_baseline.json`. The command
refuses overwrite and checks original artifact hashes and the current ledger
against the dashboard. `promote_tenpp_batch.py --baseline FILE` selects that
baseline while preserving its original default.

`campaign_queue.py --plan PLAN.csv --baseline BASELINE.json --out QUEUE.json
--watch ROOTS.txt` ranks unported bodies by dynamic-call count and marginal
address-union bytes. `--min-dynamic`, `--max-dynamic`, `--minimum-size` and
`--limit` bound a cohort; `--require-closure` keeps only roots whose static
call closure is complete. Queue totals are prospective and never grant credit.
`--exclude-watch FILE` and `--exclude-progress FILE` omit previously attempted
roots; both options are repeatable.
`--require-implementation` requires `implementation_closure_ok=Y`, rather than
SDK attribution closure. Refresh that column with `port_plan.py
--implementation-map FILE`, a JSON entry-to-C-source ownership map for existing
helpers. The map validates source paths and does not grant ledger credit.
`--require-static-implementation` permits unknown indirect sites while requiring
an empty `missing_implementations` column and no fixed firmware calls. The
reported dynamic-site count remains explicit; capture and replay must resolve
every executed helper before promotion.

`source_owners.py --build build --manual-map MANUAL.json --resolved-calls
extract/analysis/sh4_resolved.csv --out OWNERS.json --report REPORT.json`
discovers planning ownership from CMake-linked `vf3core` and `vf3matrixfamily`
sources and their included `.inc` files. It follows adapter order in
`matrix_family.c`, so overlapping adapters have one owner. Unlinked files are
excluded, and missing linked dispatcher routes remain in the report. Feed the
result to `port_plan.py --implementation-map OWNERS.json`. Owning an entry PC
does not establish complete behavior or grant C coverage credit.

`inspect_capsule.py --summary` also accepts FR/XF, PR, SR, FPSCR, MACL/MACH,
FPUL, GBR and `rbank0` through `rbank7`. Floating registers display raw bits and
decoded single precision values; registers absent from an older capsule format
display `unavailable`. Register override profiles accept FR/XF names with raw
uint32 bit patterns, preserving existing GPR input behavior.

`family_queue.py --plan PLAN.csv --baseline BASELINE.json --survey REPORT.json
--out FAMILIES.json --watch ROOTS.txt` groups callers by shared missing C
dependencies and includes their transitive static dependency leads. Ranking
uses marginal union bytes per dependency/dynamic-call cost. Selection subtracts
already selected family spans; unknown indirect sites and missing body intervals
remain explicit. Repeated `--survey` inputs contribute the maximum observed
scenario count per entry, without adding overlapping discovery counts.
Like the single-root queue, the family queue accepts repeated `--exclude-watch`
and `--exclude-progress` inputs. Excluded entries cannot be selected as callers;
they remain visible as dependencies of a new caller. Both queues normalize
RAM-address aliases and read legacy or grouped progress records through the
same shared reader.
The family ranker canonicalizes intervals once and counts marginal bytes by
binary search in the covered union. Its output matches the previous union
algorithm byte for byte; the retained 30-family campaign comparison is
`extract/analysis/advance_resume_families_fast.json` (0.51 seconds).

`capture_report.py --ready-watch ROOTS.txt` exports entries passing capture
gates in at least one input corpus. Select compatible corpora when merging:
other captures of the same entry can still contain incomplete invocations.
Strict replay and independent acceptance remain required after capture gates.
`--merge-ready DIRECTORY` collects only eligible roots and their compatible
source corpora, checks the raw records again and preserves their provenance.
Unrelated quarantined entries remain in the original evidence, outside the
filtered development corpus.
`filter_capture_runs.py BATCH --run s21 --out DIRECTORY` keeps selected complete
scenarios from a batch when another run contains an incomplete invocation; the
original raw capsule and state/play provenance remain attached.

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

Register and memory override dimensions also accept
`{"values": [0, 1], "stride": 4, "phase": 0}`. Variant `n` selects
`values[(n // stride + phase) % len(values)]`. Different strides exercise
independent field combinations; scalar and list overrides retain their existing
behavior. Strides must be positive integers and phases nonnegative integers.
Explicit GPR fixture pointers relocate with their RAM addresses; FR/XF values
remain raw bits.

`isolate_planned.py --observe-watch CHILDREN.txt --probe-children` records watched
nested entries only while a rollback probe is active. It uses
`golden_batch.py --probe-children` and the opt-in `VF3_PROBE_CHILDREN` oracle
switch, which also enables `VF3_PROBE_ONLY`. Unrelated natural invocations are
excluded. The default capture modes remain unchanged. Reinstall oracle hooks
and rebuild Flycast before using the option. Prologue candidates and frozen
children come from `prologue_roots.py`; original image/body intervals are kept.
`prologue_roots.py --prefix-distance 64` can find floating-register save prefixes
longer than its unchanged 32-byte default. Inspect the suggested parent and
retain the original frozen child/body interval for credit.

`expand_memory_profile.py PROFILE.json --out WORDS.json` expands repeated
record/table fields for `isolate_planned.py --memory-overrides WORDS.json`.
Each entry has optional `words` and `ranges`; a range specifies `start`, `count`,
`stride` and `value`. Values retain scalar/list/strided-variant semantics.
Aligned addresses must lie beyond the original image in mutable Dreamcast RAM;
overlaps, invalid dimensions and ranges crossing RAM end are rejected. This
avoids handwritten arrays of record-field addresses. It produces input fixtures
only. Twenty-one campaign-tool checks pass, including range validation and
configuration editor decoding.

`config_editor_map.py --help` describes extraction of bounded editor parameters
from the untouched retail image. The decoder validates prologue, helper ABI,
getter/setter targets and epilogue before reporting field width, offset, bounds
and step. Its output is recovered metadata, not expected replay results.

`translate_adapters.py --reuse-sources-report REPORT.json` reuses the compiled
source paths recorded by `source_owners.py`. It avoids repeatedly spelling out
long adapter lists on Windows; source paths must resolve to existing C files.

`capture_catalog.py --pattern 'extract/analysis/*report.json' --baseline BASELINE`
indexes retained complete-body development reports against current C credit.
It excludes acceptance and holdout paths, deduplicates corpora and reports
potential interval-union gain and existing source ownership. This is an advisory
index: re-run `capture_report.py` on the raw corpora before replay and promotion.

`comparison_inputs.py --watch ROOTS.txt --out REPORT.json` records bounded
integer comparison literals from the original image. `tenpp_probe_plan.py` and
`isolate_planned.py` accept `--comparison-boundaries` to sample below, at and
above those literals after the first 64 variants. Narrow fields preserve their
adjacent bytes, and protected pointers remain intact. These are advisory input
fixtures; original capture and strict replay still decide acceptance.

Use `portcheck.py --matrix-executable SNAPSHOT.exe --jobs 4` to replay the
existing matrix bindings with an immutable executable. This preserves the
binding file and leaves other replay executables unchanged. `verify_all.py`
accepts the same option. Snapshot overrides retain each binding's strict flag.

`regression_status.py LOG --out STATUS.json` summarizes running and completed
`portcheck.py` or `verify_all.py` logs against the current binding inventory.
It supports serial final summaries and parallel progress lines, deduplicates
their repeated binding names and refuses a passing status for truncated logs.
An unfinished run remains `RUNNING`; replay failures return a nonzero exit code.
For full repository gates, add `--suite verify_all` so a finished `portcheck`
does not prematurely mark the remaining audit and coverage stages complete.

`state_checksum_table.py --out TABLE.json --preview 16` checks the original
checksum lookup instructions and table pointer, compares the packed table with
generated polynomial-`0x1021` words, hashes it and optionally displays packed
words beside actual indexed reads. The packed two-byte stride differs from the
original four-byte lookup stride; this metadata receives no body credit.
`--image FILE` selects an alternate original-image input for verification.
These tools replace the session's inline Python inspection and binding edits.
All 24 campaign-tool checks pass.
