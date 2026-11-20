/* float_scale.h - native port of the unsigned-32-to-float scale
 * (0x8C039C50 / 0x8C039C70), operating on the `vf3_native_aim` context.  See
 * float_scale.c and docs/re/native_float_scale.md. */
#ifndef VF3_NATIVE_FLOAT_SCALE_H
#define VF3_NATIVE_FLOAT_SCALE_H

#include "aim_math.h"

/* Run 0x8C039C50 (pool_p1 = 0x0c039d4c) or 0x8C039C70 (pool_p1 = 0x0c039d58).
 * Reads the 32-bit value through the pool's pointer, converts it to a float,
 * folds the sign bit back in with the 2^32 addition when it is set, scales by
 * the pool's multiplier and returns the truncated integer in r0 and FPUL.  It
 * calls nobody and keeps **no stack frame**.  See docs/re/native_float_scale.md. */
void vf3_native_float_scale(vf3_native_aim *a, uint32_t pool_p1);

#endif /* VF3_NATIVE_FLOAT_SCALE_H */
