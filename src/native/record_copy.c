/* record_copy.c - SH-4 0x8C043A7C: twenty-four records, repacked, natively.
 *
 * A plain-C transcription of the readable port src/fight/record_copy.c
 * (`vf3_record_copy_entry`).  It operates on `vf3_native_aim`: the flat RAM and
 * the register file.  A self-contained integer leaf - it calls nobody, uses no
 * FPU and keeps **no stack frame**.
 *
 * The engine keeps a table of records and a destination array.  This function
 * copies twenty-four records from the table into the destination array, and the
 * two records do not have the same shape: the source's fields are spread out,
 * the destination's are packed.
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
 * twenty-four, and the destination's last eight bytes of every record are left
 * alone.  The table and the destination are two globals in the literal pool, so
 * the port reads the same addresses the guest reads.  The table is read through
 * **two** indirections (the pool gives the table, the table's cell gives the
 * source's base) and the first record is **+0x28** into that base.
 *
 * Two details the port keeps: the loop's exit test is the **T bit** of a
 * compare the body has already bumped (set at the top of every iteration), so
 * the T bit the caller sees is the last iteration's; and the bytes are
 * **sign-extended** into the register they travel through.
 *
 * See docs/re/native_record_copy.md. */
#include "record_copy.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

/* byte writer (the native aim API has set_u16/set_u32 but no set_u8) */
static inline void w8(vf3_native_aim *a, uint32_t addr, uint8_t v)
{ ((uint8_t *)a->ram)[addr - a->ram_base] = v; }

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

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

void vf3_native_record_copy(vf3_native_aim *a)
{
    /* the table and the destination */
    R(3) = vf3_aim_u32(a, G_TABLE);
    R(6) = 0u;
    R(5) = vf3_aim_u32(a, G_DEST);
    R(7) = RECORDS;

    /* the first record's source */
    R(4) = vf3_aim_u32(a, R(3));
    R(4) += SRC_OFFSET;

    for (;;) {
        /* the record's first byte */
        R(2) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(4));
        R(6) += 1u;
        set_t(a, (int32_t)R(6) >= (int32_t)R(7));

        w8(a, R(5), (uint8_t)R(2));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(4) + 1u);
        w8(a, R(5) + 1u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(4) + 2u);
        w8(a, R(5) + 2u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(4) + 3u);
        w8(a, R(5) + 3u, (uint8_t)R(0));

        /* the record's first word */
        R(3) = vf3_aim_u32(a, R(4) + 16u);
        vf3_aim_set_u32(a, R(5) + 8u, R(3));

        /* and the four bytes that go into the destination's second word */
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(4) + 8u);
        w8(a, R(5) + 4u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(4) + 9u);
        w8(a, R(5) + 5u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(4) + 10u);
        w8(a, R(5) + 6u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(4) + 11u);
        w8(a, R(5) + 7u, (uint8_t)R(0));

        /* and the record's second word */
        R(3) = vf3_aim_u32(a, R(4) + 20u);
        vf3_aim_set_u32(a, R(5) + 12u, R(3));

        R(5) += DEST_STRIDE;
        R(4) += SRC_STRIDE;
        if (R(6) >= R(7)) break;
    }
}
