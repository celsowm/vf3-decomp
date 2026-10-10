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
with two OOB and one scheduler-rejected specimen retained. Native replay
correctly fails at the unsupported full entry. Implement the readable caller
before claiming any bytes; this pilot earns zero credit.
