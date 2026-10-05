# Target campaign continuation, 2026-10-05

The campaign target remains **249,528 verified unique C bytes**. Starting at
233,838, five accepted milestones add **3,428 bytes across 27 frozen roots**,
reaching **237,266 / 434,656 (54.5871%)**. **12,262 bytes remain**. These gains
include newly verified existing static translations; they are not all new
readable implementations. SDK attribution supplies no coverage credit.

| Milestone | Roots | Unique bytes | Development / acceptance |
|---|---:|---:|---|
| `advance_target_motion_milestone.json` | 2 | 406 | Original bounded record walker, separate states and relocation |
| `advance_target_commands_milestone.json` | 8 | 940 | 1,400 strict development cases; fresh selector inputs and relocated queue |
| `advance_target_command_pair_milestone.json` | 1 | 84 | 152 development and 152 acceptance cases |
| `advance_target_families_milestone.json` | 10 | 1,476 | 5,168 development and 4,376 acceptance cases |
| `advance_target_extra_milestone.json` | 6 | 522 | 2,589 development and 2,596 acceptance cases |

Every newly credited root executes its entire frozen body in development,
with at least 64 distinct complete inputs across original states 21/27.
Acceptance uses independent states 23/29, changed inputs and relocation by
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
