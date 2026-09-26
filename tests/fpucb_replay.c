/* fpucb_replay — oracle test for vf3_fpucb_8c09553c (gap unit U2).
 *
 * r0-r6/r15/fr0-fr7/fr15/sr come out of the port (r0/r1/r4/r5/r6/fr1-fr3/sr
 * via the nested U1 calls); every other register and the whole RAM shadow
 * must equal the oracle exit exactly.
 * Usage: vf3fpucb [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/fpucb.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_fpucb_out o;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_fpucb_8c09553c(c->in[1], c->in[4], c->in[5], c->in[6], c->in[14],
                       c->in[15], c->in[16], c->in[17], c->in[18],
                       vf3h_f32(c->in[36]), &o, &m->ram);
    got[0] = o.r0;
    got[1] = o.r1;
    got[2] = o.r2;
    got[3] = o.r3;
    got[4] = o.r4;
    got[5] = o.r5;
    got[6] = o.r6;
    got[15] = o.r15;
    got[17] = o.sr;
    got[21] = o.fr0;
    got[22] = o.fr1;
    got[23] = o.fr2;
    got[24] = o.fr3;
    got[25] = o.fr4;
    got[26] = o.fr5;
    got[27] = o.fr6;
    got[28] = o.fr7;
    got[36] = o.fr15;
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "fpucb_replay",
                             "extract/analysis/goldens_s8b/f_0c09553c.cases",
                             run_case);
}
