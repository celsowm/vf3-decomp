# Execution from 59.14% — 2026-10-09

Start: **257,050 / 434,656 bytes (59.14%)**, 1,357 bindings.
Accepted so far: **257,644 bytes (59.28%)**, four new bodies and
594 additional unique bytes. The 60% checkpoint still needs 3,150 bytes;
the 65% objective still needs 24,883. This is a checkpoint in the
[authorized expansion plan](coverage_after_5914_plan.md), not completion
of its percentage objective.

## Readable implementations

| Frozen body | Source | Bytes | Development | Independent acceptance |
| --- | --- | ---: | ---: | ---: |
| `0x8c0af44e` | `script_scale_commands.c` | 60 | 256 | 512 |
| `0x8c0af610` | `script_scale_commands.c` | 182 | 256 | 512 |
| `0x8c0af38c` | `script_position_command.c` | 188 | 256 | 256 |
| `0x8c0a8d5c` | `motion_descriptor_command.c` | 164 | 241 | 485 |

All four execute their complete frozen bodies in both corpora and replay
strictly with zero skips. Each uses its original callable prefix, real
helpers and dispatcher/tail. No new static adapter was generated.

The scale/decrement commands preserve MACL, stack and ABI scratch effects,
signed script fields, SHAD, minimum decrement and saturation. The decrement
calls the existing model selector. Its first two acceptance captures missed
branches: independent input dimensions accidentally paired scene 7 with a
disabled main gate. The third capture covers every body instruction; the
earlier captures remain retained and uncredited.

The position command retains the original sequence of single-precision
operations, FPSCR-aware moves/saves and sine/cosine helper calls. Its angle
calculation subtracts a word from itself; preserve that observed operation
instead of assuming a new angle input. Acceptance changes finite positions,
model offsets, gate strides and angle words and relocates owned records.

The motion descriptor installs actor flags, positions, angle, frame selector
and auxiliary field, refreshes changed motions through the original packed
record loader, and selects the original first-frame or ongoing-frame helper.
Development uses states 27/29 and motion indices 0/1/2; independent acceptance
uses states 26/28, indices 0/3/4 and relocated descriptor storage. Actor records
and the runtime motion table retain their actual game addresses. Rejected
exception/device specimens remain in the raw archives; none enters replay.

The three milestone manifests are
`tools/oracle/percentage_5914_{script_scale,position,motion}_milestone.json`.
The first two replay snapshots are retained; the final snapshot is
`build/vf3matrixfamily_5914_motion_v1_dev.exe`, SHA-256
`8a9a1920ccd88aa80fecd091c83af9f696d0a918cffec2e52bb2e0271bedca5b`.
Executable freezing precedes acceptance for each implementation.

## Original runtime contracts recovered

Natural, nonredirected capsules from states 21/27 and `vf3_fight_keep.state`
provide the following observations. `tools/oracle/passive_contracts.py`
reports argument values, captured RAM words and executed indirect destinations
with raw-capsule hashes; its reports are advisory and award no coverage.

* Object records have a 328-byte stride at `0x0c1b34d8`. The live vtable
  pointer at `0x0c1b34d4` is `0x0c1b34c0`; slot +12 is `0x0c066d32`.
  All 128 naturally observed `0x8c04fe9e` calls tail to that actual reader.
  It reads an unsigned 16-bit word at object field +36 plus twice R5.
  This resolves that callback without substituting a generic return.
* The motion-table global at `0x0c29b9f8` is `0x0c5f4000` in the observed
  loaded states. Natural actors are `0x0c1fefe4` and `0x0c20138c`;
  their +`0x1d00` pointers are `0x0c226864` and `0x0c227064`.
  `0x8c09d5ae` uses the actor's one-based word +60 to index 12-byte offset
  records, adds their three offsets to the table base, and unpacks sixteen
  bytes into four two-bit fields each in the VM record.
* The real AICA enqueue pointer at `0x0c19e218` was observed as
  `0xa0800404`, `0xa0800420` and `0xa0800448`; it belongs to sound RAM,
  not an invented SH-4 heap pool. A natural `0x8c0c5d86` call with ID 123
  reaches the original config reader and enqueue helper and records its
  device interactions. The helper's 56-byte frozen body was already credited;
  the continuation `0x8c0c5dba` has no separate frozen body. Neither earns
  new bytes in this campaign.

Raw observations and the report are retained as
`percentage_5914_{natural_contracts,fight_natural_contracts,passive_contracts}`
under `extract/analysis/`.

## Bounded pilots that do not qualify

The command-submission pilot preserves the original ID map, generation,
deduplication and real pool. It produces 96 complete helper inputs but only
26 complete enqueue inputs and misses enqueue branches. Opcode 32's original
prefix produces 32 complete inputs covering 46/124 body bytes. Scheduler
crossings remain rejected. The helper observations do not qualify this opcode
or its callers, and no implementation or byte credit is claimed for them.

Five object-pool callers were tried through their recovered prefixes with
bounded typed descriptors and the actual callback. Their frozen coverage is
108/112, 94/258, 110/276 and 88/116 bytes; the fifth produces no qualifying
corpus. The first needs a real negative result from `0x8c04bf28`; other
callers need copy/retry and positive lookup contracts. Do not fabricate an
error return or treat a loop-skipping capture as a full proof.

The motion siblings `0x8c0a9040` and `0x8c0a94d4` reach 210/348 and
178/188 bytes. The latter's missing branch is equal motion with a frame
selector other than one. The former also needs the global `0x800` special
path and its nested frame contract. These remain uncredited.

Acceptance attempts in states 31/33 produced no probes. A separate hit-count
pilot shows only one hit at `0x8c03fa52`, and no hits at the menu trigger,
scene manager, division helper or motion loader in 90 frames. These snapshots
do not provide active acceptance scenarios for this work. States 26/28 do:
their runtime table is loaded and their menu trigger has thousands of hits.
All empty captures and trigger reports remain retained.

The proposed `0x8c09af6c` family is a scene/input family rather than a packed
motion decoder: its helper combines +8 flags from 20-byte input records at
`0x0c2cf834`, according to mode bits at `0x0c29bccc`, and stores scene +`0x1ec`.
All five original caller prefixes were tried with bounded mode and input flags.
Only 17–27 complete helper inputs survive per corpus; none of the five caller
bodies qualifies, and scheduler crossings remain rejected.

The three `0x8c0ca05c` family prefixes were also tried with real actors, style
IDs, scene input masks and the actual sound pool. `0x8c098042` produces no
complete caller inputs; `0x8c099070` reaches 66/232 bytes with 106 inputs;
`0x8c0c9f62` reaches 128/188 bytes with 36 inputs. These are retained failures,
not byte gains. The style-to-ID lookup is established, but the larger callers
still need the process-level audio boundary.

## Observation and audio feasibility

The next audio work is specified in
[the audio execution and playback plan](audio_execution_plan.md), including
repeatability diagnosis, one-shot capture, full device comparison, command
recovery and eventual portable playback.

Three fresh-process passive repetitions plus an unwatched control were run
from state 27, with no synthetic entry patch, a 128-sample limit and complete
180-frame execution. Final 16 MiB RAM dumps at frame 170 have different hashes
even among the three observed repetitions. The same check from state 31 also
differs, and that state has no qualifying watched calls. This fails the
repeatability gate before it can establish observer equivalence; it does not
prove that the observer caused the differences.

The broad audio enabling work consequently remains open. Existing passive
capsules record SH-4 state, touched RAM and ordered device accesses, but do
not establish a complete ARM7/DSP/timer/channel/scheduler/audio comparison.
No scheduler rejection is relaxed. A one-input, one-invocation nonrollback
capture must not be accepted until process-level determinism, RAM-only control
and the planned input/timer/ARM negative controls are demonstrated.

## Validation

All 39 native checks and 54 oracle-tool tests pass, including three new
contract-report tests for observed delay-slot destinations, truncated traces
and RAM aliases/bounds, and an acceptance mutation/deletion audit test.
Promotion now archives both development and acceptance fingerprints for direct
entries as well as callable-body attributions. Audit rechecks both full bodies,
disjoint scenarios and archive hashes. All three new manifests include these
fingerprints. The milestone chain and new artifact hash audits pass; the
existing model-selector quality manifest also passes the strengthened audit.
The full **1,361/1,361-binding regression passes**, with zero failures, against
the final frozen executable. Its inventory, executable, log, native/tool
results and chain hashes are recorded in
`tools/oracle/percentage_5914_regression_scope.json`.

An earlier regression using the position snapshot was stopped after the
motion implementation changed the executable. Its partial log is retained as
`percentage_5914_position_partial_regression.log` and is not a complete gate.
The final inventory is frozen at
`extract/analysis/percentage_5914_final_bindings.json`.
