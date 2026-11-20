/* range_flag.c - SH-4 0x8C0CAA9C: the out-of-range flag, natively.
 *
 * A plain-C transcription of the readable port src/fight/range_flag.c
 * (`vf3_range_flag_entry`).  It operates on `vf3_native_aim`: the flat RAM,
 * the FR bank and the register file.  A self-contained leaf - it calls nobody
 * and keeps **no stack frame**, but it uses the FR bank for the four values
 * and the two bounds.
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
 *
 * Detail the port has to keep: the end of the comparison chain has **two
 * arms and they are not symmetric** - the arm that is left is the "everything
 * is inside" one, and it clears the flag with a *mask* (`& 0xffffffef`, which
 * takes the neighbouring bit with it) rather than by writing a zero; and the
 * comparisons **short-circuit**, so the T bit the guest leaves behind is the
 * one of the last comparison it actually reached.
 *
 * See docs/re/native_range_flag.md. */
#include "range_flag.h"

#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* the literal pool */
#define G_BYTE  0x0c0cab1au   /* the byte's offset */
#define G_VALUE 0x0c0cab1cu   /* the first float's offset */
#define G_LIMIT 0x0c0cab20u   /* the upper bound */
#define G_FLOOR 0x0c0cab24u   /* the lower bound */

#define FLAG_CHECK 0x40u
#define FLAG_OUT   0x10u

/* load the float at a guest address into the frame register (single width) */
static void fload(vf3_native_aim *a, unsigned n, uint32_t addr)
{
    uint32_t u = vf3_aim_u32(a, addr);
    memcpy(&F(n), &u, 4);
}

void vf3_native_range_flag(vf3_native_aim *a)
{
    int out;

    /* the byte: its 0x40 bit says the values have to be looked at */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, G_BYTE);
    R(3) = FLAG_CHECK;
    R(5) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(4) + R(0));
    R(5) &= 0xffu;
    set_t(a, (R(3) & R(5)) == 0);
    if ((R(3) & R(5)) == 0)
        return;                      /* the byte is not even written back */

    /* the four values */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, G_VALUE);
    fload(a, 6, R(4) + R(0));
    R(0) += 12u;
    fload(a, 7, R(4) + R(0));
    R(0) -= 36u;
    fload(a, 8, R(4) + R(0));
    R(0) += 12u;
    fload(a, 9, R(4) + R(0));

    /* the upper bound */
    R(0) = G_LIMIT;
    fload(a, 5, R(0));
    R(0) = G_FLOOR;

    /* the first comparison.  The guest loads the lower bound in the branch's
     * delay slot, so the load happens here too - after the comparison, and
     * whether the branch is taken or not */
    out = F(6) > F(5);
    set_t(a, out);
    fload(a, 4, R(0));

    /* and then the rest: a value is out of range when it is above the upper
     * bound or below the lower one.  The guest branches away on the first
     * one it finds, so the later comparisons do not run */
    if (!out) { out = F(4) > F(6); set_t(a, out); }
    if (!out) { out = F(7) > F(5); set_t(a, out); }
    if (!out) { out = F(4) > F(7); set_t(a, out); }
    if (!out) { out = F(8) > F(5); set_t(a, out); }
    if (!out) { out = F(4) > F(8); set_t(a, out); }
    if (!out) { out = F(9) > F(5); set_t(a, out); }
    if (!out) { out = F(4) > F(9); set_t(a, out); }

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
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, G_BYTE);
    ((uint8_t *)a->ram)[(R(4) + R(0)) - a->ram_base] = (uint8_t)R(5);
}
