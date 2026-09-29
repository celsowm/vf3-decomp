/* RAM-shadow replay for SH-4 0x8C06951A. */
#include <stdio.h>
#include <stdlib.h>

#include "port_harness.h"
#include "fight/maplookup.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    int gated = 0;
    if (!vf3_maplookup_8c06951a(c->in, got, &m->ram, &gated)) {
        snprintf(err, errlen, "unmodeled path %d taken", gated);
        return 0;
    }
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "maplookup_replay",
                             "extract/analysis/goldens_6951a_ram/"
                             "f_0c06951a.cases", run_case);
}
