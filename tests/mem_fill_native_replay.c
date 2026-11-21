/* Differential replay of the native memory-fill leaf
 * (src/native/mem_fill.c, 0x8C095604) against the readable guest port
 * (src/fight/mem_fill.c, `vf3_mem_fill_entry`).
 *
 * Both sides seed the same flat RAM and the same r4/r5/r6, then run the leaf.
 * The readable version reaches the DIV_S32 compiler-runtime header for the
 * word count; the native inlines it as `length / 4` (same signed truncation).
 * After the run the filled region, the rest of the low RAM (including the
 * four dead stack words) and every general register / SR.T are compared
 * against the guest. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "mem_fill.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_mem_fill_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE  0x0C010000u
#define RAM_SIZE  0x200000u

#define DEST      0x0C1A4000u
#define SP0       0x0C190000u
#define LOW_END   0x0C18E000u   /* covers the four dead words under SP0 */
#define HI_END    0x0C1B0000u

#define RETURN_PC 0x0c0955f0u /*(irrelevant; leaf returns to pr)*/
#define FPSCR     0x00040001u

struct scenario {
    const char *name;
    uint32_t r5;   /* value */
    uint32_t r6;   /* byte count */
    uint32_t fill; /* RAM pre-seed byte */
};

static uint8_t *ram;
static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) |
           ((uint32_t)p[3] << 24);
}

static void seed_scene(const struct scenario *sc)
{
    memset(ram, sc->fill, RAM_SIZE);
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s (value %08x len %u)\n", sc->name, sc->r5, sc->r6);

    uint32_t in_v[37];
    vf3_matrix_state gs;
    memset(&gs, 0, sizeof gs);
    for (unsigned i = 0; i < 37; ++i) gs.v[i] = 0x76543210u + i;
    gs.v[15] = SP0;
    gs.v[5] = sc->r5;
    gs.v[6] = sc->r6;
    /* r3 back-thing: the guest sets r3 = DIV_S32_LITERAL = 0x0C042C20 */
    gs.v[3] = 0x0C042C20u;
    gs.v[4] = DEST;
    for (unsigned i = 0; i < 37; ++i) in_v[i] = gs.v[i];
    gs.v[16] = RETURN_PC;
    gs.v[17] = 0x60000000u;
    gs.v[18] = FPSCR;
    gs.budget = 4000000u;

    seed_scene(sc);

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
    const int ok_guest = vf3_mem_fill_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    uint8_t *gshot = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(gshot, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);

    seed_scene(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = FPSCR;
    a.r[5] = sc->r5;
    a.r[6] = sc->r6;
    a.r[3] = 0x0C042C20u;
    a.r[4] = DEST;

    vf3_native_mem_fill(&a);

    int bad = 0;

    /* registers the guest and native both write */
    for (unsigned i = 0; i < 16; ++i) {
        if (a.r[i] != gs.v[i]) {
            fprintf(stderr, "  r%u native %08x guest %08x\n", i, a.r[i], gs.v[i]); bad++;
        }
    }
    if ((a.sr & 1u) != (gs.v[17] & 1u)) {
        fprintf(stderr, "  SR.T native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); bad++;
    }
    if (memcmp(ram + (LOW_END - RAM_BASE), gshot, HI_END - LOW_END) != 0) {
        fprintf(stderr, "  RAM region differs from guest\n"); bad++;
    }

    /* independent fixture model: words of value, then low-byte tail */
    {
        const uint32_t words = (uint32_t)((int32_t)sc->r6 / 4);
        const uint32_t tail = sc->r6 & 3u;
        uint32_t addr = DEST;
        for (uint32_t i = 0; i < words; ++i, addr += 4)
            if (r32(addr) != sc->r5) { fprintf(stderr, "  model word@%08x got %08x want %08x\n",
                addr, r32(addr), sc->r5); bad++; }
        for (uint32_t i = 0; i < tail; ++i, ++addr)
            if (ab(addr)[0] != (uint8_t)sc->r5) { fprintf(stderr, "  model tail@%08x\n", addr); bad++; }
    }

    free(gshot);
    printf("  mem_fill: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { "16 bytes, word-aligned",  0x11223344u, 16u, 0x42u },
        { "4 bytes exact",           0xAABBCCDDu, 4u,  0x11u },
        { "1 byte, odd tail",        0xDEADBEEFu, 1u,  0x22u },
        { "3 bytes tail",            0x000000FFu, 3u,  0x33u },
        { "6 bytes: word + tail",    0xCAFEBABEu, 6u,  0x44u },
        { "14 bytes",                0x12345678u, 14u, 0x55u },
        { "zero bytes",              0x01020304u, 0u,  0x66u },
        { "39 bytes",                0x0F0F0F0Fu, 39u, 0x77u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("mem_fill_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
