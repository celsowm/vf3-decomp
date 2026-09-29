/* 0x8C0CBEFC: bounded state/animation update.
 *
 * Its sole call is the SDK __divls helper with divisor four.  The helper's
 * observable operation here is signed 32-bit division; all other effects
 * are in the caller's own registers and two captured RAM windows.
 */
#include "fight/cbefc.h"
#include "fight/fpu_tz.h"

#include <string.h>

static uint32_t cb_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4u <= w->base + w->len) {
            uint32_t v;
            memcpy(&v, w->data + (canon - w->base), 4);
            return v;
        }
    }
    ++m->oob;
    return 0;
}

static void cb_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t value)
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

static int32_t cb_rd16s(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 2u <= w->base + w->len) {
            int16_t v;
            memcpy(&v, w->data + (canon - w->base), 2);
            return v;
        }
    }
    ++m->oob;
    return 0;
}

static void cb_wr16(const vf3_ram_map *ram, uint32_t addr, uint32_t value)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 2u <= w->base + w->len) {
            uint16_t v = (uint16_t)value;
            memcpy(w->data + (canon - w->base), &v, 2);
            return;
        }
    }
    ++m->oob;
}

static float cb_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    return fpu_bits_to_f32(cb_rd32(ram, addr));
}

static void cb_wrflt(const vf3_ram_map *ram, uint32_t addr, float value)
{
    cb_wr32(ram, addr, fpu_f32_to_bits(value));
}

static float cb_fr(const uint32_t *s, unsigned fr)
{
    return fpu_bits_to_f32(s[21u + fr]);
}

static void cb_setfr(uint32_t *s, unsigned fr, float value)
{
    s[21u + fr] = fpu_f32_to_bits(value);
}

void vf3_cbefc_8c0cbefc(const uint32_t in[37], uint32_t out[37],
                        const vf3_ram_map *ram)
{
    uint32_t r0, r1, r2, r3, r4, r5, r6, r14;
    uint32_t ctx, src, vec_a, vec_b, t;
    uint32_t pr = in[16], sr = in[17];
    float fr0, fr2, fr3, fr4, fr5;
    int counter_gt;
    int div_called = 0;

    memcpy(out, in, 37u * sizeof(uint32_t));
    r0 = in[0]; r1 = in[1]; r2 = in[2]; r3 = in[3];
    r4 = cb_rd32(ram, in[15] + 4u); /* mov.l @(8,r15) after PR push */
    r5 = in[5]; r6 = in[6]; r14 = in[14];
    ctx = r4; src = r5; vec_a = in[6]; vec_b = in[7];
    fr0 = cb_fr(in, 0); fr2 = cb_fr(in, 2); fr3 = cb_fr(in, 3);
    fr4 = cb_fr(in, 4); fr5 = cb_fr(in, 5);

    /* sts.l pr,@-r15; this stack word remains after the pop on return. */
    cb_wr32(ram, in[15] - 4u, pr);

    /* Copy source floats to the context scratch slots. */
    fr3 = cb_rdflt(ram, src + r0);
    cb_wrflt(ram, ctx + 24u, fr3);
    fr3 = cb_rdflt(ram, src + 20u);
    cb_wrflt(ram, ctx + 28u, fr3);
    fr3 = cb_rdflt(ram, src + 24u);
    cb_wrflt(ram, ctx + 32u, fr3);
    fr3 = cb_rdflt(ram, src + 28u);
    cb_wrflt(ram, ctx + 36u, fr3);

    /* A set bit selects 0.9 scaling and threshold 10; otherwise the taken
     * bt/s path sets threshold 4 in its delay slot. */
    if ((cb_rd32(ram, ctx + 4u) & 2u) != 0) {
        fr2 = cb_rdflt(ram, ctx + 28u);
        fr2 = fpu_dn_fix(fmul_tz(0.9f, fr2), in[18]);
        cb_wrflt(ram, ctx + 28u, fr2);
        cb_wrflt(ram, src + 20u, fr2);
        r1 = 10;
    } else {
        r1 = 4;
    }

    r3 = cb_rd32(ram, ctx + 12u);
    counter_gt = (int32_t)r3 > (int32_t)r1;
    t = counter_gt;
    /* The delayed bf/s slot clears r14 on both branch outcomes. */
    r14 = 0;
    if (!counter_gt) {
        /* bf/s to the counter updater. */
        r2 = r3 + 1u;
        cb_wr32(ram, ctx + 12u, r2);
        r0 = (uint32_t)cb_rd16s(ram, src + 2u);
        r6 = r0;
        r0 = 4;
        r1 = cb_rd32(ram, ctx + 16u); /* jsr delay slot */
        /* __divls saves r3 then r2 below the caller's PR frame.  Its pops
         * restore the registers but the stack bytes remain observable. */
        cb_wr32(ram, in[15] - 12u, 0x0C042C20u);
        cb_wr32(ram, in[15] - 8u, r2);
        r0 = (uint32_t)((int32_t)r1 / 4); /* __divls quotient */
        r1 = r0;
        div_called = 1;
        r3 = r0;
        r6 -= r3;
        t = (int32_t)r6 >= 0;
        cb_wr32(ram, ctx + 16u, r0); /* bt/s delay slot */
        if (!t) {
            r3 = cb_rd32(ram, ctx + 16u) + r6;
            r6 = r14;
            cb_wr32(ram, ctx + 16u, r3);
        }
        r0 = r6;
        cb_wr16(ram, src + 2u, r0);
        cb_wr32(ram, ctx + 20u, r14);
    } else {
        cb_wr32(ram, ctx + 16u, r14);
        if ((cb_rd32(ram, ctx + 8u) & 2u) != 0) {
            fr2 = fpu_dn_fix(fsub_tz(cb_rdflt(ram, vec_a),
                                    cb_rdflt(ram, vec_b)), in[18]);
            cb_wrflt(ram, ctx + 24u, fr2);
            fr2 = fpu_dn_fix(fsub_tz(cb_rdflt(ram, vec_a + 8u),
                                    cb_rdflt(ram, vec_b + 8u)), in[18]);
            cb_wrflt(ram, ctx + 32u, fr2);
            fr4 = cb_rdflt(ram, ctx + 24u);
            fr5 = cb_rdflt(ram, ctx + 32u);
            fr0 = fr4;
            fr3 = fr5;
            fr3 = fpu_dn_fix(fmul_tz(fr5, fr3), in[18]);
            fr3 = fpu_dn_fix(fmac_tz(fr0, fr4, fr3), in[18]);
            fr4 = fpu_bits_to_f32(0x3C23D70Au); /* literal 0.01f */
            fr5 = fr3;
            t = fr4 > fr5;
            if (!t) {
                fr3 = fpu_bits_to_f32(0x3DCCCCCCu); /* literal 0.1f */
                cb_wrflt(ram, ctx + 28u, fr3);
                r0 = 28;
                r2 = 8;
                r3 = 15;
                cb_wr32(ram, ctx + 16u, r3);
                cb_wr32(ram, ctx + 20u, r2);
                goto early_return;
            }
        } else {
            /* tst #2 sets T when the optional FPU work is disabled. */
            t = 1;
        }
        r0 = r14;
        cb_wr16(ram, src + 2u, r0);
        cb_wr32(ram, ctx + 20u, r14);
    }

    goto common_return;

early_return:
    cb_setfr(out, 2, fr2);
    cb_setfr(out, 3, fr3);
    cb_setfr(out, 4, fr4);
    cb_setfr(out, 5, fr5);
    cb_setfr(out, 0, fr0);
    out[0] = r0; out[1] = r1; out[2] = r2; out[3] = r3;
    out[4] = r4; out[5] = r5; out[6] = r6;
    out[14] = cb_rd32(ram, in[15]);
    out[15] = in[15] + 4u;
    out[16] = pr;
    out[17] = div_called ? ((sr & ~0x301u) | 0x100u | (t ? 1u : 0u))
                         : ((sr & ~1u) | (t ? 1u : 0u));
    return;

common_return:
    cb_setfr(out, 2, fr2); cb_setfr(out, 3, fr3);
    cb_setfr(out, 4, fr4); cb_setfr(out, 5, fr5);
    cb_setfr(out, 0, fr0);
    out[0] = r0; out[1] = r1; out[2] = r2; out[3] = r3;
    out[4] = r4; out[5] = r5; out[6] = r6;
    out[14] = cb_rd32(ram, in[15]);
    out[15] = in[15] + 4u;
    out[16] = pr;
    out[17] = div_called ? ((sr & ~0x301u) | 0x100u | (t ? 1u : 0u))
                         : ((sr & ~1u) | (t ? 1u : 0u));
}
