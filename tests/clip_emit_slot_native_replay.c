/* clip_emit_slot_native_replay.c - differential replay of the native
 * clip-emit slot helper (0x8C048C80, src/native/clip_emit_slot.c,
 * `vf3_native_clip_emit_slot`) against the readable guest port
 * (src/fight/vertex_clip.c, `vf3_clip_emit_slot_entry`).
 *
 * clip_emit_slot pushes ring slot r0&3 to the store queue at r6, scaling its
 * y' and z' by the reciprocal 1/x' first, and writes the strip's control word
 * (the slot's own address, or 0xF0000000 when SR.T is set).  Both sides seed
 * the same flat RAM (the four 32-byte ring slots at 0x0C1A5960 and the output
 * slot at SLOT_R) and the same registers/FR bank, then the native leaf is run
 * with the T bit both set and clear.
 *
 * The block written at r6, the FR0..FR7 exit bank, the register contract
 * (r0, r2, r5, r6, r10) and the ring (unchanged) are compared bit-exact: the
 * leaf's only FP is two fmuls under FE_TOWARDZERO (FPSCR 0x00040001), so a
 * faithful port is bit-exact. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "clip_emit_slot.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for clip_emit_slot (0x8C048C80) */
int vf3_clip_emit_slot_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE  0x0C010000u
#define RAM_SIZE  0x200000u
#define RING_BASE 0x0C1A5960u   /* the 4-slot ring of 32-byte vertices */
#define SLOT_R    0x0C200000u   /* the store-queue output slot (r6) */

#define W    0x00
#define Y    0x04
#define Z    0x08
#define INV_X 0x0C
#define W1   0x10
#define W2   0x14
#define DIFFUSE  0x18
#define SPECULAR 0x1C

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
static void wf(uint32_t a, float v) { uint32_t u; memcpy(&u, &v, 4); wu(a, u); }

static void seed_ring_slot(uint32_t base, float w, float y, float z,
                           float invx, float w1, float w2, float diffuse,
                           float specular)
{
    wf(base + W, w); wf(base + Y, y); wf(base + Z, z); wf(base + INV_X, invx);
    wf(base + W1, w1); wf(base + W2, w2); wf(base + DIFFUSE, diffuse); wf(base + SPECULAR, specular);
}

static void seed_ram(uint32_t r0idx)
{
    for (uint32_t i = 0; i < RAM_SIZE; ++i) ram[i] = 0xA5;
    for (int k = 0; k < 4; ++k) {
        seed_ring_slot(RING_BASE + (uint32_t)k * 32u,
                       (float)(k + 1), (float)(k * 10 + 1), (float)(k * 10 + 2),
                       1.0f / (float)(k + 2), (float)(0x11220000u + k),
                       (float)(0x33440000u + k), (float)(0x55660000u + k),
                       (float)(0x77880000u + k));
    }
    /* make the scaled slot (r0idx) distinct so the y'/z' scaling is observable.
     * The products y*inv_x and z*inv_x are *inexact* (10.1*0.33333334 etc), so
     * the toward-zero vs nearest rounding choice in ft0 is exercised. */
    seed_ring_slot(RING_BASE + (r0idx & 3u) * 32u, 2.0f, 10.1f, 20.7f, 0.33333334f,
                   1.0f, 2.0f, 3.0f, 4.0f);
}

static int run_case(const char *label, uint32_t r0idx, int tbit)
{
    const uint32_t slot = SLOT_R;
    printf("== %s (r0=%u T=%d)\n", label, r0idx, tbit);
    fflush(stdout);
    int bad = 0;

    /* ---- guest ---- */
    seed_ram(r0idx);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    gs.v[0] = r0idx;
    gs.v[2] = 0;
    gs.v[5] = 0;
    gs.v[6] = slot;
    gs.v[10] = 0;
    gs.v[17] = tbit ? 0x60000001u : 0x60000000u;   /* SR */
    gs.v[18] = 0x00040001u;         /* FPSCR, RM toward zero, SZ clear */
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE; gwin[0].len = RAM_SIZE; gwin[0].data = ram;
    gmap.wins = gwin; gmap.n = 1; gmap.oob = 0;
    vf3_family_override = vf3_readable_override;
    const int gok = vf3_clip_emit_slot_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!gok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", gok, gmap.oob);
        return 1;
    }
    const uint32_t gr0 = gs.v[0], gr2 = gs.v[2], gr5 = gs.v[5], gr6 = gs.v[6],
                  gr10 = gs.v[10];
    uint32_t gfr[8];
    for (int i = 0; i < 8; ++i) gfr[i] = gs.v[VF3_REG_FR0 + i];
    /* snapshot the guest's emitted slot before the native run clobbers RAM */
    uint32_t gslot[8];
    for (int i = 0; i < 8; ++i) gslot[i] = ru(slot + 4u * i);

    /* ---- native ---- */
    seed_ram(r0idx);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    a.r[0] = r0idx;
    a.r[2] = 0;
    a.r[5] = 0;
    a.r[6] = slot;
    a.r[10] = 0;
    a.sr = tbit ? 0x60000001u : 0x60000000u;
    a.fpscr = 0x00040001u;
    const int nok = vf3_native_clip_emit_slot(&a);
    if (!nok) {
        fprintf(stderr, "  native rejected the body\n");
        return 1;
    }
    const uint32_t nr0 = a.r[0], nr2 = a.r[2], nr5 = a.r[5], nr6 = a.r[6],
                  nr10 = a.r[10];
    uint32_t nfr[8];
    for (int i = 0; i < 8; ++i) nfr[i] = vf3_aim_ubits(a.fr[i]);

    if (nr0 != gr0) { fprintf(stderr, "  r0: native %08x guest %08x\n", nr0, gr0); bad++; }
    if (nr2 != gr2) { fprintf(stderr, "  r2: native %08x guest %08x\n", nr2, gr2); bad++; }
    if (nr5 != gr5) { fprintf(stderr, "  r5: native %08x guest %08x\n", nr5, gr5); bad++; }
    if (nr6 != gr6) { fprintf(stderr, "  r6: native %08x guest %08x\n", nr6, gr6); bad++; }
    if (nr10 != gr10) { fprintf(stderr, "  r10: native %08x guest %08x\n", nr10, gr10); bad++; }
    for (int i = 0; i < 8; ++i)
        if (nfr[i] != gfr[i]) { fprintf(stderr, "  FR%d: native %08x guest %08x\n", i, nfr[i], gfr[i]); bad++; }

    for (int i = 0; i < 8; ++i) {
        uint32_t nv = ru(slot + 4u * i), gv = gslot[i];
        if (nv != gv) {
            fprintf(stderr, "  slot[%d] (addr %08x): native %08x guest %08x\n",
                    i, (unsigned)(slot + 4u * i), nv, gv);
            bad++;
        }
    }

    printf("  clip_emit_slot: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;
    bad |= run_case("slot-0", 0, 0);
    bad |= run_case("slot-1-t", 1, 1);
    bad |= run_case("slot-2", 2, 0);
    bad |= run_case("slot-3-t", 3, 1);
    free(ram);
    printf("clip_emit_slot_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
