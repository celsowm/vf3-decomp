/* terrain_plane_hit.c - SH-4 0x8C0692A6: height of a terrain triangle's
 * plane at (x, z), plus its normal, natively.
 *
 * A plain-C transcription of the readable port src/fight/terrain_plane_hit.c
 * (`vf3_terrain_plane_hit_entry`).  A call-free FP leaf with no guest callees
 * and no device/FMTRX access - only plain FR arithmetic (FSUB/FMUL/FDIV/FMAC,
 * all FPSCR-aware) over a 12-byte stack frame that it restores before the
 * tail transfer to pr.
 *
 *   r4 -> triangle record (+4 = offset of the shape record from the base at
 *   [0x0C113A0C]), r5 -> float for the height, r6 -> three floats for the
 *   normal, r7 = 4 selects the second vertex triple of the shape (vertex
 *   offsets +16 / +12 / +4) instead of the first (+12 / +8 / +4),
 *   FR4 / FR5 = x / z.
 *
 *   With the triangle P (the first vertex), Q and R, the edge vectors Q - P
 *   and R - P are crossed and the plane through them is solved for the height
 *   at (x, z), mirroring the original's FR sequence; the result goes to r5's
 *   float.  The triangle's stored normal (floats at +20 / +24 / +28 of the
 *   shape record) is copied to r6, and the return value is the record's first
 *   word shifted left once and masked with 0x1FFFC, or-ed with its low two
 *   bits (left in r0, with r1 = the low two bits).
 *
 *   r14 and FR14 are saved below sp0 and restored; the frame (sp0-20, 12
 *   bytes) holds x, z and the shape record's first word.  The FMACs are fused
 *   multiply-adds (`fmaf`), the FDIV the FPSCR-aware divide.  See
 *   docs/re/native_terrain_plane_hit.md. */
#include "terrain_plane_hit.h"
#include "aim_math.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

#define BASE_ADDR 0x0C113A0Cu
#define SAVED     8u
#define FRAME     12u
#define WORD_MASK 0x1FFFCu

/* ---- FPSCR-aware FPU wrappers (as color_unpack.c) ---- */
static inline float flush(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float fbin(vf3_native_aim *a, char op, float x, float y)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z;
    switch (op) {
    case '+': z = x + y; break;
    case '-': z = x - y; break;
    case '*': z = x * y; break;
    default:  z = x / y; break;
    }
    fesetround(saved);
    return flush(a, z);
}
static inline float fmac(vf3_native_aim *a, float x, float y, float z)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float r = fmaf(x, y, z);
    fesetround(saved);
    return flush(a, r);
}

/* ---- ground-address reads ---- */
static uint8_t *gb(vf3_native_aim *a, uint32_t addr)
{ return (uint8_t *)a->ram + (addr - a->ram_base); }
static uint32_t rd32(vf3_native_aim *a, uint32_t addr)
{ uint32_t u; memcpy(&u, gb(a, addr), 4); return u; }
static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t u)
{ memcpy(gb(a, addr), &u, 4); }

void vf3_native_terrain_plane_hit(vf3_native_aim *a)
{
    const uint32_t sp0 = R(15), f = sp0 - SAVED - FRAME;
    const uint32_t saved_r14 = R(14), saved_f14 = vf3_aim_ubits(F(14));
    const uint32_t out_h = R(5), out_n = R(6);
    uint32_t p, q, rr;

    wr32(a, sp0 - 4, saved_r14);
    wr32(a, sp0 - 8, saved_f14);
    R(15) = f;

    const uint32_t base = rd32(a, BASE_ADDR);
    const uint32_t shape = rd32(a, R(4) + 4) + base;
    wr32(a, f, vf3_aim_ubits(F(4)));
    wr32(a, f + 4, vf3_aim_ubits(F(5)));
    const uint32_t first = rd32(a, shape + 4);
    wr32(a, f + 8, first);
    if (R(7) == 4) { rr = rd32(a, shape + 16); q = rd32(a, shape + 12); }
    else           { q = rd32(a, shape + 8);   rr = rd32(a, shape + 12); }
    q += base; p = first + base; rr += base;

    F(0) = vf3_aim_fbits(rd32(a, q));
    F(2) = vf3_aim_fbits(rd32(a, p + 4));
    F(1) = vf3_aim_fbits(rd32(a, p + 8));
    F(4) = vf3_aim_fbits(rd32(a, q + 4));
    F(11) = vf3_aim_fbits(rd32(a, q + 8));
    R(14) = rr;
    F(9) = vf3_aim_fbits(rd32(a, rr + 4));
    F(14) = vf3_aim_fbits(rd32(a, p));
    F(11) = fbin(a, '-', F(11), F(1));
    F(8) = vf3_aim_fbits(rd32(a, rr + 8));
    F(4) = fbin(a, '-', F(4), F(2));
    F(10) = vf3_aim_fbits(rd32(a, rr));
    F(0) = fbin(a, '-', F(0), F(14));
    F(8) = fbin(a, '-', F(8), F(1));
    F(9) = fbin(a, '-', F(9), F(2));
    F(5) = F(11);
    F(10) = fbin(a, '-', F(10), F(14));
    F(7) = F(4);
    F(6) = F(0);
    F(7) = fbin(a, '*', F(7), F(8));
    F(6) = fbin(a, '*', F(6), F(9));
    F(5) = fbin(a, '*', F(5), F(10));
    F(11) = fbin(a, '*', F(11), F(9));
    F(3) = F(7);
    F(0) = fbin(a, '*', F(0), F(8));
    F(4) = fbin(a, '*', F(4), F(10));
    F(7) = F(11);
    F(7) = fbin(a, '-', F(7), F(3));
    F(3) = F(5);
    F(5) = F(0);
    F(5) = fbin(a, '-', F(5), F(3));
    F(3) = F(6);
    F(0) = F(7);
    F(6) = F(4);
    F(6) = fbin(a, '-', F(6), F(3));
    F(2) = fbin(a, '*', F(2), F(5));
    F(5) = -F(5);
    F(2) = fmac(a, F(0), F(14), F(2));
    F(0) = F(6);
    F(4) = F(2);
    F(4) = fmac(a, F(0), F(1), F(4));
    F(2) = vf3_aim_fbits(rd32(a, f));
    F(2) = fbin(a, '*', F(2), F(7));
    F(3) = F(4);
    F(4) = F(2);
    F(4) = fbin(a, '-', F(4), F(3));
    F(3) = vf3_aim_fbits(rd32(a, f + 4));
    F(2) = F(4);
    F(2) = fmac(a, F(0), F(3), F(2));
    F(4) = F(2);
    F(4) = fbin(a, '/', F(4), F(5));
    wr32(a, out_h, vf3_aim_ubits(F(4)));

    const uint32_t rec = shape;
    F(3) = vf3_aim_fbits(rd32(a, rec + 20));
    wr32(a, out_n, vf3_aim_ubits(F(3)));
    F(3) = vf3_aim_fbits(rd32(a, rec + 24));
    wr32(a, out_n + 4, vf3_aim_ubits(F(3)));
    F(3) = vf3_aim_fbits(rd32(a, rec + 28));
    wr32(a, out_n + 8, vf3_aim_ubits(F(3)));

    const uint32_t word = rd32(a, rec);
    R(1) = 3u & word;
    R(0) = ((word << 1) & WORD_MASK) | R(1);
    R(14) = saved_r14;
    F(14) = vf3_aim_fbits(saved_f14);
    R(15) = sp0;
    /* tail-transfer to pr: the C return leaves pr untouched */
}
