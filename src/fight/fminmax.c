/* See fminmax.h. All traffic goes through the replay map so the test
 * diffs the shadow against the oracle exit windows. */
#include "fight/fminmax.h"
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

static float bits_f(uint32_t b)
{
    float f;
    memcpy(&f, &b, 4);
    return f;
}

static float c_rdflt(const vf3_ram_map *ram, uint32_t addr){
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

void vf3_fminmax_8c073fb4(uint32_t in_r1, uint32_t in_r3, uint32_t in_r4,
                          uint32_t in_r7, uint32_t in_r12, uint32_t in_r14,
                          uint32_t in_r15, uint32_t in_pr,
                          uint32_t in_sr, uint32_t in_fpscr, float in_fr4,
                          vf3_fminmax_out *o, const vf3_ram_map *ram)
{
    uint32_t r0 = 0, r1 = in_r1, r3 = in_r3, r5 = 0, r7 = in_r7;
    uint32_t r6 = 0;                    /* 8c073fb6 mov #0,r6 */
    uint32_t r12 = 0, r14 = 0;
    uint32_t b = in_r4;
    uint32_t sr = in_sr;
    float fr3 = 0.0f, fr4 = in_fr4, fr5 = 0.0f, fr6 = 0.0f, fr7 = 0.0f;
    float fr8 = 0.0f, fr9 = 0.0f, fr10 = 0.0f;
    int T = (in_sr & 1) != 0;

    (void)in_pr;
    c_wr32(ram, in_r15 - 4, in_r14);    /* 8c073fb4 mov.l r14,@-r15 */
    c_wr32(ram, in_r15 - 8, in_r12);    /* 8c073fb8 mov.l r12,@-r15 */

#define SETT(v) do { T = (v) ? 1 : 0; } while (0)
    (void)sr;

    fr6 = c_rdflt(ram, b + 0x430);      /* 8c073fbc */
    fr8 = c_rdflt(ram, b + 0x438);      /* 8c073fc0 */
    fr9 = c_rdflt(ram, b + 16);         /* 8c073fc4 */
    fr10 = c_rdflt(ram, b + 24);        /* 8c073fc8 */
    fr7 = bits_f(0x41580000u);          /* 8c073fcc mova/fmov (pool) */
    fr5 = bits_f(0xC1580000u);          /* 8c073fce mova (pool -13.5) */
    SETT(fr6 > fr7);                    /* 8c073fd0 fcmp/gt fr7,fr6 */
    fr5 = bits_f(0xC1580000u);          /* 8c073fd4 delay (always) */
    if (!T)
        goto L_fdc;                     /* 8c073fd2 bf/s */
    fr4 = fr6;                          /* 8c073fd6 */
    fr4 = fpu_dn_fix(fadd_tz(fr4, fr5), in_fpscr); /* 8c073fda delay */
    goto L_fe4;                         /* 8c073fd8 bra */
L_fdc:
    SETT(fr5 > fr6);                    /* 8c073fdc fcmp/gt fr6,fr5 */
    if (!T)
        goto L_ff0;                     /* 8c073fde bf */
    fr4 = fr6;                          /* 8c073fe0 */
    fr4 = fpu_dn_fix(fadd_tz(fr4, fr7), in_fpscr); /* 8c073fe2 */
L_fe4:
    fr9 = fpu_dn_fix(fsub_tz(fr9, fr4), in_fpscr); /* 8c073fe4 */
    fr6 = fpu_dn_fix(fsub_tz(fr6, fr4), in_fpscr); /* 8c073fe8 */
    c_wrflt(ram, b + 16, fr9);          /* 8c073fea */
    r0 = 0x430u;                        /* 8c073fec mov.w */
    c_wrflt(ram, b + r0, fr6);          /* 8c073fee */
L_ff0:
    SETT(fr8 > fr7);                    /* 8c073ff0 fcmp/gt fr7,fr8 */
    if (!T)
        goto L_4014;                    /* 8c073ff2 bf */
    fr4 = fr8;                          /* 8c073ff4 */
    fr4 = fpu_dn_fix(fadd_tz(fr4, fr5), in_fpscr); /* 8c073ff8 delay */
    goto L_4018;                        /* 8c073ff6 bra */
L_4014:
    SETT(fr5 > fr8);                    /* 8c073ff0+: fcmp/gt fr8,fr5 */
    if (!T)
        goto L_4024;                    /* 8c073ff2+16 bf */
L_4018:
    fr10 = fpu_dn_fix(fsub_tz(fr10, fr4), in_fpscr); /* 8c074018 */
    fr8 = fpu_dn_fix(fsub_tz(fr8, fr4), in_fpscr);   /* 8c07401c */
    c_wrflt(ram, b + 24, fr10);         /* 8c07401e */
    r0 = 0x438u;                        /* 8c074020 mov.w */
    c_wrflt(ram, b + r0, fr8);          /* 8c074022 */
L_4024:
    r0 = c_rd32(ram, b + 0x1890);       /* 8c074024 */
    r0 &= 36u;                          /* 8c074028 */
    r5 = r0;                            /* 8c07402a */
    SETT(r5 == 0);                      /* 8c07402c tst r5,r5 */
    if (T)
        goto L_4034;                    /* 8c07402e bt */
    goto L_4138;                        /* 8c074030 bra (gate nonzero) */
L_4034:
    r3 = 0x0C29B880u;                   /* 8c074034 mov.l pool value */
    r12 = 15;                           /* 8c074036 */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, r3); /* 8c074038 mov.b */
    r0 &= 0xFFu;                        /* 8c07403a extu.b */
    r12 &= r0;                          /* 8c07403c */
    r12 <<= 1;                          /* 8c07403e shll */
    r7 = r6;                            /* 8c074042 delay (always) */
    goto L_4132;                        /* 8c074040 bra */
L_4132:
    r5 = 2;                             /* 8c074132 */
    SETT(r7 >= r5);                     /* 8c074134 cmp/hs r5,r7 */
    if (!T)
        goto L_4044;                    /* 8c074136 bf */
    goto L_4138;
L_4044:
    r5 = r12;                           /* 8c074044 */    r5 += r7;                           /* 8c074046 */
    r5 <<= 2;                           /* 8c074048 shll2 */
    r1 = 0x0C0F3418u;                   /* 8c07404a mov.l pool value */
    r5 <<= 1;                           /* 8c07404c shll */
    fr4 = 0.0f;                         /* 8c07404e fldi0 */
    r5 += r1;                           /* 8c074050 */
    r3 = c_rd32(ram, r5);               /* 8c074052 */
    r14 = 7;                            /* 8c074054 */
    r0 = 4;                             /* 8c074056 */
    r14 &= r3;                          /* 8c074058 */
    SETT(r14 == 0);                     /* 8c07405a tst r14,r14 */
    fr5 = c_rdflt(ram, r5 + 4);         /* 8c07405e delay (always) */
    if (T)
        goto L_4130;                    /* 8c07405c bt/s */
    r0 = r14;                           /* 8c074060 */
    SETT(r0 == 2);                      /* 8c074062 cmp/eq #2 */
    r5 = 28;                            /* 8c074066 delay (always) */
    if (T)
        goto L_40c8;                    /* 8c074064 bt/s */
    r0 = r14;                           /* 8c074068 */
    SETT(r0 == 3);                      /* 8c07406a cmp/eq #3 */
    if (T)
        goto L_4098;                    /* 8c07406c bt */
    r1 = 3;                             /* 8c07406e */
    SETT(r14 > r1);                     /* 8c074070 cmp/hi r1,r14 */
    if (T)
        goto L_40ee;                    /* 8c074072 bt */
    r0 = 0x138Cu;                       /* 8c074074 mov.w */
    r14 = c_rd32(ram, b + r0);          /* 8c074076 */
    r1 = r6;                            /* 8c07407a delay (always) */
    goto L_408e;                        /* 8c074078 bra */
L_408e:
    SETT(r1 >= r5);                     /* 8c07408e cmp/hs r5,r1 */
    if (!T)
        goto L_407c;                    /* 8c074090 bf */
    goto L_4092;
L_407c:
    fr7 = c_rdflt(ram, r14);            /* 8c07407c */
    SETT(fr5 > fr7);                    /* 8c07407e fcmp/gt fr7,fr5 */
    if (T)
        goto L_408a;                    /* 8c074080 bt */
    fr7 = fpu_dn_fix(fsub_tz(fr7, fr5), in_fpscr); /* 8c074082 */
    SETT(fr7 > fr4);                    /* 8c074084 fcmp/gt fr4,fr7 */
    if (!T)
        goto L_408a;                    /* 8c074086 bf */
    fr4 = fr7;                          /* 8c074088 */
L_408a:
    r14 += 12;                          /* 8c07408a */
    r1 += 1;                            /* 8c07408c */
    goto L_408e;                        /* 8c074090-ish loop */
L_4092:
    fr9 = fpu_dn_fix(fsub_tz(fr9, fr4), in_fpscr); /* 8c074092 */
    fr6 = fpu_dn_fix(fsub_tz(fr6, fr4), in_fpscr); /* 8c074096 delay */
    goto L_40be;                        /* 8c074094 bra */
L_40be:
    r0 = 16;                            /* 8c0740be */
    c_wrflt(ram, b + 16, fr9);          /* 8c0740c0 */
    r0 = 0x430u;                        /* 8c0740c2 mov.w */
    c_wrflt(ram, b + r0, fr6);          /* 8c0740c6 delay */
    goto L_4130;                        /* 8c0740c4 bra */
L_4098:
    r0 = 0x138Cu;                       /* 8c074098 mov.w */
    r1 = c_rd32(ram, b + r0);           /* 8c07409a */
    r14 = r6;                           /* 8c07409e delay (always) */
    goto L_40b6;                        /* 8c07409c bra */
L_40b6:
    SETT(r14 >= r5);                    /* 8c0740b6 cmp/hs r5,r14 */
    if (!T)
        goto L_40a0;                    /* 8c0740b8 bf */
    goto L_40ba;
L_40a0:
    fr7 = c_rdflt(ram, r1);             /* 8c0740a0 */
    SETT(fr7 > fr5);                    /* 8c0740a2 fcmp/gt fr5,fr7 */
    if (T)
        goto L_40b2;                    /* 8c0740a4 bt */
    fr3 = fr7;                          /* 8c0740a6 */
    fr7 = fr5;                          /* 8c0740a8 */
    fr7 = fpu_dn_fix(fsub_tz(fr7, fr3), in_fpscr); /* 8c0740aa */
    SETT(fr7 > fr4);                    /* 8c0740ac fcmp/gt fr4,fr7 */
    if (!T)
        goto L_40b2;                    /* 8c0740ae bf */
    fr4 = fr7;                          /* 8c0740b0 */
L_40b2:
    r1 += 12;                           /* 8c0740b2 */
    r14 += 1;                           /* 8c0740b4 */
    goto L_40b6;
L_40ba:
    fr6 = fpu_dn_fix(fadd_tz(fr6, fr4), in_fpscr); /* 8c0740ba */
    fr9 = fpu_dn_fix(fadd_tz(fr9, fr4), in_fpscr); /* 8c0740bc */
    goto L_40be;
L_40c8:
    r0 = 0x138Cu;                       /* 8c0740c8 mov.w */
    r14 = c_rd32(ram, b + r0);          /* 8c0740ca */
    r1 = r6;                            /* 8c0740ce delay (always) */
    goto L_40e4;                        /* 8c0740cc bra */
L_40e4:
    SETT(r1 >= r5);                     /* 8c0740e4 cmp/hs r5,r1 */
    if (!T)
        goto L_40d0;                    /* 8c0740e6 bf */
    goto L_40e8;
L_40d0:
    r0 = 8;                             /* 8c0740d0 */
    fr7 = c_rdflt(ram, r14 + 8);        /* 8c0740d2 */
    SETT(fr5 > fr7);                    /* 8c0740d4 fcmp/gt fr7,fr5 */
    if (T)
        goto L_40e0;                    /* 8c0740d6 bt */
    fr7 = fpu_dn_fix(fsub_tz(fr7, fr5), in_fpscr); /* 8c0740d8 */
    SETT(fr4 > fr7);                    /* 8c0740da fcmp/gt fr7,fr4 */
    if (!T)
        goto L_40e0;                    /* 8c0740dc bf */
    fr4 = fr7;                          /* 8c0740de */
L_40e0:
    r14 += 12;                          /* 8c0740e0 */
    r1 += 1;                            /* 8c0740e2 */
    goto L_40e4;
L_40e8:
    fr10 = fpu_dn_fix(fsub_tz(fr10, fr4), in_fpscr); /* 8c0740e8 */
    fr8 = fpu_dn_fix(fsub_tz(fr8, fr4), in_fpscr);   /* 8c0740ec delay */
    goto L_4128;                        /* 8c0740ea bra */
L_40ee:
    r0 = 0x138Cu;                       /* 8c0740ee mov.w */
    r14 = c_rd32(ram, b + r0);          /* 8c0740f0 */
    r1 = r6;                            /* 8c0740f4 delay (always) */
    goto L_4120;                        /* 8c0740f2 bra */
L_4120:
    SETT(r1 >= r5);                     /* 8c074120 cmp/hs r5,r1 */
    if (!T)
        goto L_4108;                    /* 8c074122 bf */
    goto L_4124;
L_4108:
    r0 = 8;                             /* 8c074108 */
    fr7 = c_rdflt(ram, r14 + 8);        /* 8c07410a */
    SETT(fr7 > fr5);                    /* 8c07410c fcmp/gt fr5,fr7 */
    if (T)
        goto L_411c;                    /* 8c07410e bt */
    fr3 = fr7;                          /* 8c074110 */
    fr7 = fr5;                          /* 8c074112 */
    fr7 = fpu_dn_fix(fsub_tz(fr7, fr3), in_fpscr); /* 8c074114 */
    SETT(fr7 > fr4);                    /* 8c074116 fcmp/gt fr4,fr7 */
    if (!T)
        goto L_411c;                    /* 8c074118 bf */
    fr4 = fr7;                          /* 8c07411a */
L_411c:
    r14 += 12;                          /* 8c07411c */
    r1 += 1;                            /* 8c07411e */
    goto L_4120;
L_4124:
    fr8 = fpu_dn_fix(fadd_tz(fr8, fr4), in_fpscr);   /* 8c074124 */
    fr10 = fpu_dn_fix(fadd_tz(fr10, fr4), in_fpscr); /* 8c074126 */
L_4128:
    r0 = 24;                            /* 8c074128 */
    c_wrflt(ram, b + 24, fr10);         /* 8c07412a */
    r0 = 0x438u;                        /* 8c07412c mov.w */
    c_wrflt(ram, b + r0, fr8);          /* 8c07412e */
L_4130:
    r7 += 1;                            /* 8c074130 */
    goto L_4132;
L_4138:
    /* 8c074138 pop r12; rts (delay pop r14). r14/r12/r4/r6 passthrough. */
    o->r0 = r0;
    o->r1 = r1;
    o->r3 = r3;
    o->r5 = r5;
    o->r7 = r7;
    o->r15 = in_r15;
    o->fr4 = fpu_f32_to_bits(fr4);
    o->fr5 = fpu_f32_to_bits(fr5);
    o->fr6 = fpu_f32_to_bits(fr6);
    o->fr7 = fpu_f32_to_bits(fr7);
    o->fr8 = fpu_f32_to_bits(fr8);
    o->fr9 = fpu_f32_to_bits(fr9);
    o->fr10 = fpu_f32_to_bits(fr10);
    o->sr = (sr & ~1u) | (T ? 1u : 0u);
}

#undef SETT
