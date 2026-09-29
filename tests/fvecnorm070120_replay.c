#include "port_harness.h"
#include "fight/fvecnorm070120.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    if (!vf3_fvecnorm070120_8c070120(c->in, got, &m->ram)) {
        snprintf(err, errlen, "unmodeled 070120 path/input");
        return 0;
    }
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "fvecnorm070120_boundary_replay",
        "extract/analysis/goldens_070120_boundary_cases/f_0c070120_boundary.cases",
        run_case);
}
