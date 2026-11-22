/* matrix_frame.c - SH-4 0x8C03D260 (matrix_frame_a), 0x8C03D280
 * (matrix_frame_b) and 0x8C03D2B0 (matrix_frame_c), natively.
 *
 * These are "evaluate a child transform and remember it" sequences built
 * from the matrix-stack helpers: each pushes XMTRX on the matrix stack,
 * multiplies in a parent (and in B's case a second parent first), stores the
 * result as a flat matrix in a fixed slot, and pops the stack back, all as a
 * tail of helper calls (call-free in the router sense - no indirect jump).
 *
 *   frame_A: push *(node+8);         concat_parent; store 0x0C19D4D8; pop
 *   frame_B: push *(node+8); concat *(parent+8); concat_parent; store
 *            0x0C19D4D8; pop
 *   frame_C: push *(parent+8);       concat_parent; store 0x0C19D498; pop
 *
 * with  node = 0x0C19D308, parent = 0x0C19D2FC (the +8 fields are the stack
 * tops of those control blocks).  The guest saves r15/pr itself, so the
 * helpers' own net-flat r15 handling stays within one saved frame.
 *
 * See docs/re/native_matrix_frame.md. */
#include "matrix_frame.h"

#include "aim_math.h"
#include "matrix_concat.h"
#include "matrix_concat_save.h"
#include "matrix_io.h"
#include "matrix_pop.h"
#include "matrix_push.h"

enum {
    NODE_PUSH   = 0x0C19D310u,   /* MATRIX_SLOT_NODE + 8  (0x0C19D308) */
    PARENT_PUSH = 0x0C19D304u,   /* MATRIX_SLOT_PARENT + 8 (0x0C19D2FC) */
    FLAT_A      = 0x0C19D4D8u,
    FLAT_C      = 0x0C19D498u,
};

static void frame_chain(vf3_native_aim *a, uint32_t push_from,
                        int concat_parent_matrix, uint32_t flat_slot)
{
    const uint32_t sp = a->r[15];
    const uint32_t pr = a->pr;

    vf3_aim_set_u32(a, sp - 4u, pr);
    a->r[15] = sp - 4u;

    a->r[4] = vf3_aim_u32(a, push_from);
    vf3_native_matrix_push(a);
    if (concat_parent_matrix) {
        a->r[4] = vf3_aim_u32(a, PARENT_PUSH);
        vf3_native_matrix_concat(a);
    }
    vf3_native_matrix_concat_parent(a);
    a->r[4] = flat_slot;
    vf3_native_matrix_store(a);
    a->r[4] = 1;
    vf3_native_matrix_pop(a);

    a->r[15] = sp;
    a->pr = pr;
}

void vf3_native_matrix_frame_a(vf3_native_aim *a)
{ frame_chain(a, NODE_PUSH, 0, FLAT_A); }

void vf3_native_matrix_frame_b(vf3_native_aim *a)
{ frame_chain(a, NODE_PUSH, 1, FLAT_A); }

void vf3_native_matrix_frame_c(vf3_native_aim *a)
{ frame_chain(a, PARENT_PUSH, 0, FLAT_C); }
