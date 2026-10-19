# Boot frame clock: TMU channel 0 (2026-10-19)

The title/render loop does not advance on vblanks alone. It samples the SH-4
timer unit's channel-0 counter (`TCNT0`, `0xFFD8000C`) and stores frame
deltas. The native device model returned 0 for every unmodelled register, so
those deltas were always 0: any wait measured in counter ticks never expired.

## Emulator evidence

`python tools/mem_watch.py 22 0xFFD8000C 4 --frames 900` shows the reads:

| pc | role | value |
|---|---|---|
| `0x0C059B48` | frame loop (near `0x0C0597CA`) | raw TCNT0 |
| `0x0C063C40` | vblank handler A | raw TCNT0 |
| `0x0C06402C` | ASIC handler | raw TCNT0 |
| `0x0C064292` | ASIC handler | raw TCNT0 |

TCNT0 **counts down** by 13,032-13,034 per frame (1/60 s). The frame is
3,336,670 cycles, and 3,336,670 / 13,033 = 256, so the counter is the CPU
clock divided by 256.

## Game code

- `0x8C039C10` starts all three TMU channels: TSTR = 0, TOCR = 1, then for
  each channel `TCNT = TCOR = 0xFFFFFFFF`, `TCR = 2`, and finally TSTR = 1.
  This is a free-running 32-bit microsecond-ish clock.
- `0x8C064028` reads TCNT0 and computes `old - new`:
  `r2 = TCNT0; r1 = [r7+72]; r1 -= r2; [r7+76] = r1`.
- `0x8C063C40` stores the vblank sample at `0x0C1981C8`; the frame loop
  stores its sample at `0x0C1981D0` (`0x0C198188 + 0x48`). The delta lands
  next to it at `0x0C1981D4`.

The values captured in states 21-30 are consistent with the same counter
(`0xFFFF4E1D` in state 21, `0xFFF19563` in 23/30, down to `0xFE5E49DA` in 29).

## Native model

`src/fight/native_tick.c`:

- `vf3_native_enable_tmu()` turns the model on; it is **off** for the fight
  ticks, which never read the register and are verified RAM-exact.
- `vf3_native_tmu_advance(cycles)` adds guest cycles; a TCNT0 read returns
  `0xFFFFFFFF - cycles / 256`, matching the observed rate.
- `vf3_native_tmu_set(tcnt)` seeds the accumulator from the value the
  savestate last sampled, so the first delta is one frame instead of a huge
  wrapped value.

`src/boot_sim.c` enables it with `VF3_TMU=1` on a `--cycle-frames` run
(opt-in, so the existing boot sweep and its 15/15 table are unchanged),
advances it per BIOS poll and per 20,000-step slice (the same places the
drive and frame clocks move), and seeds it from `0x0C1981C8` in the loaded
snapshot.

## Why it matters

`0x8C064030` stores `old - new` as the elapsed time. With a constant 0 the
difference wraps, and code that waits for a time budget either expires at
once or never. The GD ladder (`boot_gd_ladder.md`) stops right before
`CP_LOGO.BIN`; the emulator reaches that read only after roughly 900-1500
frames of display time, which is exactly the kind of wait this clock drives.

## Verification status

- Fight regression stays `ram 0 bytes differ` with the clock off (states 7
  and 13 re-run on the new build).
- Parity: the 300-vblank state-21 run with the clock enabled issues the same
  seven reads, reaches the frame loop and leaves the drive idle at
  `0x6c1d4`, exactly like the pre-clock run.
- Control: the **old** build (TCNT0 = 0) runs 1500 vblanks and never leaves
  the frame loop (`GD cur 0x6c1d4`, no `CP_LOGO.BIN`). So the wait is not a
  plain vblank count; it needs the sampled counter to advance.
- Long run: with the clock enabled, the 1600-vblank run **leaves** the frame
  loop during the continuation and returns from the boot task
  (`0x0C0429FE -> 0xDEAD0000`, ok, 0 unowned) at the 1600-vblank cap. The old
  build stays in the frame loop for 1500 vblanks and never leaves it. So the
  clock is what releases the timed wait.
- Open: the long run still does not issue `CP_LOGO.BIN` (request id `0x19`)
  before the task returns; the drive stays idle at `0x6c1d4`. The emulator
  issues that read between frames 900 and 1200. Next step: either the
  scheduler has to continue after the task return (the harness stops at the
  sentinel), or the logo load is waiting on another event. See
  `docs/re/phase4_findings.md`.
