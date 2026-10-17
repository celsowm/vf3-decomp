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
