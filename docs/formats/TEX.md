# TEX (VF3 texture payload)

Status: descriptor-driven decode works for AKI, JAC, and the ST01 stage. The
native C decoder reads each descriptor from its companion POL file and
produces 0xAARRGGBB pixels. The native offscreen render gate loads all three
packages through the VFA archive.

## Layout
- `.TEX` has no file header; it is a sequence of texture payloads.
- The companion POL descriptor supplies dimensions, pixel format, data
  layout, and byte offset. Supported pixel formats follow the local PVR
  rasterizer: 0 = ARGB1555, 1 = RGB565, and 2 = ARGB4444.
- Data layout 1 is square twiddled 16-bit pixels. Data layout 3 is VQ: a 2 KiB
  codebook of 256 2x2 blocks followed by one byte per texture block. The
  checked ST01 512x512 VQ texture occupies 67,584 bytes, confirming a
  non-mipmapped payload.
- The decoder returns straight 0xAARRGGBB pixels and checks compressed bounds
  before reading either layout. Mipmapped, rectangular, palette, and bump-map
  forms remain unsupported.

## Tool
`src/media/pvr_texture.c` reports each layout's required payload size and
decodes a `PolTextureDesc` from a `.TEX` payload. `tests/pol_asset_tables_replay.c`
checks AKI/JAC descriptors, and `tests/native_view_replay.c` exercises the VQ
decoder against all ST01 textures while drawing the extracted scene.

`tools/tex_peek.py` is an older whole-file format probe. Its guessed image
dimensions and color mode are not the authority for descriptor-backed assets.

## Open
- Compare the native render against a captured game frame and fix the model
  transforms, UV conventions, and draw ordering.
- Decode other PVR layouts needed by additional stages and effects.
