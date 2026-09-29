#include "fight/fvecmix070852.h"
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

static float bits_float(uint32_t bits)
{
    float value;
    memcpy(&value, &bits, sizeof(value));
    return value;
}

static uint32_t float_bits(float value)
{
    uint32_t bits;
    memcpy(&bits, &value, sizeof(bits));
    return bits;
}

static float rd_float(const vf3_ram_map *ram, uint32_t addr)
{
    return bits_float(rd32(ram, addr));
}

static void wr_float(const vf3_ram_map *ram, uint32_t addr, float value)
{
    wr32(ram, addr, float_bits(value));
}

void vf3_fvecmix070852_8c070852(const uint32_t in[37], uint32_t out[37],
                                const vf3_ram_map *ram)
{
    memcpy(out, in, 37 * sizeof(*out));

    uint32_t r4 = in[4];
    uint32_t r5 = in[15];
    uint32_t r6 = in[9];
    uint32_t r13 = in[13];

    /* fmov.s fr0,@-r4. This aliases the first frame-vector lane in the
       observed calls, so the following load must see the spilled value. */
    r4 -= 4;
    wr32(ram, r4, in[21]);
    r5 += 68;

    uint32_t lane0 = rd32(ram, r5); r5 += 4;
    uint32_t src0 = rd32(ram, r6); r6 += 4;
    uint32_t lane1 = rd32(ram, r5); r5 += 4;
    uint32_t src1 = rd32(ram, r6); r6 += 4;
    uint32_t lane2 = rd32(ram, r5); r5 += 4;
    uint32_t src2 = rd32(ram, r6); r6 += 4;

    float sum0 = fadd_tz(bits_float(lane0), bits_float(src0));
    float sum1 = fadd_tz(bits_float(lane1), bits_float(src1));
    float sum2 = fadd_tz(bits_float(lane2), bits_float(src2));
    wr_float(ram, r13, sum0);
    wr_float(ram, r13 + 4, sum1);
    wr_float(ram, r13 + 8, sum2);

    out[4] = r13;
    out[5] = r5;
    out[6] = r6;
    out[21] = float_bits(sum0);
    out[22] = float_bits(sum1);
    out[23] = float_bits(sum2);
    out[24] = src0;
    out[25] = src1;
    out[26] = src2;
}
