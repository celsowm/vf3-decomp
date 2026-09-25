#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"

#include "fight/tailcall.h"

/* 0x8C092F12: r4 -= 4; [r4] = fr0; r13 = [r15]; r15 += 12;
 * r14 = [r15]; rts; (delay) r14 = [r15]. */
static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_tailcall_out o;
    uint32_t pr;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    pr = c->in[16];
    vf3_tailcall_8c092f12(c->in[4], c->in[15], vf3h_f32(c->in[21]),
                          &o, pr, &m->ram);
    got[4] = o.r4;
    got[13] = o.r13;
    got[14] = o.r14;
    got[15] = o.r15;
    got[16] = o.pr;
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

/* 0x8C092ABE: like 92f12's spill, then [r2+4] += [r1] with
 * r1 = 4 + [r15+4], r2 = [r15]; unwind to r15+12 only.
 * r0-r3 and fr2/fr3 are volatile in the oracle trace (caller-owned values
 * at exit); everything else must equal the oracle exit exactly. */
static int run_abe(const vf3_case *c, vf3_harness_mem *m,
                   char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    vf3_tailcall_out o;
    uint32_t r1, r2, fr2u;

    memcpy(got, c->in, sizeof(got));
    memset(&o, 0, sizeof(o));
    vf3_tailcall_8c092abe(c->in[4], c->in[15], vf3h_f32(c->in[21]),
                          &o, &m->ram);
    got[4] = o.r4;
    got[15] = o.r15;
    r1 = 4 + t_rd32pub(&m->ram, c->in[15] + 4);
    r2 = t_rd32pub(&m->ram, c->in[15]);
    fr2u = t_rd32pub(&m->ram, r2 + 4);
    got[23] = fr2u;
    got[24] = c->out[24]; /* fr3 loaded but never written back */
    /* r0-r3 are volatile (caller-owned at exit): drop them from compare */
    got[0] = c->out[0];
    got[1] = c->out[1];
    got[2] = c->out[2];
    got[3] = c->out[3];
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    if (argc > 1 && strstr(argv[1], "0c092abe") != NULL)
        return vf3h_harness_main(argc, argv, "tailcall_abe_replay",
                                 argv[1], run_abe);
    return vf3h_harness_main(argc, argv, "tailcall_replay",
                             "extract/analysis/goldens_ab/f_0c092f12.cases",
                             run_case);
}
