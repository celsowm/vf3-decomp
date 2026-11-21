#ifndef VF3_NATIVE_SPRITE_RECT_B_H
#define VF3_NATIVE_SPRITE_RECT_B_H

/* Native port of the sprite far-corner UV helper 0x8C07B398
 * (vf3_native_sprite_rect_b). */
#include "aim_math.h"

/* Compute and store the far corner's four UV values.
 *
 *   r4 -> the vertex block; FR4/FR5 the near corner, FR6/FR7 its extent,
 *   FR8/FR9 the UV scales.
 *
 * Stores four floats at block+24..+36 and writes the results into the FR
 * bank.  Tail-transfer to pr (untouched).
 */
void vf3_native_sprite_rect_b(vf3_native_aim *a);

#endif /* VF3_NATIVE_SPRITE_RECT_B_H */
