/* Differential replay of the native leading-zero count
 * (src/native/count_leading.c, 0x8C0769C6) against the readable guest port
 * (src/fight/count_leading.c, `vf3_count_leading_entry`).
 *
 * Both sides seed the same register file and run the leaf.  The function is a
 * call-free, no-FPU, no-stack, no-RAM leaf, so it needs no stub, no FPU
 * wrappers and no windows that carry data.  A single full window over the flat
 * RAM keeps the guest's reads in-bounds (the body reads nothing, so the OOB
 * counter must stay at zero).  The output registers (r0, r3, r5, r6) and the T
 * bit are compared against the guest, and every other register (r1, r2, r4,
 * r7..r14, r15, pr) is checked equal to the guest's entry value, plus an
 * independent fixture model that computes the answer straight from the word. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "count_leading.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_count_leading_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x100000u

static uint8_t *ram;

struct scenario {
    const char *name;
    uint32_t word;
};

#define RETURN_PC 0x0c0432e4u

/* the fixture model: number of high bits clear before the first set one
 * (31 minus the highest set bit's position, or 32 for zero) */
static unsigned model(uint32_t word)
{
    if (word == 0u) return 32;
    unsigned p = 31;
    while (!(word & (1u << p))) --p;
    return 31 - p;
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc, uint32_t in_v[54])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[0] = 0xdeadbeefu;      /* r0: clobbered by the body */
    s->v[3] = 0x11111111u;      /* r3, r5, r6: clobbered */
    s->v[5] = 0x22222222u;
    s->v[6] = 0x33333333u;
    s->v[4] = sc->word;
    s->v[16] = RETURN_PC;       /* pr */
    s->v[17] = 0x60000001u;     /* sr, T set */
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
    printf("== %s (word %08x)\n", sc->name, sc->word);

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54];
    setup_guest(&gs, &gmap, gwin, sc, in_v);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_count_leading_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000001u;
    a.fpscr = 0x00024001u;
    vf3_native_count_leading(&a);

    const uint32_t expect = (uint32_t)model(sc->word);
    int bad = 0;

    /* output registers + T bit vs the guest */
    if (a.r[0] != gs.v[0]) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gs.v[0]); bad++; }
    if (a.r[3] != gs.v[3]) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], gs.v[3]); bad++; }
    if (a.r[5] != gs.v[5]) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], gs.v[5]); bad++; }
    if (a.r[6] != gs.v[6]) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], gs.v[6]); bad++; }
    if ((a.sr & 1u) != (gs.v[17] & 1u)) {
        fprintf(stderr, "  T bit: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); bad++;
    }

    /* untouched registers keep their entry value */
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 0 || i == 3 || i == 5 || i == 6) continue;
        if (a.r[i] != in_v[i]) {
            fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++;
        }
    }

    /* the fixture model */
    if (a.r[0] != expect || a.r[6] != expect) {
        fprintf(stderr, "  r0/r6 want %08x\n", expect); bad++;
    }
    if (a.r[3] != sc->word) { fprintf(stderr, "  r3 want the word %08x\n", sc->word); bad++; }

    printf("  count_leading: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "zero -> 32",                .word = 0x00000000u },
        { .name = "top bit set -> 0",          .word = 0x80000000u },
        { .name = "bit 15 set -> 16",          .word = 0x00008000u },
        { .name = "all ones -> 0",             .word = 0xffffffffu },
        { .name = "one low bit -> 31",         .word = 0x00000001u },
        { .name = "one in the middle -> 23",   .word = 0x00000100u },
        { .name = "two high bits -> 0",        .word = 0xc0000000u },
        { .name = "value with many zeros -> 5",.word = 0x04000000u },
        { .name = "random pattern",            .word = 0x2468acf0u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("count_leading_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
