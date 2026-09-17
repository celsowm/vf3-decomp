# TEX (VF3 texture payload)

Status: **format solved (v1)** — direct decoded image produced from
`MKAO_AKI.TEX` (AKI face/fur/eyeball visible in output).

## Layout
- No header — raw texture data only
- Pixel format: **RGB565** (little-endian u16 per texel)
- Storage order: **PVR twiddle / Morton order** at tile granularity
  (decoded result shows 32x32-tile sub-structure: per-tile twiddles with
  their own sub-layouts; refinement pending)
- Sizes are bitmap areas; example sizes observed: 256x304 (MKAO_AKI),
  256x288 (MKAO_WOL), 256x378 (ST01), 2048-byte ROB_ALP (alpha tile)

## Tool
`tools/tex_peek.py`:
- `try_tex(path, w, h, '565'|'5551', twiddle=True)`
- `write_png(path, w, h, rgb)` — stdlib PNG writer

Decoded sanity images in `extract/assets/tex/` (git-ignored).

## Next
- tile-level twiddle refinement (block size binding from POL side-table?)
- RGBA5551 vs RGB565 auto-detection (alpha detection)
- stage TEX often contain skybox walls - test CP_SKY series too
