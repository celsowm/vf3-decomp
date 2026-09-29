/* SH-4 0x8C096258: merge node flags into three indexed global masks. */
#include "fight/f096258.h"

#include <string.h>

static uint32_t f96258_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4u <= w->base + w->len) {
            uint32_t value;
            memcpy(&value, w->data + (canon - w->base), sizeof(value));
            return value;
        }
    }
    ++m->oob;
    return 0;
}

static void f96258_wr32(const vf3_ram_map *ram, uint32_t addr,
                        uint32_t value)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4u <= w->base + w->len) {
            memcpy(w->data + (canon - w->base), &value, sizeof(value));
            return;
        }
    }
    ++m->oob;
}

void vf3_f096258_8c096258(const uint32_t in[37], uint32_t out[37],
                          const vf3_ram_map *ram)
{
    uint32_t sp = in[15];
    uint32_t node_index = in[4];
    uint32_t node = 0x0C2CF834u + (uint32_t)(int32_t)(int8_t)(node_index * 20u);
    uint32_t shift = in[13];
    uint32_t node_flags[3];
    uint32_t indexed_mask;

    memcpy(out, in, 37u * sizeof(uint32_t));
    out[16] = in[16]; /* PR is pushed and restored around the body. */
    f96258_wr32(ram, sp - 4u, in[16]);

    if (f96258_rd32(ram, node) != UINT32_MAX) {
        uint32_t bitshift = (shift * 8u + 8u) & 31u;
        for (unsigned i = 0; i < 3; ++i) {
            static const uint8_t offset[3] = { 16, 8, 12 };
            uint32_t mask = f96258_rd32(ram, node + offset[i]);
            uint32_t flags = 0;
            static const uint8_t test_offset[8] = { 8, 12, 0, 4, 24, 20, 28, 32 };
            static const uint8_t flag_bit[8] = { 4, 8, 1, 2, 16, 32, 64, 128 };
            for (unsigned j = 0; j < 8; ++j)
                if (mask & f96258_rd32(ram, in[6] + test_offset[j]))
                    flags |= flag_bit[j];
            flags <<= bitshift;
            node_flags[i] = flags;
        }

        out[0] = 0x140u;
        out[1] = 0;
        out[2] = f96258_rd32(ram, node + 12u);
        out[3] = 0;
        out[4] = node_flags[2];
        out[5] = 0x01000000u;
        out[6] = 8u;

        /* Node bit 8 controls the corresponding shifted bit 16. */
        if (f96258_rd32(ram, node + 16) & 8u)
            node_flags[0] |= 16u << (shift & 31u);
        if (f96258_rd32(ram, node + 8) & 8u)
            node_flags[1] |= 16u << (shift & 31u);
        if (f96258_rd32(ram, node + 12) & 8u)
            node_flags[2] |= 16u << (shift & 31u);

        indexed_mask = f96258_rd32(ram, in[6] + 16u);
        if (f96258_rd32(ram, node + 16) & indexed_mask)
            node_flags[0] |= 64u << (shift & 31u);
        if (f96258_rd32(ram, node + 8) & indexed_mask)
            node_flags[1] |= 64u << (shift & 31u);
        if (f96258_rd32(ram, node + 12) & indexed_mask)
            node_flags[2] |= 64u << (shift & 31u);

        for (unsigned i = 0; i < 3; ++i) {
            uint32_t addr = in[9] + 0x138u + i * 4u;
            f96258_wr32(ram, addr, f96258_rd32(ram, addr) | node_flags[i]);
        }
    } else {
        out[0] = UINT32_MAX;
    }

    /* The capture starts with the callee-save frame at SP; RTS delay pops r14. */
    for (unsigned i = 0; i < 7; ++i)
        out[8u + i] = f96258_rd32(ram, sp + i * 4u);
    out[15] = sp + 28u;
}
