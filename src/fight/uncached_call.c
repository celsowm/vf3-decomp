/* uncached_call.c - SH-4 0x8C011984: an entry point called in its uncached
 * mirror, and the answer it gives back.
 *
 * The function takes a base in r3 and an offset in r0, adds them, forces the
 * result into the 0xac mirror and calls it.  The mirror mask is the literal
 * pool word at 0x8C011A78 (0xA0000000): the SH-4 mirrors the 0x0C000000
 * region at 0x8C000000 and again at 0xAC000000, so the mask turns any address
 * of the region into its 0xAC form - the uncached one.
 *
 * The answer is one when the callee left a non-zero r0 and zero when it left
 * zero.  The guest's own test is `tst r0,r0` - the T bit ends up *set* when
 * the answer is zero - and the `mov #1,r0` that follows is the **delay slot
 * of the `rts`**, not of the branch: the branch is a plain `bt`, and a plain
 * `bt` has no delay slot.  So the non-zero arm pops the pr and returns
 * through the `rts`, whose delay slot sets r0 to one, and the zero arm
 * branches to a `mov #0,r0` and returns through an `rts` of its own.
 *
 * The call has to carry two things the router cannot see:
 *
 *   - the continuation in pr is written with the code base, the mirror the
 *     run came through, so the callee comes back to the same mirror;
 *   - the callee is handed the mirror it was jumped to, because the router
 *     masks the entry PC to 29 bits and the mirror would be lost.  That is
 *     what `vf3_matrix_call_alias` / `vf3_matrix_call_alias_pc` are for.
 *
 * The port is reached through the readable hook, which only ever sees the
 * *masked* entry.  The mirror therefore comes from the alias the caller left
 * (every generated caller sets it), and a run that did not come through a
 * caller is in the 0x0C mirror - which is exactly what the generated module
 * computes for a masked entry.
 *
 * The port keeps the guest's own stack traffic: it pushes pr, and pops it
 * again on the way out.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the entry */
#define ENTRY 0x0c011984u

/* the literal pool: the mirror mask */
#define MIRROR_MASK 0x0c011a78u

/* the continuation the callee comes back to */
#define CONT 0x0c011992u

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

/* The mirror the run came through.  The caller leaves it in the alias; a run
 * that did not come through a caller is in the 0x0C mirror.
 */
static uint32_t code_base_of(void)
{
    if (vf3_matrix_call_alias_pc == (ENTRY & 0x1fffffffu)) return vf3_matrix_call_alias;
    return 0x0c000000u;
}

/* The guest's own call.  The continuation carries the mirror, and the callee
 * is handed the mirror it was jumped to.
 *
 * When the callee does not come back to the continuation the transfer is a
 * tail transfer: the reference continues at the address the callee left and
 * never comes back here, so the answer is never computed.  The port says so
 * through `tail`.
 */
static int guest_call(vf3_matrix_state *s, const vf3_ram_map *ram,
                      uint32_t target, uint32_t cont, int *tail)
{
    s->v[16] = cont;
    vf3_matrix_call_alias_pc = target & 0x1fffffffu;
    vf3_matrix_call_alias = target & 0xff000000u;
    if (!vf3_matrix_family(target, s, ram)) return 0;
    if ((s->pc & 0x1fffffffu) != (cont & 0x1fffffffu)) {
        /* the tail transfer: the reference continues at the lost address */
        const uint32_t lost = s->pc;
        vf3_matrix_call_alias_pc = lost & 0x1fffffffu;
        vf3_matrix_call_alias = lost & 0xff000000u;
        if (!s->lost_pc) s->lost_pc = lost;
        *tail = 1;
        if (!vf3_matrix_family(lost, s, ram)) return 0;
        return 1;
    }
    return 1;
}

int vf3_uncached_call_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t base = code_base_of();
    uint32_t target;
    int zero, tail = 0;

    /* the guest pushes its own pr */
    R(15) -= 4u;
    vf3_mem_set_u32(ram, R(15), R(16));

    /* the address: the base plus the offset, in the uncached mirror */
    R(3) += R(0);
    R(0) = R(3);
    R(2) = vf3_mem_u32(ram, MIRROR_MASK);
    R(0) |= R(2);
    target = R(0);

    /* the call */
    if (!guest_call(s, ram, target, base | CONT, &tail)) return 0;
    if (tail) return 1;   /* the answer is never computed on a tail transfer */

    /* the guest tests the callee's answer: zero means "no" */
    zero = (R(0) == 0);
    set_t(s, zero);
    R(0) = zero ? 0u : 1u;

    /* and pops its pr again */
    R(16) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    s->pc = R(16);
    return ram->oob == 0;
}
