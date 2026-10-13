# One-session execution plan for 65% verified C

## Current execution checkpoint, 2026-10-13

The independently accepted replay helpers add **420 marginal bytes**, bringing
the ledger to **276,578 / 434,656 bytes (63.6315%)**. The remaining target is
**5,949 bytes**. All 1,514 development and 1,515 held cases pass strict replay
with zero skips. Every helper body is covered independently in both held
states, with disjoint inputs, complete accounting and original caller proofs.
The three new owners are `0x8c099544`, `0x8c099568` and `0x8c0a91e6`.
The other two helper bodies already contribute to the baseline; their true
entry prefixes remain verified dependencies and add no bytes. Qualification,
promotion and preservation are recorded in `replay_transition_qualification_v1.json`,
`replay_transition_v1_manifest.json` and `replay_transition_historical_archive_v1.json`.
The expanded regression passed all **1,418 bindings and 39 native suites**;
all **388 oracle tool tests** passed. `replay_transition_full_checkpoint_v1.json`
seals the 408-file compiled source closure, independent acceptance evidence,
and archived binding inventory, dashboard, ledger and native executables. A new
screen enters scene-reset owner `0x8c096b0a` through its complete prefix at
`0x8c096afc`; its 512 potential bytes remain advisory until the full proof exists.
The first reset screen has no valid calls: two IRQ-invalid and two
100,000-instruction budget-limited specimens remain preserved. The limit is
reached inside an original, fixed 4,096-entry descriptor scan. A second screen
uses the same typed inputs with the separately controlled recorder and a
500,000-instruction budget. Both emulator runs terminated successfully, but
the screen still has no valid calls: 55 and 52 completed specimens are all
IRQ-invalid, and each state has one incomplete invocation. The complete
campaign is diagnostic only, with zero coverage credit; its audit is preserved
in `tools/oracle/scene_retire_original_dev_v2_report.json`. A larger recording
budget alone does not qualify this reset owner.

The later full-frame natural screen materially changes the next-candidate
ordering. With the pinned original Flycast observer and the 30-entry pool
watch list, states 26, 27, 28 and 29 complete 14,400 frames each. They reach
`0x8c09635a` 14, 19, 16 and 15 times respectively, plus one call to
`0x8c0a575c` in state 27. All other watched entries have zero hits in these
contexts. The reusable validator and hashed report are
`coverage_65_hit_screen_audit.py` and
`coverage_65_pool_hits_nine_state_v1.json`. State 21 adds seven more natural
calls to `0x8c09635a`, state 20 adds no hits, state 22 adds 18 calls, state 23
adds 31, and state 24 adds 45. Development states 30 and 31 reach none of the
30 watched pool entries. States 40 and 41 reach `0x8c09635a` 25 and 26 times,
respectively; no other watched owner appears. Their per-state audits are
`coverage_65_pool_hits_s30_v1.json`, `coverage_65_pool_hits_s31_v1.json`,
`coverage_65_pool_hits_s40_v1.json` and `coverage_65_pool_hits_s41_v1.json`.
The newly screened state 25 reaches `0x8c09635a` 73 times and no other watched
entry; its complete 14,400-frame hit audit is
`coverage_65_pool_hits_s25_v1.json`.
State 32 is unusable: the guest stops after three frames on a fatal SH-4
exception, so its screen is incomplete and excluded. State 33 completes 14,400
frames with no calls to any watched pool entry; its audit is
`coverage_65_pool_hits_s33_v1.json`. State 34 completes a 600-frame pilot with
no early pool hits; it has not yet had a full screen.
This proves natural reachability, not owner coverage. The narrow measured REIOS
`GDROM_GET_DRV_STAT` service adapter now passes all 115 complete natural cases
from states 26–29, 40 and 41 with zero skips. A new state-25 capsule supplies
73 more distinct complete inputs, and the current C adapter passes all 73/73
strict replays with zero skips. The seven-state set now totals 188 cases, but
its merged PC union remains
**140/616 bytes** at `0x8c09635a`, so none of the owner is qualified. A focused
gate probe reached the TA FIFO at `0x80800000` and produced only invalid
captures; no new body PCs were added. Keep the 5,949-byte target gap unchanged.
Details are in `docs/re/aica_stub.md`,
`tools/oracle/coverage_65_9635a_reios_dev_115_report.json`,
`extract/analysis/coverage_65_9635a_s25_capsule_v1/` and the two probe recipes.

The one naturally reached `0x8c0a575c` call has a readable isolated C model in
`src/fight/actor_table_apply.c`. Its complete 558-byte body passes strict
replay for the captured natural input (1/1), but this single example does not
establish varied inputs, caller coverage or held-state behavior, so it earns
zero credit. Both additional screens are development-only and diagnostic.
The 5,949-byte target gap is unchanged.

The options-menu diagnostic adds a readable isolated C model matching all
256 new strict original cases and 171 older cases. Each new state covers
650/664 owner bytes, but the original reset helper makes a required nonzero
configuration branch unreachable under this input model. The earlier ledger
already recorded that blocker; the entire owner remains excluded. Details are
in `docs/re/options_menu_diagnostic.md`. A reusable candidate-block registry
and pool refresh now remove known blockers before further implementation.
`coverage_65_remaining_pool_margin_v5.json` records 26 eligible advisory owners
with 18,654 potential bytes against the unchanged 5,949-byte target gap.
Potential bytes remain conditional on all original, C, caller and held gates.

The resident-menu owner `0x8c09b37e` remains blocked. Five complete diagnostic
capture reports combine to **702/726 instruction bytes independently in both
states 26/27**; the same 12 PCs remain uncovered at `0x8c09b640` through
`0x8c09b660`. A focused mutable UI configuration reaches the alternate event
handler, while later counter and task-pointer variations do not reach the
clamp or swap tail. The evidence and reusable PC-union analyzer are in
`coverage_65_resident_menu_dev_union_v1.json` and
`coverage_65_capture_union.py`. No bytes are credited; reopening this owner
requires the original task/counter context that reaches the tail.

Candidate `0x8c07e294` (1,256 bytes) also remains advisory. Its complete
14,400-frame hit-only run in state 26 recorded zero calls at true entry
`0x8c07e284`, so the remaining queued states were stopped. The owner stays in
the candidate pool pending a state where the menu actually enters it; see
`coverage_65_ui_7e294_hits_v1.json`.

The preceding round checkpoint:

The complete round-decision campaign adds **882 marginal bytes**, bringing
the ledger to **276,158 / 434,656 bytes (63.5348%)**. The remaining target is
**6,369 bytes**. Development passes 1,003/1,003 strict cases; independent
acceptance passes 1,008/1,008 with zero skips and whole-body coverage separately
in both states. All four round runs remain intact, with original caller proof
and disjoint input fingerprints. Qualification and preservation are in
`scene_round_qualification_v1.json` and `scene_round_historical_archive_v1.json`.
The expanded regression passed all **1,415 bindings and 39 native suites**;
the sealed checkpoint includes 381 oracle tests, original SAVEF state lineage
and the retained compiled source closure (`scene_round_full_checkpoint_v1.json`).
The later recording/probe/caller tool gate passes **388 tests**. No failed
input-transition cases contribute credit.

The new menu reserve screen targets `0x8c07cbda` (670) and `0x8c07cf50` (622).
Its first original campaign completed both states but covered only 104/670
bytes of the first owner. The second routine has no valid body: its repeated
120-descriptor scans exceed the old observer's 100,000-opcode record limit.
The diagnostics remain preserved. A separate `VF3CAP7` recorder raises only
the record bound to 500,000; eight old/new original caller windows match all
architecture, RAM, instructions and full audio checkpoints. The new typed
actor screens completed in states 28/29 with a 300,000-opcode budget and that
control proof pinned. These 1,292 potential bytes remain uncredited.
The focused v4 selector campaign completes all 128 invocations in each state,
with **73 distinct valid inputs per state and 622/622 body bytes**. The readable
`src/fight/menu_character_selector.c` candidate and three real helper models
are isolated from the normal build. A coordinate-register correction fixes the
large descriptor mismatch; its complete strict development replay still fails
**144/146** cases with zero skips. The first two isolated failures are preserved.
Exact original rollback repeats now prove ambiguity: state-28 invocation 21 and
repeat invocation 2 have identical captured RAM, all 63 input words and all
**161,420 instructions**, but differing final RAM at `0x0c641800`. The isolated
C model matches the repeated original output. All **622 owner bytes** remain
excluded under this input model (`menu_selector_observable_quarantine_v1.json`).
The hidden cause is not established. IRQ-invalid one-shot repeats are retained
as diagnostics and do not support the disagreement proof. The failed complete
development corpus is pinned by `menu_selector_failed_development_v1.json`.

Accepted union at the preceding independently qualified strip milestone:
**275,276 / 434,656 bytes (63.3319%)**. The preceding pushed checkpoint
`04cb3ea` was 273,148 bytes. The strip build passed its full 1,409-binding
regression, 39 native suites and 330 current oracle tests. All five new
bindings pass their strict development and independent acceptance replays;
the expanded checkpoint passed all **1,414 bindings, 39 native suites and
335 oracle tests** (`tools/oracle/strip_parent_full_633_checkpoint_v1.json`). The remaining target is
**7,251 verified bytes**; retain
the fixed target of **282,527**, including throughout intermediate batches.

Five readable strip parents added **2,128 marginal bytes**. Their frozen
400-input build passes all 2,546 strict development and 2,550 acceptance
cases with zero skips. Original states 45/46 both completed 18,000 frames
and independently cover every owner instruction; their fingerprints are
disjoint from development. Original caller contracts also pass. Qualification,
promotion and historical dependency archives are recorded in
`tools/oracle/strip_parent_qualification_v1.json`, `strip_parent_v1_manifest.json`
and `strip_parent_historical_archive_v1.json`.

Next is selection/unlock owner `0x8c0c321e`, **1,574 bytes**. Combined original
development campaigns already cover its entire frozen body independently
in states 26/27. The readable C candidate is integrated and remains uncredited;
its 1,411-case strict development replay and eight original parent-tail
windows pass. An immutable normal replay executable and 401-file archive
are ready (398 compiler dependencies plus three retained historical files).
Its full 1,414-binding regression, 39 native suites and 335 tool tests passed,
and its development freeze was sealed before new acceptance inputs. Independent
acceptance then failed: 1,386/1,388 native cases match with zero skips, and two
original invocations in the third campaign are incomplete. The two memory
counterexamples are preserved; the candidate remains unqualified and uncredited.
Exact original repeats now prove ambiguity in both states: identical captured
input RAM and all 63 architectural values yield differing final RAM, even with
identical instruction traces. The complete 1,574-byte owner is excluded through
this observation model (`tools/oracle/selection_unlock_observable_quarantine_v1.json`).
The hidden state causing the discrepancy is not established; passing subsets
cannot be credited. Any future correction still requires a new development
freeze and fresh acceptance inputs after addressing the observation limitation.
The first caller recipe produced
device events on six windows and remains diagnostic; guarded original caller
recipe v2 verifies the unchanged transfer/save/return instructions without
device activity.

Scene input owner `0x8c0993e8` now has readable development C and the paired
replay reset, action and transition helpers. Two standalone original branch
campaigns in each of states 26/27 cover all 250 owner bytes independently;
the merged corpus passes 1,016 strict native cases with zero skips and no
nondeterministic inputs. Eight original index-57 scene dispatch windows also
completed without device activity; the fixed scene-57 attribution verifier
and its five mutation tests now pass. Normal integration and the qualified
source freeze passed, but independent acceptance failed **910/911** cases with
zero skips. Case 401 maps to original state-46 invocation 210. An exact original
repeat has identical captured RAM, all 63 input registers and all 28,901
instructions, but different final RAM. The entire 250-byte owner remains
excluded under this observation model, recorded in
`scene_input_transition_observable_quarantine_v1.json`; the hidden cause is
not established. Earlier mixed scene captures contain unrelated incomplete calls
and are retained as diagnostics, rather than used for this complete proof.

The five new replay helpers provide **824 additional uncredited candidate
body bytes**, outside the nine-owner scene queue: `0x8c099544` (36), `0x8c099568`
(290), `0x8c0a91e6` (94), `0x8c0a92da` (320) and `0x8c0a9452` (84).
Their first standalone original campaign passes 970 strict native cases
but contains an incomplete invocation and insufficient per-owner cases in
one state; it remains diagnostic. The second campaign completes all 640
invocations in each of states 28/29. A separate character-six campaign fills
the action helper's missing 16 bytes. The combined complete original audit
covers all five bodies independently in both states, and its 1,514 strict
native cases pass with zero skips. These helpers need their own caller
contracts, normal integration, a qualified freeze and fresh acceptance
before they can provide any coverage margin. A fresh address-union audit
finds only **420 marginal bytes**: all 320 bytes of `0x8c0a92da` and all
84 bytes of `0x8c0a9452` already lie in accepted spans. Those helpers add
behavioral support but cannot be counted again.

The three remaining helper owners now have sealed scene-57 callable contracts
in `replay_transition_callable_v1.json`, backed by eight complete original
caller windows and four attribution mutation tests. The normal 408-file source
archive, all 1,514 development cases, the 1,415-binding/39-suite gate and 388
tool tests qualify their development freeze. Two fresh held profiles were
created after that freeze, with permuted typed inputs and relocated writable
buffers. Original acceptance completed sequentially in states 45/46 through
`replay_transition_accept_capture.py`. All held bodies, cases, callers and
accounting pass; the **420 marginal bytes** are promoted above. The generic
promotion report lists `0x8c0a92c8` and `0x8c0a9444` as having no frozen body at
those true-entry addresses; their 320/84-byte frozen owners were already
accepted. Both dependencies remain included in the complete strict audits.

Reusable commands for these inspections, isolated builds, caller proof sealing
and fixed coverage targets are documented in [evidence_tools.md](evidence_tools.md).

With selection/unlock excluded, the remaining gap stays **7,251 bytes**. The
next scene/replay selection contains **6,042 candidate bytes**:
`0x8c09970a` (1,172), `0x8c097abc` (1,132), `0x8c098c70` (882),
`0x8c099d74` (648), `0x8c0972d2` (624), `0x8c09635a` (616),
`0x8c096b0a` (512), `0x8c0993e8` (250), `0x8c0a89c2` (206).
Those 6,042 bytes plus the separate 420 helper bytes total 6,462, leaving
another **789 bytes** even if every candidate qualifies. Larger scene/actor
reserves are required; qualification failures increase that reserve requirement.
A new standalone six-root scene screen uses initialized original states 28/29
and finite actor positions to test the largest remaining scene routines and
an actor reserve. Treat it as advisory until each owner's full proof exists.
That screen completed all 768/73 started invocations, but covered only
498/1,172 bytes of scene initialization, 380/1,132 of pause flow, 378/882 of
round decision, 206/648 of scene continuation and 370/512 of the actor reserve.
The remaining 616-byte scene root had no valid calls. The initialized states
alone do not resolve the missing branches or device paths.

The first focused round-decision campaign covered 838/882 bytes with 500
valid calls. The second campaign closes its missing branches; the merged
development covers **882/882 bytes independently in both states 26/27**,
with **1,003 distinct valid calls**, zero nondeterministic inputs and no
incomplete invocations. `src/fight/scene_round_decision.c` implements the full readable
winner/draw/rematch decision and its scene-audio tail. Its isolated build
now passes **1,003/1,003 strict cases with zero skips** after adding readable
`result_statistics.c` and the true `result_record_entry.c` prefix. The
statistics helper independently passes 512/512 strict standalone cases. Its
body is outside the frozen inventory and grants no additional bytes. The
record helper's 2,364-byte owner `0x8c0698fc` was already accepted; only its
16-byte prefix before that body was missing from the callable dispatcher.
Neither dependency can provide the required reserve margin. The first two
isolated builds and their unsupported-helper failures remain preserved.
The closed paths are the zero metadata byte, deciding-draw fallback,
timer equality announcement and the nine-round completion flag. Eight complete
original index-54 scene caller windows now prove the immutable table transfer,
seven-register save prefix, frame restoration, audio callback tail and actual
outer RTS. The first two caller recipes retain an IRQ-invalid mode-one window;
recipe v3 varies the saved frame on the shorter mode-three caller path while
whole-owner development retains its mode-one branches. Division changes the
original Q/M/T scratch status bits; all SR bits remain compared in native replay.
Callable attribution is `tools/oracle/scene_round_decision_callable_v1.json`.
Normal integration now includes both completed scene owners and all seven
new dependency sources. The immutable normal snapshot has 408 archived inputs
(405 compiler dependencies plus three retained historical files). Its strict
development replays pass 1,003 round cases, 1,016 input-transition cases,
1,514 helper cases and 512 statistics cases, all with zero skips. The qualified
freeze pins 372 passing tool tests and the completed **1,414-binding / 39-suite**
regression in `scene_batch_integrated_all_bindings_dev_v1.log`. The complete
development evidence was sealed before generating four fresh acceptance
profiles, each captured in original states 45/46 for 4,000 frames. All eight
runs completed with zero incomplete invocations. The combined scene audit
stopped on the input-transition failure and grants no batch credit. The
separate complete round campaign qualifies all its valid specimens through
`scene_round_acceptance_audit.py`; no specimen is selected out of its campaign.
Eight new original scene-57 caller windows also complete the replay helper
transition paths, with no device access recorded by the capsule. They remain
caller research until their exact contracts and independent acceptance pass.
The previous selection build's 2,965 proof references and 401-file source
archive were preserved by `selection_unlock_complete_historical_v1.json`
before changing the normal build.
Reports are `scene_remaining_screen_v1_report.json` and
`scene_round_decision_dev_v1_report.json` / `scene_round_decision_dev_v2_report.json`
under `tools/oracle/`.
The current union calculation is pinned by
`tools/oracle/scene_result_record_reserve_margin_v1.json`; recompute margins
with `candidate_margin.py` instead of summing frozen body sizes.
The original 40-owner pool now offers 23,366 advisory marginal bytes when
recomputed against the current union (`coverage_65_remaining_pool_margin_v3.json`),
including quarantined or otherwise blocked candidates. Do not treat that pool
total as qualification yield; choose additional actor or scene reserves whose
original whole-body pilots and callers can actually be proven.

The interpolation owner `0x8c0a8f98` remains entirely excluded because
identical captured original inputs produced differing observable results.
Neither selected passing cases nor library attribution count toward 65% C.
Keep new raw evidence on C: while E: has approximately 1 GiB free.
Seal, commit and push each accepted milestone; at or above 65%, run the full
final inventory and evidence-chain audit before declaring completion.

Baseline: pushed commit `5e9dd1c`, **267,230 / 434,656 bytes (61.48%)**.
The objective remains **282,527 bytes or more**, requiring **15,297 new
verified bytes**. Execute this plan as one continuous working session,
including checkpoint gates, commits and pushes. A session-length deadline
is not established, and qualification yield cannot be guaranteed in advance.

## Measured work budget

The current frozen body inventory and accepted address union produce this
advisory pool. Owner ranges are disjoint in this selection; their marginal
bytes were recomputed against the current ledger, rather than reused from
older rankings. These are unqualified research candidates.

| Pool | Remaining candidate bytes | Role |
| --- | ---: | --- |
| Adjacent replay/motion | 458 | Short opening work; reuse the new descriptor-callback contract |
| Scene flow | 8,314 | Primary batch work using original scene/callback contexts |
| Actor/fight routines | 11,370 | Primary batch work using loaded actors and existing motion/geometry helpers |
| UI reserve | 6,758 | Replace primary candidates that fail caller, RAM or whole-body gates |
| Total | **26,900** | About 1.76 times the required gain |

Reaching the target requires qualification of about 57% of this pool's
bytes, or 76% of the 20,142-byte primary pool. This is a required yield,
not an observed acceptance rate. The [candidate CSV](coverage_65_one_session_queue.csv)
lists all 40 owners and their current marginal bytes. The reproducible
snapshot `tools/oracle/coverage_65_one_session_queue_v1.json` pins the
baseline, image, inventory, body ranges and binding ledger.

## 1. Establish a viable batch before implementation

Inspect the selected routines' original cached-address disassembly,
true callable prefixes, actual callers, dynamic destinations and nested
RAM/device dependencies. Reuse the proven descriptor dispatcher at
`0x8c09617c`/`0x8c096182`/`0x8c096184`, the scene dispatcher at
`0x8c0968d0`, and existing literal-JSR/BSR contracts where the original
instructions and target evidence actually fit. A ranked owner is not
necessarily the callable entry; derive and prove that entry independently.

Start with replay initializer `0x8c0a8370` and interpolation owner
`0x8c0a8f98`; the remaining replay restore owner `0x8c0a89c2` is a
conditional candidate because its SDK setup paths need additional context.
Then pilot a mix of scene owners `0x8c0991a2`, `0x8c0993e8`,
`0x8c098c70`, `0x8c0972d2` and the larger scene owners in the queue.
Prioritize a candidate after observing terminating original execution,
not merely because its static size is large.

Build an initial implementation batch offering at least 6,000 marginal
bytes across original RAM paths. Record the callable, proven caller,
missing instructions, blocking PC and dependency for every candidate.
If that batch is not viable, screen more primary/reserve candidates
before spending the session on tiny isolated promotions.

Do not reopen the known blocked playback owner `0x8c0a8aca`, unknown-caller
loader `0x8c0c7a88`, unreachable-branch rendering owners `0x8c0609b8`/
`0x8c0607a2`, or direct PVR/MMU SDK candidates without evidence addressing
their specific blockers. The UI reserve remains conditional on proving
its nested rendering behavior; its potential is not guaranteed RAM work.

## 2. Implement and qualify batches of 4,000-6,000 bytes

Use named C operations, field semantics and reusable helpers. Keep every
whole-owner gate and the frozen denominator. Do not generate a generic
opcode interpreter, waive dead instructions, stub unknown callbacks,
fabricate helper returns, or count SDK identification as C coverage.

For each batch:

1. Capture development with at least 64 distinct complete valid inputs
   per owner across two scenarios. Vary the original selectors, boundary
   values, flags, wrap cases and callback targets needed for every branch.
   An entire campaign with an incomplete invocation remains unqualified.
2. Implement the related C routines and real shared dependencies, then
   run strict development replay across all architectural state and RAM.
   Device effects require the established device comparison protocol;
   RAM command queues establish RAM behavior only.
3. Freeze the complete compiled sources and native executable once the
   whole batch passes development. Capture holdout in disjoint states with
   changed typed inputs and relocated writable objects. Any subsequent C
   correction requires another freeze and fresh holdout for that batch.
4. Require complete frozen-body execution separately in development and
   holdout, zero replay skips, original opcode/pool checks, exact caller
   proof and marginal address-union audit. Preserve every failed specimen
   and its explicit exclusion reason.
5. Run all observed/static affected bindings, 39 native suites, current
   tool tests, and batch evidence/hash audits. Commit and push the qualified
   batch and its ledger. Never report planned bytes as accepted bytes.

Use one source freeze and one native build per passing batch instead of
rebuilding all required targets for every small helper. Emulator campaigns
remain sequential; independent read-only checks may run concurrently.
Use `python tools/build_required.py --jobs 4`; archive only referenced
native binaries and keep the capture tool's 4 GiB disk reserve.

## 3. Pass the full 62.5% checkpoint

The next full-inventory checkpoint is **271,660 bytes**, requiring at
least **4,430** accepted bytes from this baseline. At the first batch that
crosses it, freeze the current full binding inventory and run every binding
against the current executable, all 39 native suites, all current tool
checks and the complete milestone hash chain. Record the actual count,
immutable executable and source freeze. Resolve failures before expanding
further; a previous full 60% gate does not validate changed C at 62.5%.

## 4. Close the remaining gap in the same session

After the checkpoint, **10,867 bytes** remain if coverage is exactly
271,660; recompute the actual gap if the passing batch overshoots it.
Continue scene and actor/fight batches, including larger owners
`0x8c09575c`, `0x8c09970a`, `0x8c097abc`, `0x8c08231c` and
`0x8c0831f8` when their whole-body pilots and callers are proven.
Use the reserve immediately when a primary candidate fails qualification.

Give a blocked candidate one new hypothesis and one targeted pilot per
triage pass. Move to another candidate when that hypothesis fails; revisit
only after new evidence resolves the named blocker. Measure the remaining
union after every promotion and expand the research pool if its still-viable
bytes cannot cover the gap. Keep working toward 65%, without replacing the
objective with completion of the selected queue or a smaller percentage.

## 5. Final completion audit and delivery

At **282,527 verified bytes or more**, freeze the final compiled sources,
executable and entire current binding inventory. Run the full binding gate,
all native suites, all tool tests and the complete milestone hash-chain audit.
Recheck every new owner's independent whole-body/caller/strict-replay proof,
excluded specimens, source freeze and original image identity. Inspect the
actual ledger and verify that the fixed-denominator union is at least 65%.

Commit and push the final accepted state; verify the remote HEAD and clean
worktree. Report the measured percentage, accepted byte gain, full-gate
results and proof artifacts. Mark the 65% goal complete only after that
audited state exists. If an external blocker prevents completion, retain
accurate progress and evidence instead of declaring the session finished.

## 6. 2026-10-13 follow-up probes

The `0x8c09970a` scene-owner nested-entry investigation now has a corrected
RAM fixture observer and a reusable body-union audit. Natural child entry was
absent in the first 2,000 frames of state 28. Synthetic nested probes then
proved 14 complete valid cases in the alternate-event seed (two specimens
were rejected), but their owner-body PC union is exactly the existing screen
baseline: **498/1,172 bytes, zero marginal bytes**. In particular, none of
those valid cases entered `0x8c099a18..0x8c099b72`. The audit is
`coverage_65_09970a_nested_probe_v9_union.json`; raw captures remain on D:.
This closes the current one-hypothesis triage pass for the synthetic branch.
Keep the owner excluded and move to another candidate unless new original
execution evidence changes its entry state. The accepted ledger and target
gap remain **276,578 / 434,656** and **5,949 bytes**.

The nullDC DevTools and AICA DSP references are already present under
gitignored `refs/`; the DevTools snapshot verifier passes. Their current
formats do not directly advance coverage: the frontend lacks a live debugger
backend, and the DSP playground consumes textual DSP registers/programs while
our `AICA_DUMP` capture contains sound RAM only. `docs/re/ref_nulldc_devtools.md`
records the concrete integration gap and the future register-export bridge.
