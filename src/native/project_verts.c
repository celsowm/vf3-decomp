/* project_verts.c - SH-4 0x8C058EA0 (project_verts), natively.
 *
 * A self-contained FP leaf (call-free): it projects and lights a run of
 * vertices into the 16-byte output records.
 *
 *   r4 = source stream (six floats per vertex: position xyz, normal xyz),
 *   r6 = vertex count, r7 -> the mode word (bit 2 selects the light-vector
 *   variant).  XMTRX = the view/projection matrix.
 *
 * Per vertex: (x, y, z, 1) goes through XMTRX, the reciprocal of w is formed,
 * and a 16-byte record is written to the output cursor:
 *
 *   +0 x/w   +4 y/w   +8 1/w   +C  max(dot(normal, light), 0) + ambient
 *
 * The FP arithmetic goes through the round-toward-zero + FTZ wrappers the
 * other FP native ports use (the FPSCR RM=truncate + FTZ is in force), and
 * the `fsrra` 1/sqrt is reproduced with `1.0f / sqrtf`.  The ftrv is the
 * SH-4 transform: result[i] = sum_k xm[4k+i] * v[k].
 *
 * Registers on exit: r0 = CURSOR_OUT, r4 = the advanced source, r5 = the
 * advanced output cursor, r6 = 0, SR.T set.  In the side-list variant r1 =
 * SIDE_END and r3 = the advanced side cursor.
 *
 * See docs/re/native_project_verts.md. */
#include "project_verts.h"

#include "aim_math.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

enum {
    CURSOR_PTR = 0x0C16B8ACu, CURSOR_OUT = 0x0C16B8B0u, DEPTH_SCALE = 0x0C16B8A8u,
    SIDE_PTR = 0x0C16B8B8u, SIDE_END = 0x0C16B8BCu, LIGHT_TABLE = 0x0C19D5B0u,
    AMBIENT = 0x0C19E0B0u, DIRECTION = 0x0C058FE0u, MODE_FLAG_ADDR = 0x0C055B8Cu,
    MODE_SIDE_LIST = 4, LIGHT_OFFSET = 0x80, RECORD_BYTES = 16, SR_T = 1u
};

static float fbits(uint32_t u) { return vf3_aim_fbits(u); }
static uint32_t ubits(float f) { return vf3_aim_ubits(f); }

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
static inline float fdiv(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '/'); }

/* ftrv: result[i] = sum_k xm[4k + i] * v[k] */
static void ftrv(vf3_native_aim *a, const float v[4], float out[4])
{
    const float *M = a->xm;
    for (int i = 0; i < 4; ++i) {
        float acc = fmul(a, M[0 + i], v[0]);
        acc = fadd(a, acc, fmul(a, M[4 + i], v[1]));
        acc = fadd(a, acc, fmul(a, M[8 + i], v[2]));
        acc = fadd(a, acc, fmul(a, M[12 + i], v[3]));
        out[i] = acc;
    }
}

/* fipr: dot of two 4-element accumulations */
static float fipr(vf3_native_aim *a, const float x[4], const float y[4])
{
    float acc = fmul(a, x[0], y[0]);
    acc = fadd(a, acc, fmul(a, x[1], y[1]));
    acc = fadd(a, acc, fmul(a, x[2], y[2]));
    return fadd(a, acc, fmul(a, x[3], y[3]));
}

void vf3_native_project_verts(vf3_native_aim *a)
{
    uint32_t src = R(4), count = R(6), mode_word = vf3_aim_u32(a, R(7));
    uint32_t out = vf3_aim_u32(a, CURSOR_PTR) - 16u;

    /* depth scale's reciprocal; light = table entry * inv */
    F(0) = fbits(vf3_aim_u32(a, DEPTH_SCALE));
    F(1) = fdiv(a, 1.0f, F(0));
    for (int i = 0; i < 3; ++i)
        F(8 + i) = fmul(a, fbits(vf3_aim_u32(a, LIGHT_TABLE + LIGHT_OFFSET + 4u * (uint32_t)i)), F(1));

    R(1) = MODE_SIDE_LIST;
    R(2) = MODE_FLAG_ADDR;
    const int side = (mode_word & MODE_SIDE_LIST) != 0;
    uint32_t side_cursor = 0;

    if (!side) {
        R(0) = 0;
        vf3_aim_set_u32(a, MODE_FLAG_ADDR, 0);
    } else {
        R(0) = 1;
        vf3_aim_set_u32(a, MODE_FLAG_ADDR, 1);
        for (int i = 0; i < 3; ++i)
            F(12 + i) = fadd(a, fmul(a, fbits(vf3_aim_u32(a, DIRECTION + 4u * (uint32_t)i)), F(1)), F(8 + i));
        F(15) = 0.0f;
        {
            float v[4] = { F(12), F(13), F(14), F(15) };
            F(15) = fipr(a, v, v);
        }
        F(15) = fdiv(a, 1.0f, sqrtf(F(15)));   /* fsrra */
        for (int i = 0; i < 3; ++i)
            F(12 + i) = fmul(a, F(12 + i), F(15));
        side_cursor = vf3_aim_u32(a, SIDE_PTR) + 4u;
        R(3) = side_cursor;
    }

    do {
        F(15) = fbits(vf3_aim_u32(a, AMBIENT));
        out += 28u;

        /* load_vertex: transform (x,y,z,1) by XMTRX, then load the normal */
        {
            F(4) = fbits(vf3_aim_u32(a, src));
            F(5) = fbits(vf3_aim_u32(a, src + 4));
            F(6) = fbits(vf3_aim_u32(a, src + 8));
            F(7) = 1.0f;
            float v[4] = { F(4), F(5), F(6), F(7) }, o[4];
            ftrv(a, v, o);
            F(4) = o[0]; F(5) = o[1]; F(6) = o[2]; F(7) = o[3];
            F(0) = fbits(vf3_aim_u32(a, src + 12));
            F(1) = fbits(vf3_aim_u32(a, src + 16));
            F(2) = fbits(vf3_aim_u32(a, src + 20));
            F(3) = 0.0f;
        }
        src += 24u;

        {
            float x[4] = { F(0), F(1), F(2), F(3) }, y[4] = { F(8), F(9), F(10), F(11) };
            F(11) = fipr(a, x, y);            /* dot(normal, light); note fr3 = 0 */
        }
        F(6) = fdiv(a, 1.0f, F(7));           /* 1/w */
        if (F(3) > F(11)) F(11) = 0.0f;       /* max(dot,0) */
        F(11) = fadd(a, F(11), F(15));        /* + ambient */
        vf3_aim_set_u32(a, out, ubits(F(11)));

        if (side) {
            float x[4] = { F(12), F(13), F(14), F(15) }, y[4] = { F(0), F(1), F(2), F(3) };
            F(3) = fipr(a, x, y);
            vf3_aim_set_u32(a, side_cursor, ubits(F(3)));
            side_cursor += 8u;
        }

        --count;
        vf3_aim_set_u32(a, out - 4u, ubits(F(6)));   /* 1/w */
        F(5) = fmul(a, F(5), F(6));                  /* y * 1/w */
        F(4) = fmul(a, F(4), F(6));                  /* x * 1/w */
        vf3_aim_set_u32(a, out - 8u, ubits(F(5)));   /* y/w */
        vf3_aim_set_u32(a, out - 12u, ubits(F(4)));  /* x/w */
        out -= 12u;
    } while (count != 0);

    out += RECORD_BYTES;
    R(0) = CURSOR_OUT;
    R(4) = src;
    R(5) = out;
    R(6) = 0;
    vf3_aim_set_u32(a, CURSOR_OUT, out);
    if (side) {
        R(1) = SIDE_END;
        R(3) = side_cursor;
        vf3_aim_set_u32(a, SIDE_END, side_cursor);
    }
    a->sr |= SR_T;
}
