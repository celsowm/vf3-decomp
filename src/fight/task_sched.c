/* task_sched.c - the fight scheduler, SH-4 0x8C09616A.
 *
 * The engine keeps its work in a fixed table of task records. Once per
 * frame this walks the table, calls the handler of every enabled record
 * and steps to the next record by the record's own stride field (so records
 * may differ in size: 0x80, 0x280, 0x23A8, ...). The remaining-task count
 * lives in guest RAM, not a register, because handlers may read it.
 *
 * Record layout (what the walker touches; handlers own the rest):
 *   +0x00  u32 flags      bit 0 = enabled
 *   +0x08  u32 stride     byte distance to the next record
 *   +0x0C  u32 handler    guest entry, called with r4 = &record
 */
#include "fight/readable.h"

#define TASK_TABLE       0x0C1FE864u
#define TASK_COUNT_CELL  0x0C29BB84u
#define TASK_SLOTS       27u
#define TASK_FLAG_ENABLED 1u
#define TASK_OFF_FLAGS   0x00u
#define TASK_OFF_STRIDE  0x08u
#define TASK_OFF_HANDLER 0x0Cu
#define SCHED_RETURN_SITE 0x8C096188u   /* instruction after the handler call (P1 alias, as the hardware link register holds it) */

/* The original saves r14, r13, r12 and pr on the guest stack; handlers run
 * below that frame, so the frame is reproduced to keep stack contents
 * byte-identical. */
int vf3_task_sched_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    enum { R12 = 12, R13 = 13, R14 = 14, SP = 15, PR = 16, ARG0 = 4 };
    uint32_t sp = s->v[SP];
    const uint32_t saved_pr = s->v[PR], saved_r12 = s->v[R12],
                   saved_r13 = s->v[R13], saved_r14 = s->v[R14];

    vf3_mem_set_u32(ram, sp - 4, saved_r14);
    vf3_mem_set_u32(ram, sp - 8, saved_r13);
    vf3_mem_set_u32(ram, sp - 12, saved_r12);
    vf3_mem_set_u32(ram, sp - 16, saved_pr);
    s->v[SP] = sp - 16;

    uint32_t task = TASK_TABLE;
    vf3_mem_set_u32(ram, TASK_COUNT_CELL, TASK_SLOTS);
    uint32_t remaining;
    do {
        if (vf3_mem_u32(ram, task + TASK_OFF_FLAGS) & TASK_FLAG_ENABLED) {
            s->v[ARG0] = task;
            s->v[R14] = task;
            s->v[R13] = task;       /* the original keeps the cursor in r13 */
            s->v[R12] = TASK_COUNT_CELL;
            if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, task + TASK_OFF_HANDLER),
                                SCHED_RETURN_SITE))
                return 0;
        }
        /* Both the count and the stride are re-read after the handler. */
        remaining = vf3_mem_u32(ram, TASK_COUNT_CELL) - 1u;
        task += vf3_mem_u32(ram, task + TASK_OFF_STRIDE);
        vf3_mem_set_u32(ram, TASK_COUNT_CELL, remaining);
    } while (remaining > 0u);          /* unsigned compare, as cmp/hi */

    s->v[PR] = saved_pr;
    s->v[R12] = saved_r12;
    s->v[R13] = saved_r13;
    s->v[R14] = saved_r14;
    s->v[SP] = sp;
    s->pc = saved_pr;
    return 1;
}
