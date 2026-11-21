#ifndef VF3_NATIVE_FLOAT_BLEND_H
#define VF3_NATIVE_FLOAT_BLEND_H

/* Native port of the four-float blend leaf 0x8C03E810 (vf3_native_float_blend). */
#include "aim_math.h"

/* Copy four floats out of an array and into a structure of four slots, then
 * write a weighted sum over three of the slots back into the first one.
 *
 *   r4 = the array of four floats, r15 = the caller's stack pointer.
 *
 * The structure's address is a word in the literal pool at 0x0C03E8A4; the
 * three weights are pool floats at 0x0C03E8A8/A C/B0.  Tail-transfer to pr
 * (untouched).  The r15 round trip around the pushed frame is net zero. */
void vf3_native_float_blend(vf3_native_aim *a);

#endif /* VF3_NATIVE_FLOAT_BLEND_H */
