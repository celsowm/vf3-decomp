/* SH-4 0x8C09F9A8: exact signed-guard return path. */
#include "fight/f9f9a8.h"

#include <string.h>

static int f9f9a8_write32(const vf3_ram_map *ram, uint32_t addr,
                          uint32_t value)
{
    uint32_t a = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4u <= w->base + w->len) {
            memcpy(w->data + a - w->base, &value, sizeof(value));
            return 1;
        }
    }
    ++m->oob;
    return 0;
}

int vf3_f9f9a8_guard(const uint32_t in[37], uint32_t out[37],
                     const vf3_ram_map *ram)
{
    uint32_t masked = in[5] & in[2];
    if ((int32_t)masked <= (int32_t)in[4])
        return -1;

    memcpy(out, in, 37u * sizeof(uint32_t));
    out[5] = masked;
    out[6] = in[6] << 8;      /* bt/s delay slot */
    out[15] = in[15] + 4u;
    out[17] = in[17] | 1u;   /* cmp/gt sets T on this branch */
    return f9f9a8_write32(ram, in[15] - 4u, in[16]);
}
