/* sprite_readable.c - billboard quad submission of the fight engine.
 *
 *   0x8C03F830  r4 = sprite object
 *
 * Looks the object's sprite index up in the table at 0x0C19E208 (index -1 = nothing to
 * draw), scales the four corner offsets by the object's size/rotation (sin/cos of the
 * angle at +28 through the corner fan 0x8C03FB10), packs the 16-bit texture coordinates,
 * patches the sprite's TA header words (entry of 0x20 bytes in the table at 0x0C19E214)
 * and finally pushes header + four vertices through the store queue (3 SQ lines), then
 * advances the SQ cursor kept next to the table at 0x0C16CA08.
 *
 * The original saves r8-r14, FR13-FR15 and PR (44 bytes) and a 60 byte frame; the dead
 * stack words are replayed because they are visible in RAM. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

int vf3_sin_u16_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_cos_u16_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_corner_fan_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

enum {
    SPRITE_INDEX_TABLE = 0x0C19E208, SPRITE_HEADER_TABLE = 0x0C19E214,
    SQ_STATE = 0x0C16CA08, QACR0 = 0xFF000038, QACR1 = 0xFF00003C,
    HALF_CONST = 0x0C03F978, SCALE_X = 0x0C0EA538, SCALE_Y = 0x0C0EA534, SCALE_TAB = 0x0C0EA668,
    TINT_TAB = 0x0C0EA634,
    ENTRY_COLOR_FN = 0x0C03FB80, RET_AFTER_FAN = 0x0C03F8DA, RET_AFTER_COLOR = 0x0C03F9EA,
    OBJ_FLAGS = 0x2C,
    SPRITE_NONE = -1,
    SQ_REGION_MASK = 0xFC000000, SQ_REGION = 0xE0000000, SQ_ADDR_MASK = 0x03FFFFFF
};
#define FRAME_BYTES 60u
#define SAVED_BYTES 44u

static void call_sin_cos(vf3_matrix_state *s, const vf3_ram_map *ram, int cos, uint32_t angle)
{
    s->v[4] = angle;
    s->v[VF3_REG_PR] = cos ? 0x0C03F8BEu : 0x0C03F8B6u;
    if (cos) vf3_cos_u16_entry(s, ram); else vf3_sin_u16_entry(s, ram);
}

int vf3_sprite_quad_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = s->v[15], obj = s->v[4];
    const uint32_t frame = sp0 - SAVED_BYTES - FRAME_BYTES;
    const uint32_t pr = s->v[VF3_REG_PR];

    /* prologue pushes: r14 r13 r12 r11 r10 r9 r8 fr15 fr14 fr13 pr */
    for (int i = 0; i < 7; ++i) vf3_mem_set_u32(ram, sp0 - 4u * (uint32_t)(i + 1), s->v[14 - i]);
    vf3_mem_set_u32(ram, sp0 - 32u, VF3_FR(s, 15));
    vf3_mem_set_u32(ram, sp0 - 36u, VF3_FR(s, 14));
    vf3_mem_set_u32(ram, sp0 - 40u, VF3_FR(s, 13));
    vf3_mem_set_u32(ram, sp0 - 44u, pr);

    const uint32_t index_word = vf3_mem_u32(ram, obj);
    const int32_t sprite = (int16_t)vf3_mem_u16(ram, vf3_mem_u32(ram, SPRITE_INDEX_TABLE) + 2u * index_word);
    if (sprite == SPRITE_NONE) { s->v[15] = sp0; s->pc = pr; return 1; }

    const uint32_t hdr = vf3_mem_u32(ram, SPRITE_HEADER_TABLE) + ((uint32_t)sprite << 5);
    const float one = 1.0f;
    float size_scale = vf3_mem_f32(ram, obj + 0x30);
    const int translucent = one > size_scale || vf3_mem_u32(ram, hdr + 20u) != 0;

    const float half = vf3_mem_f32(ram, HALF_CONST);
    const float obj_w = vf3_mem_f32(ram, obj + 0x10), obj_h = vf3_mem_f32(ram, obj + 0x14);
    const float dx = vf3_f_mul(s, vf3_f_mul(s, vf3_mem_f32(ram, hdr + 0x18), obj_w), half);
    const float dy = vf3_f_mul(s, vf3_f_mul(s, vf3_mem_f32(ram, hdr + 0x1C), obj_h), half);
    vf3_mem_set_f32(ram, frame + 8u, dx);
    vf3_mem_set_f32(ram, frame + 4u, dy);
    const float inv_depth = vf3_f_div(s, one, vf3_mem_f32(ram, obj + 0x0C));   /* FR13 */

    s->v[15] = frame;
    call_sin_cos(s, ram, 0, vf3_mem_u32(ram, obj + 0x28));
    vf3_mem_set_u32(ram, frame, VF3_FR(s, 0));
    call_sin_cos(s, ram, 1, vf3_mem_u32(ram, obj + 0x28));

    const uint32_t out_b = frame + 28u, out_a = frame + 44u;
    s->v[4] = obj; s->v[5] = out_a; s->v[6] = out_b;
    VF3_FR(s, 7) = VF3_FR(s, 0);
    vf3_fr_set(s, 4, dx);
    vf3_fr_set(s, 5, dy);
    VF3_FR(s, 6) = vf3_mem_u32(ram, frame);
    s->v[VF3_REG_PR] = RET_AFTER_FAN;
    vf3_corner_fan_entry(s, ram);

    /* squash the fan corners by the two global scale factors */
    const float scale_x = vf3_mem_f32(ram, SCALE_X), scale_y = vf3_mem_f32(ram, SCALE_Y);
    const float tab_y = vf3_f_mul(s, vf3_mem_f32(ram, SCALE_TAB + 4u), scale_x);
    const float tab_x = vf3_f_mul(s, vf3_mem_f32(ram, SCALE_TAB), scale_y);
    for (uint32_t i = 0; i < 16u; i += 4u) {
        vf3_mem_set_f32(ram, out_a + i, vf3_f_mul(s, vf3_mem_f32(ram, out_a + i), tab_x));
        vf3_mem_set_f32(ram, out_b + i, vf3_f_mul(s, vf3_mem_f32(ram, out_b + i), tab_y));
    }

    /* patch the sprite header from the object flags */
    vf3_mem_set_u32(ram, hdr, vf3_mem_u32(ram, hdr) & 0xF8FFFFFFu);
    uint32_t h8 = vf3_mem_u32(ram, hdr + 8u) & 0x03279FFFu;
    const uint32_t flags = vf3_mem_u32(ram, obj + OBJ_FLAGS);
    if (!(flags & 0x0800u)) h8 |= 0x00800000u;
    if (flags & 0x1000u) h8 |= 0x2000u;
    vf3_mem_set_u32(ram, hdr + 8u, h8);

    uint32_t blend = ((int32_t)flags >> 8) & 7u;
    if (blend == 0) blend = 4u;
    vf3_mem_set_u32(ram, hdr + 4u, (vf3_mem_u32(ram, hdr + 4u) & 0x1FFFFFFFu) | (blend << 29));
    float tint = size_scale;
    if (translucent) {
        vf3_mem_set_u32(ram, hdr, vf3_mem_u32(ram, hdr) | 0x02000000u);
        vf3_mem_set_u32(ram, hdr + 8u, vf3_mem_u32(ram, hdr + 8u) | 0x94100000u);
    } else {
        vf3_mem_set_u32(ram, hdr + 8u, vf3_mem_u32(ram, hdr + 8u) | 0x20080000u);
        tint = one;
    }

    /* colour: tint scaled through the packer 0x8C03FB80 */
    vf3_fr_set(s, 4, tint);
    if (vf3_mem_u32(ram, obj + OBJ_FLAGS) & 0x2000u) {
        vf3_fr_set(s, 5, vf3_mem_f32(ram, TINT_TAB));
        vf3_fr_set(s, 6, vf3_mem_f32(ram, TINT_TAB + 4u));
        vf3_fr_set(s, 7, vf3_mem_f32(ram, TINT_TAB + 8u));
    } else {
        vf3_fr_set(s, 5, one);
        vf3_fr_set(s, 6, one);
        vf3_fr_set(s, 7, one);
    }
    if (!vf3_guest_call(s, ram, ENTRY_COLOR_FN, RET_AFTER_COLOR)) return 0;
    vf3_mem_set_u32(ram, hdr + 16u, s->v[0]);

    /* texture coordinates: the (u0,v0) pair is flipped when flag 0x10 is set, the
     * (u1,v1) pair when flag 0x20 is clear */
    uint32_t mirror = vf3_mem_u32(ram, obj + OBJ_FLAGS) & 0x30u;
    float u0 = vf3_mem_f32(ram, obj + 0x18), v0 = vf3_mem_f32(ram, obj + 0x20);
    if (mirror & 0x10u) { u0 = vf3_f_sub(s, one, u0); v0 = vf3_f_sub(s, one, v0); }
    float u1 = vf3_mem_f32(ram, obj + 0x1C), v1 = vf3_mem_f32(ram, obj + 0x24);
    if (!(mirror & 0x20u)) { u1 = vf3_f_sub(s, one, u1); v1 = vf3_f_sub(s, one, v1); }
    uint32_t bits_u0 = vf3_f32_bits(u0), bits_v0 = vf3_f32_bits(v0);
    uint32_t bits_u1 = vf3_f32_bits(u1), bits_v1 = vf3_f32_bits(v1);
    vf3_mem_set_u32(ram, frame + 24u, bits_u0);
    vf3_mem_set_u32(ram, frame + 20u, bits_u0 & 0xFFFF0000u);
    vf3_mem_set_u32(ram, frame + 24u, bits_v0);
    uint32_t pack_hi = bits_v0 & 0xFFFF0000u;                 /* r13 */
    vf3_mem_set_u32(ram, frame + 24u, bits_u1);
    const uint32_t pack_lo = bits_u1 >> 16;                   /* r7  */
    vf3_mem_set_u32(ram, frame + 24u, bits_v1);
    vf3_mem_set_u32(ram, frame + 16u, bits_v1 >> 16);
    const uint32_t lo_word = bits_v1 >> 16;
    const uint32_t line_off = translucent ? 8u : 0u;
    vf3_mem_set_u32(ram, frame + 12u, line_off);

    /* store-queue submission: header line, then two vertex lines */
    uint32_t sq_base = vf3_mem_u32(ram, SQ_STATE);
    uint32_t sq_word = vf3_mem_u32(ram, sq_base + line_off);
    uint32_t qacr = sq_word >> 24;
    vf3_mem_set_u32(ram, QACR0, qacr);
    vf3_mem_set_u32(ram, QACR1, qacr);
    uint32_t q = (sq_word & SQ_ADDR_MASK) | SQ_REGION;
    for (uint32_t i = 0; i < 20u; i += 4u) vf3_mem_set_u32(ram, q + i, vf3_mem_u32(ram, hdr + i));
    vf3_matrix_pref(ram, q);
    q += 32u;
    vf3_mem_set_u32(ram, q, 0xFFFFFFFFu);
    vf3_mem_set_u32(ram, q + 4u, vf3_mem_u32(ram, out_a));
    vf3_mem_set_u32(ram, q + 8u, vf3_mem_u32(ram, out_b));
    vf3_mem_set_f32(ram, q + 12u, inv_depth);
    vf3_mem_set_u32(ram, q + 16u, vf3_mem_u32(ram, out_a + 4u));
    vf3_mem_set_u32(ram, q + 20u, vf3_mem_u32(ram, out_b + 4u));
    vf3_mem_set_f32(ram, q + 24u, inv_depth);
    vf3_mem_set_u32(ram, q + 28u, vf3_mem_u32(ram, out_a + 8u));
    vf3_mem_set_u32(ram, q + 32u, vf3_mem_u32(ram, out_b + 8u));
    vf3_mem_set_f32(ram, q + 36u, inv_depth);
    vf3_mem_set_u32(ram, q + 40u, vf3_mem_u32(ram, out_a + 12u));
    vf3_mem_set_u32(ram, q + 44u, vf3_mem_u32(ram, out_b + 12u));
    vf3_mem_set_u32(ram, q + 48u, (uint32_t)sprite | 0x53500000u);
    vf3_mem_set_u32(ram, q + 52u, vf3_mem_u32(ram, frame + 20u) | pack_lo);
    vf3_mem_set_u32(ram, q + 56u, pack_lo | pack_hi);
    vf3_mem_set_u32(ram, q + 60u, pack_hi | lo_word);
    vf3_matrix_pref(ram, q);
    q += 32u;
    vf3_matrix_pref(ram, q);
    q += 32u;

    const uint32_t cursor = vf3_mem_u32(ram, SQ_STATE) + line_off;
    vf3_mem_set_u32(ram, cursor, (vf3_mem_u32(ram, cursor) & SQ_REGION_MASK) | (q & SQ_ADDR_MASK));

    s->v[15] = sp0;
    s->pc = pr;
    return 1;
}
