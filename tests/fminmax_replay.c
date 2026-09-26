/* fminmax_replay — oracle test for vf3_fminmax_8c073fb4 (SH-4 0x8C073FB4).
 *
 * r2/r4/r6/r12/r14/pr/fpscr/macl/mach and fr0-fr3/fr11-fr15 pass through
 * (untouched / exit pops); r0/r1/r3/r5/r7, sr, fr4-fr10 come out of the
 * port. Usage: vf3fminmax [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/fminmax.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_fminmax_out o;
    int i;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_fminmax_8c073fb4(c->in[1], c->in[3], c->in[4], c->in[7], c->in[12],
                         c->in[14], c->in[15],
                         c->in[16], c->in[17], c->in[18],
                         vf3h_f32(c->in[25]),
                         &o, &m->ram);
    got[0] = o.r0;
    got[1] = o.r1;
    got[3] = o.r3;
    got[5] = o.r5;
    got[6] = 0;             /* 8c073fb6 mov #0,r6; never modified */
    got[7] = o.r7;
    got[15] = o.r15;
    got[17] = o.sr;
    got[25] = o.fr4;
    got[26] = o.fr5;
    got[27] = o.fr6;
    got[28] = o.fr7;
    got[29] = o.fr8;
    got[30] = o.fr9;
    got[31] = o.fr10;
    /* passthrough: untouched regs + exit pops + pr round-trip */
    for (i = 0; i < 37; i++) {
        switch (i) {
        case 0: case 1: case 3: case 5: case 7: case 15: case 17:
        case 25: case 26: case 27: case 28: case 29: case 30: case 31:
            break;
        case 6:
            got[i] = 0;
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
    return vf3h_harness_main(argc, argv, "fminmax_replay",
                             "extract/analysis/goldens_73fb4/"
                             "f_0c073fb4.cases",
                             run_case);
}
