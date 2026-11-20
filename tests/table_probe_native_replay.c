/* Differential replay of the native indexed table probe (src/native/table_probe.c,
 * 0x8C040378) against the readable guest port
 * (src/fight/readable/table_probe.c, `vf3_table_probe_entry`).
 *
 * Both sides run on the same flat RAM: the guest through its ram map (one
 * window over the whole space), the native through `ram_base`.  The body is a
 * call-free, integer-only leaf (no FP, no stub), but it writes a transient
 * stack slot at sp-4 (r15 stays net flat), so the fixture lays the pool (the
 * table-base pointer at 0x0c0403bc), the table (0x0c19e310) and the stack
 * (0x0c31f000) out, patterns the whole window, and runs the two sides from the
 * same seed.  The whole RAM region is compared byte for byte, together with
 * the contract registers (r0, r1, r2, r3) and SR's T bit. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "table_probe.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_table_probe_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define TBL_BASE 0x0c19e310u   /* the table the pool points at */
#define POOL_SLOT 0x0c0403bcu  /* holds the table-base pointer */

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

struct scenario {
    const char *name;
    int32_t r4;
    uint32_t tbl[8];    /* the table words, stride 12, indices 0..7 */
};

#define R15 0x0c31f9c4u

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    /* pattern every window byte so a wrong address is visible */
    for (uint32_t ad = RAM_BASE; ad < RAM_BASE + RAM_SIZE; ad += 4)
        w32(ad, 0x22222222u + (ad & 0xff));
    /* pool: the table-base pointer */
    w32(POOL_SLOT, TBL_BASE);
    /* the table: words at indices 0..7 of stride twelve */
    for (unsigned i = 0; i < 8; ++i)
        w32(TBL_BASE + 12u * i, sc->tbl[i]);
    /* the stack slot above the frame holds a marker (it is not touched by the
     * body - the transient slot is at sp-4, below it) */
    w32(R15, 0x33333333u);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = (uint32_t)sc->r4;
    s->v[15] = R15;
    s->v[16] = 0x0c0409deu;             /* pr */
    s->v[17] = 0x60000000u;             /* sr, T clear */
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

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);
    const uint32_t sr = 0x60000000u;    /* T clear */

    /* ---- guest side ---- */
    seed_all(sc);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, sc);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_table_probe_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    const uint32_t g_r0 = gs.v[0], g_r1 = gs.v[1], g_r2 = gs.v[2], g_r3 = gs.v[3];
    const uint32_t g_r15 = gs.v[15], g_sr = gs.v[17];

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = (uint32_t)sc->r4;
    a.r[15] = R15;
    a.pr = 0x0c0409deu;
    a.sr = sr;
    a.fpscr = 0x00024001u;
    vf3_native_table_probe(&a, R15);

    int bad = 0;
    /* whole RAM bytes 0x0c040000..0x0c320000 (covers pool, table, stack) */
    {
        int nb = 0;
        const uint32_t lo = 0x0c040000u, hi = 0x0c320000u;
        for (uint32_t ad = lo; ad < hi; ad += 4) {
            uint32_t g = r32(ad), n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", lo, hi, nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* contract registers + T bit (r1/r3 are path-dependent; r15 must be flat) */
    {
        int nb = 0;
        if (a.r[0] != g_r0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], g_r0); nb++; }
        if (a.r[1] != g_r1) { fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], g_r1); nb++; }
        if (a.r[2] != g_r2) { fprintf(stderr, "  r2: native %08x guest %08x\n", a.r[2], g_r2); nb++; }
        if (a.r[3] != g_r3) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], g_r3); nb++; }
        if (a.r[15] != g_r15) { fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], g_r15); nb++; }
        if ((a.sr & 1u) != (g_sr & 1u)) {
            fprintf(stderr, "  sr T: native %u guest %u\n", a.sr & 1u, g_sr & 1u); nb++;
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* the outcome against the fixture itself, independent of the port:
     * the transient stack slot holds r4 and the answer/T pattern per path */
    {
        const int32_t r4i = sc->r4;
        int nb = 0;
        if (r32(R15 - 4u) != (uint32_t)r4i) {
            fprintf(stderr, "  stack slot: got %08x want %08x\n", r32(R15 - 4u), (uint32_t)r4i);
            nb++;
        }
        if (a.r[2] != (uint32_t)r4i || a.r[15] != R15) {
            fprintf(stderr, "  r2 or r15 drifted (r2 %08x r15 %08x)\n", a.r[2], a.r[15]);
            nb++;
        }
        if (r4i < 0) {
            if (a.r[0] != 0xffffffffu || (a.sr & 1u) != 0u ||
                a.r[1] != 0x76543211u || a.r[3] != 0x76543213u) {
                fprintf(stderr, "  below range r0 %08x r1 %08x r3 %08x T %u\n",
                        a.r[0], a.r[1], a.r[3], a.sr & 1u);
                nb++;
            }
        } else if (r4i >= 8) {
            if (a.r[0] != 0xffffffffu || (a.sr & 1u) != 1u ||
                a.r[1] != 8u || a.r[3] != (uint32_t)r4i) {
                fprintf(stderr, "  above range r0 %08x r1 %08x r3 %08x T %u\n",
                        a.r[0], a.r[1], a.r[3], a.sr & 1u);
                nb++;
            }
        } else {
            const unsigned idx = (unsigned)r4i;
            const uint32_t val = sc->tbl[idx];
            const uint32_t want = (val == 0xffffffffu) ? 0xfffffffeu : 0u;
            const unsigned T = (val == 0xffffffffu) ? 1u : 0u;
            if (a.r[1] != TBL_BASE || a.r[3] != (uint32_t)r4i ||
                a.r[0] != want || (a.sr & 1u) != T) {
                fprintf(stderr, "  in-range r0 %08x r1 %08x r3 %08x T %u, want %08x %08x %u\n",
                        a.r[0], a.r[1], a.r[3], a.sr & 1u, want, TBL_BASE, T);
                nb++;
            }
        }
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
        printf("table_probe_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "index 3, -1 entry",
          .r4 = 3, .tbl = { 0, 0, 0, 0xffffffffu, 0, 0, 0, 0 } },
        { .name = "index 4, -1 entry",
          .r4 = 4, .tbl = { 0, 0, 0, 0, 0xffffffffu, 0, 0, 0 } },
        { .name = "index 5, -1 entry",
          .r4 = 5, .tbl = { 0, 0, 0, 0, 0, 0xffffffffu, 0, 0 } },
        { .name = "index 0, live entry",
          .r4 = 0, .tbl = { 0x7f800001u, 0, 0, 0, 0, 0, 0, 0 } },
        { .name = "index 7, live entry",
          .r4 = 7, .tbl = { 0, 0, 0, 0, 0, 0, 0, 0x1234abcd } },
        { .name = "index 1, live entry",
          .r4 = 1, .tbl = { 0, 0xdeadbeefu, 0, 0, 0, 0, 0, 0 } },
        { .name = "index -3, below range",
          .r4 = -3, .tbl = { 0, 0, 0, 0xffffffffu, 0, 0, 0, 0 } },
        { .name = "index 8, above range",
          .r4 = 8, .tbl = { 0, 0, 0, 0, 0xffffffffu, 0, 0, 0 } },
        { .name = "index -1, below range",
          .r4 = -1, .tbl = { 0, 0, 0, 0, 0, 0xffffffffu, 0, 0 } },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("table_probe_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
