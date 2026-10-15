/* vertex_light.c - per-vertex transform and lighting, SH-4 0x8C048B00.
 *
 * Called once per vertex by the strip transformers. Input r4 points at a
 * vertex record, either inline or by reference:
 *
 *   inline   (word0 bit 0 set)      { float x,y,z; float n[3]; u32 w1,w2; }   32 bytes
 *   indirect (word0 bit 0 clear)    { u32 head; u32 off; }                     8 bytes
 *                                   the body above sits at (record + 8 + off)
 *
 * (word0 is the raw bits of x, so the flag lives in the mantissa LSB.)
 * The position is multiplied by the current XMTRX. The normal is stored in
 * the order n[0],n[1],n[2] -> (FR2, FR0, FR1), i.e. FV0 = (n1, n2, n0, .), and
 * the engine's light vectors FV12/FV8 use the same permutation.
 *
 * Registers on entry that matter: r4 vertex, r8 specular selector, r12 limit,
 * XMTRX, FV12 = diffuse direction with ambient in FR15, FV8 = specular
 * direction, FPSCR.
 * On exit:
 *   r0   = bits of the transformed w
 *   r1,r2 = w1,w2          r4 = record + 8 (indirect) or + 32 (inline)
 *   FR2  = ambient + max(N.L, 0)        (FR2 = 1.0 when r8 < 0)
 *   FR3  = specular term, 0 when none
 *   FR4  = transformed w      FR5,FR6 = transformed y,z
 *   FR7  = 1 / transformed x  (the original keeps the reciprocal here)
 *   T    = (r12 > bits(w))    (unsigned compare, set on every path)
 * FR0/FR1/FR11/FPUL are scratch.
 *
 * The specular term is built from s = N.H: it is zero unless s > 0 and
 * 2s^2 > 1; then v = (2s^2 - 1)^2 and FR3 = v^k, with k picked by r8 (a
 * multiple of 4, jump table of 10 entries):
 *     r8 =  4  8 12 16 20 24 28 32 36 40
 *      k =  1  2  3  4  5  5  7  8 16 32
 * (the 24 entry really yields v^5 - its multiply chain is v*v^2*v^2).
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/vertex_light.h"

#define VERTEX_INLINE_FLAG 1u
#define VERTEX_SIZE_INLINE 32u
#define VERTEX_SIZE_HEAD   8u

enum { BODY_POS = 0, BODY_NORMAL = 12, BODY_W1 = 24, BODY_W2 = 28 };

/* v^k by the same multiply chains as the original jump table; returns 0 on a
 * selector the table does not have. */
static int specular_power(const vf3_matrix_state *s, int32_t selector, float v, float *out)
{
    float a = v, b = v;
    switch (selector) {
    case 4:  break;
    case 8:  a = vf3_f_mul(s, a, a); break;
    case 12: b = vf3_f_mul(s, b, b); a = vf3_f_mul(s, a, b); break;
    case 16: a = vf3_f_mul(s, a, a); a = vf3_f_mul(s, a, a); break;
    case 20: b = vf3_f_mul(s, b, b); b = vf3_f_mul(s, b, b); a = vf3_f_mul(s, a, b); break;
    case 24: b = vf3_f_mul(s, b, b); a = vf3_f_mul(s, a, b); a = vf3_f_mul(s, a, b); break;
    case 28: b = vf3_f_mul(s, b, b); a = vf3_f_mul(s, a, b);
             b = vf3_f_mul(s, b, b); a = vf3_f_mul(s, a, b); break;
    case 32: for (int i = 0; i < 3; ++i) a = vf3_f_mul(s, a, a); break;
    case 36: for (int i = 0; i < 4; ++i) a = vf3_f_mul(s, a, a); break;
    case 40: for (int i = 0; i < 5; ++i) a = vf3_f_mul(s, a, a); break;
    default: return 0;
    }
    *out = a;
    return 1;
}

uint32_t vf3_vertex_locate(const vf3_ram_map *ram, uint32_t record, uint32_t *next)
{
    if (vf3_mem_u32(ram, record) & VERTEX_INLINE_FLAG) {
        *next = record + VERTEX_SIZE_INLINE;
        return record;
    }
    *next = record + VERTEX_SIZE_HEAD;
    return vf3_mem_u32(ram, record + 4) + record + VERTEX_SIZE_HEAD;
}

int vf3_light_vertex(const vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t body,
                     int32_t selector, int via_adder, vf3_lit_vertex *out)
{
    const uint32_t fpscr = s->v[VF3_REG_FPSCR];
    uint32_t pos_in[4] = { vf3_mem_u32(ram, body + BODY_POS), vf3_mem_u32(ram, body + BODY_POS + 4),
                           vf3_mem_u32(ram, body + BODY_POS + 8), vf3_f32_bits(1.0f) };
    uint32_t n0 = vf3_mem_u32(ram, body + BODY_NORMAL);
    const uint32_t n1 = vf3_mem_u32(ram, body + BODY_NORMAL + 4), n2 = vf3_mem_u32(ram, body + BODY_NORMAL + 8);
    if (via_adder) n0 = vf3_f32_bits(vf3_f_add(s, 0.0f, vf3_bits_f32(n0)));
    out->w1 = vf3_mem_u32(ram, body + BODY_W1);
    out->w2 = vf3_mem_u32(ram, body + BODY_W2);

    /* FV4 = XMTRX * (x, y, z, 1) */
    uint32_t t[4];
    if (!vf3_fpu_ftrv(&s->v[VF3_REG_XF0], pos_in, fpscr, t)) return 0;
    out->depth = t[0];
    out->y = t[1];
    out->z = t[2];
    out->w = t[3];

    /* N.L with FV0 = (n1, n2, n0, 0) against FV12 */
    const uint32_t normal[4] = { n1, n2, n0, 0 };
    const uint32_t light[4] = { VF3_FR(s, 12), VF3_FR(s, 13), VF3_FR(s, 14), VF3_FR(s, 15) };
    uint32_t ndl_bits;
    if (!vf3_fpu_fipr(light, normal, fpscr, &ndl_bits)) return 0;
    const float n_dot_l = vf3_bits_f32(ndl_bits);

    out->inv_depth = vf3_f_div(s, 1.0f, vf3_bits_f32(out->depth));

    /* N.H: FV0 is now (n1, n2, n0, N.L) and FV8's fourth lane is zero */
    const uint32_t normal_l[4] = { n1, n2, n0, ndl_bits };
    const uint32_t half[4] = { VF3_FR(s, 8), VF3_FR(s, 9), VF3_FR(s, 10), 0 };
    uint32_t n_dot_h_bits;
    if (!vf3_fpu_fipr(normal_l, half, fpscr, &n_dot_h_bits)) return 0;
    const float n_dot_h = vf3_bits_f32(n_dot_h_bits);

    float intensity = vf3_bits_f32(VF3_FR(s, 15));
    if (n_dot_l > 0.0f) intensity = vf3_f_add(s, intensity, n_dot_l);

    float specular = 0.0f;
    if (selector < 0) {
        intensity = 1.0f;
    } else if (selector > 0 && n_dot_h > 0.0f) {
        const float s2 = vf3_f_mul(s, n_dot_h, n_dot_h);
        const float twice = vf3_f_add(s, s2, s2);
        const float u = vf3_f_sub(s, twice, 1.0f);
        if (twice > 1.0f) {
            const float v = vf3_f_mul(s, u, u);
            if (!specular_power(s, selector, vf3_f_add(s, 0.0f, v), &specular)) return 0;
        }
    }
    out->intensity = intensity;
    out->specular = specular;
    return 1;
}

int vf3_vertex_light_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t next;
    const uint32_t body = vf3_vertex_locate(ram, s->v[4], &next);
    vf3_lit_vertex lv;
    if (!vf3_light_vertex(s, ram, body, (int32_t)s->v[8], 0, &lv)) return 0;

    s->v[0] = lv.w;
    s->v[1] = lv.w1;
    s->v[2] = lv.w2;
    s->v[4] = next;
    vf3_fr_set(s, 2, lv.intensity);
    vf3_fr_set(s, 3, lv.specular);
    VF3_FR(s, 4) = lv.w;
    VF3_FR(s, 5) = lv.y;
    VF3_FR(s, 6) = lv.z;
    vf3_fr_set(s, 7, lv.inv_depth);
    s->v[VF3_REG_SR] = (s->v[VF3_REG_SR] & ~1u) | (s->v[12] > lv.w ? 1u : 0u);
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
