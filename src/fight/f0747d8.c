/* SH-4 0x8C0747D8: accumulate two vector components and clear two fields. */
#include "fight/f0747d8.h"
#include "fight/fpu_tz.h"

#include <string.h>

static uint32_t f7_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static void f7_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t value)
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

static float f7_load(const vf3_ram_map *ram, uint32_t addr)
{
    return fpu_bits_to_f32(f7_rd32(ram, addr));
}

static void f7_store(const vf3_ram_map *ram, uint32_t addr, float value)
{
    f7_wr32(ram, addr, fpu_f32_to_bits(value));
}

static float f7_fr(const uint32_t *s, unsigned n)
{
    return fpu_bits_to_f32(s[21u + n]);
}

void vf3_f0747d8_8c0747d8(const uint32_t in[37], uint32_t out[37],
                          const vf3_ram_map *ram)
{
    uint32_t r0, r1;
    float fr2, fr3, fr4;

    memcpy(out, in, 37u * sizeof(uint32_t));
    r0 = 16;
    fr2 = f7_load(ram, in[4] + r0);
    r1 = in[4] + 0x13A8u;
    fr3 = f7_load(ram, r1);
    fr2 = fpu_dn_fix(fadd_tz(fr3, fr2), in[18]);
    f7_store(ram, in[4] + r0, fr2);

    r0 = 24;
    fr2 = f7_load(ram, in[4] + r0);
    r1 = in[4] + 0x13B0u;
    fr3 = f7_load(ram, r1);
    fr2 = fpu_dn_fix(fadd_tz(fr3, fr2), in[18]);
    f7_store(ram, in[4] + r0, fr2);

    r0 = 0x1488u;
    fr4 = 0.0f;                       /* fldi0 fr4 */
    f7_store(ram, in[4] + r0, fr4);
    r0 += 8u;
    f7_store(ram, in[4] + r0, fr4);   /* rts delay slot */

    out[0] = r0;
    out[1] = r1;
    out[21u + 2u] = fpu_f32_to_bits(fr2);
    out[21u + 3u] = fpu_f32_to_bits(fr3);
    out[21u + 4u] = fpu_f32_to_bits(fr4);
}
