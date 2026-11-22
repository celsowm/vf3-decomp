/* strip_light_native_replay.c - differential replay of the native lit
 * strip transformer (0x8C0487A0, src/native/strip_light.c,
 * `vf3_native_strip_light`) against the readable guest port
 * (src/fight/strip_light.c, `vf3_strip_light_entry`).
 *
 * strip_light is a self-contained FP leaf (call-free - the light_vertex /
 * vertex_locate helpers are inlined as plain C, no guest dispatch): it reads
 * a strip of vertex records (r4 = a count word then records, then a trailer
 * {flags, count}), transforms and lights each vertex through XMTRX (diffuse
 * via FV12 + ambient FR15, specular via FV8 and the power ladder selected by
 * r8) and writes 32-byte store-queue vertex slots at r6 (r5 advancing 32 per
 * vertex), chaining strips through the trailer.  FPSCR.SZ is clear (single
 * FR access throughout).
 *
 * Both sides seed the same flat RAM (the strip: a count word then records,
 * then a trailer; the slot region; XMTRX) and the same registers (r4, r5, r6,
 * r8; FR8..FR15 as FV8 / FV12 / ambient), then run.  The emitted slot region,
 * the register contract and SR are compared bit-exact - the leaf's FP chains
 * (transform dot, fipr, division and the ladder multiplies) run under
 * FE_TOWARDZERO (FPSCR 0x00040001), so a faithful port is bit-exact. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/vertex_light.h"
#include "fight/family_hooks.h"
#include "strip_light.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for strip_light (0x8C0487A0) */
int vf3_strip_light_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE  0x0C010000u
#define RAM_SIZE  0x200000u
#define STRIP     0x0C1A0000u   /* the strip (count + records + trailer) */
#define SLOT0     0x0C200000u   /* the store-queue slot base (r6) */

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

/* one 32-byte inline vertex record: bit0 of word0 set (inline flag; word0 is
 * the raw bits of x), then y, z, the normal n0,n1,n2 and the two words w1,w2. */
static void write_vrec(uint32_t base, float x, float y, float z,
                       float n0, float n1, float n2, uint32_t w1, uint32_t w2)
{
    uint32_t ux; memcpy(&ux, &x, 4);
    ux |= 1u;                       /* bit0 = the inline flag */
    wu(base + 0u, ux);              /* x (flag bit set) */
    wf(base + 4u, y);
    wf(base + 8u, z);
    wf(base + 12u, n0);
    wf(base + 16u, n1);
    wf(base + 20u, n2);
    wu(base + 24u, w1);
    wu(base + 28u, w2);
}

static void seed_xf(vf3_matrix_state *s, vf3_native_aim *a, const float xm[16])
{
    for (int i = 0; i < 16; ++i) {
        if (s) s->v[VF3_REG_XF0 + i] = vf3_aim_ubits(xm[i]);
        if (a) a->xm[i] = xm[i];
    }
}

/* column-major: result[i] = sum_k xm[4k+i]*src[k].  A rotation + translation,
 * like the sibling replays, so the transformed coordinates are non-trivial
 * and the w-divisions exercise the FDIVs. */
static const float XM[16] = {
    0.8660254f, 0.0f, 0.5f, 0.0f,
    0.2f, 0.9f, -0.3f, 0.1f,
    -0.5f, 0.0f, 0.8660254f, 0.0f,
    1.5f, 2.5f, -0.5f, 1.0f,
};

/* write `nrec` inline records at `p`; returns the position after the records
 * (where the strip's trailer goes). */
static uint32_t write_recs(uint32_t p, int nrec)
{
    for (int i = 0; i < nrec; ++i) {
        write_vrec(p + (uint32_t)(32 * i),
                   (float)i + 0.5f, (float)(2 * i) + 0.25f,
                   (float)(3 * i) + 0.75f,
                   0.2f, 0.5f, 0.8f,
                   0x11111100u + (uint32_t)i, 0x22222200u + (uint32_t)i);
    }
    return p + (uint32_t)(32 * nrec);
}

/* A single strip: `nrec` records, then a trailer {flags, nextcount}.
 * Returns r4 (the strip base). */
static uint32_t seed_strip(int nrec, uint32_t flags, uint32_t nextcount)
{
    uint32_t p = STRIP;
    wu(p, (uint32_t)nrec);          /* count word */
    p += 4;
    p = write_recs(p, nrec);
    wu(p, flags);                   /* trailer flags */
    wu(p + 4, nextcount);           /* trailer count */
    return STRIP;
}

/* A chained pair: strip1 (n0 records) with a chain trailer {0x80|flags,
 * count1}, then strip2 (n1 records) with a terminal trailer {0, anything}
 * (flags <= 0 stops).  Returns r4 (the base of strip1). */
static uint32_t seed_chain(int n0, uint32_t flags1, int n1)
{
    uint32_t p = STRIP;
    wu(p, (uint32_t)n0); p += 4;
    p = write_recs(p, n0);
    wu(p, 0x00000080u | flags1);    /* chain flag set, positive */
    wu(p + 4, (uint32_t)n1);        /* strip2's count */
    p += 8;
    p = write_recs(p, n1);
    wu(p, 0xFFFFFFFFu);             /* terminal trailer: flags <= 0 stops */
    wu(p + 4, 0);
    return STRIP;
}

static int run_case(const char *label, int nrec, uint32_t flags, uint32_t r8,
                    const float fr8_11[4], const float fr12_15[4], int chain_n1)
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    const uint32_t slot0 = SLOT0;

    /* ---- guest ---- */
    for (uint32_t i = 0; i < RAM_SIZE; ++i) ram[i] = 0xA5;
    uint32_t strip = chain_n1 > 0 ? seed_chain(nrec, flags, chain_n1)
                                  : seed_strip(nrec, flags, 0);
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
    gs.v[18] = 0x00040001u;         /* fpscr, SZ clear */
    gs.v[19] = 0x12345678u;         /* fpul */
    for (int i2 = 0; i2 < 4; ++i2) {
        gs.v[VF3_REG_FR0 + 8 + i2] = vf3_aim_ubits(fr8_11[i2]);   /* FV8 */
        gs.v[VF3_REG_FR0 + 12 + i2] = vf3_aim_ubits(fr12_15[i2]); /* FV12 */
    }
    seed_xf(&gs, NULL, XM);
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE; gwin[0].len = RAM_SIZE; gwin[0].data = ram;
    gmap.wins = gwin; gmap.n = 1; gmap.oob = 0;
    vf3_family_override = vf3_readable_override;
    const int gok = vf3_strip_light_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!gok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", gok, gmap.oob);
        return 2;
    }
    const uint32_t gr0 = gs.v[0], gr1 = gs.v[1], gr2 = gs.v[2], gr3 = gs.v[3],
                  gr4 = gs.v[4], gr5 = gs.v[5], gr6 = gs.v[6], gr14 = gs.v[14],
                  gsr = gs.v[17];
    float gfr[16];
    for (int i2 = 0; i2 < 16; ++i2) { uint32_t u = gs.v[VF3_REG_FR0 + i2]; memcpy(&gfr[i2], &u, 4); }

    /* snapshot the guest's emitted slot region before the native run */ 
    const uint32_t lo = slot0;
    const uint32_t nwords = 0x800u / 4u;
    uint32_t *gslots = (uint32_t *)calloc(nwords, sizeof(uint32_t));
    for (uint32_t i2 = 0; i2 < nwords; ++i2) gslots[i2] = ru(lo + 4u * i2);

    /* ---- native ---- */
    for (uint32_t i2 = 0; i2 < RAM_SIZE; ++i2) ram[i2] = 0xA5;
    strip = chain_n1 > 0 ? seed_chain(nrec, flags, chain_n1)
                         : seed_strip(nrec, flags, 0);
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
    for (int i2 = 0; i2 < 4; ++i2) {
        a.fr[8 + i2] = fr8_11[i2];
        a.fr[12 + i2] = fr12_15[i2];
    }
    seed_xf(NULL, &a, XM);
    const int nok = vf3_native_strip_light(&a);

    if (!nok) {
        fprintf(stderr, "  native rejected the body (rc=%d)\n", nok);
        return 2;
    }
    const uint32_t nr0 = a.r[0], nr1 = a.r[1], nr2 = a.r[2], nr3 = a.r[3],
                  nr4 = a.r[4], nr5 = a.r[5], nr6 = a.r[6], nr14 = a.r[14],
                  nsr = a.sr;

    if (nr0 != gr0) { fprintf(stderr, "  r0: native %08x guest %08x\n", nr0, gr0); bad++; }
    if (nr1 != gr1) { fprintf(stderr, "  r1: native %08x guest %08x\n", nr1, gr1); bad++; }
    if (nr2 != gr2) { fprintf(stderr, "  r2: native %08x guest %08x\n", nr2, gr2); bad++; }
    if (nr3 != gr3) { fprintf(stderr, "  r3: native %08x guest %08x\n", nr3, gr3); bad++; }
    if (nr4 != gr4) { fprintf(stderr, "  r4: native %08x guest %08x\n", nr4, gr4); bad++; }
    if (nr5 != gr5) { fprintf(stderr, "  r5: native %08x guest %08x\n", nr5, gr5); bad++; }
    if (nr6 != gr6) { fprintf(stderr, "  r6: native %08x guest %08x\n", nr6, gr6); bad++; }
    if (nr14 != gr14) { fprintf(stderr, "  r14: native %08x guest %08x\n", nr14, gr14); bad++; }
    if (nsr != gsr) { fprintf(stderr, "  sr: native %08x guest %08x\n", nsr, gsr); bad++; }

    /* XMTRX unchanged and equal */
    for (int i2 = 0; i2 < 16; ++i2)
        if (memcmp(&a.xm[i2], &XM[i2], 4) != 0) { bad++; }

    /* the FR bank at tolerance (the FP chains) */
    for (int i2 = 0; i2 < 16; ++i2)
        if (fabsf(a.fr[i2] - gfr[i2]) > 2.0e-3f && memcmp(&a.fr[i2], &gfr[i2], 4) != 0) {
            if (bad < 24) fprintf(stderr, "  fr[%d]: native %.7g guest %.7g\n", i2, a.fr[i2], gfr[i2]);
            bad++;
        }

    /* emitted slot region: compare bit-exact */
    for (uint32_t i2 = 0; i2 < nwords; ++i2) {
        uint32_t nv = ru(lo + 4u * i2), gv = gslots[i2];
        if (nv != gv) {
            if (bad < 24)
                fprintf(stderr, "  slot[%u] (addr %08x): native %08x guest %08x\n",
                        (unsigned)i2, (unsigned)(lo + 4u * i2), nv, gv);
            bad++;
        }
    }

    free(gslots);

    printf("  strip_light: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
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
    /* a half-vector that puts n_dot_h well above 1/sqrt(2), so the specular
     * ladder's `twice > 1.0f` arm runs (n1,n2,n0 = 0.5,0.8,0.2 in the strip) */
    static const float FV8spec[4] = { 1.0f, 0.5f, 0.2f, 0.0f };

    /* r8=0: no specular ladder */
    bad |= run_case("r8=0, 3 rec", 3, 0xFFFFFFFFu, 0x00u, FV8, FV12, 0);
    /* r8=8: FR3 squared */
    bad |= run_case("r8=8, 3 rec", 3, 0xFFFFFFFFu, 0x08u, FV8, FV12, 0);
    /* r8=8 with the ladder entered (n_dot_h large): v^2 */
    bad |= run_case("r8=8 spec", 3, 0xFFFFFFFFu, 0x08u, FV8spec, FV12, 0);
    /* r8=24: the four-step chain */
    bad |= run_case("r8=24, 3 rec", 3, 0xFFFFFFFFu, 0x18u, FV8, FV12, 0);
    /* r8=40: the five-square end (ladder entered) */
    bad |= run_case("r8=40 spec", 3, 0xFFFFFFFFu, 0x28u, FV8spec, FV12, 0);
    /* r8=40 with the ladder entered on a 6-record strip */
    bad |= run_case("r8=40 spec 6", 6, 0xFFFFFFFFu, 0x28u, FV8spec, FV12, 0);
    /* negative half / diffuse negative */
    bad |= run_case("r8=8 neg", 3, 0xFFFFFFFFu, 0x08u, FV8n, FV12n, 0);
    bad |= run_case("r8=0 neg-w", 3, 0xFFFFFFFFu, 0x00u, FV8, FV12n, 0);
    /* a strip with more than one group (count 6 > the per-group 3) */
    bad |= run_case("r8=8, 6 rec", 6, 0xFFFFFFFFu, 0x08u, FV8, FV12, 0);
    /* chained pair: strip1 (3 rec) chain-flags into strip2 (2 rec), then stop */
    bad |= run_case("r8=8 chain", 3, 0u, 0x08u, FV8, FV12, 2);

    free(ram);
    printf("strip_light_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
