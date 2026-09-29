/* Differential replay for SH-4 0x8C0CBEFC. */
#include <string.h>

#include "port_harness.h"
#include "fight/cbefc.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    memcpy(got, c->in, sizeof(got));
    vf3_cbefc_8c0cbefc(c->in, got, &m->ram);
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "cbefc_replay",
                             "extract/analysis/goldens_covab28ram/f_0c0cbefc.cases",
                             run_case);
}
