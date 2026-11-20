/* float_table.c - SH-4 0x8C06D792: a table entry, unpacked into two
 * structures, natively.
 *
 * A plain-C transcription of the readable port src/fight/float_table.c
 * (`vf3_float_table_entry`).  It operates on `vf3_native_aim`: the flat RAM,
 * the FR bank and the register file.  A self-contained leaf - it calls nobody
 * and keeps **no stack frame**, but it uses the FR bank for the entry's three
 * floats.
 *
 * The engine keeps a table of sixteen-byte entries and an index byte.  This
 * function looks an entry up and unpacks it into two structures:
 *
 *  - the entry's two halfwords - at the entry's +12 and +14 - go into the
 *    first structure, at its +32 and its +34.  Note that they are *swapped*:
 *    the halfword at the entry's +12 lands at the structure's +32 and the one
 *    at the entry's +14 lands at the structure's +34;
 *  - the entry's three floats - at the entry's +16, +20 and +24 - go into the
 *    second structure, at the offset the pool holds, at eight bytes below that
 *    offset and at four bytes below it.
 *
 * The index is the low *four* bits of the index byte, and the entries are
 * sixty-four bytes apart.  The second structure is reached through **two**
 * indirections (the pool gives a cell, the cell gives the structure), and the
 * offset is a **signed** halfword, so it can point below the structure.  The
 * pool's values are read at run time.
 *
 * See docs/re/native_float_table.md. */
#include "float_table.h"

#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

/* the literal pool */
#define G_INDEX  0x0c06d89cu   /* the address of the index byte */
#define G_TABLE  0x0c06d8a8u   /* the table */
#define G_DEST   0x0c06d8a4u   /* the first structure */
#define G_STRUCT 0x0c06d890u   /* the address of the second structure's address */
#define G_OFFSET 0x0c06d87eu   /* where the three floats land in the second structure */

/* the index is four bits */
#define INDEX_MASK 15u

/* where the entry's two halfwords land in the first structure */
#define HALFWORD_A 32u
#define HALFWORD_B 34u

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

void vf3_native_float_table(vf3_native_aim *a)
{
    /* the index byte's address */
    R(3) = vf3_aim_u32(a, G_INDEX);
    R(4) = INDEX_MASK;

    /* the table */
    R(2) = vf3_aim_u32(a, G_TABLE);

    /* the index byte, and then the byte as an unsigned one */
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(3));

    /* the first structure */
    R(7) = vf3_aim_u32(a, G_DEST);
    R(0) &= 0xffu;

    /* and the second structure's address */
    R(1) = vf3_aim_u32(a, G_STRUCT);

    /* the entry: four bits of the index, sixty-four bytes apart */
    R(4) &= R(0);
    R(4) <<= 2;
    R(4) <<= 2;
    R(4) <<= 2;
    R(4) += R(2);

    /* the entry's two halfwords */
    R(0) = (uint32_t)half(a, R(4) + 12u);
    R(6) = R(0);
    R(0) = (uint32_t)half(a, R(4) + 14u);
    R(5) = R(0);

    /* and its three floats */
    fload(a, 4, R(4) + 16u);
    fload(a, 5, R(4) + 20u);
    fload(a, 6, R(4) + 24u);

    /* the second structure */
    R(4) = vf3_aim_u32(a, R(1));

    /* the two halfwords into the first structure */
    vf3_aim_set_u16(a, R(7) + HALFWORD_B, (uint16_t)R(5));
    vf3_aim_set_u16(a, R(7) + HALFWORD_A, (uint16_t)R(6));

    /* and the three floats into the second structure */
    R(0) = (uint32_t)half(a, G_OFFSET);
    fstore(a, 4, R(4) + R(0));
    R(0) += (uint32_t)(0u - 8u);
    fstore(a, 5, R(4) + R(0));
    R(0) += 4u;
    fstore(a, 6, R(4) + R(0));
}
