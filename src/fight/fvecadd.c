/* See fvecadd.h. All FPU adds honour the game's FPSCR.RM=1 (truncate);
 * all traffic goes through the replay map so the test diffs the shadow
 * against the oracle exit windows. */
#include "fight/fvecadd.h"
#include "fight/fpu_tz.h"

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

void vf3_fvecadd_8c0930b6(uint32_t in_r4, uint32_t in_r15, float in_fr0,
                          vf3_fvecadd_out *o, const vf3_ram_map *ram)
{
    uint32_t r4, r5;
    float a0, a1, a2, b0, b1, b2, f0, f1, f2;

    /* fmov.s fr0,@-r4 */
    r4 = in_r4 - 4;
    a_wrflt(ram, r4, in_fr0);

    /* destination triple comes from the caller frame */
    r4 = a_rd32(ram, in_r15 + 20);
    r5 = in_r15 + 4;

    a0 = a_rdflt(ram, r4); r4 += 4;
    b0 = a_rdflt(ram, r5); r5 += 4;
    a1 = a_rdflt(ram, r4); r4 += 4;
    b1 = a_rdflt(ram, r5); r5 += 4;
    a2 = a_rdflt(ram, r4); r4 += 4;
    b2 = a_rdflt(ram, r5); r5 += 4;

    f0 = fadd_tz(a0, b0);
    f2 = fadd_tz(a2, b2);
    f1 = fadd_tz(a1, b1);

    /* stored high-to-low, leaving r4 92 past the triple base */
    r4 -= 4; a_wrflt(ram, r4, f2);
    r4 -= 4; a_wrflt(ram, r4, f1);
    r4 -= 4; a_wrflt(ram, r4, f0);

    o->r4 = r4;
    o->r5 = r5;
    o->r15 = in_r15 + 20;
    o->fr0 = fpu_f32_to_bits(f0);
    o->fr1 = fpu_f32_to_bits(f1);
    o->fr2 = fpu_f32_to_bits(f2);
    o->fr3 = fpu_f32_to_bits(b0);
    o->fr4 = fpu_f32_to_bits(b1);
    o->fr5 = fpu_f32_to_bits(b2);
}
