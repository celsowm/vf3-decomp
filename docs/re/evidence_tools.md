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
39 native suites and 381 tool tests before sealing the final checkpoint.

## Capture longer original invocations

`build_extended_observer.py` creates a separate recorder and private object
archive in the evidence cache. It reuses and hashes the original linked
objects, libraries and source archive; only the recorder format tag and
instruction-vector bound change. The original observer remains available.
The resulting `VF3CAP7` layout is the `VF3CAP6` layout with a 500,000-opcode
bound. Older formats retain their 100,000-opcode bound, and every v7 record
still requires all 63 architectural words, bounded RAM pages and device tape.

`extended_observer_controls_audit.py` compares eight complete original caller
windows across both recorders. All architecture, RAM, instruction traces and
full audio checkpoints must match. The passing proof is
`extended_observer_controls_v1.json`; it grants no gameplay coverage.

`golden_batch.py --observer-controls tools/oracle/extended_observer_controls_v1.json --probe-ops 300000 ...`
validates that proof, its dependencies and the exact observer executable
before allowing a larger budget. Without explicit controls, the maximum
remains 100,000. The control path and hash are retained in each run's provenance.

`menu_reserve_inputs.py` prepares the original complete prefixes for owners
`0x8c07cbda` and `0x8c07cf50`. `--typed-actors` adds paired status-bit and
character metadata boundaries. The first screen covers only 104/670 bytes
of the first owner and no valid body of the second: its repeated descriptor
clears exceed the old record bound. The retained report is
`menu_reserve_original_dev_v1_report.json`. The extended v2 screen covers
606/622 selector bytes but contains an incomplete invocation in each state;
it remains diagnostic.

`menu_selector_inputs.py --complete-profile` places every character boundary
and the class-six branch within the first 128 probes. With 8,000 frames and
`--max-samples 128`, v4 completes both states with 73 distinct valid inputs and
whole 622-byte coverage in each. Its isolated C replay fails 144/146 cases;
the candidate remains uncredited.

`capsule_repeat_batch.py RAW --id ID --transfer PC --prefix NEW_PREFIX` prepares
exact-input rollback probes using the original executed PC alias. It emits
the supported `entry`/`target` directives and seeds every captured input page;
expected outputs are never seeded. Outputs include original code bytes and
must remain in ignored analysis storage. Original input equality still needs
all 63 words, including the unassignable inactive register bank, checked after
execution. This supports phase diagnostics when a one-shot repeat takes an IRQ.

`original_probe_disagreement.py --left BATCH --right BATCH --left-raw RAW --right-raw RAW --left-id ID --right-id ID --owner OWNER --observer-controls CONTROLS --out NEW_JSON`
checks complete frame/invocation accounting, the exact controlled recorder,
original opcodes and pools, input equality and identical instruction traces.
A final RAM disagreement excludes the entire owner. The selector proof records
161,420 identical original instructions and all 63 equal input words, with a
different word at `0x0c641800`. It establishes an observation limit, without
attributing a cache, timing or floating-point cause.

## Qualify the replay helpers

`replay_transition_callable_template_v1.json` declares the exact scene-57
transfer paths for three owners. `callable_replay_transition.py` checks their
original entry sequences, whole bodies, eight original caller windows and
native save/restore invariants. `seal_callable.py` produces the validated
`replay_transition_callable_v1.json`; it grants no byte credit.

`qualify_replay_transition_development.py` requires complete accounting and
whole-body coverage for all five helpers in each original state, all 1,514
strict native cases, the normal compiled-source closure, original callers,
full 1,415-binding/39-suite regression and 388 tool tests. It seals a development
freeze before `replay_transition_holdout_inputs.py` creates changed, relocated
input profiles. `replay_transition_accept_capture.py` then runs both profiles
against the unchanged original observer in states 45/46. Every held campaign
still needs a complete independent acceptance audit; the potential gain is
420 bytes because the two other helper bodies already lie in accepted spans.

`replay_transition_acceptance_audit.py` combines every held run, requires
complete accounting, whole bodies and 64 distinct inputs separately in each
state, original callers, zero-skip strict replay, disjoint states/inputs and
SAVEF lineage. It verifies all five helpers, including the two already
accepted dependencies, before permitting the 420-byte promotion.
`replay_transition_checkpoint.py` requires the expanded 1,418-binding gate,
39 native suites, 388 tool tests and preserved source/evidence hashes, then
archives the current inventory and suite executables as a final checkpoint.

`scene_retire_screen_inputs.py` screens a 512-byte scene reset through its true
seven-register save prefix. It retains original callback execution and uses
initialized fight states; a successful screen still needs whole-body, caller,
strict native and independent held qualification.
`--extended` retains the same reset inputs for a second screen with the
validated larger-record observer. The first screen stops inside a bounded
4,096-entry descriptor lookup; the flag-one and budget-limit specimens remain
diagnostic. Increasing the budget does not grant coverage or change the game.
