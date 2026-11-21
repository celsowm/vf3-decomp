/* div_helpers.h - native ports of the integer division helpers of the fight
 * engine, operating on the `vf3_native_aim` context.  See div_helpers.c and
 * docs/re/native_div_helpers.md. */
#ifndef VF3_NATIVE_DIV_HELPERS_H
#define VF3_NATIVE_DIV_HELPERS_H

#include "aim_math.h"

/* 0x8C042C20 signed 32-bit divide: r1 / r0 -> r0 and r1 (both the quotient). */
void vf3_native_div_s32(vf3_native_aim *a);
/* 0x8C042CD4 unsigned 32-bit divide: r1 / r0 -> r0 and r1. */
void vf3_native_div_u32(vf3_native_aim *a);
/* 0x8C042E44 unsigned 32-bit remainder: r1 / r0 -> r0 = remainder, r1 = dividend. */
void vf3_native_mod_u32(vf3_native_aim *a);
/* 0x8C042D7C signed 32-bit remainder: r1 / r0 -> r0 = remainder, r1 = dividend. */
void vf3_native_mod_s32(vf3_native_aim *a);

#endif /* VF3_NATIVE_DIV_HELPERS_H */
