/* See fpucb.h. Nested U1 calls go to the oracle-verified fdivker port;
 * all traffic goes through the replay map so the test diffs the shadow
 * against the oracle exit windows. */
#include "fight/fpucb.h"
#include "fight/fdivker.h"
#include "fight/fpu_tz.h"

#include <string.h>

static uint32_t c_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            uint32_t v = 0;
            memcpy(&v, w->data + (canon - w->base), 4);
            return v;
        }
    }
    m->oob++;
    return 0;
}

static void c_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            memcpy(w->data + (canon - w->base), &v, 4);
            return;
        }
    }
    m->oob++;
}

static float c_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t bits = c_rd32(ram, addr);
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

static void c_wrflt(const vf3_ram_map *ram, uint32_t addr, float f)
{
    uint32_t bits;
    memcpy(&bits, &f, 4);
    c_wr32(ram, addr, bits);
}

static float bits_f(uint32_t b)
{
    float f;
    memcpy(&f, &b, 4);
    return f;
}

/* U2 callee targets (literals at 0x8C0956F0/0x8C0956F4, 0x0C alias =
 * same bytes): U1 entries. r2val selects per the oracle. */
void vf3_fpucb_8c09553c(uint32_t in_r1, uint32_t in_r4, uint32_t in_r5,
                        uint32_t in_r6, uint32_t in_r14, uint32_t in_r15,
                        uint32_t in_pr, uint32_t in_sr, uint32_t in_fpscr,
                        float in_fr15, vf3_fpucb_out *o,
                        const vf3_ram_map *ram)
{
    uint32_t X, F, r4;
    uint32_t r2, r3;
    float fr0, fr4, fr5, fr6, fr7, fr15x, fr15save;
    vf3_fdivker_out o1, o2;
    uint32_t fr15bits, pr;

    memcpy(&fr15bits, &in_fr15, 4);
    X = in_r15 - 4;                       /* 8c09553c spill fr15 */
    c_wr32(ram, X, fr15bits);
    X -= 4;                               /* 8c09553e sts.l pr */
    c_wr32(ram, X, in_pr);
    F = X - 16;                           /* 8c095540 frame */
    c_wr32(ram, F + 8, in_r4);            /* 8c095542 */
    c_wr32(ram, F, in_r5);                /* 8c095544 */
    c_wr32(ram, F + 4, in_r6);            /* 8c095546 */
    r4 = c_rd32(ram, F + 8);              /* 8c095548 */
    r4 = (uint32_t)(int32_t)(int16_t)(uint16_t)r4; /* 8c09554c exts.w */
    c_wr32(ram, F + 12, r4);              /* 8c095550 delay (pre-call) */
    /* 8c09554e jsr U1-6E0 */
    memset(&o1, 0, sizeof(o1));
    vf3_fdivker_8c03a6e0(in_r1, r4, in_r5, in_r6, F, in_sr, in_fpscr,
                         &o1, ram);
    fr15save = bits_f(o1.fr0);            /* 8c095554 delay reads o1.fr0 */
    r4 = c_rd32(ram, F + 12);             /* 8c095558 delay (pre-call) */
    /* 8c095556 jsr U1-140 */
    memset(&o2, 0, sizeof(o2));
    vf3_fdivker_8c03a140(o1.r1, r4, in_r14, o1.r5, o1.r6, F, o1.sr,
                         in_fpscr, &o2, ram);
    r2 = c_rd32(ram, F);                  /* 8c09555a */
    fr7 = bits_f(o2.fr0);                 /* 8c09555c */
    fr6 = c_rdflt(ram, r2);               /* 8c09555e */
    r3 = c_rd32(ram, F + 4);              /* 8c095560 */
    fr7 = fpu_dn_fix(fmul_tz(fr6, fr7), in_fpscr);   /* 8c095562 */
    fr4 = bits_f(o2.fr0);                 /* 8c095564 */
    fr5 = c_rdflt(ram, r3);               /* 8c095566 */
    r3 = r2;                              /* 8c095568 */
    fr0 = fr5;                            /* 8c09556a */
    fr4 = fpu_dn_fix(fmul_tz(fr5, fr4), in_fpscr);   /* 8c09556c */
    fr7 = fpu_dn_fix(fmac_tz(fr0, fr15save, fr7), in_fpscr); /* 8c09556e */
    fr15x = fpu_dn_fix(fmul_tz(fr6, fr15save), in_fpscr);    /* 8c095570 */
    fr5 = fr7;                            /* 8c095572 */
    c_wrflt(ram, r3, fr5);                /* 8c095574 [entry r5] = fr5 */
    fr4 = fpu_dn_fix(fsub_tz(fr4, fr15x), in_fpscr); /* 8c095576 */
    r3 = c_rd32(ram, F + 4);              /* 8c095578 */
    c_wrflt(ram, r3, fr4);                /* 8c09557e [entry r6] = fr4 */
    /* 8c09557a r15 = X; 8c09557c pr restore; 8c095580 rts +
     * 8c095582 delay fr15 round-trip. */
    pr = c_rd32(ram, X);
    (void)pr;                             /* == in_pr; test forces pr */
    {
        float fr15r = c_rdflt(ram, X + 4);
        uint32_t b;
        memcpy(&b, &fr15r, 4);
        o->fr15 = b;
    }

    o->r0 = o2.r0;
    o->r1 = o2.r1;
    o->r2 = in_r5;
    o->r3 = in_r6;
    o->r4 = o2.r4;
    o->r5 = o2.r5;
    o->r6 = o2.r6;
    o->r15 = in_r15;
    o->fr0 = fpu_f32_to_bits(fr0);
    o->fr1 = o2.fr1;
    o->fr2 = o2.fr2;
    o->fr3 = o2.fr3;
    o->fr4 = fpu_f32_to_bits(fr4);
    o->fr5 = fpu_f32_to_bits(fr5);
    o->fr6 = fpu_f32_to_bits(fr6);
    o->fr7 = fpu_f32_to_bits(fr7);
    o->sr = o2.sr;
}
