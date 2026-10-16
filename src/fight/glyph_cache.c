/* glyph_cache.c - the HUD text layer's sprite pool.
 *
 *   0x8C07B2BE  pool_alloc(r4 = layer)         -> r0 = a free 68-byte entry, or 0 when full
 *   0x8C0C1FBA  glyph_cache(r4 = cursor word, r5 = key, r6 = layer, r7 = packed cell (0 = take
 *               it from the cursor), stack: [sp] = packed texel offsets, [sp+4] = flag bits)
 *               -> r0 = the sprite object inside the entry, or 0
 *
 * The layer (r6) keeps a pool of 120 entries of 68 bytes at *(layer + 12) and a rotating
 * allocation cursor (u16 at layer + 42). An entry is { u16 live+flags, u16 key, u16 sprite
 * cell, u16 column*8, u16 row*8, u16 width/8, u16 height/8, ..., sprite object at +16 }.
 *
 * glyph_cache has two modes: with key bit 0x8000 set it retires every entry that was drawn at
 * this column/row with the same key (and returns 0); without it, it first retires such an
 * entry (calling itself with the flag set), then allocates a fresh one, fills its cell
 * rectangle, the texture cell from tex_cell_load, the optional texel offsets of the packed
 * word, and builds the sprite object with sprite_rect_a/b. The flag bits of the last argument
 * become the entry's flag word (and the TA header word handed to the object). */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

enum {
    POOL_ENTRIES = 120, ENTRY_BYTES = 68, LAYER_POOL = 12, LAYER_CURSOR = 42, LAYER_TINT = 38,
    FULL_TABLE = 0x0C29F2F0, FULL_STRIDE = 44, FULL_EXTRA = 0x84,
    KEY_RETIRE = 0x8000,
    SELF = 0x8C0C1FBA, POOL_ALLOC = 0x8C07B2BE, TEX_CELL_LOAD = 0x8C07B4D4,
    SPRITE_RECT_A = 0x8C07B35C, SPRITE_RECT_B = 0x8C07B398,
    RET_AFTER_SELF = 0x8C0C203E, RET_AFTER_ALLOC = 0x8C0C2046, RET_AFTER_CELL = 0x8C0C209A,
    RET_AFTER_RECT_A = 0x8C0C21AC, RET_AFTER_RECT_B = 0x8C0C21C4,
    TINT_TABLE = 0x0C10FEB4, SPRITE_CELLS = 0x0C2A620C,
    HEADER_PLAIN = 0x0605, HEADER_LIT = 0x1605, HEADER_BLEND = 0x0800,
    SR_T = 1u,
    SAVED_BYTES = 48, FRAME_BYTES = 20
};

static void set_t(vf3_matrix_state *s, int t)
{
    s->v[VF3_REG_SR] = (s->v[VF3_REG_SR] & ~SR_T) | (t ? SR_T : 0u);
}

int vf3_pool_alloc_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t layer = s->v[4], sp = s->v[15];
    const uint32_t pool = vf3_mem_u32(ram, layer + LAYER_POOL);
    const uint32_t cursor = vf3_mem_u16(ram, layer + LAYER_CURSOR);
    uint32_t entry = pool + cursor * ENTRY_BYTES;
    s->v[6] = 1;
    s->v[7] = POOL_ENTRIES;
    s->v[2] = cursor;
    s->v[3] = cursor * ENTRY_BYTES;
    if (vf3_mem_u16(ram, entry) == 0) {
        uint32_t next = cursor + 1;
        vf3_mem_set_u16(ram, layer + LAYER_CURSOR, (uint16_t)next);
        s->v[2] = next;
        s->v[3] = vf3_mem_u16(ram, layer + LAYER_CURSOR);
        if (s->v[3] >= POOL_ENTRIES) {
            s->v[2] = 0;
            vf3_mem_set_u16(ram, layer + LAYER_CURSOR, 0);
            set_t(s, 1);
        } else {
            set_t(s, 0);
        }
        s->v[0] = s->v[5] = entry;
        s->pc = s->v[VF3_REG_PR];
        return 1;
    }
    entry = pool;
    uint32_t index = 0;
    for (;;) {
        if (vf3_mem_u16(ram, entry) == 0) {
            s->v[1] = index;
            s->v[5] = s->v[0] = entry;
            set_t(s, 0);
            s->pc = s->v[VF3_REG_PR];
            return 1;
        }
        ++index;
        entry += ENTRY_BYTES;
        if (index >= POOL_ENTRIES) break;
    }
    const uint32_t full_a = FULL_TABLE + FULL_STRIDE;
    vf3_mem_set_u32(ram, sp - 4u, full_a);                  /* dead spill */
    s->v[1] = index;
    s->v[0] = 0;
    s->v[2] = s->v[3] = full_a;
    s->v[5] = FULL_TABLE + FULL_EXTRA;
    s->v[6] = FULL_TABLE;
    s->v[7] = FULL_TABLE + 2u * FULL_STRIDE;
    set_t(s, s->v[4] == s->v[5]);
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

static float fr(const vf3_matrix_state *s, int n) { return vf3_fr_get(s, n); }
static float itof(const vf3_matrix_state *s, uint32_t v) { return vf3_f_from_int(s, (int32_t)v); }

int vf3_glyph_cache_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = s->v[15], pr0 = s->v[VF3_REG_PR];
    const uint32_t frame = sp0 - SAVED_BYTES - FRAME_BYTES;
    uint32_t saved[7];                                      /* r14 r13 r12 r11 r10 r9 r8 */
    for (int i = 0; i < 7; ++i) {
        saved[i] = s->v[14 - i];
        vf3_mem_set_u32(ram, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    }
    uint32_t saved_fr[4];                                   /* fr15 fr14 fr13 fr12 */
    for (int i = 0; i < 4; ++i) {
        saved_fr[i] = VF3_FR(s, 15 - i);
        vf3_mem_set_u32(ram, sp0 - 32u - 4u * (uint32_t)i, saved_fr[i]);
    }
    vf3_mem_set_u32(ram, sp0 - 48u, pr0);

    const uint32_t cursor_word = s->v[4], layer = s->v[6], packed_cell = s->v[7];
    uint32_t key = s->v[5];
    s->v[12] = key;
    s->v[10] = layer;
    s->v[9] = cursor_word;
    vf3_mem_set_u32(ram, frame, packed_cell);
    s->v[11] = vf3_mem_u32(ram, sp0);                       /* packed texel offsets */
    s->v[13] = vf3_mem_u32(ram, sp0 + 4u);                  /* flag bits */
    s->v[8] = 63;
    s->v[15] = frame;
    const uint32_t pool = vf3_mem_u32(ram, layer + LAYER_POOL);
    uint32_t result = 0;

    if (key & KEY_RETIRE) {
        /* retire every entry drawn at this cell with this key */
        const uint32_t col = (cursor_word >> 1) & 63u, row = (cursor_word >> 7) & 63u;
        const uint32_t plain_key = key ^ KEY_RETIRE;
        for (uint32_t i = 0; i < POOL_ENTRIES; ++i) {
            const uint32_t e = pool + i * ENTRY_BYTES;
            if (vf3_mem_u16(ram, e + 6u) == col && vf3_mem_u16(ram, e + 8u) == row &&
                vf3_mem_u16(ram, e + 2u) == plain_key)
                vf3_mem_set_u16(ram, e, 0);
        }
        goto epilogue;
    }

    /* first retire a previous glyph at this cell, then take a fresh pool entry */
    vf3_mem_set_u32(ram, frame - 4u, s->v[13]);
    vf3_mem_set_u32(ram, frame - 8u, s->v[11]);
    s->v[15] = frame - 8u;
    s->v[4] = cursor_word;
    s->v[5] = key | KEY_RETIRE;
    s->v[6] = layer;
    s->v[7] = packed_cell;
    if (!vf3_guest_call(s, ram, SELF, RET_AFTER_SELF)) return 0;
    s->v[15] = frame;
    s->v[4] = layer;
    if (!vf3_guest_call(s, ram, POOL_ALLOC, RET_AFTER_ALLOC)) return 0;
    const uint32_t entry = s->v[0];
    s->v[14] = entry;
    if (entry == 0) goto epilogue;
    s->v[15] = frame;

    {
        uint32_t col8, row8;
        if (packed_cell != 0) {
            col8 = (uint32_t)(int32_t)(int16_t)packed_cell;
            row8 = (uint32_t)(int32_t)(int16_t)(packed_cell >> 16);
        } else {
            col8 = (cursor_word >> 1) & 63u;
            row8 = (cursor_word >> 7) & 63u;
        }
        vf3_mem_set_u16(ram, entry + 6u, (uint16_t)col8);
        vf3_mem_set_u16(ram, entry + 8u, (uint16_t)row8);
        vf3_mem_set_u16(ram, entry + 2u, (uint16_t)key);
        vf3_mem_set_u32(ram, frame + 16u, vf3_f32_bits(itof(s, col8 << 3)));
        vf3_mem_set_u32(ram, frame + 12u, vf3_f32_bits(itof(s, row8 << 3)));
    }

    s->v[4] = key;
    if (!vf3_guest_call(s, ram, TEX_CELL_LOAD, RET_AFTER_CELL)) return 0;
    const uint32_t cell = s->v[0];
    s->v[12] = cell;
    s->v[15] = frame;
    s->v[14] = entry;
    float cell_x = vf3_mem_f32(ram, cell + 0), cell_y = vf3_mem_f32(ram, cell + 4);
    const float cell_h = vf3_mem_f32(ram, cell + 12);
    float width = vf3_mem_f32(ram, cell + 8);
    float height = cell_h;
    const float cell_u = vf3_mem_f32(ram, cell + 16), cell_v = vf3_mem_f32(ram, cell + 20);
    vf3_mem_set_u32(ram, frame + 4u, vf3_f32_bits(width));
    vf3_mem_set_u32(ram, frame + 8u, vf3_f32_bits(cell_u));
    const uint32_t offsets = s->v[11];
    if (offsets != 0) {
        /* packed texel offsets: x1 (bits 24..31), y1 (16..23), w (8..15), h (0..7), all in 1/8 steps */
        cell_x = vf3_f_add(s, itof(s, ((offsets >> 24) & 255u) << 3), cell_x);
        cell_y = vf3_f_add(s, itof(s, ((offsets >> 16) & 255u) << 3), cell_y);
        width = itof(s, ((offsets >> 8) & 255u) << 3);
        height = itof(s, (offsets & 255u) << 3);
        vf3_mem_set_u32(ram, frame + 4u, vf3_f32_bits(width));
    }
    {
        const uint32_t w_texels = ((uint32_t)vf3_f_trunc(width) & 0xFFFFu) >> 3;
        const uint32_t h_texels = ((uint32_t)vf3_f_trunc(height) & 0xFFFFu) >> 3;
        vf3_mem_set_u16(ram, entry + 10u, (uint16_t)w_texels);
        vf3_mem_set_u16(ram, entry + 12u, (uint16_t)h_texels);
    }
    const float tex_h = vf3_mem_f32(ram, frame + 8u);
    float quad_h = vf3_f_mul(s, vf3_mem_f32(ram, frame + 4u), tex_h);
    float bottom = height;
    const uint32_t flags = s->v[13];
    if (!(flags & 64u)) bottom = vf3_f_add(s, height, -1.0f);
    const float tint = vf3_mem_f32(ram, TINT_TABLE + 4u * vf3_mem_u16(ram, layer + LAYER_TINT));
    const float bottom_v = vf3_f_mul(s, bottom, cell_v);

    const uint32_t sprite = entry + 16u;
    s->v[4] = sprite;
    vf3_fr_set(s, 4, vf3_mem_f32(ram, frame + 16u));
    vf3_fr_set(s, 5, vf3_mem_f32(ram, frame + 12u));
    vf3_fr_set(s, 6, quad_h);
    vf3_fr_set(s, 7, bottom_v);
    vf3_fr_set(s, 8, tint);
    vf3_fr_set(s, 12, cell_v);
    vf3_fr_set(s, 13, cell_x);
    vf3_fr_set(s, 14, cell_y);
    vf3_fr_set(s, 15, height);
    s->v[0] = 16;
    if (!vf3_guest_call(s, ram, SPRITE_RECT_A, RET_AFTER_RECT_A)) return 0;
    s->v[15] = frame;
    s->v[4] = sprite;
    vf3_fr_set(s, 4, cell_x);
    vf3_fr_set(s, 5, cell_y);
    vf3_fr_set(s, 6, vf3_mem_f32(ram, frame + 4u));
    vf3_fr_set(s, 7, height);
    vf3_fr_set(s, 8, vf3_mem_f32(ram, frame + 8u));
    vf3_fr_set(s, 9, cell_v);
    if (!vf3_guest_call(s, ram, SPRITE_RECT_B, RET_AFTER_RECT_B)) return 0;
    s->v[15] = frame;

    const uint32_t sprite_cell = vf3_mem_u16(ram, SPRITE_CELLS + 2u * vf3_mem_u32(ram, cell + 32u));
    vf3_mem_set_u16(ram, entry + 4u, (uint16_t)sprite_cell);
    vf3_mem_set_u32(ram, entry + 16u, sprite_cell);
    vf3_mem_set_u32(ram, entry + 64u, vf3_f32_bits(1.0f));
    vf3_mem_set_u16(ram, entry, 1);
    uint32_t header = HEADER_PLAIN;
    if (flags & 1u) { vf3_mem_set_u16(ram, entry, vf3_mem_u16(ram, entry) | 2u); header = HEADER_LIT; }
    if (flags & 2u) vf3_mem_set_u16(ram, entry, vf3_mem_u16(ram, entry) | 4u);
    if (flags & 4u) vf3_mem_set_u16(ram, entry, vf3_mem_u16(ram, entry) | 8u);
    if (flags & 8u) header |= HEADER_BLEND;
    if (flags & 16u) vf3_mem_set_u16(ram, entry, vf3_mem_u16(ram, entry) | 16u);
    if (flags & 32u) vf3_mem_set_u16(ram, entry, vf3_mem_u16(ram, entry) | 32u);
    vf3_mem_set_u32(ram, entry + 60u, header);
    result = sprite;
    (void)fr;

epilogue:
    s->v[0] = result;
    s->v[15] = sp0;
    for (int i = 0; i < 7; ++i) s->v[14 - i] = saved[i];
    for (int i = 0; i < 4; ++i) VF3_FR(s, 15 - i) = saved_fr[i];
    s->v[VF3_REG_PR] = pr0;
    s->pc = pr0;
    return 1;
}
