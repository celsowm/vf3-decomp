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

#define VERTEX_INLINE_FLAG 1u
#define VERTEX_SIZE_INLINE 32u
#define VERTEX_SIZE_HEAD   8u

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

int vf3_vertex_light_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t rec = s->v[4], body, next;
    const int32_t selector = (int32_t)s->v[8];

    if (vf3_mem_u32(ram, rec) & VERTEX_INLINE_FLAG) {
        body = rec;
        next = rec + VERTEX_SIZE_INLINE;
    } else {
        body = vf3_mem_u32(ram, rec + 4) + rec + VERTEX_SIZE_HEAD;
        next = rec + VERTEX_SIZE_HEAD;
    }
    uint32_t pos_in[4] = { vf3_mem_u32(ram, body), vf3_mem_u32(ram, body + 4),
                           vf3_mem_u32(ram, body + 8), vf3_f32_bits(1.0f) };
    const uint32_t n0 = vf3_mem_u32(ram, body + 12), n1 = vf3_mem_u32(ram, body + 16),
                   n2 = vf3_mem_u32(ram, body + 20);
    s->v[1] = vf3_mem_u32(ram, body + 24);
    s->v[2] = vf3_mem_u32(ram, body + 28);
    s->v[4] = next;

    /* FV4 = XMTRX * (x, y, z, 1) */
    uint32_t t[4];
    if (!vf3_fpu_ftrv(&s->v[VF3_REG_XF0], pos_in, s->v[VF3_REG_FPSCR], t)) return 0;
    const uint32_t depth = t[0], ty = t[1], tz = t[2], tw = t[3];

    /* N.L with FV0 = (n1, n2, n0, 0) against FV12 */
    const uint32_t normal[4] = { n1, n2, n0, 0 };
    const uint32_t light[4] = { VF3_FR(s, 12), VF3_FR(s, 13), VF3_FR(s, 14), VF3_FR(s, 15) };
    uint32_t ndl_bits;
    if (!vf3_fpu_fipr(light, normal, s->v[VF3_REG_FPSCR], &ndl_bits)) return 0;
    const float n_dot_l = vf3_bits_f32(ndl_bits);

    const float inv_depth = vf3_f_div(s, 1.0f, vf3_bits_f32(depth));

    /* N.H: FV0 is now (n1, n2, n0, N.L) and FV8's fourth lane is zero */
    const uint32_t normal_l[4] = { n1, n2, n0, ndl_bits };
    const uint32_t half[4] = { VF3_FR(s, 8), VF3_FR(s, 9), VF3_FR(s, 10), 0 };
    uint32_t n_dot_h_bits;
    if (!vf3_fpu_fipr(normal_l, half, s->v[VF3_REG_FPSCR], &n_dot_h_bits)) return 0;
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

    s->v[0] = tw;
    vf3_fr_set(s, 2, intensity);
    vf3_fr_set(s, 3, specular);
    VF3_FR(s, 4) = tw;
    VF3_FR(s, 5) = ty;
    VF3_FR(s, 6) = tz;
    vf3_fr_set(s, 7, inv_depth);
    s->v[VF3_REG_SR] = (s->v[VF3_REG_SR] & ~1u) | (s->v[12] > tw ? 1u : 0u);
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
