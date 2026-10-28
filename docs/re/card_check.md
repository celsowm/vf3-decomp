# The memory card check: what the game asks, what the port answers, what is left

The game's SDK refuses to start when the card it finds has fewer free blocks
than it needs, and the boot sits on a message screen:

> A Memory Card or enough free memory blocks for saving could not be found.
> 12 empty blocks are required.  Please put a Memory Card which has more
> than 12 blocks into Expansion Socket 1 on your controller at port A.

This note records what the game asks, what the port answers, and the one
step that still does not go through.

## What the game asks (the port's Maple log, `VF3_MAPLELOG=1`)

```
maple: block at 0c2c4518 head 00000000 recv 0c2b8800 frame 00000101
maple: block at 0c2c4420 head 00000002 recv 0c2b8800 frame 0200010a [02000000] [00000000]
maple: block at 0c2c3820 head 00000002 recv 0c2b7c00 frame 0200010b [02000000] [ff000000]
maple: block at 0c2c4420 head 00000002 recv 0c2b8800 frame 0200010b [02000000] [fe000000]
maple: block at 0c2c3820 head 00000002 recv 0c2b7c00 frame 0200010b [02000000] [fd000000]
... (0xfc, 0xfb, 0xfa, 0xf9)
```

- `0x01` (device request) to the recipient `0x01` - the card in expansion
  socket 1;
- `0x0A` (media info) with the function code `MFID_1_Storage`;
- `0x0B` (block read) with `MFID_1_Storage` for the blocks 255 (the root),
  254 (the FAT) and 253..249 (the directory chain).

The port's answers follow the reference field by field
(`core/hw/maple/maple_if.cpp`, `maple_devs.cpp`), and the card's data is
**byte identical** to the reference's own card:

```
root identical: True
fat  identical: True
```

(the reference's card is `tools/emu/flycast-ref-build/data/vf3.gdi_vmu_save_A1.bin`,
which is the default VMU image `maple_devs.cpp` carries as a zlib blob -
`tools/maple_vmu_default.py` writes it out, `tools/maple_vmu_regions.py` lists
the regions that are not zero).

## Three bugs that had to be fixed first

1. **The cards are at the expansion slots, which are ports 0 and 1.**
   `core/hw/maple/maple_cfg.cpp`'s `createDreamcastDevices()` creates
   `MapleExpansionDevices[bus][0]` at port **0** and `[bus][1]` at port **1**,
   so `maple_GetAttachedDevices()` returns the bits 0 and 1 - the mask is
   **0x03**, not 0x06.  The port's mask of 0x06 told the game that the slots
   2 and 3 held a card and that socket 1 was empty, so the game stopped
   enumerating and never asked about the card at all.
2. **The port read the block number out of one byte.**  The block number is
   in the *whole* word that follows the function code, read the way the wire
   carries it; the port took `ra[0]`, the word's low byte, and answered every
   block read with the block 0.  The game then saw a root block of zeros and a
   FAT of zeros.
3. **The media info follows the card, not a fixed table.**  The reference
   answers `MDCF_GetMediaInfo` with the card's own system area (the root
   block's 24 bytes at +0x40) whenever that area's first word is not 0xFFFF -
   which is the case for the reference's card, whose first word is 0x00FF.

With the three fixed the game reads the root block, the FAT and the directory
chain, and the screen says "12 empty blocks are required" instead of "the
memory card has not been formatted" - so the card is found now.

## What is still missing

The driver records the answer but does not attach the card.  In the mpdrv's
record array at `0x0C19C6A0` (stride 76) the byte at +0 stays 0 ("attached")
and the word at +8 stays 8; the drive table at `0x0C1B34D8` (stride 0x148)
stays empty.

The check itself is at the run address `0x0C04517E` (the image's copy of the
load address `0x8C04517E`): the driver compares a 32-bit word against
**0xFFFFFF00** and **0xFFFFFFFF** - the "no device" answer and a second
status - and takes the word from a per-unit structure:

```
0C04517E  mov.w @(disp,PC),r1     ; r1 = 0xFFFFFF00 (-0x100)
0C045180  cmp/eq r1,r0
0C045182  bt/s 0x0c04518a
0C045184  mov #0,r7               ; anything else: the unit is not accepted
0C045186  cmp/eq #-1,r0           ; 0xFFFFFFFF is accepted
0C045188  bf 0x0c0451a8
```

The word comes from the structure at `0x0C1A0D24 + 0x0D24 + the unit index`
through the table at `0x0C0CD918`; in the port's RAM dump the per-unit entry
at `0x0C1A1A90` holds the response code **0x05** - the driver's copy of the
DEVINFO answer - so the answer arrives and is not accepted.

The port's answer is the reference's answer, byte for byte:

| field | the port | the reference |
|---|---|---|
| response code | 0x05 | 0x05 (`MDRS_DeviceInfo`) |
| sender | the request's sender | the request's sender (`RawDma`) |
| recipient | 0x01 | 0x01 |
| length | 28 words | 28 words (112 bytes) |
| function code | 0x0E000000 | `MFID_1_Storage\|MFID_2_LCD\|MFID_3_Clock` |
| capabilities | 0x403F7E7E, 0x00100500, 0x00410F00 | the same three words |
| area / direction | 0xFF / 0 | the same |
| name / brand | "Visual Memory" / Sega | the same (`wstr` pads with spaces) |
| standby / max | 0x007C / 0x0082 | the same |

`tools/maple_card_header_probe.py` forces the reply's header
(`VF3_MAPLE_HDR=<hex>`) and watches what the driver does with it:

| the forced header | the driver's record |
|---|---|
| 0x1C010005 (the port's, and the reference's) | `[0, 0, 8, 17, 1, 0]` |
| 0xFFFFFFFF (the "no device" answer) | `[0, 0, 0, 0, 0, 0]` |
| 0x1CFF0005 (the sender byte 0xFF) | `[0, 0, 8, 17, 1, 0]` |
| 0x1C00FF05 (the recipient byte 0xFF) | `[0, 0, 8, 17, 1, 0]` |
| 0x1C010006 (the status-all code) | `[0, 0, 0, 0, 0, 0]` |

So the driver *reads* the header and wants the response code 0x05 - which is
what the port sends - and the sender and the recipient bytes make no
difference.  The word the check at `0x0C04517E` compares is therefore not the
header but something the driver derives from the answer, and that derivation
is what still has to be found.

## The RAM the driver's tables live in

The mpdrv's record array is at `0x0C19C6A0` and the drive table at
`0x0C1B34D8` - both above the 16 MiB the Dreamcast's RAM holds.  The
reference folds them onto the lower half: `mapBlockMirror()` maps the RAM
with the mask `RAM_SIZE - 1` (24 bits), so `0x0C19C6A0` is the physical
`0x0C019C6A0`.  The port folds the same way (`0x0c000000 | (addr & 0x00ffffff)`
in `vf3_matrix_read` / `vf3_matrix_write`), so the driver's tables land where
the reference puts them - and they land on top of the game's own data there,
which is what the reference does too.

The reference's captured state (`extract/analysis/p1/frm_keep/st.bin.000280`,
a 16 MiB window from the attract mode) shows the same folded address holding
the game's data and not the driver's record array - the driver had already
cleared it by then.  The port's boot state (a fresh boot, the driver just
asked) holds the record the port's run produced: `[0, 0, 8, 17, 1, 0]`.

## The probes

- `tools/maple_card_state.py <ram dump>` - the mpdrv tables in a RAM dump.
- `tools/maple_card_probe.py` - the record with different media-info answers.
- `tools/maple_card_count_probe.py` - the record with different root blocks
  (the count does not follow the media info).
- `tools/maple_card_header_probe.py` - the record with forced reply headers
  (`VF3_MAPLE_HDR=<hex>` overrides the card's reply header).

## Where to look next

The chain the check walks, with the port's RAM dump in brackets:

```
r6  = 0x0C1A0D24            (a constant in the image)
r5  = *r6                   [0x0C19FC30 - the driver's own block]
r0  = *r6 + 0x0D24 + (96 * (1 - the byte at *r6 + 0x31E)) & 0xFF
                              [0x0C1A09B4 - the array of the answers]
r2  = the word at (0x0C0CD918 + the unit)   [0, 6, 12, 18, 1, 0, ...]
r1  = r0 + r2 * 4
r4  = *r1                   [0 - the answer's pointer is never stored]
r0  = *r4                   [the word the check compares]
```

The array at `0x0C1A09B4` is **all zeros** in the port's run: the driver never
stored a pointer to the card's answer there, even though it copied the
response code 0x05 into the per-unit entry at `0x0C1A1A90`.  The controller's
answer pointer *is* stored (at `0x0C198308`, pointing at the reply buffer
`0x0C2B7800`), so the store happens for the pad and not for the card - that
is the step to find.

