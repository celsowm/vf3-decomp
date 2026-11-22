/* strip_vertex_lit_native_replay.c - differential replay of the native lit
 * vertex-strip transformer (0x8C048F60, src/native/strip_vertex_lit.c,
 * `vf3_native_strip_vertex_lit`) against the readable guest port
 * (src/fight/strip_vertex_lit.c, `vf3_strip_vertex_lit_entry`).
 *
 * strip_vertex_lit is a software-pipelined store-queue emitter (call-free):
 * it reads a strip of 32-byte vertex records (r4), transforms each vertex
 * through XMTRX, folds its lighting (diffuse via FV12, specular via FV8 and
 * the ladder selected by r8, ambient from FR15) and writes 32-byte store-queue
 * vertex blocks at r6 (r5 advancing 32 per vertex).  FPSCR.SZ = 1 throughout.
 *
 * Both sides seed the same flat RAM (the strip: a count word then 32-byte
 * records, the output slot region and XMTRX) and the same registers (r4, r5,
 * r6, r8, r15; FR8..FR15 as the FV8 / FV12 / ambient vectors), then run.  The
 * emitted store-queue region, the register contract and SR are compared
 * bit-exact - the leaf's FP chains (transform dot, fipr, division and the
 * ladder multiplies) run under FE_TOWARDZERO (FPSCR 0x00040001), so a faithful
 * port is bit-exact. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "strip_vertex_lit.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for strip_vertex_lit (0x8C048F60) */
int vf3_strip_vertex_lit_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE  0x0C010000u
#define RAM_SIZE  0x200000u
#define STRIP     0x0C1A0000u   /* the strip (count word + records) */
#define SLOT0     0x0C200000u   /* the output slot region (r6) */

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
static float rf(uint32_t a) { return vf3_aim_fbits(ru(a)); }

/* one 32-byte inline vertex record: bit0 of word0 set (inline flag), then
 * (x, y, z, w), a texture pair and two attribute words. */
static void write_vrec(uint32_t base, float x, float y, float z, float w,
                       float t0, float t1, uint32_t a0, uint32_t a1)
{
    uint32_t ux; memcpy(&ux, &x, 4);
    ux |= 1u;                       /* bit0 = the inline flag */
    wu(base + 0u, ux);              /* x (flag bit set) */
    wf(base + 4u, y);
    wf(base + 8u, z);
    wf(base + 12u, w);
    wf(base + 16u, t0);             /* texture pair */
    wf(base + 20u, t1);
    wu(base + 24u, a0);             /* -> r1 */
    wu(base + 28u, a1);             /* -> r2 */
}

static void seed_xf(vf3_matrix_state *s, vf3_native_aim *a, const float xm[16])
{
    for (int i = 0; i < 16; ++i) {
        if (s) s->v[VF3_REG_XF0 + i] = vf3_aim_ubits(xm[i]);
        if (a) a->xm[i] = xm[i];
    }
}

/* column-major: result[i] = sum_k xm[4k+i]*src[k].  A rotation + translation,
 * like the vertex_lit replay, so the transformed coordinates are non-trivial
 * and the w-divisions exercise the FDIVs. */
static const float XM[16] = {
    0.8660254f, 0.0f, 0.5f, 0.0f,
    0.2f, 0.9f, -0.3f, 0.1f,
    -0.5f, 0.0f, 0.8660254f, 0.0f,
    1.5f, 2.5f, -0.5f, 1.0f,
};

/* Build a strip of `nrec` inline records and return the address of the first
 * record (the count word goes into the word before it). */
static uint32_t seed_strip(int nrec)
{
    uint32_t p = STRIP + 4;
    /* the strip layout used by the entry: the count word at [r4], records
     * after it. */
    wu(STRIP, 1u);                 /* group count; drives the return */
    for (int i = 0; i < nrec; ++i) {
        write_vrec(p + (uint32_t)(32 * i),
                   (float)i + 0.5f, (float)(2 * i) + 0.25f,
                   (float)(3 * i) + 0.75f, 1.0f,
                   (float)i * 0.1f, (float)i * 0.2f + 0.5f,
                   0x11111100u + (uint32_t)i, 0x22222200u + (uint32_t)i);
    }
    return STRIP;
}

static int run_case(const char *label, int nrec, uint32_t r8,
                    const float fr8_11[4], const float fr12_15[4])
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    const uint32_t slot0 = SLOT0;

    /* ---- guest ---- */
    for (uint32_t i = 0; i < RAM_SIZE; ++i) ram[i] = 0xA5;
    uint32_t strip = seed_strip(nrec);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    gs.v[4] = strip;
    gs.v[5] = 0;
    gs.v[6] = slot0;
    gs.v[8] = r8;
    gs.v[14] = 0;
    gs.v[15] = 0x0C20F000u;         /* sp */
    gs.v[16] = 0x0C0ABCDEu;         /* pr */
    gs.v[17] = 0x60000000u;         /* sr, T clear */
    gs.v[18] = 0x00040001u;         /* fpscr, SZ + PR clear */
    gs.v[19] = 0x12345678u;         /* fpul */
    for (int i = 0; i < 4; ++i) {
        gs.v[VF3_REG_FR0 + 8 + i] = vf3_aim_ubits(fr8_11[i]);   /* FV8 */
        gs.v[VF3_REG_FR0 + 12 + i] = vf3_aim_ubits(fr12_15[i]); /* FV12 */
    }
    seed_xf(&gs, NULL, XM);
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE; gwin[0].len = RAM_SIZE; gwin[0].data = ram;
    gmap.wins = gwin; gmap.n = 1; gmap.oob = 0;
    vf3_family_override = vf3_readable_override;
    const int gok = vf3_strip_vertex_lit_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!gok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", gok, gmap.oob);
        return 1;
    }
    const uint32_t gr0 = gs.v[0], gr1 = gs.v[1], gr2 = gs.v[2], gr3 = gs.v[3],
                  gr4 = gs.v[4], gr5 = gs.v[5], gr6 = gs.v[6], gr9 = gs.v[9],
                  gr14 = gs.v[14], gsr = gs.v[17];
    float gfr[16];
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_FR0 + i]; memcpy(&gfr[i], &u, 4); }

    /* snapshot the guest's emitted region before the native run clobbers RAM */
    const uint32_t lo = slot0 - 0x100u;
    const uint32_t nwords = 0x400u / 4u;
    uint32_t *gslots = (uint32_t *)calloc(nwords, sizeof(uint32_t));
    for (uint32_t i = 0; i < nwords; ++i) gslots[i] = ru(lo + 4u * i);

    /* ---- native ---- */
    for (uint32_t i = 0; i < RAM_SIZE; ++i) ram[i] = 0xA5;
    strip = seed_strip(nrec);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    a.r[4] = strip;
    a.r[5] = 0;
    a.r[6] = slot0;
    a.r[8] = r8;
    a.r[14] = 0;
    a.r[15] = 0x0C20F000u;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u;
    a.fpscr = 0x00040001u;
    a.fpul = 0x12345678u;
    for (int i = 0; i < 4; ++i) {
        a.fr[8 + i] = fr8_11[i];    /* FV8 */
        a.fr[12 + i] = fr12_15[i];  /* FV12 */
    }
    seed_xf(NULL, &a, XM);
    const int nok = vf3_native_strip_vertex_lit(&a);

    if (!nok) {
        fprintf(stderr, "  native rejected the body (rc=%d)\n", nok);
        return 1;
    }
    const uint32_t nr0 = a.r[0], nr1 = a.r[1], nr2 = a.r[2], nr3 = a.r[3],
                  nr4 = a.r[4], nr5 = a.r[5], nr6 = a.r[6], nr9 = a.r[9],
                  nr14 = a.r[14], nsr = a.sr;

    if (nr0 != gr0) { fprintf(stderr, "  r0: native %08x guest %08x\n", nr0, gr0); bad++; }
    if (nr1 != gr1) { fprintf(stderr, "  r1: native %08x guest %08x\n", nr1, gr1); bad++; }
    if (nr2 != gr2) { fprintf(stderr, "  r2: native %08x guest %08x\n", nr2, gr2); bad++; }
    if (nr3 != gr3) { fprintf(stderr, "  r3: native %08x guest %08x\n", nr3, gr3); bad++; }
    if (nr4 != gr4) { fprintf(stderr, "  r4: native %08x guest %08x\n", nr4, gr4); bad++; }
    if (nr5 != gr5) { fprintf(stderr, "  r5: native %08x guest %08x\n", nr5, gr5); bad++; }
    if (nr6 != gr6) { fprintf(stderr, "  r6: native %08x guest %08x\n", nr6, gr6); bad++; }
    if (nr9 != gr9) { fprintf(stderr, "  r9: native %08x guest %08x\n", nr9, gr9); bad++; }
    if (nr14 != gr14) { fprintf(stderr, "  r14: native %08x guest %08x\n", nr14, gr14); bad++; }
    if (nsr != gsr) { fprintf(stderr, "  sr: native %08x guest %08x\n", nsr, gsr); bad++; }

    /* XMTRX unchanged and equal */
    for (int i = 0; i < 16; ++i)
        if (a.xm[i] != XM[i] && memcmp(&a.xm[i], &XM[i], 4) != 0) bad++;

    /* the whole FR bank at tolerance (the transform / fipr dot accumulate) */
    for (int i = 0; i < 16; ++i)
        if (fabsf(a.fr[i] - gfr[i]) > 2.0e-3f && memcmp(&a.fr[i], &gfr[i], 4) != 0) {
            if (bad < 24) fprintf(stderr, "  fr[%d]: native %.7g guest %.7g\n", i, a.fr[i], gfr[i]);
            bad++;
        }

    /* emitted store-queue region: compare the whole region bit-exact */
    for (uint32_t i = 0; i < nwords; ++i) {
        uint32_t nv = ru(lo + 4u * i), gv = gslots[i];
        if (nv != gv) {
            if (bad < 24)
                fprintf(stderr, "  slot[%u] (addr %08x): native %08x guest %08x\n",
                        (unsigned)i, (unsigned)(lo + 4u * i), nv, gv);
            bad++;
        }
    }

    free(gslots);

    printf("  strip_vertex_lit: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    int bad = 0;

    static const float FV8[4] = { 0.3f, 0.4f, 0.5f, 0.6f };
    static const float FV12[4] = { 0.7f, 0.8f, 0.9f, 1.0f };
    static const float FV8n[4] = { -0.3f, -0.4f, -0.5f, 0.6f };
    static const float FV12n[4] = { -0.7f, -0.8f, -0.9f, 1.0f };

    /* 9 records (three groups of three): r8=0 (no ladder) */
    bad |= run_case("r8=0, 9 rec", 9, 0x00u, FV8, FV12);
    /* r8=8: one FR3 square (the ladder's first slot) */
    bad |= run_case("r8=8, 9 rec", 9, 0x08u, FV8, FV12);
    /* r8=24: the four-step FR11-chain */
    bad |= run_case("r8=24, 9 rec", 9, 0x18u, FV8, FV12);
    /* negative cosine / diffuse: ladder positive gate false */
    bad |= run_case("r8=8 neg", 9, 0x08u, FV8n, FV12n);
    /* r8=0 with a negative diffuse */
    bad |= run_case("r8=0 neg-w", 9, 0x00u, FV8, FV12n);

    free(ram);
    printf("strip_vertex_lit_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
