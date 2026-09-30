/* Readable first-transfer model of the 0x8C0706C4 FPU vector pipeline. */
#include "fight/fvecmix0706c4.h"
#include "fight/fpu_tz.h"
#include "fight/sh4_fpu.h"

#include <math.h>
#include <string.h>

static uint32_t vm6_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static void vm6_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t value)
{
    uint32_t a = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4 <= w->base + w->len) {
            memcpy(w->data + a - w->base, &value, 4);
            return;
        }
    }
    m->oob++;
}

static float vm6_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    return fpu_bits_to_f32(vm6_rd32(ram, addr));
}

static void vm6_wrflt(const vf3_ram_map *ram, uint32_t addr, float value)
{
    vm6_wr32(ram, addr, fpu_f32_to_bits(value));
}

static float vm6_fipr(const float a[4], const float b[4])
{
    /* SH-4 FIPR accumulates four products before the RM=truncate result. */
    double sum = (double)a[0] * b[0];
    sum += (double)a[1] * b[1];
    sum += (double)a[2] * b[2];
    sum += (double)a[3] * b[3];
    return f32_tz((long double)sum);
}

static float vm6_sqrt(float value, uint32_t fpscr)
{
    return fpu_dn_fix(f32_tz(sqrtl((long double)value)), fpscr);
}


static int vm6_normalization_scale(float norm2, float threshold, uint32_t fpscr, float *scale)
{
    uint32_t inverse;
    if (!vf3_fpu_fsrra(fpu_f32_to_bits(norm2), fpscr, &inverse)) return 0;
    *scale=fpu_bits_to_f32(vf3_fpu_binary(inverse, fpu_f32_to_bits(threshold), fpscr, '*'));
    return 1;
}

static float vm6_fmac(float a, float b, float c, uint32_t fpscr)
{
    return fpu_dn_fix(fmac_tz(a, b, c), fpscr);
}

static float vm6_mul(float a, float b, uint32_t fpscr)
{
    return fpu_dn_fix(fmul_tz(a, b), fpscr);
}

static void vm6_set_t(uint32_t out[37], int set)
{
    out[17] = (out[17] & ~1u) | (set != 0);
}

static void vm6_save_fr(uint32_t out[37], const float fr[16])
{
    for (int i = 0; i < 16; i++)
        out[21 + i] = fpu_f32_to_bits(fr[i]);
}

int vf3_fvecmix0706c4_8c0706c4(const uint32_t in[37], uint32_t out[37],
                               uint32_t *transfer_pc,
                               const vf3_ram_map *ram)
{
    const uint32_t sp = in[15], src = in[12], fpscr = in[18];
    float fr[16];
    float v[3], s[3], fv0[4], fv4[4];
    float len2, len, cross_len2, cross_len, dot;

    memcpy(out, in, 37 * sizeof(*out));
    for (int i = 0; i < 16; i++)
        fr[i] = fpu_bits_to_f32(in[21 + i]);

    /* Entry spill aliases the first frame vector word in this call path. */
    vm6_wr32(ram, in[4] - 4, in[21]);
    v[0] = vm6_rdflt(ram, sp + 68);
    v[1] = vm6_rdflt(ram, sp + 72);
    v[2] = vm6_rdflt(ram, sp + 76);

    fv0[0] = v[0]; fv0[1] = v[1]; fv0[2] = v[2]; fv0[3] = 0.0f;
    len2 = vm6_fipr(fv0, fv0);
    len = vm6_sqrt(len2, fpscr);
    fr[0] = len;
    fr[3] = 0.0f;
    vm6_set_t(out, len > 0.0f);
    out[0] = 8;
    if (!(len > 0.0f))
        return 0; /* The 0x8C0706E8 zero-length transfer was not captured. */

    /* The delayed store at 0x8C0706E4 runs on the positive-length path. */
    vm6_wrflt(ram, sp + 8, len);
    v[0] = vm6_rdflt(ram, sp + 68);
    v[1] = vm6_rdflt(ram, sp + 72);
    v[2] = vm6_rdflt(ram, sp + 76);
    s[0] = vm6_rdflt(ram, src);
    s[1] = vm6_rdflt(ram, src + 4);
    s[2] = vm6_rdflt(ram, src + 8);

    /* 0x8C070708..722 builds the cross product in ordered FMUL/FMAC steps. */
    fr[0] = v[0]; fr[5] = v[1]; fr[6] = v[2];
    fr[8] = s[0]; fr[9] = s[1]; fr[10] = s[2];
    fr[3] = vm6_mul(fr[5], fr[8], fpscr);
    fr[2] = vm6_mul(fr[0], fr[10], fpscr);
    fr[1] = vm6_mul(fr[6], fr[9], fpscr);
    fr[3] = vm6_fmac(fr[0], fr[9], -fr[3], fpscr);
    fr[0] = fr[6];
    fr[2] = vm6_fmac(fr[0], fr[8], -fr[2], fpscr);
    fr[0] = fr[5];
    fr[1] = vm6_fmac(fr[0], fr[10], -fr[1], fpscr);

    fr[0] = 0.0f;
    fv0[0] = fr[0]; fv0[1] = fr[1]; fv0[2] = fr[2]; fv0[3] = fr[3];
    cross_len2 = vm6_fipr(fv0, fv0);
    cross_len = vm6_sqrt(cross_len2, fpscr);
    fr[0] = cross_len;
    fr[3] = cross_len2;
    fr[12] = cross_len;
    vm6_set_t(out, fr[15] > cross_len);
    if (!(fr[15] > cross_len)) {
        /* 0x8C070734 jumps to 0x0C070878. */
        out[3] = 0x0C070878u;
        out[4] = sp + 76;
        out[5] = src + 8;
        *transfer_pc = 0x0C070734u;
        vm6_save_fr(out, fr);
        return 1;
    }

    /* 0x8C070748..75A computes the weighted source dot product. */
    v[0] = vm6_rdflt(ram, sp + 68);
    v[1] = vm6_rdflt(ram, sp + 72);
    v[2] = vm6_rdflt(ram, sp + 76);
    s[0] = vm6_rdflt(ram, src);
    s[1] = vm6_rdflt(ram, src + 4);
    s[2] = vm6_rdflt(ram, src + 8);
    fr[0] = v[0]; fr[1] = v[1]; fr[2] = v[2]; fr[3] = 0.0f;
    fr[4] = s[0]; fr[5] = s[1]; fr[6] = s[2]; fr[7] = 0.0f;
    fv0[0] = fr[0]; fv0[1] = fr[1]; fv0[2] = fr[2]; fv0[3] = fr[3];
    fv4[0] = fr[4]; fv4[1] = fr[5]; fv4[2] = fr[6]; fv4[3] = fr[7];
    dot = vm6_fipr(fv0, fv4);
    fr[7] = dot;
    fr[0] = dot;
    fr[3] = 0.0f;
    fr[4] = fr[0];
    vm6_set_t(out, fr[3] > fr[4]);
    if (!(fr[3] > fr[4])) {
        /* 0x8C070766 jumps to 0x0C0707B2. */
        out[3] = 0x0C0707B2u;
        out[4] = sp + 80;
        out[5] = src + 12;
        *transfer_pc = 0x0C070766u;
        vm6_save_fr(out, fr);
        return 1;
    }

    fr[3] = vm6_rdflt(ram, sp + 8);
    vm6_set_t(out, fr[15] > fr[3]);
    if (!(fr[15] > fr[3])) {
        /* 0x8C070774 jumps to 0x0C070878. */
        out[3] = 0x0C070878u;
        out[4] = sp + 80;
        out[5] = src + 12;
        *transfer_pc = 0x0C070774u;
        vm6_save_fr(out, fr);
        return 1;
    }

    /* 0x8C070790..7AA scales the frame vector and writes it back in place. */
    fr[4] = fr[15];
    v[0] = vm6_rdflt(ram, sp + 68);
    v[1] = vm6_rdflt(ram, sp + 72);
    v[2] = vm6_rdflt(ram, sp + 76);
    fv0[0] = v[0]; fv0[1] = v[1]; fv0[2] = v[2]; fv0[3] = 0.0f;
    len2 = vm6_fipr(fv0, fv0);
    if (!vm6_normalization_scale(len2, fr[4], fpscr, &fr[3]))
        return 0;
    fr[0] = vm6_mul(v[0], fr[3], fpscr);
    fr[1] = vm6_mul(v[1], fr[3], fpscr);
    fr[2] = vm6_mul(v[2], fr[3], fpscr);
    vm6_wrflt(ram, sp + 76, fr[2]);
    vm6_wrflt(ram, sp + 72, fr[1]);
    vm6_wrflt(ram, sp + 68, fr[0]);
    out[3] = 0x0C070854u;
    out[4] = sp + 68;
    out[5] = sp + 80;
    *transfer_pc = 0x0C0707AEu;
    vm6_set_t(out, 1);
    vm6_save_fr(out, fr);
    return 1;
}
