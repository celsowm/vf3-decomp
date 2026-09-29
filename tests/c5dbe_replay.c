/* Replay test for the 0x8C0C5DBE resource lookup. */
#include <string.h>

#include "port_harness.h"
#include "fight/c5dbe.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    for (int i = 0; i < m->ram.n; i++)
        m->wins[i].base &= 0x0FFFFFFFu;
    vf3_c5dbe_8c0c5dbe(c->in, got, &m->ram);
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "c5dbe_replay",
                             "extract/analysis/goldens_c5dbe_ram4/f_0c0c5dbe.cases",
                             run_case);
}
