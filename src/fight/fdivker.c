/* See fdivker.h. All traffic goes through the replay map so the test
 * diffs the shadow against the oracle exit windows. */
#include "fight/fdivker.h"
#include "fight/fpu_tz.h"

#include <string.h>

static uint32_t k_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static void k_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
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

/* ROM constants at 0x8C03A91C..0x8C03A930 (mova loads f708/f208/f108/f508). */
#define C0_BITS 0x40000000u   /* 2.0 */
#define C1_BITS 0x40C90FDAu   /* 2pi */
#define C2_BITS 0x47800000u   /* 65536.0 */
#define C3_BITS 0x3FC90FDAu   /* pi/2 */
#define C4_BITS 0x3F000000u   /* 0.5 */
#define R0_EXIT 0x0C03A92Cu   /* last mova target, execution alias */

/* SH-4 float(fpul,FRn): exact int32 -> float. ftrc: truncate to zero. */
static float k_float(int32_t v, uint32_t fpscr)
{
    float f = fpu_dn_fix(f32_tz((long double)v), fpscr);
    return f;
}

static int32_t k_ftrc(float f)
{
    /* truncate toward zero (C cast); out-of-range to INT_MIN per x86;
     * oracle decides (all observed values small). */
    if (f >= 2147483648.0 || f <= -2147483649.0)
        return (int32_t)0x80000000u;
    return (int32_t)f;
}

static void body(uint32_t r4in, uint32_t r5, uint32_t r6gpr, uint32_t sr,
                 uint32_t fpscr, vf3_fdivker_out *o)
{
    uint32_t r3, r4;
    int32_t fpul;
    int T;
    float fr0, fr1, fr2, fr3, fr4, fr5, fr6, fr7;
    float c0, c1, c2, c3, c4;

    memcpy(&c0, &(uint32_t){ C0_BITS }, 4);
    memcpy(&c1, &(uint32_t){ C1_BITS }, 4);
    memcpy(&c2, &(uint32_t){ C2_BITS }, 4);
    memcpy(&c3, &(uint32_t){ C3_BITS }, 4);
    memcpy(&c4, &(uint32_t){ C4_BITS }, 4);

    r4 = r4in & 0xFFFFu;                  /* 8c03a6e0 extu.w */
    fpul = (int32_t)r4;                   /* 8c03a6e2 lds */
    fr7 = c0; fr2 = c1;                   /* 8c03a6e6/e a */
    fr3 = k_float(fpul, fpscr);           /* 8c03a6ee */
    fr1 = c2; fr5 = c3; fr0 = c4;         /* 8c03a6f0/f4/f8 */
    r4 = 11;                              /* 8c03a6fa */
    r5 = 3;                               /* 8c03a6fc mov #3,r5: entry r5
                                           * discarded (kept as a parameter
                                           * for call-site documentation) */
    fr3 = fpu_dn_fix(fmul_tz(fr2, fr3), fpscr);   /* 8c03a6fe */
    fr3 = fpu_dn_fix(fdiv_tz(fr3, fr1), fpscr);   /* 8c03a700 fdiv fr1,fr3 */
    fr4 = fr3;                            /* 8c03a702 */
    fr4 = fpu_dn_fix(fdiv_tz(fr4, fr7), fpscr);   /* 8c03a704 */
    fr3 = fr4;                            /* 8c03a706 */
    fr3 = fpu_dn_fix(fdiv_tz(fr3, fr5), fpscr);   /* 8c03a708 */
    fr3 = fpu_dn_fix(fadd_tz(fr0, fr3), fpscr);   /* 8c03a70a */
    r6gpr = (uint32_t)k_ftrc(fr3);        /* 8c03a70c/e */
    fpul = (int32_t)r6gpr;                /* 8c03a710 lds */
    fr3 = k_float(fpul, fpscr);           /* 8c03a712 */
    fr3 = fpu_dn_fix(fmul_tz(fr5, fr3), fpscr);   /* 8c03a714 */
    fr5 = 0.0f;                           /* 8c03a716 fldi0 */
    fr4 = fpu_dn_fix(fsub_tz(fr4, fr3), fpscr);   /* 8c03a718 */
    fr6 = fr4;                            /* 8c03a71a */
    fr6 = fpu_dn_fix(fmul_tz(fr4, fr6), fpscr);   /* 8c03a71c */
    for (;;) {                            /* 8c03a71e loop */
        fpul = (int32_t)r4;               /* 8c03a71e lds */
        r4 = (uint32_t)((int32_t)r4 - 2); /* 8c03a720 */
        T = ((int32_t)r4 >= (int32_t)r5); /* 8c03a722 cmp/ge */
        fr2 = k_float(fpul, fpscr);       /* 8c03a724 */
        fr2 = fpu_dn_fix(fsub_tz(fr2, fr5), fpscr); /* 8c03a726 */
        fr5 = fr6;                        /* 8c03a728 */
        fr5 = fpu_dn_fix(fdiv_tz(fr5, fr2), fpscr); /* 8c03a72c delay */
        if (!T)                           /* 8c03a72a bt/s */
            break;
    }
    fr6 = 1.0f;                           /* 8c03a72e fldi1 */
    r3 = 1;                               /* 8c03a730 */
    fr3 = fr6;                            /* 8c03a732 */
    fr3 = fpu_dn_fix(fsub_tz(fr3, fr5), fpscr);   /* 8c03a734 */
    T = ((r3 & r6gpr) == 0);              /* 8c03a736 tst */
    fr4 = fpu_dn_fix(fdiv_tz(fr4, fr3), fpscr);   /* 8c03a738 */
    fr2 = fr4;                            /* 8c03a73a fmov fr4,fr2 */
    fr2 = fpu_dn_fix(fmul_tz(fr7, fr2), fpscr);   /* 8c03a73c */
    fr0 = fr4;                            /* 8c03a73e */
    fr6 = fpu_dn_fix(fmac_tz(fr0, fr4, fr6), fpscr); /* 8c03a740 */
    fr4 = fr2;                            /* 8c03a742 */
    fr4 = fpu_dn_fix(fdiv_tz(fr4, fr6), fpscr);   /* 8c03a746 delay */
    if (!T) {                             /* 8c03a744 bf/s */
        fr0 = fr4;                        /* 8c03a750 (fallthrough path) */
        {
            uint32_t b;
            memcpy(&b, &fr0, 4);
            b ^= 0x80000000u;             /* 8c03a752 fneg */
            memcpy(&fr0, &b, 4);
        }
    }
    /* 8c03a748 rts (+fmov fr4,fr0 delay on the T path): fr0 already fr4. */
    if (T)
        fr0 = fr4;

    o->r0 = R0_EXIT;
    o->r3 = r3;
    o->r4 = r4;
    o->r5 = 3;                            /* 8c03a6fc mov #3,r5, never changed */
    o->r6 = r6gpr;
    o->fr0 = fpu_f32_to_bits(fr0);
    o->fr1 = fpu_f32_to_bits(fr1);
    o->fr2 = fpu_f32_to_bits(fr2);
    o->fr3 = fpu_f32_to_bits(fr3);
    o->fr4 = fpu_f32_to_bits(fr4);
    o->fr5 = fpu_f32_to_bits(fr5);
    o->fr6 = fpu_f32_to_bits(fr6);
    o->fr7 = fpu_f32_to_bits(fr7);
    o->sr = T ? (sr | 1u) : (sr & ~1u);
}

void vf3_fdivker_8c03a6e0(uint32_t in_r1, uint32_t in_r4, uint32_t in_r5,
                          uint32_t in_r6, uint32_t in_r15, uint32_t in_sr,
                          uint32_t in_fpscr, vf3_fdivker_out *o,
                          const vf3_ram_map *ram)
{
    (void)ram;
    body(in_r4, in_r5, in_r6, in_sr, in_fpscr, o);
    o->r1 = in_r1;                        /* untouched by the body */
    o->r15 = in_r15;
}

void vf3_fdivker_8c03a140(uint32_t in_r1, uint32_t in_r4, uint32_t in_r14,
                          uint32_t in_r5, uint32_t in_r6, uint32_t in_r15,
                          uint32_t in_sr, uint32_t in_fpscr,
                          vf3_fdivker_out *o, const vf3_ram_map *ram)
{
    uint32_t r14, r3, r1, r4;
    uint32_t sp = in_r15 - 4;             /* 8c03a140 push r14 */
    k_wr32(ram, sp, in_r14);
    r14 = in_r4 & 0xFFFFu;                /* 8c03a142 extu.w */
    r3 = 0x00008000u;                     /* 8c03a144 lit */
    r1 = in_r1;                           /* untouched on the skip path */
    if (!((int32_t)r14 > (int32_t)r3))    /* 8c03a146 cmp/gt, 8c03a148 bf */
        goto merge;
    r1 = 0x00010000u;                     /* 8c03a14a lit */
    r1 = (uint32_t)((int32_t)r1 - (int32_t)r14); /* 8c03a14c */
    r14 = r1;                             /* 8c03a14e */
merge:
    r4 = 0x00004000u;                     /* 8c03a150 lit.w */
    r4 = (uint32_t)((int32_t)r4 - (int32_t)r14); /* 8c03a152 */
    r14 = k_rd32(ram, sp);                /* 8c03a156 delay: pop r14 */
    (void)r14;
    body(r4, in_r5, in_r6, in_sr, in_fpscr, o);
    o->r1 = r1;
    o->r15 = in_r15;                      /* balanced push/pop */
}
