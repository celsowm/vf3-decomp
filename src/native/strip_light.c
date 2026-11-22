/* strip_light.c - SH-4 0x8C0487A0 (strip_light), natively.
 *
 * A plain-C transcription of the readable port src/fight/strip_light.c
 * (`vf3_strip_light_entry`) onto `vf3_native_aim`.  The guest keeps the
 * current transform (XMTRX) in the XF bank - v[37..52] in a readable state,
 * `a->xm[16]` here - and the FR bank in v[21..36], `a->fr[16]` here.
 *
 * A self-contained FP leaf (call-free - the only guest FPU primitives are
 * ftrv, fipr, fdiv and plain fmul/fadd/fsub/fmov, reproduced here with the
 * matrix transform, dot products and float arithmetic; `vf3_light_vertex`
 * and `vf3_vertex_locate` are inlined the same way `body_capsule` inlines its
 * helpers - they are plain readable subroutines, not guest dispatch).
 *
 * It reads a strip of vertex records (r4), transforms and lights each vertex
 * through XMTRX (diffuse via FV12 + ambient FR15, specular via FV8 and the
 * power ladder selected by r8) and writes 32-byte store-queue vertex slots at
 * r6 (r5 advancing 32 per vertex), chaining strips through a trailer:
 *
 *   r4 -> strip: { u32 count; vertex records... } then a trailer
 *          { u32 flags; u32 count; } with the next strip's first record right
 *          behind it
 *   r5 = output cursor (advanced 32 per vertex)
 *   r6 = start of the store-queue area (one 32-byte slot per vertex)
 *   r8 = specular selector (0 = none; a ladder entry 4..40, step 4)
 *
 * Slot layout: +00 control word (the slot's own address for a vertex inside
 * the strip, 0xFFFFFFFF for the last one), +04 y'/x', +08 z'/x', +0C 1/x',
 * +10 w1, +14 w2, +18 diffuse, +1C specular.  The trailer's flags word chains
 * strips (flags <= 0, or bit 0x80 clear, stops).
 *
 * Runs with FPSCR.SZ clear (the readable guards it); every FR access is a
 * single.  Returns 0 on a rejected FPSCR or a malformed specular selector.
 * See docs/re/native_strip_light.md. */
#include "strip_light.h"

#include "aim_math.h"

#include <stdint.h>

#include <fenv.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

enum {
    SZ_BIT = 0x00100000u, ONE = 0x3F800000u, MAX_STEPS = 1000000,
    SLOT_SIZE = 32u, TRAILER_SIZE = 8u, STRIP_CHAIN_FLAG = 0x80u,
    PCW_VERTEX_EOS = 0xFFFFFFFFu, SQ_REGION_MASK = 0xFC000000u,
    SQ_REGION = 0xE0000000u,
};

enum {
    SLOT_CTRL = 0x00, SLOT_Y = 0x04, SLOT_Z = 0x08, SLOT_INV = 0x0C,
    SLOT_W1 = 0x10, SLOT_W2 = 0x14, SLOT_DIFFUSE = 0x18, SLOT_SPECULAR = 0x1C,
};

enum { BODY_POS = 0, BODY_NORMAL = 12, BODY_W1 = 24, BODY_W2 = 28,
       VERTEX_INLINE_FLAG = 1u, VERTEX_SIZE_INLINE = 32u, VERTEX_SIZE_HEAD = 8u };

static float fbits(uint32_t u) { return vf3_aim_fbits(u); }
static uint32_t ubits(float f) { return vf3_aim_ubits(f); }

/* dot: the guest's ftrv/fipr accumulate the four products in a volatile
 * double, exactly like sh4_fpu.c's `dot`.  Replicate that so the transformed
 * coordinates and the lighting terms are bit-exact. */
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
static void ftrv(vf3_native_aim *a, const float src[4], float out[4])
{
    for (int r = 0; r < 4; ++r) {
        float row[4] = { a->xm[r], a->xm[r + 4], a->xm[r + 8], a->xm[r + 12] };
        out[r] = dot4(a, row, src);
    }
}

/* fipr: dot of two 4-vectors, double-accumulate */
static float fipr(vf3_native_aim *a, const float *x, const float *y)
{
    return dot4(a, x, y);
}

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

/* A lit, transformed vertex, one record of the strip. */
typedef struct { uint32_t depth, y, z, w, w1, w2;
                 float intensity, specular, inv_depth; } lit_vertex;

/* vf3_vertex_locate: record is either 32 bytes inline (word0 bit 0 set) or
 * an 8-byte head whose body = record + 8 + head.offset.  Returns the body and
 * the address of the record after this one. */
static uint32_t locate(vf3_native_aim *a, uint32_t record, uint32_t *next)
{
    if (vf3_aim_u32(a, record) & VERTEX_INLINE_FLAG) {
        *next = record + VERTEX_SIZE_INLINE;
        return record;
    }
    *next = record + VERTEX_SIZE_HEAD;
    return vf3_aim_u32(a, record + 4) + record + VERTEX_SIZE_HEAD;
}

/* vf3_light_vertex (via_adder = 1): transform and light one vertex body. */
static int light_vertex(vf3_native_aim *a, uint32_t body, int32_t selector,
                        lit_vertex *out)
{
    float pos_in[4] = { fbits(vf3_aim_u32(a, body + BODY_POS)),
                        fbits(vf3_aim_u32(a, body + BODY_POS + 4)),
                        fbits(vf3_aim_u32(a, body + BODY_POS + 8)),
                        1.0f };
    /* n0 rides along a 0.0 + n0 adder (turns -0 to +0, flushes denormals) */
    float n0 = fadd(a, 0.0f, fbits(vf3_aim_u32(a, body + BODY_NORMAL)));
    const float n1 = fbits(vf3_aim_u32(a, body + BODY_NORMAL + 4));
    const float n2 = fbits(vf3_aim_u32(a, body + BODY_NORMAL + 8));
    out->w1 = vf3_aim_u32(a, body + BODY_W1);
    out->w2 = vf3_aim_u32(a, body + BODY_W2);

    /* FV4 = XMTRX * (x, y, z, 1) */
    float t[4];
    ftrv(a, pos_in, t);
    out->depth = ubits(t[0]);
    out->y = ubits(t[1]);
    out->z = ubits(t[2]);
    out->w = ubits(t[3]);

    /* N.L: FV0 = (n1, n2, n0, 0) against FV12 */
    const float normal[4] = { n1, n2, n0, 0.0f };
    const float light[4] = { F(12), F(13), F(14), F(15) };
    const float n_dot_l = fipr(a, light, normal);

    out->inv_depth = fdiv(a, 1.0f, t[0]);

    /* N.H: FV0 = (n1, n2, n0, N.L), FV8's fourth lane is zero */
    const float normal_l[4] = { n1, n2, n0, n_dot_l };
    const float half[4] = { F(8), F(9), F(10), 0.0f };
    const float n_dot_h = fipr(a, normal_l, half);

    float intensity = F(15);
    if (n_dot_l > 0.0f) intensity = fadd(a, intensity, n_dot_l);

    float specular = 0.0f;
    if (selector < 0) {
        intensity = 1.0f;
    } else if (selector > 0 && n_dot_h > 0.0f) {
        const float s2 = fmul(a, n_dot_h, n_dot_h);
        const float twice = fadd(a, s2, s2);
        const float u = fsub(a, twice, 1.0f);
        if (twice > 1.0f) {
            const float v = fmul(a, u, u);
            /* v^k by the same multiply chains as the original jump table */
            float av = fadd(a, 0.0f, v), bv = av;
            switch (selector) {
            case 4:  break;
            case 8:  av = fmul(a, av, av); break;
            case 12: bv = fmul(a, bv, bv); av = fmul(a, av, bv); break;
            case 16: av = fmul(a, av, av); av = fmul(a, av, av); break;
            case 20: bv = fmul(a, bv, bv); bv = fmul(a, bv, bv);
                     av = fmul(a, av, bv); break;
            case 24: bv = fmul(a, bv, bv); av = fmul(a, av, bv);
                     av = fmul(a, av, bv); break;
            case 28: bv = fmul(a, bv, bv); av = fmul(a, av, bv);
                     bv = fmul(a, bv, bv); av = fmul(a, av, bv); break;
            case 32: for (int i = 0; i < 3; ++i) av = fmul(a, av, av); break;
            case 36: for (int i = 0; i < 4; ++i) av = fmul(a, av, av); break;
            case 40: for (int i = 0; i < 5; ++i) av = fmul(a, av, av); break;
            default: return 0;
            }
            specular = av;
        }
    }
    out->intensity = intensity;
    out->specular = specular;
    return 1;
}

int vf3_native_strip_light(vf3_native_aim *a)
{
    if (a->fpscr & SZ_BIT) return 0;
    const int32_t selector = (int32_t)R(8);
    if (selector < 0) return 0;
    int steps = MAX_STEPS;

    uint32_t cursor = R(4);
    uint32_t count = vf3_aim_u32(a, cursor);
    cursor += 4;
    uint32_t slot = R(6);
    uint32_t next;
    uint32_t body = locate(a, cursor, &next);
    cursor = next;

    uint32_t trailer, flags = 0, w2 = 0;
    for (;;) {
        if (--steps < 0) return 0;
        lit_vertex lv;
        if (!light_vertex(a, body, selector, &lv)) return 0;
        R(5) += SLOT_SIZE;
        w2 = lv.w2;
        count--;

        const int last = count == 0;
        if (last) {
            trailer = cursor;              /* the original has already stepped r4 past it */
        } else {
            body = locate(a, cursor, &next);
            cursor = next;
        }

        const float inv = lv.inv_depth;
        vf3_aim_set_u32(a, slot + SLOT_SPECULAR, ubits(lv.specular));
        vf3_aim_set_u32(a, slot + SLOT_DIFFUSE, ubits(lv.intensity));
        vf3_aim_set_u32(a, slot + SLOT_W2, lv.w2);
        vf3_aim_set_u32(a, slot + SLOT_W1, lv.w1);
        vf3_aim_set_u32(a, slot + SLOT_INV, ubits(inv));
        vf3_aim_set_u32(a, slot + SLOT_Z, ubits(fmul(a, fbits(lv.z), inv)));
        vf3_aim_set_u32(a, slot + SLOT_Y, ubits(fmul(a, fbits(lv.y), inv)));
        vf3_aim_set_u32(a, slot + SLOT_CTRL, lv.depth);
        if (!last) {
            vf3_aim_set_u32(a, slot, slot);          /* control: the slot's own address */
            slot += SLOT_SIZE;
            continue;
        }

        vf3_aim_set_u32(a, slot, PCW_VERTEX_EOS);
        slot += SLOT_SIZE;
        flags = vf3_aim_u32(a, trailer);
        if ((int32_t)flags <= 0) { R(3) = count; R(14) = trailer + 4; break; }
        count = vf3_aim_u32(a, trailer + 4);
        R(3) = count;
        R(14) = trailer + TRAILER_SIZE;
        if (!(flags & STRIP_CHAIN_FLAG)) break;
        body = locate(a, trailer + TRAILER_SIZE, &next);
        cursor = next;
    }

    R(0) = flags;
    R(1) = PCW_VERTEX_EOS;
    R(2) = w2;
    R(4) = trailer;
    R(6) = slot;
    return 1;
}
