#include "port_harness.h"
#include "fight/fvecmix070852.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_fvecmix070852_8c070852(c->in, got, &m->ram);
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "fvecmix070852_boundary_replay",
        "extract/analysis/pairs_070852_boundary/f_0c070852_boundary.cases",
        run_case);
}
