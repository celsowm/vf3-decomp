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
