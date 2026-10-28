# The boot's VRAM traffic, and why the screen stays black (2026-10-28)

The port boots the game from the disc image (`build/boot.state`, entry
`0x8c004000`), reaches the game's main loop and the message screen, and then
renders 921,600 pixels per frame - all of them black.  This note says what the
guest writes into the VRAM during that boot, which texture the Tile
Accelerator samples, and why the picture is empty.  It also records two
fixes: the "unowned call" the host used to print at the end of every boot was
the frame cap, and the claim audit was missing the chain's fallback.

## The VRAM has three windows, and the region is the address' bits 24-28

The Dreamcast shows the PVR2's memory through several windows, and they do not
hold the same bytes at the same offsets:

| region | window | path |
|--------|--------|------|
| 0x04 | 0x04000000 (and its mirrors) | the 64 bit path: the banks one after the other, the view the Tile Accelerator samples |
| 0x05 | 0x05000000 (and its mirrors) | the 32 bit path: the banks interleaved (`pvr_map32`) |
| 0x11 | 0x11000000 | the Tile Accelerator's own window, lower half; the system bus' `SB_LMMODE0` picks the path |
| 0x13 | 0x13000000 | the same, upper half (`SB_LMMODE1`) |

The region is the address' bits 24-28, not the address' top byte: the window
repeats every 0x20000000 (the eight mirrors 0x04..0x07, 0x24..0x27, ...,
0xE4..0xE7), and every mirror of a region is the same window.  The authority is
the reference emulator's source:

* `tools/emu/flycast/core/hw/sh4/sh4_mem.cpp`, `map_area1`: the 64 bit path is
  a block mapped over the VRAM (`0x04|base`), the 32 bit path is a handler
  (`0x05|base`), and `mirrorMapping(0x06|base, 0x04|base, 0x02)` makes 0x06
  and 0x07 mirrors of them.  `base = i << 5` for the eight mirrors.
* `tools/emu/flycast/core/hw/pvr/pvr_mem.cpp`, `pvr_map32`: the interleave of
  the 32 bit path, and `pvr_read_area4`/`pvr_write_area4`: the Tile
  Accelerator's window follows `SB_LMMODE0`/`SB_LMMODE1`.

`src/render/pvr2.c` now decides the path from the region id
(`(dest >> 24) & 0x1F`) instead of from `dest & 0x0F000000`.  The change is
output-neutral for the addresses the port can produce today (the port masks
every address to 29 bits before the hook, so the old and the new rule agree);
it makes the model follow the hardware's structure and it documents the
mirrors.  The dumps before and after the change are byte-identical
(`build/boot60.vram` and `build/boot60c.vram`: the same 20,042 non-zero bytes
in the same 6,998 runs).

## What the boot writes

`VF3_VRAMLOG=1` counts the guest's VRAM writes per region (the host prints the
region and the address range):

```
  region 04: plain 32 (32 nonzero) 04400000..0440007c
  region 05: plain 2102648 (5425 nonzero) 05000000..057ffffc
  region 11: sq 54784 (3999 nonzero) 11400080..1143587c
```

* **region 0x05, 2,102,648 words, 0x05000000..0x057ffffc.**  The game's video
  init (0x8C063446) clears the whole VRAM through the mirror at 0x0A5000000 -
  the 32 bit path - in 4 byte steps: 0x8C063680 sets `r6 = 4`, `r5 = r15` (the
  word the caller zeroed at 0x8C06360E) and calls the copy helper
  0x0C062E7E once per word, 0x200000 times.  The helper reads the source word
  and writes it to the destination, so the whole 8 MB is written through the
  interleave and the VRAM ends up zero (the 5,425 non-zero words are the font
  the message screen uploads, not this loop).
* **region 0x04, 32 words at 0x04400000.**  The PVR2's own registers are
  written through the 64 bit path.
* **region 0x11, 54,784 words at 0x11400080..0x1143587C.**  The store queue
  bursts: the game's own display data (the ISP parameters and the object
  list), which land at 0x400080..0x43587C of the VRAM.

The dump confirms it: 20,042 non-zero bytes in the whole 8 MB, in three
places - the font glyphs at 0x21EE02 and 0x2D07C8 (the interleave of the
guest's 0x10FF02 and 0x1683E4), and the display data at 0x400000..0x425880.

## The texture the Tile Accelerator samples is empty

The port's own TA stream (248 words, 11 lists, 14 primitives, 3 of them
textured) samples one texture, in all three textured primitives:

```
tex fmt 0 vq 0 mip 0 lin 0 512x512 tcw 000a9b10 tsp 949024f6
```

The texture control word's address is in units of eight bytes, so the texture
is the 512x512 ARGB1555 twiddled texture at 0x54D880 - and the VRAM there is
zero (`build/boot60c.vram` at 0x54D880: 32 zero bytes).  The screen is
therefore black because the *data* is missing, not because the rasteriser
misplaces it: the same renderer reproduces the reference's attract fight at
95.48% of the pixels within 24 levels (frame 154 of `probe.raw`).

The data is missing because the port's boot never reads the disc.  The boot
starts at the game's own entry (0x8C004000) with only the 1ST_READ image in
RAM; the REIOS, which is what loads the game's files, never runs, and the
game sits on the memory card screen (docs/re/p7_boot_from_disc.md) without
asking the drive for anything.  The reference's clean boot agrees with that:
it never touches the GD-ROM either (docs/re/ref_clean_boot.md).

## "unowned call at ..." was the frame cap

Every boot run ended with

```
vf3sdl: unowned call at 0c062e7e (1 unowned, first 0c062e7e)
```

and exited with status 1.  No PC was missing: the message is the *end of the
run*.  The chain stops when the step budget runs out; the budget hook asks the
event model for more time; and the event model answers 0 when the guest has
taken as many vblanks as the host asked for (`vf3_frame_events_slice`:
`if (ev->cap && ev->frames >= ev->cap) return 0;`).  The dispatcher then sent
the stop to the "missing port" hook, which reported it as an unowned call.

The fix is in `vf3_matrix_family_dispatch` (src/fight/matrix_family.c): a stop
that comes from the budget hook running out of time is not a missing port, so
it does not go to the missing hook.  The host now reports the other way of
running out of time - an event handler that could not be run - separately.

## The claim audit was missing the chain's fallback

`tools/claim_hole_audit.py` reported 158 PCs "owned but routable by nobody",
all of them in `vf3_gap_b03_adapter.c` (0x0C0490E8..0x0C049ABE).  The audit
looked for the modules' `_contains` symbols only, and the chain's last module
has none: `vf3_matrix_adapter` (src/fight/matrix_adapters.c) is the fallback
the router ends with, and it serves *every* PC its own translation carries
(27,964 of them).  The audit now reads that translation too:

```
modules: 106   owned PCs: 312113   routable PCs: 320663   (the fallback carries 27964)
OWNED BUT ROUTABLE BY NOBODY: 0
```

There is no hole: every PC the ledger counts is servable by the router.

## The GD-ROM has two doors, and the port models one

The Dreamcast's disc is reached in two different ways, and the port only has
one of them:

* **the BIOS syscall door** - the REIOS' own loader service at the vector
  0x8C001006 (`vf3_bios_gd_syscall`, `src/sys/gdrom_hle.c`,
  `src/sys/bios_syscall.c`).  The reference's boot drives it hard: the log
  carries 23,480 "GDROM: HLE EXEC_SERVER" lines and thousands of
  "GET_CMD_STAT" polls, and the drive's sectors are read from the first
  seconds of the run.  This is the door the *REIOS* uses to load the game.
* **the ATA register door** - the register block at 0x5F7000..0x5F711F, which
  the game's own GDFS driver programs (the command block, the sector number,
  the data port and the buffer control, with the transfer done by the SH-4's
  DMA channel 1).  This is the door the *game* uses to read its own files.

The port models the second door as a stub: `device_read` in
`src/fight/native_tick.c` answers only STATUS/ALTSTAT (0x5F7018/0x5F709C)
and SECTNUM (0x5F708C) and returns zero for everything else, with the port's
own comment saying it: "With every register reading as zero the driver
concluded the drive was not there and the boot never read a file."

That is what the boot shows: with the card check passing, the game never
calls the BIOS's GD service at all (`VF3_GDTRACE` prints nothing in 90
frames) and never touches the ATA registers either (0 accesses to
0x5F70xx out of 25,512 device reads in 60 frames).  So the game is not
failing a transfer: it never asks for anything.

## Where the reference's data is, and the port's boot state is not

The port's boot state holds the 1ST_READ image and zeros.  The reference's
state (the attract fight, `extract/analysis/p1/frm_keep/st.bin.000280`, the
same file format) is 5,923,560 bytes different, and the RAM area that
differs is 0x0C22E000..0x0C2DFFFF - the size of the 512x512 ARGB1555
texture the Tile Accelerator samples, plus the sound buffer.  That is the
game's data, loaded before the game runs.

The same conclusion from the other side: the game never uploads the
texture (the boot's 2,102,648 writes to the 32 bit path are the 8 MB clear
plus ~5,500 words of font glyphs, and the 54,784 store-queue words are the
display data - the 131,072 words of the texture are simply not there), so
the texture was never in the VRAM and the data never arrived.

## What the next step is

The picture is black because the game's data never arrives.  Two ways to put
it there:

* model the **ATA register interface** the game's GDFS driver talks to (the
  port has the drive's *sector* model - `vf3_gdrom` reads sectors by FAD out
  of the disc image - but not the register door that reaches it), so the game
  can read the files itself; or
* load the same data the way the reference has it, from the extracted image
  files (`extract/gamedata/`, `extract/dtpk/`), at the addresses the
  reference has it (0x0C22E000 and up).

The renderer and the VRAM model are ready for the data: the attract fight,
which has its textures, matches the reference, and the card model now answers
the block requests the way the reference answers them (docs/re/maple.md).
