/* poly_classify_replay — oracle test for vf3_poly_classify (0x8C068FF6).
 *
 * Uses the shared port harness: replay each RAM-backed case through the port
 * and require the returned r0 to match plus a byte-exact whole-window
 * shadow-vs-exit diff (zero out-of-window accesses).
 *
 * Usage: vf3poly [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>

#include "port_harness.h"

#include "fight/poly_classify.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    float fr4 = vf3h_f32(c->in[25]);
    float fr5 = vf3h_f32(c->in[26]);
    int got = vf3_poly_classify(c->in[4], c->in[3], fr4, fr5, &m->ram);
    int want = (int)c->out[0];
    if (got != want) {
        snprintf(err, errlen, "r0 got %d want %d", got, want);
        return 0;
    }
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "poly_classify_replay",
                             "extract/analysis/goldens/f_0c068ff6.cases",
                             run_case);
}