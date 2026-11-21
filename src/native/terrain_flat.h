/* terrain_flat.h - native port of 0x8C068DE4 (terrain_flat), operating on the
 * `vf3_native_aim` context.  See terrain_flat.c and docs/re/native_terrain_flat.md. */
#ifndef VF3_NATIVE_TERRAIN_FLAT_H
#define VF3_NATIVE_TERRAIN_FLAT_H

#include "aim_math.h"

/* Run 0x8C068DE4 (terrain_flat).  A self-contained FP leaf (call-free, no
 * stack frame).  r4 -> a 3-float normal block, fr4/fr5 = x/z: writes the up
 * normal (0, 1, 0) and returns 0, or -0.5 when |x| or |z| exceeds 6 (the
 * stage edge) -> fr0.  The constants are read from the literal pool at
 * 0x8C068E5C (6.0) and 0x8C068E60 (-0.5).  See docs/re/native_terrain_flat.md. */
void vf3_native_terrain_flat(vf3_native_aim *a);

#endif /* VF3_NATIVE_TERRAIN_FLAT_H */
