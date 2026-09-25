/* See tailcall.h. The fadd honours the game's FPSCR.RM=1 (truncate);
 * the rest is integer moves. All memory traffic goes through the replay
 * map so the test can diff the shadow against the oracle exit windows and
 * count out-of-window accesses. */
#include "fight/tailcall.h"

#include <string.h>

#include "fight/fpu_tz.h"

static uint32_t t_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static void t_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
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

static void t_wrflt(const vf3_ram_map *ram, uint32_t addr, float f)
{
    uint32_t bits;
    memcpy(&bits, &f, 4);
    t_wr32(ram, addr, bits);
}

uint32_t t_rd32pub(const vf3_ram_map *ram, uint32_t addr)
{
    return t_rd32(ram, addr);
}

static float t_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t bits = t_rd32(ram, addr);
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

void vf3_tailcall_8c092f12(uint32_t in_r4, uint32_t in_r15, float in_fr0,
                           vf3_tailcall_out *o, uint32_t pr_in,
                           const vf3_ram_map *ram)
{
    uint32_t r15;

    /* fmov.s fr0,@-r4 */
    o->r4 = in_r4 - 4;
    t_wrflt(ram, o->r4, in_fr0);

    /* add #12,r15 ; mov.l @r15+,r13 ; rts ; (delay) mov.l @r15+,r14 */
    r15 = in_r15 + 12;
    o->r13 = t_rd32(ram, r15);
    r15 += 4;
    o->r14 = t_rd32(ram, r15);
    r15 += 4;
    o->r15 = r15;
    o->pr = pr_in;
}

void vf3_tailcall_8c092abe(uint32_t in_r4, uint32_t in_r15, float in_fr0,
                           vf3_tailcall_out *o, const vf3_ram_map *ram)
{
    uint32_t r3, r1, r2, r0 = 4;
    float f2, f3;

    /* fmov.s fr0,@-r4 */
    o->r4 = in_r4 - 4;
    t_wrflt(ram, o->r4, in_fr0);

    /* r3 = [r15+4]; r1 = 4; r2 = [r15]; r1 += r3 (=> u = 4+v) */
    r3 = t_rd32(ram, in_r15 + 4);
    r1 = r0;
    r2 = t_rd32(ram, in_r15);
    r1 += r3;

    /* [r2+4] += [r1], single-precision RM=1 */
    f2 = t_rdflt(ram, r2 + r0);
    f3 = t_rdflt(ram, r1);
    f2 = fadd_tz(f3, f2);
    t_wrflt(ram, r2 + r0, f2);

    /* rts ; (delay) add #12,r15 (exit lands with +12, not +16) */
    o->r15 = in_r15 + 12;
    o->r13 = 0;   /* filled in by the caller-side test from oracle state */
    o->r14 = 0;
    o->pr = 0;
    (void)r0;
}
