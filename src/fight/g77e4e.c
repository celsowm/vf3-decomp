/* See g77e4e.h. All traffic goes through the replay map so the test
 * diffs the shadow against the oracle exit windows. */
#include "fight/g77e4e.h"

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

static void c_wr8(const vf3_ram_map *ram, uint32_t addr, uint8_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 1 <= w->base + w->len) {
            memcpy(w->data + (canon - w->base), &v, 1);
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

void vf3_g77e4e_8c077e4e(uint32_t in_r0, uint32_t in_r1, uint32_t in_r2,
                         uint32_t in_r3, uint32_t in_r4, uint32_t in_r5,
                         uint32_t in_r6, uint32_t in_r7, uint32_t in_r8,
                         uint32_t in_r9, uint32_t in_r10, uint32_t in_r11,
                         uint32_t in_r12, uint32_t in_r13, uint32_t in_r14,
                         uint32_t in_r15, uint32_t in_pr, uint32_t in_sr,
                         vf3_g77e4e_out *o, const vf3_ram_map *ram)
{
    uint32_t r0 = in_r0, r1 = in_r1, r2 = in_r2, r3 = in_r3;
    uint32_t r4 = in_r4, r5 = in_r5, r6 = in_r6, r7 = in_r7;
    uint32_t r8 = in_r8, r9 = in_r9, r10 = in_r10, r11 = in_r11;
    uint32_t r12 = in_r12, r13 = in_r13, r14 = in_r14;
    uint32_t X = in_r15 - 32 - 8;       /* 7 pushes + pr + sub 8 */
    uint32_t sr = in_sr;
    int T = (in_sr & 1) != 0;

    (void)in_pr;
    c_wr32(ram, in_r15 - 4, in_r14);    /* 8c077e4e */
    c_wr32(ram, in_r15 - 8, in_r13);    /* 8c077e50 */
    c_wr32(ram, in_r15 - 12, in_r12);   /* 8c077e52 */
    c_wr32(ram, in_r15 - 16, in_r11);   /* 8c077e54 */
    c_wr32(ram, in_r15 - 20, in_r10);   /* 8c077e56 */
    c_wr32(ram, in_r15 - 24, in_r9);    /* 8c077e58 */
    c_wr32(ram, in_r15 - 28, in_r8);    /* 8c077e5a */
    c_wr32(ram, in_r15 - 32, in_pr);    /* 8c077e5c sts.l pr */

#define SETT(v) do { T = (v) ? 1 : 0; } while (0)

    r0 = c_rd32(ram, X + 60);           /* 8c077e60 */
    r10 = c_rd32(ram, X + 52);          /* 8c077e62 */
    T = ((r0 & 96) == 0);               /* 8c077e64 tst #96,r0 */
    r14 = r5;                           /* 8c077e68 delay (always) */
    if (!T)
        goto L_fe6;                     /* 8c077e66 bt/s (T=0: bits set) */
    r2 = c_rd32(ram, r10);              /* 8c077e6e */
    r3 = 0x40000000u;                   /* 8c077e70 mov.l pool value */
    T = ((r3 & r2) == 0);               /* 8c077e72 tst r3,r2 */
    if (T)
        goto L_e7a;                     /* 8c077e74 bt */
    goto L_fe6;                         /* 8c077e76 bra */
L_e7a:
    r0 = 72;                            /* 8c077e7a */
    r5 = c_rd32(ram, X + 60);           /* 8c077e7c */
    r2 = c_rd32(ram, X + 76);           /* 8c077e7e */
    r11 = 4;                            /* 8c077e80 */
    r3 = 0x00080000u;                   /* 8c077e82 mov.l pool value */
    r12 = 63;                           /* 8c077e84 */
    T = ((r11 & r2) == 0);              /* 8c077e86 tst r11,r2 */
    r5 &= r3;                           /* 8c077e8a delay (always) */
    if (!T)
        goto L_f18;                     /* 8c077e88 bt/s (T=0: bit set) */
    r1 = X;                             /* 8c077e8c */
    r1 += 72;                           /* 8c077e8e */
    r0 = c_rd32(ram, r1);               /* 8c077e90 */
    T = ((r0 & 11) == 0);               /* 8c077e92 tst #11,r0 */
    if (!T)
        goto L_e9e;                     /* 8c077e94 bf */
    r1 = c_rd32(ram, r10);              /* 8c077e96 */
    r2 = 0x7FFFFFFFu;                   /* 8c077e98 mov.l pool value */
    r1 &= r2;                           /* 8c077e9a */
    c_wr32(ram, r10, r1);               /* 8c077e9c */
L_e9e:
    r0 = c_rd32(ram, r10);              /* 8c077e9e */
    r3 = 0x80000000u;                   /* 8c077ea0 mov.l pool value */
    T = ((r3 & r0) == 0);               /* 8c077ea2 tst r3,r0 */
    if (T)
        goto L_eaa;                     /* 8c077ea4 bt */
    goto L_fe6;                         /* 8c077ea6 bra */
L_eaa:
    r0 = 0x1B82u;                       /* 8c077eaa mov.w */
    r6 = 0x00FCu;                       /* 8c077eac mov.w */
    r4 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077eae mov.b */
    r3 = 0x1C00u;                       /* 8c077eb0 mov.w */
    r4 &= 0xFFu;                        /* 8c077eb2 extu.b */
    r0 = r4;                            /* 8c077eb4 */
    r0 += (uint32_t)-1;                 /* 8c077eb6 */
    r0 <<= 2;                           /* 8c077eb8 shll2 */
    r3 += r14;                          /* 8c077eba */
    r6 &= r0;                           /* 8c077ebc */
    r6 += r3;                           /* 8c077ebe */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, r6 + 2); /* 8c077ec0 mov.b */
    r0 &= 0xFFu;                        /* 8c077ec2 extu.b */
    T = ((r11 & r0) == 0);              /* 8c077ec4 tst r11,r0 */
    if (T)
        goto L_ecc;                     /* 8c077ecc bt */
    r0 = 0x1B83u;                       /* 8c077ec8 mov.w */
    c_wr8(ram, r14 + r0, (uint8_t)r4);  /* 8c077eca mov.b */
L_ecc:
    T = (r5 == 0);                      /* 8c077ecc tst r5,r5 */
    if (T)
        goto L_ed4;                     /* 8c077ece bt */
    goto L_801c;                        /* 8c077ed0 bra */
L_ed4:
    o->gated = 2;                       /* 8c077ed4: ED4 data-block path */
    return;
L_801c:
    r0 = 0x1B88u;                       /* 8c07801c mov.w */
    r3 = c_rd32(ram, r10);              /* 8c07801e */
    c_wr32(ram, r14 + r0, r3);          /* 8c078020 */
    goto L_8024;
L_f18:
    T = (r5 == 0);                      /* 8c077f18 tst r5,r5 */
    if (!T)
        goto L_fe6;                     /* 8c077f1a bf */
    r0 = 0x1B82u;                       /* 8c077f1c mov.w */
    r5 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077f1e mov.b */
    r0 += 4;                            /* 8c077f20 -> 0x1b86 */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077f22 mov.b */
    r5 &= 0xFFu;                        /* 8c077f24 extu.b */
    r5 += (uint32_t)-1;                 /* 8c077f26 */
    r3 &= 0xFFu;                        /* 8c077f28 extu.b */
    r5 &= r12;                          /* 8c077f2a and r12,r5 */
    T = (r3 == r5);                     /* 8c077f2c cmp/eq r3,r5 */
    c_wr32(ram, X, r3);                 /* 8c077f30 delay (always) */
    if (!T)
        goto L_f32;                     /* 8c077f2e bt/s (T=0: differ) */
    goto L_fe6;
L_f32:
    r5 += (uint32_t)-1;                 /* 8c077f32 */
    r3 = 0x1C00u;                       /* 8c077f34 mov.w */
    r5 &= r12;                          /* 8c077f36 and r12,r5 */
    r13 = r5;                           /* 8c077f38 */
    r3 += r14;                          /* 8c077f3a */
    r13 <<= 2;                          /* 8c077f3c shll2 */
    r3 += r13;                          /* 8c077f3e */
    r2 = (uint32_t)(uint8_t)c_rd8s(ram, r3); /* 8c077f40 mov.b */
    r2 &= 0xFFu;                        /* 8c077f42 extu.b */
    T = ((r11 & r2) == 0);              /* 8c077f44 tst r11,r2 */
    c_wr32(ram, X + 4, r2);             /* 8c077f48 delay (always) */
    if (!T)
        goto L_f4a;                     /* 8c077f46 bt/s (T=0: bit set) */
    goto L_fe6;
L_f4a:
    r8 = 9;                             /* 8c077f4a */
L_f4c:
    r9 = 0x1C00u;                       /* 8c077f4c mov.w */
    r3 = 15;                            /* 8c077f4e */
    r9 += r14;                          /* 8c077f50 */
    r9 += r13;                          /* 8c077f52 */
    r9 = (uint32_t)(uint8_t)c_rd8s(ram, r9); /* 8c077f54 mov.b */
    r9 &= 0xFFu;                        /* 8c077f56 extu.b */
    r9 &= r3;                           /* 8c077f58 and r3,r9 */
    r0 = r9;                            /* 8c077f5a */
    T = (r0 == 4);                      /* 8c077f5c cmp/eq #4 */
    if (!T)
        goto L_fe6;                     /* 8c077f5e bf */
    r3 = 0x1C00u;                       /* 8c077f60 mov.w */
    r3 += r14;                          /* 8c077f62 */
    r13 += r3;                          /* 8c077f64 add r3,r13 */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, r13 + 2); /* 8c077f66 mov.b */
    r13 = r0 & 0xFFu;                   /* 8c077f68 extu.b (into r13) */
    T = ((r11 & r13) == 0);             /* 8c077f6a tst r11,r13 */
    if (!T)
        goto L_f88;                     /* 8c077f6c bf */
    r3 = c_rd32(ram, X);                /* 8c077f6e */
    T = (r3 == r5);                     /* 8c077f70 cmp/eq r3,r5 */
    if (T)
        goto L_fe6;                     /* 8c077f72 bt */
L_f74:
    r5 += (uint32_t)-1;                 /* 8c077f74 */
    r8 += (uint32_t)-1;                 /* 8c077f76 */
    r3 = 0;                             /* 8c077f78 */
    r5 &= r12;                          /* 8c077f7a and r12,r5 */
    T = (r8 > r3);                      /* 8c077f7c cmp/hi r3,r8 */
    r5 = r5;                            /* (r13 move below, F7E position) */
    r13 = r5;                           /* 8c077f7e mov r5,r13 */
    r13 <<= 2;                          /* 8c077f82 delay (always) */
    if (!T)
        goto L_f4c;                     /* 8c077f80 bt/s (T=0) */
    goto L_fe6;                         /* 8c077f84 bra */
L_f88:
    r0 = 0x1B83u;                       /* 8c077f88 mov.w */
    r2 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077f8a mov.b */
    r2 &= 0xFFu;                        /* 8c077f8c extu.b */
    c_wr32(ram, X, r2);                 /* 8c077f8e */
    r0 = 0x1B82u;                       /* 8c077f90 mov.w */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077f92 mov.b */
    r0 += 1;                            /* 8c077f94 -> 0x1b83 */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c077f96 mov.b */
    /* call-arg marshalling: each push shifts later [r15+76] reads down */
    r0 = 76;                            /* 8c077f98 */
    r3 = c_rd32(ram, X + 76);           /* 8c077f9a */
    r0 = 76;                            /* 8c077f9c */
    r5 = 0x00FFu;                       /* 8c077f9e mov.w */
    c_wr32(ram, X - 4, r3);             /* 8c077fa0 push r3 */
    r2 = c_rd32(ram, X + 72);           /* 8c077fa2 [X+72] */
    r0 = 76;                            /* 8c077fa4 */
    c_wr32(ram, X - 8, r2);             /* 8c077fa6 push r2 */
    r3 = c_rd32(ram, X + 68);           /* 8c077fa8 [X+68] */
    r0 = 76;                            /* 8c077faa */
    c_wr32(ram, X - 12, r3);            /* 8c077fac push r3 */
    r2 = c_rd32(ram, X + 64);           /* 8c077fae [X+64] */
    r0 = 76;                            /* 8c077fb0 */
    c_wr32(ram, X - 16, r2);            /* 8c077fb2 push r2 */
    r3 = c_rd32(ram, X + 60);           /* 8c077fb4 [X+60] */
    r0 = 76;                            /* 8c077fb6 */
    c_wr32(ram, X - 20, r3);            /* 8c077fb8 push r3 */
    r2 = c_rd32(ram, X + 56);           /* 8c077fba [X+56] */
    r0 = 76;                            /* 8c077fbc */
    c_wr32(ram, X - 24, r2);            /* 8c077fbe push r2 */
    c_wr32(ram, X - 28, r10);           /* 8c077fc0 push r10 */
    r3 = c_rd32(ram, X + 48);           /* 8c077fc2 [X+48] */
    r0 = 76;                            /* 8c077fc4 */
    c_wr32(ram, X - 32, r3);            /* 8c077fc6 push r3 */
    r2 = c_rd32(ram, X + 44);           /* 8c077fc8 [X+44] */
    c_wr32(ram, X - 36, r2);            /* 8c077fca push r2 */
    c_wr32(ram, X - 40, r5);            /* 8c077fcc push r5 (0x00ff) */
    /* 8c077fce bsr 0x8c078110: NESTED-CALL GATE (see header) */
    o->gated = 1;
    return;
L_fe6:
    r0 = 0;                             /* 8c077fe8 delay (always) */
    goto L_8024;                        /* 8c077fe6 bra 0x8c078024 */
L_8022:
    r0 = 1;                             /* 8c078022 (post-call path) */
L_8024:
    X += 8;                             /* 8c078024 add #8,r15 */
    o->pr = c_rd32(ram, X);             /* 8c078026 lds.l @r15+,pr */
    r8 = c_rd32(ram, X + 4);            /* 8c078028 */
    r9 = c_rd32(ram, X + 8);            /* 8c07802a */
    r10 = c_rd32(ram, X + 12);          /* 8c07802c */
    r11 = c_rd32(ram, X + 16);          /* 8c07802e */
    r12 = c_rd32(ram, X + 20);          /* 8c078030 */
    r13 = c_rd32(ram, X + 24);          /* 8c078032 */
    r14 = c_rd32(ram, X + 28);          /* 8c078036 delay */

    o->r0 = r0;
    o->r1 = r1;
    o->r2 = r2;
    o->r3 = r3;
    o->r4 = r4;
    o->r5 = r5;
    o->r6 = r6;
    o->r8 = r8;
    o->r9 = r9;
    o->r10 = r10;
    o->r11 = r11;
    o->r12 = r12;
    o->r13 = r13;
    o->r14 = r14;
    o->r15 = in_r15;
    o->sr = (sr & ~1u) | (T ? 1u : 0u);
}

#undef SETT