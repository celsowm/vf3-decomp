/* loader_check_dispatch.c - SH-4 0x8C034A20: loader state check with fallback dispatch.
 *
 * The function checks a loader state structure and either returns (if ready)
 * or tail-transfers to the loader dispatch routine.
 *
 *   r3 = [0x0C0EA2EC]          // loader state object
 *   r2 = [r3]                  // first field of object
 *   r2 += 1                    // increment counter at [0x0C0EA2F8]
 *   [r3] = r2
 *   r3 = [0x0C0EA2EC]          // reload object pointer
 *   r0 = [r3]                  // load object again
 *   r0 = [r0 + 36]             // read field at offset 36
 *   if (r0 == 1) return;       // if ready, return (rts)
 *   bra 0x8C035238             // else tail-transfer to loader_dispatch_5238
 *
 * The literal pool holds:
 *   0x8C034A48: 0x0C0EA2EC (object pointer)
 *   0x8C034A5C: 0x0C0EA2F8 (counter pointer)
 *
 * The branch at 0x8C034A30 is a plain 'bt' (no delay slot), so the 'bra'
 * at 0x8C034A32 executes only when the branch is not taken.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the entry (masked) */
#define ENTRY 0x0c034a20u

/* literal pool addresses */
#define OBJ_PTR_ADDR  0x0c0ea2ecu   /* pointer to loader state object */
#define COUNTER_ADDR  0x0c0ea2f8u   /* counter to increment */

/* the tail-transfer target */
#define DISPATCH_TARGET 0x0c035238u

/* the continuation (next instruction after the branch) */
#define CONTINUE_PC 0x0c034a36u

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

int vf3_loader_check_dispatch_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* r3 = [0x0C0EA2EC] - load object pointer */
    R(3) = vf3_mem_u32(ram, OBJ_PTR_ADDR);

    /* r2 = [r3] - load first field of object (counter value) */
    R(2) = vf3_mem_u32(ram, R(3));

    /* r2 += 1 - increment the counter */
    R(2) = R(2) + 1u;

    /* [r3] = r2 - store incremented counter back */
    vf3_mem_set_u32(ram, R(3), R(2));

    /* r3 = [0x0C0EA2EC] - reload object pointer (literal pool) */
    R(3) = vf3_mem_u32(ram, OBJ_PTR_ADDR);

    /* r0 = [r3] - load object again */
    R(0) = vf3_mem_u32(ram, R(3));

    /* r0 = [r0 + 36] - read field at offset 36 */
    R(0) = vf3_mem_u32(ram, R(0) + 36u);

    /* cmp/eq #1,r0 - compare with 1 */
    set_t(s, R(0) == 1u);

    /* bt 0x8C034A36 - branch if equal (plain bt, no delay slot) */
    if (R(17) & 1u) {
        /* taken: return via rts */
        s->pc = R(16);
        return 1;
    }

    /* not taken: tail-transfer to loader_dispatch_5238 */
    s->v[16] = CONTINUE_PC;  /* pr for continuation (not used on tail) */
    vf3_matrix_call_alias_pc = DISPATCH_TARGET & 0x1fffffffu;
    vf3_matrix_call_alias = DISPATCH_TARGET & 0xff000000u;
    if (!vf3_matrix_family(DISPATCH_TARGET, s, ram)) return 0;

    /* tail transfer: the reference continues at the lost address */
    const uint32_t lost = s->pc;
    vf3_matrix_call_alias_pc = lost & 0x1fffffffu;
    vf3_matrix_call_alias = lost & 0xff000000u;
    if (!s->lost_pc) s->lost_pc = lost;
    if (!vf3_matrix_family(lost, s, ram)) return 0;
    return 1;
}