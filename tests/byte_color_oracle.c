/* byte_color_oracle.c - the readable two-byte color scale against the oracle.
 *
 * tests/byte_color_replay.c proves the readable port against the retained
 * generated translation.  This one proves it against the *oracle*: the
 * captured fight states in
 *
 *   extract/analysis/tenpp_arch_third_cases/f_8c0563ac.cases
 *
 * (128 cases, five windows each: the literal pool at 0x0c056000 holding
 * ptrA/scale/out, the source floats at 0x0c16b000, the output/bytes/scratch
 * at 0x0c19d000, and two more the capture carries).  The leaf is call-free,
 * branch-free FP and touches no device register, so no sidecars and no
 * supplied pool are needed - the windows carry everything the guest reads or
 * writes.  The harness compares the whole 37-register file, SR's T bit,
 * every byte of the windows and the OOB counter; the FR registers are part
 * of the 37, and the FPUL (r53) is additionally compared by the harness's
 * register comparison when the port leaves it different, so a readable port
 * that does not reproduce the exact scaled float channels, the packed-byte
 * unpacking, the three descending output stores or the register/FPUL
 * results fails here.
 */
#include "port_harness.h"

#include "fight/matrix_family.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_byte_color_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    vf3_matrix_state s;
    uint32_t got[VF3H_NVALS];

    memset(&s, 0, sizeof s);
    for (int i = 0; i < VF3H_NVALS; ++i) s.v[i] = c->in[i];
    s.budget = 1000000u;

    if (!vf3_byte_color_entry(&s, &m->ram)) {
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
    return vf3h_harness_main(argc, argv, "byte_color_oracle",
                             "extract/analysis/tenpp_arch_third_cases/"
                             "f_8c0563ac.cases",
                             run_case);
}
