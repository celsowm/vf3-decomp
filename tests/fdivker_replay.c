/* fdivker_replay — oracle tests for the U1 range-reduction kernel
 * (gap units 0x8C03A6E0 and 0x8C03A140, shared body).
 *
 * r0/r3/r4/r6/fr0-fr7/sr come out of the port; every other register and
 * the whole RAM shadow must equal the oracle exit exactly.
 * Usage: vf3fdivker [cases_file]   (exit 0 = PASS)
 * Default runs both entry goldens.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/fdivker.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen, int alt_entry)
{
    uint32_t got[VF3H_NVALS];
    vf3_fdivker_out o;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    if (alt_entry)
        vf3_fdivker_8c03a140(c->in[1], c->in[4], c->in[14], c->in[5],
                             c->in[6], c->in[15], c->in[17], c->in[18],
                             &o, &m->ram);
    else
        vf3_fdivker_8c03a6e0(c->in[1], c->in[4], c->in[5], c->in[6],
                             c->in[15], c->in[17], c->in[18], &o, &m->ram);
    got[0] = o.r0;
    got[1] = o.r1;
    got[3] = o.r3;
    got[4] = o.r4;
    got[5] = o.r5;
    got[6] = o.r6;
    got[15] = o.r15;
    got[17] = o.sr;
    got[21] = o.fr0;
    got[22] = o.fr1;
    got[23] = o.fr2;
    got[24] = o.fr3;
    got[25] = o.fr4;
    got[26] = o.fr5;
    got[27] = o.fr6;
    got[28] = o.fr7;
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

static int run_case_main(const vf3_case *c, vf3_harness_mem *m,
                         char *err, size_t errlen)
{
    return run_case(c, m, err, errlen, 0);
}

static int run_case_alt(const vf3_case *c, vf3_harness_mem *m,
                        char *err, size_t errlen)
{
    return run_case(c, m, err, errlen, 1);
}

int main(int argc, char **argv)
{
    int rc;
    if (argc > 1)
        return vf3h_harness_main(argc, argv, "fdivker_replay", argv[1],
                                 strstr(argv[1], "3a140") ? run_case_alt
                                                          : run_case_main);
    rc = vf3h_harness_main(argc, argv, "fdivker_replay",
                           "extract/analysis/goldens_s8b/f_0c03a6e0.cases",
                           run_case_main);
    if (rc != 0)
        return rc;
    return vf3h_harness_main(argc, argv, "fdivker_replay",
                             "extract/analysis/goldens_s8b/f_0c03a140.cases",
                             run_case_alt);
}
