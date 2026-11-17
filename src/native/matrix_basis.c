/* Native port of 0x8C09E4C8 (matrix_basis): build the camera basis of a
 * record (r4) from its two angle shorts and publish the resulting axis
 * vectors.
 *
 * The guest runs on XMTRX with f = sp - 112.  In order:
 *   1. rotate_euler (0x8C09D480) on record+0x1F86, then rotate_z by the
 *      angle table entry 0x0C10DAEA[byte +0x61], rotate_y by the short at
 *      +0x22BC and rotate_z by minus the short at +0x22BE.
 *   2. matrix_store XMTRX at f+12; its columns are published to the
 *      destination block (rows to dest+0x10/+0x20, the negated second column
 *      to dest+0, the third to dest+0x20) and copied to record+0x440.
 *   3. record+0x22C0..0x22C8 = f[+60..] + 0.25 * row0 (a fused mac), then
 *      XMTRX is reloaded from the rearranged f+12 block and the two points
 *      (0.1, 0, ±0.2) at f+88..f+96 are pushed / xformed / popped into
 *      record+0x22CC..+0x22E4 for each sign.
 *
 * See docs/re/motion_row0.md and the readable port src/fight/matrix_basis.c. */
#include "pose_callees.h"

#include <math.h>
#include <stdint.h>
#include <string.h>

static uint32_t sext16(uint32_t v) { return (uint32_t)(int32_t)(int16_t)v; }

static void wf(vf3_native_aim *a, uint32_t addr, float v)
{
    uint32_t u;
    memcpy(&u, &v, 4);
    vf3_aim_set_u32(a, addr, u);
}

#define S16(hw) ((uint32_t)(int32_t)(int16_t)(hw))

void vf3_native_matrix_basis(vf3_native_aim *a, uint32_t sp, uint32_t record,
                             uint32_t block)
{
    const int saved14 = 0, saved13 = 0;   /* (kept only for the frame layout) */
    uint32_t f = sp - 112u;
    vf3_aim_set_u32(a, sp - 4u, a->r[14]);
    vf3_aim_set_u32(a, sp - 8u, a->r[13]);
    vf3_aim_set_u32(a, sp - 12u, (a->pr & 0x0FFFFFFFu) | 0x8C000000u);
    a->r[15] = f;

    /* 1. the angle rotations */
    vf3_aim_rotate_euler(a, record + 0x1F86u);
    {
        uint32_t ang = S16(vf3_aim_h16(a, 0x0C10DAEAu +
                                       ((uint32_t)(vf3_aim_u8(a, record + 0x61u) << 1))));
        vf3_aim_rotate_z_angle(a, (uint16_t)ang);
    }
    vf3_aim_rotate_y_angle(a, (uint16_t)S16(vf3_aim_h16(a, record + 0x22BCu)));
    {
        uint32_t ang = 0u - S16(vf3_aim_h16(a, record + 0x22BEu));
        vf3_aim_rotate_z_angle(a, (uint16_t)ang);
    }

    /* the entry XMTRX */
    float xm[16];
    for (int i = 0; i < 16; ++i) xm[i] = a->xm[i];

    /* 2. matrix_store XMTRX at f+12, then publish columns */
    vf3_aim_store(a, f + 12u);                        /* f+12..f+72 = xm */
    /* dest+16..+24 = row0, free-floats to f+0..+8 */
    wf(a, block + 16u, xm[0]); wf(a, block + 20u, xm[1]); wf(a, block + 24u, xm[2]);
    wf(a, f + 0u, xm[0]);     wf(a, f + 4u, xm[1]);   wf(a, f + 8u, xm[2]);
    /* dest+32..+40 = the third column */
    wf(a, block + 32u, xm[8]); wf(a, block + 36u, xm[9]); wf(a, block + 40u, xm[10]);
    /* f+12..+20 = negated second column, then dest+0..+8 = that */
    wf(a, f + 12u, -xm[4]); wf(a, f + 16u, -xm[5]);   wf(a, f + 20u, -xm[6]);
    wf(a, block + 0u, -xm[4]); wf(a, block + 4u, -xm[5]); wf(a, block + 8u, -xm[6]);
    /* f+28..+36 = the first column (copied from f+0..+8) */
    wf(a, f + 28u, xm[0]); wf(a, f + 32u, xm[1]);     wf(a, f + 36u, xm[2]);

    /* matrix_copy src = block, dst = record + 0x440 */
    vf3_aim_copy(a, record + 0x440u, block);

    /* 3. the fused mac: record+0x22C0.. = f[+60..] + 0.25 * row0 (the negated
     * second column is what now lives at f+12/16/20) */
    wf(a, record + 0x22C0u, fmaf(0.25f, -xm[4], xm[12]));
    wf(a, record + 0x22C4u, fmaf(0.25f, -xm[5], xm[13]));
    wf(a, record + 0x22C8u, fmaf(0.25f, -xm[6], xm[14]));

    /* the two points to rotate; XMTRX is reloaded from the rearranged block
     * (columns 0/1 swapped, column 0 negated) before they are pushed */
    wf(a, f + 88u, 0.1f); wf(a, f + 92u, 0.0f);       wf(a, f + 96u, 0.2f);
    /* rebuild a->xm from the rearranged f+12 block (this M' stays as the
     * XMTRX for both xforms and for the exit, as the guest keeps it) */
    for (int i = 0; i < 16; ++i)
        a->xm[i] = ((float *)vf3_aim_p(a, f + 12u))[i];

    /* first sign: +0.2 */
    vf3_aim_push(a, 0);
    vf3_aim_xform_point(a, f + 88u, f + 76u);
    vf3_aim_pop(a);
    wf(a, record + 0x22CCu, ((float *)vf3_aim_p(a, f + 76u))[0]);
    wf(a, record + 0x22D0u, ((float *)vf3_aim_p(a, f + 80u))[0]);
    wf(a, record + 0x22D4u, ((float *)vf3_aim_p(a, f + 84u))[0]);

    /* second sign: -0.2 */
    wf(a, f + 96u, -0.2f);
    vf3_aim_push(a, 0);
    vf3_aim_xform_point(a, f + 88u, f + 76u);
    vf3_aim_pop(a);
    wf(a, record + 0x22D8u, ((float *)vf3_aim_p(a, f + 76u))[0]);
    wf(a, record + 0x22DCu, ((float *)vf3_aim_p(a, f + 80u))[0]);
    wf(a, record + 0x22E0u, ((float *)vf3_aim_p(a, f + 84u))[0]);

    (void)saved14; (void)saved13;
    a->r[14] = vf3_aim_u32(a, sp - 4u);
    a->r[13] = vf3_aim_u32(a, sp - 8u);
    a->r[15] = sp;
    /* pr is unchanged (the original, restored as the guest does) */
}
