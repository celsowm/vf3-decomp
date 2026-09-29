/* Replay test for the 0x8C0B10AA vector and flag update. */
#include <string.h>

#include "port_harness.h"
#include "fight/b10aa.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_b10aa_8c0b10aa(c->in, got, &m->ram);
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "b10aa_replay",
                             "extract/analysis/goldens_b10aa_ram3/f_0c0b10aa.cases",
                             run_case);
}
