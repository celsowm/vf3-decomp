# The memory card check: what the game asks, what the port answers, what is left

The game's SDK refuses to start when the card it finds has fewer free blocks
than it needs, and the boot sits on a message screen:

> A Memory Card or enough free memory blocks for saving could not be found.
> 12 empty blocks are required.  Please put a Memory Card which has more
> than 12 blocks into Expansion Socket 1 on your controller at port A.

This note records what the game asks, what the port answers, and the one
step that still does not go through.

**Correction (2026-10-30).**  The first version of this note carried three
measurements that were wrong, and one that was right for the wrong reason.
What the measurements actually show:

| the note said | what the measurement says |
|---|---|
| "the driver never stored a pointer to the card's answer in the array at `0x0C1A09B4`" | the array **is** filled: the reply pointers sit at `0x0C1A0C70` (`0x0C1A0C10` for the other bus), holding `0x0AC2B8400` (the controller), `0x0AC2B8800` (the card) and `0x0AC2B8C00` (the "no device" answer).  The address in the note came from a wrong base: the array is `block + 0x0FE0 + 96 * (1 - the byte at block + 0x10AC)`, not `block + 0x0D24 + ...` |
| "the drive table at `0x0C1B34D8` stays empty" | its first record is filled, and it is **byte for byte the reference's** (`00010000 00000000 00000101 00010000 000d0001 00000020 ...`) |
| "the media info follows the card, not a fixed table" | the reference answers with Flycast's **fixed table**: `maple_sega_vmu::dma` reads the card's own system area only when the first *halfword* at `root + 0x40` is `0xFF`; the card starts with `0x00FF`, so the fixed table is what the guest sees (the two differ in the volume icon and in the last word) |
| "the check compares the answer's header" | it compares a word the *driver* keeps per unit; the per-unit state at `block + 40 + unit * 44` holds it in word 2 |

## What the game asks (the port's Maple log, `VF3_MAPLELOG=1`)

```
maple: block at 0c2c4518 head 00000000 recv 0c2b8800 frame 00000101
maple: block at 0c2c4420 head 00000002 recv 0c2b8800 frame 0200010a [02000000] [00000000]
maple: block at 0c2c3820 head 00000002 recv 0c2b7c00 frame 0200010b [02000000] [ff000000]
maple: block at 0c2c4420 head 00000002 recv 0c2b8800 frame 0200010b [02000000] [fe000000]
maple: block at 0c2c3820 head 00000002 recv 0c2b7c00 frame 0200010b [02000000] [fd000000]
... (0xfc, 0xfb, 0xfa, 0xf9, 0xf8)
```

- `0x01` (device request) to the recipient `0x01` - the card in expansion
  socket 1;
- `0x0A` (media info) with the function code `MFID_1_Storage`;
- `0x0B` (block read) with `MFID_1_Storage` for the blocks 255 (the root),
  254 (the FAT) and 253..248 (the directory chain).

The card's data is **byte identical** to the reference's own card:

```
root identical: True
fat  identical: True
```

(the reference's card is `tools/emu/flycast-ref-build/data/vf3.gdi_vmu_save_A1.bin`,
which is the default VMU image `maple_devs.cpp` carries as a zlib blob -
`tools/maple_vmu_default.py` writes it out, `tools/maple_vmu_regions.py` lists
the regions that are not zero).  The card has 241 free blocks (the FAT marks
them `0xFFFC`), so the "12 empty blocks" the message asks for are there.

## What the reference does (the emulator's own log)

`tools/emu/flycast-ref-build/flycast.log` holds the reference's Maple
traffic; the card's part reads:

```
00:14:542 VMU A1 GetMediaInfo storage
00:14:542 VMU A2 GetMediaInfo storage
00:14:555 VMU A1 block read: Block 255 addr 1fe00 len 512
00:14:555 VMU A2 block read: Block 255 addr 1fe00 len 512
00:14:569 VMU A1 block read: Block 254 ...
00:14:569 VMU A2 block read: Block 254 ...
...
00:14:772 VMU A1 block read: Block 241 ...
00:14:772 VMU A2 block read: Block 241 ...
00:14:782 VMU A1 LCD write
00:14:782 VMU A2 LCD write
```

Three things follow from it:

1. **The reference reads every block of the chain, 255..241** - thirteen
   directory blocks, the number the media info names (`number_of_info_blocks`
   = 0x0D).  The port stops at 248.
2. **The reference talks to *two* cards** - A1 (recipient `0x01`) and A2
   (recipient `0x02`) - and asks both for the *same* block.  The port's guest
   only ever asks `0x01`; its two transfer lists (`0x0C2C4420` and
   `0x0C2C3820`, the same two the reference uses) get the odd and the even
   block numbers instead.
3. **One block per frame in both** (the reads are 7..20 ms apart, a frame
   being 16.67 ms), so the port's rate is right - it just stops early.

The reference's card ends with an **LCD write**, whose answer is a plain
reply (`MDRS_DeviceReply`, 0 words).  That is the word the reference's
per-unit state carries in word 2 (`0x00010007`); the port's state carries the
last block read instead (`0x82010008`), because the port's guest never gets
that far.

## The driver's state is not the problem

Measured on the port's frame 30 and on the reference's frame 40 (the
reference's capture `extract/analysis/p1/frm_keep/st.bin.000040` is the
*boot*: its Maple buffers are still zero in frame 0 and filled in frame 40):

| what | the port | the reference |
|---|---|---|
| the drive table `0x0C1B34D8` (record 0) | `00010000 00000000 00000101 00010000 000d0001 00000020 ...` | the same |
| the attached flags `block + 0x0F90` (port * 6 + unit) | `82 69 0 0 0 0 / 82 0 0 0 0 0 / 0 ... / 0 ...` | the same |
| the masks `block + 0x0FB8` | `00000001 ac2c3820 ac2b7800 ac2c3820` | the same |
| the FAT copy at `0x0C198C82` (512 bytes) | identical, byte for byte | identical |
| the per-unit state, unit 0 (the controller) | `00000101 09000909 03230008 ...` | the same |
| the per-unit state, unit 6 (an empty port) | `00000000 01000101 ffffffff ...` | the same |
| the per-unit state, unit 1 (the card), word 1 | `0b0b0000` | `00000000` |
| the per-unit state, unit 1 (the card), word 2 | `82010008` (the last block read) | `00010007` (the LCD write's reply) |
| the per-unit state, unit 1 (the card), word 6 | `00000021` | `00000000` |

The driver's own state agrees; only the card's unit state says where the
two runs stopped.

## Two fixes that came out of this

### The media info (Flycast's table, not the card's)

`maple_sega_vmu::dma`, `MDCF_GetMediaInfo`, `MFID_1_Storage`:

```cpp
w32(MFID_1_Storage);
if (*(u16*)&flash_data[0xFF * 512 + 0x40] != 0xFF) {
    /* "unformatted state": the fixed table */
    w16(0xff); w16(0); w16(0xFF); w16(0xfe); w16(1); w16(0xfd); w16(0xd);
    w8(0); w8(0); w16(0xc8); w16(0x1f); w32(0);
} else {
    wptr(flash_data + 0xFF * 512 + 0x40, 24);
}
```

The card's first halfword is `0x00FF`, which is *not* `0xFF`, so the
reference answers with the fixed table - and the table differs from the
card's own area in the volume icon (`0` against `5`) and in the last word
(`0` against `0x8000`).  `src/sys/maple_hle.c` now answers the way the
reference does.

### The Maple answers at the transfer's start, and SB_MDST exists

The guest writes the transfer list to `SB_MDSTAR` (0x005F6C04) and starts it
by writing `SB_MDST` (0x005F6C18).  The reference runs the transfer *there*
(Flycast's `maple_SB_MDST_Write` -> `maple_DoDma`), and `SB_MDST` reads back
as 1 while the transfer is in flight and 0 once the answer is in the guest's
memory.  The guest polls it twice per transfer.

The port answered the list at the **next vblank** and modelled `SB_MDST` as
always zero, so the guest's poll never waited: it read the reply buffer
before the model had written it.  `src/fight/native_tick.c` now answers the
list in the `SB_MDST` write and keeps the register's value, and the
Maple-end interrupt goes out with the answer (as in the reference).

With both fixes the guest reads one block further (248) and the card's
media info is the reference's.

## What is still missing

The guest never asks the second card (recipient `0x02`) and stops walking
the directory chain at block 248 - the reference walks it to 241 and then
writes the card's LCD.

The chain itself is not the problem: the FAT copy the guest keeps
(`0x0C198C82`) is byte for byte the reference's, and the chain it names
(253 -> 252 -> ... -> 241) is the one the port reads.  So the guest stops
for a reason of its own, and the next thing to look at is the SDK's card
service: the function that reads the chain (the caller of the transfer
builder at `0x0C036132`, whose PR is `0x0C043CAA`) and the limit it applies.

The probes:

- `tools/maple_card_state.py <ram dump>` - the mpdrv tables in a RAM dump.
- `tools/maple_card_probe.py` - the record with different media-info answers.
- `tools/maple_card_count_probe.py` - the record with different root blocks
  (the count does not follow the media info).
- `tools/maple_card_header_probe.py` - the record with forced reply headers
  (`VF3_MAPLE_HDR=<hex>` overrides the card's reply header).

## The RAM the driver's tables live in

The mpdrv's record array is at `0x0C19C6A0` and the drive table at
`0x0C1B34D8` - both above the 16 MiB the Dreamcast's RAM holds.  The
reference folds them onto the lower half: `mapBlockMirror()` maps the RAM
with the mask `RAM_SIZE - 1` (24 bits), so `0x0C19C6A0` is the physical
`0x0C019C6A0`.  The port folds the same way (`0x0c000000 | (addr & 0x00ffffff)`
in `vf3_matrix_read` / `vf3_matrix_write`), so the driver's tables land where
the reference puts them - and they land on top of the game's own data there,
which is what the reference does too.
