/* record_state_walk.c - SH-4 0x8C03550C: walk a record's node chain and
 * report the state the node is in.
 *
 * The record (r4) owns a vtable (its first word); slot 9 of that vtable
 * (offset 36) is the node's kind.  A kind of 2 means "no callback"; every
 * other kind calls the node callback - the function pointer in the global
 * at 0x8C0355EC - before the state is read.
 *
 * The state itself comes from the helper at 0x8C035A20, which reads the
 * record's field pair: a flag halfword at +0x48 and a code halfword at
 * +0x4C.  A record whose flag is clear has no code, and the helper answers
 * -10 for it.  The walk reads the code like this:
 *
 *   code 0        the node is empty      -> -32
 *   code 1        the walk is finished   -> 0
 *   codes 2..4    the walk goes on       -> next round
 *   codes 5, 6    the node holds a value  -> the halfword at +0x4E
 *   any other     a code the walk does not know -> -25
 *
 * Every round moves the walk cursor.  The cursor lives behind the global
 * pointer at 0x8C0355E8 and its first word is the current position; the
 * step from the previous position has to stay inside the limit in the
 * global halfword at 0x8C0355E4, or the walk ends with -21.  The previous
 * position is the cursor's own value from the last time the record's node
 * pointer (its word at +24) moved, and the value the cursor carried when
 * the walk started.
 *
 * The guest keeps the record in r14 and saves r14, r13, r12, r11, r10 and
 * pr around the work; the readable port does the same, so the stack words
 * it leaves in RAM are the ones the original left.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* The guest's globals, read through the RAM map. */
#define G_LIMIT    0x0c0355e4u   /* the step limit (a signed short) */
#define G_CURSOR   0x0c0355e8u   /* pointer to the walk cursor */
#define G_CALLBACK 0x0c0355ecu   /* the node callback */

/* The state getter the original calls (SH-4 0x8C035A20). */
#define STATE_GETTER 0x0c035a20u

/* The continuations the original left in pr.  The guest pushes pr before it
 * calls, so the pushed word is still in RAM when the call returns and the
 * readable port has to use the same addresses. */
#define CONT_CALLBACK 0x0c035530u
#define CONT_STATE    0x0c035534u

/* The guest's own result codes. */
#define RESULT_NO_NODE  0xffffffe0u   /* -32: the node is empty */
#define RESULT_BAD_CODE 0xffffffe7u   /* -25: a code the walk does not know */
#define RESULT_STEP_OVER 0xffffffebu  /* -21: the step ran past the limit */

/* The record's fields. */
#define NODE_VTABLE 0u
#define NODE_CURSOR 24u
#define NODE_FLAG   0x48u
#define NODE_CODE   0x4cu
#define NODE_VALUE  0x4eu
#define VTABLE_KIND 36u

/* The codes the walk knows. */
#define CODE_EMPTY      0u
#define CODE_DONE       1u
#define CODE_WALK_FIRST 2u
#define CODE_WALK_LAST  4u
#define CODE_VALUE_FIRST 5u
#define CODE_VALUE_LAST  6u

/* The kind that asks for no callback. */
#define KIND_NO_CALLBACK 2u

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

int vf3_record_state_walk_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* The guest saves r14, r13, r12, r11, r10 and pr, in that order, and
     * pops them in the other order on the way out. */
    const uint32_t sp = R(15);
    vf3_mem_set_u32(ram, sp - 4u, R(14));
    R(14) = R(4);
    vf3_mem_set_u32(ram, sp - 8u, R(13));
    vf3_mem_set_u32(ram, sp - 12u, R(12));
    vf3_mem_set_u32(ram, sp - 16u, R(11));
    vf3_mem_set_u32(ram, sp - 20u, R(10));
    vf3_mem_set_u32(ram, sp - 24u, R(16));
    R(15) = sp - 24u;

    R(3) = vf3_mem_u32(ram, G_CURSOR);
    R(13) = vf3_mem_u32(ram, R(3));
    R(12) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, G_LIMIT);
    R(10) = vf3_mem_u32(ram, G_CALLBACK);
    R(11) = vf3_mem_u32(ram, R(14) + NODE_CURSOR);

    for (;;) {
        if (!s->budget) { s->failed_pc = 0x0c035524u; return 0; }
        --s->budget;

        /* the node's kind comes out of its vtable */
        const uint32_t kind = vf3_mem_u32(ram, vf3_mem_u32(ram, R(14)) + VTABLE_KIND);
        set_t(s, kind == KIND_NO_CALLBACK);
        if (kind != KIND_NO_CALLBACK) {
            /* every other kind calls the node callback first */
            if (!vf3_guest_call(s, ram, R(10), CONT_CALLBACK)) return 0;
        }

        /* the state getter reads the record's field pair */
        R(4) = R(14);
        if (!vf3_guest_call(s, ram, STATE_GETTER, CONT_STATE)) return 0;
        const uint32_t code = R(0);
        R(4) = code;
        if (code == CODE_EMPTY) {
            R(0) = RESULT_NO_NODE;
            set_t(s, 1);
            break;
        }
        if (code == CODE_DONE) {
            R(0) = 0;
            set_t(s, 1);
            break;
        }
        if (code >= CODE_WALK_FIRST && code <= CODE_WALK_LAST) {
            /* the walk goes on: the cursor bookkeeping follows */
        } else if (code >= CODE_VALUE_FIRST && code <= CODE_VALUE_LAST) {
            R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(14) + NODE_VALUE);
            set_t(s, 1);
            break;
        } else {
            R(0) = RESULT_BAD_CODE;
            set_t(s, 0);
            break;
        }

        /* the cursor bookkeeping: the step is the distance the cursor moved */
        R(3) = vf3_mem_u32(ram, R(14) + NODE_CURSOR);
        set_t(s, R(11) == R(3));
        if (R(11) != R(3)) {
            /* the node moved: the previous position is the cursor's own */
            R(1) = vf3_mem_u32(ram, G_CURSOR);
            R(13) = vf3_mem_u32(ram, R(1));
        }
        R(3) = vf3_mem_u32(ram, G_CURSOR);
        R(4) = vf3_mem_u32(ram, R(3));
        R(4) -= R(13);
        set_t(s, R(4) > R(12));
        if (R(4) <= R(12)) continue;      /* the guest branches back to the top */
        R(0) = RESULT_STEP_OVER;
        break;
    }

    /* the guest pops pr, r10, r11, r12, r13 and r14 */
    R(16) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    R(10) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    R(11) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    R(12) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    R(13) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    R(14) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    s->pc = R(16);
    return ram->oob == 0;
}
