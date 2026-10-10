# Execution toward 65% — 2026-10-10

Plan: [coverage_65_plan.md](coverage_65_plan.md). Start `65043ca`,
258,502 / 434,656 verified bytes. Planning commit `f2fd830` adds no bytes.

## Fight caller attribution: +232 bytes

The frozen owner `0x8c099070` qualifies through original callable
`0x8c099060`. Coverage reaches **258,734 / 434,656 (59.526154%)**;
23,793 bytes remain to 65%, and 2,060 remain to 60%.

The new `vf3-fight-scene-table-v1` contract is deliberately limited to this
dispatcher, target and save shape. The legacy two-BSR/single-save contract is
unchanged. Unknown contract kinds fail. It checks the complete ordered
original dispatcher instructions, PC-relative scene/table pools, original
index 55 and table slot `0x0c10bb84`, immediate transfer to the loaded
`0x0c099060` target, ordered r14/r13/PR saves and PR/r13/r14 restores, real
tail transfer, original return PC and unchanged r13/r14/SP. Prefix/dispatcher
pools and the loaded table slot must match the original image and remain
unchanged in captured RAM. Every captured opcode must match the image.

Sixteen fresh original invocations execute the real dispatcher at
`0x8c0968d0`, in states 26/28 and independent states 27/29 with relocated
actors/stack and changed inputs. These are process-owned caller fixtures
entered through the existing one-shot trigger; they prove the original
dispatcher edge, not naturally observed automatic scene-55 transitions.
There is no synthetic callback or modified target table. Every invocation
completes without invalid flags, preserves saves/SP and crosses AICA.
The manifests and capsules are hash-pinned in
`tools/oracle/audio_fight_callable_v2.json`. Frozen emulator remains
`flycast_audio_fight_live_v1.exe`.

The unchanged readable fight C retains its previously frozen source archive
and executable. Fresh native replays of the independently qualified
development and acceptance corpora pass **64/64 each**, zero skips, and
execute the entire 232-byte frozen body. Their existing **128/128 strict
live comparisons**, real callback/PVR cases and corruption negative control
remain the behavior proof; no implementation was changed after acceptance.
The default executable also passes the 64-case acceptance replay.

Manifest: `tools/oracle/percentage_audio_fight_qualified_milestone.json`.
Reports: `extract/analysis/audio_fight_qualified_{dev,accept}_v2_native_report.json`.
The new binding supplements the existing callable pilot; inventory is 1,366.
The previously sealed baseline/native suites are reused because compiled C
and the executables are unchanged; this is not a fresh full-inventory run.
The new dispatch tests exercise missing/reordered prefix and restore words,
forged targets/index/pools, altered opcodes, wrong return PC and broken save
invariants. All 91 current tool tests pass.

The complete milestone audit with artifact hashes passes: 83 new campaign
entries, +9,980 bytes from the older 248,754-byte campaign freeze, final
258,734 bytes. Report: `extract/analysis/audio_fight_qualified_v2_chain_audit.json`.

Next: qualify the input caller through its real constant-target JSR, then
pilot shared callback/motion families to close the remaining 60% gap.

## Input caller attribution: +188 bytes

Frozen owner `0x8c0c9f62` qualifies through full callable `0x8c0c9f54`.
Coverage is **258,922 / 434,656 (59.57%)**: +420 bytes from this plan's start,
23,605 remain to 65%, and 1,872 remain to 60%. Inventory is 1,367 bindings.

Fresh development and held-out acceptance each contain **64 distinct complete
cases in two states**, with relocated actors/stack and changed inputs. Each
executes all 188 frozen bytes and passes **64/64 strict native/live comparisons**,
zero skips, zero invalid/quarantined specimens and 64 positive AICA crossings.
All original ID/style/mapping tables remain unchanged. An actual C queue-word
corruption gives the expected 0/1 comparison, with a real AICA crossing.

Eight original caller specimens prove literal load `0x8c0c9208`, JSR
`0x8c0c920a`, its NOP delay, unchanged pool `0x0c0c926c`, full input prefix,
PR restoration and actual return through the original continuation branch.
This is one genuine call site; no second caller is invented. These are
process-owned caller fixtures, not natural menu-playback observations. The
new attribution contract is limited to this entry/prefix/return shape and
fails closed for unknown shapes.

The first caller pilot expected the stop at `0x8c0c920e`. The existing
`exitpc` directive captures that transfer instruction and its delay, so the
actual stop is the original branch target `0x8c0c921e`. All eight initial
specimens are retained and excluded; a fresh recipe/capture with the correct
boundary passes. The validator checks both the real JSR return at
`0x8c0c920e` and the original branch/delay to `0x8c0c921e`.

The milestone auditor now resolves absolute report paths and relative binding
paths before matching them. Its prior spelling comparison rejected the new
proof despite matching artifacts. Three focused path tests preserve rejection
of a different corpus; all **98 tool tests** pass. The failed chain report is
retained as `audio_input_qualified_v2_chain_audit.json`; the corrected full
hash-chain report is `audio_input_qualified_v3_chain_audit.json`.

Proof seals: `tools/oracle/audio_input_qualified_v2_manifest.json`,
`tools/oracle/audio_input_callable_v2.json` and
`tools/oracle/percentage_audio_input_qualified_milestone.json`.
Readable C, source archive and native/live executables are unchanged from
the prior frozen fight build. The audit verifies every archived compiled
source against that version. Earlier sealed baseline/native-suite results
are explicitly reused, with fresh default acceptance replay; no fresh full
inventory run is claimed.

Next motion pilot: `0x8c0a94d0`, frozen owner `0x8c0a94d4`. Vary descriptor
frame selector +36 across 0/1/2/3 rather than fixing it at one. The first
32-variant/two-state original pilot produces 54 distinct complete specimens,
with two flag-1 and one flag-4 rejected specimens retained. Native replay
correctly fails at the unsupported full entry. Implement the readable caller
before claiming any bytes; this pilot earns zero credit.

## Motion frame caller qualified

Readable full entry `0x8c0a94d0` now qualifies frozen owner `0x8c0a94d4`,
**+188 bytes**, total **259,110 / 434,656 (59.61%)** and 1,368 bindings.
Development/acceptance pass 109/109 and 118/118 native cases, independently
cover the full body, preserve saves/SP, and complete every started probe.
Eight original-only specimens verify both original BSR sites and ordered
prefix/return. Six new mutation tests bring tool checks to 104.

Raw campaigns retain nine/ten rejected exception/interrupt specimens; these
are excluded, not described as passing or silently discarded. The descriptor
is relocated for acceptance; the actor remains at its actual loaded address.
See [motion evidence and limitations](motion_frame.md). The remaining gap is
**1,684 bytes to 60%** and **23,417 bytes to 65%**.

## Context probes and reachability limitations

Three bounded passive capture batches retain their raw evidence:
`coverage_65_context_v1` (saves 21/27/28, 600 frames each),
`coverage_65_context_v2` (fight save/menu save, 600 frames each), and
`coverage_65_context_actions_v3` (fight/save27 with the retained button script).
The first produces 64 distinct valid original object-callback cases at
`0x8c04fe9e`, all matching the frozen current C executable, zero skips. The
other batches record none of the selected full callers; no credit is granted.
The second watch omits frequent helpers to avoid consuming caller capacity.

A separate 306-entry hit survey records only `0x8c03523c` (one hit) and
`0x8c062ec4` (five) in the retained fight/action scenario. Boot/button playback
completes 4,740 frames and records no selected entries. This boot survey lacks
a known-game positive-control PC, so it does **not** establish game progression
or globally unreachable code. Both results remain advisory, not promotion
evidence. [Counts](coverage_65_reachability.csv) and the hash-pinned
`coverage_65_reachability_v1_manifest.json` retain those limits.

Original disassembly also corrects a plan label: `0x8c09af6c` reads/merges
controller/state bits through `0x8c0a1282`; calling it the packed motion-record
decoder was unsupported. Its 1,302-byte static family lead remains advisory.
`0x8c0a9036` includes two actual sound-submission calls, so qualifying its whole
body requires their full audio contract. Object callers still need the real
`0x8c053790` lookup/error path; the callback alone does not unlock them.

The bounded closed-file experiment `coverage_65_object_error_dev_v1` invokes
actual `0x8c053ce4` and its actual error tail `0x8c053d8c`/`0x8c04bd20`,
without changing instructions or callback targets. All eight probes are
rejected (seven flag-6, one flag-1); there are **zero valid replay cases**.
Seven stop at `0x8c04bd2c`, reading context +0x18c0 with the captured context
global `0x0c1b2088` equal to zero. The kernel context `0x0c1a0d24` is present
(`0x0c19fc30`), but it is insufficient for this error path. This localizes the
missing stream/error context rather than supplying a fake return value.
The empty discovery report earns no coverage. Next evidence must include
the naturally initialized `0x0c1b2088` context and its dependent records.

### Active task context recovered

The follow-up survey adds known game input-query `0x8c0432e2` as a positive
control. Save21 observes 1,782 query hits and two hits each at actual task
driver `0x8c04bd62` and lookup `0x8c053790`. The bounded fight scenario observes
none of those entries. Passive `coverage_65_active_lookup_v1` then captures
one valid original lookup, **1/1 native matches**, with no patches or skips:
R4=0, R5=0xf2, R6=`0x0c19a2a0`, return=1, 12,006 original instructions.
Its active context is `0x0c1a5a68`, current task record `0x0c1a5ba8`.

Disassembly proves the context is execution-scoped: `0x8c04bd62` publishes
R13 through `0x0c1b2088`, publishes each current record at context +0x18c0,
then restores the prior global at `0x8c04be12`. The record stride is 0xbc,
record table starts at context +0x140, record status is +12, and its saved
continuation starts at +24. Actual `0x8c0544c8` saves SP, PR, registers and
FPU state; its counterpart restores an execution continuation. This is not
a simple semaphore read or an ordinary nested helper return.

The second bounded eight-case probe copies the observed context/header and
current record (`coverage_65_object_error_active_dev_v2`). It still rejects
all eight (seven flag-6, one flag-1): the error path exits through task-driver
restoration and reaches PC zero rather than returning to the synthetic leaf
caller. Copied record data alone does not supply the live caller continuation.
Both failed batches remain excluded; no additional bytes are counted.

Next object qualification must enter through the actual task driver and
preserve its saved stack/FPU continuation, then observe the genuine callback
and lookup paths. The recovered active lookup is a context lead, not the
64-case independent whole-caller proof required for promotion.

The motion checkpoint now has a fresh complete **1,368/1,368-binding**
regression and **39/39 native suites**, plus all **104 tool checks**, the full
percentage hash chain and remaining repository gates. The source/executable
seal is `tools/oracle/motion_frame_v1_manifest.json`. The SDK-inclusive
accounting headline is a different measure; the verified C address union
remains **259,110 bytes (59.61%)**.
