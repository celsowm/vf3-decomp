# Plan: native fight slice (2026-10-15)

Goal: move from "verified recompiled-by-capture fragments" to a native build
that runs a fight tick, with readable C progressively replacing generated C.

## Phase 0 - measurement (DONE, docs/re/exec_census_findings.md)
34% of executed block entries are outside the frozen baseline; one wait loop
(`0x8c059aea`) is 44% of fight hits; the hottest uncatalogued code is the
`0x8c0487a0` FPU transform cluster.

## Phase 1/2 - whole-tick differential harness
* `tools/tick_capture.py` - emulator fork, full 16 MiB RAM + registers at the
  entry and exit of any function (VF3_FULL + `rampc`), 64 MiB per pair.
* `tests/tick_replay.c` (`vf3tick`) - run the ported dispatcher from the
  entry state and diff regs + all RAM against the exit pair.
* Scheduler: the real function is **`0x8c09616a`** (count=27 at
  `0x0c29bb84`, table `0x0c1fe864`, stride `@+8`, enable bit `@+0`, handler
  `@+12`, r4 = record). The ledger's `0x8c096174` is mid-body.
* First run (state vf3_7): scheduler executes natively; first unsupported
  call = task handler `0x0c08b7ea`.

## Scaffold - recompiled reference build (refs/dream-recomp, gitignored)
The ported dispatcher only covers ~46% of fight work, so the tick stops at
the first uncovered handler. A static recompile of the whole image
(dream-recomp, GPL, kept in refs/ only - never committed here) gives complete
code coverage and a deterministic native oracle: run the scheduler tick with
captured RAM, diff, then replace translated functions with readable C one at
a time. This is a verification scaffold, not coverage credit.

## Phase 3 - readable hot path
Rank by census weight; rewrite against the oracle; `readable` ledger column.

## Phase 4 - other scenes
Same harness, other states.

Status (2026-10-15): savestate sweep captured scheduler ticks for 13 of 46 states
(4,5,7,9-16,37,41; the rest never reach 0x8c09616a within 300 frames, so they are not
fight ticks - other scenes need a different entry). All 13 run 100% native in the
verification harness (0 stubs, 0 mismatches, oracle and poison scratch modes).

Standalone native tick: `build/vf3 <golden_tickx_vf3_N.bin> --expect oracle_tick_sN.bin
--hw flycast_exit_sN.bin [--ta-out f]` (src/main.c, src/fight/native_tick.c) runs the
tick with no oracle, no devlog and a baked call-target table
(src/fight/call_targets.c, `tools/recomp/gen_call_targets.py`). `tools/recomp/run_native.sh
4 5 7 9 10 11 12 13 14 15 16 37 41`: all complete, 0 RAM bytes differ from the oracle
apart from 3-10 bytes per state where the oracle's denormal handling is wrong and native
equals hardware. Against the emulator's exit RAM ~450 bytes differ per state
(interrupt-driven counters, stack residue), expected and not tick logic.
Limits: one scheduler tick per run (no main loop, no scene changes); ~94.4% of state-7
oracle self steps are readable ports (106 entries as of 2026-10-16, incl. the 0x8c048260 display-list walker and the 0x8c0568a0 triangle-strip builder: sin/cos, push_offset, div_s32/u32, the
matrix stack push/pop/concat family and frame wrappers, the vertex/strip/clip chain), the
rest generated adapters; call-target table covers only entries seen in the 13 captured
ticks. Harness lessons: `TICK_SCRATCH_ONLY` takes ONE entry (a comma list silently keeps only the first);
wrapper/trampoline entries whose outputs are leftovers of nested real code (0x8c03ecb0, 0x8c0a7662)
cannot be pinned by the poison audit - the FR/XF bank swaps in push/pop carry values the next
reader still depends on - so those stay generated; `fmov` with SZ=1 writes XD pairs (0x8c03cc60 changes XF12..15).
Phase 4 items that need new captures (other scenes, multi-tick, wider call-target table) are blocked on
savestates beyond the 13 fight ticks. Next ports by census: 0x8c06f450, 0x8c070008, 0x8c071694, 0x8c073aac,
0x8c0c1fba.

## Multi-tick probe (2026-10-16)
`build2/vf3.exe <golden_tickx_vf3_N.bin> --ticks N` runs the scheduler tick N times back to back on the RAM
the previous tick left, from the same entry registers (no interrupts, no main-loop code between ticks, no
reference to compare against). It shows how far the captured coverage carries on its own:
- 3 chained ticks complete on all 13 states with 0 unowned calls and 0 out-of-bounds accesses.
- 120 chained ticks fail once game timers run into code the captures never executed: state 7 at tick 114
  (unowned entry 0x0c0786d4), state 14 at tick 38 (0x0c0786d4), state 41 at tick 49 (0x0c0af072).
- So the wider call-target table is not just a table: the generated adapters also exist only for entries
  the oracle saw. Widening needs either new captures that reach those paths (round end / state changes) or a
  static adapter generator. The two failing entries are not standalone functions: 0x0c0786d4 is a table of
`bra` stubs (a jump-table dispatch into 0x0c078dd0 ... 0x0c079488) and 0x0c0af072 is one opcode handler of a
byte-code interpreter that loops back to 0x0c0ae29c. They need the interpreter's dispatch modelled as a whole,
not a hand port of a single entry.
The interpreter (loop head 0x0c0ae29c, handler table at 0x0c10f2e8) dispatches through at least 80 word
entries into roughly 16 KB of handlers (0x0c0ab8a0 ... 0x0c0af728). Only the handlers the captured ticks
ran have adapters or an oracle reference; porting the rest would be an unverifiable bulk job.

### Oracle-chained captures (2026-10-16)
Waiting for new savestates is not the only way to reach later game state: the statically recompiled oracle
can run a tick from any RAM image, so `tools/recomp/chain_ticks.py <state> <K> [--label NAME]` feeds each
tick's oracle exit RAM into the next (same no-interrupt model as `vf3 --ticks`; ~0.6 s per tick) and records
tick K in full under the label (golden_tickx_vf3_NAME.bin, fxr_tick_sNAME.bin, oracle_tick_sNAME.bin, ...), so
`run_state.sh NAME` and the tickmix harness work on it. `tools/recomp/chain_capture.py` builds a single next
capture. Notes from state 7 (label c7_114, 114 chained ticks):
- tick 3: native vs oracle is clean except 8 one-ulp stores in clip_edge/display_list (no hardware RAM to tell
  the oracle's denormal quirk apart); poison RAM diffs are expected without a TICK_HW_RAM image.
- tick 114: the oracle's tick calls only 3 entries the 13 captured ticks never did (0x0c078170, 0x0c08c990,
  0x0c0cc2d6), but the native run diverges inside the generated adapter of the command parser 0x0c0782e4
  (2 calls, 8,761 steps, 0x884-byte frame, jump-table stubs at 0x0c0786d4): it dispatches into the stubs where
  the oracle does not. That is the next verifiable target; fxr_tick_sc7_114.bin is the reference for it.

Widening by regen (2026-10-16): feeding the executed PCs of a chained tick (`tick_s<label>_pcs.txt`, now written by
chain_ticks.py) to `regen_tickgap.sh` together with every `tick_s*_pcs.txt` extends the gap adapters. `vf3 --ticks`
now reaches tick 202 for state 7 (was 114), 131 for state 14 (was 38) and 53 for state 41 (was 38; chained c41_49
already included). The tick-202 wall of state 7 is not a port bug: the oracle itself faults there ("unimplemented
instruction 0xffff" at 0x0c03a140, executing data), so no-interrupt chaining runs out of valid state around tick 201.
State 14's tick 131 ends on the same kind of garbage address (1c8efd1f); state 41's next wall is the unowned entry
0x0c07887c.

Chaining limit reached (2026-10-16): state 41 stops at tick 121 for the same reason as state 7 at 202 - the oracle
itself faults there (0x0000 executed at 0x0c03b87c), since nothing in a no-interrupt tick loop services the timers
and queues the main loop would. Native `vf3 --ticks` now runs every chained tick the oracle can run: state 7 to 201,
state 41 to 120 (was 38), state 14 to ~130. Reaching further needs the main-loop/interrupt layer, not more adapters.

State 14 re-checked: the oracle also produces no completed tick 131 (no PC dump), so its wall at 131 is the same
oracle fault as states 7 and 41, not a native gap. All three chain walls are therefore oracle-side.

Remaining census after poly_clip_walk (107 entries, 95.3%): the biggest unported entries by self steps in state 7 are
the trampolines 0x0c03ecb0 / 0x0c0a7662 (poison-audit-unpinnable), the GBR + ftrv routines 0x0c055646 and 0x0c0cab30
(~0.3% each, 0x0c0cab30 has a 60-byte frame and ~100 insns), and 0x0c09e060 / 0x0c09e6b2: a ~1.2 KB matrix/angle
builder with a 0x128-byte frame, 20+ guest calls and long FR sequences (~0.26% each). None is blocked by a harness
limit; each is a multi-hour faithful transcription for under 0.4% of the tick.

Update: 0x0c09e060 (aim_frame.c) and 0x0c09e6b2 (aim_frame_b.c) are now readable ports, both clean on the first
verify; 109 entries, 95.8% of state-7 oracle steps. What is left by weight is the trampolines 0x0c03ecb0 /
0x0c0a7662, the ftrv culling walk 0x0c04a1a0, the GBR routines 0x0c055646 / 0x0c0cab30 and four 1-2 KB game-logic
functions (0x0c0b1550, 0x0c0c6770, 0x0c0927e6, 0x0c0a045c), each between 0.15% and 0.2% of the tick.

Why the chains stop (2026-10-17): the oracle does not fault on a native-side gap; it faults after a *scene transition* has
overwritten program text. `chain_ticks.py --code-check` (env CHAIN_TEXT_BASE / CHAIN_TEXT_LEN / CHAIN_MIN_RUN narrow
it to a window) shows the program text of state 41 changing during tick 120 (0x0c03b800, 0x0c03c4a0.. now hold other
code) and the oracle then executing garbage in that same tick, so "tick 121" never existed: a fight left to run
without input ends after ~120 ticks (state 7: ~200) and the game starts loading the next scene's overlay from the
disc, which the no-interrupt, no-GDFS model cannot serve. The ticks up to the wall are all real fight ticks and native
runs them. Past it needs the file-loader/GDFS side (docs/re/reios_exec_server.md has the REIOS HLE state) - that is the
"other scenes" half of Phase 4, not more fight adapters. `tools/recomp/frame_delta.py` lists the words the real machine
moves per frame beyond the recompiled tick (13 states): a handful of small counters (+1/+2 per frame) at 0x0c0ea2f8,
0x0c0ea710.., 0x0c16cdf0, 0x0c19e998.., 0x0c19fc40.., 0x0c1a0be8.., 0x0c1a5b9c.. plus scratch data; that is the
interrupt/main-loop contribution a driver would have to add between ticks.

CORRECTION (2026-10-17, same day): the wall is not a scene transition. Bisecting state 41 tick 120 found two writers:
(1) a texture-upload store-queue burst (`mov.l r13,@(60,r4)` at 0x0c03fad2 then `pref @r4`, r4 = 0xE10303C0) that the
oracle sends to RAM because the captured QACR (0x0c) predates the game's own retarget to 0x10; (2) the display-list ring
cursors at [0x0c16ca44] / [0x0c16ca48] (0xACC085C0 / 0xACC641C0 at the first tick) that the main loop rewinds every
frame - chained ticks have no main loop, so after ~119 ticks the cursor reaches 0x0c03c4a0 and the emitter
(0x8C048C06 `mov.l r2,@r6`) overwrites program text. Fix = model the between-tick state:
`TICK_QACR0=0x10` (new oracle switch, also read by src/fight/matrix_family.c's SQ model) and
`CHAIN_RESET=0x0c16ca44:8` (chain_ticks.py puts those words back to their tick-1 values every tick).
`TICK_QACR0=0x10 CHAIN_RESET=0x0c16ca44:8 python tools/recomp/chain_ticks.py 41 135 --label q41_135` now completes;
run_state with the same TICK_QACR0 gives native 100.0% of 1,536,545 steps, 0 arg mismatches, 13 output mismatches that are
all the known one-ulp / -0 stores in clip_edge+display_list. The ~120/200-tick limits of states 41/7/14 therefore lift
(re-check each with the two env vars); the oracle patch (refs/dream-recomp/games/vf3tb/tick_oracle.cpp: TICK_QACR0/1,
LASTSTEP print at TICK_STEPS) is local to the gitignored GPL clone.

Remaining-entry assessment (2026-10-17): 0x0c04a1a0 (the ftrv culling walk) is not a leaf port. It reads XMTRX, runs a
data-dependent loop with `trapa #48/#49` exits, store-queue bursts and a nested `bsr 0x8c04a320` (a second ftrv/fschg
routine of its own); the harness has no trapa model, so a faithful port needs that model first. The other ten entries are
each <=0.3% of a tick (two are poison-unpinnable trampolines, two use GBR, four are 1-2 KB game logic). With the 41/7/14
chains now reaching 135/260/200 ticks at 100.0% native steps, the next value is in new scenes (Phase 4, needs the GDFS/REIOS
loader state), not in these entries.

## Phase 4 first result: scene frame function 0x8C09144E (2026-10-17)
The "other scenes" blocker was only that the fight scheduler 0x8C09616A is not their entry. `tools/scene_survey.py <state>`
logs call edges (`VF3_EDGES`, needs `VF3_FULL=1`) for 120 frames and names the function holding the most shallowest-depth
calls plus its rts. Of the 29 non-fight states, 1/2/3/6 run 0x8C09144E (766 bytes, rts at 0x8C0917E6; a loop that calls the
matrix/strip helpers 40 times per run) and 8 is parked inside the 0x8C0488EA strip helper family (not an entry - the survey
heuristic only names real frame functions when the state is saved between helpers). States 20-35 sit in boot/idle code
(0x8C035518, 0x8C034864) with no per-frame call tree inside the window.

Capture + verify (no new ports were needed):
`python tools/tick_capture.py 0x8c09144e --state tools/emu/flycast-build/data/vf3_N.state --frames 300 --pairs 1 --name p4scene --exitpc 0x8c0917e6`
(no `--exitsp`; the rts is the transfer pc) then `tools/recomp/run_scene.sh 0x8c09144e extract/analysis/golden_p4scene_vf3_N.bin p4_N`.

| state | oracle steps | readable calls | stubs | arg/out mismatches | native |
|---|---|---|---|---|---|
| 1 | 8,405 | 554 | 0 | 0 | 100.0% |
| 2 | 8,405 | 554 | 0 | 0 | 100.0% |
| 3 | 80,507 | 2,327 | 0 | 0 | 100.0% |
| 6 | 44,139 | 1,391 | 0 | 0 | 100.0% |

Both scratch modes (oracle, poison) agree; states 3 and 6 show 1 RAM byte of oracle-quirk difference (23 accepted
oracle-quirk stores), the same class as the fight states. Remaining Phase 4 work: scenes whose savestates sit inside
helpers (8, 20-35) need states captured between frames, and a standalone `vf3` runner for this entry (native_tick.c is
wired to 0x8C09616A only).

Standalone: `build/vf3 <golden_p4scene_vf3_N.bin> --entry 0x8c09144e --expect oracle_p4_N.bin --hw flycast_exit_p4_N.bin`
(new `--entry` option; `gen_call_targets.py` now also reads `fxr_p4_*.bin`, 421 targets) runs states 1/3/6 with 0 unowned
calls and 0 RAM bytes different from the oracle; the 13 fight states still all pass `run_native.sh`.

States 20-35 with a 1500-frame edge window (state 21 checked, 917k edges): the whole window is one call chain entered once
from 0x8C03552C into 0x8C035CBA (depth 1, never returns), the boot/loader polling path - not a per-frame scene function. Entry-pair
capture does not apply there; those states need the GDFS/REIOS command-stat model (docs/re/reios_exec_server.md) because
the chain is waiting on the disc. State 2's standalone RAM also matches the oracle (0 bytes).
