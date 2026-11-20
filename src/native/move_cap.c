/* move_cap.c - SH-4 0x8C08DD5C: the movement, capped at the maximum step,
 * natively.
 *
 * A plain-C transcription of the readable port src/fight/move_cap.c
 * (`vf3_move_cap_entry`).  It operates on `vf3_native_aim`: the flat RAM, the
 * FR bank and the register file.  A self-contained FP leaf that keeps a small
 * frame and restores r14.
 *
 * The function knows two positions: the one the object had at the start of the
 * frame (r4 and r5) and the one it has now (the two words r6 and r7 point at).
 * It moves the current position by the difference between them - but never by
 * more than the longest movement the literal pool holds.
 *
 *   dx = current.x - old.x        dy = current.y - old.y
 *   len = sqrt(dx*dx + dy*dy)
 *   if len is shorter than the maximum step, the whole difference is used;
 *   otherwise the difference is scaled down to the maximum step.
 *
 * The scaled difference is truncated to integers, and the truncated pair is
 * added to the old position, so the new position is written back to the two
 * words r6 and r7 point at.
 *
 * This leaf runs under **round-to-nearest and no FTZ** (the readable test's
 * FPSCR is 0), so it uses plain C float multiply/add, `fmaf` for the fused
 * multiply-add, and `1/sqrtf` for the `fsrra`.  It does **not** use the
 * toward-zero/FTZ wrappers the other FP leaves need.
 *
 * Details the port has to keep: the length comes from `fsrra`, the SH-4's
 * *approximate* reciprocal of the square root, so the port has to use the same
 * helper and not 1/sqrt in C; the factor is compared as an absolute value,
 * which the guest does by masking the sign bit off the float's bits; and the
 * guest only truncates the difference when it scales it, so a movement that is
 * short enough keeps the *integer* difference.
 *
 * See docs/re/native_move_cap.md. */
#include "move_cap.h"

#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* the literal pool */
#define POOL_EPSILON 0x0c08ddc8u   /* the squared length the guest will not measure */
#define POOL_MAXSTEP 0x0c08ddccu   /* the longest movement the function allows */

/* the float at a guest address, into the frame register (single width) */
static void fload(vf3_native_aim *a, unsigned n, uint32_t addr)
{
    uint32_t u = vf3_aim_u32(a, addr);
    memcpy(&F(n), &u, 4);
}

/* the frame register's bits */
static uint32_t fbits(vf3_native_aim *a, unsigned n)
{
    uint32_t u;
    memcpy(&u, &F(n), 4);
    return u;
}

/* ftrc: the truncated integer of the frame register, saturating at int32 */
static int32_t ftrc(vf3_native_aim *a, unsigned n)
{
    double d = (double)F(n);
    if (isnan(d) || d < -2147483648.0) return (int32_t)0x80000000u;
    if (d >= 2147483648.0) return (int32_t)0x7fffffffu;
    return (int32_t)d;
}

void vf3_native_move_cap(vf3_native_aim *a)
{
    const uint32_t sp = R(15);

    /* the guest saves r14 and reserves eight bytes */
    vf3_aim_set_u32(a, sp - 4u, R(14));
    R(15) = sp - 12u;

    /* the current position, and the difference since the old one */
    R(3) = vf3_aim_u32(a, R(6));
    vf3_aim_set_u32(a, R(15) + 4u, R(3));
    R(2) = vf3_aim_u32(a, R(7));
    R(1) = R(2);
    R(1) -= R(5);
    vf3_aim_set_u32(a, R(15), R(2));
    R(14) = vf3_aim_u32(a, R(15) + 4u);
    R(14) -= R(4);

    /* the difference as two floats */
    a->fpul = R(14);
    {
        const int32_t v = (int32_t)a->fpul;
        F(3) = (float)v;
    }
    a->fpul = R(1);
    {
        const int32_t v = (int32_t)a->fpul;
        F(2) = (float)v;
    }

    /* the squared length of the difference */
    F(4) = F(3);
    F(5) = F(3);
    F(4) = F(4) * F(5);
    fload(a, 3, POOL_EPSILON);
    F(0) = F(2);
    F(6) = F(2);
    F(4) = fmaf(F(0), F(6), F(4));
    F(7) = F(4);

    /* the inverse length - unless the difference is too short to measure, and
     * then the guest leaves it at zero */
    const int too_short = (F(3) > F(7));
    set_t(a, too_short);
    if (too_short) {
        F(7) = 0;
    } else {
        F(7) = 1.0f / sqrtf(F(7));
    }

    /* the squared length times the inverse length: the length */
    F(4) = F(4) * F(7);

    /* the factor the difference is scaled by */
    R(0) = POOL_MAXSTEP;
    fload(a, 7, POOL_MAXSTEP);
    F(3) = F(4);
    F(4) = F(7);
    F(4) = F(4) / F(3);

    /* and whether the movement has to be scaled at all: the factor has to be
     * below one, and the guest compares its absolute value */
    /* one, loaded as raw bits */
    {
        uint32_t one = 0x3f800000u;
        memcpy(&F(7), &one, 4);
    }
    {
        uint32_t bits = fbits(a, 4) & 0x7fffffffu;
        memcpy(&F(4), &bits, 4);         /* fabs, as a mask on the bits */
    }
    const int scale = (F(7) > F(4));
    set_t(a, scale);
    if (scale) {
        F(5) = F(5) * F(4);
        F(6) = F(6) * F(4);
        a->fpul = (uint32_t)ftrc(a, 5);
        R(14) = a->fpul;
        a->fpul = (uint32_t)ftrc(a, 6);
        R(1) = a->fpul;
    }

    /* the new position: the old one plus the movement */
    R(4) += R(14);
    vf3_aim_set_u32(a, R(15), R(4));
    R(4) = R(5);
    R(3) = vf3_aim_u32(a, R(15));
    R(15) += 4u;
    R(4) += R(1);
    R(15) += 4u;
    vf3_aim_set_u32(a, R(6), R(3));
    vf3_aim_set_u32(a, R(7), R(4));

    /* and the saved register goes back */
    R(14) = vf3_aim_u32(a, R(15));
    R(15) += 4u;
}
