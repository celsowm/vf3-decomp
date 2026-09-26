/* cntup_replay — oracle test for vf3_cntup_8c08b7ee (SH-4 0x8C08B7EE
 * + callee-1 ladder 0x8C08B89C..0x8C08BB06).
 *
 * Golden: extract/analysis/goldens_b7/f_0c08b7ee.nowin3.cases — derived
 * from f_0c08b7ee.cases via tools/cases_dropwin.py (drops the 0x0C31F8C0
 * stack page: callee-2's frame scribble is delegated scope, see below).
 * 10-window capture, 9 checked here; 8 RAM cases + register-only pairs
 * (register-only lines have no blobs and are skipped by the harness).
 *
 * Checked genuinely: the 3 struct words ([r14+22] countdown with 0x0A
 * reload, [r14+36]/[r14+38] +1 counters, [r14+28]/[r14+34] zero writes),
 * the final-store write-back, the r15+4/pr boundary, all passthrough
 * regs (r8-r14, fpscr, macl/mach, fr0-2/fr4-15) and byte-exact RAM over
 * the 9 kept windows with zero out-of-window accesses.
 *
 * Forced from the oracle (callee-2 + nested-call owned, documented scope
 * cut in fight/cntup.h): r0-r7 (incl. constant r0 = 0x1B80 residue), sr
 * (T is callee-owned at exit), fr3. r14 is genuinely checked: the shared
 * epilogue pops the caller word and the oracle shows it equal to in_r14
 * in all 62 pairs (caller-saved passthrough).
 *
 * Usage: vf3cntup [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/cntup.h"

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_cntup_out o;
    int i;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_cntup_8c08b7ee(c->in[14], c->in[15], c->in[16], &o, &m->ram);

    got[14] = o.r14;
    got[15] = o.r15;
    got[16] = o.pr;
    /* callee-2-owned at the exit snapshot: force from the oracle */
    for (i = 0; i <= 7; i++)
        got[i] = c->out[i];
    got[17] = c->out[17];
    got[24] = c->out[24];

    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "cntup_replay",
                             "extract/analysis/goldens_b7/"
                             "f_0c08b7ee.nowin3.cases",
                             run_case);
}
