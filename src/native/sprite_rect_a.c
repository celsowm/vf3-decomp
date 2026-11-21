/* sprite_rect_a.c - SH-4 0x8C07B35C: the sprite near-corner helper, natively.
 *
 * A plain-C transcription of the readable port src/fight/sprite_uv.c
 * (`vf3_sprite_rect_a_entry`).  A call-free, branch-free FP leaf (no stack:
 * the only control transfer is the final rts; the single dead spill below the
 * entry sp is part of the captured RAM).  It operates on `vf3_native_aim`:
 * the flat RAM, the FR bank and the register file.
 *
 * FR4/FR5 are x/y, FR6/FR7 w/h, FR8 z.  It reads the four screen constants
 * (SCALE_X/Y, OFFSET_X/Y) out of fixed data addresses, scales x/y and adds
 * the offsets, stores position (+4/+8), z (+12), and the UV extent (+16/+20),
 * and leaves the results in FR3..FR5 and FR9..FR11.
 *
 * The float pipeline uses the same round-toward-zero + FTZ wrappers (fadd /
 * fmul) the other FP native ports use, so the stored floats match the guest
 * bit for bit.
 *
 * Register contract: r0 = 20, r2 = OFFSET_Y, r3 = OFFSET_X, r5 = SCALE_X,
 * r6 = SCALE_Y; FR3 = vh, FR4 = x, FR5 = y, FR9 = sy, FR10 = ox, FR11 = oy.
 * Tail-transfer to pr (untouched).
 *
 * See docs/re/native_sprite_rect_a.md. */
#include "sprite_rect_a.h"

#include <fenv.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

enum {
    SCALE_X = 0x0C10B7FCu, SCALE_Y = 0x0C10B800u,
    OFFSET_X = 0x0C10B804u, OFFSET_Y = 0x0C10B808u
};

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
static inline float fadd(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '+'); }

/* ---- ground-address reads ---- */
static uint8_t *gb(vf3_native_aim *a, uint32_t addr)
{ return (uint8_t *)a->ram + (addr - a->ram_base); }
static void wr32f(vf3_native_aim *a, uint32_t addr, float f)
{ uint32_t u = vf3_aim_ubits(f); memcpy(gb(a, addr), &u, 4); }
static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t u)
{ memcpy(gb(a, addr), &u, 4); }

void vf3_native_sprite_rect_a(vf3_native_aim *a)
{
    /* the four screen constants live in fixed data addresses */
    const float sx = vf3_aim_fbits(vf3_aim_u32(a, SCALE_X));
    const float sy = vf3_aim_fbits(vf3_aim_u32(a, SCALE_Y));
    const float ox = vf3_aim_fbits(vf3_aim_u32(a, OFFSET_X));
    const float oy = vf3_aim_fbits(vf3_aim_u32(a, OFFSET_Y));
    const uint32_t block = R(4);
    wr32(a, R(15) - 4u, vf3_aim_ubits(sx));           /* dead spill */

    const float x = fadd(a, fmul(a, F(4), sx), ox);
    const float y = fadd(a, fmul(a, F(5), sy), oy);
    wr32f(a, block + 4u, x);
    wr32f(a, block + 8u, y);
    wr32(a, block + 12u, vf3_aim_ubits(F(8)));        /* z, raw bits */

    const float uw = fmul(a, sx, F(6));
    const float vh = fmul(a, sy, F(7));
    wr32f(a, block + 16u, uw);
    wr32f(a, block + 20u, vh);

    R(0) = 20;
    R(2) = OFFSET_Y;
    R(3) = OFFSET_X;
    R(5) = SCALE_X;
    R(6) = SCALE_Y;
    F(3) = vh;
    F(4) = x;
    F(5) = y;
    F(9) = sy;
    F(10) = ox;
    F(11) = oy;

    /* tail-transfer to pr: the C return leaves pr untouched */
}
