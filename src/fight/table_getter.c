/* table_getter.c - SH-4 0x8C044068: the getter of a table entry.
 *
 * The engine asks a table for one of its entries.  The getter takes the
 * caller's frame - the three words above the caller's sp - and hands them
 * to the table's handler, the function pointer in the literal pool at
 * 0x8C044144.  The handler answers the entry.
 *
 * Before the answer is given back, the getter looks at the table's own slot:
 * the table's pointer is in the literal pool at 0x8C044140 and the slot's
 * offset in the table is the halfword at 0x8C04413A.  When the slot is taken
 * the getter asks the fallback (0x8C043D04), which lets the manager know;
 * the fallback's own answer is dropped, the handler's answer is the answer.
 *
 * The guest keeps pr and one word of frame on the stack and hands the three
 * frame words to the handler on the stack as well.  The readable port keeps
 * the same words in the same places, so the stack traffic it leaves in RAM
 * is the one the original left.
 *
 * The siblings of the getter - 0x8C04409C, 0x8C0440C8 and the ones after
 * it - are the same function with another handler and another number of
 * frame words; they live in another module and are not ported yet.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the literal pool */
#define G_HANDLER 0x0c044144u   /* the table's handler */
#define G_TABLE   0x0c044140u   /* the address of the global the table hangs off */
#define G_INDEX   0x0c04413au   /* the slot's offset in the table */

/* the fallback: the slot is taken */
#define FALLBACK 0x0c043d04u

/* the continuations the guest leaves in pr */
#define CONT_HANDLER  0x0c04407eu
#define CONT_FALLBACK 0x0c044092u

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

int vf3_table_getter_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = R(15);

    /* the guest saves pr and keeps one word of frame below it */
    vf3_mem_set_u32(ram, sp - 4u, R(16));
    R(15) = sp - 8u;

    /* the caller's frame goes down to the handler: the three words above
     * the caller's sp, the highest one first */
    R(3) = vf3_mem_u32(ram, R(15) + 16u);
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(3));
    R(2) = vf3_mem_u32(ram, R(15) + 16u);
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(2));
    R(3) = vf3_mem_u32(ram, R(15) + 16u);
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(3));

    /* the handler answers the entry */
    R(3) = vf3_mem_u32(ram, G_HANDLER);
    if (!vf3_guest_call(s, ram, R(3), CONT_HANDLER)) return 0;

    /* the answer waits in the frame while the slot is checked */
    R(15) += 12u;
    vf3_mem_set_u32(ram, R(15), R(0));

    /* the slot: the global's address, the table it holds, and the word at
     * the offset */
    R(2) = vf3_mem_u32(ram, G_TABLE);
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, G_INDEX);
    R(3) = vf3_mem_u32(ram, R(2));
    R(1) = vf3_mem_u32(ram, R(3) + R(0));
    set_t(s, R(1) == 0u);
    if (R(1) != 0u) {
        /* the slot is taken: the fallback lets the manager know */
        if (!vf3_guest_call(s, ram, FALLBACK, CONT_FALLBACK)) return 0;
    }

    /* the handler's answer is the answer */
    R(0) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    R(16) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    s->pc = R(16);
    return ram->oob == 0;
}
