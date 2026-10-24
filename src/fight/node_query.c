/* node_query.c - SH-4 0x8C053CA4: the query about a node of the table.
 *
 * The function takes an index, looks the node up in the table behind the
 * literal pool at 0x8C053D44 and asks two handlers about it:
 *
 *  - the first handler - the pointer at 0x8C053D48 - gets the node and
 *    answers a pointer to a status byte;
 *  - the second handler - the pointer at 0x8C053D4C - gets the node and
 *    answers a pointer to a word of flags.
 *
 * The answer is 1 when the status byte is not zero and the flags carry the
 * bit 1; it is 0 in every other case.
 *
 * The guest saves r14 and pr on the stack and keeps the first answer in one
 * word of frame below them.  The readable port keeps the same words in the
 * same places, so the stack traffic it leaves in RAM is the one the
 * original left.
 *
 * The sibling at 0x8C053CE4 asks a third handler as well and keeps a bigger
 * frame; it lives in another module and is not ported yet.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the literal pool */
#define G_TABLE  0x0c053d44u   /* the table of nodes */
#define G_FIRST  0x0c053d48u   /* the first handler */
#define G_SECOND 0x0c053d4cu   /* the second handler */

/* the continuations the guest leaves in pr */
#define CONT_FIRST  0x0c053cb8u
#define CONT_SECOND 0x0c053cc0u

/* the flag the second answer's word has to carry */
#define FLAG_ACTIVE 2u

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

/* The code base the module of this function derives from the caller's
 * return address: the mirror the run came through shows in it.
 */
static uint32_t code_base_of(const vf3_matrix_state *s)
{
    return ((s->v[16] & 0xff000000u) == 0x0c000000u) ? 0x0c000000u : 0x8c000000u;
}

/* The guest's own call: pr is set to the continuation exactly as the guest
 * leaves it - the module writes the continuation with the code base, so the
 * mirror travels in it - and the call fails when control does not come back
 * to the continuation.
 */
static int guest_call(vf3_matrix_state *s, const vf3_ram_map *ram,
                       uint32_t target, uint32_t cont)
{
    s->v[16] = cont;
    if (!vf3_matrix_family(target, s, ram)) return 0;
    return s->pc == cont;
}

int vf3_node_query_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t base = code_base_of(s);
    const uint32_t sp = R(15);

    /* the guest saves r14 and pr */
    vf3_mem_set_u32(ram, sp - 4u, R(14));
    R(15) = sp - 8u;
    vf3_mem_set_u32(ram, R(15), R(16));

    /* the node: the table's entry at the index */
    R(14) = R(4);
    R(0) = vf3_mem_u32(ram, G_TABLE);
    R(14) <<= 2;
    R(14) = vf3_mem_u32(ram, R(14) + R(0));

    /* the first handler: the status */
    R(3) = vf3_mem_u32(ram, G_FIRST);
    R(15) -= 4u;
    R(4) = R(14);
    if (!guest_call(s, ram, R(3), base | CONT_FIRST)) return 0;
    vf3_mem_set_u32(ram, R(15), R(0));

    /* the second handler: the flags */
    R(3) = vf3_mem_u32(ram, G_SECOND);
    R(4) = R(14);
    if (!guest_call(s, ram, R(3), base | CONT_SECOND)) return 0;

    /* the status byte and the flags decide */
    R(2) = vf3_mem_u32(ram, R(15));      /* the first answer */
    R(4) = R(0);                         /* the second answer */
    R(3) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, R(2));
    set_t(s, R(3) == 0u);
    if (R(3) == 0u) {
        /* the status is clear: the node is not active */
        R(0) = 0u;
    } else {
        R(0) = vf3_mem_u32(ram, R(4));
        set_t(s, (R(0) & FLAG_ACTIVE) == 0u);
        R(0) = (R(0) & FLAG_ACTIVE) != 0u ? 1u : 0u;
    }

    /* the epilogue: pr comes back and r14 is restored */
    R(15) += 4u;
    R(16) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    R(14) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    s->pc = R(16);
    return ram->oob == 0;
}
