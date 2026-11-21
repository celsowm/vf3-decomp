/* float_to_short.c - SH-4 0x8C09D590: the float-to-short, natively.
 *
 * A plain-C transcription of the readable port src/fight/small_leaves.c
 * (`vf3_float_to_short_entry`) onto `vf3_native_aim`: the flat RAM, the FR
 * bank, the register file and FPUL.
 *
 * A self-contained leaf (call-free, no stack frame).  It reads 42 floats out
 * of the object at r4+0x1D58 (stride 4), truncates each toward zero to a
 * 32-bit integer (`ftrc`, whose corner cases are the SH-4's: NaN or less
 * than -2^31 gives 0x80000000, at or above 2^31 gives 0x7fffffff, else the
 * truncated value), narrows it to a signed 16-bit value and stores it as a
 * halfword at r4+0x1F50 (stride 2).
 *
 * After the run r4 is 0 (the counter ran out), r5 is r4+0x1F50+84 (one past
 * the last halfword), r6 is r4+0x1D58+168 (one past the last float), r7 is
 * the last narrowed value, and SR's T bit is set.  r0..r3, r8..r15, the
 * stack pointer and pr are untouched.  The `ftrc` result rides in FPUL.
 *
 * The readable's `plain_fpu` gate (which refuses to run when the FPU is not
 * usable in the harness) is a harness concern: the body only truncates, so
 * the native leaf always runs.
 *
 * See docs/re/native_float_to_short.md. */
#include "float_to_short.h"

#include <math.h>
#include <stdint.h>

#define R(n) (a->r[(n)])

/* ftrc: the SH-4's float-to-integer truncation (toward zero).  NaN or less
 * than -2^31 gives 0x80000000, at or above 2^31 gives 0x7fffffff, else the
 * truncated value. */
static uint32_t ftrc(float f)
{
    double d = (double)f;
    if (isnan(d) || d < -2147483648.0) return 0x80000000u;
    if (d >= 2147483648.0) return 0x7fffffffu;
    return (uint32_t)(int32_t)d;
}

void vf3_native_float_to_short(vf3_native_aim *a)
{
    uint32_t src = R(4) + 0x1D58u;
    uint32_t dst = R(4) + 0x1F50u;
    uint32_t n = 42;

    do {
        float f = vf3_aim_fbits(vf3_aim_u32(a, src));
        src += 4;
        --n;
        uint32_t t = ftrc(f);
        a->fpul = t;
        uint32_t r7 = (uint32_t)(int32_t)(int16_t)t;
        vf3_aim_set_u16(a, dst, (uint16_t)r7);
        dst += 2;
    } while (n != 0);

    R(4) = 0;
    R(5) = dst;
    R(6) = src;
    R(7) = (uint32_t)(int32_t)(int16_t)a->fpul;
    a->sr |= 1u;            /* SET_T(1) */
}
