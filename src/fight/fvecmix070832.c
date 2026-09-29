#include "fight/fvecmix070832.h"
#include "fight/fpu_tz.h"

#include <string.h>

static uint32_t rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            uint32_t value;
            memcpy(&value, w->data + canon - w->base, sizeof(value));
            return value;
        }
    }
    ++m->oob;
    return 0;
}

static void wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t value)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            memcpy(w->data + canon - w->base, &value, sizeof(value));
            return;
        }
    }
    ++m->oob;
}

static uint32_t bits(float value)
{
    uint32_t result;
    memcpy(&result, &value, sizeof(result));
    return result;
}

static float f32(uint32_t value)
{
    float result;
    memcpy(&result, &value, sizeof(result));
    return result;
}

void vf3_fvecmix070832_8c070832(const uint32_t in[37], uint32_t out[37],
                                const vf3_ram_map *ram)
{
    memcpy(out, in, 37 * sizeof(*out));

    uint32_t r4 = in[15] + 68;
    uint32_t r5 = in[15] + 56;
    uint32_t r6 = in[4] - 4;

    /* The entry spill becomes the third-vector source at r15+56. */
    wr32(ram, r6, in[21]);
    uint32_t lane0 = rd32(ram, r4); r4 += 4;
    uint32_t src0 = rd32(ram, r5); r5 += 4;
    uint32_t lane1 = rd32(ram, r4); r4 += 4;
    uint32_t src1 = rd32(ram, r5); r5 += 4;
    uint32_t lane2 = rd32(ram, r4); r4 += 4;
    uint32_t src2 = rd32(ram, r5); r5 += 4;

    float sum0 = fadd_tz(f32(lane0), f32(src0));
    float sum1 = fadd_tz(f32(lane1), f32(src1));
    float sum2 = fadd_tz(f32(lane2), f32(src2));

    /* This 32-byte fragment ends after the first two predecrement stores. */
    r4 -= 4;
    wr32(ram, r4, bits(sum2));
    r4 -= 4;
    wr32(ram, r4, bits(sum1));

    out[4] = r4;
    out[5] = r5;
    out[21] = bits(sum0);
    out[22] = bits(sum1);
    out[23] = bits(sum2);
    out[24] = src0;
    out[25] = src1;
    out[26] = src2;
}
