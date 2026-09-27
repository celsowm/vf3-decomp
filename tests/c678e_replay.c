/* c678e_replay — oracle test for vf3_c678e_8c0c678e (SH-4 0x8C0C678E).
 *
 * r0-r15/pr/sr/fr0-fr15 come out of the port (r8-r14/fr12-fr15/pr via the
 * exit pops modeled as shadow reads; r10 genuinely differs from entry).
 * fpscr/macl/mach pass through (untouched). gated!=0 (untripped path)
 * fails loud.
 * Usage: vf3c678e [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/c678e.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_c678e_out o;
    int i;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_c678e_8c0c678e(c->in[0], c->in[1], c->in[2], c->in[3], c->in[4],
                       c->in[5], c->in[6], c->in[7], c->in[8], c->in[9],
                       c->in[10], c->in[11], c->in[12], c->in[13],
                       c->in[14], c->in[15], c->in[16], c->in[17],
                       c->in[18],
                       vf3h_f32(c->in[21]), vf3h_f32(c->in[22]),
                       vf3h_f32(c->in[23]), vf3h_f32(c->in[24]),
                       vf3h_f32(c->in[25]), vf3h_f32(c->in[26]),
                       vf3h_f32(c->in[27]), vf3h_f32(c->in[28]),
                       vf3h_f32(c->in[29]), vf3h_f32(c->in[30]),
                       vf3h_f32(c->in[31]), vf3h_f32(c->in[32]),
                       vf3h_f32(c->in[33]), vf3h_f32(c->in[34]),
                       vf3h_f32(c->in[35]), vf3h_f32(c->in[36]),
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
    return vf3h_harness_main(argc, argv, "c678e_replay",
                             "extract/analysis/goldens_c678e2/"
                             "f_0c0c678e.cases",
                             run_case);
}
