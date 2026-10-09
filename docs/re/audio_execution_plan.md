# Audio execution and playback plan (2026-10-09)

This plan turns the audio blocker into verified readable C command handling
and, subsequently, working music/voice playback. Execute milestones A through
F in order; advance only after each gate passes. Planning and capture tooling
earn no coverage. The accepted baseline remains 257,644 / 434,656 bytes
(59.28%), commit `01e3b7f`, with 1,361 bindings, 39 native checks and 54 tool
tests passing. No percentage increase is promised for the infrastructure work.

Results and corrections are recorded in [the execution ledger](audio_execution.md).

## Evidence and scope

- DTPK extraction and AICA ADPCM already have bit-exact C implementations in
  `src/media/`. Reuse them; decoding samples is not the current blocker.
- `src/fight/command_encoders.c` already models command encoding/enqueue.
  `0x8c040f1e` is the useful small queue control; `0x8c0c5d86` is an already
  credited 56-byte submission helper. Queue storage is the original
  `0xa0800400..0xa0800500`, through pointer global `0x0c19e218`.
- `VF3_ROLLBACK_AICA_RAM` journals sound RAM but rejects scheduler crossings.
  It does not rewind ARM7, DSP, channels, timers, DMA, interrupts or scheduled
  work. Keep that guard and its existing proof contract intact.
- The retained observation pilot failed repeatability, including within three
  fresh-process repetitions. See
  `tools/oracle/percentage_5914_observation_pilot.json` and
  [the execution ledger](coverage_5914_execution.md). This does not establish
  that the observer caused the differences.
- `src/sys/soundcmd.c` has unresolved zero-address endpoints and speculative
  command naming. Treat it as a research model, not verified playback.
  The old [AICA adapter note](aica_stub.md) covers a SH-4 copy/dispatch helper,
  not a complete audio device implementation.

The first delivery is a trustworthy scheduler-crossing command comparison.
The second is attributed song/voice control with audible playback. Hardware
emulation remains an oracle/backend concern; game-side recovered behavior
belongs in readable C. Using Flycast to validate a command does not constitute
a readable-C port of its ARM7 driver or DSP.

## A. Diagnose and establish deterministic observation

Use active states 26 and 28 first. Verify the actual trigger and sound calls
before capturing; states 31/33 produced no qualifying calls in the previous
pilot and are unsuitable substitutes. Record state/image/build hashes, input
script, settings, interpreter mode and trigger occurrence.

Instrument bounded checkpoints at matching guest instruction and emulated
cycle boundaries. Compare three unobserved fresh-process runs, three observed
runs, and a known short RAM-only control. A final frame-number RAM hash alone
cannot locate the fault. Find the first differing register, page, event or
sample; progressively narrow the interval rather than increasing capture
duration or masking differing bytes.

Investigate state-load/start ordering in `core/windows/winmain.cpp`, RTC/host
clock inputs, controller delivery, asynchronous storage completion, pending
render events and thread scheduling. These are hypotheses, not established
causes. Pin or record genuine external inputs at their guest-visible delivery
boundary; preserve original guest device/event ordering. Document every
normalization with the causal evidence that makes it safe.

Deliver `tools/oracle/audio_determinism.py` and a tracked manifest containing
build/input hashes, aligned checkpoint hashes, first-divergence reports and
pass/fail controls. Raw snapshots remain under ignored `extract/analysis/`.
Gate: identical relevant entry/exit state and event sequences on repeat runs,
with observed and unobserved controls equivalent. If whole-game determinism
cannot be established, test an isolated invocation from a complete original
entry snapshot; explicitly establish its determinism before proceeding.

## B. Add one-invocation capture without rollback

Add an explicitly separate one-shot mode in `tools/oracle/vf3oracle.cpp` and
its emulator integration. Start a fresh process for every state/input, capture
one original call, let real scheduled devices run, and stop after its verified
return or known tail-transfer completion. Do not continue the game or invoke
a second input in the same process.

Use the interpreter's instruction/return hooks to request a stop, then exit
through a safe emulator lifecycle boundary. Inspect
`core/hw/sh4/interpr/sh4_interpreter.cpp` and the Windows runner together:
stopping the CPU is not automatically a safe point to serialize a running
callback or flush another thread. Capture the exact return boundary, including
delay-slot effects, without executing the caller's next instruction. Preserve
normal interrupt handling and reject faults, truncation and unmatched returns.

Deliver a bounded process runner and explicit mode/completion metadata. Add
negative tests for faults, timeouts, tail transfers, nested calls and attempted
reuse. Gate: a real call crosses an AICA event and completes reproducibly;
the RAM-only mode still rejects that same crossing. A successful early return
does not satisfy this gate.

## C. Capture and compare the complete audio contract

Introduce a versioned audio capsule alongside the SH-4 capsule. Inventory:

| State | Capture/comparison source |
|---|---|
| SH-4 architecture, RAM/cache effects | Existing oracle, plus exact guest cycle position |
| 2 MiB AICA RAM and registers | Explicit full initial image and final changes |
| ARM7 registers, mode, IRQ/FIQ, clock and execution | `hw/aica/aica_if.cpp` and ARM execution hooks |
| DSP memory, registers and progress | DSP state and execution hooks |
| Channel/sample, ADPCM, envelopes, filters, LFO/noise | `hw/aica/sgc_if.cpp` |
| Timers, interrupts and DMA | AICA update and DMA event hooks |
| Scheduler and other interacting devices | `hw/sh4/sh4_sched.cpp` plus each relevant device |
| Generated sound | Exact guest-generated PCM samples, count and sample times before host resampling |

The existing serializers are an inventory, not a proven safe capture boundary.
In particular, AICA RAM is omitted when their rollback flag is set. Audit
derived channel fields, host output buffering, CDDA/MIDI state and pending
work rather than assuming a savestate covers everything. Pin the serializer
and emulator build. Identify scheduled events by device/role and time, not
unexplained numeric callback IDs.

Define a cycle-aware device interface for the C replay. First validate the
original and C executions against the same initialized research backend;
recover smaller standalone device models only where evidence supports them.
C must generate its own command writes, waits and state transitions. Recorded
external inputs may be replayed; recorded expected writes, device replies
caused by those writes, or golden final state may not be copied into the result.

Gate: strict architectural, RAM, ordered-device, audio-state and PCM comparison
passes a real event-crossing command. Changing a meaningful input, timer/ARM
state, command byte or sample must produce a detected difference. Unrelated
events remain observable whenever they affect the invocation.

## D. Recover command families, smallest first

1. Revalidate `0x8c040f1e`: invalid command bit, free slot, busy/full pool,
   pointer wrap and natural pointer positions. Then close the real submission
   chain through `0x8c0c5d86`: scene/config gating, ID range 0..476, immutable
   map `0x0c1025f0`, dedup table `0x0c2cfa00` and generation `0x0c1fd758`.
2. Recover the complete uncredited `0x8c040fa4` body. Known initial branches
   reject R6 != 0, R4 + 2*R5 > 8, or an enabled channel in the eight-record
   table at `0x0c19e250`. The positive path writes `0xa08000a0/a4` and reads
   `0xa080008c`. Disassemble the remaining polling/command path and establish
   the actual completion protocol before choosing event inputs. Preserve its
   waits, errors and state publication; never invent an early-success return.
3. Revisit the `0x8c0ca05c` callers `0x8c098042`, `0x8c099070` and
   `0x8c0c9f62`, using real actors and the immutable style/ID table at
   `0x0c11331c`. Then revisit sound-dependent scene/input callers of
   `0x8c09af6c`. That helper is not a motion decoder. Attribute each remaining
   failure separately; object/GDFS failures are not automatically audio faults.

Deliver readable C, independent development/acceptance recipes and manifests
per accepted family. Compute marginal frozen-body union after each tranche;
the helper/submission bodies already credited must not be counted again.
Gate: full frozen-body execution in both corpora, at least 64 distinct complete
inputs each, two scenarios per corpus, disjoint development/acceptance states,
changed acceptance inputs and relocated owned writable objects where valid.
Freeze the executable before acceptance; archive both proof fingerprints.

## E. Attribute music, voices and reset behavior

Create verified menu-to-fight and fight-to-next-song playback scripts. Capture
SH-4 issuers, G2/AICA transfers, ARM command consumption and PCM around each
transition. Use the measured regions in [sound_bgm.md](sound_bgm.md) as leads:
baseline below `0x086e54`, song-kit suffix beginning there, and the observed
streaming window `0x00a0b4..0x00cf5d`. Recheck the address aliases and range
against actual transfers; old speculative bus ranges are not authority.

Associate loaded BGM assets and voice slots with actual calls and command
bytes. Determine which voices survive or reset, when DMA completes, how
streaming wraps, and how stop/pause/restart and overlapping effects behave.
Use debug strings as attribution leads only. Replace zero registry endpoints
and inferred opcode ordering in `src/sys/soundcmd.c` after runtime proof.

Deliver transition ledgers with transfer CRCs, bank/slot maps, command timing
and short rendered WAV comparisons. Gate: original/C agreement on command
ordering, kit contents, reset effects and sample output for menu, fight and a
second song/scene. Listening supports the numerical checks; it does not replace
them. Decoded assets alone are not evidence of command semantics.

## F. Connect playback to the portable C port

Expose verified load-bank, start/stop voice, command and advance-by-cycles
operations in a small audio interface. Choose a host PCM output backend after
the guest contract is known, using the repository's actual platform needs.
Keep host resampling/buffering outside the deterministic guest mixer boundary.
Integrate existing DTPK/ADPCM code; add voice mixing, loops, envelopes, pan,
pitch and DSP behavior incrementally from proved contracts. Clearly identify
any temporary emulator-backed ARM/DSP dependency in the progress ledger.

Gate: the port plays verified menu/fight music and an overlapping voice/effect,
survives the demonstrated bank/reset transition, and passes deterministic PCM
regressions plus a bounded manual listening check. Standalone readable-C audio
is complete only when required ARM/DSP behavior no longer depends on executing
the original driver in the research emulator. Track that separately from
verified SH-4 command coverage and from working host playback.

## Resources, checks and delivery

Start with a few one-shot inputs per control, not hundreds of full snapshots.
An uncompressed initial RAM pair is already 18 MiB before registers, traces
and output. Measure pilot storage, set instruction/cycle/event limits, keep
the existing 4 GiB free-space reserve, and retain failed evidence. Deduplicate
immutable images by hash after validating reconstruction.

Commit each milestone with source, recipes, manifests and documentation;
never commit `rom/`, `extract/` or `build/`. Report repeatability and positive
event-crossing results before claiming the audio boundary is solved. Run
affected checks per tranche and the complete current binding inventory,
native/tool suites, artifact audit and milestone chain against the final
executable when promoting C changes. Documentation-only planning does not
require rerunning the baseline regression.

If a milestone fails, retain its first-divergence/negative-control result and
name the missing contract. The next pilot must test one new causal hypothesis.
Do not relax rejection guards or promote incomplete bodies to gain percentage.
