/* node_rotate.c - SH-4 0x8C09F83C: the fighter's nodes turned around.
 *
 * The engine keeps a fighter's nodes in an array of twelve-byte records, and
 * the root's position behind them.  This function turns the nodes around the
 * Y axis and then moves the root:
 *
 *  - seven records are walked, twelve bytes apart.  Each holds two floats,
 *    eight bytes apart, and they are rotated by the angle the caller leaves in
 *    FR4 (the cosine) and FR5 (the sine);
 *  - the root's position - three floats - then moves by the value the caller
 *    leaves in FR6.
 *
 * The rotation is the 2x2 matrix [[cos, -sin], [sin, cos]]: a record's first
 * float becomes `cos * first - sin * second` and its second becomes
 * `sin * first + cos * second`.
 *
 * The three floats of the root's position are at the record's +0x58, at the
 * offset in the literal pool and twenty-four bytes below that offset.  The
 * pool's halfword is not recoverable offline, so the port reads the same
 * address the guest reads.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"

#define R(n) s->v[(n)]

/* the literal pool: the offset of the root's second coordinate */
#define G_Y 0x0c09f8d0u

/* the root's first coordinate */
#define ROOT_X 0x58u

/* the distance between the root's second and third coordinates */
#define ROOT_STEP 24u

/* how many records the array holds */
#define NODES 7u

/* the size of one record */
#define NODE_STRIDE 12u

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

int vf3_node_rotate_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* the seven records */
    R(6) = NODES;
    R(5) = R(4);
    for (;;) {
        R(7) = R(5);
        R(7) += 8u;
        vf3_matrix_load(s, ram, 8, R(7));            /* FR8: the record's second float */
        --R(6);
        set_t(s, R(6) == 0);
        vf3_matrix_move(s, 7, 4);                    /* FR7: the cosine */
        vf3_matrix_load(s, ram, 9, R(5));            /* FR9: the record's first float */
        vf3_fr_set(s, 7, vf3_f_mul(s, vf3_fr_get(s, 7), vf3_fr_get(s, 8)));
        vf3_matrix_move(s, 2, 5);                    /* FR2: the sine */
        vf3_matrix_move(s, 3, 8);
        vf3_fr_set(s, 2, vf3_f_mul(s, vf3_fr_get(s, 2), vf3_fr_get(s, 9)));
        vf3_matrix_move(s, 8, 5);
        vf3_fr_set(s, 8, vf3_f_mul(s, vf3_fr_get(s, 8), vf3_fr_get(s, 3)));
        vf3_matrix_move(s, 3, 7);
        vf3_matrix_move(s, 0, 9);
        vf3_matrix_move(s, 7, 2);
        vf3_fr_set(s, 7, vf3_f_sub(s, vf3_fr_get(s, 7), vf3_fr_get(s, 3)));
        vf3_matrix_move(s, 2, 8);
        vf3_fr_set(s, 2, vf3_f_mac(s, vf3_fr_get(s, 0), vf3_fr_get(s, 4),
                                   vf3_fr_get(s, 2)));
        vf3_matrix_move(s, 8, 2);
        vf3_matrix_store(s, ram, 7, R(5));           /* cos * first - sin * second */
        vf3_matrix_store(s, ram, 8, R(7));           /* sin * first + cos * second */
        R(5) += NODE_STRIDE;
        if (R(6) == 0) break;
    }

    /* and the root's position moves by the caller's vector */
    R(0) = ROOT_X;
    vf3_matrix_move(s, 7, 6);                        /* FR7: the move */
    vf3_matrix_load(s, ram, 4, R(4) + R(0));         /* FR4: the first coordinate */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, G_Y);
    vf3_fr_set(s, 4, vf3_f_add(s, vf3_fr_get(s, 4), vf3_fr_get(s, 6)));
    vf3_matrix_load(s, ram, 5, R(4) + R(0));         /* FR5: the second coordinate */
    R(0) += (uint32_t)(0u - ROOT_STEP);
    vf3_matrix_load(s, ram, 3, R(4) + R(0));         /* FR3: the third coordinate */
    R(0) = ROOT_X;
    vf3_fr_set(s, 5, vf3_f_add(s, vf3_fr_get(s, 5), vf3_fr_get(s, 6)));
    vf3_matrix_store(s, ram, 4, R(4) + R(0));
    vf3_fr_set(s, 7, vf3_f_add(s, vf3_fr_get(s, 7), vf3_fr_get(s, 3)));
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, G_Y);
    vf3_matrix_store(s, ram, 5, R(4) + R(0));
    R(0) += (uint32_t)(0u - ROOT_STEP);
    vf3_matrix_store(s, ram, 7, R(4) + R(0));

    s->pc = R(16);
    return ram->oob == 0;
}
