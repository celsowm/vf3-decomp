/* See cntup.h. Integer-only port (FPU skipped: fr3 is callee-2-owned at
 * the oracle exit). All stack traffic goes through a private frame so the
 * harness OOB counter only sees checked-window traffic; every map read in
 * this file must hit (nonzero OOB fails the replay). */
#include "fight/cntup.h"

#include <string.h>

static uint32_t m_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static void m_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
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

static uint32_t m_rd16(const vf3_ram_map *ram, uint32_t addr)
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

static void m_wr16(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
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

static uint32_t m_rd8(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 1 <= w->base + w->len)
            return w->data[canon - w->base];
    }
    m->oob++;
    return 0;
}

static void m_wr8(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 1 <= w->base + w->len) {
            w->data[canon - w->base] = (uint8_t)(v & 0xFFu);
            return;
        }
    }
    m->oob++;
}

/* Private frame: covers [F-32, F+96); all offsets below are relative to
 * the b7ee frame base F = in_r15 - 88. */
typedef struct {
    uint8_t b[128];
} privframe;

static uint32_t p_rd32(privframe *f, int off)
{
    uint32_t v = 0;
    memcpy(&v, f->b + (off + 32), 4);
    return v;
}

static void p_wr32(privframe *f, int off, uint32_t v)
{
    memcpy(f->b + (off + 32), &v, 4);
}

static uint32_t p_rd8(privframe *f, int off)
{
    return f->b[off + 32];
}

static void p_wr8(privframe *f, int off, uint32_t v)
{
    f->b[off + 32] = (uint8_t)(v & 0xFFu);
}

static uint32_t sext16(uint32_t w)
{
    return (uint32_t)(int32_t)(int16_t)(uint16_t)w;
}

/* SH-4 dynamic logical shift (SHLD): logical, low 5 bits of the count. */
static uint32_t shld(uint32_t v, int32_t n)
{
    uint32_t c = (uint32_t)n & 31u;
    if ((n & 0x80000000u) == 0)
        return v << (c & 31u);
    if (c == 0)
        return v;
    return v >> c;
}

/* Callee-1 (0x8C08B89C..0x8C08BB06): A = task struct (caller's r14),
 * frame base F in pf. All addresses simplified to F-relative. */
static void callee1(uint32_t A, privframe *pf, const vf3_ram_map *ram)
{
    uint32_t r0, r1, r2, r3, r6, r7, r11, r12, r13, r14c;
    int T;

    r6 = p_rd32(pf, 76);            /* 8c08b8a6 [F+76] */
    r14c = p_rd32(pf, 80);          /* 8c08b8aa [F+80] */
    r3 = m_rd32(ram, A + 16);       /* 8c08b8ae */
    p_wr32(pf, 4, r3);              /* 8c08b8b2 [F+4] */
    r2 = m_rd32(ram, r6 + 56);      /* 8c08b8b4 */
    p_wr32(pf, 8, r2);              /* 8c08b8b6 [F+8] */
    p_wr8(pf, 12, m_rd8(ram, r6 + 97)); /* 8c08b8b8-ba [F+12] */
    r3 = m_rd32(ram, r6 + 72);      /* 8c08b8be */
    p_wr32(pf, 16, r3);             /* 8c08b8c0 [F+16] */
    r2 = m_rd32(ram, r14c + 72);    /* 8c08b8c2 */
    p_wr32(pf, 20, r2);             /* 8c08b8c6 [F+20] */
    r3 = m_rd32(ram, r6 + 76);      /* 8c08b8c8 */
    p_wr32(pf, 24, r3);             /* 8c08b8ca [F+24] */
    r2 = m_rd32(ram, r14c + 76);    /* 8c08b8cc */
    p_wr32(pf, 28, r2);             /* 8c08b8d0 [F+28] */
    r3 = m_rd32(ram, r6 + 80);      /* 8c08b8d2 */
    p_wr32(pf, 32, r3);             /* 8c08b8d6 [F+32] */
    r2 = m_rd32(ram, r6);           /* 8c08b8d8 */
    p_wr32(pf, 36, r2);             /* 8c08b8da [F+36] */
    /* 8c08b8dc-de FPU skipped (fr3 spill, callee-2-owned) */
    r3 = m_rd8(ram, A + 64);        /* 8c08b8e4 */
    p_wr32(pf, 48, r3);             /* 8c08b8e8 [F+48] */
    r3 = (uint32_t)(-(int32_t)r3);  /* 8c08b8ea neg */
    r2 = shld(0x80000000u, (int32_t)r3); /* 8c08b8ec shld */
    p_wr32(pf, 52, r2);             /* 8c08b8f2 [F+52] */
    r1 = p_rd32(pf, 4);             /* 8c08b8f4 */
    r1 &= 0xFFFFFFFDu;              /* 8c08b8f0 mov #-3 + 8c08b8f6 and */
    p_wr32(pf, 4, r1);              /* 8c08b8f8 */
    r1 = p_rd32(pf, 16);            /* 8c08b8fa [F+16] */
    T = ((r1 & 0x0003D000u) == 0);   /* 8c08b8fc-900 tst */
    if (!T)
        goto L90A;                  /* 8c08b902 bf */
    r3 = p_rd32(pf, 24);            /* 8c08b904 [F+24] */
    r7 = 0x00100000u;               /* 8c08b8fe lit */
    T = ((r3 & r7) == 0);           /* 8c08b906 tst */
    if (T)
        goto L910;                  /* 8c08b908 bt */
L90A:
    r0 = p_rd32(pf, 4);             /* 8c08b90a */
    r0 |= 2u;                       /* 8c08b90c */
    p_wr32(pf, 4, r0);              /* 8c08b90e */
L910:
    r3 = 0x00020000u;               /* 8c08b910 lit */
    r13 = p_rd32(pf, 16);           /* 8c08b912 [F+16] */
    T = ((r13 & r3) == 0);          /* 8c08b914 tst */
    if (!T)
        goto L938;                  /* 8c08b916 bf */
    r2 = 0x00008000u;               /* 8c08b918 lit */
    T = ((r13 & r2) == 0);          /* 8c08b91a tst */
    if (!T)
        goto L938;                  /* 8c08b91c bf */
    r1 = p_rd32(pf, 4);             /* 8c08b91e */
    r1 &= 0xFFFFFFFBu;              /* 8c08b920 and #-5 */
    p_wr32(pf, 4, r1);              /* 8c08b924 */
    r1 = 1;                         /* 8c08b926 */
    r0 = 0x1BCEu;                   /* 8c08b928 lit.w */
    r2 = m_rd16(ram, r6 + r0);      /* 8c08b92a */
    r2 = sext16(r2);
    T = ((int32_t)r2 >= (int32_t)r1); /* 8c08b92c cmp/ge */
    p_wr32(pf, -24, r2);            /* 8c08b92e spill */
    if (!T)
        goto L93E;                  /* 8c08b930 bf */
    r3 = 0x80000000u;               /* 8c08b932 lit */
    T = ((r13 & r3) == 0);          /* 8c08b934 tst */
    if (T)
        goto L93E;                  /* 8c08b936 bt */
L938:
    r0 = p_rd32(pf, 4);             /* 8c08b938 */
    r0 |= 4u;                       /* 8c08b93a */
    p_wr32(pf, 4, r0);              /* 8c08b93c */
L93E:
    r1 = r14c + 56;                 /* 8c08b93e-40 */
    r2 = p_rd32(pf, 4);             /* 8c08b942 */
    r2 &= 0xFFFFFFF7u;              /* 8c08b944 and #-9 */
    p_wr32(pf, 4, r2);              /* 8c08b948 */
    r0 = m_rd8(ram, r1 + 3);        /* 8c08b94a [r14c+59] */
    T = (r0 == 26);                 /* 8c08b94e cmp/eq */
    p_wr32(pf, -24, r0);            /* 8c08b952 delay spill (always) */
    if (!T)
        goto L95A;                  /* 8c08b950 bf/s */
    r0 = p_rd32(pf, 4);             /* 8c08b954 */
    r0 |= 8u;                       /* 8c08b956 */
    p_wr32(pf, 4, r0);              /* 8c08b958 */
L95A:
    r2 = p_rd32(pf, 4);             /* 8c08b95a */
    r2 &= 0xFFFFFFEFu;              /* 8c08b95c and #-17 */
    p_wr32(pf, 4, r2);              /* 8c08b960 */
    r0 = 0x1B98u;                   /* 8c08b962 lit.w */
    r1 = m_rd32(ram, r14c + r0);    /* 8c08b964 */
    r2 = r1;                        /* 8c08b966 */
    T = (r2 == 0);                  /* 8c08b968 tst */
    p_wr32(pf, -24, r1);            /* 8c08b96a delay spill (always) */
    r12 = 16;                       /* 8c08b96e delay (always) */
    if (!T)
        goto L976;                  /* 8c08b96c bf/s */
    r2 = p_rd32(pf, 4);             /* 8c08b970 */
    r2 |= r12;                      /* 8c08b972 */
    p_wr32(pf, 4, r2);              /* 8c08b974 */
L976:
    r3 = p_rd32(pf, 24);            /* 8c08b976 [F+24] */
    T = ((r3 & r7) == 0);           /* 8c08b978 tst (r7 = 0x00100000) */
    if (!T)
        goto L984;                  /* 8c08b97a bf */
    r2 = p_rd32(pf, 16);            /* 8c08b97c [F+16] */
    r3 = 0x1000u;                   /* 8c08b97e lit.w */
    T = ((r2 & r3) == 0);           /* 8c08b980 tst */
    if (T)
        goto L994;                  /* 8c08b982 bt */
L984:
    r1 = p_rd32(pf, 36);            /* 8c08b984 [F+36] */
    T = ((r1 & r7) == 0);           /* 8c08b986 tst */
    if (T)
        goto L994;                  /* 8c08b988 bt */
    r0 = 32;                        /* 8c08b98a */
    r7 = m_rd16(ram, A + r0);       /* 8c08b98c */
    r7 &= 0xFFFFu;                  /* 8c08b98e extu.w */
    r7 += 1;                        /* 8c08b990 */
    m_wr16(ram, A + r0, r7);        /* 8c08b992 [A+32] += 1 */
L994:
    r0 = m_rd16(ram, A + 28);       /* 8c08b994 */
    r13 = r0;                       /* 8c08b998 */
    r2 = p_rd32(pf, 16);            /* 8c08b99a [F+16] */
    r0 = 38;                        /* 8c08b99c */
    r11 = sext16(m_rd16(ram, A + r0)); /* 8c08b99e [A+38] */
    r3 = 0x4000u;                   /* lit via pool; 8c08b996 lit.w */
    T = ((r2 & r3) == 0);           /* 8c08b9a0 tst */
    r7 = 0;                         /* 8c08b9a4 delay (always) */
    if (!T)
        goto L9B2;                  /* 8c08b9a2 bf/s */
    r0 = p_rd32(pf, 4);             /* 8c08b9a6 */
    T = ((r0 & 2u) == 0);           /* 8c08b9a8 tst #2 */
    if (!T)
        goto L9D4;                  /* 8c08b9aa bf */
    r13 = r7;                       /* 8c08b9ac */
    r11 += 1;                       /* 8c08b9b0 delay of bra (always) */
    goto L9D8;                      /* 8c08b9ae bra */
L9B2:
    r13 += 1;                       /* 8c08b9b2 */
    r11 = r7;                       /* 8c08b9b6 delay of bra (always) */
    goto L9D8;                      /* 8c08b9b4 bra */
L9D4:
    r11 = r7;                       /* 8c08b9d4 */
    r13 = r7;                       /* 8c08b9d6 */
L9D8:
    r0 = r13;                       /* 8c08b9d8 */
    m_wr16(ram, A + 28, r0);        /* 8c08b9da [A+28] */
    r0 = 38;                        /* 8c08b9dc */
    m_wr16(ram, A + r0, r11);       /* 8c08b9de [A+38] */
    r0 = m_rd16(ram, A + 22);       /* 8c08b9e0 */
    r11 = r0 & 0xFFFFu;             /* 8c08b9e2 extu.w */
    r11 = (uint32_t)((int32_t)r11 - 1); /* 8c08b9e4 */
    T = ((int32_t)r11 >= 0);        /* 8c08b9e6 cmp/pz r11 */
    r13 = r11;                      /* 8c08b9ea delay (always) */
    if (T)
        goto LBA24;                 /* 8c08b9e8 bt/s */
    r0 = 46;                        /* 8c08b9ec */
    r13 = m_rd8(ram, A + r0);       /* 8c08b9ee [A+46] */
    r0 = 97;                        /* 8c08b9f0 */
    r11 = m_rd8(ram, r14c + r0);    /* 8c08b9f2 [structB+97] */
    r13 &= 0xFFu;                   /* 8c08b9f4 extu.b */
    r0 = r11 & 0xFFu;               /* 8c08b9f6 extu.b */
    T = (r0 == 12);                 /* 8c08b9f8 cmp/eq */
    r11 = r0;                       /* 8c08b9fc delay (always) */
    if (T)
        goto LBA02;                 /* 8c08b9fa bt/s */
    T = (r11 == 0);                 /* 8c08b9fe tst */
    if (!T)
        goto LBA14;                 /* 8c08ba00 bf */
LBA02:
    r0 = 0x0085u;                   /* 8c08ba02 lit.w */
    r2 = 3;                         /* 8c08ba04 */
    r3 = m_rd8(ram, A + r0);        /* 8c08ba06 [A+0x85] */
    r3 &= 0xFFu;                    /* 8c08ba08 extu.b */
    T = (r3 >= r2);                 /* 8c08ba0a cmp/hs (unsigned) */
    p_wr32(pf, -24, r3);            /* 8c08ba0e delay spill (always) */
    if (!T)
        goto LBA24;                 /* 8c08ba0c bf/s */
    goto LBA22;                     /* 8c08ba10 bra */
LBA14:
    r0 = 0x0086u;                   /* 8c08ba14 lit.w */
    r3 = 38;                        /* 8c08ba16 */
    r2 = m_rd8(ram, A + r0);        /* 8c08ba18 [A+0x86] */
    r2 &= 0xFFu;                    /* 8c08ba1a extu.b */
    T = (r2 >= r3);                 /* 8c08ba1c cmp/hs (unsigned) */
    p_wr32(pf, -24, r2);            /* 8c08ba20 delay spill (always) */
    if (!T)
        goto LBA24;                 /* 8c08ba1e bf/s */
LBA22:
    r13 = r7;                       /* 8c08ba22 */
LBA24:
    m_wr16(ram, A + 22, r13);       /* 8c08ba24-26 [A+22] */
    r3 = p_rd32(pf, 4);             /* 8c08ba28 */
    T = ((r3 & r12) == 0);          /* 8c08ba2a tst */
    r13 = r7;                       /* 8c08ba2e delay (always) */
    if (T)
        goto LBA38;                 /* 8c08ba2c bt/s */
    r0 = 36;                        /* 8c08ba30 */
    r11 = sext16(m_rd16(ram, A + r0)); /* 8c08ba32 [A+36] */
    r11 += 1;                       /* 8c08ba34 */
    r13 = r11;                      /* 8c08ba36 */
LBA38:
    m_wr16(ram, A + 36, r13);       /* 8c08ba38-3a [A+36] (both paths join) */
    r3 = p_rd32(pf, 4);             /* 8c08ba3c */
    T = ((r3 & r12) == 0);          /* 8c08ba3e tst */
    if (T)
        goto LBA50;                 /* 8c08ba40 bt */
    r2 = 7;                         /* 8c08ba42 */
    T = (r13 >= r2);                /* 8c08ba44 cmp/hs (unsigned) */
    if (!T)
        goto LBAA2;                 /* 8c08ba46 bf */
    r13 = r7;                       /* 8c08ba4a delay of bra (always) */
    goto LBA9E;                     /* 8c08ba48 bra */
LBA50:
    r0 = 34;                        /* 8c08ba50 */
    r13 = m_rd16(ram, A + r0);      /* 8c08ba52 [A+34] */
    r13 += 1;                       /* 8c08ba56 */
    r13 &= 63u;                     /* 8c08ba58 and #63 */
    r3 = r13;                       /* (8c08ba5a tst uses r3) */
    T = (r3 == 0);                  /* 8c08ba5a tst */
    p_wr32(pf, -24, r3);            /* 8c08ba5c spill */
    r0 = 0x0085u;                   /* 8c08ba5e lit.w */
    r12 = m_rd8(ram, A + r0);       /* 8c08ba60 [A+0x85] */
    r12 &= 0xFFu;                   /* 8c08ba64 delay extu.b (always) */
    if (!T)
        goto LBA6A;                 /* 8c08ba62 bf/s */
    r12 += 1;                       /* 8c08ba66 */
    m_wr8(ram, A + 0x85u, r12);     /* 8c08ba68 [A+0x85] += 1 */
LBA6A:
    r3 = 1;                         /* 8c08ba6a */
    T = (r12 >= r3);                /* 8c08ba6c cmp/hs (unsigned) */
    if (!T)
        goto LBA9E;                 /* 8c08ba6e bf */
    r2 = p_rd32(pf, 20);            /* 8c08ba70 [F+20] */
    r3 = 0x00800000u;               /* 8c08ba72 lit */
    T = ((r2 & r3) == 0);           /* 8c08ba74 tst */
    if (T)
        goto LBA9E;                 /* 8c08ba76 bt */
    r0 = 0x1A21u;                   /* 8c08ba78 lit.w */
    r1 = m_rd8(ram, r14c + r0);     /* 8c08ba7a [structB+0x1a21] */
    r0 = 97;                        /* 8c08ba7c */
    r1 &= 0xFFu;                    /* (8c08ba7e extu.b folded) */
    p_wr32(pf, -24, r1);            /* 8c08ba80 spill */
    r3 = m_rd8(ram, r14c + 97);     /* 8c08ba82 [structB+97] */
    r3 &= 0xFFu;                    /* 8c08ba84 extu.b */
    p_wr32(pf, -20, r3);            /* 8c08ba86 spill */
    r0 = p_rd32(pf, -24);           /* 8c08ba88 */
    T = (r0 == 1);                  /* 8c08ba8a cmp/eq */
    if (!T)
        goto LBA9E;                 /* 8c08ba8c bf */
    r3 = p_rd32(pf, -20);           /* 8c08ba8e */
    T = (r3 == 0);                  /* 8c08ba90 tst */
    if (T)
        goto LBA9E;                 /* 8c08ba92 bt */
    r0 = 0x0086u;                   /* 8c08ba94 lit.w */
    r14c = m_rd8(ram, A + r0);      /* 8c08ba96 [A+0x86] */
    r14c &= 0xFFu;                  /* 8c08ba98 extu.b */
    r14c += 1;                      /* 8c08ba9a */
    m_wr8(ram, A + 0x86u, r14c);    /* 8c08ba9c */
LBA9E:
    r0 = 34;                        /* 8c08ba9e */
    m_wr16(ram, A + r0, r13);       /* 8c08baa0 [A+34] */
LBAA2:
    r2 = p_rd32(pf, 4);             /* 8c08baa2 */
    r2 &= 0xFFFFFFDFu;              /* 8c08baa4 and #-33 */
    p_wr32(pf, 4, r2);              /* 8c08baa6 */
    r2 = 0;                         /* 8c08baaa */
    r0 = 0x0085u;                   /* 8c08baac lit.w */
    r1 = m_rd8(ram, A + r0);        /* 8c08baae [A+0x85] */
    r1 &= 0xFFu;                    /* 8c08bab0 extu.b */
    r1 = (uint32_t)((int32_t)r1 - 3); /* 8c08bab2 */
    T = (r1 > r2);                  /* 8c08bab4 cmp/hi (unsigned) */
    p_wr32(pf, -24, r1);            /* 8c08bab6 spill */
    r14c = 96;                      /* 8c08baba delay (always) */
    if (!T)
        goto LBABE;                 /* 8c08bab8 bf/s */
    r14c = 35;                      /* 8c08babc */
LBABE:
    T = (r13 >= r14c);              /* 8c08babe cmp/hs (unsigned) */
    if (!T)
        goto LBAC8;                 /* 8c08bac0 bf */
    r0 = p_rd32(pf, 4);             /* 8c08bac2 */
    r0 |= 32u;                      /* 8c08bac4 */
    p_wr32(pf, 4, r0);              /* 8c08bac6 */
LBAC8:
    r0 = m_rd16(ram, A + 30);       /* 8c08bac8 [A+30] */
    {
        int32_t s = (int32_t)(r0 & 0xFFFFu); /* 8c08baca extu.w */
        s -= 1;                     /* 8c08bacc */
        T = (s >= 0);               /* 8c08bace cmp/pz r5 */
        r6 = (uint32_t)s;           /* 8c08bad2 delay (always) */
        if (T)
            goto LBAD6;             /* 8c08bad0 bt/s */
        r6 = r7;                    /* 8c08bad4 */
    }
LBAD6:
    m_wr16(ram, A + 30, r6);        /* 8c08bad6-d8 [A+30] */
    r0 = sext16(m_rd16(ram, A + 24)); /* 8c08bada [A+24] */
    {
        int32_t s = (int32_t)r0;    /* 8c08badc mov (no extu) */
        s -= 1;                     /* 8c08bade */
        T = (s >= 0);               /* 8c08bae0 cmp/pz */
        r6 = (uint32_t)s;           /* 8c08bae4 delay (always) */
        if (!T)
            goto LBAEC;             /* 8c08bae2 bf/s */
        r0 = r6;                    /* 8c08bae6 */
        m_wr16(ram, A + 24, r0);    /* 8c08baea delay (always) */
        goto LBAFC;                 /* 8c08bae8 bra */
    }
LBAEC:
    r0 = sext16(m_rd16(ram, A + 20)); /* 8c08baec [A+20] */
    {
        int32_t s = (int32_t)r0;    /* 8c08baee mov (no extu) */
        s -= 1;                     /* 8c08baf0 */
        T = (s >= 0);               /* 8c08baf2 cmp/pz */
        r6 = (uint32_t)s;           /* 8c08baf6 delay (always) */
        if (!T)
            goto LBAFC;             /* 8c08baf4 bf/s */
        r0 = r6;                    /* 8c08baf8 */
        m_wr16(ram, A + 20, r0);    /* 8c08bafa delay (always) */
    }
LBAFC:
    /* 8c08bafc-fe epilogue (add #8, pop r11/r12/r13, rts + delay pop
     * r14): private-frame unwinding, no observable effect. */
    (void)r0; (void)r1; (void)r2; (void)r3;
    (void)r6; (void)r7; (void)r11; (void)r12; (void)r13; (void)r14c;
}

void vf3_cntup_8c08b7ee(uint32_t in_r14, uint32_t in_r15, uint32_t in_pr,
                        vf3_cntup_out *o, const vf3_ram_map *ram)
{
    privframe pf;
    uint32_t r0, r2, r3, r4;
    uint32_t X = in_r15;

    memset(&pf, 0, sizeof(pf));
    p_wr32(&pf, 84, in_pr);         /* 8c08b7ee sts.l pr,@-r15 */
    /* 8c08b7f0-f2: r15 -= 84 -> frame base F */
    p_wr32(&pf, 0, in_r14);         /* 8c08b7f4 [F] = r14 */
    r4 = 0x0C29BB84u;               /* 8c08b7f6 lit */
    r3 = m_rd32(ram, r4 + 16);      /* 8c08b7f8 */
    p_wr32(&pf, 76, r3);            /* 8c08b7fa [F+76] */
    r2 = m_rd32(ram, r4 + 20);      /* 8c08b7fe */
    p_wr32(&pf, 80, r2);            /* 8c08b800 [F+80] */
    r4 = m_rd32(ram, r4 + 40);      /* 8c08b802 guard ptr */
    r0 = m_rd32(ram, r4);           /* 8c08b804 deref */
    if ((r0 & 2u) != 0)             /* 8c08b806-808 tst #2 + bf */
        goto done;
    /* 8c08b80a delay (r1 load) has no checked effect; folded below */
    r3 = 0x00080001u;               /* 8c08b80c lit */
    r2 = m_rd32(ram, 0x0C29BCC0u);  /* 8c08b80e deref */
    if ((r2 & r3) != 0)             /* 8c08b810-812 tst + bf */
        goto done;
    /* 8c08b814 delay (r5 = F+4) folded into the call */
    callee1(in_r14, &pf, ram);      /* 8c08b818 bsr 0x8C08B89C */
    /* 8c08b820 bsr 0x8C08BB14 (callee-2 + nested calls): DELEGATED,
     * see cntup.h. No checked-window traffic. */
    r2 = p_rd32(&pf, 4);            /* 8c08b824 [F+4] */
    r3 = p_rd32(&pf, 0);            /* 8c08b826 [F] */
    m_wr32(ram, r3 + 16, r2);       /* 8c08b828 final store */
done:
    /* 8c08b82a-30 epilogue: r15 += 84 (balanced), pr restored,
     * rts delay pops the caller word into r14 (caller-owned; the
     * replay test forces r14 from the oracle). */
    o->r14 = in_r14;
    o->r15 = X + 4;
    o->pr = in_pr;
}
