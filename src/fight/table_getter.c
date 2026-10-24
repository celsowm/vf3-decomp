/* table_getter.c - SH-4 0x8C044068 and its siblings: the getter of a table
 * entry.
 *
 * The engine asks a table for one of its entries.  The getter takes the
 * caller's frame - the words above the caller's sp - and hands them to the
 * table's handler, the function pointer in the literal pool next to the
 * getter.  The handler answers the entry.
 *
 * Before the answer is given back, the getter looks at the table's own slot:
 * the table's pointer is in the literal pool at 0x8C044140 and the slot's
 * offset in the table is the halfword at 0x8C04413A.  When the slot is taken
 * the getter asks the fallback (0x8C043D04), which lets the manager know;
 * the fallback's own answer is dropped, the handler's answer is the answer.
 *
 * The branch is the opposite of what the name suggests: the guest tests the
 * slot and branches *over* the fallback when the slot is zero, so the
 * fallback runs when the slot is not empty.  The port follows the machine.
 *
 * The family:
 *
 *   entry       frame words   handler      module
 *   0x8C044068  3             0x8C044144   target_record_adapters
 *   0x8C04409C  1             0x8C044148   vf3_c91_adapter
 *   0x8C0440C8  0             0x8C04414C   vf3_c91_adapter
 *
 * Every member shares the tail: the same table pointer, the same slot
 * offset, the same fallback and the same epilogue.  The two after the first
 * live in a module that writes its continuations with the code base it
 * derived from the caller's return address, so their continuation carries
 * the mirror the run came through; the first one does not.
 *
 * The guest keeps pr and one word of frame on the stack and hands the frame
 * words to the handler on the stack as well.  The readable port keeps the
 * same words in the same places, so the stack traffic it leaves in RAM is
 * the one the original left.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the literal pool */
#define G_HANDLER_3 0x0c044144u   /* the handler of the getter at 0x8C044068 */
#define G_HANDLER_1 0x0c044148u   /* ... and of the one at 0x8C04409C */
#define G_HANDLER_0 0x0c04414cu   /* ... and of the one at 0x8C0440C8 */
#define G_TABLE   0x0c044140u   /* the address of the global the table hangs off */
#define G_INDEX   0x0c04413au   /* the slot's offset in the table */

/* the fallback: the slot is taken */
#define FALLBACK 0x0c043d04u

/* the continuations the guest leaves in pr */
#define CONT_HANDLER_3  0x0c04407eu
#define CONT_FALLBACK_3 0x0c044092u
#define CONT_HANDLER_1  0x0c0440aau
#define CONT_FALLBACK_1 0x0c0440beu
#define CONT_HANDLER_0  0x0c0440d2u
#define CONT_FALLBACK_0 0x0c0440e4u

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

/* The guest's own call: pr is set to the continuation exactly as the guest
 * leaves it - the aliased members carry the mirror in it, which the shared
 * helper cannot do - and the call fails when control does not come back
 * to the continuation.
 */
static int guest_call(vf3_matrix_state *s, const vf3_ram_map *ram,
                       uint32_t target, uint32_t cont)
{
    s->v[16] = cont;
    if (!vf3_matrix_family(target, s, ram)) return 0;
    return s->pc == cont;
}

/* The code base the module of the two younger getters derives from the
 * caller's return address: the mirror the run came through shows in it.
 */
static uint32_t code_base_of(const vf3_matrix_state *s)
{
    return ((s->v[16] & 0xff000000u) == 0x0c000000u) ? 0x0c000000u : 0x8c000000u;
}

/* The prologue every member shares: pr goes down and one word of frame is
 * reserved for the handler's answer.
 */
static void getter_prologue(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = R(15);
    vf3_mem_set_u32(ram, sp - 4u, R(16));
    R(15) = sp - 8u;
}

/* The part every member shares: the handler answers, the answer waits in the
 * frame while the table's slot is checked, the fallback is asked when the
 * slot is taken, and the handler's answer is the answer.
 */
static int getter_tail(vf3_matrix_state *s, const vf3_ram_map *ram,
                        uint32_t handler, uint32_t cont_handler,
                        uint32_t cont_fallback, unsigned nwords)
{
    /* the handler answers the entry */
    R(3) = handler;
    if (!guest_call(s, ram, R(3), cont_handler)) return 0;

    /* the answer waits in the frame while the slot is checked */
    R(15) += nwords * 4u;
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
        if (!guest_call(s, ram, FALLBACK, cont_fallback)) return 0;
    }

    /* the handler's answer is the answer */
    R(0) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    R(16) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    s->pc = R(16);
    return ram->oob == 0;
}

/* The getter at 0x8C044068: the caller's three frame words go to the
 * handler.  The guest reads them from the highest to the lowest and the
 * handler sees them in the order the caller passed them.
 */
int vf3_table_getter_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    getter_prologue(s, ram);

    R(3) = vf3_mem_u32(ram, R(15) + 16u);
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(3));
    R(2) = vf3_mem_u32(ram, R(15) + 16u);
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(2));
    R(3) = vf3_mem_u32(ram, R(15) + 16u);
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(3));

    return getter_tail(s, ram, vf3_mem_u32(ram, G_HANDLER_3),
                       CONT_HANDLER_3, CONT_FALLBACK_3, 3u);
}

/* The getter at 0x8C04409C: one frame word.  Its module writes the
 * continuations with the code base, so the continuation carries the mirror
 * the run came through.
 */
int vf3_table_getter_1_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t base = code_base_of(s);
    getter_prologue(s, ram);

    R(3) = vf3_mem_u32(ram, R(15) + 8u);
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(3));

    return getter_tail(s, ram, vf3_mem_u32(ram, G_HANDLER_1),
                       base | CONT_HANDLER_1, base | CONT_FALLBACK_1, 1u);
}

/* The getter at 0x8C0440C8: no frame word at all. */
int vf3_table_getter_0_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t base = code_base_of(s);
    getter_prologue(s, ram);

    return getter_tail(s, ram, vf3_mem_u32(ram, G_HANDLER_0),
                       base | CONT_HANDLER_0, base | CONT_FALLBACK_0, 0u);
}
