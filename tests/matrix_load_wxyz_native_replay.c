/* Differential replay of the native wxyz matrix load leaf
 * (src/native/matrix_load_wxyz.c, 0x8C03EFB0) against the readable guest
 * port (src/fight/matrix_lib.c, `vf3_matrix_load_wxyz_entry`).
 *
 * Both sides seed the same flat RAM (the source matrix at r4) and the same
 * XMTRX, then run the leaf.  The function is call-free, no-stack and
 * FPU-free.  After the run the whole XMTRX (guest v[37..52] vs native
 * a->xm[16]) and r4 are compared, plus every other general register asserted
 * unchanged. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "matrix_load_wxyz.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_matrix_load_wxyz_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE  0x0C010000u
#define RAM_SIZE  0x200000u

#define SRC       0x0C1A0000u
#define RETURN_PC 0x0c03efa0u /*(irrelevant; leaf pops pr)*/
#define FPSCR     0x00040001u

static uint8_t *ram;
static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) |
           ((uint32_t)p[3] << 24);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

static void seed_xf(vf3_matrix_state *s, vf3_native_aim *a, uint32_t sxm)
{
    for (uint32_t i = 0; i < 16; ++i) {
        const uint32_t w = sxm + 0x9E3779B9u * (i + 1u);
        if (s) s->v[37 + i] = w;
        if (a) a->xm[i] = vf3_aim_fbits(w);
    }
}

static int run_one(uint32_t sxm)
{
    printf("== seed xm %08x\n", sxm);

    memset(ram, 0x3a, RAM_SIZE);
    for (uint32_t c = 0; c < 4; ++c)
        for (uint32_t k = 0; k < 4; ++k)
            w32(SRC + 16u * c + 4u * k, 0x40000000u + 0x11111111u * (c * 4u + k));

    uint32_t in_v[37];
    vf3_matrix_state gs;
    memset(&gs, 0, sizeof gs);
    for (unsigned i = 0; i < 37; ++i) gs.v[i] = 0x76543210u + i;
    gs.v[15] = 0x0C19D200u;
    gs.v[4] = SRC;
    for (unsigned i = 0; i < 37; ++i) in_v[i] = gs.v[i];
    gs.v[16] = RETURN_PC;
    gs.v[17] = 0x60000000u;
    gs.v[18] = FPSCR;
    gs.budget = 4000000u;

    seed_xf(&gs, NULL, sxm);

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
    const int ok_guest = vf3_matrix_load_wxyz_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = FPSCR;
    seed_xf(NULL, &a, sxm);

    vf3_native_matrix_load_wxyz(&a);

    int bad = 0;
    for (uint32_t i = 0; i < 16; ++i) {
        if (vf3_aim_ubits(a.xm[i]) != gs.v[37 + i]) {
            fprintf(stderr, "  xm[%u] native %08x guest %08x\n", i,
                    vf3_aim_ubits(a.xm[i]), gs.v[37 + i]); bad++;
        }
    }
    if (a.r[4] != gs.v[4]) {
        fprintf(stderr, "  r4 native %08x guest %08x\n", a.r[4], gs.v[4]); bad++;
    }
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 4) continue;
        if (a.r[i] != gs.v[i]) {
            fprintf(stderr, "  r%u native %08x guest %08x\n", i, a.r[i], gs.v[i]); bad++;
        }
    }
    /* independent fixture model: col c -> (d a b -d), where (a,b,c,d) are the
       four words of the source column */
    for (uint32_t c = 0; c < 4; ++c) {
        const uint32_t a_ = 0x40000000u + 0x11111111u * (c * 4u + 0u);
        const uint32_t b = 0x40000000u + 0x11111111u * (c * 4u + 1u);
        const uint32_t d = 0x40000000u + 0x11111111u * (c * 4u + 3u);
        if (vf3_aim_ubits(a.xm[4 * c + 0]) != d) {
            fprintf(stderr, "  model col%u[0] %08x want %08x\n", c,
                    vf3_aim_ubits(a.xm[4 * c + 0]), d); bad++;
        }
        if (vf3_aim_ubits(a.xm[4 * c + 1]) != a_) {
            fprintf(stderr, "  model col%u[1]\n", c); bad++;
        }
        if (vf3_aim_ubits(a.xm[4 * c + 2]) != b) {
            fprintf(stderr, "  model col%u[2]\n", c); bad++;
        }
        if (vf3_aim_ubits(a.xm[4 * c + 3]) != (d ^ 0x80000000u)) {
            fprintf(stderr, "  model col%u[3]\n", c); bad++;
        }
    }

    printf("  matrix_load_wxyz: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    int bad = 0;
    bad |= run_one(0x40000000u);
    bad |= run_one(0x13579BDFu);
    bad |= run_one(0x80000000u);   /* exercises negated-w on negative words */

    free(ram);
    printf("matrix_load_wxyz_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
