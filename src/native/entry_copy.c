/* entry_copy.c - SH-4 0x8C06D7D6: a table entry's fields, into two places,
 * natively.
 *
 * A plain-C transcription of the readable port src/fight/entry_copy.c
 * (`vf3_entry_copy_entry`).  It operates on `vf3_native_aim`: the flat RAM,
 * the FR bank and the register file.  A self-contained leaf - it calls nobody
 * and keeps **no stack frame**, but it uses the FR bank for the entry's five
 * floats.
 *
 * The engine keeps a table of sixty-four byte entries and a structure with a
 * pair of offsets in it.  This function looks an entry up and copies some of
 * its fields into the structure, twice: once at each offset.
 *
 * The entry is picked by the **whole** index byte, so the table has 256
 * entries, and each of them is sixty-four bytes apart.  The entry's three
 * bytes - at its +5, +6 and +7 - go into the structure at the first offset and
 * at the second one, three bytes apart in each case.  The entry's five floats
 * go to two groups as well:
 *
 *   at the first offset:  the float at the entry's +28 at offset-20,
 *                          the float at the entry's +32 at offset-16,
 *                          the float at the entry's +36 at offset-4;
 *   at the second offset: the float at the entry's +24 at offset-12,
 *                          the float at the entry's +16 at offset-16.
 *
 * The two offsets are signed halfwords in the literal pool (0x0c06d880 and
 * 0x0c06d882), so they can point below the structure; the pool's values are
 * read at run time.  The bytes are sign-extended into the register they
 * travel through, and the last float is stored in the `rts`'s delay slot.
 *
 * See docs/re/native_entry_copy.md. */
#include "entry_copy.h"

#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

/* byte writer (the native aim API has set_u16/set_u32 but no set_u8) */
static inline void w8(vf3_native_aim *a, uint32_t addr, uint8_t v)
{ ((uint8_t *)a->ram)[addr - a->ram_base] = v; }

/* the literal pool */
#define G_INDEX  0x0c06d89cu   /* the address of the index byte */
#define G_TABLE  0x0c06d8a8u   /* the table */
#define G_STRUCT 0x0c06d890u   /* the address of the structure's address */
#define G_FIRST  0x0c06d880u   /* the first offset in the structure */
#define G_SECOND 0x0c06d882u   /* and the second */

/* the entries are sixty-four bytes apart */
#define ENTRY_STRIDE 64u

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

void vf3_native_entry_copy(vf3_native_aim *a)
{
    /* the index byte's address and the table */
    R(3) = vf3_aim_u32(a, G_INDEX);
    R(2) = vf3_aim_u32(a, G_TABLE);

    /* the index byte, and the cell that holds the structure's address */
    R(4) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(3));
    R(1) = vf3_aim_u32(a, G_STRUCT);

    /* the entry: the whole byte, sixty-four bytes apart */
    R(5) = R(4) & 0xffu;
    R(5) <<= 2;
    R(5) <<= 2;
    R(5) <<= 2;
    R(4) = vf3_aim_u32(a, R(1));
    R(5) += R(2);

    /* the entry's three bytes */
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(5) + 5u);
    R(6) = R(0);
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(5) + 6u);
    R(7) = R(0);
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(5) + 7u);
    R(1) = R(0);

    /* and its five floats */
    fload(a, 5, R(5) + 28u);
    fload(a, 8, R(5) + 32u);
    fload(a, 6, R(5) + 36u);
    fload(a, 7, R(5) + 24u);
    fload(a, 4, R(5) + 16u);

    /* the first group: the three bytes and three of the floats */
    R(0) = (uint32_t)half(a, G_FIRST);
    w8(a, R(4) + R(0), (uint8_t)R(6));
    R(0) += 1u;
    w8(a, R(4) + R(0), (uint8_t)R(7));
    R(0) += 1u;
    w8(a, R(4) + R(0), (uint8_t)R(1));
    R(0) += (uint32_t)(0u - 22u);
    fstore(a, 5, R(4) + R(0));
    R(0) += 4u;
    fstore(a, 8, R(4) + R(0));
    R(0) += 12u;
    fstore(a, 6, R(4) + R(0));

    /* and the second group: the same three bytes and the other two floats */
    R(0) = (uint32_t)half(a, G_SECOND);
    w8(a, R(4) + R(0), (uint8_t)R(6));
    R(0) += 1u;
    w8(a, R(4) + R(0), (uint8_t)R(7));
    R(0) += 1u;
    w8(a, R(4) + R(0), (uint8_t)R(1));
    R(0) += (uint32_t)(0u - 14u);
    fstore(a, 7, R(4) + R(0));
    R(0) += (uint32_t)(0u - 4u);
    fstore(a, 4, R(4) + R(0));
}
