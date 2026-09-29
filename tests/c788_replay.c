/* Paired register+RAM replay for SH-4 0x8C08C788. */
#include "port_harness.h"
#include "fight/c788.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    if (vf3_c788_guard(c->in, got, &m->ram)) {
        snprintf(err, errlen, "uncovered random/remainder path");
        return 0;
    }
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    static const char *goldens[] = {
        "extract/analysis/goldens_c788_states30_44/f_0c08c788.cases",
        "extract/analysis/goldens_c788_force4/f_0c08c788.cases",
        "extract/analysis/goldens_c788_mod16/f_0c08c788.cases",
        "extract/analysis/goldens_c788_bound0/f_0c08c788.cases"
    };
    if (argc > 1)
        return vf3h_harness_main(argc, argv, "c788_replay", goldens[0], run_case);
    for (size_t i = 0; i < sizeof(goldens) / sizeof(goldens[0]); ++i) {
        char *args[] = { argv[0], (char *)goldens[i] };
        int rc = vf3h_harness_main(2, args, "c788_replay", goldens[i], run_case);
        if (rc != 0)
            return rc;
    }
    return 0;
}
