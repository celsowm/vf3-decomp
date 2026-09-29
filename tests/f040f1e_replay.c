#include <string.h>

#include "port_harness.h"
#include "fight/f040f1e.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    int i;
    memcpy(got, c->in, sizeof(got));
    /* The AICA 0xA080 alias is shadowed at its 0x00800000 bus address. */
    for (i = 0; i < m->ram.n; ++i)
        m->wins[i].base &= 0x0FFFFFFFu;
    vf3_f040f1e_8c040f1e(c->in, got, &m->ram);
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "f040f1e_replay",
                             "extract/analysis/goldens_040f1eext/f_0c040f1e.cases",
                             run_case);
}
