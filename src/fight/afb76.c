/* See afb76.h. All traffic goes through the replay map so the test diffs
 * the shadow against the oracle exit windows. */
#include "fight/afb76.h"
#include "fight/fpucb.h"
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

static int16_t c_rd16s(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 2 <= w->base + w->len) {
            uint16_t v = 0;
            memcpy(&v, w->data + (canon - w->base), 2);
            return (int16_t)v;
        }
    }
    m->oob++;
    return 0;
}

static int8_t c_rd8s(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 1 <= w->base + w->len) {
            int8_t v = 0;
            memcpy(&v, w->data + (canon - w->base), 1);
            return v;
        }
    }
    m->oob++;
    return 0;
}

static void c_wr16(const vf3_ram_map *ram, uint32_t addr, uint16_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 2 <= w->base + w->len) {
            memcpy(w->data + (canon - w->base), &v, 2);
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

void vf3_afb76_8c0afb76(uint32_t in_r0, uint32_t in_r1, uint32_t in_r4,
                        uint32_t in_r5, uint32_t in_r15, uint32_t in_pr,
                        uint32_t in_sr, uint32_t in_fpscr, float in_fr0,
                        float in_fr1, float in_fr2, float in_fr3,
                        float in_fr4, float in_fr5, float in_fr6,
                        float in_fr7, float in_fr14, float in_fr15,
                        vf3_afb76_out *o, const vf3_ram_map *ram)
{
    uint32_t r0 = in_r0, r1 = in_r1;
    uint32_t r2 = 0, r3 = 0;
    uint32_t r4 = in_r4, r5 = in_r5, r6 = 0, r7 = 0;
    uint32_t r8 = 0, r9 = 0, r10 = 0, r11 = 0, r12 = 0, r13 = 0;
    uint32_t b = in_r4;                 /* 8c0afb64: r14 = r4 (struct) */
    uint32_t X = in_r15 - 4 - 28;       /* pr push + add #-28 */
    uint32_t sr = in_sr;
    float fr0 = in_fr0, fr1 = in_fr1;
    float fr2 = in_fr2, fr3 = in_fr3, fr4 = in_fr4, fr5 = in_fr5;
    float fr6 = in_fr6, fr7 = in_fr7;
    float fr14 = in_fr14, fr15 = in_fr15;
    int T = (in_sr & 1) != 0;

    c_wr32(ram, in_r15 - 4, in_pr);     /* 8c0afb76 sts.l pr */

#define SETT(v) do { T = (v) ? 1 : 0; } while (0)

    r2 = c_rd32(ram, b);                /* 8c0afb78 mov.l @r14,r2 */
    r3 = 0x0200u;                       /* 8c0afb7a mov.w */
    SETT((r2 & r3) == 0);               /* 8c0afb7e tst r3,r2 */
    if (T)
        goto L_b86;                     /* 8c0afb80 bt */
    goto L_eca;                         /* 8c0afb82 bra */
L_b86:
    r0 = 72;                            /* 8c0afb86 */
    r3 = 0x00020210u;                   /* 8c0afb88 */
    r4 = c_rd32(ram, b + 72);           /* 8c0afb8a */
    r6 = c_rd32(ram, r5 + 72);          /* 8c0afb8c */
    r0 = 76;                            /* 8c0afb8e */
    SETT((r4 & r3) == 0);               /* 8c0afb90 tst r4,r3 */
    r11 = c_rd32(ram, b + 76);          /* 8c0afb94 delay (always) */
    if (T)
        goto L_b9a;                     /* 8c0afb92 bt/s */
    goto L_eca;                         /* 8c0afb96 bra */
L_b9a:
    r7 = 0x08080000u;                   /* 8c0afb9a */
    r3 = r7;                            /* 8c0afb9c */
    r3 &= r4;                           /* 8c0afb9e */
    SETT(r7 == r3);                     /* 8c0afba0 cmp/eq */
    c_wr32(ram, X, r3);                 /* 8c0afba4 delay (always) */
    if (T)
        goto L_eca;                     /* 8c0afba6 bra (T==1 path) */
    goto L_baa;                         /* 8c0afba2 bf/s */
L_baa:
    r3 = 0x00008000u;                   /* 8c0afbaa */
    r3 &= r4;                           /* 8c0afbac */
    SETT(r3 == 0);                      /* 8c0afbae tst r3,r3 */
    c_wr32(ram, X, r3);                 /* 8c0afbb0 */
    r7 = 0x00800000u;                   /* 8c0afbb2 */
    r7 &= r4;                           /* 8c0afbb6 delay (always) */
    if (T)
        goto L_bcc;                     /* 8c0afbb4 bt/s (T from bae) */
    SETT(r7 == 0);                      /* 8c0afbb8 tst r7,r7 */
    if (!T)
        goto L_bcc;                     /* 8c0afbba bf */
    r3 = 0x00800000u;                   /* 8c0afbbc */
    SETT((r6 & r3) == 0);               /* 8c0afbbe tst r6,r3 */
    if (T)
        goto L_bcc;                     /* 8c0afbc0 bt */
    r2 = 0x08000000u;                   /* 8c0afbc2 */
    SETT((r6 & r2) == 0);               /* 8c0afbc4 tst r6,r2 */
    if (T)
        goto L_bcc;                     /* 8c0afbc6 bt */
    goto L_eca;                         /* 8c0afbc8 bra */
L_bcc:
    r3 = 0x00100000u;                   /* 8c0afbcc */
    SETT((r11 & r3) == 0);              /* 8c0afbce tst r11,r3 */
    if (T)
        goto L_bd6;                     /* 8c0afbd0 bt */
    goto L_eca;                         /* 8c0afbd2 bra */
L_bd6:
    r0 = 106;                           /* 8c0afbd6 */
    r3 = 0x00080000u;                   /* 8c0afbd8 */
    r13 = (uint32_t)(uint16_t)c_rd16s(ram, b + 106); /* 8c0afbda mov.w */
    r0 = 76;                            /* 8c0afbdc */
    r10 = c_rd32(ram, r5 + 76);         /* 8c0afbde */
    r3 &= r11;                          /* 8c0afbe0 */
    r9 = 0x2000u;                       /* 8c0afbe2 mov.w */
    r13 &= 0xFFFFu;                     /* 8c0afbe4 extu.w */
    r2 = r10;                           /* 8c0afbe6 */
    r12 = 0x4000u;                      /* 8c0afbe8 mov.w */
    SETT((r9 & r2) == 0);               /* 8c0afbea tst r9,r2 */
    c_wr32(ram, X + 4, r3);             /* 8c0afbee delay (always) */
    if (!T)
        goto L_c1e;                     /* 8c0afbec bf/s */
    SETT((r12 & r10) == 0);             /* 8c0afbf0 tst r12,r10 */
    if (!T)
        goto L_c1e;                     /* 8c0afbf2 bf */
    r3 = 8;                             /* 8c0afbf4 */
    SETT((r6 & r3) == 0);               /* 8c0afbf6 tst r6,r3 */
    if (!T)
        goto L_c1e;                     /* 8c0afbf8 bf */
    r2 = c_rd32(ram, X + 4);            /* 8c0afbfa */
    SETT(r2 == 0);                      /* 8c0afbfc tst r2,r2 */
    if (T)
        goto L_c1e;                     /* 8c0afbfe bt */
    r1 = r5;                            /* 8c0afc00 */
    r1 += 56;                           /* 8c0afc02 */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, r1 + 3); /* 8c0afc04 mov.b */
    r0 &= 0xFFu;                        /* 8c0afc06 extu.b */
    SETT(r0 == 18);                     /* 8c0afc08 cmp/eq #18,r0 */
    c_wr32(ram, X + 8, r0);             /* 8c0afc0c delay (always) */
    if (T)
        goto L_c1e;                     /* 8c0afc0a bt/s */
    r3 = c_rd32(ram, b);                /* 8c0afc0e */
    c_wr32(ram, X + 8, r3);             /* 8c0afc10 */
    r2 = c_rd32(ram, X + 8);            /* 8c0afc12 */
    r3 = 0x02000000u;                   /* 8c0afc14 */
    SETT((r3 & r2) == 0);               /* 8c0afc16 tst r3,r2 */
    r13 += r9;                          /* 8c0afc1a delay (always) */
    if (T)
        goto L_c1e;                     /* 8c0afc18 bt/s */
    r13 -= r12;                         /* 8c0afc1c */
L_c1e:
    r3 = 8;                             /* 8c0afc1e */
    r8 = 0x20000000u;                   /* 8c0afc20 */
    r3 &= r4;                           /* 8c0afc22 */
    SETT(r3 == 0);                      /* 8c0afc24 tst r3,r3 */
    c_wr32(ram, X + 24, r3);            /* 8c0afc28 delay (always) */
    if (T)
        goto L_c74;                     /* 8c0afc26 bt/s */
    SETT(r7 == 0);                      /* 8c0afc2a tst r7,r7 */
    if (T)
        goto L_c32;                     /* 8c0afc2c bt */
    goto L_de6;                         /* 8c0afc2e bra */
L_c32:
    r0 = 0x8C0AFC70u;                   /* 8c0afc32 mova */
    fr3 = c_rdflt(ram, r0);             /* 8c0afc34 fmov.s @r0,fr3 */
    r0 = 92;                            /* 8c0afc36 */
    fr2 = c_rdflt(ram, b + 92);         /* 8c0afc38 fmov.s @(r0,r14),fr2 */
    SETT(fr3 > fr2);                    /* 8c0afc3a fcmp/gt fr2,fr3 */
    if (!T)
        goto L_e42;                     /* 8c0afc3c bf */
    goto L_e04;                         /* 8c0afc3e bra */
L_e42:
    goto L_e3c;                         /* 8c0afc42 bra */
L_c74:
    r2 = 1;                             /* 8c0afc74 */
    r10 = 0x40000000u;                  /* 8c0afc76 */
    SETT((r11 & r2) == 0);              /* 8c0afc78 tst r11,r2 */
    r10 &= r4;                          /* 8c0afc7c delay (always) */
    if (T)
        goto L_c8a;                     /* 8c0afc7a bt/s */
    SETT(r7 == 0);                      /* 8c0afc7e tst r7,r7 */
    if (T)
        goto L_c8a;                     /* 8c0afc80 bt */
    SETT(r10 == 0);                     /* 8c0afc82 tst r10,r10 */
    if (T)
        goto L_c8a;                     /* 8c0afc84 bt */
    goto L_e04;                         /* 8c0afc86 bra */
L_c8a:
    r3 = 0x00040000u;                   /* 8c0afc8a */
    r3 &= r4;                           /* 8c0afc8c */
    SETT(r3 == 0);                      /* 8c0afc8e tst r3,r3 */
    c_wr32(ram, X + 8, r3);             /* 8c0afc92 delay (always) */
    if (T)
        goto L_c98;                     /* 8c0afc90 bt/s */
    goto L_de6;                         /* 8c0afc94 bra */
L_c98:
    r2 = 0x00200000u;                   /* 8c0afc98 */
    r2 &= r4;                           /* 8c0afc9a */
    SETT(r2 == 0);                      /* 8c0afc9c tst r2,r2 */
    c_wr32(ram, X + 20, r2);            /* 8c0afca0 delay (always) */
    if (T)
        goto L_ca6;                     /* 8c0afc9e bt/s */
    goto L_e04;                         /* 8c0afca2 bra */
L_ca6:
    r3 = 0x00040000u;                   /* 8c0afca6 */
    SETT((r3 & r11) == 0);              /* 8c0afca8 tst r3,r11 */
    if (T)
        goto L_cb0;                     /* 8c0afcaa bt */
    goto L_e04;                         /* 8c0afcac bra */
L_cb0:
    r0 = 76;                            /* 8c0afcb0 */
    r11 = c_rd32(ram, r5 + 76);         /* 8c0afcb2 */
    r0 = 0x1A04u;                       /* 8c0afcb4 mov.w */
    r0 = c_rd32(ram, r5 + r0);          /* 8c0afcb6 */
    SETT((r0 & 8) == 0);                /* 8c0afcb8 tst #8,r0 */
    if (!T)
        goto L_cc6;                     /* 8c0afcba bf */
    r3 = r11;                           /* 8c0afcbc */
    SETT((r12 & r3) == 0);              /* 8c0afcbe tst r12,r3 */
    if (!T)
        goto L_cc6;                     /* 8c0afcc0 bf */
    SETT((r9 & r11) == 0);              /* 8c0afcc2 tst r9,r11 */
    if (T)
        goto L_d02;                     /* 8c0afcc4 bt */
L_cc6:
    r3 = c_rd32(ram, X + 4);            /* 8c0afcc6 */
    SETT(r3 == 0);                      /* 8c0afcc8 tst r3,r3 */
    if (T)
        goto L_cd0;                     /* 8c0afcca bt */
    goto L_e3c;                         /* 8c0afccc bra */
L_cd0:
    r2 = c_rd32(ram, X + 8);            /* 8c0afcd0 */
    SETT(r2 == 0);                      /* 8c0afcd2 tst r2,r2 */
    if (T)
        goto L_cda;                     /* 8c0afcd4 bt */
    goto L_e04;                         /* 8c0afcd6 bra */
L_cda:
    r2 = c_rd32(ram, X + 20);           /* 8c0afcda */
    SETT(r2 == 0);                      /* 8c0afcdc tst r2,r2 */
    if (T)
        goto L_ce4;                     /* 8c0afcde bt */
    goto L_e04;                         /* 8c0afce0 bra */
L_ce4:
    r2 = c_rd32(ram, X + 24);           /* 8c0afce4 */
    SETT(r2 == 0);                      /* 8c0afce6 tst r2,r2 */
    if (T)
        goto L_cee;                     /* 8c0afce8 bt */
    goto L_eca;                         /* 8c0afcea bra */
L_cee:
    SETT(r7 == 0);                      /* 8c0afcee tst r7,r7 */
    if (T)
        goto L_cf6;                     /* 8c0afcf0 bt */
    goto L_eca;                         /* 8c0afcf2 bra */
L_cf6:
    r0 = 0x226Cu;                       /* 8c0afcf6 mov.w */
    r2 = (uint32_t)(int32_t)c_rd16s(ram, r5 + r0); /* 8c0afcf8 mov.w */
    SETT((int32_t)r2 > 0);              /* 8c0afcfa cmp/pl r2 */
    if (!T)
        goto L_d02;                     /* 8c0afcfc bf */
    goto L_eca;                         /* 8c0afcfe bra */
L_d02:
    SETT((r4 & r9) == 0);               /* 8c0afd02 tst r4,r9 */
    if (T)
        goto L_d0e;                     /* 8c0afd04 bt */
    SETT(r10 == 0);                     /* 8c0afd06 tst r10,r10 */
    if (!T)
        goto L_dda;                     /* 8c0afd08 bf */
    goto L_eca;                         /* 8c0afd0a bra */
L_d0e:
    r11 = 0x00010000u;                  /* 8c0afd0e */
    r11 &= r4;                          /* 8c0afd10 */
    SETT(r11 == 0);                     /* 8c0afd12 tst r11,r11 */
    if (T)
        goto L_d1e;                     /* 8c0afd14 bt */
    SETT(r7 == 0);                      /* 8c0afd16 tst r7,r7 */
    if (T)
        goto L_d1e;                     /* 8c0afd18 bt */
    goto L_e04;                         /* 8c0afd1a bra */
L_d1e:
    r2 = r4;                            /* 8c0afd1e */
    SETT((r8 & r2) == 0);               /* 8c0afd20 tst r8,r2 */
    r9 = r4;                            /* 8c0afd22 */
    r9 &= r12;                          /* 8c0afd26 delay (always) */
    if (T)
        goto L_d6c;                     /* 8c0afd24 bt/s */
    r3 = 0x08000000u;                   /* 8c0afd28 */
    SETT((r4 & r3) == 0);               /* 8c0afd2a tst r4,r3 */
    if (T)
        goto L_d32;                     /* 8c0afd2c bt */
    goto L_eca;                         /* 8c0afd2e bra */
L_d32:
    SETT(r9 == 0);                      /* 8c0afd32 tst r9,r9 */
    if (!T)
        goto L_e04;                     /* 8c0afd34 bf */
    r2 = c_rd32(ram, X);                /* 8c0afd36 */
    SETT(r2 == 0);                      /* 8c0afd38 tst r2,r2 */
    if (T)
        goto L_d40;                     /* 8c0afd3a bt */
    goto L_eca;                         /* 8c0afd3c bra */
L_d40:
    r1 = 0x00020000u;                   /* 8c0afd40 */
    SETT((r1 & r4) == 0);               /* 8c0afd42 tst r1,r4 */
    if (T)
        goto L_d4a;                     /* 8c0afd44 bt */
    goto L_eca;                         /* 8c0afd46 bra */
L_d4a:
    goto L_e04;                         /* 8c0afd4a bra */
L_d6c:
    r2 = r4 & 0x40880000u;              /* 8c0afd6c */
    c_wr32(ram, X, r2);                 /* 8c0afd70 */
    r3 = 0x40080000u;                   /* 8c0afd72 */
    r1 = r3;                            /* 8c0afd74 */
    SETT(r1 == r2);                     /* 8c0afd76 cmp/eq r1,r2 */
    c_wr32(ram, X + 4, r3);             /* 8c0afd78 */
    if (T)
        goto L_de6;                     /* 8c0afd7a bt */
    SETT(r9 == 0);                      /* 8c0afd7c tst r9,r9 */
    if (T)
        goto L_d86;                     /* 8c0afd7e bt */
    r2 = r4;                            /* 8c0afd80 */
    SETT((r8 & r2) == 0);               /* 8c0afd82 tst r8,r2 */
    if (T)
        goto L_de6;                     /* 8c0afd84 bt */
L_d86:
    r3 = 0x08020000u;                   /* 8c0afd86 */
    r2 = r3;                            /* 8c0afd88 */
    c_wr32(ram, X, r3);                 /* 8c0afd8a */
    r2 &= r6;                           /* 8c0afd8c */
    c_wr32(ram, X + 4, r2);             /* 8c0afd8e */
    r3 = c_rd32(ram, X);                /* 8c0afd90 */
    SETT(r3 == r2);                     /* 8c0afd92 cmp/eq r3,r2 */
    if (T)
        goto L_e04;                     /* 8c0afd94 bt */
    SETT(r10 == 0);                     /* 8c0afd96 tst r10,r10 */
    if (T)
        goto L_dcc;                     /* 8c0afd98 bt */
    SETT(r7 == 0);                      /* 8c0afd9a tst r7,r7 */
    if (!T)
        goto L_da2;                     /* 8c0afd9c bf */
    goto L_eca;                         /* 8c0afd9e bra */
L_da2:
    r0 = 0x1938u;                       /* 8c0afda2 mov.w */
    r3 = 0x80000000u;                   /* 8c0afda4 */
    r2 = c_rd32(ram, b + r0);           /* 8c0afda6 */
    SETT((r3 & r2) == 0);               /* 8c0afda8 tst r3,r2 */
    if (T)
        goto L_e3c;                     /* 8c0afdaa bt */
    r0 = 0x226Cu;                       /* 8c0afdac mov.w */
    r1 = (uint32_t)(int32_t)c_rd16s(ram, r5 + r0); /* 8c0afdae mov.w */
    SETT((int32_t)r1 > 0);              /* 8c0afdb0 cmp/pl r1 */
    if (!T)
        goto L_db8;                     /* 8c0afdb2 bf */
    goto L_eca;                         /* 8c0afdb4 bra */
L_db8:
    r3 = r6;                            /* 8c0afdb8 */
    SETT((r8 & r3) == 0);               /* 8c0afdba tst r8,r3 */
    if (!T)
        goto L_de6;                     /* 8c0afdbc bf */
    SETT((r6 & r12) == 0);              /* 8c0afdbe tst r6,r12 */
    if (!T)
        goto L_de6;                     /* 8c0afdc0 bf */
    r3 = 0x00020000u;                   /* 8c0afdc2 */
    SETT((r6 & r3) == 0);               /* 8c0afdc4 tst r6,r3 */
    if (!T)
        goto L_de6;                     /* 8c0afdc6 bf */
    goto L_e04;                         /* 8c0afdc8 bra */
L_dcc:
    SETT(r11 == 0);                     /* 8c0afdcc tst r11,r11 */
    if (!T)
        goto L_de6;                     /* 8c0afdce bf */
    r1 = 2;                             /* 8c0afdd0 */
    SETT((r1 & r4) == 0);               /* 8c0afdd2 tst r1,r4 */
    if (!T)
        goto L_df0;                     /* 8c0afdd4 bf */
    goto L_eca;                         /* 8c0afdd6 bra */
L_dda:
    r0 = (uint32_t)(uint16_t)c_rd16s(ram, b + 30); /* 8c0afdda mov.w */
    r4 = r0 & 0xFFFFu;                  /* 8c0afddc extu.w */
    r0 = (uint32_t)(uint16_t)c_rd16s(ram, r5 + 30); /* 8c0afdde mov.w */
    r6 = r0 & 0xFFFFu;                  /* 8c0afde0 extu.w */
    r5 = r6;                            /* 8c0afde4 delay (always) */
    goto L_e0c;                         /* 8c0afde2 bra */
L_de6:
    r2 = 0x00010000u;                   /* 8c0afde6 */
    SETT((r2 & r6) == 0);               /* 8c0afde8 tst r2,r6 */
    if (T)
        goto L_e04;                     /* 8c0afdea bt */
    r4 = 91;                            /* 8c0afdee delay (always) */
    goto L_df2;                         /* 8c0afdec bra */
L_df0:
    r4 = 0x016Cu;                       /* 8c0afdf0 mov.w */
L_df2:
    r0 = 0x1394u;                       /* 8c0afdf2 mov.w */
    r3 = r13;                           /* 8c0afdf4 */
    r6 = 0x2AA8u;                       /* 8c0afdf6 mov.w */
    r5 = (uint32_t)(uint16_t)c_rd16s(ram, b + r0); /* 8c0afdf8 mov.w */
    r5 &= 0xFFFFu;                      /* 8c0afdfa extu.w */
    r3 -= r5;                           /* 8c0afdfc */
    r5 = r3;                            /* 8c0afdf e */
    r7 = 1;                             /* 8c0afe02 delay (always) */
    goto L_e4c;                         /* 8c0afe00 bra */
L_e04:
    r0 = 0x1394u;                       /* 8c0afe04 mov.w */
    r5 = r13;                           /* 8c0afe06 */
    r4 = (uint32_t)(uint16_t)c_rd16s(ram, b + r0); /* 8c0afe08 mov.w */
    r4 &= 0xFFFFu;                      /* 8c0afe0a extu.w */
L_e0c:
    r5 -= r4;                           /* 8c0afe0c */
    r4 = 0x038Eu;                       /* 8c0afe0e mov.w */
    r6 = 0x5FFAu;                       /* 8c0afe10 mov.w */
    r7 = 0;                             /* 8c0afe14 delay (always) */
    goto L_e4c;                         /* 8c0afe12 bra */
L_e3c:
    r0 = 0x1394u;                       /* 8c0afe3c mov.w */
    r5 = r13;                           /* 8c0afe3e */
    r7 = 0;                             /* 8c0afe40 */
    r4 = (uint32_t)(uint16_t)c_rd16s(ram, b + r0); /* 8c0afe42 mov.w */
    r4 &= 0xFFFFu;                      /* 8c0afe44 extu.w */
    r5 -= r4;                           /* 8c0afe46 */
    r4 = 0x3FFCu;                       /* 8c0afe48 mov.w */
    r6 = r4;                            /* 8c0afe4a */
L_e4c:
    r13 = (uint32_t)(int32_t)(int16_t)(uint16_t)r5; /* 8c0afe4c exts.w */
    r5 = (uint32_t)(0u - r6);           /* 8c0afe4e neg r6,r5 */
    SETT((int32_t)r13 >= (int32_t)r5);  /* 8c0afe50 cmp/ge r5,r13 */
    if (!T)
        goto L_e58;                     /* 8c0afe52 bf */
    SETT((int32_t)r13 > (int32_t)r6);   /* 8c0afe54 cmp/gt r6,r13 */
    if (!T)
        goto L_e62;                     /* 8c0afe56 bf */
L_e58:
    SETT(r7 == 0);                      /* 8c0afe58 tst r7,r7 */
    if (!T)
        goto L_eca;                     /* 8c0afe5a bf */
    r3 = 0x00008000u;                   /* 8c0afe5c */
    r13 ^= r3;                          /* 8c0afe5e xor r3,r13 */
    r13 = (uint32_t)(int32_t)(int16_t)(uint16_t)r13; /* 8c0afe60 exts.w */
L_e62:
    r5 = (uint32_t)(0u - r4);           /* 8c0afe62 neg r4,r5 */
    SETT((int32_t)r13 >= (int32_t)r5);  /* 8c0afe64 cmp/ge r5,r13 */
    if (T)
        goto L_e6c;                     /* 8c0afe66 bt */
    r13 = r5;                           /* 8c0afe6a delay (always) */
    goto L_e72;                         /* 8c0afe68 bra */
L_e6c:
    SETT((int32_t)r13 > (int32_t)r4);   /* 8c0afe6c cmp/gt r4,r13 */
    if (!T)
        goto L_e72;                     /* 8c0afe6e bf */
    r13 = r4;                           /* 8c0afe70 */
L_e72:
    r3 = c_rd32(ram, b);                /* 8c0afe72 mov.l @r14,r3 */
    SETT((r3 & r8) == 0);               /* 8c0afe74 tst r3,r8 */
    if (T)
        goto L_e82;                     /* 8c0afe76 bt */
    r0 = 0x1A2Du;                       /* 8c0afe78 mov.w */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, b + r0); /* 8c0afe7a mov.b */
    r0 &= 0xFFu;                        /* 8c0afe7c extu.b */
    SETT((r0 & 1) == 0);                /* 8c0afe7e tst #1,r0 */
    if (!T)
        goto L_ec4;                     /* 8c0afe80 bf */
L_e82:
    r0 = 0x0430u;                       /* 8c0afe3c mov.w */
    r5 = X + 16;                        /* 8c0afe84/88 mov r15,r5 + add */
    r6 = X;                             /* 8c0afe86 mov r15,r6 */
    fr14 = c_rdflt(ram, b + r0);        /* 8c0afe8a */
    r0 += 8;                            /* 8c0afe8c */
    fr15 = c_rdflt(ram, b + r0);        /* 8c0afe8e */
    r0 = 16;                            /* 8c0afe90 */
    fr5 = c_rdflt(ram, b + 16);         /* 8c0afe92 */
    r0 = 24;                            /* 8c0afe94 */
    fr4 = c_rdflt(ram, b + 24);         /* 8c0afe96 */
    r0 = 16;                            /* 8c0afe98 */
    fr5 = fpu_dn_fix(fsub_tz(fr5, fr14), in_fpscr); /* 8c0afe9a */
    r6 += 12;                           /* 8c0afe9c -> X+12 */
    fr4 = fpu_dn_fix(fsub_tz(fr4, fr15), in_fpscr); /* 8c0afe9e */
    c_wrflt(ram, X + 16, fr5);          /* 8c0afea0 */
    r0 = 12;                            /* 8c0afea2 */
    c_wrflt(ram, X + 12, fr4);          /* 8c0afea4 */
    r3 = 0x0C09553Cu;                   /* 8c0afea6 */
    { /* 8c0afea8 jsr @r3 (delay: r4 = r13, pre-call) */
        vf3_fpucb_out u2;
        uint32_t u2r4 = r13;
        uint32_t u2sr = (sr & ~1u) | (T ? 1u : 0u);
        memset(&u2, 0, sizeof(u2));
        vf3_fpucb_8c09553c(r1, u2r4, X + 16, X + 12, b, X, 0x0C0AFEACu,
                           u2sr, in_fpscr, fr15, &u2, ram);
        r0 = u2.r0; r1 = u2.r1; r2 = u2.r2; r3 = u2.r3;
        r4 = u2.r4; r5 = u2.r5; r6 = u2.r6;
        sr = u2.sr; SETT(sr & 1);
        fr0 = bits_f(u2.fr0); fr1 = bits_f(u2.fr1);
        fr2 = bits_f(u2.fr2); fr3 = bits_f(u2.fr3);
        fr6 = bits_f(u2.fr6); fr7 = bits_f(u2.fr7);
        fr15 = bits_f(u2.fr15);
    }
    r0 = 16;                            /* 8c0afeac */
    fr4 = fr14;                         /* 8c0afeae fmov fr14,fr4 */
    fr3 = c_rdflt(ram, X + 16);         /* 8c0afeb0 */
    r0 = 12;                            /* 8c0afeb2 */
    fr2 = c_rdflt(ram, X + 12);         /* 8c0afeb4 */
    r0 = 16;                            /* 8c0afeb6 */
    fr4 = fpu_dn_fix(fadd_tz(fr4, fr3), in_fpscr); /* 8c0afeb8 */
    fr5 = fr15;                         /* 8c0afeba fmov fr15,fr5 */
    fr5 = fpu_dn_fix(fadd_tz(fr5, fr2), in_fpscr); /* 8c0afebc */
    c_wrflt(ram, b + 16, fr4);          /* 8c0afebe */
    r0 = 24;                            /* 8c0afec0 */
    c_wrflt(ram, b + 24, fr5);          /* 8c0afec2 */
L_ec4:
    r0 = (uint32_t)(int32_t)c_rd16s(ram, b + 30); /* 8c0afec4 mov.w */
    r0 += r13;                          /* 8c0afec6 */
    c_wr16(ram, b + 30, (uint16_t)r0);  /* 8c0afec8 */
L_eca:
    /* 8c0afeca add #28,r15; pr/fr14/fr15/r8-r14 restore; rts. The pops
     * read the B62-B74 saves, so r8-r14/fr14/fr15/pr are passthrough. */
    o->r0 = r0;
    o->r1 = r1;
    o->r2 = r2;
    o->r3 = r3;
    o->r4 = r4;
    o->r5 = r5;
    o->r6 = r6;
    o->r7 = r7;
    o->r15 = in_r15 + 36;   /* 8c0afeca epilogue: +28 then 10 pops */
    o->fr0 = fpu_f32_to_bits(fr0);
    o->fr1 = fpu_f32_to_bits(fr1);
    o->fr2 = fpu_f32_to_bits(fr2);
    o->fr3 = fpu_f32_to_bits(fr3);
    o->fr4 = fpu_f32_to_bits(fr4);
    o->fr5 = fpu_f32_to_bits(fr5);
    o->fr6 = fpu_f32_to_bits(fr6);
    o->fr7 = fpu_f32_to_bits(fr7);
    o->sr = (sr & ~1u) | (T ? 1u : 0u);
}

#undef SETT