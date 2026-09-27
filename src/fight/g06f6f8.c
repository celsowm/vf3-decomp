/* See g06f6f8.h. All traffic goes through the replay map so the test
 * diffs the shadow against the oracle exit windows; every map access must
 * hit (nonzero OOB fails the replay). FPU uses the entry FPSCR (oracle:
 * 0x00040001 = RM=01 truncate, DN=1) via fight/fpu_tz.h. */
#include "fight/g06f6f8.h"
#include "fight/fpu_tz.h"

#include <math.h>
#include <string.h>

static uint32_t a_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static void a_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
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

static float a_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t bits = a_rd32(ram, addr);
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

static void a_wrflt(const vf3_ram_map *ram, uint32_t addr, float f)
{
    uint32_t bits;
    memcpy(&bits, &f, 4);
    a_wr32(ram, addr, bits);
}

/* fipr fv0,fv0 (0xF0ED): fr3 = fr0*fr0 + fr1*fr1 + fr2*fr2 + fr3*fr3.
 * Evaluated once in extended precision and truncated to float (Flycast /
 * dream-recomp evaluate FIPR in double, rounded once; the hardware uses
 * reduced internal precision, so this is a documented approximation). */
static float do_fipr_fv0(float f0, float f1, float f2, float f3)
{
    long double d = (long double)f0 * f0 + (long double)f1 * f1 +
                    (long double)f2 * f2 + (long double)f3 * f3;
    return f32_tz(d);
}

/* fsrra fr3 (0xF37D): approximate 1/sqrt. The SH-4 uses a hardware lookup
 * table (not bit-exact via Newton); dream-recomp/Flycast evaluate
 * 1/sqrtf. Truncate-rounded here to match the RM=1 game mode. */
static float do_fsrra(float f)
{
    long double d;
    if (!(f > 0.0f))
        return fpu_bits_to_f32(0x7FC00000u); /* hardware QNaN neighbourhood;
                                                * zero/negative never occur
                                                * on the oracle path */
    d = 1.0L / sqrtl((long double)f);
    return f32_tz(d);
}

void vf3_g06f6f8_8c06f6f8(uint32_t in_r4, uint32_t in_r15,
                          float in_fr0, float in_fr14, float in_fr15,
                          uint32_t in_fpscr,
                          vf3_g06f6f8_out *o, const vf3_ram_map *ram)
{
    uint32_t r0, r3, r4, r5;
    float fr0, fr1, fr2, fr3, fr4;
    float len, thr;
    uint32_t T;

    memset(o, 0, sizeof(*o));

    /* fmov.s fr0,@-r4 */
    r4 = in_r4 - 4;
    a_wrflt(ram, r4, in_fr0);

    /* mov r15,r4 ; add #56,r4 */
    r4 = in_r15 + 56;

    /* fmov.s @r4+,fr0/fr1/fr2 (fr0 slot holds the spill just written) */
    fr0 = a_rdflt(ram, r4); r4 += 4;
    fr1 = a_rdflt(ram, r4); r4 += 4;
    fr2 = a_rdflt(ram, r4); r4 += 4;

    /* fldi0 fr3 ; fipr fv0,fv0 ; fmov fr3,fr0 ; fsqrt fr0 */
    fr3 = 0.0f;
    fr3 = do_fipr_fv0(fr0, fr1, fr2, fr3);
    fr0 = fr3;
    fr0 = fpu_dn_fix(f32_tz(sqrtl((long double)fr0)), in_fpscr);

    /* mova @(36,pc),r0 ; fmov.s @r0,fr3 */
    r0 = 0x8C06F738u;
    thr = a_rdflt(ram, r0);
    fr3 = thr;

    /* fcmp/gt fr0,fr3 : T = (fr3 > fr0), unordered (NaN) -> 0 */
    len = fr0;
    T = (thr > len && thr == thr && len == len) ? 1u : 0u;

    if (T != 0) {
        /* Small-|v| path: untripped in all 8 oracle RAM cases. Model the
         * three in-bounds stores, then gate: the jmp @r3 target
         * (0x0C06F75C, read from pool 0x8C06F73C) lies outside the 88 B. */
        r0 = 56;
        a_wrflt(ram, in_r15 + r0, in_fr14);   /* fmov.s fr14,@(r0,r15) */
        r0 = 60;
        a_wrflt(ram, in_r15 + r0, in_fr15);   /* fmov.s fr15,@(r0,r15) */
        r0 = 64;
        r3 = a_rd32(ram, 0x8C06F73Cu);        /* pool: 0x0C06F75C */
        /* jmp @r3 (delay slot always executes) */
        a_wrflt(ram, in_r15 + r0, in_fr15);   /* fmov.s fr15,@(r0,r15) */
        o->r0 = r0;
        o->r4 = in_r15 + 56;
        o->r5 = in_r15;
        o->fr0 = fpu_f32_to_bits(len);
        o->fr1 = fpu_f32_to_bits(fr1);
        o->fr2 = fpu_f32_to_bits(fr2);
        o->fr3 = fpu_f32_to_bits(thr);
        o->fr4 = fpu_f32_to_bits(in_fr14);
        o->T = T;
        o->gated = 1;
        o->tail_target = 0x8C000000u | (r3 & 0x00FFFFFFu);
        return;
    }

    /* Normalize path (0x8C06F728, taken by all 8 oracle RAM cases):
     * mov r15,r4 ; mov r15,r5 ; add #56,r4 ; fmov fr14,fr4 ; add #56,r5 ;
     * bra 0x8C06F740 (delay nop). */
    r4 = in_r15;
    r5 = in_r15;
    r4 += 56;
    fr4 = in_fr14;
    r5 += 56;

    /* 0x8C06F740: fmov.s @r5+,fr0/fr1/fr2 */
    fr0 = a_rdflt(ram, r5); r5 += 4;
    fr1 = a_rdflt(ram, r5); r5 += 4;
    fr2 = a_rdflt(ram, r5); r5 += 4;

    /* fldi0 fr3 ; fipr fv0,fv0 ; fsrra fr3 ; fmul fr4,fr3 ; add #12,r4 */
    fr3 = 0.0f;
    fr3 = do_fipr_fv0(fr0, fr1, fr2, fr3);
    fr3 = fpu_dn_fix(do_fsrra(fr3), in_fpscr);
    fr3 = fpu_dn_fix(fmul_tz(fr4, fr3), in_fpscr);
    r4 += 12;   /* r4 = frame+68; falls through to 0x8C06F750 (out of scope) */

    o->r0 = 0x8C06F738u;
    o->r4 = r4;
    o->r5 = r5;
    o->fr0 = fpu_f32_to_bits(fr0);
    o->fr1 = fpu_f32_to_bits(fr1);
    o->fr2 = fpu_f32_to_bits(fr2);
    o->fr3 = fpu_f32_to_bits(fr3);
    o->fr4 = fpu_f32_to_bits(fr4);
    o->T = T;
    o->gated = 0;
    o->tail_target = 0;
}
