/* scalemap.c — warping scale-map sampler, SH-4 0x8C068E16.
 *
 * Oracle-verified against 64 fight-scenario golden cases (entry/exit
 * snapshots + byte-exact RAM windows).
 *
 * The game runs with FPSCR = 0x240001: RM=1 (round toward zero) and DN=1
 * (denormals are zero), so every SH-4 FPU op truncates instead of rounding
 * to nearest. The f32_tz/fmul_tz/fadd_tz/fsub_tz/fmac_tz helpers reproduce
 * that; using round-to-nearest shifts results by ~1 ULP and fails the
 * golden comparison.
 *
 * Entry r0 == 8 (caller convention): prologue stores pr at [r15-4],
 * frame = r15-40; fr4 -> [frame+r0], fr5 -> [frame+4]. The port mirrors
 * every stack write so the replay memory diff matches byte-exactly.
 *
 * Exercised path (all 64 cases, selector 15 & mask 0x01 -> no rescale):
 *   t = fma(5, coord, 64); i = trunc(t); f = t - i;
 *   idx = (i1 & 0x7F) | ((i2 & 0x7F) << 7);
 *   v = A[idx]*(1-f1)*(1-f2) + A[idx+1]*f1*(1-f2)
 *     + A[idx+0x80]*(1-f1)*f2 + A[idx+0x81]*f1*f2
 * over a 128x128 float table at *(0x0C1B9610), clamped coords [-12,12].
 *
 * Not exercised / documented gaps:
 *  - selector 11 auxiliary call 0x0C087ACE (not implemented),
 *  - selector 13 branch constants at 0x8C068E54 (0.1f) — plausible, unverified,
 *  - ctx == 0 fallback to 0x8C068DE4, K constant taken from 0x8C068E60
 *    (-0.5f), unverified.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fight/scalemap.h"
#include "fight/fpu_tz.h"

static float bits_to_f32(uint32_t bits) { return fpu_bits_to_f32(bits); }
static uint32_t f32_to_bits(float f) { return fpu_f32_to_bits(f); }

/* ---- replay memory access (windows are writable shadows) ---------------- */
static uint8_t *win_of(const vf3_ram_map *ram, uint32_t addr, uint32_t n)
{
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (addr >= w->base && addr + n <= w->base + w->len)
            return w->data + (addr - w->base);
    }
    ((vf3_ram_map *)ram)->oob++;
    return NULL;
}

static uint32_t rd_u32(const vf3_ram_map *ram, uint32_t addr)
{
    uint8_t *p = win_of(ram, addr, 4);
    uint32_t v = 0;
    if (p)
        memcpy(&v, p, 4);
    return v;
}

static uint8_t rd_u8(const vf3_ram_map *ram, uint32_t addr)
{
    uint8_t *p = win_of(ram, addr, 1);
    return p ? *p : 0;
}

static void wr_u32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint8_t *p = win_of(ram, addr, 4);
    if (p)
        memcpy(p, &v, 4);
}

static float rd_f32(const vf3_ram_map *ram, uint32_t addr)
{
    uint8_t *p = win_of(ram, addr, 4);
    float f = 0.0f;
    if (p)
        memcpy(&f, p, 4);
    return f;
}

static void wr_f32(const vf3_ram_map *ram, uint32_t addr, float f)
{
    uint8_t *p = win_of(ram, addr, 4);
    if (p)
        memcpy(p, &f, 4);
}

/* 0x8C068D54 — selector-driven coordinate rescale/quantize. */
static void scalemap_rescale(uint32_t sel, const vf3_ram_map *ram,
                             uint32_t pa_addr, uint32_t pb_addr)
{
    const float S = bits_to_f32(0x3F44EC4Fu);   /* 10/13 at 0x8C068E50 */
    if (sel == 2 || sel == 7) {
        wr_f32(ram, pa_addr, fmul_tz(rd_f32(ram, pa_addr), S));
        wr_f32(ram, pb_addr, fmul_tz(rd_f32(ram, pb_addr), S));
        return;
    }
    if (sel == 13) {
        const float C = bits_to_f32(0x3DCCCCCDu);
        int i;
        float v;
        i = (int)fmul_tz(rd_f32(ram, pa_addr), C);
        if (i & 1)
            i += (i < 0) ? -1 : 1;
        v = (float)(i * 10);
        wr_f32(ram, pa_addr, fsub_tz(rd_f32(ram, pa_addr), v));
        i = (int)fmul_tz(rd_f32(ram, pb_addr), C);
        if (i & 1)
            i += (i < 0) ? -1 : 1;
        v = (float)(i * 10);
        wr_f32(ram, pb_addr, fsub_tz(rd_f32(ram, pb_addr), v));
    }
}

float vf3_scalemap_8c068e16(uint32_t selector_in, uint32_t sp, uint32_t pr,
                            float fr4, float fr5, const vf3_ram_map *ram)
{
    uint32_t frame = sp - 4 - 36;      /* sts.l pr,@-r15; add #-36,r15 */
    uint32_t slot_a = frame + 8;       /* [r15+r0], r0 == 8 at entry */
    uint32_t slot_b = frame + 4;
    uint32_t selector = selector_in & rd_u8(ram, 0x0C29B880u);
    uint32_t ctx = rd_u32(ram, 0x0C1B9610u);

    wr_u32(ram, sp - 4, pr);
    wr_f32(ram, slot_a, fr4);
    wr_f32(ram, slot_b, fr5);

    scalemap_rescale(selector, ram, slot_a, slot_b);

    if (ctx == 0) {
        /* 0x8C068DE4(dst = frame+24): {0,0,1.0}; returns -0.5f */
        wr_f32(ram, frame + 32, 0.0f);
        wr_f32(ram, frame + 24, 0.0f);
        wr_f32(ram, frame + 28, 1.0f);
        wr_f32(ram, frame + 20, bits_to_f32(0xBF000000u));
        return bits_to_f32(0xBF000000u);
    }

    /* clamp to [-12, 12] in place (fcmp/gt + bt store form, NaN-safe) */
    {
        const float NEG12 = bits_to_f32(0xC1400000u);
        const float POS12 = bits_to_f32(0x41400000u);
        float a = rd_f32(ram, slot_a), b = rd_f32(ram, slot_b);
        if (!(a > NEG12))
            a = NEG12;
        if (!(b > NEG12))
            b = NEG12;
        if (!(POS12 > a))
            a = POS12;
        if (!(POS12 > b))
            b = POS12;
        wr_f32(ram, slot_a, a);
        wr_f32(ram, slot_b, b);
    }

    {
        const float FIVE = bits_to_f32(0x40A00000u);
        const float SIXTY4 = bits_to_f32(0x42800000u);
        float slot1 = rd_f32(ram, slot_a);
        float slot2 = rd_f32(ram, slot_b);
        float t1 = fmac_tz(FIVE, slot1, SIXTY4);
        float t2 = fmac_tz(FIVE, slot2, SIXTY4);
        int i1, i2;
        float f1, f2;
        uint32_t idx;
        float a0, a1, a2, a3, r2, r3, w, w1m, w2m;

        wr_f32(ram, frame + 0, t1);            /* fmov.s fr3,@r15 */
        i1 = (int)t1;                          /* ftrc: toward zero */
        i2 = (int)t2;
        f1 = fsub_tz(t1, (float)i1);
        f2 = fsub_tz(t2, (float)i2);
        idx = ((uint32_t)i1 & 0x7Fu) | (((uint32_t)i2 & 0x7Fu) << 7);

        a0 = rd_f32(ram, ctx + idx * 4);
        a1 = rd_f32(ram, ctx + (idx + 1) * 4);
        a2 = rd_f32(ram, ctx + (idx + 0x80) * 4);
        a3 = rd_f32(ram, ctx + (idx + 0x81) * 4);
        if (getenv("VF3_SCALEMAP_DBG"))
            fprintf(stderr, "DBG sel=%u ctx=%08x i1=%d i2=%d idx=%x "
                    "A=%08x %08x %08x %08x oob=%u\n", selector, ctx, i1, i2,
                    idx, f32_to_bits(a0), f32_to_bits(a1), f32_to_bits(a2),
                    f32_to_bits(a3), ram->oob);

        w1m = fsub_tz(1.0f, f1);
        w2m = fsub_tz(1.0f, f2);

        wr_f32(ram, frame + 16, a0);           /* fmov.s fr3,@(16,r15) */
        wr_f32(ram, frame + 12, a1);           /* [12] = A1 */
        wr_f32(ram, frame + 0, a2);            /* [0]  = A2 */
        wr_f32(ram, frame + 16, fmul_tz(a0, w1m));
        wr_f32(ram, frame + 12, fmul_tz(a1, f1));
        wr_f32(ram, frame + 0, fmul_tz(a2, w1m));
        wr_f32(ram, frame + 16, fmul_tz(fmul_tz(a0, w1m), w2m));

        r2 = fmul_tz(fmul_tz(a1, f1), w2m);
        r3 = fmul_tz(fmul_tz(a0, w1m), w2m);
        wr_f32(ram, frame + 12, r2);           /* [12] = (A1*f1)*(1-f2) */
        r2 = fmac_tz(f2, fmul_tz(a3, f1), r2);
        r3 = fmac_tz(f2, fmul_tz(a2, w1m), r3);
        wr_f32(ram, frame + 0, r3);            /* [0] = fr3 after fmac */
        w = fadd_tz(r3, r2);
        wr_f32(ram, frame + 20, w);            /* result */

        /* selector 11 auxiliary call 0x0C087ACE is not implemented. */
        return w;
    }
}

uint32_t vf3_scalemap_f32bits(float f)
{
    return f32_to_bits(f);
}
