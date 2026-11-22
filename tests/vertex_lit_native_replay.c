/* vertex_lit_native_replay.c - differential replay of the native strip
 * vertex-lighting leaf (0x8C047EA0, src/native/vertex_lit.c,
 * `vf3_native_vertex_lit`) against the readable guest port
 * (src/fight/vertex_lit.c, `vf3_vertex_lit_entry`).
 *
 * vertex_lit is a self-contained FP leaf (call-free, no stack frame): it
 * transforms one strip vertex record (r4) through XMTRX as (x, y, z, 1),
 * folds its lighting terms, and ends with T = (r12 > the transformed w, as
 * unsigned bits) and r4 = record + 32.  A record holds x, y, z at +0, a raw
 * vector at +12, and two words at +24/+28.  r8 selects how many squarings the
 * specular ladder runs.  On return r0 = the transformed w, FR0..FR7 and FR11
 * the lighting state, FR15 a copy of FR2, and XMTRX, FR8..FR10, FR12..FR14
 * untouched.
 *
 * Both sides seed the same flat RAM (the record), the same XMTRX, FR bank
 * (including FV12 and FV8 passed in FR12..FR15 / FR8..FR11), r4, r8 and r12,
 * then run.  r0/r1/r2/r4, FPUL, SR's T bit and the preserved XMTRX,
 * FR8..FR10, FR12..FR14 are compared bit-exact; FR0..FR7, FR11 and FR15 at
 * the 2e-3 FPU tolerance (the ftrv/fipr accumulate difference). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "vertex_lit.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for vertex_lit (0x8C047EA0) */
int vf3_vertex_lit_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define TOL 2.0e-3f

static uint8_t *ram;
static void *atw(uint32_t addr) { return ram + (addr - RAM_BASE); }

static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static void w32(uint32_t addr, uint32_t v) { memcpy(atw(addr), &v, 4); }

static int run_case(const char *label, const float xm[16], const float fr[16],
                    uint32_t r4, uint32_t r8, uint32_t r12,
                    float x, float y, float z,
                    const float v[3], uint32_t w24, uint32_t w28)
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    const uint32_t P = r4;
    w32(P + 0u, fbits(x));
    w32(P + 4u, fbits(y));
    w32(P + 8u, fbits(z));
    w32(P + 12u, fbits(v[0]));
    w32(P + 16u, fbits(v[1]));
    w32(P + 20u, fbits(v[2]));
    w32(P + 24u, w24);
    w32(P + 28u, w28);

    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    gs.v[4] = P;
    gs.v[8] = r8;
    gs.v[12] = r12;
    gs.v[15] = 0x0C20FF00u;
    gs.v[16] = 0x0C0ABCDEu;                 /* pr */
    gs.v[17] = 0x60000000u;                 /* sr, T clear initially */
    gs.v[18] = 0x00040001u;                 /* fpscr, SZ + PR clear */
    for (int i = 0; i < 16; ++i) {
        uint32_t bits; memcpy(&bits, &xm[i], 4);
        gs.v[VF3_REG_XF0 + i] = bits;       /* XMTRX */
    }
    for (int i = 0; i < 16; ++i) {
        uint32_t bits; memcpy(&bits, &fr[i], 4);
        gs.v[VF3_REG_FR0 + i] = bits;
    }
    gs.budget = 4000000u;
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE; gwin[0].len = RAM_SIZE;
    gwin[0].data = ram;
    gmap.wins = gwin; gmap.n = 1; gmap.oob = 0;
    const int ok = vf3_vertex_lit_entry(&gs, &gmap);
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }
    const uint32_t gr0 = gs.v[0], gr1 = gs.v[1], gr2 = gs.v[2], gr4 = gs.v[4],
                   gfpul = gs.v[VF3_REG_FPUL], gsr = gs.v[17];
    float gfr[16];
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_FR0 + i]; memcpy(&gfr[i], &u, 4); }

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram; a.ram_base = RAM_BASE;
    a.r[4] = P; a.r[8] = r8; a.r[12] = r12;
    memcpy(a.xm, xm, sizeof a.xm);
    memcpy(a.fr, fr, sizeof a.fr);
    a.r[15] = 0x0C20FF00u;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u; a.fpscr = 0x00040001u;
    const int rc = vf3_native_vertex_lit(&a);
    if (rc != 1) {
        fprintf(stderr, "  native rc=%d (expect 1)\n", rc);
        return 1;
    }

    if (a.r[0] != gr0) { if (bad < 12) fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gr0); bad++; }
    if (a.r[1] != gr1) { if (bad < 12) fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], gr1); bad++; }
    if (a.r[2] != gr2) { if (bad < 12) fprintf(stderr, "  r2: native %08x guest %08x\n", a.r[2], gr2); bad++; }
    if (a.r[4] != gr4) { if (bad < 12) fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gr4); bad++; }
    if (a.fpul != gfpul) { if (bad < 12) fprintf(stderr, "  fpul: native %08x guest %08x\n", a.fpul, gfpul); bad++; }
    if (a.sr != gsr) { if (bad < 12) fprintf(stderr, "  sr: native %08x guest %08x\n", a.sr, gsr); bad++; }
    /* FR0..FR7, FR11, FR15 at tolerance */
    {
        const int sig[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 11, 15 };
        for (int q = 0; q < 10; ++q) {
            int i = sig[q];
            if (fabsf(a.fr[i] - gfr[i]) > TOL && memcmp(&a.fr[i], &gfr[i], 4) != 0) {
                if (bad < 12) fprintf(stderr, "  fr[%d]: native %.7g guest %.7g\n", i, a.fr[i], gfr[i]);
                bad++;
            }
        }
    }
    /* preserved: FR8..FR10, FR12..FR14 bit-exact */
    {
        const int keep[6] = { 8, 9, 10, 12, 13, 14 };
        for (int q = 0; q < 6; ++q) {
            int i = keep[q];
            if (memcmp(&a.fr[i], &fr[i], 4) != 0) {
                if (bad < 12) fprintf(stderr, "  fr[%d] preserved: native %08x guest seed %08x\n", i, fbits(a.fr[i]), fbits(fr[i]));
                bad++;
            }
        }
    }
    for (int i = 0; i < 16; ++i) {
        if (memcmp(&a.xm[i], &xm[i], 4) != 0) {
            if (bad < 12) fprintf(stderr, "  xm[%d] preserved: native %.7g guest %.7g\n", i, a.xm[i], xm[i]);
            bad++;
        }
    }

    printf("  vertex_lit: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;

    /* XMTRX: rotation + translation, w col = (0,0,0,1). */
    static const float MX[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,
        0.2f, 0.9f, -0.3f, 0.1f,
        -0.5f, 0.0f, 0.8660254f, 0.0f,
        1.5f, 2.5f, -0.5f, 1.0f,
    };
    float fr0[16];
    memset(fr0, 0, sizeof fr0);
    /* FV8 = FR8..FR11 and FV12 = FR12..FR15, left by the caller */
    fr0[8] = 0.3f; fr0[9] = 0.4f; fr0[10] = 0.5f; fr0[11] = 0.6f;
    fr0[12] = 0.7f; fr0[13] = 0.8f; fr0[14] = 0.9f; fr0[15] = 1.0f;

    const uint32_t P = 0x0C200000u;

    /* The records: vary z (hence the transformed w and w-divisions) and the
     * vector (hence the diffuse / specular terms). */
    static const struct {
        const char *label;
        float x, y, z;
        float v[3];
        uint32_t r8;
        float clip;
    } cases[] = {
        /* r8 == 0: no ladder, T = clip > w */
        { "sel=0",          1.0f, 0.0f, 1.0f, { 1.0f, 0.0f, 0.0f }, 0x00u, 2.0f },
        /* r8 < 0: FR2 = 1.0 */
        { "sel=-1",         0.0f, 1.0f, 0.0f, { 0.0f, 1.0f, 0.0f }, (uint32_t)-1, 1.0f },
        /* r8 == 8: one FR3 square */
        { "sel=8",          1.0f, 1.0f, 1.0f, { 1.0f, 1.0f, 0.0f }, 0x08u, 3.0f },
        /* r8 == 12: FR11 square then l2a (FR3 *= FR11 twice) */
        { "sel=12",         0.5f, 0.5f, 1.0f, { 1.0f, 0.0f, 1.0f }, 0x0Cu, 2.5f },
        /* r8 == 20: FR11 square then l20 (l20 -> l22) */
        { "sel=20",         0.0f, 0.0f, 2.0f, { 0.0f, 1.0f, 1.0f }, 0x14u, 1.5f },
        /* r8 == 48: straight l22 */
        { "sel=48",         2.0f, 0.0f, 1.0f, { 1.0f, 0.0f, 1.0f }, 0x30u, 4.0f },
        /* r8 == 0x50 (80): done */
        { "sel=80",         1.0f, 1.0f, 0.0f, { 0.0f, 0.0f, 1.0f }, 0x50u, 2.0f },
        /* negative diffuse (lit false), negative cosine (positive false):
         * the ladder is skipped entirely */
        { "sel=8 neglit",   -1.0f, -1.0f, -1.0f, { -1.0f, -1.0f, -1.0f }, 0x08u, 1.0f },
        /* small cosine (above_one false): stops before the second square */
        { "sel=8 small",    0.03f, 0.04f, 0.05f, { 0.03f, 0.04f, 0.05f }, 0x08u, 2.0f },
    };
    const int ncase = (int)(sizeof cases / sizeof cases[0]);
    for (int i = 0; i < ncase; ++i)
        bad |= run_case(cases[i].label, MX, fr0, P, cases[i].r8,
                        fbits(cases[i].clip),
                        cases[i].x, cases[i].y, cases[i].z,
                        cases[i].v, 0x11111111u, 0x22222222u);

    free(ram);
    printf("vertex_lit_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
