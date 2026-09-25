# M39 — fight-logic top-half catalog (2026-09-24)

Consolidates the decoded fight-side task/VM knowledge for the M39+
increments (port-in-place, verified per stage against trace windows).

## Dispatch plane (verified, M25/M28/M34)
- Per-frame step `f_8c034864` (spawner side `f_8c0349aa`): manager/singleton
  pool root `*0x8C0EA2EC`, chain head `+0x28`, per-node payload `+0x3C`,
  result codes {0/1,4/5/6,7,default} with offset-exact side effects.
- Manager thunk family `f_8c035BF2..` = singleton `*0x8C0CC9E8`-style ->
  vt slot tail calls (slot 52/4 = alloc path).

## Scene plane (verified, M29/M35)
- Walker `f_8c0b1a54`: switch keys {1,5,9,14,17} -> per-scene handler
  arg word; the frame "6-slot ladder" = struct-offset words into the
  r13 task state (frame.c constants reinterpreted on true image: 0x0C0E,
  0x76AC, 0x76B8, 0x76C4 = offsets).
- Fight == scene-0x0A at task-VM predicate (`docs/fight_dispatch_chain.md`).
- Runner `f_8c0796f4`: dynamic-entry, boot-trace-absent (first 1200f);
  to be window-traced from a fight-live state (vf3_7) — honest gate.

## Motion plane (verified, M24/M33)
- 63-channel MT evaluator `f_8c09d690` ported (`mt_play.c`), phase
  1/256 units, z-negate post-pass, `task+0x1A00` cycle.
- MT pack residency = per-record scatter (M33 falsified uniform +0x27B0);
  loader fn to pin via trace watch on dst window.

## Sound plane (M26/M37)
- libsnd 0.82 mpdrv_* endpoints named (dreset = kit write boundary commit).

## Increment order for the remaining port
1. Fight-window trace (resume vf3_7, watch f_8c0796f4) → runner body port.
2. Per-fight task handlers table (walker word set) → `fight/task_run_c.c`
   refresh on true offsets.
3. Input sampling + hit/anim cue tables (from task getters in M34).
