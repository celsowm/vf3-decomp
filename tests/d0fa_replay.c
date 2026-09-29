/* Paired RAM oracle replay for SH-4 0x8C08D0FA. */
#include <stdio.h>

#include "port_harness.h"
#include "fight/d0fa.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got = vf3_d0fa_update(c->in[0], c->in[3], c->in[4],
                                    c->in[13], c->in[5], c->in[15],
                                    c->in[16], &m->ram);
    if (got != c->out[0]) {
        snprintf(err, errlen, "r0 got %08x want %08x", got, c->out[0]);
        return 0;
    }
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "d0fa_replay",
                             "extract/analysis/goldens_d0fa_states1_16/"
                             "f_0c08d0fa.cases", run_case);
}
