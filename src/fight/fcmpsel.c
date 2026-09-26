/* See fcmpsel.h. All traffic goes through the replay map so the test
 * diffs the shadow against the oracle exit windows. */
#include "fight/fcmpsel.h"
#include "fight/fpu_tz.h"

#include <string.h>

static uint32_t s_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static void s_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
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

static float s_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t bits = s_rd32(ram, addr);
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

static void s_wrflt(const vf3_ram_map *ram, uint32_t addr, float f)
{
    uint32_t bits;
    memcpy(&bits, &f, 4);
    s_wr32(ram, addr, bits);
}

/* SH-4 fcmp/gt FRm,FRn: T = (FRn > FRm). Note the operand order reads
 * backwards from the comparison: `fcmp/gt fr5,fr3` tests fr3 > fr5. */
static int fcmp_gt(uint32_t m_bits, uint32_t n_bits)
{
    float m, n;
    memcpy(&m, &m_bits, 4);
    memcpy(&n, &n_bits, 4);
    return n > m;
}

void vf3_fcmpsel_8c0c7050(uint32_t in_sr, float in_fr3, float in_fr4,
                          float in_fr5, float in_fr6, uint32_t in_r4,
                          uint32_t in_r5, uint32_t in_r6,
                          vf3_fcmpsel_out *o, const vf3_ram_map *ram)
{
    uint32_t r3, r7;
    float fr3 = in_fr3, fr4 = in_fr4, fr5 = in_fr5, fr6;
    int T;

    (void)in_fr6;
    r7 = 0x0C2D0190u;                 /* 8c0c7050 lit (mov.l @(156,pc),r7) */
    fr6 = fr4;                        /* 8c0c7052 fmov fr4,fr6 */
    r3 = s_rd32(ram, r7 + 28);        /* 8c0c7054 */
    T = (r3 == 0);                    /* 8c0c7056 tst */
    fr6 = fsub_tz(fr6, fr5);          /* 8c0c705a delay (always) */
    if (T) {
        fr4 = fr6;                    /* 8c0c705e delay of bra (always) */
        goto store;                   /* 8c0c7058 bf/s not taken */
    }
    /* 8c0c705c bra delay fmov fr6,fr4 folds into `store` prologue below */
    r3 = s_rd32(ram, r7 + 24);        /* 8c0c7060 */
    T = (r3 == 0);                    /* 8c0c7062 tst */
    if (!T)
        goto loadpath;                /* 8c0c7064 bf */
    fr3 = 0.0f;                       /* 8c0c7066 fldi0 */
    T = fcmp_gt(fpu_f32_to_bits(fr5), fpu_f32_to_bits(fr3)); /* 8c0c7068: T = (fr3 > fr5) */
    fr4 = fr6;                        /* 8c0c706c delay (always) */
    if (!T)
        goto done_nostore;            /* 8c0c706a bf/s taken */
    goto store;                       /* 8c0c706e bra */
loadpath:
    fr6 = s_rdflt(ram, in_r6);        /* 8c0c7072 */
    fr5 = s_rdflt(ram, in_r5);        /* 8c0c7074 */
    fr5 = fsub_tz(fr5, fr6);          /* 8c0c7076 */
    T = fcmp_gt(fpu_f32_to_bits(fr4), fpu_f32_to_bits(fr5)); /* 8c0c7078: T = (fr5 > fr4) */
    if (T)
        goto store;                   /* 8c0c707a bt */
    fr4 = fsub_tz(fr4, fr5);          /* 8c0c707c delay (always) */
store:
    s_wrflt(ram, in_r4, fr4);         /* 8c0c707e */
done_nostore:
    /* 8c0c7080 rts (+nop delay) */
    o->r3 = r3;
    o->r7 = r7;
    o->fr3 = fpu_f32_to_bits(fr3);
    o->fr4 = fpu_f32_to_bits(fr4);
    o->fr5 = fpu_f32_to_bits(fr5);
    o->fr6 = fpu_f32_to_bits(fr6);
    o->sr = T ? (in_sr | 1u) : (in_sr & ~1u);
}
