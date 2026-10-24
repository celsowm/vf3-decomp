/* entry_copy.c - SH-4 0x8C06D7D6: a table entry's fields, into two places.
 *
 * The engine keeps a table of sixty-four byte entries and a structure with a
 * pair of offsets in it.  This function looks an entry up and copies some of
 * its fields into the structure, twice: once at each offset.
 *
 * The entry is picked by the **whole** index byte, so the table has 256
 * entries, and each of them is sixty-four bytes apart.
 *
 * The entry's three bytes - at its +5, +6 and +7 - go into the structure at
 * the first offset and at the second one, three bytes apart in each case.
 * The entry's five floats go to two groups as well:
 *
 *   at the first offset:  the float at the entry's +28 at offset-20,
 *                          the float at the entry's +32 at offset-16,
 *                          the float at the entry's +36 at offset-4;
 *   at the second offset: the float at the entry's +24 at offset-12,
 *                          the float at the entry's +16 at offset-16.
 *
 * The two offsets are signed halfwords in the literal pool, at 0x8C06D880 and
 * 0x8C06D882, so they can point below the structure.  The pool's values are
 * not recoverable offline, so the port reads the same addresses the guest
 * reads.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"

#define R(n) s->v[(n)]

/* the literal pool */
#define G_INDEX  0x0c06d89cu   /* the address of the index byte */
#define G_TABLE  0x0c06d8a8u   /* the table */
#define G_STRUCT 0x0c06d890u   /* the address of the structure's address */
#define G_FIRST  0x0c06d880u   /* the first offset in the structure */
#define G_SECOND 0x0c06d882u   /* and the second */

/* the entries are sixty-four bytes apart */
#define ENTRY_STRIDE 64u

int vf3_entry_copy_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* the index byte's address and the table */
    R(3) = vf3_mem_u32(ram, G_INDEX);
    R(2) = vf3_mem_u32(ram, G_TABLE);

    /* the index byte, and the cell that holds the structure's address */
    R(4) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(3));
    R(1) = vf3_mem_u32(ram, G_STRUCT);

    /* the entry: the whole byte, sixty-four bytes apart */
    R(5) = R(4) & 0xffu;
    R(5) <<= 2;
    R(5) <<= 2;
    R(5) <<= 2;
    R(4) = vf3_mem_u32(ram, R(1));
    R(5) += R(2);

    /* the entry's three bytes */
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(5) + 5u);
    R(6) = R(0);
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(5) + 6u);
    R(7) = R(0);
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(5) + 7u);
    R(1) = R(0);

    /* and its five floats */
    vf3_matrix_load(s, ram, 5, R(5) + 28u);
    vf3_matrix_load(s, ram, 8, R(5) + 32u);
    vf3_matrix_load(s, ram, 6, R(5) + 36u);
    vf3_matrix_load(s, ram, 7, R(5) + 24u);
    vf3_matrix_load(s, ram, 4, R(5) + 16u);

    /* the first group: the three bytes and three of the floats */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, G_FIRST);
    vf3_mem_set_u8(ram, R(4) + R(0), (uint8_t)R(6));
    R(0) += 1u;
    vf3_mem_set_u8(ram, R(4) + R(0), (uint8_t)R(7));
    R(0) += 1u;
    vf3_mem_set_u8(ram, R(4) + R(0), (uint8_t)R(1));
    R(0) += (uint32_t)(0u - 22u);
    vf3_matrix_store(s, ram, 5, R(4) + R(0));
    R(0) += 4u;
    vf3_matrix_store(s, ram, 8, R(4) + R(0));
    R(0) += 12u;
    vf3_matrix_store(s, ram, 6, R(4) + R(0));

    /* and the second group: the same three bytes and the other two floats */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, G_SECOND);
    vf3_mem_set_u8(ram, R(4) + R(0), (uint8_t)R(6));
    R(0) += 1u;
    vf3_mem_set_u8(ram, R(4) + R(0), (uint8_t)R(7));
    R(0) += 1u;
    vf3_mem_set_u8(ram, R(4) + R(0), (uint8_t)R(1));
    R(0) += (uint32_t)(0u - 14u);
    vf3_matrix_store(s, ram, 7, R(4) + R(0));
    R(0) += (uint32_t)(0u - 4u);
    vf3_matrix_store(s, ram, 4, R(4) + R(0));

    s->pc = R(16);
    return ram->oob == 0;
}
