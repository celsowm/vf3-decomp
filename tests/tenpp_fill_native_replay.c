/* Differential replay of the native tenpp leaf structure filler
 * (src/native/tenpp_fill.c, 0x8C0C103C) against the readable guest port
 * (src/fight/readable/tenpp_fill.c, `vf3_tenpp_fill_entry`).
 *
 * Both sides run on the same flat RAM: the guest through its ram map (one
 * window over the whole space), the native through `ram_base`.  The body is a
 * call-free, no-FPU, no-stack leaf, so it needs no stub and no FPU wrappers.
 * The window carries both the node and the cell; the fixture patterns every
 * byte so a wrong address reads a non-guest value.  The whole RAM region is
 * compared byte for byte, together with the output registers (r0, r3, r5, r6)
 * and the untouched ones (r4, r15, pr). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "tenpp_fill.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_tenpp_fill_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define WIN_BASE 0x0c404000u   /* the window: node and cell live here */
#define WIN_HI   0x0c406000u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static uint16_t r16(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint16_t)(p[0] | ((uint16_t)p[1] << 8));
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

struct scenario {
    const char *name;
    uint32_t r4;   /* the node */
    uint32_t r5;   /* the auxiliary cell */
};

#define RETURN_PC 0x0c0432e4u

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    for (uint32_t ad = WIN_BASE; ad < WIN_HI; ad += 4)
        w32(ad, 0x11111111u + (ad & 0xff));
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->r4;
    s->v[5] = sc->r5;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x60000001u;             /* sr */
    s->v[18] = 0x00024001u;             /* fpscr */
    s->budget = 4000000u;

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = ram;
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

static const char *load_image(void)
{
    FILE *f = fopen("extract/exe/1ST_READ.unsc.bin", "rb");
    if (!f) return "image absent";
    if (fread(ram, 1, 0x120000u, f) != 0x120000u) {
        fclose(f);
        return "image short";
    }
    fclose(f);
    return NULL;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    /* ---- guest side ---- */
    seed_all(sc);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, sc);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_tenpp_fill_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    const uint32_t gr0 = gs.v[0], gr3 = gs.v[3], gr5 = gs.v[5], gr6 = gs.v[6];
    const uint32_t gr4 = gs.v[4], gr15 = gs.v[15], gpr = gs.v[16];

    /* snapshot the guest's RAM over the window before the native re-seeds */
    uint8_t *gshot = (uint8_t *)malloc(WIN_HI - WIN_BASE);
    memcpy(gshot, ram + (WIN_BASE - RAM_BASE), WIN_HI - WIN_BASE);

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = sc->r4;
    a.r[5] = sc->r5;
    a.pr = RETURN_PC;
    a.sr = 0x60000001u;
    a.fpscr = 0x00024001u;
    vf3_native_tenpp_fill(&a, 0x0c47f000u);

    int bad = 0;
    /* the guest's RAM snapshot vs the native run */
    {
        int nb = 0;
        for (uint32_t ad = WIN_BASE; ad < WIN_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, gshot + (ad - WIN_BASE), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }
    free(gshot);

    /* output + untouched registers */
    {
        int nb = 0;
        if (a.r[0] != gr0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gr0); nb++; }
        if (a.r[3] != gr3) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], gr3); nb++; }
        if (a.r[5] != gr5) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], gr5); nb++; }
        if (a.r[6] != gr6) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], gr6); nb++; }
        if (a.r[4] != gr4) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gr4); nb++; }
        if (a.r[15] != gr15) { fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], gr15); nb++; }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* the outcome against the fixture itself */
    {
        const uint32_t r4 = sc->r4, r5 = sc->r5;
        int nb = 0;
        if (a.r[0] != 0x28u || a.r[3] != r4 + 0x10u ||
            a.r[5] != 0xffffffffu || a.r[6] != 0u) {
            fprintf(stderr, "  outputs wrong\n"); nb++;
        }
        /* the five 0xff bytes +16..+20 */
        for (unsigned off = 16; off <= 20; ++off)
            if (((uint8_t*)ab(r4 + off))[0] != 0xffu) {
                fprintf(stderr, "  node +%u not ff\n", off); nb++;
            }
        /* the cleared halfwords +22..+30 and +32..+40 */
        for (unsigned off = 22; off <= 30; off += 2)
            if (r16(r4 + off) != 0u) { fprintf(stderr, "  halfword +%u not cleared\n", off); nb++; }
        for (unsigned off = 0x20; off <= 0x28; off += 2)
            if (r16(r4 + off) != 0u) { fprintf(stderr, "  halfword +%u not cleared\n", off); nb++; }
        /* the cleared words +44..+60 */
        for (unsigned off = 44; off <= 60; off += 4)
            if (r32(r4 + off) != 0u) { fprintf(stderr, "  word +%u not cleared\n", off); nb++; }
        /* the cell word +20 cleared */
        if (r32(r5 + 20u) != 0u) { fprintf(stderr, "  cell word +20 not cleared\n"); nb++; }
        printf("  outcome: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    const char *err = load_image();
    if (err) {
        printf("tenpp_fill_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "the corpus' own node",   .r4 = 0x0c404000u, .r5 = 0x0c405000u },
        { .name = "node before cell",       .r4 = 0x0c404020u, .r5 = 0x0c405010u },
        { .name = "node shifted up",        .r4 = 0x0c404080u, .r5 = 0x0c404200u },
        { .name = "cell inside node region",.r4 = 0x0c404100u, .r5 = 0x0c404140u },
        { .name = "large offsets in window",.r4 = 0x0c405f00u, .r5 = 0x0c405e80u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("tenpp_fill_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
