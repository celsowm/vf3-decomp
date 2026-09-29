#include <string.h>

#include "port_harness.h"
#include "fight/f096258.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    memcpy(got, c->in, sizeof(got));
    vf3_f096258_8c096258(c->in, got, &m->ram);
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "f096258_replay",
                             "extract/analysis/goldens_96258_states37_40_41/"
                             "f_0c096258.cases", run_case);
}
