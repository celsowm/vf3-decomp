# The reference's clean boot: what the disc really does (2026-10-27)

The port's disc boot stops at the SDK scheduler's wait (see
`docs/re/boot_stall_wait_flag.md`).  Before modelling a GD-ROM register
interface to fix it, the reference emulator was run on the same disc to see
what the hardware actually does during the boot.  The answer changes the
plan: **the reference does not touch the GD-ROM during the boot at all.**

## Running the reference from the disc

Flycast lives in `tools/emu/flycast-ref-build/` (the source in
`tools/emu/flycast/`).  It runs the disc through its GDI descriptor:

```
tools\emu\flycast-ref-build\flycast.exe -config log:Verbosity=5 E:\vf3-decomp\rom\vf3.gdi
```

**The savestate trap.**  Flycast loads a per-ROM savestate automatically
(`core/nullDC.cpp:360`, "Loaded state ver 854 from ...\data\vf3.state"), so a
run that looks like a boot is in fact a resume from the middle of the game -
and `-config Dreamcast:AutoLoadState=0` does *not* stop it.  To see a clean
boot the state has to be moved out of the way:

```
Move-Item tools\emu\flycast-ref-build\data\vf3.state tools\emu\flycast-ref-build\data\vf3.state.off
```

The log file (`flycast.log`) is appended across runs, so the clean-boot
segment has to be cut at the last `GDI: 3 tracks` line.

## What the clean boot does

The clean-boot segment (the first 60 s) is dominated by these:

| count | message | what it is |
|---|---|---|
| 363,668 | `read SB_FFST.0 == 0` | a busy-wait on the SH-4/SB FIFO status |
| 238,920 | `read SB_ISTNRM.0 == 30` | a busy-wait on the interrupt mask |
| 103,424 | `write CCN_QACR0 = 10` / `CCN_QACR1 = 10` | the first VRAM clear through the store queue |
| 100,410 | `write CCN_QACR0 = 0xc` / `CCN_QACR1 = 0xc` | the second VRAM pass |
| 4,453 | `write DMAC_CHCR2 = 0x12c0` | the C2 (PVR2) DMA, `SB_C2DLEN = 0x40` |
| 3,982 | `read SPG_VBLANK.0` | the render loop: the game is drawing frames |
| 4,004 | `write SB_ISTNRM.0 = 8` | the vblank interrupt mask |

Two things follow from this:

1. **The game reaches its render loop during the boot.**  It reads
   `SPG_VBLANK` thousands of times and takes the vblank interrupt, so the
   boot is not stuck: the game is running and drawing.
2. **The boot never reads the disc.**  There is not a single `[GDROM]` line
   in the clean-boot segment - no sector read, no ATA command, no BIOS
   `REQ_CMD`.  (The `[REIOS]: GDROM: HLE GET_CMD_STAT` lines that *do* appear
   in the log belong to the earlier runs that resumed from `vf3.state`, where
   the game was already running and re-reading its files.)

That kills the plan of modelling the GD-ROM's ATA register interface for the
sake of the boot: the game's own loader does not use it, and the file ladder
of `docs/re/boot_gd_ladder.md` is read later (or by a different code path
than the one the boot takes).

## How the port compares

| | reference | port |
|---|---|---|
| Maple card check | passes | passes |
| VRAM clear | two passes (QACR 0x10, then 0x0c) | one pass (2,104,928 words to 0x05000000-0x05807FC0) |
| PVR2 DMA | `DMAC_CHCR2`, `SB_C2DLEN = 0x40` | 297 writes to 0x005F6800/04/08 |
| render loop | `SPG_VBLANK` + vblank interrupts | TA words per frame, but the frame is black |
| where it stops | the render loop | the SDK scheduler's wait on the flag at 0x0C16CDF4 |

The port's boot reaches the game and draws (128 TA words, 8 lists, 8
primitives at frame 20), but the drawn frame is entirely black and the
`SPG_VBLANK` equivalent never advances, so the game ends up in the SDK
scheduler's wait.

The two remaining gaps are therefore *not* the disc:

* the port's rendered frame is black (the VRAM is still empty at the
  texture address the TA samples), and
* the flag the scheduler waits for is never set, which keeps the game in the
  scheduler instead of the render loop.

`docs/re/boot_stall_wait_flag.md` names the flag, its deadline and the three
places that can set it.
