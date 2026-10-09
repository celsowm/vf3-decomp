# Audio execution ledger (2026-10-09)

Execution of [the audio plan](audio_execution_plan.md). Audio tooling earns no
decompilation credit. Accepted channel allocation brings the readable-C union
to **258,430 / 434,656 (59.46%)**.

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

## D: independent channel allocation accepted

`src/fight/audio_channels.c` implements the complete 786-byte `0x8c040fa4`
body and its unsigned division dependency. Both corpora execute the entire
frozen root body: **128 distinct development cases in states 26/27** and
**128 distinct acceptance cases in states 28/29**, with zero native skips and
no nondeterminism. All **256 original/live-C comparisons** match exactly:
ordered bus operations, guest instruction paths, CPU/cache/RAM, AICA/ARM/DSP,
scheduler events and PCM. Development has 121 real AICA crossings; acceptance
has 128. Acceptance changes counts, modes and allocation inputs and relocates
the owned stack to `0x0c3fd000`. Native and research executables were frozen
before acceptance.

The recipes cover every legal mono/dual layout, enabled-channel rejection at
all eight positions, mode rejection, weighted overflow, unclamped allocation,
unaligned starts, signed negative counts, enqueue rejection and ring wrap.
Busy enqueue still returns zero from configuration. The division dependency
earns no separate credit. The C path generates its own writes and branches;
original ARM/DSP execute normally in the research backend. Generic RAM patching
and rollback guards remain intact; allocation uses typed live-bus inputs.

The first 16-pair C pilot failed eight positive cases because helper PCs and
return PR used the wrong cached/physical alias. Final registers, RAM and PCM
matched, but instruction evidence did not. The retained failure is
`audio_channels_compare_pilot_v1.json`. The corrected 24-pair pilot passes
fully; its native corpus has 23 distinct inputs after exact deduplication.
Qualifying corpora use corrected source and `flycast_audio_channels_v2.exe`.

The AICA observer now records eleven volatile DSP words omitted by the ordinary
serializer. Layouts are pinned by executable/source hashes; old opaque captures
remain readable. New corpus metadata says `process_owned_audio` and
`frame_complete:false`. Promotion pins the batch and its live evidence while
preserving the old completed-frame gate. Changed sources, rollback and invented
frame completion are rejected. Identical audio archives become hard links only
after full SHA-256 reconstruction checks; failed evidence and paths remain.

Sources are retained under `extract/analysis/audio_channels_v2_frozen_sources/`.
Evidence is sealed in `audio_channels_v3_manifest.json`; byte credit is in
`percentage_audio_channels_milestone.json`. Marginal union increases exactly
786 bytes, from 257,644 to 258,430.

## D: submission and actor cleanup accepted

`src/fight/audio_submission.c` replaces the existing submission adapter with
readable scene/config gating, signed ID rejection, immutable command mapping
and generation-based deduplication. The stamp updates before enqueue, including
enqueue failure. The paired 32-run pilot covers IDs, scene 3 configuration,
deduplication, queue-busy behavior and style lookup. All live architectural,
memory, instruction, device, AICA and PCM comparisons pass. Its native cohorts
contain 26 submission and six style inputs; both also pass against the final
actor executable. The complete 56-byte submission body is exercised. Existing
credit is retained; style has no standalone frozen inventory entry.

`audio_id_map.py` compares all 477 map words with the original image. Both
observed states match exactly, and submissions leave the map unchanged. This
prevents confusing a negative map slot with a dynamically initialized table.
The pilot is sealed in `audio_submission_pilot_v1_manifest.json`.

`src/fight/audio_actor_clear.c` implements callable `0x8c098040`, whose frozen
owner is `0x8c098042` (72 bytes). It requests startup words for channels
**1, 2, 4, 5, 6, 7**, submits both actor styles, and clears bit 0 on six task
objects. The private startup encoder is specialized to this caller's constant
arguments; it does not claim the complete general selector/encoder helpers.
Two original BSR/NOP callers establish the entry. The prefix audit additionally
requires the declared saved register, its original restoration, complete image
PCs and preserved stack/register values in every native case.

Development uses states 26/27; acceptance uses 28/29, different styles, flags
and generations, actor objects moved from `0x0c404000` to `0x0c480000`, and
stack `0x0c3fd000`. Both cohorts contain 128 distinct complete inputs, execute
the complete frozen body and pass native replay with zero skips. **256/256**
strict live comparisons pass, each crossing a real AICA event. The eight-pair
actor pilot also passes. The frozen executable is
`build/vf3matrixfamily_audio_actor_clear_v1.exe`; matching research sources are
archived in the explicitly selected local audio-evidence cache. Large new
captures use that cache because drive E remains close to its 4 GiB reserve.
Hash-verified hard links preserve every evidence path.

Evidence is sealed in `audio_actor_clear_v1_manifest.json` and
`percentage_audio_actor_clear_milestone.json`. The marginal union grows exactly
**72 bytes**, to **258,502 / 434,656 (59.47%)**. The full 1,362-binding baseline,
upgraded submission's 26 strict cases and added cleanup's 128 strict cases all
use the same frozen matrix executable. All 39 native suites were freshly linked,
rerun and archived; 86 tool tests and the complete milestone hash chain pass.
The final 1,363-binding scope is `audio_actor_clear_v1_regression_scope.json`.

## E: bank identity and ARM observation

`audio_state.py` distinguishes requested key bits from actually enabled voices.
`audio_bank_map.py` requires complete byte equality with shipped DTPK files.
All thirteen enabled voices at the last retained state-26 checkpoint have sample
bases inside the complete **BGM_VAN.BIN** image at **AICA `0x086e50`**,
length **1,014,948 bytes**. State 28 also contains this bank. The older
`0x086e54` measurement was the first changed byte, not the file's start.
Shared sections alone do not identify a bank.

Resident ARM firmware matches **SNDDRV.BIN**: vector bytes and the complete
code interval `0x0510..0x9fff` match all eight aligned state-26/28 checkpoints.
RELOAD.BIN begins with SH-4 instructions; its entry is the wrong ARM target.
Measurements are in `audio_snddrv_identity_v1.json` and the two bank-map reports.

The separate ARM observer records real protocol reads, stores and voice MMIO.
The x64 compiler supplies the original ARM PC before memory operations and
interpreter fallbacks. Ordering is exact; time is the enclosing SH-4 callback,
not an exact ARM cycle. The two-million-record limit is explicit. This is
research instrumentation, not a C driver or command-semantics implementation.
The first long pilot timed out before checkpoint three; partial evidence is
retained and rejected. A shorter equivalence pilot uses the same two states
at instructions 1 and 4,194,304 and **passes in both states**. All identities
and seven checkpoint sections match with observation enabled. The complete
traces contain 44,380 state-26 and 85,342 state-28 records, with no truncation.
State 26 shows nine nonzero queue words read at ARM `0x668`/`0x674` and cleared
at `0x688`. State 28 has 277 real hardware voice-register writes. No replacement
C ARM handler is claimed. Evidence is sealed in `audio_arm_observer_v2_manifest.json`.

Bank identity and queue reads alone do not establish menu/fight/second-song
C agreement, voice reset semantics or standalone playback. Those gates and
sound-dependent SH-4 callers remain open.

`src/media/driver_queue.c` now recovers the bounded A0 handoff: stable double
reads, scratch publication, clearing the external slot, advancing its 256-byte
ring, byte reversal, ORing bit 6 and appending to the internal 1,024-byte ring
at `0xa400`. Nine independent observed inputs reproduce all nine ordered store
sequences. A separate synthetic wrap fixture and unsupported/empty/input guards
pass. The API validates its owned inputs; its status values are host API results,
not attributed ARM return values. It does not model instruction timing, ARM
registers/interrupts, non-A0 classes, later dispatch, DSP or PCM generation.
No extra ARM or SH-4 coverage is claimed. Evidence is
`audio_arm_handoff_v1_manifest.json`; the native runner builds as `vf3driverqueue`.

The older purported streaming window overlaps the ARM stack, driver context,
internal command ring and sixteen 48-byte software records. Static literal/layout
evidence is `audio_arm_workspace_v1.json`; the command-ring stores are separately
observed. Sample streaming and reset semantics are still unproved.

`audio_pcm_compare.py` uses the existing PCM exporter after strict original/
observer equality. State28 exports 14,446 stereo frames at 44,100 Hz, about
0.328 seconds, with reversible right/left-to-left/right channel ordering and
sample-perfect WAV reconstruction. This is a bounded research rendering; manual
listening and standalone playback are not claimed. Unused opcodes guessed from
debug-string order have been removed from `src/sys/soundcmd.c`; unresolved
endpoint addresses remain zero until attribution is proved.

## Accepted milestone checks

The section below records the preceding channel milestone. The actor-cleanup
scope above supersedes its final inventory counts.

The 1,361 unchanged bindings pass against the immutable channel executable;
the added binding passes its 128 distinct strict cases against that same
executable. This covers the complete **1,362-binding** inventory. All **39
native checks** and **83 tool checks** pass. The complete percentage milestone
chain, raw evidence hashes and independent live proof metadata pass. The
components and frozen sources are sealed in `audio_channels_v3_regression_scope.json`.
