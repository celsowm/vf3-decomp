/* See scaler3.h. The port models the SH-4 body as straight-line code
 * through the vf3_ram_map so the replay shadows every in-window write.
 * Uses the fpu_tz helpers (RM=truncate) — plain RN differed by 1 ULP on
 * the products (model-based oracle check across 4 RAM cases, e.g.
 * 0x3ab39469 vs 0x3ab39468 on case 1's sx). */
#include "fight/scaler3.h"
#include "fight/fpu_tz.h"

#include <string.h>

static uint32_t f2bits(float f)
{
    uint32_t b;
    memcpy(&b, &f, 4);
    return b;
}

static float bits2f(uint32_t b)
{
    float f;
    memcpy(&f, &b, 4);
    return f;
}

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

#define EPILOGUE_R3    0x0C092C38u /* literal tail target */

static float m_rdflt(const vf3_ram_map *ram, uint32_t a) { return bits2f(m_rd32(ram, a)); }
static void m_wrflt(const vf3_ram_map *ram, uint32_t a, float f) { m_wr32(ram, a, f2bits(f)); }

void vf3_scaler3_8c092bc6(uint32_t in_r1, uint32_t in_r3, uint32_t in_r4,
                          uint32_t in_r15,
                          uint32_t in_fr0_bits, uint32_t in_fr1_bits,
                          uint32_t in_fr2_bits, uint32_t in_fr3_bits,
                          uint32_t in_fr4_bits, uint32_t in_fr5_bits,
                          int path, float scale2x_ignored,
                          vf3_scaler3_out *o, const vf3_ram_map *ram)
{
    uint32_t r4, r5, r15;
    float s, s2;

    r4 = in_r4;
    r15 = in_r15;
    (void)scale2x_ignored;

    memset(o, 0, sizeof(*o));

    /* --- shared prefix: spill + first test, ALL paths --- */
    r4 -= 4;
    m_wrflt(ram, r4, bits2f(in_fr0_bits)); /* fmov.s fr0,@-r4 (window 0) */

    if (path == 1) {
        /* bit-1 of m[r15+40] is SET: T=0, fall through to literal-load +
         * tail-jmp. The only deterministic RAM reads are the spill target
         * and the epilogue pop. */
        o->r0 = m_rd32(ram, r15 + 40);
        o->r1 = in_r1;                 /* unchanged */
        o->r2 = 0;                     /* in_r2 unchanged; test forces */
        o->r3 = EPILOGUE_R3;
        o->r4 = r4;
        o->r5 = 0;                     /* in_r5 unchanged; test forces */
        o->sr_T = 0;
        o->fr0 = in_fr0_bits;
        o->fr1 = in_fr1_bits;
        o->fr2 = in_fr2_bits;
        o->fr3 = in_fr3_bits;
        o->fr4 = in_fr4_bits;
        o->fr5 = in_fr5_bits;
    } else {
        /* --- paths 2/3/4: scale load ---
         *   r2 = m[r15+4]; r0 = 20; fr2 = 0; fr4 = m[r2+20]; fr4 += fr4_under_RM1 */
        o->r0 = 20;
        o->r2 = m_rd32(ram, r15 + 4);
        s  = m_rdflt(ram, o->r2 + 20);
        s2 = fadd_tz(s, s);            /* fadd fr4, fr4 under RM=truncate */

        if (path == 2) {
            /* scale == 0 => fcmp T=1 -> tail jmp. */
            o->r1 = in_r1;
            o->r3 = EPILOGUE_R3;
            o->r4 = r4;
            o->r5 = 0;                 /* untouched; forced by test */
            o->sr_T = 1;
            o->fr0 = in_fr0_bits;
            o->fr1 = in_fr1_bits;
            o->fr2 = f2bits(0.0f);
            o->fr3 = f2bits(s);
            o->fr4 = f2bits(s2);
            o->fr5 = in_fr5_bits;
        } else if (path == 3) {
            /* scale != 0 AND m[r15+0] == 0 -> r1 overwrite + tail. */
            o->r1 = EPILOGUE_R3;
            o->r3 = in_r3;             /* jump via r1, r3 unchanged */
            o->r4 = r4;
            o->r5 = 0;
            o->sr_T = 1;
            o->fr0 = in_fr0_bits;
            o->fr1 = in_fr1_bits;
            o->fr2 = f2bits(0.0f);
            o->fr3 = f2bits(s);
            o->fr4 = f2bits(s2);
            o->fr5 = in_fr5_bits;
        } else {
            /* path == 4: full body (scale != 0 AND m[r15+0] != 0). */
            float vec1x, vec1y, vec1z, vec2x, vec2y, vec2z;
            float sx, sy, sz;
            uint32_t ptr, r1;

            r1 = m_rd32(ram, r15 + 0);
            o->r1 = r1;
            o->r3 = in_r3;             /* body never writes r3 */

            r5 = m_rd32(ram, r15 + 36);
            vec1x = m_rdflt(ram, r5 + 0);
            vec1y = m_rdflt(ram, r5 + 4);
            vec1z = m_rdflt(ram, r5 + 8);

            sx = fmul_tz(s2, vec1x);
            sy = fmul_tz(s2, vec1y);
            sz = fmul_tz(s2, vec1z);

            m_wrflt(ram, r15 + 20, sz);
            m_wrflt(ram, r15 + 16, sy);
            m_wrflt(ram, r15 + 12, sx);

            ptr = r1;
            vec2x = m_rdflt(ram, ptr + 24);
            vec2y = m_rdflt(ram, ptr + 28);
            vec2z = m_rdflt(ram, ptr + 32);

            o->fr0 = f2bits(fadd_tz(vec2x, sx));
            o->fr1 = f2bits(fadd_tz(vec2y, sy));
            o->fr2 = f2bits(fadd_tz(vec2z, sz));
            o->fr3 = f2bits(sx);
            o->fr4 = f2bits(sy);
            o->fr5 = f2bits(sz);

            m_wrflt(ram, ptr + 32, bits2f(o->fr2));
            m_wrflt(ram, ptr + 28, bits2f(o->fr1));
            m_wrflt(ram, ptr + 24, bits2f(o->fr0));

            o->sr_T = 0;               /* tst r1,r1 with r1 != 0 -> T=0 */
            o->r4 = ptr + 24;
            o->r5 = in_r15 + 24;
        }
    }

    /* --- shared epilogue: r14 = m[in_r15+24]; r15 += 28 --- */
    o->r14 = m_rd32(ram, in_r15 + 24);
    o->r15 = in_r15 + 28;
}
