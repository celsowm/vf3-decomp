/* Partial 0x8C0708B0 model for the 56 captured calls that take the direct
 * 0x8C070920 transfer. Alternate paths continue into the enclosing vector
 * routine and are deliberately excluded from the baseline coverage ledger. */
#include "fight/fvecnorm070x.h"
#include "fight/fpu_tz.h"

#include <math.h>
#include <string.h>

static uint32_t n_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            uint32_t v;
            memcpy(&v, w->data + canon - w->base, 4);
            return v;
        }
    }
    m->oob++;
    return 0;
}

static void n_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            memcpy(w->data + canon - w->base, &v, 4);
            return;
        }
    }
    m->oob++;
}

static float n_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    return fpu_bits_to_f32(n_rd32(ram, addr));
}

static float n_fipr_v0(float x, float y, float z, float w)
{
    long double d = (long double)x * x + (long double)y * y +
                    (long double)z * z + (long double)w * w;
    return f32_tz(d);
}

static float n_sqrt(float x, uint32_t fpscr)
{
    return fpu_dn_fix(f32_tz(sqrtl((long double)x)), fpscr);
}

void vf3_fvecnorm070x_8c0708b0(const uint32_t in[37], uint32_t out[37],
                               const vf3_ram_map *ram)
{
    uint32_t r4 = in[15] + 68;
    uint32_t r5 = in[11];
    uint32_t fpscr = in[18];
    float x, y, z, sx, sy, sz, cx, cy, cz, norm2, length, frame_length;

    memcpy(out, in, 37 * sizeof(uint32_t));

    /* 0x8C0708B0: caller FR0 spill. */
    n_wr32(ram, in[4] - 4, in[21]);

    /* 0x8C0708B4..8C: length of the frame vector in FR0. */
    x = n_rdflt(ram, r4); r4 += 4;
    y = n_rdflt(ram, r4); r4 += 4;
    z = n_rdflt(ram, r4);
    norm2 = n_fipr_v0(x, y, z, 0.0f);
    frame_length = n_sqrt(norm2, fpscr);
    /* The 0x8C0708D0 delay slot retires on the taken BT/S path too. */
    n_wr32(ram, in[15] + 0x18, fpu_f32_to_bits(frame_length));

    /* Captured 0x8B0 entries take the positive-length branch to 0x8D8. */
    out[0] = 24;                         /* mov #0x18,r0 */
    r4 = in[15] + 68;
    x = n_rdflt(ram, r4); r4 += 4;
    y = n_rdflt(ram, r4); r4 += 4;
    z = n_rdflt(ram, r4);
    sx = n_rdflt(ram, r5); r5 += 4;
    sy = n_rdflt(ram, r5); r5 += 4;
    sz = n_rdflt(ram, r5);

    /* 0x8C0708F4..0E: ordered FMUL/FMAC cross product. */
    cx = fmul_tz(y, sx);
    cy = fmul_tz(x, sz);
    cz = fmul_tz(z, sy);
    cx = -cx;
    cx = fmac_tz(x, sy, cx);
    cy = -cy;
    cy = fmac_tz(z, sx, cy);
    cz = -cz;
    cz = fmac_tz(y, sz, cz);

    /* 0x8C070910..16: magnitude of the cross product. */
    norm2 = n_fipr_v0(0.0f, cx, cy, cz);
    length = n_sqrt(norm2, fpscr);

    /* 0x8C070918..20 copies the length, compares FR15 against FR12, loads
     * the observed tail target, then stops before the indirect jump. */
    out[3] = 0x0C070A64u;
    out[4] = r4;
    out[5] = r5;
    out[17] &= ~1u;                    /* comparison is false in captures */
    out[21] = fpu_f32_to_bits(length);
    out[22] = fpu_f32_to_bits(cz);
    out[23] = fpu_f32_to_bits(cy);
    out[24] = fpu_f32_to_bits(norm2);
    out[26] = fpu_f32_to_bits(y);
    out[27] = fpu_f32_to_bits(z);
    out[29] = fpu_f32_to_bits(sx);
    out[30] = fpu_f32_to_bits(sy);
    out[31] = fpu_f32_to_bits(sz);
    out[33] = fpu_f32_to_bits(length);
}
