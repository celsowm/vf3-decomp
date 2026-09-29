/* Clean C model for the 0x8C0B10AA shape update and flag cleanup. */
#include "fight/b10aa.h"

#include "fight/fpucb.h"
#include "fight/fpu_tz.h"

#include <string.h>

static uint32_t b10_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static uint16_t b10_rd16(const vf3_ram_map *ram, uint32_t addr)
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

static uint8_t b10_rd8(const vf3_ram_map *ram, uint32_t addr)
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

static void b10_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
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

static float b10_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    return fpu_bits_to_f32(b10_rd32(ram, addr));
}

static void b10_wrflt(const vf3_ram_map *ram, uint32_t addr, float f)
{
    b10_wr32(ram, addr, fpu_f32_to_bits(f));
}

void vf3_b10aa_8c0b10aa(const uint32_t in[37], uint32_t out[37],
                        const vf3_ram_map *ram)
{
    uint32_t r[37], entry_sp = in[15], obj = in[4];
    uint32_t sp = entry_sp - 20u;
    uint32_t p5, p6, mask, r0;
    float fr2, fr3, fr4, fr5;

    memcpy(r, in, sizeof(r));
    b10_wr32(ram, entry_sp - 4u, in[16]);           /* save PR */
    b10_wr32(ram, sp + 8u, in[5]);                 /* save r5 */
    b10_wr32(ram, sp + 12u, in[6]);                /* save r6 */

    p5 = b10_rd32(ram, sp + 8u);
    r[1] = b10_rd32(ram, p5);
    if ((r[1] & 0x20000000u) != 0) {
        /* The captured path clears the selected vector fields and flags. */
        obj = in[4];
        if ((b10_rd8(ram, obj + 0x1A2Du) & 1u) == 0) {
            uint32_t arg4 = (uint32_t)(int32_t)(int16_t)b10_rd16(
                ram, obj + 0x1Eu);
            vf3_fpucb_out cb;
            float fr15 = fpu_bits_to_f32(in[36]);

            /* Two helper inputs are staged in the caller's local frame. */
            b10_wrflt(ram, sp, b10_rdflt(ram, obj + 0x1D04u));
            b10_wrflt(ram, sp + 4u, b10_rdflt(ram, obj + 0x1D0Cu));
            vf3_fpucb_8c09553c(r[1], arg4, sp, sp + 4u, obj, sp,
                               0x0C0B10E4u, r[17] | 1u, r[18], fr15,
                               &cb, ram);
            r[0] = cb.r0; r[1] = cb.r1; r[2] = cb.r2; r[3] = cb.r3;
            r[4] = cb.r4; r[5] = cb.r5; r[6] = cb.r6; r[15] = cb.r15;
            r[17] = cb.sr;
            r[21] = cb.fr0; r[22] = cb.fr1; r[23] = cb.fr2;
            r[24] = cb.fr3; r[25] = cb.fr4; r[26] = cb.fr5;
            r[27] = cb.fr6; r[28] = cb.fr7; r[36] = cb.fr15;

            /* The callback returns to 10E4; finish its caller FPU updates. */
            fr3 = b10_rdflt(ram, sp);
            fr4 = b10_rdflt(ram, obj + 16u);
            fr5 = b10_rdflt(ram, obj + 24u);
            fr2 = b10_rdflt(ram, sp + 4u);
            fr4 = fpu_dn_fix(fsub_tz(fr4, fr3), r[18]);
            fr5 = fpu_dn_fix(fsub_tz(fr5, fr2), r[18]);
            b10_wrflt(ram, obj + 16u, fr4);
            b10_wrflt(ram, obj + 24u, fr5);
            r[25] = fpu_f32_to_bits(fr4);
            r[26] = fpu_f32_to_bits(fr5);
        }

        fr3 = b10_rdflt(ram, obj + 0x434u);
        b10_wrflt(ram, sp, fr3);
        fr3 = b10_rdflt(ram, obj + 20u);
        b10_wrflt(ram, sp + 4u, fr3);
        fr2 = b10_rdflt(ram, sp);
        fr2 = fpu_dn_fix(fsub_tz(fr2, fr3), r[18]);
        b10_wrflt(ram, sp, fr2);
        fr3 = fr2;
        b10_wrflt(ram, obj + 0x1D08u, fr3);
        r[23] = fpu_f32_to_bits(fr2);
        r[24] = fpu_f32_to_bits(fr3);

        p5 = b10_rd32(ram, sp + 8u);
        r[2] = 0xDFFFFFFFu;
        r[1] = b10_rd32(ram, p5) & r[2];
        b10_wr32(ram, p5, r[1]);
        p6 = b10_rd32(ram, sp + 12u);
        r[3] = p6;
        r[1] = 0xF7FFFFFFu;
        r0 = b10_rd32(ram, p6) & r[1];
        b10_wr32(ram, p6, r0);
        r[0] = r0;
    }

    /* add #16,r15; lds.l @r15+,pr; rts delay: pop caller's r14. */
    r[15] = sp + 16u;
    r[16] = b10_rd32(ram, r[15]);
    r[15] += 4u;
    r[14] = b10_rd32(ram, r[15]);
    r[15] += 4u;
    memcpy(out, r, sizeof(r));
}
