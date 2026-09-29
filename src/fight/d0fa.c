/* SH-4 0x8C08D0FA: update a slot and resolve its two byte-table fields. */
#include "fight/d0fa.h"

#include <string.h>

static uint32_t canon(uint32_t a) { return a & 0x0FFFFFFFu; }

static uint8_t rd8(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t a = canon(addr);
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 1 <= w->base + w->len)
            return w->data[a - w->base];
    }
    m->oob++;
    return 0;
}

static uint16_t rd16(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t a = canon(addr);
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 2 <= w->base + w->len) {
            uint16_t v;
            memcpy(&v, w->data + a - w->base, 2);
            return v;
        }
    }
    m->oob++;
    return 0;
}

static uint32_t rd32(const vf3_ram_map *ram, uint32_t addr)
{
    return vf3_ram_read32(ram, addr);
}

static void wr8(const vf3_ram_map *ram, uint32_t addr, uint8_t value)
{
    uint32_t a = canon(addr);
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 1 <= w->base + w->len) {
            w->data[a - w->base] = value;
            return;
        }
    }
    m->oob++;
}

static void wr16(const vf3_ram_map *ram, uint32_t addr, uint16_t value)
{
    uint32_t a = canon(addr);
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 2 <= w->base + w->len) {
            memcpy(w->data + a - w->base, &value, 2);
            return;
        }
    }
    m->oob++;
}

static void wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t value)
{
    uint32_t a = canon(addr);
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4 <= w->base + w->len) {
            memcpy(w->data + a - w->base, &value, 4);
            return;
        }
    }
    m->oob++;
}

static void resolve_state(uint32_t state, uint32_t stack, uint16_t key, uint32_t index,
                          const vf3_ram_map *ram)
{
    const uint32_t a = 0x0C0F9214u + (uint32_t)key * 4u;
    const uint32_t b = 0x0C0F829Cu + (uint32_t)key * 4u;
    uint8_t va, vb;

    /* The helper scales the saved key by four before writing it back. */
    wr32(ram, state + 52u, (uint32_t)key * 4u);
    wr32(ram, state + 64u, index);
    /* The table slots contain absolute RAM pointers; only the sequence
       index is added after loading the pointer. */
    va = rd8(ram, rd32(ram, a) + index);
    vb = rd8(ram, rd32(ram, b) + index);
    wr32(ram, stack - 8u, va);
    wr32(ram, state + 56u, vb);
    wr32(ram, state + 60u, va);
}

uint32_t vf3_d0fa_update(uint32_t slot_offset, uint32_t limit,
                         uint32_t index, uint32_t object,
                         uint32_t state, uint32_t stack,
                         uint32_t saved_pr, const vf3_ram_map *ram)
{
    uint32_t next = index + 1u;
    uint32_t r0 = slot_offset;

    /* The entry saves PR at -4(r15); its helper uses -8(r15) as scratch. */
    wr32(ram, stack - 4u, saved_pr);

    if (next >= limit) {
        wr32(ram, state, rd32(ram, state) & ~1u);
        return r0;
    }

    wr8(ram, object + slot_offset, (uint8_t)next);
    resolve_state(state, stack, rd16(ram, object + 40u), next, ram);
    r0 = 64u;

    if (rd32(ram, state + 56u) == 0xFFu || rd32(ram, state + 60u) == 0u) {
        wr32(ram, state, rd32(ram, state) & ~1u);
        return r0;
    }

    r0 = 45u;
    wr8(ram, object + 45u, (uint8_t)rd32(ram, state + 56u));
    r0 = rd32(ram, state + 60u);
    wr16(ram, object + 20u, (uint16_t)r0);
    return r0;
}
