/* scale_step.c - SH-4 0x8C0CB8AC: one step of the motion VM's scaling.
 *
 * The motion VM keeps a mode byte and two float constants.  When the mode
 * byte says 1, this function takes the step count, makes it a positive
 * number, and scales the two constants with it:
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
 * guest reads.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"

#define R(n) s->v[(n)]

/* the literal pool */
#define G_OFFSET 0x0c0cb9b4u   /* the offset of the second destination */
#define G_MODE   0x0c0cb9b8u   /* a pointer to the mode byte */
#define G_VM     0x0c0cb9bcu   /* a pointer to the VM's structure */
#define G_ONE    0x0c0cb9c0u   /* the first constant */
#define G_TWO    0x0c0cb9c4u   /* the second constant */

/* the mode that asks for a step */
#define STEP_MODE 1u

/* where the VM's structure keeps the count and the second destination */
#define COUNT_SLOT   0x44u
#define COUNT_VALUE  0x54u
#define DEST_SLOT    0x20u

/* the count is scaled down before it is used */
#define COUNT_BIAS 60u

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

int vf3_scale_step_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* the mode byte: only 1 asks for a step */
    R(3) = vf3_mem_u32(ram, G_MODE);
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(3));
    R(0) &= 0xffu;
    R(0) &= 15u;
    set_t(s, R(0) == STEP_MODE);
    if (R(0) != STEP_MODE) {
        s->pc = R(16);
        return ram->oob == 0;
    }

    /* the count, and the step it takes */
    R(6) = vf3_mem_u32(ram, G_VM);
    R(0) = COUNT_SLOT;
    R(5) = vf3_mem_u32(ram, R(6) + R(0));
    R(0) = COUNT_VALUE;
    R(5) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(5) + R(0));
    R(5) += (uint32_t)(0u - COUNT_BIAS);
    set_t(s, (int32_t)R(5) >= 0);
    if ((int32_t)R(5) < 0) R(5) = 0u - R(5);
    R(53) = R(5);

    /* the two constants, and the scale */
    R(0) = G_ONE;
    vf3_matrix_load(s, ram, 5, R(0));
    R(0) = G_TWO;
    vf3_matrix_load(s, ram, 4, R(0));
    R(0) = 16u;
    vf3_fr_set(s, 3, vf3_f_from_int(s, (int32_t)R(53)));
    vf3_matrix_move(s, 0, 4);
    vf3_matrix_move(s, 6, 3);
    vf3_fr_set(s, 5, vf3_f_mac(s, vf3_fr_get(s, 0), vf3_fr_get(s, 6),
                               vf3_fr_get(s, 5)));
    vf3_matrix_move(s, 4, 5);
    vf3_matrix_store(s, ram, 4, R(4) + R(0));

    /* and into the structure the VM names */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, G_OFFSET);
    R(4) = vf3_mem_u32(ram, R(6) + DEST_SLOT);
    vf3_matrix_store(s, ram, 4, R(4) + R(0));

    s->pc = R(16);
    return ram->oob == 0;
}
