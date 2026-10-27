# P3: the rasteriser (2026-10-27)

`src/render/pvr2.c` rasterises a decoded TA frame against the reference's own
PVR2 state (`tests/pvr2_render.c` -> `build/vf3pvr`; `tools/pvr2_render_frame.py`
renders and diffs a frame, `tools/ta_split.py` cuts one frame out of a capture).

What the frame at marker 300 of the attract demo shows now: geometry, depth,
the fighters' VQ RGB565 / ARGB4444 textures, the stone floor and the sunset
horizon all land where the reference has them (`VF3_PVR_RAWTEX=1` shows the
textures without shading).

Faults found and fixed this session:

* texels are **little-endian** in the VRAM (the first version read them
  big-endian, which turned every texture into noise);
* **intensity mode 2** (colour type 3) has no face colour of its own - the TA
  scales the face colour of the last mode 1 header; without it every
  mode-2 polygon (288 of 504 in frame 300) came out black;
* a flipped axis **mirrors every other repeat**, it does not mirror always;
* mipmap offsets, scan-order (linear/stride) textures and palette textures
  (4/8 bit, PAL_RAM_CTRL) are implemented, but frame 300 uses none of them
  (formats are RGB565/ARGB4444/ARGB1555, VQ or twiddled), so they are untested.

Alignment: TA frame 297 against the dump at marker 300 gives 90.9% of pixels
within 24 levels (the display lags the TA by about three frames).  Still open:
the stone's trilinear/mip detail, the fighters' edges, the exact fog density
exponent (the sky is ~2 levels dark), modifier volumes, YUV, user clip.

## The host end to end (state of 2026-10-27)

`build/vf3sdl --state extract/analysis/p1/frm/st.bin.015800 --entry 0x8c059b48
--frames N --headless` runs the game from a reference frame state (the default
entry is the scheduler tick, which needs a tick capture and ends in an
"unowned call at 1ead0000").  It runs, but the TA streams it produces are not
yet the reference's: frame 1 has 20,997 blocks (the reference's frame 297 has
18,198), frame 4 has 78,747 blocks with 22,048 skipped words, and the vertex
range is +-1e38 - the port's DMA-2/TA hand-off (`dma2_ch2_transfer`, which now
passes every copied block) or the frame events are submitting lists more than
once.  The renderer is ready for them; the stream is the next thing to pin,
by diffing the port's frame-1 stream block for block against the reference's.

### The host's stream was byte-swapped (fixed)

`dma2_ch2_transfer` built each TA word from the RAM bytes big-endian; the
SH-4's RAM is little-endian, so every block the DMA handed over was scrambled
(that was the "garbage vertices", the 1e38 ranges and the 22,048 skipped
words).  With the order fixed the host's frame 1 parses with 0 skipped words
and 18,577 blocks (the reference's frame 297 has 18,198), and

    vf3sdl --state extract/analysis/p1/frm_keep/st.bin.000280 \
      --entry 0x8c059b48 --frames 18 --headless \
      --pvr-state <ref pvr dump> --dump-frame out.ppm

renders the attract fight - the game's own C code, our TA decoder, our
rasteriser - with the HUD, the fighters and the stage.  (The textures come
from a VRAM dump taken at a different moment, so some stage textures are
wrong: the game does not fill the VRAM through the port yet.)
