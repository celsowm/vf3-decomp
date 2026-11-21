#ifndef VF3_NATIVE_SPRITE_RECT_A_H
#define VF3_NATIVE_SPRITE_RECT_A_H

/* Native port of the sprite near-corner helper 0x8C07B35C
 * (vf3_native_sprite_rect_a). */
#include "aim_math.h"

/* Compute and store the vertex block's scaled position, z and UV extent.
 *
 *   r4 -> the vertex block; FR4/FR5 = x/y, FR6/FR7 = w/h, FR8 = z.
 *
 * Stores position +4/+8, z +12, UV extent +16/+20, and writes the results
 * into the FR and integer registers.  Tail-transfer to pr (untouched).
 */
void vf3_native_sprite_rect_a(vf3_native_aim *a);

#endif /* VF3_NATIVE_SPRITE_RECT_A_H */
