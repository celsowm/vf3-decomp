/* vertex_classify_native_replay.c - differential replay of the native
 * strip point-classify leaf (0x8C048EC0, src/native/vertex_classify.c,
 * `vf3_native_vertex_classify`) against the readable guest port
 * (src/fight/vertex_classify.c, `vf3_vertex_classify_entry`).
 *
 * vertex_classify is a self-contained FP leaf (call-free, no stack frame): it
 * transforms three consecutive strip point records through XMTRX as
 * (x, y, z, 1) and records, in r9's lowest three bits, which lie behind the
 * clip plane (r12, compared as an unsigned bit pattern).  A point record is
 * inline (bit 0 of its flag word set: x, y, z from the first word on, stride
 * 32) or out-of-line (bit 0 clear: an offset from record + 8 to x, y, z,
 * stride 8).  On return r4/r1 are the original record pointer, r0/FPUL the
 * first point's transformed w, and r9 holds the three rotated outcode bits
 * (the last shifted into T).  FR0..FR3 hold the second point transformed,
 * FR4..FR7 the first.
 *
 * Both sides seed the same flat RAM (the three records), the same XMTRX, FR
 * bank, r4, r12 and r9, then run.  The outcode r9, r0/r1/r4, FPUL, the T bit
 * and the preserved XMTRX are compared bit-exact; FR0..FR7 are compared at the
 * 2e-3 FPU tolerance (the ftrv accumulate difference). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "vertex_classify.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for vertex_classify (0x8C048EC0) */
int vf3_vertex_classify_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define TOL 2.0e-3f

static uint8_t *ram;
static void *atw(uint32_t addr) { return ram + (addr - RAM_BASE); }

static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static void w32(uint32_t addr, uint32_t v) { memcpy(atw(addr), &v, 4); }

/* write one point record at `addr`; returns the next record's address */
static uint32_t put_inline(uint32_t addr, float x, float y, float z)
{
    w32(addr + 0u, fbits(x) | 1u);   /* inline flag + x */
    w32(addr + 4u, fbits(y));
    w32(addr + 8u, fbits(z));
    return addr + 32u;
}
static uint32_t put_outline(uint32_t addr, float x, float y, float z,
                            uint32_t xyz_addr)
{
    w32(addr + 0u, 0u);              /* bit 0 clear: out-of-line */
    w32(addr + 4u, xyz_addr - (addr + 8u));  /* offset from record + 8 */
    w32(xyz_addr + 0u, fbits(x));
    w32(xyz_addr + 4u, fbits(y));
    w32(xyz_addr + 8u, fbits(z));
    return addr + 8u;
}

static int run_case(const char *label, const float xm[16], const float fr[16],
                    uint32_t r4, uint32_t r12, uint32_t r9_seed)
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    gs.v[4] = r4;
    gs.v[12] = r12;
    gs.v[9] = r9_seed;
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
    const int ok = vf3_vertex_classify_entry(&gs, &gmap);
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }
    const uint32_t gr0 = gs.v[0], gr1 = gs.v[1], gr4 = gs.v[4], gr9 = gs.v[9],
                   gfpul = gs.v[VF3_REG_FPUL], gsr = gs.v[17];
    float gfr[16];
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_FR0 + i]; memcpy(&gfr[i], &u, 4); }

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram; a.ram_base = RAM_BASE;
    a.r[4] = r4; a.r[12] = r12; a.r[9] = r9_seed;
    memcpy(a.xm, xm, sizeof a.xm);
    memcpy(a.fr, fr, sizeof a.fr);
    a.r[15] = 0x0C20FF00u;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u; a.fpscr = 0x00040001u;
    const int rc = vf3_native_vertex_classify(&a);
    if (rc != 1) {
        fprintf(stderr, "  native rc=%d (expect 1)\n", rc);
        return 1;
    }

    if (a.r[9] != gr9) { if (bad < 10) fprintf(stderr, "  r9: native %08x guest %08x\n", a.r[9], gr9); bad++; }
    if (a.r[0] != gr0) { if (bad < 10) fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gr0); bad++; }
    if (a.r[1] != gr1) { if (bad < 10) fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], gr1); bad++; }
    if (a.r[4] != gr4) { if (bad < 10) fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gr4); bad++; }
    if (a.fpul != gfpul) { if (bad < 10) fprintf(stderr, "  fpul: native %08x guest %08x\n", a.fpul, gfpul); bad++; }
    if (a.sr != gsr) { if (bad < 10) fprintf(stderr, "  sr: native %08x guest %08x\n", a.sr, gsr); bad++; }
    /* FR0..FR7 at tolerance */
    for (int i = 0; i < 8; ++i) {
        if (fabsf(a.fr[i] - gfr[i]) > TOL && memcmp(&a.fr[i], &gfr[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  fr[%d]: native %.7g guest %.7g\n", i, a.fr[i], gfr[i]);
            bad++;
        }
    }
    /* FR8..FR15 and XMTRX untouched */
    for (int i = 8; i < 16; ++i) {
        if (memcmp(&a.fr[i], &fr[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  fr[%d] preserved: native %.7g guest %.7g\n", i, a.fr[i], fr[i]);
            bad++;
        }
    }
    for (int i = 0; i < 16; ++i) {
        if (memcmp(&a.xm[i], &xm[i], 4) != 0) {
            if (bad < 10) fprintf(stderr, "  xm[%d] preserved: native %.7g guest %.7g\n", i, a.xm[i], xm[i]);
            bad++;
        }
    }

    printf("  vertex_classify: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;

    /* XMTRX: a rotation + translation ·  points near the origin, so all
     * three transformed w land close to the translation's w = 1. */
    static const float MX[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,
        0.2f, 0.9f, -0.3f, 0.1f,
        -0.5f, 0.0f, 0.8660254f, 0.0f,
        1.5f, 2.5f, -0.5f, 1.0f,
    };
    float fr0[16];
    memset(fr0, 0, sizeof fr0);
    fr0[8] = 1.0f; fr0[9] = 2.0f; fr0[10] = 3.0f; fr0[11] = 4.0f;
    fr0[12] = 5.0f; fr0[13] = 6.0f; fr0[14] = 7.0f; fr0[15] = 8.0f;

    const uint32_t P0 = 0x0C200000u;

    /* ---- case 1: three inline records, clip above all three w ---- */
    {
        uint32_t p = put_inline(P0, 1.0f, 0.0f, 0.0f);
        p = put_inline(p, 0.0f, 1.0f, 0.0f);
        put_inline(p, 0.0f, 0.0f, 1.0f);
        bad |= run_case("inline, all in front (clip 2.0)", MX, fr0, P0,
                        fbits(2.0f), 0x0u);
    }
    /* ---- case 2: inline records with clip below all three w ---- */
    {
        uint32_t p = put_inline(P0, 1.0f, 0.0f, 0.0f);
        p = put_inline(p, 0.0f, 1.0f, 0.0f);
        put_inline(p, 0.0f, 0.0f, 1.0f);
        bad |= run_case("inline, all behind (clip 0.5)", MX, fr0, P0,
                        fbits(0.5f), 0x0u);
    }
    /* ---- case 3: mixed inline/outline with a real mixed-outcode pattern.
     * For MX the transform's w is 1 + 0.1*y, so the middle point (y = 1) is
     * behind a clip of 1.05 while the two edge points (y = 0) are in front. */
    {
        uint32_t p = put_inline(P0, 0.0f, 0.0f, 0.0f);        /* w = 1    -> 0 */
        uint32_t xyz = p + 0x40u;
        p = put_outline(p, 0.0f, 1.0f, 0.0f, xyz);            /* w = 1.1  -> 1 */
        p = put_inline(p, 0.0f, 0.0f, 1.0f);                 /* w = 1    -> 0 */
        bad |= run_case("mixed inline/outline, r9 seeded 0x4", MX, fr0, P0,
                        fbits(1.05f), 0x4u);
    }
    /* ---- case 4: a matrix whose w tracks the point's z, so the three
     * transformed w values differ and stretch across the clip.  The points
     * in record order are first/second/third with z = 2.0 / 0.5 / 1.0, so
     * w = (2.0, 0.5, 1.0): the first and third straddle a clip of 1.5 (first
     * behind, third in front) while the second is in front.  The rotcl order
     * is second, third, then first, so the second/third/first outcodes are
     * (0, 1, 0) -> r9 = 0b010 rotated in. */
    {
        float M2[16]; memset(M2, 0, sizeof M2);
        M2[0] = M2[5] = M2[10] = 1.0f;
        M2[11] = 1.0f;                                  /* w = z */
        uint32_t p = put_inline(P0, 0.0f, 0.0f, 2.0f);    /* first,  w = 2.0 -> 1 */
        p = put_inline(p, 0.0f, 0.0f, 0.5f);              /* second, w = 0.5 -> 0 */
        put_inline(p, 0.0f, 0.0f, 1.0f);                  /* third,  w = 1.0 -> 0 */
        bad |= run_case("w-tracks-z, clip 1.5", M2, fr0, P0,
                        fbits(1.5f), 0x0u);
    }

    free(ram);
    printf("vertex_classify_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
