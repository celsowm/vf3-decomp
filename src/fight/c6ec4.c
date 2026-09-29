/* Clean C model for the flag-selected 0x8C0C6EC4 vector updates. */
#include "fight/c6ec4.h"

#include "fight/fcmpsel.h"
#include "fight/fpu_tz.h"

#include <string.h>

static uint32_t c6_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4u <= w->base + w->len) {
            uint32_t v;
            memcpy(&v, w->data + canon - w->base, sizeof(v));
            return v;
        }
    }
    m->oob++;
    return 0;
}

static uint16_t c6_rd16(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 2u <= w->base + w->len) {
            uint16_t v;
            memcpy(&v, w->data + canon - w->base, sizeof(v));
            return v;
        }
    }
    m->oob++;
    return 0;
}

static uint8_t c6_rd8(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon < w->base + w->len)
            return w->data[canon - w->base];
    }
    m->oob++;
    return 0;
}

static void c6_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4u <= w->base + w->len) {
            memcpy(w->data + canon - w->base, &v, sizeof(v));
            return;
        }
    }
    m->oob++;
}

static void c6_fcmpsel(uint32_t r[16], uint32_t fr[16], uint32_t *sr,
                       uint32_t fpscr, const vf3_ram_map *ram)
{
    vf3_fcmpsel_out o;
    (void)fpscr; /* fcmpsel uses SH-4 single-precision RM=1 operations. */
    vf3_fcmpsel_8c0c7050(*sr,
                         fpu_bits_to_f32(fr[3]),
                         fpu_bits_to_f32(fr[4]),
                         fpu_bits_to_f32(fr[5]),
                         fpu_bits_to_f32(fr[6]),
                         r[4], r[5], r[6], &o, ram);
    r[3] = o.r3;
    r[7] = o.r7;
    fr[3] = o.fr3;
    fr[4] = o.fr4;
    fr[5] = o.fr5;
    fr[6] = o.fr6;
    *sr = o.sr;
}

static void c6_call_selected(uint32_t r[16], uint32_t fr[16], uint32_t *sr,
                             uint32_t fpscr, const vf3_ram_map *ram,
                             uint32_t obj, uint32_t value_off,
                             uint32_t dest_off, uint32_t left_off,
                             uint32_t right_base)
{
    r[0] = value_off;
    fr[4] = c6_rd32(ram, obj + value_off);
    r[4] = obj + dest_off;
    r[6] = obj + left_off;
    r[5] = right_base;
    fr[5] = fr[15];                    /* bsr delay slot */
    c6_fcmpsel(r, fr, sr, fpscr, ram);
}

void vf3_c6ec4_8c0c6ec4(const uint32_t in[37], uint32_t out[37],
                        const vf3_ram_map *ram)
{
    uint32_t r[16], fr[16], pr = in[16], sr = in[17], fpscr = in[18];
    uint32_t obj = in[14], sp = in[15], flags, r12, r9, r8, r11, r10;
    uint32_t global = 0x0C2D0190u;
    uint32_t saved_fr15;

    memcpy(out, in, 37u * sizeof(uint32_t));
    memcpy(r, in, sizeof(r));
    memcpy(fr, in + 21, sizeof(fr));
    saved_fr15 = fr[15];

    /* Entry fields and the two global mode words. */
    flags = c6_rd8(ram, obj + r[0]);
    r[0] = 20u;
    fr[15] = c6_rd32(ram, obj + 20u);
    r12 = c6_rd32(ram, obj + 0x138Cu);
    r[0] = 0x138Cu;
    r[6] = c6_rd32(ram, obj);
    r[5] = global;
    sr = (r[3] & flags) == 0 ? (sr | 1u) : (sr & ~1u);
    r[4] = 1;
    c6_wr32(ram, global + 28u, (r[3] & flags) == 0 ? r[7] : r[4]);
    r[2] = 0x20000000u;
    sr = (r[2] & r[6]) == 0 ? (sr | 1u) : (sr & ~1u);
    r[9] = r12;                         /* bt/s delay slot */
    c6_wr32(ram, global + 24u, (0x20000000u & r[6]) == 0 ? r[7] : r[4]);

    r[11] = 0xE8u + r12;
    r[8] = 0x94u + r12;
    r[9] += 88u;
    r[10] = 0x13Cu;

    /* tst r13,r4; the delay slot adds r12 to r10 on either branch. */
    sr = (flags & r[4]) == 0 ? (sr | 1u) : (sr & ~1u);
    r[10] += r12;
    if ((sr & 1u) != 0) {
        /* flag bit 0 clear selects the four-slot layout. */
        r[3] = 8u;
        if ((flags & 0x08u) != 0)
            c6_call_selected(r, fr, &sr, fpscr, ram, obj,
                             0x15C4u, 0x209Cu, 0x12C8u, r[9]);
        r[2] = 0x10u;
        sr = (flags & r[2]) == 0 ? (sr | 1u) : (sr & ~1u);
        if ((sr & 1u) == 0)
            c6_call_selected(r, fr, &sr, fpscr, ram, obj,
                             0x15D8u, 0x20A8u, 0x12DCu, r[8]);
        r[2] = 0x02u;
        sr = (flags & r[2]) == 0 ? (sr | 1u) : (sr & ~1u);
        if ((sr & 1u) == 0)
            c6_call_selected(r, fr, &sr, fpscr, ram, obj,
                             0x15F4u, 0x20B4u, 0x12F8u, r[11]);
        r[2] = 0x04u;
        sr = (flags & r[2]) == 0 ? (sr | 1u) : (sr & ~1u);
        if ((sr & 1u) == 0)
            c6_call_selected(r, fr, &sr, fpscr, ram, obj,
                             0x1610u, 0x20C0u, 0x1314u, r[10]);
    } else {
        r[3] = 0x80u;
        sr = (flags & r[3]) == 0 ? (sr | 1u) : (sr & ~1u);
        if ((sr & 1u) != 0) {
            c6_call_selected(r, fr, &sr, fpscr, ram, obj,
                             0x15B0u, 0x2308u, 0x12B4u, r12 + 28u);
            c6_call_selected(r, fr, &sr, fpscr, ram, obj,
                             0x15A8u, 0x2090u, 0x12ACu, r12 + 4u);
        }
        c6_call_selected(r, fr, &sr, fpscr, ram, obj,
                         0x15C4u, 0x209Cu, 0x12C8u, r[9]);
        c6_call_selected(r, fr, &sr, fpscr, ram, obj,
                         0x15D8u, 0x20A8u, 0x12DCu, r[8]);
        r[2] = 0x40u;
        sr = (flags & r[2]) == 0 ? (sr | 1u) : (sr & ~1u);
        if ((sr & 1u) != 0) {
            c6_call_selected(r, fr, &sr, fpscr, ram, obj,
                             0x15F4u, 0x20B4u, 0x12F8u, r[11]);
            c6_call_selected(r, fr, &sr, fpscr, ram, obj,
                             0x1610u, 0x20C0u, 0x1314u, r[10]);
        }
    }

    /* Restore PR and r8-r14 through the caller-owned save area. */
    c6_wr32(ram, sp - 4u, pr);
    for (int i = 0; i < 7; i++)
        r[8 + i] = c6_rd32(ram, sp + 4u + (uint32_t)i * 4u);
    r[15] = sp + 32u;
    fr[15] = saved_fr15;
    r[17] = sr;
    r[18] = fpscr;
    for (int i = 0; i < 16; i++)
        out[21 + i] = fr[i];
    for (int i = 0; i < 16; i++)
        out[i] = r[i];
    out[16] = pr;
    out[17] = r[17];
    out[18] = r[18];
}
