/* project_verts_native_replay.c - differential replay of the native
 * project_verts (0x8C058EA0, src/native/project_verts.c,
 * `vf3_native_project_verts`) against the readable guest port
 * (src/fight/project_verts.c, `vf3_project_verts_entry`).
 *
 * project_verts is a self-contained FP leaf (call-free): it projects and
 * lights a run of vertices (six floats per vertex: position xyz, normal xyz)
 * from the source stream at r4, into 16-byte output records built at the
 * cursor CURSOR_PTR (0x0C16B8AC), using XMTRX as the view/projection
 * matrix, the depth scale's reciprocal 0x0C16B8A8 to scale a light direction
 * table 0x0C19D5B0 and (in the mode-bit-2 variant) a side direction
 * 0x0C058FE0, and the ambient 0x0C19E0B0:
 *
 *   +0 x/w   +4 y/w   +8 1/w   +C  max(dot(normal, light), 0) + ambient
 *
 * Both sides seed the same flat RAM (all globals, the source stream, the
 * mode word, the output area) and the same XMTRX (guest XF v[37..52],
 * native a->xm[16]).  Output records, advanced cursors, the mode flag, the
 * register contract (r0/r1/r3/r4/r5/r6, SR.T) and XMTRX (unchanged) are
 * compared.  The residual is fsrra 1/sqrt against sqrtf at 3e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "project_verts.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for project_verts (0x8C058EA0) */
int vf3_project_verts_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define TOL 3.0e-3f

#define RAM_BASE  0x0C010000u
#define RAM_SIZE  0x200000u
#define CURSOR_PTR 0x0C16B8ACu
#define CURSOR_OUT 0x0C16B8B0u
#define DEPTH_SCALE 0x0C16B8A8u
#define SIDE_PTR   0x0C16B8B8u
#define SIDE_END   0x0C16B8BCu
#define LIGHT_TABLE 0x0C19D5B0u
#define AMBIENT    0x0C19E0B0u
#define DIRECTION  0x0C058FE0u
#define MODE_FLAG  0x0C055B8Cu
#define SRC        0x0C1B0000u
#define MODEWORD   0x0C1B1000u

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

/* a vertex seed: six floats */
typedef struct { float pos[3]; float nrm[3]; } vert_seed;

static void seed_ram(const vert_seed *vert, int nv,
                     const float light[3], const float dir[3],
                     float depth_scale, float ambient,
                     uint32_t cursor, uint32_t side_ptr, uint32_t modeword)
{
    for (uint32_t i = 0; i < RAM_SIZE; ++i) ram[i] = 0xA5;
    wf(DEPTH_SCALE, depth_scale);
    for (int k = 0; k < 3; ++k) wf(LIGHT_TABLE + 0x80u + 4u * (uint32_t)k, light[k]);
    wf(AMBIENT, ambient);
    for (int k = 0; k < 3; ++k) wf(DIRECTION + 4u * (uint32_t)k, dir[k]);
    wu(CURSOR_PTR, cursor);
    wu(SIDE_PTR, side_ptr);
    wu(MODEWORD, modeword);
    for (int v = 0; v < nv; ++v) {
        for (int k = 0; k < 3; ++k) wf(SRC + 24u * (uint32_t)v + 4u * (uint32_t)k, vert[v].pos[k]);
        for (int k = 0; k < 3; ++k) wf(SRC + 24u * (uint32_t)v + 12u + 4u * (uint32_t)k, vert[v].nrm[k]);
    }
}

static void seed_xf(vf3_matrix_state *s, vf3_native_aim *a, const float xm[16])
{
    for (int i = 0; i < 16; ++i) {
        if (s) s->v[VF3_REG_XF0 + i] = vf3_aim_ubits(xm[i]);
        if (a) a->xm[i] = xm[i];
    }
}

static int run_case(const char *label, const vert_seed *v, int nv,
                    const float light[3], const float dir[3],
                    float depth_scale, float ambient, int side,
                    const float xm[16])
{
    printf("== %s (%d verts, %s)\n", label, nv, side ? "side" : "plain");
    fflush(stdout);
    int bad = 0;

    const uint32_t cursor = 0x0C1C0000u;   /* within the ram map window */
    const uint32_t side_ptr = 0x0C1D0000u;
    const uint32_t modeword = side ? 4u : 0u;

    /* ---- guest ---- */
    seed_ram(v, nv, light, dir, depth_scale, ambient, cursor, side_ptr, modeword);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    gs.v[15] = 0x0C20FF00u;
    gs.v[16] = 0x0C0ABCDEu;
    gs.v[17] = 0x60000000u;
    gs.v[18] = 0x00040001u;
    gs.v[19] = 0x12345678u;
    gs.v[4] = SRC;
    gs.v[6] = (uint32_t)nv;
    gs.v[7] = MODEWORD;
    seed_xf(&gs, NULL, xm);
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE; gwin[0].len = RAM_SIZE; gwin[0].data = ram;
    gmap.wins = gwin; gmap.n = 1; gmap.oob = 0;
    vf3_family_override = vf3_readable_override;
    const int ok = vf3_project_verts_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }
    const uint32_t g_cursor_out = ru(CURSOR_OUT);
    const uint32_t g_side_end = ru(SIDE_END);
    const uint32_t g_mode = ru(MODE_FLAG);
    const uint32_t gr0 = gs.v[0], gr1 = gs.v[1], gr3 = gs.v[3],
                  gr4 = gs.v[4], gr5 = gs.v[5], gr6 = gs.v[6], gsr = gs.v[17];

    /* snapshot the guest's output records and side list before we re-seed */
    const int nrec = (int)((g_cursor_out - cursor) / 16u);
    float *grec = (float *)calloc((size_t)(nrec * 4), sizeof(float));
    float *gside = (float *)calloc((size_t)(nv + 1), sizeof(float));
    for (int i = 0; i < nrec * 4; ++i) grec[i] = rf(cursor + 4u * (uint32_t)i);
    if (side) for (int v = 0; v < nv; ++v) gside[v] = rf(side_ptr + 4u + 8u * (uint32_t)v);

    /* ---- native ---- */
    seed_ram(v, nv, light, dir, depth_scale, ambient, cursor, side_ptr, modeword);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    a.r[15] = 0x0C20FF00u;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u;
    a.fpscr = 0x00040001u;
    a.fpul = 0x12345678u;
    a.r[4] = SRC;
    a.r[6] = (uint32_t)nv;
    a.r[7] = MODEWORD;
    seed_xf(NULL, &a, xm);
    vf3_native_project_verts(&a);

    const uint32_t n_cursor_out = ru(CURSOR_OUT);
    const uint32_t n_side_end = ru(SIDE_END);
    const uint32_t n_mode = ru(MODE_FLAG);
    const uint32_t nr0 = a.r[0], nr1 = a.r[1], nr3 = a.r[3],
                  nr4 = a.r[4], nr5 = a.r[5], nr6 = a.r[6], nsr = a.sr;

    /* XMTRX unchanged by the leaf, and equal on both sides */
    for (int i = 0; i < 16; ++i)
        if (a.xm[i] != xm[i] && memcmp(&a.xm[i], &xm[i], 4) != 0) { bad++; }

    /* cursors / flags */
    if (g_cursor_out != n_cursor_out) { fprintf(stderr, "  cursor_out: native %08x guest %08x\n", n_cursor_out, g_cursor_out); bad++; }
    if (g_side_end != n_side_end && side) { fprintf(stderr, "  side_end: native %08x guest %08x\n", n_side_end, g_side_end); bad++; }
    if (g_mode != n_mode) { fprintf(stderr, "  mode: native %08x guest %08x\n", n_mode, g_mode); bad++; }
    if (nr0 != gr0) { fprintf(stderr, "  r0: native %08x guest %08x\n", nr0, gr0); bad++; }
    if (nr4 != gr4) { fprintf(stderr, "  r4: native %08x guest %08x\n", nr4, gr4); bad++; }
    if (nr5 != gr5) { fprintf(stderr, "  r5: native %08x guest %08x\n", nr5, gr5); bad++; }
    if (nr6 != gr6) { fprintf(stderr, "  r6: native %08x guest %08x\n", nr6, gr6); bad++; }
    if (side) {
        if (nr1 != gr1) { fprintf(stderr, "  r1: native %08x guest %08x\n", nr1, gr1); bad++; }
        if (nr3 != gr3) { fprintf(stderr, "  r3: native %08x guest %08x\n", nr3, gr3); bad++; }
    }
    if ((nsr & 1u) != (gsr & 1u)) { fprintf(stderr, "  SR.T: native %x guest %x\n", (unsigned)(nsr & 1), (unsigned)(gsr & 1)); bad++; }

    /* output records: 4 words per vertex at cursor .. cursor_out */
    for (int i = 0; i < nrec * 4; ++i) {
        float nf = rf(cursor + 4u * (uint32_t)i), gf = grec[i];
        if (fabsf(nf - gf) > TOL && memcmp(&nf, &gf, 4) != 0) {
            if (bad < 24) fprintf(stderr, "  rec[%d]: native %.7g guest %.7g\n", i, nf, gf);
            bad++;
        }
    }
    /* side list: one float per vertex at side_ptr+4, stride 8 */
    if (side) {
        for (int v = 0; v < nv; ++v) {
            float nf = rf(side_ptr + 4u + 8u * (uint32_t)v), gf = gside[v];
            if (fabsf(nf - gf) > TOL && memcmp(&nf, &gf, 4) != 0) { bad++; }
        }
    }

    free(grec); free(gside);
    (void)gr1; (void)gr3; (void)gr5;
    printf("  project_verts: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    /* three vertices: pos xyz, normal xyz */
    static const vert_seed V[3] = {
        { { 1.0f, 2.0f, 3.0f }, { 0.57735f, 0.57735f, 0.57735f } },
        { { -2.0f, 0.5f, 1.5f }, { 0.0f, -1.0f, 0.0f } },
        { { 3.0f, -1.0f, 0.25f }, { 0.70711f, 0.0f, -0.70711f } },
    };
    static const float LIGHT[3] = { 0.0f, 0.0f, 1.0f };
    static const float DIR[3] = { 1.0f, 0.0f, 0.0f };

    /* perspective-ish XMTRX: w = z-ish, nonzero off-diagonal */
    static const float M1[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.2f, 1.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
    /* identity XMTRX */
    static const float MI[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };

    int bad = 0;
    bad |= run_case("three-plain", V, 3, LIGHT, DIR, 2.0f, 0.25f, 0, M1);
    bad |= run_case("three-side", V, 3, LIGHT, DIR, 2.0f, 0.25f, 1, M1);
    bad |= run_case("one-plain-ident", V, 1, LIGHT, DIR, 1.0f, 0.0f, 0, MI);

    free(ram);
    printf("project_verts_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
