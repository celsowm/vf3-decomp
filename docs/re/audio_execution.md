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

## Remaining gates

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

One-shot return-boundary capture, a positive AICA event crossing with unchanged
rollback rejection, causally generated C/device replay, actual timer/ARM input
controls, attributed bank/voice transitions and portable playback remain open.
