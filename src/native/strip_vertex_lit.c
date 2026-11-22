/* strip_vertex_lit.c - SH-4 0x8C048F60 (strip_vertex_lit), natively.
 *
 * A plain-C transcription of the readable port src/fight/strip_vertex_lit.c
 * (`vf3_strip_vertex_lit_entry`) onto `vf3_native_aim`.  The guest keeps the
 * current transform (XMTRX) in the XF bank and the FR bank in v[21..36],
 * `a->fr[16]` here.
 *
 * A self-contained FP leaf (call-free - the only guest FPU primitives are
 * ftrv, fipr, fdiv and plain fmul/fadd/fsub/fmov, reproduced with the matrix
 * transform, dot products and float arithmetic).  It reads a strip of 32-byte
 * vertex records (r4), transforms each vertex through XMTRX, folds its
 * lighting (diffuse + the specular ladder selected by r8), and writes 32-byte
 * store-queue vertex blocks at r6 (r5 advancing 32 per vertex):
 *
 *   r4 -> the strip: a vertex count word (r9), then records of 32 bytes:
 *        bit 0 of a record's first word set = the vertex data is inline,
 *        otherwise word 1 is an offset (from record + 8) to it.  A vertex is
 *        (x, y, z, w) in FR4..7, a texture pair in FR0/FR1 and two attribute
 *        words (r1 / r2).  r6 is the store-queue write pointer (vertices are
 *        written backwards, so r6 is moved up before and down while writing),
 *        r5 advances 32, r8 selects the specular power ladder (4..40, 0 = no
 *        specular), FV12 (FR12..15) the light vector, FV8 (FR8..11) the half
 *        vector, FR15 the ambient the caller left.
 *
 *   FPSCR.SZ is 1 for the whole body (set on entry, cleared in the rts delay
 *   slot), so every FRn load or store moves a pair.
 *
 * See docs/re/native_strip_vertex_lit.md. */
#include "strip_vertex_lit.h"

#include "aim_math.h"

#include <stdint.h>

#include <fenv.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

enum {
    SZ_BIT = 0x00100000u, PR_BIT = 0x00080000u, ONE = 0x3F800000u,
    MAX_STEPS = 1000000, LADDER_MIN = 4, LADDER_MAX = 40,
};

static float fbits(uint32_t u) { return vf3_aim_fbits(u); }
static uint32_t ubits(float f) { return vf3_aim_ubits(f); }
static void set_t(vf3_native_aim *a, int c) { a->sr = (a->sr & ~1u) | (c ? 1u : 0u); }

/* dot: the guest's ftrv/fipr accumulate the four products in a volatile
 * double, exactly like sh4_fpu.c's `dot` (the accumulate, not each term, is
 * the extension point).  Replicate that so the transformed coordinates and
 * the lighting terms are bit-exact, not off by one ulp. */
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

/* ftrv: out[r] = sum_k xm[4k+r] * v[k] (column-major XMTRX); transforms
 * FR4..FR7 in place. */
static void ftrv(vf3_native_aim *a)
{
    float src[4] = { F(4), F(5), F(6), F(7) };
    float out[4];
    for (int r = 0; r < 4; ++r) {
        float row[4] = { a->xm[r], a->xm[r + 4], a->xm[r + 8], a->xm[r + 12] };
        out[r] = dot4(a, row, src);
    }
    for (int r = 0; r < 4; ++r) F(4 + r) = out[r];
}

/* fipr: dot of two 4-vectors, double-accumulate */
static float fipr(vf3_native_aim *a, const float *x, const float *y)
{
    return dot4(a, x, y);
}

/* a scalar multiply-add with the guest's rounding (FPSCR.RM) */
static float fmul(vf3_native_aim *a, float x, float y)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = x * y;
    fesetround(saved);
    return z;
}
static float fadd(vf3_native_aim *a, float x, float y)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = x + y;
    fesetround(saved);
    return z;
}
static float fsub(vf3_native_aim *a, float x, float y)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = x - y;
    fesetround(saved);
    return z;
}
static float fdiv(vf3_native_aim *a, float x, float y)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = x / y;
    fesetround(saved);
    return z;
}

/* fmov @r14+,FRn (a pair, SZ = 1 throughout) */
static void fld_post14(vf3_native_aim *a, int n)
{
    F(n) = fbits(vf3_aim_u32(a, R(14)));
    F(n + 1) = fbits(vf3_aim_u32(a, R(14) + 4));
    R(14) += 8;
}

/* fmov FRn,@-r6 (a pair) */
static void fst_pre6(vf3_native_aim *a, int n)
{
    R(6) -= 8;
    vf3_aim_set_u32(a, R(6), ubits(F(n)));
    vf3_aim_set_u32(a, R(6) + 4, ubits(F(n + 1)));
}

static void push6(vf3_native_aim *a, uint32_t v)
{
    R(6) -= 4;
    vf3_aim_set_u32(a, R(6), v);
}

/* The ladder slot r8 selects: the multiplies its chain of branches runs
 * before it rejoins at 0x8C048FF4. */
static void ladder(vf3_native_aim *a, uint32_t slot)
{
    switch (slot) {
    case 4:  break;
    case 8:  F(3) = fmul(a, F(3), F(3)); break;
    case 12: F(11) = fmul(a, F(11), F(11)); F(3) = fmul(a, F(3), F(11)); break;
    case 16: F(3) = fmul(a, F(3), F(3)); F(3) = fmul(a, F(3), F(3)); break;
    case 20: F(11) = fmul(a, F(11), F(11)); F(11) = fmul(a, F(11), F(11));
             F(3) = fmul(a, F(3), F(11)); break;
    case 24: F(11) = fmul(a, F(11), F(11)); F(3) = fmul(a, F(3), F(11));
             F(3) = fmul(a, F(3), F(11)); break;
    case 28: F(11) = fmul(a, F(11), F(11)); F(3) = fmul(a, F(3), F(11));
             F(11) = fmul(a, F(11), F(11)); F(3) = fmul(a, F(3), F(11)); break;
    case 32: F(3) = fmul(a, F(3), F(3)); F(3) = fmul(a, F(3), F(3));
             F(3) = fmul(a, F(3), F(3)); break;
    case 36: F(3) = fmul(a, F(3), F(3)); F(3) = fmul(a, F(3), F(3));
             F(3) = fmul(a, F(3), F(3)); F(3) = fmul(a, F(3), F(3)); break;
    default: F(3) = fmul(a, F(3), F(3)); F(3) = fmul(a, F(3), F(3));
             F(3) = fmul(a, F(3), F(3)); F(3) = fmul(a, F(3), F(3));
             F(3) = fmul(a, F(3), F(3)); break;   /* 40 */
    }
}

int vf3_native_strip_vertex_lit(vf3_native_aim *a)
{
    if ((a->fpscr & (SZ_BIT | PR_BIT)) || (a->fpscr & 3u) > 1u) return 0;
    if (R(8) != 0 && (R(8) < LADDER_MIN || R(8) > LADDER_MAX || (R(8) & 3u))) return 0;
    int steps = MAX_STEPS;

    R(3) = 3;
    R(9) = vf3_aim_u32(a, R(4));
    R(4) += 4;
    R(6) -= 32;
    R(0) = vf3_aim_u32(a, R(4));
    a->fpscr ^= SZ_BIT;                          /* SZ = 1 from here */
    set_t(a, (R(0) & 1u) == 0);
    R(14) = R(4);
    R(4) += 32;                                  /* bf/s delay slot */
    if (a->sr & 1u) {                            /* out-of-line record */
        R(14) = vf3_aim_u32(a, R(14) + 4);
        R(4) -= 24;
        R(14) += R(4);
    }

load_x:
    if (--steps < 0) return 0;
    fld_post14(a, 4);
load_z:
    fld_post14(a, 6);
    F(2) = 0;
tail_w:
    F(2) = fadd(a, F(2), F(7));                  /* FADD(2,7) */
    F(7) = fbits(ONE);
    R(6) += 64;
    F(3) = 0;
    R(5) += 32;
    fld_post14(a, 0);
    ftrv(a);                                     /* FR4..7 = xm * (x,y,z,w) */
    F(11) = 0;
    R(1) = vf3_aim_u32(a, R(14));
    R(14) += 4;
    R(3) -= 1;
    set_t(a, R(3) == 0);
    R(2) = vf3_aim_u32(a, R(14));
    R(14) += 4;
    R(0) = vf3_aim_u32(a, R(4));                 /* bt/s delay slot */
    if (a->sr & 1u) {                            /* the third vertex of the group */
        F(3) = fipr(a, &F(12), &F(0));           /* F3 = FV12 . FV0 (diffuse) */
        F(7) = fbits(ONE);
        F(7) = fdiv(a, F(7), F(4));              /* FR7 = 1 / FR4 */
        goto next_inline;
    }
    F(3) = fipr(a, &F(12), &F(0));               /* F3 = FV12 . FV0 (diffuse) */
    R(14) = vf3_aim_u32(a, R(4) + 4);
    set_t(a, (R(0) & 1u) == 0);
    F(7) = fbits(ONE);
    F(7) = fdiv(a, F(7), F(4));                  /* bf/s delay slot */
    if (!(a->sr & 1u)) goto next_inline;
    R(4) += 8;                                   /* the next record is out of line */
    {
        const int lit = F(3) > F(11);            /* GT(11,3): FR3 > FR11 */
        R(14) += R(4);
        a->fpul = ubits(F(15));
        F(11) = fipr(a, &F(0), &F(8));           /* F11 = FV0 . FV8 (cosine) */
        F(2) = fbits(a->fpul);
        if (lit) F(2) = fadd(a, F(2), F(3));     /* FADD(2,3) */
    }
    goto shade;

next_inline:
    R(14) = R(4);
    R(4) += 32;
    {
        const int lit = F(3) > F(11);            /* GT(11,3): FR3 > FR11 */
        F(11) = fipr(a, &F(0), &F(8));           /* F11 = FV0 . FV8 (cosine) */
        a->fpul = ubits(F(15));
        F(2) = fbits(a->fpul);
        if (lit) F(2) = fadd(a, F(2), F(3));     /* FADD(2,3) */
    }

shade:
    F(3) = 0;
    if (R(8) != 0) {
        const int positive = F(11) > F(3);       /* GT(3,11): FR11 > FR3 */
        F(0) = fbits(ONE);
        F(11) = fmul(a, F(11), F(11));           /* FMUL(11,11) */
        if (positive) {
            F(11) = fadd(a, F(11), F(11));       /* FADD(11,11): 2c^2 */
            const int above_one = F(11) > F(0);  /* GT(0,11): FR11 > 1 */
            F(11) = fsub(a, F(11), F(0));        /* FSUB(11,0) */
            if (above_one) {
                F(11) = fmul(a, F(11), F(11));   /* FMUL(11,11) */
                F(3) = fadd(a, F(3), F(11));     /* FADD(3,11) */
                ladder(a, R(8));
            }
            R(0) = R(8) + 72;                    /* braf offset */
        }
    }

emit:
    fst_pre6(a, 2);                              /* store FR2,FR3 pair */
    F(6) = fmul(a, F(6), F(7));                  /* FMUL(6,7) */
    push6(a, R(2));
    F(5) = fmul(a, F(5), F(7));                  /* FMUL(5,7) */
    push6(a, R(1));
    set_t(a, R(3) == 0);
    fst_pre6(a, 6);                              /* store FR6,FR7 pair */
    fst_pre6(a, 4);                              /* bt/s delay slot: FR4,FR5 pair */
    if (!(a->sr & 1u)) {
        vf3_aim_set_u32(a, R(6), R(6));
        fld_post14(a, 4);                        /* bf/s delay slot */
        if (--steps < 0) return 0;
        goto load_z;
    }

    R(1) = 0xFFFFFFFFu;                          /* 8C049010 */
    vf3_aim_set_u32(a, R(6), R(1));
    R(9) -= 1;
    set_t(a, R(9) == 0);
    if (a->sr & 1u) {
        R(4) -= 32;
        R(6) += 32;
        a->fpscr ^= SZ_BIT;                      /* rts delay slot */
        return 1;
    }
    R(0) = vf3_aim_u32(a, R(14));
    R(3) = 3;
    fld_post14(a, 4);
    set_t(a, (R(0) & 1u) == 0);
    fld_post14(a, 6);
    F(2) = fsub(a, F(2), F(2));                  /* bf/s delay slot: FR2 -= FR2 (=> 0) */
    if (!(a->sr & 1u)) goto tail_w;
    a->fpul = ubits(F(5));
    R(4) -= 24;
    R(14) = a->fpul;
    R(14) += R(4);
    goto load_x;
}
