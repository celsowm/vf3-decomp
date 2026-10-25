/* state_rotate_oracle.c - the readable fighter-vector rotator (SH-4 0x8C06DEC6)
 * against the oracle corpus.
 *
 * tests/state_rotate_replay.c proves the readable port against the retained
 * generated translation.  This one proves it against the *oracle*: the captures
 * in extract/analysis/fight_all_cases/f_8c06dec6.cases (192 specimens) and
 * extract/analysis/fight_release_cases/f_8c06dec6.cases (256), over six RAM
 * windows - the literal pool, the helper's pool, the two leaves' pool, the
 * fighter's struct and the tables.
 *
 * The port calls the rotation helper (0x8C09553C), which the tree has *not*
 * been ported, so the run has to go through the dispatcher.  The dispatcher
 * would also let the readable table pre-empt the helper's own leaves - the
 * tree's readable sin_u16 and cos_u16 sit at the addresses the helper calls -
 * and those leaves leave a different r4 behind than the code the oracle ran.
 * So the hook this test installs serves *only* the entry under test: the
 * helper and its leaves stay on the generated chain, exactly as they were when
 * the oracle captured them.
 *
 * The corpus holds the whole register file (r0..r15, pr, sr, fpscr, macl,
 * mach and fr0..fr15) and the six RAM windows, so the comparison covers every
 * register, the XF registers, the FPUL, the GBR, the exit PC and every byte of
 * RAM.
 */
#include "port_harness.h"

#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_state_rotate_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c06dec6u

static FILE *xfin, *xfout, *extra, *gbr;

/* The hook: the entry under test is served readably, everything else - the
 * helper, its leaves - stays on the generated chain. */
static int hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                int *handled)
{
    if ((entry & 0x1fffffffu) != ENTRY) { *handled = 0; return 0; }
    *handled = 1;
    return vf3_state_rotate_entry(s, ram);
}

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    vf3_matrix_state state;
    uint32_t wantxf[16], aux[4], global[3];
    uint32_t got[VF3H_NVALS];

    memset(&state, 0, sizeof state);
    state.budget = 4000000u;
    for (int i = 0; i < VF3H_NVALS; ++i) state.v[i] = c->in[i];

    /* the sidecars carry the XF registers, the FPUL and the exit PC */
    if (fseek(xfin, (long)c->ordinal * 64, SEEK_SET) ||
        fseek(xfout, (long)c->ordinal * 64, SEEK_SET) ||
        fseek(extra, (long)c->ordinal * 16, SEEK_SET)) {
        snprintf(err, errlen, "missing extended state");
        return 0;
    }
    if (fread(state.v + 37, 4, 16, xfin) != 16 ||
        fread(wantxf, 4, 16, xfout) != 16 ||
        fread(aux, 4, 4, extra) != 4) {
        snprintf(err, errlen, "missing extended state");
        return 0;
    }
    state.v[53] = aux[0];
    if (fseek(gbr, (long)c->ordinal * 12, SEEK_SET) ||
        fread(global, 4, 3, gbr) != 3) {
        snprintf(err, errlen, "missing GBR state");
        return 0;
    }
    state.gbr = global[0];
    state.gbr_known = global[2];

    vf3_family_override = hook;
    const int ok = vf3_matrix_family(ENTRY, &state, &m->ram);
    vf3_family_override = NULL;
    if (!ok) {
        snprintf(err, errlen, "the port failed (oob %u, pc %08x)",
                 m->ram.oob, state.pc);
        return 0;
    }

    for (int i = 0; i < VF3H_NVALS; ++i) got[i] = state.v[i];
    if (!vf3h_regs_ok(c, got, err, errlen)) return 0;
    for (unsigned i = 0; i < 16; ++i)
        if (state.v[37 + i] != wantxf[i]) {
            snprintf(err, errlen, "XF%u: %08x != %08x", i,
                     state.v[37 + i], wantxf[i]);
            return 0;
        }
    if (state.v[53] != aux[1]) {
        snprintf(err, errlen, "FPUL: %08x != %08x", state.v[53], aux[1]);
        return 0;
    }
    if (state.pc != aux[3]) {
        snprintf(err, errlen, "exit PC: %08x != %08x", state.pc, aux[3]);
        return 0;
    }
    if (state.gbr_known && state.gbr != global[1]) {
        snprintf(err, errlen, "GBR differs");
        return 0;
    }
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    char path[1400], stem[1200];
    snprintf(stem, sizeof stem, "%s", argc > 1 ? argv[1]
            : "extract/analysis/fight_all_cases/f_8c06dec6.cases");
    {
        char *ext = strrchr(stem, '.');
        if (ext) *ext = 0;
    }
    snprintf(path, sizeof path, "%s.xfin.bin", stem); xfin = fopen(path, "rb");
    snprintf(path, sizeof path, "%s.xfout.bin", stem); xfout = fopen(path, "rb");
    snprintf(path, sizeof path, "%s.extra.bin", stem); extra = fopen(path, "rb");
    snprintf(path, sizeof path, "%s.gbr.bin", stem); gbr = fopen(path, "rb");
    if (!xfin || !xfout || !extra || !gbr) {
        fprintf(stderr, "state_rotate_oracle: the corpus's sidecars are missing\n");
        return 2;
    }
    {
        char *args[] = { argv[0], argc > 1 ? argv[1]
            : "extract/analysis/fight_all_cases/f_8c06dec6.cases" };
        const int result = vf3h_harness_main(argc > 1 ? 2 : 2, args,
                                              "state_rotate_oracle", args[1],
                                              run_case);
        fclose(xfin); fclose(xfout); fclose(extra); fclose(gbr);
        return result;
    }
}
