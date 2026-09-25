/* scalemap_replay — oracle test for vf3_scalemap_8c068e16 (0x8C068E16).
 *
 * Each RAM-backed case is replayed through the port; the returned fr0 must
 * match the recorded exit fr0 bit-exactly and the whole-window shadow must
 * match the captured exit RAM.  selector/ctx come from entry r13/r14.
 *
 * Usage: vf3scalemap [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>

#include "port_harness.h"

#include "fight/scalemap.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    if (getenv("VF3_SCALEMAP_DBG"))
        fprintf(stderr, "DBG case entry=%s nentry=%d xexit=%s nexit=%d\n",
                c->entry, c->nentry, c->xexit, c->nexit);
    float fr4 = vf3h_f32(c->in[25]);        /* fr4 */
    float fr5 = vf3h_f32(c->in[26]);        /* fr5 */
    float got = vf3_scalemap_8c068e16(c->in[13], c->in[15], c->in[16],
                                      fr4, fr5, &m->ram);
    uint32_t gotb = vf3_scalemap_f32bits(got);
    if (gotb != c->out[21]) {
        snprintf(err, errlen, "fr0 got %08x want %08x", gotb, c->out[21]);
        return 0;
    }
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "scalemap_replay",
                             "extract/analysis/goldens_ab/f_0c068e16.cases",
                             run_case);
}