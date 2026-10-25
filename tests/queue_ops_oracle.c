/* queue_ops_oracle.c - the readable queue family (SH-4 0x8C038570, 0x8C038590
 * and 0x8C0385C0) against the oracle corpus.
 *
 * tests/queue_ops_replay.c proves the readable ports against the retained
 * generated translation.  This one proves them against the *oracle*: the
 * captures in extract/analysis/fight_all_cases/f_8c038570.cases (448 specimens)
 * and f_8c038590.cases (396), and the release capture's 576 and 484.
 *
 * The three functions call nobody, so the hook this test installs serves *only*
 * the entry under test - and, unlike the rotator's oracle leg, there is no
 * helper whose leaves the readable table could pre-empt.  The entry is taken
 * from the corpus' own name, so one binary serves the whole family.
 *
 * The **pop** has no corpus of its own: nothing in the captured fight ever
 * reaches 0x8C0385C0 as a watched entry.  Its evidence is therefore indirect
 * and comes from the corpora whose call trees *do* contain it:
 *
 *   extract/analysis/next_device_dev_cases/f_8c06d46c.cases      (65 cases)
 *   extract/analysis/u90_sw2/u90_sw2_8c0b1ed4/f_8c0b1ed4.cases  (16 cases)
 *
 * For those the specimen starts at the corpus' own entry and the hook serves
 * the **pop** readably, so the recorded exit state of the whole specimen -
 * the queue's counter, the struct's words and the arrays - is the oracle's
 * own record of what the pop did.  The test counts how often the hook was
 * actually asked for the pop, so a corpus that never reaches it cannot pass
 * vacuously.
 *
 * Both of those corpora touch a device register, so the specimen needs the
 * device tape and the banked registers; tests/oracle_sidecars.h carries them.
 *
 * The corpus holds the whole register file (r0..r15, pr, sr, fpscr, macl, mach
 * and fr0..fr15) and the RAM windows, so the comparison covers every register,
 * the XF registers, the FPUL, the GBR, the exit PC and every byte of RAM.
 */
#include "port_harness.h"
#include "oracle_sidecars.h"

#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_queue_reset_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_queue_push_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_queue_pop_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY_RESET 0x0c038570u
#define ENTRY_PUSH  0x0c038590u
#define ENTRY_POP   0x0c0385c0u

static vf3h_sidecars sc;
static uint32_t g_entry;      /* the entry the specimen starts at */
static uint32_t g_serve;      /* the entry the readable port serves */
static unsigned g_served;     /* how often the hook was asked for it */

static int call_port(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (entry == ENTRY_RESET) return vf3_queue_reset_entry(s, ram);
    if (entry == ENTRY_PUSH) return vf3_queue_push_entry(s, ram);
    return vf3_queue_pop_entry(s, ram);
}

/* The hook: the entry under test is served readably, everything else stays on
 * the generated chain. */
static int hook(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                int *handled)
{
    if ((entry & 0x1fffffffu) != g_serve) { *handled = 0; return 0; }
    *handled = 1;
    ++g_served;
    return call_port(g_serve, s, ram);
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

/* the entry the corpus was captured at: f_8c038570.cases -> 0x0c038570 */
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
    char *args[] = { (char *)"vf3queueopsoracle", (char *)leg->path };
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
        { "extract/analysis/fight_all_cases/f_8c038570.cases",
          "queue_reset_oracle", 0 },
        { "extract/analysis/fight_release_cases/f_8c038570.cases",
          "queue_reset_oracle_release", 0 },
        { "extract/analysis/fight_all_cases/f_8c038590.cases",
          "queue_push_oracle", 0 },
        { "extract/analysis/fight_release_cases/f_8c038590.cases",
          "queue_push_oracle_release", 0 },
        /* the pop has no corpus of its own: these two reach it */
        { "extract/analysis/next_device_dev_cases/f_8c06d46c.cases",
          "queue_pop_oracle_next_device", ENTRY_POP },
        { "extract/analysis/u90_sw2/u90_sw2_8c0b1ed4/f_8c0b1ed4.cases",
          "queue_pop_oracle_u90_sw2", ENTRY_POP },
    };
    if (argc > 1) {
        struct leg one = { argv[1], "queue_ops_oracle", 0 };
        return run_corpus(&one);
    }

    int result = 0;
    for (unsigned i = 0; i < sizeof legs / sizeof legs[0]; ++i) {
        const int r = run_corpus(&legs[i]);
        if (r != 0) result = r;
    }
    return result;
}
