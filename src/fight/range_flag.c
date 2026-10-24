/* range_flag.c - SH-4 0x8C0CAA9C: the out-of-range flag.
 *
 * The engine keeps a byte of flags beside four floats.  This function looks
 * at the four floats and sets the 0x10 bit of the byte when one of them is
 * outside the range the two bounds describe.
 *
 * The byte's own 0x40 bit says whether the floats have to be looked at at
 * all: when it is clear the function does nothing - it does not even write
 * the byte back.
 *
 * The bounds are two float constants in the literal pool, and so are the
 * offsets of the byte and of the first float, so the port reads the same
 * addresses the guest reads.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"

/* the literal pool */
#define G_BYTE  0x0c0cab1au   /* the byte's offset */
#define G_VALUE 0x0c0cab1cu   /* the first float's offset */
#define G_LIMIT 0x0c0cab20u   /* the upper bound */
#define G_FLOOR 0x0c0cab24u   /* the lower bound */

/* the byte's bit that says "look at the values" */
#define FLAG_CHECK 0x40u
/* the bit the function sets when a value is out of range */
#define FLAG_OUT   0x10u

#define R(n) s->v[(n)]

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

int vf3_range_flag_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    int out;

    /* the byte: its 0x40 bit says the values have to be looked at */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, G_BYTE);
    R(3) = FLAG_CHECK;
    R(5) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(4) + R(0));
    R(5) &= 0xffu;
    set_t(s, (R(3) & R(5)) == 0);
    if ((R(3) & R(5)) == 0) {
        /* nothing to do - the byte is not even written back */
        s->pc = R(16);
        return ram->oob == 0;
    }

    /* the four values */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, G_VALUE);
    vf3_matrix_load(s, ram, 6, R(4) + R(0));
    R(0) += 12u;
    vf3_matrix_load(s, ram, 7, R(4) + R(0));
    R(0) -= 36u;
    vf3_matrix_load(s, ram, 8, R(4) + R(0));
    R(0) += 12u;
    vf3_matrix_load(s, ram, 9, R(4) + R(0));

    /* the upper bound */
    R(0) = G_LIMIT;
    vf3_matrix_load(s, ram, 5, R(0));
    R(0) = G_FLOOR;

    /* the first comparison.  The guest loads the lower bound in the branch's
     * delay slot, so the load happens here too - after the comparison, and
     * whether the branch is taken or not */
    out = vf3_fr_get(s, 6) > vf3_fr_get(s, 5);
    set_t(s, out);
    vf3_matrix_load(s, ram, 4, R(0));

    /* and then the rest: a value is out of range when it is above the upper
     * bound or below the lower one.  The guest branches away on the first
     * one it finds, so the later comparisons do not run */
    if (!out) { out = vf3_fr_get(s, 4) > vf3_fr_get(s, 6); set_t(s, out); }
    if (!out) { out = vf3_fr_get(s, 7) > vf3_fr_get(s, 5); set_t(s, out); }
    if (!out) { out = vf3_fr_get(s, 4) > vf3_fr_get(s, 7); set_t(s, out); }
    if (!out) { out = vf3_fr_get(s, 8) > vf3_fr_get(s, 5); set_t(s, out); }
    if (!out) { out = vf3_fr_get(s, 4) > vf3_fr_get(s, 8); set_t(s, out); }
    if (!out) { out = vf3_fr_get(s, 9) > vf3_fr_get(s, 5); set_t(s, out); }
    if (!out) { out = vf3_fr_get(s, 4) > vf3_fr_get(s, 9); set_t(s, out); }

    if (out) {
        /* the flag goes on */
        R(3) = FLAG_OUT;
        R(5) |= R(3);
    } else {
        /* and off again - the guest clears the neighbouring bit as well */
        R(1) = 0xffffffefu;
        R(5) &= R(1);
    }

    /* and the byte goes back */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, G_BYTE);
    vf3_mem_set_u8(ram, R(4) + R(0), (uint8_t)R(5));

    s->pc = R(16);
    return ram->oob == 0;
}
