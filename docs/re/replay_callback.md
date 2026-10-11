# Paired replay callback (2026-10-11)

Callable `0x8c0a8e18`, frozen owner `0x8c0a8e22`, adds **238 verified
C bytes** through `src/fight/replay_callback.c`. Its ten-byte save prefix
and existing helpers earn no additional credit.

The callback checks the replay mode and pause mask, clears both actor
transients, restores two history records through the qualified reader,
and advances the ring index. Scene bit `0x800` and an odd-frame timer
hold the interpolated index; otherwise it increments and wraps after
319. Reaching the descriptor's end index sets the scene completion byte
and clears the original status flag. Continuing replay updates both
motion streams, runs the existing ordered pair/physics helpers, and
clears the four original actor/status flags. Original scratch-register
and stack results remain part of strict comparison.

Development `coverage_65_replay_callback_dev_v1` runs states 26/27 for
600 frames each: 64/64 and 57/57 invocations complete, and **109/109
valid strict cases pass**. Holdout runs states 28/29 for 600 frames each:
64/64 invocations complete per state, and **116/116 valid cases pass**.
Both campaigns independently execute every byte of the frozen owner.
Each retains nine interrupted specimens and three budget-limited
specimens, all excluded from qualification. There are no incomplete
invocations, nondeterministic retained entries or native replay skips.
Owned descriptors, side records and queues relocate by `0x100000`;
loaded actors retain their observed addresses. The unchanged native
executable and 389-file compiled source freeze precede holdout.

Eight original-only windows begin at `0x8c09617c`. The original flag
predicate selects descriptor offset 12, loads the callback at
`0x8c096182`, and invokes it at `0x8c096184` with the untouched
MOV R14,R4 delay. Short mode/pause fixtures establish ordered saves,
restores, actual return at `0x8c096188`, and zero device accesses. The
validator requires the descriptor target to equal the original
`0x0c0a8e18` installer pool at `0x0c0a86a8` and checks the untouched
load/store instructions at `0x8c0a8668`/`0x8c0a866a`. Installer bytes
are checked statically; these windows execute the dispatcher rather
than the installer. They are process-owned fixtures, not natural
playback observations. Eight mutation tests reject forged predicates,
callback pointers, pools, saves and return evidence.

The first replay report, produced before the full C entry existed,
records 0/109 supported cases and remains pinned as excluded evidence.
The full structured implementation passes all 109 development cases
without a corrective C revision. The two affected bindings, **39 native
suites** and **257 tool tests** pass. Only required native regression
executables are archived. The static dispatcher owner `0x8c096174`
has no matching matrix-family binding; its existing native walker
regression remains included among the 39 suites.

`tools/oracle/replay_callback_v1_manifest.json` seals the immutable
sources, original captures, independent comparisons, caller proof,
exclusions, affected gate and previous replay-record proof chain.
Verified C is **267,230 / 434,656 (61.48%)**; **15,297 bytes remain to
65%**. Full inventory gates at 62.5% and 65% remain required.
