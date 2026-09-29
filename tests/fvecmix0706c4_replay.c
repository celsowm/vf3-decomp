#include "port_harness.h"
#include "fight/fvecmix0706c4.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    uint32_t transfer = 0;
    if (!vf3_fvecmix0706c4_8c0706c4(c->in, got, &transfer, &m->ram)) {
        snprintf(err, errlen, "unmodeled 0706C4 path/input");
        return 0;
    }
    uint32_t expected_target;
    switch (transfer) {
    case 0x0C070734u:
    case 0x0C070774u:
        expected_target = 0x0C070878u;
        break;
    case 0x0C070766u:
        expected_target = 0x0C0707B2u;
        break;
    case 0x0C0707AEu:
        expected_target = 0x0C070854u;
        break;
    default:
        snprintf(err, errlen, "unknown first-transfer PC %08x", transfer);
        return 0;
    }
    if (got[3] != expected_target) {
        snprintf(err, errlen, "transfer %08x target %08x, expected %08x",
                 transfer, got[3], expected_target);
        return 0;
    }
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "fvecmix0706c4_boundary_replay",
        "extract/analysis/goldens_0706c4_narrow/f_0c0706c4_boundary.cases",
        run_case);
}
