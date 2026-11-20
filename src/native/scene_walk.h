/* scene_walk.h - native port of the scene list walk with an enable flag
 * (0x8C06233E), operating on the `vf3_native_aim` context.
 *
 * See scene_walk.c and docs/re/native_scene_walk.md. */
#ifndef VF3_NATIVE_SCENE_WALK_H
#define VF3_NATIVE_SCENE_WALK_H

#include "aim_math.h"

/* Run 0x8C06233E.  r4 = the key, r5 = the flag/table write target.  A
 * call-free, integer-only leaf; it neither pushes pr nor touches r15 (the
 * guest tail-returns through r16).  It reads a threshold pointer from the
 * pool at 0x0c06238c and a table base at 0x0c062384, writes a 16-bit enable
 * flag to [r5] (1 when r4 >= *p1, signed), reads it back as a sign-extended
 * byte, walks the table slot base + 20*byte and leaves r0 = r6 = the first
 * node whose value at +12 equals r4 (or 0).  See docs/re/native_scene_walk.md. */
void vf3_native_scene_walk(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_SCENE_WALK_H */
