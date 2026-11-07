/* vmu_cmd_name.c - SH-4 0x8C0374B0: the save-operation name selector.
 *
 * The engine hands this function a command id in r4 and it answers with the
 * string that names that operation on the VMU / save-unit.  The id is one of
 * the engine's command enums, and the answer is a pointer to an ASCII string
 * the caller shows on screen:
 *
 *     0    -> "NOP"
 *     1    -> "CONNECTED"
 *     2    -> "DISCONNECTED"
 *     3    -> "FORMAT DISK"
 *     7    -> "DELETE FILE"
 *     0xb  -> "LOAD FILE"
 *     0xc  -> "SAVE FILE"
 *     else -> "UNKNOWN OPERATION"
 *
 * The strings are not stored inline - the function returns the *address* of
 * each one, read from the literal pool.  The pool holds one word per known
 * command (the address of its string, at 0x0c03754c...0x0c037564) and one
 * word for the fallback (0x0c037568).  The pool is ROM, so the port reads the
 * same eight addresses the guest reads.
 *
 * The function is a self-contained leaf: no calls, no FPU, no stack frame.
 * Its body is the whole 0x8C0374B0 selector: it copies r4 into r0, tests r0
 * against the seven known ids in order, and takes the first match, falling
 * back to the "UNKNOWN OPERATION" string.
 *
 * Two details the port has to keep:
 *
 *   * the **T bit** the guest leaves depends on the path: a matched id leaves
 *     T set (the matching compare just made it), the fallback leaves it clear
 *     (it is the last compare, r0 == 0xc, which has just failed);
 *   * r0 is overwritten twice - `mov r4, r0` at the entry, then the pool word
 *     on the matched path - so the answer in r0 is the string address, never
 *     the command id.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

/* The command ids the guest matches, in the order it tests them. */
static const uint32_t keys[7] = { 0u, 1u, 2u, 3u, 7u, 0xbu, 0xcu };

/* The pool word that holds each id's string address, in the same order. */
static const uint32_t pool[7] = {
    0x0c03754cu, 0x0c037550u, 0x0c037554u, 0x0c037558u,
    0x0c03755cu, 0x0c037560u, 0x0c037564u,
};

/* The fallback: "UNKNOWN OPERATION". */
#define POOL_DEFAULT 0x0c037568u

int vf3_vmu_cmd_name_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(0) = R(4);                       /* the command id */

    uint32_t pool_addr = POOL_DEFAULT;
    for (unsigned i = 0; i < 7; ++i) {
        set_t(s, R(0) == keys[i]);     /* the guest's cmp/eq keeps the id */
        if (R(0) == keys[i]) {
            pool_addr = pool[i];
            break;
        }
    }
    /* The fallback keeps the T bit of the last compare (r0 == 0xc), which is
     * clear - the id matched none of the seven. */

    R(0) = vf3_mem_u32(ram, pool_addr);   /* the string's address */
    s->pc = R(16);                        /* the caller's return address */
    return ram->oob == 0;
}
