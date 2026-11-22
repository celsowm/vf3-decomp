/* quad_strip.c - SH-4 0x8C048600 (quad_strip), natively.
 *
 * Walks a list of groups of four vertices and emits 32-byte store-queue slots.
 * Mirror of the readable authority src/fight/quad_strip.c
 * (`vf3_quad_strip_entry`) with the shared lighting step of
 * src/fight/vertex_light.c inlined, exactly as the guest inlines it.
 *
 *   r4 = group list.  At r4-8 the byte length of all groups (units = that >> 1,
 *        in halfwords), at r4-4 a flags word, at r4 a count; the first group
 *        starts at r4+4.  A group is
 *            { 4 inline vertex records (32 bytes each); u32 flags; u32 count }
 *        = 136 bytes, and the 8-byte tail is skipped between groups.
 *   r5 = output cursor (advanced by 128 per quad, 0 per triangle),
 *   r6 = store-queue slot (32 bytes per vertex), r8 = specular selector,
 *        XMTRX (a->xm), FV12 (diffuse, ambient in FR15) and FV8 (specular)
 *        lights in the FR bank.
 *
 *   Only vertex 0 is lit.  Vertices 1..3 carry no colour: their slots write
 *   only their first 24 bytes, and vertex 0's diffuse/specular pair is parked
 *   at slot-8 / slot-4 (the tail of the *other* store-queue buffer), so the
 *   other slots flush flat-shaded with that pair still sitting in the buffer.
 *
 *   The first three vertices decide the primitive:
 *       (y0 - y1)(z1 - z2)  >  (z0 - z1)(y1 - y2)
 *   keeps the fourth (a quad, four slots, r6 on by 128); otherwise a triangle
 *   goes out: slot 2 is rewritten as the end-of-strip marker (0xFFFFFFFF) and
 *   r6 stays at the group's first slot.
 *
 *   Exit: r0, r1=w1, r2=w2, r4=end of last group, r5, r6=slot after output,
 *   r9=0, r14=the slot the call started with.
 *
 * The observable, flat-RAM contract is the slots written at `slot` (the
 * fixture points it at a RAM window), the register file (the exit set above)
 * and the first/w2 words.  The PREF flushes are store-queue device side
 * effects, inert when `slot` is a RAM pointer.
 */
#include "quad_strip.h"

#include "aim_math.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

enum {
    SLOT_SIZE = 32u, RECORD_SIZE = 32u, GROUP_RECORDS = 4u, GROUP_TAIL = 8u,
    GROUP_UNITS = 68u, PCW_VERTEX_EOS = 0xFFFFFFFFu, FPSCR_SZ = 0x00100000u,
};
enum { SLOT_CTRL = 0x00, SLOT_Y = 0x04, SLOT_Z = 0x08, SLOT_INV = 0x0C,
       SLOT_W1 = 0x10, SLOT_W2 = 0x14, SLOT_DIFFUSE = 0x18, SLOT_SPECULAR = 0x1C };
enum { BODY_POS = 0, BODY_NORMAL = 12, BODY_W1 = 24, BODY_W2 = 28 };

static float fbits(uint32_t u) { return vf3_aim_fbits(u); }
static uint32_t ubits(float f) { return vf3_aim_ubits(f); }

/* ---- round-toward-zero + FTZ wrappers (as project_verts.c) ---- */
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
static inline float fsub(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '-'); }
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

/* v^k by the same multiply chains as the guest jump table; -1 on an unknown
 * selector (the guest body would not continue either). */
static int specular_power(vf3_native_aim *a, int32_t selector, float v, float *out)
{
    float p = v, b = v;
    switch (selector) {
    case 4:  break;
    case 8:  p = fmul(a, p, p); break;
    case 12: b = fmul(a, b, b); p = fmul(a, p, b); break;
    case 16: p = fmul(a, p, p); p = fmul(a, p, p); break;
    case 20: b = fmul(a, b, b); b = fmul(a, b, b); p = fmul(a, p, b); break;
    case 24: b = fmul(a, b, b); p = fmul(a, p, b); p = fmul(a, p, b); break;
    case 28: b = fmul(a, b, b); p = fmul(a, p, b);
             b = fmul(a, b, b); p = fmul(a, p, b); break;
    case 32: for (int i = 0; i < 3; ++i) p = fmul(a, p, p); break;
    case 36: for (int i = 0; i < 4; ++i) p = fmul(a, p, p); break;
    case 40: for (int i = 0; i < 5; ++i) p = fmul(a, p, p); break;
    default: return -1;
    }
    *out = p;
    return 0;
}

/* the shared lighting step of vertex_light.c, inlined with via_adder = 1
 * (the normal's first component rides through a 0.0 + n0 addition) */
typedef struct {
    uint32_t depth, y, z, w, w1, w2;
    float intensity, specular, inv_depth;
} lit_vertex;

static int light_vertex(vf3_native_aim *a, uint32_t body, int32_t selector, lit_vertex *out)
{
    const float pos_in[4] = { fbits(vf3_aim_u32(a, body + BODY_POS)),
                              fbits(vf3_aim_u32(a, body + BODY_POS + 4)),
                              fbits(vf3_aim_u32(a, body + BODY_POS + 8)), 1.0f };
    float n0 = fbits(vf3_aim_u32(a, body + BODY_NORMAL));
    const float n1 = fbits(vf3_aim_u32(a, body + BODY_NORMAL + 4));
    const float n2 = fbits(vf3_aim_u32(a, body + BODY_NORMAL + 8));
    n0 = fadd(a, 0.0f, n0);                              /* via_adder */
    out->w1 = vf3_aim_u32(a, body + BODY_W1);
    out->w2 = vf3_aim_u32(a, body + BODY_W2);

    float t[4];
    ftrv(a, pos_in, t);
    out->depth = ubits(t[0]);
    out->y = ubits(t[1]);
    out->z = ubits(t[2]);
    out->w = ubits(t[3]);

    /* N.L with FV0 = (n1, n2, n0, 0) against FV12 */
    const float normal[4] = { n1, n2, n0, 0.0f };
    const float light[4] = { F(12), F(13), F(14), F(15) };
    const float ndl = fipr(a, light, normal);

    out->inv_depth = fdiv(a, 1.0f, t[0]);

    /* N.H: FV0 is now (n1, n2, n0, N.L) and FV8's fourth lane is zero */
    const float normal_l[4] = { n1, n2, n0, ndl };
    const float half[4] = { F(8), F(9), F(10), 0.0f };
    const float ndh = fipr(a, normal_l, half);

    float intensity = F(15);
    if (ndl > 0.0f) intensity = fadd(a, intensity, ndl);

    float specular = 0.0f;
    if (selector < 0) {
        intensity = 1.0f;
    } else if (selector > 0 && ndh > 0.0f) {
        const float s2 = fmul(a, ndh, ndh);
        const float twice = fadd(a, s2, s2);
        const float u = fsub(a, twice, 1.0f);
        if (twice > 1.0f) {
            const float v = fmul(a, u, u);
            if (specular_power(a, selector, fadd(a, 0.0f, v), &specular) != 0) return -1;
        }
    }
    out->intensity = intensity;
    out->specular = specular;
    return 0;
}

/* position-only transform of an inline record: depth and y/x', z/x' */
typedef struct {
    float depth, y_scaled, z_scaled, inv;
    uint32_t w1, w2;
} screen_vertex;

static int project(vf3_native_aim *a, uint32_t record, screen_vertex *v)
{
    const float pos[4] = { fbits(vf3_aim_u32(a, record + BODY_POS)),
                           fbits(vf3_aim_u32(a, record + BODY_POS + 4)),
                           fbits(vf3_aim_u32(a, record + BODY_POS + 8)), 1.0f };
    float t[4];
    ftrv(a, pos, t);
    v->depth = t[0];
    v->inv = fdiv(a, 1.0f, t[0]);
    v->y_scaled = fmul(a, t[1], v->inv);
    v->z_scaled = fmul(a, t[2], v->inv);
    v->w1 = vf3_aim_u32(a, record + BODY_W1);
    v->w2 = vf3_aim_u32(a, record + BODY_W2);
    return 0;
}

/* the first 24 bytes of a slot, in the order the routine writes them */
static void emit_position(vf3_native_aim *a, uint32_t slot, const screen_vertex *v, uint32_t control)
{
    vf3_aim_set_u32(a, slot + SLOT_W1, v->w1);
    vf3_aim_set_u32(a, slot + SLOT_W2, v->w2);
    vf3_aim_set_u32(a, slot + SLOT_Z, ubits(v->z_scaled));
    vf3_aim_set_u32(a, slot + SLOT_INV, ubits(v->inv));
    vf3_aim_set_u32(a, slot + SLOT_CTRL, ubits(v->depth));
    vf3_aim_set_u32(a, slot + SLOT_Y, ubits(v->y_scaled));
    vf3_aim_set_u32(a, slot + SLOT_CTRL, control);
}

int vf3_native_quad_strip(vf3_native_aim *a)
{
    if (a->fpscr & FPSCR_SZ) return 0;                   /* fschg would turn pair moves off */
    const int32_t selector = (int32_t)a->r[8];

    const uint32_t first_slot = a->r[6];
    uint32_t units = vf3_aim_u32(a, a->r[4] - 8u) >> 1;
    uint32_t group = a->r[4] + 4u;
    uint32_t slot = first_slot;
    uint32_t r0 = a->r[0], w1 = a->r[1], w2 = a->r[2];
    uint32_t r5 = a->r[5];

    if (units == 0 || units % GROUP_UNITS) return 0;

    for (;;) {
        lit_vertex lit;
        if (light_vertex(a, group, selector, &lit) != 0) return 0;
        const float y0 = fmul(a, fbits(lit.y), lit.inv_depth);
        const float z0 = fmul(a, fbits(lit.z), lit.inv_depth);
        w1 = lit.w1;
        w2 = lit.w2;

        vf3_aim_set_u32(a, slot - 8u, ubits(lit.intensity));
        vf3_aim_set_u32(a, slot - 4u, ubits(lit.specular));
        vf3_aim_set_u32(a, slot + SLOT_DIFFUSE, ubits(lit.intensity));
        vf3_aim_set_u32(a, slot + SLOT_SPECULAR, ubits(lit.specular));
        vf3_aim_set_u32(a, slot + SLOT_W2, lit.w2);
        vf3_aim_set_u32(a, slot + SLOT_W1, lit.w1);
        vf3_aim_set_u32(a, slot + SLOT_Z, ubits(z0));
        vf3_aim_set_u32(a, slot + SLOT_INV, ubits(lit.inv_depth));
        vf3_aim_set_u32(a, slot + SLOT_CTRL, lit.depth);
        vf3_aim_set_u32(a, slot + SLOT_Y, ubits(y0));
        vf3_aim_set_u32(a, slot + SLOT_CTRL, slot);

        screen_vertex v1, v2, v3;
        const uint32_t rec3 = group + 3u * RECORD_SIZE;
        if (project(a, group + RECORD_SIZE, &v1) != 0) return 0;
        emit_position(a, slot + SLOT_SIZE, &v1, slot + SLOT_SIZE);
        if (project(a, group + 2u * RECORD_SIZE, &v2) != 0) return 0;
        emit_position(a, slot + 2u * SLOT_SIZE, &v2, slot + 2u * SLOT_SIZE);

        const float y0s = fadd(a, 0.0f, y0), z0s = fadd(a, 0.0f, z0);
        const float dy01 = fsub(a, y0s, v1.y_scaled);
        const float dz01 = fsub(a, z0s, v1.z_scaled);
        const float dy12 = fsub(a, fadd(a, 0.0f, v1.y_scaled), v2.y_scaled);
        const float dz12 = fsub(a, v1.z_scaled, v2.z_scaled);
        const int quad = fmul(a, dy01, dz12) > fmul(a, dz01, dy12);

        units -= GROUP_UNITS;
        if (quad) {
            if (project(a, rec3, &v3) != 0) return 0;
            const uint32_t slot3 = slot + 3u * SLOT_SIZE;
            r0 = (uint32_t)((int32_t)(slot3 + 24u) >> 1);
            emit_position(a, slot3, &v3, r0);
            r5 += 2u * 64u;
            slot += 4u * SLOT_SIZE;
        } else {
            r0 = rec3 + 16u;
            w1 = PCW_VERTEX_EOS;
            vf3_aim_set_u32(a, slot + 2u * SLOT_SIZE, PCW_VERTEX_EOS);
        }
        group += GROUP_RECORDS * RECORD_SIZE;
        if (units == 0) break;
        group += GROUP_TAIL;
    }

    a->r[0] = r0;
    a->r[1] = w1;
    a->r[2] = w2;
    a->r[4] = group;
    a->r[5] = r5;
    a->r[6] = slot;
    a->r[9] = 0;
    a->r[14] = first_slot;
    return 1;
}
