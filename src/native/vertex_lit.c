/* vertex_lit.c - SH-4 0x8C047EA0 (vertex_lit), natively.
 *
 * A plain-C transcription of the readable port src/fight/vertex_lit.c
 * (`vf3_vertex_lit_entry`) onto `vf3_native_aim`.  The guest keeps the current
 * transform (XMTRX) in the XF bank - v[37..52] in a readable state, `a->xm[16]`
 * here - and the FR bank in v[21..36], `a->fr[16]` here.
 *
 * A self-contained FP leaf (call-free - the only guest FPU primitives are
 * ftrv, fipr, fdiv and plain fmul/fadd/fsub, reproduced with the matrix
 * transform, dot products and float arithmetic).  The caller leaves r4
 * pointing at a strip vertex record: position x, y, z at +0 (transformed by
 * XMTRX as (x, y, z, 1)), a vector at +12 (stored FR2, FR0, FR1 order; used
 * raw), then two words at +24 / +28 that go to r1 / r2.  r8 selects how many
 * squarings the specular term gets, r12 is the clip value, and FV12 and FV8
 * are two vectors the caller left in the FP registers.
 *
 *   FR3 = FV0 . FV12 (diffuse), FR2 = FR15 + max(FR3, 0).
 *   r8 > 0: FR11 = FV0 . FV8 (a cosine).  FR11 is squared; if it is positive,
 *           doubled (2c^2) and, when above 1, reduced by 1 and squared again;
 *           FR3 then collects that term and the power ladder below runs from
 *           the slot chosen by r8 (a chain of squarings of FR3 / FR11 that
 *           ends in a multiply into FR3).
 *   r8 < 0: FR2 = 1.0;  r8 == 0: nothing more.
 *   The routine ends with T = (r12 > the transformed w, as unsigned bits) and
 *   r4 = record + 32.  r0 holds w.
 *
 * On return FR0..FR7 and FR11 hold the lighting state; XMTRX, FR8..FR10 and
 * FR12..FR15 are untouched.  r1 = the record's word at +24, r2 = its word at
 * +28, r4 = record + 32, r0 = FPUL = the transformed w.  See docs/re/native_vertex_lit.md. */
#include "vertex_lit.h"

#include "aim_math.h"

#include <stdint.h>

#include <fenv.h>

static const float ONE = 1.0f;

/* dot: the guest's ftrv/fipr accumulate the four products in a volatile
 * double, exactly like sh4_fpu.c's `dot` (the accumulate, not each term, is
 * the extension point).  Replicate that so the transformed w that lands in
 * r0/fpul is bit-exact, not off by one ulp. */
static float dot4(vf3_native_aim *a, const float b[4], const float c[4])
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile double sum = (double)b[0] * (double)c[0];
    for (unsigned i = 1; i < 4; ++i) sum += (double)b[i] * (double)c[i];
    float r = (float)sum;
    fesetround(saved);
    return r;
}

/* ftrv: out[r] = sum_k xm[4k+r] * v[k] (column-major XMTRX) */
static void ftrv(vf3_native_aim *a)
{
    float src[4] = { a->fr[4], a->fr[5], a->fr[6], a->fr[7] };
    float out[4];
    for (int r = 0; r < 4; ++r) {
        float row[4] = { a->xm[r], a->xm[r + 4], a->xm[r + 8], a->xm[r + 12] };
        out[r] = dot4(a, row, src);
    }
    for (int r = 0; r < 4; ++r) a->fr[4 + r] = out[r];
}

/* fipr: dot of two 4-vectors, guest double-accumulate */
static float fipr(vf3_native_aim *a, const float *x, const float *y)
{
    return dot4(a, x, y);
}

int vf3_native_vertex_lit(vf3_native_aim *a)
{
    const uint32_t p = a->r[4];
    const int32_t sel = (int32_t)a->r[8];
    const uint32_t clip = a->r[12];

    /* load the position and the raw vector */
    a->fr[4] = vf3_aim_fbits(vf3_aim_u32(a, p));
    a->fr[5] = vf3_aim_fbits(vf3_aim_u32(a, p + 4));
    a->fr[6] = vf3_aim_fbits(vf3_aim_u32(a, p + 8));
    a->fr[7] = ONE;
    a->fr[2] = vf3_aim_fbits(vf3_aim_u32(a, p + 12));
    a->fr[0] = vf3_aim_fbits(vf3_aim_u32(a, p + 16));
    a->fr[1] = vf3_aim_fbits(vf3_aim_u32(a, p + 20));

    ftrv(a);                                    /* FR4..FR7 = xm * (x,y,z,1) */
    a->fr[3] = 0.0f;
    a->r[1] = vf3_aim_u32(a, p + 24);
    a->r[2] = vf3_aim_u32(a, p + 28);
    a->r[4] = p + 32;

    /* fipr(FV12, FV0) -> FR3 : the diffuse term.  FV0 = FR0..FR3. */
    a->fr[3] = fipr(a, &a->fr[12], &a->fr[0]);

    a->fpul = vf3_aim_ubits(a->fr[7]);          /* save the transformed w */
    a->fr[7] = ONE;
    {
        const int saved = fegetround();
        fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
        volatile float q = a->fr[7] / a->fr[4];
        fesetround(saved);
        a->fr[7] = q;                           /* FR7 = 1 / transformed x */
    }
    a->fr[11] = 0.0f;
    const int lit = a->fr[3] > a->fr[11];       /* FR3 > 0 */
    a->r[0] = a->fpul;                          /* = the transformed w */
    a->fr[4] = vf3_aim_fbits(a->fpul);          /* FR4 = the transformed w */
    a->fr[11] = fipr(a, &a->fr[0], &a->fr[8]);  /* FR11 = FV0 . FV8 */
    a->fr[2] = a->fr[15];                       /* FR2 = FR15 (before diffuse) */
    if (lit) a->fr[2] += a->fr[3];              /* FR2 = FR15 + max(FR3, 0) */
    a->fr[3] = 0.0f;

    if (sel <= 0) {
        if (sel < 0) a->fr[2] = ONE;            /* r8 < 0: FR2 = 1.0 */
        goto done;
    }
    a->fr[0] = ONE;
    {
        const int positive = a->fr[11] > a->fr[3];   /* FR11 > 0 */
        a->fr[11] = a->fr[11] * a->fr[11];
        if (!positive) goto done;
    }
    a->fr[11] = a->fr[11] + a->fr[11];          /* 2c^2 */
    {
        const int above_one = a->fr[11] > a->fr[0];  /* 2c^2 > 1 */
        a->fr[11] = a->fr[11] - a->fr[0];
        if (!above_one) goto done;
    }
    a->fr[11] = a->fr[11] * a->fr[11];
    a->fr[3] = a->fr[3] + a->fr[11];

    /* the power ladder: which chain of squarings runs is chosen by sel
     * (the braf r8 offset).  Reproduced as a switch on the offset. */
    switch (sel) {
    case 0x00: case 0x04: goto done;
    case 0x08: a->fr[3] = a->fr[3] * a->fr[3]; goto done;
    case 0x0C: a->fr[11] = a->fr[11] * a->fr[11]; goto l2a;
    case 0x10: a->fr[3] = a->fr[3] * a->fr[3]; goto l40;
    case 0x14: a->fr[11] = a->fr[11] * a->fr[11]; goto l20;
    case 0x18: a->fr[11] = a->fr[11] * a->fr[11]; goto l28;
    case 0x1C: a->fr[11] = a->fr[11] * a->fr[11]; goto l1e;
    case 0x20: a->fr[3] = a->fr[3] * a->fr[3]; goto l3e;
    case 0x24: a->fr[3] = a->fr[3] * a->fr[3]; goto l3c;
    case 0x28: a->fr[3] = a->fr[3] * a->fr[3]; goto l3a;
    case 0x2C: goto l1e;
    case 0x2E: goto l20;
    case 0x30: goto l22;
    case 0x32: goto done;
    case 0x36: goto l28;
    case 0x38: goto l2a;
    case 0x3A: goto done;
    case 0x48: goto l3a;
    case 0x4A: goto l3c;
    case 0x4C: goto l3e;
    case 0x4E: goto l40;
    case 0x50: goto done;
    default: goto unsupported;     /* a braf target the table does not cover */
    }
l1e: a->fr[3] = a->fr[3] * a->fr[11];           /* fallthrough */
l20: a->fr[11] = a->fr[11] * a->fr[11];          /* fallthrough */
l22: a->fr[3] = a->fr[3] * a->fr[11]; goto done;
l28: a->fr[3] = a->fr[3] * a->fr[11];            /* fallthrough */
l2a: a->fr[3] = a->fr[3] * a->fr[11]; goto done;
l3a: a->fr[3] = a->fr[3] * a->fr[3];             /* fallthrough */
l3c: a->fr[3] = a->fr[3] * a->fr[3];             /* fallthrough */
l3e: a->fr[3] = a->fr[3] * a->fr[3];             /* fallthrough */
l40: a->fr[3] = a->fr[3] * a->fr[3];             /* fallthrough */

done:
    a->sr = (a->sr & ~1u) | ((clip > a->r[0]) ? 1u : 0u);
    return 1;

unsupported:
    return 0;
}
