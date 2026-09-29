#include <string.h>

#include "port_harness.h"
#include "fight/f9f354.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    if (!vf3_f9f354(c->in, got, &m->ram)) {
        snprintf(err, errlen, "helper accessed outside captured RAM windows");
        return 0;
    }
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "f9f354_replay",
                             "extract/analysis/goldens_f9f9a8_full/"
                             "f_0c09f354.cases", run_case);
}
