/* fvectail_replay — oracle test for vf3_fvectail_8c0930d4 (SH-4 0x8C0930D4).
 *
 * r4/r15/fr15 come out of the port; every other register and the whole
 * RAM shadow must equal the oracle exit exactly.
 * Usage: vf3fvectail [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/fvectail.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_fvectail_out o;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_fvectail_8c0930d4(c->in[4], c->in[15], vf3h_f32(c->in[21]),
                          &o, &m->ram);
    got[4] = o.r4;
    got[15] = o.r15;
    got[36] = o.fr15;
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "fvectail_replay",
                             "extract/analysis/goldens_s5b/f_0c0930d4.cases",
                             run_case);
}
