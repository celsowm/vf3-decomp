# Percentage expansion campaign — 2026-10-08

Latest accepted audio milestone (2026-10-09): complete channel allocation adds
**786 unique bytes**, reaching **258,430 / 434,656 (59.46%)**. Both disjoint
128-case corpora execute the full body and pass strict native and live-device
comparisons. See [audio execution](audio_execution.md). Remaining work includes
sound-dependent callers and attributed playback; ARM/DSP are research dependencies.

Objective: the [coverage expansion plan](coverage_expansion_plan.md), with
65% as the main checkpoint and a ten-percentage-point stretch target. The
immutable starting union is 248,754 / 434,656 bytes. The stretch freeze is
`tools/oracle/percentage_coverage_baseline.json`; the main checkpoint is
282,527 bytes. Neither the frozen original image nor body ranges changed.

## Resource and callback milestone

Nine complete frozen bodies add **406 unique C bytes**, reaching
**249,160 / 434,656 (57.32%)**. All pass original development and independent
acceptance replay with zero skips. Development contains 1,368 distinct
complete cases; acceptance contains 4,400, in disjoint states 23/29 with
writable fixture relocation by `0x100000`. Each body is complete in both
corpora. The milestone hash audit passes.

New readable C replaces the static callback selector at `0x8c059400` and
implements resource acquisition/reset (`0x8c05cace`) and allocation range
lookup (`0x8c061ba8`). The selector installs nine original callback literals
at their task slots and preserves invalid-selector behavior. Acquisition
uses the original resource callee and clears five state words only after
success. Range lookup preserves the original signed comparisons, byte-sized
list index, exclusive start containment and inclusive requested end. These
three roots account for 262 bytes; six other roots use existing C owners.

Proofs: `percentage_static_complete_dev`, `percentage_resources_complete_accept`,
`percentage_resources_dev_replay.json`, and `percentage_resources_accept_replay.json`
under `extract/analysis`. Immutable executable:
`build/vf3matrixfamily_percentage_resources_dev.exe`, SHA-256
`1eefa3b3791ef15ba3bece3427af797a9cd84a4497745078b1d3da54570b7001`.
Manifest: `tools/oracle/percentage_resources_milestone.json`.
The full integrated regression remains due at the planned checkpoints.

## Packed motion-transition command

Readable `src/fight/motion_flag_command.c` adds **406 unique bytes**, reaching
**249,566 / 434,656 (57.42%)**. This completes the older 249,528-byte campaign
target by 38 bytes. The new 65% checkpoint still needs **32,961 bytes**.

The command decodes unaligned little-endian words, tests the record's selector
and object flags, applies the float threshold, selects one of two motion
pairs, checks the prior motion's flag combination, and advances the real
motion dispatcher by twelve bytes. Original scratch registers, stack stores,
callee and return behavior remain part of strict replay. Development caught
and corrected two reversed branch conditions before acceptance began.

Merged development executes **406/406 bytes** and passes **4,860/4,860 cases**
in states 21/27. Independent acceptance changes record ordering, unknown
selectors, prior motions, finite float values and object initialization, with
buffers relocated by `0x100000` in states 23/29. It executes **406/406 bytes**
and passes **3,783/3,783 cases**, zero skips. The milestone hash audit passes.
Invalid specimens are retained; neither final corpus has an incomplete
invocation or nondeterministic entry.

Input recipes are `tools/oracle/motion_flag_{registers,development_memory,
development_crosses,acceptance_memory}.json`. Use `isolate_planned.py` with
the register recipe and the corresponding memory recipe. Development merges
384 variants of the memory recipe (160 frames) and 2,048 variants of the
crosses recipe (600 frames), states 21/27, `--global-fields`. Acceptance uses
2,048 variants and 600 frames, states 23/29, `--holdout-inputs --relocation
0x100000`. The frozen watch is `pc 0x8c0af1a4`; record seeds supply no expected
outputs. An earlier 200-frame development pilot ended during an invocation
and was not used in the accepted proof.

Evidence: `percentage_motion_flags_complete_dev`,
`percentage_motion_flags_v3_replay.json`, `percentage_motion_flags_accept`,
and `percentage_motion_flags_accept_replay.json` under `extract/analysis`.
Immutable executable: `build/vf3matrixfamily_percentage_motion_v3_dev.exe`,
SHA-256 `bc3889b07e5df50172c69b6ff6599871357e2db660373b2c10f9f7e1bc8b8d47`.
Manifest: `tools/oracle/percentage_motion_flags_milestone.json`.
All **43** campaign-tool checks pass; integrated regression is still due.

## Development triage

The retained-report catalog has 40 uncredited full-body leads with 3,096
potential unique bytes, including previously blocked acceptance and BIOS
boundaries. Those leads have not been promoted from the advisory index.
Updated linked ownership identifies 134 implementation-closed roots with
12,090 potential bytes; ownership supplies no verification credit.

The bounded pilots cover 32 initial roots, 102 additional linked-closure
roots, and 100 shared-family callers. They use original interpreter execution
in states 21/27 with typed fields, finite float registers and independent
comparison-boundary dimensions. Invalid/incomplete specimens remain in raw
manifests and provide no proof. Raw evidence is retained under
`percentage_static_dev`, `percentage_static_extended_dev` and
`percentage_family_dev`. Repeating the queue without a new input hypothesis
is not a next step: most larger families need original caller contracts or
specific missing predicates.

The menu milestone below completes the directed input work.
Free space rose from about 4.9 to 50 GiB
during the session. The decoded-cache scan was stopped without applying any
deletion; captures retain a 4 GiB reserve.

## Menu navigation and stronger acceptance gates

The existing static C translation of `0x8c0c80be` now contributes **372
unique bytes**, reaching **249,938 / 434,656 (57.50%)**. This is newly verified
existing C, rather than a new readable module. The 65% objective still needs
**32,589 bytes**. Development covers previous/current buttons, selection
coordinates, style and repeat counter paths using the original prefix-derived
register setup. Its merged corpus executes 372/372 bytes and passes all
2,303 strict cases. Independent relocated acceptance in states 23/29 executes
372/372 bytes and passes all 2,560 cases, with zero skips. No incomplete or
nondeterministic invocations occur in the final corpora.

The initial acceptance missed a previous-button branch, despite passing every
captured case. A targeted original-input capture closed the gap before
promotion. `promote_tenpp_batch.py` now explicitly requires full-body
acceptance as well as development; a regression check prevents partial
acceptance from satisfying that gate. All 46 campaign-tool checks pass.

Evidence: `percentage_menu_verified_dev`, `percentage_menu_verified_replay.json`,
`percentage_menu_final_accept`, `percentage_menu_final_accept_replay.json`.
Immutable executable is the motion-v3 snapshot documented above. Manifest:
`tools/oracle/percentage_menu_milestone.json`; artifact hash audit passes.
The `menu_navigation_*.json` recipes preserve the original-input dimensions.
Development uses the general (1024 variants, 600 frames) and repeat (128,
160) memory profiles; acceptance adds the previous-button (128,160) profile.
All use the register profile, global/scalar/random/expanded fields and the
independent states and relocation convention described above.

`callee_global_inputs.py` now discovers bounded mutable scalar inputs in real
static callees, with source provenance, excluding code, pointers, callback
stubs and float fields. These input hypotheses carry no coverage credit.
The sound and larger-family acceptance investigations remain uncredited.

## Accepted family and helper expansion

The next ten milestones add **2,436 unique bytes**, moving from 249,938 to **252,374 / 434,656 (58.06%)**. Campaign gain is **3,620 bytes / 0.833 percentage points**, across 29 newly credited entries. The 65% objective still needs **30,153 bytes**. Every listed body executes completely in both development and independent acceptance; all strict replays have zero skips. All thirteen milestone hash audits and their address-union chain pass.

| Milestone manifest | Roots | Unique gain | Development / acceptance cases |
| --- | --- | ---: | --- |
| [percentage_family_milestone](../../tools/oracle/percentage_family_milestone.json) | 0x8c06e1ae, 0x8c09c044 | 674 | 0x8c06e1ae: 1024/1279; 0x8c09c044: 1016/1015 |
| [percentage_resource_result_milestone](../../tools/oracle/percentage_resource_result_milestone.json) | 0x8c05c90e | 28 | 0x8c05c90e: 864/1023 |
| [percentage_selection_milestone](../../tools/oracle/percentage_selection_milestone.json) | 0x8c0c2f4e | 650 | 0x8c0c2f4e: 677/606 |
| [percentage_index_milestone](../../tools/oracle/percentage_index_milestone.json) | 0x8c07abf8 | 48 | 0x8c07abf8: 247/247 |
| [percentage_angular_milestone](../../tools/oracle/percentage_angular_milestone.json) | 0x8c0abcb8 | 140 | 0x8c0abcb8: 1152/794 |
| [percentage_clients_milestone](../../tools/oracle/percentage_clients_milestone.json) | 0x8c03ca8c, 0x8c03caac, 0x8c03e79e, 0x8c045e4e, 0x8c0801de | 120 | 0x8c03ca8c: 512/879; 0x8c03caac: 511/881; 0x8c03e79e: 258/881; 0x8c045e4e: 66/148; 0x8c0801de: 465/904 |
| [percentage_rng_milestone](../../tools/oracle/percentage_rng_milestone.json) | 0x8c0c9d04 | 26 | 0x8c0c9d04: 618/512 |
| [percentage_indicator_milestone](../../tools/oracle/percentage_indicator_milestone.json) | 0x8c07ae30, 0x8c08a61c | 236 | 0x8c07ae30: 457/896; 0x8c08a61c: 759/1152 |
| [percentage_aux_milestone](../../tools/oracle/percentage_aux_milestone.json) | 0x8c07385c, 0x8c081a46, 0x8c081a9e | 304 | 0x8c07385c: 237/563; 0x8c081a46: 371/718; 0x8c081a9e: 364/716 |
| [percentage_aux_completion_milestone](../../tools/oracle/percentage_aux_completion_milestone.json) | 0x8c08919e | 210 | 0x8c08919e: 449/402 |

New readable modules cover indexed resource reset (`resource_index_reset.c`), a real-generator floating random fraction (`random_fraction.c`), and a scene indicator with real transform and render calls (`scene_indicator.c`). Existing readable resource/client wrappers gained small entry points. The larger selection, angular and auxiliary bodies use static instruction adapters as integration scaffolding; they still need semantic cleanup. Newly verified existing C contributes the interpolation, resource-claim and three client bodies.

The indexed reset is verified under the original caller contract R14=10, R11=82, R13=0, established by the prefix at 0x8c07abe8. A generic out-of-contract large-index specimen exposed a helper RAM mismatch and is retained uncredited. This proof does not claim arbitrary index limits.

Input recipes for these milestones are retained in `tools/oracle/percentage_inputs/`. The manifests freeze exact corpus paths, case hashes, immutable executable names and SHA-256 hashes. Regeneration uses `isolate_planned.py`; original input recipes contain no expected outputs or executable patches. Development uses states 21/27, acceptance uses states 23/29 with holdout values and relocation 0x100000. Merged corpora close individually documented branch gaps; raw failed or incomplete runs provide no credit.

## Parked hypotheses and remaining boundaries

`task_text_commands.c` is development-only C for 0x8c06c52a / 0x8c06cea2. These are text-rendering commands; the exploratory `percentage_sound_*` artifact names were an incorrect initial label. Both bodies pass full-body development replay, but independent acceptance misses 14 bytes per body. Attempts to reach the nonzero helper-return path encounter invalid render callbacks. Neither wrapper receives coverage credit.

The loaded-state pilot used new development states 31/35 for forty roots with 9,276 advisory bytes. It produced no new qualifying body: successful cases were sparse, often only one scenario, and some runs incomplete. It is parked; changing game state alone did not resolve the caller contracts. Other bounded pilots covered additional shared families and one hundred previously unattempted static roots. Their queue potential is not accepted coverage.

Original-instruction inspection found apparently unreachable paths in 0x8c0853fe (sign-extended 16-bit value compared above 0x8000), 0x8c0c15f8 (negative tests after masking with 63), and helper 0x8c0a2e06 (contradictory table tests without intervening writes). No denominator adjustment or dead-code exemption is applied. The first two remain at 326/332 and 310/342 bytes; all three families remain uncredited.

Campaign-tool tests: **46 passed**. The full integrated gate uses its frozen 1,295-binding inventory and family-v1 executable; additional bindings and changed client dispatch require a separate current-executable affected regression. Completion of either gate is reported separately, rather than inferred from progress output.

Current-executable affected regression: **37/37 bindings PASS**, plus all native replay tests and golden metadata checks (`percentage_checkpoint_affected_regression.log`). It uses immutable `vf3matrixfamily_percentage_aux_v2_dev.exe`, covering every percentage binding and earlier bindings owned by changed resource/client wrappers.

## Integrated checkpoint and AICA RAM boundary

The frozen full integrated gate completed: **1,295/1,295 bindings PASS**, all native tests, SDK union, body coverage, call decoding/resolution and planning gates PASS. Current inventory has 1,310 bindings. A current-executable regression expands the earlier owner-only subset through static/resolved reverse call dependencies: **47/47 affected bindings PASS**, including all new percentage entries. This is the scope of current-code validation; unresolved dynamic edges cannot be inferred from that graph.

A bounded original-input pilot for 0x8c040fa4 constrained channel counts, busy flags, alignment inputs and a valid queue buffer. It reaches 116/786 valid bytes; deeper paths previously stopped at sound RAM access 0xa08000a0. A new opt-in checkpoint journals canonical, aligned 1/2/4/8-byte accesses in **0xa0800000..0xa09fffff**. Each touched 4 KiB sound-RAM page is restored and byte-checked. Ordered device access recording remains enabled. AICA registers, aliases, misalignment, MMU accesses and other device boundaries remain rejected.

Crucially, `vf3OracleBeforeTimeslice()` retires every opted-in synthetic probe before `UpdateSystem_INTC()` can advance the scheduler. ARM7, audio DSP and DMA are driven by scheduler callbacks (`aica.cpp`); they cannot consume temporary sound bytes in an accepted probe. The larger initializer still cannot complete within this bound, so its deeper paths receive no credit. A five-client pilot also yields no complete new body. Supporting long sound commands requires a wider scheduler/ARM7 state model, not permission to ignore their execution.

`aica_ram_probe_plan.py` regenerates the original five-instruction helper's word-store inputs. The independent runs change values, stack location, sound-RAM destination and scenarios. Strict C replay passes **360 development / 373 acceptance cases**, zero skips. The checkpoint audit verifies original architectural results, unchanged captured main RAM, ordered device words, restore counts and provenance hashes. **1,152** disabled/register/alias controls reject the access; **310** initializer specimens reject scheduler crossings. An additional 35 short-leaf scheduler crossings are retained invalid. This platform work supplies **zero new coverage credit**.

Reproduction: generate `--mode development|acceptance|disabled|register|alias` patches, then use `golden_batch.py --capsule --probe-only --rollback-aica-ram` (omit the checkpoint for disabled controls). The helper watch is `pc 0x8c060d14`; development/control states 21/27 and acceptance states 23/29, 192 variants and 120 frames. `audit_aica_ram.py --help` lists the six evidence inputs. Evidence prefixes are `percentage_aica_word_{dev,accept,disabled,register,alias}` and `percentage_audio_slots_checkpoint_dev`; audit `percentage_aica_checkpoint_audit.json`. Four audit regression tests and the 46 campaign checks pass. `verify_all.py` now includes the four new tests.

## Five-object animation initialization

The original prefix at 0x8c094e6c lays out five objects at offsets 0, 0xa8, 0x150, 0x1f8, 0x2a0. Root 0x8c094e8c installs style-specific animation references for selectors 5, 7 and 18; real helper 0x8c095036 (frozen interior entry 0x8c095040) initializes motion fields and calls the original six-float copier 0x8c09493c. The new static module `motion_group_adapters.c` supplies both bodies as scaffolding, with no interpreter or expected-result tables.

The record chain is the missing development contract: model-table indices **0xee9, 0xeeb, 0xef6**, model +4 -> descriptor, descriptor +4 -> vector buffer. A first pilot incorrectly used literal addresses as indices, then treated the descriptor's vector pointer as a float. Both incomplete-path hypotheses were rejected without credit. The corrected recipe executes the whole initializer and helper. Writable objects, descriptor, record, model chain and vector buffers are independently relocated for acceptance; finite vector values, command duration, selector order and initial registers change. R0 selects either original global task record; the contiguous object registers follow the original prefix.

Development **375 initializer / 381 helper cases**, independent acceptance **504 / 509**, full **336/336 and 214/214 bytes** in both corpora. All strict architecture, captured RAM and ordered-device replay passes with zero skips; both scenario pairs are complete and disjoint. Immutable executable `build/vf3matrixfamily_percentage_motion_group_v1_dev.exe`, SHA-256 `fef1cc3db5ac6b8d843f2d0513f4fb4ffc067b67906e7d738d51fcd1520d9e6b`, frozen before acceptance. Manifest `percentage_motion_group_milestone.json` hash audit PASS.

This adds **550 unique bytes**, reaching **252,924 / 434,656 (58.19%)**. Campaign gain **4,170 bytes / 0.959 percentage points**, 31 entries. The 65% objective still needs **29,603 bytes**; it remains unfinished. Evidence is `percentage_motion_group_helper_dev`, `percentage_motion_group_helper_replay.json`, `percentage_motion_group_accept`, `percentage_motion_group_accept_replay.json`. Four tracked `percentage_motion_group_*.json` recipes regenerate inputs with `--preserve-fields --global-fields`, 192 development / 256 acceptance variants, 280 / 320 frames, 60,000 original-instruction probe budget. Observe `pc 0x8c095040` with `--probe-children` to collect the real nested helper.

## Motion step and descriptor initialization

The reusable descriptor contract closes two more bodies: **0x8c09497a, 186 bytes**, newly verified existing C, and **0x8c094b2a, 360 bytes**, new static scaffolding in `motion_initialize_adapters.c`. The step decodes ordinary records and markers 0x80/0x81, handles signed remaining-frame counts and updates vector pointers through the real six-float copier. The initializer fills an eight-entry model window, selects the current command and prepares interpolation fields. The original prefix fixes R0=0x84 for the step and R7=0x0c29b864 for initialization; a decompiler's apparent incoming parameter obscured this global context.

Development **767 / 511** strict cases, full 186/186 and 360/360 bodies. Independent relocated acceptance **639 / 512**, full bodies and zero skips. The first acceptance passed all recorded cases but missed the 0x80 marker's motion-0x1c flag update because two input dimensions were correlated. A strided motion-type dimension closed those ten bytes before promotion; the implementation remained frozen. Invalid specimens remain excluded, with no incomplete or nondeterministic final entry.

Manifest `percentage_motion_flow_milestone.json` hash audit passes; immutable `vf3matrixfamily_percentage_motion_flow_v1_dev.exe` is recorded there with its SHA-256. Evidence is `percentage_motion_flow_dev`, `percentage_motion_flow_replay.json`, `percentage_motion_flow_final_accept`, `percentage_motion_flow_final_accept_replay.json`. Seven tracked input recipes cover development and acceptance. Development captures 384 step / 256 initializer variants (320 / 280 frames); acceptance uses 256 variants / 320 frames plus a 128-variant / 180-frame directed step capture. Both use the standard disjoint scenarios, relocation and `--preserve-fields --global-fields`.

Gain **546 unique bytes**, total **253,470 / 434,656 (58.31%)**, campaign **+4,716 bytes / +1.085 percentage points**, 33 entries. Current inventory has 1,314 bindings. Its reverse-dependency affected regression passes **51/51 bindings**, native replays and metadata checks, against the frozen motion-flow executable. All fifteen milestone hash audits and the union chain pass. The 65% objective remains **29,057 bytes** away.

## Style selection and five-object rebinding

`motion_style_adapters.c` adds **0x8c094a36 (198 bytes)** and **0x8c094dc6 (166 bytes)**. They check actor/style ownership and activity flags, select the original immutable descriptor table, bind five contiguous objects, and invoke the real initializers added above. The adapter also supplies their original prologues; it delegates existing motion bodies instead of duplicating them.

Development passes **768 / 379 cases**, independent relocated acceptance **512 / 505**, full bodies in each corpus and zero skips. The missing style-7 flag-clear branch required actor byte +0x1561 to equal one: the aligned fixture is **+0x1560, bits 8..15**, rather than +0x1564. Other input dimensions include ownership mismatch, style 0/5/7/18, scene 0/4/5, global enable masks, activity byte +0x57 and the style-3 special flag. Immutable descriptor arrays at 0x0c1016a0 and 0x0c11cdfc are read from the original executable, never patched; only their runtime model-map entries and writable data chains are seeded.

Manifest `percentage_motion_style_milestone.json` hash audit passes; immutable `vf3matrixfamily_percentage_motion_style_v1_dev.exe` SHA-256 and exact evidence paths are frozen there. Five tracked style recipes regenerate 384 general / 192 branch development variants, 360 / 280 frames, and 256 acceptance variants, 320 frames, using the same disjoint scenario, holdout, relocation and 60,000-op budget convention. Evidence: `percentage_motion_style_complete_dev`, `percentage_motion_style_replay.json`, `percentage_motion_style_complete_accept`, `percentage_motion_style_accept_replay.json`.

The motion-family tranche adds **1,460 unique bytes** in six entries. Campaign total is **253,834 / 434,656 (58.40%)**, **+5,080 bytes / +1.169 percentage points**, 35 entries. Current inventory has 1,316 bindings. Reverse-dependency affected regression passes **53/53 bindings** and native replay/metadata checks against the frozen style executable. All sixteen milestone hash audits and the address-union chain pass. The full 1,295-binding frozen gate reported above predates this tranche; the current dependency regression covers the changed routes and new bindings.

The 60% checkpoint still needs **6,960 bytes**; 65% still needs **28,693**. The percentage objective is unfinished. The campaign retains the fixed denominator and full-body gate, including apparently unreachable branches. Next work needs additional original caller/data contracts and broader platform models for the parked boundaries; repeating the tested generic queues without a new hypothesis is not evidence of progress.
