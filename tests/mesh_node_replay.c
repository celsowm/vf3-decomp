/* Paired RAM oracle replay for SH-4 0x8C068FE4. */
#include <stdio.h>

#include "port_harness.h"
#include "fight/mesh_node.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    float x = vf3h_f32(c->in[25]);
    float y = vf3h_f32(c->in[26]);
    int got = vf3_mesh_node_classify(c->in[4], x, y, &m->ram);
    if (got != (int)c->out[0]) {
        snprintf(err, errlen, "r0 got %d want %u node=%08x root=%08x xy=%08x,%08x",
                 got, c->out[0], c->in[4],
                 vf3_ram_read32(&m->ram, 0x0C113A0Cu),
                 c->in[25], c->in[26]);
        return 0;
    }
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "mesh_node_replay",
                             "extract/analysis/goldens_68fe4_ram/"
                             "f_0c068fe4.cases", run_case);
}
