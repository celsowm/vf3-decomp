/* Differential replay of the native negate-copy (src/native/negate_copy.c,
 * 0x8C072B02) against the readable guest port (src/fight/negate_copy.c,
 * `vf3_negate_copy_entry`).
 *
 * Both sides seed the same flat RAM (the descriptor at [r5], the source
 * region and the destination region) and the same register file, then run the
 * leaf.  The function is call-free and no-FPU; it reads the descriptor and
 * the source and writes the destination, and leaves r4/r6/r7 and SR's T bit.
 * The whole RAM span the two could touch is compared byte for byte against a
 * snapshot of the guest's writes, together with the output registers
 * (r4, r6, r7) and SR's T bit, the untouched ones, and an independent fixture
 * model that computes the copied words straight from the source, including
 * the sign flip of the second three. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "negate_copy.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_negate_copy_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x180000u

#define DESC_BASE 0x0c120000u   /* the descriptor {count, src, dst} at [r5] */
#define SRC_BASE  0x0c130000u
#define DST_BASE  0x0c140000u
#define LOW_END   0x0c110000u   /* the compared span starts below the desc */
#define HI_END    0x0c160000u

#define SIGN 0x80000000u

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
    int32_t count;
    uint32_t r5;
};

#define RETURN_PC 0x0c0432e4u

static void seed_all(const struct scenario *sc)
{
    (void)sc;
    memset(ram, 0x33, RAM_SIZE);
    /* the descriptor at [r5] */
    w32(sc->r5, (uint32_t)sc->count);
    w32(sc->r5 + 4u, SRC_BASE);
    w32(sc->r5 + 8u, DST_BASE);
    /* the source: 6 words per entry, some with the sign bit set - every word
     * distinct so a wrong read or offset reads a non-guest value */
    for (int e = 0; e < 8; ++e)
        for (int i = 0; i < 6; ++i) {
            uint32_t v = 0x3f000000u + (uint32_t)(e * 6 + i);
            if (i >= 3) v |= SIGN;      /* the second three carry the sign bit */
            w32(SRC_BASE + 4u * (uint32_t)(e * 6 + i), v);
        }
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc, uint32_t in_v[54])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[5] = sc->r5;              /* r5: the descriptor */
    s->v[4] = 0x11111111u;         /* r4/r6/r7: clobbered by the body */
    s->v[6] = 0x22222222u;
    s->v[7] = 0x33333333u;
    s->v[16] = RETURN_PC;          /* pr */
    s->v[17] = 0x60000001u;        /* sr, T set */
    s->v[18] = 0x00024001u;        /* fpscr */
    s->budget = 4000000u;
    memcpy(in_v, s->v, 54 * sizeof(uint32_t));

    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE;
    win[0].len = RAM_SIZE;
    win[0].data = ram;
    map->wins = win;
    map->n = 1;
    map->oob = 0;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s (count %d)\n", sc->name, sc->count);

    seed_all(sc);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54];
    setup_guest(&gs, &gmap, gwin, sc, in_v);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_negate_copy_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    uint8_t *gshot = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(gshot, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);

    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000001u;
    a.fpscr = 0x00024001u;
    vf3_native_negate_copy(&a);

    int bad = 0;

    /* RAM: native writes vs the guest snapshot, byte for byte */
    {
        int nb = 0;
        for (uint32_t ad = LOW_END; ad < HI_END; ad += 4) {
            uint32_t n = vf3_aim_u32(&a, ad);
            uint32_t g;
            memcpy(&g, gshot + (ad - LOW_END), 4);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", LOW_END, HI_END, nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    /* output + untouched registers */
    if (a.r[4] != gs.v[4]) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gs.v[4]); bad++; }
    if (a.r[6] != gs.v[6]) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], gs.v[6]); bad++; }
    if (a.r[7] != gs.v[7]) { fprintf(stderr, "  r7: native %08x guest %08x\n", a.r[7], gs.v[7]); bad++; }
    if ((a.sr & 1u) != (gs.v[17] & 1u)) {
        fprintf(stderr, "  T bit: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); bad++;
    }
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 4 || i == 6 || i == 7) continue;
        if (i == 5) { if (a.r[i] != in_v[i]) { fprintf(stderr, "  r5: native %08x entry %08x\n", a.r[i], in_v[i]); bad++; } continue; }
        if (a.r[i] != in_v[i]) {
            fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++;
        }
    }

    /* the fixture model: source words, second three sign-flipped */
    {
        int nb = 0;
        uint32_t src = SRC_BASE, dst = DST_BASE;
        int32_t c = sc->count;
        while (c > 0) {
            for (int i = 0; i < 6; ++i) {
                uint32_t srcv = r32(src);
                uint32_t want = (i >= 3) ? (srcv ^ SIGN) : srcv;
                if (r32(dst) != want) {
                    fprintf(stderr, "  dst @%08x want %08x got %08x\n", dst, want, r32(dst)); nb++;
                }
                src += 4; dst += 4;
            }
            --c;
        }
        printf("  model: %s\n", nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    free(gshot);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "one entry",        .count = 1,  .r5 = 0x0c120000u },
        { .name = "two entries",      .count = 2,  .r5 = 0x0c120010u },
        { .name = "three entries",    .count = 3,  .r5 = 0x0c120020u },
        { .name = "four entries",     .count = 4,  .r5 = 0x0c120030u },
        { .name = "zero entries",     .count = 0,  .r5 = 0x0c120040u },
        { .name = "negative count",   .count = -2, .r5 = 0x0c120050u },
        { .name = "five entries",     .count = 5,  .r5 = 0x0c120060u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("negate_copy_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
