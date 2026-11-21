/* frame_counter_step.c - SH-4 0x8C0CC334 (frame_counter_step), natively.
 *
 * A plain-C transcription of the readable port src/fight/frame_counter_step.c
 * (`vf3_frame_counter_step_entry`) onto `vf3_native_aim`: the flat RAM, the
 * FR bank, the register file and FPUL.
 *
 * A self-contained FP leaf (call-free): r4 -> object (word counter at +0x1E,
 * word table value at +0x1C, floats at +0x10 / +0x0C / +0x14), r5 -> flag
 * word, r6 / r7 -> two halfword tables, [the caller's sp] -> a third, fr4 /
 * fr5 = speeds.  It steps a looping frame counter and the two floats it
 * drives.  See the readable port's header comment for the full reading.
 *
 * The float arithmetic goes through the round-toward-zero + FTZ wrappers (the
 * corpus FPSCR 0x00024001 - RM=truncate and FTZ - is in force), so the stored
 * floats match the guest bit for bit; the two fused multiply-adds (the
 * `fmac`s) use `fmaf` so they round once.  See
 * docs/re/native_frame_counter_step.md. */
#include "frame_counter_step.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

#define LIT_ADVANCE 0xBAEBEDFAu     /* -0.0018f */
#define LIT_FLOOR   0xBBC49BA5u     /* -0.006f */
#define LIT_SCALE   0x3D03126Eu     /* 0.032f */

/* ---- round-toward-zero + FTZ wrappers (as extent_flip.c) ---- */
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
static inline float fadd(vf3_native_aim *a, float x, float y) { return fop(a, x, y, '+'); }
static inline float fmul(vf3_native_aim *a, float x, float y) { return fop(a, x, y, '*'); }
static inline float fma0(vf3_native_aim *a, float x, float y, float acc)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = fmaf(x, y, acc);
    fesetround(saved);
    return flz(a, z);
}

static uint32_t sext16(vf3_native_aim *a, uint32_t addr)
{
    return (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, addr);
}

void vf3_native_frame_counter_step(vf3_native_aim *a)
{
    const uint32_t sp0 = R(15), obj = R(4), flags_at = R(5);
    const uint32_t saved_r13 = R(13);

    vf3_aim_set_u32(a, sp0 - 4u, saved_r13);        /* push r13 */
    F(8) = vf3_aim_fbits(LIT_ADVANCE);
    F(7) = vf3_aim_fbits(LIT_FLOOR);

    const uint32_t counter = sext16(a, obj + 0x1Eu) - 1u;
    R(1) = counter;
    if ((int32_t)counter < 0) {
        R(2) = vf3_aim_u32(a, flags_at) & 0xFFFFFFFEu;
        R(3) = 0xFFFFFFFEu;
        vf3_aim_set_u32(a, flags_at, R(2));
        R(0) = sext16(a, obj + 0x1Eu);              /* the word read that started */
        a->sr &= ~1u;                               /* cmp/pz false: T clear */
        R(13) = vf3_aim_u32(a, sp0 - 4u);
        return;
    }

    vf3_aim_set_u16(a, obj + 0x1Eu, (uint16_t)counter);
    const uint32_t flags = vf3_aim_u32(a, flags_at);
    R(13) = 31;
    R(1) = counter & 31u;
    uint32_t table;
    if (flags & 2u)      table = R(6);
    else if (flags & 4u) table = vf3_aim_u32(a, sp0);
    else                 table = R(7);
    R(5) = table;
    R(0) = (counter & 31u) << 1;
    R(5) = sext16(a, table + R(0));
    R(0) = R(5);
    vf3_aim_set_u16(a, obj + 0x1Cu, (uint16_t)R(5));

    R(0) = 16;
    F(6) = vf3_aim_fbits(vf3_aim_u32(a, obj + 0x10u));
    F(6) = fadd(a, F(6), F(8));                     /* += -0.0018 */
    F(6) = (F(7) > F(6)) ? F(7) : F(6);             /* fcmp/gt FR6,FR7: floor at FR7 */
    F(3) = 0;
    const int still = (F(4) == 0.0f);               /* fcmp/eq FR3,FR4: fr4 == 0 */
    a->sr = (a->sr & ~1u) | (still ? 1u : 0u);
    vf3_aim_set_u32(a, obj + 0x10u, vf3_aim_ubits(F(6)));
    if (!still) {
        R(0) = 12;
        R(3) = 31;
        F(8) = vf3_aim_fbits(vf3_aim_u32(a, obj + 0x0Cu));
        F(7) = vf3_aim_fbits(vf3_aim_u32(a, obj + 0x14u));
        R(5) = sext16(a, obj + 0x1Eu) & 31u;
        R(3) = 31u - R(5);
        R(5) = R(3);
        a->fpul = R(5);
        F(2) = (float)(int32_t)R(5);                /* float fpul, fr2 */
        F(6) = F(2);                                /* FMOV(6,2) */
        F(2) = vf3_aim_fbits(LIT_SCALE);
        F(6) = fmul(a, F(6), F(2));                 /* fr6 *= 0.032 */
        F(0) = F(6);                                /* FMOV(0,6) */
        F(8) = fma0(a, F(0), F(4), F(8));           /* fr8 += fr0*fr4 */
        F(7) = fma0(a, F(0), F(5), F(7));           /* fr7 += fr0*fr5 */
        vf3_aim_set_u32(a, obj + 0x0Cu, vf3_aim_ubits(F(8)));
        R(0) = 20;
        vf3_aim_set_u32(a, obj + 0x14u, vf3_aim_ubits(F(7)));
    }
    R(13) = vf3_aim_u32(a, sp0 - 4u);
}
