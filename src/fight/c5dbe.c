/* Clean C model for the 0x8C0C5DBE table-backed resource lookup. */
#include "fight/c5dbe.h"

#include "fight/f040f1e.h"

#include <string.h>

static uint32_t c5_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4u <= w->base + w->len) {
            uint32_t v;
            memcpy(&v, w->data + (canon - w->base), sizeof(v));
            return v;
        }
    }
    m->oob++;
    return 0;
}

static void c5_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4u <= w->base + w->len) {
            memcpy(w->data + (canon - w->base), &v, sizeof(v));
            return;
        }
    }
    m->oob++;
}

void vf3_c5dbe_8c0c5dbe(const uint32_t in[37], uint32_t out[37],
                        const vf3_ram_map *ram)
{
    uint32_t sp = in[15] - 4u;
    uint32_t r[37];
    uint32_t offset, table = 0x0C1025F0u;
    int take_call = 0;

    memcpy(r, in, sizeof(r));
    r[5] = 0x0C1FD758u;
    c5_wr32(ram, sp, in[16]);                  /* sts.l pr,@-r15 */
    r[15] = sp;

    /* bf 5DF0; cmp/ge #0x1DD,r4; bt 5DF0. */
    if ((in[17] & 1u) != 0 && in[4] < 0x1DDu) {
        offset = in[4] << 2;
        r[14] = offset;
        r[3] = c5_rd32(ram, table + offset);
        /* cmp/pz r3; bf 5DF0 */
        if ((int32_t)r[3] >= 0) {
            uint32_t base = 0x0C2CFA00u;
            r[0] = offset;
            r[4] = base;
            uint32_t global = c5_rd32(ram, r[5]);
            uint32_t cur = c5_rd32(ram, base + offset);
            r[2] = global;
            r[3] = cur;
            /* cmp/eq r2,r3; bt 5DF0 */
            if (global != cur) {
                r[3] = c5_rd32(ram, r[5]);
                r[0] = offset;
                c5_wr32(ram, base + offset, r[3]);
                r[3] = 0x0C040F1Eu;
                r[0] = table;
                take_call = 1;
            }
        }
    }

    if (take_call) {
        uint32_t helper_in[37], helper_out[37];
        memcpy(helper_in, r, sizeof(helper_in));
        /* SH-4 executes the jsr delay slot before entering the helper. */
        helper_in[4] = c5_rd32(ram, table + r[14]);
        helper_in[15] = sp;
        helper_in[16] = 0x8C0C5DEEu;            /* jsr return address */
        vf3_f040f1e_8c040f1e(helper_in, helper_out, ram);
        for (int i = 0; i < 37; i++)
            r[i] = helper_out[i];
    }

    /* lds.l @r15+,pr; rts; delay slot: mov.l @r15+,r14. */
    r[16] = c5_rd32(ram, r[15]);
    r[15] += 4u;
    r[14] = c5_rd32(ram, r[15]);
    r[15] += 4u;
    memcpy(out, r, sizeof(r));
}
