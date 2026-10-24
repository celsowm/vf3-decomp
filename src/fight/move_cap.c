/* move_cap.c - SH-4 0x8C08DD5C: the movement, capped at the maximum step.
 *
 * The function knows two positions: the one the object had at the start of the
 * frame (r4 and r5) and the one it has now (the two words r6 and r7 point at).
 * It moves the current position by the difference between them - but never by
 * more than the longest movement the literal pool holds.
 *
 *   dx = current.x - old.x        dy = current.y - old.y
 *   len = sqrt(dx*dx + dy*dy)
 *   if len is shorter than the maximum step, the whole difference is used;
 *   otherwise the difference is scaled down to the maximum step.
 *
 * The scaled difference is truncated to integers, and the truncated pair is
 * added to the old position, so the new position is written back to the two
 * words r6 and r7 point at.
 *
 * It is the two-dimensional sibling of `aim_step` (0x8C093768), which does the
 * same for three dimensions and takes its step length from a context instead
 * of the pool.
 *
 * Three details the port has to keep: the length comes from `fsrra`, the SH-4's
 * *approximate* reciprocal of the square root, so the port has to use the same
 * helper and not 1/sqrt in C; the factor is compared as an absolute value,
 * which the guest does by masking the sign bit off the float's bits; and the
 * guest only truncates the difference when it scales it, so a movement that is
 * short enough keeps the *integer* difference.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

/* the literal pool */
#define POOL_EPSILON 0x0c08ddc8u   /* the squared length the guest will not measure */
#define POOL_MAXSTEP 0x0c08ddccu   /* the longest movement the function allows */

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

int vf3_move_cap_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = R(15);

    /* the guest saves r14 and reserves eight bytes */
    vf3_mem_set_u32(ram, sp - 4u, R(14));
    R(15) = sp - 12u;

    /* the current position, and the difference since the old one */
    R(3) = vf3_mem_u32(ram, R(6));
    vf3_mem_set_u32(ram, R(15) + 4u, R(3));
    R(2) = vf3_mem_u32(ram, R(7));
    R(1) = R(2);
    R(1) -= R(5);
    vf3_mem_set_u32(ram, R(15), R(2));
    R(14) = vf3_mem_u32(ram, R(15) + 4u);
    R(14) -= R(4);

    /* the difference as two floats */
    R(VF3_REG_FPUL) = R(14);
    F(3) = vf3_fpu_float(R(VF3_REG_FPUL), R(VF3_REG_FPSCR));
    R(VF3_REG_FPUL) = R(1);
    F(2) = vf3_fpu_float(R(VF3_REG_FPUL), R(VF3_REG_FPSCR));

    /* the squared length of the difference */
    vf3_matrix_move(s, 4, 3);
    vf3_matrix_move(s, 5, 3);
    F(4) = vf3_fpu_binary(F(4), F(5), R(VF3_REG_FPSCR), '*');
    vf3_matrix_load(s, ram, 3, POOL_EPSILON);
    vf3_matrix_move(s, 0, 2);
    vf3_matrix_move(s, 6, 2);
    F(4) = vf3_fpu_mac(F(0), F(6), F(4), R(VF3_REG_FPSCR));
    vf3_matrix_move(s, 7, 4);

    /* the inverse length - unless the difference is too short to measure, and
     * then the guest leaves it at zero */
    const int too_short = (fl(s, 3) > fl(s, 7));
    set_t(s, too_short);
    if (too_short) {
        F(7) = 0;
    } else if (!vf3_fpu_fsrra(F(7), R(VF3_REG_FPSCR), &F(7))) {
        return 0;
    }

    /* the squared length times the inverse length: the length */
    F(4) = vf3_fpu_binary(F(4), F(7), R(VF3_REG_FPSCR), '*');

    /* the factor the difference is scaled by */
    R(0) = POOL_MAXSTEP;
    vf3_matrix_load(s, ram, 7, POOL_MAXSTEP);
    vf3_matrix_move(s, 3, 4);
    vf3_matrix_move(s, 4, 7);
    F(4) = vf3_fpu_binary(F(4), F(3), R(VF3_REG_FPSCR), '/');

    /* and whether the movement has to be scaled at all: the factor has to be
     * below one, and the guest compares its absolute value */
    F(7) = 0x3f800000u;                 /* one */
    F(4) &= 0x7fffffffu;                /* fabs, as a mask on the bits */
    const int scale = (fl(s, 7) > fl(s, 4));
    set_t(s, scale);
    if (scale) {
        F(5) = vf3_fpu_binary(F(5), F(4), R(VF3_REG_FPSCR), '*');
        F(6) = vf3_fpu_binary(F(6), F(4), R(VF3_REG_FPSCR), '*');
        R(VF3_REG_FPUL) = (uint32_t)vf3_f_trunc(fl(s, 5));
        R(14) = R(VF3_REG_FPUL);
        R(VF3_REG_FPUL) = (uint32_t)vf3_f_trunc(fl(s, 6));
        R(1) = R(VF3_REG_FPUL);
    }

    /* the new position: the old one plus the movement */
    R(4) += R(14);
    vf3_mem_set_u32(ram, R(15), R(4));
    R(4) = R(5);
    R(3) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    R(4) += R(1);
    R(15) += 4u;
    vf3_mem_set_u32(ram, R(6), R(3));
    vf3_mem_set_u32(ram, R(7), R(4));

    /* and the saved register goes back */
    R(14) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;

    s->pc = R(VF3_REG_PR);
    return ram->oob == 0;
}
