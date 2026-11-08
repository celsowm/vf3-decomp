/* fdiv_oracle.c - the readable float division helper against the oracle corpus.
 *
 * tests/fdiv_replay.c proves the readable port against the retained generated
 * translation.  This one proves it against the *oracle*: the captured fight
 * states in
 *
 *   extract/analysis/percentage_loaded_states_dev/
 *       percentage_loaded_states_dev_8c062b06_8c0533a4/f_8c0533a4.cases
 *
 * (40 cases, three windows each).  The three windows are the code region
 * 0x0c035000, the literal pool 0x0c053000 (which carries the four scratch
 * constants the guest reads from the image, so the receivable port finds them
 * as captured runtime state - unlike record-kind, whose pool was not in the
 * capture) and the stack 0x0c31f000.  The guest touches no device register, so
 * no sidecars are needed.
 *
 * The in->out register deltas in these cases match the port's contract: r0..r3
 * come back holding the caller's saved values (restored from sp+0/+4/+8/+12)
 * and r15 advances by twenty.  The harness compares the whole 37-register file
 * and every byte of every window, so a readable port that does not reproduce
 * the guest's exact cell write, T bit or stack traffic fails here.
 */
#include "port_harness.h"

#include "fight/matrix_family.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_fdiv_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    vf3_matrix_state s;
    uint32_t got[VF3H_NVALS];

    memset(&s, 0, sizeof s);
    for (int i = 0; i < VF3H_NVALS; ++i) s.v[i] = c->in[i];
    s.budget = 1000000u;

    if (!vf3_fdiv_entry(&s, &m->ram)) {
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
    return vf3h_harness_main(argc, argv, "fdiv_oracle",
                             "extract/analysis/percentage_loaded_states_dev/"
                             "percentage_loaded_states_dev_8c062b06_8c0533a4/"
                             "f_8c0533a4.cases",
                             run_case);
}
