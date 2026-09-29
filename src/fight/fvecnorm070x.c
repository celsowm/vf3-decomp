/* Partial 0x8C0708B0 model through the captured indirect transfer sites.
 * The direct route is verified; the alternate normalized route retains one
 * single-precision boundary mismatch and is not eligible for coverage credit. */
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

static float n_fipr(float x, float y, float z, float w,
                    float a, float b, float c, float d)
{
    long double dot = (long double)x * a + (long double)y * b +
                      (long double)z * c + (long double)w * d;
    return f32_tz(dot);
}

static float n_fipr_native(float x, float y, float z, float w)
{
    double d = (double)x * x;
    d += (double)y * y;
    d += (double)z * z;
    d += (double)w * w;
    return (float)d;
}

static float n_sqrt(float x, uint32_t fpscr)
{
    return fpu_dn_fix(f32_tz(sqrtl((long double)x)), fpscr);
}

void vf3_fvecnorm070x_8c0708b0(const uint32_t in[37], uint32_t out[37],
                               const vf3_ram_map *ram)
{
    uint32_t sp = in[15];
    uint32_t r4, r5;
    uint32_t fpscr = in[18];
    float x, y, z, sx, sy, sz, cx, cy, cz, norm2, length, frame_length;
    float dot, stored_length;

    memcpy(out, in, 37 * sizeof(uint32_t));

    /* 0x8C0708B0: caller FR0 spill. */
    n_wr32(ram, in[4] - 4, in[21]);

    /* 0x8C0708B4..8C: length of the frame vector in FR0. */
    r4 = sp + 68;
    x = n_rdflt(ram, r4); r4 += 4;
    y = n_rdflt(ram, r4); r4 += 4;
    z = n_rdflt(ram, r4);
    norm2 = n_fipr_v0(x, y, z, 0.0f);
    frame_length = n_sqrt(norm2, fpscr);
    /* The 0x8C0708D0 delay slot retires on the taken BT/S path too. */
    n_wr32(ram, in[15] + 0x18, fpu_f32_to_bits(frame_length));

    /* The positive-length branch at 0x8CCE enters the vector comparison. */
    out[0] = 24;                         /* mov #0x18,r0 */
    r4 = sp + 68;
    r5 = in[11];
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
    /* The direct transfer is selected when input FR15 <= cross length. */
    if (!(fpu_bits_to_f32(in[36]) > length)) {
        out[3] = 0x0C070A64u;
        out[4] = r4;
        out[5] = r5;
        out[17] &= ~1u;
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
        return;
    }

    /* 0x8C070924..4C computes frame dot source into FR7. */
    x = n_rdflt(ram, sp + 68);
    y = n_rdflt(ram, sp + 72);
    z = n_rdflt(ram, sp + 76);
    sx = n_rdflt(ram, in[11]);
    sy = n_rdflt(ram, in[11] + 4);
    sz = n_rdflt(ram, in[11] + 8);
    dot = n_fipr(x, y, z, 0.0f, sx, sy, sz, 0.0f);
    out[4] = sp + 80;
    out[5] = in[11] + 12;
    out[21] = fpu_f32_to_bits(dot);     /* fr0 <- fr7 */
    out[22] = fpu_f32_to_bits(y);
    out[23] = fpu_f32_to_bits(z);
    out[24] = 0;                        /* fr3 = 0 */
    out[25] = fpu_f32_to_bits(dot);     /* fr4 <- fr0 */
    out[26] = fpu_f32_to_bits(sy);
    out[27] = fpu_f32_to_bits(sz);
    out[28] = fpu_f32_to_bits(dot);     /* fr7 retains the dot */
    out[29] = fpu_f32_to_bits(sx);
    out[30] = fpu_f32_to_bits(sy);
    out[31] = fpu_f32_to_bits(sz);
    out[33] = fpu_f32_to_bits(length);

    if (dot >= 0.0f) {
        /* 0x8C070952: dot is nonnegative, tail-jump to 0x0C07099E. */
        out[3] = 0x0C07099Eu;
        out[17] &= ~1u;
        return;
    }

    stored_length = n_rdflt(ram, sp + 24);
    if (!(fpu_bits_to_f32(in[36]) > stored_length)) {
        /* 0x8C070960: preserve the unnormalized vector and transfer. */
        out[3] = 0x0C070A64u;
        out[0] = 24;
        out[24] = fpu_f32_to_bits(stored_length);
        out[17] &= ~1u;
        return;
    }

    /* 0x8C070964..99A normalizes the frame vector in place. */
    x = n_rdflt(ram, sp + 68);
    y = n_rdflt(ram, sp + 72);
    z = n_rdflt(ram, sp + 76);
    norm2 = n_fipr_native(x, y, z, 0.0f);
    {
        /* Flycast's FSRRA path computes 1/sqrtf, then rounds each FMUL. */
        float scale = fpu_dn_fix(f32_tz((long double)fpu_bits_to_f32(in[36]) /
                                        sqrtl((long double)norm2)), fpscr);
        x = fmul_tz(x, scale);
        y = fmul_tz(y, scale);
        z = fmul_tz(z, scale);
        n_wr32(ram, sp + 76, fpu_f32_to_bits(z));
        n_wr32(ram, sp + 72, fpu_f32_to_bits(y));
        n_wr32(ram, sp + 68, fpu_f32_to_bits(x));
        out[4] = sp + 68;
        out[5] = sp + 80;
        out[22] = fpu_f32_to_bits(y);
        out[23] = fpu_f32_to_bits(z);
        out[24] = fpu_f32_to_bits(scale);
        out[25] = fpu_f32_to_bits(fpu_bits_to_f32(in[36]));
        out[26] = fpu_f32_to_bits(sy);
        out[27] = fpu_f32_to_bits(sz);
        out[28] = fpu_f32_to_bits(dot);
        out[17] |= 1u;
    }
    out[0] = 24;
    out[3] = 0x0C070A40u;
    out[21] = fpu_f32_to_bits(x);
}
