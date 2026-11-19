/* glyph_cache.c - SH-4 0x8C0C1FBA: the HUD text layer's sprite pool, natively.
 *
 * A plain-C transcription of the readable port src/fight/glyph_cache.c
 * (`vf3_glyph_cache_entry`), with its five guest callees inlined as static
 * helpers: the retirement self-call (0x8C0C1FBA in retire-key mode, here a
 * direct loop), pool_alloc (0x8C07B2BE, `vf3_pool_alloc_entry`),
 * tex_cell_load (0x8C07B4D4), sprite_rect_a (0x8C07B35C) and sprite_rect_b
 * (0x8C07B398) (the last three in src/fight/sprite_uv.c).  It operates on
 * `vf3_native_aim`: the flat RAM (every guest address resolves through
 * `ram_base`), the FR bank and the register file.
 *
 * The routine's outputs are preponderantly integers (the entry's u16 fields)
 * and float sprite geometry derived from round-toward-zero arithmetic, so the
 * float helpers run the same toward-zero + FTZ wrappers hitbox_overlap uses
 * and the stored floats match the guest bit for bit.  On exit the saved block
 * (r8..r14, fr12..fr15, pr) is restored and r0 = the sprite object (the pool
 * entry + 16) or 0.  SR's T bit is left as the last SR-modifying inlined
 * callee produced: tex_cell_load, so the success path leaves T = !(the key's
 * cell id has the cell-flag bit); the retire path never touches SR.
 *
 * See docs/re/native_glyph_cache.md. */
#include "glyph_cache.h"

#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

static inline void w8(vf3_native_aim *a, uint32_t addr, uint8_t v)
{ ((uint8_t *)a->ram)[addr - a->ram_base] = v; }

enum {
    POOL_ENTRIES = 120, ENTRY_BYTES = 68, LAYER_POOL = 12, LAYER_CURSOR = 42,
    LAYER_TINT = 38, FULL_TABLE = 0x0C29F2F0, FULL_STRIDE = 44, FULL_EXTRA = 0x84,
    KEY_RETIRE = 0x8000,
    TINT_TABLE = 0x0C10FEB4, SPRITE_CELLS = 0x0C2A620C,
    HEADER_PLAIN = 0x0605, HEADER_LIT = 0x1605, HEADER_BLEND = 0x0800,
    CELL_RECORDS = 0x0C11ABB0u, CELL_PAIRS = 0x0C11AA60u,
    CELL_FLAG = 0x4000u, CELL_INDEX_MASK = 0x3FFFu,
    SCRATCH = 0x0C1B9620u, SCRATCH_RECIP_W = 0x0C1B9630u,
    SCRATCH_RECIP_H = 0x0C1B9634u, SCRATCH_U = 0x0C1B9638u,
    SCRATCH_V = 0x0C1B963Cu, SCRATCH_ID = 0x0C1B9640u,
    SCALE_X = 0x0C10B7FCu, SCALE_Y = 0x0C10B800u,
    OFFSET_X = 0x0C10B804u, OFFSET_Y = 0x0C10B808u,
    SAVED_BYTES = 48, FRAME_BYTES = 20
};

/* ---- ground-address decode (the guest's vf3_matrix_read masking) ---- */
static uint32_t mir(uint32_t addr)
{
    addr &= 0x1FFFFFFFu;
    if (addr >= 0x0c000000u && addr < 0x10000000u)
        addr = 0x0c000000u | (addr & 0x00ffffffu);
    return addr;
}
static uint32_t rd32(vf3_native_aim *a, uint32_t addr)
{ return vf3_aim_u32(a, mir(addr)); }
static uint16_t rd16(vf3_native_aim *a, uint32_t addr)
{ return (uint16_t)(rd32(a, addr) & 0xFFFFu); }
static uint8_t rd8(vf3_native_aim *a, uint32_t addr)
{ return (uint8_t)(rd32(a, addr) & 0xFFu); }
static void wr16(vf3_native_aim *a, uint32_t addr, uint16_t v)
{ vf3_aim_set_u16(a, mir(addr), v); }
static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t v)
{ vf3_aim_set_u32(a, mir(addr), v); }
static float rd32f(vf3_native_aim *a, uint32_t addr)
{ return vf3_aim_fbits(rd32(a, addr)); }
static void wr32f(vf3_native_aim *a, uint32_t addr, float f)
{ wr32(a, addr, vf3_aim_ubits(f)); }

/* ---- round-toward-zero FPU wrappers (as hitbox_overlap.c) ---- */
static inline float flz(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float ft0(vf3_native_aim *a, float x, float y, char op)
{
    const int saved = fegetround();
    fesetround(FE_TOWARDZERO);
    volatile float z = 0;
    switch (op) {
        case '+': z = x + y; break;
        case '-': z = x - y; break;
        case '*': z = x * y; break;
        default:  z = x / y; break;
    }
    fesetround(saved);
    return flz(a, z);
}
static inline float fadd(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '+'); }
static inline float fmul(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '*'); }
static inline float fdivv(vf3_native_aim *a, float x, float y) { return ft0(a, x, y, '/'); }
static inline float itof(int32_t v) { return (float)v; }
static inline int32_t ftrunc(float f) { return (int32_t)f; }

/* 0x8C07B2BE pool_alloc(r4 = layer, sp = frame) -> r0 = a free 68-byte entry, or 0. */
static inline uint32_t pool_alloc(vf3_native_aim *a, uint32_t layer, uint32_t sp)
{
    const uint32_t pool = rd32(a, layer + LAYER_POOL);
    const uint32_t cursor = rd16(a, layer + LAYER_CURSOR);
    uint32_t entry = pool + cursor * ENTRY_BYTES;
    int T = 0;
    R(6) = 1; R(7) = POOL_ENTRIES; R(2) = cursor; R(3) = cursor * ENTRY_BYTES;
    if (rd16(a, entry) == 0) {
        uint32_t next = cursor + 1;
        wr16(a, layer + LAYER_CURSOR, (uint16_t)next);
        R(2) = next;
        R(3) = rd16(a, layer + LAYER_CURSOR);
        if (R(3) >= POOL_ENTRIES) {
            R(2) = 0;
            wr16(a, layer + LAYER_CURSOR, 0);
            T = 1;
        } else {
            T = 0;
        }
        R(0) = entry; R(5) = entry;
        a->sr = (a->sr & ~1u) | (T ? 1u : 0u);
        return entry;
    }
    entry = pool;
    uint32_t index = 0;
    for (;;) {
        if (rd16(a, entry) == 0) {
            R(1) = index;
            R(5) = entry; R(0) = entry;
            a->sr = (a->sr & ~1u) | 0u;
            return entry;
        }
        ++index;
        entry += ENTRY_BYTES;
        if (index >= POOL_ENTRIES) break;
    }
    /* full: r0 = 0, T = (layer == FULL_TABLE + FULL_EXTRA) */
    {
        const uint32_t full_a = FULL_TABLE + FULL_STRIDE;
        wr32(a, sp - 4u, full_a);          /* dead spill */
        R(1) = index;
        R(0) = 0;
        R(2) = R(3) = full_a;
        R(5) = FULL_TABLE + FULL_EXTRA;
        R(6) = FULL_TABLE;
        R(7) = FULL_TABLE + 2u * FULL_STRIDE;
        T = (layer == FULL_TABLE + FULL_EXTRA);
        a->sr = (a->sr & ~1u) | (T ? 1u : 0u);
        return 0;
    }
}

/* 0x8C07B4D4 tex_cell_load(r4 = cell id, sp = frame) -> r0 = SCRATCH.
 * Its dead spill writes the caller's live r14/r13 (the guest's mov.l r14/r13,
 * @-r15 prologue) at frame-4/frame-8. */
static inline uint32_t tex_cell_load(vf3_native_aim *a, uint32_t id_in, uint32_t sp,
                                     uint32_t r14, uint32_t r13)
{
    wr32(a, sp - 4u, r14);                 /* dead spill */
    wr32(a, sp - 8u, r13);                 /* dead spill */
    const uint32_t id = id_in & 0xFFFFu;
    uint32_t first, x, y, w, h, T = 0;
    if (id & CELL_FLAG) {
        const uint32_t rec = CELL_RECORDS + 6u * (id & CELL_INDEX_MASK);
        first = (uint32_t)(int32_t)(int16_t)rd16(a, rec);
        x = rd8(a, rec + 2u); y = rd8(a, rec + 3u);
        w = rd8(a, rec + 4u); h = rd8(a, rec + 5u);
        T = 0;
    } else {
        const uint32_t pair = CELL_PAIRS + 4u * id;
        first = id_in;
        x = y = 0;
        w = (uint32_t)(int32_t)(int16_t)rd16(a, pair);
        h = (uint32_t)(int32_t)(int16_t)rd16(a, pair + 2u);
        T = 1;
    }
    R(6) = (x & 0xFFFFu) << 3;
    R(7) = (y & 0xFFFFu) << 3;
    w = (w & 0xFFFFu) << 3;
    h = (h & 0xFFFFu) << 3;

    wr32(a, SCRATCH_ID, first & 0xFFFFu);
    wr32f(a, SCRATCH + 0, itof((int32_t)R(6)));
    wr32f(a, SCRATCH + 4, itof((int32_t)R(7)));
    wr32f(a, SCRATCH + 8, itof((int32_t)w));
    wr32f(a, SCRATCH + 12, itof((int32_t)h));

    const uint32_t pair = CELL_PAIRS + 4u * (first & 0xFFFFu);
    const uint32_t pw = (((uint32_t)(int32_t)(int16_t)rd16(a, pair)) & 0xFFFFu) << 3;
    const uint32_t ph = (((uint32_t)(int32_t)(int16_t)rd16(a, pair + 2u)) & 0xFFFFu) << 3;
    const float recip_w = fdivv(a, 1.0f, itof((int32_t)pw));
    const float recip_h = fdivv(a, 1.0f, itof((int32_t)ph));
    wr32f(a, SCRATCH_RECIP_W, recip_w);
    wr32f(a, SCRATCH_RECIP_H, recip_h);
    const float u = fmul(a, rd32f(a, SCRATCH + 8), recip_w);
    const float v = fmul(a, rd32f(a, SCRATCH + 12), recip_h);
    wr32f(a, SCRATCH_U, u);
    wr32f(a, SCRATCH_V, v);

    R(1) = SCRATCH_RECIP_W;
    R(2) = SCRATCH_RECIP_H;
    R(3) = SCRATCH_V;
    R(0) = SCRATCH;
    R(4) = pw;
    R(5) = ph;
    a->sr = (a->sr & ~1u) | (T ? 1u : 0u);
    return SCRATCH;
}

/* the retirement self-call: clear every entry drawn at this cell with the key.
 * (0x8C0C1FBA in retire-key mode; inlined as a direct loop.) */
static inline void retire(vf3_native_aim *a, uint32_t layer, uint32_t cursor_word,
                          uint32_t key, uint32_t pool)
{
    const uint32_t col = (cursor_word >> 1) & 63u, row = (cursor_word >> 7) & 63u;
    const uint32_t plain_key = key ^ KEY_RETIRE;
    for (uint32_t i = 0; i < POOL_ENTRIES; ++i) {
        const uint32_t e = pool + i * ENTRY_BYTES;
        if (rd16(a, e + 6u) == col && rd16(a, e + 8u) == row &&
            rd16(a, e + 2u) == plain_key)
            wr16(a, e, 0);
    }
}

/* sprite_rect_a (0x8C07B35C): the vertex block's scaled position, z and UV
 * extent.  FR4/FR5 = x/y, FR6/FR7 = w/h, FR8 = z. */
static inline void sprite_rect_a(vf3_native_aim *a, uint32_t block)
{
    const float sx = rd32f(a, SCALE_X), sy = rd32f(a, SCALE_Y);
    const float ox = rd32f(a, OFFSET_X), oy = rd32f(a, OFFSET_Y);
    wr32(a, a->r[15] - 4u, vf3_aim_ubits(sx));          /* dead spill */
    const float x = fadd(a, fmul(a, F(4), sx), ox);
    const float y = fadd(a, fmul(a, F(5), sy), oy);
    wr32f(a, block + 4u, x);
    wr32f(a, block + 8u, y);
    wr32(a, block + 12u, vf3_aim_ubits(F(8)));
    const float uw = fmul(a, sx, F(6));
    const float vh = fmul(a, sy, F(7));
    wr32f(a, block + 16u, uw);
    wr32f(a, block + 20u, vh);
    R(0) = 20;
    R(2) = OFFSET_Y;
    R(3) = OFFSET_X;
    R(5) = SCALE_X;
    R(6) = SCALE_Y;
}

/* sprite_rect_b (0x8C07B398): the far corner's four UVs. */
static inline void sprite_rect_b(vf3_native_aim *a, uint32_t block)
{
    static const uint32_t BIAS_A = 0x3A8461F9u, BIAS_B = 0x33D6BF94u,
                          BIAS_C = 0x80000000u, BIAS_D = 0xBED70A3Du;
    const float x = F(4), y = F(5);
    const float su = F(8), sv = F(9);
    const float x1 = fadd(a, x, F(6));
    const float u0 = fmul(a, fadd(a, x, vf3_aim_fbits(BIAS_A)), su);
    wr32f(a, block + 24u, u0);
    const float y1 = fadd(a, y, F(7));
    const float v0 = fmul(a, fadd(a, y, vf3_aim_fbits(BIAS_B)), sv);
    wr32f(a, block + 28u, v0);
    const float u1 = fmul(a, fadd(a, x1, vf3_aim_fbits(BIAS_C)), su);
    wr32f(a, block + 32u, u1);
    const float v1 = fmul(a, fadd(a, y1, vf3_aim_fbits(BIAS_D)), sv);
    wr32f(a, block + 36u, v1);
    R(0) = 36;
}

void vf3_native_glyph_cache(vf3_native_aim *a, uint32_t sp0)
{
    /* entry values the epilogue restores */
    const uint32_t e8 = R(8), e9 = R(9), e10 = R(10), e11 = R(11);
    const uint32_t e12 = R(12), e13 = R(13), e14 = R(14);
    const float ef15 = F(15), ef14 = F(14), ef13 = F(13), ef12 = F(12);
    const uint32_t pr0 = a->pr;
    const uint32_t frame = sp0 - SAVED_BYTES - FRAME_BYTES;

    /* prologue: push r14..r8, fr15..fr12, pr */
    {
        const uint32_t saved[7] = { e14, e13, e12, e11, e10, e9, e8 };
        for (int i = 0; i < 7; ++i)
            vf3_aim_set_u32(a, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
        const float sf[4] = { ef15, ef14, ef13, ef12 };
        for (int i = 0; i < 4; ++i)
            vf3_aim_set_u32(a, sp0 - 32u - 4u * (uint32_t)i, vf3_aim_ubits(sf[i]));
        vf3_aim_set_u32(a, sp0 - 48u, pr0);
    }
    R(15) = frame;

    const uint32_t cursor_word = R(4), layer = R(6), packed_cell = R(7);
    uint32_t key = R(5);
    R(12) = key; R(10) = layer; R(9) = cursor_word;
    wr32(a, frame, packed_cell);
    R(11) = rd32(a, sp0);            /* packed texel offsets */
    R(13) = rd32(a, sp0 + 4u);       /* flag bits */
    R(8) = 63;
    R(15) = frame;
    const uint32_t pool = rd32(a, layer + LAYER_POOL);
    uint32_t result = 0;
    const uint32_t flags = R(13);

    if (key & KEY_RETIRE) {
        retire(a, layer, cursor_word, key, pool);
        goto epilogue;           /* retire path leaves SR unchanged */
    }

    /* first retire a previous glyph at this cell, then take a fresh entry */
    wr32(a, frame - 4u, flags);
    wr32(a, frame - 8u, R(11));
    retire(a, layer, cursor_word, key | KEY_RETIRE, pool);
    R(4) = layer;
    uint32_t entry = pool_alloc(a, layer, frame);
    R(14) = entry;
    if (entry == 0) goto epilogue;
    R(15) = frame;

    {
        uint32_t col8, row8;
        if (packed_cell != 0) {
            col8 = (uint32_t)(int32_t)(int16_t)packed_cell;
            row8 = (uint32_t)(int32_t)(int16_t)(packed_cell >> 16);
        } else {
            col8 = (cursor_word >> 1) & 63u;
            row8 = (cursor_word >> 7) & 63u;
        }
        wr16(a, entry + 6u, (uint16_t)col8);
        wr16(a, entry + 8u, (uint16_t)row8);
        wr16(a, entry + 2u, (uint16_t)key);
        wr32f(a, frame + 16u, itof((int32_t)(col8 << 3)));
        wr32f(a, frame + 12u, itof((int32_t)(row8 << 3)));
    }

    R(4) = key;
    uint32_t cell = tex_cell_load(a, key, frame, entry, flags);
    R(12) = cell;
    R(15) = frame;
    R(14) = entry;
    float cell_x = rd32f(a, cell + 0), cell_y = rd32f(a, cell + 4);
    const float cell_h = rd32f(a, cell + 12);
    float width = rd32f(a, cell + 8);
    float height = cell_h;
    const float cell_u = rd32f(a, cell + 16), cell_v = rd32f(a, cell + 20);
    wr32f(a, frame + 4u, width);
    wr32f(a, frame + 8u, cell_u);
    const uint32_t offsets = R(11);
    if (offsets != 0) {
        cell_x = fadd(a, itof((int32_t)(((offsets >> 24) & 255u) << 3)), cell_x);
        cell_y = fadd(a, itof((int32_t)(((offsets >> 16) & 255u) << 3)), cell_y);
        width = itof((int32_t)(((offsets >> 8) & 255u) << 3));
        height = itof((int32_t)((offsets & 255u) << 3));
        wr32f(a, frame + 4u, width);
    }
    {
        const uint32_t w_texels = ((uint32_t)ftrunc(width) & 0xFFFFu) >> 3;
        const uint32_t h_texels = ((uint32_t)ftrunc(height) & 0xFFFFu) >> 3;
        wr16(a, entry + 10u, (uint16_t)w_texels);
        wr16(a, entry + 12u, (uint16_t)h_texels);
    }
    const float tex_h = rd32f(a, frame + 8u);
    float quad_h = fmul(a, rd32f(a, frame + 4u), tex_h);
    float bottom = height;
    if (!(flags & 64u)) bottom = fadd(a, height, -1.0f);
    const float tint = rd32f(a, TINT_TABLE + 4u * rd16(a, layer + LAYER_TINT));
    const float bottom_v = fmul(a, bottom, cell_v);

    const uint32_t sprite = entry + 16u;
    R(4) = sprite;
    F(4) = rd32f(a, frame + 16u);
    F(5) = rd32f(a, frame + 12u);
    F(6) = quad_h;
    F(7) = bottom_v;
    F(8) = tint;
    F(12) = cell_v; F(13) = cell_x; F(14) = cell_y; F(15) = height;
    R(0) = 16;
    sprite_rect_a(a, sprite);

    R(15) = frame;
    R(4) = sprite;
    F(4) = cell_x; F(5) = cell_y;
    F(6) = rd32f(a, frame + 4u);
    F(7) = height;
    F(8) = rd32f(a, frame + 8u);
    F(9) = cell_v;
    sprite_rect_b(a, sprite);

    const uint32_t sprite_cell = rd16(a, SPRITE_CELLS + 2u * rd32(a, cell + 32u));
    wr16(a, entry + 4u, (uint16_t)sprite_cell);
    wr32(a, entry + 16u, sprite_cell);
    wr32f(a, entry + 64u, 1.0f);
    wr16(a, entry, 1);
    uint32_t head = HEADER_PLAIN;
    if (flags & 1u) { wr16(a, entry, (uint16_t)(rd16(a, entry) | 2u)); head = HEADER_LIT; }
    if (flags & 2u) wr16(a, entry, (uint16_t)(rd16(a, entry) | 4u));
    if (flags & 4u) wr16(a, entry, (uint16_t)(rd16(a, entry) | 8u));
    if (flags & 8u) head |= HEADER_BLEND;
    if (flags & 16u) wr16(a, entry, (uint16_t)(rd16(a, entry) | 16u));
    if (flags & 32u) wr16(a, entry, (uint16_t)(rd16(a, entry) | 32u));
    wr32(a, entry + 60u, head);
    result = sprite;

epilogue:
    R(0) = result;
    R(15) = sp0;
    R(8) = e8; R(9) = e9; R(10) = e10; R(11) = e11;
    R(12) = e12; R(13) = e13; R(14) = e14;
    F(15) = ef15; F(14) = ef14; F(13) = ef13; F(12) = ef12;
    a->pr = pr0;
}
