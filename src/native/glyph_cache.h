/* glyph_cache.h - native port of the HUD text layer's sprite pool
 * (0x8C0C1FBA), operating on the `vf3_native_aim` context.
 *
 * See glyph_cache.c and docs/re/native_glyph_cache.md. */
#ifndef VF3_NATIVE_GLYPH_CACHE_H
#define VF3_NATIVE_GLYPH_CACHE_H

#include "aim_math.h"

/* Run 0x8C0C1FBA.  r4 = cursor word, r5 = key, r6 = layer, r7 = packed cell
 * (0 = take it from the cursor); the two caller stack words at sp0+0 / +4 are
 * the packed texel offsets and the flag bits.  Returns r0 = the sprite object
 * inside the pool entry, or 0.  The five guest callees (the retirement
 * self-call, pool_alloc, tex_cell_load, sprite_rect_a, sprite_rect_b) are
 * inlined as plain-C helpers; see docs/re/native_glyph_cache.md. */
void vf3_native_glyph_cache(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_GLYPH_CACHE_H */
