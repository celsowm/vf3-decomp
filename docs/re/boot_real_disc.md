# The disc was there after all: the boot reads the real ISO (2026-10-31)

`docs/re/boot_data_blocked.md` concluded that the boot could not reach the
game because the disc image in `rom/` was empty and the game's data files
were absent.  **That conclusion was about the workspace, not about the
game.**  The disc was in the workspace all along - just not in `rom/`.

With the real disc in place the port's boot does what the hardware does:
it reads the ISO9660 volume, walks the directory and loads the game's files.
The card check now matches the reference exactly.  This note records what
changed, how it was proven, and what is still open.

## The disc was in the emulator's ISO directory

The images in `rom/` were **placeholders of the wrong size**, not dumps:

| file | `rom/` (before) | the real one | note |
|---|---:|---:|---|
| `track01.bin` | 9,408 B | 705,600 B | 300 sectors, not 4 |
| `track02.raw` | 104,781,600 B | 1,237,152 B | 526 sectors, not 44,550 |
| `track03.bin` | 1,305,360,000 B | 1,185,760,800 B | 504,150 sectors, not 555,000 |

The real data track is 504,150 sectors, which is exactly what a GD-ROM needs:
the track starts at LBA 45,000 and the disc ends at LBA 549,149
(45,000 + 504,150 - 1).  The placeholders were zero-filled files of arbitrary
length, so the GDI descriptor in `rom/` was describing a disc that never
existed.

The real image was in the emulator's own ISO directory:

```
D:\emuladores\dreamcast\isos\[GDI] Virtua Fighter 3tb (US)\
    track01.bin      705,600
    track02.raw    1,237,152
    track03.bin 1,185,760,800
    Virtua Fighter 3tb v1.002 (1999)(Sega)(NTSC)(US)[!].gdi
    rip\            413 files: the data track's contents
```

The `.gdi` is **byte-identical** to the one in `rom/`, so the descriptor was
never wrong - only the tracks it pointed at.

Both tracks and the 413 extracted files were copied into `rom/` and
`extract/gamedata/` (both gitignored, so no copyrighted data is committed).
The copies were verified with SHA-256 against the source.

## The boot reads the real volume

`tools/iso9660.py` (new) reads the data track's ISO9660 volume: the primary
volume descriptor at sector 16, the root directory at LBA 45,020, and every
file record.

```
$ python tools/iso9660.py rom/track03.bin
volume id : VF3TB
root      : LBA 45020, 20480 bytes
/1ST_READ.BIN                            file LBA   548424     1179648
/ANAUNCE.BIN                             file LBA   532972      175508
/BGM_AKI.BIN                             file LBA   533058      894320
... (412 files)
```

The port's boot now reads exactly those sectors.  With `VF3_GDTRACE=1` the
loader's requests are:

```
  req cmd 17 params 0000b06e 00000001 0c2a6300 00000000   <- the PVD
  req cmd 17 params 0000b072 00000001 0c2a6300 00000000   <- the root directory
  ... b073 .. b07b                                        <- 10 directory sectors
  req cmd 17 params 0000b070 00000001 0c2a6340 00000000
  req cmd 17 params 000085b12 00000001 0caae800 00000000   <- /SNDDRV.BIN
```

FAD `0xb06e` = LBA 45,016 = the volume descriptor; `0xb072`..`0xb07b` = the
10 sectors of the root directory (20,480 bytes, exactly what the PVD says);
`0xb070` = LBA 45,018; `0x85b12` = LBA 547,452 = `/SNDDRV.BIN`'s extent.

The file arrives **byte for byte**: the RAM at `0x0CAAE800` after the boot is
identical to `extract/gamedata/SNDDRV.BIN` (the first 64 bytes and the whole
file).

The 69 DTPK packages were rebuilt from the restored data
(`tools/dtpk_extract.py`, 69 packages, the number `AGENTS.md` documents), and
`extract/dtpk/` holds their sections and `_dtpk.json` again.

## The card check is now correct

`docs/re/card_check.md` recorded that the port's card check read **eight**
blocks (255..248) while the reference read **fifteen** (255..241), and that
the port never asked the second card (recipient `0x02`) while the reference
asked both `0x01` and `0x02`.

**Both of those differences were artifacts of the empty disc and of the
save-state reference.**  The port's own boot-time card check now reads the
whole chain:

```
$ python tools/count_blocks.py build/maple_real.log
block reads: 15
  to=0x01 block=ff
  ...
  to=0x01 block=f1
```

and it ends with the **LCD write** (`frame 3200010c`, the `0x0C` command with
the `0x04000000` argument), which is the last thing the reference does:

```
00:14:901 hw/maple/maple_devs.cpp:718 D[MAPLE]: VMU A1 LCD write
```

The missing second card was never a defect either.  The reference's
`flycast.log` was a **save-state run** (`SAVESTATE: Loaded state ver 854`),
in which the running game polls *both* VMUs.  In a **real boot** the
reference never touches A2:

```
$ grep -c 'VMU A2' flycast.log
0
```

So the port's "never asks `0x02`" is what the hardware does at boot time.

## The reference can now boot for real

With the disc in place, the reference emulator does a **clean boot** instead
of resuming a save state.  Two things have to be moved out of the way:

* the savestate: `tools/emu/flycast-build/data/vf3.state` (Flycast loads it
  automatically; `-config Dreamcast:AutoLoadState=0` does not stop it);
* the log is written to the **current directory**, not to the build
  directory, and it is 1.4 GB for a boot.

```
$ tools\emu\flycast-build\flycast_v3.exe E:\vf3-decomp\rom\vf3.gdi
```

The log's head shows the REIOS reading the real disc:

```
00:00:953 imgread/gdi.cpp:41 I[GDROM]: GDI: 3 tracks
00:00:953 imgread/gdi.cpp:125 D[GDROM]: file[3] "track03.bin": FAD:45000, CTRL:4, SSIZE:2352, OFFSET:0
00:00:982 reios/reios.cpp:153 I[REIOS]: hardware SEGA SEGAKATANA ... product MK-51001 version V1.002 date 19990820 boot 1ST_READ.BIN ... name VF3TB
```

**This is the boot oracle the earlier notes said did not exist.**  The
reference's boot is a run of the hardware, not a resume.

## The two boots, request by request

`tools/boot_reads.py` (new) lines the two boots up.  It parses the
reference's `SPI_CD_READ - Sector=N` line - the sector the guest asked for -
and not the `GDROM-DMA ... fad X` line, whose "fad" is
`read_params.start_sector` **after** the transfer advanced it, so it is the
address of the sector *after* the one that was read.

| | reference | port |
|---|---:|---:|
| sectors requested | 382 | 13 |
| files loaded | 367 | 1 |
| card check | 15 blocks (255..241), A1 only, then the LCD write | **the same** |

From the ISO directory onward the two agree request for request:

```
   #       dest       len      fad  file            the port
   0    c2a6300      2048     b06e  (PVD)           b06e  c2a6300
   1    c2a6300      2048     b072  (directory)     b072  c2a6300
   ...                                               ...
  11    c2a6340      2048     b070  (directory)     b070  c2a6340
  12    caae800     53248    85b12  /SNDDRV.BIN     85b12 caae800
```

The reference's first four requests (`0xb05e`, `0xb065`, `0xb06e`, `0xb072`
into `0x0C008000`/`0x0C00B800`/`0x0C010000`, then `1ST_READ.BIN` itself into
`0x0C010000`) are the **REIOS's** own boot reads.  The port does not run the
REIOS - it starts at the game's own entry with the image already in RAM - so
it begins at the reference's fifth request, which is the game's own loader
reading the volume.

The two diverge at the reference's request 13: the reference asks for
`/COIN.BIN` (FAD `0x8226d`) and carries on to 367 files; the port stops after
`/SNDDRV.BIN`.

## What is still open

**The port loads one file and stops.**  The loader's buffer at `0x0C2A6300`
holds the next file it wants - the name `VF3TBE3.BIN;1` and the directory
record - so the loader *did* find the next entry; it just never asked the
drive for it.  The guest is parked at `0x0C0C5C00` (the host's `pc` in the
`VF3_HOST_TRACE=1` output), in a function that calls `0x0C040498` and tests
its result.

The next step is to find what the loader does between two files and what the
port's model does not answer.  The oracle is now in place: the reference's
log says exactly which sector comes next.

Two smaller leads are still open from the earlier notes:

* the enumeration stub `0x0C046E14` - who computes its indirect target (no
  literal, no direct branch, absent from RAM);
* the device-tape mismatch at `0x1F8000BC` - the port's PVR2 view swallows a
  BIOS pointer read.

## The tools

| tool | what it answers |
|---|---|
| `tools/iso9660.py` | the data track's ISO9660 volume: the files, their extents and the file a FAD belongs to |
| `tools/boot_reads.py` | the two boots side by side, request for request, with the file each request fetches |
| `tools/trace_bin_sum.py` | the reference's binary execution trace (8 bytes per instruction) as a PC histogram |
| `tools/gd_sectorscan.py` | how much of a track file carries data |
| `tools/gd_layout.py` | the data track's sector map |
| `tools/count_blocks.py` | the blocks a Maple log reads, and the recipient of each |

## Correction to `docs/re/boot_data_blocked.md`

That note's headline - "the boot is blocked by data, not by the services" -
was right about the *workspace* and wrong about the *game*: the data was
never missing, it was in the emulator's ISO directory.  Its table of what the
port's boot reaches is also superseded: the boot now reads the volume, loads
`/SNDDRV.BIN` byte for byte and completes the card check with the LCD write.

Its second half - "the reference's log is a run with a save state loaded, not
a boot" - **stands**, and is now the reason the reference could be compared
at all: with the disc in place the savestate can be moved aside and the
reference can boot for real.
