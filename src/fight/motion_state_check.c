/* motion_state_check.c - SH-4 0x8C0355CA: motion state field checker with
 * conditional tail transfer.
 *
 * The function:
 *   - If r4 == 0, tail-calls to r16 with r0 = 0
 *   - Otherwise reads halfword at r4+0x48; if zero, returns with r0 = 0
 *   - If non-zero, reads word at r4+12 and stores it through the pointer in r5
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

int vf3_motion_state_check_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* If r4 == 0, tail-call to r16 with r0 = 0 */
    set_t(s, R(4) == 0);
    if (R(4) == 0) {
        R(0) = 0;
        s->pc = R(16);
        return ram->oob == 0;
    }

    /* Read halfword at r4 + 0x48 */
    R(0) = 0x00000048u;
    R(3) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(4) + R(0));

    /* If the halfword is zero, return 0 through r16. */
    set_t(s, R(3) == 0);
    if (R(3) == 0) {
        R(0) = 0;
        s->pc = R(16);
        return ram->oob == 0;
    }

    /* Read word at r4 + 12 */
    R(3) = vf3_mem_u32(ram, R(4) + 12u);

    /* The guest stores through r5 and reports success in r0. */
    vf3_mem_set_u32(ram, R(5), R(3));
    R(0) = 1;

    /* Tail-call to r16 (the address is already in s->pc after the test) */
    s->pc = R(16);
    return ram->oob == 0;
}
