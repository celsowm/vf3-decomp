#include <string.h>

#include "port_harness.h"
#include "fight/f9f9a8.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    memcpy(got, c->in, sizeof(got));
    int modeled = vf3_f9f9a8_guard(c->in, got, &m->ram);
    if (modeled < 0)
        return -1;
    if (modeled == 0) {
        snprintf(err, errlen, "guard path stack write outside captured RAM");
        return 0;
    }
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "f9f9a8_replay",
                             "extract/analysis/goldens_f9f9a8_full/"
                             "f_0c09f9a8.cases", run_case);
}
