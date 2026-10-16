/* project_verts.c - 0x8C058EA0  project and light a run of vertices into the 16-byte output records.
 *
 *   r4 = source stream (six floats per vertex: position xyz, normal xyz), r6 = vertex count,
 *   r7 -> the mode word (bit 2 selects the second, light-vector variant)
 *   XMTRX = the view/projection matrix, 0x0C16B8A8 = the depth scale (reciprocal is applied to
 *   the light direction table entry at 0x0C19D5B0 + 0x80), 0x0C19E0B0 = ambient term.
 *
 * Per vertex: (x, y, z, 1) goes through XMTRX, the reciprocal of w is formed, and a record of
 *     +0 x/w   +4 y/w   +8 1/w   +C  max(dot(normal, light), 0) + ambient
 * is written at the output cursor (0x0C16B8AC points at the buffer, 0x0C16B8B0 receives the
 * advanced cursor). The variant with mode bit 2 also normalises a second direction
 * (0x0C058FE0 table * the same scale, plus the light) and writes dot(normal, direction) per
 * vertex into the side list at 0x0C16B8B8 (8-byte stride, end pointer to 0x0C16B8BC); it is
 * ported from the disassembly and is not exercised by the captured states. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

enum {
    CURSOR_PTR = 0x0C16B8ACu, CURSOR_OUT = 0x0C16B8B0u, DEPTH_SCALE = 0x0C16B8A8u,
    SIDE_PTR = 0x0C16B8B8u, SIDE_END = 0x0C16B8BCu, LIGHT_TABLE = 0x0C19D5B0u,
    AMBIENT = 0x0C19E0B0u, DIRECTION = 0x0C058FE0u, MODE_FLAG_ADDR = 0x0C055B8Cu,
    MODE_SIDE_LIST = 4, LIGHT_OFFSET = 0x80, RECORD_BYTES = 16, SR_T = 1u
};

static uint32_t *fr_at(vf3_matrix_state *s, int n) { return &VF3_FR(s, n); }

static int load_vertex(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t src)
{
    for (int i = 0; i < 3; ++i) VF3_FR(s, 4 + i) = vf3_mem_u32(ram, src + 4u * (uint32_t)i);
    vf3_fr_set(s, 7, 1.0f);
    if (!vf3_fpu_ftrv(&s->v[VF3_REG_XF0], fr_at(s, 4), s->v[VF3_REG_FPSCR], fr_at(s, 4))) return 0;
    for (int i = 0; i < 3; ++i) VF3_FR(s, i) = vf3_mem_u32(ram, src + 12u + 4u * (uint32_t)i);
    vf3_fr_set(s, 3, 0.0f);
    return 1;
}

int vf3_project_verts_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t src = s->v[4], count = s->v[6], mode_word = vf3_mem_u32(ram, s->v[7]);
    uint32_t out = vf3_mem_u32(ram, CURSOR_PTR) - 16u;

    VF3_FR(s, 0) = vf3_mem_u32(ram, DEPTH_SCALE);
    const float inv = vf3_f_div(s, 1.0f, vf3_fr_get(s, 0));
    vf3_fr_set(s, 1, inv);
    for (int i = 0; i < 3; ++i) {
        VF3_FR(s, 8 + i) = vf3_mem_u32(ram, LIGHT_TABLE + LIGHT_OFFSET + 4u * (uint32_t)i);
        vf3_fr_set(s, 8 + i, vf3_f_mul(s, vf3_fr_get(s, 8 + i), inv));
    }
    s->v[1] = MODE_SIDE_LIST;
    s->v[2] = MODE_FLAG_ADDR;
    const int side = (mode_word & MODE_SIDE_LIST) != 0;
    uint32_t side_cursor = 0;

    if (!side) {
        s->v[0] = 0;
        vf3_mem_set_u32(ram, MODE_FLAG_ADDR, 0);
    } else {
        s->v[0] = 1;
        vf3_mem_set_u32(ram, MODE_FLAG_ADDR, 1);
        for (int i = 0; i < 3; ++i) {
            VF3_FR(s, 12 + i) = vf3_mem_u32(ram, DIRECTION + 4u * (uint32_t)i);
            vf3_fr_set(s, 12 + i, vf3_f_add(s, vf3_f_mul(s, vf3_fr_get(s, 12 + i), inv),
                                            vf3_fr_get(s, 8 + i)));
        }
        vf3_fr_set(s, 15, 0.0f);
        if (!vf3_fpu_fipr(fr_at(s, 12), fr_at(s, 12), s->v[VF3_REG_FPSCR], fr_at(s, 15))) return 0;
        if (!vf3_fpu_fsrra(VF3_FR(s, 15), s->v[VF3_REG_FPSCR], fr_at(s, 15))) return 0;
        for (int i = 0; i < 3; ++i)
            vf3_fr_set(s, 12 + i, vf3_f_mul(s, vf3_fr_get(s, 12 + i), vf3_fr_get(s, 15)));
        side_cursor = vf3_mem_u32(ram, SIDE_PTR) + 4u;
        s->v[3] = side_cursor;
    }

    do {
        VF3_FR(s, 15) = vf3_mem_u32(ram, AMBIENT);
        out += 28u;
        if (!load_vertex(s, ram, src)) return 0;
        src += 24u;
        if (!vf3_fpu_fipr(fr_at(s, 0), fr_at(s, 8), s->v[VF3_REG_FPSCR], fr_at(s, 11))) return 0;
        vf3_fr_set(s, 6, vf3_f_div(s, 1.0f, vf3_fr_get(s, 7)));
        if (vf3_fr_get(s, 3) > vf3_fr_get(s, 11)) vf3_fr_set(s, 11, 0.0f);
        vf3_fr_set(s, 11, vf3_f_add(s, vf3_fr_get(s, 11), vf3_fr_get(s, 15)));
        vf3_mem_set_u32(ram, out, VF3_FR(s, 11));
        if (side) {
            if (!vf3_fpu_fipr(fr_at(s, 12), fr_at(s, 0), s->v[VF3_REG_FPSCR], fr_at(s, 3))) return 0;
            vf3_mem_set_u32(ram, side_cursor, VF3_FR(s, 3));
            side_cursor += 8u;
        }
        --count;
        vf3_mem_set_u32(ram, out - 4u, VF3_FR(s, 6));
        vf3_fr_set(s, 5, vf3_f_mul(s, vf3_fr_get(s, 5), vf3_fr_get(s, 6)));
        vf3_fr_set(s, 4, vf3_f_mul(s, vf3_fr_get(s, 4), vf3_fr_get(s, 6)));
        vf3_mem_set_u32(ram, out - 8u, VF3_FR(s, 5));
        vf3_mem_set_u32(ram, out - 12u, VF3_FR(s, 4));
        out -= 12u;
    } while (count != 0);

    out += RECORD_BYTES - 0u;
    s->v[0] = CURSOR_OUT;
    s->v[4] = src;
    s->v[5] = out;
    s->v[6] = 0;
    vf3_mem_set_u32(ram, CURSOR_OUT, out);
    if (side) {
        s->v[1] = SIDE_END;
        s->v[3] = side_cursor;
        vf3_mem_set_u32(ram, SIDE_END, side_cursor);
    }
    s->v[VF3_REG_SR] |= SR_T;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
