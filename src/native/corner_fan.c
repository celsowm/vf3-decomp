/* corner_fan.c - SH-4 0x8C03FB10: the four-corner offset-fan, natively.
 *
 * A plain-C transcription of the readable port src/fight/geom_readable.c
 * (`vf3_corner_fan_entry`) onto `vf3_native_aim`: the flat RAM, the FR bank,
 * the register file and FPUL.
 *
 * A self-contained FP leaf (call-free, no tail-transfer).  r4 = object (flags
 * word at +0x2C: low 2 bits select the base column A, the next 2 bits the
 * base row B), r5/r6 = output arrays of 4 floats, FR4..FR7 = (a,b,c,d).  A, B
 * come from the flags; each of the 4 table corners (u,v) in 0x0C0EA670 gives
 *
 *     du = u - A, dv = v - B
 *     out5 = obj[+4] + du*(a*d) + dv*(b*c)
 *     out6 = obj[+8] - (a*c)*du + dv*(b*d)
 *
 * in the order of the original: the macs round once, and the du (dv) terms
 * are skipped entirely when du (dv) is zero.  This entry also writes the
 * entry FR14 (a dead push) to sp-4.
 *
 * The FP arithmetic goes through the same round-toward-zero + FTZ wrappers
 * the other FP native ports use; the three fused multiply-adds (the `fmac`s)
 * use `fmaf` so they round once.  See docs/re/native_corner_fan.md. */
#include "corner_fan.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

#define CORNER_TABLE 0x0C0EA670u

static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static float bits2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

/* ---- round-toward-zero + FTZ wrappers (as glyph_cache.c) ---- */
static inline float flz(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float fop(vf3_native_aim *a, float x, float y, char op)
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
static inline float fsub(vf3_native_aim *a, float x, float y) { return fop(a, x, y, '-'); }
static inline float fmul(vf3_native_aim *a, float x, float y) { return fop(a, x, y, '*'); }
static inline float fadd(vf3_native_aim *a, float x, float y) { return fop(a, x, y, '+'); }
static inline float fma0(vf3_native_aim *a, float x, float y, float acc)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = fmaf(x, y, acc);
    fesetround(saved);
    return flz(a, z);
}
static inline float fmacv(vf3_native_aim *a, float x, float y, float acc) { return fma0(a, x, y, acc); }

void vf3_native_corner_fan(vf3_native_aim *a)
{
    const uint32_t obj = R(4);
    uint32_t out_a = R(5), out_b = R(6);
    const uint32_t flags = vf3_aim_u32(a, obj + 0x2Cu);
    /* the dead fr14 push: write the *entry* FR14 to sp-4 (nothing reads it) */
    vf3_aim_set_u32(a, R(15) - 4u, vf3_aim_ubits(F(14)));

    const float a_ = F(4), b = F(5);
    const float c = F(6), d = F(7);
    const float bc = fmul(a, b, c);                     /* fr9 */
    const float ac = fmul(a, a_, c);                    /* fr4 */
    const float bd = fmul(a, b, d);                     /* fr5 */
    const float ad = fmul(a, a_, d);                    /* fr8 */
    const int32_t col = (int32_t)(flags & 3u), row = (int32_t)((flags >> 2) & 3u);
    const float base_u = (float)col;                    /* fr6 (int -> float) */
    const float base_v = (float)row;                    /* fr14 in the original */

    float fr0 = 0, fr1 = 0, fr2 = 0, fr3 = 0, fr7 = 0, fr10 = 0, fr11 = 0;
    uint32_t table = CORNER_TABLE;
    for (int i = 0; i < 4; ++i) {
        fr7 = fsub(a, bits2f(vf3_aim_u32(a, table)), base_u);
        fr10 = fsub(a, bits2f(vf3_aim_u32(a, table + 4u)), base_v);
        table += 8u;
        fr11 = bits2f(vf3_aim_u32(a, obj + 4u));
        fr1 = bits2f(vf3_aim_u32(a, obj + 8u));
        fr3 = 0;
        if (!(fr7 == 0)) {
            fr2 = fmul(a, ac, fr7);
            fr0 = fr7;
            fr11 = fmacv(a, fr0, ad, fr11);
            fr2 = bits2f(fbits(fr2) ^ 0x80000000u);
            fr1 = fadd(a, fr1, fr2);
        }
        if (!(fr10 == 0)) {
            fr0 = fr10;
            fr1 = fmacv(a, fr0, bd, fr1);
            fr11 = fmacv(a, fr0, bc, fr11);
        }
        vf3_aim_set_u32(a, out_a, vf3_aim_ubits(fr11));
        vf3_aim_set_u32(a, out_b, vf3_aim_ubits(fr1));
        out_a += 4u;
        out_b += 4u;
    }
    F(0) = fr0;  F(1) = fr1;  F(2) = fr2;  F(3) = fr3;
    F(4) = ac;   F(5) = bd;   F(6) = base_u; F(7) = fr7;
    F(8) = ad;   F(9) = bc;   F(10) = fr10;  F(11) = fr11;
    R(1) = 0;
    R(3) = 3;
    R(5) = out_a;
    R(6) = out_b;
    R(7) = table;
    a->sr |= 1u;                                          /* final tst r1,r1 */
    a->fpul = (uint32_t)row;
}
