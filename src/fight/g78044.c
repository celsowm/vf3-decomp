/* See g78044.h. All traffic goes through the replay map so the test
 * diffs the shadow against the oracle exit windows. */
#include "fight/g78044.h"

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

void vf3_g78044_8c078044(uint32_t in_r4, uint32_t in_r5, uint32_t in_r6,
                         uint32_t in_r7, uint32_t in_r13, uint32_t in_r14,
                         uint32_t in_r15, uint32_t in_sr,
                         vf3_g78044_out *o, const vf3_ram_map *ram)
{
    uint32_t r0 = 0, r1 = 0, r2 = 0, r3 = 0;
    uint32_t r4 = in_r4, r5 = in_r5, r6 = in_r6, r7 = in_r7;
    uint32_t r13 = in_r13, r14 = in_r14;
    uint32_t X = in_r15 - 8;            /* push r14 + push r13 */
    uint32_t sr = in_sr;
    int T = (in_sr & 1) != 0;

    c_wr32(ram, in_r15 - 4, in_r14);    /* 8c078044 mov.l r14,@-r15 */
    r4 = 15;                            /* 8c078046 */
    c_wr32(ram, in_r15 - 8, in_r13);    /* 8c078048 mov.l r13,@-r15 */
    r14 = 0x1BB0u;                      /* 8c07804a mov.w */
    r6 = c_rd32(ram, X + 16);           /* 8c07804c mov.l @(8,r15),r6 */
    r14 += r5;                          /* 8c07804e */
    r14 += r7;                          /* 8c078050 */
    r14 = (uint32_t)(uint8_t)c_rd8s(ram, r14); /* 8c078052 mov.b */
    r14 &= 0xFFu;                       /* 8c078054 extu.b */
    T = (r14 == 0);                     /* 8c078056 tst r14,r14 */
    r4 &= r6;                           /* 8c07805a delay (always) */
    if (!T)
        goto L_8090;                    /* 8c078058 bf/s */
    T = (r4 == 0);                      /* 8c07805c tst r4,r4 */
    if (T)
        goto L_807c;                    /* 8c07805e bt */
    r0 = r4;                            /* 8c078060 */
    T = (r0 == 15);                     /* 8c078062 cmp/eq #15 */
    if (T)
        goto L_807c;                    /* 8c078064 bt */
    r2 = 0x1BB0u;                       /* 8c078066 mov.w */
    r3 = 1;                             /* 8c078068 */
    r2 += r5;                           /* 8c07806a */
    r2 += r7;                           /* 8c07806c */
    c_wr8(ram, r2, (uint8_t)r3);        /* 8c07806e mov.b r3,@r2 */
    r3 = (uint32_t)(int32_t)-16;        /* 8c078070 */
    r2 = 0x1BB2u;                       /* 8c078072 mov.w */
    r6 &= (uint32_t)r3;                 /* 8c078074 and r3,r6 */
    r2 += r5;                           /* 8c078076 */
    r2 += r7;                           /* 8c078078 */
    c_wr8(ram, r2, (uint8_t)r4);        /* 8c07807a mov.b r4,@r2 */
L_807c:
    r0 = 0x1B83u;                       /* 8c07807c mov.w */
    r3 = 0x1BB4u;                       /* 8c07807e mov.w */
    r4 = (uint32_t)(uint8_t)c_rd8s(ram, r5 + r0); /* 8c078080 mov.b */
    r0 += 51;                           /* 8c078082 -> 0x1bb6 */
    r3 += r5;                           /* 8c078084 */
    r7 += r3;                           /* 8c078086 add r3,r7 */
    r4 &= 0xFFu;                        /* 8c078088 extu.b */
    c_wr8(ram, r7, (uint8_t)r4);        /* 8c07808a mov.b r4,@r7 */
    c_wr8(ram, r5 + r0, (uint8_t)r4);   /* 8c07808e delay (always) */
    goto L_8108;                        /* 8c07808c bra */
L_8090:
    r13 = 0x1BB2u;                      /* 8c078090 mov.w */
    r3 = 0x40000000u;                   /* 8c078092 mov.l pool value */
    r13 += r5;                          /* 8c078094 */
    r2 = c_rd32(ram, X + 20);           /* 8c078096 mov.l @(12,r15),r2 */
    r13 += r7;                          /* 8c078098 */
    r13 = (uint32_t)(uint8_t)c_rd8s(ram, r13); /* 8c07809a mov.b */
    T = ((r3 & r2) == 0);               /* 8c07809c tst r3,r2 */
    r13 &= 0xFFu;                       /* 8c0780a0 delay (always) */
    if (!T)
        goto L_80c8;                    /* 8c07809e bf/s */
    r0 = r13;                           /* 8c0780a2 */
    T = (r0 == 4);                      /* 8c0780a4 cmp/eq #4 */
    if (!T)
        goto L_80c8;                    /* 8c0780a6 bf */
    r0 = c_rd32(ram, X + 24);           /* 8c0780a8 mov.l @(16,r15),r0 */
    T = ((r0 & 4) == 0);                /* 8c0780aa tst #4,r0 */
    if (!T)
        goto L_80c8;                    /* 8c0780ac bf */
    r0 = r4;                            /* 8c0780ae */
    T = (r0 == 1);                      /* 8c0780b0 cmp/eq #1 */
    if (!T)
        goto L_80c8;                    /* 8c0780b2 bf */
    r0 = 0x1B83u;                       /* 8c0780b4 mov.w */
    r3 = 0x1BB4u;                       /* 8c0780b6 mov.w */
    r14 = (uint32_t)(uint8_t)c_rd8s(ram, r5 + r0); /* 8c0780b8 mov.b */
    r0 += 51;                           /* 8c0780ba -> 0x1bb6 */
    r3 += r5;                           /* 8c0780bc */
    r7 += r3;                           /* 8c0780be add r3,r7 */
    r14 &= 0xFFu;                       /* 8c0780c0 extu.b */
    c_wr8(ram, r3, (uint8_t)r14);       /* 8c0780c2 mov.b */
    c_wr8(ram, r5 + r0, (uint8_t)r14);  /* 8c0780c6 delay (always) */
    goto L_80fc;                        /* 8c0780c4 bra */
L_80c8:
    r0 = r13;                           /* 8c0780c8 */
    T = (r0 == 6);                      /* 8c0780ca cmp/eq #6 */
    if (!T)
        goto L_80da;                    /* 8c0780cc bf */
    r0 = c_rd32(ram, X + 24);           /* 8c0780ce mov.l @(16,r15),r0 */
    r0 &= 15u;                          /* 8c0780d0 and #15,r0 */
    T = (r0 == 2);                      /* 8c0780d2 cmp/eq #2 */
    if (!T)
        goto L_80da;                    /* 8c0780d4 bf */
    r2 = 0x0100u;                       /* 8c0780d6 mov.w */
    r6 |= (uint32_t)r2;                 /* 8c0780d8 or r2,r6 */
L_80da:
    r4 |= r13;                          /* 8c0780da or r13,r4 */
    r0 = r4;                            /* 8c0780dc */
    T = (r0 == 15);                     /* 8c0780de cmp/eq #15 */
    if (T)
        goto L_80fc;                    /* 8c0780e0 bt */
    r14 -= 1;                           /* 8c0780e2 dt r14 */
    T = (r14 == 0);
    if (T)
        goto L_80fc;                    /* 8c0780e4 bt */
    r3 = 0x1BB0u;                       /* 8c0780e6 mov.w */
    r3 += r5;                           /* 8c0780e8 */
    r7 += r3;                           /* 8c0780ea add r3,r7 */
    c_wr8(ram, r3, (uint8_t)r14);       /* 8c0780ec mov.b r14,@r3 */
    r3 = (uint32_t)(int32_t)-16;        /* 8c0780ee */
    r2 = 0x1BB2u;                       /* 8c0780f0 mov.w */
    r2 += r5;                           /* 8c0780f2 */
    r7 += r2;                           /* 8c0780f4 add r2,r7 */
    c_wr8(ram, r7, (uint8_t)r4);        /* 8c0780f6 mov.b r4,@r7 */
    r6 &= (uint32_t)r3;                 /* 8c0780fa delay (always) */
    goto L_8108;                        /* 8c0780f8 bra */
L_80fc:
    r1 = 0x1BB0u;                       /* 8c0780fc mov.w */
    r3 = 0;                             /* 8c0780fe */
    r6 |= r4;                           /* 8c078100 or r4,r6 */
    r1 += r5;                           /* 8c078102 */
    r7 += r1;                           /* 8c078104 add r1,r7 */
    c_wr8(ram, r7, (uint8_t)r3);        /* 8c078106 mov.b r3,@r7 */
L_8108:
    r13 = c_rd32(ram, X + 8);           /* 8c078108 pop r13 */
    r0 = r6;                            /* 8c07810a */
    r14 = c_rd32(ram, X + 12);          /* 8c07810e delay (pop r14) */

    o->r0 = r0;
    o->r3 = r3;
    o->r4 = r4;
    o->r6 = r6;
    o->r7 = r7;
    o->r15 = in_r15;
    o->sr = (sr & ~1u) | (T ? 1u : 0u);
    (void)r1;
    (void)r2;
    (void)r3;
}
