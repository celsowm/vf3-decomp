/* 0x8C040F1E: allocate one word from the AICA command pool. */
#include "fight/f040f1e.h"

#include <string.h>

static uint32_t f_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4u <= w->base + w->len) {
            uint32_t value;
            memcpy(&value, w->data + (canon - w->base), 4);
            return value;
        }
    }
    ++m->oob;
    return 0;
}

static void f_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t value)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4u <= w->base + w->len) {
            memcpy(w->data + (canon - w->base), &value, 4);
            return;
        }
    }
    ++m->oob;
}

void vf3_f040f1e_8c040f1e(const uint32_t in[37], uint32_t out[37],
                          const vf3_ram_map *ram)
{
    const uint32_t slot = 0x0C19E218u;
    uint32_t sp = in[15] - 4u;
    uint32_t t = 0;
    uint32_t result;

    memcpy(out, in, 37u * sizeof(uint32_t));
    f_wr32(ram, sp, in[4]);                /* mov.l r4,@r15 */
    result = f_rd32(ram, sp);              /* mov.l @r15,r0 */
    if ((result & 0x80u) == 0) {
        out[0] = 0xFFFFFFFEu;
        out[15] = in[15];
        out[17] = in[17] & ~1u;
        return;
    }
    {
        uint32_t pool = f_rd32(ram, slot);
        uint32_t busy = f_rd32(ram, pool);
        out[3] = slot;
        out[2] = pool;
        out[1] = busy;
        if (busy != 0) {
            out[0] = 0xFFFFFFFFu;
            out[15] = in[15];
            out[17] = in[17] & ~1u;
            return;
        }
        pool += 4u;
        f_wr32(ram, slot, pool);
        f_wr32(ram, pool - 4u, in[4]);
        t = pool == 0xA0800500u;
        if (t)
            f_wr32(ram, slot, 0xA0800400u);
        out[0] = 0;
        out[1] = pool;
    }
    out[2] = 0xA0800500u;
    out[3] = slot;
    out[15] = in[15];
    out[17] = (in[17] & ~1u) | t;
}
