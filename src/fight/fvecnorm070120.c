/* 0x8C070120 fragment through its three observed branch boundaries. */
#include "fight/fvecnorm070120.h"
#include "fight/fpu_tz.h"

#include <string.h>

static uint32_t v120_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static void v120_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
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

static float v120_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    return fpu_bits_to_f32(v120_rd32(ram, addr));
}

static float v120_fipr(float x0, float x1, float x2, float x3,
                       float y0, float y1, float y2, float y3)
{
    double d = (double)x0 * y0;
    d += (double)x1 * y1;
    d += (double)x2 * y2;
    d += (double)x3 * y3;
    return f32_tz((long double)d);
}

static float v120_sqrt(float x, uint32_t fpscr)
{
    return fpu_dn_fix(f32_tz(sqrtl((long double)x)), fpscr);
}

static void v120_store_fr(uint32_t out[37], const float fr[16])
{
    memcpy(out + 21, fr, 16 * sizeof(uint32_t));
}

int vf3_fvecnorm070120_8c070120(const uint32_t in[37], uint32_t out[37],
                                const vf3_ram_map *ram)
{
    const uint32_t sp = in[15], source = in[11], fpscr = in[18];
    float fr[16], v[3], s[3], c[3], norm2, length, dot;
    uint32_t route;

    memcpy(out, in, 37 * sizeof(uint32_t));
    memcpy(fr, in + 21, sizeof(fr));
    /* Entry spill and first vector length (0x8C070120..13C). */
    v120_wr32(ram, in[4] - 4, in[21]);
    v[0] = v120_rdflt(ram, sp + 68);
    v[1] = v120_rdflt(ram, sp + 72);
    v[2] = v120_rdflt(ram, sp + 76);
    norm2 = v120_fipr(v[0], v[1], v[2], 0, v[0], v[1], v[2], 0);
    length = v120_sqrt(norm2, fpscr);
    fr[0] = length;
    fr[3] = 0;
    fr[12] = length;

    /* 0x8C070146..182: ordered vector cross product and magnitude. */
    s[0] = v120_rdflt(ram, source);
    s[1] = v120_rdflt(ram, source + 4);
    s[2] = v120_rdflt(ram, source + 8);
    c[2] = fmac_tz(v[0], s[1], -fmul_tz(v[1], s[0]));
    c[1] = fmac_tz(v[2], s[0], -fmul_tz(v[0], s[2]));
    c[0] = fmac_tz(v[1], s[2], -fmul_tz(v[2], s[1]));
    fr[0] = v[0]; fr[1] = c[0]; fr[2] = c[1]; fr[3] = c[2];
    fr[5] = v[1]; fr[6] = v[2];
    fr[8] = s[0]; fr[9] = s[1]; fr[10] = s[2];
    norm2 = v120_fipr(c[0], c[1], c[2], 0, c[0], c[1], c[2], 0);
    length = v120_sqrt(norm2, fpscr);
    fr[0] = length;
    fr[3] = norm2;
    out[0] = 12;

    /* SH-4 BT/S retires its delay-slot store on either branch outcome. */
    v120_wr32(ram, sp + 12, fpu_f32_to_bits(length));
    if (!(fpu_bits_to_f32(in[36]) > length)) {
        /* 0x8C07018E tail transfer when the cross length reaches the limit. */
        route = 0x0C0702ECu;
        out[3] = route;
        out[4] = sp + 76;
        out[5] = source + 8;
        out[17] &= ~1u;
        v120_store_fr(out, fr);
        return 1;
    }

    /* 0x8C070192..1B8 computes source/vector dot into FR7. */
    dot = v120_fipr(v[0], v[1], v[2], 0, s[0], s[1], s[2], 0);
    fr[0] = dot;
    fr[1] = v[1]; fr[2] = v[2]; fr[3] = 0;
    fr[4] = dot; fr[5] = s[1]; fr[6] = s[2]; fr[7] = dot;
    fr[8] = s[0]; fr[9] = s[1]; fr[10] = s[2];
    out[4] = sp + 80;
    out[5] = source + 12;

    if (dot >= 0.0f) {
        /* 0x8C0701BE tail transfer for a nonnegative dot product. */
        out[3] = 0x0C070226u;
        out[17] &= ~1u;
        v120_store_fr(out, fr);
        return 1;
    }

    if (!(fpu_bits_to_f32(in[36]) > fr[12]))
        return 0; /* The unobserved 0x8C0701C8 exit is deliberately rejected. */

    /* 0x8C0701CC..1EC, ending at the inventory fragment boundary. */
    fr[4] = fsub_tz(fr[12], fpu_bits_to_f32(in[36]));
    v[0] = v120_rdflt(ram, sp + 68);
    v[1] = v120_rdflt(ram, sp + 72);
    v[2] = v120_rdflt(ram, sp + 76);
    fr[0] = v[0]; fr[1] = v[1]; fr[2] = v[2]; fr[3] = 0;
    norm2 = v120_fipr(v[0], v[1], v[2], 0, v[0], v[1], v[2], 0);
    fr[3] = norm2;
    out[4] = sp + 68;
    out[5] = sp + 80;
    out[17] |= 1u;
    v120_store_fr(out, fr);
    return 1;
}
