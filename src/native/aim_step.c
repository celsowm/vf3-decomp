/* aim_step.c - SH-4 0x8C093768: push a point along the direction between two
 * points, natively.
 *
 * A plain-C transcription of the readable port src/fight/aim_step.c
 * (`vf3_aim_step_entry`).  It operates on `vf3_native_aim`: the flat RAM, the
 * FR bank and the register file.  A self-contained FP leaf (call-free) that
 * keeps a small frame (r14, r13 and FR15 saved) and restores them.
 *
 *   r4 -> a context whose float at +36 is the step length,
 *   r5 -> point A (vec3, updated in place),
 *   r6 -> point B (vec3),
 *   r7 -> vec3 receiving the unit direction.
 *
 *   d = A - B is stored to *r7; the squared length of d comes from `fipr`
 *   (the SH-4 inner product, accumulated in double).  The inverse length
 *   comes from `fsrra`, and is zero when d is zero or its squared length is
 *   below the pool's epsilon (1e-7).  Then A = d * (inverse length * step) +
 *   B, and *r7 = d * inverse length, so A ends up the step length away from
 *   B on the same line and *r7 is the unit direction from B to A.
 *
 * This leaf runs under **round-to-nearest and no FTZ** (the readable test's
 * FPSCR is 0, like the sibling move_cap leaf), so it uses plain C float
 * multiply/add, `1/sqrtf` for the `fsrra`, and double accumulation for the
 * `fipr` inner product.
 *
 * Details the port has to keep: the inverse length is zero when the squared
 * length is below the epsilon **or** zero (the guest compares `sq != 0`
 * before the epsilon test); the second point B is read back from the frame
 * slot, not from r6 (r6 is never re-read); and the final A is the scaled d
 * (stored first) plus B, while *r7 gets the unit direction.
 *
 * See docs/re/native_aim_step.md. */
#include "aim_step.h"

#include <math.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

/* the literal pool */
#define POOL_LIT 0x0c0937d0u   /* the squared length the guest will not measure */

/* the epsilon, as its raw bits */
#define LIT_BITS 0x33d6bf94u

/* the step length offset in the context */
#define POOL_STEP 36u

static float load_f(vf3_native_aim *a, uint32_t addr)
{
    uint32_t u = vf3_aim_u32(a, addr);
    float f;
    memcpy(&f, &u, 4);
    return f;
}

static void store_f(vf3_native_aim *a, uint32_t addr, float f)
{
    uint32_t u;
    memcpy(&u, &f, 4);
    vf3_aim_set_u32(a, addr, u);
}

/* the SH-4 inner product over a[0..3] . b[0..3], accumulated in double and
 * flushed once (fipr) */
static float fipr4(float a0, float a1, float a2, float a3)
{
    volatile double sum = (double)a0 * (double)a0;
    sum += (double)a1 * (double)a1;
    sum += (double)a2 * (double)a2;
    sum += (double)a3 * (double)a3;
    return (float)sum;
}

/* the SH-4 approximate reciprocal square root (fsrra) */
static float fsrra(float v)
{
    return 1.0f / sqrtf(v);
}

void vf3_native_aim_step(vf3_native_aim *a)
{
    const uint32_t sp0 = R(15);
    const uint32_t saved_r14 = R(14);
    const uint32_t saved_r13 = R(13);
    const uint32_t saved_f15 = vf3_aim_ubits(F(15));
    const uint32_t ctx = R(4), A = R(5), B = R(6), out = R(7);
    uint32_t f = sp0 - 20u;

    /* save r14, r13, FR15 and set up the frame */
    vf3_aim_set_u32(a, sp0 - 4u, saved_r14);
    vf3_aim_set_u32(a, sp0 - 8u, saved_r13);
    vf3_aim_set_u32(a, sp0 - 12u, saved_f15);
    R(14) = out;
    R(13) = A;
    R(15) = f;
    vf3_aim_set_u32(a, f + 4u, ctx);
    vf3_aim_set_u32(a, f, B);

    /* d = A - B  (stored to *out) */
    F(0) = load_f(a, A);
    F(3) = load_f(a, B);
    F(1) = load_f(a, A + 4u);
    F(4) = load_f(a, B + 4u);
    F(0) = F(0) - F(3);            /* FSUB(0,3) */
    F(2) = load_f(a, A + 8u);
    F(5) = load_f(a, B + 8u);
    F(1) = F(1) - F(4);            /* FSUB(1,4) */
    F(2) = F(2) - F(5);            /* FSUB(2,5) */
    store_f(a, out + 8u, F(2));
    store_f(a, out + 4u, F(1));
    store_f(a, out, F(0));

    /* the squared length of d, via fipr (double accumulation), into F3 */
    F(0) = load_f(a, out);
    F(1) = load_f(a, out + 4u);
    F(2) = load_f(a, out + 8u);
    F(3) = 0;
    F(3) = fipr4(F(0), F(1), F(2), F(3));
    F(0) = F(3);                  /* FMOV(0,3) */
    F(3) = 0;
    F(15) = F(0);                 /* FMOV(15,0): F15 = sq */

    /* the inverse length: zero unless sq is non-zero and at-or-above eps */
    if (F(15) != F(3)) {          /* sq != 0 */
        R(0) = POOL_LIT;
        F(2) = 0;
        {
            uint32_t u = LIT_BITS;
            memcpy(&F(2), &u, 4);
        }
        if (F(2) > F(15)) {       /* eps > sq -> inverse length 0 */
            F(15) = F(3);
        } else {
            F(15) = fsrra(F(15)); /* else 1/sqrt(sq) */
        }
    }

    /* the scaled direction: F4 = inverse length * step */
    R(3) = vf3_aim_u32(a, f + 4u);   /* ctx */
    R(0) = POOL_STEP;
    F(4) = F(15);                    /* FMOV(4,15): F4 = inverse length */
    F(3) = load_f(a, R(3) + POOL_STEP);
    F(4) = F(4) * F(3);              /* FMUL(4,3): F4 = invlen * step */

    /* A = d * (invlen * step), stored first */
    F(0) = load_f(a, out);
    F(1) = load_f(a, out + 4u);
    F(2) = load_f(a, out + 8u);
    F(2) = F(2) * F(4);              /* FMUL(2,4) */
    F(1) = F(1) * F(4);              /* FMUL(1,4) */
    F(0) = F(0) * F(4);              /* FMUL(0,4) */
    store_f(a, A + 8u, F(2));
    store_f(a, A + 4u, F(1));
    store_f(a, A, F(0));

    /* *out = d * inverse length (the unit direction); F4 reloaded */
    F(4) = F(15);                    /* FMOV(4,15) */
    F(0) = load_f(a, out);
    F(1) = load_f(a, out + 4u);
    F(2) = load_f(a, out + 8u);
    F(2) = F(2) * F(4);              /* FMUL(2,4) */
    F(1) = F(1) * F(4);              /* FMUL(1,4) */
    F(0) = F(0) * F(4);              /* FMUL(0,4) */
    store_f(a, out + 8u, F(2));
    store_f(a, out + 4u, F(1));
    store_f(a, out, F(0));

    /* A = d * (invlen * step) + B  (B re-read from the frame slot) */
    {
        const uint32_t bp = vf3_aim_u32(a, f);
        F(0) = load_f(a, A);
        F(3) = load_f(a, bp);
        F(1) = load_f(a, A + 4u);
        F(4) = load_f(a, bp + 4u);
        F(2) = load_f(a, A + 8u);
        F(5) = load_f(a, bp + 8u);
        F(0) = F(0) + F(3);          /* FADD(0,3) */
        F(2) = F(2) + F(5);          /* FADD(2,5) */
        F(1) = F(1) + F(4);          /* FADD(1,4) */
        store_f(a, A + 8u, F(2));
        store_f(a, A + 4u, F(1));
        store_f(a, A, F(0));

        R(4) = A;
        R(5) = bp + 12u;
    }

    /* restore the saved registers */
    R(14) = saved_r14;
    R(13) = saved_r13;
    {
        float x;
        memcpy(&x, &saved_f15, 4);
        F(15) = x;
    }
    R(15) = sp0;
}
