# The boot is blocked by data, not by the services

This note records what the from-scratch boot of the port can and cannot do in
this workspace, and what the reference's own log may be used as an oracle for.
It is the correction of two beliefs that the earlier notes carried.

## The disc image in `rom/` is empty

`rom/vf3.gdi` describes three tracks:

```
3
1 0 4 2352 track01.bin 0
2 450 0 2352 track02.raw 0
3 45000 4 2352 track03.bin 0
```

(track 1 at LBA 0 and track 3 at LBA 45000, 2352 bytes per sector - the raw
layout with a 16 byte sync+header in front of the 2048 user bytes.)

The files have the right sizes and **no data at all**:

```
$ python tools/gd_sectorscan.py rom/track01.bin rom/track02.raw rom/track03.bin
track01.bin         9408 bytes       0/     1 chunks with data  first nz none  last nz none
track02.raw    104781600 bytes       0/  3198 chunks with data  first nz none  last nz none
track03.bin   1305360000 bytes       0/ 39837 chunks with data  first nz none  last nz none
```

Every byte of the disc is zero.  A loader that reads the disc therefore gets
zeros, and so does the reference emulator - it was pointed at the same `.gdi`.

The game's own data files are missing as well: `extract/gamedata/` holds the
three executables (`1ST_READ.BIN`, `RELOAD.BIN`, `VF3TBE3.BIN`), not the 412
files of the data track that `AGENTS.md` describes.

**Consequence.**  The port's boot can never reach the game from the disc, and
the reference could not have either.  The black screen is explained: the
loader runs, the drive answers, the sectors are empty.  The missing piece is
the *data*, and no amount of service modelling will produce it.

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

## What is left, and where to look next

The card check's own limit (eight reads, and no second card) is still open,
but it now has to be measured **against the boot-time card service**, not
against the reference's running-game poll.  The guest's own code is the
oracle here: the transfer builder is at `0x0C036132` (it writes `SB_MDST` at
`0x0C0361F4`), the caller that walks the chain is at `0x0C043CAA`, and the
chain itself is in the guest's FAT copy at `0x0C198AA0` (halfword *n* holds
block *n*; `FAT[241] = 0xFFFC` ends the chain, `FAT[248] = 0x00F7` says
"continue").

The tools that read the tables:

| tool | what it answers |
|---|---|
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
