/* strlen.c - SH-4 0x8C05342C: the string length, natively.
 *
 * A plain-C transcription of the readable port src/fight/small_leaves.c
 * (`vf3_strlen_entry`) onto `vf3_native_aim`: the flat RAM and the register
 * file.
 *
 * A self-contained leaf (call-free, no FPU, no stack frame).  r4 = the
 * string; the body walks its bytes (each read as a sign-extended 8-bit
 * value) until a zero, so r4 ends one past the NUL, r3 is the NUL byte (0),
 * r5 is the length (the number of non-zero bytes before the NUL) and r0 = r5.
 * SR's T bit is set (the loop's final cmp/eq).
 *
 * r1, r2, r6..r15, the stack pointer and pr are untouched.  The return pops
 * pr (the caller's return address).
 *
 * See docs/re/native_strlen.md. */
#include "strlen.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

void vf3_native_strlen(vf3_native_aim *a)
{
    R(5) = 0;
    for (;;) {
        uint32_t c = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(4));
        R(3) = c;                       /* r3 is the widened byte read */
        R(4) += 1u;
        if (c == 0) break;
        R(5) += 1u;
    }
    a->sr |= 1u;            /* SET_T(1): the loop's final cmp/eq */
    R(0) = R(5);
}
