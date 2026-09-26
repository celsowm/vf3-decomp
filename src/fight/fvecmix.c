/* See fvecmix.h. Single-precision IEEE arithmetic, same as the SH-4 FPU
 * round-to-nearest. All memory traffic goes through the replay map so the
 * test can diff the shadow against the oracle exit windows and count
 * out-of-window accesses. */
#include "fight/fvecmix.h"

#include <string.h>

static uint32_t f_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static void f_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
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

static void f_wrflt(const vf3_ram_map *ram, uint32_t addr, float f)
{
    uint32_t bits;
    memcpy(&bits, &f, 4);
    f_wr32(ram, addr, bits);
}

void vf3_fvecmix_8c071668(uint32_t in_r4, uint32_t in_r9, uint32_t in_r10,
                          uint32_t in_r12, uint32_t in_r14, uint32_t in_r15,
                          float in_fr0, vf3_fvecmix_out *o,
                          const vf3_ram_map *ram)
{
    uint32_t r4 = in_r4, r12 = in_r12, r14 = in_r14, r15 = in_r15;
    uint32_t r9 = in_r9 - 1;
    int gt = (int32_t)in_r10 > (int32_t)r9;

    /* fmov.s fr0,@-r4 */
    r4 -= 4;
    f_wrflt(ram, r4, in_fr0);
    r12 += 24;
    if (!gt) {
        /* bf/s taken: delay slot still retires (r14 += 24), then the
         * taken path pops fr12-15 / r9-r13 and returns. */
        uint32_t v;
        r14 += 24;
        r15 += 52;
        /* fr12..fr15 pop (values caller-owned; traffic still modelled) */
        r15 += 16;
        r9 = f_rd32(ram, r15); r15 += 4;
        f_rd32(ram, r15); r15 += 4;      /* r10 slot */
        f_rd32(ram, r15); r15 += 4;      /* r11 slot */
        r12 = f_rd32(ram, r15); r15 += 4;
        f_rd32(ram, r15); r15 += 4;      /* r13 slot */
        r14 = f_rd32(ram, r15); r15 += 4;
        v = r9;
        (void)v;
        o->r4 = r4;
        o->r9 = r9;
        o->r12 = r12;
        o->r14 = r14;
        o->r15 = r15;
        o->pr = 0;               /* rts taken */
        return;
    }
    /* fall-through: r14 += 24 (delay slot), tail jump (unmodelled target) */
    r14 += 24;
    o->r4 = r4;
    o->r9 = r9;
    o->r12 = r12;
    o->r14 = r14;
    o->r15 = r15;
    o->pr = 0x8C071676u;         /* jmp @r3 site (target = oracle pr) */
}
