/* scale_step.c - SH-4 0x8C0CB8AC: one step of the motion VM's scaling,
 * natively.
 *
 * A plain-C transcription of the readable port src/fight/scale_step.c
 * (`vf3_scale_step_entry`).  It operates on `vf3_native_aim`: the flat RAM,
 * the FR bank, the register file and FPUL.  A self-contained leaf - it calls
 * nobody and keeps **no stack frame**, but it uses the FR bank for the two
 * constants and the scale, and FPUL for the count.
 *
 * The motion VM keeps a mode byte and two float constants.  When the mode
 * byte (masked to four bits) says 1, this function takes the step count,
 * makes it a positive number, and scales the two constants with it:
 *
 *   result = constant_two * count + constant_one
 *
 * The result goes into the caller's structure (at its +16) and into the
 * structure the pointer at +32 of the VM's own structure names (at the offset
 * in the literal pool).
 *
 * The count is made positive and parked in FPUL, and the FPUL is what the
 * scale is taken from - the guest uses the FPU's instruction-length register
 * as a scratch word here.
 *
 * The mode byte, the VM's structure, the offset and the two constants are all
 * reached through the literal pool, so the port reads the same addresses the
 * guest reads.  The scale is a **fused** multiply-add (the guest's `fmac`
 * rounds once), so the port uses `fmaf`, not a multiply and an add.
 *
 * Two details the port has to keep: the mode byte is masked to eight then to
 * four bits before it is compared (so 17 is a step and 9 is not); and the
 * count is made positive and *that* value goes into FPUL.
 *
 * See docs/re/native_scale_step.md. */
#include "scale_step.h"

#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* the literal pool */
#define G_OFFSET 0x0c0cb9b4u   /* the offset of the second destination */
#define G_MODE   0x0c0cb9b8u   /* a pointer to the mode byte */
#define G_VM     0x0c0cb9bcu   /* a pointer to the VM's structure */
#define G_ONE    0x0c0cb9c0u   /* the first constant */
#define G_TWO    0x0c0cb9c4u   /* the second constant */

#define STEP_MODE 1u

#define COUNT_SLOT   0x44u
#define COUNT_VALUE  0x54u
#define DEST_SLOT    0x20u

#define COUNT_BIAS 60u

/* the guest's halfword: sixteen bits, sign extended */
static int32_t half(vf3_native_aim *a, uint32_t addr)
{
    return (int32_t)(int16_t)vf3_aim_h16(a, addr);
}

/* load the float at a guest address into the frame register (single width) */
static void fload(vf3_native_aim *a, unsigned n, uint32_t addr)
{
    uint32_t u = vf3_aim_u32(a, addr);
    memcpy(&F(n), &u, 4);
}

/* store the frame register to a guest address (single width) */
static void fstore(vf3_native_aim *a, unsigned n, uint32_t addr)
{
    uint32_t u;
    memcpy(&u, &F(n), 4);
    vf3_aim_set_u32(a, addr, u);
}

void vf3_native_scale_step(vf3_native_aim *a)
{
    /* the mode byte: only 1 asks for a step */
    R(3) = vf3_aim_u32(a, G_MODE);
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(3));
    R(0) &= 0xffu;
    R(0) &= 15u;
    set_t(a, R(0) == STEP_MODE);
    if (R(0) != STEP_MODE)
        return;

    /* the count, and the step it takes */
    R(6) = vf3_aim_u32(a, G_VM);
    R(0) = COUNT_SLOT;
    R(5) = vf3_aim_u32(a, R(6) + R(0));
    R(0) = COUNT_VALUE;
    R(5) = (uint32_t)half(a, R(5) + R(0));
    R(5) += (uint32_t)(0u - COUNT_BIAS);
    set_t(a, (int32_t)R(5) >= 0);
    if ((int32_t)R(5) < 0) R(5) = 0u - R(5);
    a->fpul = R(5);

    /* the two constants, and the scale */
    R(0) = G_ONE;
    fload(a, 5, R(0));
    R(0) = G_TWO;
    fload(a, 4, R(0));
    R(0) = 16u;
    F(3) = (float)(int32_t)a->fpul;
    F(0) = F(4);
    F(6) = F(3);
    F(5) = fmaf(F(0), F(6), F(5));
    F(4) = F(5);
    fstore(a, 4, R(4) + R(0));

    /* and into the structure the VM names */
    R(0) = (uint32_t)half(a, G_OFFSET);
    R(4) = vf3_aim_u32(a, R(6) + DEST_SLOT);
    fstore(a, 4, R(4) + R(0));
}
