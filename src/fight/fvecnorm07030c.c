/* Readable model of the observed 0x8C07030C vector normalization paths. */
#include "fight/fvecnorm07030c.h"
#include "fight/fpu_tz.h"
#include "fight/sh4_fpu.h"

#include <string.h>

static uint32_t v30c_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t a = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4 <= w->base + w->len) {
            uint32_t v;
            memcpy(&v, w->data + a - w->base, 4);
            return v;
        }
    }
    m->oob++;
    return 0;
}

static void v30c_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint32_t a = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4 <= w->base + w->len) {
            memcpy(w->data + a - w->base, &v, 4);
            return;
        }
    }
    m->oob++;
}

static float v30c_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    return fpu_bits_to_f32(v30c_rd32(ram, addr));
}

static float v30c_fipr(float x0, float x1, float x2, float x3,
                      float y0, float y1, float y2, float y3)
{
    /* SH-4 FIPR accumulates four products before the FPSCR.RM truncation. */
    double d = (double)x0 * y0;
    d += (double)x1 * y1;
    d += (double)x2 * y2;
    d += (double)x3 * y3;
    return f32_tz((long double)d);
}

static float v30c_sqrt(float x, uint32_t fpscr)
{
    return fpu_dn_fix(f32_tz(sqrtl((long double)x)), fpscr);
}

static void v30c_store_fr(uint32_t out[37], const float fr[16])
{
    memcpy(out + 21, fr, 16 * sizeof(uint32_t));
}

static int v30c_normalization_scale(float norm2, float threshold, uint32_t fpscr, float *scale)
{
    uint32_t inverse;
    if (!vf3_fpu_fsrra(fpu_f32_to_bits(norm2), fpscr, &inverse))
        return 0;
    *scale = fpu_bits_to_f32(vf3_fpu_binary(inverse, fpu_f32_to_bits(threshold), fpscr, '*'));
    return 1;
}

int vf3_fvecnorm07030c_8c07030c(const uint32_t in[37], uint32_t out[37],
                                const vf3_ram_map *ram)
{
    const uint32_t sp = in[15], fpscr = in[18];
    float v[3], s[3], c[3], len2, len, dot;
    float fr[16];

    memcpy(out, in, 37 * sizeof(uint32_t));
    memcpy(fr, in + 21, sizeof(fr));
    /* Entry instruction spills caller FR0 at R4-4. */
    v30c_wr32(ram, in[4] - 4, in[21]);

    v[0] = v30c_rdflt(ram, sp + 68);
    v[1] = v30c_rdflt(ram, sp + 72);
    v[2] = v30c_rdflt(ram, sp + 76);
    len2 = v30c_fipr(v[0], v[1], v[2], 0, v[0], v[1], v[2], 0);
    len = v30c_sqrt(len2, fpscr);
    fr[0] = len;
    fr[3] = 0;
    if (len == 0.0f)
        return 0; /* The zero-vector route at 0x8C07032E is not in this set. */
    /* 0x8C07032C delay slot stores FR0 at SP+20. */
    v30c_wr32(ram, sp + 20, fpu_f32_to_bits(len));

    s[0] = v30c_rdflt(ram, in[12]);
    s[1] = v30c_rdflt(ram, in[12] + 4);
    s[2] = v30c_rdflt(ram, in[12] + 8);
    /* 0x8C070350..6A ordered FMUL/FMAC cross product. */
    c[2] = fmac_tz(v[0], s[1], -fmul_tz(v[1], s[0]));
    c[1] = fmac_tz(v[2], s[0], -fmul_tz(v[0], s[2]));
    c[0] = fmac_tz(v[1], s[2], -fmul_tz(v[2], s[1]));
    fr[0] = v[0]; fr[5] = v[1]; fr[6] = v[2];
    fr[8] = s[0]; fr[9] = s[1]; fr[10] = s[2];
    fr[1] = c[0]; fr[2] = c[1]; fr[3] = c[2];
    len2 = v30c_fipr(c[0], c[1], c[2], 0, c[0], c[1], c[2], 0);
    len = v30c_sqrt(len2, fpscr);
    fr[0] = len;
    fr[3] = len2;
    fr[12] = len;
    fr[15] = fpu_bits_to_f32(in[36]);
    out[0] = 20;
    out[4] = sp + 76;
    out[5] = in[12] + 8;
    if (!(fr[15] > len)) {
        out[3] = 0x0C0704C0u;
        out[17] &= ~1u;
        v30c_store_fr(out, fr);
        return 1;
    }

    /* FIPR writes the vector dot product to FR7, then copies it to FR0. */
    out[4] = sp + 80;
    dot = v30c_fipr(v[0], v[1], v[2], 0, s[0], s[1], s[2], 0);
    out[5] = in[12] + 12;
    fr[0] = dot;
    fr[1] = v[1]; fr[2] = v[2];
    fr[3] = 0;
    fr[4] = dot;
    fr[5] = s[1]; fr[6] = s[2];
    fr[8] = s[0]; fr[9] = s[1]; fr[10] = s[2];
    fr[7] = dot;
    if (dot >= 0.0f) {
        out[3] = 0x0C0703FAu;
        out[17] &= ~1u;
        v30c_store_fr(out, fr);
        return 1;
    }
    out[17] |= 1u;

    len = v30c_rdflt(ram, sp + 20);
    fr[3] = len;
    if (!(fr[15] > len))
        return 0; /* The unobserved 0x8C0703BC helper path is rejected. */

    /* 0x8C0703C0..3F4: scale and write the frame vector in place. */
    len2 = v30c_fipr(v[0], v[1], v[2], 0, v[0], v[1], v[2], 0);
    if (!v30c_normalization_scale(len2, fr[15], fpscr, &len))
        return 0;
    v[0] = fmul_tz(v[0], len);
    v[1] = fmul_tz(v[1], len);
    v[2] = fmul_tz(v[2], len);
    v30c_wr32(ram, sp + 68, fpu_f32_to_bits(v[0]));
    v30c_wr32(ram, sp + 72, fpu_f32_to_bits(v[1]));
    v30c_wr32(ram, sp + 76, fpu_f32_to_bits(v[2]));
    out[4] = sp + 68;
    out[5] = sp + 80;
    fr[0] = v[0]; fr[1] = v[1]; fr[2] = v[2];
    fr[3] = len;
    fr[4] = fpu_bits_to_f32(in[36]);
    out[3] = 0x0C0702ECu;
    out[17] |= 1u;
    v30c_store_fr(out, fr);
    return 1;
}
