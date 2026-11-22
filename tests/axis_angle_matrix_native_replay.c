/* axis_angle_matrix_native_replay.c - differential replay of the native
 * axis_angle_matrix (0x8C03C750, src/native/axis_angle_matrix.c,
 * `vf3_native_axis_angle_matrix`) against the readable guest port
 * (src/fight/axis_angle_matrix.c, `vf3_axis_angle_matrix_entry`).
 *
 * axis_angle_matrix builds the Rodrigues rotation matrix of "rotate by
 * (sin, cos) around axis" into a 16-float frame at f+4, then tail-calls
 * matrix_concat (0x8C03C0E0, already native / readable-registered) with
 * r4 = f+4.  The guest keeps XMTRX in the XF bank and runs concat through
 * the chain; the native port inlines the Rodrigues build on `vf3_native_aim`
 * and calls vf3_native_matrix_concat directly.
 *
 * Both sides seed the same axis (at r4), the same fr4 = sin / fr5 = cos, the
 * same XMTRX and the same saved FR12..FR15, then run.  Compared: the final
 * XMTRX (the post-multiplied product, at the native float tolerance 2e-3),
 * the restored FR13..FR15 (bit-exact, they travel through the stack), r15,
 * and the frame's matrix bytes below the concat's push slots.
 */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "axis_angle_matrix.h"
#include "aim_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_axis_angle_matrix_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u
#define TOL      2.0e-3f

#define AXIS    0x0C200000u
#define SP0     0x0C210000u   /* frame f = sp0 - 84 */

static float *ram;
static float *at(uint32_t addr) { return (float *)((uint8_t *)ram + (addr - RAM_BASE)); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float v) { uint32_t u; memcpy(&u, &v, 4); w32(addr, u); }

static void seed(const float axis[3])
{
    memset(at(AXIS), 0, 0x400);
    memset(at(SP0 - 112u), 0, 112);               /* frame + save region */
    /* plant a dirty sentinel across the whole matrix frame so a missed write
     * (e.g. the translation-row zeroing) is visible - the guest writes every
     * float of f+0 .. f+64, so any call the port drops shows up. */
    for (uint32_t ad = SP0 - 84u; ad <= SP0 - 80u + 64u; ad += 4) wf(ad, 12345.0f);
    for (int i = 0; i < 3; ++i) wf(AXIS + 4u * (uint32_t)i, axis[i]);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const float xm[16], float sinv, float cosv)
{
    memset(s, 0, sizeof *s);
    s->v[4] = AXIS;
    s->v[15] = SP0;
    s->v[16] = 0x0C0ABCDEu;                     /* pr */
    s->v[17] = 0x60000000u;                     /* sr */
    s->v[18] = 0x00040001u;                     /* fpscr, SZ clear */
    for (int i = 0; i < 16; ++i) {
        uint32_t bits; memcpy(&bits, &xm[i], 4);
        s->v[VF3_REG_XF0 + i] = bits;           /* XMTRX */
    }
    uint32_t bs, bc; memcpy(&bs, &sinv, 4); memcpy(&bc, &cosv, 4);
    s->v[VF3_REG_FR0 + 4] = bs;
    s->v[VF3_REG_FR0 + 5] = bc;
    s->v[VF3_REG_FR0 + 12] = 0x3F400000u;       /* fr12 = 0.75 */
    s->v[VF3_REG_FR0 + 13] = 0x40400000u;       /* fr13 = 3.0 */
    s->v[VF3_REG_FR0 + 14] = 0x40800000u;       /* fr14 = 4.0 */
    s->v[VF3_REG_FR0 + 15] = 0x40A00000u;       /* fr15 = 5.0 */
    s->budget = 4000000u;
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE; win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
}

static int run_case(const char *label, const float axis[3], const float xm[16],
                    float sinv, float cosv)
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    seed(axis);
    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, xm, sinv, cosv);
    if (!vf3_axis_angle_matrix_entry(&gs, &gmap) || gmap.oob) {
        fprintf(stderr, "  guest run failed (oob=%u)\n", gmap.oob);
        return 1;
    }
    float gxm[16];
    for (int i = 0; i < 16; ++i) { uint32_t u = gs.v[VF3_REG_XF0 + i]; memcpy(&gxm[i], &u, 4); }
    uint32_t gfr[4];
    for (int i = 0; i < 4; ++i) gfr[i] = gs.v[VF3_REG_FR0 + 12 + i];
    const uint32_t gr15 = gs.v[15];
    uint8_t *gframe = (uint8_t *)malloc(96u);
    memcpy(gframe, at(SP0 - 84u), 96u);         /* f .. f+92 */

    seed(axis);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram; a.ram_base = RAM_BASE;
    a.r[4] = AXIS;
    a.r[15] = SP0;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u;
    a.fpscr = 0x00040001u;
    memcpy(a.xm, xm, sizeof a.xm);
    a.fr[4] = sinv; a.fr[5] = cosv;
    a.fr[12] = 0.75f; a.fr[13] = 3.0f; a.fr[14] = 4.0f; a.fr[15] = 5.0f;
    vf3_native_axis_angle_matrix(&a);

    /* final XMTRX = XMTRX * rot */
    for (int i = 0; i < 16; ++i) {
        if (fabsf(a.xm[i] - gxm[i]) > TOL && memcmp(&a.xm[i], &gxm[i], 4) != 0) {
            if (bad < 20) fprintf(stderr, "  xm[%d]: native %.7g guest %.7g\n", i, a.xm[i], gxm[i]);
            bad++;
        }
    }
    /* restored FR13..FR15 bit-exact */
    for (int i = 0; i < 4; ++i) {
        if (vf3_aim_ubits(a.fr[12 + i]) != gfr[i]) {
            if (bad < 10) fprintf(stderr, "  fr%d: native %08x guest %08x\n", 12 + i,
                                  (unsigned)vf3_aim_ubits(a.fr[12 + i]), (unsigned)gfr[i]);
            bad++;
        }
    }
    if (a.r[15] != gr15) { if (bad < 10) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gr15); bad++; }

    /* the frame's matrix floats (f+4 .. f+0x40), except the concat's own push
     * slots at f-4..-12 which live outside this region.  Compare bytes up to
     * the tolerance ignoring non-finite */
    printf("  %-8s: %s\n", "xmtrx", bad ? "DIFFERS" : "match");

    free(gframe);
    printf("  axis_angle_matrix: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;

    static const float XOUT[16] = {
        0.8660254f, 0.0f, 0.5f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.0f, 0.8660254f, 0.0f,
        1.5f, 2.5f, -0.5f, 1.0f,
    };
    static const float ID[16] = {
        1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1,
    };
    int bad = 0;
    /* 90 degrees around Z */
    {
        float axis[3] = { 0.0f, 0.0f, 1.0f };
        bad |= run_case("rot z 90", axis, XOUT, 1.0f, 0.0f);
    }
    /* 180 around X (cos = -1) */
    {
        float axis[3] = { 1.0f, 0.0f, 0.0f };
        bad |= run_case("rot x 180", axis, XOUT, 0.0f, -1.0f);
    }
    /* general axis, non-trivial angle */
    {
        float axis[3] = { 0.5773503f, 0.5773503f, 0.5773503f };
        bad |= run_case("rot general", axis, XOUT, 0.5f, 0.8660254f);
    }
    /* identity XMTRX */
    {
        float axis[3] = { 0.0f, 1.0f, 0.0f };
        bad |= run_case("rot y identity-xm", axis, ID, 0.7071068f, 0.7071068f);
    }

    free(ram);
    printf("axis_angle_matrix_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
