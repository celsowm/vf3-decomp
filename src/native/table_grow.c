/* table_grow.c - SH-4 0x8C044C7C: the table grower, natively.
 *
 * A plain-C transcription of the readable port src/fight/table_grow.c
 * (`vf3_table_grow_entry`).  It operates on `vf3_native_aim`: the flat RAM and
 * the register file.  A self-contained leaf - it calls nobody, uses no FPU and
 * keeps no stack frame.
 *
 * The engine keeps two arrays behind one header.  This function adds N entries
 * (r4) to them:
 *
 *  - the *first* array holds strided entries.  Its pointer moves on by the
 *    stride (the header's first word) and the new entries get the fill value
 *    out of the literal pool;
 *  - the *second* array holds plain entries.  Its count becomes N and its
 *    pointer moves on by N words.
 *
 * The header sits behind a global: the global holds the header's address and
 * the header's first word holds the base the slots are measured from.  The
 * three slots - the first array's, the fill value and the second array's - are
 * halfwords in the literal pool, so the port reads the same addresses the
 * guest reads.
 *
 * Two details the port keeps: the two indirections to the header (the global,
 * then the header's first word) are distinct accesses, and the loop's guard is
 * **signed**, so a negative count leaves the first array alone but still moves
 * the second array's pointer backwards.  The answer is 0.  The leaf touches no
 * stack.
 *
 * See docs/re/native_table_grow.md. */
#include "table_grow.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

/* the global: the header's address */
#define G_HEADER 0x0c044d44u

/* the literal pool */
#define G_SLOT0 0x0c044d16u   /* the first array's slot */
#define G_FILL  0x0c044d18u   /* the value the new entries get */
#define G_SLOT1 0x0c044d1au   /* the second array's slot */

/* the stride sits twelve bytes past the first array's slot */
#define STRIDE_OFFSET 12u

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

void vf3_native_table_grow(vf3_native_aim *a)
{
    const uint32_t count = R(4);
    uint32_t base, slot0, slot1;

    /* the header */
    R(5) = vf3_aim_u32(a, G_HEADER);
    base = vf3_aim_u32(a, R(5));
    R(3) = base;

    /* the first array: its pointer moves on by the stride */
    slot0 = vf3_aim_h16(a, G_SLOT0);
    R(0) = slot0;
    R(1) = vf3_aim_u32(a, base + slot0 + STRIDE_OFFSET);
    R(1) <<= 2;
    R(2) = vf3_aim_u32(a, base + slot0);
    R(2) += R(1);
    vf3_aim_set_u32(a, base + slot0, R(2));

    /* the new entries get the fill value.  The loop only runs when the count
     * is positive, and it counts the entries it has written */
    R(1) = vf3_aim_u32(a, R(5));
    R(7) = vf3_aim_h16(a, G_FILL);
    R(1) = vf3_aim_u32(a, R(1) + R(0));
    R(6) = 0u;
    set_t(a, (int32_t)count > 0);
    if ((int32_t)count > 0) {
        do {
            R(6) += 1u;
            vf3_aim_set_u32(a, R(1), R(7));
            set_t(a, (int32_t)R(6) >= (int32_t)count);
            R(1) += 4u;
        } while ((int32_t)R(6) < (int32_t)count);
    }

    /* the second array: the count goes in and its pointer moves on */
    slot1 = vf3_aim_h16(a, G_SLOT1);
    R(0) = slot1;
    R(2) = vf3_aim_u32(a, R(5));
    vf3_aim_set_u32(a, R(2) + R(0), R(4));
    R(0) += 4u;
    R(3) = vf3_aim_u32(a, R(5));
    R(4) <<= 2;
    R(2) = vf3_aim_u32(a, R(3) + R(0));
    R(2) += R(4);
    vf3_aim_set_u32(a, R(3) + R(0), R(2));

    R(0) = 0u;
}
