# Original execution screening for the 65% session

Baseline remains **267,230 / 434,656 bytes (61.48%)**. These experiments
grant **zero C coverage**. The target remains 282,527 bytes, with 15,297
verified bytes outstanding. The 62.5% and 65% full inventory gates remain
required by [the execution plan](coverage_65_one_session_plan.md).

## Captured evidence

All pilots execute the untouched original image in the fixed interpreter
observer, in save states 26 and 27. They vary typed controller records,
task descriptors, replay boundaries and owned RAM. Original instructions,
callback tables and architectural outputs are not fixture values.

| Pilot | Scope | Complete-body observations | Incomplete invocations | C credit |
| --- | --- | --- | ---: | ---: |
| `coverage_65_batch_screen_dev_v1` | 12 roots, 6,534 candidate bytes | initializer 94; geometry callback 750 | 1 | 0 |
| `coverage_65_batch_screen_dev_v2` | same roots; independent controller and selector dimensions | initializer 94; replay interpolation 158; geometry callback 750 | 1 | 0 |
| `coverage_65_batch_expand_dev_v1` | seven more roots, 6,714 candidate bytes | none | 0 | 0 |
| `coverage_65_batch_boundary_dev_v1` | four roots; crossed parameter limits, bounded history descriptor and circular lists | list interpolation 598 | 0 | 0 |

Whole-body observations above are unions of valid original specimens in
each pilot. They are research evidence, not development/holdout acceptance.
The first two campaigns are excluded from promotion because they contain
incomplete invocations. No routine has received a new binding or C credit.

The fourth pilot records 383 valid settings-menu invocations, 359 valid
list-interpolation invocations, 384 valid scene invocations and 384 valid
timed-effect invocations. It retains 24 rejected non-RAM list specimens
and two interrupted specimens. The circular-list fixture permits a stale
node to become detached in some combinations; those results stay excluded.
Its body observations are respectively 654/664, 598/598, 420/488 and
498/512 bytes. Neither a partial body nor a rejected invocation is waived.

The larger expansion completes both campaigns without incomplete
invocations. Its largest routines execute 698/2,084 bytes in the controller
menu and 876/1,574 bytes in character selection. They need further selector
and timer combinations before being eligible for promotion. The round-scene
candidate at `0x8c0996f4` also encounters SDK/BIOS exception and budget paths;
its 536/1,172-byte observation is not evidence that those dependencies work.

## Original callers and fixture findings

The original scene table at `0x0c10baa8` contains the menu/scene pointers
listed in each report. Their true callable entries precede the frozen owner
by their saved-register prologues. Pointer locations are static target
evidence; the reports explicitly mark executed callable proof as pending.

Two additional real transfers were checked in the untouched cached-address
disassembly:

- `0x8c090b76` loads the list-interpolation target from `0x8c090bc8`;
  `0x8c090b78` executes `JSR @r2`, with `R4 = R13` in its delay slot.
- `0x8c0c31de` branches to character selection at `0x8c0c3210`, after
  restoring the parent frame; its delay slot restores R14.

The list's interval test is **FR15 > FR14**, not the reversed comparison.
The replay-history index is loaded from the descriptor at global
`0x0c29bbd4`, offset 16. Bounding only the scene counter does not bound it.
The settings menu needs its decrement/increment boundaries crossed with
every selector; varying those fields with correlated strides misses paths.
The timed effect has separate words at offsets 16 and 18, and a mode-mask
case hidden by a correlated pause fixture.

The completed `coverage_65_selection_boundary_dev_v1` pilot crosses the
controller status, button, cursor, phase, timer and particle-age inputs for
four roots. Both states finish 1,024/1,024 invocations with no incomplete
specimens. Valid body observations are 1,682/2,084, 1,242/1,574, 472/504
and 210/210 bytes. Conversion finds 496-512 distinct valid specimens per
root; 31 interrupted specimens remain excluded. The round-count callback
is now a full-body development candidate, with caller/C/holdout still pending.

The large controller-menu owner has a likely unreachable branch at
`0x8c09c2cc`/`0x8c09c2ce`. R12 is initialized to 1. The flag tested at
`0x8c09c280` must have bit 0 clear to enter the later path. Before testing
it again at `0x8c09c2c8`, the intervening code can only OR bit 3 into the
same flag, with no intervening call. The second nonzero case therefore
cannot be reached in this original RAM model. Preserve the failed coverage
observation and park this owner unless new evidence changes that premise;
its 2,084 bytes are not reliable implementation-budget yield.

The new `coverage_65_batch_resident_dev_v1` tests the original sound
wrappers' resident-kit predicates. Mutable current-kit globals receive
IDs read from the untouched request tables. Original helper calls execute
normally; neither their returns nor immutable tables are patched. It also
crosses mutable settings bytes, scene-history phases and the independent
timed-effect counters. Both captures are complete.

Its first state has completed all 1,920 invocations, with no incomplete
records. It observes all 488 scene-history bytes and all 512 timed-effect
bytes. The resident menus remain partial (684/726 and 598/764). Two sound
test specimens reach `0xa0800074` and remain excluded device paths.
The second state also completes its 1,920 invocations and independently
executes both complete owners. Conversion yields 765 distinct valid scene
cases and 768 distinct timed-effect cases across both states. The other
roots have 747-768 distinct valid cases. The sound test retains 16 exception,
four non-RAM and one interrupted specimens; five settings-menu and three
scene interruptions remain excluded. No incomplete records exist.

The reset-settings owner `0x8c09bc2e` has a second proven obstacle:
the reset helper `0x8c08e5c4` calls the original byte setter at
`0x8c08e620`/`0x8c08e622`, writing zero to configuration offset 14.
The menu then reads that byte at `0x8c09be80`/`0x8c09be82`.
The nonzero branch `0x8c09be92` through `0x8c09be9a` cannot be reached
by supplying a different initial configuration value. Park this owner
without patching the helper or waiving whole-body coverage.

The prepared resident-menu v2 pilot excludes that owner and crosses
equal alternate characters, player swapping and both secondary controller
buttons for `0x8c09b36c`. Its original stage/character tables contain byte
rows; bounded neighboring selectors are explicit RAM input cases.

The prepared `coverage_65_batch_expand_dev_v2` adds seven previously
unscreened true callable prefixes, offering 7,916 advisory owner bytes.
They cover pause/scene handling and scene/UI initialization. Their nested
SDK, rendering and callback dependencies remain conditional on execution.
The 1,780-byte initialization owner at `0x8c09575c` is not included: its
disassembly explicitly writes PVR registers `0xa05f7890`/`0xa05f7894`.

The prepared clipping pilot tests eight SDK variants using a typed RAM
output cursor in R12. Their original helpers issue PREF against that cursor;
this experiment claims RAM behavior only. Their true prefixes start with
two extra R10/R9 saves, matched by extra pops just before RTS. The packed
strip pointer is saved R8 at frame offset 100, not saved R1. Original caller
pools include `0x8c057288`, `0x8c0566cc`, `0x8c05762c`, `0x8c056a50`,
`0x8c057a10`, `0x8c056e8c`, `0x8c058148` and `0x8c057e08`.
For example, `0x8c05725e` loads the first target, `0x8c057260` calls it,
and the delay slot copies R0 into the clip selector R4. These static facts
are not a substitute for executed caller proof.

`coverage_65_batch_candidate_budget_v1.json` measures this conditional
implementation pool against the current accepted half-open byte ranges:
2,810 bytes with whole-body original observations and 3,266 uncredited
clipping bytes, totaling **6,076 marginal bytes**. Clipping owner
`0x8c051f8e` is already credited and contributes zero new bytes; it is a
control in the new pilot. The snapshot explicitly marks the pool unproven
until the pending captures and caller/dependency gates succeed.
The initial 6,000-byte implementation batch has not yet passed the screening
requirements. Continue screening and then implement the batch; do not turn
these observed instruction bytes into a percentage claim.

## C batch development

The scene/UI expansion v2 completes its scheduled runs but retains one
incomplete invocation, so the entire campaign is excluded from promotion.
Its valid observations remain partial. Other specimens expose PVR
`0xa05f80b0`, MMU `0xff000038`, invalid RAM and SDK budget/interrupt paths.

The clipping pilot completes 512/512 original invocations in each state.
All eight bodies execute completely in each state. Conversion records
127-128 distinct valid cases per variant, with four interruptions retained
and excluded; there are no incomplete, non-RAM or exception records.
One variant was already credited, leaving 3,266 marginal clipping bytes.

Implementation has started as one 6,076-byte batch. The new shared
`clip_triangle.c` models the six visible topologies, vertex-format stride,
original helper order, banked final command and full register/float frame.
`clip_profiles.inc` contains fixed ABI addresses extracted from the original
image, not opcodes or expected results. `replay_setup.c` implements ring
initialization and actor interpolation. Syntax checks pass with warnings
treated as errors.

Provisional strict development replay results:

- Replay initializer: 166/166 matches, zero skips.
- Replay interpolation: 152/152 matches, zero skips.
- Clipping entry `0x8c051918`: 128/128 matches after implementing its plain
  scalar packet emitter; entry `0x8c0525c0`: 127/127 matches.
- Previously credited clipping control `0x8c051f50`: 127/127 matches.
- The other clipping formats identify missing native copy/intersection
  helper entries. Their failed replay report and executable are retained.

These are development results. The earlier replay screening corpus also
contains an incomplete invocation and cannot serve as an accepted campaign.
The provisional v2 executable and all 392 compiled-source inputs are
archived in `ram_clipping_batch_dev_v2_complete_sources/manifest.json`.
Finish the remaining helpers and five scene/geometry/effect routines,
then capture a complete batch development campaign and perform the official
freeze, disjoint holdout, original caller proofs and regression gates.
No binding or verified C credit has changed.

The new `clip_attributes.c` closes the five unweighted vertex formats,
including indexed/inline ARGB, signed texture coordinates, packed coordinate
words and alpha adjustment. Native development v3 passes **all eight clipping
variants, 1,020/1,020 cases with zero skips and zero OOB**. Its complete
393-file source snapshot and executable are retained separately from v2.
The conditional pool's clipping portion is now implemented in development;
it still needs the final complete-batch freeze, disjoint holdout and callers.

`scene_replay_flow.c` adds the round clock, history transition, actor history
run coalescing, scene-end predicate and secondary scene dispatcher.
`replay_setup.c` also adds the signed-round block clear with MACL preservation.
Development v6 matches 374/504 round-clock cases and 324/765 scene-history
cases. The remaining cases report genuine missing helpers at
`0x0c09705e` and `0x0c0994fa`; failed reports and executables are retained.
Those helpers and the remaining geometry/list/timed-effect routines must be
completed before this batch can qualify. Source changes remain uncommitted
development work; there is no new binding, holdout or percentage claim.

The targeted resident-menu v2 pilot also completes both original states
without incomplete invocations. It has 511 distinct valid cases and one
excluded interruption, but only 652/726 owner bytes. It remains outside
the initial implementation batch.

Further scene closure adds the round retirement and activation predicates,
replay readiness/status transitions and the original replay-wait branch.
Development v7 now matches **504/504 round-clock cases**; development v8
matches **765/765 scene-history cases**, both with zero skips and zero OOB.
The provisional v8 complete source archive contains 395 compiled inputs.

`timed_boundary_effect.c` retains the two actor sweeps, edge-entry flags,
original sound/motion helper ordering and separate lifetime thresholds.
Development v9 matches **768/768 cases**, zero skips/OOB. The second sweep
uses the original temporary stack countdown rather than the first sweep's
different local slot.

`list_interpolation.c` retains circular-list head transfers, neighbor
selection, degenerate interval handling, seven tangent pairs and cubic
channel evaluation. Development v10 matches **359/359 valid cases**, zero
skips/OOB. The original 24 non-RAM list specimens remain excluded and are
not replaced by a sanitizing behavior change. V10's executable and all
397 compiled inputs are retained as a provisional development snapshot.

All fourteen primary entries now have passing preliminary development
replays, covering the planned 6,076 candidate bytes. Geometry v16 matches
**165/165 cases** and all eight clipping entries still match **1,020/1,020**,
with zero skips. Geometry's NaN sign discrepancy exposed a shared FTRV
operand-choice issue: the frozen observer's packed MULPD retains the matrix
NaN in even rows and the vector NaN in odd rows. The explicit FPU model now
retains that choice, including payloads and signaling-input quieting. Its
opcode suite passes **213,312/213,312** cases. The diagnostic disassembly
and original trace are retained; production geometry has no debug logging.

A fresh complete development campaign combines the retained typed inputs
for all fourteen entries plus the already-credited clipping control:
`coverage_65_complete_batch_dev_v1`, 384 rounds in each of states 26 and 27.
V1 exceeded its configured 900-second deadline before the requested frame
count in state 26. State 27 was stopped after confirming that failure; all
raw files are retained and the campaign is unqualified. Fresh v2 inputs
retain the complete batch and 384 rounds, with a longer capture deadline.
V2 is running with a 2,400-second deadline per state. All 39 required native suites and 272 oracle tool
tests passed at that development point. The full baseline regression now
passes all 1,396 bindings against the immutable v16 matrix executable and
rebuilt required targets. Its 60 executables, 398-source snapshot, 39 native
suites and 286-test tool result are archived as the provisional v16 full gate.
The newer interpolation/initializer caller checks bring the current oracle
suite to 286 passing tests.

Fresh v2 state 26 completed 48,000 requested frames with 1,829 accounted
invocations, no incomplete/unaccounted records, and every selected frozen
owner fully executed. The original trigger produced approximately 122
invocations per entry rather than all 384 scheduled variants; actual
valid/distinct counts, rather than requested quotas, govern qualification.
First-scenario native replay is running; state 27 capture continues. Prior incomplete
screening campaigns remain ineligible for qualification. These figures are implementation progress,
not accepted C credit. Complete fresh development, freeze the final batch,
then perform disjoint holdout, caller proofs and full checkpoint gates.

## Reproduction and retention

Generators, watch lists and explicit typed input JSON are committed under
`tools/oracle/`; original captures and patches remain ignored local evidence.
The reports hash-pin the capsules, accounting summaries, original observer,
state files, input patches, logs, image and frozen body inventory. New reports
also pin their explicit input files, watch lists and owner maps.

`tools/oracle/coverage_65_screening_checkpoint.py` seals the retained
reports together with the typed inputs, generators and prior accepted replay
callback seal. Its audit grants zero credit and refuses to overwrite evidence.
The next pilot's prepared inputs are pinned as inputs, not as completed
captures. The earlier screening checkpoints changed no compiled C and
claimed no native regression or holdout source freeze. The current C work
is provisional development, not a promoted coverage milestone.

## Complete development freeze and holdout in progress

Fresh development v2 completes both 48,000-frame original scenarios with
zero incomplete/unaccounted records and zero nondeterministic entries.
Every selected owner is independently whole in each scenario and has at
least 64 valid cases in each. All 15 combined entry replays pass against
v16, with zero skips and no device accesses in valid development specimens.
Invalid interrupt/non-RAM specimens remain retained and excluded.

`ram_clipping_batch_qualified_development_freeze_v1.json` in the evidence
cache seals this complete development result, the unchanged 398 compiled
inputs, immutable native executable and full 1,396-binding baseline gate.
The disjoint holdout `coverage_65_complete_batch_accept_v1` began afterward
in states 28/29, with objects relocated by `0x100000`, changed typed sequence
phases, changed clipping attributes/normalization, and FPSCR `0x240001`.
Its input manifest pins the formal development freeze. Holdout execution,
remaining scene callers, promotion audit and checkpoint binding additions
remain pending; accepted coverage is still 267,230/434,656 bytes.
