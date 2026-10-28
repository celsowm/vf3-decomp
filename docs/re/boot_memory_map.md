# 0x8C000000 is RAM, and the REIOS' system area is what the game reads

Two facts about the boot, both settled against the reference emulator's own
code (`tools/emu/flycast/core/`), and both of them change what the port's
boot has to provide.

## 0x8C000000 is the RAM's cached mirror, not the PVR2's register view

The port used to fold `0x8C000000..0x8C000FFF` into `0x1F800000`, the
uncached PVR2's register file, because the game's own code reads the PVR2
through that window.  The reference does not map it that way:

- `core/hw/sh4/sh4_mem.cpp`, `map_area3()`: the SH-4's area 3 is the RAM, and
  the Dreamcast's RAM sits at `0x0C|base`, with `base = i << 5` for the four
  mirrors - so `0x0C000000`, `0x0C200000`, `0x0C400000` and `0x0C600000` are
  the same 32 MiB of RAM, and `0x8C000000` is the *cached* mirror of the first
  of them (`0x8C000000 | base`).
- `core/hw/holly/sb_mem.cpp`: the PVR2's registers live in **area 0**, at
  `0x005F8000..0x005F9FFF`, mirrored at `0xA05F8000`.  There is no
  `0x8C000000` window at all.
- `core/hw/sh4/sh4_mem.cpp`, `map_area1()`: area 1 is the VRAM (`0x04`,
  `0x05`), and area 4 is the Tile Accelerator's FIFO.

So the fold was wrong twice over: it answered a *RAM* read with a register
value, and it answered it with a view the reference does not have.

The port now masks the address to 29 bits and reads the RAM
(`src/fight/matrix_family.c`, `vf3_matrix_read` / `vf3_matrix_write`):

```c
addr &= 0x1FFFFFFFu;
if (addr >= 0x0c000000u && addr < 0x10000000u)
    addr = 0x0c000000u | (addr & 0x00ffffffu);
```

The attract-mode regression stayed at **95.48 %** against the reference's
`extract/analysis/p1/probe.raw` (frame 154, tolerance 24), so the change does
not disturb the rendering.

## The 0x8C0000B0..0x8C0000E0 window is the REIOS' system area

With the RAM mapped correctly, the game's read of `0x8C0000BC` is a read of
RAM - and the value it wants there is the **pointer to the REIOS' GD-ROM
service**, not a device register.  `core/reios/reios.cpp`'s `setup_syscall()`
installs the service vectors in the system area:

| address | service |
|---|---|
| 0x8C0000B0 | system |
| 0x8C0000B4 | font |
| 0x8C0000B8 | flashrom |
| 0x8C0000BC | **gdrom** |
| 0x8C0000C0 | gd2 |
| 0x8C0000E0 | misc |

each pointing at the BIOS' own code (`0x8C001000`, `0x8C001002`, `0x8C001004`,
`0x8C001006`, `0x8C001008`).  This is the answer to the `0x1F8000BC` lead in
`docs/re/advance_progress.md`: the port's "device access mismatch at
0/0: got R 1f8000bc/4" was the game reading the *GD-ROM service pointer* out
of the RAM, and the port's PVR2 view was answering it.

## The boot state has to be the REIOS' own boot state

`tools/make_boot_state.py` now builds the state the way
`core/reios/reios.cpp`'s `reios_boot()` does:

- the first 64 KiB of the RAM are filled with `0xFF`
  (`memset(RAM[0x8C000000], 0xFF, 64K)`);
- the IP.BIN (16 sectors at FAD 45150) is loaded at `0x8C008000` - the copy of
  the disc in this workspace has that region zeroed, and the reference's clean
  boot suffers from the same hole, so the port models the *hardware* and not
  the broken dump;
- the service pointers of the system area are installed;
- the BIOS' own system information (24 bytes at `0x8C000068`, the id and the
  properties at `0x21A056` / `0x21A000` of the BIOS ROM, the settings from the
  flash) is written.

The effect is measurable: with the old state the boot drew a black screen
(0 lit pixels); with the new one it draws **2.154 lit pixels**, and **6.458**
once the Maple model answers the card's requests - the game's message screen.
The "unowned call at 1fffffff" (a jump to the `0xFFFFFFFF` the system area
held) is gone.

## What is still missing

The port starts at the game's own entry (`0x8C004000`) with the 1ST_READ
image in RAM, so the REIOS itself - the part that reads the disc and loads the
game's files - never runs.  The port models the REIOS' *services* instead
(`src/fight/vf3_aica_stub_adapter.c` answers the vectors at `0x0C001000`,
`0x0C001002`, `0x0C001004`, `0x0C001006`), but the game's loader has not
reached the GD-ROM door yet: `VF3_GDTRACE` stays empty.  The card check is in
the way - see `docs/re/card_check.md`.
