/* Readable model of the 228-byte SH-4 worker at 0x8C06951A.
 *
 * The verified path rescales selector 2/7 coordinates, clamps the pair to
 * [-12,12], forms a 128x128 map index with FMA + truncation, and loads one
 * sample. The saved-state oracle currently exercises selector 12 with a
 * nonzero map context. */
#include "fight/maplookup.h"

#include <string.h>

#include "fight/fpu_tz.h"

static uint32_t map_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            uint32_t v;
            memcpy(&v, w->data + (canon - w->base), sizeof(v));
            return v;
        }
    }
    m->oob++;
    return 0;
}

static void map_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            memcpy(w->data + (canon - w->base), &v, sizeof(v));
            return;
        }
    }
    m->oob++;
}

static float map_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    return fpu_bits_to_f32(map_rd32(ram, addr));
}

static void map_wrflt(const vf3_ram_map *ram, uint32_t addr, float v)
{
    map_wr32(ram, addr, fpu_f32_to_bits(v));
}

int vf3_maplookup_8c06951a(const uint32_t in[37], uint32_t out[37],
                           const vf3_ram_map *ram, int *gated)
{
    const uint32_t entry_sp = in[15];
    const uint32_t frame = entry_sp - 40u;
    const uint32_t selector = 15u & (map_rd32(ram, 0x0C29B880u) & 0xFFu);
    const uint32_t ctx = map_rd32(ram, 0x0C1B9610u);
    float x = fpu_bits_to_f32(in[25]);
    float y = fpu_bits_to_f32(in[26]);
    float sample, tx, ty;
    int ix, iy;
    uint32_t iy_shift, index;

    memcpy(out, in, 37 * sizeof(uint32_t));
    *gated = 0;

    /* 8C069522-524: push PR, reserve 36 bytes, spill input coordinates. */
    map_wr32(ram, entry_sp - 4u, in[16]);
    map_wrflt(ram, frame + 4u, x);
    map_wrflt(ram, frame, y);

    if (selector == 2u || selector == 7u) {
        const float scale = fpu_bits_to_f32(0x3F44EC4Fu);
        x = fpu_dn_fix(fmul_tz(x, scale), in[18]);
        y = fpu_dn_fix(fmul_tz(y, scale), in[18]);
        map_wrflt(ram, frame + 4u, x);
        map_wrflt(ram, frame, y);
    }

    if (ctx == 0) {
        *gated = 1; /* 0x8C068DE4 fallback closure is outside this capture. */
        return 0;
    }
    if (selector == 11u) {
        *gated = 2; /* runtime target [0x8C069604] = 0x0C087ACE */
        return 0;
    }

    /* Each fcmp/store pair clamps one coordinate at each bound. */
    if (!(x > -12.0f)) {
        x = -12.0f;
        map_wrflt(ram, frame + 4u, x);
    }
    if (!(y > -12.0f)) {
        y = -12.0f;
        map_wrflt(ram, frame, y);
    }
    if (!(12.0f > x)) {
        x = 12.0f;
        map_wrflt(ram, frame + 4u, x);
    }
    if (!(12.0f > y)) {
        y = 12.0f;
        map_wrflt(ram, frame, y);
    }

    tx = fpu_dn_fix(fmac_tz(5.0f, x, 64.0f), in[18]);
    ty = fpu_dn_fix(fmac_tz(5.0f, y, 64.0f), in[18]);
    map_wrflt(ram, frame + 12u, tx);
    ix = (int)tx; /* SH-4 FTRC: round toward zero. */
    iy = (int)ty;
    iy_shift = (uint32_t)iy << 7;
    index = (uint32_t)ix + iy_shift;
    sample = map_rdflt(ram, ctx + index * 4u);
    map_wrflt(ram, frame + 8u, sample);

    /* Integer and FPU clobbers visible at RTS, mapped from the instruction
     * sequence 0x8C0695A0-5F4. */
    out[0] = 8u;
    out[2] = 0x0C1B9610u;
    out[3] = 7u;
    out[4] = selector;
    out[5] = ctx;
    out[6] = index;
    out[7] = iy_shift;
    out[17] &= ~1u; /* cmp/eq #11,r0 leaves T clear for selector 12. */
    out[21] = fpu_f32_to_bits(sample);
    out[23] = fpu_f32_to_bits(y);
    out[24] = fpu_f32_to_bits(sample);
    out[25] = fpu_f32_to_bits(ty);
    out[26] = fpu_f32_to_bits(5.0f);
    out[15] = entry_sp;
    out[16] = in[16];
    return 1;
}
