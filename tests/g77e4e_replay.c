/* g77e4e_replay — oracle test for vf3_g77e4e_8c077e4e (gap unit).
 *
 * r7-r11/fr/mac passthrough (untouched / exit pops); r0-r6/r12-r15/pr/sr
 * come out of the port. gated==1 (nested-call path or ED4 data-block
 * path) fails loud. Usage: vf3g77e4e [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/g77e4e.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_g77e4e_out o;
    int i;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_g77e4e_8c077e4e(c->in[0], c->in[1], c->in[2], c->in[3], c->in[4],
                        c->in[5], c->in[6], c->in[7], c->in[8], c->in[9],
                        c->in[10], c->in[11], c->in[12], c->in[13],
                        c->in[14], c->in[15], c->in[16], c->in[17],
                        &o, &m->ram);
    if (o.gated) {
        snprintf(err, errlen, "gated path taken (scope)");
        return 0;
    }
    got[0] = o.r0;
    got[1] = o.r1;
    got[2] = o.r2;
    got[3] = o.r3;
    got[4] = o.r4;
    got[5] = o.r5;
    got[6] = o.r6;
    got[12] = o.r12;
    got[13] = o.r13;
    got[14] = o.r14;
    got[15] = o.r15;
    got[16] = o.pr;
    got[17] = o.sr;
    for (i = 0; i < 37; i++) {
        switch (i) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6:
        case 12: case 13: case 14: case 15: case 16: case 17:
            break;
        default:
            got[i] = c->in[i];
            break;
        }
    }
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "g77e4e_replay",
                             "extract/analysis/goldens_cascade/"
                             "f_0c077e4e.cases",
                             run_case);
}
