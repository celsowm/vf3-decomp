/* g06f6f8_replay — oracle test for vf3_g06f6f8_8c06f6f8 (SH-4 0x8C06F6F8).
 *
 * r0/r4/r5/sr(T)/fr0-fr4 come out of the port; every other register passes
 * through untouched. gated!=0 (small-|v| tail path to 0x8C06F75C, outside
 * the 88 B) fails loud. The whole RAM shadow must equal the oracle exit
 * exactly with zero out-of-window accesses.
 *
 * EVIDENCE (2026-09-27, see src/fight/g06f6f8.h): the goldens_ab batch
 * exit snapshot is degenerate — all 64 lines share one byte-identical
 * out-vector and exit-RAM blob (md5 3e5a1c6e16aee54aed4008e394ed6433)
 * while entries vary, PR changes across a leaf (0c06f6a6 -> 0c06f43a),
 * and ~500 exit words lie outside any in-bounds store. Expect FAIL on
 * regs/RAM here; the port's in-bounds footprint (spill word) is verified
 * separately. Usage: vf3g06f6f8 [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/g06f6f8.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_g06f6f8_out o;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_g06f6f8_8c06f6f8(c->in[4], c->in[15],
                         vf3h_f32(c->in[21]), vf3h_f32(c->in[35]),
                         vf3h_f32(c->in[36]), c->in[18], &o, &m->ram);
    if (o.gated) {
        snprintf(err, errlen, "gated small-|v| tail to %08x taken (scope)",
                 o.tail_target);
        return 0;
    }
    got[0] = o.r0;
    got[4] = o.r4;
    got[5] = o.r5;
    got[17] = (c->in[17] & ~1u) | (o.T & 1u);
    got[21] = o.fr0;
    got[22] = o.fr1;
    got[23] = o.fr2;
    got[24] = o.fr3;
    got[25] = o.fr4;
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "g06f6f8_replay",
                             "extract/analysis/goldens_ab/f_0c06f6f8.cases",
                             run_case);
}
