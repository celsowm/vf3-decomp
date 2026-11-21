/* push_offset.c - SH-4 0x8C056B20: the scaled-offset push helper, natively.
 *
 * A plain-C transcription of the readable port src/fight/geom_readable.c
 * (`vf3_push_offset_entry`).  A call-free FP leaf (only fmul / from-int; no
 * guest callees, no FPU branch -> the only control transfer is the final
 * rts).  It operates on `vf3_native_aim`: the flat RAM, the FR bank and the
 * register file.
 *
 * It is register-passed: r8 = source (two int16 at +0x0E, +0x10), r12 =
 * record cursor, r6 and FR12..FR15 = values to push, FR3 = scale.  It writes
 *
 *     [r12+30] = FR14, [r12+2C] = FR13, [r12+28] = FR12, [r12+24] = r6
 *     [r12'+14] = float(s16 @ src+0x10) * scale    (y, -> FR1)
 *     [r12'+10] = float(s16 @ src+0x0E) * scale    (x, -> FR2)
 *     [r12'+18] = FR15, [r12'+1C] = 0
 *
 * with r12' = r12 + 0x20 on return; r0 = 0, r8 is unchanged.  Tail transfer
 * to pr (untouched).
 *
 * The float pipeline uses the same round-toward-zero + FTZ wrappers (fmul)
 * the other FP native ports use, so the stored floats match the guest bit
 * for bit.  See docs/re/native_push_offset.md. */
#include "push_offset.h"

#include <fenv.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

/* ---- round-toward-zero FPU wrappers (as sprite_rect_b.c) ---- */
static inline float flz(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float ft0(vf3_native_aim *a, float x, float y, char op)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = 0;
    switch (op) {
        case '+': z = x + y; break;
        case '-': z = x - y; break;
        case '*': z = x * y; break;
        default:  z = x / y; break;
    }
    fesetround(saved);
    return flz(a, z);
}
static inline float fmul(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '*'); }

/* ---- ground-address reads ---- */
static uint8_t *gb(vf3_native_aim *a, uint32_t addr)
{ return (uint8_t *)a->ram + (addr - a->ram_base); }
static uint16_t rd16(vf3_native_aim *a, uint32_t addr)
{ return (uint16_t)((gb(a, addr)[0]) | ((uint16_t)gb(a, addr)[1] << 8)); }
static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t u)
{ memcpy(gb(a, addr), &u, 4); }
static void wr32f(vf3_native_aim *a, uint32_t addr, float f)
{ uint32_t u = vf3_aim_ubits(f); memcpy(gb(a, addr), &u, 4); }

void vf3_native_push_offset(vf3_native_aim *a)
{
    const uint32_t src = R(8), cursor = R(12) + 0x30u;
    const float scale = F(3);
    const int32_t first = (int16_t)rd16(a, src + 0x0Eu);
    const int32_t second = (int16_t)rd16(a, src + 0x10u);

    const float y = fmul(a, (float)second, scale);
    const float x = fmul(a, (float)first, scale);
    F(1) = y;
    F(2) = x;

    const uint32_t top = cursor - 16u;
    wr32(a, cursor - 4u, vf3_aim_ubits(F(14)));
    wr32(a, cursor - 8u, vf3_aim_ubits(F(13)));
    wr32(a, cursor - 12u, vf3_aim_ubits(F(12)));
    wr32(a, top, R(6));
    wr32f(a, top + 20u, y);
    wr32f(a, top + 16u, x);
    wr32(a, top + 24u, vf3_aim_ubits(F(15)));
    wr32(a, top + 28u, 0);
    R(0) = 0;
    R(12) = top;

    /* tail-transfer to pr: the C return leaves pr untouched */
}
