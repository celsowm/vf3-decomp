/* slot_claim_oracle.c - the readable slot-claim scan against the oracle.
 *
 * tests/slot_claim_replay.c proves the readable port against the retained
 * generated translation.  This one proves it against the *oracle*: the
 * captured fight states in
 *
 *   extract/analysis/continuation_allocator_pool_long_dev/f_8c062490.cases
 *
 * (506 cases, two windows each at 0x0c062000 and 0x0c16c000, all len 0x1000:
 * the literal pool holding the count at 0x0c06258a and the base pointer at
 * 0x0c062590, and the slot array the base points into).  The leaf is call-free
 * and integer-only and touches no device register and no stack, so no sidecars
 * and no supplied pool are needed - the windows carry everything the guest
 * reads or writes.  The harness compares the whole 37-register file, SR's T bit
 * and every byte of the windows, so a readable port that does not reproduce the
 * exact scan, the mark or the returned slot address fails here.
 */
#include "port_harness.h"

#include "fight/matrix_family.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_slot_claim_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    vf3_matrix_state s;
    uint32_t got[VF3H_NVALS];

    memset(&s, 0, sizeof s);
    for (int i = 0; i < VF3H_NVALS; ++i) s.v[i] = c->in[i];
    s.budget = 1000000u;

    if (!vf3_slot_claim_entry(&s, &m->ram)) {
        snprintf(err, errlen, "the port failed (oob %u)", m->ram.oob);
        return 0;
    }
    if (m->ram.oob) {
        snprintf(err, errlen, "%u out-of-window accesses", m->ram.oob);
        return 0;
    }

    for (int i = 0; i < VF3H_NVALS; ++i) got[i] = s.v[i];
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "slot_claim_oracle",
                             "extract/analysis/continuation_allocator_pool_"
                             "long_dev/f_8c062490.cases",
                             run_case);
}
