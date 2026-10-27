# P7: booting from the disc image (2026-10-27)

`python tools/make_boot_state.py extract/exe/1ST_READ.unsc.bin boot.state` builds a
machine state with the image at 0x8C010000 and the copy the first stub performs
(0x0C010100..0x0C014000 -> 0x0C004000).  `build/vf3sdl --state boot.state --entry
0x8c004000 --gdi rom/vf3.gdi --frames N --headless` then runs the game from its own
startup, with no reference state.

## What the startup is

0x8C010000 is a copy stub.  The copied block (0x4000) is the SDK's kernel: it
clears the original region, installs a vector area at 0x8C00F400, runs a command
loop (serial monitor, released by bit 7 of the config byte at 0x0C00F71C) and
hands off to a context switch (0x8C010E3C) that restores a thread through an RTE
stub it writes into RAM (0x8C00FA20).  The first thread is the game's main
(0x0C020000 -> 0x0C020024).

## What the port needed

* `tools/boot_relocate.py` - the translator walks the image at its load address;
  the code runs 0xC100 bytes lower.  The relocation moves every code address in the
  window so the literal-pool reads hit the copy (the original is cleared).
* `tools/boot_walk.py` - run, take the first unowned PC, add it as a root,
  regenerate `src/fight/vf3_boot_adapter.c`, rebuild; repeat.
* translator: `ldc Rn,vbr`, `ldc Rn,ssr/spc`, `ldc.l @Rn+,ssr/spc/vbr`,
  `stc.l vbr/ssr/spc,@-Rn`.  SSR/SPC live in two words (`src/fight/boot_rte.c`).
* `src/fight/boot_rte.c` - the RTE stub (RAM code the translator cannot see).
* devices: the config byte at 0xA30100C0 answers 0x8F (the BIOS system area does
  not hold "00"), SCIF SCFSR2 answers 0x60.
* host: `g_events.cap = frames` (a guest that never returns still stops);
  the GDI parser accepts unquoted track names; `VF3_HOST_TRACE=1` prints each slice.

## Where it stands

The startup runs to the game's main loop (0x8C09574E) and the frame events fire
(the ASIC handler 0x8C06423A, the vblank pair).  After 300 frames the host has
produced 0 TA words and issued no GD request: the main loop polls the video cable
(PDTRA, 0xFF800030) and the drive status, but the scene never advances to the
file loads (PLAYER.BIN ... CP_LOGO.BIN of docs/re/boot_gd_ladder.md).  The next
step is to find which condition the first scene waits for.

## Where the boot stands (2026-10-27)

- The disc boot reaches the game's main loop (0x8C09574E), runs the PVR2 init (the PVR ID/revision answers at
  0xA05F8000/4 select the video mode: the variable at 0x0C16CA8C must become 6) and closes frames at every vblank
  (the slice hook hands the TA stream to the host, 800 frames in ~26 s).
- The main thread then sits in the message screen "A Memory Card or enough free memory blocks for saving could not be
  found" (text blitter 0x8C042660 with the BIOS font vector 0x8C0000B4; call chain 0x8C0A24A6 -> 0x8C0A2574 ->
  0x8C0425F0).  It never asks the GD-ROM for anything while that screen is up.
- `vf3_maple_dma` now answers a formatted 128 KiB memory card in slot 1 of port A, but the game's own Maple driver
  (0x8C045xxx, DMA registers through the pool at 0x8C045F18) issues **one** scan list and then waits for its
  completion callback.  ISTNRM bit 0x1000 stays pending (568 reads, never cleared): the host runs the game's own
  handlers (0x8C06423A, vblank pair) directly, but the Maple end callback is reached only through the SDK's interrupt
  dispatcher (VBR 0x8C00F400 + 0x600 -> 0x8C00FA0C -> 0x8C004C66, which saves a full thread context and uses the
  RAM `rte` stub at 0x8C00FA20).  Next step: run that vector for ASIC events in boot mode (INTEVT 0x320, SSR/SPC
  pointing at a return sentinel) instead of calling the game's handler directly.
- Host switches added on the way: `--bios FILE` (optional boot ROM; the font reads), `--dump-vram`, `VF3_MAPLELOG`,
  `VF3_ASICLOG`, register trace in `VF3_HOST_TRACE`.

## Status 2026-10-27: the Maple completion works; the card check does not pass yet

- The SDK vector is not needed.  ASIC bits routed by SB_IML2NRM (0x005F6910, now modelled) go to the SDK's
  second-level handler 0x8C0460E8 (`asic2_entry` in `frame_events`), which walks the callback lists at
  0x0C1A0D48 + 4 * type and runs the maple-end callbacks 0x0C0439BA / 0x0C043A0E (the latter clears ISTNRM 0x1000).
- Three fixes were needed for that: nested handler runs copy the device state (istnrm, iml2, maple/DMA registers)
  back; a call to the masked return sentinel (0x1EAD0000) is a return (`unowned_hook`); a Maple block whose header
  has instruction 7 is one word long and is skipped.
- The game now issues VMU DEVINFO (frame 0x00000101) and GETMEDIAINFO (0x0200010a) to port A unit 1, once each, and
  no BLOCKREAD follows.  The media-info words now follow a formatted card image (255,0,255,254,1,253,13,5,200,31,0,128);
  that did not change the behaviour.
- What the check reads: `0x8C0A1F50` asks the record array at 0x0C19C6A0 (stride 76; +0 attached, +2 usable); the
  attach handler `0x8C0370F0` sets +2 only when `0x8C04667A` (-> 0x8C04D50C) finds the device in the mpdrv table at
  0x0C1B34D8 (stride 0x148, byte +2 present).  `VF3_WATCHW=<hex addr>[,<hex len>]` (new) logs the writes into a RAM range:
  device 0 gets its entry (+2 = 1, state 1..4) but **no write ever lands in the entries after it**, so the mpdrv
  receive path (0x8C03631E.., per port/unit flag bytes at +0xF90, response header compared with -0x100 / -1 at
  0x8C04517E) does not accept the VMU's DEVINFO answer.  The reason is not found yet.
- Pressing Start (`VF3_PRESS=<hex mask>,<from>,<hold>,<period>`, new; `vf3_frame_events_set_buttons`) does not leave
  the screen either, so it is not a plain "press a button" prompt.
- Next: trace the mpdrv receive of the sub-unit response (flags at +0xF90, the `from` byte compare) against a log of
  what the hardware writes for a sub-peripheral answer.
