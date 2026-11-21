/* vec_offset.c - SH-4 0x8C074702 (vec_offset) / 0x8C074854 (vec_offset3),
 * natively.
 *
 * Plain-C transcriptions of the readable ports src/fight/vec_offset.c
 * (`vf3_vec_offset_entry`) and src/fight/vec_offset3.c
 * (`vf3_vec_offset3_entry`) onto `vf3_native_aim`: the flat RAM and the FR
 * bank.
 *
 * Self-contained FP leaves (call-free, no stack frame).  vec_offset: r4 =
 * record; the offset is the two floats at +0x13A8 (x) and +0x13B0 (z); the
 * record's own position at +0x1488 / +0x1490 gets it added, then every point
 * of the list that begins at the pointer stored at +0x138C (0x150 bytes of
 * 12-byte points) gets the same offset on x and z.  vec_offset3: r4 = record;
 * the offset is the three floats at +0x1488 .. +0x1490; the record's own
 * vector at +0x10 .. +0x18 gets it added, then the 25 points of 64 bytes each
 * starting at +0x180 get it added at +0x30 / +0x34 / +0x38.
 *
 * The float adds go through the round-toward-zero + FTZ wrapper (the corpus
 * FPSCR 0x00024001 - RM=truncate and FTZ - is in force), so the stored floats
 * match the guest bit for bit.
 *
 * See docs/re/native_vec_offset.md. */
#include "vec_offset.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static float bits2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* ---- round-toward-zero + FTZ wrapper (as float_scale.c/atan_turn.c) ---- */
static inline float flz(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float fadd(vf3_native_aim *a, float x, float y)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = x + y;
    fesetround(saved);
    return flz(a, z);
}

static float load_f(vf3_native_aim *a, uint32_t addr) { return bits2f(vf3_aim_u32(a, addr)); }
static void store_f(vf3_native_aim *a, uint32_t addr, float f) { vf3_aim_set_u32(a, addr, fbits(f)); }

void vf3_native_vec_offset(vf3_native_aim *a)
{
    R(0) = 0x13A8u;
    R(6) = 0x150u;
    F(4) = load_f(a, R(4) + R(0));
    R(0) += 8;
    F(5) = load_f(a, R(4) + R(0));
    R(0) -= 36;
    R(5) = vf3_aim_u32(a, R(4) + R(0));
    R(0) = 0x1488u;
    R(6) += R(5);
    F(3) = load_f(a, R(4) + R(0));
    set_t(a, R(5) == R(6));
    F(3) = fadd(a, F(3), F(4));
    store_f(a, R(4) + R(0), F(3));
    R(0) += 8;
    F(2) = load_f(a, R(4) + R(0));
    F(2) = fadd(a, F(2), F(5));
    store_f(a, R(4) + R(0), F(2));
    if (R(5) != R(6)) {
        do {
            R(0) = 8;
            F(3) = load_f(a, R(5));
            F(3) = fadd(a, F(3), F(4));
            store_f(a, R(5), F(3));
            F(2) = load_f(a, R(5) + R(0));
            F(2) = fadd(a, F(2), F(5));
            store_f(a, R(5) + R(0), F(2));
            R(5) += 12;
            set_t(a, R(5) == R(6));
        } while (R(5) != R(6));
    }
}

void vf3_native_vec_offset3(vf3_native_aim *a)
{
    R(0) = 0x1488u;
    R(5) = 0x180u;
    F(4) = load_f(a, R(4) + R(0));
    R(0) += 4;
    F(5) = load_f(a, R(4) + R(0));
    R(0) += 4;
    F(6) = load_f(a, R(4) + R(0));
    R(0) = 16;
    F(3) = load_f(a, R(4) + R(0));
    R(5) += R(4);
    R(6) = 0x640u;
    F(3) = fadd(a, F(3), F(4));
    R(6) += R(5);
    set_t(a, R(5) == R(6));
    store_f(a, R(4) + R(0), F(3));
    R(0) = 20;
    F(2) = load_f(a, R(4) + R(0));
    F(2) = fadd(a, F(2), F(5));
    store_f(a, R(4) + R(0), F(2));
    R(0) = 24;
    F(3) = load_f(a, R(4) + R(0));
    F(3) = fadd(a, F(3), F(6));
    store_f(a, R(4) + R(0), F(3));
    if (R(5) != R(6)) {
        do {
            R(0) = 48;
            F(3) = load_f(a, R(5) + R(0));
            F(3) = fadd(a, F(3), F(4));
            store_f(a, R(5) + R(0), F(3));
            R(0) = 52;
            F(2) = load_f(a, R(5) + R(0));
            F(2) = fadd(a, F(2), F(5));
            store_f(a, R(5) + R(0), F(2));
            R(0) = 56;
            F(3) = load_f(a, R(5) + R(0));
            F(3) = fadd(a, F(3), F(6));
            store_f(a, R(5) + R(0), F(3));
            R(5) += 64;
            set_t(a, R(5) == R(6));
        } while (R(5) != R(6));
    }
}
