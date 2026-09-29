#include "port_harness.h"
#include "fight/fvecnorm070x.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    if (!vf3_fvecnorm070x_8c0708b0(c->in, got, &m->ram)) {
        snprintf(err, errlen, "unmodeled FSRRA input");
        return 0;
    }
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "fvecnorm070x_boundary_replay",
                             "extract/analysis/goldens_070x_boundary_cases/f_0c0708b0_boundary.cases",
                             run_case);
}
