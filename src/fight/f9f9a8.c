/* SH-4 0x8C09F9A8: signed guard and captured FPU continuation. */
#include "fight/f9f9a8.h"
#include "fight/f9f354.h"
#include "fight/fpu_tz.h"

#include <string.h>

static int f9f9a8_write32(const vf3_ram_map *ram, uint32_t addr,
                          uint32_t value)
{
    uint32_t a = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4u <= w->base + w->len) {
            memcpy(w->data + (a - w->base), &value, sizeof(value));
            return 1;
        }
    }
    ++m->oob;
    return 0;
}

int vf3_f9f9a8(const uint32_t in[37], uint32_t out[37],
               const vf3_ram_map *ram)
{
    uint32_t masked = in[5] & in[2];
    if ((int32_t)masked <= (int32_t)in[4]) {
        uint32_t helper_in[37], helper_out[37];
        uint32_t step = (in[6] & 0xFFFFu) << 8;
        uint32_t denominator = in[4] - step;
        uint32_t numerator = masked - step;
        float den_f, num_f;

        if (in[18] != 0x00240001u || denominator == 0)
            return -1;
        den_f = (float)(int32_t)denominator;
        num_f = (float)(int32_t)numerator;
        memcpy(helper_in, in, sizeof(helper_in));
        helper_in[4] = in[14] + 0x1D04u;
        helper_in[5] = in[14] + 0x1E00u;
        helper_in[6] = step;
        helper_in[15] = in[15] - 4u;
        helper_in[16] = 0x8C09F9CEu;
        helper_in[24] = fpu_f32_to_bits(den_f); /* fr3 */
        helper_in[23] = fpu_f32_to_bits(num_f); /* fr2 */
        helper_in[25] = fpu_f32_to_bits(
            fdiv_tz(num_f, den_f));             /* fr4 */
        helper_in[26] = fpu_f32_to_bits(num_f); /* fr5 */
        if (!f9f9a8_write32(ram, in[15] - 4u, in[16]) ||
            !vf3_f9f354(helper_in, helper_out, ram))
            return 0;
        memcpy(out, helper_out, sizeof(helper_out));
        out[14] = in[14]; /* caller's saved r14 is restored in rts delay */
        out[15] = in[15] + 4u;
        out[16] = in[16]; /* lds.l restores caller PR */
        return 1;
    }

    memcpy(out, in, 37u * sizeof(uint32_t));
    out[5] = masked;
    out[6] = in[6] << 8;      /* bt/s delay slot */
    out[15] = in[15] + 4u;
    out[17] = in[17] | 1u;   /* cmp/gt sets T on this branch */
    return f9f9a8_write32(ram, in[15] - 4u, in[16]);
}
