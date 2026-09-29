/* Clean C model for SH-4 0x8C0CC148. */
#include "fight/cc148.h"

#include "fight/fdivker.h"
#include "fight/fpu_tz.h"

#include <string.h>

static uint32_t c148_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            uint32_t v;
            memcpy(&v, w->data + (canon - w->base), 4);
            return v;
        }
    }
    m->oob++;
    return 0;
}

static uint16_t c148_rd16(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 2 <= w->base + w->len) {
            uint16_t v;
            memcpy(&v, w->data + (canon - w->base), 2);
            return v;
        }
    }
    m->oob++;
    return 0;
}

static void c148_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            memcpy(w->data + (canon - w->base), &v, 4);
            return;
        }
    }
    m->oob++;
}

static void c148_wr16(const vf3_ram_map *ram, uint32_t addr, uint16_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 2 <= w->base + w->len) {
            memcpy(w->data + (canon - w->base), &v, 2);
            return;
        }
    }
    m->oob++;
}

static float c148_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    return fpu_bits_to_f32(c148_rd32(ram, addr));
}

static void c148_wrflt(const vf3_ram_map *ram, uint32_t addr, float v)
{
    c148_wr32(ram, addr, fpu_f32_to_bits(v));
}

static float c148_add(float a, float b, uint32_t fpscr)
{
    return fpu_dn_fix(fadd_tz(a, b), fpscr);
}

static float c148_sub(float a, float b, uint32_t fpscr)
{
    return fpu_dn_fix(fsub_tz(a, b), fpscr);
}

static float c148_mul(float a, float b, uint32_t fpscr)
{
    return fpu_dn_fix(fmul_tz(a, b), fpscr);
}

static float c148_mac(float a, float b, float c, uint32_t fpscr)
{
    return fpu_dn_fix(fmac_tz(a, b, c), fpscr);
}

void vf3_cc148_8c0cc148(const vf3_cc148_state *in, vf3_cc148_state *out,
                        const vf3_ram_map *ram)
{
    uint32_t r[16];
    float fr[16];
    uint32_t pr = in->pr, sr = in->sr;
    uint32_t fpscr = in->fpscr;
    uint32_t entry_sp = in->r[15], sp, r12;
    uint32_t kfr[8];
    vf3_fdivker_out k;

    memcpy(out, in, sizeof(*out));
    memcpy(r, in->r, sizeof(r));
    for (int i = 0; i < 16; i++)
        fr[i] = fpu_bits_to_f32(in->fr[i]);

    /* Prologue, first 0x8C03A6E0 range-reduction call. */
    sp = entry_sp - 4;
    c148_wr32(ram, sp, pr);                         /* 0xCC148 */
    sp -= 12;
    c148_wr32(ram, sp, r[6]);                       /* 0xCC14C */
    c148_wrflt(ram, sp + r[0], fr[4]);              /* 0xCC14E */
    r12 = c148_rd32(ram, sp + 0x20);                /* 0xCC150 */
    r[4] = (uint32_t)(int32_t)(int16_t)r12;         /* 0xCC154 */
    c148_wr32(ram, sp + 8, r[4]);                   /* 0xCC158 delay slot */
    vf3_fdivker_8c03a6e0(r[1], r[4], r[5], r[6], sp,
                         sr, fpscr, &k, ram);        /* 0xCC156 */
    r[0] = k.r0; r[1] = k.r1; r[3] = k.r3;
    r[4] = k.r4; r[5] = k.r5; r[6] = k.r6; r[15] = k.r15;
    sr = k.sr;
    kfr[0] = k.fr0; kfr[1] = k.fr1; kfr[2] = k.fr2; kfr[3] = k.fr3;
    kfr[4] = k.fr4; kfr[5] = k.fr5; kfr[6] = k.fr6; kfr[7] = k.fr7;
    for (int i = 0; i < 8; i++) fr[i] = fpu_bits_to_f32(kfr[i]);

    /* Second entry reflects the first call's FR0/r4 results. */
    fr[15] = fr[0];                                 /* 0xCC15C */
    r[4] = c148_rd32(ram, sp + 8);                  /* 0xCC160 */
    vf3_fdivker_8c03a140(r[1], r[4], r[14], r[5], r[6],
                         sp, sr, fpscr, &k, ram);     /* 0xCC15E */
    r[0] = k.r0; r[1] = k.r1; r[3] = k.r3;
    r[4] = k.r4; r[5] = k.r5; r[6] = k.r6; r[15] = k.r15;
    sr = k.sr;
    kfr[0] = k.fr0; kfr[1] = k.fr1; kfr[2] = k.fr2; kfr[3] = k.fr3;
    kfr[4] = k.fr4; kfr[5] = k.fr5; kfr[6] = k.fr6; kfr[7] = k.fr7;
    for (int i = 0; i < 8; i++) fr[i] = fpu_bits_to_f32(kfr[i]);

    /* FPU transform body, 0x8C0CC162..0x8C0CC1F0. */
    fr[4] = fr[0];
    fr[5] = c148_rdflt(ram, r[14] + 24);
    fr[3] = fr[0];
    fr[6] = fr[5];
    fr[6] = c148_mul(fr[4], fr[6], fpscr);
    fr[8] = fr[5];
    fr[8] = c148_mul(fr[15], fr[8], fpscr);
    fr[5] = c148_rdflt(ram, r[14] + 32);
    r[4] = 15;
    r[4] &= r12;
    fr[7] = c148_mul(fr[15], fr[5], fpscr);
    fr[4] = c148_mul(fr[3], fr[5], fpscr);
    r[5] = r[4] + 18;
    fr[6] = c148_sub(fr[6], fr[7], fpscr);
    fr[8] = c148_add(fr[8], fr[4], fpscr);
    c148_wrflt(ram, r[14] + 24, fr[6]);
    c148_wrflt(ram, r[14] + 32, fr[8]);
    r[0] = r[5];
    fr[4] = 1.0f;
    c148_wr16(ram, r[13] + 30, (uint16_t)r[0]);

    /* Scalar lane transform and three output vector stores. */
    fr[2] = fr[4];
    fr[3] = (float)(int32_t)r[4];
    fr[5] = fr[3];
    fr[0] = fpu_bits_to_f32(0x3C23D70Au);          /* 0xCC1A2 */
    fr[3] = c148_rdflt(ram, r[14] + 36);
    fr[2] = c148_mac(fr[0], fr[5], fr[2], fpscr);  /* 0xCC1AA */
    r[3] = c148_rd32(ram, sp);                      /* 0xCC1AC */
    r[4] = (uint8_t)r12;                             /* 0xCC1AE */
    fr[4] = c148_mul(fr[2], fr[3], fpscr);
    fr[3] = c148_rdflt(ram, r[14] + 24);
    fr[0] = fr[4];
    fr[5] = c148_rdflt(ram, r[3]);
    fr[5] = c148_mac(fr[0], fr[3], fr[5], fpscr);
    fr[3] = c148_rdflt(ram, r[3] + 8);
    fr[2] = c148_rdflt(ram, r[14] + 32);
    fr[3] = c148_mac(fr[0], fr[2], fr[3], fpscr);
    fr[4] = fr[3];
    c148_wrflt(ram, r[13], fr[5]);
    c148_wrflt(ram, r[13] + 4, c148_rdflt(ram, sp + 4));
    c148_wrflt(ram, r[13] + 8, -fr[4]);

    /* Final scale terms and epilogue. */
    fr[5] = fpu_bits_to_f32(0x39CD9A49u);          /* 0xCC1DC */
    fr[3] = (float)(int32_t)r[4];
    fr[4] = fr[3];
    fr[3] = fr[5];
    fr[5] = c148_mul(fr[3], fr[4], fpscr);
    fr[4] = fpu_bits_to_f32(0x3D8F5C28u);          /* 0xCC1EA */
    fr[3] = c148_rdflt(ram, r[14] + 24);
    fr[4] = c148_add(fr[4], fr[5], fpscr);
    sp += 12;
    pr = c148_rd32(ram, sp); sp += 4;
    fr[3] = c148_mul(fr[4], fr[3], fpscr);
    c148_wrflt(ram, r[13] + 12, fr[3]);
    fr[3] = c148_rdflt(ram, r[14] + 28);
    fr[3] = c148_mul(fr[4], fr[3], fpscr);
    c148_wrflt(ram, r[13] + 16, fr[3]);
    fr[3] = c148_rdflt(ram, r[14] + 32);
    fr[3] = c148_mul(fr[4], fr[3], fpscr);
    c148_wrflt(ram, r[13] + 20, fr[3]);
    r[0] = 20;
    fr[15] = c148_rdflt(ram, sp); sp += 4;
    r[12] = c148_rd32(ram, sp); sp += 4;
    r[13] = c148_rd32(ram, sp); sp += 4;
    r[14] = c148_rd32(ram, sp); sp += 4;           /* RTS delay slot */
    r[15] = sp;

    for (int i = 0; i < 16; i++)
        out->r[i] = r[i];
    out->pr = pr; out->sr = sr;
    for (int i = 0; i < 16; i++)
        out->fr[i] = fpu_f32_to_bits(fr[i]);
}
