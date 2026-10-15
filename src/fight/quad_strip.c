/* quad_strip.c - transform and emit groups of four vertices, SH-4 0x8C048600.
 *
 * In:  r4 = group list. At r4-8 the byte length of all groups, at r4-4 a flags word,
 *           at r4 a count; the first group starts at r4+4. A group is
 *               { 4 inline vertex records (32 bytes each, layout of vertex_light.c);
 *                 u32 flags; u32 count }          = 136 bytes
 *           and the 8-byte tail is skipped between groups (the header at the very start
 *           has the same size, which is why the list begins at r4+4).
 *      r5 = output cursor, r6 = store-queue slot (32 bytes per vertex),
 *      r8 = specular selector, XMTRX, FV12 / FV8 lights, as in vertex_light.c
 * Out: r4 = end of the last group's records, r5 += 128 for every quad (a triangle leaves it),
 *      r6 = slot after the output, r9 = 0, r14 = the slot the call started with.
 *
 * Only vertex 0 is lit. Vertices 1..3 carry no colour of their own: the routine stores
 * vertex 0's (diffuse, specular) pair at slot-8, i.e. into the tail of the *other*
 * 32-byte store-queue buffer (the two buffers alternate with address bit 5, as do the
 * slots), and the slots of vertices 1..3 only write their first 24 bytes, so they are
 * flushed with that pair still sitting in the buffer: flat shading.
 *
 * The first three vertices decide the primitive. With y, z the perspective-scaled
 * coordinates (y/x', z/x'),
 *     (y0 - y1) * (z1 - z2)  >  (z0 - z1) * (y1 - y2)
 * keeps the fourth vertex too (a quad, four slots, r6 moves on by 128). Otherwise only a
 * triangle goes out: slot 2 is rewritten as the end-of-strip vertex and r6 goes back to
 * the group's first slot (the three slots were already flushed).
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/vertex_light.h"

#define SLOT_SIZE        32u
#define RECORD_SIZE      32u
#define GROUP_RECORDS     4u
#define GROUP_TAIL        8u
#define GROUP_UNITS      68u           /* 136 bytes of a group, in halfwords */
#define PCW_VERTEX_EOS   0xFFFFFFFFu
#define FPSCR_SZ         0x00100000u
#define SQ_REGION_MASK   0xFC000000u
#define SQ_REGION        0xE0000000u

enum { SLOT_CTRL = 0x00, SLOT_Y = 0x04, SLOT_Z = 0x08, SLOT_INV = 0x0C,
       SLOT_W1 = 0x10, SLOT_W2 = 0x14, SLOT_DIFFUSE = 0x18, SLOT_SPECULAR = 0x1C };
enum { BODY_W1 = 24, BODY_W2 = 28 };

typedef struct {
    float depth, y_scaled, z_scaled, inv;
    uint32_t w1, w2;
} screen_vertex;

static void flush(const vf3_ram_map *ram, uint32_t slot)
{
    if ((slot & SQ_REGION_MASK) == SQ_REGION) vf3_matrix_pref(ram, slot);
}

/* position-only transform of an inline record: 1/x' and y/x', z/x' */
static int project(const vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t record, screen_vertex *v)
{
    const uint32_t pos[4] = { vf3_mem_u32(ram, record), vf3_mem_u32(ram, record + 4),
                              vf3_mem_u32(ram, record + 8), vf3_f32_bits(1.0f) };
    uint32_t t[4];
    if (!vf3_fpu_ftrv(&s->v[VF3_REG_XF0], pos, s->v[VF3_REG_FPSCR], t)) return 0;
    v->depth = vf3_bits_f32(t[0]);
    v->inv = vf3_f_div(s, 1.0f, v->depth);
    v->y_scaled = vf3_f_mul(s, vf3_bits_f32(t[1]), v->inv);
    v->z_scaled = vf3_f_mul(s, vf3_bits_f32(t[2]), v->inv);
    v->w1 = vf3_mem_u32(ram, record + BODY_W1);
    v->w2 = vf3_mem_u32(ram, record + BODY_W2);
    return 1;
}

/* the first 24 bytes of a slot, in the order the routine writes them */
static void emit_position(const vf3_ram_map *ram, uint32_t slot, const screen_vertex *v, uint32_t control)
{
    vf3_mem_set_u32(ram, slot + SLOT_W1, v->w1);
    vf3_mem_set_u32(ram, slot + SLOT_W2, v->w2);
    vf3_mem_set_f32(ram, slot + SLOT_Z, v->z_scaled);
    vf3_mem_set_f32(ram, slot + SLOT_INV, v->inv);
    vf3_mem_set_f32(ram, slot + SLOT_CTRL, v->depth);
    vf3_mem_set_f32(ram, slot + SLOT_Y, v->y_scaled);
    vf3_mem_set_u32(ram, slot + SLOT_CTRL, control);
}

int vf3_quad_strip_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (s->v[VF3_REG_FPSCR] & FPSCR_SZ) return 0;       /* the routine's own fschg would turn pair moves off */
    const int32_t selector = (int32_t)s->v[8];

    const uint32_t first_slot = s->v[6];
    uint32_t units = vf3_mem_u32(ram, s->v[4] - 8) >> 1;
    uint32_t group = s->v[4] + 4;                       /* first record of the current group */
    uint32_t slot = first_slot;
    uint32_t r0 = s->v[0], w1 = s->v[1], w2 = s->v[2];
    uint32_t r5 = s->v[5];

    if (units == 0 || units % GROUP_UNITS) return 0;    /* the routine would not terminate */

    for (;;) {
        /* vertex 0: transformed, lit, written first */
        vf3_lit_vertex lit;
        if (!vf3_light_vertex(s, ram, group, selector, 1, &lit)) return 0;
        const float y0 = vf3_f_mul(s, vf3_bits_f32(lit.y), lit.inv_depth);
        const float z0 = vf3_f_mul(s, vf3_bits_f32(lit.z), lit.inv_depth);
        w1 = lit.w1;
        w2 = lit.w2;

        vf3_mem_set_f32(ram, slot - 8, lit.intensity);   /* colour for slots 1..3, see above */
        vf3_mem_set_f32(ram, slot - 4, lit.specular);
        vf3_mem_set_f32(ram, slot + SLOT_DIFFUSE, lit.intensity);
        vf3_mem_set_f32(ram, slot + SLOT_SPECULAR, lit.specular);
        vf3_mem_set_u32(ram, slot + SLOT_W2, lit.w2);
        vf3_mem_set_u32(ram, slot + SLOT_W1, lit.w1);
        vf3_mem_set_f32(ram, slot + SLOT_Z, z0);
        vf3_mem_set_f32(ram, slot + SLOT_INV, lit.inv_depth);
        vf3_mem_set_u32(ram, slot + SLOT_CTRL, lit.depth);
        vf3_mem_set_f32(ram, slot + SLOT_Y, y0);
        vf3_mem_set_u32(ram, slot + SLOT_CTRL, slot);
        flush(ram, slot);

        /* vertices 1 and 2: position only */
        screen_vertex v1, v2, v3;
        const uint32_t rec3 = group + 3 * RECORD_SIZE;
        if (!project(s, ram, group + RECORD_SIZE, &v1)) return 0;
        emit_position(ram, slot + SLOT_SIZE, &v1, slot + SLOT_SIZE);
        flush(ram, slot + SLOT_SIZE);
        if (!project(s, ram, group + 2 * RECORD_SIZE, &v2)) return 0;
        emit_position(ram, slot + 2 * SLOT_SIZE, &v2, slot + 2 * SLOT_SIZE);

        /* which way the triangle 0-1-2 faces decides whether vertex 3 is kept */
        const float y0s = vf3_f_add(s, 0.0f, y0), z0s = vf3_f_add(s, 0.0f, z0);
        const float dy01 = vf3_f_sub(s, y0s, v1.y_scaled);
        const float dz01 = vf3_f_sub(s, z0s, v1.z_scaled);
        const float dy12 = vf3_f_sub(s, vf3_f_add(s, 0.0f, v1.y_scaled), v2.y_scaled);
        const float dz12 = vf3_f_sub(s, v1.z_scaled, v2.z_scaled);
        const int quad = vf3_f_mul(s, dy01, dz12) > vf3_f_mul(s, dz01, dy12);

        units -= GROUP_UNITS;
        if (quad) {
            flush(ram, slot + 2 * SLOT_SIZE);
            if (!project(s, ram, rec3, &v3)) return 0;
            const uint32_t slot3 = slot + 3 * SLOT_SIZE;
            /* the control word of the last vertex is a shifted address, not 0xFFFFFFFF */
            r0 = (uint32_t)((int32_t)(slot3 + 24) >> 1);
            emit_position(ram, slot3, &v3, r0);
            r5 += 2 * 64;
            flush(ram, slot3);
            slot += 4 * SLOT_SIZE;
        } else {
            r0 = rec3 + 16;                              /* the copy of r4 that two pair loads walked on */
            w1 = PCW_VERTEX_EOS;
            vf3_mem_set_u32(ram, slot + 2 * SLOT_SIZE, PCW_VERTEX_EOS);
            flush(ram, slot + 2 * SLOT_SIZE);
        }
        group += GROUP_RECORDS * RECORD_SIZE;           /* at the group's tail */
        if (units == 0) break;
        group += GROUP_TAIL;
    }

    s->v[0] = r0;
    s->v[1] = w1;
    s->v[2] = w2;
    s->v[4] = group;
    s->v[5] = r5;
    s->v[6] = slot;
    s->v[9] = 0;
    s->v[14] = first_slot;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
