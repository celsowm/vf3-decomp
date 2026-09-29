/* Baseline loop at 0x8C09F6DC. The loop invokes the local clipping helper
 * once per 12-byte record, then restores its saved callee registers. */
#include "fight/f9f6dc.h"
#include "fight/f9f6fc.h"

#include <string.h>

static uint32_t f6_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t a = addr & 0x0fffffffu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4u <= w->base + w->len) {
            uint32_t v;
            memcpy(&v, w->data + (a - w->base), 4);
            return v;
        }
    }
    ++m->oob;
    return 0;
}

static void f6_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t value)
{
    uint32_t a = addr & 0x0fffffffu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4u <= w->base + w->len) {
            memcpy(w->data + (a - w->base), &value, 4);
            return;
        }
    }
    ++m->oob;
}

void vf3_f9f6dc_8c09f6dc(const uint32_t in[37], uint32_t out[37],
                         const vf3_ram_map *ram)
{
    memcpy(out, in, 37u * sizeof(uint32_t));

    /* sts.l pr,@-r15; the call's delay slot sets r4 from r14. */
    out[15] -= 4u;
    f6_wr32(ram, out[15], in[16]);
    out[12] += out[4];
    out[14] += out[4];

    for (unsigned calls = 0; calls < 256; ++calls) {
        out[5] = out[12];
        out[4] = out[14];
        vf3_f9f6fc_8c09f6fc(out, out, ram);

        /* add #-1,r13; add #12,r14; bt/s back, with r12's increment
         * in the taken branch delay slot. */
        --out[13];
        out[17] = (out[17] & ~1u) | ((int32_t)out[13] > 0);
        out[14] += 12u;
        if ((int32_t)out[13] > 0) {
            out[12] += 12u;
            continue;
        }
        break;
    }

    /* lds.l @r15+,pr followed by the three stack restores in the RTS slot. */
    out[16] = f6_rd32(ram, out[15]);
    out[15] += 4u;
    out[12] = f6_rd32(ram, out[15]);
    out[15] += 4u;
    out[13] = f6_rd32(ram, out[15]);
    out[15] += 4u;
    out[14] = f6_rd32(ram, out[15]);
    out[15] += 4u;
}
