/* Differential replay of the native motion state field checker
 * (src/native/motion_state_check.c, 0x8C0355CA) against the readable guest
 * port (src/fight/motion_state_check.c, `vf3_motion_state_check_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is a call-free integer body
 * with no FP and no stack frame; it checks a motion state record (R4), reads
 * the halfword at R4+0x48 and (when non-zero) the word at R4+12, storing that
 * word through *R5 (R5), and answers 0 on the two empty paths, 1 on the
 * success path.  Every path is a tail transfer to pr, which neither side
 * touches.
 *
 * The fixture lays out the record (the halfword at +0x48 and the word at +12)
 * and the destination, and runs the two sides from the same seed.  The record
 * and destination regions are compared byte for byte, together with the
 * contract registers (r0, r3, the untouched r15 and the SR T bit) and the
 * stored destination word. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "motion_state_check.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_motion_state_check_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define REC_LO 0x0c16c000u
#define REC_HI 0x0c16c200u

#define REC_ADDR 0x0c16c080u
#define DST_ADDR 0x0c16c180u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}

struct scenario {
    const char *name;
    int r4_null;       /* if non-zero, r4 = 0 */
    int16_t h48;       /* the halfword at record + 0x48 */
    uint32_t w12;      /* the word at record + 12 */
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t r4, uint32_t pr, uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = r4;                   /* the record pointer */
    s->v[5] = DST_ADDR;             /* the destination */
    s->v[15] = 0x0c47f000u;         /* r15, untouched */
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00024001u;         /* the chain's FPU gate, otherwise unused */
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

static void seed_all(const struct scenario *sc, uint32_t *r4)
{
    memset(ram, 0, RAM_SIZE);
    *r4 = sc->r4_null ? 0 : REC_ADDR;
    if (!sc->r4_null) {
        w16(REC_ADDR + 0x48, (uint16_t)sc->h48);
        w32(REC_ADDR + 12, sc->w12);
        /* guard byte so an offset slip on the halfword is visible */
        ab(REC_ADDR + 0x48)[2] = 0xBB;
    }
    w32(DST_ADDR, 0x0F0F0F0Fu);
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c0355d2u;
    const uint32_t sr = 0x60000000u;    /* T clear */

    uint32_t r4;
    seed_all(sc, &r4);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, r4, pr, sr);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_motion_state_check_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the compared region */
    const size_t l0 = REC_HI - REC_LO;
    uint8_t *snap = (uint8_t *)malloc(l0);
    memcpy(snap, ab(REC_LO), l0);

    const uint32_t g_r0 = gs.v[0], g_r3 = gs.v[3], g_r4 = gs.v[4];
    const uint32_t g_r15 = gs.v[15], g_sr = gs.v[17];

    /* ---- native side ---- */
    seed_all(sc, &r4);

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = r4;
    a.r[5] = DST_ADDR;
    a.r[15] = 0x0c47f000u;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00024001u;
    vf3_native_motion_state_check(&a);

    int bad = 0;

    /* RAM region */
    {
        int nb = 0;
        for (uint32_t ad = REC_LO; ad < REC_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, snap + (ad - REC_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* contract registers */
    {
        int nb = 0;
        if (a.r[0] != g_r0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], g_r0); nb++; }
        if (a.r[3] != g_r3) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], g_r3); nb++; }
        if (a.r[4] != g_r4) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], g_r4); nb++; }
        if (a.r[15] != g_r15) { fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], g_r15); nb++; }
        if ((a.sr & 1u) != (g_sr & 1u)) {
            fprintf(stderr, "  sr T: native %u guest %u\n", a.sr & 1u, g_sr & 1u); nb++;
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* outcome against the fixture */
    {
        int nb = 0;
        uint32_t want_r0;
        uint32_t want_r3 = 0x76543213u;      /* the seeded r3, unchanged on the null path */
        uint32_t want_t;
        if (sc->r4_null) {
            want_r0 = 0; want_t = 1;
        } else if (sc->h48 == 0) {
            want_r0 = 0; want_r3 = 0; want_t = 1;
        } else {
            want_r0 = 1; want_r3 = sc->w12; want_t = 0;
        }
        if (a.r[0] != want_r0) { fprintf(stderr, "  r0 %08x want %08x\n", a.r[0], want_r0); nb++; }
        if (a.r[3] != want_r3) { fprintf(stderr, "  r3 %08x want %08x\n", a.r[3], want_r3); nb++; }
        if ((a.sr & 1u) != want_t) { fprintf(stderr, "  T %u want %u\n", a.sr & 1u, want_t); nb++; }
        if (!sc->r4_null && sc->h48 != 0) {
            if (vf3_aim_u32(&a, DST_ADDR) != sc->w12) {
                fprintf(stderr, "  dest %08x want %08x\n", vf3_aim_u32(&a, DST_ADDR), sc->w12);
                nb++;
            }
        } else {
            if (vf3_aim_u32(&a, DST_ADDR) != 0x0F0F0F0Fu) {
                fprintf(stderr, "  dest changed on empty path\n"); nb++;
            }
        }
        if (nb) fprintf(stderr, "  fixture model mismatches\n");
        bad |= nb;
    }

    free(snap);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    const char *err = load_image();
    if (err) {
        printf("motion_state_check_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "null record", .r4_null = 1, .h48 = 0, .w12 = 0u },
        { .name = "empty halfword", .r4_null = 0, .h48 = 0, .w12 = 0x11223344u },
        { .name = "store positive", .r4_null = 0, .h48 = 0x1234, .w12 = 0x11223344u },
        { .name = "negative halfword", .r4_null = 0, .h48 = -1, .w12 = 0xCAFEBABEu },
        { .name = "halfword 0x8000", .r4_null = 0, .h48 = (int16_t)0x8000, .w12 = 0xDEADBEEFu },
        { .name = "store zero", .r4_null = 0, .h48 = 0x0001, .w12 = 0u },
        { .name = "store high", .r4_null = 0, .h48 = 0x7fff, .w12 = 0xFFFFFFFFu },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("motion_state_check_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
