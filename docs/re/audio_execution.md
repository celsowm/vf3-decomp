# Audio execution ledger (2026-10-09)

Execution of [the audio plan](audio_execution_plan.md). Audio tooling earns no
decompilation credit; the readable-C union remains 59.28%.

## A: aligned observation pilot passes

Added `tools/oracle/audio_determinism.py` and research-only `vf3audio.cpp/.h`.
The installer reproduces interpreter, scheduler and pre-host-output PCM hooks.
The recorder copies state without cache writeback, invalidation or device
ticks. Each checkpoint is after opcode fetch and before dispatch, identified
by instruction ordinal, PC/opcode, emulated scheduler time and cycle counters.
It includes all 63 existing architectural words, physical SH-4 RAM, serialized
AICA state including sound RAM, caches, scheduler state, accumulated guest PCM
and scheduler callback events. This is an observation format, not a proven
complete device restore format or C replay acceptance.

The synchronous pilot `extract/analysis/audio_sync_long_v1/manifest.json`
passes all ten comparisons: three baseline processes and three processes
observing real enqueue/submission calls in each of states 26 and 28.
Checkpoints are at instructions 1, 4,194,304, 16,777,216 and 67,108,864.
All seven state/output sections and checkpoint identities match exactly.
The observed capsules contain ten completed calls per state-26 run and two
per state-28 run. Original state-26 execution reaches 47 runner frames before
the final instruction checkpoint; 324,692 bytes of guest PCM and 1,968,096
bytes of scheduler events are compared there.

Five diagnostic tests pass: identical streams, register/RAM/AICA/PCM/event
mutations, misaligned guest boundaries, truncation/missing records and exclusion
of simultaneous diagnostic batches. The runner locks the emulator's staging
directory because all instances share staged savestate slot 0. An earlier
short synchronous batch overlapped a threaded batch; its manifest is explicitly
invalidated and its raw evidence retained. The longer passing batch ran alone.

The earlier frame-170 RAM mismatch remains a failed observation result. Its
frame counters identify host renderer iterations, not a fixed guest instruction
boundary; `vf3script.cpp` copies RAM from that runner without stopping/joining
guest execution. The new result establishes bounded repeatability, rather than
proving the cause of every previous RAM difference. A short threaded diagnostic
also matched at aligned instruction boundaries; threading alone is not proven
to make the guest nondeterministic.

## Newly resolved static contract

The complete `0x8c040fa4` disassembly contradicts the proposed polling lead.
It validates signed 16-bit arguments, rejects active channels, computes aligned
per-channel allocation, publishes 24-byte host channel descriptors and 96-byte
AICA descriptors, disables unused slots, posts `0xa1` through `0x8c040f1e`
and returns zero. There is no completion-polling loop in this body. Its frozen
size is 786 bytes; all-path execution and independent C/device replay remain
required before any credit. This evidence updates phase D's implementation
target; it does not establish the ARM7 meaning of command `0xa1`.

## B: process-owned original calls pass

`VF3_ONESHOT` is separate from rollback probes and forbids rollback flags or
threaded execution. Each process arms one redirected original invocation,
captures audio at entry and its completed return/tail boundary, and stops via
the interpreter's normal stop exception before executing the caller. No game
state is restored. The capsule summary records mode, completion and restores.

The fixed-installer pilot `audio_one_shot_acceptance_v3` passes 30/30 runs:
three repetitions of five cases in states 26 and 28. All 20 repetition
comparisons match full audio checkpoint bytes. Cases cover invalid-command
RAM-only execution, positive channel configuration with a real AICA callback,
argument rejection, an actual style-helper tail jump after its delay slot,
and rejected instruction-budget exhaustion. Positive configuration completes
with result zero and one AICA callback; all one-shot restore counts are zero.
The nested division/enqueue calls are included in the positive invocation.

`audio_rollback_guard_v3` rejects both positive configuration attempts with
flag 4 and a recorded timeslice abort. This is the existing guard: it rejects
any scheduler timeslice, even one before the next actual AICA callback.
Short one-shot controls do not imply a short rollback control will fit the
remaining cycles at this particular trigger.

A tail-transfer negative control found an installer upgrade defect: adding the
one-shot stop check made the previous textual hook replacement appear absent,
so the old installer inserted a second observer call. The new normalization
installs exactly one hook and has an idempotence/upgrade regression test.
Earlier one-shot/guard v1/v2 evidence is invalidated and retained; the passing
v3 captures use the repaired executable. The phase-A recorder had one hook.

The 60 oracle-tool tests pass. These results establish original-call capture,
not C/device replay or portable playback. Fault/timeout rejection is enforced
by the runner's completion checks; broader live fault/interrupt campaigns
remain work alongside the device bridge.

## C: bounded live-C queue bridge passes

`vf3audiobridge.cpp` compiles the existing readable enqueue body from
`src/fight/command_encoders.c` against actual emulator memory/device reads and
writes. Optional C statement markers charge opcode fetch/issue timing using
the interpreter's existing cycle accounting. They do not execute original
opcodes or choose branches. The ordinary portable build discards these markers.
The bridge invokes the real scheduler, ARM7, DSP, timers and sample generator;
golden data supplies no device responses or expected writes.

The sealed `tools/oracle/audio_live_queue_v1_manifest.json` passes **16/16**
strict original/C comparisons. Six are three repetitions in each of states 26
and 28, with an actual AICA callback on every invocation. Four more compare
changed real timer settings and disabled ARM input. Six cover invalid commands,
busy slots and queue wrapping in both states; three cross actual AICA callbacks.
Capsule comparisons cover all 63 architectural words, return boundary, touched
RAM pages, instruction path and ordered bus transactions. Every audio identity
and all seven checkpoint sections match, including caches, full AICA state,
scheduler, callback events and guest PCM. Completion requires exactly one call,
zero restores, no unaccounted/incomplete call and a successful process exit.

A command-corruption control changes the C backend's real queue write and fails
at the ordered device transaction and AICA output state. Timer/ARM controls
change the initial serialized AICA input while preserving entry architecture;
both original and C run against that changed input. The input-control evidence
is sealed alongside the positive comparisons. Selecting a natural trigger near
an event changes neither clock nor event schedule. A fixed ordinal crossed an
event in state 26 but not 28; that earlier gate remains failed and retained.

All queue return paths are checked. The general entry patcher correctly rejected
an attempted AICA-memory patch in `audio_queue_paths_original_v1`; its failed
evidence remains. The passing v2 pilot occupies the current slot through a
dedicated live-bus control. This does not widen rollback or generic RAM patching.
Interrupts/MMU paths unsupported by this small bridge abort and reject the
invocation. Configuration/caller bridges still require their own timing and
exception verification; this queue result is not a general audio-call backend.
Four original/C controls with budgets of eight and twenty instructions reject
after actually entering the C backend. Their capsules and complete audio
checkpoints match exactly, with flag 4 and zero restores; no caller continues.
Fingerprints are in `tools/oracle/audio_queue_budget_v1_manifest.json`.

New checkpoints use gzip only after verifying the exact reconstruction SHA-256.
Raw hashes and compressed hashes are retained. Two earlier source revisions
are retained under `extract/analysis/audio_queue_v1_frozen_sources/`, with hashes
matched against the original v1 capture provenance; both emulator versions are
immutable snapshots. Existing failed evidence remains available.

## D: channel allocation interpretation passes original pilots

Sixteen original calls in additional active states **27 and 29** verify the
allocation contract: mixed, mono-only, dual-only and zero-channel configurations,
all three rejection codes, and truncation of arguments to signed 16-bit storage.
Fifteen calls cross real AICA callbacks. `audio_channel_contract.py` checks
published host descriptors, channel-length publication, the nested queue pointer
and the entire ordered AICA write sequence. The results are sealed in
`tools/oracle/audio_channel_contract_v1_manifest.json`. These are offline checks
of original behavior; they neither feed device reads to C nor qualify this
786-byte body for decompilation credit.

Active descriptors have 24-byte host stride and 96-byte AICA stride. Mono slots
consume one buffer and clear the second; dual slots publish the second buffer
first, then the first, allocating backward. Unused slots publish byte 255 and
`0xffffffff` buffer sentinels. The positive body posts `0xa1` and returns zero
even if enqueue rejects a busy slot; its ARM-side meaning remains unproved.
The bounded pilot does not cover negative counts, unclamped allocation,
unaligned allocation input or an independently scheduled C implementation.

## PCM rendering and remaining gates

`audio_pcm.py` exports pre-host-output guest PCM at 44,100 Hz, converting the
recorder's right/left pairs to WAV left/right and checking exact reconstruction.
The aligned original runs yield 81,173 stereo frames in state 26 and 93,816 in
state 28. WAVs and checks live under `extract/analysis/`; fingerprints are in
`tools/oracle/audio_pcm_v1_manifest.json`. These are research-emulator samples,
without new command/voice attribution or a manual listening claim.

Independent channel-configuration C/device replay, qualifying development and
acceptance corpora, sound-dependent callers, attributed bank/reset/voice
transitions and portable playback remain open. ARM7/DSP still execute in the
research emulator. No additional frozen-body credit is assigned.

## Final checks for this tranche

The frozen production replay snapshot passes **1,361/1,361 bindings** with no
failures. All **39 native checks** and **71 oracle-tool tests** pass. The complete
existing coverage milestone chain and artifact hashes pass, ending at 257,644
readable-C bytes. Snapshot, inventory, regression, test, chain and audio evidence
fingerprints are sealed in `tools/oracle/audio_queue_v1_regression_scope.json`.
