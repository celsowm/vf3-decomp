/* geom_readable.c - small geometry/trig leaves of the fight engine.
 *
 *   0x8C068F92  triangle winding test      (fr4..fr9 -> r0)
 *   0x8C03A6E0  16-bit-angle sine          (r4 -> fr0)
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"

/* ---- 0x8C068F92: screen-space triangle winding ------------------------
 * Points are passed in FR4/FR5, FR6/FR7 and FR8/FR9 as (x,y) pairs p0,p1,p2.
 * With d01 = p1-p0 and d12 = p2-p1 it forms
 *     area = d01.y * d12.x - d01.x * d12.y
 * and returns 2 for area > 0, 1 for area == 0, 4 otherwise (negative or NaN).
 * Only r0 is a result; every other caller-saved register is scratch (checked
 * by tools/recomp/scratch_deps.py: poisoning them changes nothing). */
enum { WINDING_POSITIVE = 2, WINDING_DEGENERATE = 1, WINDING_NEGATIVE = 4 };

int vf3_tri_winding_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    const float x0 = vf3_fr_get(s, 4), y0 = vf3_fr_get(s, 5);
    const float x1 = vf3_fr_get(s, 6), y1 = vf3_fr_get(s, 7);
    const float x2 = vf3_fr_get(s, 8), y2 = vf3_fr_get(s, 9);

    const float d12x = vf3_f_sub(s, x2, x1);
    const float d01y = vf3_f_sub(s, y1, y0);
    const float d01x = vf3_f_sub(s, x1, x0);
    const float d12y = vf3_f_sub(s, y2, y1);
    const float p_a = vf3_f_mul(s, d01y, d12x);
    const float p_b = vf3_f_mul(s, d01x, d12y);
    const float area = vf3_f_sub(s, p_a, p_b);

    uint32_t result;
    if (area > 0.0f)
        result = WINDING_POSITIVE;
    else
        result = (area == 0.0f) ? WINDING_DEGENERATE : WINDING_NEGATIVE;
    s->v[0] = result;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* ---- 0x8C03A6E0: sin() of a 16-bit angle (65536 = one turn) ------------
 * theta = angle * 2pi / 65536. The half angle h = theta/2 is reduced to
 * y = h - n*pi/2 (n = nearest quadrant), tan(y) comes from the continued
 * fraction y / (1 - y^2/(3 - y^2/(5 - ... y^2/11))), and
 * sin(theta) = +-2t / (1 + t^2) with t = tan(y) (sign flips for odd n).
 * The result is in FR0. */
#define K_TWO     0x40000000u
#define K_TWO_PI  0x40c90fdau
#define K_TURN    0x47800000u   /* 65536.0f */
#define K_HALF_PI 0x3fc90fdau
#define K_HALF    0x3f000000u

int vf3_sin_u16_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    const float two = vf3_bits_f32(K_TWO), two_pi = vf3_bits_f32(K_TWO_PI),
                turn = vf3_bits_f32(K_TURN), half_pi = vf3_bits_f32(K_HALF_PI),
                half = vf3_bits_f32(K_HALF);

    const uint32_t angle = s->v[4] & 0xFFFFu;
    const float theta = vf3_f_div(s, vf3_f_mul(s, vf3_f_from_int(s, (int32_t)angle), two_pi), turn);
    const float h = vf3_f_div(s, theta, two);

    const int32_t quadrant = vf3_f_trunc(vf3_f_add(s, vf3_f_div(s, h, half_pi), half));
    const float y = vf3_f_sub(s, h, vf3_f_mul(s, vf3_f_from_int(s, quadrant), half_pi));
    const float y_sq = vf3_f_mul(s, y, y);

    float frac = 0.0f;
    for (int k = 11; k >= 3; k -= 2)
        frac = vf3_f_div(s, y_sq, vf3_f_sub(s, vf3_f_from_int(s, k), frac));

    const float t = vf3_f_div(s, y, vf3_f_sub(s, 1.0f, frac));
    const float denom = vf3_f_mac(s, t, t, 1.0f);
    const float sine = vf3_f_div(s, vf3_f_mul(s, t, two), denom);

    vf3_fr_set(s, 0, (quadrant & 1) ? -sine : sine);
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* ---- 0x8C068FE4: point-in-quad test of one relative polygon node --------
 * r4 -> node { u32 flags; u32 rec_off; ... }. A node with flag bit 0 set is
 * reported as 1 straight away. Otherwise
 *     rec = base + node.rec_off          (base = *(u32 *)0x0C113A0C)
 *     rec = { u32 flags; u32 vtx_off[4]; ...; float live @ +0x18 }
 * and vertex i sits at base + rec.vtx_off[i] ({float x @ +0, float z @ +8}).
 * The query point is (FR4, FR5). Five winding tests are folded into a mask
 * (bit 2 = positive, bit 4 = negative; a point is inside when all edges it
 * looked at agree, i.e. exactly one of the two bits is set):
 *     2  inside triangle v0 v1 v2         (diagonal v2->v0 included)
 *     4  inside triangle v0 v2 v3         (skipped when rec.flags bit 0 is set)
 *     0  outside, or rec.live == 0
 * Contract: r0, the callee-saved set (r9-r14, FR14/FR15, sp, pr) and the stack
 * frame it pushes; all other caller-saved registers are scratch. */
#define QUAD_BASE_CELL 0x0C113A0Cu
#define WINDING_ENTRY  0x8C068F92u
#define QUAD_RET_AFTER_CALL(n) (0x8C069048u + 0x12u * (n))   /* bsr sites are 0x12 apart */

static int edges_agree(uint32_t mask)
{
    return ((mask & 2u) != 0) != ((mask & 4u) != 0);
}

int vf3_quad_node_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    enum { R4 = 4, R14 = 14, SP = 15 };
    const uint32_t sp0 = s->v[SP];
    const uint32_t saved_pr = s->v[VF3_REG_PR];
    uint32_t saved[6];                        /* r14..r9, in push order */
    for (int i = 0; i < 6; ++i) saved[i] = s->v[14 - i];
    const uint32_t saved_fr15 = VF3_FR(s, 15), saved_fr14 = VF3_FR(s, 14);

    for (int i = 0; i < 6; ++i) vf3_mem_set_u32(ram, sp0 - 4 - 4 * (uint32_t)i, saved[i]);
    vf3_mem_set_u32(ram, sp0 - 28, saved_fr15);
    vf3_mem_set_u32(ram, sp0 - 32, saved_fr14);
    vf3_mem_set_u32(ram, sp0 - 36, saved_pr);
    const uint32_t local = sp0 - 40;          /* one word of locals */
    s->v[SP] = local;

    const uint32_t node = s->v[R4];
    const uint32_t base = vf3_mem_u32(ram, QUAD_BASE_CELL);
    const uint32_t rec = vf3_mem_u32(ram, node + 4) + base;
    int result;

    if (vf3_mem_u32(ram, node) & 1u) {
        result = 1;
        goto out;
    }
    const uint32_t one_triangle = vf3_mem_u32(ram, rec) & 1u;
    vf3_mem_set_u32(ram, local, one_triangle);
    VF3_FR(s, 14) = VF3_FR(s, 4);             /* query point kept in FR14/FR15 */
    VF3_FR(s, 15) = VF3_FR(s, 5);
    if (vf3_mem_f32(ram, rec + 0x18) == 0.0f) {
        result = 0;
        goto out;
    }

    uint32_t v[4];
    for (int i = 0; i < 4; ++i) v[i] = vf3_mem_u32(ram, rec + 4 + 4 * (uint32_t)i) + base;

    /* edge i runs v[a] -> v[b] */
    static const uint8_t edge_a[5] = { 0, 1, 2, 2, 3 };
    static const uint8_t edge_b[5] = { 1, 2, 0, 3, 0 };
    uint32_t wind[5];
    for (int e = 0; e < 5; ++e) {
        const uint32_t pa = v[edge_a[e]], pb = v[edge_b[e]];
        VF3_FR(s, 4) = VF3_FR(s, 14);
        VF3_FR(s, 5) = VF3_FR(s, 15);
        vf3_fr_set(s, 6, vf3_mem_f32(ram, pa));
        vf3_fr_set(s, 7, vf3_mem_f32(ram, pa + 8));
        vf3_fr_set(s, 8, vf3_mem_f32(ram, pb));
        vf3_fr_set(s, 9, vf3_mem_f32(ram, pb + 8));
        if (!vf3_guest_call(s, ram, WINDING_ENTRY, QUAD_RET_AFTER_CALL((uint32_t)e)))
            return 0;
        wind[e] = s->v[0];
    }

    /* wind[]: 0 = v0v1, 1 = v1v2, 2 = v2v0, 3 = v2v3, 4 = v3v0 */
    uint32_t m = wind[0] | (wind[1] & 6u);               /* edges 01, 12 */
    const uint32_t tri1 = wind[2] | (m & 6u);            /* + diagonal 20 */
    const uint32_t second = wind[3] | (wind[4] & 6u);    /* edges 23, 30 */
    if (edges_agree(tri1)) {
        result = 2;
    } else if (one_triangle) {
        result = 0;
    } else {
        m |= second & 6u;
        result = edges_agree(m) ? 4 : 0;
    }

out:
    s->v[0] = (uint32_t)result;
    VF3_FR(s, 14) = saved_fr14;
    VF3_FR(s, 15) = saved_fr15;
    for (int i = 0; i < 6; ++i) s->v[14 - i] = saved[i];
    s->v[SP] = sp0;
    s->v[VF3_REG_PR] = saved_pr;
    s->pc = saved_pr;
    return 1;
}

/* ---- 0x8C03A140: cos() of a 16-bit angle --------------------------------
 * cos(a) = sin(0x4000 - a') where a' folds the angle into the first half turn
 * (a' = 0x10000 - a when a > 0x8000). Tail-calls the sine routine, whose
 * result lands in FR0. r14 is saved and restored by the original. */
int vf3_cos_u16_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* the original pushes r14 and pops it again; the dead stack word is visible in RAM */
    vf3_mem_set_u32(ram, s->v[15] - 4u, s->v[14]);
    uint32_t angle = s->v[4] & 0xFFFFu;
    if (angle > 0x8000u) angle = 0x10000u - angle;
    s->v[4] = 0x4000u - angle;
    return vf3_sin_u16_entry(s, ram);
}

/* ---- 0x8C056B20: push one scaled 2D offset onto a descending record ------
 * Register-passed helper of a larger routine: r8 -> source (two int16 at +0E, +10),
 * r12 -> record cursor, r6 and FR12..FR15 -> values to push, FR3 -> scale. It writes
 *     [r12+30] = FR14, [r12+2C] = FR13, [r12+28] = FR12, [r12+24] = r6   (old r12 + 30 - 4k)
 *     [r12'+14] = float(s16 @ src+10) * scale     [r12'+10] = float(s16 @ src+0E) * scale
 *     [r12'+18] = FR15, [r12'+1C] = 0
 * with r12' = r12 + 0x20 on return; r0 = 0, r8 is unchanged. */
int vf3_push_offset_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t src = s->v[8], cursor = s->v[12] + 0x30u;
    const float scale = vf3_fr_get(s, 3);
    const int32_t first = (int16_t)vf3_mem_u16(ram, src + 0x0Eu);
    const int32_t second = (int16_t)vf3_mem_u16(ram, src + 0x10u);

    const float y = vf3_f_mul(s, vf3_f_from_int(s, second), scale);
    const float x = vf3_f_mul(s, vf3_f_from_int(s, first), scale);
    vf3_fr_set(s, 1, y);
    vf3_fr_set(s, 2, x);

    const uint32_t top = cursor - 16u;
    vf3_mem_set_u32(ram, cursor - 4u, VF3_FR(s, 14));
    vf3_mem_set_u32(ram, cursor - 8u, VF3_FR(s, 13));
    vf3_mem_set_u32(ram, cursor - 12u, VF3_FR(s, 12));
    vf3_mem_set_u32(ram, top, s->v[6]);
    vf3_mem_set_u32(ram, top + 20u, vf3_f32_bits(y));
    vf3_mem_set_u32(ram, top + 16u, vf3_f32_bits(x));
    vf3_mem_set_u32(ram, top + 24u, VF3_FR(s, 15));
    vf3_mem_set_u32(ram, top + 28u, 0);
    s->v[0] = 0;
    s->v[12] = top;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* ---- 0x8C03FB10: four-corner offset fan --------------------------------
 * r4 = object (flags word at +2C: low 2 bits select the base column A, the next
 * 2 bits the base row B), r5/r6 = output arrays of 4 floats, FR4..FR7 = (a,b,c,d).
 * A, B come from the flags; each of the 4 table corners (u,v) in 0x0C0EA670 gives
 *     du = u - A, dv = v - B
 *     out5 = obj[+4] + du*(a*d) + dv*(b*c)
 *     out6 = obj[+8] - (a*c)*du + dv*(b*d)
 * in the order of the original: fmac rounds once, and the du (dv) terms are skipped
 * entirely when du (dv) is zero. */
#define CORNER_TABLE 0x0C0EA670u
int vf3_corner_fan_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t obj = s->v[4];
    uint32_t out_a = s->v[5], out_b = s->v[6];
    const uint32_t flags = vf3_mem_u32(ram, obj + 0x2Cu);
    vf3_mem_set_u32(ram, s->v[15] - 4u, VF3_FR(s, 14));      /* dead fr14 push */

    const float a = vf3_fr_get(s, 4), b = vf3_fr_get(s, 5);
    const float c = vf3_fr_get(s, 6), d = vf3_fr_get(s, 7);
    const float bc = vf3_f_mul(s, b, c);                     /* fr9 */
    const float ac = vf3_f_mul(s, a, c);                     /* fr4 */
    const float bd = vf3_f_mul(s, b, d);                     /* fr5 */
    const float ad = vf3_f_mul(s, a, d);                     /* fr8 */
    const int32_t col = (int32_t)(flags & 3u), row = (int32_t)((flags >> 2) & 3u);
    const float base_u = vf3_f_from_int(s, col);             /* fr6 */
    const float base_v = vf3_f_from_int(s, row);             /* fr14 */

    float fr0 = 0, fr1 = 0, fr2 = 0, fr3 = 0, fr7 = 0, fr10 = 0, fr11 = 0;
    uint32_t table = CORNER_TABLE;
    for (int i = 0; i < 4; ++i) {
        fr7 = vf3_f_sub(s, vf3_mem_f32(ram, table), base_u);
        fr10 = vf3_f_sub(s, vf3_mem_f32(ram, table + 4u), base_v);
        table += 8u;
        fr11 = vf3_mem_f32(ram, obj + 4u);
        fr1 = vf3_mem_f32(ram, obj + 8u);
        fr3 = 0;
        if (!(fr7 == 0)) {
            fr2 = vf3_f_mul(s, ac, fr7);
            fr0 = fr7;
            fr11 = vf3_f_mac(s, fr0, ad, fr11);
            fr2 = vf3_bits_f32(vf3_f32_bits(fr2) ^ 0x80000000u);
            fr1 = vf3_f_add(s, fr1, fr2);
        }
        if (!(fr10 == 0)) {
            fr0 = fr10;
            fr1 = vf3_f_mac(s, fr0, bd, fr1);
            fr11 = vf3_f_mac(s, fr0, bc, fr11);
        }
        vf3_mem_set_f32(ram, out_a, fr11);
        vf3_mem_set_f32(ram, out_b, fr1);
        out_a += 4u;
        out_b += 4u;
    }
    vf3_fr_set(s, 0, fr0);  vf3_fr_set(s, 1, fr1);  vf3_fr_set(s, 2, fr2);  vf3_fr_set(s, 3, fr3);
    vf3_fr_set(s, 4, ac);   vf3_fr_set(s, 5, bd);   vf3_fr_set(s, 6, base_u); vf3_fr_set(s, 7, fr7);
    vf3_fr_set(s, 8, ad);   vf3_fr_set(s, 9, bc);   vf3_fr_set(s, 10, fr10);  vf3_fr_set(s, 11, fr11);
    s->v[1] = 0;
    s->v[3] = 3;
    s->v[5] = out_a;
    s->v[6] = out_b;
    s->v[7] = table;
    s->v[17] |= 1u;                                          /* final tst r1,r1 */
    s->v[VF3_REG_FPUL] = (uint32_t)row;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
