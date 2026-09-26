/* g78044_replay — oracle test for vf3_g78044_8c078044 (gap unit).
 *
 * r1-r3/r5/r8-r15/pr/fpscr/macl/mach/fr passthrough (untouched / exit
 * pops); r0/r4/r6/r7, sr come out of the port. Usage:
 * vf3g78044 [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/g78044.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_g78044_out o;
    int i;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_g78044_8c078044(c->in[4], c->in[5], c->in[6], c->in[7], c->in[13],
                        c->in[14], c->in[15], c->in[17], &o, &m->ram);
    got[0] = o.r0;
    got[3] = o.r3;
    got[4] = o.r4;
    got[6] = o.r6;
    got[7] = o.r7;
    got[15] = o.r15;
    got[17] = o.sr;
    for (i = 0; i < 37; i++) {
        switch (i) {
        case 0: case 3: case 4: case 6: case 7: case 15: case 17:
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
    return vf3h_harness_main(argc, argv, "g78044_replay",
                             "extract/analysis/goldens_78044/"
                             "f_0c078044.cases",
                             run_case);
}
