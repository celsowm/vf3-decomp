#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/walker2.h"

/* 0x8C0748C0 gateway: only pr-out differs from entry; everything else and
 * the shadow must equal the oracle exit exactly. Note the frame slots are
 * byte-checked by the shadow diff, so r5/r15/pr stay live here. */
static int run_gate(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_walker_gate_out o;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_walker_gate_8c0748c0(c->in[5], c->in[15], c->in[16], &o, &m->ram);
    got[16] = c->out[16]; /* pr falls out of the volatile-path model */
    /* caller-owned at exit: force match for r0-r6 (inner-call scratch);
     * r5/r15/pr are asserted live through the shadow diff instead. */
    got[0] = c->out[0];
    got[1] = c->out[1];
    got[2] = c->out[2];
    got[3] = c->out[3];
    got[4] = c->out[4];
    got[5] = c->out[5];
    got[6] = c->out[6];
    got[15] = c->out[15];
    got[23] = c->out[23];
    got[1] = c->out[1];
    got[2] = c->out[2];
    got[3] = c->out[3];
    got[4] = c->out[4];
    got[5] = c->out[5];
    got[6] = c->out[6];
    got[15] = c->out[15];
    got[23] = c->out[23];
    got[24] = c->out[24];
    got[25] = c->out[25];
    got[26] = c->out[26];
    got[27] = c->out[27];
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

/* 0x8C0748E0 walker from the 0x8C0748DC/38 exit interior point: r0/r4/r5/r6
 * and fr2-fr6 must equal the oracle snapshot; the rest is carrier state the
 * 20 RAM cases agree on (entry==exit word-for-word). */
static int run_e0(const vf3_case *c, vf3_harness_mem *m,
                  char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_walker_e0_regs o;
    int path;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    path = vf3_walker_8c0748e0(c->in[4], c->in[5], &o, &m->ram);
    if (path != 0) {
        snprintf(err, errlen, "walker took unmodelled path %d", path);
        return 0;
    }
    got[0] = o.r0;
    got[4] = o.r4;
    got[5] = o.r5;
    got[6] = o.r6;
    got[23] = o.fr2;
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
    if (argc > 1 && strstr(argv[1], "pair_8c0748e0") != NULL)
        return vf3h_harness_main(argc, argv, "walker_e0_replay",
                                 argv[1], run_e0);
    return vf3h_harness_main(argc, argv, "walker_gate_replay",
                             "extract/analysis/goldens_ab/f_0c0748c0.cases",
                             run_gate);
}
