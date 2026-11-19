/* point_wrap.c - SH-4 0x8C09F5F8: clamp a point into the ring's period, natively.
 *
 * Plain-C transcription of the readable port src/fight/point_wrap.c
 * (`vf3_point_wrap_entry`).  The leaf clamps a three-float point to
 * +-655360.0, folds x and z back into [fr8..fr4] by the period fr9, reflects
 * y about fr5 when a component is still large, and writes the three
 * components back.  Nothing happens when the global word at 0x0C29B864 has a
 * bit of 0x0C000000 set.
 *
 *   r4 = the point (x, y, z).  It takes fr4..fr9 as inputs (the period's
 *   bounds and thresholds, established by the wrapper 0x8C09F432) and leaves
 *   r0 = the point plus 12, r15 = the entry sp, pr untouched.
 *
 * All the arithmetic is add/sub, compare and sign-masking on values that are
 * exactly representable floats (coordinates, the +-655360 bounds and the
 * 65536 period), so plain C float operations reproduce the guest bit for
 * bit under FPSCR round-toward-zero.  See docs/re/native_point_wrap.md and
 * docs/re/pose_post.md. */
#include "pose_callees.h"

#include <stdint.h>

#include "aim_math.h"

#define R(n) (r[(n)])

/* the global that gates the whole body */
#define GATE_ADDR 0x0C29B864u
#define GATE_MASK 0x0C000000u

#define FABS_BITS(f)   vf3_aim_fbits(vf3_aim_ubits((f)) & 0x7fffffffu)
#define FNEG_BITS(f)   vf3_aim_fbits(vf3_aim_ubits((f)) ^ 0x80000000u)

static void clamp_fr(vf3_native_aim *a, int x)
{
    int t = a->fr[x] > a->fr[1];              /* GT(1,x) */
    a->sr = (a->sr & ~1u) | (t ? 1u : 0u);
    if (t) { a->fr[x] = a->fr[1]; return; }
    t = a->fr[0] > a->fr[x];                  /* GT(x,0): fr[0] > fr[x] */
    a->sr = (a->sr & ~1u) | (t ? 1u : 0u);
    if (t) { a->fr[x] = a->fr[0]; return; }
    t = a->fr[x] > a->fr[1];
    a->sr = (a->sr & ~1u) | (t ? 1u : 0u);
    if (t) { a->fr[x] = a->fr[1]; return; }
    t = a->fr[0] > a->fr[x];
    a->sr = (a->sr & ~1u) | (t ? 1u : 0u);
    if (!t) return;
    a->fr[x] = a->fr[1];
}

static void fold(vf3_native_aim *a, int x)
{
    for (;;) {
        int t = a->fr[8] > a->fr[x];          /* GT(x,8): fr[8] > fr[x] */
        a->sr = (a->sr & ~1u) | (t ? 1u : 0u);
        if (t) {
            t = a->fr[x] > a->fr[6];          /* GT(6,x) */
            a->sr = (a->sr & ~1u) | (t ? 1u : 0u);
            if (t) return;
            a->fr[3] = a->fr[x];              /* FMOV(3,x) */
            a->fr[x] = a->fr[9];              /* FMOV(x,9) */
            a->fr[x] = a->fr[x] + a->fr[3];   /* FADD(x,3) */
            continue;
        }
        t = a->fr[x] > a->fr[4];              /* GT(4,x) */
        a->sr = (a->sr & ~1u) | (t ? 1u : 0u);
        if (!t) return;
        a->fr[x] = a->fr[x] - a->fr[9];       /* FSUB(x,9) */
    }
}

/* fr[4..9] = the caller's inputs (established by the wrapper) */
void vf3_native_point_wrap(vf3_native_aim *a, uint32_t sp, uint32_t pt)
{
    uint32_t r[16];
    for (int i = 0; i < 16; ++i) r[i] = a->r[i];
    R(4) = pt; R(15) = sp;
    const uint32_t f = sp - 8u;

    /* the gate: proceed only when no 0x0C bit is set in the global */
    const uint32_t gate = vf3_aim_u32(a, GATE_ADDR);
    int t = (gate & GATE_MASK) == 0u;
    a->sr = (a->sr & ~1u) | (t ? 1u : 0u);
    if (!t) { R(0) = pt; R(15) = sp; a->r[0] = R(0); a->r[15] = R(15); return; }

    /* read the three components and the bounds */
    a->fr[10] = vf3_aim_fbits(vf3_aim_u32(a, pt));       /* x */
    a->fr[1]  = 655360.0f;                               /* fr1 = +655360 */
    R(6) = R(4); R(5) = R(4);
    R(6) += 8u;                                          /* the z pointer */
    t = a->fr[10] > a->fr[1];                            /* BT/S: fr10 > fr1 */
    a->sr = (a->sr & ~1u) | (t ? 1u : 0u);
    R(5) += 4u;                                          /* the y pointer */
    a->fr[2] = vf3_aim_fbits(vf3_aim_u32(a, R(5)));      /* y */
    a->fr[11] = vf3_aim_fbits(vf3_aim_u32(a, R(6)));     /* z */
    a->fr[0] = -655360.0f;                               /* fr0 = -655360 */
    if (t) { a->fr[10] = a->fr[1]; goto clamp_z; }
    clamp_fr(a, 10);
clamp_z:
    clamp_fr(a, 11);                                          /* z */
    clamp_fr(a, 2);                                           /* y */

refold:
    fold(a, 10);                                          /* x */
    fold(a, 11);                                          /* z */
    a->fr[3] = FABS_BITS(a->fr[10]);                      /* |x| */
    t = a->fr[7] > a->fr[3];                              /* GT(3,7): fr7 > |x| */
    a->sr = (a->sr & ~1u) | (t ? 1u : 0u);
    vf3_aim_set_u32(a, f + 4u, vf3_aim_ubits(a->fr[3]));  /* the delay slot */
    if (t) goto store;
    a->fr[3] = FABS_BITS(a->fr[11]);                      /* |z| */
    t = a->fr[7] > a->fr[3];                              /* GT(3,7): fr7 > |z| */
    a->sr = (a->sr & ~1u) | (t ? 1u : 0u);
    vf3_aim_set_u32(a, f, vf3_aim_ubits(a->fr[3]));
    if (t) goto store;

    /* reflect y about fr5 and refold */
    a->fr[2] = a->fr[2] - a->fr[5];                       /* y -= fr5 */
    a->fr[10] = a->fr[10] - a->fr[4];                     /* x -= fr4 */
    a->fr[11] = a->fr[11] - a->fr[4];                     /* z -= fr4 */
    a->fr[2] = FNEG_BITS(a->fr[2]);                       /* y = -y */
    a->fr[3] = a->fr[2];                                  /* fr3 = y */
    a->fr[2] = a->fr[5];                                  /* fr2 = fr5 */
    a->fr[2] = a->fr[2] + a->fr[3];                       /* fr2 = fr5 + y */
    goto refold;

store:
    vf3_aim_set_u32(a, R(4), vf3_aim_ubits(a->fr[10]));   /* x */
    R(4) += 12u;
    vf3_aim_set_u32(a, R(5), vf3_aim_ubits(a->fr[2]));    /* y */
    vf3_aim_set_u32(a, R(6), vf3_aim_ubits(a->fr[11]));   /* z */

    R(0) = R(4);
    R(15) = sp;
    a->r[0] = R(0);
    a->r[15] = R(15);
}
