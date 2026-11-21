/* float_to_short.h - native port of the float-to-short (0x8C09D590),
 * operating on the `vf3_native_aim` context.
 *
 * See float_to_short.c and docs/re/native_float_to_short.md. */
#ifndef VF3_NATIVE_FLOAT_TO_SHORT_H
#define VF3_NATIVE_FLOAT_TO_SHORT_H

#include "aim_math.h"

/* Run 0x8C09D590.  A self-contained leaf (call-free, no stack frame).  It
 * reads 42 floats out of the object at r4+0x1D58 (stride 4), truncates each
 * to a 32-bit integer (ftrc: toward zero), narrows it to a signed 16-bit
 * value and stores it as a halfword at r4+0x1F50 (stride 2).  Leaves r4 = 0,
 * r5 = r4+0x1F50+84, r6 = r4+0x1D58+168 and r7 = the last narrowed value,
 * and SR's T bit set.  r0..r3, r8..r15, the stack pointer and pr are
 * untouched.  See docs/re/native_float_to_short.md. */
void vf3_native_float_to_short(vf3_native_aim *a);

#endif /* VF3_NATIVE_FLOAT_TO_SHORT_H */
