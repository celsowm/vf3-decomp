/* quad_node.c - SH-4 0x8C068FE4: the point-in-quad test of one relative
 * polygon node, natively.
 *
 * A plain-C transcription of the readable port vf3_quad_node_entry
 * (src/fight/geom_readable.c, 0x8C068FE4) onto `vf3_native_aim`.
 *
 *   r4 -> node { u32 flags; u32 rec_off; ... }.  A node with flag bit 0 set is
 *   reported as 1 straight away.  Otherwise
 *       rec = base + node.rec_off          (base = *(u32 *)0x0C113A0C)
 *       rec = { u32 flags; u32 vtx_off[4]; ...; float live @ +0x18 }
 *   and vertex i sits at base + rec.vtx_off[i] ({float x @ +0, float z @ +8}).
 *   The query point is (FR4, FR5).  Five winding tests are folded into a mask
 *   (bit 2 = positive, bit 4 = negative; a point is inside when all edges it
 *   looked at agree, i.e. exactly one of the two bits is set):
 *       2  inside triangle v0 v1 v2         (diagonal v2->v0 included)
 *       4  inside triangle v0 v2 v3         (skipped when rec.flags bit 0 is set)
 *       0  outside, or rec.live == 0
 *
 * The only callee is the triangle winding test (0x8C068F92), already natively
 * ported as `vf3_native_tri_winding`, so the five guest calls become direct
 * native calls into tri_winding.c and the port stays self-contained on
 * vf3nativeview.  r0 carries the answer; the callee-saved set (r9..r14,
 * FR14/FR15, sp, pr) and the pushed stack frame are restored exactly.
 *
 * See docs/re/native_quad_node.md. */
#include "quad_node.h"

#include "aim_math.h"
#include "tri_winding.h"

#define QUAD_BASE_CELL 0x0C113A0Cu

static int edges_agree(uint32_t mask)
{
    return ((mask & 2u) != 0) != ((mask & 4u) != 0);
}

static float f32(uint32_t u) { return vf3_aim_fbits(u); }

void vf3_native_quad_node(vf3_native_aim *a)
{
    const uint32_t sp0 = a->r[15];
    const uint32_t saved_pr = a->pr;
    uint32_t saved[6];                        /* r14..r9, in push order */
    for (int i = 0; i < 6; ++i) saved[i] = a->r[14 - i];
    const float saved_fr15 = a->fr[15], saved_fr14 = a->fr[14];

    for (int i = 0; i < 6; ++i) vf3_aim_set_u32(a, sp0 - 4u - 4u * (uint32_t)i, saved[i]);
    vf3_aim_set_u32(a, sp0 - 28u, vf3_aim_ubits(saved_fr15));
    vf3_aim_set_u32(a, sp0 - 32u, vf3_aim_ubits(saved_fr14));
    vf3_aim_set_u32(a, sp0 - 36u, saved_pr);
    const uint32_t local = sp0 - 40u;         /* one word of locals */
    a->r[15] = local;

    const uint32_t node = a->r[4];
    const uint32_t base = vf3_aim_u32(a, QUAD_BASE_CELL);
    const uint32_t rec = vf3_aim_u32(a, node + 4u) + base;
    int result;

    if (vf3_aim_u32(a, node) & 1u) {
        result = 1;
        goto out;
    }
    const uint32_t one_triangle = vf3_aim_u32(a, rec) & 1u;
    vf3_aim_set_u32(a, local, one_triangle);
    a->fr[14] = a->fr[4];                     /* query point kept in FR14/FR15 */
    a->fr[15] = a->fr[5];
    if (f32(vf3_aim_u32(a, rec + 0x18u)) == 0.0f) {
        result = 0;
        goto out;
    }

    uint32_t v[4];
    for (int i = 0; i < 4; ++i) v[i] = vf3_aim_u32(a, rec + 4u + 4u * (uint32_t)i) + base;

    /* edge i runs v[a] -> v[b] */
    static const uint8_t edge_a[5] = { 0, 1, 2, 2, 3 };
    static const uint8_t edge_b[5] = { 1, 2, 0, 3, 0 };
    uint32_t wind[5];
    for (int e = 0; e < 5; ++e) {
        const uint32_t pa = v[edge_a[e]], pb = v[edge_b[e]];
        a->fr[4] = a->fr[14];
        a->fr[5] = a->fr[15];
        a->fr[6] = f32(vf3_aim_u32(a, pa));
        a->fr[7] = f32(vf3_aim_u32(a, pa + 8u));
        a->fr[8] = f32(vf3_aim_u32(a, pb));
        a->fr[9] = f32(vf3_aim_u32(a, pb + 8u));
        vf3_native_tri_winding(a);
        wind[e] = a->r[0];
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
    a->r[0] = (uint32_t)result;
    a->fr[14] = saved_fr14;
    a->fr[15] = saved_fr15;
    for (int i = 0; i < 6; ++i) a->r[14 - i] = saved[i];
    a->r[15] = sp0;
    a->pr = saved_pr;
}
