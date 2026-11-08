/* scene_walk_oracle.c - the readable scene list walk against the oracle.
 *
 * tests/scene_walk_replay.c proves the readable port against the retained
 * generated translation.  This one proves it against the *oracle*: the
 * captured fight states in
 *
 *   extract/analysis/target_retained_scene_final_dev/f_8c06233e.cases
 *
 * (272 cases, four windows each at 0x0c062000, 0x0c0ea000, 0x0c16d000 and
 * 0x0c31f000, all len 0x1000: the literal pool holding the threshold pointer
 * at 0x0c06238c and the table base at 0x0c062384, the pool's table/threshold
 * region, the node region and the caller's stack where the flag word lands).
 * The leaf is call-free and integer-only and touches no device register, so no
 * sidecars and no supplied pool are needed - the windows carry everything the
 * guest reads or writes.  The harness compares the whole 37-register file,
 * SR's T bit and every byte of the windows, so a readable port that does not
 * reproduce the exact enable flag, the table lookup, the linked-list walk, the
 * returned node or the tail-return fails here.
 */
#include "port_harness.h"

#include "fight/matrix_family.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_scene_walk_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    vf3_matrix_state s;
    uint32_t got[VF3H_NVALS];

    memset(&s, 0, sizeof s);
    for (int i = 0; i < VF3H_NVALS; ++i) s.v[i] = c->in[i];
    s.budget = 1000000u;

    if (!vf3_scene_walk_entry(&s, &m->ram)) {
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
    return vf3h_harness_main(argc, argv, "scene_walk_oracle",
                             "extract/analysis/target_retained_scene_final_dev/"
                             "f_8c06233e.cases",
                             run_case);
}
