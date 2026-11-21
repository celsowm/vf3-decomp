/* Differential replay of the native current-transform identity reset
 * (src/native/xmtrx_identity.c, 0x8C03CCB0) against the readable guest port
 * (src/fight/matrix_lib.c, `vf3_matrix_identity_entry`).
 *
 * Both sides seed the same flat RAM and the same XMTRX / FR bank, then run
 * the leaf.  The function is call-free and no-stack, touching only the matrix
 * bank (guest v[37..52] <-> native a->xm[16]) and FR0..FR3 (guest v[21..24]
 * <-> native a->fr[0..3]).  XMTRX must become the identity, FR0..FR3 become
 * (1, 0, 0, 1), and every general register, SR, pr and every RAM byte must be
 * untouched. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "xmtrx_identity.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_matrix_identity_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x100000u

#define RETURN_PC 0x0c03cca0u /*(irrelevant; leaf pops pr)*/

static int compare_one(uint32_t junk_seed, uint32_t reg_seed)
{
    printf("== identity (junk %08x reg %08x)\n", junk_seed, reg_seed);

    uint32_t in_v[37];
    vf3_matrix_state gs;
    memset(&gs, 0, sizeof gs);
    for (unsigned i = 0; i < 37; ++i) gs.v[i] = reg_seed + i;
    for (unsigned i = 0; i < 37; ++i) in_v[i] = gs.v[i];
    /* seed the matrix bank and FR bank with junk */
    for (uint32_t i = 0; i < 16; ++i) gs.v[37 + i] = junk_seed + 0x1234u * i;
    for (uint32_t i = 0; i < 4; ++i)  gs.v[21 + i] = junk_seed + 0x421u * i;
    gs.v[16] = RETURN_PC;          /* pr */
    gs.v[17] = 0x60000000u;        /* sr */
    gs.v[18] = 0x00024001u;        /* fpscr */
    gs.budget = 4000000u;

    uint8_t *ram = (uint8_t *)calloc(RAM_SIZE, 1);
    memset(ram, 0x5d, RAM_SIZE);
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
    const int ok_guest = vf3_matrix_identity_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        free(ram); return 1;
    }

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    for (uint32_t i = 0; i < 16; ++i) a.xm[i] = vf3_aim_fbits(junk_seed + 0x1234u * i);
    for (uint32_t i = 0; i < 4; ++i)  a.fr[i] = vf3_aim_fbits(junk_seed + 0x421u * i);
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    vf3_native_xmtrx_identity(&a);

    int bad = 0;

    /* XMTRX == guest XF bank (the identity) */
    for (uint32_t i = 0; i < 16; ++i) {
        const uint32_t gw = gs.v[37 + i];
        if (vf3_aim_ubits(a.xm[i]) != gw) {
            fprintf(stderr, "  xm[%u] native %08x guest %08x\n", i,
                    vf3_aim_ubits(a.xm[i]), gw); bad++;
        }
    }
    /* FR0..3 == guest FR0..3 */
    for (uint32_t i = 0; i < 4; ++i) {
        const uint32_t gw = gs.v[21 + i];
        if (vf3_aim_ubits(a.fr[i]) != gw) {
            fprintf(stderr, "  fr[%u] native %08x guest %08x\n", i,
                    vf3_aim_ubits(a.fr[i]), gw); bad++;
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
    printf("  xmtrx_identity: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    int bad = 0;
    bad |= compare_one(0x3FC00000u, 0x76543210u);
    bad |= compare_one(0xDEAD0000u, 0x10203040u);
    bad |= compare_one(0x01234567u, 0x0CAFE000u);
    printf("xmtrx_identity_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
