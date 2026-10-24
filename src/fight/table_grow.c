/* table_grow.c - SH-4 0x8C044C7C: the table grows by N entries.
 *
 * The engine keeps two arrays behind one header.  This function adds N
 * entries to them:
 *
 *  - the *first* array holds strided entries.  Its pointer moves on by the
 *    stride (the header's field twelve bytes past the slot) and the new
 *    entries get the fill value out of the literal pool;
 *  - the *second* array holds plain entries.  Its count becomes N and its
 *    pointer moves on by N words.
 *
 * The header sits behind a global: the global holds the header's address and
 * the header's first word holds the base the slots are measured from.  The
 * three slots - the first array's, the fill value and the second array's -
 * are offsets in the literal pool, so the port reads the same addresses the
 * guest reads.
 *
 * The answer is 0.  The function touches no stack.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the global: the header's address */
#define G_HEADER 0x0c044d44u

/* the literal pool */
#define G_SLOT0 0x0c044d16u   /* the first array's slot */
#define G_FILL  0x0c044d18u   /* the value the new entries get */
#define G_SLOT1 0x0c044d1au   /* the second array's slot */

/* the stride sits twelve bytes past the first array's slot */
#define STRIDE_OFFSET 12u

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

int vf3_table_grow_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t count = R(4);
    uint32_t base, slot0, slot1;

    /* the header */
    R(5) = vf3_mem_u32(ram, G_HEADER);
    base = vf3_mem_u32(ram, R(5));
    R(3) = base;

    /* the first array: its pointer moves on by the stride */
    slot0 = vf3_mem_u16(ram, G_SLOT0);
    R(0) = slot0;
    R(1) = vf3_mem_u32(ram, base + slot0 + STRIDE_OFFSET);
    R(1) <<= 2;
    R(2) = vf3_mem_u32(ram, base + slot0);
    R(2) += R(1);
    vf3_mem_set_u32(ram, base + slot0, R(2));

    /* the new entries get the fill value.  The loop only runs when the count
     * is positive, and it counts the entries it has written */
    R(1) = vf3_mem_u32(ram, R(5));
    R(7) = vf3_mem_u16(ram, G_FILL);
    R(1) = vf3_mem_u32(ram, R(1) + R(0));
    R(6) = 0u;
    set_t(s, (int32_t)count > 0);
    if ((int32_t)count > 0) {
        do {
            R(6) += 1u;
            vf3_mem_set_u32(ram, R(1), R(7));
            set_t(s, (int32_t)R(6) >= (int32_t)count);
            R(1) += 4u;
        } while ((int32_t)R(6) < (int32_t)count);
    }

    /* the second array: the count goes in and its pointer moves on */
    slot1 = vf3_mem_u16(ram, G_SLOT1);
    R(0) = slot1;
    R(2) = vf3_mem_u32(ram, R(5));
    vf3_mem_set_u32(ram, R(2) + R(0), R(4));
    R(0) += 4u;
    R(3) = vf3_mem_u32(ram, R(5));
    R(4) <<= 2;
    R(2) = vf3_mem_u32(ram, R(3) + R(0));
    R(2) += R(4);
    vf3_mem_set_u32(ram, R(3) + R(0), R(2));

    R(0) = 0u;
    s->pc = R(16);
    return ram->oob == 0;
}
