# Reusable evidence commands

Use these commands instead of temporary Python snippets when inspecting
captures, replay failures, caller contracts and coverage campaigns.
Run from the repository root. Set an output directory on the drive with space:

```powershell
$evidenceCache = 'C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence'
```

## Inspect existing evidence

`tools/oracle/evidence_inspect.py` has four read-only subcommands. Its optional
`--out` precedes the subcommand and refuses an existing report.

```powershell
python tools/oracle/evidence_inspect.py status extract/analysis/strip_parent_full_633_checkpoint_v1.log --suite portcheck

python tools/oracle/evidence_inspect.py capture --batch "$evidenceCache/coverage_65_selection_unlock_accept_v3_export/batch_manifest.json" --owners tools/oracle/coverage_65_selection_unlock_accept_v3_owners.json --image extract/gamedata/1ST_READ.BIN

python tools/oracle/evidence_inspect.py case "$evidenceCache/coverage_65_selection_unlock_combined_accept_v1_export" --entry 0x8c0c3210 --case 1117 --window 20
```

`status` checks terminal log markers and the expected binding inventory. It
does not infer that a process is running from an unfinished log. Choose
`--suite verify_all` when checking the complete repository gate.

`capture` reads completed raw capsule files and reports invocation accounting,
excluded flags, distinct inputs, device events and owner instruction gaps per
original state. With `--image`, it checks original instructions and literal
pools. It also reports identical captured inputs with different outputs.
These diagnostics do not qualify a campaign or grant C coverage.

`case` uses one-based replay case numbers and zero-based RAM window indices.
It prints the original capsule/invocation references, stack pointer and
before/expected bytes. To inspect that original record, use the reported
capsule path and invocation ID:

```powershell
python tools/oracle/evidence_inspect.py sample ORIGINAL_CAPSULE_PATH --id 142 --pc 0x8c040f4e
```

This reports selected instruction hits, final instructions, floating-point
store instructions, architectural-state size, device events and fingerprints.
It does not reconstruct every effective write address from opcodes.

## Build isolated readable candidates

`tools/oracle/build_isolated.py` copies the current static library, dispatcher,
runner and optional C candidates into a new directory, compiles there and
records the inputs, archived headers, compiler commands and executable hashes.
Candidate routes follow the existing FPSCR guard. The normal build is untouched.

```powershell
python tools/oracle/build_isolated.py --config tools/oracle/build_configs/scene_replay_development.json --out "$evidenceCache/scene_replay_example_v1"

python tools/oracle/build_isolated.py --memory-diagnostic --out "$evidenceCache/memory_diagnostic_example_v1"
```

The JSON config contains `sources` and `routes`; each route supplies `entries`,
a C `function` name and optional `entry_argument: true`. Entries are normalized
to physical addresses, and duplicate aliases are rejected.

`--memory-diagnostic` adds byte previews inside the existing RAM mismatch branch.
The strict comparisons and failure returns remain active. Run the executable
through `tools/oracle/verify_matrix.py --executable PATH`, which enables strict
replay. Existing output directories are refused.

This is a development builder, not a qualified compiled-source freeze: it pins
the copied static library binary rather than archiving its entire source closure.
Normal integration still requires `compiled_source_freeze.py` and the established
development, independent acceptance and full regression gates. Historical builders
remain intact because earlier proofs pin their exact bytes.

## Seal an authored caller contract

`tools/oracle/seal_callable.py` attaches hashed original caller manifests to an
authored owner-to-contract JSON and runs the existing callable validators against
every supplied corpus. It does not infer a caller contract from addresses.

```powershell
python tools/oracle/seal_callable.py --template tools/oracle/scene_input_transition_callable_v1.json --caller-manifest "$evidenceCache/scene_input_transition_original_dispatch_v1/manifest.json" --corpus "$evidenceCache/coverage_65_scene_input_transition_combined_dev_v1_export" --reference-key original_dispatch_manifests --out "$evidenceCache/scene_callable_example_v1.json"
```

Repeat `--caller-manifest` or `--corpus` as needed. The default reference key is
`original_caller_manifests`; scene table contracts use `original_dispatch_manifests`.
The command rejects an existing output and callers that change during validation.

## Freeze a fixed coverage target

`freeze_campaign.py` now accepts an exact byte-union target as well as its existing
percentage-point option:

```powershell
python tools/oracle/freeze_campaign.py --target-bytes 282527 --out "$evidenceCache/next_65_campaign_example_v1.json"
```

It verifies the frozen image/inventory/body hashes and that the coverage dashboard
agrees with the ledger. At the current checkpoint this records baseline 275,276,
target 282,527 and remaining gain 7,251. It preserves earlier campaign files.

## Verification of these tools

The reusable builder reproduced the known selection acceptance result exactly:
1,386/1,388 matches, zero skips, with failures at cases 1,117 and 1,353. The caller
sealer validated the existing scene dispatch proof, and the exact-target freezer
reproduced the 7,251-byte gap. The isolated scene build and replay results are
recorded in `extract/analysis/scene_replay_reusable_dev_v1_scene_native.json`.
Tool tests live in `tools/oracle/test_reusable_evidence_tools.py`; immutable earlier
335-test checkpoint logs remain preserved. The current oracle discovery run passes
all 346 tests. The reusable scene build also passes all 1,514 combined helper cases
with zero skips (`scene_replay_reusable_dev_v1_helpers_native.json`).

## Repeat an original counterexample

`capsule_repeat_recipe.py CAPSULE --id N --transfer RTS_ADDRESS --out NEW_JSON`
prepares a diagnostic recipe for `audio_one_shot.py`. It restores all captured
RAM words and the 55 architectural values supported by the unchanged observer,
setting FPSCR before FR/XF. The observer cannot assign the eight inactive GPR
bank values, so equality of all 63 captured words must be checked afterward.
The original explicit return boundary must appear in the source instruction trace.

`compare_original_samples.py LEFT RIGHT --left-id N --right-id M --out NEW_JSON`
compares two complete RAM-only records, including all 63 architectural values,
captured pages and outputs. It reports input differences separately from output
differences and never grants coverage or automatically quarantines an owner.
Original image, execution provenance and accounting still need their established
audits. `selection_unlock_observable_audit.py` applies those checks to the two
selection counterexamples and seals their owner-wide exclusion evidence.
Instruction comparisons normalize cached and physical address aliases. The
current oracle discovery run, including repeat-tool identity checks, passes
all 351 tests (`extract/analysis/original_repeat_tools_tests_v2.log`).

## Measure candidate coverage margins

`candidate_margin.py --owner OWNER --owner OWNER --target-bytes 282527 --out NEW_JSON`
subtracts the accepted address union from the selected frozen bodies and combines
overlapping candidate ranges once. It pins the dashboard, ledger and inventory
inputs but remains advisory: a candidate's potential bytes are not verified bytes.
An owner can have a substantial frozen body and zero marginal gain because its
addresses already appear in accepted spans. The current scene/helper pool offers
6,462 marginal bytes, leaving a 789-byte shortfall against the 7,251-byte gap.

## Merge original development campaigns

`merge_development.py --batch BATCH --batch BATCH --owners OWNER_MAP --image ORIGINAL_BIN --out NEW_CORPUS --proof NEW_JSON`
requires complete invocation and frame accounting, original instruction/pool
identity, all 63 architectural values, no device events in valid records,
complete owner bodies and 64 distinct inputs per original state by default.
It combines valid cases through the established capsule converter and rejects
nondeterministic entries. The resulting original-development proof grants no
C coverage and still needs strict native replay, caller proof and the full
independent acceptance workflow. The round-decision merge produces 1,003 cases
and independently covers its 882-byte owner in both original states.

## Preserve and qualify normal builds

`preserve_historical.py --proof PROOF --source-archive SOURCE_MANIFEST --out NEW_ARCHIVE --manifest NEW_JSON`
validates frozen hashes before copying mutable workspace dependencies into a
historical archive. Existing archives are preserved. This keeps an earlier
checkpoint reviewable when the normal build advances.

`qualify_development_batch.py --config CONFIG`
checks the normal compiled-source archive, per-owner whole original bodies,
strict native reports, original callers, full binding inventory, native suites
and tool-test gate before sealing a development freeze. Independent acceptance
inputs must be created after that freeze; this command grants no C coverage.
The scene configuration is `scene_batch_development_qualification_v1.json`.

`scene_batch_holdout_inputs.py` checks the qualified freeze and every pinned
dependency before creating four fresh scene input profiles. It preserves
original code and pools, changes typed counters and timers, relocates writable
objects and refuses to replace an existing input artifact.

`scene_batch_accept_capture.py` runs those profiles sequentially in original
states 45/46 using the unchanged observer. `scene_batch_acceptance_audit.py`
requires complete invocation accounting and frames, whole-body coverage with
at least 64 distinct valid inputs in each state, original caller contracts,
strict full-state native replay without skips, disjoint states and input
fingerprints, and original SAVEF state lineage. It preserves failed evidence
and grants no ledger credit itself.

`promote_tenpp_batch.py --evidence-root CACHE` explicitly permits immutable
corpora stored outside the workspace. Relative workspace artifact names and
hash formats remain unchanged; undeclared external paths and sibling-prefix
escapes are rejected. This avoids copying large evidence caches onto the
nearly full workspace drive without changing qualification gates.

`original_input_disagreement.py --frame BATCH --repeat ONE_SHOT --capsule RAW --invocation ID --owner OWNER --out NEW_JSON`
checks both original execution manifests, the unchanged observer, every
provenance hash, complete invocation accounting, all 63 input words, captured
RAM, original opcodes/pools and identical instruction traces. Differing final
RAM excludes the entire owner under the captured-input model. It establishes
an observation limit, without attributing a hidden cause or correcting C.

`pin_failed_campaign.py CORPUS --report STRICT_REPORT --out NEW_JSON` pins the
complete replay report, native executable, every corpus file and each raw run,
summary, log and input patch. It requires a failed report covering every corpus
entry and preserves all cases. The input-transition failure retains 1,849
dependencies in `scene_input_transition_failed_acceptance_v1.json`.

`replay_transition_caller_inputs.py` prepares four typed expired-clock inputs
through the immutable original scene-57 table. The resulting one-shot caller
captures retain the input predicate, paired reset callbacks, replay transition
and final RTS. The recipe grants no coverage credit.
`--force-pair-reset --out NEW_RECIPE` clears the original optional-reset input
byte for every variant. `replay_transition_caller_audit.py` verifies the eight
resulting original windows, including dispatcher slot, complete ordered save
prefixes, delayed transfers, callback tail and actual outer return. Its proof
is `replay_transition_original_callers_v2_proof.json`; the helpers remain uncredited.

`scene_round_acceptance_audit.py` audits the complete round campaign separately
from the failed input-transition campaign, using every run and valid specimen.
`scene_round_checkpoint.py` requires its historical hashes, original SAVEF
state lineage, compiled source freeze, expanded 1,415-binding regression,
39 native suites and 375 tool tests before sealing the final checkpoint.
