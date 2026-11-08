/* aim_midpoints_oracle.c - the readable aim-midpoints builder
 * (SH-4 0x8C09E428) against the oracle.
 *
 * tests/aim_midpoints_replay.c proves the readable port against the
 * retained generated translation.  This one proves it against the *oracle*:
 * 0x8C09E428 has no corpus of its own, so its evidence is indirect and
 * comes from the corpus whose call tree does contain it:
 *
 *   extract/analysis/native_pose_orchestration_s29_v1/f_8c09eaf2.cases
 *
 * For that corpus the specimen starts at the corpus' own entry
 * (0x8C09EAF2) and the hook serves the aim-midpoints builder readably, so
 * the recorded exit state of the whole specimen - the actor's fields, the
 * matrix bank and every RAM window - is the oracle's own record of what
 * the builder did.  The test counts how often the hook was actually
 * asked for the entry, so a corpus that never reaches it cannot pass
 * vacuously.
 *
 * The corpus touches device registers and carries the XF / FPUL / GBR /
 * banked sidecars, so the specimen needs them; tests/oracle_sidecars.h
 * carries them.
 */
#include "port_harness.h"
#include "oracle_sidecars.h"

#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_aim_midpoints_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c09e428u

static vf3h_sidecars sc;
static uint32_t g_entry;      /* the entry the specimen starts at */
static unsigned g_served;     /* how often the hook was asked for the port */

static int hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                int *handled)
{
    if ((entry & 0x1fffffffu) != ENTRY) { *handled = 0; return 0; }
    *handled = 1;
    ++g_served;
    return vf3_aim_midpoints_entry(s, ram);
}

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    vf3_matrix_state state;
    memset(&state, 0, sizeof state);
    state.budget = 4000000u;
    for (int i = 0; i < VF3H_NVALS; ++i) state.v[i] = c->in[i];

    /* The alias handoff is per case: a stale one from the previous case
     * would give the entry the wrong mirror (0x0c/0x8c/0xac). */
    vf3_matrix_call_alias = 0u;
    vf3_matrix_call_alias_pc = 0xffffffffu;

    if (!vf3h_sidecars_load(&sc, c, &state, &m->ram, err, errlen)) return 0;

    vf3_family_override = hook;
    const int ok = vf3_matrix_family(g_entry, &state, &m->ram);
    vf3_family_override = NULL;
    if (!ok) {
        snprintf(err, errlen, "the port failed (oob %u, pc %08x, failed %08x)",
                 m->ram.oob, state.pc, state.failed_pc);
        return 0;
    }
    if (!vf3h_sidecars_devices_ok(&sc, err, errlen)) return 0;

    if (!vf3h_regs_ok(c, state.v, err, errlen)) return 0;
    for (unsigned i = 0; i < 16; ++i)
        if (state.v[37 + i] != sc.wantxf[i]) {
            snprintf(err, errlen, "XF%u: %08x != %08x", i,
                     state.v[37 + i], sc.wantxf[i]);
            return 0;
        }
    if (state.v[53] != sc.aux[1]) {
        snprintf(err, errlen, "FPUL: %08x != %08x", state.v[53], sc.aux[1]);
        return 0;
    }
    if (state.pc != sc.aux[3]) {
        snprintf(err, errlen, "exit PC: %08x != %08x", state.pc, sc.aux[3]);
        return 0;
    }
    if (state.gbr_known && state.gbr != sc.global[1]) {
        snprintf(err, errlen, "GBR differs");
        return 0;
    }
    if (sc.bank_valid && memcmp(state.bank, sc.bank_state + 9, sizeof(state.bank))) {
        snprintf(err, errlen, "banked registers differ");
        return 0;
    }
    return vf3h_mem_ok(m, err, errlen);
}

static uint32_t entry_of(const char *path)
{
    const char *base = strrchr(path, '/');
    base = base ? base + 1 : path;
    const char *p = strstr(base, "f_");
    if (!p) return 0;
    char hex[16];
    size_t n = 0;
    for (p += 2; n + 1 < sizeof hex && *p && *p != '.'; ++n, ++p)
        hex[n] = *p;
    hex[n] = 0;
    return (uint32_t)strtoul(hex, NULL, 16) & 0x1fffffffu;
}

int main(int argc, char **argv)
{
    const char *path = argc > 1
        ? argv[1]
        : "extract/analysis/native_pose_orchestration_s29_v1/f_8c09eaf2.cases";
    char stem[1200];
    snprintf(stem, sizeof stem, "%s", path);
    {
        char *ext = strrchr(stem, '.');
        if (ext) *ext = 0;
    }
    if (!vf3h_sidecars_open(&sc, stem)) {
        fprintf(stderr, "the corpus's sidecars are missing\n");
        return 2;
    }
    g_entry = entry_of(path);
    if (!g_entry) {
        fprintf(stderr, "the corpus' name carries no entry\n");
        vf3h_sidecars_close(&sc);
        return 2;
    }
    g_served = 0;
    /* A module that reaches a register-indirect jump whose target it was
     * not generated with stops at that target with the jump already taken;
     * the reference continues there as the tail transfer it is. */
    vf3_family_tail_retry = 1;
    char *args[] = { (char *)"vf3rootorientationoracle", (char *)path };
    const int result = vf3h_harness_main(2, args, "aim_midpoints_oracle",
                                         path, run_case);
    if (result == 0 && !g_served) {
        fprintf(stderr, "the corpus never reached 0x%08x - the leg is "
                "vacuous\n", ENTRY);
        vf3h_sidecars_close(&sc);
        return 2;
    }
    if (result == 0)
        printf("aim_midpoints_oracle: the readable port served 0x%08x "
               "%u times\n", ENTRY, g_served);
    vf3h_sidecars_close(&sc);
    return result;
}
