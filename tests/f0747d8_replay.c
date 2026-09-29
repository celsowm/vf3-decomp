#include <string.h>

#include "port_harness.h"
#include "fight/f0747d8.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    memcpy(got, c->in, sizeof(got));
    vf3_f0747d8_8c0747d8(c->in, got, &m->ram);
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "f0747d8_replay",
                             "extract/analysis/goldens_0747d8ram4/f_0c0747d8.cases",
                             run_case);
}
