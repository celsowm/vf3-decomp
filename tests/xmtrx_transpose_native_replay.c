/* Differential replay of the native current-transform transpose
 * (src/native/xmtrx_transpose.c, 0x8C03CC30) against the readable guest port
 * (src/fight/matrix_extra.c, `vf3_matrix_transpose_entry`).
 *
 * Both sides seed the same flat RAM and the same XMTRX, then run the leaf.
 * The function is call-free, no-FPU-math and no-stack, touching only the
 * matrix bank (guest v[37..52] <-> native a->xm[16]).  XMTRX must become the
 * transpose of what was seeded, and every general register, SR, pr and every
 * RAM byte must be untouched. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "xmtrx_transpose.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_matrix_transpose_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x100000u

#define RETURN_PC 0x0c03cc20u /*(irrelevant; leaf pops pr)*/

/* an independent transpose model on the raw words */
static void model_transpose(uint32_t m[16])
{
    static const int pairs[6][2] = { { 1, 4 }, { 2, 8 }, { 3, 12 }, { 6, 9 }, { 7, 13 }, { 11, 14 } };
    for (int i = 0; i < 6; ++i) {
        const int a = pairs[i][0], b = pairs[i][1];
        const uint32_t t = m[a]; m[a] = m[b]; m[b] = t;
    }
}

static int compare_one(uint32_t junk_seed, uint32_t reg_seed)
{
    printf("== transpose (junk %08x reg %08x)\n", junk_seed, reg_seed);

    uint32_t model[16];
    for (uint32_t i = 0; i < 16; ++i) model[i] = junk_seed + 0x9E3779B9u * (i + 1u);

    uint32_t in_v[37];
    vf3_matrix_state gs;
    memset(&gs, 0, sizeof gs);
    for (unsigned i = 0; i < 37; ++i) gs.v[i] = reg_seed + i;
    for (unsigned i = 0; i < 37; ++i) in_v[i] = gs.v[i];
    for (uint32_t i = 0; i < 16; ++i) gs.v[37 + i] = model[i];
    gs.v[16] = RETURN_PC;          /* pr */
    gs.v[17] = 0x60000000u;        /* sr */
    gs.v[18] = 0x00024001u;        /* fpscr */
    gs.budget = 4000000u;

    uint8_t *ram = (uint8_t *)calloc(RAM_SIZE, 1);
    memset(ram, 0x5e, RAM_SIZE);
    uint8_t *pristine = (uint8_t *)malloc(RAM_SIZE);
    memcpy(pristine, ram, RAM_SIZE);
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
    const int ok_guest = vf3_matrix_transpose_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        free(pristine); free(ram); return 1;
    }

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    for (uint32_t i = 0; i < 16; ++i) a.xm[i] = vf3_aim_fbits(model[i]);
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    vf3_native_matrix_transpose(&a);

    int bad = 0;

    /* XMTRX == guest XF bank, and == the independent transpose model */
    model_transpose(model);
    for (uint32_t i = 0; i < 16; ++i) {
        const uint32_t gw = gs.v[37 + i];
        if (vf3_aim_ubits(a.xm[i]) != gw) {
            fprintf(stderr, "  xm[%u] native %08x guest %08x\n", i,
                    vf3_aim_ubits(a.xm[i]), gw); bad++;
            continue;
        }
        if (a.xm[i] != vf3_aim_fbits(model[i])) {
            fprintf(stderr, "  xm[%u] native %08x model %08x\n", i,
                    vf3_aim_ubits(a.xm[i]), model[i]); bad++;
        }
    }
    /* every general register untouched */
    for (unsigned i = 0; i < 16; ++i)
        if (a.r[i] != in_v[i]) {
            fprintf(stderr, "  r%u native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++;
        }
    /* RAM untouched */
    if (memcmp(ram, pristine, RAM_SIZE) != 0) {
        fprintf(stderr, "  RAM differs after the leaf\n"); bad++;
    }

    free(pristine);
    free(ram);
    printf("  xmtrx_transpose: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    int bad = 0;
    bad |= compare_one(0x3FC00000u, 0x76543210u);
    bad |= compare_one(0xDEADBEEFu, 0x10203040u);
    bad |= compare_one(0x01234567u, 0x0CAFE000u);
    printf("xmtrx_transpose_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
