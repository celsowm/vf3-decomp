/* See f076c00.h. All traffic goes through the replay map so the test
 * diffs the shadow against the oracle exit windows. */
#include "fight/f076c00.h"
#include "fight/g78044.h"
#include "fight/g77e4e.h"

#include <stdio.h>
#include <stdlib.h>
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

#define SETT(v) do { T = (v) ? 1 : 0; } while (0)

/* Indexed pointer table at image 0x0C0F3A88 (words 0..15 verified against
 * extract/exe/1ST_READ.unsc.bin, file offset 0x0E3A88). Golden indices stay
 * <= 7; anything beyond the baked slice is a loud gate.
 * (kept local: the only two readers are the 076EB4/076EFC sites below). */
static const uint32_t c_tab_0f3a88[16] = {
    0x0C021020u, 0x0C023F08u, 0x0C031A54u, 0x0C025D14u,
    0x0C02CCC0u, 0x0C024DE8u, 0x0C02E8FCu, 0x0C03394Cu,
    0x0C032770u, 0x0C022A60u, 0x0C02DB78u, 0x0C0200A4u,
    0x0C021EF4u, 0x0F2A0F2Au, 0x00800080u, 0x00000100u
};

void vf3_f076c00_8c076c00(uint32_t in_r0, uint32_t in_r1, uint32_t in_r2,
                          uint32_t in_r3, uint32_t in_r4, uint32_t in_r5,
                          uint32_t in_r6, uint32_t in_r7, uint32_t in_r8,
                          uint32_t in_r9, uint32_t in_r10, uint32_t in_r11,
                          uint32_t in_r12, uint32_t in_r13, uint32_t in_r14,
                          uint32_t in_r15, uint32_t in_pr, uint32_t in_sr,
                          vf3_f076c00_out *o, const vf3_ram_map *ram)
{
    uint32_t r0 = in_r0, r1 = in_r1, r2 = in_r2, r3 = in_r3;
    uint32_t r4 = in_r4, r5 = in_r5, r6 = in_r6, r7 = in_r7;
    uint32_t r8 = in_r8, r9 = in_r9, r10 = in_r10, r11 = in_r11;
    uint32_t r12 = in_r12, r13 = in_r13, r14 = in_r14;
    uint32_t X = in_r15 - 4 - 156;      /* sts.l pr + add -156 */
    uint32_t sr = in_sr;
    int T = (in_sr & 1) != 0;

    (void)in_pr;
    memset(o, 0, sizeof(*o));
    c_wr32(ram, in_r15 - 4, in_pr);     /* 8c076c00 sts.l pr */
    /* prologue spills + struct setup [076C02, 076C64] */
    r0 = (uint32_t)(int32_t)(int16_t)0xFF64u; /* 8c076c02 mov.w (-156) */
    r3 = 0x98u;                         /* 8c076c04 */
    X = X;                              /* (frame; add applied above) */
    r3 += X;                            /* 8c076c08 -> X+0x98 */
    c_wr32(ram, r3, in_r4);             /* 8c076c0a */
    { r2 = 0x94u; } /* 8c076c0c */
    { r2 += X; } /* 8c076c0e -> X+0x94 */
    c_wr32(ram, r2, in_r5);             /* 8c076c10 */
    r3 = 0x90u;                         /* 8c076c12 */
    r3 += X;                            /* 8c076c14 -> X+0x90 */
    c_wr32(ram, r3, in_r6);             /* 8c076c16 */
    r0 = 0x8Cu;                         /* 8c076c18 */
    r2 = 0x0C29B864u;                   /* 8c076c1a mov.l pool literal */
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
    { r2 = c_rd32(ram, r14); } /* 8c076c34 */
    c_wr32(ram, X + r0, r2);            /* 8c076c36 [X+0x84] */
    r0 = 72;                            /* 8c076c38 */
    r3 = c_rd32(ram, r14 + r0);         /* 8c076c3a */
    r0 = 0x80u;                         /* 8c076c3c */
    c_wr32(ram, X + r0, r3);            /* 8c076c3e [X+0x80] */
    r0 = 97;                            /* 8c076c40 */
    { r2 = (uint32_t)(int32_t)c_rd8s(ram, r14 + r0); } /* 8c076c42 mov.b */
    r0 = 124;                           /* 8c076c44 */
    r3 = 0;                             /* 8c076c46 */
    { r2 &= 0xFFu; } /* 8c076c48 extu.b */
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
    { r2 = 0x10000000u; } /* 8c076c5e mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c076c60 [X+0x88] */
    T = ((r2 & r1) == 0);               /* 8c076c62 tst r2,r1 */
    if (T)
        goto L_cd8;                     /* 8c076c64 bt -> path b */
    /* path a: zeroing + tail setup [076C66, 076C9C] */
    r0 = 0x88u;                         /* 8c076c66 */
    r1 = 0;                             /* 8c076c68 */
    r3 = r1;                            /* 8c076c6a */
    c_wr32(ram, X + r0, r1);            /* 8c076c6c [X+0x88] = 0 */
    r0 = 0x1B88u;                       /* 8c076c6e mov.w */
    c_wr32(ram, r14 + r0, r1);          /* 8c076c70 = 0 */
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
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c076c8a mov.b */
    r3 = 0;                             /* 8c076c8c */
    r0 = 0x1C01u;                       /* 8c076c8e mov.w */
    r1 = c_rd32(ram, X + 4);            /* 8c076c90 */
    c_wr8(ram, r14 + r0, (uint8_t)r1);  /* 8c076c92 mov.b */
    r0 -= 127;                          /* 8c076c94 -> 0x1b82 */
    r1 = r3;                            /* 8c076c96 (= 0) */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c076c98 mov.b */
    r3 = 0x0C077E12u;                   /* 8c076c9a mov.l pool value */
    goto L_7e12;                        /* 8c076c9c jmp @r3 */
/* path b [076CD8, ...] */
L_cd8:
    r0 = 0x88u;                         /* 8c076cd8 mov.w */
    r3 = 0x40000000u;                   /* 8c076cda mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c076cdc [X+0x88] */
    T = ((r3 & r2) == 0);               /* 8c076cde tst r3,r2 */
    if (T)
        goto L_cec;                     /* 8c076ce0 bt */
    r0 = 0x88u;                         /* 8c076ce2 mov.w */
    { r2 = 0x20000000u; } /* 8c076ce4 mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c076ce6 [X+0x88] */
    r1 |= r2;                           /* 8c076cea delay (always) */
    goto L_cf4;                         /* 8c076ce8 bra */
L_cec:
    r0 = 0x88u;                         /* 8c076cec mov.w */
    { r2 = 0xDFFFFFFFu; } /* 8c076cee mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c076cf0 [X+0x88] */
    r1 &= r2;                           /* 8c076cf2 delay (always) */
L_cf4:
    r3 = 0xBFFFFFFFu;                   /* 8c076cf4 mov.l pool value */
    { r2 = r1; } /* 8c076cf6 */
    r0 = 0x88u;                         /* 8c076cf8 mov.w */
    { r2 &= r3; } /* 8c076cfa */
    c_wr32(ram, X + r0, r2);            /* 8c076cfc [X+0x88] */
    r0 = 0x1B9Cu;                       /* 8c076cfe mov.w */
    r1 = c_rd32(ram, r14 + r0);         /* 8c076d00 */
    T = (r1 == 0);                      /* 8c076d02 tst r1,r1 */
    if (T)
        goto L_d1c;                     /* 8c076d04 bt */
    r0 = 0x1BA0u;                       /* 8c076d06 mov.w */
    r1 = (uint32_t)c_rd16s(ram, r14 + r0); /* 8c076d08 mov.w */
    T = (r1 == 0);                      /* 8c076d0a tst r1,r1 */
    if (T)
        goto L_d16;                     /* 8c076d0c bt */
    r3 = (uint32_t)(uint16_t)c_rd16s(ram, r14 + r0); /* 8c076d0e mov.w */
    r3 += (uint32_t)-1;                 /* 8c076d10 */
    c_wr16(ram, r14 + r0, (uint16_t)r3);/* 8c076d14 delay (always) */
    goto L_d1c;                         /* 8c076d12 bra */
L_d16:
    r0 = 0x1B9Cu;                       /* 8c076d16 mov.w */
    r1 = 0;                             /* 8c076d18 */
    c_wr32(ram, r14 + r0, r1);          /* 8c076d1a */
L_d1c:
    r0 = 0x84u;                         /* 8c076d1c mov.w */
    r3 = 0x08000000u;                   /* 8c076d1e mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c076d20 [X+0x84] */
    T = ((r3 & r2) == 0);               /* 8c076d22 tst r3,r2 */
    if (T)
        goto L_d40;                     /* 8c076d24 bt */
    r0 = 0x1B98u;                       /* 8c076d26 mov.w */
    { r2 = 0; } /* 8c076d28 */
    r1 = r2;                            /* 8c076d2a */
    c_wr32(ram, r14 + r0, r2);          /* 8c076d2c */
    r0 -= 8;                            /* 8c076d2e -> 0x1b90 */
    c_wr16(ram, r14 + r0, (uint16_t)r1);/* 8c076d30 mov.w */
    r0 = 0x88u;                         /* 8c076d32 mov.w */
    { r2 = 0x40000000u; } /* 8c076d34 mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c076d36 [X+0x88] */
    r1 |= r2;                           /* 8c076d3a delay (always) */
    goto L_d3e_store;                   /* 8c076d3c bra 076e64 (via delay) */
L_d3e_store:
    c_wr32(ram, X + r0, r1);            /* 8c076d3e delay (always) */
    goto L_e64;
L_d40:
    r0 = 0x1B98u;                       /* 8c076d40 mov.w */
    r3 = c_rd32(ram, r14 + r0);         /* 8c076d42 */
    r0 = 112;                           /* 8c076d44 */
    c_wr32(ram, X + r0, r3);            /* 8c076d46 [X+112] */
    r0 = 0x208Au;                       /* 8c076d48 mov.w */
    { r2 = (uint32_t)c_rd16s(ram, r14 + r0); } /* 8c076d4a mov.w */
    T = ((int32_t)r2 > 0);              /* 8c076d4c cmp/pl r2 */
    if (!T)
        goto L_d5a;                     /* 8c076d4e bf */
    r0 = 0x80u;                         /* 8c076d50 mov.w */
    r3 = 0x00080000u;                   /* 8c076d52 mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c076d54 [X+0x80] */
    T = ((r3 & r2) == 0);               /* 8c076d56 tst r3,r2 */
    if (!T)
        goto L_de0;                     /* 8c076d58 bf */
L_d5a:
    r0 = 0x80u;                         /* 8c076d5a mov.w */
    r3 = 0x80000000u;                   /* 8c076d5c mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c076d5e [X+0x80] */
    T = ((r3 & r1) == 0);               /* 8c076d60 tst r3,r1 */
    if (!T)
        goto L_d68;                     /* 8c076d62 bf */
    goto L_e54;                         /* 8c076d64 bra */
L_d68:
    r0 = 0x80u;                         /* 8c076d68 mov.w */
    r3 = 0x08002000u;                   /* 8c076d6a mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c076d6c [X+0x80] */
    T = ((r3 & r2) == 0);               /* 8c076d6e tst r3,r2 */
    if (!T)
        goto L_d84;                     /* 8c076d70 bf */
    r0 = 0x80u;                         /* 8c076d72 mov.w */
    r3 = 0x20000000u;                   /* 8c076d74 mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c076d76 [X+0x80] */
    T = ((r3 & r1) == 0);               /* 8c076d78 tst r3,r1 */
    if (T)
        goto L_e2c;                     /* 8c076d7a bt */
    r0 = 0x208Au;                       /* 8c076d7c mov.w */
    r3 = (uint32_t)c_rd16s(ram, r14 + r0); /* 8c076d7e mov.w */
    T = ((int32_t)r3 > 0);              /* 8c076d80 cmp/pl r3 */
    if (T)
        goto L_e54;                     /* 8c076d82 bt */
L_d84:
    r0 = 0x1BD0u;                       /* 8c076d84 mov.w */
    r3 = c_rd32(ram, r14 + r0);         /* 8c076d86 */
    T = (r3 == 0);                      /* 8c076d88 tst r3,r3 */
    if (!T)
        goto L_e2c;                     /* 8c076d8a bf */
    r0 = 0x1BD4u;                       /* 8c076d8c mov.w */
    r3 = c_rd32(ram, r14 + r0);         /* 8c076d8e */
    T = (r3 == 0);                      /* 8c076d90 tst r3,r3 */
    if (!T)
        goto L_e2c;                     /* 8c076d92 bf */
    r0 = 76;                            /* 8c076d94 */
    r3 = 0x2000u;                       /* 8c076d96 mov.w */
    { r2 = c_rd32(ram, r14 + r0); } /* 8c076d98 */
    T = ((r3 & r2) == 0);               /* 8c076d9a tst r3,r2 */
    if (!T)
        goto L_e54;                     /* 8c076d9c bf */
    r1 = c_rd32(ram, r14 + r0);         /* 8c076d9e */
    r3 = 0x0400u;                       /* 8c076da0 mov.w */
    T = ((r3 & r1) == 0);               /* 8c076da2 tst r3,r1 */
    if (!T)
        goto L_e64;                     /* 8c076da4 bf */
    goto L_e2c;                         /* 8c076da6 bra */
L_de0:
    r0 = 0x80u;                         /* 8c076de0 mov.w */
    r3 = 0x00800000u;                   /* 8c076de2 mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c076de4 [X+0x80] */
    T = ((r3 & r2) == 0);               /* 8c076de6 tst r3,r2 */
    if (!T)
        goto L_e2c;                     /* 8c076de8 bf */
    r0 = 0x84u;                         /* 8c076dea mov.w */
    r3 = 13;                            /* 8c076dec */
    r1 = c_rd32(ram, X + r0);           /* 8c076dee [X+0x84] */
    r0 = 108;                           /* 8c076df0 */
    if (r3 >= 0)                        /* 8c076df2 shld r3,r1 */
        r1 <<= r3;
    else
        r1 = ((uint32_t)r1) >> (-(int32_t)r3);
    c_wr32(ram, X + r0, r1);            /* 8c076df4 [X+108] */
    r0 = 0x80u;                         /* 8c076df6 mov.w */
    { r2 = c_rd32(ram, X + r0); } /* 8c076df8 [X+0x80] */
    r0 = r1;                            /* 8c076dfa */
    r0 |= r2;                           /* 8c076dfc */
    { r2 = X; } /* 8c076dfe */
    { r2 += 108; } /* 8c076e00 */
    c_wr32(ram, r2, r0);                /* 8c076e02 */
    r1 = 0x80000000u;                   /* 8c076e04 mov.l pool value */
    T = ((r1 & r0) == 0);               /* 8c076e06 tst r1,r0 */
    if (T)
        goto L_e1a;                     /* 8c076e08 bt */
    r0 = 100;                           /* 8c076e0a */
    { r2 = (uint32_t)c_rd16s(ram, r14 + r0); } /* 8c076e0c mov.w */
    T = (r2 == 0);                      /* 8c076e0e tst r2,r2 */
    if (T)
        goto L_e2c;                     /* 8c076e10 bt */
    r1 = c_rd32(ram, r14 + 56);         /* 8c076e12 */
    r3 = 0x00040000u;                   /* 8c076e14 mov.l pool value */
    T = ((r3 & r1) == 0);               /* 8c076e16 tst r3,r1 */
    if (T)
        goto L_e2c;                     /* 8c076e18 bt */
L_e1a:
    r0 = 76;                            /* 8c076e1a */
    r3 = 0x0800u;                       /* 8c076e1c mov.w */
    { r2 = c_rd32(ram, r14 + r0); } /* 8c076e1e */
    T = ((r3 & r2) == 0);               /* 8c076e20 tst r3,r2 */
    if (!T)
        goto L_e2c;                     /* 8c076e22 bf */
    r0 = 112;                           /* 8c076e24 */
    r1 = c_rd32(ram, X + r0);           /* 8c076e26 [X+112] */
    T = (r1 == 0);                      /* 8c076e28 tst r1,r1 */
    if (T)
        goto L_e64;                     /* 8c076e2a bt */
L_e2c:
    r0 = 0x88u;                         /* 8c076e2c mov.w */
    r3 = 0x40000000u;                   /* 8c076e2e mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c076e30 [X+0x88] */
    r0 = 0x88u;                         /* 8c076e32 mov.w */
    r1 |= r3;                           /* 8c076e34 */
    c_wr32(ram, X + r0, r1);            /* 8c076e36 [X+0x88] */
    r0 = 76;                            /* 8c076e38 */
    { r2 = c_rd32(ram, r14 + r0); } /* 8c076e3a */
    r0 = 108;                           /* 8c076e3c */
    c_wr32(ram, X + r0, r2);            /* 8c076e3e [X+108] */
    r0 = 108;                           /* 8c076e40 */
    r1 = c_rd32(ram, X + r0);           /* 8c076e42 [X+108] */
    { r2 = 0x00200000u; } /* 8c076e44 mov.l pool value */
    T = ((r2 & r1) == 0);               /* 8c076e46 tst r2,r1 */
    if (!T)
        goto L_e54;                     /* 8c076e48 bf */
    r0 = 108;                           /* 8c076e4a */
    r1 = 0x00100000u;                   /* 8c076e4c mov.l pool value */
    r0 = c_rd32(ram, X + r0);           /* 8c076e4e [X+108] */
    T = ((r1 & r0) == 0);               /* 8c076e50 tst r1,r0 */
    if (T)
        goto L_f08;                     /* 8c076e52 bt */
L_e54:
    r0 = 112;                           /* 8c076e54 */
    { r2 = c_rd32(ram, X + r0); } /* 8c076e56 [X+112] */
    T = (r2 == 0);                      /* 8c076e58 tst r2,r2 */
    if (T)
        goto L_e64;                     /* 8c076e5a bt */
    r0 = 0x1B90u;                       /* 8c076e5c mov.w */
    { r2 = (uint32_t)c_rd16s(ram, r14 + r0); } /* 8c076e5e mov.w */
    T = (r2 == 0);                      /* 8c076e60 tst r2,r2 */
    if (!T)
        goto L_f08;                     /* 8c076e62 bf */
L_e64:
    r0 = 124;                           /* 8c076e64 */
    r0 = c_rd32(ram, X + r0);           /* 8c076e66 [X+124] */
    T = (r0 == 8);                      /* 8c076e68 cmp/eq #8 */
    if (!T)
        goto L_ef4;                     /* 8c076e6a bf */
    r0 = 0x80u;                         /* 8c076e6c mov.w */
    r3 = 0x00080000u;                   /* 8c076e6e mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c076e70 [X+0x80] */
    T = ((r3 & r2) == 0);               /* 8c076e72 tst r3,r2 */
    if (!T)
        goto L_ef4;                     /* 8c076e74 bf */
    r0 = 0x80u;                         /* 8c076e76 mov.w */
    { r2 = 0x08000000u; } /* 8c076e78 mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c076e7a [X+0x80] */
    T = ((r2 & r1) == 0);               /* 8c076e7c tst r2,r1 */
    if (!T)
        goto L_ef4;                     /* 8c076e7e bf */
    r0 = 0x80u;                         /* 8c076e80 mov.w */
    r1 = 0x80000000u;                   /* 8c076e82 mov.l pool value */
    r0 = c_rd32(ram, X + r0);           /* 8c076e84 [X+0x80] */
    T = ((r1 & r0) == 0);               /* 8c076e86 tst r1,r0 */
    if (!T)
        goto L_ef4;                     /* 8c076e88 bf */
    { r2 = 0x80u; } /* 8c076e8a mov.w */
    { r2 += X; } /* 8c076e8c */
    r0 = c_rd32(ram, r2);               /* 8c076e8e */
    T = ((r0 & 64) == 0);               /* 8c076e90 tst #64,r0 */
    if (T)
        goto L_e9a;                     /* 8c076e92 bt */
    r1 = 0x0C03340Du;                   /* 8c076e94 mov.l pool value */
    goto L_ea6;                         /* 8c076e96 bra */
L_e9a:
    { r2 = 0x80u; } /* 8c076e9a mov.w */
    { r2 += X; } /* 8c076e9c */
    r0 = c_rd32(ram, r2);               /* 8c076e9e */
    T = ((r0 & 32) == 0);               /* 8c076ea0 tst #32,r0 */
    if (T)
        goto L_eac;                     /* 8c076ea2 bt */
    r1 = 0x0C0334A9u;                   /* 8c076ea4 mov.l pool value */
L_ea6:
    r0 = 112;                           /* 8c076eaa */
    c_wr32(ram, X + r0, r1);            /* 8c076eaa delay (always) */
    goto L_f02;                         /* 8c076ea8 bra */
L_eac:
    r0 = 124;                           /* 8c076eac */
    { r2 = c_rd32(ram, X + r0); } /* 8c076eae [X+124] */
    r0 = 0x0C0F3A88u;                   /* 8c076eb0 mov.l pool value */
    { r2 <<= 2; } /* 8c076eb2 shll2 */
    if ((r2 >> 2) < 16)
        r3 = c_tab_0f3a88[r2 >> 2];     /* 8c076eb4 image table 0x0C0F3A88 */
    else {
        o->gated = 30;
        return;
    }
    r0 = 112;                           /* 8c076eb6 */
    c_wr32(ram, X + r0, r3);            /* 8c076eba delay (always) */
    goto L_f02;                         /* 8c076eb8 bra */
L_ef4:
    r0 = 124;                           /* 8c076ef4 */
    r1 = c_rd32(ram, X + r0);           /* 8c076ef6 [X+124] */
    r0 = 0x0C0F3A88u;                   /* 8c076ef8 mov.l pool value */
    r1 <<= 2;                           /* 8c076efa shll2 */
    if ((r1 >> 2) < 16)
        r3 = c_tab_0f3a88[r1 >> 2];     /* 8c076efc image table 0x0C0F3A88 */
    else {
        o->gated = 31;
        return;
    }
    r0 = 112;                           /* 8c076efe */
    c_wr32(ram, X + r0, r3);            /* 8c076f00 */
L_f02:
    r0 = 0x1B98u;                       /* 8c076f02 mov.w */
    { r2 = 0; } /* 8c076f04 */
    c_wr32(ram, r14 + r0, r2);          /* 8c076f06 */
    r0 = 0x1B82u;                       /* 8c076f08 mov.w */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c076f0a mov.b */
    r3 &= 0xFFu;                        /* 8c076f0c extu.b */
    c_wr32(ram, X + 32, r3);            /* 8c076f0e [X+32] */
    r3 <<= 2;                           /* 8c076f10 shll2 */
    { r2 = 0x00FCu; } /* 8c076f12 mov.w */
    r3 &= r2;                           /* 8c076f14 */
    c_wr32(ram, X + 20, r3);            /* 8c076f16 [X+20] */
    goto L_6f18;                        /* (076f16 fallthrough to 076f18) */
L_6f18:
    r0 = c_rd32(ram, X + 32);           /* 8c076f18 */
    r0 += (uint32_t)-1;                 /* 8c076f1a */
    r0 <<= 2;                           /* 8c076f1c shll2 */
    r0 &= 252u;                         /* 8c076f1e and #252,r0 */
    r3 = r0;                            /* 8c076f20 */
    c_wr32(ram, X, r0);                 /* 8c076f22 [X] */
    { r2 = 0x1C00u; } /* 8c076f24 mov.w */
    r0 = 88;                            /* 8c076f26 */
    { r2 += r14; } /* 8c076f28 */
    { r2 += r3; } /* 8c076f2a */
    r1 = (uint32_t)(uint8_t)c_rd8s(ram, r2); /* 8c076f2c mov.b */
    r1 &= 0xFFu;                        /* 8c076f2e extu.b */
    c_wr32(ram, X + r0, r1);            /* 8c076f30 [X+88] */
    r1 = X;                             /* 8c076f32 */
    { r2 = 0x1C00u; } /* 8c076f34 mov.w */
    r1 += 84;                           /* 8c076f36 */
    r3 = c_rd32(ram, X);                /* 8c076f38 */
    { r2 += r14; } /* 8c076f3a */
    { r2 += r3; } /* 8c076f3c */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, r2 + 1); /* 8c076f3e mov.b */
    r0 &= 0xFFu;                        /* 8c076f40 extu.b */
    c_wr32(ram, r1, r0);                /* 8c076f42 */
    r0 = 88;                            /* 8c076f44 */
    { r2 = c_rd32(ram, X + r0); } /* 8c076f46 [X+88] */
    r1 = c_rd32(ram, X + 4);            /* 8c076f48 [X+4] */
    { r2 = ~r2; } /* 8c076f4a not r2,r2 */
    r0 = 80;                            /* 8c076f4c */
    { r2 &= r1; } /* 8c076f4e */
    c_wr32(ram, X + r0, r2);            /* 8c076f50 [X+80] */
    r0 = 80;                            /* 8c076f52 */
    r1 = 0x1C00u;                       /* 8c076f54 mov.w */
    r3 = c_rd32(ram, X + 20);           /* 8c076f56 [X+20] */
    { r2 = c_rd32(ram, X + 4); } /* 8c076f58 [X+4] */
    r1 += r14;                          /* 8c076f5a */
    r1 += r3;                           /* 8c076f5c */
    c_wr8(ram, r1, (uint8_t)r2);        /* 8c076f5e mov.b r2,@r1 */
    r1 = 0x1C00u;                       /* 8c076f60 mov.w */
    r3 = c_rd32(ram, X + 20);           /* 8c076f62 [X+20] */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, X + r0); /* 8c076f64 mov.b */
    r1 += r14;                          /* 8c076f66 */
    r1 += r3;                           /* 8c076f68 */
    c_wr8(ram, r1 + 2, r0);             /* 8c076f6a mov.b r0,@(2,r1) */
    r0 = 88;                            /* 8c076f6c */
    r3 = c_rd32(ram, X + 4);            /* 8c076f6e [X+4] */
    { r2 = c_rd32(ram, X + r0); } /* 8c076f70 [X+88] */
    r3 = ~r3;                           /* 8c076f72 not r3,r3 */
    r3 &= r2;                           /* 8c076f74 */
    c_wr32(ram, X + 60, r3);            /* 8c076f76 [X+60] */
    { r2 = 0x1C00u; } /* 8c076f78 mov.w */
    r3 = c_rd32(ram, X + 20);           /* 8c076f7a [X+20] */
    r0 = c_rd32(ram, X + 60);           /* 8c076f7c [X+60] */
    { r2 += r14; } /* 8c076f7e */
    { r2 += r3; } /* 8c076f80 */
    c_wr8(ram, r2 + 3, (uint8_t)r0);    /* 8c076f82 mov.b */
    r0 = 76;                            /* 8c076f84 */
    r3 = c_rd32(ram, X + 4);            /* 8c076f86 [X+4] */
    c_wr32(ram, X + r0, r3);            /* 8c076f88 [X+76] */
    r0 = c_rd32(ram, X + 4);            /* 8c076f8a [X+4] */
    T = ((r0 & 192) == 0);              /* 8c076f8c tst #192,r0 */
    if (!T)
        goto L_fa4;                     /* 8c076f8e bf */
    { r2 = X; } /* 8c076f90 */
    r1 = X;                             /* 8c076f92 */
    { r2 += 84; } /* 8c076f94 */
    r1 += 76;                           /* 8c076f96 */
    r0 = c_rd32(ram, r2);               /* 8c076f98 */
    r3 = c_rd32(ram, r1);               /* 8c076f9a */
    r0 &= 192u;                         /* 8c076f9c and #192,r0 */
    r3 |= r0;                           /* 8c076f9e */
    r0 = 76;                            /* 8c076fa0 */
    c_wr32(ram, X + r0, r3);            /* 8c076fa2 [X+76] */
L_fa4:
    { r2 = X; } /* 8c076fa4 */
    { r2 += 76; } /* 8c076fa6 */
    r0 = c_rd32(ram, r2);               /* 8c076fa8 */
    T = ((r0 & 48) == 0);               /* 8c076faa tst #48,r0 */
    if (!T)
        goto L_fc2;                     /* 8c076fac bf */
    r1 = X;                             /* 8c076fae */
    { r2 = X; } /* 8c076fb0 */
    r1 += 84;                           /* 8c076fb2 */
    { r2 += 76; } /* 8c076fb4 */
    r0 = c_rd32(ram, r1);               /* 8c076fb6 */
    r3 = c_rd32(ram, r2);               /* 8c076fb8 */
    r0 &= 48u;                          /* 8c076fba and #48,r0 */
    r3 |= r0;                           /* 8c076fbc */
    r0 = 76;                            /* 8c076fbe */
    c_wr32(ram, X + r0, r3);            /* 8c076fc0 [X+76] */
L_fc2:
    r1 = 0x1C00u;                       /* 8c076fc2 mov.w */
    r0 = 76;                            /* 8c076fc4 */
    r3 = c_rd32(ram, X + 20);           /* 8c076fc6 [X+20] */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, X + r0); /* 8c076fc8 mov.b */
    r1 += r14;                          /* 8c076fca */
    r1 += r3;                           /* 8c076fcc */
    c_wr8(ram, r1 + 1, r0);             /* 8c076fce mov.b */
    r0 = 0x8Cu;                         /* 8c076fd0 mov.w */
    { r2 = 0x0F000000u; } /* 8c076fd2 mov.l pool value */
    r3 = c_rd32(ram, X + r0);           /* 8c076fd4 [X+0x8c] */
    r1 = c_rd32(ram, r3 + 4);           /* 8c076fd6 [0x0c29b868] */
    T = ((r2 & r1) == 0);               /* 8c076fd8 tst r2,r1 */
    if (T)
        goto L_ff4;                     /* 8c076fda bt */
    r0 = c_rd32(ram, X + 4);            /* 8c076fdc [X+4] */
    r1 = X;                             /* 8c076fde */
    r1 += 80;                           /* 8c076fe0 */
    r0 &= 16u;                          /* 8c076fe2 and #16,r0 */
    c_wr32(ram, X + 4, r0);             /* 8c076fe4 [X+4] */
    r0 = 80;                            /* 8c076fe6 */
    r0 = c_rd32(ram, X + r0);           /* 8c076fe8 [X+80] */
    r0 &= 16u;                          /* 8c076fea and #16,r0 */
    c_wr32(ram, r1, r0);                /* 8c076fec */
    r0 = c_rd32(ram, X + 60);           /* 8c076fee [X+60] */
    r0 &= 16u;                          /* 8c076ff0 and #16,r0 */
    c_wr32(ram, X + 60, r0);            /* 8c076ff2 [X+60] */
L_ff4:
    { r2 = c_rd32(ram, X + 32); } /* 8c076ff4 */
    { r2 += 1; } /* 8c076ff6 */
    r0 = r2;                            /* 8c076ff8 */
    r0 &= 63u;                          /* 8c076ffa and #63,r0 */
    r3 = r0;                            /* 8c076ffc */
    c_wr32(ram, X + 32, r0);            /* 8c076ffe [X+32] */
    r0 = 0x1B82u;                       /* 8c077000 mov.w */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c077002 mov.b */
    r3 = 63;                            /* 8c077004 */
    { r2 = c_rd32(ram, X + 32); } /* 8c077006 [X+32] */
    r0 = 88;                            /* 8c077008 */
    { r2 += 1; } /* 8c07700a */
    { r2 &= r3; } /* 8c07700c */
    c_wr32(ram, X + r0, r2);            /* 8c07700e [X+88] */
    r0 = 0x1B84u;                       /* 8c077010 mov.w */
    { r2 = c_rd32(ram, X + 32); } /* 8c077012 [X+32] */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077014 mov.b */
    r3 &= 0xFFu;                        /* 8c077016 extu.b */
    T = (r2 == r3);                     /* 8c077018 cmp/eq r2,r3 */
    if (!T)
        goto L_7024;                    /* 8c07701a bf */
    r0 = 88;                            /* 8c07701c */
    r1 = (uint32_t)(uint8_t)c_rd8s(ram, X + r0); /* 8c07701e mov.b */
    r0 = 0x1B84u;                       /* 8c077020 mov.w */
    c_wr8(ram, r14 + r0, (uint8_t)r1);  /* 8c077022 mov.b */
L_7024:
    r0 = 0x1B85u;                       /* 8c077024 mov.w */
    { r2 = c_rd32(ram, X + 32); } /* 8c077026 [X+32] */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077028 mov.b */
    r3 &= 0xFFu;                        /* 8c07702a extu.b */
    T = (r2 == r3);                     /* 8c07702c cmp/eq r2,r3 */
    if (!T)
        goto L_7038;                    /* 8c07702e bf */
    r0 = 88;                            /* 8c077030 */
    r1 = (uint32_t)(uint8_t)c_rd8s(ram, X + r0); /* 8c077032 mov.b */
    r0 = 0x1B85u;                       /* 8c077034 mov.w */
    c_wr8(ram, r14 + r0, (uint8_t)r1);  /* 8c077036 mov.b */
L_7038:
    r0 = 0x1B86u;                       /* 8c077038 mov.w */
    { r2 = c_rd32(ram, X + 32); } /* 8c07703a [X+32] */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c07703c mov.b */
    r3 &= 0xFFu;                        /* 8c07703e extu.b */
    T = (r2 == r3);                     /* 8c077040 cmp/eq r2,r3 */
    if (!T)
        goto L_704c;                    /* 8c077042 bf */
    r0 = 88;                            /* 8c077044 */
    r1 = (uint32_t)(uint8_t)c_rd8s(ram, X + r0); /* 8c077046 mov.b */
    r0 = 0x1B86u;                       /* 8c077048 mov.w */
    c_wr8(ram, r14 + r0, (uint8_t)r1);  /* 8c07704a mov.b */
L_704c:
    r0 = 80;                            /* 8c07704c */
    r3 = c_rd32(ram, r14 + r0);         /* 8c07704e */
    r0 = 72;                            /* 8c077050 */
    c_wr32(ram, X + r0, r3);            /* 8c077052 [X+72] */
    r0 = 0x84u;                         /* 8c077054 mov.w */
    r3 = 0x40000000u;                   /* 8c077056 mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c077058 [X+0x84] */
    T = ((r3 & r2) == 0);               /* 8c07705a tst r3,r2 */
    goto L_7080;                        /* 8c07705c bra 077080 */
L_7080:
    if (T)
        goto L_708c;                    /* 8c077080 bt */
    { r2 = 0x80u; } /* 8c077082 mov.w */
    r0 = 68;                            /* 8c077084 */
    c_wr32(ram, X + r0, r2);            /* 8c077086 [X+68] = 0x80 */
    r1 = 64;                            /* 8c07708a delay (always) */
    goto L_7094;                        /* 8c077088 bra */
L_708c:
    r0 = 68;                            /* 8c07708c */
    { r2 = 64; } /* 8c07708e via 07708a-delay */
    c_wr32(ram, X + r0, r2);            /* 8c077090 [X+68] = 64 */
    r1 = 0x80u;                         /* 8c077092 mov.w */
L_7094:
    r0 = 64;                            /* 8c077094 (r1: path value) */
    c_wr32(ram, X + 64, r1);            /* 8c077096 [X+64] = r1 */
    r0 = 0x80u;                         /* 8c077098 mov.w */
    r3 = 0x80000000u;                   /* 8c07709a mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c07709c [X+0x80] */
    T = ((r3 & r2) == 0);               /* 8c07709e tst r3,r2 */
    if (T)
        goto L_70ba;                    /* 8c0770a0 bt */
    r1 = 0x80u;                         /* 8c0770a2 mov.w */
    r1 += X;                            /* 8c0770a4 */
    r0 = c_rd32(ram, r1);               /* 8c0770a6 [X+0x80] */
    T = ((r0 & 128) == 0);              /* 8c0770a8 tst #128,r0 */
    if (T)
        goto L_70ba;                    /* 8c0770aa bt */
    r0 = 80;                            /* 8c0770ac */
    { r2 = c_rd32(ram, X + r0); } /* 8c0770ae [X+80] */
    T = (r2 == 0);                      /* 8c0770b0 tst r2,r2 */
    if (T)
        goto L_70ba;                    /* 8c0770b2 bt */
    r3 = 0x1B000000u;                   /* 8c0770b4 mov.l pool value */
    goto L_72f6;                        /* 8c0770b6 bra 0772f6 */
L_70ba:
    r1 = c_rd32(ram, X + 4);            /* 8c0770ba [X+4] */
    r5 = r14;                           /* 8c0770bc */
    r6 = r13;                           /* 8c0770be */
    r7 = 0;                             /* 8c0770c0 */
    c_wr32(ram, X - 4, r1);             /* 8c0770c2 push r1 */
    r0 = 0x8Cu;                         /* 8c0770c4 mov.w */
    r3 = c_rd32(ram, X + 0x88);         /* 8c0770c6 [X+0x88] */
    r0 = 88;                            /* 8c0770c8 */
    c_wr32(ram, X - 8, r3);             /* 8c0770ca push r3 */
    { r2 = c_rd32(ram, X + 80); } /* 8c0770cc [X+80] */
    c_wr32(ram, X - 12, r2);            /* 8c0770ce push r2 */
    r3 = 0x0C078044u;                   /* 8c0770d0 mov.l pool value */
    { /* 8c0770d2 jsr @r3 (delay r4 = r12, pre-call) */
        vf3_g78044_out o1;
        uint32_t u1sr = (sr & ~1u) | (T ? 1u : 0u);
        memset(&o1, 0, sizeof(o1));
        vf3_g78044_8c078044(r12, r14, r13, 0, r13, r14, X - 12, u1sr,
                            &o1, ram);
        r0 = o1.r0; r3 = o1.r3; r4 = o1.r4;
        r6 = o1.r6; r7 = o1.r7;
        sr = o1.sr; SETT(sr & 1);
    }
    /* (8c0770d6 add #12,r15: no-op under absolute-X modeling) */
    r3 = r14;                           /* 8c0770d8 */
    r1 = X;                             /* 8c0770da */
    r1 += 80;                           /* 8c0770dc */
    c_wr32(ram, r1, r0);                /* 8c0770e0 [X+80] = r0 */
    r3 += 56;                           /* 8c0770de */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, r3 + 3); /* 8c0770e2 mov.b */
    r1 = X;                             /* 8c0770e4 */
    r1 += 104;                          /* 8c0770e6 */
    r0 &= 0xFFu;                        /* 8c0770e8 extu.b */
    c_wr32(ram, r1, r0);                /* 8c0770ea [X+104] */
    r0 = 0x1B98u;                       /* 8c0770ec mov.w */
    r3 = c_rd32(ram, r14 + r0);         /* 8c0770ee */
    r0 = 100;                           /* 8c0770f0 */
    c_wr32(ram, X + r0, r3);            /* 8c0770f2 [X+100] */
    r0 = 98;                            /* 8c0770f4 */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); } /* 8c0770f6 mov.b */
    r0 = 96;                            /* 8c0770f8 */
    { r2 &= 0xFFu; } /* 8c0770fa extu.b */
    c_wr32(ram, X + r0, r2);            /* 8c0770fc [X+96] */
    r0 = 104;                           /* 8c0770fe */
    r0 = c_rd32(ram, X + r0);           /* 8c077100 [X+104] */
    T = (r0 == 11);                     /* 8c077102 cmp/eq #11 */
    if (T)
        goto L_710a;                    /* 8c077104 bt */
    goto L_72fa;                        /* 8c077106 bra 0772fa */
L_710a:
    r0 = 100;                           /* 8c07710a */
    r1 = c_rd32(ram, X + r0);           /* 8c07710c [X+100] */
    T = (r1 == 0);                      /* 8c07710e tst r1,r1 */
    if (T)
        goto L_7116;                    /* 8c077110 bt */
    goto L_72fa;                        /* 8c077112 bra */
L_7116:
    r0 = 96;                            /* 8c077116 */
    r0 = c_rd32(ram, X + r0);           /* 8c077118 [X+96] */
    T = (r0 == 4);                      /* 8c07711a cmp/eq #4 */
    if (!T)
        goto L_7122;                    /* 8c07711c bf */
    goto L_72a0path;                    /* 8c07711e bra 0772a0 */
L_7122:
    r0 = 96;                            /* 8c077122 */
    r0 = c_rd32(ram, X + r0);           /* 8c077124 [X+96] */
    T = (r0 == 5);                      /* 8c077126 cmp/eq #5 */
    if (!T)
        goto L_712e;                    /* 8c077128 bf */
    goto L_72a0path;                    /* 8c07712a bra */
L_712e:
    r0 = 96;                            /* 8c07712e */
    { r2 = c_rd32(ram, X + r0); } /* 8c077130 [X+96] */
    r3 = 5;                             /* 8c077132 */
    T = (r2 > r3);                      /* 8c077134 cmp/hi r3,r2 */
    if (!T)
        goto L_713c;                    /* 8c077136 bf */
    goto L_7e38dir;                     /* 8c077138 bra 077e38 */
L_713c:
    r0 = 80;                            /* 8c07713c */
    r1 = c_rd32(ram, X + r0);           /* 8c07713e [X+80] */
    r3 = r1;                            /* 8c077140 */
    T = (r3 == 0);                      /* 8c077142 tst r3,r3 */
    c_wr32(ram, X + 48, r1);            /* 8c077146 delay (always) */
    if (T)
        goto L_714c;                    /* 8c077144 bt/s */
    r3 = 1;                             /* 8c077148 */
    c_wr32(ram, X + 48, r3);            /* 8c07714a [X+48] = 1 */
L_714c:
    r1 = X;                             /* 8c07714c */
    r1 += 80;                           /* 8c07714e */
    r3 = 0x0B000000u;                   /* 8c077150 mov.l pool value */
    { r2 = c_rd32(ram, X + 48); } /* 8c077152 [X+48] */
    { r2 += r3; } /* 8c077154 */
    c_wr32(ram, X + 56, r2);            /* 8c077156 [X+56] */
    r0 = c_rd32(ram, r1);               /* 8c077158 [X+80] */
    T = ((r0 & 2) == 0);                /* 8c07715a tst #2,r0 */
    if (T)
        goto L_7180;                    /* 8c07715c bt */
    r0 = 108;                           /* 8c07715e */
    r1 = 30;                            /* 8c077160 */
    c_wr32(ram, X + r0, r1);            /* 8c077162 [X+108] = 30 */
    r0 = c_rd32(ram, X + 4);            /* 8c077164 [X+4] */
    T = ((r0 & 16) == 0);               /* 8c077166 tst #16,r0 */
    if (T)
        goto L_7170;                    /* 8c077168 bt */
    r0 = 108;                           /* 8c07716a */
    r1 = 29;                            /* 8c07716c */
    c_wr32(ram, X + r0, r1);            /* 8c07716e [X+108] = 29 */
L_7170:
    r0 = 108;                           /* 8c077170 */
    { r2 = 0x80000000u; } /* 8c077172 mov.l pool value */
    r3 = c_rd32(ram, X + r0);           /* 8c077174 [X+108] */
    r1 = c_rd32(ram, X + 56);           /* 8c077176 [X+56] */
    r3 = -r3;                           /* 8c077178 neg r3,r3 */
    if ((int32_t)r3 >= 0)               /* 8c07717a shld r3,r2 */
        { r2 <<= r3; } 
    else
        { r2 = ((uint32_t)r2) >> (-(int32_t)r3); } 
    r1 |= r2;                           /* 8c07717c */
    c_wr32(ram, X + 56, r1);            /* 8c07717e [X+56] */
L_7180:
    { r2 = X; } /* 8c077180 */
    { r2 += 80; } /* 8c077182 */
    r0 = c_rd32(ram, r2);               /* 8c077184 [X+80] */
    T = ((r0 & 8) == 0);                /* 8c077186 tst #8,r0 */
    if (T)
        goto L_71ac;                    /* 8c077188 bt */
    r1 = c_rd32(ram, X + 48);           /* 8c07718a [X+48] */
    r3 = 0x0B000008u;                   /* 8c07718c mov.l pool value */
    r1 += r3;                           /* 8c077190 delay (always) */
    goto L_7284;                        /* 8c07718e bra 077284 */
L_71ac:
    { r2 = X; } /* 8c0771ac */
    { r2 += 80; } /* 8c0771ae */
    r0 = c_rd32(ram, r2);               /* 8c0771b0 [X+80] */
    T = ((r0 & 4) == 0);                /* 8c0771b2 tst #4,r0 */
    if (T)
        goto L_720e;                    /* 8c0771b4 bt */
    r0 = c_rd32(ram, X + 56);           /* 8c0771b6 [X+56] */
    r0 |= 64u;                          /* 8c0771b8 or #64,r0 */
    c_wr32(ram, X + 56, r0);            /* 8c0771ba [X+56] */
    r0 = c_rd32(ram, X + 4);            /* 8c0771bc [X+4] */
    r0 &= 240u;                         /* 8c0771be and #240,r0 */
    c_wr16(ram, X + 10, (uint16_t)r0);  /* 8c0771c0 mov.w r0,@(10,r15) */
    r0 &= 0xFFFFu;                      /* 8c0771c2 extu.w (into r0) */
    r0 = r0;                            /* (0771c2: extu.w r0,r0) */
    T = (r0 == 0);                      /* 8c0771c4 tst r0,r0 */
    if (T)
        goto L_7286;                    /* 8c0771c6 bt */
    r0 = (uint32_t)c_rd16s(ram, X + 10);/* 8c0771c8 mov.w @(10,r15),r0 */
    r0 &= 0xFFFFu;                      /* 8c0771ca extu.w */
    r0 >>= 2;                           /* 8c0771cc shlr2 */
    r0 >>= 2;                           /* 8c0771ce shlr2 */
    c_wr16(ram, X + 10, (uint16_t)r0);  /* 8c0771d0 mov.w */
    r0 &= 0xFFFFu;                      /* 8c0771d2 extu.w */
    r1 = 0x0C0F3A68u;                   /* 8c0771d4 mov.l pool value */
    r0 <<= 1;                           /* 8c0771d6 shll */
    r0 = (uint32_t)c_rd16s(ram, r1 + r0); /* 8c0771d8 mov.w @(r0,r1) */
    c_wr16(ram, X + 10, (uint16_t)r0);  /* 8c0771da mov.w */
    r0 = 0x1394u;                       /* 8c0771dc mov.w */
    r3 = (uint32_t)c_rd16s(ram, r14 + r0); /* 8c0771de mov.w */
    r0 = (uint32_t)c_rd16s(ram, X + 10);/* 8c0771e0 mov.w */
    r0 -= r3;                           /* 8c0771e2 sub r3,r0 */
    c_wr16(ram, X + 10, (uint16_t)r0);  /* 8c0771e4 mov.w */
    r3 = 0x0C29BBA4u;                   /* 8c0771e6 mov.l pool value */
    r1 = c_rd32(ram, r3);               /* 8c0771e8 */
    r0 = (uint32_t)c_rd16s(ram, r1 + 30); /* 8c0771ea mov.w @(30,r1) */
    { r2 = r0; } /* 8c0771ec */
    r0 = (uint32_t)c_rd16s(ram, X + 10);/* 8c0771ee mov.w */
    r0 += r2;                           /* 8c0771f0 add r2,r0 */
    c_wr16(ram, X + 10, (uint16_t)r0);  /* 8c0771f2 mov.w */
    r0 &= 0xFFFFu;                      /* 8c0771f4 extu.w */
    r1 = 0x00008000u;                   /* 8c0771f6 mov.l pool value */
    T = ((r1 & r0) == 0);               /* 8c0771f8 tst r1,r0 */
    if (T)
        goto L_7204;                    /* 8c0771fa bt */
    r0 = c_rd32(ram, X + 56);           /* 8c0771fc [X+56] */
    r0 |= 128u;                         /* 8c0771fe or #128,r0 */
    c_wr32(ram, X + 56, r0);            /* 8c077202 delay (always) */
    goto L_7286;                        /* 8c077200 bra 077286 */
L_7204:
    r1 = c_rd32(ram, X + 56);           /* 8c077204 [X+56] */
    { r2 = 0x0100u; } /* 8c077206 mov.w */
    r1 |= r2;                           /* 8c077208 */
    c_wr32(ram, X + 56, r1);            /* 8c07720c delay (always) */
    goto L_7286;                        /* 8c07720a bra */
L_720e:
    r3 = c_rd32(ram, X + 4);            /* 8c07720e [X+4] */
    c_wr32(ram, X + 44, r3);            /* 8c077210 [X+44] */
    { r2 = c_rd32(ram, r14 + 56); } /* 8c077212 */
    r3 = 0x00FFFFFEu;                   /* 8c077214 mov.l pool value */
    T = ((r3 & r2) == 0);               /* 8c077216 tst r3,r2 */
    if (T)
        goto L_7220;                    /* 8c077218 bt */
    r0 = 80;                            /* 8c07721a */
    r0 = c_rd32(ram, X + r0);           /* 8c07721c [X+80] */
    c_wr32(ram, X + 44, r0);            /* 8c07721e [X+44] */
L_7220:
    r0 = c_rd32(ram, X + 44);           /* 8c077220 [X+44] */
    T = ((r0 & 16) == 0);               /* 8c077222 tst #16,r0 */
    if (!T)
        goto L_724e;                    /* 8c077224 bf */
    r0 = c_rd32(ram, X + 44);           /* 8c077226 [X+44] */
    T = ((r0 & 32) == 0);               /* 8c077228 tst #32,r0 */
    if (!T)
        goto L_724e;                    /* 8c07722a bf */
    r0 = 64;                            /* 8c07722c */
    r3 = c_rd32(ram, X + 44);           /* 8c07722e [X+44] */
    { r2 = c_rd32(ram, X + r0); } /* 8c077230 [X+64] */
    T = ((r3 & r2) == 0);               /* 8c077232 tst r3,r2 */
    if (T)
        goto L_723c;                    /* 8c077234 bt */
    r0 = c_rd32(ram, X + 56);           /* 8c077236 [X+56] */
    r0 |= 32u;                          /* 8c07723a delay (always) */
    goto L_724a;                        /* 8c077238 bra */
L_723c:
    r0 = 68;                            /* 8c07723c */
    r3 = c_rd32(ram, X + 44);           /* 8c07723e [X+44] */
    { r2 = c_rd32(ram, X + r0); } /* 8c077240 [X+68] */
    T = ((r3 & r2) == 0);               /* 8c077242 tst r3,r2 */
    if (T)
        goto L_724e;                    /* 8c077244 bt */
    r0 = c_rd32(ram, X + 56);           /* 8c077246 [X+56] */
    r0 |= 16u;                          /* 8c077248 or #16,r0 */
L_724a:
    c_wr32(ram, X + 56, r0);            /* 8c07724c delay (always) */
    goto L_7286;                        /* 8c07724a bra */
L_724e:
    r3 = c_rd32(ram, X + 56);           /* 8c07724e [X+56] */
    c_wr32(ram, X + 52, r3);            /* 8c077250 [X+52] */
    r3 = (uint32_t)-2;                  /* 8c077252 */
    { r2 = c_rd32(ram, r14 + 56); } /* 8c077254 */
    r0 = c_rd32(ram, X + 48);           /* 8c077256 [X+48] */
    { r2 &= (uint32_t)r3; } /* 8c077258 and r3,r2 */
    r0 &= 1u;                           /* 8c07725a and #1,r0 */
    r0 |= r2;                           /* 8c07725c */
    c_wr32(ram, X + 56, r0);            /* 8c07725e [X+56] */
    r0 = c_rd32(ram, X + 52);           /* 8c077260 [X+52] */
    T = ((r0 & 4) == 0);                /* 8c077262 tst #4,r0 */
    if (!T)
        goto L_727a;                    /* 8c077264 bf */
    r0 = c_rd32(ram, X + 52);           /* 8c077266 [X+52] */
    T = ((r0 & 2) == 0);                /* 8c077268 tst #2,r0 */
    if (T)
        goto L_7286;                    /* 8c07726a bt */
    r0 = c_rd32(ram, X + 56);           /* 8c07726c [X+56] */
    r3 = (uint32_t)-5;                  /* 8c07726e */
    r0 |= 2u;                           /* 8c077270 or #2,r0 */
    r1 = r0;                            /* 8c077272 */
    c_wr32(ram, X + 56, r0);            /* 8c077274 [X+56] */
    r1 &= (uint32_t)r3;                 /* 8c077278 delay (always) */
    goto L_7284;                        /* 8c077276 bra */
L_727a:
    r0 = c_rd32(ram, X + 56);           /* 8c07727a [X+56] */
    r3 = (uint32_t)-3;                  /* 8c07727c */
    r0 |= 4u;                           /* 8c07727e or #4,r0 */
    r1 = r0;                            /* 8c077280 */
    r1 &= (uint32_t)r3;                 /* 8c077282 delay (always) */
L_7284:
    c_wr32(ram, X + 56, r1);            /* 8c077284 [X+56] */
    { r2 = c_rd32(ram, X + 56); } /* 8c077286 [X+56] */
    c_wr32(ram, r14 + 48, r2);          /* 8c077288 delay (always) */
    goto L_7e0c;                        /* 8c077288 bra 077e0c */
L_72a0path:
    r1 = X;                             /* 8c0772a0 */
    r1 += 80;                           /* 8c0772a2 */
    r0 = c_rd32(ram, r1);               /* 8c0772a4 [X+80] */
    T = ((r0 & 2) == 0);                /* 8c0772a6 tst #2,r0 */
    if (T)
        goto L_72fa;                    /* 8c0772a8 bt */
    { r2 = X; } /* 8c0772aa */
    { r2 += 80; } /* 8c0772ac */
    r0 = c_rd32(ram, r2);               /* 8c0772ae [X+80] */
    T = ((r0 & 1) == 0);                /* 8c0772b0 tst #1,r0 */
    if (!T)
        goto L_72fa;                    /* 8c0772b2 bf */
    r1 = X;                             /* 8c0772b4 */
    r1 += 80;                           /* 8c0772b6 */
    r0 = c_rd32(ram, r1);               /* 8c0772b8 [X+80] */
    T = ((r0 & 4) == 0);                /* 8c0772ba tst #4,r0 */
    if (!T)
        goto L_72fa;                    /* 8c0772bc bf */
    { r2 = X; } /* 8c0772be */
    { r2 += 80; } /* 8c0772c0 */
    r0 = c_rd32(ram, r2);               /* 8c0772c2 [X+80] */
    T = ((r0 & 8) == 0);                /* 8c0772c4 tst #8,r0 */
    if (!T)
        goto L_72fa;                    /* 8c0772c6 bf */
    r1 = c_rd32(ram, r14 + 56);         /* 8c0772c8 */
    r0 = r1;                            /* 8c0772ca */
    T = ((r0 & 14) == 0);               /* 8c0772cc tst #14,r0 */
    c_wr32(ram, X + 56, r1);            /* 8c0772ce delay (always) */
    if (!T)
        goto L_72fa;                    /* 8c0772d0 bf */
    r0 = 108;                           /* 8c0772d2 */
    r1 = 30;                            /* 8c0772d4 */
    c_wr32(ram, X + r0, r1);            /* 8c0772d6 [X+108] = 30 */
    r0 = c_rd32(ram, X + 4);            /* 8c0772d8 [X+4] */
    T = ((r0 & 16) == 0);               /* 8c0772da tst #16,r0 */
    if (T)
        goto L_72e4;                    /* 8c0772dc bt */
    r0 = 108;                           /* 8c0772de */
    r1 = 29;                            /* 8c0772e0 */
    c_wr32(ram, X + r0, r1);            /* 8c0772e2 [X+108] = 29 */
L_72e4:
    r0 = 108;                           /* 8c0772e4 */
    { r2 = 0x80000000u; } /* 8c0772e6 mov.l pool value */
    r3 = c_rd32(ram, X + r0);           /* 8c0772e8 [X+108] */
    r1 = c_rd32(ram, X + 56);           /* 8c0772ea [X+56] */
    r3 = -r3;                           /* 8c0772ec neg r3,r3 */
    if ((int32_t)r3 >= 0)               /* 8c0772ee shld r3,r2 */
        { r2 <<= r3; } 
    else
        { r2 = ((uint32_t)r2) >> (-(int32_t)r3); } 
    r1 |= r2;                           /* 8c0772f0 */
    r3 = r1;                            /* 8c0772f2 */
    c_wr32(ram, X + 56, r1);            /* 8c0772f4 [X+56] */
L_72f6:
    c_wr32(ram, r14 + 48, r3);          /* 8c0772f8 delay (always) */
    goto L_7e0e;                        /* 8c0772f6 bra 077e0e */
L_72fa:
    r1 = X;                             /* 8c0772fa */
    r1 += 80;                           /* 8c0772fc */
    r0 = c_rd32(ram, r1);               /* 8c0772fe [X+80] */
    T = ((r0 & 4) == 0);                /* 8c077300 tst #4,r0 */
    if (!T)
        goto L_7308;                    /* 8c077302 bf */
    goto L_746c;                        /* 8c077304 bra 07746c */
L_7308:
    { r2 = X; } /* 8c077308 */
    { r2 += 80; } /* 8c07730a */
    r0 = c_rd32(ram, r2);               /* 8c07730c [X+80] */
    T = ((r0 & 11) == 0);               /* 8c07730e tst #11,r0 */
    if (T)
        goto L_7316;                    /* 8c077310 bt */
    goto L_74c0;                        /* 8c077312 bra 0774c0 */
L_7316:
    r0 = 0x88u;                         /* 8c077316 mov.w */
    r3 = 0x7FFFFFFFu;                   /* 8c077318 mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c07731a [X+0x88] */
    r0 = 0x88u;                         /* 8c07731c mov.w */
    r1 &= r3;                           /* 8c07731e */
    c_wr32(ram, X + r0, r1);            /* 8c077320 [X+0x88] */
    r0 = 0x1B82u;                       /* 8c077322 mov.w */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); } /* 8c077324 mov.b */
    r0 += 1;                            /* 8c077326 -> 0x1b83 */
    c_wr8(ram, r14 + r0, (uint8_t)r2);  /* 8c077328 mov.b */
    r0 += 21;                           /* 8c07732a -> 0x1b98 */
    r1 = c_rd32(ram, r14 + r0);         /* 8c07732c */
    T = (r1 == 0);                      /* 8c07732e tst r1,r1 */
    if (T)
        goto L_734c;                    /* 8c077330 bt */
    r0 = 0x1B90u;                       /* 8c077332 mov.w */
    r1 = (uint32_t)c_rd16s(ram, r14 + r0); /* 8c077334 mov.w */
    T = (r1 == 0);                      /* 8c077336 tst r1,r1 */
    if (!T)
        goto L_73b6;                    /* 8c077338 bf */
    goto L_7360;                        /* 8c07733a bra 077360 */
L_734c:
    r0 = 0x88u;                         /* 8c07734c mov.w */
    { r2 = 0x40000000u; } /* 8c07734e mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c077350 [X+0x88] */
    T = ((r2 & r1) == 0);               /* 8c077352 tst r2,r1 */
    if (!T)
        goto L_73b6;                    /* 8c077354 bf */
    r0 = 0x80u;                         /* 8c077356 mov.w */
    r3 = 0x08000000u;                   /* 8c077358 mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c07735a [X+0x80] */
    T = ((r3 & r2) == 0);               /* 8c07735c tst r3,r2 */
    if (!T)
        goto L_73b6;                    /* 8c07735e bf */
L_7360:
    r0 = 120;                           /* 8c077360 */
    r1 = 4;                             /* 8c077362 */
    c_wr32(ram, X + r0, r1);            /* 8c077364 [X+120] = 4 */
    r0 = 80;                            /* 8c077366 */
    r3 = c_rd32(ram, X + r0);           /* 8c077368 [X+80] */
    r0 = 76;                            /* 8c07736a */
    c_wr32(ram, X - 4, r3);             /* 8c07736c push r3 */
    { r2 = c_rd32(ram, X + 4); } /* 8c07736e [X+4] */
    c_wr32(ram, X - 8, r2);             /* 8c077370 push r2 */
    r3 = c_rd32(ram, X + 68);           /* 8c077372 [X+68] */
    r0 = 76;                            /* 8c077374 */
    c_wr32(ram, X - 12, r3);            /* 8c077376 push r3 */
    { r2 = c_rd32(ram, X + 64); } /* 8c077378 [X+64] */
    r0 = 76;                            /* 8c07737a */
    c_wr32(ram, X - 16, r2);            /* 8c07737c push r2 */
    r0 = 0x90u;                         /* 8c07737c mov.w */
    r3 = c_rd32(ram, X + 0x80);         /* 8c07737e [X+0x80] */
    r0 = 92;                            /* 8c077380 */
    c_wr32(ram, X - 20, r3);            /* 8c077382 push r3 */
    { r2 = c_rd32(ram, X + 72); } /* 8c077384 [X+72] */
    c_wr32(ram, X - 24, r2);            /* 8c077386 push r2 */
    r3 = 0xA0u;                         /* 8c077388 mov.w */
    r3 += X - 24;                       /* 8c07738a (r15=X-24: X+0x88) */
    c_wr32(ram, X - 28, r3);            /* 8c07738c push r3 */
    r0 = 0xA0u;                         /* 8c07738e mov.w */
    { r2 = c_rd32(ram, X + 0x88); } /* 8c077390 [X+0x88] */
    c_wr32(ram, X - 32, r2);            /* 8c077392 push r2 */
    r3 = c_rd32(ram, X + 0x70);         /* 8c077394 [X+0x70] */
    c_wr32(ram, X - 36, r3);            /* 8c077396 push r3 */
    { r2 = c_rd32(ram, X + 0x60); } /* 8c077398 [X+0x60] */
    c_wr32(ram, X - 40, r2);            /* 8c07739c push r2 */
    r5 = r14;                           /* 8c07739e? (mov r14,r5) */
    r6 = r13;                           /* (mov r13,r6) */
    r7 = 0x9Cu;                         /* 8c0773a0 mov.w */
    r7 += X - 40;                       /* 8c0773a2 (r15=X-40: X+0x70) */
    /* 8c0773a8 bsr 0x8c0781ba: RARE-CALL GATE (0781BA ~0x in edges) */
    o->gated = 11;
    return;
L_73b6:
    r0 = 0x1BB4u;                       /* 8c0773b6 mov.w */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); } /* 8c0773b8 mov.b */
    r0 = 108;                           /* 8c0773ba */
    { r2 &= 0xFFu; } /* 8c0773bc extu.b */
    c_wr32(ram, X + r0, r2);            /* 8c0773be [X+108] */
    r0 = 108;                           /* 8c0773c0 */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, X + r0); /* 8c0773c2 mov.b */
    r0 = 0x1B84u;                       /* 8c0773c4 mov.w */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c0773c6 mov.b */
    r0 = 108;                           /* 8c0773c8 */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, X + r0); } /* 8c0773ca mov.b */
    r3 = 0;                             /* 8c0773cc */
    r0 = 0x1B85u;                       /* 8c0773ce mov.w */
    c_wr8(ram, r14 + r0, (uint8_t)r2);  /* 8c0773d0 mov.b */
    r0 += 19;                           /* 8c0773d2 -> 0x1b98 */
    c_wr32(ram, r14 + r0, r3);          /* 8c0773d4 = 0 */
    r0 -= 8;                            /* 8c0773d6 -> 0x1b90 */
    { r2 = r3; } /* 8c0773d8 (= 0) */
    c_wr16(ram, r14 + r0, (uint16_t)r2);/* 8c0773da mov.w = 0 */
    r0 = 60;                            /* 8c0773dc */
    r3 = (uint32_t)c_rd16s(ram, r14 + r0); /* 8c0773de mov.w */
    T = (r3 == 0);                      /* 8c0773e0 tst r3,r3 */
    if (T)
        goto L_73fa;                    /* 8c0773e2 bt */
    r0 = 62;                            /* 8c0773e4 */
    r3 = (uint32_t)c_rd16s(ram, r14 + r0); /* 8c0773e6 mov.w */
    r0 = 0x1A65u;                       /* 8c0773e8 mov.w */
    r3 &= 0xFFFFu;                      /* 8c0773ea extu.w */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); } /* 8c0773ec mov.b */
    { r2 &= 0xFFu; } /* 8c0773ee extu.b */
    T = (r3 > r2);                      /* 8c0773f0 cmp/gt r2,r3 */
    if (T)
        goto L_73fa;                    /* 8c0773f2 bt */
    { r2 = 0x1A000000u; } /* 8c0773f4 mov.l pool value */
    c_wr32(ram, r14 + 48, r2);          /* 8c0773f8 delay (always) */
    goto L_7e38dir;                     /* 8c0773f6 bra 077e38 */
L_73fa:
    r0 = 80;                            /* 8c0773fa */
    r6 = r13;                           /* 8c0773fc */
    r1 = c_rd32(ram, X + r0);           /* 8c0773fe [X+80] */
    r0 = 76;                            /* 8c077400 */
    c_wr32(ram, X - 4, r1);             /* 8c077402 push r1 */
    r3 = c_rd32(ram, X + 8);            /* 8c077404 [X+8] (r15=X-4) */
    c_wr32(ram, X - 8, r3);             /* 8c077406 push r3 */
    { r2 = c_rd32(ram, X + 76); } /* 8c077408 [X+76] (r15=X-8) */
    r0 = 76;                            /* 8c07740a */
    c_wr32(ram, X - 12, r2);            /* 8c07740c push r2 */
    r3 = c_rd32(ram, X + 76);           /* 8c07740e [X+76] (r15=X-12) */
    c_wr32(ram, X - 16, r3);            /* 8c077410 push r3 */
    r0 = 0x90u;                         /* 8c077412 mov.w */
    { r2 = c_rd32(ram, X + r0); } /* 8c077414 [X+0x90] (r15=X-16) */
    r0 = 92;                            /* 8c077416 */
    c_wr32(ram, X - 20, r2);            /* 8c077418 push r2 */
    r3 = c_rd32(ram, X + r0);           /* 8c07741a [X+92] (r15=X-20) */
    c_wr32(ram, X - 24, r3);            /* 8c07741c push r3 */
    { r2 = 0xA0u; } /* 8c07741e mov.w */
    { r2 += X; } /* 8c077420 (r15=X-24: X+0x88) */
    c_wr32(ram, X - 28, r2);            /* 8c077422 push r2 */
    r0 = 0xA0u;                         /* 8c077424 mov.w */
    r3 = c_rd32(ram, X + r0);           /* 8c077426 [X+0xa0] (r15=X-28) */
    c_wr32(ram, X - 32, r3);            /* 8c077428 push r3 */
    r0 = 0x90u;                         /* 8c07742a mov.w */
    { r2 = c_rd32(ram, X + r0); } /* 8c07742c [X+0x90] (r15=X-32) */
    c_wr32(ram, X - 36, r2);            /* 8c07742e push r2 */
    r0 = 0x9Cu;                         /* 8c077430 mov.w */
    r3 = c_rd32(ram, X + r0);           /* 8c077432 [X+0x9c] (r15=X-36) */
    c_wr32(ram, X - 40, r3);            /* 8c077434 push r3 */
    r7 = 0x9Cu;                         /* 8c077436 mov.w */
    r7 += X;                            /* 8c077438 (r15=X-40: X+0x70) */
    r5 = r14;                           /* 8c07743a */
    /* 8c07743c bsr 0x8c077e4e: UNREACHED-CALL GATE (0x in edges) */
    o->gated = 12;
    return;
L_746c:
    r0 = 80;                            /* 8c07746c */
    r6 = r13;                           /* 8c07746e */
    r3 = c_rd32(ram, X + r0);           /* 8c077470 [X+80] */
    r0 = 76;                            /* 8c077472 */
    c_wr32(ram, X - 4, r3);             /* 8c077474 push r3 */
    { r2 = c_rd32(ram, X + 4); } /* 8c077476 [X+4] (r15=X-4) */
    c_wr32(ram, X - 8, r2);             /* 8c077478 push r2 */
    r3 = c_rd32(ram, X + 68);           /* 8c07747a [X+68] (r15=X-8) */
    r0 = 76;                            /* 8c07747c */
    c_wr32(ram, X - 12, r3);            /* 8c07747e push r3 */
    { r2 = c_rd32(ram, X + 64); } /* 8c077480 [X+64] (r15=X-12) */
    c_wr32(ram, X - 16, r2);            /* 8c077482 push r2 */
    r0 = 0x90u;                         /* 8c077484 mov.w */
    r3 = c_rd32(ram, X + 0x80);         /* 8c077486 [X+0x80] (r15=X-16) */
    r0 = 92;                            /* 8c077488 */
    c_wr32(ram, X - 20, r3);            /* 8c07748a push r3 */
    { r2 = c_rd32(ram, X + 72); } /* 8c07748c [X+72] (r15=X-20) */
    c_wr32(ram, X - 24, r2);            /* 8c07748e push r2 */
    r3 = 0xA0u;                         /* 8c077490 mov.w */
    r3 += X - 24;                       /* 8c077492 (r15=X-24: X+0x88) */
    c_wr32(ram, X - 28, r3);            /* 8c077494 push r3 */
    r0 = 0xA0u;                         /* 8c077496 mov.w */
    { r2 = c_rd32(ram, X + 0x84); } /* 8c077498 [X+0x84] (r15=X-28) */
    c_wr32(ram, X - 32, r2);            /* 8c07749a push r2 */
    r3 = c_rd32(ram, X + 0x70);         /* 8c07749c [X+0x70] (r15=X-32) */
    c_wr32(ram, X - 36, r3);            /* 8c07749e push r3 */
    { r2 = c_rd32(ram, X + 0x78); } /* 8c0774a0 [X+0x78] (r15=X-36) */
    c_wr32(ram, X - 40, r2);            /* 8c0774a2 push r2 */
    r7 = 0x9Cu;                         /* 8c0774a8 mov.w */
    r7 += X - 40;                       /* 8c0774aa (r15=X-40: X+0x70) */
    r5 = r14;                           /* 8c0774ac */
    r4 = r12;                           /* 8c0774b0 delay (always) */
    { /* 8c0774ae bsr 0x8c077e4e */
        vf3_g77e4e_out o2;
        uint32_t u2sr = (sr & ~1u) | (T ? 1u : 0u);
        memset(&o2, 0, sizeof(o2));
        vf3_g77e4e_8c077e4e(r0, r1, r2, r3, r4, r5, r6, r7, r8, r9,
                            r10, r11, r12, r13, r14, X - 40, 0x0C0774B2u,
                            u2sr, &o2, ram);
        if (o2.gated) {
            o->gated = 20 + o2.gated;
            return;
        }
        r0 = o2.r0; r1 = o2.r1; r2 = o2.r2; r3 = o2.r3;
        r4 = o2.r4; r5 = o2.r5; r6 = o2.r6; r7 = o2.r7;
        r8 = o2.r8; r9 = o2.r9; r10 = o2.r10; r11 = o2.r11;
        r12 = o2.r12; r13 = o2.r13; r14 = o2.r14;
        sr = o2.sr; SETT(sr & 1);
    }
    /* (8c0774b6 add #40,r15 delay: no-op under absolute-X modeling) */
    T = (r0 == 0);                      /* 8c0774b2 tst r0,r0 */
    if (!T)
        goto L_74b8e40;                 /* 8c0774b4 bt/s (T=0: bra E40) */
    goto L_74bc;                        /* (T=1: 0774bc) */
L_74b8e40:
    goto L_e40epi;                      /* 8c0774b8 bra 077e40 */
L_74bc:
    goto L_74cc;                        /* 8c0774bc bra 0774cc */
L_74cc:
    r0 = 0x1B90u;                       /* 8c0774cc mov.w */
    r1 = (uint32_t)c_rd16s(ram, r14 + r0); /* 8c0774ce mov.w */
    r1 &= 0xFFFFu;                      /* 8c0774d0 extu.w */
    c_wr32(ram, X + 20, r1);            /* 8c0774d2 [X+20] */
    r0 = 0x1B98u;                       /* 8c0774d4 mov.w */
    r3 = c_rd32(ram, r14 + r0);         /* 8c0774d6 */
    T = (r3 == 0);                      /* 8c0774d8 tst r3,r3 */
    if (T)
        goto L_7584;                    /* 8c0774da bt */
    r3 = c_rd32(ram, X + 20);           /* 8c0774dc [X+20] */
    T = (r3 == 0);                      /* 8c0774de tst r3,r3 */
    if (T)
        goto L_7584;                    /* 8c0774e0 bt */
    { r2 = c_rd32(ram, X + 20); } /* 8c0774e2 [X+20] */
    r3 = 0x7FFFu;                       /* 8c0774e4 mov.w */
    T = (r3 == r2);                     /* 8c0774e6 cmp/eq r3,r2 */
    if (T)
        goto L_7518;                    /* 8c0774e8 bt */
    r1 = c_rd32(ram, X + 20);           /* 8c0774ea [X+20] */
    { r2 = 0x7FFEu; } /* 8c0774ec mov.w */
    T = (r2 == r1);                     /* 8c0774ee cmp/eq r2,r1 */
    if (!T)
        goto L_7500;                    /* 8c0774f0 bf */
    r0 = 0x23A5u;                       /* 8c0774f2 mov.w */
    r1 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c0774f4 mov.b */
    r1 &= 0xFFu;                        /* 8c0774f6 extu.b */
    T = ((int32_t)r1 > 0);              /* 8c0774f8 cmp/pl r1 */
    if (!T)
        goto L_7512;                    /* 8c0774fa bf */
    goto L_7e38dir;                     /* 8c0774fc bra 077e38 */
L_7500:
    r0 = 62;                            /* 8c077500 */
    r3 = c_rd32(ram, X + 20);           /* 8c077502 [X+20] */
    { r2 = (uint32_t)c_rd16s(ram, r14 + r0); } /* 8c077504 mov.w */
    { r2 &= 0xFFFFu; } /* 8c077506 extu.w */
    { r2 += 1; } /* 8c077508 */
    T = (r3 >= r2);                     /* 8c07750a cmp/hs r3,r2 */
    if (T)
        goto L_7512;                    /* 8c07750c bt */
    goto L_7e38dir;                     /* 8c07750e bra */
L_7512:
    r0 = 0x1B90u;                       /* 8c077512 mov.w */
    { r2 = 0; } /* 8c077514 */
    c_wr16(ram, r14 + r0, (uint16_t)r2);/* 8c077516 mov.w = 0 */
L_7518:
    r0 = 80;                            /* 8c077518 */
    r6 = r13;                           /* 8c07751a */
    r3 = c_rd32(ram, X + r0);           /* 8c07751c [X+80] */
    r0 = 76;                            /* 8c07751e */
    c_wr32(ram, X - 4, r3);             /* 8c077520 push r3 */
    { r2 = c_rd32(ram, X + 8); } /* 8c077522 [X+8] (r15=X-4) */
    c_wr32(ram, X - 8, r2);             /* 8c077524 push r2 */
    r3 = c_rd32(ram, X + 76);           /* 8c077526 [X+76] (r15=X-8) */
    r0 = 76;                            /* 8c077528 */
    c_wr32(ram, X - 12, r3);            /* 8c07752a push r3 */
    { r2 = c_rd32(ram, X + 76); } /* 8c07752c [X+76] (r15=X-12) */
    c_wr32(ram, X - 16, r2);            /* 8c07752e push r2 */
    r0 = 0x90u;                         /* 8c077530 mov.w */
    r3 = c_rd32(ram, X + r0);           /* 8c077532 [X+0x90] (r15=X-16) */
    r0 = 92;                            /* 8c077534 */
    c_wr32(ram, X - 20, r3);            /* 8c077536 push r3 */
    { r2 = c_rd32(ram, X + r0); } /* 8c077538 [X+92] (r15=X-20) */
    c_wr32(ram, X - 24, r2);            /* 8c07753a push r2 */
    r3 = 0xA0u;                         /* 8c07753c mov.w */
    r3 += X - 24;                       /* 8c07753e (r15=X-24: X+0x88) */
    c_wr32(ram, X - 28, r3);            /* 8c077540 push r3 */
    r0 = 0xA0u;                         /* 8c077542 mov.w */
    { r2 = c_rd32(ram, X + 0x88); } /* 8c077544 [X+0x88] (r15=X-28) */
    c_wr32(ram, X - 32, r2);            /* 8c077546 push r2 */
    r3 = c_rd32(ram, X + 0x90);         /* 8c077548 [X+0x90] (r15=X-32) */
    c_wr32(ram, X - 36, r3);            /* 8c07754a push r3 */
    { r2 = c_rd32(ram, X + 0x9C); } /* 8c07754c [X+0x9c] (r15=X-36) */
    c_wr32(ram, X - 40, r2);            /* 8c07754e push r2 */
    r7 = 0x9Cu;                         /* 8c077554 mov.w */
    r7 += X - 40;                       /* 8c077556 (r15=X-40: X+0x70) */
    r5 = r14;                           /* 8c077558 */
    /* 8c07755a bsr 0x8c07825e: UNREACHED-CALL GATE (0x in edges) */
    o->gated = 13;
    return;
L_7584:
    r0 = 0x1BB1u;                       /* 8c077584 mov.w */
    r3 = 0;                             /* 8c077586 */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c077588 mov.b = 0 */
    r0 = 0x88u;                         /* 8c07758a mov.w */
    r3 = 0x40000000u;                   /* 8c07758c mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c07758e [X+0x88] */
    T = ((r3 & r2) == 0);               /* 8c077590 tst r3,r2 */
    if (T)
        goto L_7614;                    /* 8c077592 bt */
    r0 = 0x1B9Cu;                       /* 8c077594 mov.w */
    { r2 = c_rd32(ram, r14 + r0); } /* 8c077596 */
    T = (r2 == 0);                      /* 8c077598 tst r2,r2 */
    if (!T)
        goto L_7672;                    /* 8c07759a bf */
    r0 = 112;                           /* 8c07759c */
    r1 = c_rd32(ram, X + r0);           /* 8c07759e [X+112] */
    T = (r1 == 0);                      /* 8c0775a0 tst r1,r1 */
    if (!T)
        goto L_7672;                    /* 8c0775a2 bf */
    r0 = 0x88u;                         /* 8c0775a4 mov.w */
    r3 = 0x08000000u;                   /* 8c0775a6 mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c0775a8 [X+0x88] */
    T = ((r3 & r1) == 0);               /* 8c0775aa tst r3,r1 */
    if (T)
        goto L_75b2;                    /* 8c0775ac bt */
    goto L_7e38dir;                     /* 8c0775ae bra 077e38 */
L_75b2:
    r0 = 0x1B82u;                       /* 8c0775b2 mov.w */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c0775b4 mov.b */
    r3 &= 0xFFu;                        /* 8c0775b6 extu.b */
    c_wr32(ram, X + 32, r3);            /* 8c0775b8 [X+32] */
    r0 = 0x1B83u;                       /* 8c0775ba mov.w */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); } /* 8c0775bc mov.b */
    r0 = 108;                           /* 8c0775be */
    { r2 &= 0xFFu; } /* 8c0775c0 extu.b */
    c_wr32(ram, X + 28, r2);            /* 8c0775c2 [X+28] */
    r3 = c_rd32(ram, X + 32);           /* 8c0775c4 [X+32] */
    r3 -= r2;                           /* 8c0775c6 sub r2,r3 */
    c_wr32(ram, X + 24, r3);            /* 8c0775c8 [X+24] */
    r3 = 12;                            /* 8c0775ca */
    c_wr32(ram, X + 108, r3);           /* 8c0775cc [X+108] = 12 */
    r0 = 76;                            /* 8c0775ce */
    { r2 = c_rd32(ram, r14 + r0); } /* 8c0775d0 */
    r3 = 0x2000u;                       /* 8c0775d2 mov.w */
    T = ((r3 & r2) == 0);               /* 8c0775d4 tst r3,r2 */
    if (T)
        goto L_75de;                    /* 8c0775d6 bt */
    r0 = 108;                           /* 8c0775d8 */
    { r2 = 13; } /* 8c0775da */
    c_wr32(ram, X + r0, r2);            /* 8c0775dc [X+108] = 13 */
L_75de:
    r0 = 108;                           /* 8c0775de */
    r1 = c_rd32(ram, X + 24);           /* 8c0775e0 [X+24] */
    r3 = c_rd32(ram, X + r0);           /* 8c0775e2 [X+108] */
    T = (r1 >= r3);                     /* 8c0775e4 cmp/hi r3,r1 */
    if (!T)
        goto L_75ea;                    /* 8c0775e6 bf */
    c_wr32(ram, X + 24, r3);            /* 8c0775e8 [X+24] = r3 */
L_75ea:
    { r2 = c_rd32(ram, X + 32); } /* 8c0775ea [X+32] */
    r3 = c_rd32(ram, X + 24);           /* 8c0775ec [X+24] */
    { r2 -= r3; } /* 8c0775ee sub r3,r2 */
    r0 = r2;                            /* 8c0775f0 */
    r0 &= 63u;                          /* 8c0775f2 and #63,r0 */
    r3 = r0;                            /* 8c0775f4 */
    c_wr32(ram, X + 28, r0);            /* 8c0775f6 [X+28] */
    r0 = 0x1B83u;                       /* 8c0775f8 mov.w */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c0775fa mov.b + bra E38 */
    goto L_7e38dir;                     /* 8c0775fa bra 077e38 */
L_7614:
    r0 = 0x88u;                         /* 8c077614 mov.w */
    r3 = 0x08000000u;                   /* 8c077616 mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c077618 [X+0x88] */
    T = ((r3 & r2) == 0);               /* 8c07761a tst r3,r2 */
    if (!T)
        goto L_7672;                    /* 8c07761c bf */
    r0 = 0x88u;                         /* 8c07761e mov.w */
    { r2 = 0x20000000u; } /* 8c077620 mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c077622 [X+0x88] */
    T = ((r2 & r1) == 0);               /* 8c077624 tst r2,r1 */
    if (T)
        goto L_7672;                    /* 8c077626 bt */
    r0 = 0x1B82u;                       /* 8c077628 mov.w */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c07762a mov.b */
    r3 &= 0xFFu;                        /* 8c07762c extu.b */
    c_wr32(ram, X + 32, r3);            /* 8c07762e [X+32] */
    r0 = 0x1B84u;                       /* 8c077630 mov.w */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); } /* 8c077632 mov.b */
    r0 = 108;                           /* 8c077634 */
    { r2 &= 0xFFu; } /* 8c077636 extu.b */
    c_wr32(ram, X + 28, r2);            /* 8c077638 [X+28] */
    r3 = c_rd32(ram, X + 32);           /* 8c07763a [X+32] */
    r3 -= r2;                           /* 8c07763c sub r2,r3 */
    c_wr32(ram, X + 24, r3);            /* 8c07763e [X+24] */
    r3 = 12;                            /* 8c077640 */
    c_wr32(ram, X + 108, r3);           /* 8c077642 [X+108] = 12 */
    r0 = 76;                            /* 8c077644 */
    { r2 = c_rd32(ram, r14 + r0); } /* 8c077646 */
    r3 = 0x2000u;                       /* 8c077648 mov.w */
    T = ((r3 & r2) == 0);               /* 8c07764a tst r3,r2 */
    if (T)
        goto L_7654;                    /* 8c07764c bt */
    r0 = 108;                           /* 8c07764e */
    { r2 = 13; } /* 8c077650 */
    c_wr32(ram, X + r0, r2);            /* 8c077652 [X+108] = 13 */
L_7654:
    r0 = 108;                           /* 8c077654 */
    r1 = c_rd32(ram, X + 24);           /* 8c077656 [X+24] */
    r3 = c_rd32(ram, X + r0);           /* 8c077658 [X+108] */
    T = (r1 >= r3);                     /* 8c07765a cmp/hi r3,r1 */
    if (!T)
        goto L_7660;                    /* 8c07765c bf */
    c_wr32(ram, X + 24, r3);            /* 8c07765e [X+24] = r3 */
L_7660:
    { r2 = c_rd32(ram, X + 32); } /* 8c077660 [X+32] */
    r3 = c_rd32(ram, X + 24);           /* 8c077662 [X+24] */
    { r2 -= r3; } /* 8c077664 sub r3,r2 */
    r0 = r2;                            /* 8c077666 */
    r0 &= 63u;                          /* 8c077668 and #63,r0 */
    r3 = r0;                            /* 8c07766a */
    c_wr32(ram, X + 28, r0);            /* 8c07766c [X+28] */
    r0 = 0x1B83u;                       /* 8c07766e mov.w */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c077670 mov.b + bra E38 */
    goto L_7e38dir;                     /* 8c077670 bra 077e38 */
L_7672:
    r0 = 0x1B82u;                       /* 8c077672 mov.w */
    r1 = X;                             /* 8c077674 */
    r1 += 108;                          /* 8c077676 */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); } /* 8c077678 mov.b */
    { r2 &= 0xFFu; } /* 8c07767a extu.b */
    c_wr32(ram, X + 28, r2);            /* 8c07767c [X+28] */
    r0 = 0x1B83u;                       /* 8c07767e mov.w */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077680 mov.b */
    r3 &= 0xFFu;                        /* 8c077682 extu.b */
    { r2 = r3; } /* 8c077684 */
    { r2 += 1; } /* 8c077686 */
    r0 = r2;                            /* 8c077688 */
    r0 &= 63u;                          /* 8c07768a and #63,r0 */
    c_wr32(ram, r1, r0);                /* 8c07768c [X+108] */
    r3 = c_rd32(ram, X + 28);           /* 8c07768e [X+28] */
    T = (r3 == r0);                     /* 8c077690 cmp/eq r3,r0 */
    if (T)
        goto L_7720;                    /* 8c077692 bt */
L_7694:
    r0 = 0x1B83u;                       /* 8c077694 mov.w */
    r1 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077696 mov.b */
    r1 &= 0xFFu;                        /* 8c077698 extu.b */
    r1 <<= 2;                           /* 8c07769a shll2 */
    r3 = r1;                            /* 8c07769c */
    c_wr32(ram, X + 20, r1);            /* 8c07769e [X+20] */
    { r2 = 0x1C00u; } /* 8c0776a0 mov.w */
    { r2 += r14; } /* 8c0776a2 */
    { r2 += r3; } /* 8c0776a4 */
    r1 = (uint32_t)(uint8_t)c_rd8s(ram, r2); /* 8c0776a6 mov.b */
    r1 &= 0xFFu;                        /* 8c0776a8 extu.b */
    c_wr32(ram, X + 4, r1);             /* 8c0776aa [X+4] */
    r1 = X;                             /* 8c0776ac */
    { r2 = 0x1C00u; } /* 8c0776ae mov.w */
    r1 += 80;                           /* 8c0776b0 */
    r3 = c_rd32(ram, X + 20);           /* 8c0776b2 [X+20] */
    { r2 += r14; } /* 8c0776b4 */
    { r2 += r3; } /* 8c0776b6 */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, r2 + 2); /* 8c0776b8 mov.b */
    r0 &= 0xFFu;                        /* 8c0776ba extu.b */
    c_wr32(ram, r1, r0);                /* 8c0776bc */
    { r2 = 0x1C00u; } /* 8c0776be mov.w */
    r3 = c_rd32(ram, X + 20);           /* 8c0776c0 [X+20] */
    { r2 += r14; } /* 8c0776c2 */
    { r2 += r3; } /* 8c0776c4 */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, r2 + 3); /* 8c0776c6 mov.b */
    r0 &= 0xFFu;                        /* 8c0776c8 extu.b */
    c_wr32(ram, X + 60, r0);            /* 8c0776ca [X+60] */
    r0 = 0x8Cu;                         /* 8c0776cc mov.w */
    r3 = 0x0F000000u;                   /* 8c0776ce mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c0776d0 [X+0x8c] */
    r1 = c_rd32(ram, r2 + 4);           /* 8c0776d2 [0x0c29b868] */
    T = ((r3 & r1) == 0);               /* 8c0776d4 tst r3,r1 */
    if (T)
        goto L_76f0;                    /* 8c0776d6 bt */
    r0 = c_rd32(ram, X + 4);            /* 8c0776d8 [X+4] */
    r1 = X;                             /* 8c0776da */
    r1 += 80;                           /* 8c0776dc */
    r0 &= 16u;                          /* 8c0776de and #16,r0 */
    c_wr32(ram, X + 4, r0);             /* 8c0776e0 [X+4] */
    r0 = 80;                            /* 8c0776e2 */
    r0 = c_rd32(ram, X + r0);           /* 8c0776e4 [X+80] */
    r0 &= 16u;                          /* 8c0776e6 and #16,r0 */
    c_wr32(ram, r1, r0);                /* 8c0776e8 */
    r0 = c_rd32(ram, X + 60);           /* 8c0776ea [X+60] */
    r0 &= 16u;                          /* 8c0776ec and #16,r0 */
    c_wr32(ram, X + 60, r0);            /* 8c0776ee [X+60] */
L_76f0:
    r3 = c_rd32(ram, X + 4);            /* 8c0776f0 [X+4] */
    r6 = r13;                           /* 8c0776f2 */
    r5 = r14;                           /* 8c0776f4 */
    r7 = 1;                             /* 8c0776f6 */
    c_wr32(ram, X - 4, r3);             /* 8c0776f8 push r3 */
    r0 = 0x8Cu;                         /* 8c0776fa mov.w */
    { r2 = c_rd32(ram, X + 0x88); } /* 8c0776fc [X+0x88] (r15=X-4) */
    r0 = 88;                            /* 8c0776fe */
    c_wr32(ram, X - 8, r2);             /* 8c077700 push r2 */
    r3 = c_rd32(ram, X + 80);           /* 8c077702 [X+80] (r15=X-8) */
    c_wr32(ram, X - 12, r3);            /* 8c077704 push r3 */
    { /* 8c077706 bsr 0x8c078044 (delay r4 = r12, pre-call) */
        vf3_g78044_out o1;
        uint32_t u1sr = (sr & ~1u) | (T ? 1u : 0u);
        memset(&o1, 0, sizeof(o1));
        vf3_g78044_8c078044(r12, r14, r13, 1, r13, r14, X - 12, u1sr,
                            &o1, ram);
        r0 = o1.r0; r3 = o1.r3; r4 = o1.r4;
        r6 = o1.r6; r7 = o1.r7;
        sr = o1.sr; SETT(sr & 1);
    }
    /* (8c07770a add #12,r15: no-op under absolute-X modeling) */
L_770c:
    r1 = X;                             /* 8c07770c */
    r1 += 80;                           /* 8c07770e */
    c_wr32(ram, r1, r0);                /* 8c077710 [X+80] = r0 */
    r0 = 0x1B83u;                       /* 8c077712 mov.w */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077714 mov.b */
    r3 &= 0xFFu;                        /* 8c077716 extu.b */
    r3 += 1;                            /* 8c077718 */
    r0 = r3;                            /* 8c07771a */
    r0 &= 63u;                          /* 8c07771c and #63,r0 */
    c_wr32(ram, X + 28, r0);            /* 8c07771e [X+28] */
    r0 = 0x1B83u;                       /* 8c077720 mov.w */
    r3 = c_rd32(ram, X + 28);           /* 8c077722 [X+28] */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c077724 mov.b */
    r0 -= 1;                            /* 8c077726 -> 0x1b82 */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); } /* 8c077728 mov.b */
    r0 = 108;                           /* 8c07772a */
    { r2 &= 0xFFu; } /* 8c07772c extu.b */
    c_wr32(ram, X + 32, r2);            /* 8c07772e [X+32] */
    r3 = c_rd32(ram, X + 28);           /* 8c077730 [X+28] */
    { r2 -= r3; } /* 8c077732 sub r3,r2 */
    c_wr32(ram, X + 24, r2);            /* 8c077734 [X+24] */
    { r2 = 11; } /* 8c077736 */
    c_wr32(ram, X + 108, r2);           /* 8c077738 [X+108] = 11 */
    r0 = 76;                            /* 8c07773a */
    r1 = c_rd32(ram, r14 + r0);         /* 8c07773c */
    r3 = 0x2000u;                       /* 8c07773e mov.w */
    T = ((r3 & r1) == 0);               /* 8c077740 tst r3,r1 */
    if (T)
        goto L_774a;                    /* 8c077742 bt */
    r0 = 108;                           /* 8c077744 */
    { r2 = 12; } /* 8c077746 */
    c_wr32(ram, X + r0, r2);            /* 8c077748 [X+108] = 12 */
L_774a:
    r0 = 108;                           /* 8c07774a */
    r1 = c_rd32(ram, X + 24);           /* 8c07774c [X+24] */
    r3 = c_rd32(ram, X + r0);           /* 8c07774e [X+108] */
    T = (r1 >= r3);                     /* 8c077750 cmp/hi r3,r1 */
    r1 = 0;                             /* 8c077754 delay (always) */
    if (T)
        goto L_7762;                    /* 8c077752 bt/s */
    r0 = 0x88u;                         /* 8c077756 mov.w */
    r3 = 0xF7FFFFFFu;                   /* 8c077758 mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c07775a [X+0x88] */
    r0 = 0x88u;                         /* 8c07775c mov.w */
    { r2 &= r3; } /* 8c07775e */
    c_wr32(ram, X + r0, r2);            /* 8c077760 [X+0x88] */
L_7762:
    goto L_7784;                        /* 8c077762 bra 077784 */
L_7784:
    { r2 = X; } /* 8c077784 */
    r0 = 120;                           /* 8c077786 */
    { r2 += 80; } /* 8c077788 */
    c_wr32(ram, X + r0, r1);            /* 8c07778a [X+120] = r1 */
    r0 = c_rd32(ram, r2);               /* 8c07778c [X+80] */
    r3 = r1;                            /* 8c07778e */
    r0 &= 11u;                          /* 8c077790 and #11,r0 */
    r3 |= r0;                           /* 8c077792 */
    r0 = 120;                           /* 8c077794 */
    c_wr32(ram, X + r0, r3);            /* 8c077796 [X+120] */
    { r2 = 0x80u; } /* 8c077798 mov.w */
    { r2 += X; } /* 8c07779a */
    r0 = c_rd32(ram, r2);               /* 8c07779c [X+0x80] */
    T = ((r0 & 64) == 0);               /* 8c07779e tst #64,r0 */
    if (!T)
        goto L_77b4;                    /* 8c0777a0 bf */
    r1 = 0x80u;                         /* 8c0777a2 mov.w */
    r1 += X;                            /* 8c0777a4 */
    r0 = c_rd32(ram, r1);               /* 8c0777a6 [X+0x80] */
    T = ((r0 & 32) == 0);               /* 8c0777a8 tst #32,r0 */
    if (!T)
        goto L_77b4;                    /* 8c0777aa bf */
    r0 = 120;                           /* 8c0777ac */
    r3 = c_rd32(ram, X + r0);           /* 8c0777ae [X+120] */
    T = (r3 == 0);                      /* 8c0777b0 tst r3,r3 */
    if (T)
        goto L_77de;                    /* 8c0777b2 bt */
L_77b4:
    { r2 = X; } /* 8c0777b4 */
    r1 = X;                             /* 8c0777b6 */
    { r2 += 80; } /* 8c0777b8 */
    r1 += 120;                          /* 8c0777ba */
    r0 = c_rd32(ram, r2);               /* 8c0777bc [X+80] */
    r3 = c_rd32(ram, r1);               /* 8c0777be [X+120] */
    r0 &= 4u;                           /* 8c0777c0 and #4,r0 */
    r3 |= r0;                           /* 8c0777c2 */
    r0 = 120;                           /* 8c0777c4 */
    c_wr32(ram, X + r0, r3);            /* 8c0777c6 [X+120] */
    r0 = 80;                            /* 8c0777c8 */
    r1 = c_rd32(ram, X + r0);           /* 8c0777ca [X+80] */
    r0 = r3;                            /* 8c0777cc */
    { r2 = 0x0100u; } /* 8c0777ce mov.w */
    r1 &= r2;                           /* 8c0777d0 */
    r1 >>= 2;                           /* 8c0777d2 shlr2 */
    r1 >>= 1;                           /* 8c0777d4 shlr */
    r0 |= r1;                           /* 8c0777d6 */
    r1 = X;                             /* 8c0777d8 */
    r1 += 120;                          /* 8c0777da */
    c_wr32(ram, r1, r0);                /* 8c0777dc */
L_77de:
    r0 = 108;                           /* 8c0777de */
    r3 = 0;                             /* 8c0777e0 */
    c_wr32(ram, X + r0, r3);            /* 8c0777e2 [X+108] = 0 */
    r0 = 120;                           /* 8c0777e4 */
    r0 = c_rd32(ram, X + r0);           /* 8c0777e6 [X+120] */
    T = (r0 == 2);                      /* 8c0777e8 cmp/eq #2 */
    if (!T)
        goto L_77fa;                    /* 8c0777ea bf */
    r0 = 0x203Au;                       /* 8c0777ec mov.w */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); } /* 8c0777ee mov.b */
    T = (r2 == 0);                      /* 8c0777f0 tst r2,r2 */
    if (T)
        goto L_77fa;                    /* 8c0777f2 bt */
    r0 = 108;                           /* 8c0777f4 */
    r3 = 1;                             /* 8c0777f6 */
    c_wr32(ram, X + r0, r3);            /* 8c0777f8 [X+108] = 1 */
L_77fa:
    r0 = 108;                           /* 8c0777fa */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, X + r0); } /* 8c0777fc mov.b */
    r0 = 27;                            /* 8c0777fe */
    c_wr8(ram, r12 + r0, r2);           /* 8c077800 mov.b r2,@(27,r12) */
    r0 = 0x80u;                         /* 8c077802 mov.w */
    r3 = 0x00080000u;                   /* 8c077804 mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c077806 [X+0x80] */
    T = ((r3 & r1) == 0);               /* 8c077808 tst r3,r1 */
    if (T)
        goto L_7810;                    /* 8c07780a bt */
    goto L_7922;                        /* 8c07780c bra 077922 */
L_7810:
    { r2 = 0x80u; } /* 8c077810 mov.w */
    { r2 += X; } /* 8c077812 */
    r0 = c_rd32(ram, r2);               /* 8c077814 [X+0x80] */
    T = ((r0 & 96) == 0);               /* 8c077816 tst #96,r0 */
    if (T)
        goto L_781e;                    /* 8c077818 bt */
    goto L_7b5e;                        /* 8c07781a bra 077b5e */
L_781e:
    r0 = 0x88u;                         /* 8c07781e mov.w */
    { r2 = 0x40000000u; } /* 8c077820 mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c077822 [X+0x88] */
    T = ((r2 & r1) == 0);               /* 8c077824 tst r2,r1 */
    if (T)
        goto L_782c;                    /* 8c077826 bt */
    goto L_7b5e;                        /* 8c077828 bra */
L_782c:
    r0 = c_rd32(ram, X + 4);            /* 8c07782c [X+4] */
    T = ((r0 & 32) == 0);               /* 8c07782e tst #32,r0 */
    if (!T)
        goto L_7836;                    /* 8c077830 bf */
    goto L_7b5e;                        /* 8c077832 bra */
L_7836:
    r0 = c_rd32(ram, X + 4);            /* 8c077836 [X+4] */
    T = ((r0 & 15) == 0);               /* 8c077838 tst #15,r0 */
    if (T)
        goto L_7840;                    /* 8c07783a bt */
    goto L_7b5e;                        /* 8c07783c bra */
L_7840:
    r0 = 0x1B83u;                       /* 8c077840 mov.w */
    r1 = X;                             /* 8c077842 */
    r1 += 104;                          /* 8c077844 */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); } /* 8c077846 mov.b */
    { r2 &= 0xFFu; } /* 8c077848 extu.b */
    { r2 -= 2; } /* 8c07784a */
    r0 = r2;                            /* 8c07784c */
    r0 &= 63u;                          /* 8c07784e and #63,r0 */
    c_wr32(ram, r1, r0);                /* 8c077850 [X+104] */
    r1 = X;                             /* 8c077852 */
    r1 += 96;                           /* 8c077854 */
    r0 <<= 2;                           /* 8c077856 shll2 */
    c_wr32(ram, r1, r0);                /* 8c077858 [X+96] */
    r0 = 0x1B85u;                       /* 8c07785a mov.w */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c07785c mov.b */
    r0 = 92;                            /* 8c07785e */
    r3 &= 0xFFu;                        /* 8c077860 extu.b */
    c_wr32(ram, X + r0, r3);            /* 8c077862 [X+92] */
    r0 = 104;                           /* 8c077864 */
    { r2 = c_rd32(ram, X + r0); } /* 8c077866 [X+104] */
    T = (r3 == r2);                     /* 8c077868 cmp/eq r3,r2 */
    if (!T)
        goto L_7870;                    /* 8c07786a bf */
    goto L_7b5e;                        /* 8c07786c bra */
L_7870:
    r0 = 108;                           /* 8c077870 */
    r3 = 12;                            /* 8c077872 */
    c_wr32(ram, X + r0, r3);            /* 8c077874 [X+108] = 12 */
    r0 = 76;                            /* 8c077876 */
    { r2 = c_rd32(ram, r14 + r0); } /* 8c077878 */
    r3 = 0x2000u;                       /* 8c07787a mov.w */
    T = ((r3 & r2) == 0);               /* 8c07787c tst r3,r2 */
    r3 = 0;                             /* 8c077880 delay (always) */
    if (T)
        goto L_7888;                    /* 8c07787e bt/s */
    r0 = 108;                           /* 8c077882 */
    { r2 = 6; } /* 8c077884 */
    c_wr32(ram, X + r0, r2);            /* 8c077886 [X+108] = 6 */
L_7888:
    goto L_78e0;                        /* 8c077888 bra 0778e0 */
L_78e0:
    r3 = c_rd32(ram, X + 12);           /* 8c0778e0 [X+12] */
    r3 += 1;                            /* 8c0778e2 */
    r1 = r3;                            /* 8c0778e4 */
    c_wr32(ram, X + 12, r3);            /* 8c0778e4 store (delay pos) */
    { r2 = c_rd32(ram, X + 108); } /* 8c0778e6 [X+108] */
    T = (r1 >= r2);                     /* 8c0778e8 cmp/hs r2,r1 */
    if (!T)
        goto L_78a4;                    /* 8c0778ea bf (loop) */
    goto L_7b5e;                        /* 8c0778ec bra */
L_78a4:
    r0 = 96;                            /* 8c0778a4 */
    r3 = c_rd32(ram, X + r0);           /* 8c0778a6 [X+96] */
    r0 = 0x1C00u;                       /* 8c0778a8 mov.w */
    r0 += r14;                          /* 8c0778aa add r14,r0 */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, r0 + r3); /* 8c0778ac mov.b */
    r0 &= 0xFFu;                        /* 8c0778ae extu.b */
    T = ((r0 & 16) == 0);               /* 8c0778b0 tst #16,r0 */
    if (!T)
        goto L_78f0;                    /* 8c0778b2 bf */
    r0 = 92;                            /* 8c0778b4 */
    r3 = c_rd32(ram, X + r0);           /* 8c0778b6 [X+92] */
    r0 = 104;                           /* 8c0778b8 */
    { r2 = c_rd32(ram, X + r0); } /* 8c0778ba [X+104] */
    T = (r3 == r2);                     /* 8c0778bc cmp/eq r3,r2 */
    if (!T)
        goto L_78c4;                    /* 8c0778be bf */
    goto L_7b5e;                        /* 8c0778c0 bra */
L_78c4:
    r0 = 104;                           /* 8c0778c4 */
    { r2 = X; } /* 8c0778c6 */
    r1 = c_rd32(ram, X + r0);           /* 8c0778c8 [X+104] */
    { r2 += 104; } /* 8c0778ca */
    r1 += (uint32_t)-1;                 /* 8c0778cc */
    r0 = r1;                            /* 8c0778ce */
    r0 &= 63u;                          /* 8c0778d0 and #63,r0 */
    r1 = X;                             /* 8c0778d2 */
    c_wr32(ram, r2, r0);                /* 8c0778d4 [X+104]... (r2=X+104) */
    r1 += 96;                           /* 8c0778d6 */
    r0 <<= 2;                           /* 8c0778d8 shll2 */
    c_wr32(ram, r1, r0);                /* 8c0778da [X+96] */
    r3 = c_rd32(ram, X + 12);           /* 8c0778dc [X+12] */
    r3 += 1;                            /* 8c0778de */
    goto L_78e0back;
L_78e0back:
    goto L_78e0;                        /* (loop latch: re-test) */
L_78f0:
    r3 = 0x07000000u;                   /* 8c0778f0 mov.l pool value */
    r0 = 68;                            /* 8c0778f2 */
    c_wr32(ram, X + 56, r3);            /* 8c0778f4 [X+56] */
    { r2 = c_rd32(ram, X + r0); } /* 8c0778f6 [X+68] */
    r3 = c_rd32(ram, X + 4);            /* 8c0778f8 [X+4] */
    T = ((r3 & r2) == 0);               /* 8c0778fa tst r3,r2 */
    if (T)
        goto L_7906;                    /* 8c0778fc bt */
    r1 = c_rd32(ram, X + 56);           /* 8c0778fe [X+56] */
    { r2 = 0x00010000u; } /* 8c077900 mov.l pool value */
    r1 |= r2;                           /* 8c077902 */
    c_wr32(ram, X + 56, r1);            /* 8c077904 [X+56] */
L_7906:
    r0 = 64;                            /* 8c077906 */
    r3 = c_rd32(ram, X + 4);            /* 8c077908 [X+4] */
    { r2 = c_rd32(ram, X + r0); } /* 8c07790a [X+64] */
    T = ((r3 & r2) == 0);               /* 8c07790c tst r3,r2 */
    if (T)
        goto L_7918;                    /* 8c07790e bt */
    r1 = c_rd32(ram, X + 56);           /* 8c077910 [X+56] */
    { r2 = 0x00020000u; } /* 8c077912 mov.l pool value */
    r1 |= r2;                           /* 8c077914 */
    c_wr32(ram, X + 56, r1);            /* 8c077916 [X+56] */
L_7918:
    r3 = c_rd32(ram, X + 56);           /* 8c077918 [X+56] */
    { r2 = 0; } /* 8c07791a */
    c_wr32(ram, X + 40, r3);            /* 8c07791c [X+40] */
    c_wr32(ram, X + 36, r2);            /* 8c077920 delay (always) */
    goto L_7a02;                        /* 8c07791e bra 077a02 */
L_7922:
    r1 = 0;                             /* 8c077922 */
    c_wr32(ram, X + 56, r1);            /* 8c077924 [X+56] = 0 */
    r0 = 0x1B98u;                       /* 8c077926 mov.w */
    { r2 = c_rd32(ram, r14 + r0); } /* 8c077928 */
    T = (r2 == 0);                      /* 8c07792a tst r2,r2 */
    if (T)
        goto L_7998;                    /* 8c07792c bt */
    r0 = 80;                            /* 8c07792e */
    r6 = r13;                           /* 8c077930 */
    { r2 = c_rd32(ram, X + r0); } /* 8c077932 [X+80] */
    r0 = 76;                            /* 8c077934 */
    c_wr32(ram, X - 4, r2);             /* 8c077936 push r2 */
    r1 = c_rd32(ram, X + 8);            /* 8c077938 [X+8] (r15=X-4) */
    c_wr32(ram, X - 8, r1);             /* 8c07793a push r1 */
    { r2 = c_rd32(ram, X + 76); } /* 8c07793c [X+76] (r15=X-8) */
    r0 = 76;                            /* 8c07793e */
    c_wr32(ram, X - 12, r2);            /* 8c077940 push r2 */
    r1 = c_rd32(ram, X + 76);           /* 8c077942 [X+76] (r15=X-12) */
    c_wr32(ram, X - 16, r1);            /* 8c077944 push r1 */
    r0 = 0x90u;                         /* 8c077946 mov.w */
    { r2 = c_rd32(ram, X + r0); } /* 8c077948 [X+0x90] (r15=X-16) */
    r0 = 92;                            /* 8c07794a */
    c_wr32(ram, X - 20, r2);            /* 8c07794c push r2 */
    r1 = c_rd32(ram, X + r0);           /* 8c07794e [X+92] (r15=X-20) */
    c_wr32(ram, X - 24, r1);            /* 8c077950 push r1 */
    { r2 = 0xA0u; } /* 8c077952 mov.w */
    { r2 += X - 24; } /* 8c077954 (r15=X-24: X+0x88) */
    c_wr32(ram, X - 28, r2);            /* 8c077956 push r2 */
    r0 = 0xA0u;                         /* 8c077958 mov.w */
    r1 = c_rd32(ram, X + r0);           /* 8c07795a [X+0xa0] (r15=X-28) */
    c_wr32(ram, X - 32, r1);            /* 8c07795c push r1 */
    r0 = 0x90u;                         /* 8c07795e mov.w */
    { r2 = c_rd32(ram, X + r0); } /* 8c077960 [X+0x90] (r15=X-32) */
    c_wr32(ram, X - 36, r2);            /* 8c077962 push r2 */
    r0 = 0x9Cu;                         /* 8c077964 mov.w */
    r1 = c_rd32(ram, X + r0);           /* 8c077966 [X+0x9c] (r15=X-36) */
    c_wr32(ram, X - 40, r1);            /* 8c077968 push r1 */
    r7 = 0x9Cu;                         /* 8c07796a mov.w */
    r7 += X - 40;                       /* 8c07796c (r15=X-40: X+0x70) */
    r5 = r14;                           /* 8c07796e */
    /* 8c077970 bsr 0x8c07829a: UNREACHED-CALL GATE (0x in edges) */
    o->gated = 14;
    return;
L_7998:
    r0 = 0x88u;                         /* 8c077998 mov.w */
    r3 = 0x40000000u;                   /* 8c07799a mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c07799c [X+0x88] */
    T = ((r3 & r2) == 0);               /* 8c07799e tst r3,r2 */
    if (T)
        goto L_79a6;                    /* 8c0779a0 bt */
    goto L_7e38dir;                     /* 8c0779a2 bra 077e38 */
L_79a6:
    { r2 = c_rd32(ram, r14 + 56); } /* 8c0779a6 */
    r3 = 0x00070000u;                   /* 8c0779a8 mov.l pool value */
    { r2 &= r3; } /* 8c0779aa */
    c_wr32(ram, X + 40, r2);            /* 8c0779ac [X+40] */
    r0 = 0x1B8Cu;                       /* 8c0779ae mov.w */
    r1 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c0779b0 mov.b */
    r0 = 98;                            /* 8c0779b2 */
    r1 &= 0xFFu;                        /* 8c0779b4 extu.b */
    c_wr32(ram, X + 36, r1);            /* 8c0779b6 [X+36] */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c0779b8 mov.b */
    r0 &= 0xFFu;                        /* 8c0779ba extu.b */
    T = (r0 == 1);                      /* 8c0779bc cmp/eq #1 */
    if (!T)
        goto L_79c4;                    /* 8c0779be bf */
    goto L_7ad0;                        /* 8c0779c0 bra 077ad0 */
L_79c4:
    r0 = c_rd32(ram, X + 36);           /* 8c0779c4 [X+36] */
    T = ((r0 & 64) == 0);               /* 8c0779c6 tst #64,r0 */
    if (T)
        goto L_79ce;                    /* 8c0779c8 bt */
    goto L_7b48;                        /* 8c0779ca bra 077b48 */
L_79ce:
    r0 = 62;                            /* 8c0779ce */
    r3 = (uint32_t)c_rd16s(ram, r14 + r0); /* 8c0779d0 mov.w */
    r0 = 0x1A12u;                       /* 8c0779d2 mov.w */
    r3 &= 0xFFFFu;                      /* 8c0779d4 extu.w */
    { r2 = (uint32_t)c_rd16s(ram, r14 + r0); } /* 8c0779d6 mov.w */
    r3 += 1;                            /* 8c0779d8 */
    { r2 &= 0xFFFFu; } /* 8c0779da extu.w */
    T = (r3 >= r2);                     /* 8c0779dc cmp/ge r2,r3 */
    if (!T)
        goto L_79e6;                    /* 8c0779de bf */
    r0 = c_rd32(ram, X + 36);           /* 8c0779e0 [X+36] */
    r0 |= 128u;                         /* 8c0779e2 or #128,r0 */
    c_wr32(ram, X + 36, r0);            /* 8c0779e4 [X+36] */
L_79e6:
    r0 = c_rd32(ram, X + 4);            /* 8c0779e6 [X+4] */
    T = ((r0 & 32) == 0);               /* 8c0779e8 tst #32,r0 */
    if (!T)
        goto L_7a02;                    /* 8c0779ea bf */
    r1 = c_rd32(ram, X + 40);           /* 8c0779ec [X+40] */
    r3 = 0x00040000u;                   /* 8c0779ee mov.l pool value */
    T = ((r3 & r1) == 0);               /* 8c0779f0 tst r3,r1 */
    if (!T)
        goto L_7a02;                    /* 8c0779f2 bf */
    { r2 = 0x07040000u; } /* 8c0779f4 mov.l pool value */
    r1 = r2;                            /* 8c0779f6 */
    c_wr32(ram, X + 56, r2);            /* 8c0779f8 [X+56] */
    c_wr32(ram, X + 40, r1);            /* 8c0779fa [X+40] */
    r0 = c_rd32(ram, X + 36);           /* 8c0779fc [X+36] */
    r0 |= 128u;                         /* 8c0779fe or #128,r0 */
    c_wr32(ram, X + 36, r0);            /* 8c077a00 [X+36] */
L_7a02:
    r0 = c_rd32(ram, X + 36);           /* 8c077a02 [X+36] */
    T = ((r0 & 15) == 0);               /* 8c077a04 tst #15,r0 */
    if (!T)
        goto L_7a1a;                    /* 8c077a06 bf */
    r1 = X;                             /* 8c077a08 */
    r1 += 120;                          /* 8c077a0a */
    r0 = c_rd32(ram, r1);               /* 8c077a0c [X+120] */
    r3 = (uint32_t)-16;                 /* 8c077a0e */
    r0 &= 15u;                          /* 8c077a12 and #15,r0 */
    { r2 = c_rd32(ram, X + 36); } /* 8c077a10 [X+36] */
    { r2 &= (uint32_t)r3; } /* 8c077a14 and r3,r2 */
    { r2 |= r0; } /* 8c077a16 */
    c_wr32(ram, X + 36, r2);            /* 8c077a18 [X+36] */
L_7a1a:
    r0 = c_rd32(ram, X + 36);           /* 8c077a1a [X+36] */
    { r2 = X; } /* 8c077a1c */
    { r2 += 120; } /* 8c077a1e */
    r0 &= 15u;                          /* 8c077a20 and #15,r0 */
    T = (r0 == 0);                      /* 8c077a22 tst r0,r0 */
    r0 = c_rd32(ram, r2);               /* 8c077a26 delay (always) */
    if (!T)
        goto L_7a2c;                    /* 8c077a24 bf/s (T=0) */
    goto L_7b48;                        /* 8c077a28 bra */
L_7a2c:
    r0 = c_rd32(ram, X + 36);           /* 8c077a2c [X+36] */
    T = ((r0 & 128) == 0);              /* 8c077a2e tst #128,r0 */
    if (!T)
        goto L_7a36;                    /* 8c077a30 bf */
    goto L_7b48;                        /* 8c077a32 bra */
L_7a36:
    { r2 = c_rd32(ram, X + 40); } /* 8c077a36 [X+40] */
    r3 = 0x00040000u;                   /* 8c077a38 mov.l pool value */
    T = ((r3 & r2) == 0);               /* 8c077a3a tst r3,r2 */
    if (T)
        goto L_7a44;                    /* 8c077a3c bt */
    { r2 = 0x0200u; } /* 8c077a3e mov.w */
    goto L_7a46;                        /* 8c077a40 bra */
L_7a44:
    { r2 = 0x0100u; } /* 8c077a44 mov.w */
L_7a46:
    r0 = 120;                           /* 8c077a46 */
    r1 = c_rd32(ram, X + r0);           /* 8c077a48 [X+120] */
    r0 = 120;                           /* 8c077a4a */
    r1 += r2;                           /* 8c077a4c */
    c_wr32(ram, X + r0, r1);            /* 8c077a4e [X+120] */
    r0 = c_rd32(ram, X + 36);           /* 8c077a50 [X+36] */
    r0 |= 64u;                          /* 8c077a52 or #64,r0 */
    { r2 = r0; } /* 8c077a54 */
    c_wr32(ram, X + 36, r0);            /* 8c077a56 [X+36] */
    r0 = 0x1B8Cu;                       /* 8c077a58 mov.w */
    c_wr8(ram, r14 + r0, (uint8_t)r2);  /* 8c077a5a mov.b */
    r0 = 80;                            /* 8c077a5c */
    r3 = c_rd32(ram, X + r0);           /* 8c077a5e [X+80] */
    r0 = 76;                            /* 8c077a60 */
    c_wr32(ram, X - 4, r3);             /* 8c077a62 push r3 */
    { r2 = c_rd32(ram, X + 8); } /* 8c077a64 [X+8] (r15=X-4) */
    c_wr32(ram, X - 8, r2);             /* 8c077a66 push r2 */
    r3 = c_rd32(ram, X + 76);           /* 8c077a68 [X+76] (r15=X-8) */
    r0 = 76;                            /* 8c077a6a */
    c_wr32(ram, X - 12, r3);            /* 8c077a6c push r3 */
    { r2 = c_rd32(ram, X + 76); } /* 8c077a6e [X+76] (r15=X-12) */
    c_wr32(ram, X - 16, r2);            /* 8c077a70 push r2 */
    r0 = 0x90u;                         /* 8c077a72 mov.w */
    r3 = c_rd32(ram, X + r0);           /* 8c077a74 [X+0x90] (r15=X-16) */
    r0 = 92;                            /* 8c077a76 */
    c_wr32(ram, X - 20, r3);            /* 8c077a78 push r3 */
    { r2 = c_rd32(ram, X + r0); } /* 8c077a7a [X+92] (r15=X-20) */
    c_wr32(ram, X - 24, r2);            /* 8c077a7c push r2 */
    r3 = 0xA0u;                         /* 8c077a7e mov.w */
    r3 += X - 24;                       /* 8c077a80 (r15=X-24: X+0x88) */
    c_wr32(ram, X - 28, r3);            /* 8c077a82 push r3 */
    r0 = 0xA0u;                         /* 8c077a84 mov.w */
    { r2 = c_rd32(ram, X + r0); } /* 8c077a86 [X+0xa0] (r15=X-28) */
    r5 = r14;                           /* 8c077a88 */
    r6 = r13;                           /* 8c077a8a */
    c_wr32(ram, X - 32, r2);            /* 8c077a8c push r2 */
    r0 = 0x90u;                         /* 8c077a8e mov.w */
    r3 = c_rd32(ram, X + r0);           /* 8c077a90 [X+0x90] (r15=X-32) */
    c_wr32(ram, X - 36, r3);            /* 8c077a92 push r3 */
    { r2 = c_rd32(ram, X + 0x9C); } /* 8c077a94 [X+0x9c] (r15=X-36) */
    c_wr32(ram, X - 40, r2);            /* 8c077a96 push r2 */
    r7 = 0x9Cu;                         /* 8c077a9a mov.w */
    r7 += X - 40;                       /* 8c077a9c (r15=X-40: X+0x70) */
    /* 8c077a9e bsr 0x8c0781ba: RARE-CALL GATE (0781BA 1x in edges) */
    o->gated = 15;
    return;
L_7ad0:
    r1 = X;                             /* 8c077ad0 */
    r1 += 120;                          /* 8c077ad2 */
    r0 = c_rd32(ram, r1);               /* 8c077ad4 [X+120] */
    T = ((r0 & 15) == 0);               /* 8c077ad6 tst #15,r0 */
    if (T)
        goto L_7b48;                    /* 8c077ad8 bt */
    { r2 = c_rd32(ram, X + 40); } /* 8c077ada [X+40] */
    r3 = 0x00040000u;                   /* 8c077adc mov.l pool value */
    T = ((r3 & r2) == 0);               /* 8c077ade tst r3,r2 */
    if (!T)
        goto L_7ae8;                    /* 8c077ae0 bf */
    { r2 = 0x0300u; } /* 8c077ae2 mov.w */
    goto L_7aea;                        /* 8c077ae4 bra */
L_7ae8:
    { r2 = 0x0400u; } /* 8c077ae8 mov.w */
L_7aea:
    r0 = 120;                           /* 8c077aea */
    r1 = c_rd32(ram, X + r0);           /* 8c077aec [X+120] */
    r0 = 120;                           /* 8c077aee */
    r1 += r2;                           /* 8c077af0 */
    c_wr32(ram, X + r0, r1);            /* 8c077af2 [X+120] */
    r0 = 80;                            /* 8c077af4 */
    r3 = c_rd32(ram, X + r0);           /* 8c077af6 [X+80] */
    r0 = 76;                            /* 8c077af8 */
    c_wr32(ram, X - 4, r3);             /* 8c077afa push r3 */
    { r2 = c_rd32(ram, X + 8); } /* 8c077afc [X+8] (r15=X-4) */
    c_wr32(ram, X - 8, r2);             /* 8c077afe push r2 */
    r3 = c_rd32(ram, X + 76);           /* 8c077b00 [X+76] (r15=X-8) */
    r0 = 76;                            /* 8c077b02 */
    c_wr32(ram, X - 12, r3);            /* 8c077b04 push r3 */
    { r2 = c_rd32(ram, X + 76); } /* 8c077b06 [X+76] (r15=X-12) */
    c_wr32(ram, X - 16, r2);            /* 8c077b08 push r2 */
    r0 = 0x90u;                         /* 8c077b0a mov.w */
    r3 = c_rd32(ram, X + r0);           /* 8c077b0c [X+0x90] (r15=X-16) */
    r0 = 92;                            /* 8c077b0e */
    c_wr32(ram, X - 20, r3);            /* 8c077b10 push r3 */
    { r2 = c_rd32(ram, X + r0); } /* 8c077b12 [X+92] (r15=X-20) */
    r5 = r14;                           /* 8c077b2c? (order:movs before pushes?) */
    r6 = r13;
    c_wr32(ram, X - 24, r2);            /* 8c077b14 push r2 */
    r3 = 0xA0u;                         /* 8c077b16 mov.w */
    r3 += X - 24;                       /* 8c077b18 (r15=X-24: X+0x88) */
    c_wr32(ram, X - 28, r3);            /* 8c077b1a push r3 */
    r0 = 0xA0u;                         /* 8c077b1c mov.w */
    { r2 = c_rd32(ram, X + r0); } /* 8c077b1e [X+0xa0] (r15=X-28) */
    c_wr32(ram, X - 32, r2);            /* 8c077b20 push r2 */
    r0 = 0x90u;                         /* 8c077b22 mov.w */
    r3 = c_rd32(ram, X + r0);           /* 8c077b24 [X+0x90] (r15=X-32) */
    c_wr32(ram, X - 36, r3);            /* 8c077b26 push r3 */
    r0 = 0x9Cu;                         /* 8c077b28 mov.w */
    { r2 = c_rd32(ram, X + r0); } /* 8c077b2a [X+0x9c] (r15=X-36) */
    r5 = r5;                            /* (r14->r5 at 077b2c) */
    c_wr32(ram, X - 40, r2);            /* 8c077b30 push r2 */
    r7 = 0x9Cu;                         /* 8c077b32 mov.w */
    r7 += X - 40;                       /* 8c077b34 (r15=X-40: X+0x70) */
    /* 8c077b36 bsr 0x8c0781ba: RARE-CALL GATE (0781BA 1x in edges) */
    o->gated = 16;
    return;
L_7b48:
    r0 = 0x1B8Cu;                       /* 8c077b48 mov.w */
    r3 = c_rd32(ram, X + 36);           /* 8c077b4a [X+36] */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c077b4c mov.b */
    { r2 = c_rd32(ram, X + 56); } /* 8c077b4e [X+56] */
    T = (r2 == 0);                      /* 8c077b50 tst r2,r2 */
    if (!T)
        goto L_7b58;                    /* 8c077b52 bf */
    goto L_7ca8;                        /* 8c077b54 bra 077ca8 */
L_7b58:
    r1 = c_rd32(ram, X + 56);           /* 8c077b58 [X+56] */
    c_wr32(ram, r14 + 48, r1);          /* 8c077b5c delay (always) */
    goto L_7e16;                        /* 8c077b5a bra 077e16 */
L_7b5e:
    r0 = 120;                           /* 8c077b5e */
    { r2 = c_rd32(ram, X + r0); } /* 8c077b60 [X+120] */
    T = (r2 == 0);                      /* 8c077b62 tst r2,r2 */
    if (T)
        goto L_7c32;                    /* 8c077b64 bt */
    r0 = 76;                            /* 8c077b66 */
    r3 = c_rd32(ram, r14 + r0);         /* 8c077b68 */
    r0 = 108;                           /* 8c077b6a */
    c_wr32(ram, X + r0, r3);            /* 8c077b6c [X+108] */
    r0 = 108;                           /* 8c077b6e */
    { r2 = c_rd32(ram, X + r0); } /* 8c077b70 [X+108] */
    r3 = 0x00200000u;                   /* 8c077b72 mov.l pool value */
    T = ((r3 & r2) == 0);               /* 8c077b74 tst r3,r2 */
    if (T)
        goto L_7b86;                    /* 8c077b76 bt */
    r0 = 120;                           /* 8c077b78 */
    { r2 = 0x0600u; } /* 8c077b7a mov.w */
    r1 = c_rd32(ram, X + r0);           /* 8c077b7c [X+120] */
    r0 = 120;                           /* 8c077b7e */
    r1 += r2;                           /* 8c077b80 */
    c_wr32(ram, X + r0, r1);            /* 8c077b84 delay (always) */
    goto L_7bd4;                        /* 8c077b82 bra 077bd4 */
L_7b86:
    r0 = 108;                           /* 8c077b86 */
    { r2 = 0x00100000u; } /* 8c077b88 mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c077b8a [X+108] */
    T = ((r2 & r1) == 0);               /* 8c077b8c tst r2,r1 */
    if (T)
        goto L_7bbc;                    /* 8c077b8e bt */
    r0 = 120;                           /* 8c077b90 */
    r1 = 0x0700u;                       /* 8c077b92 mov.w */
    r0 = c_rd32(ram, X + r0);           /* 8c077b94 [X+120] */
    r3 = X;                             /* 8c077b96 */
    r3 += 120;                          /* 8c077b98 */
    r0 += r1;                           /* 8c077b9a */
    c_wr32(ram, r3, r0);                /* 8c077b9c delay (always) */
    goto L_7bd4;                        /* 8c077b9c bra 077bd4 */
L_7bbc:
    r0 = 0x84u;                         /* 8c077bbc mov.w */
    r1 = 0x08000000u;                   /* 8c077bbe mov.l pool value */
    r0 = c_rd32(ram, X + r0);           /* 8c077bc0 [X+0x84] */
    T = ((r1 & r0) == 0);               /* 8c077bc2 tst r1,r0 */
    if (T)
        goto L_7bd4;                    /* 8c077bc4 bt */
    r0 = 120;                           /* 8c077bc6 */
    r3 = 0x0500u;                       /* 8c077bc8 mov.w */
    r0 = c_rd32(ram, X + r0);           /* 8c077bca [X+120] */
    { r2 = X; } /* 8c077bcc */
    { r2 += 120; } /* 8c077bce */
    r0 += r3;                           /* 8c077bd0 add r3,r0 */
    c_wr32(ram, r2, r0);                /* 8c077bd2 [X+120] += 0x500 */
L_7bd4:
    r0 = 80;                            /* 8c077bd4 */
    r6 = r13;                           /* 8c077bd6 */
    r1 = c_rd32(ram, X + r0);           /* 8c077bd8 [X+80] */
    r0 = 76;                            /* 8c077bda */
    c_wr32(ram, X - 4, r1);             /* 8c077bdc push r1 */
    r3 = c_rd32(ram, X + 8);            /* 8c077bde [X+8] (r15=X-4) */
    c_wr32(ram, X - 8, r3);             /* 8c077be0 push r3 */
    { r2 = c_rd32(ram, X + 76); } /* 8c077be2 [X+76] (r15=X-8) */
    r0 = 76;                            /* 8c077be4 */
    c_wr32(ram, X - 12, r2);            /* 8c077be6 push r2 */
    r3 = c_rd32(ram, X + 76);           /* 8c077be8 [X+76] (r15=X-12) */
    c_wr32(ram, X - 16, r3);            /* 8c077bea push r3 */
    r0 = 0x90u;                         /* 8c077bec mov.w */
    { r2 = c_rd32(ram, X + r0); } /* 8c077bee [X+0x90] (r15=X-16) */
    r0 = 92;                            /* 8c077bf0 */
    c_wr32(ram, X - 20, r2);            /* 8c077bf2 push r2 */
    r3 = c_rd32(ram, X + r0);           /* 8c077bf4 [X+92] (r15=X-20) */
    c_wr32(ram, X - 24, r3);            /* 8c077bf6 push r3 */
    { r2 = 0xA0u; } /* 8c077bf8 mov.w */
    { r2 += X - 24; } /* 8c077bfa (r15=X-24: X+0x88) */
    c_wr32(ram, X - 28, r2);            /* 8c077bfc push r2 */
    r0 = 0xA0u;                         /* 8c077bfe mov.w */
    r3 = c_rd32(ram, X + r0);           /* 8c077c00 [X+0xa0] (r15=X-28) */
    c_wr32(ram, X - 32, r3);            /* 8c077c02 push r3 */
    r0 = 0x90u;                         /* 8c077c04 mov.w */
    { r2 = c_rd32(ram, X + r0); } /* 8c077c06 [X+0x90] (r15=X-32) */
    c_wr32(ram, X - 36, r2);            /* 8c077c08 push r2 */
    r0 = 0x9Cu;                         /* 8c077c0a mov.w */
    r3 = c_rd32(ram, X + r0);           /* 8c077c0c [X+0x9c] (r15=X-36) */
    c_wr32(ram, X - 40, r3);            /* 8c077c0e push r3 */
    r7 = 0x9Cu;                         /* 8c077c10 mov.w */
    r7 += X - 40;                       /* 8c077c12 (r15=X-40: X+0x70) */
    r5 = r14;                           /* 8c077c14 */
    /* 8c077c16 bsr 0x8c0781ba: RARE-CALL GATE (0781BA 1x in edges) */
    o->gated = 17;
    return;
L_7c24:
    r0 = 116;                           /* 8c077c24 */
    r3 = 0x80000000u;                   /* 8c077c26 mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c077c28 [X+116] */
    T = ((r3 & r2) == 0);               /* 8c077c2a tst r3,r2 */
    if (T)
        goto L_7c32;                    /* 8c077c2c bt */
    goto L_7e38dir;                     /* 8c077c2e bra 077e38 */
L_7c32:
    r0 = 0x88u;                         /* 8c077c32 mov.w */
    r3 = 0x40000000u;                   /* 8c077c34 mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c077c36 [X+0x88] */
    T = ((r3 & r1) == 0);               /* 8c077c38 tst r3,r1 */
    if (!T)
        goto L_7ca8;                    /* 8c077c3a bf */
    r0 = 0x88u;                         /* 8c077c3c mov.w */
    { r2 = 0x08000000u; } /* 8c077c3e mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c077c40 [X+0x88] */
    T = ((r2 & r1) == 0);               /* 8c077c42 tst r2,r1 */
    if (!T)
        goto L_7ca8;                    /* 8c077c44 bf */
    r0 = 80;                            /* 8c077c46 */
    r1 = c_rd32(ram, X + 60);           /* 8c077c48 [X+60] */
    r0 = c_rd32(ram, X + r0);           /* 8c077c4a [X+80] */
    r1 |= r0;                           /* 8c077c4c */
    T = ((r1 & 240) == 0);              /* 8c077c4e tst #240,r1 */
    if (T)
        goto L_7ca8;                    /* 8c077c50 bt */
    r0 = 120;                           /* 8c077c52 */
    { r2 = 0; } /* 8c077c54 */
    c_wr32(ram, X + r0, r2);            /* 8c077c56 [X+120] = 0 */
    r0 = 80;                            /* 8c077c58 */
    r3 = c_rd32(ram, X + r0);           /* 8c077c5a [X+80] */
    r0 = 76;                            /* 8c077c5c */
    c_wr32(ram, X - 4, r3);             /* 8c077c5e push r3 */
    { r2 = c_rd32(ram, X + 8); } /* 8c077c60 [X+8] (r15=X-4) */
    c_wr32(ram, X - 8, r2);             /* 8c077c62 push r2 */
    r3 = c_rd32(ram, X + 76);           /* 8c077c64 [X+76] (r15=X-8) */
    r0 = 76;                            /* 8c077c66 */
    c_wr32(ram, X - 12, r3);            /* 8c077c68 push r3 */
    { r2 = c_rd32(ram, X + 76); } /* 8c077c6a [X+76] (r15=X-12) */
    c_wr32(ram, X - 16, r2);            /* 8c077c6c push r2 */
    r0 = 0x90u;                         /* 8c077c6e mov.w */
    r3 = c_rd32(ram, X + r0);           /* 8c077c70 [X+0x90] (r15=X-16) */
    r0 = 92;                            /* 8c077c72 */
    c_wr32(ram, X - 20, r3);            /* 8c077c74 push r3 */
    { r2 = c_rd32(ram, X + r0); } /* 8c077c76 [X+92] (r15=X-20) */
    c_wr32(ram, X - 24, r2);            /* 8c077c78 push r2 */
    r3 = 0xA0u;                         /* 8c077c7a mov.w */
    r3 += X - 24;                       /* 8c077c7c (r15=X-24: X+0x88) */
    c_wr32(ram, X - 28, r3);            /* 8c077c7e push r3 */
    r0 = 0xA0u;                         /* 8c077c80 mov.w */
    { r2 = c_rd32(ram, X + r0); } /* 8c077c82 [X+0xa0] (r15=X-28) */
    c_wr32(ram, X - 32, r2);            /* 8c077c84 push r2 */
    r0 = 0x90u;                         /* 8c077c86 mov.w */
    r3 = c_rd32(ram, X + r0);           /* 8c077c88 [X+0x90] (r15=X-32) */
    c_wr32(ram, X - 36, r3);            /* 8c077c8a push r3 */
    r0 = 0x9Cu;                         /* 8c077c8c mov.w */
    { r2 = c_rd32(ram, X + r0); } /* 8c077c8e [X+0x9c] (r15=X-36) */
    c_wr32(ram, X - 40, r2);            /* 8c077c90 push r2 */
    r7 = 0x9Cu;                         /* 8c077c92 mov.w */
    r5 = r14;                           /* 8c077c94 */
    r6 = r13;                           /* 8c077c96 */
    r7 += X - 40;                       /* 8c077c98 (r15=X-40: X+0x70) */
    /* 8c077c9a bsr 0x8c078170: RARE-CALL GATE (078170 2x in edges) */
    o->gated = 18;
    return;
L_7ca8:
    r0 = 0x1B83u;                       /* 8c077ca8 mov.w */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); } /* 8c077caa mov.b */
    r0 -= 1;                            /* 8c077cac -> 0x1b82 */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077cae mov.b */
    T = (r3 == r2);                     /* 8c077cb0 cmp/eq r3,r2 */
    if (T)
        goto L_7cb8;                    /* 8c077cb2 bt */
    goto L_7694;                        /* 8c077cb4 bra 077694 (loop) */
L_7cb8:
    r0 = 0x1BB1u;                       /* 8c077cb8 mov.w */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077cba mov.b */
    T = (r3 == 0);                      /* 8c077cbc tst r3,r3 */
    if (T)
        goto L_7cc8;                    /* 8c077cbe bt */
    r0 = 0x1BB5u;                       /* 8c077cc0 mov.w */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077cc2 mov.b */
    r0 -= 50;                           /* 8c077cc4 -> 0x1b83 */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c077cc6 mov.b */
L_7cc8:
    r0 = 0x88u;                         /* 8c077cc8 mov.w */
    r3 = 0x40000000u;                   /* 8c077cca mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c077ccc [X+0x88] */
    T = ((r3 & r2) == 0);               /* 8c077cce tst r3,r2 */
    if (T)
        goto L_7cd6;                    /* 8c077cd0 bt */
    goto L_7e38dir;                     /* 8c077cd2 bra 077e38 */
L_7cd6:
    r0 = 0x80u;                         /* 8c077cd6 mov.w */
    r3 = 0x00080000u;                   /* 8c077cd8 mov.l pool value */
    r1 = c_rd32(ram, X + r0);           /* 8c077cda [X+0x80] */
    T = ((r3 & r1) == 0);               /* 8c077cdc tst r3,r1 */
    if (T)
        goto L_7ce4;                    /* 8c077cde bt */
    goto L_7e38dir;                     /* 8c077ce0 bra */
L_7ce4:
    r0 = c_rd32(ram, X + 4);            /* 8c077ce4 [X+4] */
    T = ((r0 & 240) == 0);              /* 8c077ce6 tst #240,r0 */
    if (T)
        goto L_7d34;                    /* 8c077ce8 bt */
    r1 = 0x80u;                         /* 8c077cea mov.w */
    r1 += X;                            /* 8c077cec */
    r0 = c_rd32(ram, r1);               /* 8c077cee [X+0x80] */
    T = ((r0 & 32) == 0);               /* 8c077cf0 tst #32,r0 */
    goto L_7d1c;                        /* 8c077cf2 bra 077d1c */
L_7d1c:
    T = ((r0 & 32) == 0);
    if (T)
        goto L_7d26;                    /* 8c077d1c bt */
    r3 = 0x0C102D64u;                   /* 8c077d1e mov.l pool value */
    { r2 = c_rd32(ram, r3); } /* 8c077d20 [0x0c102d64] */
    c_wr32(ram, r14 + 48, r2);          /* 8c077d24 delay (always) */
    goto L_7e16;                        /* 8c077d22 bra 077e16 */
L_7d26:
    r1 = 0x80u;                         /* 8c077d26 mov.w */
    r1 += X;                            /* 8c077d28 */
    r0 = c_rd32(ram, r1);               /* 8c077d2a [X+0x80] */
    T = ((r0 & 64) == 0);               /* 8c077d2c tst #64,r0 */
    if (T)
        goto L_7d34;                    /* 8c077d2e bt */
    goto L_7e38dir;                     /* 8c077d30 bra */
L_7d34:
    r3 = r14;                           /* 8c077d34 */
    r3 += 56;                           /* 8c077d36 */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, r3 + 3); /* 8c077d38 mov.b */
    r0 &= 0xFFu;                        /* 8c077d3a extu.b */
    c_wr32(ram, X + 16, r0);            /* 8c077d3c [X+16] */
    r0 = c_rd32(ram, X + 4);            /* 8c077d3e [X+4] */
    T = ((r0 & 16) == 0);               /* 8c077d40 tst #16,r0 */
    r0 = 68;                            /* 8c077d44 delay (always) */
    if (!T)
        goto L_7da6;                    /* 8c077d42 bf */
    r3 = c_rd32(ram, X + 4);            /* 8c077d46 [X+4] */
    { r2 = c_rd32(ram, X + r0); } /* 8c077d48 [X+68] */
    T = ((r3 & r2) == 0);               /* 8c077d4a tst r3,r2 */
    if (T)
        goto L_7d64;                    /* 8c077d4c bt */
    r0 = c_rd32(ram, X + 16);           /* 8c077d4e [X+16] */
    T = (r0 == 16);                     /* 8c077d50 cmp/eq #16 */
    if (T)
        goto L_7e38dir;                 /* 8c077d52 bt */
    r0 = 76;                            /* 8c077d54 */
    r3 = 0x00040000u;                   /* 8c077d56 mov.l pool value */
    { r2 = c_rd32(ram, r14 + r0); } /* 8c077d58 */
    T = ((r3 & r2) == 0);               /* 8c077d5a tst r3,r2 */
    if (!T)
        goto L_7e38dir;                 /* 8c077d5c bf */
    r1 = 0x03000000u;                   /* 8c077d5e mov.l pool value */
    goto L_e06;                        /* 8c077d60 bra 077e06 */
L_7d64:
    r0 = 64;                            /* 8c077d64 */
    r3 = c_rd32(ram, X + 4);            /* 8c077d66 [X+4] */
    { r2 = c_rd32(ram, X + r0); } /* 8c077d68 [X+64] */
    T = ((r3 & r2) == 0);               /* 8c077d6a tst r3,r2 */
    if (T)
        goto L_7d9a;                    /* 8c077d6c bt */
    r0 = c_rd32(ram, X + 16);           /* 8c077d6e [X+16] */
    T = (r0 == 17);                     /* 8c077d70 cmp/eq #17 */
    if (T)
        goto L_7e38dir;                 /* 8c077d72 bt */
    r0 = 72;                            /* 8c077d74 */
    r3 = 0x80000000u;                   /* 8c077d76 mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c077d78 [X+72] */
    T = ((r3 & r2) == 0);               /* 8c077d7a tst r3,r2 */
    if (!T)
        goto L_7d84;                    /* 8c077d7c bf */
    { r2 = 0x04000000u; } /* 8c077d7e mov.l pool value */
    goto L_7dd8;                        /* 8c077d80 bra 077dd8 */
L_7d84:
    r0 = 97;                            /* 8c077d84 */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077d86 mov.b */
    r0 &= 0xFFu;                        /* 8c077d88 extu.b */
    T = (r0 == 12);                     /* 8c077d8a cmp/eq #12 */
    if (!T)
        goto L_7d94;                    /* 8c077d8c bf */
    { r2 = 0x0530u; } /* 8c077d8e mov.w */
    goto L_7dd8;                        /* 8c077d90 bra 077dd8 */
L_7d94:
    r1 = 0x01BCu;                       /* 8c077d94 mov.w */
    goto L_e06;                        /* 8c077d96 bra 077e06 */
L_7d9a:
    r0 = c_rd32(ram, X + 16);           /* 8c077d9a [X+16] */
    T = (r0 == 17);                     /* 8c077d9c cmp/eq #17 */
    if (T)
        goto L_7e38dir;                 /* 8c077d9e bt */
    r3 = 0x01000000u;                   /* 8c077da0 mov.l pool value */
    goto L_7db8;                        /* 8c077da2 bra 077db8 */
L_7da6:
    r0 = 68;                            /* 8c077da6 */
    r3 = c_rd32(ram, X + 4);            /* 8c077da8 [X+4] */
    { r2 = c_rd32(ram, X + r0); } /* 8c077daa [X+68] */
    T = ((r3 & r2) == 0);               /* 8c077dac tst r3,r2 */
    if (T)
        goto L_7dbc;                    /* 8c077dae bt */
    r0 = c_rd32(ram, X + 16);           /* 8c077db0 [X+16] */
    T = (r0 == 18);                     /* 8c077db2 cmp/eq #18 */
    if (T)
        goto L_7e38dir;                 /* 8c077db4 bt */
    r3 = 0x05000000u;                   /* 8c077db6 mov.l pool value */
    goto L_7db8;                        /* 8c077db6? (fallthrough shape) */
L_7db8:
    c_wr32(ram, X + 56, r3);            /* 8c077dba delay (always) */
    goto L_e08;                        /* 8c077db8 bra 077e08 */
L_7dbc:
    r0 = 64;                            /* 8c077dbc */
    r3 = c_rd32(ram, X + 4);            /* 8c077dbe [X+4] */
    { r2 = c_rd32(ram, X + r0); } /* 8c077dc0 [X+64] */
    T = ((r3 & r2) == 0);               /* 8c077dc2 tst r3,r2 */
    if (T)
        goto L_e04;                    /* 8c077dc4 bt */
    r0 = c_rd32(ram, X + 16);           /* 8c077dc6 [X+16] */
    T = (r0 == 19);                     /* 8c077dc8 cmp/eq #19 */
    if (T)
        goto L_7e38dir;                 /* 8c077dca bt */
    r0 = 72;                            /* 8c077dcc */
    r3 = 0x80000000u;                   /* 8c077dce mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c077dd0 [X+72] */
    T = ((r3 & r2) == 0);               /* 8c077dd2 tst r3,r2 */
    if (!T)
        goto L_7d84;                    /* 8c077dd4 bf */
    { r2 = 0x06000000u; } /* 8c077dd6 mov.l pool value */
    goto L_7dd8;                        /* 8c077dd6? (fallthrough) */
L_7dd8:
    c_wr32(ram, X + 56, r2);            /* 8c077dda delay (always) */
    goto L_e08;                         /* 8c077dd8 bra 077e08 */
L_7286:
    { r2 = c_rd32(ram, X + 56); } /* 8c077286 [X+56] */
    c_wr32(ram, r14 + 48, r2);          /* 8c077288 delay (always) */
    goto L_7e0c;                        /* 8c077288 bra 077e0c */
L_74c0:
    r0 = 0x88u;                         /* 8c0774c0 mov.w */
    r3 = 0x80000000u;                   /* 8c0774c2 mov.l pool value */
    { r2 = c_rd32(ram, X + r0); } /* 8c0774c4 [X+0x88] */
    r0 = 0x88u;                         /* 8c0774c6 mov.w */
    { r2 |= r3; } /* 8c0774c8 or r3,r2 */
    c_wr32(ram, X + r0, r2);            /* 8c0774ca [X+0x88] */
    goto L_74cc;                        /* (fallthrough to 0774cc) */
L_7720:
    r0 = 0x1B83u;                       /* 8c077720 mov.w */
    r3 = c_rd32(ram, X + 28);           /* 8c077722 [X+28] */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c077724 mov.b */
    r0 -= 1;                            /* 8c077726 -> 0x1b82 */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); } /* 8c077728 mov.b */
    r0 = 108;                           /* 8c07772a */
    { r2 &= 0xFFu; } /* 8c07772c extu.b */
    c_wr32(ram, X + 32, r2);            /* 8c07772e [X+32] */
    r3 = c_rd32(ram, X + 28);           /* 8c077730 [X+28] */
    { r2 -= r3; } /* 8c077732 sub r3,r2 */
    c_wr32(ram, X + 24, r2);            /* 8c077734 [X+24] */
    { r2 = 11; } /* 8c077736 */
    c_wr32(ram, X + 108, r2);           /* 8c077738 [X+108] = 11 */
    r0 = 76;                            /* 8c07773a */
    r1 = c_rd32(ram, r14 + r0);         /* 8c07773c */
    r3 = 0x2000u;                       /* 8c07773e mov.w */
    T = ((r3 & r1) == 0);               /* 8c077740 tst r3,r1 */
    if (T)
        goto L_774a;                    /* 8c077742 bt */
    r0 = 108;                           /* 8c077744 */
    { r2 = 12; } /* 8c077746 */
    c_wr32(ram, X + r0, r2);            /* 8c077748 [X+108] = 12 */
    goto L_774a;                        /* (fallthrough to 07774a) */
L_f08:
    r0 = 0x1B82u;                       /* 8c076f08 mov.w */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c076f0a mov.b */
    r3 &= 0xFFu;                        /* 8c076f0c extu.b */
    c_wr32(ram, X + 32, r3);            /* 8c076f0e [X+32] */
    r3 <<= 2;                           /* 8c076f10 shll2 */
    r2 = 0x00FCu;                       /* 8c076f12 mov.w */
    r3 &= r2;                           /* 8c076f14 */
    c_wr32(ram, X + 20, r3);            /* 8c076f16 [X+20] */
    goto L_6f18;                        /* (076f16 fallthrough to 076f18) */
L_7e38dir:
    goto L_e38epi;                      /* (077e38 epilogue head) */
L_7e0c:
    c_wr32(ram, r14 + 48, r3);          /* 8c077e0c (delay-slot land) */
L_7e0e:
    r0 = 0x1B82u;                       /* 8c077e0e mov.w */
    r1 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077e10 mov.b */
L_7e12:
    r0 += 1;                            /* 8c077e12 add #1,r0 */
    c_wr8(ram, r14 + r0, (uint8_t)r1);  /* 8c077e14 mov.b */
    goto L_7e16;
L_7e16:
    r0 = 0x1B83u;                       /* 8c077e16 mov.w */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); /* 8c077e18 mov.b */
    r0 += 1;                            /* 8c077e1a -> 0x1b84 */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c077e1c mov.b */
    r0 -= 1;                            /* 8c077e1e -> 0x1b83 */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, r14 + r0); } /* 8c077e20 mov.b */
    r0 = 108;                           /* 8c077e22 */
    { r2 &= 0xFFu; } /* 8c077e24 extu.b */
    c_wr32(ram, X + r0, r2);            /* 8c077e26 [X+108] */
    r0 = 108;                           /* 8c077e28 */
    r3 = (uint32_t)(uint8_t)c_rd8s(ram, X + r0); /* 8c077e2a mov.b */
    r0 = 0x1B85u;                       /* 8c077e2c mov.w */
    c_wr8(ram, r14 + r0, (uint8_t)r3);  /* 8c077e2e mov.b */
    r0 = 108;                           /* 8c077e30 */
    { r2 = (uint32_t)(uint8_t)c_rd8s(ram, X + r0); } /* 8c077e32 mov.b */
    r0 = 0x1B86u;                       /* 8c077e34 mov.w */
    c_wr8(ram, r14 + r0, (uint8_t)r2);  /* 8c077e36 mov.b */
    goto L_e38epi;
L_e04:
    r1 = 0x02000000u;                   /* 8c077e04 mov.l pool value */
L_e06:
    c_wr32(ram, X + 56, r1);            /* 8c077e06 [X+56] */
L_e08:
    r3 = c_rd32(ram, X + 56);           /* 8c077e08 [X+56] */
    c_wr32(ram, r14 + 48, r3);          /* 8c077e0c delay (always) */
    goto L_e38epi;                      /* 8c077e0a bra 077e38 */
L_e38epi:
    r0 = 0x88u;                         /* 8c077e38 mov.w */
    r3 = c_rd32(ram, X + r0);
    r0 = 0x1B88u;
    c_wr32(ram, r14 + r0, r3);
    goto L_e40epi;
L_e40epi:
    r1 = 0x9Cu;
    X += r1;
    o->pr = c_rd32(ram, X);
    r12 = c_rd32(ram, X + 4);
    r13 = c_rd32(ram, X + 8);
    r14 = c_rd32(ram, X + 12);
    goto L_eca;
L_eca:
    o->r0 = r0;
    o->r1 = r1;
    o->r2 = r2;
    o->r3 = r3;
    o->r4 = r4;
    o->r5 = r5;
    o->r6 = r6;
    o->r7 = r7;
    o->r8 = r8;
    o->r9 = r9;
    o->r10 = r10;
    o->r11 = r11;
    o->r12 = r12;
    o->r13 = r13;
    o->r14 = r14;
    o->r15 = in_r15 + 12;
    o->sr = (sr & ~1u) | (T ? 1u : 0u);
}

#undef SETT
