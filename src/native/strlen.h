/* strlen.h - native port of the string length (0x8C05342C), operating on the
 * `vf3_native_aim` context.
 *
 * See strlen.c and docs/re/native_strlen.md. */
#ifndef VF3_NATIVE_STRLEN_H
#define VF3_NATIVE_STRLEN_H

#include "aim_math.h"

/* Run 0x8C05342C.  A self-contained leaf (call-free, no FPU, no stack
 * frame).  r4 = the string; walks its bytes (read as sign-extended 8-bit)
 * until a zero, leaving r4 one past the NUL, r3 = the NUL byte (0), r5 =
 * length (the number of non-zero bytes before the NUL) and r0 = r5.  SR's T
 * bit is set.  r1, r2, r6..r15 and pr are untouched.  See
 * docs/re/native_strlen.md. */
void vf3_native_strlen(vf3_native_aim *a);

#endif /* VF3_NATIVE_STRLEN_H */
