# Dreamcast Maple bus - notes for the pad model

Sources: Linux drivers/sh/maple/maple.c (https://codebrowser.dev/linux/linux/drivers/sh/maple/maple.c.html), MAME dc.h /
maple-dc.cpp register map (https://git.redump.net/hbmame/tree/src/mame/includes/dc.h), KallistiOS controller.h
(https://cadcdev.sourceforge.net/docs/kos-2.0.0/controller_8h.html), Linux maplecontrol.c.

## DMA registers (base 0x005F6C00)
| addr | name | meaning |
|---|---|---|
| 5F6C04 | SB_MDSTAR | physical address of the transmit block list |
| 5F6C10 | SB_MDTSEL | trigger: 0 = software (MDST), 1 = vblank |
| 5F6C14 | SB_MDEN | DMA enable |
| 5F6C18 | SB_MDST | start (software trigger); reads busy while a DMA runs |
| 5F6C80 | SB_MSYS | bits 31-16 timeout (20 ns), 9-8 speed (0 = 2 Mbps), 3-0 delay after vblank (1.3 ms units) |
| 5F6C84 | SB_MST | state, bit 0 = DMA in progress |

(Offsets from MAME's map; the Linux names MAPLE_DMAADDR/ENABLE/TRIGTYPE/SPEED/STATE are the same registers.)

## Transmit block (per packet, 3 + len words)
1. header: `(port << 16) | len | last<<31` (bit 31 set on the final packet of the list)
2. receive address: physical address where the response is written
3. frame: `command | to << 8 | from << 16 | len << 24` (port in bits 7-6 of from/to; unit 0 = main = 0x20, sub-units 1-5 = bit mask)
4. payload `len` words; first word is the function code (big-endian)
Linux's comment says the last header has bit 31 set to 0 while its code leaves it set: unresolved, check against flycast.

## Response (receive buffer)
byte 0 = response code (0xFF none, 5 DEVINFO, 8 DATATRF, 0xFE file error ...); DEVINFO: +4 function code, +8 function data (3 words),
+20 area, +21 connector dir, +22 name[30], +112 standby, +114 max power. GET_CONDITION answer = DATATRF with function 0x01000000
(controller) then buttons u16 (wire is active low: Linux inverts it), rtrig, ltrig, joy x, y (0x80 centred), joy2 x, y.
Button bits (KOS): C=0 B=1 A=2 START=3 UP=4 DOWN=5 LEFT=6 RIGHT=7 Y=9 X=10.

## Completion
When the DMA ends the ASIC raises ISTNRM bit 12 (Maple DMA end, 0x1000 - from memory of flycast/KOS, not verified in the sources above).

## What the native runs do (2026-10-18)
VF3_DEVLOG on state 21 over 30 vblanks: no access to 0x5F6C00..0x5F6CFF at all (reads are SPG_STATUS 5F8138, TMU 1FD8000C, ASIC
5F6900/5F6908, DMAC ch2). So state 21's frame loop never polls the pad; the title screen idle needs a different gate. Model
Maple only when a run writes SB_MDSTAR/SB_MDST.

## Confirmed against local references (2026-10-18)
- ISTNRM bit 12 = Maple DMA end (refs/DreamcastRecompiled dc_runtime.cpp: `kAsicEventMapleDmaBit = 1u << 12`, ASIC_EVT_MAPLE_DMA).
- Transfer header (refs/dream-recomp/runtime/src/maple/maple.cpp:338): bit 31 = **last** (set on the final block, so the Linux code
  is right and its comment wrong), bits 17:16 port, 10:8 pattern, 7:0 frame words - 1; then the receive address, then the frame.

## The card's block requests (2026-10-28)

The port read the wrong block of the memory card.  The guest asks for a block
with the word that follows the function code, and the reference reads that
word the way the Maple wire carries it (most significant byte first, while the
SH-4 stores it the other way round), keeps its low sixteen bits as the block
number and truncates a number above 255 to its low byte
(`tools/emu/flycast/core/hw/maple/maple_devs.cpp`, `MDCF_BlockRead` /
`MFID_1_Storage`):

```c
u32 xo = r32();
u32 Block = (SWAP32(xo)) & 0xffff;
if (Block > 255) Block &= 255;
wptr(flash_data + Block * 512, 512);     /* the whole block, in one transfer */
```

The game asks for the last blocks of the card as 0xFFFC..0xFFFF, so the
truncation is what makes those requests mean the blocks 252..255.  The port
read the phase and the block out of the *following* words, so every request
answered with the block 0 - the game's read of the FAT (block 254) came back
with the root block's bytes, the free-block count was zero and the game sat
on the message screen.

The port now parses the request the way the reference does and answers with
the whole 512 byte block (`src/sys/maple_hle.c`, `maple_wire` / `maple_block`).
The write path follows the reference as well: the block and the phase share
the same word (the block is its low sixteen bits, the phase its bits 16-23)
and the data follows it.

The card's media info also had to match the reference: the directory size is
13, because the card's own FAT chains thirteen directory blocks (253..241) -
`maple_sega_vmu` writes the same number for an unformatted card.

## Where the port's boot differs from the reference's (2026-10-28)

The reference's boot runs the REIOS' *exec server*: the log of a clean
Flycast boot carries 23,480 "GDROM: HLE EXEC_SERVER" lines and thousands of
"GET_CMD_STAT" polls, and the drive's sector reads follow (the disc image is
read from the first seconds of the run).  The port's boot starts at the
game's own entry (0x8C004000) with only the 1ST_READ image in RAM, so the
REIOS - the component that reads the disc and loads the game's files - never
runs: the port's GD-ROM model is attached, but nothing asks it for anything
(`VF3_GDTRACE` prints nothing), and the game's textures never arrive (the
512x512 texture the Tile Accelerator samples, at 0x54D880, is empty).
See docs/re/boot_vram_traffic.md.

