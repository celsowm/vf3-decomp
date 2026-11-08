/* table_probe.c - SH-4 0x8C040378: the indexed table probe.
 *
 * A small self-contained leaf (62 B, call-free, integer-only, no FP).  r4 is
 * an index.  The body pushes r4 onto the stack, reads it back (r2 = r4) and
 * returns a status in r0:
 *
 *   * r4 < 0        -> -1 (index below range), T clear;
 *   * r4 >= 8       -> -1 (index above range), T set  (r1 is left as 8);
 *   * otherwise     -> the table's entry for the index is looked up and the
 *                      answer depends on it:
 *                      - the entry is 0xffffffff  -> -2, T set;
 *                      - any other entry         ->  0, T clear.
 *
 * The index selects the table by a stride of twelve bytes:
 *
 *     tbl = read32(0x0c0403bc)          the table's base pointer
 *     val = read32(tbl + 12 * r4)
 *
 * (the guest builds 12*r4 by `add r0,r3` + two left shifts and sign-extends
 * the byte, which for r4 in [0,8) leaves it as the positive 0..84 it is).
 *
 * The transient stack slot: the guest stores r4 at sp-4 on entry, reads it
 * back for the range tests and the index, and restores sp at the return - so
 * r15 is net unchanged, but the four bytes above the frame hold the entry
 * value of r4 and are part of the captured RAM.  The registers the body
 * leaves are r2 = r3 = r4 on every path that passes the first test, r1 = 8 on
 * the "too big" path and r1 = the table base on the lookup path, r0 the
 * status above, and SR's T bit from the last comparison.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

int vf3_table_probe_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t r4 = R(4);

    /* 0x0c04037a: the transient stack slot gains the entry value of r4. */
    vf3_mem_set_u32(ram, R(15) - 4u, r4);

    /* 0x0c04037c: r2 = the pushed r4. */
    R(2) = r4;

    /* 0x0c04037e: T = (r2 >= 0); below range returns -1 with T clear.  On this
     * path r1 and r3 keep their entry values (the branch is taken before the
     * body reads the slot into r3). */
    if ((int32_t)r4 < 0) {
        R(0) = 0xffffffffu;
        R(17) = (R(17) & ~1u);                  /* T = 0 */
        s->pc = R(16);
        return ram->oob == 0;
    }

    /* 0x0c040382/384: on any r4 >= 0 path r3 = the slot value = r4, and the
     * above-range test sets r1 = 8 before it decides. */
    R(3) = r4;
    R(1) = 8u;
    if ((int32_t)r4 >= 8) {
        R(0) = 0xffffffffu;
        R(17) = (R(17) & ~1u) | 1u;             /* T = 1 */
        s->pc = R(16);
        return ram->oob == 0;
    }

    /* 0x0c040392..3a0: r4 in [0,8): val = tbl[12 * r4].  r1 = the table base. */
    {
        uint32_t tbl = vf3_mem_u32(ram, 0x0c0403bcu);
        R(1) = tbl;
        R(0) = vf3_mem_u32(ram, tbl + 12u * r4);
    }

    /* 0x0c0403a2/3a4: the entry selects the answer and the T bit. */
    if (R(0) == 0xffffffffu) {
        R(0) = 0xffffffffu - 1u;                /* -2 */
        R(17) = (R(17) & ~1u) | 1u;             /* T = 1 */
    } else {
        R(0) = 0u;
        R(17) = (R(17) & ~1u);                  /* T = 0 */
    }

    s->pc = R(16);
    return ram->oob == 0;
}
