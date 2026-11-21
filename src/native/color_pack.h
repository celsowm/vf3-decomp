/* color_pack.h - native port of the color-pack (0x8C03FB80), operating on
 * the `vf3_native_aim` context.
 *
 * See color_pack.c and docs/re/native_color_pack.md. */
#ifndef VF3_NATIVE_COLOR_PACK_H
#define VF3_NATIVE_COLOR_PACK_H

#include "aim_math.h"

/* Run 0x8C03FB80.  A self-contained FP leaf (call-free, no stack frame, no
 * tail-transfer).  FR4..FR7 (a, r, g, b) are scaled by 255 (a constant read
 * from the literal pool at 0x0C03FC38), converted to unsigned integers (a
 * value at or above 2^31 wraps through a -2^32 bias read at 0x0C03FC40, with
 * the half range 2^31 at 0x0C03FC3C), clamped to 255 as unsigned, and
 * packed a:r:g:b into r0 (also left in r4).  r5..r7 keep the clamped r, g,
 * b.  Leaves r0 = r4 = the packed word, r1 = 0, fr0/fr1/fr2/fr3/fr4/fr5/fr6/
 * fr7/fr8/fr9 and FPUL as the original does, and SR's T bit = (raw[3] > 0xFF).
 * r2, r3 and r8..r15, the stack pointer and pr are untouched.
 * See docs/re/native_color_pack.md. */
void vf3_native_color_pack(vf3_native_aim *a);

#endif /* VF3_NATIVE_COLOR_PACK_H */
