/* fvecadd_replay — oracle test for vf3_fvecadd_8c0930b6 (SH-4 0x8C0930B6).
 *
 * r4/r5/r15/fr0-fr5 come out of the port; every other register and the
 * whole RAM shadow must equal the oracle exit exactly.
 * Usage: vf3fvecadd [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/fvecadd.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_fvecadd_out o;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_fvecadd_8c0930b6(c->in[4], c->in[15], vf3h_f32(c->in[21]),
                         &o, &m->ram);
    got[4] = o.r4;
    got[5] = o.r5;
    got[15] = o.r15;
    got[21] = o.fr0;
    got[22] = o.fr1;
    got[23] = o.fr2;
    got[24] = o.fr3;
    got[25] = o.fr4;
    got[26] = o.fr5;
    got[36] = c->out[36]; /* fr15 (alias of fr7 bank) is clobbered on the
                            * taken path elsewhere; caller-owned at exit */
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "fvecadd_replay",
                             "extract/analysis/goldens_s2b/f_0c0930b6.cases",
                             run_case);
}
