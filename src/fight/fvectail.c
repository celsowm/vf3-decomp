/* See fvectail.h. All traffic goes through the replay map so the test
 * diffs the shadow against the oracle exit windows. */
#include "fight/fvectail.h"

#include <string.h>

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

void vf3_fvectail_8c0930d4(uint32_t in_r4, uint32_t in_r15, float in_fr0,
                           vf3_fvectail_out *o, const vf3_ram_map *ram)
{
    uint32_t r4, r15, fr15bits;
    uint32_t fr0bits;

    /* fmov.s fr0,@-r4 */
    memcpy(&fr0bits, &in_fr0, 4);
    r4 = in_r4 - 4;
    t_wr32(ram, r4, fr0bits);

    /* nop ; add #16,r15 ; rts + delay fmov.s @r15+,fr15 */
    r15 = in_r15 + 16;
    fr15bits = t_rd32(ram, r15);
    r15 += 4;

    o->r4 = r4;
    o->r15 = r15;
    o->fr15 = fr15bits;
}
