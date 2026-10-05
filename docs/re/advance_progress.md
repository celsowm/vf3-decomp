# Next ten-point campaign progress

The campaign starts at 206,062 unique C bytes and targets 249,528 bytes.
Thirty-two accepted batches add **22,718 bytes**, reaching **228,780 / 434,656
(52.6347%)**, a gain of **5.2267 percentage points**. The remaining shortfall
to the ten-point campaign target is **20,748 bytes**. The first checkpoint
at 227,795 bytes has passed; the next checkpoint is 239,061 bytes.

## Descriptor initializers

`0x8c037e6e`, `0x8c037f2e`, and `0x8c037ffe` initialize related object records.
The frozen seeds occur 14 bytes after their original prologues. Fixtures retain
the established R0=64 indexed offset, R3=8 selector, R4=0 field value, and
`0x03f3ffff` header already stored through R14. The port follows original field
writes and invokes existing helpers for subsequent setup and tail behavior.

All three bodies execute completely. Strict replay passes **1,530/1,530
development cases** across states 21/27 and **765/765 independent acceptance
cases** across states 23/29, with zero skips. Acceptance changes the finite
input palette and relocates fixture pointers by `0x100000`. No acceptance
results were used to change the implementation.

Source: `src/fight/advance_closure_adapters.c` (244 emitted statements, zero
unsupported instructions). Immutable replay binary:
`build/vf3matrixfamily_advance_initializers.exe`. Proof:
`tools/oracle/advance_initializers_milestone.json`. The full CMake build and
artifact-hash/union audit pass. Full repository regression passes, including
all 949 previously bound replays and native replay tests. The new bindings
pass their separate strict development and acceptance runs. The retained
regression log is `extract/analysis/advance_initializers_regression.log`.

## Scene workers and nested helpers

Six new worker bodies add 1,278 unique bytes: `0x8c03dad0`, `0x8c03ea22`,
`0x8c06c6d6`, `0x8c085666`, `0x8c0abcdc`, and `0x8c0ca0c6`.
Development passes 2,669 strict cases. Independent acceptance uses states
23/29, relocated fixtures and holdout inputs. The seventh implemented worker,
`0x8c04baf6`, passes replay but remains uncredited because its acceptance
capture includes an incomplete invocation.

The worker source is `src/fight/advance_worker_adapters.c`; the immutable proof
executable is `build/vf3matrixfamily_advance_workers.exe`. Three existing shared
helpers receive fresh whole-body proof and add another 222 bytes:
`0x8c06c398`, `0x8c06c5c8`, and `0x8c08583c`. Their development replay passes
1,485 cases and acceptance passes 1,376 cases, with zero skips. Ownership is
recorded per source in `tools/oracle/advance_helper_ports.json`.

Nested capture exposed an oracle rollback bug, fixed in `cb36f29`. See
`docs/re/nested_capture_boundary.md`. Only fresh corrected child observations
support the helper milestone. The campaign union and all three manifests pass
the artifact-hash audit. Repository regression passes; its retained
log is `extract/analysis/advance_workers_regression.log`.

## Completed recaptures and original gameplay

Longer development recaptures (150 frames per state) finish all invocations in
20 previously complete-body candidates. Nineteen pass strict development and
independent acceptance, adding 3,876 unique bytes. `0x8c047230` fails at an
external firmware dependency and remains uncredited. Eight one-call workers
add 984 bytes; two descriptor leaves add 192 bytes. Fresh probe-only acceptance
also clears the incomplete-invocation blocker on `0x8c04baf6`, adding 162 bytes.

The accepted expanded batch is implemented in `advance_worker_adapters.c`.
It passes all seven earlier parent replays again. The full CMake build passes.
The previous integration's regression passes all 952 bound replays plus native
tests; the expanded integration's regression passes separately in
`extract/analysis/advance_expanded_regression.log`.

Seven original-gameplay routines add 332 unique bytes, with 4,775 strict
development cases from states 10/20/25/40 and independent acceptance from
states 14/23/29/44. A filtered development corpus preserves provenance and
excludes an unrelated quarantined entry. New proof reports hash the immutable
executable `build/vf3matrixfamily_advance_natural_proof.exe`.

The original gameplay failures are retained. `0x8c03523c`, `0x8c045f62`, and
`0x8c062ec4` reach the emulator's GD-ROM firmware trap (`0x8c001006`, opcode
`0x085b`), which the current C dependency model cannot reproduce. `0x8c094242`
fails device/register replay. No partial successes from these entries are
counted. The larger gameplay bodies also retain missing body paths.

## Remaining queue execution

Two additional leaf batches add 638 unique bytes. Development and relocated
holdout acceptance pass strictly; firmware-dependent leaves remain excluded.

The next ranked leaf batch accepts four entries for 506 unique bytes. `0x8c0591a0`
matches its complete body across 478 development cases and 223 independent
holdout cases. `0x8c088222` and `0x8c08b73c` match 510/511 development cases and
256 acceptance cases each. `0x8c07ef90` covers all 100 body bytes across 132
development cases and 61 independent holdout cases. Strict replay has zero
skipped cases.

The vector-grid batch adds 1,380 unique bytes from 23 frozen entries. Starting
at the real `0x8c072076` prologue initializes the stack and 24-byte record stride
before observing its internal blocks. `grid_probe_plan.py` supplies finite
vectors, bounded dimensions and the original descriptor selectors. Development
uses states 21/27; acceptance uses states 23/29, different dimensions and finite
values, and pointers relocated by `0x100000`. All selected invocations match
complete registers and captured RAM with zero skips. Proof executable:
`build/vf3matrixfamily_advance_grid.exe`; manifest:
`tools/oracle/advance_grid_milestone.json`. The off-inventory parent receives no
credit, and `0x8c0727b4` remains excluded for incomplete body execution.

The next ranked leaf batch adds 218 unique bytes across `0x8c0ac192`,
`0x8c08d406`, and `0x8c0876f2`. Development captures contain 192, 415, and 415
distinct cases; independent relocated acceptance contains 768, 1,024, and
1,024. Each root executes its full frozen body. All six strict replays match
complete state with zero skips. `translate_adapters.py` emits a separate
1,417-statement adapter with no unsupported instructions. The full build passes;
the milestone is `tools/oracle/advance_ranked_fourth_milestone.json`.

`0x8c0c8b52` is not credited. Its body executed completely, but the generic
trigger produced acceptance cases in only one state, short of the two-scenario
holdout gate.

Two final ranked leaves add 1,346 unique bytes: manager `0x8c0c2278` contributes
984 bytes and `0x8c041b94` contributes 362. The manager's existing adapter
already owned its root; its 939 development cases across two scenarios and 128
relocated holdout cases pass strict replay with zero skips. The leaf adapter is
newly emitted as 181 statements with no unsupported instructions. Its complete
362-byte body executes across 366 development cases from state21 and state21
with the m26 input script; 128 independent state21/m26 holdout cases relocate
fixture pointers by `0x100000`. Both leaf replay reports pass with zero skips.
Proof manifests are `tools/oracle/advance_large_manager_milestone.json` and
`tools/oracle/advance_leaf_041b94_milestone.json`.

The reusable capsule inspector now summarizes initial aligned RAM words with
`inspect_capsule.py --memory-summary`, which helped isolate the leaf's selector
cross-product and shift threshold.

The original-image codec at `0x8c05b20e` adds 1,322 unique bytes. Its 661-
statement adapter has no unsupported instructions and reuses the existing
`0x8c042efc` and `0x8c05af5c` helper owners. Strict development replay passes
509/509 cases across state21 and state21/m26 scenarios; the complete 1,322-byte
body executes. Independent relocated state21/m26 acceptance passes 128/128
cases, with zero skips. The immutable replay executable is
`build/vf3matrixfamily_advance_05b20e.exe`; proof is recorded in
`tools/oracle/advance_05b20e_milestone.json`.

The reusable `tools/oracle/rampc_audit.py` parses RAM-window snapshots directly
from Flycast traces and summarizes nonzero and changing words. On trigger
`0x8c048284`, the full 512 KiB at `0x0c500000` was zero in 32 snapshots across
states 21/27. The equally sized `0x0c700000` window contained 96,054 nonzero
words. This is recorded as memory observation only; it does not change any
probe allocator or earn C coverage.

Watching repeated loop blocks revealed that the oracle must retain one active
observation per entry and call depth. Revisiting a block at the same depth now
extends its existing observation; recursion at a deeper depth still starts a
new observation. This prevents repeated loop visits from exhausting the active
capture limit. Only fresh captures from the corrected oracle support the grid
milestone. The earlier generic parent fixture failed and is excluded.

`prologue_roots.py` suggests nearby original prologues; its output is advisory.
`range_watch.py` selects their frozen children, and `isolate_planned.py
--observe-watch` captures children while probing only the selected parents.
The ranked queue now preserves byte priority and can exclude already attempted
progress entries. These tools replace repeated inline extraction scripts.

The first broad queue comprises 150 roots with 40,984 potential marginal bytes;
potential is not credit. Captures are serial and resumable with
`isolate_planned.py`; a `STOP` file pauses between roots for acceptance captures.
The next queue contains 150 roots with one unresolved dynamic call site each,
representing another 29,384 potential bytes before overlap and proof.
The next 500 previously unattempted zero-dynamic-call roots represent 32,840
potential unique bytes. They include smaller SDK-attributed routines needing
actual C invocation proof; attribution is not counted as C coverage.

`0x8c0c051a` adds 506 unique bytes. Its 789 development cases span state21
without input and state21 with the m26 input script; every frozen body PC ran.
The independent relocated state21/m26 holdout passes 128/128 strict cases and
also covers the complete body. The reusable register and RAM override files
exercise the descriptor tag, selector, and frame-threshold branches. Proof is
recorded in `tools/oracle/advance_0c051a_milestone.json` using the immutable
`build/vf3matrixfamily_advance_05b20e.exe` snapshot.

`0x8c062616` adds 142 unique bytes. Existing state20/21 captures and a synthetic
three-node ordering provide 132 distinct development cases; every frozen body
PC executes and strict replay passes with zero skips. A separate three-node
holdout relocates the RAM graph by `0x100000` and passes 128/128 strict cases.
The existing survey adapter owns the routine; register and RAM profiles are
`tools/oracle/advance_062616_register_overrides.json` and
`tools/oracle/advance_062616_memory_overrides.json`. Proof is recorded in
`tools/oracle/advance_062616_milestone.json`.

`0x8c0632d2` adds 92 unique bytes. The merged development corpus combines
natural state20/21 runs with an explicit table-match fixture and has 513
distinct complete cases; every frozen body PC executes. Strict replay passes
513/513 development cases and 256/256 independent state23/29 holdout cases.
The holdout reaches 74/92 body bytes, while development reaches 92/92. Register
and table-word profiles are recorded in `tools/oracle/advance_0632d2_*` and
the milestone proof is `tools/oracle/advance_0632d2_milestone.json`.

`0x8c04a4c4` reaches 500/506 body bytes, but its entry path sets R11=1 before
the missing R11=0 exit. Keep it uncredited while the frozen boundary is reviewed.
The revised `0x8c0877ac` probe reaches 276/280 bytes; its remaining conditional
exit appears incompatible with the preceding squared-value comparison and
needs a reachability review. `0x8c0c8334` remains blocked on descriptor/table
state and incomplete variants. Failed or incomplete corpora remain uncredited.

`0x8c0c0772` adds 990 unique bytes. Its merged development corpus contains
3,532 distinct complete cases and executes every frozen body PC. Independent
relocated acceptance across states 23/29 passes 256/256 strict cases with zero
skips. The existing expanded adapter owns the body; the manifest is
`tools/oracle/advance_0c0772_milestone.json`.

`0x8c05cc38` remains uncredited. An R13 selector sweep and a combined floating
input/selector sweep leave its body at 1,072/1,290 executed bytes. The merged
development corpus retains 2,529 distinct complete cases. Its indirect resource
lookup now has a shared readable C implementation in
`src/fight/advance_dynamic_06129c.c`; this dependency implementation receives
no independent coverage credit. All 2,529 merged cases pass strict replay with
zero skips against `build/vf3matrixfamily_advance_final.exe`, recorded in
`extract/analysis/advance_05cc38_final_replay.json`. The remaining branch clusters require
different resource/table state. `0x8c0c8334` similarly remains uncredited at
628/638 executed body bytes after two descriptor profiles.

The final twenty-one-milestone chain is audited with all artifact hashes in
`extract/analysis/advance_series_final_audit.json`. The `0x8c0632d2` development
and acceptance proofs were replayed against the immutable final executable
snapshot before rebinding their proof records. Frozen original image,
inventory, body ranges, prior baseline, and prior manifests are preserved.

Final integration passes the full CMake build and
`python tools/verify_all.py --no-build --jobs 4`: all 1,048 bound replays,
native replay checks, prior batch audits, complete body coverage, SDK union,
and call-resolution checks pass. The retained regression log is
`extract/analysis/advance_final_regression.log`.

## Resumed campaign after 865e4a6

The target remains 249,528 unique C bytes. Existing image, inventory, body
ranges and baseline hashes remain frozen. Work includes game families and
independently implemented pure SDK helpers under the same invocation gates.

`0x8c05ee6e` adds 486 unique bytes. A descriptor tag fixture exercises every
frozen body PC in 512 development cases across states 21/27. Independent
relocated states 23/29 use changed tags and scalar inputs and pass 256 strict
cases. Both corpora replay with zero skips against the immutable
`build/vf3matrixfamily_advance_resume.exe`. The existing matrix adapter owns
the implementation. The artifact-hash audit passes for
`tools/oracle/advance_resume_05ee6e_milestone.json`.

The floating-register inspector exposed a 100.0 comparison value in
`0x8c05cc38`; earlier sweeps stopped at 50.0. A threshold-specific profile
adds 36 executed body bytes. The merged corpus contains 2,924 complete cases
and reaches 1,108/1,290 body bytes; the root remains uncredited.

The initial `0x8c0609b8` direct fixture produced no valid complete cases.
Original disassembly places the saved R14/R13/R12 prologue at `0x8c0609ae`.
The next attempt observes the frozen child while probing that original parent.
That second capture also produces no valid complete cases, with budget and
invalid-memory flags retained in its raw specimens. It is parked after these
two attempts, pending a coherent original runtime contract.

Seven reusable-tool checks pass: architectural register indexing, invalid names,
floating bit formatting, unavailable registers, helper ownership without
ledger credit, and queue selection that excludes attributed-only dependencies
and attempted entries while measuring overlapping bodies by union. The family
ranker also checks that dependency cycles terminate and overlapping families
contribute only marginal address-union bytes.

All seven additional development states (11/15/22/26/30/34/38) complete 900-frame
discovery runs. Combined with prior discovery, 99 unported roots covering
13,020 potential unique bytes occur in at least two runs, up from 65 roots and
9,856 bytes before this tranche. No new root appears; the increase is scenario
diversity. A focused eight-root natural resource/scene capture follows.

`0x8c061910` adds 136 unique bytes. Development uses two-node descriptor
lists with disabled records and signed maxima: all 136 frozen body bytes
execute and 512/512 strict cases pass. Independent acceptance changes to
three-node lists, changes flags and values, and relocates every fixture
pointer by `0x100000`: 256/256 strict cases pass with full body execution.
The immutable executable is `build/vf3matrixfamily_advance_resource_descriptor.exe`;
the proof is `tools/oracle/advance_resume_061910_milestone.json`.

The natural resource capture identified a missing descriptor dependency at
`0x8c05c7c6`. Its readable C implementation in
`src/fight/advance_resource_descriptor.c` follows the original five-word copy,
saved positions, parity selector and ring offsets, retaining the original
reload order for aliasing. Direct mode/selector fixtures pass 256/256 strict
development cases and 256/256 changed, relocated acceptance cases. The parent
`0x8c059f8a` now passes all 474 natural cases. Neither helper nor parent gains
coverage credit: the helper lacks its own frozen inventory interval, and the
parent executes only 540/1,242 frozen body bytes.

The other natural resource roots remain uncredited. `0x8c063d36` executes
258/512 bytes and passes 512 strict cases; `0x8c063894` executes 54/512 bytes
and passes 473 cases. `0x8c064246` and `0x8c09635a` retain strict failures on
uncaptured RAM reads. Directed SDK selector attempts at `0x8c040e28`
and `0x8c040c92` add no body PCs after their generic captures; both are parked
pending a supported firmware contract. These results retain their original
raw evidence and do not alter frozen intervals.

`0x8c06c8b2` reaches all 142 frozen body bytes using bounded command masks,
global scene flags, paired counters and queue occupancy. The merged development
corpus has 495 distinct cases across states 21/22 and passes strict replay with
zero skips. Its independent acceptance capture in reserved states
23/29/24/28 produces no valid complete cases: all 512 invocations access
`0xff000038`. The root remains uncredited; the development success cannot
substitute for an independent supported runtime contract.

Ten campaign-tool checks now pass, including shared legacy/grouped attempt
history, family caller exclusions that retain dependency costs, and 100
deterministic interval comparisons against the original address-union method.
The optimized family ranker reproduces the earlier 30-family report exactly
(SHA-256 `9bda53e4e69398a30aa9c40faab527c57cade8443a3ad6b21b0aebc76b29f65b`)
in 0.51 seconds.

Integration passes the full CMake build and all 1,050 bound replays and native
checks in `python tools/verify_all.py --no-build --jobs 4`, including frozen
body coverage, SDK union and call-resolution checks. The regression log is
`extract/analysis/advance_resume_resource_regression.log`. All 23 milestone
artifact hashes and their byte-union chain pass in
`extract/analysis/advance_resume_series_audit.json`. The two subsequent scene
commands and their capture cohort remain development work outside this ledger
milestone.

## Remaining small routines

A 64-root development cohort yields 23 complete-body candidates. All
**11,694/11,694 development cases** pass strict replay across states 21/27.
Independent states 23/29 use changed integer/floating inputs and fixture
relocation by `0x100000`; **5,877/5,877 cases** pass with zero skips. Each
selected root also executes its entire frozen body in acceptance. The cohort
adds **932 unique bytes**, with source ownership preserved in
`tools/oracle/advance_resume_small_ports.json` and proofs in
`tools/oracle/advance_resume_small_milestone.json`. The executable snapshot is
`build/vf3matrixfamily_advance_small_final.exe`.

Eight new readable C routines in `src/fight/advance_scene_commands.c` cover
descriptor flags, sequential entry resets, transform reset, packed command
descriptors, a command without a payload, scalar offsets applied to a sample
ring, coordinate subtraction and scene state reset. Existing verified C
helpers retain ownership of their operations. A missing scene-selector helper
at `0x8c09abc4` is also implemented there; 512 direct development cases and
256 changed acceptance cases pass. It receives no independent ledger credit
because it has no frozen inventory interval.

The diagnostic resource replay identifies the first uncaptured read as
`0x0c001006/4` for `0x8c064246` and `0x8c09635a`. The original opcode there
is the `0x085b` REIOS GD-ROM firmware trap (see Flycast's `reios.h` and
`reios.cpp`), so this is a firmware dependency. The existing low-RAM C adapter
does not model that trap; both parents remain outside the accepted cohort.

Boot and scripted gameplay discovery both complete 3,000 frames within the
120-second cap. The longer 4,800-frame attempts timed out and are excluded.
Combined discovery still reaches 218 unported roots, with 200 roots and
30,678 potential bytes observed in at least two scenarios; no new root appears.
These are prospective bytes, not coverage credit.

The linked-source ownership tool finds 1,869 advisory owners after including
resolved call targets. It uses actual CMake target dependencies and dispatcher
priority, includes local adapter fragments, and excludes retired sources.
Thirteen reusable-tool checks pass. A new queue option retains explicit unknown
indirect sites while requiring all direct C dependencies to be available.

The full integration regression passes in
`extract/analysis/advance_resume_small_regression.log`, including 1,073 campaign
C bindings and frozen-body, SDK-union and call-resolution checks. All 24
milestone hashes and the campaign byte-union chain pass in
`extract/analysis/advance_resume_small_series_audit.json`.

## Calendar, record and render helpers

Ten roots add **854 unique bytes** in
`tools/oracle/advance_resume_static_milestone.json`. All **6,797 development
cases** and **2,312 independent acceptance cases** pass strict replay with zero
skips. Development executes every frozen body PC; acceptance uses states 23/29,
changed inputs and fixture relocation by `0x100000`. The source ownership map is
`tools/oracle/advance_resume_static_ports.json`.

Six further roots add **760 unique bytes** in
`tools/oracle/advance_resume_render_milestone.json`. All **2,452 development
cases** and **2,670 independent acceptance cases** pass. These implement scene
indicator callbacks and repeated record transforms, and verify additional
existing C owners. Some acceptance paths cover fewer PCs than development;
full development bodies, varied acceptance inputs and strict replay remain the
credit gates. Ownership is in `tools/oracle/advance_resume_render_ports.json`.
Both batches use immutable snapshot
`build/vf3matrixfamily_advance_render_final.exe`.

The original scene/controller dependency and both indicator callbacks are
statically translated in `src/fight/advance_controller_adapters.c`; 517 original
statements have zero unsupported instructions. The readable entry models are
`src/fight/advance_static_helpers.c` and `src/fight/advance_render_helpers.c`.
Helpers without their own accepted frozen-body proof receive no independent
credit.

The fixture generator now relocates explicitly overridden GPR pointers with
their RAM words while preserving FR/XF bit patterns. A dedicated regression
check passes. With the optional longer prologue-prefix check, 15 reusable-tool
checks pass. The initial mismatched
acceptance fixtures remain archived; credit uses the repeated, correctly
relocated capture only. Promotion also explicitly requires at least 64 distinct
acceptance cases in two scenarios disjoint from development.

Nested rollback capture is checked separately with the verified calendar entry
and its original unsigned arithmetic callees: **128/128 cases per entry** pass
strict replay, across states 21/27. Proof:
`extract/analysis/advance_resume_probe_children_regression_proof.json`.
The prologue finder preserves its 32-byte default; `--prefix-distance 64` finds
the saved-r14 prefix at `0x8c08ffd0`, 48 bytes before the frozen vector entry.
That wider-prefix development capture reaches 1,574/1,586 vector-body bytes.
Additional projection and zero-distance contracts bring the merged development
corpus to 1,586/1,586 bytes across 1,265 cases in two scenarios. The routine
is accepted below following C replay and independent acceptance.

The family campaign also verifies the original `0x8c0c298c` prologue and frozen
child `0x8c0c2992`, both owned by existing `src/fight/next_adapters.c`. Complete
development bodies and **632/632 strict development cases** pass. Reserved
states 23/29 provide **338/338 changed acceptance cases** with relocated fixture
pointers, at least 64 inputs and two scenarios per entry. Their **394-byte**
union gain is recorded in `tools/oracle/advance_resume_family_milestone.json`.

The integrated native build and full repository regression pass after the
static and render source changes (`advance_resume_static_final_regression.log`).
The family milestone reuses unchanged native sources and has separate strict
development and acceptance proofs.

## Record rendering and vector projection

Seven roots add **958 unique bytes** in
`tools/oracle/advance_resume_records_milestone.json`. All **3,576/3,576
development cases** and **3,576/3,576 independent acceptance cases** pass
strict replay with zero skips. Four readable models in
`src/fight/advance_record_render.c` preserve the original matrix stack, draw
calls, floating registers and repeated record writes. The other three roots
use existing C owners listed in `advance_resume_records_ports.json`.

The vector root `0x8c090000` adds **1,586 unique bytes** in
`tools/oracle/advance_resume_vector_milestone.json`. Its original prologue at
`0x8c08ffd0` supplies the saved r14 and float registers. Projection and
zero-distance RAM contracts give **1,265/1,265 development cases** and
**505/505 independent acceptance cases**, across two scenarios each. Both
corpora execute every frozen body PC. Acceptance uses changed finite floats,
independent flags and coordinate strides, and relocated pointers in states
23/29. The 793 original statements have zero unsupported instructions.

Both milestones use immutable snapshot
`build/vf3matrixfamily_advance_records_dev.exe` (SHA-256
`5965b6a0a797277a0445ad7ad2746fe30247c90d53a85af8b3ad01b31c820870`).
Their complete artifact-hash and interval-union audits pass. The preceding
27-milestone series audit also passes; the campaign target remains unmet.

The integrated build and full repository regression pass in
`extract/analysis/advance_resume_records_regression.log`.

## Configuration editors and SDK clients

Twenty-five roots add **1,244 unique bytes** in
`tools/oracle/advance_resume_config_milestone.json`. Strict replay passes
**12,673/12,673 development cases** and **12,588/12,588 independent acceptance
cases**, with zero skips and complete frozen bodies in both corpora.
Fifteen readable configuration editors preserve byte/word access, bounds,
steps and calls to the original editor. `config_editor_map.py` recovers their
parameters and validates their instruction patterns against the original image.

`src/fight/advance_client_wrappers.c` preserves client validation, error returns,
SDK calls and the original slot-index helper. Actual SDK operation bodies are
translated in `advance_client_helper_adapters.c`; they retain query loops and
status/error calls. Those dependencies receive no independent body credit.
Two existing C owners also receive fresh complete-body proof. The immutable
snapshot is `build/vf3matrixfamily_advance_clients_final.exe`.

## Scene predicates and projected record loops

`0x8c0ab8f0` and `0x8c0c1ac2` add **612 unique bytes** in
`tools/oracle/advance_resume_branch_milestone.json`. All **836/836 development
cases** and **851/851 independent acceptance cases** pass strict replay with
zero skips. Merged development evidence executes every frozen body PC across
two scenarios per root. Acceptance changes counters, scene and descriptor flags,
record identifiers and fixture addresses in reserved states 23/29; it need not
repeat every development branch. The 448 translated statements have zero
unsupported instructions and preserve the original rendering dependencies.

The complete 31-milestone artifact-hash audit passes: 177 newly credited entries
add 22,636 unique bytes with the frozen image and body ranges unchanged.
The integrated build and full repository regression also pass in
`extract/analysis/advance_resume_config_regression.log`. Nineteen reusable-tool
checks pass, including the new advisory retained-capture catalog.

All four new milestone artifact-hash and interval-union audits pass. Two SDK
child capture attempts, including explicit output-buffer contracts, add no new
body PCs. These partial helpers remain uncredited and that fixture approach is
parked pending a supported runtime contract.

## Randomized pair selector

The retained-capture catalog identifies `0x8c0c8b52`, whose earlier acceptance
lacked a second valid scenario. Rechecking its untouched raw development
evidence gives complete frozen-body execution and **135/135 strict cases** in
states 21/27. Fresh states 23/29 use changed pair record flags, relocated object
pointers and the original scene guard. They execute the complete body and pass
**512/512 strict acceptance cases**, with zero skips. The actual RNG and scene
callee remain intact. The existing owner is `src/fight/device_adapters.c`.

`tools/oracle/advance_resume_pair_milestone.json` adds **82 unique bytes**.
Development uses `build/vf3matrixfamily_advance_clients_final.exe`; acceptance
uses `build/vf3matrixfamily_advance_small_tail_final_dev.exe`. The owner is
unchanged from the passing integrated regression; the new root has separate
strict proofs and independent artifact hashes.
