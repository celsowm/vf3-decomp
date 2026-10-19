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

## Correction: mpdrv is the Maple peripheral driver (2026-10-18, later)
- The strings "mpdrv_frame_send / mpdrv_frame_recv_pre / DriverState is not RECEIVED / SENT / DMA incompleted" and "mpdrv_set_getcond_ns,
  mpdrv_set_dreq_ns, mpdrv_make_rootdevicedata, mpdrv_set_ft4ctrl" belong to the **Maple peripheral driver** (mp = Maple Peripheral),
  not the sound driver; the earlier note above that called it "sound" is wrong. The register base stored at struct+0x10EC is 0xA05F6C00
  and `(base+0x18) & 1` is SB_MDST (DMA busy). Driver state lives at [0x0C1A0BE8]: 0 = SENT, 1 = RECEIVED.
- Emulator ground truth (`python tools/mem_watch.py 21 0x8C1A0BE8 4 --frames 1500 --writes`, new): the word toggles every frame,
  written 0 by pc 0x0C036276 (frame_send: DMA started) and 1 by pc 0x0C03632A (frame_recv_pre, after the DMA-end event).
- State 21 was saved with the word at 0 (a Maple DMA in flight). The native run had no Maple at all, so frame_send failed with
  "not RECEIVED" every frame. Added: `src/sys/maple_hle.c` (answers a transfer list: DEVINFO and GET_CONDITION for a stand-in pad
  on port A, 0xFFFFFFFF "no device" elsewhere), SB_MDSTAR/SB_MDST capture in native_tick.c, ASIC bit 0x1000 on DMA end in boot_sim,
  and `--maple-inflight 1` (raises the pending DMA-end event at start for a savestate taken mid-DMA).
- Result: with the driver unblocked (also tried with the word poked to 1: `BS_POKE=0x0c1a0be8:1`, which makes the driver start a
  real DMA: MDSTAR=0x0C2C4420, MDST=1) the game still sits in the render-wait spin at 0x0C0597CA for 100 vblanks and issues no GD
  request. So the Maple handshake was one blocker but is **not sufficient**; the gate is elsewhere in the render/scene wait.

## Still open
- Past the title screen (state 21 -> 22 differs by 475 KB of GD-loaded data 0x0CAB4000-0x0CAE9000): the gate is not Maple;
  look for the game-side GD request or timer that never fires in the model.
- Fixed 2,688-cycle poll (cycles are not counted per instruction); 7 game-state bytes of the 8,220-byte frame diff
  (0x0C2A62E4, 0x0C2A73A9/A, 0x0C31F9AD/AE/C1/C2) - attributed to interrupt ordering, not proven.
- Maple: both items now confirmed (docs/re/maple.md, last section).
- Nothing further for the savestate coverage; the 2,688-cycle poll is a calibrated constant (it reproduces the emulator GD log: 191 sectors left at the same cycle), not a counted cycle total.

## State 21: the wait object really completes (2026-10-18)
- Wait object r14 = 0x0C2A7390, request state is the halfword at +0x4C (0x0C2A73DC): 2 = busy, 1 = done (0x35A20 returns it;
  0x35510 returns 0 on 1). mem_watch over 900 emulator frames shows three cycles state 1 (pc 0x0C0348BC) -> 0 (0x0C035128)
  -> 2 (0x0C035848): the emulator finishes the request, then issues the next one. So the early native exit (wait=0, 2 iterations)
  is correct; the "emulator stays in the loader wait" reading came from the hot polling functions dominating the hit counts.
- Open question is therefore not the wait but what native does after the read function (0x0C0A7F3C family, returns r14=0 ->
  0x0C0A8024 cleanup) and whether the next request (state 2 write at 0x0C035848) is issued later than the 60-vblank cap.
  A 900-vblank native run from state 21 is the check (slow, ~15 min+).
- Result of the 900-vblank native run from state 21 (13.5 min wall): ok 1, 0 unowned, 3.0e9 cycles, GD idle (0 sectors left)
  and no new request is ever issued. So the next read is not a timing artefact; the frame loop is missing a condition that the
  emulator satisfies (next lead: diff the frame-loop task state, [0x0C16CDF0..] and the request-issuing caller of 0x0C035848).

## State 21 gate found: AICA sound RAM was not modelled (2026-10-18)
The post-wait caller (0x0C0C5C3A) loads DTPK files into sound RAM through the loader at 0x0C0406B2. Its header check
(0x0C040154) reads **AICA RAM 0xA0800088** (driver-published free size, `0x001E0000` in the emulator) and fails with -4 if the
file does not fit; native device reads returned 0, so the loader reported an error, closed the GDFS (globals 0x0C0EA2EC /
0x0C0EA314 zeroed), every later open failed, and the game never asked the GD for the next file.
- Fix: `native_tick.c` now backs 0x00800000-0x009FFFFF with a 2 MB array (`vf3_native_aica_poke`, boot_sim `--aica-word off:val`;
  boot_states and grow_boot pass `88:001e0000`).
- The upload then handshakes with the ARM7 driver through the mailbox: `[0xB4]` goes 0 -> 1 after 2223 polls, the SH-4 writes
  `[0xB0]=1`, `[0xB4]` drops to 0 after ~5947 polls, the SH-4 clears `[0xB0]` (emulator trace, tools/mem_watch.py). Modelled by poll
  count. `[0x98]` (command-taken flag the SH-4 polls) reads 0.
- Result: from state 21 native now loads on, issues the next GD request and sits in a second loader wait (GD status 1);
  states 26, 27, 28 reach the frame loop with 0 genuine unowned calls. State 29/46 grow past 0x0C0AB8A0 only to reach the
  frame loop. The second loader wait is not yet driven by the harness (it only drives the first), which is the next item.
- New debug: `VF3_TRACE_ENTRIES` now also prints `leave` lines (r0) and the AICA/GDFS globals on 0x0C035C60;
  `tools/entry_order.py` lists emulator entry order + callers from a savestate.

## EXEC_SERVER and the 300-vblank sweep (2026-10-19)
- `vf3_aica_stub_adapter.c` (replay era) answered GDROM_EXEC_SERVER (r7=2) as a no-op, so in the native boot flow queued GD
  requests were never executed: the drive stayed BUSY with 0 sectors left after the first request. With a drive model attached
  (`vf3_native_gd_attached()`) the call now reaches the model; from state 21 the game then runs request after request
  (cur sector 0x85324 at 300 vblanks) and reaches the frame loop.
- Sweep at `--cap 300` (docs/boot_states.csv): 21-26, 28-30, 42-46 reach the frame loop (the "unowned 1 @ 0x0C0597CA" in the
  table is the vblank cap ending the run inside that loop). State 30 ends at the sentinel. State 22 needed adapters grown to
  0x0C096E5C (`CAP=300 sh tools/recomp/grow_boot.sh 30 22`; grow_boot now takes CAP).
- State 27 is the open one. Native spins in a grid lookup (0x0C06911C -> 0x0C068FE4, scan runs off a table with no -1 terminator:
  r4 climbs from 0x4BFA9B6B in steps of 8). The grid pointers come from the stage file the loader callback 0x0C068C10 parses
  out of the buffer at [0x0C113A0C] = 0x0CBCE800, which holds float data, not the expected two-offset header.
  The emulator never reaches that point inside 600 frames: from state 27 it sits in a sound-RAM upload (0x0C040A54 mailbox,
  then 0x0C0400C0 command: [0x90]=dest, [0x94]=src, [0x98]=size 0x25EB0, `[0x98]` polled ~326,000 times until the ARM7 clears it).
  Native answers `[0x98]` = 0 at once, so it is hundreds of frames *ahead* of the emulator and may be running the next phase
  with data the real console would not have had yet (or the buffer is simply different). A 3000-frame emulator entry trace
  (`tools/entry_order.py 27 ...`) is the comparison.
