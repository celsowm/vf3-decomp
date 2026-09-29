/* Paired replay gate for the non-baseline helper at 0x8C09F6FC. */
#include <stdio.h>
#include <stdlib.h>

#include "port_harness.h"
#include "fight/f9f6fc.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[37];
    vf3_f9f6fc_8c09f6fc(c->in, got, &m->ram);
    for (unsigned i = 0; i < 37; ++i) {
        if (got[i] != c->out[i]) {
            snprintf(err, errlen, "state[%u] got %08x want %08x",
                     i, got[i], c->out[i]);
            return 0;
        }
    }
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "f9f6fc_replay",
                             "extract/analysis/goldens_9f6fc_full/f_0c09f6fc.cases",
                             run_case);
}
