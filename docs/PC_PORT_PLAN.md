# VF3tb: completion and native SDL PC port plan

Initial baseline inspected: `35aba99` on upstream `master`, 2026-10-20. Integrated upstream through `78a93c3` on 2026-10-21. Counts below reflect that revision and the supplied evidence audit. Work continues directly on `main` at the user's request; the default branch has not been renamed. The user confirmed Windows x86-64 as the primary release target, with Linux x86-64 support. macOS remains a development/test target.

## Outcome and acceptance contract

Deliver a native, playable reimplementation of the supplied USA Dreamcast edition, MK-51001 V1.002, with the original rules, content, timing, inputs, visuals and audio. The player supplies the supported disc dump. SDL handles host windowing, input, presentation, timing and eventually audio output; SDL does not implement the Dreamcast renderer, sound driver or game runtime.

“100%” has two separate gates:

1. **Code coverage:** port the remaining bodies against a fixed, versioned function inventory and range-union denominator, with reproducible validation. The historical denominator covers identified bodies in `1ST_READ.BIN`; it is not the entire executable, the secondary executable, the ARM driver, all paths or the whole game.
2. **Game equivalence:** pass the end-to-end feature matrix below from cold boot without starting from a captured game state, an emulator execution fallback, unowned calls, placeholders or suppressed device writes on required paths. Coverage of code alone never closes this gate.

Identical original executable bytes are not the project's goal. Deterministic gameplay state, rules and event ordering require exact comparisons. Graphics/audio tolerances, if needed for host backends, must be measured, justified and approved before acceptance; discrepancies cannot be silently excused as “close enough.” No release is called 1:1 while material deviations remain.

## What the repository actually establishes

| Item | Evidence at baseline | Qualification |
|---|---|---|
| Ported address union | 400,098 / 434,656 bytes = 92.05%, `docs/coverage.md` | Recomputed with restored frozen inputs; ledger coverage is not gameplay fidelity |
| Remaining address union | 34,558 bytes under that denominator | Not an estimate of remaining engineering effort |
| Ported ledger | 2,239 unique entries; 2,243 ported rows | Four duplicate rows must not inflate progress |
| Golden bindings | 2,250 bindings, 2,202 marked strict | All golden descriptors restored locally; six corpora lack 5,408 RAM blobs |
| Local fixture replay | 2,202/2,202 marked-strict PASS; 2,244/2,250 total | Six missing-RAM failures; 14 unmarked passes skip 700 rows |
| Native tick | Author records 13 captured fight states with exact RAM | The supplied bundle omits all 39 tick input files; not rerun here |
| Boot experiment | 15 recorded states reach 700 vblanks | Rows also record `ok=0`, `unowned=1`, failed PC `0c0597ca`; not a clean full-boot pass |
| Native executable | `vf3` loads captured RAM/registers; `vf3boot` requires three captures; two original boot segments now match fresh full-state captures | No disc-only cold boot |
| Video | Persistent native VRAM, incremental TA parser and a software rendering subset, integrated with original emitters | Fog, sprites, VQ/mipmaps, translucency sorting and other paths remain; no complete-frame parity |
| Audio | ADPCM decode and command queue | No complete voice/DSP/mix playback engine |
| Input | Independent Maple main ports; SDL keyboard and virtual-controller samples tested through A/B guest responses | Boot harness remains neutral; complete game-loop sampling/timing remains |

`docs/re/oracle_device_reads.md` records that some synthetic probes suppress device writes and replay the recorded read tape. These fixtures validate the specified probe policy, not unmodified-device behavior. Keep their results separate from live-device acceptance.

### Fresh-reference and runtime work, 2026-10-21

An isolated official Flycast revision now builds locally and cold-starts the
supplied disc with HLE BIOS and a passive interpreter observer. This new
reference has its own source/build/capture manifests; it does not reproduce
the historical missing seals. See [the new reference](NEW_ORACLE.md).
Its null renderer is suitable for the measured CPU bootstrap transitions,
not graphics or complete-game fidelity qualification.

The native relocation `AC010000 -> AC004000` and CRT0
`0C020000 -> 0C09574E` each match all 16 MiB RAM and 64 context words, with
exact instruction counts (24,198 and 1,282,358). Dirty-BSS synthetic cases
also verify the clear operations. The intermediate bootstrap and startup
remain unimplemented; these are bounded code segments, not a coldboot
executable. See [boot boundaries](re/native_boot_entry.md).

Native invocations now commit nested hardware effects, preserve ordered TA
output, restore caller hooks, reset session/SQ state explicitly, and report
attached-device failures. This repairs the base for a persistent runtime;
it does not preserve a native C continuation after returning to the host.
See [runtime lifecycle](re/native_runtime_lifecycle.md) and
[native PVR subset](re/native_pvr.md). Historical coverage/replay totals above
are unchanged; none of these new subsystem checks adds automatic ledger credit.

The imported evidence exposed and reproduced a stack-array overrun in `src/fight/c6ec4.c` and host-dependent INVALID NaN generation. Both are corrected with focused differential and sanitizer checks. Live GD-ROM requests now precede capture-only REIOS stubs when a drive is attached. Existing warnings include a placeholder null dereference in `src/fight/task_run_c.c` and overlong strings in `src/sys/gdfs_table.h`; these still need reachability and semantic triage.

## Deliverable sequence

### M0 — Reproducible inputs and honest test gates

- Accept collaborator invitation and preserve upstream history; create `main` from the inspected upstream revision.
- Import the local ZIP with `tools/prepare_rom.py`: exact three track hashes, GDI hash, retail executable SHA-256, 412 files, identity copies of executable images, local provenance manifest. Never descramble these retail files.
- Build `vf3`, `vf3boot`, `vf3gdrom` and the SDL host diagnostics using CMake.
- Make missing inputs, invalid selections, crashes, unowned calls and capped execution distinguishable from passing tests. Register ROM-free tests in CTest and run them on Windows/Linux/macOS.
- Audit local prerequisites with `tools/port_preflight.py`; missing replay evidence is a blocker, not a passing result.

Exit: deterministic import, baseline builds, negative-path tests, and a machine-readable list of unavailable artifacts. M0 does not imply a playable game.

### M1 — Restore and qualify the reference oracle

The received archive restores the frozen inventory and most replay inputs. See [the import audit](EVIDENCE_IMPORT_AUDIT.md) and [oracle reproducibility audit](ORACLE_REPRODUCIBILITY_AUDIT.md) for exact gaps. Minimum complete handoff:

- Frozen `extract/analysis/funcs_1ST_READ.unsc.bin.csv` and `function_body_ranges.csv`, hashes, analysis-tool versions and provenance.
- Every golden file selected by `tools/golden_bindings.json`, its RAM shadows, `.ops.json` maps, device tapes and related metadata required by its runner. Include a file manifest with hashes; deduplicate shared corpora by path/hash.
- `golden_tickx_vf3_<N>.bin`, `oracle_tick_s<N>.bin` and `flycast_exit_s<N>.bin` for states 4, 5, 7, 9–16, 37 and 41, boot loop captures for states 21–30 and 42–46, `golden_bootI_vf3_30.bin`, `golden_bootS_vf3_30.bin`, and GD state dumps, with the commands used to create them. Thirty golden paths use absolute Windows locations (26 capture-drive and four user-cache paths); preserve canonical manifests and use a separate relocation map.
- Source and exact commit of the instrumented `tools/emu` oracle; upstream revision plus all local patches, build recipe, configuration, savestate format and capture recipes. A binary or unversioned working directory alone is insufficient.
- Reference-code revision/build details where `refs/dream-recomp` is needed. Clarify provenance and redistribution terms before incorporating reference implementation code.

Keep game data, RAM images and oracle snapshots local, outside Git. No message to Celso was sent by this work; this is the concrete handoff list for collaboration.

Run strict register/RAM replays, independently captured holdouts and all 13 ticks. Verify declared strict flags and explicitly report any tests not running in strict mode. Recalculate the range union using the same frozen inventory. Record failing PC, first differing register/byte, input and fixture hash for every divergence. If the inventory is regenerated, publish a new denominator and a reconciliation, not an unqualified replacement percentage.

Exit: reference results reproduce from a clean checkout plus the documented local evidence package; missing/failed tests are zero for the claimed scope.

### M2 — Persistent native runtime and cold boot

Extract reusable state ownership from `native_tick.c` / `boot_sim.c`: RAM, registers, banked FPU state, VRAM, device state, scheduling and lifecycle. Preserve snapshot runners as regression tools. Implement an explicit cold-boot path from disc with specified reset/BIOS state rather than captured fight RAM. Resolve the REIOS/GD loader state around `0x8C001006` and `0x0C2A7344` from captured evidence.

Implement and validate timers, ASIC/vblank scheduling, DMA, GD command completion, Maple polling, callbacks and shutdown. Audit SR-load register banking and interrupt effects, including the older direct `LDC Rn,SR` emitter (see `docs/re/translator_semantics_review.md`). Replace polling-count shortcuts and temporary synthetic return markers on production paths with validated service behavior. Log unknown hardware accesses and unowned calls as errors.

Wire the SDL host to the continuous loop. Capture input at the original emulated sampling boundary; host frame rate must not alter simulation. Complete two Maple ports before claiming two-player support. Keep reproducible input playback and RNG initialization available headlessly.

Exit: cold boot → title → menu → character/team selection → complete fight → result → menu, repeatedly, with no imported savestate, missing native call, OOB access or device-policy substitution.

### M3 — Native video renderer

Specify the actual PVR/TA stream and VRAM writes used by VF3tb. Implement polygon/sprite lists, vertices, texture upload/addressing, twiddling, used texture/palette/VQ formats, depth, culling, clipping, blending, punch-through/transparency ordering, render targets and display timing. Use a backend abstraction for host rendering; SDL owns presentation/windowing. A software reference renderer can make comparisons deterministic before optimized GPU paths.

Build small synthetic parser/texture tests and reference stream/frame captures from the original execution. Compare TA commands, texture contents and rendered output independently so a renderer error cannot hide a game-logic error. Preserve 640×480/4:3 reference presentation; higher-resolution modes are optional after reference parity.

Exit: title, menus, every arena, fighter, effect, HUD and replay render correctly through full sessions, with documented frame comparisons and no dropped unsupported commands.

### M4 — Native audio and synchronization

Map AICA command semantics, PCM/ADPCM voices, envelope/pitch/loop behavior, mixing, sound effects, music transitions and any DSP behavior actually used. Evaluate native reimplementation of the sound driver separately from main SH-4 coverage. Decoding an ADPCM file is not equivalent to running the sound system.

Connect the validated mixer to SDL audio with stable buffering, explicit sample rate, pause/resume/device-change handling, and a simulation-derived clock. Log underruns and compare command timing plus decoded/mixed PCM against reference captures.

Exit: voices, impacts, music, menus and transitions match the reference across the feature matrix, with no drift, missing channels or recurring underruns.

### M5 — Close code and content coverage

Rank unported entries by new bytes contributed to the range union, then by runtime reachability and dependency. Address the known helpers `0x0C0635EC` / `0x0C055578`, null dispatch/device-state cases and remaining loader clusters using new captures, CFG-complete translation and readable replacement where justified. No promotion based only on compilation or nested-body duplication.

Qualify every relevant mode/content path, not only the hot fight tick. Preserve original rules, edge cases, numerical behavior, move timing, collision results and deterministic random behavior. Save/VMU format must be validated before exposing save migration.

Exit: 100% of the frozen main-code scope has an evidence-backed disposition; every required game feature has end-to-end coverage. Any undiscovered/dynamically loaded code is a tracked expansion of scope, not omitted from completion claims.

### M6 — Fidelity qualification and release

| Required scenario group | Required evidence |
|---|---|
| Boot/title/attract/menus/options | Cold start, timed transitions, input navigation and reference frames/audio |
| Every selectable fighter and team composition | Move/throw/guard/evasion, hit and miss, special states, damage and round outcomes |
| Every arena | Collision, walls/edges, movement, cameras, stage transitions and rendering |
| Every mode listed by the original menus | Full entry-to-completion journeys, failure/retry/continue and return paths |
| Two players | Independent devices, simultaneous inputs, reconnects and mappings |
| Replay and unlocks | Deterministic recording/playback and original conditions |
| Save/load/VMU behavior | Fresh save, repeat load, settings/progress, invalid-data handling |
| Long sessions and lifecycle | Repeated matches, pause/focus changes, exit/restart, no leaks/crashes/drift |
| Windows/Linux release builds | Clean-machine install/run with user's extracted assets; Debug/Release regression parity |

Record game edition, repository commit, fixture hashes, host/compiler/backend, input sequence, expected/actual results and remaining deviations. Automated differential checks must be supplemented by actual visual/audio and gameplay review. Optimize only after correctness, then retest optimized builds. Distribute source/runtime and dependency notices, never ROM/assets/captured game RAM. Tag a playable release only after all required gates pass.

## Progress policy and work distribution

Use one commit per tested milestone directly on `main`, fetching remote history before each push. Do not force-push, rewrite upstream `master`, or report the SDL diagnostic as gameplay. Keep `master` as upstream baseline until the maintainer chooses branch consolidation.

Parallel responsibilities: runtime/devices; renderer; audio; decomp/fixtures; portability/CI and independent verification. Agree file ownership before concurrent edits. Every module change supplies a deterministic regression and an integration test at the next available boundary.

Track separate quantities: historical byte union, locally rerun strict cases, completed feature scenarios, graphics/audio comparisons, unresolved native calls and release-platform checks. A percentage for one must never stand in for another.

No credible completion date is established. Completion means all gates are
satisfied. Immediate critical path: use the newly reproducible reference to
capture startup/ticks and close native bootstrap/continuation/device gaps,
while completing video/audio and retaining the historical missing-evidence
list. The new oracle must be qualified independently before replacing any
historical reference claims.
