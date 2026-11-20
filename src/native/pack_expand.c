/* pack_expand.c - SH-4 0x8C09D5AE: the fight engine's packed-attribute
 * expansion, natively.
 *
 * A plain-C transcription of the readable port src/fight/pack_expand.c
 * (`vf3_pack_expand_entry`).  It operates on `vf3_native_aim`: the flat RAM
 * and the register file.  A self-contained leaf - it calls nobody and uses no
 * FPU.
 *
 * The function takes one record and expands the **sixteen packed bytes** the
 * record's table entry points at into **sixteen groups of four two-bit
 * fields**, written to a destination the record carries.  The literal pool
 * holds three entries read at run time: the address of a pointer to the table
 * (0x0c09d6dc), and the record's two offsets (0x0c09d6ce for the packed byte,
 * 0x0c09d6d0 for the destination).
 *
 * Two details the port keeps: the guest pushes the record on its stack and
 * pops it again without using it (the stack pointer's round trip is visible),
 * and the memory-access order is reproduced because the corpus compares every
 * RAM byte.  The loop ends with the counter at 16, so the T bit the port
 * leaves is **set**.
 *
 * See docs/re/native_pack_expand.md. */
#include "pack_expand.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

/* byte writer (the native aim API has set_u16/set_u32 but no set_u8) */
static inline void w8(vf3_native_aim *a, uint32_t addr, uint8_t v)
{ ((uint8_t *)a->ram)[addr - a->ram_base] = v; }

/* The guest's literal pool.  Every entry is read at run time. */
#define POOL_TABLE  0x0c09d6dcu /* the address of the table's pointer */
#define POOL_PACKED 0x0c09d6ceu /* the record's offset of the packed byte */
#define POOL_DEST   0x0c09d6d0u /* the record's offset of the destination */

/* The table's entries are twelve bytes: three offsets from the table's base. */
#define ENTRY_FIRST  0u
#define ENTRY_SECOND 4u
#define ENTRY_THIRD  8u
#define ENTRY_SIZE   12u

/* The record's halfword at 60 says which entry the record uses - from one. */
#define RECORD_INDEX 60u

/* The expansion: sixteen rounds, four two-bit fields each. */
#define GROUP_COUNT 16u
#define GROUP_SIZE  4u

/* The groups start at the destination's offset 12. */
#define GROUP_ORIGIN 12u

/* The source's head: two bytes before the packed bytes, and the guest takes
 * bit 14 of it. */
#define HEAD_SHIFT 12
#define HEAD_MASK  4u

/* The record's packed byte moves up by this many bytes. */
#define PACKED_STEP 29

/* The destination's first word is the source's head plus seventeen. */
#define SOURCE_HEAD_STEP 17u

void vf3_native_pack_expand(vf3_native_aim *a, uint32_t sp0)
{
    const uint32_t record = R(4);

    /* The guest pushes the record on its stack and pops it again without
     * using it.  The stack pointer's round trip is visible, so the port makes
     * the same round trip the guest does. */
    R(15) -= 4u;
    vf3_aim_set_u32(a, R(15), record);
    R(15) += 4u;                      /* the `bra`'s delay slot */

    /* The table, and the entry this record uses. */
    const uint32_t base = vf3_aim_u32(a, vf3_aim_u32(a, POOL_TABLE));
    const uint32_t index = (uint32_t)vf3_aim_h16(a, record + RECORD_INDEX) - 1u;
    const uint32_t entry = base + ENTRY_SIZE * index;

    /* The three offsets of the entry, each from the table's base. */
    const uint32_t first = base + vf3_aim_u32(a, entry + ENTRY_FIRST);
    const uint32_t second = base + vf3_aim_u32(a, entry + ENTRY_SECOND);
    const uint32_t third = base + vf3_aim_u32(a, entry + ENTRY_THIRD);

    /* The two words the guest pushes before the loop. */
    R(15) -= 8u;
    vf3_aim_set_u32(a, R(15), second);
    vf3_aim_set_u32(a, R(15) + 4u, third);

    /* The record's packed byte's offset comes out of the pool, as a sign
     * extended halfword - the guest reads it with `mov.w`. */
    const int32_t packed_at = (int32_t)(int16_t)vf3_aim_h16(a, POOL_PACKED);

    /* The source's head: the guest reads it before it writes to the record. */
    const uint32_t head = (uint32_t)vf3_aim_h16(a, first);

    /* The record's packed byte: the byte itself moves up by 29, and the
     * record's own byte takes the top of the source halfword. */
    const uint8_t packed = vf3_aim_u8(a, record + (uint32_t)packed_at);
    w8(a, record + (uint32_t)(packed_at + PACKED_STEP), packed);
    w8(a, record + (uint32_t)packed_at,
       (uint8_t)((head >> HEAD_SHIFT) & HEAD_MASK));

    /* The destination: a pointer the record carries, at the offset the pool
     * names - the guest reads that offset only now, after it has written into
     * the record. */
    const int32_t dest_at = (int32_t)(int16_t)vf3_aim_h16(a, POOL_DEST);
    const uint32_t dest = vf3_aim_u32(a, record + (uint32_t)dest_at);

    /* The destination's three words: where the packed bytes are, and the two
     * places the record wanted to remember. */
    vf3_aim_set_u32(a, dest + 8u, third);
    vf3_aim_set_u32(a, dest + 4u, second);
    vf3_aim_set_u32(a, dest, first + SOURCE_HEAD_STEP);

    /* The expansion.  The guest's stride is the delay slot of the loop's
     * branch, so it advances on the last round as well. */
    uint32_t stride = 0u;
    for (unsigned round = 0; round < GROUP_COUNT; ++round) {
        const uint8_t value = vf3_aim_u8(a, first + 2u + round);
        w8(a, dest + GROUP_ORIGIN + stride + 0u, (uint8_t)((value >> 6) & 3u));
        w8(a, dest + GROUP_ORIGIN + stride + 1u, (uint8_t)((value >> 4) & 3u));
        w8(a, dest + GROUP_ORIGIN + stride + 2u, (uint8_t)((value >> 2) & 3u));
        w8(a, dest + GROUP_ORIGIN + stride + 3u, (uint8_t)(value & 3u));

        /* the registers the guest leaves behind */
        R(0) = value & 3u;             /* the last byte it wrote */
        R(6) = value;                  /* the packed byte it read */
        stride += GROUP_SIZE;
    }
    R(1) = GROUP_COUNT;               /* the loop's limit */
    R(2) = first + 2u + GROUP_COUNT;  /* the source, after the last read */
    R(3) = dest + GROUP_ORIGIN + stride - GROUP_SIZE;  /* the last group */
    R(4) = dest;                      /* the destination */
    R(5) = stride;                    /* the stride, one past the last group */
    R(7) = GROUP_COUNT;               /* the round counter */

    /* The loop ended with the counter at 16, so the guest's T bit is set. */
    a->sr |= 1u;

    /* The `rts` restores the stack it pushed. */
    R(15) += 8u;
    (void)sp0;
}
