# GD-ROM low-level notes (research, 2026-10-19)

Why this exists: state 27 hung for days because our drive model fed the game's sector addresses to the GDI as if
they were LBAs. The drive speaks FADs (LBA + 150). This note collects what public sources say about the Dreamcast
GD-ROM so the model in `src/sys/gdrom_hle.c` / `src/sys/bios_syscall.c` rests on documented facts, and marks what is
our own inference.

## 1. Addressing: FAD vs LBA

- GDI files list track starts as LBAs (track 3 at 45000 in the usual layout; one published example lists
  track 1 at 0, track 2 at 45000 raw, track 3 at 45150 data). The 45000 start of the high-density area is also why
  the track-3 ISO9660 structures refer to absolute sector numbers (multimedia.cx).
- The drive and the BIOS use FADs, which are LBA + 150 (the 2-second CD pregap). The Linux `gdrom.c` driver adds
  `GD_SESSION_OFFSET` = 150 to every block it asks the drive to read, and subtracts it again when converting a TOC
  entry to an LBA. The driver itself never uses the word FAD; the FAD/LBA reading is an inference from the code.
- KallistiOS calls the TOC entry value (low 24 bits) "the FAD of the track" (`TOC_LBA(n)`).
- **Project consequence:** the game's `GDC_REQ_CMD` start sector (e.g. 0x7ED77 for state 27) is a FAD. The GDI
  read must use `fad - 150`. Fixed in `vf3_gdi_read_sector` (commit aa4e647). Checking: disc sector 0x7ECE1 holds the
  header `00000200 19990628 ... 00025a08 00024400`, which is exactly what the emulator reads; sector 0x7ED77 is float data.

## 2. Disc layout

- Two areas: a low-density CD-compatible area (up to about 35 MB; readable by any CD drive: track 1 data,
  track 2 audio) and a high-density area (up to about 984 MB) that holds the game data.
- A plain CD reader stops at the first TOC; GD-aware firmware reads a second TOC in the high-density area.
  Hence `GETTOC` is called with session 1 first (Linux driver tries session 1, then session 0 for ordinary CDs).
- Data tracks are 2048 bytes/sector in ISO dumps, audio and raw dumps 2352 (a Mode 1 raw sector has a
  16-byte sync + header in front of the 2048 user bytes, which is what `vf3_gdi_read_sector` skips).
- Why data sits far out: constant linear velocity makes the outer edge faster.
- Sega's own spec: "GD-ROM Format Specification Details" Ver. 1.32 (segaretro.org, Gdfm_s132e.pdf). Not read in
  full; the PDF is the authority for the high-density track structure.

## 3. BIOS GDC syscall layer (what the game calls)

The game calls the BIOS through one vector (`0x0C001006` in this build, r7 = function, r6 = 0): REQ_CMD (0),
GET_CMD_STAT (1), EXEC_SERVER (2), INIT_SYSTEM, GET_DRV_STAT, G1 DMA end, CHANGE_DATA_TYPE, REQ_DMA_TRANS, ...
(see `bios_syscall.c`). Names above follow the KallistiOS/DreamShell wrappers (`gdcReqCmd`, `gdcGetCmdStat`).

Command codes (KallistiOS `cdrom.h`):

| code | meaning | code | meaning |
|---|---|---|---|
| 16 (0x10) | PIOREAD | 24 | INIT |
| 17 (0x11) | DMAREAD | 27 | SEEK |
| 18 / 19 | GETTOC / GETTOC2 | 28 | READ (raw sectors) |
| 20 / 21 | PLAY (tracks) / PLAY2 (sectors) | 33 | STOP |
| 22 / 23 | PAUSE / RELEASE | 34 / 35 | GETSCD / GETSES |

The game's loader uses cmd 17 (DMAREAD) with params {start FAD, sector count, destination}. That matches the
`req cmd 17 params 0007ed77 0000004c 0c350000` trace lines.

Command status as returned by GET_CMD_STAT (KallistiOS): FAILED -1, NO_ACTIVE 0, PROCESSING 1, COMPLETED 2,
ABORTED 3. Our model's enum (`gdrom_hle.h`): ERR -1, OK 0 (idle), BUSY 1, COMPLETE 2, CONTINUE 3. BUSY/COMPLETE
line up with PROCESSING/COMPLETED. CONTINUE is our name for the "more data" state of a multi-step read
(not confirmed against another source).

Execution model: REQ_CMD only queues; **EXEC_SERVER must be called repeatedly to let the BIOS state machine advance**,
and the caller polls GET_CMD_STAT until it leaves PROCESSING. This is why a loader wait loop calls
r7=2 then r7=1 in pairs, and why the replay-era stub that swallowed EXEC_SERVER hid the whole load path.

Data-type change (`cdrom_change_dataype(sector_part, cdxa, sector_size)`, -1 = default): sector part
(0x1000 whole sector / 0x2000 data area), CD-XA mode, size (2048 or 2352 common).

Drive status values (GET_DRV_STAT): BUSY 0, PAUSED 1, STANDBY 2, PLAYING 3, SEEKING 4, SCANNING 5, OPEN 6,
NO_DISC 7; disc type 0x80 = GD-ROM (our model returns 1, 0x80).

## 4. Hardware underneath (G1 bus, ATA/SPI)

From the Linux `gdrom.c` driver (credits Marcus Comstedt and Nathan Keynes for the reverse engineering):

- ATA-like register block at 0xA05F7000: ALTSTATUS +0x18, DATA +0x80, ERROR +0x84, INTSEC +0x88, SECNUM +0x8C,
  BCL/BCH +0x90/+0x94, DSEL +0x98, STATUS/COMMAND +0x9C. Busy = ALTSTATUS bit 7; data request when
  `(status & 0x88) == 8`.
- G1 DMA registers: START addr +0x404, LENGTH +0x408, DIRECTION +0x40C, ENABLE +0x414, STATUS +0x418,
  WAIT +0x4A0, ACCESS_CTRL +0x4B8, RESET +0x4E4.
- ATA commands: 0xA0 PACKET, 0xA1 IDENTIFY, 0x90 EXECDIAG, 0xEF SET FEATURES (DMA mode init).
- Sega Packet Interface (12-byte packets sent after 0xA0): 0x70 spin up/prepare, 0x14 read TOC (byte 1 = session),
  0x13 sense data, **0x30 DMA read** (byte 1 = 0x20, bytes 2-4 start block, bytes 8-10 block count).
- DMA read sequence: set START (physical), LENGTH = blocks x 2048, DIRECTION = 1, ENABLE = 1; fill the 0x30 packet;
  wait not-busy, write 0xA0; send the packet; write 1 to DMA STATUS to start; wait for the DMA interrupt.
  ACCESS_CTRL is written 0x8843407F (allowed range 0x0C000000-0x0FFFFFFF), WAIT = 9.
- The MAME NAOMI/DC G1 code notes the G1 ATA area stays locked until the BIOS checksum check passes (so a custom
  boot cannot touch the drive registers before that).
- The disc interrupt model: a command IRQ (pending flag cleared on read of status) and a DMA IRQ (transfer done).

## 5. What the model does and does not reproduce

- Reproduced: REQ_CMD/GET_CMD_STAT/EXEC_SERVER state machine, DMAREAD of 5 sectors per scheduler step, FAD addressing
  (now), request ids, sector copy into guest RAM at the requested destination.
- Not reproduced: the real timing (our poll divider / cycle clock is measured on a few states, see
  phase4_findings.md "accepted" list), seek/spin states, G1 DMA interrupts (the callback registration call is
  acknowledged but no interrupt is delivered), SPI errors/retries, GETTOC/GETSES results, CDDA.
- Open item worth checking against real hardware docs: the bytes the BIOS returns in the GET_CMD_STAT ext words
  (`result[2]` = bytes transferred so far, `result[3]` = 0 internal wait) are from observation of the game's reads,
  not from a public spec.

## Sources

- KallistiOS `cdrom.h`: https://cadcdev.sourceforge.net/docs/kos-current/cdrom_8h.html
- Linux `drivers/cdrom/gdrom.c` (Dreamcast GD-ROM driver): https://android.googlesource.com/kernel/common/+/1855aaccd74c/drivers/cdrom/gdrom.c
- Understanding the Dreamcast GD-ROM layout (multimedia.cx): https://multimedia.cx/eggs/?p=4745
- Sega GD-ROM Format Specification Details 1.32: https://www.segaretro.org/images/e/e8/Gdfm_s132e.pdf (not read in full)
- MAME NAOMI G1 / dccons: https://git.redump.net/hbmame/tree/src/mame/machine/naomig1.cpp
- DreamShell ISO loader (GDC syscall emulation): https://deepwiki.com/DC-SWAT/DreamShell/3.1-iso-loader-module
- Fabien Sanglard, Dreamcast hacking: https://www.fabiensanglard.net/dreamcast_hacking
