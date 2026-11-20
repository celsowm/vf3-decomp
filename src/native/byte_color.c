/* byte_color.c - SH-4 0x8C0563AC: the two-byte color scale into floats,
 * natively.
 *
 * A plain-C transcription of the readable port src/fight/readable/byte_color.c
 * (`vf3_byte_color_entry`).  A self-contained 80 B leaf
 * (0x0C0563AC..0x0C0563F8), call-free and branch-free (straight-line; the
 * only control transfer is the final rts).  It operates on `vf3_native_aim`:
 * the flat RAM, the FR bank and the register file.
 *
 * It reads three floats through a pointer from the literal pool, scales them
 * by a fourth, unpacks two packed bytes into three byte channels, converts
 * them to floats, scales those by the first three, and writes three floats
 * down a descending run of the output pointer.  The `w` below is
 * FPSCR.PR ? 8 : 4 (single/double width that gates every load and store).
 *
 * The float pipeline is done with the same round-toward-zero + FTZ wrappers
 * (fmul / flz) the other FP native ports use, so the stored floats match the
 * guest bit for bit.  The FP results ride in the FR bank (fr4/5/6 scaled,
 * fr0/1/2 the byte channels), as the guest's stores emit the bank.
 *
 * See docs/re/native_byte_color.md. */
#include "byte_color.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

/* ---- round-toward-zero FPU wrappers (as glyph_cache.c / hitbox_overlap.c) ---- */
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
static inline float fadd(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '+'); }
static inline float itof(int32_t v) { return (float)v; }

/* ---- ground-address reads ---- */
static uint8_t *gb(vf3_native_aim *a, uint32_t addr)
{ return (uint8_t *)a->ram + (addr - a->ram_base); }
static uint32_t rd32(vf3_native_aim *a, uint32_t addr)
{ uint32_t v; memcpy(&v, gb(a, addr), 4); return v; }
static uint16_t rd16(vf3_native_aim *a, uint32_t addr)
{ uint16_t v; memcpy(&v, gb(a, addr), 2); return v; }
static float rd32f(vf3_native_aim *a, uint32_t addr)
{ return vf3_aim_fbits(rd32(a, addr)); }
static void wr32f(vf3_native_aim *a, uint32_t addr, float f)
{ uint32_t u = vf3_aim_ubits(f); memcpy(gb(a, addr), &u, 4); }
static void wr64f(vf3_native_aim *a, uint32_t addr, double d)
{ memcpy(gb(a, addr), &d, 8); }

void vf3_native_byte_color(vf3_native_aim *a, uint32_t sp0)
{
    (void)sp0;
    const unsigned w = (a->fpscr & 0x100000u) ? 8u : 4u;
    const uint32_t r1_in = R(1);
    const uint32_t r4_in = R(4);

    /* 0x0c0563ac: the entry fr0 is pushed out to [r1 - w] (scratch).  The
     * store width follows the FPSCR mode: a single is 4 bytes, a double 8. */
    if (w == 4) wr32f(a, r1_in - w, F(0));
    else        { double d = F(0); wr64f(a, r1_in - w, d); }

    /* 0x0c0563c0..c6: the pool pointer, r4, the scale and the output base. */
    uint32_t r2 = rd32(a, 0x0c056504u);
    uint32_t r4 = r4_in + 4u;
    F(7) = (w == 4) ? rd32f(a, 0x0c056508u)
                    : (float)(*(double *)gb(a, 0x0c056508u));
    uint32_t out = rd32(a, 0x0c056510u);

    /* 0x0c0563ca..ce: fr4, fr5, fr6 = the three source floats at ptrA. */
    if (w == 4) {
        F(4) = rd32f(a, r2); r2 += w;
        F(5) = rd32f(a, r2); r2 += w;
        F(6) = rd32f(a, r2);
    } else {
        F(4) = (float)(*(double *)gb(a, r2)); r2 += w;
        F(5) = (float)(*(double *)gb(a, r2)); r2 += w;
        F(6) = (float)(*(double *)gb(a, r2));
    }

    /* 0x0c0563d0..e8: the packed bytes at [r4+4] and [r4+6]; r4 += 4. */
    const uint32_t lo = (uint32_t)(int32_t)(int16_t)rd16(a, r4);
    const uint32_t hi = (uint32_t)(int32_t)(int16_t)rd16(a, r4 + 2u);
    r4 += 4u;

    /* 0x0c0563d2..da: scale the source channels by fr7 in the FP bank. */
    F(4) = fmul(a, F(4), F(7));
    F(5) = fmul(a, F(5), F(7));
    F(6) = fmul(a, F(6), F(7));

    /* 0x0c0563d8..f0: the byte channels, as floats, scaled, into the bank. */
    const uint32_t c_r2 = lo & 0xffu;            /* lo's low byte */
    const uint32_t c_r5 = (lo >> 8u) & 0xffu;     /* lo's high byte */
    const uint32_t c_r6 = hi & 0xffu;            /* hi's low byte */
    F(0) = fmul(a, itof((int32_t)c_r2), F(6));
    F(1) = fmul(a, itof((int32_t)c_r5), F(5));
    F(2) = fmul(a, itof((int32_t)c_r6), F(4));

    /* 0x0c0563f2..f8: the three stores down the output run. */
    if (w == 4) {
        wr32f(a, out, F(0));
        wr32f(a, out - w, F(1));
        wr32f(a, out - 2u * w, F(2));
    } else {
        double d0 = F(0), d1 = F(1), d2 = F(2);
        wr64f(a, out, d0);
        wr64f(a, out - w, d1);
        wr64f(a, out - 2u * w, d2);
    }

    /* the visited registers. */
    R(0) = 0x0c056508u;
    R(1) = out - 2u * w;
    R(2) = c_r2;
    R(4) = r4_in + 8u;
    R(5) = c_r5;
    R(6) = c_r6;
    a->fpul = c_r6;                    /* FPUL: the last r53 write */
}
