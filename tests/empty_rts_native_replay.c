/* empty_rts_native_replay.c - differential replay of the native
 * render_callback_stub (0x8C0597CA, src/native/empty_rts.c,
 * `vf3_native_empty_rts`) against the readable guest port
 * (src/fight/gd_syscall_stub.c, `vf3_empty_rts_entry`).
 *
 * render_callback_stub is a bare `rts`: the guest body is exactly
 * `pc = pr; return;` and touches no register.  The native port is the same
 * no-op.  The differential seeds identical full register state and RAM on
 * both sides and asserts the whole comparable register file (r0..r15, SR,
 * PR, FPSCR, FPUL, GBR) and RAM are unchanged by both. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "empty_rts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for render_callback_stub (0x8C0597CA) */
int vf3_empty_rts_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE  0x0C010000u
#define RAM_SIZE  0x4000u

static uint8_t *ram;

static int run_case(const char *label, uint32_t prseed)
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    /* ---- guest ---- */
    memset(ram, 0x5A, RAM_SIZE);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    for (int i = 0; i < 16; ++i) gs.v[i] = 0x04030200u + (uint32_t)i * 0x00000011u;
    gs.v[15] = 0x0C20FF00u;
    gs.v[16] = prseed;
    gs.v[17] = 0x60000001u;
    gs.v[18] = 0x00040001u;
    gs.v[19] = 0x12345678u;
    for (int i = 23; i < 37; ++i) gs.v[i] = (uint32_t)(0x80000000u + i);
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE; gwin[0].len = RAM_SIZE; gwin[0].data = ram;
    gmap.wins = gwin; gmap.n = 1; gmap.oob = 0;
    vf3_family_override = vf3_readable_override;
    const int ok = vf3_empty_rts_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }
    uint32_t g_v[37];
    for (int i = 0; i < 16; ++i) g_v[i] = gs.v[i];
    const uint32_t g_sr = gs.v[17], g_pr = gs.v[16], g_fpscr = gs.v[18], g_fpul = gs.v[19];
    int g_ram_same = 1;
    for (uint32_t i = 0; i < RAM_SIZE; ++i) if (ram[i] != 0x5A) { g_ram_same = 0; break; }

    /* ---- native ---- */
    memset(ram, 0x5A, RAM_SIZE);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (int i = 0; i < 16; ++i) a.r[i] = gs.v[i];
    a.pr = prseed;
    a.sr = 0x60000001u;
    a.fpscr = 0x00040001u;
    a.fpul = 0x12345678u;
    a.gbr = 0x22222222u;
    vf3_native_empty_rts(&a);

    int n_ram_same = 1;
    for (uint32_t i = 0; i < RAM_SIZE; ++i) if (ram[i] != 0x5A) { n_ram_same = 0; break; }

    for (int i = 0; i < 16; ++i) {
        if (a.r[i] != g_v[i]) {
            fprintf(stderr, "  r[%d] native %08x guest %08x\n", i, a.r[i], g_v[i]);
            bad++;
        }
    }
    if (a.sr != g_sr) { fprintf(stderr, "  SR native %08x guest %08x\n", a.sr, g_sr); bad++; }
    if (a.pr != g_pr) { fprintf(stderr, "  PR native %08x guest %08x\n", a.pr, g_pr); bad++; }
    if (a.fpscr != g_fpscr) { fprintf(stderr, "  FPSCR native %08x guest %08x\n", a.fpscr, g_fpscr); bad++; }
    if (a.fpul != g_fpul) { fprintf(stderr, "  FPUL native %08x guest %08x\n", a.fpul, g_fpul); bad++; }
    if (a.gbr != 0x22222222u) { fprintf(stderr, "  GBR moved\n"); bad++; }
    if (!g_ram_same) { fprintf(stderr, "  guest touched RAM\n"); bad++; }
    if (!n_ram_same) { fprintf(stderr, "  native touched RAM\n"); bad++; }

    printf("  empty_rts: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)malloc(RAM_SIZE);
    if (!ram) return 2;

    int bad = 0;
    bad |= run_case("low-pr", 0x0C0ABCDEu);
    bad |= run_case("high-pr", 0x8C0EA624u);
    bad |= run_case("mid-pr", 0x0C0597CAu);

    free(ram);
    printf("empty_rts_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
