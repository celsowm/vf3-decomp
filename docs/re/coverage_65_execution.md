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

## Resource task driver continuation (2026-10-10)

After fast-forwarding the merged signature-name PR, added readable C for
the actual resource driver `0x8c04bd62` and original tail-call wrapper
`0x8c053d7c`. Two natural resumes, 16 pilots, 128 development cases and
128 freshly captured acceptance cases match the final frozen native C.
The real wrapper also exposed FPSCR bank switching missing from the prior
adapter: its bank-one cases fail the old native image and pass the new C.

This work resolves the driver entry and ordinary-return model, but does not
yet qualify the object-family caller. The frozen driver owner is 138/142
bytes observed: `0x8c04bdee` / `0x8c04bdf0` remain missing. No percentage
milestone is emitted and the verified union stays 259,110 bytes. See
`docs/re/task_driver.md` and the advisory `task_driver_v1_manifest.json`.

The final driver also passes constructed object first-yield development and
fresh holdout (2/2 each), preserving the original object BSR, file lookup
and both SDK context helpers. Native host continuation scopes unwind calls
made obsolete by the original guest-stack restore. This is preparation for
whole-caller qualification, with zero additional bytes claimed. The next
recorder version must honor an explicit driver-return boundary instead of
ending early at a resumed job RTS; then collect complete second ticks and
observe the actual object negative-return branch. Failed or interrupted
pilots stay excluded from the advisory proof.

Final frozen-driver validation passes **1,368/1,368 bindings**, **39 native
suites**, and **104 tool tests**. The existing completed percentage hash-chain
audit is reused because the accepted union is unchanged. The gap to 65% is
23,417 bytes; these continuation and capture fixes add zero credited bytes.


## Complete job boundary and next percentage candidate (2026-10-10)

The new explicit-return recorder captures complete second ticks rather than
stopping at a resumed helper's RTS. Readable C follows job return continuations
through real retirement and cleanup. Two original second ticks, two unsigned
counter-wrap development cases, four fresh relocated resumed-job acceptance
cases and two relocated wrap acceptance cases match frozen version 9 exactly.
Two interrupted wrap holdouts remain excluded. The default observer control
matches the previous partial capsule exactly; budget rejection still works.
See [complete job evidence](task_driver.md).

This closes the completion contract but adds zero verified bytes: object
startup and the whole caller prefix remain unqualified, and the driver's
ordinary restore-return path remains unobserved. Do not repeat another object
sweep without a new startup/caller hypothesis. The next bounded percentage
candidate is the actual controller merge at `0x0c09af6c`, frozen owner
`0x8c09af72` (78 bytes), within the previously ranked 1,302-byte family.

Eight original-only pilots across saves 21/26 vary the real selector bits at
`0x0c29bccc` and two actual packet bit fields. They preserve the literal-loaded
`0x0c0a1282` lookup and exercise all three merge choices (first packet, second
packet, OR). All eight match the existing native adapter with zero skips and
cover the 78-byte frozen owner. This is a concrete next candidate, not a
promotion: implement readable full C, freeze it, capture at least 64 distinct
development and acceptance inputs with changed/relocated writable stack,
qualify the actual caller entry/prefix/return, and audit marginal union before
credit. Pilot proof is pinned in `task_completion_v1_manifest.json`.


The follow-up original controller development set passes **64/64** against
the current adapter, with all 78 frozen bytes exercised and no rejected raw
specimens. Thirty-two variants on each of saves 21/26 change selector/packet
bits, the writable stack and preserved-register sentinels. This set is
preparation, not readable-C acceptance; its recipe and original/native hashes
are also pinned in the completion seal. The nearby `0x0c09b924` caller tails
into `0x0c09b978`, so it must not be treated as a simple ordinary-return wrapper.


An isolated readable controller implementation in the evidence cache also
matches those 64 original cases. It is deliberately a diagnostic build while
the frozen version-9 repository gate runs. Integrating it into the normal
CMake build, freezing all dependencies, qualifying the two genuine BSR sites
(`0x0c09b92a` and `0x0c09b988`) and recording fresh independent acceptance
remain necessary before awarding the 78 bytes. The completion seal pins this
candidate separately and grants it no credit.


Eight fresh original BSR observations validate both sites, their NOP delay
slots, the ordered R14/R13/R12/PR saves and the complete callee return. These
observations start at each actual BSR and stop at the callee's RTS/delay slot;
they do not claim full execution of either parent. The dedicated controller
attribution validator rejects changed targets/delays, missing or reordered
saves/restores, register/SP/return corruption and modified literal pools.
Six mutation tests bring the tool suite to **110 passing checks**. Normal
repository integration and independent acceptance are still pending for this
candidate; current credited coverage remains unchanged.


A standard rollback-probe development batch now records **128 distinct
complete controller cases** across saves 21/26. Both original runs complete
180 frames, with no rejected specimens or incomplete calls. The isolated C
matches 128/128 cases and the caller validator accepts the full frozen body
and three-register prefix. This corpus can use the existing promotion gates
without calling a one-shot stop a completed game frame. It remains uncredited
until normal C integration, source freeze and fresh independent acceptance.
