/* scene_clear_flag.h - native port of the scene-table bit-clear (0x8C0624BA),
 * operating on the `vf3_native_aim` context.
 *
 * See scene_clear_flag.c and docs/re/native_scene_clear_flag.md. */
#ifndef VF3_NATIVE_SCENE_CLEAR_FLAG_H
#define VF3_NATIVE_SCENE_CLEAR_FLAG_H

#include "aim_math.h"

/* Run 0x8C0624BA.  A self-contained leaf (call-free, no FPU, no stack
 * frame).  r4 = the address of a scene record; scans the 4096-record scene
 * object table at 0x0C16CF6C (stride 24) and clears bit 0 of the first
 * halfword of the record whose address equals r4, then leaves
 * r1 = r7 = 0x1000 and r5 = r6 = table base + 24 * 0x1000.  r4, the SR and
 * every other register are untouched.  See docs/re/native_scene_clear_flag.md. */
void vf3_native_scene_clear_flag(vf3_native_aim *a);

#endif /* VF3_NATIVE_SCENE_CLEAR_FLAG_H */
