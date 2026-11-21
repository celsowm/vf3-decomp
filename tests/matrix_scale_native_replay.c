/* Differential replay of the native current-transform scale
 * (src/native/matrix_scale.c, 0x8C03CB70) against the readable guest port
 * (src/fight/leaf_math.c, `vf3_matrix_scale_entry`).
 *
 * Both sides seed the same flat RAM and the same XMTRX / FR bank / FPUL,
 * then run the leaf.  The function is call-free and no-stack (the FR pushes
 * only write sp-4/sp-8/sp-12).  After the run the whole XMTRX (guest
 * v[37..52] vs native a->xm[16]), FPUL (guest v[53] vs a->fpul), the pushed
 * stack words, and every general register / FR are compared against the
 * guest.  The multiplies are FPU-exact (toward-zero + FTZ per FPSCR), so the
 * comparison is byte-exact. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "matrix_scale.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_matrix_scale_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x200000u

#define SP0        0x0C190000u   /* r15; the pushes land at sp-4/sp-8/sp-12 */
#define LOW_END    0x0C18E000u   /* must cover sp-12 = 0x0C18FFF4 */
#define HI_END     0x0C190100u

#define RETURN_PC 0x0c03cb60u /*(irrelevant; leaf pops pr)*/
#define FPSCR     0x00040001u   /* single-PR, toward-zero + FTZ */

struct scenario {
    const char *name;
    float xm[16];
    float fr[16];
    uint32_t fpul;
};

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    uint32_t in_v[37];
    vf3_matrix_state gs;
    memset(&gs, 0, sizeof gs);
    for (unsigned i = 0; i < 37; ++i) gs.v[i] = 0x76543210u + i;
    gs.v[15] = SP0;
    for (unsigned i = 0; i < 37; ++i) in_v[i] = gs.v[i];
    for (uint32_t i = 0; i < 16; ++i) gs.v[37 + i] = vf3_f32_bits(sc->xm[i]);
    for (uint32_t i = 0; i < 16; ++i) gs.v[21 + i] = vf3_f32_bits(sc->fr[i]);
    gs.v[53] = sc->fpul;              /* FPUL */
    gs.v[16] = RETURN_PC;             /* pr */
    gs.v[17] = 0x60000000u;           /* sr */
    gs.v[18] = FPSCR;                 /* fpscr */
    gs.budget = 4000000u;

    uint8_t *ram = (uint8_t *)calloc(RAM_SIZE, 1);
    memset(ram, 0x42, RAM_SIZE);
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    memset(&gmap, 0, sizeof gmap);
    gwin[0].base = RAM_BASE;
    gwin[0].len = RAM_SIZE;
    gwin[0].data = ram;
    gmap.wins = gwin;
    gmap.n = 1;
    gmap.oob = 0;

    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_matrix_scale_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        free(ram); return 1;
    }
    uint8_t *gshot = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(gshot, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);

    memset(ram, 0x42, RAM_SIZE);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    for (uint32_t i = 0; i < 16; ++i) a.xm[i] = sc->xm[i];
    for (uint32_t i = 0; i < 16; ++i) a.fr[i] = sc->fr[i];
    a.fpul = sc->fpul;
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = FPSCR;
    vf3_native_matrix_scale(&a);

    int bad = 0;

    /* XMTRX vs guest XF bank */
    for (uint32_t i = 0; i < 16; ++i) {
        if (vf3_aim_ubits(a.xm[i]) != gs.v[37 + i]) {
            fprintf(stderr, "  xm[%u] native %08x guest %08x\n", i,
                    vf3_aim_ubits(a.xm[i]), gs.v[37 + i]); bad++;
        }
    }
    /* FPUL vs guest */
    if (a.fpul != gs.v[53]) {
        fprintf(stderr, "  fpul native %08x guest %08x\n", a.fpul, gs.v[53]); bad++;
    }
    /* FR bank untouched vs guest */
    for (uint32_t i = 0; i < 16; ++i) {
        if (vf3_aim_ubits(a.fr[i]) != gs.v[21 + i]) {
            fprintf(stderr, "  fr[%u] native %08x guest %08x\n", i,
                    vf3_aim_ubits(a.fr[i]), gs.v[21 + i]); bad++;
        }
    }
    /* every general register vs guest */
    for (unsigned i = 0; i < 16; ++i) {
        if (a.r[i] != gs.v[i]) {
            fprintf(stderr, "  r%u native %08x guest %08x\n", i, a.r[i], gs.v[i]); bad++;
        }
    }
    /* the pushed stack words (sp-4/sp-8/sp-12) */
    if (memcmp(ram + (LOW_END - RAM_BASE), gshot, HI_END - LOW_END) != 0) {
        fprintf(stderr, "  stack region differs from guest\n"); bad++;
    }

    free(gshot);
    free(ram);
    printf("  matrix_scale: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

#define INIT(...) __VA_ARGS__

int main(void)
{
    /* the three axis columns sit at xm[0..3], xm[4..7], xm[8..11];
       the fourth column and xm[15] are the scales' scratch / parked slot. */
    static const struct scenario scenarios[] = {
        {
            "ordinary scales",
            INIT({ 2.5f, 0.0f, 0.0f, 1.0f,  0.0f, 1.75f, 0.0f, -2.0f,
                   0.0f, 0.0f, 3.125f, 0.5f,  0.3f, 0.1f, 0.2f, 0.9f }),
            INIT({ 0, 0, 0, 0,  1.5f, -2.25f, 0.75f, 0,  0, 0, 0, 0,  0, 0, 0, 0 }),
            0x3F800000u,
        },
        {
            "rounding-exercising scales",
            INIT({ 1.1f, 0.7f, -0.3f, 9.9f,  0.25f, 3.0f, 1.7f, -4.4f,
                   0.6f, -1.2f, 2.2f, 0.8f,  1.0f, 1.0f, 1.0f, 2.5f }),
            INIT({ 0, 0, 0, 0,  0.33333334f, 2.7f, 5.1f, 0,  0, 0, 0, 0,  0, 0, 0, 0 }),
            0x40000000u,
        },
        {
            "denormal-flush product",
            INIT({ 3.0f, -1.0e-30f, 2.0e-30f, 1.0f,  0.0f, 1.0f, 0.0f, 0.0f,
                   0.0f, 0.0f, 1.0f, 0.0f,  0.0f, 0.0f, 0.0f, 1.0f }),
            INIT({ 0, 0, 0, 0,  1.0e-20f, 1.0e-40f, 1.0f, 0,  0, 0, 0, 0,  0, 0, 0, 0 }),
            0x3DCCCCCDu,
        },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    printf("matrix_scale_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
