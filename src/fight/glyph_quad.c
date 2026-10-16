/* glyph_quad.c - 0x8C0C13C4  draw one character cell of the on-screen text/HUD font.
 *
 *   r4 = text context (u16 at +0x24 selects the entry of the colour-scale table at 0x0C10FE94),
 *   r5 = packed cursor word (bits 1..6: column, bits 7..12: row; advanced past the glyph),
 *   r6 = character code, r7 = font id (0 / 0x53 / 0x4000 / 0x4030, anything else is handed to
 *        the alternate font drawer 0x8C0C15E8)
 *   -> r0 = the advanced cursor word
 *
 * The font id picks the glyph cell size in texels (FR14 wide, FR15 high) and how far the
 * cursor moves. tex_cell_load (0x8C07B4D4) describes the font's texture cell in the scratch
 * block (r13); the glyph's row/column inside the cell come from the character code, sprite_rect_a/b
 * (0x8C07B35C / 0x8C07B398) fill a sprite object on the stack with position and UVs, a flags word
 * at 0x0C29B864 can shade it (bit 0x0C00 / 0x0300 pick the TA header word and a z tilt), and
 * sprite_quad (0x8C03F830) submits it. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

enum {
    TEX_CELL_LOAD = 0x8C07B4D4, SPRITE_RECT_A = 0x8C07B35C, SPRITE_RECT_B = 0x8C07B398,
    SPRITE_QUAD = 0x8C03F830, ALT_FONT = 0x8C0C15E8,
    RET_AFTER_CELL = 0x8C0C1424, RET_AFTER_ALT = 0x8C0C1486, RET_AFTER_RECT_A = 0x8C0C151A,
    RET_AFTER_RECT_B = 0x8C0C1536, RET_AFTER_QUAD = 0x8C0C15A0,
    CONST_8 = 0x41000000, CONST_16 = 0x41800000, CONST_24 = 0x41C00000,
    TILT_Z = 0x3F333333, TILT_X = 0x3B666666, TILT_Y = 0x3AE66666,   /* 0.7, 0.0035156, 0.0017578 */
    COLOR_SCALE_TABLE = 0x0C10FE94, SHADE_FLAGS = 0x0C29B864, SPRITE_CELL_TABLE = 0x0C2A620C,
    FONT_ASCII = 0, FONT_NARROW = 0x53, FONT_WIDE = 0x4000, FONT_WIDE_KANA = 0x4030,
    HEADER_PLAIN = 0x0605, HEADER_SHADED = 0x1605,
    SAVED_BYTES = 32, FRAME_BYTES = 72,
    LOCAL_CTX = 0, LOCAL_V = 4, LOCAL_X1 = 8, LOCAL_Y1 = 12, LOCAL_U = 16, LOCAL_SPRITE = 20,
    SPRITE_SHADE_Z = 68
};

static float float_of(const vf3_matrix_state *s, uint32_t v) { return vf3_f_from_int(s, (int32_t)v); }

int vf3_glyph_quad_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = s->v[15], pr0 = s->v[VF3_REG_PR];
    const uint32_t frame = sp0 - SAVED_BYTES - FRAME_BYTES;
    const uint32_t ctx = s->v[4], cursor0 = s->v[5], code0 = s->v[6], font = s->v[7];
    const uint32_t saved[4] = { s->v[14], s->v[13], s->v[12], s->v[11] };
    const uint32_t saved_fr[3] = { VF3_FR(s, 15), VF3_FR(s, 14), VF3_FR(s, 13) };

    for (int i = 0; i < 4; ++i) vf3_mem_set_u32(ram, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    for (int i = 0; i < 3; ++i) vf3_mem_set_u32(ram, sp0 - 16u - 4u * (uint32_t)(i + 1), saved_fr[i]);
    vf3_mem_set_u32(ram, sp0 - 32u, pr0);
    vf3_mem_set_u32(ram, frame + LOCAL_CTX, ctx);

    /* texel column/row of the cursor, in 8-texel units */
    s->v[12] = cursor0;
    s->v[14] = code0;
    s->v[11] = font;
    s->v[15] = frame;
    const uint32_t col = (cursor0 >> 1) & 63u, row = (cursor0 >> 7) & 63u;
    vf3_fr_set(s, 13, vf3_bits_f32(CONST_8));
    const float u = vf3_f_mul(s, float_of(s, col), vf3_fr_get(s, 13));
    const float v = vf3_f_mul(s, float_of(s, row), vf3_fr_get(s, 13));
    vf3_mem_set_u32(ram, frame + LOCAL_U, vf3_f32_bits(u));
    vf3_mem_set_u32(ram, frame + LOCAL_V, vf3_f32_bits(v));

    s->v[4] = font;
    if (!vf3_guest_call(s, ram, TEX_CELL_LOAD, RET_AFTER_CELL)) return 0;
    const uint32_t cell = s->v[0];                 /* r13 = scratch block */
    s->v[13] = cell;
    s->v[15] = frame;
    float cw = 0.0f, ch = 0.0f;                    /* FR14 / FR15 */
    uint32_t cursor = cursor0, code = code0;
    int skip_check = 0;                            /* the narrow font jumps past the blank test */
    const float sixteen = vf3_bits_f32(CONST_16);
    vf3_fr_set(s, 4, sixteen);
    switch (font) {
    case FONT_ASCII:      ch = sixteen; cw = vf3_fr_get(s, 13); cursor += 2; break;
    case FONT_WIDE:       ch = vf3_fr_get(s, 13); cw = ch; cursor += 2; break;
    case FONT_NARROW:
        cw = ch = sixteen;
        cursor += 4;
        if (code == 32) { s->v[0] = cursor; goto epilogue; }
        code -= 16;
        skip_check = 1;
        break;
    case FONT_WIDE_KANA:
        if (code >= 97) code -= 32;
        cw = sixteen;
        ch = vf3_bits_f32(CONST_24);
        code -= 32;
        cursor += 4;
        break;
    default: {
        code -= 48;
        s->v[5] = cursor0;
        s->v[6] = code;
        s->v[7] = font;
        s->v[4] = ctx;
        s->v[12] = cursor0;
        s->v[14] = code;
        if (!vf3_guest_call(s, ram, ALT_FONT, RET_AFTER_ALT)) return 0;
        goto epilogue;
    }
    }
    s->v[12] = cursor;
    s->v[14] = code;
    vf3_fr_set(s, 14, cw);
    vf3_fr_set(s, 15, ch);
    if (!skip_check && code == 32) { s->v[0] = cursor; goto epilogue; }

    {
        /* glyph (column in the low nibble, row in the high nibble of the code - 32) */
        const float gx = float_of(s, code & 15u);
        const float x1 = vf3_f_mac(s, cw, gx, vf3_mem_f32(ram, cell));
        vf3_mem_set_u32(ram, frame + LOCAL_X1, vf3_f32_bits(x1));
        const uint32_t grow = (code & 0xF0u) >> 4;
        const float gy = float_of(s, grow);
        const float y1 = vf3_f_mac(s, ch, gy, vf3_mem_f32(ram, cell + 4u));
        vf3_mem_set_u32(ram, frame + LOCAL_Y1, vf3_f32_bits(y1));
        s->v[14] = grow;

        const float cell_w = vf3_mem_f32(ram, cell + 16u), cell_h = vf3_mem_f32(ram, cell + 20u);
        const float ew = vf3_f_mul(s, cw, cell_w);
        const uint32_t colour = vf3_mem_u16(ram, vf3_mem_u32(ram, frame + LOCAL_CTX) + 36u);
        const float eh = vf3_f_mul(s, ch, cell_h);
        const float scale = vf3_mem_f32(ram, COLOR_SCALE_TABLE + 4u * colour);
        const uint32_t sprite = frame + LOCAL_SPRITE;

        s->v[4] = sprite;
        s->v[13] = cell;
        vf3_fr_set(s, 4, vf3_mem_f32(ram, frame + LOCAL_U));
        vf3_fr_set(s, 5, vf3_mem_f32(ram, frame + LOCAL_V));
        vf3_fr_set(s, 6, ew);
        vf3_fr_set(s, 7, eh);
        vf3_fr_set(s, 8, scale);
        s->v[0] = 16;
        s->v[2] = SPRITE_RECT_A;
        if (!vf3_guest_call(s, ram, SPRITE_RECT_A, RET_AFTER_RECT_A)) return 0;
        s->v[15] = frame;

        s->v[4] = sprite;
        s->v[3] = SPRITE_RECT_B;
        vf3_fr_set(s, 9, cell_h);
        vf3_fr_set(s, 8, cell_w);
        vf3_fr_set(s, 5, vf3_mem_f32(ram, frame + LOCAL_Y1));
        vf3_fr_set(s, 4, vf3_mem_f32(ram, frame + LOCAL_X1));
        vf3_fr_set(s, 7, ch);
        vf3_fr_set(s, 6, cw);
        if (!vf3_guest_call(s, ram, SPRITE_RECT_B, RET_AFTER_RECT_B)) return 0;
        s->v[15] = frame;

        float z = 1.0f;
        uint32_t header = HEADER_PLAIN;
        const uint32_t shade = vf3_mem_u32(ram, SHADE_FLAGS);
        vf3_mem_set_u32(ram, frame + SPRITE_SHADE_Z, vf3_f32_bits(z));
        if ((shade & 0x0C00u) != 0) {
            header = HEADER_SHADED;
        } else if ((shade & 0x0300u) != 0) {
            header = HEADER_SHADED;
            z = vf3_bits_f32(TILT_Z);
            vf3_mem_set_u32(ram, frame + SPRITE_SHADE_Z, vf3_f32_bits(z));
            const float tx = vf3_bits_f32(TILT_X), ty = vf3_bits_f32(TILT_Y);
            vf3_mem_set_u32(ram, frame + 36u, vf3_f32_bits(vf3_f_sub(s, vf3_mem_f32(ram, frame + 36u), tx)));
            vf3_mem_set_u32(ram, frame + 44u, vf3_f32_bits(vf3_f_add(s, vf3_mem_f32(ram, frame + 44u), ty)));
            vf3_mem_set_u32(ram, frame + 52u, vf3_f32_bits(vf3_f_sub(s, vf3_mem_f32(ram, frame + 52u), ty)));
            vf3_fr_set(s, 4, ty);
        }
        const uint32_t cell_index = vf3_mem_u32(ram, cell + 32u);
        const uint32_t sprite_cell = vf3_mem_u16(ram, SPRITE_CELL_TABLE + 2u * cell_index);
        vf3_mem_set_u32(ram, frame + LOCAL_SPRITE, sprite_cell);
        vf3_mem_set_u32(ram, frame + 60u, 0);
        vf3_mem_set_u32(ram, frame + 64u, header);
        s->v[4] = sprite;
        s->v[3] = SPRITE_QUAD;
        s->v[2] = sprite_cell;
        s->v[5] = shade;
        if (!vf3_guest_call(s, ram, SPRITE_QUAD, RET_AFTER_QUAD)) return 0;
    }
    s->v[0] = cursor;
epilogue:
    s->v[15] = sp0;
    s->v[14] = saved[0];
    s->v[13] = saved[1];
    s->v[12] = saved[2];
    s->v[11] = saved[3];
    VF3_FR(s, 15) = saved_fr[0];
    VF3_FR(s, 14) = saved_fr[1];
    VF3_FR(s, 13) = saved_fr[2];
    s->v[VF3_REG_PR] = pr0;
    s->pc = pr0;
    return 1;
}
