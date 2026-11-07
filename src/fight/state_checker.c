/* state_checker.c - SH-4 0x8C0355A0: checks a task/thread state structure
 * and conditionally calls a handler.
 *
 * The function:
 *   - Takes a state pointer in r4 (saved to r14)
 *   - Saves callee-saved r14 and pr (r16) to stack
 *   - If r14 == 0, returns immediately
 *   - Reads halfword at r14+0x48, if non-zero returns
 *   - Reads halfword at r14+0x4c, if == 2, tail-calls 0x0c035a4e
 *   - Otherwise writes 0 to r14+0x48 and returns
 *   - Restores r14 and r16 from stack before return
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

/* Entry point: r4 = state pointer */
int vf3_state_checker_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* Save callee-saved r14 and pr (r16) to stack */
    R(15) -= 4u;
    vf3_mem_set_u32(ram, R(15), R(14));
    R(15) -= 4u;
    vf3_mem_set_u32(ram, R(15), R(16));

    /* r14 = r4 (state pointer) */
    R(14) = R(4);

    /* if (r14 == 0) goto epilogue */
    set_t(s, R(14) == 0);
    if (R(17) & 1u) {
        goto epilogue;
    }

    /* Read halfword at r14 + 0x48 */
    R(0) = 0x00000048u;
    R(2) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(14) + R(0));

    /* if (r2 != 0) goto epilogue */
    set_t(s, R(2) == 0);
    if ((R(17) & 1u) == 0) {
        goto epilogue;
    }

    /* Read halfword at r14 + 0x4c into r0. */
    R(0) = 0x0000004cu;
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(14) + R(0));

    /* if (r0 == 2) tail-call 0x0c035a4e */
    set_t(s, R(0) == 0x00000002u);
    if (R(17) & 1u) {
        /* Tail call: r4 = r14 (state pointer), return to 0x0c0355be */
        R(4) = R(14);
        uint32_t target = 0x0c035a4eu;
        uint32_t ret_addr = 0x0c0355beu;
        s->v[16] = ret_addr;
        vf3_matrix_call_alias_pc = target & 0x1fffffffu;
        vf3_matrix_call_alias = target & 0xff000000u;
        if (!vf3_matrix_family(target, s, ram)) return 0;
        while ((s->pc & 0x1fffffffu) != (ret_addr & 0x1fffffffu)) {
            const uint32_t lost = s->pc;
            vf3_matrix_call_alias_pc = lost & 0x1fffffffu;
            vf3_matrix_call_alias = lost & 0xff000000u;
            if (!vf3_matrix_family(lost, s, ram)) return 0;
            if ((s->pc & 0x1fffffffu) == (lost & 0x1fffffffu)) return 0;
        }
    }

    /* Write 0 to r14 + 0x48 */
    R(0) = 0x00000048u;
    R(3) = 0x00000000u;
    vf3_mem_set_u16(ram, R(14) + R(0), (uint16_t)R(3));

epilogue:
    /* Restore r16 (pr) and r14 from stack */
    R(16) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    R(14) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;

    /* Return to caller */
    s->pc = R(16);
    return ram->oob == 0;
}
