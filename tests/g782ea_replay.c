/* g782ea_replay - oracle test for vf3_g782ea_8c0782ea (SH-4 0x8C0782EA).
 *
 * Threaded-VM fight dispatcher (BRAF switch, 19 tripped arms). Entry regs
 * + 10 RAM windows in, exit regs + windows out; gated!=0 (untripped path)
 * fails loud.
 * Usage: vf3g782ea [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/g782ea.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_g782ea_out o;
    int i;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_g782ea_8c0782ea(c->in[0], c->in[1], c->in[2], c->in[3], c->in[4],
                        c->in[5], c->in[6], c->in[7], c->in[8], c->in[9],
                        c->in[10], c->in[11], c->in[12], c->in[13],
                        c->in[14], c->in[15], c->in[16], c->in[17],
                        c->in[18],
                        c->in[21], c->in[22], c->in[23], c->in[24],
                        c->in[25], c->in[26], c->in[27], c->in[28],
                        c->in[29], c->in[30], c->in[31], c->in[32],
                        c->in[33], c->in[34], c->in[35], c->in[36],
                        &o, &m->ram);
    if (o.gated) {
        snprintf(err, errlen, "gated path %d taken (scope)", o.gated);
        return 0;
    }
    got[0] = o.r0;
    got[1] = o.r1;
    got[2] = o.r2;
    got[3] = o.r3;
    got[4] = o.r4;
    got[5] = o.r5;
    got[6] = o.r6;
    got[7] = o.r7;
    got[8] = o.r8;
    got[9] = o.r9;
    got[10] = o.r10;
    got[11] = o.r11;
    got[12] = o.r12;
    got[13] = o.r13;
    got[14] = o.r14;
    got[15] = o.r15;
    got[16] = o.pr;
    got[17] = o.sr;
    got[21] = o.fr0;
    got[22] = o.fr1;
    got[23] = o.fr2;
    got[24] = o.fr3;
    got[25] = o.fr4;
    got[26] = o.fr5;
    got[27] = o.fr6;
    got[28] = o.fr7;
    got[29] = o.fr8;
    got[30] = o.fr9;
    got[31] = o.fr10;
    got[32] = o.fr11;
    got[33] = o.fr12;
    got[34] = o.fr13;
    got[35] = o.fr14;
    got[36] = o.fr15;
    for (i = 0; i < 37; i++) {
        switch (i) {
        case 18: case 19: case 20:
            got[i] = c->in[i];
            break;
        default:
            break;
        }
    }
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "vf3g782ea",
                             "extract/analysis/goldens_782eo_rts/f_0c0782ea.cases",
                             run_case);
}
