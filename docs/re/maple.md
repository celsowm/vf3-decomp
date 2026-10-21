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

## Independent controller ports (2026-10-21)

`vf3_maple_dma_bus` now accepts a stable input snapshot for four main ports,
with independent connection bits and pad states. The SDL host produces two
samples for ports A/B; the runtime must latch them at the guest polling
boundary. Main-unit addresses include their port bits, and sub-units remain
absent. The old `vf3_maple_dma` wrapper preserves the one-pad capture API.

Invalid list bounds, mismatched descriptor/frame lengths, unaligned accesses,
short receive buffers, unsupported DMA patterns and unterminated 64-block
lists return explicit failures. No response is partly written on a short
buffer. The boot harness stops instead of signalling Maple completion after
such a failure. Other DMA patterns and VMUs are still unimplemented.

ROM-free tests cover all four port addresses, different simultaneous inputs,
disconnect without moving player 2, RAM aliases and malformed lists. The SDL
test feeds virtual-controller and keyboard events into two guest GETCOND
requests and verifies the returned wire bytes. This establishes the input
transport, not two-player game acceptance or calibrated device timing.
