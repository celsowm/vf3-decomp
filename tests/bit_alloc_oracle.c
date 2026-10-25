/* bit_alloc_oracle.c - the readable bit allocator (SH-4 0x8C038860) against the
 * oracle corpus.
 *
 * tests/bit_alloc_replay.c proves the readable port against the retained
 * generated translation.  This one proves it against the *oracle*: the 194
 * specimens in extract/analysis/next_dev_cases/f_8c038860.cases.
 *
 * The function calls nobody, so the hook this test installs serves *only* the
 * entry under test - and there is no helper whose leaves the readable table
 * could pre-empt.
 *
 * The corpus holds the whole register file (r0..r15, pr, sr, fpscr, macl, mach
 * and fr0..fr15) and the RAM windows, so the comparison covers every register,
 * the XF registers, the FPUL, the GBR, the exit PC and every byte of RAM -
 * and the word the guest writes into the table is one of those bytes.
 *
 * The corpus walks the **whole bit space**: the answers run from 0 to 0x90,
 * every bit number from 0 to 31 appears, and 149 of the 194 specimens skip at
 * least one exhausted slot - so the slot-skipping path, the mask's last step
 * and the word the guest writes are all covered.
 *
 * What the corpus does **not** pin down, and the differential has to: the
 * table with **no free bit at all** (the answer is -1 and nothing is
 * written) never happens in the 194 specimens, and neither does an empty
 * table.
 */
#include "port_harness.h"
#include "oracle_sidecars.h"

#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_bit_alloc_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c038860u

static vf3h_sidecars sc;
static uint32_t g_entry;      /* the entry the specimen starts at */
static uint32_t g_serve;      /* the entry the readable port serves */
static unsigned g_served;     /* how often the hook was asked for it */

/* The hook: the entry under test is served readably, everything else stays on
 * the generated chain. */
static int hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                int *handled)
{
    if ((entry & 0x1fffffffu) != g_serve) { *handled = 0; return 0; }
    *handled = 1;
    ++g_served;
    return vf3_bit_alloc_entry(s, ram);
}

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    vf3_matrix_state state;
    memset(&state, 0, sizeof state);
    state.budget = 4000000u;
    for (int i = 0; i < VF3H_NVALS; ++i) state.v[i] = c->in[i];

    /* The alias handoff is per case: a stale one from the previous case would
     * give the entry the wrong mirror (0x0c/0x8c/0xac). */
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

/* the entry the corpus was captured at: f_8c038860.cases -> 0x0c038860 */
static uint32_t entry_of(const char *path)
{
    const char *base = strrchr(path, '/');
    base = base ? base + 1 : path;
    const char *p = strstr(base, "f_");
    if (!p) return 0;
    char hex[16];
    size_t n = 0;
    for (p += 2; n + 1 < sizeof hex && *p && *p != '.'; ++n, ++p)
        hex[n] = *p;                 /* the digits, as characters */
    hex[n] = 0;
    return (uint32_t)strtoul(hex, NULL, 16) & 0x1fffffffu;
}

struct leg {
    const char *path;
    const char *name;
    uint32_t serve;        /* the entry the readable port serves */
};

static int run_corpus(const struct leg *leg)
{
    char stem[1200];
    snprintf(stem, sizeof stem, "%s", leg->path);
    {
        char *ext = strrchr(stem, '.');
        if (ext) *ext = 0;
    }
    if (!vf3h_sidecars_open(&sc, stem)) {
        fprintf(stderr, "%s: the corpus's sidecars are missing\n", leg->name);
        return 2;
    }
    g_entry = entry_of(leg->path);
    if (!g_entry) {
        fprintf(stderr, "%s: the corpus' name carries no entry\n", leg->name);
        vf3h_sidecars_close(&sc);
        return 2;
    }
    g_serve = leg->serve ? leg->serve : g_entry;
    g_served = 0;
    /* A module that reaches a register-indirect jump whose target it was not
     * generated with stops at that target with the jump already taken; the
     * reference continues there as the tail transfer it is. */
    vf3_family_tail_retry = 1;
    char *args[] = { (char *)"vf3bitallocoracle", (char *)leg->path };
    const int result = vf3h_harness_main(2, args, leg->name, leg->path, run_case);
    if (result == 0 && !g_served) {
        fprintf(stderr, "%s: the corpus never reached 0x%08x - the leg is "
                "vacuous\n", leg->name, g_serve);
        vf3h_sidecars_close(&sc);
        return 2;
    }
    if (result == 0)
        printf("%s: the readable port served 0x%08x %u times\n",
               leg->name, g_serve, g_served);
    vf3h_sidecars_close(&sc);
    return result;
}

int main(int argc, char **argv)
{
    static const struct leg legs[] = {
        { "extract/analysis/next_dev_cases/f_8c038860.cases",
          "bit_alloc_oracle", 0 },
    };
    if (argc > 1) {
        struct leg one = { argv[1], "bit_alloc_oracle", 0 };
        return run_corpus(&one);
    }

    int result = 0;
    for (unsigned i = 0; i < sizeof legs / sizeof legs[0]; ++i) {
        const int r = run_corpus(&legs[i]);
        if (r != 0) result = r;
    }
    return result;
}
