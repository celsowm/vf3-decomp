/* record_flag40.c - SH-4 0x8C04B9BE: the record flag-40 probe, natively.
 *
 * A plain-C transcription of the readable port src/fight/small_leaves.c
 * (`vf3_record_flag40_entry`) onto `vf3_native_aim`: the flat RAM and the
 * register file.
 *
 * A self-contained leaf (call-free, no FPU, no stack frame).  r4 = a record.
 * It reads the record's first word - the record kind:
 *
 *   kind = *r4;
 *   T    = (kind == 1);
 *   if (kind == 1) { r0 = 0; }
 *   else           { r1 = 16; r0 = (int8)byte[ *(r4+4) + 16 ] & 0x40; }
 *
 * So r0 is 0 for a kind-1 record, otherwise the low 0x40 bit of the byte the
 * record's second word points at (offset +16), sign-extended and masked.
 *
 * r1 is set to 16 on the else path only; r4 and every other register are
 * untouched.  SR's T bit is (kind == 1).  The return pops pr (the caller's
 * return address).
 *
 * See docs/re/native_record_flag40.md. */
#include "record_flag40.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

void vf3_native_record_flag40(vf3_native_aim *a)
{
    const uint32_t kind = vf3_aim_u32(a, R(4));
    a->sr = (a->sr & ~1u) | (kind == 1 ? 1u : 0u);   /* SET_T(kind == 1) */

    if (kind == 1) {
        R(0) = 0;
    } else {
        R(1) = 16;
        const uint32_t p = vf3_aim_u32(a, R(4) + 4u);
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, p + 16u);
        R(0) &= 0x40u;
    }
}
