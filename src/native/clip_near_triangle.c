/* clip_near_triangle.c - SH-4 0x8C04A320 (clip_near_triangle), natively.
 *
 * Mirror of the readable authority src/fight/clip_near_triangle.c
 * (`vf3_clip_near_triangle_entry`).  It walks a stream of triangles, projects
 * each point through XMTRX, clips the strip against the near plane, and writes
 * 32-byte store-queue vertex blocks at r6, counting 64-byte blocks in r5.
 *
 *   r4 -> a stream: a point count, then that many triangles (three point
 *        records each, the vertex_classify layout: inline at +0 with a 32-byte
 *        stride, or an offset to out-of-line x,y,z with an 8-byte stride);
 *        after the last triangle a word > 0 with bit 7 clear continues the
 *        stream with a new count, anything else ends it.
 *   r5 counts the 64-byte vertex blocks written,
 *   r6 the store-queue write pointer (flushed with pref every 32 bytes),
 *   r7 a constant word that goes into the last word of the second vertex
 *        block (1.0 in the callers),
 *   r12 the near-plane threshold (a float, kept in FR2).
 *
 *   The body runs with FPSCR.SZ except in the short stretches it toggles off;
 *   `sz` below is that bit.  Per triangle each point goes through XMTRX as
 *   (x,y,z,1); the three depths land in FR4/FR8/FR12, tested against the
 *   threshold to make one outcode bit per point (first point the high bit):
 *       0  all in front - the triangle written as is (96 bytes + 32 trailer),
 *       7  all behind    - nothing written,
 *       1  first behind  - the emit_one_behind path,
 *       2..6             - the point order is rotated (permutation stubs) so
 *                           the two emitters serve every case.
 *   Each emitter writes the cut vertices by interpolating toward the
 *   threshold: t = (thr - depth_a) / (depth_b - depth_a), pos += t * delta.
 *   After the stream the trailer pair (header + or-ed words from the caller's
 *   frame at sp+20/24/28) is written once, only if something was emitted.
 *
 * The observable, flat-RAM contract is the vertex-block region written at r6
 * (the fixture points it at a RAM window), the register file (r0..r6, r11,
 * r14) and XMTRX (unchanged).  The pref flushes are store-queue device side
 * effects, inert when r6 is a RAM pointer.
 */
#include "clip_near_triangle.h"

#include "aim_math.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

enum {
    SZ_BIT = 0x00100000u, FPSCR_FTZ = 0x00040000u, ONE = 0x3F800000u,
    MAX_STEPS = 1000000, SQ_REGION_MASK = 0xFC000000u, SQ_REGION = 0xE0000000u,
};

static float fbits(uint32_t u) { return vf3_aim_fbits(u); }
static uint32_t ubits(float f) { return vf3_aim_ubits(f); }
static void set_t(vf3_native_aim *a, int c) { a->sr = (a->sr & ~1u) | (c ? 1u : 0u); }

static float flushz(vf3_native_aim *a, float f)
{
    if (a->fpscr & FPSCR_FTZ) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float ft0(vf3_native_aim *a, float x, float y, char op)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = 0;
    switch (op) {
        case '+': z = x + y; break;
        case '-': z = x - y; break;
        case '*': z = x * y; break;
        default:  z = x / y; break;
    }
    fesetround(saved);
    return flushz(a, z);
}
static inline float fmul(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '*'); }
static inline float fadd(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '+'); }
static inline float fsub(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '-'); }
static inline float fdiv(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '/'); }
static inline float fmac(vf3_native_aim *a, float x, float y, float acc)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = fmaf(x, y, acc);
    fesetround(saved);
    return flushz(a, z);
}

/* ftrv(XMTRX, src): result[i] = sum_k XMTRX[4k + i] * src[k], the column-major
 * product, accumulated in double and rounded once (as vf3_fpu_ftrv). */
static void transform(vf3_native_aim *a, int n)
{
    const float *M = a->xm;
    const float src[4] = { F(n), F(n + 1), F(n + 2), F(n + 3) };
    for (int i = 0; i < 4; ++i) {
        volatile double s = (double)M[i] * (double)src[0];
        s += (double)M[4 + i] * (double)src[1];
        s += (double)M[8 + i] * (double)src[2];
        s += (double)M[12 + i] * (double)src[3];
        F(n + i) = flushz(a, (float)s);
    }
}

/* fmov FRm,FRn - a register pair when SZ */
static void fmov_reg(vf3_native_aim *a, int sz, int d, int m)
{
    F(d) = F(m);
    if (sz) F(d + 1) = F(m + 1);
}
/* fmov FRm,@-r6 */
static void fst_pre(vf3_native_aim *a, int sz, int n)
{
    R(6) -= sz ? 8u : 4u;
    vf3_aim_set_u32(a, R(6), ubits(F(n)));
    if (sz) vf3_aim_set_u32(a, R(6) + 4, ubits(F(n + 1)));
}
/* fmov FRm,@(r0,r6) and fmov FRm,@r6 */
static void fst_at(vf3_native_aim *a, int sz, int n, uint32_t addr)
{
    vf3_aim_set_u32(a, addr, ubits(F(n)));
    if (sz) vf3_aim_set_u32(a, addr + 4, ubits(F(n + 1)));
}
/* fmov @r14+,FRn */
static void fld_post14(vf3_native_aim *a, int sz, int n)
{
    F(n) = fbits(vf3_aim_u32(a, R(14)));
    if (sz) F(n + 1) = fbits(vf3_aim_u32(a, R(14) + 4));
    R(14) += sz ? 8u : 4u;
}

/* r14 = the record, r0 = its flag word, r4 on to the next record */
static void begin_point(vf3_native_aim *a)
{
    R(14) = R(4);
    R(0) = vf3_aim_u32(a, R(4));
    R(4) += 32;
}
/* tst #1,r0; pref @r4; an out-of-line record redirects r14 to its coords */
static void resolve_point(vf3_native_aim *a)
{
    set_t(a, (R(0) & 1u) == 0);
    /* pref @r4: store-queue flush, inert when r4 is a RAM pointer */
    if (a->sr & 1u) {
        R(14) = vf3_aim_u32(a, R(14) + 4);
        R(4) -= 24;
        R(14) += R(4);
    }
}
/* rotcl r0: r0 = (r0 << 1) | T, T = the bit shifted out */
static void rotcl_r0(vf3_native_aim *a)
{
    const uint32_t out = R(0) >> 31;
    R(0) = (R(0) << 1) | (a->sr & 1u);
    set_t(a, out);
}

int vf3_native_clip_near_triangle(vf3_native_aim *a)
{
    if ((a->fpscr & 0x80000u) || (a->fpscr & 3u) > 1u || (a->fpscr & SZ_BIT)) return 0;
    const uint32_t sp = R(15);
    int guard = MAX_STEPS;
    int sz;                                     /* FPSCR.SZ */

    a->fpul = R(12);
    R(0) = 1;
    F(2) = fbits(a->fpul);                      /* FSTS(2) */
    sz = 1;                                     /* FSCHG: SZ = 1 from here */
    a->fpul = R(0);
    R(11) = 0;
    R(3) = vf3_aim_u32(a, R(4));
    R(4) += 4;

next_triangle:
    if (--guard < 0) return 0;
    begin_point(a);
    F(1) = 0.0f;                                /* FLDI0(1) */
    resolve_point(a);
    fld_post14(a, sz, 4);
    fld_post14(a, sz, 6);
    F(7) = (float)(int32_t)a->fpul;             /* FLOAT(7) */

    begin_point(a);
    transform(a, 4);
    resolve_point(a);
    fld_post14(a, sz, 8);
    F(1) = fadd(a, F(1), F(7));                 /* FADD(1,7) */
    F(7) = 1.0f;                                /* FLDI1(7) */
    F(7) = fdiv(a, F(7), F(4));                 /* FDIV(7,4) */
    fld_post14(a, sz, 10);
    F(11) = (float)(int32_t)a->fpul;            /* FLOAT(11) */
    F(4) = 0.0f;                                /* FLDI0(4) */
    F(4) = fadd(a, F(4), F(1));                 /* FADD(4,1) */

    begin_point(a);
    transform(a, 8);
    F(1) = 0.0f;                                /* FLDI0(1) */
    resolve_point(a);
    F(1) = fadd(a, F(1), F(11));                /* FADD(1,11) */
    F(11) = 1.0f;                               /* FLDI1(11) */
    F(11) = fdiv(a, F(11), F(8));               /* FDIV(11,8) */
    fld_post14(a, sz, 12);
    fld_post14(a, sz, 14);
    F(15) = (float)(int32_t)a->fpul;            /* FLOAT(15) */
    F(8) = 0.0f;                                /* FLDI0(8) */
    F(8) = fadd(a, F(8), F(1));                 /* FADD(8,1) */
    transform(a, 12);
    F(1) = 0.0f;                                /* FLDI0(1) */
    F(1) = fadd(a, F(1), F(15));                /* FADD(1,15) */
    F(15) = 1.0f;                               /* FLDI1(15) */
    F(15) = fdiv(a, F(15), F(12));              /* FDIV(15,12) */
    F(12) = 0.0f;                               /* FLDI0(12) */
    F(12) = fadd(a, F(12), F(1));               /* FADD(12,1) */

    /* one outcode bit per point: depth > threshold */
    R(0) = 0;
    set_t(a, F(4) > F(2)); rotcl_r0(a);         /* GT(2,4) */
    set_t(a, F(8) > F(2)); rotcl_r0(a);         /* GT(2,8) */
    set_t(a, F(12) > F(2)); rotcl_r0(a);        /* GT(2,12) */
    set_t(a, (R(0) & 7u) == 0);
    if (!(a->sr & 1u)) goto clipped;

    /* all three points in front: the triangle as it is */
    a->fpul = ubits(F(11));                     /* FLDS(11) */
    R(0) = 24;
    R(6) += 16;
    F(6) = fmul(a, F(6), F(7));                 /* FMUL(6,7) */
    F(5) = fmul(a, F(5), F(7));                 /* FMUL(5,7) */
    R(1) = a->fpul;
    fst_pre(a, sz, 6);
    F(14) = fmul(a, F(14), F(15));              /* FMUL(14,15) */
    fst_pre(a, sz, 4);
    F(13) = fmul(a, F(13), F(15));              /* FMUL(13,15) */
    fst_at(a, sz, 12, R(6) + R(0));
    F(10) = fmul(a, F(10), F(11));              /* FMUL(10,11) */
    R(0) = 32;
    F(9) = fmul(a, F(9), F(11));                /* FMUL(9,11) */
    fst_at(a, sz, 14, R(6) + R(0));
    R(0) = 0xFFFFFFFFu;
    vf3_aim_set_u32(a, R(6) + 24, R(1));
    sz = 0;                                     /* FSCHG: SZ = 0 */
    vf3_aim_set_u32(a, R(6), R(0));
    R(0) = 16;
    fst_at(a, sz, 9, R(6) + R(0));
    R(0) = 20;
    fst_at(a, sz, 10, R(6) + R(0));
    R(5) += 64;
    R(6) += 32;                                 /* pref @r6 inert */
    R(11) = 1;
    sz = 1;                                     /* FSCHG: SZ = 1 */
    a->fpul = R(11);
    R(6) += 32;                                 /* pref @r6 inert */

next_stream_word:                               /* 8C04A3F2 */
    R(3) -= 1;
    set_t(a, R(3) == 0);
    R(0) = vf3_aim_u32(a, R(4));
    if (!(a->sr & 1u)) goto next_triangle;
    set_t(a, (int32_t)R(0) > 0);
    if (a->sr & 1u) {
        set_t(a, (R(0) & 128u) == 0);
        R(4) += 4;
        R(3) = vf3_aim_u32(a, R(4));            /* delay slot of the bf/s */
        R(4) += 4;
        if (!(a->sr & 1u)) goto next_triangle;
        R(4) -= 8;
    }
    set_t(a, R(11) == 0);
    sz = 0;                                     /* FSCHG: SZ = 0 */
    if (a->sr & 1u) {
        R(6) -= 32;
        R(5) -= 32;
        goto done;
    }
    R(6) += 32;                                 /* pref @r6 inert */
    R(0) = vf3_aim_u32(a, sp + 20);
    R(5) += 64;
    R(1) = vf3_aim_u32(a, sp + 24);
    R(2) = vf3_aim_u32(a, sp + 28);
    R(6) -= 96;                                 /* pref @r6 inert */
    vf3_aim_set_u32(a, R(6), R(0));
    R(0) |= 64;
    vf3_aim_set_u32(a, R(6) + 4, R(1));
    R(2) |= R(1);
    R(6) += 32;                                 /* pref @r6 inert */
    vf3_aim_set_u32(a, R(6), R(0));
    vf3_aim_set_u32(a, R(6) + 4, R(2));
    R(6) += 96;                                 /* pref @r6 inert */
    goto done;

clipped: {                                      /* 8C04A438 */
        const uint32_t outcode = R(0);
        set_t(a, outcode == 7);
        R(0) -= 2;
        if (a->sr & 1u) goto next_stream_word;  /* all behind */
        R(0) <<= 2;
        set_t(a, (int32_t)R(0) == -4);
        R(0) <<= 2;
        if (a->sr & 1u) goto emit_one_behind;   /* outcode 1 */
        fmov_reg(a, sz, 2, 6);                  /* delay slot of the braf */
        switch (outcode) {                      /* permutation stubs 8C04A44A.. */
        case 2:
            fmov_reg(a, sz, 0, 4); fmov_reg(a, sz, 6, 14); fmov_reg(a, sz, 4, 12); fmov_reg(a, sz, 14, 10);
            fmov_reg(a, sz, 12, 8); fmov_reg(a, sz, 10, 2); fmov_reg(a, sz, 8, 0);
            goto emit_one_behind;
        case 3:
            fmov_reg(a, sz, 0, 4); fmov_reg(a, sz, 6, 10); fmov_reg(a, sz, 4, 8); fmov_reg(a, sz, 10, 14);
            fmov_reg(a, sz, 8, 12); fmov_reg(a, sz, 14, 2); fmov_reg(a, sz, 12, 0);
            goto emit_two_behind;
        case 4:
            fmov_reg(a, sz, 0, 4); fmov_reg(a, sz, 6, 10); fmov_reg(a, sz, 4, 8); fmov_reg(a, sz, 10, 14);
            fmov_reg(a, sz, 8, 12); fmov_reg(a, sz, 14, 2); fmov_reg(a, sz, 12, 0);
            goto emit_one_behind;
        case 5:
            fmov_reg(a, sz, 0, 4); fmov_reg(a, sz, 6, 14); fmov_reg(a, sz, 4, 12); fmov_reg(a, sz, 14, 10);
            fmov_reg(a, sz, 12, 8); fmov_reg(a, sz, 10, 2); fmov_reg(a, sz, 8, 0);
            goto emit_two_behind;
        case 6:
            goto emit_two_behind;
        default:
            return 0;
        }
    }

emit_two_behind:                                /* 8C04A48A */
    a->fpul = R(12);
    R(6) += 40;
    fmov_reg(a, sz, 2, 14);
    F(14) = fmul(a, F(14), F(15));              /* FMUL(14,15) */
    fmov_reg(a, sz, 0, 12);
    F(13) = fmul(a, F(13), F(15));              /* FMUL(13,15) */
    F(0) = fbits(a->fpul);                      /* FSTS(0) */
    F(0) = fsub(a, F(0), F(12));                /* FSUB(0,12) */
    F(4) = fsub(a, F(4), F(12));                /* FSUB(4,12) */
    fst_pre(a, sz, 14);
    F(6) = fsub(a, F(6), F(2));                 /* FSUB(6,2) */
    fst_pre(a, sz, 12);
    F(5) = fsub(a, F(5), F(1));                 /* FSUB(5,1) */
    fmov_reg(a, sz, 14, 0);
    F(0) = fdiv(a, F(0), F(4));                 /* FDIV(0,4) */
    F(8) = fsub(a, F(8), F(12));                /* FSUB(8,12) */
    fmov_reg(a, sz, 12, 2);
    F(10) = fsub(a, F(10), F(2));               /* FSUB(10,2) */
    F(9) = fsub(a, F(9), F(1));                 /* FSUB(9,1) */
    F(2) = fmac(a, F(0), F(6), F(2));           /* FMAC(2,6) */
    F(1) = fmac(a, F(0), F(5), F(1));           /* FMAC(1,5) */
    a->fpul = R(7);
    F(14) = fdiv(a, F(14), F(8));               /* FDIV(14,8) */
    F(3) = fbits(a->fpul);                      /* FSTS(3) */
    F(2) = fmul(a, F(2), F(3));                 /* FMUL(2,3) */
    R(6) -= 8;
    F(1) = fmul(a, F(1), F(3));                 /* FMUL(1,3) */
    R(0) = 0xFFFFFFFFu;
    fst_pre(a, sz, 2);
    fst_pre(a, sz, 0);
    sz = 0;                                     /* FSCHG: SZ = 0 */
    fmov_reg(a, sz, 0, 14);
    F(12) = fmac(a, F(0), F(10), F(12));        /* FMAC(12,10) */
    vf3_aim_set_u32(a, R(6), R(0));
    F(15) = fmac(a, F(0), F(9), F(15));         /* FMAC(15,9) */
    R(6) += 28;
    fst_pre(a, sz, 3);
    F(12) = fmul(a, F(12), F(3));               /* FMUL(12,3) */
    F(15) = fmul(a, F(15), F(3));               /* FMUL(15,3) */
    fst_pre(a, sz, 12);
    fst_pre(a, sz, 15);
    sz = 1;                                     /* FSCHG: SZ = 1 (pref @r6) */
    R(6) += 16;
    a->fpul = R(12);
    R(11) = 1;
    F(2) = fbits(a->fpul);                      /* FSTS(2) */
    R(5) += 64;
    a->fpul = R(11);
    R(6) += 32;                                 /* pref @r6 inert */
    goto next_stream_word;

emit_one_behind:                                /* 8C04A4F2 */
    a->fpul = R(12);
    R(6) += 40;
    fmov_reg(a, sz, 2, 6);
    F(6) = fmul(a, F(6), F(7));                 /* FMUL(6,7) */
    fmov_reg(a, sz, 0, 4);
    F(5) = fmul(a, F(5), F(7));                 /* FMUL(5,7) */
    F(0) = fbits(a->fpul);                      /* FSTS(0) */
    F(0) = fsub(a, F(0), F(4));                 /* FSUB(0,4) */
    a->fpul = ubits(F(12));                     /* FLDS(12) */
    F(15) = fbits(a->fpul);                     /* FSTS(15) */
    F(15) = fsub(a, F(15), F(4));               /* FSUB(15,4) */
    a->fpul = ubits(F(14));                     /* FLDS(14) */
    fst_pre(a, sz, 6);
    fst_pre(a, sz, 4);
    F(0) = fdiv(a, F(0), F(15));                /* FDIV(0,15) */
    fmov_reg(a, sz, 6, 10);
    F(6) = fmul(a, F(6), F(7));                 /* FMUL(6,7) */
    fmov_reg(a, sz, 4, 8);
    F(5) = fmul(a, F(5), F(7));                 /* FMUL(5,7) */
    R(6) -= 8;
    fst_pre(a, sz, 6);
    R(0) = 0xFFFFFFFFu;
    fst_pre(a, sz, 4);
    sz = 0;                                     /* FSCHG: SZ = 0 */
    vf3_aim_set_u32(a, R(6), R(0));
    F(6) = fbits(a->fpul);                      /* FSTS(6): FPUL held F14 */
    F(6) = fsub(a, F(6), F(2));                 /* FSUB(6,2) */
    a->fpul = ubits(F(13));                     /* FLDS(13) */
    R(0) = 4;
    F(5) = fbits(a->fpul);                      /* FSTS(5) */
    F(5) = fsub(a, F(5), F(1));                 /* FSUB(5,1) */
    R(6) += 16;
    F(2) = fmac(a, F(0), F(6), F(2));           /* FMAC(2,6): F2 += F0*F6 */
    a->fpul = R(7);
    F(1) = fmac(a, F(0), F(5), F(1));           /* FMAC(1,5): F1 += F0*F5 */
    F(0) = fbits(a->fpul);                      /* FSTS(0) */
    F(2) = fmul(a, F(2), F(0));                 /* FMUL(2,0) */
    vf3_aim_set_u32(a, R(6) + 8, R(7));
    F(1) = fmul(a, F(1), F(0));                 /* FMUL(1,0) */
    fst_at(a, sz, 2, R(6) + R(0));
    fst_at(a, sz, 1, R(6));
    R(6) -= 16;
    sz = 1;                                     /* FSCHG: SZ = 1 (pref @r6) */
    R(6) += 32;
    R(5) += 64;
    R(6) += 32;                                 /* pref @r6 inert */
    a->fpul = R(12);
    R(6) += 40;
    fmov_reg(a, sz, 2, 10);
    F(10) = fmul(a, F(10), F(11));              /* FMUL(10,11) */
    fmov_reg(a, sz, 0, 8);
    F(9) = fmul(a, F(9), F(11));                /* FMUL(9,11) */
    F(0) = fbits(a->fpul);                      /* FSTS(0) */
    F(0) = fsub(a, F(0), F(8));                 /* FSUB(0,8) */
    a->fpul = ubits(F(12));                     /* FLDS(12) */
    F(15) = fbits(a->fpul);                     /* FSTS(15) */
    F(15) = fsub(a, F(15), F(8));               /* FSUB(15,8) */
    fst_pre(a, sz, 10);
    fst_pre(a, sz, 8);
    F(0) = fdiv(a, F(0), F(15));                /* FDIV(0,15) */
    sz = 0;                                     /* FSCHG: SZ = 0 */
    vf3_aim_set_u32(a, R(6), R(7));
    F(14) = fsub(a, F(14), F(2));               /* FSUB(14,2) */
    R(0) = 4;
    F(13) = fsub(a, F(13), F(1));               /* FSUB(13,1) */
    R(6) -= 20;
    F(2) = fmac(a, F(0), F(14), F(2));          /* FMAC(2,14): F2 += F0*F14 */
    a->fpul = R(7);
    F(1) = fmac(a, F(0), F(13), F(1));          /* FMAC(1,13): F1 += F0*F13 */
    F(0) = fbits(a->fpul);                      /* FSTS(0) */
    F(2) = fmul(a, F(2), F(0));                 /* FMUL(2,0) */
    vf3_aim_set_u32(a, R(6) + 8, R(7));
    F(1) = fmul(a, F(1), F(0));                 /* FMUL(1,0) */
    fst_at(a, sz, 2, R(6) + R(0));
    fst_at(a, sz, 1, R(6));
    R(6) -= 4;
    sz = 1;                                     /* FSCHG: SZ = 1 (pref @r6) */
    R(6) += 32;
    a->fpul = R(12);
    R(11) = 1;
    F(2) = fbits(a->fpul);                      /* FSTS(2) */
    R(5) += 64;
    a->fpul = R(11);
    R(6) += 32;                                 /* pref @r6 inert */
    goto next_stream_word;

done:
    return 1;
}
