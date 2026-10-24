/* node_handler.c - SH-4 0x8C0AB870: the node's handler, called with a frame.
 *
 * The function takes an object (r4) and a node (r6) and calls the handler
 * the node names:
 *
 *  - the handler is the table's entry at the node's second word - the table
 *    is behind the literal pool at 0x8C0AB9A0 and the index is [r6+4];
 *  - the handler gets a five-word frame on the stack: the handler itself,
 *    the object's first word, the node's two words and the float that
 *    belongs to the object (the float is at the object's address plus the
 *    offset in the literal pool at 0x8C0AB990);
 *  - r5 points at the frame's second word, so the handler's arguments start
 *    there.
 *
 * The guest keeps pr and the frame on the stack and moves the float through
 * the FPU on the way.  The readable port does the same, so the stack
 * traffic it leaves in RAM is the one the original left.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the literal pool */
#define G_OFFSET 0x0c0ab990u   /* the object's float offset */
#define G_TABLE  0x0c0ab9a0u   /* the table of handlers */

/* the continuation the guest leaves in pr */
#define CONT_HANDLER 0x0c0ab898u

/* the frame the handler gets */
#define FRAME_WORDS 5u

int vf3_node_handler_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = R(15);

    /* the guest saves pr */
    vf3_mem_set_u32(ram, sp - 4u, R(16));

    /* the float that belongs to the object comes in through the FPU */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, G_OFFSET);
    vf3_matrix_load(s, ram, 3, R(4) + R(0));

    /* the frame */
    R(15) = sp - 24u;
    R(5) = R(15);
    vf3_matrix_store(s, ram, 3, R(15) + 16u);

    /* the object and the node */
    R(3) = vf3_mem_u32(ram, R(4));
    vf3_mem_set_u32(ram, R(15) + 4u, R(3));
    R(2) = vf3_mem_u32(ram, R(6));
    vf3_mem_set_u32(ram, R(15) + 8u, R(2));
    R(3) = vf3_mem_u32(ram, R(6) + 4u);
    vf3_mem_set_u32(ram, R(15) + 12u, R(3));

    /* the handler: the table's entry of the node's second word */
    R(2) = vf3_mem_u32(ram, R(6) + 4u);
    R(0) = vf3_mem_u32(ram, G_TABLE);
    R(2) <<= 2;
    R(3) = vf3_mem_u32(ram, R(2) + R(0));
    vf3_mem_set_u32(ram, R(15), R(3));

    /* the handler gets the frame, and r5 points at its arguments */
    R(5) += 4u;
    if (!vf3_guest_call(s, ram, R(3), CONT_HANDLER)) return 0;

    /* the epilogue: the frame goes and pr comes back */
    R(15) += FRAME_WORDS * 4u;
    R(16) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    s->pc = R(16);
    return ram->oob == 0;
}
