/* fcmpsel_replay — oracle test for vf3_fcmpsel_8c0c7050 (SH-4 0x8C0C7050).
 *
 * r3/r7/fr3/fr4/fr5/fr6/sr come out of the port; every other register and
 * the whole RAM shadow must equal the oracle exit exactly.
 * Usage: vf3fcmpsel [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/fcmpsel.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_fcmpsel_out o;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_fcmpsel_8c0c7050(c->in[17], vf3h_f32(c->in[24]), vf3h_f32(c->in[25]),
                         vf3h_f32(c->in[26]), vf3h_f32(c->in[27]),
                         c->in[4], c->in[5], c->in[6], &o, &m->ram);
    got[3] = o.r3;
    got[7] = o.r7;
    got[17] = o.sr;
    got[24] = o.fr3;
    got[25] = o.fr4;
    got[26] = o.fr5;
    got[27] = o.fr6;
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "fcmpsel_replay",
                             "extract/analysis/goldens_s5b/f_0c0c7050.cases",
                             run_case);
}
