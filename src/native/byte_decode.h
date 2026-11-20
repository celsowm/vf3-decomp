/* byte_decode.h - native port of the word decoder (0x8C04538A), operating on
 * the `vf3_native_aim` context.  See byte_decode.c and
 * docs/re/native_byte_decode.md. */
#ifndef VF3_NATIVE_BYTE_DECODE_H
#define VF3_NATIVE_BYTE_DECODE_H

#include "aim_math.h"

/* Run 0x8C04538A.  A word off the caller's stack, turned around or not, and
 * the answer its first byte carries.  r4 = the object, r5 = the caller's
 * stack.  A self-contained integer leaf with no calls and no FP. */
void vf3_native_byte_decode(vf3_native_aim *a);

#endif /* VF3_NATIVE_BYTE_DECODE_H */
