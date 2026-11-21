/* Differential replay of the native pointer-chase leaf
 * (src/native/pointer_chase.c, 0x8C035264) against the readable guest port
 * (src/fight/pointer_chase.c, `vf3_pointer_chase_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is a call-free integer body
 * with no FP and no stack frame; it reads a pointer from the literal pool at
 * 0x0c03548c, dereferences it to get an object, reads the word at object+40,
 * and tail-transfers to pr (which neither side touches).
 *
 * The fixture lays out the pool slot and the object (field at +40), and runs
 * the two sides from the same seed.  The pool and object regions are compared
 * byte for byte, together with the contract registers (r0 = the field, r3 =
 * the pool-loaded pointer, and the untouched r4/r5/r15/SR.T). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "pointer_chase.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_pointer_chase_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define POOL_ADDR 0x0c03548cu        /* the literal pool slot holding the pointer */
#define OBJ1_ADDR 0x0c16c000u        /* the object whose first word is a pointer */
#define OBJ2_ADDR 0x0c16c100u        /* the pointed-to object */
#define FIELD_ADDR (OBJ2_ADDR + 40u)

#define POOL_LO 0x0c035000u
#define POOL_HI 0x0c036000u
#define OBJ_LO  0x0c16c000u
#define OBJ_HI  0x0c16c200u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

struct scenario {
    const char *name;
    uint32_t field;      /* the word at the far object + 40 */
};

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t pr, uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
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
    w32(POOL_ADDR, OBJ1_ADDR);        /* the pool holds a pointer to the object */
    w32(OBJ1_ADDR, OBJ2_ADDR);        /* the object's first word is a pointer */
    w32(FIELD_ADDR, sc->field);
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c03526eu;
    const uint32_t sr = 0x60000000u;

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, pr, sr);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_pointer_chase_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the compared regions */
    const size_t l0 = POOL_HI - POOL_LO, l1 = OBJ_HI - OBJ_LO;
    uint8_t *snap = (uint8_t *)malloc(l0 + l1);
    memcpy(snap, ab(POOL_LO), l0);
    memcpy(snap + l0, ab(OBJ_LO), l1);

    const uint32_t g_r0 = gs.v[0], g_r3 = gs.v[3], g_r4 = gs.v[4];
    const uint32_t g_r5 = gs.v[5], g_r15 = gs.v[15], g_sr = gs.v[17];

    /* ---- native side ---- */
    seed_all(sc);

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[15] = 0x0c47f000u;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00024001u;
    vf3_native_pointer_chase(&a);

    int bad = 0;

    /* RAM regions */
    {
        int nb = 0;
        for (uint32_t ad = POOL_LO; ad < POOL_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, snap + (ad - POOL_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) { if (nb < 10) fprintf(stderr, "  pool @%08x: got %08x want %08x\n", ad, n, g); nb++; }
        }
        for (uint32_t ad = OBJ_LO; ad < OBJ_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, snap + l0 + (ad - OBJ_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) { if (nb < 10) fprintf(stderr, "  obj @%08x: got %08x want %08x\n", ad, n, g); nb++; }
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
        if (a.r[5] != g_r5) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], g_r5); nb++; }
        if (a.r[15] != g_r15) { fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], g_r15); nb++; }
        if ((a.sr & 1u) != (g_sr & 1u)) { fprintf(stderr, "  sr T differs\n"); nb++; }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* outcome against the fixture */
    {
        int nb = 0;
        if (a.r[0] != sc->field) { fprintf(stderr, "  r0 %08x want %08x\n", a.r[0], sc->field); nb++; }
        if (a.r[3] != OBJ1_ADDR) { fprintf(stderr, "  r3 %08x want obj1 %08x\n", a.r[3], OBJ1_ADDR); nb++; }
        if (a.pr != pr) { fprintf(stderr, "  pr changed\n"); nb++; }
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
        printf("pointer_chase_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "field nonzero", .field = 0x12345678u },
        { .name = "field zero", .field = 0u },
        { .name = "field all ones", .field = 0xFFFFFFFFu },
        { .name = "field high", .field = 0xCAFEBABEu },
        { .name = "field small", .field = 0x0000000Fu },
        { .name = "field low bytes", .field = 0x00FF00FFu },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("pointer_chase_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
