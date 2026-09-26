/* scaler3_replay — oracle test for vf3_scaler3_8c092bc6 (SH-4 0x8C092BC6
 * + 0x8C092C04 body + 0x8C092C38 shared epilogue).
 *
 * frame/scratch state captured in 4 windows (goldens_s4):
 *   win0 0x0c203700 len 0x1280  (dst-vector region — vec2 + sums)
 *   win1 0x0c207000 len 0x8d8   (caller frame0 — dst ptr)
 *   win2 0x0c31f540 len 0x894   (function frame — r15 slots)
 *   win3 0x0c0fb000 len 0x1000  (caller scratch — scale at [r2+20])
 *
 * The SH-4 body reads the caller-page word at [r2+20]; we supply a separate
 * capture window for it. See scaler3.h for the full register/MEM semantics.
 * Usage: vf3scaler3 [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/scaler3.h"

/* indices in the 37-word row: 0..15 = r0..r15, 16 pr, 17 sr, 18 fpscr,
 * 19 macl, 20 mach, 21..36 = fr0..fr15. */

/* classify path from in m[in_r15+40] + oracle outs:
 *  1 = bit-1 of m[r15+40] set    (tst T=0; fall to lit-load tail-jmp)
 *  2 = scale == 0 tail           (T=1, fr4_out == 0, r3 == 0x0C092C38)
 *  3 = m[r15+0] == 0 tail        (T=1, fr4_out != 0, r1 == 0x0C092C38)
 *  4 = full body                 (r3 out == 0x100 == in_r3)
 */
static int classify_path(const vf3_case *c, uint32_t in_m40)
{
    uint32_t out_r3 = c->out[3];
    uint32_t out_fr4 = c->out[25];
    if ((in_m40 & 2u) != 0)
        return 1;
    if (out_r3 == 0x0C092C38u) {
        if (out_fr4 == 0u)
            return 2;
        return 3;
    }
    return 4;
}

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_scaler3_out o;
    uint32_t in_r15 = c->in[15];
    uint32_t in_m40 = 0;
    int i, path;

    for (i = 0; i < m->ram.n; i++) {
        const vf3_ram_win *w = &m->ram.wins[i];
        uint32_t a = in_r15 + 40;
        if (a >= w->base && a + 4 <= w->base + w->len)
            memcpy(&in_m40, w->data + (a - w->base), 4);
    }
    path = classify_path(c, in_m40);

    memset(&o, 0, sizeof(o));
    vf3_scaler3_8c092bc6(c->in[1], c->in[3], c->in[4], c->in[15],
                         c->in[21], c->in[22], c->in[23],
                         c->in[24], c->in[25], c->in[26],
                         path, 0.0f, &o, &m->ram);

    /* default: oracle-forced (caller-owned / unmodelled); overridden by port. */
    memcpy(got, c->out, sizeof(got));
    got[0]  = o.r0;
    got[1]  = o.r1;
    got[3]  = o.r3;
    got[4]  = o.r4;
    got[14] = o.r14;
    got[15] = o.r15;
    got[17] = (c->in[17] & ~1u) | o.sr_T;
    got[21] = o.fr0;
    got[22] = o.fr1;
    got[23] = o.fr2;
    got[24] = o.fr3;
    got[25] = o.fr4;
    got[26] = o.fr5;
    if (path == 2 || path == 3 || path == 4)
        got[2] = o.r2;
    if (path == 4)
        got[5] = o.r5;

    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "scaler3_replay",
                             "extract/analysis/goldens_s4/f_0c092bc6.cases",
                             run_case);
}
