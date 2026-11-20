/* Differential replay of the native slot-claim scan (src/native/slot_claim.c,
 * 0x8C062490) against the readable guest port
 * (src/fight/readable/slot_claim.c, `vf3_slot_claim_entry`).
 *
 * Both sides run on the same flat RAM: the guest through its ram map (one
 * window over the whole space), the native through `ram_base`.  The body is a
 * call-free, integer-only, no-stack leaf (it tail-returns through r16, never
 * touches r15), so it needs no stub and no FPU wrappers.  The fixture lays out
 * the literal pool (the base pointer at 0x0c062590, the signed count at
 * 0x0c06258a) and the 0x18-stride slot array, and runs the two sides from the
 * same seed.
 *
 * The pool and the slot array are compared byte for byte, together with the
 * contract registers (r0 = the found slot or 0, r3, r4/r6, r5 = 1, r7 and
 * SR's T bit; r1/r2/r15 untouched). */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "slot_claim.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_slot_claim_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define POOL_BASE 0x0c062590u   /* holds the slot array base pointer */
#define POOL_CNT  0x0c06258au   /* holds the signed 16-bit count */
#define SLOT_BASE 0x0c16cf6cu   /* the array base */

#define POOL_LO 0x0c062000u
#define POOL_HI 0x0c063000u
#define SLOT_LO 0x0c16c000u
#define SLOT_HI 0x0c16e000u

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
    int32_t count;
    uint16_t tags[8];
};

static uint32_t slot_va(unsigned i) { return SLOT_BASE + 0x18u * i; }

static const uint32_t ENTRY = 0x0c062490u;

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t pr, uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = 0x0c47f000u;             /* r15, untouched */
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00024001u;             /* fpscr: the chain's FPU gate */
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
    /* the literal pool */
    w32(POOL_BASE, SLOT_BASE);
    w16(POOL_CNT, (uint16_t)(int16_t)sc->count);
    /* the slots: each 0x18 stride, a 16-bit tag at the slot start; guard bytes
     * beyond the tag so an overwrite (especially a u16 vs u8 mark) is visible */
    for (unsigned i = 0; i < 8; ++i) {
        uint8_t *p = ab(slot_va(i));
        w16(slot_va(i), sc->tags[i]);
        p[2] = (uint8_t)(0xA0u + i);
    }
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c062004u;
    const uint32_t sr = 0x60000000u;    /* T clear */

    /* ---- guest side ---- */
    seed_all(sc);

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, pr, sr);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_slot_claim_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot compared regions */
    const size_t l0 = POOL_HI - POOL_LO, l1 = SLOT_HI - SLOT_LO;
    uint8_t *snap = (uint8_t *)malloc(l0 + l1);
    memcpy(snap, ab(POOL_LO), l0);
    memcpy(snap + l0, ab(SLOT_LO), l1);

    /* guest contract registers */
    const uint32_t g_r0 = gs.v[0], g_r3 = gs.v[3], g_r4 = gs.v[4];
    const uint32_t g_r5 = gs.v[5], g_r6 = gs.v[6], g_r7 = gs.v[7];
    const uint32_t g_r1 = gs.v[1], g_r2 = gs.v[2], g_r15 = gs.v[15], g_sr = gs.v[17];

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
    vf3_native_slot_claim(&a, 0x0c47f000u);

    int bad = 0;

    /* RAM ranges */
    {
        int nb = 0;
        for (uint32_t ad = POOL_LO; ad < POOL_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, snap + (ad - POOL_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  pool @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  pool: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }
    {
        int nb = 0;
        for (uint32_t ad = SLOT_LO; ad < SLOT_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, snap + l0 + (ad - SLOT_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  slots @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  slots: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* contract registers */
    {
        int nb = 0;
        if (a.r[0] != g_r0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], g_r0); nb++; }
        if (a.r[1] != g_r1) { fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], g_r1); nb++; }
        if (a.r[2] != g_r2) { fprintf(stderr, "  r2: native %08x guest %08x\n", a.r[2], g_r2); nb++; }
        if (a.r[3] != g_r3) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], g_r3); nb++; }
        if (a.r[4] != g_r4) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], g_r4); nb++; }
        if (a.r[5] != g_r5) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], g_r5); nb++; }
        if (a.r[6] != g_r6) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], g_r6); nb++; }
        if (a.r[7] != g_r7) { fprintf(stderr, "  r7: native %08x guest %08x\n", a.r[7], g_r7); nb++; }
        if (a.r[15] != g_r15) { fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], g_r15); nb++; }
        if ((a.sr & 1u) != (g_sr & 1u)) {
            fprintf(stderr, "  sr T: native %u guest %u\n", a.sr & 1u, g_sr & 1u); nb++;
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* outcome against the fixture: first free slot honouring the do-while */
    {
        uint32_t want_addr = 0;
        unsigned iters = 0;
        for (;;) {
            const unsigned i = iters;
            if ((sc->tags[i] & 0x01u) == 0u) { want_addr = slot_va(i); break; }
            if ((int32_t)(iters + 1) >= sc->count) break;
            ++iters;
            if (iters >= 8) break;
        }
        if (a.r[0] != want_addr) {
            fprintf(stderr, "  r0 %08x, want %08x\n", a.r[0], want_addr); bad++;
        }
        if (want_addr != 0) {
            unsigned wi = 0;
            while (slot_va(wi) != want_addr) ++wi;
            if (a.r[4] != want_addr || a.r[6] != want_addr || a.r[7] != (uint32_t)wi) {
                fprintf(stderr, "  found r4/6/7 %08x/%08x/%u want %08x/%08x/%u\n",
                        a.r[4], a.r[6], a.r[7], want_addr, want_addr, wi); bad++;
            }
        }
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
        printf("slot_claim_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "count0 first slot free",
          .count = 0, .tags = { 0x00, 0x01, 0x01, 0x01, 0, 0, 0, 0 } },
        { .name = "first slot free",
          .count = 4, .tags = { 0x03, 0x05, 0x07, 0x0b, 0, 0, 0, 0 } },
        { .name = "second slot free",
          .count = 4, .tags = { 0x01, 0x02, 0x05, 0x07, 0, 0, 0, 0 } },
        { .name = "fourth slot free",
          .count = 6, .tags = { 0x01, 0x03, 0x05, 0x00, 0x07, 0x09, 0, 0 } },
        { .name = "high nibble set free",
          .count = 2, .tags = { 0x01, 0x0100, 0, 0, 0, 0, 0, 0 } },
        { .name = "all occupied",
          .count = 4, .tags = { 0x01, 0x03, 0x05, 0x07, 0x00, 0, 0, 0 } },
        { .name = "negative count occupied first",
          .count = -2, .tags = { 0x01, 0x00, 0, 0, 0, 0, 0, 0 } },
        { .name = "count1 occupied",
          .count = 1, .tags = { 0x01, 0x00, 0, 0, 0, 0, 0, 0 } },
        { .name = "count stops before free",
          .count = 2, .tags = { 0x01, 0x03, 0x00, 0, 0, 0, 0, 0 } },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("slot_claim_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
