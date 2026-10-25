/* pack_expand.c - SH-4 0x8C09D5AE: the fight engine's packed-attribute expansion.
 *
 * The function takes one record and expands the **sixteen packed bytes** the
 * record's table entry points at into **sixteen groups of four two-bit
 * fields**, written to a destination the record carries.
 *
 * The pieces:
 *
 *   * a **table** of twelve-byte entries.  The literal pool holds the address
 *     of a pointer, and the pointer the table's base.  The record's halfword
 *     at its offset 60 says which entry the record uses - counted from one,
 *     so the first entry is the record's halfword 1;
 *   * each entry carries **three offsets** from the table's base.  The first
 *     points at the packed bytes, the second and the third at two more places
 *     the record wants to remember;
 *   * the record also carries the **destination**: a pointer, at the offset
 *     the pool names, to a block the expansion writes into.
 *
 * The expansion itself is a loop of sixteen rounds.  Each round reads one
 * packed byte and writes four bytes: the byte's four two-bit fields, most
 * significant first.  The groups land at the destination's offset 12, one
 * group every four bytes.
 *
 * Details the port has to keep:
 *
 *   * the pool's three entries are **read at run time**, the way the guest
 *     reads them: the table's address and the record's two offsets;
 *   * the guest **pushes the record on its stack and pops it again** without
 *     using it, and pushes the two words it remembers before the loop.  The
 *     two words are visible in the corpus' RAM; the record's own push is not
 *     - the second push writes over the very same address - but the stack
 *     pointer's round trip is, so the port reproduces both;
 *   * the `bra` that skips the dead push has a **delay slot**, so the stack
 *     pointer is restored before the branch is taken;
 *   * the record keeps the **packed byte twice**: the byte itself moves up by
 *     29, and the record's own byte gets the top of the source halfword - bit
 *     14 of it, and only that bit;
 *   * the loop's **delay slot** (the group's stride) runs on both the branch
 *     and the fall-through, so the stride advances on the last round too;
 *   * the loop's **T bit** is the guest's branch condition and the guest
 *     leaves it behind: the loop ends with the counter at 16, so the T bit
 *     the port leaves has to be **set**;
 *   * the guest's **order of the memory accesses** is reproduced, because the
 *     corpus compares every RAM byte and a store that lands before a read
 *     would see a different word.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* The guest's literal pool.  Every entry is read at run time. */
#define POOL_TABLE  0x0c09d6dcu /* the address of the table's pointer */
#define POOL_PACKED 0x0c09d6ceu /* the record's offset of the packed byte */
#define POOL_DEST   0x0c09d6d0u /* the record's offset of the destination */

/* The table's entries are twelve bytes: three offsets from the table's base. */
#define ENTRY_FIRST  0u  /* the packed bytes */
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

int vf3_pack_expand_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t record = R(4);

    /* The guest pushes the record on its stack and pops it again without
     * using it.  The *word* it leaves behind does not survive: the second
     * push, below, writes its own word over the very same address.  The
     * stack pointer's round trip is visible though - the function's sp ends
     * where it began, and a port that skips the pop leaves it four bytes
     * lower - so the port makes the same round trip the guest does. */
    R(15) -= 4u;
    vf3_mem_set_u32(ram, R(15), record);
    R(15) += 4u;                      /* the `bra`'s delay slot */

    /* The table, and the entry this record uses. */
    const uint32_t base = vf3_mem_u32(ram, vf3_mem_u32(ram, POOL_TABLE));
    const uint32_t index = (uint32_t)vf3_mem_u16(ram, record + RECORD_INDEX) - 1u;
    const uint32_t entry = base + ENTRY_SIZE * index;

    /* The three offsets of the entry, each from the table's base. */
    const uint32_t first = base + vf3_mem_u32(ram, entry + ENTRY_FIRST);
    const uint32_t second = base + vf3_mem_u32(ram, entry + ENTRY_SECOND);
    const uint32_t third = base + vf3_mem_u32(ram, entry + ENTRY_THIRD);

    /* The two words the guest pushes before the loop. */
    R(15) -= 8u;
    vf3_mem_set_u32(ram, R(15), second);
    vf3_mem_set_u32(ram, R(15) + 4u, third);

    /* The record's packed byte's offset comes out of the pool, as a sign
     * extended halfword - the guest reads it with `mov.w`. */
    const int32_t packed_at = (int32_t)(int16_t)vf3_mem_u16(ram, POOL_PACKED);

    /* The source's head: the guest reads it before it writes to the record. */
    const uint32_t head = (uint32_t)vf3_mem_u16(ram, first);

    /* The record's packed byte: the byte itself moves up by 29, and the
     * record's own byte takes the top of the source halfword. */
    const uint8_t packed = vf3_mem_u8(ram, record + (uint32_t)packed_at);
    vf3_mem_set_u8(ram, record + (uint32_t)(packed_at + PACKED_STEP), packed);
    vf3_mem_set_u8(ram, record + (uint32_t)packed_at,
                   (uint8_t)((head >> HEAD_SHIFT) & HEAD_MASK));

    /* The destination: a pointer the record carries, at the offset the pool
     * names - the guest reads that offset only now, after it has written into
     * the record. */
    const int32_t dest_at = (int32_t)(int16_t)vf3_mem_u16(ram, POOL_DEST);
    const uint32_t dest = vf3_mem_u32(ram, record + (uint32_t)dest_at);

    /* The destination's three words: where the packed bytes are, and the two
     * places the record wanted to remember. */
    vf3_mem_set_u32(ram, dest + 8u, third);
    vf3_mem_set_u32(ram, dest + 4u, second);
    vf3_mem_set_u32(ram, dest, first + SOURCE_HEAD_STEP);

    /* The expansion.  The guest's stride is the delay slot of the loop's
     * branch, so it advances on the last round as well. */
    uint32_t stride = 0u;
    for (unsigned round = 0; round < GROUP_COUNT; ++round) {
        const uint8_t value = vf3_mem_u8(ram, first + 2u + round);
        vf3_mem_set_u8(ram, dest + GROUP_ORIGIN + stride + 0u,
                       (uint8_t)((value >> 6) & 3u));
        vf3_mem_set_u8(ram, dest + GROUP_ORIGIN + stride + 1u,
                       (uint8_t)((value >> 4) & 3u));
        vf3_mem_set_u8(ram, dest + GROUP_ORIGIN + stride + 2u,
                       (uint8_t)((value >> 2) & 3u));
        vf3_mem_set_u8(ram, dest + GROUP_ORIGIN + stride + 3u,
                       (uint8_t)(value & 3u));

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
    R(17) = (R(17) & ~1u) | 1u;

    /* The `rts` restores the stack it pushed. */
    R(15) += 8u;
    s->pc = R(16);
    return ram->oob == 0;
}
