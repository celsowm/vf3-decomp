# Target campaign continuation, 2026-10-05

**2026-10-08 update:** the original 249,528-byte target is achieved.
Two independently accepted milestones in the
[percentage expansion campaign](percentage_campaign.md) add 812 unique bytes,
reaching **249,566 / 434,656 (57.42%)**. The next main checkpoint is **65%**.
The dated checkpoint sections below preserve their historical totals.

The campaign target remains **249,528 verified unique C bytes**. Starting at
233,838, twelve accepted milestones add **9,418 bytes across 80 frozen roots**,
reaching **243,256 / 434,656 (55.9652%)**. **6,272 bytes remain**. These gains
include newly verified existing static translations; they are not all new
readable implementations. SDK attribution supplies no coverage credit.

| Milestone | Roots | Unique bytes | Development / acceptance |
|---|---:|---:|---|
| `advance_target_motion_milestone.json` | 2 | 406 | Original bounded record walker, separate states and relocation |
| `advance_target_commands_milestone.json` | 8 | 940 | 1,400 strict development cases; fresh selector inputs and relocated queue |
| `advance_target_command_pair_milestone.json` | 1 | 84 | 152 development and 152 acceptance cases |
| `advance_target_families_milestone.json` | 10 | 1,476 | 5,168 development and 4,376 acceptance cases |
| `advance_target_extra_milestone.json` | 6 | 522 | 2,589 development and 2,596 acceptance cases |
| `advance_target_broad_milestone.json` | 12 | 2,240 | Whole bodies; 4,562 development and 5,423 acceptance cases |
| `advance_target_extended_milestone.json` | 24 | 1,326 | Strict development and independent acceptance; BIOS cases excluded |
| `advance_target_scenario_milestone.json` | 1 | 246 | 483 development cases in states 21/25; 484 acceptance cases in 23/29 |
| `advance_target_extended_scenes_milestone.json` | 3 | 184 | Additional independent acceptance states 24/26; unchanged C |
| `advance_target_retained_milestone.json` | 1 | 142 | Retained whole-body development in 21/22; 671 fresh acceptance cases |
| `advance_target_closure_milestone.json` | 11 | 1,750 | New helper closure; original bodies in 21/27 and independent acceptance |
| `advance_target_closure_tail_milestone.json` | 1 | 102 | Final completed replay report: 446 development and 449 acceptance cases |

Every newly credited root executes its entire frozen body in development,
with at least 64 distinct complete inputs across two original scenarios.
Acceptance uses independent scenarios, changed inputs and relocation by
`0x100000`. Complete architectural, captured RAM and ordered device replay
passes with zero skips. Acceptance results did not drive implementation edits.
The original image, inventory and body ranges retain their frozen hashes.
Per-root immutable executable hashes and artifact digests are in the milestone
manifests under `tools/oracle/`.

## Readable command encoders

`src/fight/command_encoders.c` models nine frozen scalar/channel command roots
(1,024 bytes), their original prologues and the real enqueue operation. It
preserves selector packing, 24-byte channel stride, enabled bytes, busy and
invalid-command errors, queue advancement/wrap, scratch stores, condition bit
and caller state. The independent queue fixtures occupy ordinary client RAM;
they do not replace an original callee. Development exposed and corrected an
initial 48-byte channel-stride error before acceptance began.

`command_selector_probe_plan.py` generates these original caller contracts.
`motion_record_probe_plan.py` generates 120 records at the original 68-byte
stride with at most one active record, preserving the real float-table index
and global pointer comparisons. All-active exploratory motion inputs exceeded
the unchanged oracle record cap and earn no credit. Existing
`phase1_adapters.c` supplies the motion C owner. Other newly closed families
use existing helpers plus `target_family_adapters.c` and
`target_extra_adapters.c`: static original-instruction C, with no unsupported
instructions or foreign code in their translation reports.

## PVR checkpoint pilot

The synthetic oracle previously rejected the original helper `0x8c060d14`
when it wrote PVR `TEXT_CONTROL` at `0xa05f80e4`. In this headless interpreter
build, `Renderer_if.cpp` forces `norend`, and `pvr_WriteReg` handles offset
`0xe4` by storing the register word, without TA, renderer or timing effects.
Texture-cache users of this register are outside the active `norend` path.

An explicit `--rollback-text-control` option now permits only 32-bit access at
the exact original uncached address `0xa05f80e4` in a `VF3_HEADLESS` build. Each synthetic root journals
the real old word once at the canonical address, executes the actual device
handler and ordered tape, restores the old word and checks exact readback.
Failed restoration aborts the run. Other widths/addresses, ordinary builds
and the default option retain the device rejection policy. The authoritative
source remains `tools/oracle/vf3oracle.cpp`, copied into the ignored emulator
fork for builds. New opted-in captures also record emulator/source hashes.

Review found that masking to a physical address would also admit
`0xe05f80e4`, which belongs to store queues. The final guard compares the exact
uncached address instead. The original pilot is archived as exploratory
evidence; the corrected emulator was rebuilt and all checks were recaptured.

`text_control_probe_plan.py` validates the original five helper instructions
and PVR base literal before generating inputs. `audit_text_control.py` checks
**1,280 original calls**: development and independent acceptance (256 each),
the default-disabled control (256), adjacent-register control (256) and
store-queue alias control (256).
Allowed specimens preserve every captured RAM byte, have the complete five
instructions and exactly one original word-store event, and restore once per
call. All three negative controls remain rejected before issuing device events.
Development and acceptance also pass existing C replay, **256/256 each, zero
skips**, against `vf3matrixfamily_target_integrated.exe`. This infrastructure
pilot supplies **zero coverage credit**. Evidence and implementation hashes:
`extract/analysis/target_text_control_v2_audit.json` and
`target_text_control_v2_{dev,accept}_proof.json`. Opted-in run hashes match the
audited emulator and authoritative source. One initial disabled-control run
completed 150 frames without hitting the trigger; it supplied no proof.
A fresh 300-frame control completes all 128 original attempts per state.

Retrying the real resource parent `0x8c05cc20` with the checkpoint reaches past
the original PVR boundary but still produces no admissible complete child
specimens: rejection flags `4:694`, `5:151`, `1:151`. A sampled original exit
remains inside the real 4096-slot descriptor release scan at `0x0c0624cc`.
The record limits remain unchanged; this retry earns no bytes.

## Integration checkpoint

The immutable integrated replay binary is
`build/vf3matrixfamily_target_integrated.exe`, SHA-256
`e84ed5fa1e2d8b6e2e5fb6133d8631b0f76039cc1cc3f29565d61972ef89f516`.
The CMake build passes. All **31 campaign-tool tests** pass. Full regression
finishes with **`verify_all: PASS`**, **1,179/1,179 bound replays**, zero replay
failures and passing native tests. The artifact-hash/union audit passes all
**44 milestones**. Final evidence is retained in
`extract/analysis/target_full_regression.log`,
`target_full_regression_status.json` and `target_series_audit.json`.

An expanded queue of 160 roots without known indirect calls has 37,136
potential marginal bytes, not proof. Nearby original prologues and retained
probe history identify 112 previously unattempted callers. Their development
captures are split into independent `target_broad{,_a,_b,_c}_dev` directories;
the initial runner stopped between roots after index 6 and the three shards
cover indices 7..41, 42..76 and 77..111. New roots still require whole-body
execution, implementation, immutable strict replay and fresh acceptance.

## Expanded continuation checkpoint

The expanded static C owners are `target_broad_adapters.c`,
`target_extended_adapters.c` and `target_closure_adapters.c`. Their translation
reports contain 1,815, 2,947 and 1,296 original statements respectively, with
zero unsupported emitted instructions. No accepted closure uses the generic
`0x8c0671aa/0x8c0671ac` RTS fixture callback. Development and acceptance replay
use immutable snapshots recorded separately in each proof. The closure
snapshot has SHA-256
`10d3beb0eb0f118822410ffafc9c3ec074888baf7867bcc882695a0b64b6cc10`.

Seven extended roots (`04326c`, `0433c6`, `04341e`, `043440`, `043472`,
`04348e`, `0434aa`) execute the original GD-ROM BIOS bridge via `04308c`
and the external REIOS opcode at `8c001006`. The current C capture/replay does
not model that platform boundary; all seven fail strict development replay
and receive no credit. Three different roots passed replay but initially had
only one acceptance scenario. Fresh states 24/26 resolved that diversity gap
without changing C. One closure root was initially omitted while its replay
report was still being written; its final passing result is credited by a
separate tail milestone, preserving the earlier manifest.

`ready_parents.py` recovers actual original parent groups from capture
reports. `capture_catalog.py --single-scenario` finds retained full bodies
needing another development scenario; it excludes acceptance, holdout and
held reports. `catalog_parents.py` exports their actual parent watches and
development directories without granting credit. Raw original capsules must
still be merged and revalidated, replayed and independently accepted.
The current retained index has 35 leads and 2,894 potential union bytes,
including already scheduled entries. These are advisory totals only.

The expanded full gate passes **1,232/1,232 bindings**, native tests and all
31 campaign-tool checks (`verify_all: PASS`) in
`target_checkpoint_regression.log` against the immutable closure snapshot.
Its frozen binding inventory is `target_checkpoint_bindings.json`; machine
status is `target_checkpoint_regression_status.json`. Later captures and
source additions do not change that executable. The four subsequent
scene-recovery roots and the remaining fresh prologue queue are still
uncredited at this checkpoint.

## 2026-10-06 continuation

Eight further accepted milestones add **3,094 unique bytes across 41 roots**
after the 243,256 checkpoint, reaching **246,350 / 434,656**. The campaign
still needs **3,178 bytes** to reach 249,528. Static instruction adapters
provide part of this gain; this is not a claim that every new body is already
expressed as readable game-level C.

| Milestone suffix | Roots | Unique bytes |
|---|---:|---:|
| `scene_recovery` | 1 | 160 |
| `extra_scene` | 1 | 108 |
| `remaining` | 26 | 1,564 |
| `retained_scene` | 9 | 618 |
| `record_selector` | 1 | 148 |
| `dependency` | 1 | 180 |
| `configuration` | 1 | 254 |
| `retained_extra_scenes` | 1 | 62 |

Each is an `advance_target_*_milestone.json` with whole-body development,
independent acceptance, zero-skip strict replay and checked artifacts. The
remaining batch passes 32/32 acceptance replays, but six roots have only 50
acceptance cases and receive no credit. Retained scenes yield fewer accepted
roots than their raw size ceiling: some callers never enter the child in the
held-out scenes. `07ac6e` fails at unresolved helper PC `0c0597ba`; `080238`
and `080444` retain their development RAM mismatches. None earns credit.

The 52-caller dependency campaign produces two eligible development bodies:
`087e1c` (750 bytes) and `08dbee` (180 bytes). Only `08dbee` passes strict
development and acceptance. `087e1c` matches 190/334 development cases and
differs in the sign of NaN in `fr1`; it remains uncredited. An experimental
binary-operation NaN precedence change did not fix it and was reverted.
No shared FPU behavior change is shipped by this continuation.

Directed record inputs exercise `0370fc` through its true `0370f0` prologue:
slot indices 0..7, selectors 1/2/11, arguments including zero, and mutable
global gate `0c19c900`. Original instructions at `037170..17e` explain the
joint selector-11/zero-argument condition. All 148 frozen bytes execute;
development matches **508/508**, independent acceptance **504/504**.
Reusable inputs are `tools/oracle/record_selector_{registers,memory}.json`
and `tools/watch/vf3_record_selector_{parent,child}.txt`.

The configuration gate uses the original byte reader at `0c0c66b8` and
mutable configuration base `0c11e504`, also used by the original editor and
setter documented by `config_editor_map.py`. Input byte +0x13 is enabled,
the global selector byte at `0c29bced` includes 3, and the global word at
`0c29bccc` includes 1. The initial word at `0c11e514` was observed as
`00010001`; its other bytes are retained when changing its high byte.
No opcode or literal pool is patched. The true prologue is `0a8574`, frozen
root `0a8582`: **511/511 development and 512/512 independent acceptance cases**
match. The input contract is `tools/oracle/config_gate_memory.json` with
parent/child watch files under `tools/watch`.

Near-zero float sampling adds cases to `08fe62` and `0ca8da` but no missing
PCs; neither is credited. A different lead, `0853fe`, contains an impossible
signed comparison: `mov.w @(30,r10),r0` at `085418` sign-extends a 16-bit
value, then `cmp/gt r2,r4` compares it with positive 32768. Thus the path at
`085420..424` cannot execute from that predecessor. The frozen body is kept.
The unmapped small entries near `0204e8`/`0345c6` are data-like words rather
than verified callable leaves; advisory ranking is not sufficient to port them.

The immutable integration checkpoint
`build/vf3matrixfamily_target_20261006_checkpoint.exe` has SHA-256
`e3878590f0b278ee302093398a1c21c467fe05ee4e6773f9882871c9ffd89daf`.
Full regression passes **1,269/1,269 bindings**, native tests and the 36
campaign-tool tests present when it started (`verify_all: PASS`). The
binding inventory is frozen in `target_20261006_checkpoint_bindings.json`;
log and machine status are `target_20261006_regression{.log,_status.json}`.
Later record, dependency and configuration additions have their own immutable
proof snapshots and still require the next integrated regression checkpoint.
The current expanded tool suite independently passes **37 tests**.

`verify_all.py --bindings` now pins both bound replay and body coverage to
the same inventory. `isolate_planned.py --float-palette` permits eight finite
float32 boundary inputs without altering expected results. Parent mappings
can be restored with `catalog_parents.py --sources --watch`, which validates
the original watch and development provenance. Artifact promotion reports
per-root hash progress. Cache planners protect uncommitted milestone proofs
as well as tracked ones, permit explicit unbound staging-cache selection,
and retain all original capsules. Additional cleanup journals are
`target_small_cache_cleanup{,2}_applied.json` and
`target_staging_cache_cleanup_applied.json`; about 12.5 GiB of rebuildable
shadows were reclaimed after the earlier cleanup.

The remaining retained roots are being recaptured in development through
nearby true prologues, including `07f714` for `07f722` and `0a0280` for
`0a028a`. Earlier retained probe-parent maps sometimes began at a frozen
interior entry. Inspect original setup and stack saves before treating the
advisory prologue map as a callable input contract. The 4 GiB reserve stopped
the new capture campaign between groups; incomplete or absent proofs do not
receive credit.

### Directed inputs after the 246,350-byte checkpoint (2026-10-06)

Three further frozen bodies passed independent original-image acceptance:

| Root | Bytes | DEV | ACCEPT | Implementation |
| --- | ---: | ---: | ---: | --- |
| `0x8c0a00c8` | 362 | 1,446 | 512 | `advance_controller_adapters.c` |
| `0x8c0a92da` | 320 | 512 | 511 | `target_action_selector_adapters.c` |
| `0x8c04709a` | 294 | 714 | 423 | `target_record_adapters.c` |

All rows cover the complete frozen body in development, use at least two
development and two disjoint acceptance scenarios, and replay architecture,
all captured RAM and the ordered device tape with zero skipped cases. The
three `advance_target_{name_entry,action_selector,save_record}_milestone.json`
manifests were individually audited with hashes. Verified unique coverage is
**247,326 / 434,656**, with **2,202 bytes** left to the 249,528-byte target.

`name_entry_memory.json` varies the cursor, count, status and button words
together, supplies writable task objects, and leaves the original character
table untouched. `action_selector_{memory,registers}.json` exercises the
joint object-selector/button-mask conditions. Its new C module contains 160
original statements and no unsupported instructions; existing helper routes
are reused. Both use independent acceptance objects relocated by `0x100000`.

`save_record_inputs.py` generates CRC-16/0x1021 records with correct and
incorrect stored checksums. Original section-size tables remain unchanged.
The record reader adds 128, the 512-byte primary section, an optional section
of 0/8064/4544/2048 bytes and an untrusted uint32 payload length. Inputs with
payload `-optional_size` modulo 2^32 make the original sum wrap to 640.
This tests malformed-length behavior as well as the normal optional-size-zero
record. The original interpreter executes and checks each specimen; the tool
supplies no expected register, RAM or device outputs. Existing ordinary
development records are retained in the merged 714-case proof. The opcode
budget remains 100,000. There are now 39 passing campaign-tool tests, including
the independent CRC reference `123456789 -> 0x31c3` and fixture consistency.

The corrected-prologue retained development merge passed 17/17 strict entry
replays against the immutable configuration checkpoint. Acceptance through
states 23/29 still fails to produce complete invocations for most graphics
families; states 30/41 likewise produced no valid invocations in their second
and third groups before the disk guard stopped the next group. These roots
remain uncredited. New independent quadrant inputs for `03a070` execute the
axis cases but still do not cover the complete 244-byte frozen body; the
initial replay lacks its entry adapter. Its retained input JSON is advisory.

The whole hash audit started before these three promotions and passed through
246,350 bytes: `target_20261006_chain_audit.json`, 324 new roots and +40,288
unique bytes over the frozen 206,062-byte baseline. The three subsequent
individual hash audits extend that verified chain to 247,326. The integrated
1,274-binding regression passed against frozen
`target_20261006_name_checkpoint_bindings.json` and immutable
`vf3matrixfamily_target_configuration_dev.exe`, with zero replay failures and
terminal `verify_all: PASS`, recorded in
`target_20261006_name_regression_status.json`. It ran 37 campaign-tool tests;
the later 39-test suite also passed separately. Later action-selector
integration and record/motion promotions still require the final integrated
checkpoint.

Cleanup journals `target_small_cache_cleanup3_applied.json`,
`target_small_cache_cleanup4_applied.json` and
`target_gap_staging_cleanup_applied.json` record removal of 312,942, 217,856
and 37,190 rebuildable RAM-shadow files (about 8.00, 5.50 and 1.04 GiB).
Original capsules, case headers, opcode maps, manifests, bound proofs and
selected analysis leads were preserved. No ROM, SDK or frozen range changed.

### Motion and score checkpoint (2026-10-06)

| Root | Bytes | DEV | ACCEPT | Implementation |
| --- | ---: | ---: | ---: | --- |
| `0x8c08cae2` | 286 | 511 | 511 | `motion_adapters.c` |
| `0x8c094cd2` | 204 | 470 | 474 | `target_retained_scene_adapters.c` |
| `0x8c06c0da` | 276 | 266 | 82 | `fight_adapters.c` |

These three complete frozen bodies add 766 unique bytes using existing C
implementations. Each passes strict development and independent relocated
acceptance replay, with zero skips and at least two disjoint scenarios in
each corpus. The corresponding `advance_target_{motion_choice,motion_command,
score_format}_milestone.json` manifests preserve artifact hashes and pass
individual hash audits. Verified unique coverage is **248,092 / 434,656**;
**1,436 bytes** remain to the 249,528-byte target.

Motion-choice inputs vary the original writable RNG seed to reach both
selection outcomes. Motion-command inputs vary command words and finite
interpolation values. Score-format inputs vary the mode, score pairs and
threshold. Original code and constant tables remain unchanged. These proofs
use immutable `vf3matrixfamily_target_action_selector_dev.exe`, SHA-256
`5a9d9c12826eadc6576709c51025738c043a16fd307917416608f7a8e4f4c10e`.
The effect-pool input contract is advisory and receives no coverage credit;
its parent address was corrected to the actual prologue at `0x8c089088`.

### Final-push checkpoint (2026-10-07)

An integrated regression over the frozen 1,279-binding inventory passes
with the immutable `build/vf3matrixfamily_target_20261006_final.exe`
(SHA-256 `e419fea4593a62cd6fc70f37df6a6c13e6a8499605cb10a3d2097c567917cb3d`):
portcheck 1,279/1,279, 39 campaign-tool tests, body-cover quiet gate and
union 31/31 (`target_20261006_final_regression_status.json`).

One further frozen body was promoted with a directed tail-closure input:

| Root | Bytes | DEV | ACCEPT | Implementation |
| --- | ---: | ---: | ---: | --- |
| `0x8c08d00e` | 156 | 490 | 128 | `phase1_adapters.c` |

The pre-existing 362-case development corpus covered only 128/156 bytes:
the `0x8c08d06a` tail needs `float([r14+36])` strictly inside `(2.0, 5.0]`
together with sign-bit conditions at `0x8c08d070/07e/084`, read from the
existing static translation (`tail_08d00e_inputs.py`). Merged development
(362 prior + 128 directed, states 21/27) covers 156/156 and replays
490/490 strict with zero skips against the immutable final executable;
independent relocated acceptance (states 23/29, +0x100000) replays 128/128.
Manifest `advance_target_final_08d00e_milestone.json` passes its hash audit
(+156 bytes). Verified unique coverage is **248,248 / 434,656**;
**1,280 bytes** remain to the 249,528-byte target.

Near-misses banked for the next session (all measured, none credited):
`0x8c0c8334` (638 B, 6,493 cases across 9 states, 98.4%) is blocked on five
PCs needing `[[r10]]==0` through a live-stack word that no longer survives
from seed to read (verified in captured dumps); `0x8c05cc38` (1,290 B,
81.4%) needs branches whose taken side dereferences an invalid pointer and
never completes; `0x8c04a4c4` (506 B, 98.8%) fails replay on an untranslated
BRAF table at `0x8c04a446`. Broad natural capture does not fire these roots
in states 20-29; blind synthetic fuzz crashes (flag 6) on object contracts.

### Matrix dispatch continuation (2026-10-07)

The `04a4c4` replay blocker is resolved: completing the five BRAF destinations
and matching the capture interpreter's two-NaN operand priority passes all
852/852 retained development cases with zero skips. The FPU suite passes
213,056 cases and the campaign tools pass 41 tests. No new coverage credit
is claimed: the missing six body bytes form the no-emission exit, which
requires the original callable entry at `0x8c04a320` to initialize R11 to
zero. The current interior entry sets it to one before that exit. Storage
is below the existing capture reserve. See [matrix_clip_dispatch.md](matrix_clip_dispatch.md)
for the original dispatch map, proof limits and next input contract.
The integrated immutable snapshot passes `verify_all`, **1,280/1,280** bound
replays, native tests and all **41** tool checks, with zero replay failures.
Logs and parsed terminal status are `target_matrix_braf_regression{.log,_status.json}`.


### Original matrix helper acceptance (2026-10-07)

Callable-entry captures resolve the last six missing bytes of frozen owner
`0x8c04a4c4`. All 506 frozen bytes execute in both development (states 21/27)
and independent acceptance (23/29, relocated buffers and different finite
values); each passes **256/256 strict cases, zero skips**, against the
unchanged `vf3matrixfamily_target_braf_final.exe` snapshot.
`advance_target_matrix_clip_milestone.json` passes its hash audit and adds
**506 unique bytes**, reaching **248,754/434,656** with **774 bytes** remaining.
Explicit attribution to original callable entry `0x8c04a320` preserves the
frozen inventory and requires two original BSR callers, a straight prefix,
image-identical captured instructions and full body execution in both
corpora. No credit is claimed for the additional 138 bytes outside the
frozen body. The tool suite now passes **43 tests**. Details and evidence
are in [matrix_clip_dispatch.md](matrix_clip_dispatch.md).

The integrated gate uses frozen `target_clip_complete_bindings.json` and the
same immutable snapshot. It finishes **`verify_all: PASS`**, **1,281/1,281**
bound replays, zero failures, **43** tool tests, native tests and union
checks. Log/status artifacts are
`target_clip_complete_regression{.log,_status.json}`. The full milestone
chain audit also passes (`target_clip_complete_series_audit.json`).
