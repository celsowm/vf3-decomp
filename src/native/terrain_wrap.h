/* terrain_wrap.h - native port of 0x8C068D54 (terrain_wrap), operating on the
 * `vf3_native_aim` context.  See terrain_wrap.c and docs/re/native_terrain_wrap.md. */
#ifndef VF3_NATIVE_TERRAIN_WRAP_H
#define VF3_NATIVE_TERRAIN_WRAP_H

#include "aim_math.h"

/* Run 0x8C068D54 (terrain_wrap).  A self-contained FP leaf (call-free, no
 * stack frame).  r4 = stage type, r5 -> x, r6 -> z (floats): stages of type
 * 2/7 scale both by 0.769; type 13 folds both into a 10-unit repeating cell;
 * every other type leaves them alone.  The constants come from the literal
 * pool at 0x8C068E50 (0.769) and 0x8C068E54 (0.1).  See
 * docs/re/native_terrain_wrap.md. */
void vf3_native_terrain_wrap(vf3_native_aim *a);

#endif /* VF3_NATIVE_TERRAIN_WRAP_H */
