/* Differential replay of the native four-threshold counter selection
 * (src/native/counter_select.c, 0x8C0C10A2) against the readable guest port
 * (src/fight/readable/counter_select.c, `vf3_counter_select_entry`).
 *
 * Both sides run on the same flat RAM: the guest through its ram map (one
 * window over the whole space), the native through `ram_base`.  The body is a
 * call-free, integer-only leaf (no FP, no stub), but it pushes r14/r13 and
 * allocates a 16-byte frame at SP0-24, so the fixture lays the pool
 * (below the base pointer at 0x0c0c11e0 and the halfwords 0x0c0c11ce..11d6),
 * the target structure and the stack out, patterns the whole window, and runs
 * the two sides from the same seed.  The whole RAM region is compared byte
 * for byte, together with the contract registers (r0..r7, r13, r14, r15) and
 * SR's T bit. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "counter_select.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_counter_select_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define BASE 0x0c29f000u          /* the target structure's base (== WIN2) */

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
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}

struct scenario {
    const char *name;
    uint32_t mask;
    int16_t hw_ce;
    uint32_t sp0;
    int32_t m1, m2, m3, m4;
};

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    for (uint32_t ad = RAM_BASE; ad < RAM_BASE + RAM_SIZE; ad += 4)
        w32(ad, 0x22222222u + (ad & 0xff));
    /* pool: the base pointer and the four signed halfword masks + hw_ce */
    w32(0x0c0c11e0u, BASE);
    w16(0x0c0c11ceu, (uint16_t)(int16_t)sc->hw_ce);
    w16(0x0c0c11d0u, (uint16_t)(int16_t)sc->m1);
    w16(0x0c0c11d2u, (uint16_t)(int16_t)sc->m2);
    w16(0x0c0c11d4u, (uint16_t)(int16_t)sc->m3);
    w16(0x0c0c11d6u, (uint16_t)(int16_t)sc->m4);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->mask;             /* r4 */
    s->v[15] = sc->sp0;             /* r15 */
    s->v[16] = 0x0c0c1120u;         /* pr */
    s->v[17] = 0x60000000u;         /* sr, T clear */
    s->v[18] = 0x00024001u;         /* fpscr: the chain's FPU gate */
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
    const int ok_guest = vf3_counter_select_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    const uint32_t gr[11] = { gs.v[0], gs.v[1], gs.v[2], gs.v[3], gs.v[4],
                              gs.v[5], gs.v[6], gs.v[7], gs.v[13], gs.v[14],
                              gs.v[15] };
    const uint32_t g_sr = gs.v[17];

    /* ---- native side ---- */
    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = sc->mask;
    a.r[15] = sc->sp0;
    a.pr = 0x0c0c1120u;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    vf3_native_counter_select(&a, sc->sp0);

    int bad = 0;
    /* whole RAM bytes covering pool + struct + stack */
    {
        int nb = 0;
        const uint32_t lo = 0x0c0c1000u, hi = 0x0c320000u;
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

    /* contract registers + T bit */
    {
        static const char *nm[11] = { "r0", "r1", "r2", "r3", "r4", "r5",
                                      "r6", "r7", "r13", "r14", "r15" };
        int nb = 0;
        const uint32_t nv[11] = { a.r[0], a.r[1], a.r[2], a.r[3], a.r[4],
                                  a.r[5], a.r[6], a.r[7], a.r[13], a.r[14],
                                  a.r[15] };
        for (unsigned i = 0; i < 11; ++i)
            if (nv[i] != gr[i]) {
                fprintf(stderr, "  %s: native %08x guest %08x\n", nm[i], nv[i], gr[i]);
                nb++;
            }
        if ((a.sr & 1u) != (g_sr & 1u)) {
            fprintf(stderr, "  sr T: native %u guest %u\n", a.sr & 1u, g_sr & 1u); nb++;
        }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* outcome against the fixture itself */
    {
        const int32_t mask = (int32_t)sc->mask;
        uint32_t r6c = 0, r5c = 4;
        uint32_t r7, t2, t3, r4out;
        if ((sc->m1 & mask) == 0) { r7 = r5c; r5c += 1; } else { r7 = r6c; r6c += 1; }
        if ((sc->m2 & mask) == 0) { t2 = r5c; r5c += 1; } else { t2 = r6c; r6c += 1; }
        if ((sc->m3 & mask) == 0) { t3 = r5c; r5c += 1; } else { t3 = r6c; r6c += 1; }
        uint32_t eT;
        if ((sc->m4 & mask) == 0) { r4out = r5c; eT = 1; } else { r4out = r6c; eT = 0; }

        int nb = 0;
        const uint32_t sp0 = sc->sp0;
        if (r32(sp0 - 4u) != 0x7654321eu || r32(sp0 - 8u) != 0x7654321du ||
            r32(sp0 - 24u) != BASE || r32(sp0 - 20u) != BASE + 0x58u ||
            r32(sp0 - 16u) != BASE + (uint32_t)sc->hw_ce ||
            r32(sp0 - 12u) != BASE + 0x2cu) {
            fprintf(stderr, "  stack frame words wrong\n"); nb++;
        }
        if (r16(BASE + 0x26u) != (uint16_t)r7 ||
            r16(BASE + 0x2cu + 0x26u) != (uint16_t)t2 ||
            r16(BASE + 0x58u + 0x26u) != (uint16_t)t3 ||
            r16(BASE + (uint32_t)sc->hw_ce + 0x26u) != (uint16_t)r4out) {
            fprintf(stderr, "  struct halfwords wrong\n"); nb++;
        }
        if (a.r[0] != 0x26u || a.r[2] != (uint32_t)sc->m3 ||
            a.r[3] != BASE + (uint32_t)sc->hw_ce || a.r[4] != r4out ||
            a.r[5] != r5c || a.r[6] != r6c || a.r[7] != r7 ||
            (a.sr & 1u) != eT || a.r[15] != sp0 ||
            a.r[13] != 0x7654321du || a.r[14] != 0x7654321eu) {
            fprintf(stderr, "  answer registers/T wrong\n"); nb++;
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
        printf("counter_select_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "mix of overlaps and clears",
          .mask = 0x00000001u, .hw_ce = 0x0374, .sp0 = 0x0c31fa34u,
          .m1 = 0x0001, .m2 = 0x0000, .m3 = 0x0001, .m4 = 0x0000 },
        { .name = "all clears -> all odd",
          .mask = 0x00000002u, .hw_ce = 0x0100, .sp0 = 0x0c31f9c8u,
          .m1 = 0x0000, .m2 = 0x0000, .m3 = 0x0000, .m4 = 0x0000 },
        { .name = "all overlaps -> all even",
          .mask = 0xffffffffu, .hw_ce = -16, .sp0 = 0x0c31fa40u,
          .m1 = 0x0001, .m2 = 0x0001, .m3 = 0x0001, .m4 = 0x0001 },
        { .name = "odd, even, odd, even",
          .mask = 0x00000001u, .hw_ce = 0x0200, .sp0 = 0x0c31fa10u,
          .m1 = 0x0000, .m2 = 0x0001, .m3 = 0x0000, .m4 = 0x0001 },
        { .name = "negative hw_ce, all odd",
          .mask = 0x00000004u, .hw_ce = 0xFFE0, .sp0 = 0x0c31f9e8u,
          .m1 = 0x0000, .m2 = 0x0000, .m3 = 0x0000, .m4 = 0x0000 },
        { .name = "two overlapping bits",
          .mask = 0x00000003u, .hw_ce = 0x0078, .sp0 = 0x0c31fa28u,
          .m1 = 0x0001, .m2 = 0x0002, .m3 = 0x0001, .m4 = 0x0002 },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("counter_select_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
