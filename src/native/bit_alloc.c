/* bit_alloc.c - SH-4 0x8C038860: the fight engine's first-free-bit allocator,
 * natively.
 *
 * A plain-C transcription of the readable port src/fight/bit_alloc.c
 * (`vf3_bit_alloc_entry`).  It operates on `vf3_native_aim`: the flat RAM and
 * the register file.  A self-contained leaf - it calls nobody and uses no FP.
 *
 * The function hands back **the index of the first free bit** of a table of
 * 32-bit words, and it takes that bit while it is there.  The table is a list
 * of words.  The literal pool holds two pointers read at run time:
 *
 *   * the **count** of the table's words (via 0x0c0389c8 - the pool entry is
 *     the *address* of the count, so the count is read through it);
 *   * the **table** (via 0x0c0389cc - a pointer to an array whose first entry
 *     points at the words; the guest only uses that first entry).
 *
 * A word of `0xFFFFFFFF` is the table's end marker (an exhausted slot); the
 * free bit is the **lowest clear bit** of the word, and the answer is the
 * bit's index in the whole table (word index * 32 + bit number).  A table
 * with no free bit answers **-1** and writes nothing.
 *
 * The guest keeps a frame of six callee-saved registers (r8, r9, r10, r11,
 * r13, r14) on the stack - the frame bytes are part of the contract and are
 * visible in the RAM the test compares - so the port makes the same six
 * pushes and the same six pops, in the guest's order.
 *
 * See docs/re/native_bit_alloc.md. */
#include "bit_alloc.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

/* The literal pool: two pointers, read at run time. */
#define POOL_COUNT 0x0c0389c8u  /* the count of the table's words */
#define POOL_TABLE 0x0c0389ccu  /* the table: an array of word pointers */

/* A word of this value is the table's end marker, not a free bit. */
#define EXHAUSTED 0xffffffffu

/* The table's words are 32 bits wide, so a word holds 32 bits. */
#define BITS_PER_WORD 32u

/* The guest's frame: six callee-saved registers, in the order it pushes
 * them.  r12 is the frame pointer and is never saved. */
#define FRAME_SIZE 6

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

void vf3_native_bit_alloc(vf3_native_aim *a, uint32_t sp0)
{
    (void)sp0;

    /* The guest's frame: the six pushes, in the guest's order. */
    {
        static const uint8_t order[FRAME_SIZE] = { 14, 13, 11, 10, 9, 8 };
        for (unsigned i = 0; i < FRAME_SIZE; ++i) {
            R(15) -= 4u;
            vf3_aim_set_u32(a, R(15), R(order[i]));
        }
    }

    R(7) = 0u;
    R(5) = R(7);                     /* the bit offset */
    R(14) = R(7);                    /* the byte offset of the slot */
    R(10) = R(7);                    /* the index */
    R(9) = 1u;                       /* the mask the bit scan starts with */
    R(8) = vf3_aim_u32(a, POOL_COUNT);
    R(13) = vf3_aim_u32(a, POOL_TABLE);
    R(11) = R(7);                    /* the byte offset into the table */

    for (;;) {
        /* The loop's condition: the index against the count. */
        R(3) = vf3_aim_u32(a, R(8));
        set_t(a, (int32_t)R(10) >= (int32_t)R(3));
        if ((int32_t)R(10) >= (int32_t)R(3)) {
            /* The table is exhausted: the answer is -1 and nothing is
             * written. */
            R(0) = EXHAUSTED;
            break;
        }

        /* The word at this index. */
        R(0) = vf3_aim_u32(a, R(13));
        R(0) = vf3_aim_u32(a, R(0) + R(11));
        set_t(a, R(0) == EXHAUSTED);
        R(1) = R(0);                  /* the branch's delay slot: the word is
                                      * copied into r1 on **both** paths */
        if (R(0) == EXHAUSTED) {
            /* An exhausted slot: the next word. */
            R(14) += 4u;
            R(11) += 4u;
            R(10) += 1u;
            R(5) += BITS_PER_WORD;
            continue;
        }

        /* The bit scan: the lowest clear bit of the word. */
        R(4) = R(9);                  /* the mask */
        R(6) = R(7);                  /* the bit's number */
        for (;;) {
            R(2) = R(1);
            set_t(a, (R(2) & R(4)) == 0u);
            if ((R(2) & R(4)) == 0u) {
                /* The bit is free: take it. */
                R(0) = vf3_aim_u32(a, R(13));
                R(2) = vf3_aim_u32(a, R(0) + R(14));
                R(2) |= R(4);
                vf3_aim_set_u32(a, R(0) + R(14), R(2));
                R(0) = R(5);
                R(0) += R(6);         /* the branch's delay slot */
                break;
            }
            /* The bit is taken: the next one.  The delay slot of the branch
             * counts the bit. */
            R(4) <<= 1;
            R(6) += 1u;
        }
        break;
    }

    /* The guest's frame comes back. */
    {
        static const uint8_t order[FRAME_SIZE] = { 8, 9, 10, 11, 13, 14 };
        for (unsigned i = 0; i < FRAME_SIZE; ++i) {
            R(order[i]) = vf3_aim_u32(a, R(15));
            R(15) += 4u;
        }
    }
}
