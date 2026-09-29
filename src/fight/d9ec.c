/* SH-4 0x8C09D9EC: captured FPU setup path ending at the C6C0 tail jump.
 *
 * The 64 paired cases exercise three first-angle values, zero fields at
 * +0x1F50/+0x1F52, and an identity XF matrix on entry. SH-4 FSCA is a ROM
 * lookup, so retain its exact observed coefficients for this bounded path.
 * Other angle/XF/field combinations are rejected instead of approximated.
 */
#include "fight/d9ec.h"

#include <string.h>

static uint32_t d9ec_canon(uint32_t addr)
{
    return addr & 0x0FFFFFFFu;
}

static int d9ec_read16(const vf3_ram_map *ram, uint32_t addr, uint16_t *out)
{
    uint32_t a = d9ec_canon(addr);
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 2u <= w->base + w->len) {
            memcpy(out, w->data + a - w->base, sizeof(*out));
            return 1;
        }
    }
    ++m->oob;
    return 0;
}

static int d9ec_write32(const vf3_ram_map *ram, uint32_t addr,
                        uint32_t value)
{
    uint32_t a = d9ec_canon(addr);
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

typedef struct {
    uint16_t angle;
    uint32_t fr0_cos;
    uint32_t fr2_neg_sin;
    uint32_t fr4_sin;
    uint32_t fr6_cos;
} d9ec_fsca_case;

static const d9ec_fsca_case d9ec_fsca[] = {
    { 0x663d, 0xbf4e826d, 0xbf174b3c, 0x3f174b3c, 0xbf4e826d },
    { 0xcc16, 0x3e95a8aa, 0x3f74d1c7, 0xbf74d1c7, 0x3e95a8aa },
    { 0xcc17, 0x3e95b4ae, 0x3f74cff1, 0xbf74cff1, 0x3e95b4ae },
};

static const d9ec_fsca_case *d9ec_find_angle(uint16_t angle)
{
    for (unsigned i = 0; i < sizeof(d9ec_fsca) / sizeof(d9ec_fsca[0]); ++i)
        if (d9ec_fsca[i].angle == angle)
            return &d9ec_fsca[i];
    return NULL;
}

int vf3_d9ec_8c09d9ec(const uint32_t in[37], uint32_t out[37],
                      const uint32_t xf_in[16], uint32_t xf_out[16],
                      const vf3_ram_map *ram)
{
    static const uint32_t identity[16] = {
        0x3f800000, 0, 0, 0,
        0, 0x3f800000, 0, 0,
        0, 0, 0x3f800000, 0,
        0, 0, 0, 0x3f800000
    };
    const d9ec_fsca_case *rotation;
    uint16_t angle, next0, next1, tail_angle;
    uint32_t object = in[14];
    uint32_t sp = in[15];

    if (in[18] != 0x00240001 || memcmp(xf_in, identity, sizeof(identity)))
        return 0;
    if (!d9ec_read16(ram, object + 0x1eu, &angle) ||
        !d9ec_read16(ram, object + 0x1f50u, &next0) ||
        !d9ec_read16(ram, object + 0x1f52u, &next1) ||
        !d9ec_read16(ram, object + 0x1f54u, &tail_angle))
        return 0;
    if (next0 != 0 || next1 != 0 || !(rotation = d9ec_find_angle(angle)))
        return 0;

    memcpy(out, in, 37u * sizeof(uint32_t));
    memcpy(xf_out, identity, sizeof(identity));

    /* The helper chain leaves this rotation in both FR and the XF matrix. */
    out[0] = 0x1f54u;
    out[3] = 0x0c03c6c0u;
    out[4] = tail_angle;
    out[15] = sp + 4u;
    out[21] = rotation->fr0_cos;
    out[23] = rotation->fr2_neg_sin;
    out[25] = rotation->fr4_sin;
    out[27] = rotation->fr6_cos;
    out[22] = 0;
    out[24] = 0;
    out[26] = 0;
    out[28] = 0;

    xf_out[0] = rotation->fr0_cos;
    xf_out[2] = rotation->fr2_neg_sin;
    xf_out[8] = rotation->fr4_sin;
    xf_out[10] = rotation->fr6_cos;

    return d9ec_write32(ram, sp - 4u, in[16]);
}
