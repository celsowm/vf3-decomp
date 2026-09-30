/* Readable model of the observed 0x8C070CF0 vector normalization paths. */
#include "fight/fvecnorm070cf0.h"
#include "fight/fpu_tz.h"
#include "fight/sh4_fpu.h"

#include <string.h>

static uint32_t vcf0_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static void vcf0_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
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

static float vcf0_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    return fpu_bits_to_f32(vcf0_rd32(ram, addr));
}

static float vcf0_fipr(float x0, float x1, float x2, float x3,
                      float y0, float y1, float y2, float y3)
{
    /* SH-4 FIPR accumulates four products before the FPSCR.RM truncation. */
    double d = (double)x0 * y0;
    d += (double)x1 * y1;
    d += (double)x2 * y2;
    d += (double)x3 * y3;
    return f32_tz((long double)d);
}

static float vcf0_sqrt(float x, uint32_t fpscr)
{
    return fpu_dn_fix(f32_tz(sqrtl((long double)x)), fpscr);
}

static void vcf0_store_fr(uint32_t out[37], const float fr[16])
{
    memcpy(out + 21, fr, 16 * sizeof(uint32_t));
}

static int vcf0_normalization_scale(float norm2, float threshold, uint32_t fpscr, float *scale)
{
    uint32_t inverse;
    if (!vf3_fpu_fsrra(fpu_f32_to_bits(norm2), fpscr, &inverse))
        return 0;
    *scale = fpu_bits_to_f32(vf3_fpu_binary(inverse, fpu_f32_to_bits(threshold), fpscr, '*'));
    return 1;
}

int vf3_fvecnorm070cf0_8c070cf0(const uint32_t in[37], uint32_t out[37],
                                const vf3_ram_map *ram)
{
    const uint32_t sp = in[15], source = in[11], fpscr = in[18];
    float v[3], s[3], c[3], len2, len, dot;
    float fr[16];

    memcpy(out, in, 37 * sizeof(uint32_t));
    memcpy(fr, in + 21, sizeof(fr));
    /* Entry instruction spills caller FR0 at R4-4. */
    vcf0_wr32(ram, in[4] - 4, in[21]);

    v[0] = vcf0_rdflt(ram, sp + 68);
    v[1] = vcf0_rdflt(ram, sp + 72);
    v[2] = vcf0_rdflt(ram, sp + 76);
    len2 = vcf0_fipr(v[0], v[1], v[2], 0, v[0], v[1], v[2], 0);
    len = vcf0_sqrt(len2, fpscr);
    fr[0] = len;
    fr[3] = 0;
    fr[12] = len;
    if (len == 0.0f)
        return 0; /* The zero-vector route at 0x8C070D12 is not in this set. */

    s[0] = vcf0_rdflt(ram, source);
    s[1] = vcf0_rdflt(ram, source + 4);
    s[2] = vcf0_rdflt(ram, source + 8);
    /* 0x8C070D30..4A ordered FMUL/FMAC cross product. */
    c[2] = fmac_tz(v[0], s[1], -fmul_tz(v[1], s[0]));
    c[1] = fmac_tz(v[2], s[0], -fmul_tz(v[0], s[2]));
    c[0] = fmac_tz(v[1], s[2], -fmul_tz(v[2], s[1]));
    fr[0] = v[0]; fr[5] = v[1]; fr[6] = v[2];
    fr[8] = s[0]; fr[9] = s[1]; fr[10] = s[2];
    fr[1] = c[0]; fr[2] = c[1]; fr[3] = c[2];
    len2 = vcf0_fipr(c[0], c[1], c[2], 0, c[0], c[1], c[2], 0);
    len = vcf0_sqrt(len2, fpscr);
    fr[0] = len;
    fr[3] = len2;
    fr[15] = fpu_bits_to_f32(in[36]);
    out[0] = 28;
    /* BT/S at 0xD58 retires this cross-length store before either path. */
    vcf0_wr32(ram, sp + 28, fpu_f32_to_bits(len));
    out[4] = sp + 76;
    out[5] = source + 8;
    if (!(fr[15] > len)) {
        out[3] = 0x0C070EA0u;
        out[17] &= ~1u;
        vcf0_store_fr(out, fr);
        return 1;
    }

    /* FIPR writes the vector dot product to FR7. */
    out[4] = sp + 80;
    dot = vcf0_fipr(v[0], v[1], v[2], 0, s[0], s[1], s[2], 0);
    out[5] = source + 12;
    fr[0] = dot;
    fr[1] = v[1]; fr[2] = v[2];
    fr[3] = 0;
    fr[4] = dot;
    fr[5] = s[1]; fr[6] = s[2];
    fr[8] = s[0]; fr[9] = s[1]; fr[10] = s[2];
    fr[7] = dot;
    if (dot >= 0.0f) {
        out[3] = in[3];
        out[17] &= ~1u;
        vcf0_store_fr(out, fr);
        return 1;
    }
    out[17] |= 1u;

    if (!(fr[15] > fr[12])) {
        out[2] = 0x0C070EA0u;
        out[17] &= ~1u;
        vcf0_store_fr(out, fr);
        return 1;
    }

    /* 0x8C070D9C..DD2: normalize and tail-transfer to 0x0C070E7C. */
    len2 = vcf0_fipr(v[0], v[1], v[2], 0, v[0], v[1], v[2], 0);
    if (!vcf0_normalization_scale(len2, fr[15], fpscr, &len))
        return 0;
    v[0] = fmul_tz(v[0], len);
    v[1] = fmul_tz(v[1], len);
    v[2] = fmul_tz(v[2], len);
    vcf0_wr32(ram, sp + 68, fpu_f32_to_bits(v[0]));
    vcf0_wr32(ram, sp + 72, fpu_f32_to_bits(v[1]));
    vcf0_wr32(ram, sp + 76, fpu_f32_to_bits(v[2]));
    out[2] = 0x0C070E7Cu;
    out[4] = sp + 68;
    out[5] = sp + 80;
    fr[0] = v[0]; fr[1] = v[1]; fr[2] = v[2];
    fr[3] = len;
    fr[4] = fpu_bits_to_f32(in[36]);
    out[17] |= 1u;
    vcf0_store_fr(out, fr);
    return 1;
}
