# The PVR2's area 1: the 64 bit path and the 32 bit path (2026-10-27)

The Dreamcast shows its texture memory twice, and the two windows do not hold
the same bytes at the same offsets.  The port had them the other way round, so
the guest's texture uploads landed in the wrong place.

## The two windows

| window | view | the guest's address |
|---|---|---|
| `0x04000000` (mirror `0x06000000`) | the 64 bit path: the banks one after the other, the view the Tile Accelerator samples | linear |
| `0x05000000` (mirror `0x07000000`) | the 32 bit path: the banks interleaved, so only half of every 64 bit word is reachable | interleaved |

The interleaving is the arithmetic in `pvr_map32`
(`tools/emu/flycast/core/hw/pvr/pvr_mem.cpp`):

```c
static u32 pvr_map32(u32 offset32)
{
	//64b wide bus is achieved by interleaving the banks every 32 bits
	const u32 static_bits = VRAM_MASK - (VRAM_BANK_BIT * 2 - 1) + 3;   // 3
	const u32 offset_bits = (VRAM_BANK_BIT - 1) & ~3;                   // 0x3ffffc
	u32 bank = (offset32 & VRAM_BANK_BIT) / VRAM_BANK_BIT;
	u32 rv = offset32 & static_bits;
	rv |= (offset32 & offset_bits) * 2;
	rv |= bank * 4;
	return rv;
}
```

With `VRAM_BANK_BIT = 0x400000`, a 32 bit path offset below 4 MB lands at the
linear offset `2 * offset`, and the window's second half (offset >= 4 MB)
lands at `4 + 2 * (offset - 0x400000)` - the other half of each 64 bit word.

The reference emulator maps the windows the same way
(`tools/emu/flycast/core/hw/sh4/sh4_mem.cpp`, `map_area1`):

```c
	//Lower 32 mb map
	//64b interface
	addrspace::mapBlock(&vram[0], 0x04 | base, 0x04 | base, VRAM_MASK);
	//32b interface
	addrspace::mapHandler(area1_32b, 0x05 | base, 0x05 | base);
```

`map_area1` is called with `base = i << 5` for `i = 0..7`, so the windows are
mirrored every 0x20000000 (0x04000000, 0x24000000, ... and 0x05000000,
0x25000000, ...).  The port's `address & 0x1FFFFFFF` fold reproduces that: it
maps 0x24000000 onto 0x04000000 and 0x25000000 onto 0x05000000.

## The boot proves which way round it is

`VF3_DEVLOG=1` over the first 30 frames of the disc boot
(`build/vf3sdl --state build/boot.state --entry 0x8c004000 --gdi rom/vf3.gdi
--frames 30 --headless`) shows the guest writing **2,104,928 words**
sequentially from `0x05000000` upwards - 8.4 MB, the size of the VRAM.  The
values are almost all zero (2,097,564 of them): the game is clearing the
texture memory, and the boot is still in that phase at frame 150.

The Tile Accelerator of those frames draws one full-screen sprite whose
texture control word is `0x000A9B10`, i.e. a 512x512 ARGB1555 texture at the
**linear** VRAM address `0x54D880`:

```
prim 1825: sprite list 2 (translucent) pcw a2000009 tsp 949024f6 tcw 000a9b10
            -> tex 0054d880 fmt 0 vq 0 mip 0 512x512
```

The two mappings put that texture at different places in the guest's write
range:

| mapping | the guest address that holds the texture | inside the observed range `0x05000000..0x05807FC0`? |
|---|---|---|
| interleaved (correct) | `0x05000000 + 0x54D880 / 2` = `0x052A6C40` | yes |
| linear (wrong) | `0x05000000 + 0x54D880` = `0x0A54D880` | no - never written |

So the guest uploads its textures through the **32 bit path**, and the Tile
Accelerator samples the **linear** view: the interleaving is what makes the
two meet.

The guest's write pattern agrees: the pointer tables it writes appear twice,
at `0x051683E4` and at `0x055683E4` - exactly 0x400000 apart, the bank bit.
Under the interleaved mapping those two addresses are the two halves of the
same 64 bit words.

## The store queue

The store queue's flush is the other way into the VRAM.  The reference
(`tools/emu/flycast/core/hw/sh4/storeq.cpp`) computes the destination as
`(area << 26) + (SQ address & ~0x1f)`, and then

* an area 1 destination goes through the normal memory write path - the P2
  mirror of the **64 bit path**, so it is linear;
* an area 4 destination goes to `TAWriteSQ`
  (`tools/emu/flycast/core/hw/pvr/pvr_mem.cpp`), where `address & 0x01FFFFE0`
  picks the stream: below 0x800000 the polygon stream, below 0x1000000 the YUV
  converter, and from 0x1000000 the **VRAM**, with the 32 bit or the 64 bit
  path chosen by `SB_LMMODE0`/`SB_LMMODE1` (0x005F6884 / 0x005F6888).

The port's `vf3_matrix_pref` (`src/fight/matrix_family.c`) computes the
destination as `(QACR area << 26) | (SQ address & 0x03FFFFE0)`, so it loses
the high bits of the store queue's address.  For area 1 that does not matter
(the destination is the 64 bit path either way); for area 4 the reference's
"VRAM write" case (a store queue address from 0x1000000 up) is unreachable,
because the port's 22 bit mask keeps the offset below 0x200000.  **Known
divergence**, not reached by this game's boot: the game uploads its textures
with plain stores to `0x05000000`.

## What the port does now

* `src/render/pvr2.c`: `vf3_pvr2_vram_store_n` picks the view from the
  address - the 32 bit path for `0x05000000` and `0x07000000`, the 64 bit path
  for `0x04000000`, `0x06000000` and the Tile Accelerator's own window
  (`0x11000000` / `0x13000000`, whose path the system bus' long mode bits
  select).
* `src/fight/native_tick.c`: a plain store into `0x04000000..0x07FFFFFF`
  reaches the VRAM.  Before this, only `0x04000000..0x04FFFFFF` did, so the
  game's whole texture upload was dropped.
* `src/fight/native_tick.h` / `src/host/sdl3_host.c`: the long mode bits
  (`SB_LMMODE0` at 0x005F6884, `SB_LMMODE1` at 0x005F6888) are handed to the
  model.

The attract fight still matches the reference (95.48 % of the pixels within 24
levels against `extract/analysis/p1/probe.raw`, frame 154), so the change does
not disturb the renderer.

## Diagnostic

`VF3_VRAMLOG=1` prints where the guest's texture writes go, by the megabyte of
the address they used and by the path they came through (a plain store or the
store queue's flush).
