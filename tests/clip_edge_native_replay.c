/* clip_edge_native_replay.c - differential replay of the native clip-edge
 * helper (0x8C048CC0, src/native/clip_edge.c, `vf3_native_clip_edge`) against
 * the readable guest port (src/fight/vertex_clip.c, `vf3_clip_edge_entry`).
 *
 * clip_edge pushes the point where the strip edge ring[r0&3] -> ring[r11&3]
 * crosses the plane w' = r12: t = (plane - w0)/(w1 - w0), every attribute is
 * lerp'ed with a fused multiply-add, and y'/z' are scaled by the r7 float.
 * Both sides seed the same flat RAM (the four 32-byte ring slots at
 * 0x0C1A5960, the store-queue output slot at SLOT_R and the control word) and
 * the same registers/FR bank, then the native leaf is run with the T bit both
 * set and clear (edge vs strip-end control word).
 *
 * The block written at r6, the FR0..FR5 exit bank, the register contract
 * (r0, r2, r5, r6, r10, fpul) and the ring (unchanged) are compared bit-exact:
 * the leaf's FP chain is fsub/fdiv/fmac/fmul under FE_TOWARDZERO (FPSCR
 * 0x00040001), so a faithful port is bit-exact. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "clip_edge.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for clip_edge (0x8C048CC0) */
int vf3_clip_edge_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

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
                           float invx, float w1, float w2, float diffuse, float specular)
{
    wf(base + W, w); wf(base + Y, y); wf(base + Z, z); wf(base + INV_X, invx);
    wf(base + W1, w1); wf(base + W2, w2); wf(base + DIFFUSE, diffuse); wf(base + SPECULAR, specular);
}

static int run_case(const char *label, uint32_t r0idx, uint32_t r11idx, int tbit)
{
    const uint32_t slot = SLOT_R;
    printf("== %s (r0=%u r11=%u T=%d)\n", label, r0idx, r11idx, tbit);
    fflush(stdout);
    int bad = 0;

    /* the ring attributes; the edge start (p) and end (q) slots */
    const float w0 = 8.0f, w1 = 14.0f;       /* plane 10.0 -> t = 0.3333.. */
    const float y0 = 30.0f, y1 = -10.0f;
    const float z0 = 5.0f, z1 = 25.0f;
    const float invx = 0.5f;
    const uint32_t d0 = 0x40404040u, d1 = 0x80808080u;
    const uint32_t s0 = 0x10203040u, s1 = 0x90A0B0C0u;
    const uint32_t w10 = 0x11223344u, w11 = 0x55667788u;
    const uint32_t w20 = 0x99AABBCCu, w21 = 0xDDEEFF00u;

    /* ---- guest ---- */
    for (uint32_t i = 0; i < RAM_SIZE; ++i) ram[i] = 0xA5;
    for (int k = 0; k < 4; ++k) {
        seed_ring_slot(RING_BASE + (uint32_t)k * 32u,
                       w0 + k * 0.5f, y0 + k, z0 + k, invx + k * 0.1f,
                       0.0f, 0.0f, 0u, 0u);
    }
    /* overwrite the two edge slots with the actual attrs */
    seed_ring_slot(RING_BASE + (r0idx & 3u) * 32u, w0, y0, z0, invx, 0.0f, 0.0f, (float)(int32_t)d0, (float)(int32_t)s0);
    seed_ring_slot(RING_BASE + (r11idx & 3u) * 32u, w1, y1, z1, invx, 0.0f, 0.0f, (float)(int32_t)d1, (float)(int32_t)s1);
    /* the shading-pair copies for W1/W2 live in word pairs */
    wu(RING_BASE + (r0idx & 3u) * 32u + W1, w10);
    wu(RING_BASE + (r0idx & 3u) * 32u + W2, w20);
    wu(RING_BASE + (r11idx & 3u) * 32u + W1, w11);
    wu(RING_BASE + (r11idx & 3u) * 32u + W2, w21);

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    gs.v[0] = r0idx;
    gs.v[2] = 0;
    gs.v[5] = 0;
    gs.v[6] = slot;
    gs.v[7] = 0x3F000000u;          /* 0.5f, the y'/z' scale */
    gs.v[10] = 0;
    gs.v[11] = r11idx;
    gs.v[12] = 0x41200000u;         /* 10.0f, the clip plane */
    gs.v[17] = tbit ? 0x60000001u : 0x60000000u;   /* SR */
    gs.v[18] = 0x00040001u;         /* FPSCR, RM toward zero, SZ clear */
    gs.v[VF3_REG_FPUL] = 0;         /* fpul (guest r53) */
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE; gwin[0].len = RAM_SIZE; gwin[0].data = ram;
    gmap.wins = gwin; gmap.n = 1; gmap.oob = 0;
    vf3_family_override = vf3_readable_override;
    const int gok = vf3_clip_edge_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!gok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", gok, gmap.oob);
        return 1;
    }
    const uint32_t gr0 = gs.v[0], gr2 = gs.v[2], gr5 = gs.v[5], gr6 = gs.v[6],
                  gr10 = gs.v[10], gfpul = gs.v[VF3_REG_FPUL];
    uint32_t gfr[6];
    for (int i = 0; i < 6; ++i) gfr[i] = gs.v[VF3_REG_FR0 + i];
    /* snapshot the guest's emitted slot before the native run clobbers RAM */
    uint32_t gslot[8];
    for (int i = 0; i < 8; ++i) gslot[i] = ru(slot + 4u * i);

    /* ---- native ---- */
    for (uint32_t i = 0; i < RAM_SIZE; ++i) ram[i] = 0xA5;
    for (int k = 0; k < 4; ++k) {
        seed_ring_slot(RING_BASE + (uint32_t)k * 32u,
                       w0 + k * 0.5f, y0 + k, z0 + k, invx + k * 0.1f,
                       0.0f, 0.0f, 0u, 0u);
    }
    seed_ring_slot(RING_BASE + (r0idx & 3u) * 32u, w0, y0, z0, invx, 0.0f, 0.0f, (float)(int32_t)d0, (float)(int32_t)s0);
    seed_ring_slot(RING_BASE + (r11idx & 3u) * 32u, w1, y1, z1, invx, 0.0f, 0.0f, (float)(int32_t)d1, (float)(int32_t)s1);
    wu(RING_BASE + (r0idx & 3u) * 32u + W1, w10);
    wu(RING_BASE + (r0idx & 3u) * 32u + W2, w20);
    wu(RING_BASE + (r11idx & 3u) * 32u + W1, w11);
    wu(RING_BASE + (r11idx & 3u) * 32u + W2, w21);

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    a.r[0] = r0idx;
    a.r[2] = 0;
    a.r[5] = 0;
    a.r[6] = slot;
    a.r[7] = 0x3F000000u;
    a.r[10] = 0;
    a.r[11] = r11idx;
    a.r[12] = 0x41200000u;
    a.sr = tbit ? 0x60000001u : 0x60000000u;
    a.fpscr = 0x00040001u;
    a.fpul = 0;
    const int nok = vf3_native_clip_edge(&a);
    if (!nok) {
        fprintf(stderr, "  native rejected the body\n");
        return 1;
    }
    const uint32_t nr0 = a.r[0], nr2 = a.r[2], nr5 = a.r[5], nr6 = a.r[6],
                  nr10 = a.r[10], nfpul = a.fpul;
    uint32_t nfr[6];
    for (int i = 0; i < 6; ++i) nfr[i] = vf3_aim_ubits(a.fr[i]);

    if (nr0 != gr0) { fprintf(stderr, "  r0: native %08x guest %08x\n", nr0, gr0); bad++; }
    if (nr2 != gr2) { fprintf(stderr, "  r2: native %08x guest %08x\n", nr2, gr2); bad++; }
    if (nr5 != gr5) { fprintf(stderr, "  r5: native %08x guest %08x\n", nr5, gr5); bad++; }
    if (nr6 != gr6) { fprintf(stderr, "  r6: native %08x guest %08x\n", nr6, gr6); bad++; }
    if (nr10 != gr10) { fprintf(stderr, "  r10: native %08x guest %08x\n", nr10, gr10); bad++; }
    if (nfpul != gfpul) { fprintf(stderr, "  fpul: native %08x guest %08x\n", nfpul, gfpul); bad++; }
    for (int i = 0; i < 6; ++i)
        if (nfr[i] != gfr[i]) { fprintf(stderr, "  FR%d: native %08x guest %08x\n", i, nfr[i], gfr[i]); bad++; }

    for (int i = 0; i < 8; ++i) {
        uint32_t nv = ru(slot + 4u * i), gv = gslot[i];
        if (nv != gv) {
            fprintf(stderr, "  slot[%d] (addr %08x): native %08x guest %08x\n",
                    i, (unsigned)(slot + 4u * i), nv, gv);
            bad++;
        }
    }

    printf("  clip_edge: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;
    /* edge cases: r0=0/r11=1, r0=1/r11=3, and the T-bit strip-end variant */
    bad |= run_case("edge-0-1", 0, 1, 0);
    bad |= run_case("edge-0-1-t", 0, 1, 1);
    bad |= run_case("edge-1-3", 1, 3, 0);
    bad |= run_case("edge-3-0", 3, 0, 0);
    free(ram);
    printf("clip_edge_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
