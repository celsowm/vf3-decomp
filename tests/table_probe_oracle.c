/* table_probe_oracle.c - the readable indexed table probe against the oracle.
 *
 * tests/table_probe_replay.c proves the readable port against the retained
 * generated translation.  This one proves it against the *oracle*: the
 * captured fight states in
 *
 *   extract/analysis/seventh_c5_cases/f_8c040378.cases
 *
 * (8 cases, three windows each: the literal pool at 0x0c040000 holding the
 * table-base pointer at 0x0c0403bc, the table at 0x0c19e310, and the stack at
 * 0x0c31f000 where the transient slot lands).  The leaf is call-free and
 * integer-only and touches no device register, so no sidecars and no supplied
 * pool are needed - the windows carry everything the guest reads or writes.
 * The harness compares the whole 37-register file, SR's T bit and every byte
 * of the windows, so a readable port that does not reproduce the exact
 * status, the preserved/overwritten registers, the transient stack slot or
 * the tail-return fails here.
 *
 * The captured cases all exercise the in-range path with a 0xffffffff table
 * entry (giving -2), so this leg pins that path directly; the differential
 * supplies the out-of-range and live-entry arms.
 */
#include "port_harness.h"

#include "fight/matrix_family.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_table_probe_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    vf3_matrix_state s;
    uint32_t got[VF3H_NVALS];

    memset(&s, 0, sizeof s);
    for (int i = 0; i < VF3H_NVALS; ++i) s.v[i] = c->in[i];
    s.budget = 1000000u;

    if (!vf3_table_probe_entry(&s, &m->ram)) {
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
    return vf3h_harness_main(argc, argv, "table_probe_oracle",
                             "extract/analysis/seventh_c5_cases/"
                             "f_8c040378.cases",
                             run_case);
}
