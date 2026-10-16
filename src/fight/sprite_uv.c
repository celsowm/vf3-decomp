/* sprite_uv.c - texture-cell helpers of the 2D sprite/glyph path.
 *
 *   0x8C07B4D4  tex_cell_load   r4 = cell id -> fills the cell scratch block at 0x0C1B9620
 *   0x8C07B35C  sprite_rect_a   r4 = vertex block, FR4/FR5 = x/y, FR6/FR7 = w/h, FR8 = z:
 *                               writes position, z and the UV extent (words +4..+14)
 *   0x8C07B398  sprite_rect_b   the opposite corner's UV pair (words +18..+24)
 *
 * A cell id selects a record from one of two tables: ids with bit 0x4000 set index a table of
 * six-byte records at 0x0C11ABB0 (u16 id, four byte fields), others the pair table at
 * 0x0C11AA60 (two u16 per entry). The scratch block receives the cell's rectangle in texels
 * (x8 as floats) and the reciprocal-scaled UV extents the sprite quad (0x8C03F830) consumes. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

enum {
    CELL_RECORDS = 0x0C11ABB0u, CELL_PAIRS = 0x0C11AA60u, CELL_FLAG = 0x4000u, CELL_INDEX_MASK = 0x3FFFu,
    SCRATCH = 0x0C1B9620u,          /* +0 x, +4 y, +8 w, +C h (texels * 8) */
    SCRATCH_ID = 0x0C1B9640u,       /* the cell id being drawn */
    SCRATCH_RECIP_W = 0x0C1B9630u, SCRATCH_RECIP_H = 0x0C1B9634u,
    SCRATCH_U = 0x0C1B9638u, SCRATCH_V = 0x0C1B963Cu,
    SR_T = 1u
};

static uint32_t u16_shl3(uint32_t v) { return (v & 0xFFFFu) << 3; }

int vf3_tex_cell_load_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = s->v[15], saved_r14 = s->v[14], saved_r13 = s->v[13];
    vf3_mem_set_u32(ram, sp - 4u, saved_r14);
    vf3_mem_set_u32(ram, sp - 8u, saved_r13);

    uint32_t id = s->v[4] & 0xFFFFu, first, x, y, w, h;
    if (id & CELL_FLAG) {
        const uint32_t rec = CELL_RECORDS + 6u * (id & CELL_INDEX_MASK);
        first = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, rec);
        x = vf3_mem_u8(ram, rec + 2u);
        y = vf3_mem_u8(ram, rec + 3u);
        w = vf3_mem_u8(ram, rec + 4u);
        h = vf3_mem_u8(ram, rec + 5u);
        s->v[VF3_REG_SR] &= ~SR_T;
    } else {
        const uint32_t pair = CELL_PAIRS + 4u * id;
        first = s->v[4];
        x = y = 0;
        w = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, pair);
        h = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, pair + 2u);
        s->v[VF3_REG_SR] |= SR_T;
    }
    s->v[6] = u16_shl3(x);
    s->v[7] = u16_shl3(y);
    w = u16_shl3(w);
    h = u16_shl3(h);

    vf3_mem_set_u32(ram, SCRATCH_ID, first & 0xFFFFu);
    vf3_mem_set_u32(ram, SCRATCH + 0, vf3_f32_bits(vf3_f_from_int(s, (int32_t)s->v[6])));
    vf3_mem_set_u32(ram, SCRATCH + 4, vf3_f32_bits(vf3_f_from_int(s, (int32_t)s->v[7])));
    vf3_mem_set_u32(ram, SCRATCH + 8, vf3_f32_bits(vf3_f_from_int(s, (int32_t)w)));
    vf3_mem_set_u32(ram, SCRATCH + 12, vf3_f32_bits(vf3_f_from_int(s, (int32_t)h)));

    /* the reciprocal pair comes from the id's entry in the pair table whatever the id's kind */
    const uint32_t pair = CELL_PAIRS + 4u * (first & 0xFFFFu);
    const uint32_t pw = u16_shl3((uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, pair)) & 0xFFFFu;
    const uint32_t ph = u16_shl3(vf3_mem_u16(ram, pair + 2u)) & 0xFFFFu;
    const float one = 1.0f;
    const float recip_w = vf3_f_div(s, one, vf3_f_from_int(s, (int32_t)pw));
    const float recip_h = vf3_f_div(s, one, vf3_f_from_int(s, (int32_t)ph));
    vf3_mem_set_u32(ram, SCRATCH_RECIP_W, vf3_f32_bits(recip_w));
    vf3_mem_set_u32(ram, SCRATCH_RECIP_H, vf3_f32_bits(recip_h));
    const float u = vf3_f_mul(s, vf3_mem_f32(ram, SCRATCH + 8), recip_w);
    const float v = vf3_f_mul(s, vf3_mem_f32(ram, SCRATCH + 12), recip_h);
    vf3_mem_set_u32(ram, SCRATCH_U, vf3_f32_bits(u));
    vf3_mem_set_u32(ram, SCRATCH_V, vf3_f32_bits(v));

    s->v[1] = SCRATCH_RECIP_W;
    s->v[2] = SCRATCH_RECIP_H;
    s->v[3] = SCRATCH_V;
    s->v[0] = SCRATCH;
    s->v[4] = pw;
    s->v[5] = ph;
    s->v[VF3_REG_FPUL] = ph;
    vf3_fr_set(s, 2, v);
    vf3_fr_set(s, 3, recip_h);
    vf3_fr_set(s, 4, recip_h);
    s->v[14] = saved_r14;
    s->v[13] = saved_r13;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* sprite_rect_a: the vertex block's position (scaled and offset by the screen constants at
 * 0x0C10B7FC..0x0C10B808), z and UV extent. */
enum { SCALE_X = 0x0C10B7FCu, SCALE_Y = 0x0C10B800u, OFFSET_X = 0x0C10B804u, OFFSET_Y = 0x0C10B808u };

int vf3_sprite_rect_a_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t block = s->v[4];
    const float sx = vf3_mem_f32(ram, SCALE_X), sy = vf3_mem_f32(ram, SCALE_Y);
    const float ox = vf3_mem_f32(ram, OFFSET_X), oy = vf3_mem_f32(ram, OFFSET_Y);
    vf3_mem_set_u32(ram, s->v[15] - 4u, vf3_f32_bits(sx));          /* dead spill */
    const float x = vf3_f_add(s, vf3_f_mul(s, vf3_fr_get(s, 4), sx), ox);
    const float y = vf3_f_add(s, vf3_f_mul(s, vf3_fr_get(s, 5), sy), oy);
    vf3_mem_set_u32(ram, block + 4u, vf3_f32_bits(x));
    vf3_mem_set_u32(ram, block + 8u, vf3_f32_bits(y));
    vf3_mem_set_u32(ram, block + 12u, VF3_FR(s, 8));
    const float uw = vf3_f_mul(s, sx, vf3_fr_get(s, 6));
    const float vh = vf3_f_mul(s, sy, vf3_fr_get(s, 7));
    vf3_mem_set_u32(ram, block + 16u, vf3_f32_bits(uw));
    vf3_mem_set_u32(ram, block + 20u, vf3_f32_bits(vh));
    s->v[0] = 20;
    s->v[2] = OFFSET_Y;
    s->v[3] = OFFSET_X;
    s->v[5] = SCALE_X;
    s->v[6] = SCALE_Y;
    vf3_fr_set(s, 3, vh);
    vf3_fr_set(s, 4, x);
    vf3_fr_set(s, 5, y);
    vf3_fr_set(s, 9, sy);
    vf3_fr_set(s, 10, ox);
    vf3_fr_set(s, 11, oy);
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

/* sprite_rect_b: the far corner. FR4/FR5 are the near corner, FR6/FR7 its extent, FR8/FR9 the
 * UV scales; the stored values are (corner + bias) * scale for the four corner UVs. */
int vf3_sprite_rect_b_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    static const uint32_t BIAS_A = 0x3A8461F9u, BIAS_B = 0x33D6BF94u, BIAS_C = 0x80000000u, BIAS_D = 0xBED70A3Du;
    const uint32_t block = s->v[4];
    const float x = vf3_fr_get(s, 4), y = vf3_fr_get(s, 5);
    const float su = vf3_fr_get(s, 8), sv = vf3_fr_get(s, 9);

    const float x1 = vf3_f_add(s, x, vf3_fr_get(s, 6));
    const float u0 = vf3_f_mul(s, vf3_f_add(s, x, vf3_bits_f32(BIAS_A)), su);
    vf3_mem_set_u32(ram, block + 24u, vf3_f32_bits(u0));
    const float y1 = vf3_f_add(s, y, vf3_fr_get(s, 7));
    const float v0 = vf3_f_mul(s, vf3_f_add(s, y, vf3_bits_f32(BIAS_B)), sv);
    vf3_mem_set_u32(ram, block + 28u, vf3_f32_bits(v0));
    const float u1 = vf3_f_mul(s, vf3_f_add(s, x1, vf3_bits_f32(BIAS_C)), su);
    vf3_mem_set_u32(ram, block + 32u, vf3_f32_bits(u1));
    const float v1 = vf3_f_mul(s, vf3_f_add(s, y1, vf3_bits_f32(BIAS_D)), sv);
    vf3_mem_set_u32(ram, block + 36u, vf3_f32_bits(v1));
    s->v[0] = 36;
    vf3_fr_set(s, 1, vf3_bits_f32(BIAS_C));
    vf3_fr_set(s, 2, vf3_bits_f32(BIAS_B));
    vf3_fr_set(s, 3, vf3_bits_f32(BIAS_D));
    vf3_fr_set(s, 4, u1);
    vf3_fr_set(s, 5, v1);
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
