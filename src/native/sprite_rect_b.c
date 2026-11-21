/* sprite_rect_b.c - SH-4 0x8C07B398: the sprite far-corner UV helper,
 * natively.
 *
 * A plain-C transcription of the readable port src/fight/sprite_uv.c
 * (`vf3_sprite_rect_b_entry`).  A call-free, branch-free FP leaf (no stack:
 * the only control transfer is the final rts).  It operates on
 * `vf3_native_aim`: the flat RAM, the FR bank and the register file.
 *
 * FR4/FR5 are the near corner, FR6/FR7 its extent, FR8/FR9 the UV scales.
 * The stored values are (corner + bias) * scale for the four corner UVs:
 *
 *     u0 = (x + BIAS_A) * su   ;  v0 = (y + BIAS_B) * sv
 *     u1 = (x + w + BIAS_C) * su ; v1 = (y + h + BIAS_D) * sv
 *
 * stored at block +24/+28/+32/+36.  The float pipeline uses the same
 * round-toward-zero + FTZ wrappers (fadd / fmul) the other FP native ports
 * use, so the stored floats match the guest bit for bit.
 *
 * Register contract: r0 = 36; FR1 = BIAS_C, FR2 = BIAS_B, FR3 = BIAS_D,
 * FR4 = u1, FR5 = v1.  Tail-transfer to pr (untouched).
 *
 * See docs/re/native_sprite_rect_b.md. */
#include "sprite_rect_b.h"

#include <fenv.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

/* ---- round-toward-zero FPU wrappers (as byte_color.c) ---- */
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

void vf3_native_sprite_rect_b(vf3_native_aim *a)
{
    /* the exact bias bit patterns from the readable's constants */
    const uint32_t BIAS_A = 0x3A8461F9u, BIAS_B = 0x33D6BF94u,
                   BIAS_C = 0x80000000u, BIAS_D = 0xBED70A3Du;
    const uint32_t block = R(4);
    const float x = F(4), y = F(5);
    const float su = F(8), sv = F(9);

    const float x1 = fadd(a, x, F(6));
    const float u0 = fmul(a, fadd(a, x, vf3_aim_fbits(BIAS_A)), su);
    wr32f(a, block + 24u, u0);
    const float y1 = fadd(a, y, F(7));
    const float v0 = fmul(a, fadd(a, y, vf3_aim_fbits(BIAS_B)), sv);
    wr32f(a, block + 28u, v0);
    const float u1 = fmul(a, fadd(a, x1, vf3_aim_fbits(BIAS_C)), su);
    wr32f(a, block + 32u, u1);
    const float v1 = fmul(a, fadd(a, y1, vf3_aim_fbits(BIAS_D)), sv);
    wr32f(a, block + 36u, v1);
    R(0) = 36;
    F(1) = vf3_aim_fbits(BIAS_C);
    F(2) = vf3_aim_fbits(BIAS_B);
    F(3) = vf3_aim_fbits(BIAS_D);
    F(4) = u1;
    F(5) = v1;

    /* tail-transfer to pr: the C return leaves pr untouched */
}
