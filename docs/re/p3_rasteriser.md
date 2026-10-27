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
