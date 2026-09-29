/* Replay test for the 0x8C0CC148 vector transform. */
#include <stdio.h>
#include <string.h>

#include "port_harness.h"
#include "fight/cc148.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    vf3_cc148_state in, out;
    uint32_t got[VF3H_NVALS];

    memcpy(got, c->in, sizeof(got));
    memcpy(in.r, c->in, sizeof(in.r));
    in.pr = c->in[16]; in.sr = c->in[17]; in.fpscr = c->in[18];
    memcpy(in.fr, c->in + 21, sizeof(in.fr));
    memset(&out, 0, sizeof(out));
    vf3_cc148_8c0cc148(&in, &out, &m->ram);

    got[0] = out.r[0]; got[1] = out.r[1]; got[3] = out.r[3];
    got[4] = out.r[4]; got[5] = out.r[5]; got[6] = out.r[6];
    got[12] = out.r[12]; got[13] = out.r[13]; got[14] = out.r[14];
    got[15] = out.r[15]; got[16] = out.pr; got[17] = out.sr;
    for (int i = 0; i <= 8; i++)
        got[21 + i] = out.fr[i];
    got[36] = out.fr[15];
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "cc148_replay",
                             "extract/analysis/goldens_cc148_ram3/f_0c0cc148.cases",
                             run_case);
}
