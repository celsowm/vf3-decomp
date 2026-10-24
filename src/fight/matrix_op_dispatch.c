/* matrix_op_dispatch.c - SH-4 0x8C035CE8: run the matrix operation the
 * current node asks for.
 *
 * The engine keeps the current node behind a global: the word at 0x8C035D60
 * points at the node pointer, so the node itself is the word behind it.
 *
 * The node names the operation to run in its word at +0x50.  The pointer is
 * one of the matrix operations the engine has (xform_point, matrix_concat,
 * matrix_load, ...); the guest jumps to it with its own pr, so the operation
 * runs in the caller's frame and returns straight to the caller's caller.
 * The matrix the operation works on is the caller's r4 and travels
 * untouched.
 *
 * A node that is not there (the word behind the global is null) has no
 * operation to run: the guest answers 0 and returns.
 *
 * The guest saves r14 around the work and restores it before it jumps, so
 * the word it leaves on the stack is the one the original left.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* The global that points at the current node pointer. */
#define G_CURRENT_NODE 0x0c035d60u

/* The node's word with the operation's entry (the node vocabulary of
 * src/sys/taskvm.c calls these fields N_Fxx). */
#define N_F50 0x50u

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

int vf3_matrix_op_dispatch_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* the guest saves r14 around the work */
    const uint32_t sp = R(15);
    vf3_mem_set_u32(ram, sp - 4u, R(14));
    R(15) = sp - 4u;

    /* the node behind the global */
    R(3) = vf3_mem_u32(ram, G_CURRENT_NODE);
    R(14) = vf3_mem_u32(ram, R(3));
    set_t(s, R(14) == 0);

    if (R(14) == 0) {
        /* no node: there is no operation to run */
        R(0) = 0;
        R(14) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
        s->pc = R(16);
        return ram->oob == 0;
    }

    /* the operation the node names, and the jump to it: the guest pops r14
     * and leaves its own pr in place, so the operation returns to the
     * caller's caller */
    R(0) = vf3_mem_u32(ram, R(14) + N_F50);
    R(14) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    return vf3_matrix_family(R(0), s, ram);
}
