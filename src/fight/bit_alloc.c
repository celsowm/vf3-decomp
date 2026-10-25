/* bit_alloc.c - SH-4 0x8C0B0FD2's neighbour 0x8C038860: the fight engine's
 * first free bit.
 *
 * The function hands back **the index of the first free bit** of a table of
 * 32-bit words, and it takes that bit while it is there.
 *
 * The table is a list of words.  The literal pool holds two pointers:
 *
 *   * the **count** of the table's words - the loop stops when the index
 *     reaches it.  The pool entry is the *address* of the count, so the
 *     count is read through it;
 *   * the **table** itself, a pointer to an array whose first entry points at
 *     the words.  The guest only ever uses that first entry: the word at
 *     index *i* lives at *(table + i * 4).
 *
 * A word of `0xFFFFFFFF` is the table's end marker: it is not a free bit but
 * an exhausted slot, and the function moves on to the next word.
 *
 * The free bit is the **lowest clear bit** of the word - the function walks a
 * mask from 1 upwards until the word's bit is clear, and then sets that bit.
 * The answer is the bit's index in the whole table: the word's index times
 * 32, plus the bit's number inside the word.
 *
 * A table with no free bit at all - every word exhausted, or the count
 * reached - answers **-1**, and nothing is written.
 *
 * Details the port has to keep:
 *
 *   * the guest keeps a **frame of six registers** (r8, r9, r10, r11, r13 and
 *     r14 - r12 is the frame pointer and is never saved), and the frame is
 *     visible in the corpus' RAM: the port makes the same six pushes and the
 *     same six pops;
 *   * the pushes happen **before** the registers are overwritten, so the
 *     frame holds the caller's values;
 *   * the guest reuses **r14 and r11** as the byte offsets into the table and
 *     **r5** as the bit offset, so they do not hold the caller's values when
 *     the function returns - the pops put the caller's back;
 *   * the inner loop's **delay slot** counts the bit, and the branch's delay
 *     slot adds it to the answer;
 *   * the guest's `tst` sets the T bit when the AND is zero, and the `bf`
 *     branches when that bit is clear - so the *free* bit is the one the
 *     `bf` does **not** take;
 *   * the **T bit** the guest leaves is the last test it made, so it depends
 *     on the path;
 *   * the copy of the word into r1 is the **delay slot** of the branch that
 *     decides whether the slot is exhausted, so it happens on **both** paths:
 *     a table whose every slot is exhausted leaves r1 holding 0xffffffff;
 *   * the **mask's shift** sets the T bit from the mask's top bit, but the
 *     bit scan's own test overwrites it before anything reads it, so the port
 *     leaves it out.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* The literal pool: two pointers, read at run time. */
#define POOL_COUNT 0x0c0389c8u  /* the count of the table's words */
#define POOL_TABLE 0x0c0389ccu  /* the table: an array of word pointers */

/* A word of this value is the table's end marker, not a free bit. */
#define EXHAUSTED 0xffffffffu

/* The table's words are 32 bits wide, so a word holds 32 bits. */
#define BITS_PER_WORD 32u

/* The guest's frame: six callee-saved registers, in the order it pushes
 * them.  r12 is the frame pointer and is never saved. */
#define FRAME_R14 0
#define FRAME_R13 1
#define FRAME_R11 2
#define FRAME_R10 3
#define FRAME_R9  4
#define FRAME_R8  5
#define FRAME_SIZE 6

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

/* The guest's frame: the six pushes, in the guest's order. */
static void push_frame(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    static const uint8_t order[FRAME_SIZE] = { 14, 13, 11, 10, 9, 8 };
    for (unsigned i = 0; i < FRAME_SIZE; ++i) {
        R(15) -= 4u;
        vf3_mem_set_u32(ram, R(15), R(order[i]));
    }
}

/* The guest's frame: the six pops, in the guest's order. */
static void pop_frame(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    static const uint8_t order[FRAME_SIZE] = { 8, 9, 10, 11, 13, 14 };
    for (unsigned i = 0; i < FRAME_SIZE; ++i) {
        R(order[i]) = vf3_mem_u32(ram, R(15));
        R(15) += 4u;
    }
}

int vf3_bit_alloc_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* The guest's frame.  The pushes come before the registers are
     * overwritten, so the frame holds the caller's values. */
    push_frame(s, ram);

    R(7) = 0u;
    R(5) = R(7);                     /* the bit offset */
    R(14) = R(7);                    /* the byte offset of the slot */
    R(10) = R(7);                    /* the index */
    R(9) = 1u;                       /* the mask the bit scan starts with */
    R(8) = vf3_mem_u32(ram, POOL_COUNT);
    R(13) = vf3_mem_u32(ram, POOL_TABLE);
    R(11) = R(7);                    /* the byte offset into the table */

    for (;;) {
        /* The loop's condition: the index against the count. */
        R(3) = vf3_mem_u32(ram, R(8));
        set_t(s, (int32_t)R(10) >= (int32_t)R(3));
        if ((int32_t)R(10) >= (int32_t)R(3)) {
            /* The table is exhausted: the answer is -1 and nothing is
             * written. */
            R(0) = EXHAUSTED;
            break;
        }

        /* The word at this index. */
        R(0) = vf3_mem_u32(ram, R(13));
        R(0) = vf3_mem_u32(ram, R(0) + R(11));
        set_t(s, R(0) == EXHAUSTED);
        R(1) = R(0);                  /* the branch's delay slot: the guest
                                      * copies the word into r1 on **both**
                                      * paths, so an exhausted slot leaves
                                      * r1 holding 0xffffffff */
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
            set_t(s, (R(2) & R(4)) == 0u);
            if ((R(2) & R(4)) == 0u) {
                /* The bit is free: take it. */
                R(0) = vf3_mem_u32(ram, R(13));
                R(2) = vf3_mem_u32(ram, R(0) + R(14));
                R(2) |= R(4);
                vf3_mem_set_u32(ram, R(0) + R(14), R(2));
                R(0) = R(5);
                R(0) += R(6);         /* the branch's delay slot */
                break;
            }
            /* The bit is taken: the next one.  The delay slot of the
             * branch counts the bit. */
            R(4) <<= 1;
            R(6) += 1u;
        }
        break;
    }

    /* The guest's frame comes back. */
    pop_frame(s, ram);
    s->pc = R(16);
    return ram->oob == 0;
}
