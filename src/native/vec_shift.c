/* vec_shift.c - SH-4 0x8C0748E0: the vec-shift, natively.
 *
 * A plain-C transcription of the readable port src/fight/vec_shift.c
 * (`vf3_vec_shift_entry`) onto `vf3_native_aim`: the flat RAM, the FR bank
 * and the register file.
 *
 * A self-contained FP leaf (call-free, no stack frame, no tail-transfer).
 * r4 -> object.  The offset (x, y, z) lives at +0x13A8 / +0x13AC / +0x13B0
 * and is added to the vec3 at +0x1488; the point-record pointer at +0x138C
 * then walks 0x150 bytes (28 vec3s, 12 bytes each) and every vec3 on the way
 * gets the same offset added.
 *
 * No frame, nothing saved.  After the run: r0 = 8, r5 = r6 = the end pointer
 * (one past the last point record), and SR's T bit is set.  r1..r4,
 * r7..r15, the stack pointer and pr are untouched.
 *
 * The FP adds go through the round-toward-zero + FTZ wrappers the other FP
 * native ports use (the corpus FPSCR 0x00024001 sets RM=truncate and FTZ),
 * so the stored floats match the guest bit for bit.
 *
 * See docs/re/native_vec_shift.md. */
#include "vec_shift.h"

#include <fenv.h>
#include <stdint.h>

#define R(n) (a->r[(n)])

#define OFFSET      0x13A8u
#define POINTS_PTR  0x138Cu
#define POSITION    0x1488u
#define POINTS_LEN  0x150u
#define POINT_STRIDE 12u

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* ---- round-toward-zero + FTZ wrappers (as float_scale.c) ---- */
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

/* add the offset vec (fr4, fr5, fr6) to the vec3 at addr, through the FR
 * bank as the original does */
static void add_offset(vf3_native_aim *a, uint32_t addr)
{
    float f;
    f = vf3_aim_fbits(vf3_aim_u32(a, addr));      a->fr[3] = fadd(a, f, a->fr[4]); vf3_aim_set_u32(a, addr, vf3_aim_ubits(a->fr[3]));
    f = vf3_aim_fbits(vf3_aim_u32(a, addr + 4));  a->fr[2] = fadd(a, f, a->fr[5]); vf3_aim_set_u32(a, addr + 4, vf3_aim_ubits(a->fr[2]));
    f = vf3_aim_fbits(vf3_aim_u32(a, addr + 8));  a->fr[3] = fadd(a, f, a->fr[6]); vf3_aim_set_u32(a, addr + 8, vf3_aim_ubits(a->fr[3]));
}

void vf3_native_vec_shift(vf3_native_aim *a)
{
    const uint32_t obj = R(4);

    a->fr[4] = vf3_aim_fbits(vf3_aim_u32(a, obj + OFFSET));
    a->fr[5] = vf3_aim_fbits(vf3_aim_u32(a, obj + OFFSET + 4));
    a->fr[6] = vf3_aim_fbits(vf3_aim_u32(a, obj + OFFSET + 8));

    /* r5 = the points pointer, r6 = one past the 0x150-byte run */
    /* (the guest computes both; see below) */

    /* the position vec3 gets the offset first */
    add_offset(a, obj + POSITION);
    R(0) = 8;

    /* r5 = [obj+POINTS_PTR]; r6 = r5 + POINTS_LEN.  T = (r5 == r6). */
    R(5) = vf3_aim_u32(a, obj + POINTS_PTR);
    R(6) = R(5) + POINTS_LEN;
    set_t(a, R(5) == R(6));

    if (R(5) != R(6)) {
        do {
            add_offset(a, R(5));
            R(5) += POINT_STRIDE;
        } while (R(5) != R(6));
        a->sr |= 1u;   /* SET_T(1) */
    }
}
