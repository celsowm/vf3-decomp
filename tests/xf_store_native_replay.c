/* Differential replay of the native shadow-bank store
 * (src/native/xf_store.c, 0x8C03B820) against the readable guest port
 * (src/fight/small_leaves.c, `vf3_xf_store_entry`).
 *
 * Both sides seed the same flat RAM and the same XMTRX / FR bank, then run
 * the leaf.  The leaf is a call-free, no-stack word copy: it writes XF12,
 * XF13, XF14 (the XMTRX shadow bank) as 32-bit words at r4+0/+4/+8 and leaves
 * r4 (and everything else) untouched.  After the run the written RAM region,
 * the whole XMTRX / FR bank and every general register are compared against
 * the guest. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "xf_store.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_xf_store_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x200000u

#define DST       0x0C1A4000u   /* r4: where the three words land */
#define LOW_END   0x0C1A3FF0u   /* must cover dst-16 */
#define HI_END    0x0C1A4018u   /* must cover dst+8 */
#define RETURN_PC 0x0c03b820u  /*(irrelevant; leaf pops pr)*/
#define FPSCR     0x00040001u   /* single-PR (SZ/PR clear), toward-zero + FTZ */

struct scenario {
    const char *name;
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
    gs.v[4] = DST;
    for (unsigned i = 0; i < 37; ++i) in_v[i] = gs.v[i];
    for (uint32_t i = 0; i < 16; ++i) gs.v[37 + i] = vf3_f32_bits(sc->xm[i]);   /* XF bank */
    for (uint32_t i = 0; i < 16; ++i) gs.v[21 + i] = vf3_f32_bits(sc->fr[i]);   /* FR bank */
    gs.v[16] = RETURN_PC;             /* pr */
    gs.v[17] = 0x60000000u;           /* sr */
    gs.v[18] = FPSCR;                 /* fpscr */
    gs.budget = 4000000u;

    uint8_t *ram = (uint8_t *)calloc(RAM_SIZE, 1);
    memset(ram, 0x5A, RAM_SIZE);       /* junk outside the written region */
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
    const int ok_guest = vf3_xf_store_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        free(ram); return 1;
    }
    uint8_t *gshot = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(gshot, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);

    memset(ram, 0x5A, RAM_SIZE);
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
    vf3_native_xf_store(&a);

    int bad = 0;

    /* XMTRX bank must be untouched (leaf reads, does not change it) */
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
    /* every general register (only r4 is read here; it must stay) */
    for (unsigned i = 0; i < 16; ++i) {
        if (a.r[i] != gs.v[i]) {
            fprintf(stderr, "  r%u native %08x guest %08x\n", i, a.r[i], gs.v[i]); bad++;
        }
    }
    /* the written region (dst-16 .. dst+8) */
    if (memcmp(ram + (LOW_END - RAM_BASE), gshot, HI_END - LOW_END) != 0) {
        fprintf(stderr, "  RAM region differs from guest\n"); bad++;
    }

    /* independent fixture model: the three shadow words land in order */
    {
        static const uint32_t gx[3] = { 0, 1, 2 }; /* indices mapped below */
        uint32_t want[3];
        for (int i = 0; i < 3; ++i) want[i] = vf3_f32_bits(sc->xm[12 + i]);
        for (int i = 0; i < 3; ++i) {
            uint32_t got =
                (uint32_t)ram[(DST - RAM_BASE) + 4u * (uint32_t)i] |
                ((uint32_t)ram[(DST - RAM_BASE) + 4u * (uint32_t)i + 1] << 8) |
                ((uint32_t)ram[(DST - RAM_BASE) + 4u * (uint32_t)i + 2] << 16) |
                ((uint32_t)ram[(DST - RAM_BASE) + 4u * (uint32_t)i + 3] << 24);
            if (got != want[i]) {
                fprintf(stderr, "  model slot%d got %08x want %08x\n", i, got, want[i]); bad++;
            }
        }
        (void)gx;
    }

    free(gshot);
    free(ram);
    printf("  xf_store: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

#define INIT(...) __VA_ARGS__

int main(void)
{
    static const struct scenario scenarios[] = {
        {
            "plain shadow bank",
            INIT({ 1.0f, 0.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f,
                   0.0f, 0.0f, 1.0f, 0.0f,  0.5f, -1.25f, 2.75f, 1.0f }),
            INIT({ 0.1f, 0.2f, 0.3f, 0.4f,  0.5f, 0.6f, 0.7f, 0.8f,
                   0.9f, 1.0f, 1.1f, 1.2f,  1.3f, 1.4f, 1.5f, 1.6f }),
        },
        {
            "shadow with signs/exponents",
            INIT({ 3.0f, -2.0f, 1.0f, -0.5f,  0.0f, 1e30f, -1e-30f, 4.0f,
                   9.9f, -8.8f, 7.7f, -6.6f,  -1234.5f, 1.0e-12f, 1.0e12f, -1.0f }),
            INIT({ 0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0 }),
        },
        {
            "shadow as raw bit patterns",
            INIT({ 1.0f, 0.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f,
                   0.0f, 0.0f, 1.0f, 0.0f,  0x3F800000u, 0x40490FDBu, 0x402DF854u, 0.0f }),
            INIT({ 0.1f, 0.1f, 0.1f, 0.1f,  0.1f, 0.1f, 0.1f, 0.1f,
                   0.1f, 0.1f, 0.1f, 0.1f,  0.1f, 0.1f, 0.1f, 0.1f }),
        },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    printf("xf_store_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
