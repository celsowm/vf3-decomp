/* tailpath_replay — oracle test for vf3_tailpath_8c076c00 (path a).
 *
 * r4-r11/fr/mac passthrough (untouched); r0-r3, r12-r14 (caller-spill
 * pops), r15, pr, sr come out of the port. gated==1 (path b taken)
 * fails loud. Usage: vf3tailpath [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/tailpath.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_tailpath_out o;
    int i;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_tailpath_8c076c00(c->in[4], c->in[5], c->in[6], c->in[15],
                          c->in[16], c->in[17], &o, &m->ram);
    if (o.gated) {
        snprintf(err, errlen, "path-b taken (gated scope)");
        return 0;
    }
    got[0] = o.r0;
    got[1] = o.r1;
    got[2] = o.r2;
    got[3] = o.r3;
    got[12] = o.r12;
    got[13] = o.r13;
    got[14] = o.r14;
    got[15] = o.r15;
    got[16] = o.pr;
    got[17] = o.sr;
    for (i = 0; i < 37; i++) {
        switch (i) {
        case 0: case 1: case 2: case 3:
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
    return vf3h_harness_main(argc, argv, "tailpath_replay",
                             "extract/analysis/goldens_76c00/"
                             "f_0c076c00.cases",
                             run_case);
}
