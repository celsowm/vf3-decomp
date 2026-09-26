/* See af734.h. The RUN-path nested call goes to the oracle-verified U2
 * port; all traffic goes through the replay map so the test diffs the
 * shadow against the oracle exit windows. */
#include "fight/af734.h"
#include "fight/fpucb.h"
#include "fight/fpu_tz.h"

#include <string.h>

static uint32_t g_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static void g_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
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

static uint32_t g_rd16(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 2 <= w->base + w->len) {
            uint32_t v = 0;
            memcpy(&v, w->data + (canon - w->base), 2);
            return v & 0xFFFFu;
        }
    }
    m->oob++;
    return 0;
}

static void g_wr16(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 2 <= w->base + w->len) {
            uint8_t b[2];
            b[0] = (uint8_t)(v & 0xFFu);
            b[1] = (uint8_t)((v >> 8) & 0xFFu);
            memcpy(w->data + (canon - w->base), b, 2);
            return;
        }
    }
    m->oob++;
}

static float g_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t bits = g_rd32(ram, addr);
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

static void g_wrflt(const vf3_ram_map *ram, uint32_t addr, float f)
{
    uint32_t bits;
    memcpy(&bits, &f, 4);
    g_wr32(ram, addr, bits);
}

static float bits_f(uint32_t b)
{
    float f;
    memcpy(&f, &b, 4);
    return f;
}

void vf3_af734_8c0af734(uint32_t in_r0, uint32_t in_r3, uint32_t in_r5,
                        uint32_t in_r6, uint32_t in_r13, uint32_t in_r14,
                        uint32_t in_r15, uint32_t in_pr, uint32_t in_sr,
                        uint32_t in_fpscr, float in_fr0, float in_fr1,
                        float in_fr2, float in_fr3, float in_fr4, float in_fr5,
                        float in_fr6, float in_fr7, float in_fr15,
                        vf3_af734_out *o, const vf3_ram_map *ram)
{
    uint32_t X, F, r0, r1, r2, r3, r4, r5, r6, r14;
    uint32_t sr = in_sr;
    int T;
    float fr0, fr1, fr2, fr3, fr4, fr5, fr6, fr7;
    int run = 0, saw74c = 0;

    r0 = in_r0; r3 = in_r3; r5 = in_r5; r6 = in_r6; r14 = in_r14;
    /* SKIP path preserves all fr; RUN overwrites fr0-fr7 (fr8+ untouched). */
    fr0 = in_fr0; fr1 = in_fr1; fr2 = in_fr2; fr3 = in_fr3;
    fr4 = in_fr4; fr5 = in_fr5; fr6 = in_fr6; fr7 = in_fr7;

    X = in_r15 - 4;                       /* 8c0af734 sts.l pr */
    g_wr32(ram, X, in_pr);
    r4 = 0x0C29B864u;                     /* 8c0af736 lit */
    g_wr32(ram, in_r0 + in_r14, in_r3);   /* 8c0af738 */
    r3 = 0x0800u;                         /* 8c0af73a lit.w */
    F = X - 8;                            /* 8c0af73c frame */
    r2 = g_rd32(ram, in_r13 + 12);        /* 8c0af73e */
    T = ((r2 & r3) == 0);                 /* 8c0af740 tst */
    if (T)                                /* 8c0af742 bt */
        goto L762;
    r1 = g_rd32(ram, in_r13 + 12);        /* 8c0af744 */
    r3 = 0xF7FFu;                         /* 8c0af746 lit.w */
    r1 &= r3;                             /* 8c0af748 */
    g_wr32(ram, in_r13 + 12, r1);         /* 8c0af74a */
    r5 = 0x000C0000u;                     /* 8c0af74c lit */
    saw74c = 1;
    r2 = g_rd32(ram, r4 + 4);             /* 8c0af74e */
    T = ((r2 & r5) == 0);                 /* 8c0af750 tst */
    if (!T)                               /* 8c0af752 bf */
        goto L762;
    r3 = g_rd32(ram, r4);                 /* 8c0af754 */
    T = ((r3 & r5) == 0);                 /* 8c0af756 tst */
    if (!T)                               /* 8c0af758 bf */
        goto L762;
    r0 = g_rd16(ram, in_r14 + 30);        /* 8c0af75a mov.w */
    r3 = 0x8000u;                         /* 8c0af75c lit.w */
    r0 = r0 + r3;                         /* 8c0af75e add */
    g_wr16(ram, in_r14 + 30, r0);         /* 8c0af760 mov.w */
L762:
    r3 = g_rd32(ram, in_r13 + 16);        /* 8c0af762 */
    r4 = 0x01000000u;                     /* 8c0af764 lit */
    T = ((r4 & r3) == 0);                 /* 8c0af766 tst */
    if (T)                                /* 8c0af768 bt */
        goto L772;
    r2 = g_rd32(ram, in_r13 + 12);        /* 8c0af76a */
    r3 = 0x04000000u;                     /* 8c0af76c lit */
    r2 |= r3;                             /* 8c0af76e */
    g_wr32(ram, in_r13 + 12, r2);         /* 8c0af770 */
L772:
    r1 = g_rd32(ram, in_r13 + 12);        /* 8c0af772 */
    T = ((r1 & r4) == 0);                 /* 8c0af774 tst (r4 = 0x01000000) */
    if (T)                                /* 8c0af776 bt */
        goto L7B6;
    run = 1;
    {
        vf3_fpucb_out ou;
        r3 = 0xFEFFFFFFu;                 /* 8c0af778 lit */
        r5 = F;                           /* 8c0af77a (r15 == F here) */
        r2 = g_rd32(ram, in_r13 + 12);    /* 8c0af77c */
        r6 = F;                           /* 8c0af77e */
        r2 &= r3;                         /* 8c0af780 */
        g_wr32(ram, in_r13 + 12, r2);     /* 8c0af782 */
        r0 = g_rd16(ram, in_r14 + 30);    /* 8c0af784 mov.w */
        r4 = r0 & 0xFFFFu;                /* 8c0af786 extu.w */
        r0 = 0x1D04u;                     /* 8c0af788 lit.w */
        fr3 = g_rdflt(ram, in_r14 + r0);  /* 8c0af78a fr3a */
        r0 = 4;                           /* 8c0af78c */
        g_wrflt(ram, F + 4, fr3);         /* 8c0af78e spill */
        r0 = 0x1D0Cu;                     /* 8c0af790 lit.w */
        fr3 = g_rdflt(ram, in_r14 + r0);  /* 8c0af792 fr3b */
        g_wrflt(ram, F, fr3);             /* 8c0af794 spill */
        /* 8c0af796 lit r2 = U2 target (immediate); 8c0af798 jsr @r2
         * with r5 = F+4 (8c0af79a delay add). */
        memset(&ou, 0, sizeof(ou));
        vf3_fpucb_8c09553c(r1, r4, F + 4, F, in_r14, F, in_pr, sr,
                           in_fpscr, in_fr15, &ou, ram);
        r5 = ou.r5;
        r6 = ou.r6;
        sr = ou.sr;
        fr0 = bits_f(ou.fr0);
        fr1 = bits_f(ou.fr1);
        fr6 = bits_f(ou.fr6);
        fr7 = bits_f(ou.fr7);
        r0 = 0x0430u;                     /* 8c0af79c lit.w */
        fr2 = g_rdflt(ram, F);            /* 8c0af79e */
        fr5 = g_rdflt(ram, in_r14 + r0);  /* 8c0af7a0 */
        r0 += 8;                          /* 8c0af7a2 -> 0x438 */
        fr4 = g_rdflt(ram, in_r14 + r0);  /* 8c0af7a4 */
        r0 = 4;                           /* 8c0af7a6 */
        fr3 = g_rdflt(ram, F + 4);        /* 8c0af7a8 */
        r0 = 16;                          /* 8c0af7aa */
        fr4 = fpu_dn_fix(fsub_tz(fr4, fr2), in_fpscr); /* 8c0af7ac */
        fr5 = fpu_dn_fix(fsub_tz(fr5, fr3), in_fpscr); /* 8c0af7ae */
        g_wrflt(ram, in_r14 + 16, fr5);   /* 8c0af7b0 */
        r0 = 24;                          /* 8c0af7b2 */
        g_wrflt(ram, in_r14 + 24, fr4);   /* 8c0af7b4 */
    }
L7B6:
    r3 = 0x00080000u;                     /* 8c0af7b6 lit */
    r4 = g_rd32(ram, in_r14);             /* 8c0af7b8 */
    T = ((r4 & r3) == 0);                 /* 8c0af7ba tst */
    if (T)                                /* 8c0af7bc bt */
        goto L7CC;
    r2 = 0xFFF7FFFFu;                     /* 8c0af7be lit */
    r4 &= r2;                             /* 8c0af7c0 */
    g_wr32(ram, in_r14, r4);              /* 8c0af7c2 */
    r3 = 0x80000000u;                     /* 8c0af7c4 lit */
    r1 = g_rd32(ram, in_r13 + 12);        /* 8c0af7c6 */
    r1 |= r3;                             /* 8c0af7c8 */
    g_wr32(ram, in_r13 + 12, r1);         /* 8c0af7ca */
L7CC:
    r2 = g_rd32(ram, in_r13 + 12);        /* 8c0af7ce */
    g_wr32(ram, in_r14 + 72, r2);         /* 8c0af7d4 (r0 = 72) */
    r0 = 72;                              /* 8c0af7d2 mov #72 */
    r14 = g_rd32(ram, X + 4);             /* 8c0af7da delay: pop r14 */

    o->r0 = r0;
    o->r1 = r1;
    o->r2 = r2;
    o->r3 = r3;
    o->r4 = r4;
    o->r5 = run ? r5 : (saw74c ? r5 : in_r5);
    o->r6 = run ? r6 : in_r6;
    o->r14 = r14;
    o->r15 = in_r15;
    o->sr = T ? (sr | 1u) : (sr & ~1u);
    {
        uint32_t b;
        memcpy(&b, &fr0, 4); o->fr0 = b;
        memcpy(&b, &fr1, 4); o->fr1 = b;
        memcpy(&b, &fr2, 4); o->fr2 = b;
        memcpy(&b, &fr3, 4); o->fr3 = b;
        memcpy(&b, &fr4, 4); o->fr4 = b;
        memcpy(&b, &fr5, 4); o->fr5 = b;
        memcpy(&b, &fr6, 4); o->fr6 = b;
        memcpy(&b, &fr7, 4); o->fr7 = b;
    }
}
