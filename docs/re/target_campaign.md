# Target campaign continuation, 2026-10-05

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
