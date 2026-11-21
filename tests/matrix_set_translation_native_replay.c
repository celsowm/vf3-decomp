/* Differential replay of the native XMTRX set-translation leaf
 * (src/native/matrix_set_translation.c, 0x8C03CBD0) against the readable guest
 * port (src/fight/leaf_math.c, `vf3_matrix_set_translation_entry`).
 *
 * Both sides seed the same flat RAM and the same XMTRX / FR bank, then run the
 * leaf.  The leaf is a call-free, no-stack word copy: it reads three floats at
 * r4 and writes them into the XMTRX translation words 12..14, advancing r4 by
 * 12.  After the run the whole XMTRX bank, the whole FR bank and every general
 * register are compared against the guest. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "matrix_set_translation.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_matrix_set_translation_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x200000u

#define SRC       0x0C1A4000u   /* r4 -> the three source floats */
#define LOW_END   0x0C1A3FF0u
#define HI_END    0x0C1A4018u
#define RETURN_PC 0x0c03cbe0u  /*(irrelevant; leaf pops pr)*/
#define FPSCR     0x00040001u   /* single-PR, toward-zero + FTZ */

struct scenario {
    const char *name;
    float src[3];
    float xm[16];
    float fr[16];
};

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    uint32_t in_v[37];
    vf3_matrix_state gs;
    memset(&gs, 0, sizeof gs);
    for (unsigned i = 0; i < 37; ++i) gs.v[i] = 0x76543210u + i;
    gs.v[4] = SRC;
    for (unsigned i = 0; i < 37; ++i) in_v[i] = gs.v[i];
    for (uint32_t i = 0; i < 16; ++i) gs.v[37 + i] = vf3_f32_bits(sc->xm[i]);   /* XF bank */
    for (uint32_t i = 0; i < 16; ++i) gs.v[21 + i] = vf3_f32_bits(sc->fr[i]);   /* FR bank */
    gs.v[16] = RETURN_PC;             /* pr */
    gs.v[17] = 0x60000000u;           /* sr */
    gs.v[18] = FPSCR;                 /* fpscr */
    gs.budget = 4000000u;

    uint8_t *ram = (uint8_t *)calloc(RAM_SIZE, 1);
    memset(ram, 0x5A, RAM_SIZE);
    /* seed the three source floats */
    for (int i = 0; i < 3; ++i) {
        uint32_t w = vf3_f32_bits(sc->src[i]);
        ram[(SRC - RAM_BASE) + 4u * (uint32_t)i + 0] = (uint8_t)w;
        ram[(SRC - RAM_BASE) + 4u * (uint32_t)i + 1] = (uint8_t)(w >> 8);
        ram[(SRC - RAM_BASE) + 4u * (uint32_t)i + 2] = (uint8_t)(w >> 16);
        ram[(SRC - RAM_BASE) + 4u * (uint32_t)i + 3] = (uint8_t)(w >> 24);
    }
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
    const int ok_guest = vf3_matrix_set_translation_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        free(ram); return 1;
    }

    memset(ram, 0x5A, RAM_SIZE);
    for (int i = 0; i < 3; ++i) {
        uint32_t w = vf3_f32_bits(sc->src[i]);
        ram[(SRC - RAM_BASE) + 4u * (uint32_t)i + 0] = (uint8_t)w;
        ram[(SRC - RAM_BASE) + 4u * (uint32_t)i + 1] = (uint8_t)(w >> 8);
        ram[(SRC - RAM_BASE) + 4u * (uint32_t)i + 2] = (uint8_t)(w >> 16);
        ram[(SRC - RAM_BASE) + 4u * (uint32_t)i + 3] = (uint8_t)(w >> 24);
    }
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    for (uint32_t i = 0; i < 16; ++i) a.xm[i] = sc->xm[i];
    for (uint32_t i = 0; i < 16; ++i) a.fr[i] = sc->fr[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = FPSCR;
    vf3_native_matrix_set_translation(&a);

    int bad = 0;

    /* XMTRX bank: words 12..14 are the written translation */
    for (uint32_t i = 0; i < 16; ++i) {
        if (vf3_aim_ubits(a.xm[i]) != gs.v[37 + i]) {
            fprintf(stderr, "  xm[%u] native %08x guest %08x\n", i,
                    vf3_aim_ubits(a.xm[i]), gs.v[37 + i]); bad++;
        }
    }
    /* FR bank untouched */
    for (uint32_t i = 0; i < 16; ++i) {
        if (vf3_aim_ubits(a.fr[i]) != gs.v[21 + i]) {
            fprintf(stderr, "  fr[%u] native %08x guest %08x\n", i,
                    vf3_aim_ubits(a.fr[i]), gs.v[21 + i]); bad++;
        }
    }
    /* every general register (r4 must advance by 12, the rest stay) */
    for (unsigned i = 0; i < 16; ++i) {
        if (a.r[i] != gs.v[i]) {
            fprintf(stderr, "  r%u native %08x guest %08x\n", i, a.r[i], gs.v[i]); bad++;
        }
    }

    /* independent fixture model: xm[12..14] are the three source floats, r4+=12 */
    for (int i = 0; i < 3; ++i)
        if (vf3_aim_ubits(a.xm[12 + i]) != vf3_f32_bits(sc->src[i])) {
            fprintf(stderr, "  model xm[%u] got %08x want %08x\n", 12 + i,
                    vf3_aim_ubits(a.xm[12 + i]), vf3_f32_bits(sc->src[i])); bad++;
        }
    if (a.r[4] != SRC + 12u) {
        fprintf(stderr, "  model r4 got %08x want %08x\n", a.r[4], SRC + 12u); bad++;
    }

    free(ram);
    printf("  matrix_set_translation: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

#define INIT(...) __VA_ARGS__

int main(void)
{
    static const struct scenario scenarios[] = {
        {
            "ordinary translation",
            INIT({ 1.0f, -2.5f, 3.75f }),
            INIT({ 1.0f, 0.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f,
                   0.0f, 0.0f, 1.0f, 0.0f,  99.0f, 99.0f, 99.0f, 1.0f }),
            INIT({ 0.1f, 0.2f, 0.3f, 0.4f,  0.5f, 0.6f, 0.7f, 0.8f,
                   0.9f, 1.0f, 1.1f, 1.2f,  1.3f, 1.4f, 1.5f, 1.6f }),
        },
        {
            "translation with signs/exponents",
            INIT({ -1234.5f, 1.0e-12f, 1.0e12f }),
            INIT({ 3.0f, -2.0f, 1.0f, -0.5f,  0.0f, 1e30f, -1e-30f, 4.0f,
                   9.9f, -8.8f, 7.7f, -6.6f,  0.5f, 0.5f, 0.5f, -1.0f }),
            INIT({ 0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0 }),
        },
        {
            "translation as raw bit patterns",
            INIT({ 0x3F800000u, 0x40490FDBu, 0x402DF854u }),
            INIT({ 1.0f, 0.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f,
                   0.0f, 0.0f, 1.0f, 0.0f,  7.0f, 8.0f, 9.0f, 0.0f }),
            INIT({ 0.1f, 0.1f, 0.1f, 0.1f,  0.1f, 0.1f, 0.1f, 0.1f,
                   0.1f, 0.1f, 0.1f, 0.1f,  0.1f, 0.1f, 0.1f, 0.1f }),
        },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    printf("matrix_set_translation_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
