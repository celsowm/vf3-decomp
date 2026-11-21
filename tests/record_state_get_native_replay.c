/* Differential replay of the native record-state getter
 * (src/native/record_state_get.c, 0x8C035A20) against the readable guest
 * port (src/fight/record_state_field.c, `vf3_record_state_get_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is a call-free integer body
 * with no FP and no stack frame: it answers the record's state word at +0x4C,
 * but only when the busy word at +0x48 says the record carries one; a record
 * that is not busy - and a null record - answers -10.  It leaves the busy
 * word in r2, the state (or -10) in r0 and the T flag (SR bit 0).
 *
 * The fixture lays out the record's busy/state halfwords and runs the two
 * sides from the same seed.  The record region is compared byte for byte,
 * together with the contract registers (r0, r2, pr, SR.T). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "record_state_get.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_record_state_get_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define NODE_BASE 0x0c16c000u         /* the record */
#define NODE_BUSY 0x48u
#define NODE_STATE 0x4cu

#define NODE_LO 0x0c16c000u
#define NODE_HI 0x0c16c100u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}

struct scenario {
    const char *name;
    uint32_t record;   /* 0 or NODE_BASE */
    int16_t busy;      /* the halfword at +0x48 */
    int16_t state;     /* the halfword at +0x4C */
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t r4, uint32_t pr, uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = r4;
    s->v[15] = 0x0c47f000u;
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00024001u;
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

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    if (sc->record) {
        w16(sc->record + NODE_BUSY, (uint16_t)sc->busy);
        w16(sc->record + NODE_STATE, (uint16_t)sc->state);
    }
}

/* the answer worked out from the fixture */
static void expect(const struct scenario *sc, uint32_t *r0, uint32_t *t)
{
    if (sc->record == 0)      { *r0 = 0xfffffff6u; *t = 1; return; }
    int32_t busy = (int32_t)(int16_t)sc->busy;
    if (busy == 0)            { *r0 = 0xfffffff6u; *t = 1; return; }
    *r0 = (uint32_t)(int32_t)(int16_t)sc->state;
    *t = 0;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c035a5cu;
    const uint32_t sr = 0x60000000u;

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, sc->record, pr, sr);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_record_state_get_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the compared region */
    const size_t l0 = NODE_HI - NODE_LO;
    uint8_t *snap = (uint8_t *)malloc(l0);
    memcpy(snap, ab(NODE_LO), l0);

    const uint32_t g_r0 = gs.v[0], g_r2 = gs.v[2];
    const uint32_t g_r15 = gs.v[15], g_pr = gs.v[16], g_sr = gs.v[17];

    /* ---- native side ---- */
    seed_all(sc);

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = sc->record;
    a.r[15] = 0x0c47f000u;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00024001u;
    vf3_native_record_state_get(&a);

    int bad = 0;

    /* RAM region (the leaf only reads, so it must be unchanged) */
    {
        int nb = 0;
        for (uint32_t ad = NODE_LO; ad < NODE_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, snap + (ad - NODE_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) { if (nb < 10) fprintf(stderr, "  node @%08x: got %08x want %08x\n", ad, n, g); nb++; }
        }
        printf("  ram: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* contract registers + fixture model */
    {
        int nb = 0;
        if (a.r[0] != g_r0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], g_r0); nb++; }
        if (a.r[2] != g_r2) { fprintf(stderr, "  r2: native %08x guest %08x\n", a.r[2], g_r2); nb++; }
        if (a.r[15] != g_r15) { fprintf(stderr, "  r15 differs\n"); nb++; }
        if (a.pr != g_pr) { fprintf(stderr, "  pr differs\n"); nb++; }
        if ((a.sr & 1u) != (g_sr & 1u)) { fprintf(stderr, "  sr T differs\n"); nb++; }

        uint32_t er0, et;
        expect(sc, &er0, &et);
        if (a.r[0] != er0) { fprintf(stderr, "  r0 %08x want %08x\n", a.r[0], er0); nb++; }
        if ((a.sr & 1u) != et) { fprintf(stderr, "  T %u want %u\n", a.sr & 1u, et); nb++; }
        /* r2 is the sign-extended busy word; a null record returns before
         * setting it, so it keeps the seed */
        uint32_t busy = sc->record ? (uint32_t)(int32_t)(int16_t)sc->busy
                                   : (0x76543210u + 2u);
        if (a.r[2] != busy) { fprintf(stderr, "  r2 %08x want %08x\n", a.r[2], busy); nb++; }
        printf("  regs+model: %s\n", nb ? "DIFFERS" : "match");
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
        printf("record_state_get_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "null record", .record = 0, .busy = 0, .state = 0 },
        { .name = "not busy", .record = NODE_BASE, .busy = 0, .state = 5 },
        { .name = "state 5", .record = NODE_BASE, .busy = 7, .state = 5 },
        { .name = "state 0", .record = NODE_BASE, .busy = 3, .state = 0 },
        { .name = "state -3", .record = NODE_BASE, .busy = 9, .state = (int16_t)0xfffd },
        { .name = "state 32767", .record = NODE_BASE, .busy = 1, .state = 32767 },
        { .name = "busy -32768", .record = NODE_BASE, .busy = (int16_t)0x8000, .state = 42 },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("record_state_get_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
