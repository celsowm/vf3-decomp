/* axis_extract_native_replay.c - differential replay of the native
 * axis_extract (0x8C03EE40, src/native/axis_extract.c,
 * `vf3_native_axis_extract`) against the readable guest port
 * (src/fight/axis_extract.c, `vf3_axis_extract_entry`).
 *
 * axis_extract is a self-contained FP leaf (call-free, no stack frame): it
 * derives the camera/body axes from a three-by-four direction table at
 * 0x0C0EA624, transforms two of its rows through the transpose of XMTRX's
 * 3x3 part, and writes the result to the vector block at 0x0C1A58A0:
 *
 *   block[+16..+18] = (t0, t1, t2) . M^T    (a transformed copy of row 0)
 *   block[+0..+2]   = norm((t0, t1, t3) . M^T)   (the unit axis)
 *
 * Both sides seed the same flat RAM (the table and the block area) and the
 * same XMTRX (the guest XF bank v[37..52], the native a->xm[16]), then run.
 * The block output, the XMTRX (unchanged), the FPUL side effect (xm[9]) and
 * the registers r0/r4/r5 are compared.  The residual is the fsrra 1/sqrt
 * against sqrtf, tolerated at 3e-3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "axis_extract.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* guest readable authority for axis_extract (0x8C03EE40) */
int vf3_axis_extract_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define TOL 3.0e-3f

#define RAM_BASE  0x0C010000u
#define RAM_SIZE  0x400000u
#define TABLE     0x0C0EA624u
#define BLOCK     0x0C1A58A0u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static void wf(uint32_t addr, float v)
{
    uint8_t *p = ab(addr);
    uint32_t u; memcpy(&u, &v, 4);
    p[0] = (uint8_t)u; p[1] = (uint8_t)(u >> 8);
    p[2] = (uint8_t)(u >> 16); p[3] = (uint8_t)(u >> 24);
}
static float rf(uint32_t addr) { const uint8_t *p = ab(addr); return vf3_aim_fbits((uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24)); }

static void seed_scene_ram(const float t[4])
{
    for (uint32_t i = 0; i < RAM_SIZE; ++i) ram[i] = 0xA5;
    for (int i = 0; i < 4; ++i) wf(TABLE + 4u * (uint32_t)i, t[i]);
}

static void seed_xf(vf3_matrix_state *s, vf3_native_aim *a, const float xm[16])
{
    for (int i = 0; i < 16; ++i) {
        if (s) s->v[VF3_REG_XF0 + i] = vf3_aim_ubits(xm[i]);
        if (a) a->xm[i] = xm[i];
    }
}

static int run_case(const char *label, const float t[4], const float xm[16])
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    /* ---- guest ---- */
    seed_scene_ram(t);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gs, 0, sizeof gs);
    gs.v[15] = 0x0C20FF00u;            /* sp */
    gs.v[16] = 0x0C0ABCDEu;            /* pr */
    gs.v[17] = 0x60000000u;            /* sr */
    gs.v[18] = 0x00040001u;            /* fpscr */
    gs.v[19] = 0x12345678u;            /* macl */
    seed_xf(&gs, NULL, xm);
    gs.budget = 4000000u;
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE; gwin[0].len = RAM_SIZE; gwin[0].data = ram;
    gmap.wins = gwin; gmap.n = 1; gmap.oob = 0;
    vf3_family_override = vf3_readable_override;
    const int ok = vf3_axis_extract_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok, gmap.oob);
        return 1;
    }

    /* guest block + registers */
    float gblk[6];
    for (int i = 0; i < 6; ++i) gblk[i] = rf(BLOCK + 4u * (uint32_t)i);
    const uint32_t gr0 = gs.v[0], gr4 = gs.v[4], gr5 = gs.v[5];
    const uint32_t gfpul = gs.v[VF3_REG_FPUL];
    float gxm[16];
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_XF0 + i]; memcpy(&gxm[i], &u, 4); }

    /* ---- native ---- */
    seed_scene_ram(t);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    a.r[15] = 0x0C20FF00u;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u;
    a.fpscr = 0x00040001u;
    a.fpul = 0x12345678u;
    seed_xf(NULL, &a, xm);
    vf3_native_axis_extract(&a);

    float nblk[6];
    for (int i = 0; i < 6; ++i) nblk[i] = rf(BLOCK + 4u * (uint32_t)i);

    for (int i = 0; i < 6; ++i) {
        if (fabsf(nblk[i] - gblk[i]) > TOL && memcmp(&nblk[i], &gblk[i], 4) != 0) {
            if (bad < 12) fprintf(stderr, "  blk[%d]: native %.7g guest %.7g\n", i, nblk[i], gblk[i]);
            bad++;
        }
    }
    /* XMTRX unchanged by the leaf, and equal on both sides */
    for (int i = 0; i < 16; ++i) {
        if (a.xm[i] != xm[i] && memcmp(&a.xm[i], &xm[i], 4) != 0) {
            if (bad < 20) fprintf(stderr, "  xm[%d] native %.7g changed from seed %.7g\n", i, a.xm[i], xm[i]);
            bad++;
        }
        if (a.xm[i] != gxm[i] && memcmp(&a.xm[i], &gxm[i], 4) != 0) {
            if (bad < 20) fprintf(stderr, "  xm[%d]: native %.7g guest %.7g\n", i, a.xm[i], gxm[i]);
            bad++;
        }
    }
    if (a.fpul != gfpul) {
        fprintf(stderr, "  fpul: native %08x guest %08x\n", a.fpul, gfpul);
        bad++;
    }
    if (a.r[0] != gr0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gr0); bad++; }
    if (a.r[4] != gr4) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gr4); bad++; }
    if (a.r[5] != gr5) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], gr5); bad++; }

    printf("  axis_extract: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    /* a rotated basis, t3 distinct from t2 so the two rows differ */
    static const float T1[4] = { 1.0f, 0.0f, 0.0f, 1.7f };
    static const float M1[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.1f,
        -0.5f, 0.0f, 0.8660254f, 0.0f,
        1.5f, 2.5f, -0.5f, 1.0f,
    };

    /* a full 3D direction, unit columns so the normalisation is exact */
    static const float T2[4] = { 0.3f, -0.8f, 2.2f, -0.6f };
    static const float M2[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };

    /* identity table, non-trivial matrix */
    static const float T3[4] = { 2.0f, 3.0f, 0.5f, -1.0f };
    static const float M3[16] = {
        0.0f, 1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };

    int bad = 0;
    bad |= run_case("rotated-basis", T1, M1);
    bad |= run_case("identity", T2, M2);
    bad |= run_case("z-rotation", T3, M3);

    free(ram);
    printf("axis_extract_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
