/* vertex_emit_ring_native_replay.c - differential replay of the native
 * clip-ring vertex emitter (0x8C048C20, src/native/vertex_emit_ring.c,
 * `vf3_native_vertex_emit_ring`) against the readable guest port
 * (src/fight/vertex_emit.c, `vf3_vertex_emit_ring_entry`).
 *
 * vertex_emit_ring packs the lit, transformed vertex (FR4..FR7, r1, r2,
 * FR2, FR3) into slot r11&3 of the 4-slot clip ring at 0x0C1A5960, and leaves
 * r0 = slot*32, r10 = the slot's low address.  Both sides seed the same FR
 * bank, r1/r2/r11 and flat RAM, then the native leaf is compared against the
 * readable authority.  The ring slot region, r0 and r10 are compared
 * bit-exact (the leaf does no arithmetic - it is a pure pack, so a faithful
 * port is bit-exact by construction). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "vertex_emit_ring.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for vertex_emit_ring (0x8C048C20) */
int vf3_vertex_emit_ring_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE  0x0C010000u
#define RAM_SIZE  0x200000u
#define RING_BASE 0x0C1A5960u   /* the 4-slot ring of 32-byte vertices */

static uint8_t *ram;

static uint8_t *ab(uint32_t a) { return ram + (a - RAM_BASE); }
static void wu(uint32_t a, uint32_t v)
{
    uint8_t *p = ab(a);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static uint32_t ru(uint32_t a)
{
    const uint8_t *p = ab(a);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static int run_case(const char *label, uint32_t r11idx)
{
    const uint32_t base = RING_BASE + (r11idx & 3u) * 32u;
    printf("== %s (r11=%u)\n", label, r11idx);
    fflush(stdout);
    int bad = 0;

    const uint32_t fr4 = 0x3F800000u, fr5 = 0x40000000u, fr6 = 0x40400000u,
                  fr7 = 0x40800000u, fr2 = 0x40A00000u, fr3 = 0x40C00000u;
    const uint32_t r1 = 0x11223344u, r2 = 0x55667788u;

    /* ---- guest ---- */
    for (uint32_t i = 0; i < RAM_SIZE; ++i) ram[i] = 0xA5;
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    gs.v[1] = r1;
    gs.v[2] = r2;
    gs.v[11] = r11idx;
    gs.v[18] = 0x00040001u;         /* FPSCR, SZ clear */
    VF3_FR(&gs, 4) = fr4; VF3_FR(&gs, 5) = fr5; VF3_FR(&gs, 6) = fr6; VF3_FR(&gs, 7) = fr7;
    VF3_FR(&gs, 2) = fr2; VF3_FR(&gs, 3) = fr3;
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE; gwin[0].len = RAM_SIZE; gwin[0].data = ram;
    gmap.wins = gwin; gmap.n = 1; gmap.oob = 0;
    vf3_family_override = vf3_readable_override;
    const int gok = vf3_vertex_emit_ring_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!gok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", gok, gmap.oob);
        return 1;
    }
    const uint32_t gr0 = gs.v[0], gr10 = gs.v[10];
    /* snapshot the guest's emitted slot before the native run clobbers RAM */
    uint32_t gslot[8];
    for (int i = 0; i < 8; ++i) gslot[i] = ru(base + 4u * i);

    /* ---- native ---- */
    for (uint32_t i = 0; i < RAM_SIZE; ++i) ram[i] = 0xA5;
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    a.r[1] = r1;
    a.r[2] = r2;
    a.r[11] = r11idx;
    a.fpscr = 0x00040001u;
    a.fr[4] = vf3_aim_fbits(fr4); a.fr[5] = vf3_aim_fbits(fr5);
    a.fr[6] = vf3_aim_fbits(fr6); a.fr[7] = vf3_aim_fbits(fr7);
    a.fr[2] = vf3_aim_fbits(fr2); a.fr[3] = vf3_aim_fbits(fr3);
    const int nok = vf3_native_vertex_emit_ring(&a);
    if (!nok) {
        fprintf(stderr, "  native rejected the body\n");
        return 1;
    }
    const uint32_t nr0 = a.r[0], nr10 = a.r[10];

    if (nr0 != gr0) { fprintf(stderr, "  r0: native %08x guest %08x\n", nr0, gr0); bad++; }
    if (nr10 != gr10) { fprintf(stderr, "  r10: native %08x guest %08x\n", nr10, gr10); bad++; }

    for (int i = 0; i < 8; ++i) {
        uint32_t nv = ru(base + 4u * i), gv = gslot[i];
        if (nv != gv) {
            fprintf(stderr, "  slot[%d] (addr %08x): native %08x guest %08x\n",
                    i, (unsigned)(base + 4u * i), nv, gv);
            bad++;
        }
    }

    printf("  vertex_emit_ring: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;
    bad |= run_case("slot-0", 0);
    bad |= run_case("slot-1", 1);
    bad |= run_case("slot-3", 3);
    bad |= run_case("slot-wraparound", 7);      /* 7 & 3 == 3, but r11 differs */
    free(ram);
    printf("vertex_emit_ring_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
