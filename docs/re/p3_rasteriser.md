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

Not closed - the pixel diff against the reference is not meaningful yet:

* the reference framebuffer in the VRAM dump and the TA frame are not aligned
  (the best pairing is ~34% of pixels within 24 levels), and the sky texture
  in the dump (1024x1024 VQ at 0x264000) is a dusk sky with no pink at all,
  whereas the reference frame shows a pink sky - so either the texture is
  rewritten between the dump and the render or the sprites are not what we
  think they are.  The reference's own raw frame for 300 (`frames2/`) is
  truncated and not 24-bit RGB;
* no fog, no per-pixel LOD, no modifier volumes, no YUV, no user clip;
* translucent-list sorting and the HUD sprites are unchecked.
Next step: have the instrument dump the framebuffer *with* the TA frame in one
run, so each frame has its own aligned reference.
