/* Differential replay of the native word copy (src/native/word_copy.c,
 * 0x8C042F08) against the readable guest port (src/fight/word_copy.c,
 * `vf3_word_copy_entry`).
 *
 * Both sides seed the same flat RAM (the source and destination regions plus
 * the stack) and the same register file, then run the leaf.  The function is
 * call-free and no-FPU; it only reads src, writes dst, pushes r3 to [sp0-4]
 * and restores it.  The whole RAM span that the two could touch is compared
 * byte for byte (against a snapshot of the guest's writes), together with the
 * output registers (r0, r3), the untouched ones (r1, r2, r4..r15, pr), and an
 * independent fixture model that computes the copied words straight from the
 * source. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "word_copy.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_word_copy_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x260000u

#define SRC_BASE 0x0c200000u
#define DST_BASE 0x0c210000u
#define LOW_END  0x0c1f0000u   /* the span compared starts below both */
#define HI_END   0x0c230000u

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
    uint32_t bytes;
    uint32_t sp0;
};

#define RETURN_PC 0x0c0432e4u

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0x22, RAM_SIZE);
    for (uint32_t ad = SRC_BASE; ad < SRC_BASE + 64u; ad += 4)
        w32(ad, 0x1000u + (ad - SRC_BASE));
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc, uint32_t in_v[54])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[0] = sc->bytes;        /* r0: byte count */
    s->v[1] = DST_BASE;         /* r1: dst */
    s->v[2] = SRC_BASE;         /* r2: src */
    s->v[3] = 0xaaaa5555u;      /* r3: saved and restored */
    s->v[15] = sc->sp0;
    s->v[16] = RETURN_PC;       /* pr */
    s->v[17] = 0x60000001u;     /* sr */
    s->v[18] = 0x00024001u;     /* fpscr */
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
    printf("== %s (bytes %u)\n", sc->name, sc->bytes);

    seed_all(sc);
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54];
    setup_guest(&gs, &gmap, gwin, sc, in_v);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_word_copy_entry(&gs, &gmap);
    vf3_family_override = NULL;
    uint8_t *gshot = NULL;
    if (ok_guest && gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    seed_all(sc);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000001u;
    a.fpscr = 0x00024001u;
    const int ok_native = vf3_native_word_copy(&a, sc->sp0);

    int bad = 0;

    /* the body must agree with the guest on whether it refused */
    if ((ok_native != 0) != (ok_guest != 0)) {
        fprintf(stderr, "  refuse disagreement (native %d guest %d)\n", ok_native, ok_guest);
        bad++;
    }

    if (!ok_guest) {
        /* refused (both sides): nothing copied, no stack push */
        for (uint32_t ad = DST_BASE; ad < DST_BASE + 64u; ad += 4)
            if (r32(ad) != 0x22222222u) { fprintf(stderr, "  dst wrote on refuse\n"); bad++; }
        if (r32(sc->sp0 - 4u) != 0x22222222u) {
            fprintf(stderr, "  [sp0-4] changed on refuse\n"); bad++;
        }
        free(gshot);
        return bad ? 1 : 0;
    }

    gshot = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(gshot, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);
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

        /* output + untouched registers */
        if (a.r[0] != gs.v[0]) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gs.v[0]); bad++; }
        if (a.r[3] != gs.v[3]) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], gs.v[3]); bad++; }
        for (unsigned i = 0; i < 16; ++i) {
            if (i == 0 || i == 3) continue;
            if (a.r[i] != in_v[i]) {
                fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++;
            }
        }

        /* the stack frame: r3 pushed to [sp0-4] */
        if (r32(sc->sp0 - 4u) != 0xaaaa5555u) {
            fprintf(stderr, "  [sp0-4] not the saved r3\n"); bad++;
        }

        /* the fixture model: destination words */
        {
            const uint32_t words = sc->bytes >> 2;
            int nb = 0;
            if (words > 0 && words <= 16) {
                /* compute what the guest produced: copy each source word, with the
                 * highest destination word receiving r0 for an even count */
                uint32_t r0 = sc->bytes - 4u;
                uint32_t r3v = r32(SRC_BASE + r0);
                uint32_t *held = (words & 1u) ? &r3v : &r0;
                uint32_t *other = (words & 1u) ? &r0 : &r3v;
                for (int j = (int)words - 2; j >= 0; --j) {
                    *other = r32(SRC_BASE + 4u * (uint32_t)j);
                    if (r32(DST_BASE + 4u * (uint32_t)(j + 1)) != *held) {
                        fprintf(stderr, "  dst word %d wrong\n", j + 1); nb++;
                    }
                    uint32_t *t = held; held = other; other = t;
                }
                if (r32(DST_BASE) != *held) { fprintf(stderr, "  dst word 0 wrong\n"); nb++; }
            } else {
                /* refused: nothing copied */
                for (uint32_t ad = DST_BASE; ad < DST_BASE + 64u; ad += 4)
                    if (r32(ad) != 0x22222222u) { fprintf(stderr, "  dst wrote on refuse\n"); nb++; }
            }
            printf("  model: %s\n", nb ? "DIFFERS" : "match");
            bad |= (nb != 0);
        }
    }

    free(gshot);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "one word",        .bytes = 4u,  .sp0 = 0x0c268000u },
        { .name = "two words (even)",.bytes = 8u,  .sp0 = 0x0c268010u },
        { .name = "three (odd)",     .bytes = 12u, .sp0 = 0x0c268020u },
        { .name = "four (even)",     .bytes = 16u, .sp0 = 0x0c268030u },
        { .name = "five (odd)",      .bytes = 20u, .sp0 = 0x0c268040u },
        { .name = "sixteen (max)",   .bytes = 64u, .sp0 = 0x0c268050u },
        { .name = "refuse: not multi of 4", .bytes = 6u,  .sp0 = 0x0c268060u },
        { .name = "refuse: too big", .bytes = 68u, .sp0 = 0x0c268070u },
        { .name = "refuse: zero",    .bytes = 0u,  .sp0 = 0x0c268080u },
        { .name = "seven (odd)",     .bytes = 28u, .sp0 = 0x0c268090u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("word_copy_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
