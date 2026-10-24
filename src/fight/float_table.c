/* float_table.c - SH-4 0x8C06D792: a table entry, unpacked into two structures.
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
 * sixty-four bytes apart.  Each entry holds its two halfwords at its +12 and
 * +14 and its three floats at its +16, +20 and +24.
 *
 * The pool's values are not recoverable offline, so the port reads the same
 * addresses the guest reads.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"

#define R(n) s->v[(n)]

/* the literal pool */
#define G_INDEX  0x0c06d89cu   /* the address of the index byte */
#define G_TABLE  0x0c06d8a8u   /* the table */
#define G_DEST   0x0c06d8a4u   /* the first structure */
#define G_STRUCT 0x0c06d890u   /* the address of the second structure's address */
#define G_OFFSET 0x0c06d87eu   /* where the three floats land in the second structure */

/* the index is four bits */
#define INDEX_MASK 15u

/* the table's entries are sixty-four bytes apart */
#define ENTRY_STRIDE 64u

/* where the entry's two halfwords land in the first structure */
#define HALFWORD_A 32u
#define HALFWORD_B 34u

int vf3_float_table_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* the index byte's address */
    R(3) = vf3_mem_u32(ram, G_INDEX);
    R(4) = INDEX_MASK;

    /* the table */
    R(2) = vf3_mem_u32(ram, G_TABLE);

    /* the index byte, and then the byte as an unsigned one */
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(3));

    /* the first structure */
    R(7) = vf3_mem_u32(ram, G_DEST);
    R(0) &= 0xffu;

    /* and the second structure's address */
    R(1) = vf3_mem_u32(ram, G_STRUCT);

    /* the entry: four bits of the index, sixty-four bytes apart */
    R(4) &= R(0);
    R(4) <<= 2;
    R(4) <<= 2;
    R(4) <<= 2;
    R(4) += R(2);

    /* the entry's two halfwords */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(4) + 12u);
    R(6) = R(0);
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(4) + 14u);
    R(5) = R(0);

    /* and its three floats */
    vf3_matrix_load(s, ram, 4, R(4) + 16u);
    vf3_matrix_load(s, ram, 5, R(4) + 20u);
    vf3_matrix_load(s, ram, 6, R(4) + 24u);

    /* the second structure */
    R(4) = vf3_mem_u32(ram, R(1));

    /* the two halfwords into the first structure */
    vf3_mem_set_u16(ram, R(7) + HALFWORD_B, (uint16_t)R(5));
    vf3_mem_set_u16(ram, R(7) + HALFWORD_A, (uint16_t)R(6));

    /* and the three floats into the second structure */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, G_OFFSET);
    vf3_matrix_store(s, ram, 4, R(4) + R(0));
    R(0) += (uint32_t)(0u - 8u);
    vf3_matrix_store(s, ram, 5, R(4) + R(0));
    R(0) += 4u;
    vf3_matrix_store(s, ram, 6, R(4) + R(0));

    s->pc = R(16);
    return ram->oob == 0;
}
