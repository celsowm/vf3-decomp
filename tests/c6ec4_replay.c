/* Replay test for the 0x8C0C6EC4 renderer state update. */
#include "port_harness.h"
#include "fight/c6ec4.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_c6ec4_8c0c6ec4(c->in, got, &m->ram);
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "c6ec4_replay",
                             "extract/analysis/goldens_c6ec4_ram/f_0c0c6ec4.cases",
                             run_case);
}
