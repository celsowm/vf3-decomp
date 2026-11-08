/* tenpp_fill_oracle.c - the readable tenpp leaf filler against the oracle.
 *
 * tests/tenpp_fill_replay.c proves the readable port against the retained
 * generated translation.  This one proves it against the *oracle*: the
 * captured fight states in
 *
 *   extract/analysis/tenpp_arch_third_cases/f_8c0c103c.cases
 *
 * (128 cases, one window each: 0x0c404000 / len 0x2000, which holds both the
 * node the function fills and the auxiliary cell it clears).  The leaf is
 * call-free and touches no device register and no stack, so no sidecars and no
 * supplied pool are needed - the window carries everything the guest reads or
 * writes.  The harness compares the whole 37-register file and every byte of
 * the window, so a readable port that does not reproduce the exact node/cell
 * stores, the output registers or the tail-return fails here.
 */
#include "port_harness.h"

#include "fight/matrix_family.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_tenpp_fill_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    vf3_matrix_state s;
    uint32_t got[VF3H_NVALS];

    memset(&s, 0, sizeof s);
    for (int i = 0; i < VF3H_NVALS; ++i) s.v[i] = c->in[i];
    s.budget = 1000000u;

    if (!vf3_tenpp_fill_entry(&s, &m->ram)) {
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
    return vf3h_harness_main(argc, argv, "tenpp_fill_oracle",
                             "extract/analysis/tenpp_arch_third_cases/"
                             "f_8c0c103c.cases",
                             run_case);
}
