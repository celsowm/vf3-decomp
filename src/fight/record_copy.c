/* record_copy.c - SH-4 0x8C043A7C: twenty-four records, repacked.
 *
 * The engine keeps a table of records and a destination array.  This function
 * copies twenty-four records from the table into the destination array, and
 * the two records do not have the same shape: the source's fields are spread
 * out, the destination's are packed.
 *
 * Per record:
 *
 *   source            destination
 *   ------            -----------
 *   byte  0.. 3       byte  0.. 3
 *   byte  8..11       byte  4.. 7
 *   word 16..19       word  8..11
 *   word 20..23       word 12..15
 *
 * The source's records are forty-four bytes apart and the destination's
 * twenty-four, and the destination's last eight bytes of every record are
 * left alone.
 *
 * The table and the destination are two globals in the literal pool, so the
 * port reads the same addresses the guest reads.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the literal pool */
#define G_DEST 0x0c043b74u   /* the destination array */
#define G_TABLE 0x0c043b78u  /* the table */

/* how many records are copied */
#define RECORDS 24u

/* the distance between the source's records */
#define SRC_STRIDE 0x2cu

/* the distance between the destination's records */
#define DEST_STRIDE 0x18u

/* the first record's field sits behind this much of the table's cell */
#define SRC_OFFSET 0x28u

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

int vf3_record_copy_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* the table and the destination */
    R(3) = vf3_mem_u32(ram, G_TABLE);
    R(6) = 0u;
    R(5) = vf3_mem_u32(ram, G_DEST);
    R(7) = RECORDS;

    /* the first record's source */
    R(4) = vf3_mem_u32(ram, R(3));
    R(4) += SRC_OFFSET;

    for (;;) {
        /* the record's first byte */
        R(2) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(4));
        R(6) += 1u;
        set_t(s, (int32_t)R(6) >= (int32_t)R(7));

        vf3_mem_set_u8(ram, R(5), (uint8_t)R(2));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(4) + 1u);
        vf3_mem_set_u8(ram, R(5) + 1u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(4) + 2u);
        vf3_mem_set_u8(ram, R(5) + 2u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(4) + 3u);
        vf3_mem_set_u8(ram, R(5) + 3u, (uint8_t)R(0));

        /* the record's first word */
        R(3) = vf3_mem_u32(ram, R(4) + 16u);
        vf3_mem_set_u32(ram, R(5) + 8u, R(3));

        /* and the four bytes that go into the destination's second word */
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(4) + 8u);
        vf3_mem_set_u8(ram, R(5) + 4u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(4) + 9u);
        vf3_mem_set_u8(ram, R(5) + 5u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(4) + 10u);
        vf3_mem_set_u8(ram, R(5) + 6u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(4) + 11u);
        vf3_mem_set_u8(ram, R(5) + 7u, (uint8_t)R(0));

        /* and the record's second word */
        R(3) = vf3_mem_u32(ram, R(4) + 20u);
        vf3_mem_set_u32(ram, R(5) + 12u, R(3));

        R(5) += DEST_STRIDE;
        R(4) += SRC_STRIDE;
        if (R(6) >= R(7)) break;
    }

    s->pc = R(16);
    return ram->oob == 0;
}
