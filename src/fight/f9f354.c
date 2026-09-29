/* SH-4 0x8C09F354: repeated in-place vector update followed by three
 * finishing vectors. Arithmetic follows FPSCR's truncate-toward-zero mode.
 */
#include "fight/f9f354.h"
#include "fight/fpu_tz.h"

#include <string.h>

static uint32_t f9_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t a = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4u <= w->base + w->len) {
            uint32_t v;
            memcpy(&v, w->data + (a - w->base), sizeof(v));
            return v;
        }
    }
    ++m->oob;
    return 0;
}

static void f9_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint32_t a = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4u <= w->base + w->len) {
            memcpy(w->data + (a - w->base), &v, sizeof(v));
            return;
        }
    }
    ++m->oob;
}

static float f9_rd(const vf3_ram_map *ram, uint32_t addr)
{
    return fpu_bits_to_f32(f9_rd32(ram, addr));
}

static void f9_wr(const vf3_ram_map *ram, uint32_t addr, float f)
{
    f9_wr32(ram, addr, fpu_f32_to_bits(f));
}

int vf3_f9f354(const uint32_t in[37], uint32_t out[37],
               const vf3_ram_map *ram)
{
    uint32_t r4 = in[4], r5 = in[5], r6, r7, r3, sp = in[15] - 4u;
    float fr[16];
    for (int i = 0; i < 16; ++i)
        fr[i] = fpu_bits_to_f32(in[21 + i]);

    /* 18 iterations, dt r6 / bf/s; each iteration advances the source
     * and walks one destination triple. */
    for (int n = 0; n < 18; ++n) {
        r3 = r4 + 8u;
        r7 = r4 + 4u;
        float f6 = f9_rd(ram, r4);
        float f8 = f9_rd(ram, r7);
        float f9 = f9_rd(ram, r5 + 4u);
        float f7 = f9_rd(ram, r5 + 8u);
        float f5 = f9_rd(ram, r3);
        float f10;
        f8 = fsub_tz(f8, f9);
        f10 = f9_rd(ram, r5);
        r5 += 12u;
        f5 = fsub_tz(f5, f7);
        fr[0] = fr[4];
        f6 = fsub_tz(f6, f10);
        f9 = fmac_tz(fr[0], f8, f9);
        f7 = fmac_tz(fr[0], f5, f7);
        f10 = fmac_tz(fr[0], f6, f10);
        fr[8] = f9; fr[5] = f7; fr[6] = f10;
        f9_wr(ram, r4, fr[6]);
        f9_wr(ram, r7, fr[8]);
        f9_wr32(ram, sp, r3);
        r3 = f9_rd32(ram, sp);
        f9_wr(ram, r3, fr[5]);
        r4 += 12u;
    }

    /* The three finishing vectors operate on the first words after the
     * 18-element source span. */
    r6 = r4;
    {
        float f10 = f9_rd(ram, r5);
        float f6 = f9_rd(ram, r4);
        float f9 = f9_rd(ram, r5 + 4u);
        float f7, f5, f8;
        r6 += 4u;
        f7 = f9_rd(ram, r6);
        r7 = r4;
        r7 += 8u;
        f5 = f9_rd(ram, r7);
        f8 = f9_rd(ram, r5 + 8u);
        r5 += 12u;
        fr[0] = fr[4];
        f6 = fsub_tz(f6, f10);
        f7 = fsub_tz(f7, f9);
        f10 = fmac_tz(fr[0], f6, f10);
        f5 = fsub_tz(f5, f8);
        f9 = fmac_tz(fr[0], f7, f9);
        f8 = fmac_tz(fr[0], f5, f8);
        f6 = f10; f7 = f9; f5 = f8;
        f9_wr(ram, r4, f6); r4 += 12u;
        f9_wr(ram, r6, f7);
        r6 = r4 + 4u;
        f9_wr(ram, r7, f5);
        fr[6] = f6; fr[7] = f7; fr[5] = f5;
    }
    {
        float f7 = f9_rd(ram, r6);
        float f6 = f9_rd(ram, r4);
        float f8 = f9_rd(ram, r5);
        float f9 = f9_rd(ram, r5 + 4u);
        float f10 = f9_rd(ram, r5 + 8u);
        float f5;
        r7 = r4 + 8u;
        f5 = f9_rd(ram, r7);
        r5 += 12u;
        f7 = fsub_tz(f7, f9);
        f6 = fsub_tz(f6, f8);
        f5 = fsub_tz(f5, f10);
        fr[9] = fmac_tz(fr[0], f7, f9);
        fr[8] = fmac_tz(fr[0], f6, f8);
        fr[10] = fmac_tz(fr[0], f5, f10);
        fr[6] = fr[9]; fr[5] = fr[10];
        f9_wr(ram, r4, fr[8]); r4 += 12u;
        f9_wr(ram, r6, fr[6]);
        r6 = r4;
        f9_wr(ram, r7, fr[5]);
    }
    {
        float f9;
        float f8 = f9_rd(ram, r4);
        float f6, f7, f10, f5;
        r6 += 8u;
        r7 = r4 + 4u;
        f9 = f9_rd(ram, r5 + 4u);
        f6 = f9_rd(ram, r5 + 8u);
        f7 = f9_rd(ram, r7);
        f10 = f9_rd(ram, r5);
        f5 = f9_rd(ram, r6);
        f5 = fsub_tz(f5, f6);
        f7 = fsub_tz(f7, f9);
        f8 = fsub_tz(f8, f10);
        fr[6] = fmac_tz(fr[0], f5, f6);
        fr[9] = fmac_tz(fr[0], f7, f9);
        fr[10] = fmac_tz(fr[0], f8, f10);
        fr[4] = fr[6]; fr[5] = f5; fr[7] = fr[9]; fr[8] = fr[10];
        f9_wr(ram, r4, fr[8]);
        f9_wr(ram, r7, fr[7]);
        f9_wr(ram, r6, fr[4]);
    }

    memcpy(out, in, 37u * sizeof(uint32_t));
    out[0] = 8u;
    out[3] = r3;
    out[4] = r4;
    out[5] = r5;
    out[6] = r6;
    out[7] = r7;
    out[15] = in[15];
    out[17] = in[17] | 1u;
    for (int i = 0; i < 16; ++i)
        out[21 + i] = fpu_f32_to_bits(fr[i]);
    return ram->oob == 0;
}
