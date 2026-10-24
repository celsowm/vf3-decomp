/* float_blend.c - SH-4 0x8C03E810: four floats in, one blended float out.
 *
 * The engine keeps a structure of four floats and an array of four floats, and
 * this function moves the array into the structure and then writes a weighted
 * sum over three of the four slots back into the first one.
 *
 * The structure is four slots of one float: the slot at +0, the slot at +4,
 * the slot at +8 and the slot at +12.  The array's four floats land in those
 * slots in order, and the slot at +0 is then overwritten:
 *
 *     slot0 = weight_a * slot2 + weight_b * slot1 + weight_c * slot3
 *
 * The first source float is therefore dropped: it is copied into the slot at
 * +0 and then overwritten by the blend.
 *
 * The three weights are float constants in the literal pool, at 0x8C03E8A8,
 * 0x8C03E8AC and 0x8C03E8B0, and the structure's address is the pool word at
 * 0x8C03E8A4.  The pool's values are not recoverable offline, so the port
 * reads the same addresses the guest reads.
 *
 * The blend is a multiply followed by two *fused* multiply-adds, so the port
 * cannot write it as an expression of C floats: each step rounds once, where
 * a plain expression rounds three times.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"

#define R(n) s->v[(n)]

/* the literal pool: the structure and the three weights */
#define G_DEST 0x0c03e8a4u
#define G_A    0x0c03e8a8u
#define G_B    0x0c03e8acu
#define G_C    0x0c03e8b0u

/* the frame the function pushes */
#define FRAME 8u

/* the FPSCR's double-precision bit: it makes the float loads eight bytes
 * wide and the array's step eight bytes long */
#define FPSCR_WIDE 0x100000u

/* one step along the array */
static uint32_t fstep(const vf3_matrix_state *s)
{
    return (s->v[18] & FPSCR_WIDE) ? 8u : 4u;
}

int vf3_float_blend_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* the structure */
    R(5) = vf3_mem_u32(ram, G_DEST);

    /* the first weight's address */
    R(0) = G_A;

    /* the array's first float, into the slot at +0 */
    vf3_matrix_load(s, ram, 3, R(4));
    R(4) += fstep(s);

    /* the frame: the two slot addresses the blend reads back */
    R(15) -= FRAME;

    R(6) = R(5);
    R(3) = R(6);
    vf3_matrix_store(s, ram, 3, R(6));
    R(3) = R(6) + 4u;
    R(7) = R(6) + 8u;
    R(5) = R(6) + 12u;
    vf3_mem_set_u32(ram, R(15), R(3));

    /* the array's second float, into the slot at +4 */
    vf3_matrix_load(s, ram, 3, R(4));
    R(4) += fstep(s);
    vf3_matrix_store(s, ram, 3, R(3));

    /* the array's third float, into the slot at +8 */
    vf3_matrix_load(s, ram, 3, R(4));
    R(4) += fstep(s);
    vf3_matrix_store(s, ram, 3, R(7));

    vf3_mem_set_u32(ram, R(15) + 4u, R(5));

    /* the array's fourth float, into the slot at +12 */
    vf3_matrix_load(s, ram, 3, R(4));
    vf3_matrix_store(s, ram, 3, R(5));

    /* and the blend over the three slots that are not the first */
    vf3_matrix_load(s, ram, 3, R(7));        /* FR3: the slot at +8 */
    vf3_matrix_load(s, ram, 0, R(0));        /* FR0: the first weight */
    R(0) = G_B;
    R(2) = vf3_mem_u32(ram, R(15));          /* the slot at +4 */
    vf3_fr_set(s, 3, vf3_f_mul(s, vf3_fr_get(s, 3), vf3_fr_get(s, 0)));

    vf3_matrix_load(s, ram, 0, R(0));        /* FR0: the second weight */
    vf3_matrix_load(s, ram, 2, R(2));        /* FR2: the slot at +4 */
    R(0) = G_C;
    R(3) = vf3_mem_u32(ram, R(15) + 4u);     /* the slot at +12 */
    vf3_fr_set(s, 3, vf3_f_mac(s, vf3_fr_get(s, 0), vf3_fr_get(s, 2),
                               vf3_fr_get(s, 3)));

    vf3_matrix_load(s, ram, 0, R(0));        /* FR0: the third weight */
    vf3_matrix_load(s, ram, 2, R(3));        /* FR2: the slot at +12 */
    vf3_fr_set(s, 3, vf3_f_mac(s, vf3_fr_get(s, 0), vf3_fr_get(s, 2),
                               vf3_fr_get(s, 3)));

    /* and back into the slot at +0 */
    vf3_matrix_store(s, ram, 3, R(6));

    R(15) += FRAME;
    s->pc = R(16);
    return ram->oob == 0;
}
