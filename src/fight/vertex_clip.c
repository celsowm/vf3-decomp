/* vertex_clip.c - clip-edge helpers of the strip transformers (SH-4 0x8C048C40..0x8C048D4A).
 *
 * The transformer keeps the last four transformed vertices in a ring of 32-byte
 * slots at 0x0C1A5960 (written by vertex_emit.c, see there for the layout:
 * w' y' z' 1/x' w1 w2 diffuse specular). When a strip edge crosses the near plane
 * these routines finish the vertex in the ring and push it to the store queue at r6.
 *
 * (0x8C048C40, which copies the shading pair of ring slot r11 into the two slots
 * before it, never runs in the captured ticks and is not ported.)
 *
 *   0x8C048C80  push ring slot (r0 & 3) to the store queue: y' and z' are
 *               multiplied by 1/x' first
 *   0x8C048CC0  push the point where the edge ring[r0&3] -> ring[r11&3] crosses
 *               the plane w' = r12: t = (plane - w0) / (w1 - w0), every
 *               attribute is interpolated lerp(a0, a1, t) with a fused multiply-add,
 *               then y' and z' are scaled by the float whose bits are in r7
 *
 * The control word in the first slot word is the strip flag: 0xF0000000 when T
 * is set (last vertex of the strip), otherwise an address: the slot's own for
 * 0x8C048C80, the slot's y' field (slot + 4) for 0x8C048CC0.
 * r6 is the start of the store-queue slot (advanced by 32 on return) and r5 the
 * input cursor (advanced by 32), as in vertex_emit.c.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"

#define SLOT_SIZE        32u
#define RING_BASE        0x0C1A5960u
#define RING_MASK        3u
#define FPSCR_SZ         0x00100000u
#define SQ_REGION_MASK   0xFC000000u
#define SQ_REGION        0xE0000000u
#define STRIP_END_FLAG   0xF0000000u

enum { W = 0x00, Y = 0x04, Z = 0x08, INV_X = 0x0C, W1 = 0x10, W2 = 0x14, DIFFUSE = 0x18, SPECULAR = 0x1C };

static uint32_t ring_slot(uint32_t index) { return RING_BASE + (index & RING_MASK) * SLOT_SIZE; }
static int sr_t(const vf3_matrix_state *s) { return (int)(s->v[VF3_REG_SR] & 1u); }

static void pref_sq(const vf3_ram_map *ram, uint32_t slot)
{
    if ((slot & SQ_REGION_MASK) == SQ_REGION) vf3_matrix_pref(ram, slot);
}

/* 0x8C048C80 */
int vf3_clip_emit_slot_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (s->v[VF3_REG_FPSCR] & FPSCR_SZ) return 0;
    const uint32_t src = ring_slot(s->v[0]);
    const uint32_t out = s->v[6];                      /* start of the store-queue slot */

    const uint32_t w = vf3_mem_u32(ram, src + W);
    const float y = vf3_bits_f32(vf3_mem_u32(ram, src + Y));
    const float z = vf3_bits_f32(vf3_mem_u32(ram, src + Z));
    const float inv_x = vf3_bits_f32(vf3_mem_u32(ram, src + INV_X));
    const float y_scaled = vf3_f_mul(s, y, inv_x);
    const float z_scaled = vf3_f_mul(s, z, inv_x);

    VF3_FR(s, 0) = w;
    vf3_fr_set(s, 1, y_scaled);
    vf3_fr_set(s, 2, z_scaled);
    VF3_FR(s, 3) = vf3_mem_u32(ram, src + INV_X);
    VF3_FR(s, 4) = vf3_mem_u32(ram, src + W1);
    VF3_FR(s, 5) = vf3_mem_u32(ram, src + W2);
    VF3_FR(s, 6) = vf3_mem_u32(ram, src + DIFFUSE);
    VF3_FR(s, 7) = vf3_mem_u32(ram, src + SPECULAR);

    const uint32_t base = out;
    vf3_mem_set_u32(ram, base + DIFFUSE, VF3_FR(s, 6));
    vf3_mem_set_u32(ram, base + SPECULAR, VF3_FR(s, 7));
    vf3_mem_set_u32(ram, base + W1, VF3_FR(s, 4));
    vf3_mem_set_u32(ram, base + W2, VF3_FR(s, 5));
    vf3_mem_set_u32(ram, base + Z, VF3_FR(s, 2));
    vf3_mem_set_u32(ram, base + INV_X, VF3_FR(s, 3));
    vf3_mem_set_u32(ram, base + W, VF3_FR(s, 0));
    vf3_mem_set_u32(ram, base + Y, VF3_FR(s, 1));

    s->v[5] += SLOT_SIZE;
    s->v[2] = sr_t(s) ? STRIP_END_FLAG : base;
    vf3_mem_set_u32(ram, base, s->v[2]);
    pref_sq(ram, base);
    s->v[10] = src + SLOT_SIZE;
    s->v[0] = (s->v[0] & RING_MASK) * SLOT_SIZE;
    s->v[6] = base + SLOT_SIZE;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* a0 + t * (a1 - a0), the multiply-add fused as the hardware does */
static float lerp_bits(const vf3_matrix_state *s, float t, uint32_t a0, uint32_t a1, float *delta)
{
    const float from = vf3_bits_f32(a0);
    const float d = vf3_f_sub(s, vf3_bits_f32(a1), from);
    if (delta) *delta = d;
    return vf3_f_mac(s, t, d, from);
}

/* 0x8C048CC0 */
int vf3_clip_edge_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (s->v[VF3_REG_FPSCR] & FPSCR_SZ) return 0;
    const uint32_t p = ring_slot(s->v[0]);             /* edge start */
    const uint32_t q = ring_slot(s->v[11]);            /* edge end */
    const uint32_t base = s->v[6];                     /* start of the store-queue slot */

    const float plane_gap = vf3_f_sub(s, vf3_bits_f32(s->v[12]), vf3_mem_f32(ram, p + W));
    const float edge_gap = vf3_f_sub(s, vf3_mem_f32(ram, q + W), vf3_mem_f32(ram, p + W));
    const float t = vf3_f_div(s, plane_gap, edge_gap);
    const float scale = vf3_bits_f32(s->v[7]);

    float d4, d5, shade, spec, u, v, y, z;
    shade = lerp_bits(s, t, vf3_mem_u32(ram, p + DIFFUSE), vf3_mem_u32(ram, q + DIFFUSE), &d4);
    spec = lerp_bits(s, t, vf3_mem_u32(ram, p + SPECULAR), vf3_mem_u32(ram, q + SPECULAR), &d5);
    vf3_mem_set_f32(ram, base + DIFFUSE, shade);
    vf3_mem_set_f32(ram, base + SPECULAR, spec);

    u = lerp_bits(s, t, vf3_mem_u32(ram, p + W1), vf3_mem_u32(ram, q + W1), &d4);
    v = lerp_bits(s, t, vf3_mem_u32(ram, p + W2), vf3_mem_u32(ram, q + W2), &d5);
    vf3_mem_set_f32(ram, base + W1, u);
    vf3_mem_set_f32(ram, base + W2, v);
    vf3_mem_set_f32(ram, base + INV_X, scale);

    y = lerp_bits(s, t, vf3_mem_u32(ram, p + Y), vf3_mem_u32(ram, q + Y), &d4);
    z = lerp_bits(s, t, vf3_mem_u32(ram, p + Z), vf3_mem_u32(ram, q + Z), &d5);
    y = vf3_f_mul(s, y, scale);
    z = vf3_f_mul(s, z, scale);
    vf3_mem_set_f32(ram, base + Z, z);
    vf3_mem_set_f32(ram, base + Y, y);

    /* this path stores the control word with a pre-decrement, so the address
     * it records is the previous word's (the y' field) rather than the slot's */
    s->v[2] = sr_t(s) ? STRIP_END_FLAG : base + Y;
    vf3_mem_set_u32(ram, base, s->v[2]);
    pref_sq(ram, base);

    vf3_fr_set(s, 0, t);
    vf3_fr_set(s, 1, scale);
    vf3_fr_set(s, 2, y);
    vf3_fr_set(s, 3, z);
    vf3_fr_set(s, 4, d4);
    vf3_fr_set(s, 5, d5);
    s->v[VF3_REG_FPUL] = s->v[7];
    s->v[0] = (s->v[11] & RING_MASK) * SLOT_SIZE;
    s->v[10] = p + Y;
    s->v[5] += SLOT_SIZE;
    s->v[6] = base + SLOT_SIZE;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
