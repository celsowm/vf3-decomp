/* SH-4 matrix kernels used by the 09D4/09D9 families. Coefficients cover
 * every 16-bit angle through the independently captured opcode ROM. */
#include "fight/sh4_matrix.h"
#include "fight/sh4_fpu.h"

#include <fenv.h>
#include <stdint.h>
#include <string.h>

static float bits_f32(uint32_t bits)
{
    float f;
    memcpy(&f, &bits, sizeof(f));
    return f;
}

static uint32_t f32_bits(float f)
{
    uint32_t bits;
    memcpy(&bits, &f, sizeof(bits));
    return bits;
}

/* Keep each double operation materialized under the guest's RM=truncate
 * mode. The oracle's FTRV path uses double products/sums, then rounds once
 * to the single-precision destination. */
static void ftrv(float fr[16], const float xf[16], unsigned n, uint32_t fpscr)
{
    uint32_t matrix[16], vector[4], result[4];
    memcpy(matrix, xf, sizeof(matrix));
    memcpy(vector, fr + n, sizeof(vector));
    vf3_fpu_ftrv(matrix, vector, fpscr, result);
    memcpy(fr + n, result, sizeof(result));
}

static void copy_xd(uint32_t xf_out[16], const float fr[16],
                    unsigned src_pair, unsigned dst_pair)
{
    xf_out[dst_pair * 2] = f32_bits(fr[src_pair * 2]);
    xf_out[dst_pair * 2 + 1] = f32_bits(fr[src_pair * 2 + 1]);
}

static int run_helper(unsigned which, const uint32_t in[37], uint32_t out[37],
                      const uint32_t xf_in[16], uint32_t xf_out[16])
{
    uint32_t rotation[2];
    float fr[16], xf[16];

    if (!vf3_fpu_supported(in[18]) || (in[18] & 3u) != 1)
        return 0;
    vf3_fpu_fsca(in[4], rotation);
    memcpy(out, in, sizeof(uint32_t) * 37);
    memcpy(xf_out, xf_in, sizeof(uint32_t) * 16);
    for (unsigned i = 0; i < 16; ++i) {
        fr[i] = bits_f32(in[21 + i]);
        xf[i] = bits_f32(xf_in[i]);
    }

    /* FSCA FPUL,FR4. */
    fr[4] = bits_f32(rotation[0]);
    fr[5] = bits_f32(rotation[1]);

    if (which == 0) {                 /* 0x0C03C940 */
        fr[2] = 0.0f;
        fr[3] = 0.0f;
        fr[6] = 0.0f;
        fr[7] = 0.0f;
        fr[0] = fr[5];
        fr[1] = fr[4];
        fr[4] = -fr[4];
    } else if (which == 1) {          /* 0x0C03C880 */
        fr[1] = 0.0f;
        fr[3] = 0.0f;
        fr[7] = 0.0f;
        fr[0] = fr[5];
        fr[2] = fr[4];
        fr[2] = -fr[2];
        fr[6] = fr[0];
    } else {                          /* 0x0C03C6C0 */
        fr[0] = 0.0f;
        fr[3] = 0.0f;
        fr[7] = 0.0f;
        fr[1] = fr[5];
        fr[2] = fr[4];
        fr[5] = fr[2];
        fr[5] = -fr[5];
        fr[6] = fr[1];
    }

    ftrv(fr, xf, 0, in[18]);
    if (which == 0) {
        ftrv(fr, xf, 4, in[18]);
    } else if (which == 1) {
        fr[5] = 0.0f;
        ftrv(fr, xf, 4, in[18]);
    } else {
        fr[4] = 0.0f;
        ftrv(fr, xf, 4, in[18]);
    }

    for (unsigned i = 0; i < 8; ++i)
        out[21 + i] = f32_bits(fr[i]);

    /* FSCHG selects 64-bit register moves. Their cross-bank transfers write
     * these XD slots while leaving the remaining captured bank words intact. */
    if (which == 0) {
        for (unsigned p = 0; p < 4; ++p)
            copy_xd(xf_out, fr, p, p);
    } else if (which == 1) {
        copy_xd(xf_out, fr, 0, 0);
        copy_xd(xf_out, fr, 1, 1);
        copy_xd(xf_out, fr, 2, 4);
        copy_xd(xf_out, fr, 3, 5);
    } else {
        copy_xd(xf_out, fr, 0, 2);
        copy_xd(xf_out, fr, 1, 3);
        copy_xd(xf_out, fr, 2, 4);
        copy_xd(xf_out, fr, 3, 5);
    }
    return 1;
}

int vf3_sh4_c940(const uint32_t in[37], uint32_t out[37],
                 const uint32_t xf_in[16], uint32_t xf_out[16])
{
    return run_helper(0, in, out, xf_in, xf_out);
}

int vf3_sh4_c880(const uint32_t in[37], uint32_t out[37],
                 const uint32_t xf_in[16], uint32_t xf_out[16])
{
    return run_helper(1, in, out, xf_in, xf_out);
}

int vf3_sh4_c6c0(const uint32_t in[37], uint32_t out[37],
                 const uint32_t xf_in[16], uint32_t xf_out[16])
{
    return run_helper(2, in, out, xf_in, xf_out);
}

static int write_bytes(const vf3_ram_map *ram, uint32_t addr,
                       const void *src, uint32_t size)
{
    uint32_t a = addr & 0x0fffffffu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + size <= w->base + w->len) {
            memcpy(w->data + (a - w->base), src, size);
            return 1;
        }
    }
    ++m->oob;
    return 0;
}

int vf3_sh4_d452(const uint32_t in[37], uint32_t out[37],
                 const uint32_t xf_in[16], uint32_t xf_out[16],
                 const vf3_ram_map *ram)
{
    uint32_t a[37], b[37], c[37];
    uint32_t xa[16], xb[16];
    uint32_t sp = in[15];
    uint16_t half;
    int ok = 1;

    memcpy(out, in, sizeof(uint32_t) * 37);
    a[4] = in[6] & 0xffffu;
    memcpy(a, in, 4u * sizeof(uint32_t));
    memcpy(a + 5, in + 5, 32u * sizeof(uint32_t));
    if (!vf3_sh4_c940(a, b, xf_in, xa))
        return 0;

    b[4] = in[5] & 0xffffu;
    if (!vf3_sh4_c880(b, c, xa, xb))
        return 0;

    memcpy(xf_out, xb, sizeof(xb));

    /* Entry setup and saved halfwords in the 12-byte temporary frame. */
    half = (uint16_t)in[4];
    ok &= write_bytes(ram, sp - 16u, &half, sizeof(half));
    half = (uint16_t)in[5];
    ok &= write_bytes(ram, sp - 12u, &half, sizeof(half));
    half = (uint16_t)in[6];
    ok &= write_bytes(ram, sp - 8u, &half, sizeof(half));
    ok &= write_bytes(ram, sp - 4u, &in[16], sizeof(in[16]));

    /* This boundary is after the wrapper's JMP delay slot, before C6C0. */
    for (unsigned i = 21; i < 29; ++i)
        out[i] = c[i];
    out[0] = in[5];
    out[3] = 0x0c03c6c0u;
    out[4] = in[4] & 0xffffu;
    out[15] = sp;
    out[16] = in[16];
    return ok;
}

static int read_u32(const vf3_ram_map *ram, uint32_t addr, uint32_t *value)
{
    uint32_t a = addr & 0x0fffffffu;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4u <= w->base + w->len) {
            memcpy(value, w->data + (a - w->base), sizeof(*value));
            return 1;
        }
    }
    return 0;
}

/* Some helper writes land in uncaptured regions. They do not affect any
 * boundary RAM assertion, so retain only writes covered by an oracle window. */
static void write_observed(const vf3_ram_map *ram, uint32_t addr,
                           const void *src, uint32_t size)
{
    uint32_t a = addr & 0x0fffffffu;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + size <= w->base + w->len) {
            memcpy(w->data + (a - w->base), src, size);
            return;
        }
    }
}

int vf3_sh4_0955b0_step(const uint32_t in[37], uint32_t out[37],
                        const uint32_t xf_in[16], uint32_t xf_out[16],
                        const vf3_ram_map *ram, unsigned stop_step)
{
    const uint32_t queue = 0x0c19d2e4u;
    uint32_t cur[37], next[37], xf[16], xnext[16];
    uint32_t packed, ptr, stack, spill;
    int16_t low, high, incremented;
    int ok = 1;

    memcpy(cur, in, sizeof(cur));
    memcpy(xf, xf_in, sizeof(xf));
    stack = in[15] - 20u;

    /* 0x0955B0 prologue and saved argument frame. */
    write_observed(ram, in[15] - 4u, &in[16], 4);
    write_observed(ram, stack + 8u, &in[4], 4);
    write_observed(ram, stack + 4u, &in[5], 4);
    write_observed(ram, stack, &in[6], 4);
    write_observed(ram, stack + 12u, &in[7], 4);

    /* C4F0 advances the packed queue cursor, saving XF0..XF14 in the
     * upper half of the old 64-byte slot. Its optional copy branch is not
     * taken here (the caller supplies r4=0). */
    if (!read_u32(ram, queue, &packed) ||
        !read_u32(ram, queue + 8u, &ptr))
        return 0;
    low = (int16_t)(packed & 0xffffu);
    high = (int16_t)(packed >> 16);
    incremented = (int16_t)(low + 1);
    cur[0] = (uint32_t)(high > low);
    cur[1] = ptr;
    cur[2] = (uint32_t)(int32_t)high;
    cur[3] = queue;
    cur[4] = 0;
    cur[6] = (uint32_t)(int32_t)incremented;
    cur[7] = ptr + 64u;
    cur[15] = stack;
    cur[16] = 0x0c0955c2u;
    cur[17] = (in[17] & ~1u) | (uint32_t)(high > low);
    for (unsigned i = 0; i < 8; ++i) {
        const unsigned fr = 14u - i * 2u;
        write_observed(ram, ptr + 60u - i * 4u,
                       &xf[fr], sizeof(uint32_t));
    }
    packed = (packed & 0xffff0000u) | (uint16_t)incremented;
    write_observed(ram, queue, &packed, sizeof(packed));
    ptr += 64u;
    write_observed(ram, queue + 8u, &ptr, sizeof(ptr));
    if (stop_step == 1) {
        memcpy(out, cur, sizeof(cur));
        memcpy(xf_out, xf, sizeof(xf));
        return 1;
    }

    /* CCB0 seeds the active FR bank. */
    cur[2] = 0x0c03ccb0u;
    cur[16] = 0x0c0955c8u;
    cur[21] = 0x3f800000u;
    cur[22] = 0x00000000u;
    cur[23] = 0x00000000u;
    cur[24] = 0x3f800000u;
    xf[0] = 0x3f800000u;
    xf[1] = 0;
    xf[2] = 0;
    xf[4] = 0;
    xf[5] = 0x3f800000u;
    xf[6] = 0;
    xf[8] = 0;
    xf[9] = 0;
    xf[10] = 0x3f800000u;
    xf[12] = 0;
    xf[13] = 0;
    xf[14] = 0;
    if (stop_step == 2) {
        memcpy(out, cur, sizeof(cur));
        memcpy(xf_out, xf, sizeof(xf));
        return 1;
    }

    /* C940, C880, and C6C0 use the three halfwords in the saved frame. */
    if (!read_u32(ram, stack + 24u, &cur[4]))
        return 0;
    if (!vf3_sh4_c940(cur, next, xf, xnext))
        return -3;
    memcpy(cur, next, sizeof(cur));
    memcpy(xf, xnext, sizeof(xf));
    cur[3] = 0x0c03c940u;
    cur[16] = 0x0c0955ceu;
    if (stop_step == 3) {
        memcpy(out, cur, sizeof(cur));
        memcpy(xf_out, xf, sizeof(xf));
        return 1;
    }

    if (!read_u32(ram, stack + 20u, &cur[4]))
        return 0;
    if (!vf3_sh4_c880(cur, next, xf, xnext))
        return -5;
    memcpy(cur, next, sizeof(cur));
    memcpy(xf, xnext, sizeof(xf));
    cur[3] = 0x0c03c880u;
    cur[16] = 0x0c0955d4u;
    if (stop_step == 4) {
        memcpy(out, cur, sizeof(cur));
        memcpy(xf_out, xf, sizeof(xf));
        return 1;
    }

    if (!read_u32(ram, stack + 12u, &cur[4]))
        return 0;
    if (!vf3_sh4_c6c0(cur, next, xf, xnext))
        return -7;
    memcpy(cur, next, sizeof(cur));
    memcpy(xf, xnext, sizeof(xf));
    cur[3] = 0x0c03c6c0u;
    cur[16] = 0x0c0955dau;
    if (stop_step == 5) {
        memcpy(out, cur, sizeof(cur));
        memcpy(xf_out, xf, sizeof(xf));
        return 1;
    }

    /* B620 writes the XF bank into the current slot and returns its base. */
    if (!read_u32(ram, queue + 8u, &spill))
        return 0;
    spill += 64u;
    for (unsigned i = 0; i < 16; ++i)
        write_observed(ram, spill - 64u + i * 4u,
                       &xf[i], sizeof(uint32_t));
    cur[0] = spill - 64u;
    cur[2] = 0x0c03b620u;
    cur[4] = spill - 64u;
    cur[16] = 0x0c0955e0u;
    if (stop_step == 6) {
        memcpy(out, cur, sizeof(cur));
        memcpy(xf_out, xf, sizeof(xf));
        return 1;
    }

    /* Three selected vector components are copied to caller destinations. */
    cur[0] = 0x20u;
    cur[24] = xf[8];
    write_observed(ram, in[4], &cur[24], 4);
    cur[0] = 0x24u;
    cur[24] = xf[9];
    write_observed(ram, in[5], &cur[24], 4);
    cur[0] = 0x28u;
    cur[24] = xf[10];
    cur[4] = 1;
    write_observed(ram, in[6], &cur[24], 4);

    cur[3] = 0x0c03c4a0u;
    cur[15] = in[15] - 4u;
    memcpy(out, cur, sizeof(cur));
    memcpy(xf_out, xf, sizeof(xf));
    return ok;
}

int vf3_sh4_0955b0(const uint32_t in[37], uint32_t out[37],
                   const uint32_t xf_in[16], uint32_t xf_out[16],
                   const vf3_ram_map *ram)
{
    return vf3_sh4_0955b0_step(in, out, xf_in, xf_out, ram, 0);
}
