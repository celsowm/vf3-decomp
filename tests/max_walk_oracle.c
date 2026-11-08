/* max_walk_oracle.c - the readable four-list gated max walk against the oracle.
 *
 * tests/max_walk_replay.c proves the readable port against the retained
 * generated translation.  This one proves it against the *oracle*: the
 * captured states in
 *
 *   extract/analysis/advance_resume_061910_dev/
 *     advance_resume_061910_dev_8c061910/f_8c061910.cases
 *
 * (512 cases, five windows each: the literal pool at 0x0c061000 holding the
 * struct pointer at 0x0c061a0c, the fight structure at 0x0c0ea000, the stack
 * at 0x0c31f000, the output words at 0x0c40d000 and the node region at
 * 0x0c40f000).  The leaf is call-free and integer-only and touches no device
 * register, so no sidecars and no supplied pool are needed - the windows carry
 * everything the guest reads or writes.  The harness compares the whole
 * 37-register file, SR's T bit, every byte of the windows and the OOB counter,
 * so a readable port that does not reproduce the exact maxima (into [r4]/[r5]),
 * the four list walks, the restored r12/r13/r14, r15 flat or the tail-return
 * fails here.
 */
#include "port_harness.h"

#include "fight/matrix_family.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_max_walk_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    vf3_matrix_state s;
    uint32_t got[VF3H_NVALS];

    memset(&s, 0, sizeof s);
    for (int i = 0; i < VF3H_NVALS; ++i) s.v[i] = c->in[i];
    s.budget = 1000000u;

    if (!vf3_max_walk_entry(&s, &m->ram)) {
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
    return vf3h_harness_main(argc, argv, "max_walk_oracle",
                             "extract/analysis/advance_resume_061910_dev/"
                             "advance_resume_061910_dev_8c061910/"
                             "f_8c061910.cases",
                             run_case);
}
