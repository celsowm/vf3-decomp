# The boot is blocked by data, not by the services

**Correction (2026-10-31).**  The disc was **not** missing.  The images in
`rom/` were zero-filled placeholders of the wrong size, and the real image
was in the emulator's own ISO directory all along
(`D:\emuladores\dreamcast\isos\[GDI] Virtua Fighter 3tb (US)\`).  With the
real disc restored the port's boot reads the ISO9660 volume, loads the game's
files and completes the card check; the reference can boot for real too.  See
**`docs/re/boot_real_disc.md`** for the measurements, the tools and the two
boots side by side.

The rest of this note is what was measured against the empty disc, and it is
kept because the reasoning still holds - in particular the second half, "the
reference's log is a run with a save state loaded, not a boot", which is the
reason the reference could not be compared with the port until now.

This note records what the from-scratch boot of the port can and cannot do in
this workspace, and what the reference's own log may be used as an oracle for.
It is the correction of two beliefs that the earlier notes carried.

## The disc image in `rom/` is empty

**Correction (2026-10-31).**  The files in `rom/` are zero-filled placeholders
of the **wrong size** - not a dump of a disc that has no data.  The real
image was in the emulator's ISO directory:

| file | `rom/` (before) | the real one |
|---|---:|---:|
| `track01.bin` | 9,408 B | 705,600 B |
| `track02.raw` | 104,781,600 B | 1,237,152 B |
| `track03.bin` | 1,305,360,000 B | 1,185,760,800 B |

The real data track's 504,150 sectors are exactly what a GD-ROM needs (the
track starts at LBA 45,000 and the disc ends at LBA 549,149).  The `.gdi`
descriptor was never wrong - only the tracks it pointed at.

The scan below is what the placeholders showed, and it is what the earlier
notes measured:

```
$ python tools/gd_sectorscan.py rom/track01.bin rom/track02.raw rom/track03.bin
track01.bin         9408 bytes       0/     1 chunks with data  first nz none  last nz none
track02.raw    104781600 bytes       0/  3198 chunks with data  first nz none  last nz none
track03.bin   1305360000 bytes       0/ 39837 chunks with data  first nz none  last nz none
```

The game's own data files were missing as well: `extract/gamedata/` held the
three executables (`1ST_READ.BIN`, `RELOAD.BIN`, `VF3TBE3.BIN`), not the 412
files of the data track that `AGENTS.md` describes.

**Consequence (as measured then).**  The port's boot could never reach the
game from the disc, and the reference could not have either.  The black
screen was explained: the loader ran, the drive answered, the sectors were
empty.  The missing piece was the *data*, and no amount of service modelling
would produce it.

**Consequence (now).**  The data was never missing; it was in the wrong
place.  `docs/re/boot_real_disc.md` has the restored boot.

## The reference's log is a run with a save state loaded, not a boot

`tools/emu/flycast-ref-build/flycast.log` starts with

```
00:00:778 nullDC.cpp:360 N[SAVESTATE]: Loaded state ver 854 from
             E:\vf3-decomp\tools\emu\flycast-ref-build\data\vf3.state size 27785294
```

so the reference **loaded a state of the already running game** (27.8 MB) and
carried on from there.  Everything the log shows after that second belongs to
a running game, not to a boot:

* the 23,480 `GDROM: HLE EXEC_SERVER` calls and the 20,904 `GET_CMD_STAT`
  polls are the running game's disc traffic;
* the four `GDROM: DMA READ` calls (FAD 429257, 438518, 439286, 546094 - 512,
  256, 256 and 84 sectors) are the running game's own reads;
* the card check at `00:14:542` (blocks 255..241 to A1 *and* A2, then the LCD
  write) is the **running game's** card poll.

The port's boot is a different scenario: it starts at the game's own entry
(`0x8C004000`) with only the 1ST_READ image in RAM, and the SDK's card
service runs its **boot-time** check there.

**Consequence.**  "The reference walks fifteen blocks and talks to two cards,
the port walks eight and talks to one" is **not** a port defect.  Two
scenarios are being compared, and the numbers differ for that reason alone.
The earlier notes took the difference for a bug; this is the correction.

The same goes for the per-device table: the reference's `+0x30 = 18` /
`+0x34 = 17` is the state of a running game's mpdrv, not the state the boot
reaches.

## What the port's boot does reach

With the drive served (`docs/re/gd_service.md`), the port's boot now:

* asks the BIOS GD-ROM vector about twenty times in 45 frames and receives the
  drive's answers (before the fix: the idle model's);
* renders the same picture as before the fix (176 TA words, 614400 pixels,
  the same ten primitives) - the picture is black because the texture the
  Tile Accelerator samples is empty, not because the rasteriser is broken;
* runs the SDK's card check, which walks the directory chain from block 255 to
  248 and asks the card in expansion socket 1 (`0x01`).

**Correction (2026-10-31).**  With the real disc, the card check walks the
chain to block **241** (fifteen blocks) and ends with the card's LCD write,
and the loader reads the volume and loads `/SNDDRV.BIN` byte for byte.  See
`docs/re/boot_real_disc.md`.

## What is left, and where to look next

**Correction (2026-10-31).**  The card check's own limit (eight reads, and no
second card) is **closed**: it was the empty disc.  The port's boot-time card
check now reads 255..241 and writes the LCD, which is exactly what the
reference does in a real boot (where it never touches A2 at all).

What is left is the loader: the port loads one file (`/SNDDRV.BIN`) and stops,
while the reference loads 367.  The guest is parked at `0x0C0C5C00`.  The
oracle is the reference's own boot log - it names the next sector to read -
and the tools are `tools/boot_reads.py` (the two boots side by side) and
`tools/iso9660.py` (the volume).

The guest's card service is at: the transfer builder `0x0C036132` (it writes
`SB_MDST` at `0x0C0361F4`), the caller that walks the chain `0x0C043CAA`, and
the chain itself in the guest's FAT copy at `0x0C198AA0` (halfword *n* holds
block *n*; `FAT[241] = 0xFFFC` ends the chain, `FAT[248] = 0x00F7` says
"continue").

The tools that read the tables:

| tool | what it answers |
|---|---|
| `tools/iso9660.py <track>` | the data track's ISO9660 volume: the files, their extents, and the file a FAD belongs to |
| `tools/boot_reads.py <ref log> [port log]` | the two boots side by side, request for request |
| `tools/trace_bin_sum.py <trace>` | the reference's binary execution trace as a PC histogram |
| `tools/maple_card_state.py <ram dump>` | the mpdrv tables in a RAM dump |
| `tools/maple_card_probe.py` | the record with different media-info answers |
| `tools/maple_card_count_probe.py` | the record with different root blocks (the count does not follow the media info) |
| `tools/maple_card_header_probe.py` | the record with forced reply headers |
| `tools/count_blocks.py <maple log>` | the blocks a Maple log reads, and the recipient of each |
| `tools/node_list.py <ram dump>` | the SDK's service node list (the heads at `0x0C1A0D48`, the nodes at `0x0C1A0D80`) |
| `tools/trace_sum.py <trace log>` | how often each entry was entered, and from which return address |
| `tools/pool_at.py <addr>...` | the image's literal-pool words at a few addresses |
| `tools/gd_sector_check.py` | the bytes a sector read hands the guest, against the disc |
| `tools/gd_sectorscan.py` | how much of a track file carries data |
| `tools/gd_layout.py` | the data track's sector map (which sectors carry anything) |

The `VF3_MAPLEPC=1` probe prints the guest's return addresses at the moment a
Maple transfer starts; the function that asks for the next block of the chain
is one of them.
