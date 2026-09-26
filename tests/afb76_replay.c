/* afb76_replay — oracle test for vf3_afb76_8c0afb76 (SH-4 0x8C0AFB76).
 *
 * r8-r14/fr14/fr15/pr/fpscr/macl/mach and fr8-fr13 pass through (exit
 * pops / untouched); r0-r7, sr, fr0-fr7 come out of the port (fr0-fr3/
 * fr6-fr7 via the nested U2 call on FPU paths, entry values otherwise).
 * Usage: vf3afb76 [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/afb76.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_afb76_out o;
    int i;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_afb76_8c0afb76(c->in[0], c->in[1], c->in[4], c->in[5], c->in[15],
                       c->in[16], c->in[17], c->in[18],
                       vf3h_f32(c->in[21]), vf3h_f32(c->in[22]),
                       vf3h_f32(c->in[23]), vf3h_f32(c->in[24]),
                       vf3h_f32(c->in[25]), vf3h_f32(c->in[26]),
                       vf3h_f32(c->in[27]), vf3h_f32(c->in[28]),
                       vf3h_f32(c->in[35]), vf3h_f32(c->in[36]),
                       &o, &m->ram);
    got[0] = o.r0;
    got[1] = o.r1;
    got[2] = o.r2;
    got[3] = o.r3;
    got[4] = o.r4;
    got[5] = o.r5;
    got[6] = o.r6;
    got[7] = o.r7;
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
    /* passthrough: exit pops restore the B62-B74 saves, pr round-trips */
    for (i = 8; i <= 14; i++)
        got[i] = c->in[i];
    got[16] = c->in[16];
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "afb76_replay",
                             "extract/analysis/goldens_afb76/"
                             "f_0c0afb76.cases",
                             run_case);
}
