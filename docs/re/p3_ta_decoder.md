# P3: the Tile Accelerator's command stream

The first half of the PVR2 model: our own decoder for the command stream the
game hands the Tile Accelerator (TA), and the port's model of where that
stream lands.

## What the port hands the TA

The game builds its display list in the SH-4's store queue and bursts it into
the PVR2's own memory; the TA reads the list back out of that memory when the
game runs it.  The port keeps that memory (`src/render/ta_stream.h`), so a
burst that is written twice leaves the *second* one's words behind - the way
the hardware's would.

The bursts are the store queue's `PREF`: a 32-byte burst to
`(QACRn.AREA << 26) | (Rn & ~0x1F)`.  With `AREA = 4` that is
`0x10000000`, the TA's list area.  The port splits the burst by its target the
way the hardware does:

| target | what it is |
|---|---|
| below 8 MB | the TA's polygon stream (the display list) |
| below 16 MB | the YUV converter |
| above that | the VRAM |

Only the first is a display command, so only the first is kept; the other two
are not modelled yet (the VRAM is where the textures live - P3's next piece).

**The store queue's own behaviour is visible in the capture** (`VF3_SQLOG=1`
prints the stores and the bursts).  The game writes the list at a moving
address in the queue (`0xE0000000`, `0xE0000020`, `0xE0000040`, ...), the
queue's two halves alternate, and the first burst of a frame carries the
queue's *stale* words: the game stores one word and bursts before it has
filled the queue.  The burst that follows overwrites the same address, which
is why the list has to be read out of the memory and not out of the burst
sequence.

## The command stream's format

`src/render/ta.c` is our decoder.  The stream is a sequence of 32-byte
blocks; the first word of a block is its **parameter control word** (PCW),
whose top three bits say what the block is:

| PCW's top three bits | block |
|---|---|
| `000` | end of list |
| `001` | user tile clip (a rectangle in tile units) |
| `010` | object list set |
| `100` | polygon or modifier volume (the primitive's parameter block) |
| `101` | sprite (the primitive's parameter block) |
| `111` | vertex parameter (one vertex of the primitive being built) |

The PCW's low seven bits are the *object control*: textured or not, how the
colour is given (packed `0xAARRGGBB`, four floats, or an intensity), one or
two volumes, and whether the texture coordinates are 16 bit.  Those bits
select both the size of the parameter block (32 or 64 bytes) and the layout
of the vertices that follow.

The parameter block of a polygon holds the ISP/TSP instruction word, the TSP
instruction word, the texture control word, the base and offset colours and
(for the 64-byte layouts) the four face colours.  A sprite's parameter block
is 32 bytes and is followed by 64 bytes of vertex data: four corners of a
plane, with three pairs of 16-bit texture coordinates at the end.

The vertices are 32-bit floats: the position is three of them (the third is
`1/w`, the reciprocal the TA divides by) and the texture coordinates are two
floats or two 16-bit halves.

## Where it stands

The decoder parses the stream (`build/vf3ta <file.bin>` prints what a captured
stream holds) and the port runs it on the list it read back from the TA's
memory.  Two things are still open:

* **where the list starts.**  The game runs the list from an address the port
  does not see yet: the PVR2's register writes do not reach the port's device
  hook.  The PVR2's registers are visible twice - cached at `0x8C000000` and
  uncached at `0x5F800000` - and the port used to mask the address to 29 bits,
  which folded the cached view onto the RAM; that is fixed now
  (`vf3_matrix_write`/`vf3_matrix_read` in `src/fight/matrix_family.c`), but
  the fight scene still writes no PVR2 register the port can see, so the list
  is still located by the bursts alone.
* **the rasteriser.**  Nothing is drawn yet: the model counts the display
  commands and the pixels stay at zero.  The rasteriser needs the list's
  extent, the VRAM (the textures) and the frame buffer's configuration.

## The decoder's own notes

* The vertex layouts the decoder knows are listed in `src/render/ta.h`
  (`VF3_TA_V_*`).
* `vf3_ta_vertex_type()` maps the object control onto a layout, and
  `vf3_ta_param_is_64()` onto the parameter block's size.
* The decoder is deliberately separate from the rasteriser: it hands the
  primitives over as plain data (`vf3_ta_prim`), so the rasteriser can be
  written and tested against the decoder without either knowing about the
  other's internals.
