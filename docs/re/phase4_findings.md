# Phase 4 findings - native run over the boot savestates (2026-10-18)

Runner: `build/vf3boot` (src/boot_sim.c) on the native tick (src/fight/native_tick.c). Table: `docs/boot_states.csv`
(`python tools/boot_states.py --states ... --cap N`). Detail log: docs/re/reios_exec_server.md.

## What is established
- States 20-46 are **independent emulator savestates**, not one run. The loader-wait states are 21-30 and 42-46
  (wait function 0x8C035510, loop 0x8C035524/30). All 15 run natively past the wait with **0 unowned calls**; state 42 runs
  1200 vblanks ok (after seeding 0x0C0433BC / 0x0C04312C).
- The "render loop" (0x0C0597CA, empty idle callback) is the game's **frame loop**, not a stall: [0x0C16CDF0] cycles and
  [0x0C16CDF4] toggles 1/0 per frame. The run stops there only at the vblank cap. States 21, 25, 26, 28, 45 sit in it.
- Stalls at 0x0C0559B4 (26, 27, 28, 45) were a runner bug: a callee returning into a frame the hop never entered ends with
  ok 0, failed pc 0, 0 unowned. boot_sim now resumes at that return address.
- Event model that makes the frame loop run: vblank handler pair inside time slices (in-place budget hook, no unwinding),
  DMAC ch2 end -> ASIC ISTNRM 0x80000 (starts the next queued DMA), TA list-end bits (0x80/0x100/0x200/0x400/0x200000),
  EoR-TSP 0x4 on STARTRENDER. Render-end events are heuristic (ISP/video EoR not modelled).
- GD syscalls modelled: REQ_CMD, GET_CMD_STAT, EXEC_SERVER, INIT_SYSTEM, GET_DRV_STAT, G1_DMA_END, REQ_DMA_TRANS,
  CHECK_DMA_TRANS, READ_ABORT, RESET, CHANGE_DATA_TYPE, REQ/CHECK_PIO_TRANS (src/sys/bios_syscall.c). ROM-font stubs
  0x0C04A5C0/D4/E8 answer in native_tick.c.
- Pad input is **not** what gates state 21: VF3_DEVLOG over 30 vblanks shows no access to 0x5F6C00-0x5F6CFF (Maple). Reads
  are SPG_STATUS 5F8138, TMU 1FD8000C, ASIC 5F6900/08, DMAC ch2. See docs/re/maple.md for the Maple research.
- Regression guard: `sh tools/recomp/run_native.sh 7 13` must print "ram 0 bytes differ" twice (done after every change).

## Other savestates
- 31-36, 38, 39 share one GD snapshot (idle, request 0x8A done) and start at pc 0x0C03FA52 (not a loader wait; a store-queue
  copy routine). State 20 starts at the BIOS 0x8C00909A. 37, 40, 41 are fight states and already pass `run_native.sh`
  (0 unowned, ram 0 bytes differ). The others have no 0x8C09616A tick in the 300-frame capture window.
- `vf3boot --free 1 --loop-entry <pc>` (python tools/boot_states.py --free 0x0c03fa52 --capture) runs a capture from its pc with no
  wait-loop machinery. The state-31 "jump to pc 1" is the **task exit marker**: the routine was entered with pr = 1 saved in
  its frame, so returning to 1 means the task finished. boot_sim stops cleanly there.
  A task whose bottom frame holds a marker or data (1, 0, a table address, a float) has finished: when a hop resumes outside the
  image (0C010000-0C130000) boot_sim reports "task left the code" and counts the run ok.
  Results (docs/boot_states.csv, entry = the savestate pc): 31, 33, 34, 35, 36, 38 (pc 0x0C03FA52), 32 (0x0C0361F4) and 39
  (0x0C0AA0F2) all run to the end of their task with 0 unowned calls. State 20 sits in the BIOS ROM (0x8C00909A), which is not in the
  image, so it is out of scope for the native port (a BIOS HLE boundary, not a gap in the game code).

## Title-screen gate: what was ruled out (state 21, 2026-10-18)
- State 21 is a loader wait with a read in flight (gd_state: request 0x11, 31 sectors left). The model finishes the read in about 6 drive
  steps, the wait returns, and the game then runs its frame loop; the emulator reaches state 22 (requests 0x12, 0x13 done) from there
  with no input, so the next GD request is issued by game logic, not by the pad. The native frame loop never issues it.
- The "PORT"/"FUNC" driver struct at [0x0C1A0D24] -> 0x0C19FC30 with base 0xA05F6C00 at +0x10EC belongs to `mpdrv_` (the sound driver:
  strings "mpdrv_frame_send", "DriverState is not 'RECEIVED'", "DMA incompleted."), not to a Maple driver. 0xA05F6C00 is only a
  register base there; the game has no literal for SB_MDSTAR/MDEN/MDST in the image, and a 30-vblank run touches no 0x5F6C00-FF.
- Functions entered once per frame in the native loop (60-vblank run): 0x0C036132 (mpdrv_frame_send), 0x0C03B620, 0x0C03BD80,
  0x0C043964, 0x0C043BB4, 0x0C045F5E, 0x0C0460A4, 0x0C0A2E06. The sound-driver handshake with the ARM7 (DriverState RECEIVED) is the
  first candidate for what the loading sequence waits on; the AICA/ARM7 side is not modelled in vf3boot.
- Next step: compare [mpdrv driver state] in the native run against the emulator state 22 and trace which per-frame function
  would raise the next GD request (docs/re/sound_bgm.md covers the BGM voice-kit side).

## Still open
- Past the title screen (state 21 -> 22 differs by 475 KB of GD-loaded data 0x0CAB4000-0x0CAE9000): the gate is not Maple;
  look for the game-side GD request or timer that never fires in the model.
- Fixed 2,688-cycle poll (cycles are not counted per instruction); 7 game-state bytes of the 8,220-byte frame diff
  (0x0C2A62E4, 0x0C2A73A9/A, 0x0C31F9AD/AE/C1/C2) - attributed to interrupt ordering, not proven.
- Maple: both items now confirmed (docs/re/maple.md, last section).
- Nothing further for the savestate coverage; the 2,688-cycle poll is a calibrated constant (it reproduces the emulator GD log: 191 sectors left at the same cycle), not a counted cycle total.
