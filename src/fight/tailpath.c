/* See tailpath.h. All traffic goes through the replay map so the test
 * diffs the shadow against the oracle exit windows. */
#include "fight/tailpath.h"

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

void vf3_tailpath_8c076c00(uint32_t in_r4, uint32_t in_r5, uint32_t in_r6,
                           uint32_t in_r15, uint32_t in_pr, uint32_t in_sr,
                           vf3_tailpath_out *o, const vf3_ram_map *ram)
{
    uint32_t r0, r1, r2, r3;
    uint32_t r12, r13, r14;
    uint32_t X = in_r15 - 4 - 156;      /* sts.l pr + add r0(-156),r15 */
    int T;

    memset(o, 0, sizeof(*o));
    c_wr32(ram, in_r15 - 4, in_pr);     /* 8c076c00 sts.l pr,@-r15 */
    r0 = 0xFFFFFF9Cu;                   /* 8c076c02 mov.w 0xff64 (-156) */
    r3 = 0x98u;                         /* 8c076c04 */
    r3 += X;                            /* 8c076c08 -> X+0x98 */
    c_wr32(ram, r3, in_r4);             /* 8c076c0a */
    r2 = 0x94u;                         /* 8c076c0c */
    r2 += X;                            /* 8c076c0e -> X+0x94 */
    c_wr32(ram, r2, in_r5);             /* 8c076c10 */
    r3 = 0x90u;                         /* 8c076c12 */
    r3 += X;                            /* 8c076c14 -> X+0x90 */
    c_wr32(ram, r3, in_r6);             /* 8c076c16 */
    r0 = 0x8Cu;                         /* 8c076c18 */
    r2 = c_rd32(ram, 0x0C29B864u);      /* 8c076c1a mov.l pool value */
    c_wr32(ram, X + r0, r2);            /* 8c076c1c [X+0x8c] */
    r0 = 0x94u;                         /* 8c076c1e */
    r14 = c_rd32(ram, X + r0);          /* 8c076c20 (= in_r5) */
    r0 = 0x90u;                         /* 8c076c22 */
    r13 = c_rd32(ram, X + r0);          /* 8c076c24 (= in_r6) */
    r0 = 0x98u;                         /* 8c076c26 */
    r12 = c_rd32(ram, X + r0);          /* 8c076c28 (= in_r4) */
    r0 = 0x1B88u;                       /* 8c076c2a mov.w */
    r3 = c_rd32(ram, r14 + r0);         /* 8c076c2c */
    r0 = 0x88u;                         /* 8c076c2e */
    c_wr32(ram, X + r0, r3);            /* 8c076c30 [X+0x88] */
    r0 = 0x84u;                         /* 8c076c32 */
    r2 = c_rd32(ram, r14);              /* 8c076c34 */
    c_wr32(ram, X + r0, r2);            /* 8c076c36 [X+0x84] */
    r0 = 72;                            /* 8c076c38 */
    r3 = c_rd32(ram, r14 + r0);         /* 8c076c3a */
    r0 = 0x80u;                         /* 8c076c3c */
    c_wr32(ram, X + r0, r3);            /* 8c076c3e [X+0x80] */
    r0 = 97;                            /* 8c076c40 */
    r2 = (uint32_t)(int32_t)c_rd8s(ram, r14 + r0); /* 8c076c42 mov.b */
    r0 = 124;                           /* 8c076c44 */
    r3 = 0;                             /* 8c076c46 */
    r2 &= 0xFFu;                        /* 8c076c48 extu.b */
    r1 = r3;                            /* 8c076c4a */
    c_wr32(ram, X + r0, r2);            /* 8c076c4c [X+124] */
    r0 = 120;                           /* 8c076c4e */
    c_wr32(ram, X + r0, r3);            /* 8c076c50 [X+120] */
    c_wr32(ram, X + 56, r1);            /* 8c076c52 [X+56] */
    r0 = 0x1B80u;                       /* 8c076c54 mov.w */
    r3 = (uint32_t)(int32_t)c_rd8s(ram, r14 + r0); /* 8c076c56 mov.b */
    r3 &= 0xFFu;                        /* 8c076c58 extu.b */
    c_wr32(ram, X + 4, r3);             /* 8c076c5a [X+4] */
    r0 = 0x88u;                         /* 8c076c5c */
    r2 = 0x10000000u;                   /* 8c076c5e mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c076c60 [X+0x88] */
    T = ((r2 & r1) == 0);               /* 8c076c62 tst r2,r1 */
    if (T) {
        o->gated = 1;                   /* 8c076c64 bt -> path b */
        return;                         /* (test fails loud; see header) */
    }
    r0 = 0x88u;                         /* 8c076c66 */
    r1 = 0;                             /* 8c076c68 */
    r3 = r1;                            /* 8c076c6a */
    c_wr32(ram, X + r0, r1);            /* 8c076c6c [X+0x88] = 0 */
    r0 = 0x1B88u;                       /* 8c076c6e mov.w */
    c_wr32(ram, r14 + r0, r1);          /* 8c076c70 [r5+0x1b88] = 0 */
    r0 += 16;                           /* 8c076c72 -> 0x1b98 */
    c_wr32(ram, r14 + r0, r3);          /* 8c076c74 = 0 */
    r0 -= 8;                            /* 8c076c76 -> 0x1b90 */
    c_wr16(ram, r14 + r0, (uint16_t)r3);/* 8c076c78 mov.w = 0 */
    r0 += 12;                           /* 8c076c7a -> 0x1b9c */
    c_wr32(ram, r14 + r0, r3);          /* 8c076c7c = 0 */
    r0 += 20;                           /* 8c076c7e -> 0x1bb0 */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c076c80 mov.b = 0 */
    r0 += 1;                            /* 8c076c82 -> 0x1bb1 */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c076c84 mov.b = 0 */
    r0 = 0x1C00u;                       /* 8c076c86 mov.w */
    r3 = c_rd32(ram, X + 4);            /* 8c076c88 */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c076c8a mov.b [r5+1c00] */
    r3 = 0;                             /* 8c076c8c */
    r0 = 0x1C01u;                       /* 8c076c8e mov.w */
    r1 = c_rd32(ram, X + 4);            /* 8c076c90 */
    c_wr8(ram, r14 + r0, (uint8_t)r1);  /* 8c076c92 mov.b [r5+1c01] */
    r0 -= 127;                          /* 8c076c94 -> 0x1b82 */
    r1 = r3;                            /* 8c076c96 (= 0) */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c076c98 mov.b [r5+1b82] */
    r3 = 0x0C077E12u;                   /* 8c076c9a mov.l pool value */
    /* 8c076c9c jmp @r3 -> 0x8c077e12 (tail; delay nop) */
    r0 = 0x1B82u + 1;                   /* 8c077e12 add #1,r0 -> 0x1b83 */
    c_wr8(ram, r14 + r0, (uint8_t)r1);  /* 8c077e14 mov.b [r5+1b83] = 0 */
    r0 = 0x1B83u;                       /* 8c077e16 mov.w */
    r3 = (uint32_t)(int32_t)c_rd8s(ram, r14 + r0); /* 8c077e18 mov.b */
    r0 += 1;                            /* 8c077e1a -> 0x1b84 */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c077e1c mov.b */
    r0 -= 1;                            /* 8c077e1e -> 0x1b83 */
    r2 = (uint32_t)(int32_t)c_rd8s(ram, r14 + r0); /* 8c077e20 mov.b */
    r0 = 108;                           /* 8c077e22 */
    r2 &= 0xFFu;                        /* 8c077e24 extu.b */
    c_wr32(ram, X + r0, r2);            /* 8c077e26 [X+108] */
    r0 = 108;                           /* 8c077e28 */
    r3 = (uint32_t)(int32_t)c_rd8s(ram, X + r0); /* 8c077e2a mov.b */
    r0 = 0x1B85u;                       /* 8c077e2c mov.w */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c077e2e mov.b */
    r0 = 108;                           /* 8c077e30 */
    r2 = (uint32_t)(int32_t)c_rd8s(ram, X + r0); /* 8c077e32 mov.b */
    r0 = 0x1B86u;                       /* 8c077e34 mov.w */
    c_wr8(ram, r14 + r0, (uint8_t)r2);  /* 8c077e36 mov.b */
    r0 = 0x88u;                         /* 8c077e38 mov.w */
    r3 = c_rd32(ram, X + r0);           /* 8c077e3a [X+0x88] (= 0) */
    r0 = 0x1B88u;                       /* 8c077e3c mov.w */
    c_wr32(ram, r14 + r0, r3);          /* 8c077e3e [r5+0x1b88] */
    r1 = 0x9Cu;                         /* 8c077e40 mov.w */
    X += r1;                            /* 8c077e42 add r1,r15 */
    o->pr = c_rd32(ram, X);             /* 8c077e44 lds.l @r15+,pr */
    r12 = c_rd32(ram, X + 4);           /* 8c077e46 (caller spill) */
    r13 = c_rd32(ram, X + 8);           /* 8c077e48 (caller spill) */
    r14 = c_rd32(ram, X + 12);          /* 8c077e4a delay (caller spill) */

    o->r0 = r0;
    o->r1 = r1;
    o->r2 = r2;
    o->r3 = r3;
    o->r12 = r12;
    o->r13 = r13;
    o->r14 = r14;
    o->r15 = in_r15 + 12;
    o->sr = in_sr & ~1u;                /* T = 0 on path a */
}
