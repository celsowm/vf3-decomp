/* negate_copy.c - SH-4 0x8C072B02: the negate-copy, natively.
 *
 * A plain-C transcription of the readable port src/fight/negate_copy.c
 * (`vf3_negate_copy_entry`) onto `vf3_native_aim`: the flat RAM and the
 * register file.
 *
 * A self-contained leaf (call-free, no FPU, no stack frame).  r5 -> { count,
 * src, dst } (three words read from RAM).  Every entry copies six floats:
 * the first three as they are, the next three with the sign flipped (a fneg,
 * so a NaN keeps its payload and a zero becomes -0).  The readable routes the
 * value through the FR bank as a 32-bit word, so the sign flip is exactly the
 * bitwise xor `v ^ 0x80000000` and the stored word is the plain source byte
 * (or its negation) - pure integer in native form.
 *
 * After the loop: r7 = count (int32, <= 0), r4 = src (one past the last
 * read), r6 = dst (one past the last write), and SR's T bit is clear (the
 * last cmp/pl was false).  r5 and every other register are untouched.  The
 * return pops pr (the caller's return address).
 *
 * See docs/re/native_negate_copy.md. */
#include "negate_copy.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

#define SIGN 0x80000000u

void vf3_native_negate_copy(vf3_native_aim *a)
{
    int32_t count = (int32_t)vf3_aim_u32(a, R(5));
    uint32_t src  = vf3_aim_u32(a, R(5) + 4u);
    uint32_t dst  = vf3_aim_u32(a, R(5) + 8u);

    while (count > 0) {
        for (int i = 0; i < 6; ++i) {
            uint32_t v = vf3_aim_u32(a, src);
            vf3_aim_set_u32(a, dst, (i < 3) ? v : (v ^ SIGN));
            src += 4u; dst += 4u;
        }
        --count;
    }

    R(7) = (uint32_t)count;
    R(4) = src;
    R(6) = dst;
    a->sr &= ~1u;                       /* the last cmp/pl was false */
}
