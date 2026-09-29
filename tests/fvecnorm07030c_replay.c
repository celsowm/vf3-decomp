#include "port_harness.h"
#include "fight/fvecnorm07030c.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    if (!vf3_fvecnorm07030c_8c07030c(c->in, got, &m->ram)) {
        snprintf(err, errlen, "unmodeled 07030C path/input");
        return 0;
    }
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "fvecnorm07030c_boundary_replay",
        "extract/analysis/goldens_07030c_boundary_cases/f_0c07030c_boundary.cases",
        run_case);
}
