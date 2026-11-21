/* format_int.h - native port of the integer conversion leaf 0x8C04AF04
 * (vf3_native_format_int).  See format_int.c and docs/re/native_format_int.md. */
#ifndef VF3_NATIVE_FORMAT_INT_H
#define VF3_NATIVE_FORMAT_INT_H

#include "aim_math.h"

/* 0x8C04AF04: render one number into the engine's printf buffer.  r4 = value,
 * r5 = output cursor, r6 = conversion character, r7 = conversion spec. */
void vf3_native_format_int(vf3_native_aim *a);

#endif /* VF3_NATIVE_FORMAT_INT_H */
