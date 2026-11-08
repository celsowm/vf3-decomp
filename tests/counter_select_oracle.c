/* counter_select_oracle.c - the readable four-threshold counter selection
 * against the oracle.
 *
 * tests/counter_select_replay.c proves the readable port against the
 * retained generated translation.  This one proves it against the *oracle*:
 * the captured fight states in
 *
 *   extract/analysis/next_combined_cases/f_8c0c10a2.cases
 *
 * (70 cases, three windows each: the literal pool at 0x0c0c1000 holding the
 * five signed halfword constants and the base pointer, the target structure
 * at 0x0c29f000, and the stack at 0x0c31f000 where the pushed registers and
 * the 16-byte frame land).  The leaf is call-free and integer-only and
 * touches no device register, so no sidecars and no supplied pool are needed
 * - the windows carry everything the guest reads or writes.  The harness
 * compares the whole 37-register file, SR's T bit, every byte of the windows
 * and the OOB counter, so a readable port that does not reproduce the exact
 * handed-out counters, the four struct halfword writes, the frame, the
 * restored r13/r14, r15 flat or the tail-return fails here.
 */
#include "port_harness.h"

#include "fight/matrix_family.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_counter_select_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    vf3_matrix_state s;
    uint32_t got[VF3H_NVALS];

    memset(&s, 0, sizeof s);
    for (int i = 0; i < VF3H_NVALS; ++i) s.v[i] = c->in[i];
    s.budget = 1000000u;

    if (!vf3_counter_select_entry(&s, &m->ram)) {
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
    return vf3h_harness_main(argc, argv, "counter_select_oracle",
                             "extract/analysis/next_combined_cases/"
                             "f_8c0c10a2.cases",
                             run_case);
}
