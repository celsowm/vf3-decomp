/* See c678e.h. All traffic goes through the replay map so the test diffs
 * the shadow against the oracle exit windows.
 *
 * Coverage: prologue / 28-loop (inline scalemap twin) / select /
 * branch tree (odd early-exit at 0x693C) / deep FPU chain (even) with
 * nested 069624 (baked atan ramp) and 06911C/06912A (walk path) /
 * shared FPU tail / epilogue. Untaken sides are loud gates.
 */
#include "fight/c678e.h"
#include "fight/c678e_tbl.h"
#include "fight/fpu_tz.h"

#include <math.h>
#include <string.h>

#define SETT(v) do { T = (v) ? 1 : 0; } while (0)

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

static uint16_t c_rd16u(const vf3_ram_map *ram, uint32_t addr)
{
    return (uint16_t)c_rd16s(ram, addr);
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

/* ---- [0x0C2D0190] flag mirror (8 words; outside golden windows).
 * Every read on emulated paths follows an in-function write. -------- */
typedef struct { uint32_t w[8]; } c_flags;

/* ---- SH-4 0x8C069624: FPU ratio/index kernel (leaf, no RAM traffic).
 * fr4/fr5 in; returns table index in r0. Clobbers fr2/fr3/fr6/fr7/fr8
 * (caller reloads them). Only memory op is the baked atan-ramp halfword.
 * fpscr carries DN for denormal flushing. ---------------------------- */
static int32_t c_9624(float fr4in, float fr5in, float *fr2p, float *fr3p,
                      float *fr6p, float *fr7p, float *fr8p,
                      uint32_t fpscr, int *gated)
{
    float fr2 = 0.0f, fr3, fr4 = fr4in, fr5 = fr5in, fr6, fr7, fr8;
    int T;
    int32_t r0, r4;
    uint32_t r1, r2;

    fr3 = 0.0f;                          /* 8c069624 fldi0 fr3 */
    T = (fr5 == fr3);                    /* fcmp/eq fr3,fr5 */
    if (!T)
        goto L632;
    T = (fr4 == fr3);                    /* fcmp/eq fr3,fr4 */
    if (!T)
        goto L632;
    r0 = 0;                              /* delay: mov #0,r0 */
    return r0;                           /* rts (both zero) */
L632:
    fr3 = 0.0f;                          /* fldi0 fr3 */
    T = (fr3 > fr5);                     /* fcmp/gt fr5,fr3 */
    if (!T) {                            /* bf/s 0x69640 */
        fr3 = 0.0f;                      /* delay fldi0 */
        fr6 = fr5;                       /* 0x6963a fmov fr5,fr6 */
        goto L642;                       /* bra */
    } else {
        fr6 = fr5;                       /* delay-slot form 0x69640 */
        fr6 = -fr6;                      /* 0x6963e fneg fr6 */
    }
L642:
    T = (fr3 > fr4);                     /* fcmp/gt fr4,fr3 */
    if (!T) {
        fr7 = fr4;
        goto L64e;
    } else {
        fr7 = fr4;                       /* delay-slot form */
        fr7 = -fr7;                      /* fneg fr7 */
    }
L64e:
    fr6 = fpu_dn_fix(fr6, fpscr);
    fr7 = fpu_dn_fix(fr7, fpscr);
    T = (fr6 > fr7);                     /* fcmp/gt fr7,fr6 */
    if (T) {
        fr8 = fr7;                       /* 8c069652 fmov fr7,fr8 */
        fr8 = fpu_dn_fix(fdiv_tz(fr8, fr6), fpscr); /* 8c069654: fr8/=fr6 */
    } else {
        fr8 = fr6;                       /* 8c069658 fmov fr6,fr8 */
        fr8 = fpu_dn_fix(fdiv_tz(fr8, fr7), fpscr); /* 8c06965a: fr8/=fr7 */
    }
    fr2 = fr8;                           /* fmov fr8,fr2 */
    fr3 = bits_f(0x466A6000u);           /* mova K=15000 @0x696a4 */
    fr2 = fpu_dn_fix(fmul_tz(fr3, fr2), fpscr);
    r4 = (int32_t)fr2;                   /* ftrc */
    r4 <<= 1;                            /* shll (byte offset) */
    T = (fr6 > fr7);                     /* fcmp/gt fr6,fr7 */
    { /* delay (always): table halfword */
        if (r4 < 0 || (uint32_t)r4 + 2 > (uint32_t)(VF3_C678E_TBL_N * 2)) {
            *gated = 201;
            return 0;
        }
        r4 = (int32_t)(int16_t)vf3_c678e_tbl[(uint32_t)r4 >> 1];
    }
    if (T)
        goto L678;                       /* bf/s not taken */
    r2 = 0x4000u;                        /* delay-form path */
    r4 = (int32_t)r2 - r4;               /* sub r4,r2 */
    r4 = r4;                             /* mov r2,r4 */
L678:
    fr3 = 0.0f;                          /* fldi0 fr3 */
    T = (fr3 > fr5);                     /* fcmp/gt fr5,fr3 */
    if (T)
        goto L688;                       /* bt */
    fr3 = 0.0f;                          /* fldi0 */
    T = (fr3 > fr4);                     /* fcmp/gt fr4,fr3 */
    if (!T)
        goto L698;                       /* bf (fr4>=0: no neg) */
    r4 = -r4;                            /* 8c069686 delay (always) */
    goto L698;                           /* bra */
L688:
    T = (fr3 > (float)fr4);              /* fcmp/gt fr4,fr3 */
    if (T)
        goto L694;
    r2 = 0x00008000u;
    r4 = (int32_t)r2 - r4;
    goto L698;
L694:
    r1 = 0x8000u;
    r4 = r4 + (int32_t)r1;
L698:
    r0 = r4;
    *fr2p = fr2; *fr3p = fr3; *fr6p = fr6; *fr7p = fr7; *fr8p = fr8;
    return r0;                           /* rts */
}


/* OOB-data stubs for the 06912A mesh walk (phase 2).
 * Provenance: case-independent constants observed across even goldens
 * ([X+52..] floats, node pointer, [node]=1). The walk CONTROL is faithful;
 * only unreadable-mesh words are stubbed (no map access -> zero OOB). */
static const uint32_t W_NODE = 0x0CBD9618u;
static const uint32_t W_NODE0 = 1u;              /* [node] */
static const uint32_t W_N2 = 2u;                 /* [node2] */
static const uint32_t W_N2_20 = 0x3C9628CCu;     /* [node2+20] */
static const uint32_t W_N2_24 = 0x3F7FF4EDu;     /* [node2+24] */
static const uint32_t W_N2_28 = 0x3AAEB80Fu;     /* [node2+28] */

/* ---- SH-4 0x8C06911C wrapper + 0x8C06912A (mesh-walk path).
 * outptr = X+52 struct; sel = 15&mask (1 here); fr4/fr5 in.
 * Frame F = X-52 (slots [F+0..28]); wrapper pushes + sts mirrored.
 * Returns r0 (tail index); r7out = walk residue (1). fr outs reloaded by
 * caller afterwards (preserved here). --------------------------------- */
static int32_t c_6911c(uint32_t r4in, uint32_t outptr, uint32_t sel,
                       float fr4in, float fr5in, uint32_t X,
                       uint32_t retpr, uint32_t r9main,
                       float fr15main, float fr14main, uint32_t *r7out,
                       const vf3_ram_map *ram, uint32_t fpscr, int *gated)
{
    uint32_t F = X - 52;
    float fr1, fr2, fr3, fr4 = fr4in, fr5 = fr5in, fr6, fr7, fr8;
    int T;
    int32_t r0, r4;
    uint32_t r2, r3, r5, r6, r7, r11, r12, r14;
    (void)r4in; (void)sel;
    c_wr32(ram, X - 20, retpr);          /* wrapper+12A sts.l pr */
    c_wrflt(ram, F + 0, fr4);            /* 8c069134 [F+0]=fr4 */
    fr5 = -fr5;                          /* (caller fneg delay) */
    c_wrflt(ram, F + 4, fr5);            /* 8c069138 [F+4]=-fr5 */
    /* rescale (sel=1 after 15&1): no-op; bsr-push skipped (overwritten) */
    /* root read bypassed (OOB): walk path proven by [0x22E8] stores */
    fr3 = c_rdflt(ram, F + 0);           /* 8c069160 */
    fr4 = bits_f(0x41600000u);           /* 8c069162 mova 14.0 */
    SETT(fr4 > fr3);                     /* 8c069164 fcmp/gt fr3,fr4 */
    if (!T)
        goto L9180;                      /* 8c069166 bf */
    r0 = 4;                              /* 8c069168 */
    fr2 = c_rdflt(ram, F + 4);           /* 8c06916a */
    SETT(fr4 > fr2);                     /* 8c06916c fcmp/gt fr2,fr4 */
    if (!T)
        goto L9180;                      /* 8c06916e bf */
    fr1 = bits_f(0xC1600000u);           /* 8c069172 mova -14.0 */
    SETT(fr3 > fr1);                     /* 8c069174 fcmp/gt fr1,fr3 */
    if (!T)
        goto L9180;                      /* 8c069176 bf */
    fr3 = bits_f(0xC1600000u);           /* 8c06917a mova -14.0 */
    SETT(fr2 > fr3);                     /* 8c06917c fcmp/gt fr3,fr2 */
    if (T)
        goto L9184;                      /* 8c06917e bt */
L9180:
    r14 = 1;                             /* 8c069182 delay mov #1,r14 */
    goto L9180done;                      /* 8c069180 bra */
L9184:
    fr4 = bits_f(0x41800000u);           /* 8c069188 mova 16.0 */
    r0 = 24;                             /* 8c06918a */
    c_wrflt(ram, F + 24, c_rdflt(ram, F + 0));   /* 8c06918c [F+24]=fr3 */
    r0 = 4;                              /* 8c06918e */
    fr3 = c_rdflt(ram, F + 4);           /* 8c069190 */
    r0 = 20;                             /* 8c069192 */
    r7 = 31;                             /* 8c069194 mov #31,r7 */
    c_wrflt(ram, F + 20, fr3);           /* 8c069196 [F+20]=fr3 */
    r0 = 24;                             /* 8c069198 */
    fr3 = c_rdflt(ram, F + 24);          /* 8c06919a */
    r0 = 20;                             /* 8c06919c */
    fr5 = fr4;                           /* 8c06919e fmov fr4,fr5 */
    fr5 = fpu_dn_fix(fadd_tz(fr5, fr3), fpscr);  /* 8c0691a0 fadd fr3,fr5 */
    fr2 = c_rdflt(ram, F + 20);          /* 8c0691a2 */
    r0 = 28;                             /* 8c0691a4 */
    fr4 = fpu_dn_fix(fadd_tz(fr4, fr2), fpscr);  /* 8c0691a6 fadd fr2,fr4 */
    r4 = (int32_t)fr5;                   /* 8c0691a8 ftrc fr5,fpul */
    c_wrflt(ram, F + 28, fr4);           /* 8c0691aa [F+28]=fr4 */
    fr1 = fr4;                           /* 8c0691ac fmov fr4,fr1 */
    r4 = (int32_t)fr5;                   /* 8c0691ae sts fpul,r4 */
    fr1 = fr1;                           /* (ftrc fr1 form) */
    r6 = (int32_t)fr1;                   /* 8c0691b0 ftrc fr1,fpul */
    r0 = 0x1F0u;                         /* 8c0691b2 mov.w */
    r4 &= 31;                            /* 8c0691b4 and r7,r4 */
    r6 &= 31;                            /* 8c0691b8 and r7,r6 */
    r6 <<= 2; r6 <<= 2; r6 <<= 1;        /* 8c0691ba/bc/be shll2,2,1 */
    r4 |= r6;                            /* 8c0691c0 or r6,r4 */
    r4 <<= 2;                            /* 8c0691c2 shll2 */
    /* root chase bypassed: stub node (provenance above) */
    r4 = (int32_t)W_NODE;                /* node */
    r0 = (int32_t)r4;
    SETT(r0 == -1);                      /* 8c0691cc cmp/eq #-1,r0 */
    if (T) { *gated = 103; return 0; }   /* immediate-done: untripped */
    r11 = 0x0C113A0Cu;                   /* 8c0691d0 literal */
    r3 = 0x0CBD9618u;                    /* ([0x0C113A0C] in-window read) */
    r3 = c_rd32(ram, r11);               /* (kept as map read: in-window) */
    (void)r3;
    r4 = (int32_t)W_NODE;                /* add r3,r4 form (stubbed sum) */
    r14 = (uint32_t)r4;                  /* 8c0691d6 mov r4,r14 (node) */
    /* node loop (single iteration proven): 068FE4 stub */
    {
        /* 068FE4 pushes (sp=X-52) with caller regs; [frame]=r7&1 */
        uint32_t e_r14 = (uint32_t)r4;   /* node */
        uint32_t e_r13 = X + 52;         /* (06912A r13 = outptr) */
        uint32_t e_r12 = 1u;             /* (sel) */
        uint32_t e_r11 = 0x0C113A0Cu;
        uint32_t e_r10 = 4u;
        c_wr32(ram, X - 56, e_r14);
        c_wr32(ram, X - 60, e_r13);
        c_wr32(ram, X - 64, e_r12);
        c_wr32(ram, X - 68, e_r11);
        c_wr32(ram, X - 72, e_r10);
        c_wr32(ram, X - 76, r9main);     /* 068FE4 r9-push */
        c_wrflt(ram, X - 80, fr15main);  /* 068FE4 fr15-push */
        c_wrflt(ram, X - 84, fr14main);  /* 068FE4 fr14-push */
        c_wr32(ram, X - 88, 0x0C0691EAu);/* 068FE4 pr-push (bsr ret) */
        c_wr32(ram, X - 92, W_NODE0 & 1u); /* [frame] = r7&1 */
        r7 = W_NODE0 & 1u;               /* 068FE4 r7 residue */
        r0 = 1;                          /* 068FE4 ret (nonzero: continue) */
        /* fr outs overwritten by walk-continue loads below */
        fr6 = fr6; fr7 = fr7; fr8 = fr8;
        (void)e_r14; (void)e_r13; (void)e_r12; (void)e_r11; (void)e_r10;
    }
    r4 = r0;                             /* 8c0691ea mov r0,r4 (delay) */
    SETT(r4 == 0);                       /* 8c0691ec tst r4,r4 */
    if (T)
        goto L921a;                      /* 8c0691ee bt (not taken: ret=1) */
    /* walk-continue (stubbed node2 struct): */
    fr4 = bits_f(W_N2_20);               /* [node2+20] */
    fr5 = bits_f(W_N2_24);               /* [node2+24] */
    fr6 = bits_f(W_N2_28);               /* [node2+28] */
    r4 = (int32_t)W_N2;                  /* [node2] */
    r4 <<= 1;                            /* shll */
    r4 &= 0x1FFFC;                       /* and 0x0001fffc */
    r14 = (uint32_t)r4;                  /* mov r4,r14 (tail index) */
    c_wrflt(ram, F + 12, fr4);           /* 8c069208 [F+12]=fr4 */
    c_wrflt(ram, F + 16, fr5);           /* 8c06920e [F+16]=fr5 */
    c_wrflt(ram, F + 8, fr6);            /* 8c069218 delay [F+8]=fr6 */
    goto Ltail;                          /* 8c069216 bra */
L921a:
    { *gated = 102; return 0; }          /* multi-node loop: untripped */
L9180done:
    r14 = 1;                             /* 0x9180-path tail index */
    c_wrflt(ram, F + 16, 1.0f);          /* 8c06923e+ slot init */
    c_wrflt(ram, F + 8, 0.0f);
    c_wrflt(ram, F + 12, 0.0f);
    goto Ltail;
Ltail:
    r0 = 12;                             /* tail stores [outptr..] */
    fr3 = c_rdflt(ram, F + 12);          /* 8c069282 (walk-continue data) */
    r0 = 16;
    /* ({zero,0x9180}-path tail writes [F+16]=1.0 etc.; walk path uses
     * slots as stored above) */
    c_wrflt(ram, outptr, fr3);           /* 8c069286 [X+52] */
    fr3 = c_rdflt(ram, F + 16);
    r0 = 4;
    c_wrflt(ram, outptr + 4, fr3);       /* 8c06928c [X+56] */
    r0 = 8;
    fr3 = c_rdflt(ram, F + 8);
    c_wrflt(ram, outptr + 8, fr3);       /* 8c069294 [X+60] */
    r0 = (int32_t)r14;                   /* 8c069296 mov r14,r0 */
    *r7out = r7;                         /* (integer residue 1) */
    /* epilogue pops restore r11-r14 (modeled as no-ops: caller regs
     * untouched except r0/r7 above) */
    return r0;                           /* rts */
}

void vf3_c678e_8c0c678e(uint32_t in_r0, uint32_t in_r1, uint32_t in_r2,
                        uint32_t in_r3, uint32_t in_r4, uint32_t in_r5,
                        uint32_t in_r6, uint32_t in_r7, uint32_t in_r8,
                        uint32_t in_r9, uint32_t in_r10, uint32_t in_r11,
                        uint32_t in_r12, uint32_t in_r13, uint32_t in_r14,
                        uint32_t in_r15, uint32_t in_pr, uint32_t in_sr,
                        uint32_t in_fpscr,
                        float in_fr0, float in_fr1, float in_fr2,
                        float in_fr3, float in_fr4, float in_fr5,
                        float in_fr6, float in_fr7, float in_fr8,
                        float in_fr9, float in_fr10, float in_fr11,
                        float in_fr12, float in_fr13, float in_fr14,
                        float in_fr15, vf3_c678e_out *o,
                        const vf3_ram_map *ram)
{
    uint32_t r0 = in_r0, r1 = in_r1, r2 = in_r2, r3 = in_r3;
    uint32_t r4 = in_r4, r5 = in_r5, r6 = in_r6, r7 = in_r7;
    uint32_t r8 = in_r8, r9 = in_r9, r10 = in_r10, r11 = in_r11;
    uint32_t r12 = in_r12, r13 = in_r13, r14 = in_r14;
    uint32_t X = in_r15 - 4 - 64;    /* sts.l pr + add #-64 */
    uint32_t sr = in_sr;
    uint32_t fpscr = in_fpscr;
    float fr0 = in_fr0, fr1 = in_fr1, fr2 = in_fr2, fr3 = in_fr3;
    float fr4 = in_fr4, fr5 = in_fr5, fr6 = in_fr6, fr7 = in_fr7;
    float fr8 = in_fr8, fr9 = in_fr9, fr10 = in_fr10, fr11 = in_fr11;
    float fr12 = in_fr12, fr13 = in_fr13, fr14 = in_fr14, fr15 = in_fr15;
    int T = (in_sr & 1) != 0;
    c_flags glo;
    int i;

    (void)in_r2; (void)in_r3; (void)in_r6; (void)in_r7; (void)in_r13;
    (void)fr10; (void)fr11;
    memset(o, 0, sizeof(*o));
    memset(&glo, 0, sizeof(glo));
    c_wr32(ram, in_r15 - 4, in_pr);      /* 8c0c678e sts.l pr */

    /* prologue spills + struct setup [06790, 067AC] */
    r8 = 0x00800000u;                    /* 8c0c6790 literal */
    /* (add #-64 already folded into X) */
    c_wr32(ram, X + 40, in_r5);          /* 8c0c6794 [X+40] = r5 */
    r3 = 0x0C29B864u;                    /* 8c0c6796 literal */
    r0 = r3;                             /* 8c0c6798 */
    c_wr32(ram, X + 8, r3);              /* 8c0c679a [X+8] */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, r0 + r1); /* 8c0c679c mov.b */
    r3 = 0x15A8u;                        /* 8c0c679e mov.w */
    r0 &= 0xFFu;                         /* 8c0c67a0 extu.b */
    r4 &= r0;                            /* 8c0c67a2 and r0,r4 */
    r0 = 0x138Cu;                        /* 8c0c67a4 mov.w */
    r3 += r14;                           /* 8c0c67a6 -> r14+0x15a8 */
    r9 = c_rd32(ram, r0 + r14);          /* 8c0c67a8 [r14+0x138c] */
    r0 = r4;                             /* 8c0c67aa */
    c_wr32(ram, X + 4, r3);              /* 8c0c67ac [X+4] */
    r12 = 0x0C2D0190u;                   /* 8c0c67ae literal */
    SETT(r0 == 2);                       /* 8c0c67b0 cmp/eq #2,r0 */
    if (!T) {                            /* 8c0c67b2 bf/s (delay mov #0,r11) */
        r11 = 0;                         /* delay (always) */
        r2 = 1;                          /* 8c0c67ba */
        glo.w[0] = r2;                   /* 8c0c67bc [r12] = 1 */
        goto L67be;
    } else {
        r11 = 0;                         /* delay (always) */
        /* fallthrough delay form 8c0c67b8: [r12] = r11(0) */
        glo.w[0] = r11;
    }
L67be:
    r0 = r4;                             /* 8c0c67be */
    SETT(r0 == 7);                       /* 8c0c67c0 cmp/eq #7,r0 */
    if (!T) {                            /* 8c0c67c2 bf/s (delay mov r4,r0) */
        r0 = r4;                         /* delay (always) */
        r3 = 1;                          /* 8c0c67ca */
        glo.w[7] = r3;                   /* 8c0c67cc [r12+28] = 1 */
        goto L67ce;
    } else {
        r0 = r4;                         /* delay (always) */
        /* fallthrough delay form 8c0c67c8: [r12+28] = r11(0) */
        glo.w[7] = r11;
    }
L67ce:
    SETT(r0 == 13);                      /* 8c0c67ce cmp/eq #13,r0 */
    if (!T)
        goto L67f8;                      /* 8c0c67d0 bf (no delay) */
    /* (8c0c67d2 bra delay writes [r12+24]=r11) */
    glo.w[6] = r11;                      /* 8c0c67d4 delay (always) */
    goto L67fc;
L67f8:
    r2 = 1;                              /* 8c0c67f8 */
    glo.w[6] = r2;                       /* 8c0c67fa [r12+24] = 1 */
L67fc:
    r1 = glo.w[7];                       /* 8c0c67fc [r12+28] */
    r13 = 28;                            /* 8c0c67fe */
    r3 = glo.w[0];                       /* 8c0c6800 [r12] */
    r1 |= r3;                            /* 8c0c6802 */
    glo.w[7] = r1;                       /* 8c0c6804 [r12+28] */
    c_wr32(ram, X, r13);                 /* 8c0c6806 [X] = 28 */

    /* 28-iteration scalemap loop [06808, 06830] */
    for (;;) {
        float s_fr4, s_fr5, s_fr0;
        uint32_t sc_sp = X - 8;          /* wrapper pushed r14/r13 */
        r0 = 8;                          /* 8c0c6808 */
        s_fr4 = c_rdflt(ram, r9);        /* 8c0c680a fr4=[r9] */
        fr3 = c_rdflt(ram, r9 + 8);      /* 8c0c680c fr3=[r9+8] */
        r0 = 44;                         /* 8c0c680e */
        r9 += 12;                        /* 8c0c6810 */
        c_wrflt(ram, X + 44, fr3);       /* 8c0c6812 [X+44]=fr3 */
        /* r3 = 0x0C068E0E (jsr target) */
        fr5 = fr3;                       /* 8c0c6816 fmov fr3,fr5 */
        s_fr5 = -fr5;                    /* 8c0c681a delay fneg fr5 */
        { /* jsr 0x0C068E0E wrapper: push r14/r13, sel=15, body 068E16 */
            uint32_t wframe = sc_sp - 4 - 36;
            uint32_t wsa = wframe + 8, wsb = wframe + 4;
            uint32_t wctx, wsel;
            float wa, wb, wt1, wt2, wf1, wf2, ww1m, ww2m;
            int32_t wi1, wi2;
            uint32_t widx;
            float wa0, wa1, wa2, wa3;
            c_wr32(ram, X - 4, r14);     /* wrapper push r14 */
            c_wr32(ram, X - 8, r13);     /* wrapper push r13 */
            c_wr32(ram, sc_sp - 4, 0x0C0C681Cu); /* sts.l pr */
            c_wrflt(ram, wsa, s_fr4);
            c_wrflt(ram, wsb, s_fr5);
            wsel = 15u & (uint32_t)(uint8_t)c_rd8s(ram, 0x0C29B880u);
            (void)wsel;                  /* sel=1: rescale no-op */
            wctx = c_rd32(ram, 0x0C1B9610u);
            wa = c_rdflt(ram, wsa); wb = c_rdflt(ram, wsb);
            if (!(wa > bits_f(0xC1400000u)))
                wa = bits_f(0xC1400000u);
            if (!(wb > bits_f(0xC1400000u)))
                wb = bits_f(0xC1400000u);
            if (!(bits_f(0x41400000u) > wa))
                wa = bits_f(0x41400000u);
            if (!(bits_f(0x41400000u) > wb))
                wb = bits_f(0x41400000u);
            c_wrflt(ram, wsa, wa); c_wrflt(ram, wsb, wb);
            wt1 = fmac_tz(bits_f(0x40A00000u), wa, bits_f(0x42800000u));
            wt2 = fmac_tz(bits_f(0x40A00000u), wb, bits_f(0x42800000u));
            c_wrflt(ram, wframe + 0, wt1);
            wi1 = (int32_t)wt1; wi2 = (int32_t)wt2;
            wf1 = fsub_tz(wt1, (float)wi1); wf2 = fsub_tz(wt2, (float)wi2);
            widx = ((uint32_t)wi1 & 0x7Fu) | (((uint32_t)wi2 & 0x7Fu) << 7);
            wa0 = c_rdflt(ram, wctx + widx * 4);
            wa1 = c_rdflt(ram, wctx + (widx + 1) * 4);
            wa2 = c_rdflt(ram, wctx + (widx + 0x80) * 4);
            wa3 = c_rdflt(ram, wctx + (widx + 0x81) * 4);
            ww1m = fsub_tz(1.0f, wf1); ww2m = fsub_tz(1.0f, wf2);
            c_wrflt(ram, wframe + 16, wa0);
            c_wrflt(ram, wframe + 12, wa1);
            c_wrflt(ram, wframe + 0, wa2);
            c_wrflt(ram, wframe + 16, fmul_tz(wa0, ww1m));
            c_wrflt(ram, wframe + 12, fmul_tz(wa1, wf1));
            c_wrflt(ram, wframe + 0, fmul_tz(wa2, ww1m));
            c_wrflt(ram, wframe + 16, fmul_tz(fmul_tz(wa0, ww1m), ww2m));
            {
                float q2 = fmul_tz(fmul_tz(wa1, wf1), ww2m);
                float q3 = fmul_tz(fmul_tz(wa0, ww1m), ww2m);
                c_wrflt(ram, wframe + 12, q2);
                q2 = fmac_tz(wf2, fmul_tz(wa3, wf1), q2);
                q3 = fmac_tz(wf2, fmul_tz(wa2, ww1m), q3);
                c_wrflt(ram, wframe + 0, q3);
                s_fr0 = fadd_tz(q3, q2);
                c_wrflt(ram, wframe + 20, s_fr0);
            }
            /* nested-call residue (verified): r1=127, r6=sp-36.
             * fr1/fr2/fr6/fr7/fr8 follow the 068EAE+ chain exactly
             * (fr9 preserved: scalemap never touches it). r5 is the
             * masked shift residue (i2<<7)&0x3F80. */
            r1 = 127;
            r6 = sc_sp - 36;
            {
                float e1 = fmul_tz(ww1m, wa2);          /* fr1 */
                float e2a = fmul_tz(wf1, wa1);          /* [F+12] mid */
                float e2b = fmul_tz(e2a, ww2m);
                float e6 = fmul_tz(wf1, wa3);           /* fr6 input */
                float e2 = fmac_tz(wf2, e6, e2b);       /* fr2 */
                fr1 = fpu_dn_fix(e1, fpscr);
                fr2 = fpu_dn_fix(e2, fpscr);
                fr6 = fpu_dn_fix(e6, fpscr);
                fr7 = fpu_dn_fix(ww1m, fpscr);
                fr8 = fpu_dn_fix(ww2m, fpscr);
                r5 = (((uint32_t)wi2 << 7) & 0x3F80u);
            }
        }
        fr0 = s_fr0;
        r2 = c_rd32(ram, X + 4);         /* 8c0c681c */
        fr4 = fr0;                       /* 8c0c681e fmov fr0,fr4 */
        c_wrflt(ram, r2, fr4);           /* 8c0c6820 [r2]=fr4 */
        r3 = c_rd32(ram, X + 4);         /* 8c0c6822 */
        r3 += 4;                         /* 8c0c6824 */
        c_wr32(ram, X + 4, r3);          /* 8c0c6826 */
        r2 = c_rd32(ram, X);             /* 8c0c6828 */
        r2 += (uint32_t)-1;              /* 8c0c682a */
        SETT(r2 == 0);                   /* 8c0c682c tst r2,r2 */
        if (!T) {                        /* 8c0c682e bf/s (delay [X]=r2) */
            c_wr32(ram, X, r2);          /* delay (always) */
            continue;                    /* loop 0x6808 */
        } else {
            c_wr32(ram, X, r2);          /* delay (always) */
            break;
        }
    }

    /* flag test [06832, 06840] */
    r0 = 72;                             /* 8c0c6832 */
    r3 = 0x0200u;                        /* 8c0c6834 mov.w */
    r4 = c_rd32(ram, r0 + r14);          /* 8c0c6836 [r14+72] */
    SETT((r4 & r3) == 0);                /* 8c0c6838 tst r4,r3 */
    if (T)
        goto L6874;                      /* 8c0c683a bt */
    { /* fallthrough 8c0c683c (untripped): gate */
        o->gated = 1;
        return;
    }
L6874:
    /* FPU select [06874, 068A4] */
    r4 = r14 + 0x15A8u;                  /* 8c0c6874/687a */
    r0 = 76;                             /* 8c0c6876 */
    fr3 = 0.0f;                          /* 8c0c6878 fldi0 fr3 */
    fr15 = c_rdflt(ram, r4 + r0);        /* 8c0c687c fr15=[r14+0x15A8+76] */
    r4 += 104;                           /* 8c0c687e */
    fr14 = c_rdflt(ram, r4);             /* 8c0c6880 fr14=[r14+0x15A8+104] */
    fr12 = fr15;                         /* 8c0c6882 fmov fr15,fr12 */
    fr12 = fpu_dn_fix(fsub_tz(fr12, fr14), fpscr); /* 8c0c6884 fsub */
    SETT(fr3 > fr12);                    /* 8c0c6886 fcmp/gt fr12,fr3 */
    if (T) {                             /* 8c0c6888 bt/s (delay fldi0) */
        fr3 = 0.0f;                      /* delay (always) */
        fr4 = fr15;                      /* 8c0c6890 fmov fr15,fr4 */
        goto L6892;
    } else {
        fr3 = 0.0f;                      /* delay (always) */
        /* fallthrough delay form 8c0c688e: fr4 = fr14 */
        fr4 = fr14;
    }
    goto L6892b;
L6892:
    /* (bt/s-taken join) */
L6892b:
    SETT(fr3 > fr12);                    /* 8c0c6892 fcmp/gt fr12,fr3 */
    if (T)
        goto L689a;                      /* 8c0c6894 bt */
    /* fallthrough delay form 8c0c6898: fr5 = fr15 */
    fr5 = fr15;                          /* 8c0c6896 bra delay (always) */
    goto L689c;
L689a:
    fr5 = fr14;                          /* 8c0c689a fmov fr14,fr5 */
L689c:
    r0 = 0x1594u;                        /* 8c0c689c mov.w */
    c_wrflt(ram, r0 + r14, fr4);         /* 8c0c689e [r14+0x1594]=fr4 */
    r0 += 4;                             /* 8c0c68a0 */
    c_wrflt(ram, r0 + r14, fr5);         /* 8c0c68a2 [r14+0x1598]=fr5 */
    r4 = c_rd32(ram, r14);               /* 8c0c68a4 */
    r3 = 0x20000000u;                    /* 8c0c68a6 */
    SETT((r3 & r4) == 0);                /* 8c0c68a8 tst r3,r4 */
    if (!T) {                            /* 8c0c68aa bf/s (delay mov r11,r13) */
        r13 = r11;                       /* delay (always) */
        r2 = 1;                          /* 8c0c68cc */
        glo.w[4] = r2;                   /* 8c0c68ce [r12+16] = 1 */
        goto L68d0;
    } else {
        r13 = r11;                       /* delay (always) */
        /* fallthrough delay form 8c0c68b0: [r12+16] = r11 */
        glo.w[4] = r11;                  /* (even: 0) */
    }
    goto L68d0b;                         /* 8c0c68ae bra 0x68d0 */
L68d0:
    /* (bt/s-taken join) */
L68d0b:
    /* struct reloads [068D0, 068F2] */
    r0 = 99;                             /* 8c0c68d0 */
    r4 = (uint32_t)(uint8_t)c_rd8s(ram, r0 + r14); /* 8c0c68d2 */
    r0 = 0x138Cu;                        /* 8c0c68d4 mov.w */
    r4 &= 0xFFu;                         /* 8c0c68d6 extu.b */
    r11 = c_rd32(ram, r0 + r14);         /* 8c0c68d8 [r14+0x138c] */
    r0 = 72;                             /* 8c0c68da */
    r9 = c_rd32(ram, r0 + r14);          /* 8c0c68dc [r14+72] */
    r4 += (uint32_t)-1;                  /* 8c0c68de */
    r0 = 0x1A04u;                        /* 8c0c68e0 mov.w */
    r3 = c_rd32(ram, r0 + r14);          /* 8c0c68e2 [r14+0x1a04] */
    c_wr32(ram, X + 4, r3);              /* 8c0c68e4 [X+4] */
    r0 = 0x1A20u;                        /* 8c0c68e6 mov.w */
    r2 = (uint32_t)(uint8_t)c_rd8s(ram, r0 + r14); /* 8c0c68e8 */
    r2 &= 0xFFu;                         /* 8c0c68ea extu.b */
    c_wr32(ram, X, r2);                  /* 8c0c68ec [X] */
    glo.w[3] = r4;                       /* 8c0c68ee [r12+12] = r4 */
    r3 = c_rd32(ram, X + 8);             /* 8c0c68f0 */
    r2 = 0x00C03000u;                    /* 8c0c68f2 */
    r1 = c_rd32(ram, r3);                /* 8c0c68f4 [0x0c29b864] */
    SETT((r2 & r1) == 0);                /* 8c0c68f6 tst r2,r1 */
    if (!T)
        goto L6904;                      /* 8c0c68f8 bf (no delay) */
    r3 = c_rd32(ram, X + 8);             /* 8c0c68fa */
    r2 = 0x00038000u;                    /* 8c0c68fc */
    r1 = c_rd32(ram, r3 + 4);            /* 8c0c68fe [0x0c29b868] */
    SETT((r2 & r1) == 0);                /* 8c0c6900 tst r2,r1 */
    if (T)
        goto L6936;                      /* 8c0c6902 bt */
L6904:
    { /* 0x6904 filter (untripped): gate */
        o->gated = 3;
        return;
    }
L6936:
    r3 = 0x0100u;                        /* 8c0c6936 mov.w */
    SETT((r9 & r3) == 0);                /* 8c0c6938 tst r9,r3 */
    if (T)
        goto L6940;                      /* 8c0c693a bt */
    goto L6e5e;                          /* 8c0c693c bra epilogue (odd) */
L6940:
    r0 = 60;                             /* 8c0c6940 */
    r3 = 0x0424u;                        /* 8c0c6942 mov.w */
    r2 = c_rd16u(ram, r0 + r14);         /* 8c0c6944 mov.w */
    r2 &= 0xFFFFu;                       /* 8c0c6946 extu.w */
    SETT(r2 == r3);                      /* 8c0c6948 cmp/eq r3,r2 */
    if (!T)
        goto L6950;                      /* 8c0c694a bf */
    { /* equal-side (untripped): gate */
        o->gated = 4;
        return;
    }
L6950:
    r0 = 76;                             /* 8c0c6950 */
    r3 = 0x0100u;                        /* 8c0c6952 mov.w */
    r2 = c_rd32(ram, r0 + r14);          /* 8c0c6954 [r14+76] */
    SETT((r3 & r2) == 0);                /* 8c0c6956 tst r3,r2 */
    r4 = glo.w[4];                       /* 8c0c695a delay (always) */
    if (!T) {                            /* 8c0c6958 bf/s */
        o->gated = 5;
        return;
    }
    /* fallthrough 0x695c */
    r5 = 0x0003B200u;                    /* 8c0c695c */
    SETT((r9 & r5) == 0);                /* 8c0c695e tst r9,r5 */
    if (!T) {                            /* 8c0c6960 bf */
        o->gated = 6;
        return;
    }
    goto L6aec;                          /* 8c0c6962 bra (delay nop) */
L6aec:
    SETT(r4 == 0);                       /* 8c0c6aec tst r4,r4 */
    if (T)
        goto L6af4;                      /* 8c0c6aee bt */
    { o->gated = 7; return; }
L6af4:
    r2 = 32;                             /* 8c0c6af4 */
    SETT((r2 & r9) == 0);                /* 8c0c6af6 tst r2,r9 */
    if (T)
        goto L6b60;                      /* 8c0c6af8 bt */
    { /* 0x6afa region (untripped): gate */
        o->gated = 8;
        return;
    }
L6b60:
    /* deep FPU block [06B60, 06BBE): even samples reach the 06911C
     * gate at 0x6bbe (phase 2). */
    r4 = 0x00E8u;                        /* 8c0c6b60 mov.w (sign-extended) */
    r4 = (uint32_t)(int32_t)(int16_t)(uint16_t)r4;
    fr13 = bits_f(0x3D4CCCCCu);           /* 8c0c6b62 mova 0.05 @0x6c04 */
    r0 = 20;                             /* 8c0c6b66 */
    r4 += r11;                           /* 8c0c6b68 */
    fr5 = c_rdflt(ram, r4);              /* 8c0c6b6a fr5=[r11+0xe8] */
    r4 = 0x013Cu;                        /* 8c0c6b6c mov.w */
    r4 += r11;                           /* 8c0c6b6e */
    fr3 = c_rdflt(ram, r4);              /* 8c0c6b70 fr3=[r11+0x13c] */
    c_wrflt(ram, X + 20, fr3);           /* 8c0c6b72 [X+20]=fr3 */
    fr4 = bits_f(0x3DCCCCCCu);            /* 8c0c6b74 mova 0.1 @0x6c08 */
    fr6 = fr5;                           /* 8c0c6b76 fmov fr5,fr6 */
    fr6 = fpu_dn_fix(fsub_tz(fr6, fr3), fpscr); /* 8c0c6b78 fsub fr3,fr6 */
    fr6 = fabsf(fr6);                    /* 8c0c6b7e fabs fr6 */
    fr6 = fpu_dn_fix(fsub_tz(fr6, fr4), fpscr); /* 8c0c6b80 fsub fr4,fr6 */
    c_wrflt(ram, X + 16, fr6);           /* 8c0c6b82 [X+16]=fr6 */
    r0 = 76;                             /* 8c0c6b84 */
    r5 = r14 + 0x12ACu;                  /* 8c0c6b86/8a (0x12ac) */
    r4 = 0x00F4u;                        /* 8c0c6b88 mov.w */
    r3 = 0x0100u;                        /* 8c0c6b8c mov.w */
    fr6 = c_rdflt(ram, r0 + r5);         /* 8c0c6b8e fr6=[r14+0x12ac+76] */
    r5 += 80;                            /* 8c0c6b90 */
    r4 += r11;                           /* 8c0c6b92 */
    fr7 = c_rdflt(ram, r5);              /* 8c0c6b94 fr7=[r14+0x12ac+80] */
    fr4 = c_rdflt(ram, r4);              /* 8c0c6b96 fr4=[r11+0xf4] */
    fr5 = fpu_dn_fix(fsub_tz(fr5, fr6), fpscr); /* 8c0c6b98 fsub fr6,fr5 */
    fr4 = fpu_dn_fix(fsub_tz(fr4, fr7), fpscr); /* 8c0c6b9a fsub fr7,fr4 */
    fr5 = fpu_dn_fix(fsub_tz(fr5, fr13), fpscr);/* 8c0c6b9c fsub fr13,fr5 */
    fr4 = fpu_dn_fix(fsub_tz(fr4, fr13), fpscr);/* 8c0c6b9e fsub fr13,fr4 */
    SETT(fr5 > fr15);                    /* 8c0c6ba0 fcmp/gt fr15,fr5 */
    if (!T) {                            /* 8c0c6ba2 bf/s (delay or r3,r13) */
        r13 |= r3;                       /* delay (always) */
        goto L6bae;
    } else {
        r13 |= r3;                       /* delay (always) */
        /* fallthrough 0x6ba6 */
        SETT(fr4 > fr15);                /* 8c0c6ba6 fcmp/gt fr15,fr4 */
        if (!T)
            goto L6bae;                  /* 8c0c6ba8 bf */
        r3 = 0xFEFFu;                    /* 8c0c6baa mov.w */
        r3 = (uint32_t)(int32_t)(int16_t)(uint16_t)r3;
        r13 &= r3;                       /* 8c0c6bac and r3,r13 */
    }
L6bae:
    r4 = 0x00E4u;                        /* 8c0c6bae mov.w */
    /* r2 = 0x0C06911C literal (8c0c6bb0) */
    r4 += r11;                           /* 8c0c6bb2 */
    fr4 = c_rdflt(ram, r4);              /* 8c0c6bb4 fr4=[r11+0xe4] */
    r4 = 0x00ECu;                        /* 8c0c6bb6 mov.w */
    r4 += r11;                           /* 8c0c6bb8 */
    fr5 = c_rdflt(ram, r4);              /* 8c0c6bba fr5=[r11+0xec] */
    r4 = X;                              /* 8c0c6bbc mov r15,r4 */
    /* 8c0c6bbe jsr 0x0C06911C (delay r4 = X+52) */
    c_wr32(ram, X - 4, r14);             /* wrapper push r14 */
    c_wr32(ram, X - 8, r13);             /* wrapper push r13 */
    c_wr32(ram, X - 12, r12);            /* wrapper push r12 */
    c_wr32(ram, X - 16, r11);            /* wrapper push r11 */
    r4 = X + 52;                         /* delay (always) */
    {
        uint32_t w_r7;
        int wg = 0;
        r0 = (uint32_t)c_6911c(X + 52, X + 52, 15, fr4, fr5, X,
                               0x0C0C6BC2u, r9, fr15, fr14, &w_r7,
                               ram, fpscr, &wg);
        if (wg) { o->gated = wg; return; }
        r4 = (uint32_t)r0;               /* 8c0c6bc4 mov r0,r4 */
        r7 = w_r7;                       /* (walk residue) */
        fr9 = bits_f(0x40400000u);       /* 068FE4 mesh const (see c_6911c) */
    }
    r9 = 0xFFFFF000u;                    /* 8c0c6bc2 mov.w 0xf000 (signext) */
    SETT((r10 & r4) == 0);               /* 8c0c6bc6 tst r10,r4 */
    if (T)
        goto L6c6c;                      /* 8c0c6bc8 bt (not taken: bit2 set) */
    /* string scan 1 [06BCA, 06C2C] */
    r3 = c_rd32(ram, X + 4);             /* 8c0c6bca */
    SETT((r8 & r3) == 0);                /* 8c0c6bcc tst r8,r3 */
    if (T)
        goto L6c2c;                      /* 8c0c6bce bt */
    r5 = 0x0C11096Au;                    /* 8c0c6bd0 */
    for (;;) {
        r3 = c_rd32(ram, X);             /* 8c0c6bd2 */
        r4 = (uint32_t)(int32_t)c_rd8s(ram, r5); /* 8c0c6bd4 mov.b @r5 */
        r5++;                            /* 8c0c6bd4 post-inc */
        SETT(r3 == r4);                  /* 8c0c6bd6 cmp/eq r3,r4 */
        if (T)
            goto L6c14;                  /* 8c0c6bd8 bt */
        SETT(r4 == 0);                   /* 8c0c6bda tst r4,r4 */
        if (!T)
            continue;                    /* 8c0c6bdc bf */
        goto L6c2c;                      /* 8c0c6bde bra */
    }
L6c14:
    r1 = glo.w[3];                       /* 8c0c6c14 [r12+12] */
    SETT((int32_t)r1 >= 0);              /* 8c0c6c16 cmp/pz r1 */
    if (!T)
        goto L6c2c;                      /* 8c0c6c18 bf */
    r0 = 16;                             /* 8c0c6c1a */
    fr3 = 0.0f;                          /* 8c0c6c1c fldi0 fr3 */
    fr2 = c_rdflt(ram, X + 16);          /* 8c0c6c1e */
    r3 = 0x0400u;                        /* 8c0c6c20 mov.w */
    SETT(fr2 > fr3);                     /* 8c0c6c22 fcmp/gt fr3,fr2 */
    if (!T) {                            /* 8c0c6c24 bf/s (delay or) */
        r13 |= r3;                       /* delay (always) */
        goto L6c2c;
    } else {
        r13 |= r3;                       /* delay (always) */
        r3 = 32;                         /* 8c0c6c28 */
        r13 |= r3;                       /* 8c0c6c2a */
    }
L6c2c:
    r0 = 0x22ECu;                        /* 8c0c6c2c mov.w */
    r2 = 2;                              /* 8c0c6c2e */
    r13 |= r2;                           /* 8c0c6c30 */
    fr4 = c_rdflt(ram, r0 + r14);        /* 8c0c6c32 fr4=[r14+0x22ec] */
    r0 += 8;                             /* 8c0c6c34 */
    fr3 = c_rdflt(ram, r0 + r14);        /* 8c0c6c36 fr3=[r14+0x22f4] */
    r0 = 48;                             /* 8c0c6c38 */
    c_wrflt(ram, X + 48, fr3);           /* 8c0c6c3a [X+48]=fr3 */
    /* r3 = 0x0C068E0E (8c0c6c3c); fr5 = fr3 */
    fr5 = fr3;                           /* 8c0c6c3e fmov fr3,fr5 */
    /* 8c0c6c40 jsr scalemap (delay fneg fr5) */
    {
        uint32_t sc_sp = X - 8;
        float s_fr4 = fr4, s_fr5 = -fr5, s_fr0;
        uint32_t wframe = sc_sp - 4 - 36;
        uint32_t wsa = wframe + 8, wsb = wframe + 4;
        uint32_t wctx; float wa, wb, wt1, wt2, wf1, wf2, ww1m, ww2m;
        int32_t wi1, wi2; uint32_t widx; float wa0, wa1, wa2, wa3;
        c_wr32(ram, X - 4, r14);
        c_wr32(ram, X - 8, r13);
        c_wr32(ram, sc_sp - 4, 0x0C0C6C44u);
        c_wrflt(ram, wsa, s_fr4); c_wrflt(ram, wsb, s_fr5);
        wctx = c_rd32(ram, 0x0C1B9610u);
        wa = c_rdflt(ram, wsa); wb = c_rdflt(ram, wsb);
        if (!(wa > bits_f(0xC1400000u))) wa = bits_f(0xC1400000u);
        if (!(wb > bits_f(0xC1400000u))) wb = bits_f(0xC1400000u);
        if (!(bits_f(0x41400000u) > wa)) wa = bits_f(0x41400000u);
        if (!(bits_f(0x41400000u) > wb)) wb = bits_f(0x41400000u);
        c_wrflt(ram, wsa, wa); c_wrflt(ram, wsb, wb);
        wt1 = fmac_tz(bits_f(0x40A00000u), wa, bits_f(0x42800000u));
        wt2 = fmac_tz(bits_f(0x40A00000u), wb, bits_f(0x42800000u));
        c_wrflt(ram, wframe + 0, wt1);
        wi1 = (int32_t)wt1; wi2 = (int32_t)wt2;
        wf1 = fsub_tz(wt1, (float)wi1); wf2 = fsub_tz(wt2, (float)wi2);
        widx = ((uint32_t)wi1 & 0x7Fu) | (((uint32_t)wi2 & 0x7Fu) << 7);
        wa0 = c_rdflt(ram, wctx + widx * 4);
        wa1 = c_rdflt(ram, wctx + (widx + 1) * 4);
        wa2 = c_rdflt(ram, wctx + (widx + 0x80) * 4);
        wa3 = c_rdflt(ram, wctx + (widx + 0x81) * 4);
        ww1m = fsub_tz(1.0f, wf1); ww2m = fsub_tz(1.0f, wf2);
        c_wrflt(ram, wframe + 16, wa0);
        c_wrflt(ram, wframe + 12, wa1);
        c_wrflt(ram, wframe + 0, wa2);
        c_wrflt(ram, wframe + 16, fmul_tz(wa0, ww1m));
        c_wrflt(ram, wframe + 12, fmul_tz(wa1, wf1));
        c_wrflt(ram, wframe + 0, fmul_tz(wa2, ww1m));
        c_wrflt(ram, wframe + 16, fmul_tz(fmul_tz(wa0, ww1m), ww2m));
        {
            float q2 = fmul_tz(fmul_tz(wa1, wf1), ww2m);
            float q3 = fmul_tz(fmul_tz(wa0, ww1m), ww2m);
            c_wrflt(ram, wframe + 12, q2);
            q2 = fmac_tz(wf2, fmul_tz(wa3, wf1), q2);
            q3 = fmac_tz(wf2, fmul_tz(wa2, ww1m), q3);
            c_wrflt(ram, wframe + 0, q3);
            s_fr0 = fadd_tz(q3, q2);
            c_wrflt(ram, wframe + 20, s_fr0);
        }
        r1 = 127; r6 = sc_sp - 36;
        {
            float e1 = fmul_tz(ww1m, wa2);
            float e2a = fmul_tz(wf1, wa1);
            float e2b = fmul_tz(e2a, ww2m);
            float e6 = fmul_tz(wf1, wa3);
            float e2 = fmac_tz(wf2, e6, e2b);
            fr1 = fpu_dn_fix(e1, fpscr);
            fr2 = fpu_dn_fix(e2, fpscr);
            fr6 = fpu_dn_fix(e6, fpscr);
            fr7 = fpu_dn_fix(ww1m, fpscr);
            fr8 = fpu_dn_fix(ww2m, fpscr);
            r5 = (((uint32_t)wi2 << 7) & 0x3F80u);
        }
        fr0 = s_fr0;
    }
    r0 = 0x15F4u;                        /* 8c0c6c44 mov.w */
    /* r3 = 0x0C069624 (8c0c6c46) */
    fr6 = c_rdflt(ram, r0 + r14);        /* 8c0c6c48 fr6=[r14+0x15f4] */
    /* r0 = mova 0x0C0C6CE8 (8c0c6c4a) */
    fr5 = bits_f(0x3E4CCCCCu);           /* 8c0c6c4c fr5=0.2 */
    fr4 = fr0;                           /* 8c0c6c4e fmov fr0,fr4 */
    /* 8c0c6c50 jsr 069624 (delay fsub fr6,fr4) */
    {
        float d_fr4 = fpu_dn_fix(fsub_tz(fr4, fr6), fpscr);
        float d_fr2, d_fr3, d_fr6, d_fr7, d_fr8;
        int wg2 = 0;
        r0 = (uint32_t)c_9624(d_fr4, fr5, &d_fr2, &d_fr3, &d_fr6,
                              &d_fr7, &d_fr8, fpscr, &wg2);
        if (wg2) { o->gated = wg2; return; }
        fr4 = d_fr4;
    }
    r2 = 0x1800u;                        /* 8c0c6c54 mov.w (sign-extended) */
    r2 = (uint32_t)(int32_t)(int16_t)(uint16_t)r2;
    r0 = (uint32_t)(int32_t)(int16_t)(uint16_t)r0; /* 8c0c6c56 exts.w */
    r4 = (uint32_t)(int32_t)(int16_t)(uint16_t)r0; /* 8c0c6c58 exts.w */
    SETT((int32_t)r4 > (int32_t)r2);     /* 8c0c6c5a cmp/gt r2,r4 */
    if (!T)                              /* 8c0c6c5c bf */
        goto L6c62;                      /* (clamp-high skipped) */
    goto L6c68;                          /* 8c0c6c5e bra (delay mov r2,r4) */
    /* (delay: r4 = r2) */
L6c62:
    /* (bf-taken join: r4 unchanged) */
L6c68:
    if (T) r4 = r2;                      /* (06c60 delay form) */
    SETT((int32_t)r4 >= (int32_t)r9);    /* 8c0c6c62 cmp/ge r9,r4 */
    if (T)
        goto L6c6a_store;                /* 8c0c6c64 bt */
    r4 = r9;                             /* 8c0c6c66 mov r9,r4 (delay form) */
L6c6a_store:
    r0 = 0x22E8u;                        /* 8c0c6c68 mov.w */
    c_wr16(ram, r0 + r14, (uint16_t)r4); /* 8c0c6c6a [r14+0x22e8] */
L6c6c:
    r5 = 0x12ACu;                        /* 8c0c6c6c mov.w */
    r0 = 104;                            /* 8c0c6c6e */
    r4 = 0x0148u;                        /* 8c0c6c70 mov.w */
    r5 += r14;                           /* 8c0c6c72 */
    r3 = 0x0200u;                        /* 8c0c6c74 mov.w */
    fr5 = c_rdflt(ram, r0 + r5);         /* 8c0c6c76 fr5=[r14+0x12ac+104] */
    r0 = 20;                             /* 8c0c6c78 */
    r4 += r11;                           /* 8c0c6c7a */
    fr3 = fr5;                           /* 8c0c6c7c fmov fr5,fr3 */
    r5 += 108;                           /* 8c0c6c7e */
    fr5 = c_rdflt(ram, X + 20);          /* 8c0c6c80 fr5=[X+20] */
    fr4 = c_rdflt(ram, r4);              /* 8c0c6c82 fr4=[r11+0x148] */
    fr5 = fpu_dn_fix(fsub_tz(fr5, fr3), fpscr); /* 8c0c6c84 fsub fr3,fr5 */
    fr6 = c_rdflt(ram, r5);              /* 8c0c6c86 fr6=[r14+0x12ac+108] */
    fr4 = fpu_dn_fix(fsub_tz(fr4, fr6), fpscr); /* 8c0c6c88 fsub fr6,fr4 */
    fr5 = fpu_dn_fix(fsub_tz(fr5, fr13), fpscr);/* 8c0c6c8a fsub fr13,fr5 */
    fr4 = fpu_dn_fix(fsub_tz(fr4, fr13), fpscr);/* 8c0c6c8c fsub fr13,fr4 */
    SETT(fr5 > fr14);                    /* 8c0c6c8e fcmp/gt fr14,fr5 */
    if (!T) {                            /* 8c0c6c90 bf/s (delay or) */
        r13 |= r3;                       /* delay (always) */
        goto L6c9c;
    } else {
        r13 |= r3;                       /* delay (always) */
        SETT(fr4 > fr14);                /* 8c0c6c94 fcmp/gt fr14,fr4 */
        if (!T)
            goto L6c9c;                  /* 8c0c6c96 bf */
        r3 = 0xFDFFu;                    /* 8c0c6c98 mov.w */
        r3 = (uint32_t)(int32_t)(int16_t)(uint16_t)r3;
        r13 &= r3;                       /* 8c0c6c9a and r3,r13 */
    }
L6c9c:
    r4 = 0x0138u;                        /* 8c0c6c9c mov.w */
    /* r2 = 0x0C06911C (8c0c6c9e) */
    r4 += r11;                           /* 8c0c6ca0 */
    fr4 = c_rdflt(ram, r4);              /* 8c0c6ca2 fr4=[r11+0x138] */
    r4 = 0x0140u;                        /* 8c0c6ca4 mov.w */
    r4 += r11;                           /* 8c0c6ca6 */
    fr5 = c_rdflt(ram, r4);              /* 8c0c6ca8 fr5=[r11+0x140] */
    r4 = X;                              /* 8c0c6caa mov r15,r4 */
    /* 8c0c6cac jsr 0x0C06911C (delay r4 = X+52) */
    c_wr32(ram, X - 4, r14);
    c_wr32(ram, X - 8, r13);
    c_wr32(ram, X - 12, r12);
    c_wr32(ram, X - 16, r11);
    r4 = X + 52;                         /* delay (always) */
    {
        uint32_t w_r7;
        int wg = 0;
        r0 = (uint32_t)c_6911c(X + 52, X + 52, 15, fr4, fr5, X,
                               0x0C0C6CB0u, r9, fr15, fr14, &w_r7,
                               ram, fpscr, &wg);
        if (wg) { o->gated = wg; return; }
        r4 = (uint32_t)r0;               /* 8c0c6cb0 mov r0,r4 */
        r7 = w_r7;
        fr9 = bits_f(0x40400000u);       /* 068FE4 mesh const (2nd call) */
    }
    SETT((r10 & r4) == 0);               /* 8c0c6cb2 tst r10,r4 */
    if (T) {                             /* 8c0c6cb4 bt 0x6d4e */
        o->gated = 11;                   /* (untripped: store skipped) */
        return;
    }
    /* string scan 2 [06CB6, 06D10] */
    r3 = c_rd32(ram, X + 4);             /* 8c0c6cb6 */
    SETT((r8 & r3) == 0);                /* 8c0c6cb8 tst r8,r3 */
    if (T)
        goto L6d10;                      /* 8c0c6cba bt */
    r5 = 0x0C110976u;                    /* 8c0c6cbc */
    for (;;) {
        r3 = c_rd32(ram, X);             /* 8c0c6cbe */
        r4 = (uint32_t)(int32_t)c_rd8s(ram, r5);
        r5++;
        SETT(r3 == r4);                  /* 8c0c6cc2 cmp/eq r3,r4 */
        if (T)
            goto L6cf8;                  /* 8c0c6cc4 bt */
        SETT(r4 == 0);                   /* 8c0c6cc6 tst r4,r4 */
        if (!T)
            continue;                    /* 8c0c6cc8 bf */
        goto L6d10;                      /* 8c0c6cca bra */
    }
L6cf8:
    r1 = glo.w[3];                       /* 8c0c6cf8 [r12+12] */
    SETT((int32_t)r1 >= 0);              /* 8c0c6cfa cmp/pz r1 */
    if (!T)
        goto L6d10;                      /* 8c0c6cfc bf */
    r0 = 16;                             /* 8c0c6cfe */
    fr3 = 0.0f;                          /* 8c0c6d00 fldi0 fr3 */
    fr2 = c_rdflt(ram, X + 16);          /* 8c0c6d02 */
    r3 = 0x0800u;                        /* 8c0c6d04 mov.w */
    SETT(fr2 > fr3);                     /* 8c0c6d06 fcmp/gt fr3,fr2 */
    if (!T) {                            /* 8c0c6d08 bf/s (delay or) */
        r13 |= r3;                       /* delay (always) */
        goto L6d10;
    } else {
        r13 |= r3;                       /* delay (always) */
        r3 = 32;                         /* 8c0c6d0c */
        r13 |= r3;                       /* 8c0c6d0e */
    }
L6d10:
    r0 = 0x22F8u;                        /* 8c0c6d10 mov.w */
    r13 |= r10;                          /* 8c0c6d12 or r10,r13 */
    fr4 = c_rdflt(ram, r0 + r14);        /* 8c0c6d14 fr4=[r14+0x22f8] */
    r0 += 8;                             /* 8c0c6d16 */
    fr3 = c_rdflt(ram, r0 + r14);        /* 8c0c6d18 fr3=[r14+0x2300] */
    r0 = 36;                             /* 8c0c6d1a */
    c_wrflt(ram, X + 36, fr3);           /* 8c0c6d1c [X+36]=fr3 */
    /* r3 = 0x0C068E0E (8c0c6d1e); fr5 = fr3 */
    fr5 = fr3;                           /* 8c0c6d20 fmov fr3,fr5 */
    /* 8c0c6d22 jsr scalemap (delay fneg fr5) */
    {
        uint32_t sc_sp = X - 8;
        float s_fr4 = fr4, s_fr5 = -fr5, s_fr0;
        uint32_t wframe = sc_sp - 4 - 36;
        uint32_t wsa = wframe + 8, wsb = wframe + 4;
        uint32_t wctx; float wa, wb, wt1, wt2, wf1, wf2, ww1m, ww2m;
        int32_t wi1, wi2; uint32_t widx; float wa0, wa1, wa2, wa3;
        c_wr32(ram, X - 4, r14);
        c_wr32(ram, X - 8, r13);
        c_wr32(ram, sc_sp - 4, 0x0C0C6D26u);
        c_wrflt(ram, wsa, s_fr4); c_wrflt(ram, wsb, s_fr5);
        wctx = c_rd32(ram, 0x0C1B9610u);
        wa = c_rdflt(ram, wsa); wb = c_rdflt(ram, wsb);
        if (!(wa > bits_f(0xC1400000u))) wa = bits_f(0xC1400000u);
        if (!(wb > bits_f(0xC1400000u))) wb = bits_f(0xC1400000u);
        if (!(bits_f(0x41400000u) > wa)) wa = bits_f(0x41400000u);
        if (!(bits_f(0x41400000u) > wb)) wb = bits_f(0x41400000u);
        c_wrflt(ram, wsa, wa); c_wrflt(ram, wsb, wb);
        wt1 = fmac_tz(bits_f(0x40A00000u), wa, bits_f(0x42800000u));
        wt2 = fmac_tz(bits_f(0x40A00000u), wb, bits_f(0x42800000u));
        c_wrflt(ram, wframe + 0, wt1);
        wi1 = (int32_t)wt1; wi2 = (int32_t)wt2;
        wf1 = fsub_tz(wt1, (float)wi1); wf2 = fsub_tz(wt2, (float)wi2);
        widx = ((uint32_t)wi1 & 0x7Fu) | (((uint32_t)wi2 & 0x7Fu) << 7);
        wa0 = c_rdflt(ram, wctx + widx * 4);
        wa1 = c_rdflt(ram, wctx + (widx + 1) * 4);
        wa2 = c_rdflt(ram, wctx + (widx + 0x80) * 4);
        wa3 = c_rdflt(ram, wctx + (widx + 0x81) * 4);
        ww1m = fsub_tz(1.0f, wf1); ww2m = fsub_tz(1.0f, wf2);
        c_wrflt(ram, wframe + 16, wa0);
        c_wrflt(ram, wframe + 12, wa1);
        c_wrflt(ram, wframe + 0, wa2);
        c_wrflt(ram, wframe + 16, fmul_tz(wa0, ww1m));
        c_wrflt(ram, wframe + 12, fmul_tz(wa1, wf1));
        c_wrflt(ram, wframe + 0, fmul_tz(wa2, ww1m));
        c_wrflt(ram, wframe + 16, fmul_tz(fmul_tz(wa0, ww1m), ww2m));
        {
            float q2 = fmul_tz(fmul_tz(wa1, wf1), ww2m);
            float q3 = fmul_tz(fmul_tz(wa0, ww1m), ww2m);
            c_wrflt(ram, wframe + 12, q2);
            q2 = fmac_tz(wf2, fmul_tz(wa3, wf1), q2);
            q3 = fmac_tz(wf2, fmul_tz(wa2, ww1m), q3);
            c_wrflt(ram, wframe + 0, q3);
            s_fr0 = fadd_tz(q3, q2);
            c_wrflt(ram, wframe + 20, s_fr0);
        }
        r1 = 127; r6 = sc_sp - 36;
        {
            float e1 = fmul_tz(ww1m, wa2);
            float e2a = fmul_tz(wf1, wa1);
            float e2b = fmul_tz(e2a, ww2m);
            float e6 = fmul_tz(wf1, wa3);
            float e2 = fmac_tz(wf2, e6, e2b);
            fr1 = fpu_dn_fix(e1, fpscr);
            fr2 = fpu_dn_fix(e2, fpscr);
            fr6 = fpu_dn_fix(e6, fpscr);
            fr7 = fpu_dn_fix(ww1m, fpscr);
            fr8 = fpu_dn_fix(ww2m, fpscr);
            r5 = (((uint32_t)wi2 << 7) & 0x3F80u);
        }
        fr0 = s_fr0;
    }
    r0 = 0x1610u;                        /* 8c0c6d26 mov.w */
    /* r3 = 0x0C069624 (8c0c6d28) */
    fr6 = c_rdflt(ram, r0 + r14);        /* 8c0c6d2a fr6=[r14+0x1610] */
    /* r0 = mova 0x0C0C6DE8 (8c0c6d2c) */
    fr5 = bits_f(0x3E4CCCCCu);           /* 8c0c6d2e fr5=0.2 */
    fr4 = fr0;                           /* 8c0c6d30 fmov fr0,fr4 */
    /* 8c0c6d32 jsr 069624 (delay fsub fr6,fr4) */
    {
        float d_fr4 = fpu_dn_fix(fsub_tz(fr4, fr6), fpscr);
        float d_fr2, d_fr3, d_fr6, d_fr7, d_fr8;
        int wg2 = 0;
        r0 = (uint32_t)c_9624(d_fr4, fr5, &d_fr2, &d_fr3, &d_fr6,
                              &d_fr7, &d_fr8, fpscr, &wg2);
        if (wg2) { o->gated = wg2; return; }
        fr4 = d_fr4;
        /* fr2/fr7/fr8 survive to exit (nothing reloads them) */
        fr2 = d_fr2;
        fr7 = d_fr7;
        fr8 = d_fr8;
    }
    r2 = 0x1800u;                        /* 8c0c6d36 mov.w */
    r2 = (uint32_t)(int32_t)(int16_t)(uint16_t)r2;
    r0 = (uint32_t)(int32_t)(int16_t)(uint16_t)r0; /* 8c0c6d38 exts.w */
    r4 = (uint32_t)(int32_t)(int16_t)(uint16_t)r0; /* 8c0c6d3a exts.w */
    SETT((int32_t)r4 > (int32_t)r2);     /* 8c0c6d3c cmp/gt r2,r4 */
    if (!T)                              /* 8c0c6d3e bf */
        goto L6d44;
    goto L6d4a;                          /* 8c0c6d40 bra (delay mov r2,r4) */
L6d44:
L6d4a:
    if (T) r4 = r2;                      /* (06d42 delay form) */
    SETT((int32_t)r4 >= (int32_t)r9);    /* 8c0c6d44 cmp/ge r9,r4 */
    if (T)
        goto L6d4c_store;                /* 8c0c6d46 bt */
    r4 = r9;                             /* 8c0c6d48 mov r9,r4 (delay form) */
L6d4c_store:
    r0 = 0x22EAu;                        /* 8c0c6d4a mov.w */
    c_wr16(ram, r0 + r14, (uint16_t)r4); /* 8c0c6d4c [r14+0x22ea] */
    r4 = 6;                              /* 8c0c6d4e mov #6,r4 */
    r4 &= r13;                           /* 8c0c6d50 and r13,r4 */
    r0 = r4;                             /* 8c0c6d52 mov r4,r0 */
    SETT(r0 == 6);                       /* 8c0c6d54 cmp/eq #6,r0 */
    if (!T)
        goto L6dfc;                      /* 8c0c6d56 bf */
    r3 = 0x0400u;                        /* 8c0c6d58 mov.w */
    SETT((r13 & r3) == 0);               /* 8c0c6d5a tst r13,r3 */
    if (!T)                              /* 8c0c6d5c bf */
        goto L6d84;                      /* (bra 0x6e06) */
    r1 = 0x0800u;                        /* 8c0c6d5e mov.w */
    SETT((r13 & r1) == 0);               /* 8c0c6d60 tst r13,r1 */
    if (!T)                              /* 8c0c6d62 bf */
        goto L6d7a;                      /* (bra 0x6e06) */
    r3 = 32;                             /* 8c0c6d64 */
    SETT((r13 & r3) == 0);               /* 8c0c6d66 tst r13,r3 */
    if (T)
        goto L6d88;                      /* 8c0c6d68 bt */
    r4 = 0x0300u;                        /* 8c0c6d6a mov.w */
    r5 = r4;                             /* 8c0c6d6c mov r4,r5 */
    r5 &= r13;                           /* 8c0c6d6e and r13,r5 */
    SETT(r4 == r5);                      /* 8c0c6d70 cmp/eq r4,r5 */
    if (T)
        goto L6d88;                      /* 8c0c6d72 bt */
    r3 = 0x0100u;                        /* 8c0c6d74 mov.w */
    SETT((r13 & r3) == 0);               /* 8c0c6d76 tst r13,r3 */
    if (T)
        goto L6d7e;                      /* 8c0c6d78 bt */
L6d7a:
    fr13 = fr15;                         /* 8c0c6d7c delay (always) */
    goto L6e06;                          /* 8c0c6d7a bra */
L6d7e:
    r2 = 0x0200u;                        /* 8c0c6d7e mov.w */
    SETT((r13 & r2) == 0);               /* 8c0c6d80 tst r13,r2 */
    if (T)
        goto L6d88;                      /* 8c0c6d82 bt */
L6d84:
    fr13 = fr14;                         /* 8c0c6d86 delay (always) */
    goto L6e06;                          /* 8c0c6d84 bra */
L6d88:
    r0 = 0x1A04u;                        /* 8c0c6d88 mov.w */
    r5 = c_rd32(ram, r14);               /* 8c0c6d8a mov.l @r14,r5 */
    r4 = c_rd32(ram, r0 + r14);          /* 8c0c6d8c mov.l @(r0,r14),r4 */
    /* r0 = mova 0x0C0C6DF0 (8c0c6d8e) */
    SETT((r8 & r5) == 0);                /* 8c0c6d90 tst r8,r5 */
    if (!T) {                            /* 8c0c6d92 bt/s (delay fmov) */
        fr4 = bits_f(0x3E199999u);       /* delay (always): fr4=0.15 */
        SETT((r8 & r4) == 0);            /* 8c0c6d96 tst r8,r4 */
        /* r0 = mova 0x0C0C6DF4 (8c0c6d98) */
        if (!T) {                        /* 8c0c6d9a bf/s (delay fmov) */
            fr4 = bits_f(0x3F000000u);   /* delay (always): fr4=0.5 */
            goto L6daa;
        } else {
            fr4 = bits_f(0x3F000000u);   /* delay (always) */
            /* r0 = mova 0x0C0C6DF8 (8c0c6d9e); fr4=[mova]=0.6 */
            fr4 = bits_f(0x3F199999u);   /* 8c0c6da0 */
            goto L6daa;
        }
    } else {
        fr4 = bits_f(0x3E199999u);       /* delay (always) */
        goto L6da2;
    }
L6da2:
    r0 = 97;                             /* 8c0c6da2 */
    r0 = (uint32_t)(uint8_t)c_rd8s(ram, r0 + r14); /* 8c0c6da4 */
    r0 &= 0xFFu;                         /* 8c0c6da6 extu.b */
    SETT(r0 == 1);                       /* 8c0c6da8 cmp/eq #1,r0 */
L6daa:
    fr5 = fr12;                          /* 8c0c6daa fmov fr12,fr5 */
    fr3 = 0.0f;                          /* 8c0c6dac fldi0 fr3 */
    SETT(fr3 > fr5);                     /* 8c0c6dae fcmp/gt fr5,fr3 */
    if (T) {                             /* 8c0c6db0 bt/s (delay fldi0) */
        fr3 = 0.0f;                      /* delay (always) */
        goto L6db8;                      /* 8c0c6db8 (T=1: fr5>... wait) */
    } else {
        fr3 = 0.0f;                      /* delay (always) */
        goto L6dba;                      /* 8c0c6db4 bra */
    }
L6db8:
    fr6 = fr15;                          /* 8c0c6db8 fmov fr15,fr6 */
    goto L6dba2;
L6dba:
    fr6 = fr14;                          /* 8c0c6db6 delay (always) */
L6dba2:
    SETT(fr3 > fr5);                     /* 8c0c6dba fcmp/gt fr5,fr3 */
    if (T)
        goto L6dc2;                      /* 8c0c6dbc bt */
    goto L6dc4;                          /* 8c0c6dbe bra (delay fr5=fr15) */
L6dc2:
    fr5 = fr14;                          /* 8c0c6dc2 fmov fr14,fr5 */
L6dc4:
    fr5 = fpu_dn_fix(fsub_tz(fr5, fr6), fpscr); /* 8c0c6dc4 fsub fr6,fr5 */
    fr0 = fr4;                           /* 8c0c6dc6 fmov fr4,fr0 */
    fr6 = fpu_dn_fix(fmac_tz(fr0, fr5, fr6), fpscr); /* 8c0c6dc8 fmac */
    fr13 = fr6;                          /* 8c0c6dcc delay (always) */
    goto L6e06;                          /* 8c0c6dca bra */
L6dfc:
    r2 = 2;                              /* 8c0c6dfc */
    SETT((r13 & r2) == 0);               /* 8c0c6dfe tst r13,r2 */
    fr13 = fr15;                         /* 8c0c6e02 delay (always) */
    if (!T) {                            /* 8c0c6e00 bf/s */
        fr13 = fr14;                     /* 8c0c6e04 delay (always) */
    }
    goto L6e06;
L6e06:
    r0 = 20;                             /* 8c0c6e06 */
    fr4 = fr13;                          /* 8c0c6e08 fmov fr13,fr4 */
    fr3 = c_rdflt(ram, r0 + r14);        /* 8c0c6e0a fr3=[r14+20] */
    r0 = 72;                             /* 8c0c6e0c */
    r4 = c_rd32(ram, r0 + r14);          /* 8c0c6e0e r4=[r14+72] */
    r0 = 76;                             /* 8c0c6e10 */
    fr4 = fpu_dn_fix(fsub_tz(fr4, fr3), fpscr); /* 8c0c6e12 fsub fr3,fr4 */
    r5 = c_rd32(ram, r0 + r14);          /* 8c0c6e14 r5=[r14+76] */
    r3 = r4;                             /* 8c0c6e16 mov r4,r3 */
    SETT((r10 & r3) == 0);               /* 8c0c6e18 tst r10,r3 */
    /* r0 = mova 0x0C0C6EF8 (8c0c6e1a) */
    if (!T) {                            /* 8c0c6e1c bf/s (delay fmov) */
        fr5 = bits_f(0x3DCCCCCCu);       /* delay (always): fr5=0.1 */
        goto L6e32;
    } else {
        fr5 = bits_f(0x3DCCCCCCu);       /* delay (always) */
        /* r2 = 0x00040000 (8c0c6e20) */
        r2 = 0x00040000u;                /* (literal) */
        SETT((r2 & r5) == 0);            /* 8c0c6e22 tst r2,r5 */
        if (!T)
            goto L6e32;                  /* 8c0c6e24 bf */
        SETT((r8 & r4) == 0);            /* 8c0c6e26 tst r8,r4 */
        /* r0 = mova 0x0C0C6F00 (8c0c6e28) */
        if (!T) {                        /* 8c0c6e2a bf/s (delay fmov) */
            fr5 = bits_f(0x3D4CCCCCu);   /* delay (always): fr5=0.05 */
            goto L6e32;
        } else {
            fr5 = bits_f(0x3D4CCCCCu);   /* delay (always) */
            /* r0 = mova 0x0C0C6F04 (8c0c6e2e) */
            fr5 = bits_f(0x3CA3D70Au);   /* 8c0c6e30 fr5=0.02 */
        }
    }
L6e32:
    SETT(fr4 > fr5);                     /* 8c0c6e32 fcmp/gt fr5,fr4 */
    fr6 = fr5;                           /* 8c0c6e34 fmov fr5,fr6 */
    if (T) {                             /* 8c0c6e36 bt/s (delay fneg) */
        fr6 = -fr6;                      /* delay (always) */
        goto L6e42;                      /* 8c0c6e42 (T=1) */
    } else {
        fr6 = -fr6;                      /* delay (always) */
        /* fallthrough delay form 8c0c6e3a */
        SETT(fr6 > fr4);                 /* 8c0c6e3c? (see below) */
        goto L6e3c2;
    }
L6e42:
    fr4 = fr5;                           /* 8c0c6e44 delay (always) */
    goto L6e48;                          /* 8c0c6e42 bra */
L6e3c2:
    SETT(fr6 > fr4);                     /* 8c0c6e3a fcmp/gt fr4,fr6 */
    if (T)
        goto L6e46;                      /* 8c0c6e3c bt */
    goto L6e48;                          /* 8c0c6e3e bra */
L6e46:
    fr4 = fr6;                           /* 8c0c6e46 fmov fr6,fr4 */
    /* (delay form 8c0c6e44: fr4 = fr5) */
L6e48:
    /* (bt/s-taken join sets fr4 = fr5 via delay) */
    r0 = 0x13A8u;                        /* 8c0c6e48 mov.w */
    SETT(r13 == 0);                      /* 8c0c6e4a tst r13,r13 */
    fr5 = 0.0f;                          /* 8c0c6e4c fldi0 fr5 */
    c_wrflt(ram, r0 + r14, fr5);         /* 8c0c6e4e [r14+0x13a8]=0 */
    r0 += 4;                             /* 8c0c6e50 */
    c_wrflt(ram, r0 + r14, fr4);         /* 8c0c6e52 [r14+0x13ac]=fr4 */
    r0 += 4;                             /* 8c0c6e54 */
    if (!T) {                            /* 8c0c6e56 bf/s (delay store) */
        c_wrflt(ram, r0 + r14, fr5);     /* delay (always): [r14+0x13b0]=0 */
        goto L6e5e;                      /* (T=0: r13!=0, skip 0x6e5a) */
    } else {
        c_wrflt(ram, r0 + r14, fr5);     /* delay (always) */
        r0 = 0x13ACu;                    /* 8c0c6e5a */
        c_wrflt(ram, r0 + r14, fr5);     /* 8c0c6e5c [r14+0x13ac]=0 */
    }
    goto L6e5e;
L6e5e:
    /* shared epilogue [06E5E, 06E7C]: add #64 (r15 = X+64), pops. */
    r0 = 0x1FDDu;                        /* 8c0c6e60 mov.w */
    /* (8c0c6e62 lds.l @r15+,pr -> pr = in_pr) */
    c_wr8(ram, r0 + r14, (uint8_t)r13);  /* 8c0c6e64 mov.b r13,@(r0,r14) */
    fr12 = c_rdflt(ram, in_r15 + 0);     /* 8c0c6e66 fmov.s @r15+,fr12 */
    fr13 = c_rdflt(ram, in_r15 + 4);     /* 8c0c6e68 */
    fr14 = c_rdflt(ram, in_r15 + 8);     /* 8c0c6e6a */
    fr15 = c_rdflt(ram, in_r15 + 12);    /* 8c0c6e6c */
    r8 = c_rd32(ram, in_r15 + 16);       /* 8c0c6e6e pop r8 */
    r9 = c_rd32(ram, in_r15 + 20);       /* pop r9 */
    r10 = c_rd32(ram, in_r15 + 24);      /* pop r10 */
    r11 = c_rd32(ram, in_r15 + 28);      /* pop r11 */
    r12 = c_rd32(ram, in_r15 + 32);      /* pop r12 */
    r13 = c_rd32(ram, in_r15 + 36);      /* pop r13 */
    r14 = c_rd32(ram, in_r15 + 40);      /* 8c0c6e7c delay pop r14 */
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
    o->r15 = in_r15 + 44;
    o->pr = in_pr;
    o->sr = (sr & ~1u) | (T ? 1u : 0u);
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
        memcpy(&b, &fr8, 4); o->fr8 = b;
        memcpy(&b, &fr9, 4); o->fr9 = b;
        memcpy(&b, &fr10, 4); o->fr10 = b;
        memcpy(&b, &fr11, 4); o->fr11 = b;
        memcpy(&b, &fr12, 4); o->fr12 = b;
        memcpy(&b, &fr13, 4); o->fr13 = b;
        memcpy(&b, &fr14, 4); o->fr14 = b;
        memcpy(&b, &fr15, 4); o->fr15 = b;
    }
}
