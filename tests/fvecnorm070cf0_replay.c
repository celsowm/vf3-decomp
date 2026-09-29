#include "port_harness.h"
#include "fight/fvecnorm070cf0.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    if (!vf3_fvecnorm070cf0_8c070cf0(c->in, got, &m->ram)) {
        snprintf(err, errlen, "unmodeled 070CF0 path/input");
        return 0;
    }
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "fvecnorm070cf0_boundary_replay",
        "extract/analysis/goldens_070cf0_boundary_cases/f_0c070cf0_boundary.cases",
        run_case);
}
