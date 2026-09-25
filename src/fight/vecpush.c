/* See vecpush.h. Single-precision IEEE arithmetic, same as SH-4 FPU
 * round-to-nearest. All memory traffic goes through the replay map so the
 * test can diff the shadow against the oracle exit windows and count
 * out-of-window accesses. */
#include "fight/vecpush.h"

#include <string.h>

static uint32_t v_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static void v_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
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

static float v_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t bits = v_rd32(ram, addr);
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

static void v_wrflt(const vf3_ram_map *ram, uint32_t addr, float f)
{
    uint32_t bits;
    memcpy(&bits, &f, 4);
    v_wr32(ram, addr, bits);
}

static int32_t s32(uint32_t v)
{
    return (int32_t)v;
}

int vf3_vecpush_sub3_head(uint32_t in_r4, uint32_t in_r8, uint32_t in_r9,
                          uint32_t in_r11, uint32_t in_r13, uint32_t in_r14,
                          uint32_t in_r15, float in_fr0,
                          vf3_vecpush_out *o, const vf3_ram_map *ram)
{
    uint32_t r3x, r2x;
    float a0, a1, a2, b0, b1, b2;
    float f0, f1, f2;

    /* spill entry fr0 to the caller scratch slot (pre-decrement) */
    v_wrflt(ram, in_r4 - 4, in_fr0);

    /* caller-frame bookkeeping */
    v_wr32(ram, in_r15 + 4, in_r14);
    r3x = v_rd32(ram, in_r15);
    r3x += 24;
    v_wr32(ram, in_r15, r3x);
    r2x = v_rd32(ram, in_r15 + 20);
    v_wr32(ram, in_r15 + 8, r2x);

    if (!(s32(r2x) > s32(in_r9)))
        return VF3_VECPUSH_FULL;

    o->r8 = in_r8 + 24;
    o->r11 = in_r11 + 24;
    o->r14 = in_r11;

    {
        uint32_t a = in_r14, b = in_r11, d = in_r13;
        a0 = v_rdflt(ram, a);
        b0 = v_rdflt(ram, b);
        a1 = v_rdflt(ram, a + 4);
        b1 = v_rdflt(ram, b + 4);
        a2 = v_rdflt(ram, a + 8);
        b2 = v_rdflt(ram, b + 8);
        f0 = a0 - b0;
        f1 = a1 - b1;
        f2 = a2 - b2;
        v_wrflt(ram, d + 8, f2);
        v_wrflt(ram, d + 4, f1);
        v_wrflt(ram, d, f0);
        o->r4 = d;
        o->r5 = a + 8;
        o->r6 = b + 8;
        o->fr[0] = f0;
        o->fr[1] = f1;
        o->fr[2] = f2;
        o->fr[3] = b0;
        o->fr[4] = b1;
        o->fr[5] = b2;
    }
    return VF3_VECPUSH_MAIN;
}
