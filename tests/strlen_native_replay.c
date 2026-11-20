/* Differential replay of the native string length (src/native/strlen.c,
 * 0x8C05342C) against the readable guest port
 * (src/fight/small_leaves.c, `vf3_strlen_entry`).
 *
 * Both sides seed the same flat RAM (the string) and the same register file,
 * then run the leaf.  The function is call-free, no-FPU and no-stack; it only
 * reads the string bytes and leaves r0/r3/r4/r5 and SR's T bit.  The output
 * registers and T bit are compared against the guest, every other register
 * equal to its entry value, the string bytes unchanged, and an independent
 * fixture model computes the length straight from the bytes. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "strlen.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_strlen_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x100000u

#define STR_BASE 0x0c108000u   /* the string lives well inside the window */

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static uint8_t ru8(uint32_t addr) { return *ab(addr); }

struct scenario {
    const char *name;
    uint32_t r_addr;      /* the string's start offset */
    const char *str;
};

#define RETURN_PC 0x0c0432e4u

/* the fixture model: the number of non-zero bytes before the first zero */
static unsigned model(const uint8_t *s)
{
    unsigned n = 0;
    while (*s) { ++n; ++s; }
    return n;
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc, uint32_t in_v[54])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = STR_BASE + sc->r_addr; /* r4: the string */
    s->v[0] = 0xdeadbeefu;           /* r0/r3/r5: clobbered */
    s->v[3] = 0x11111111u;
    s->v[5] = 0x22222222u;
    s->v[16] = RETURN_PC;            /* pr */
    s->v[17] = 0x60000000u;          /* sr, T clear: the leaf sets it */
    s->v[18] = 0x00024001u;          /* fpscr */
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
    printf("== %s (off %04x)\n", sc->name, sc->r_addr);

    /* seed a distinctive 0x7f fill so a wrong read/walk reads a non-guest
     * value, then place the string */
    memset(ram, 0x7f, RAM_SIZE);
    memcpy(ram + (STR_BASE + sc->r_addr - RAM_BASE), sc->str, strlen(sc->str) + 1u);

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54];
    setup_guest(&gs, &gmap, gwin, sc, in_v);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_strlen_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    memset(ram, 0x7f, RAM_SIZE);
    memcpy(ram + (STR_BASE + sc->r_addr - RAM_BASE), sc->str, strlen(sc->str) + 1u);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    vf3_native_strlen(&a);

    const uint8_t *s0 = ram + (STR_BASE + sc->r_addr - RAM_BASE);
    const uint32_t expect = model(s0);

    int bad = 0;

    /* output registers + T bit vs the guest */
    if (a.r[0] != gs.v[0]) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gs.v[0]); bad++; }
    if (a.r[3] != gs.v[3]) { fprintf(stderr, "  r3: native %08x guest %08x\n", a.r[3], gs.v[3]); bad++; }
    if (a.r[4] != gs.v[4]) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], gs.v[4]); bad++; }
    if (a.r[5] != gs.v[5]) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], gs.v[5]); bad++; }
    if ((a.sr & 1u) != (gs.v[17] & 1u)) {
        fprintf(stderr, "  T bit: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); bad++;
    }

    /* untouched registers keep their entry value */
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 0 || i == 3 || i == 4 || i == 5) continue;
        if (a.r[i] != in_v[i]) {
            fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++;
        }
    }

    /* the fixture model */
    if (a.r[0] != expect || a.r[5] != expect) {
        fprintf(stderr, "  r0/r5 want %08x\n", expect); bad++;
    }
    /* r4 ends one past the NUL */
    if (a.r[4] != STR_BASE + sc->r_addr + expect + 1u) {
        fprintf(stderr, "  r4 want %08x\n", STR_BASE + sc->r_addr + expect + 1u); bad++;
    }
    /* r3 is the NUL byte, sign-extended (0) */
    if (a.r[3] != 0u) { fprintf(stderr, "  r3 want 0\n"); bad++; }

    printf("  strlen: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "hello world",   .r_addr = 0x00u, .str = "hello, world" },
        { .name = "empty",         .r_addr = 0x40u, .str = "" },
        { .name = "single char",   .r_addr = 0x50u, .str = "a" },
        { .name = "abc",           .r_addr = 0x60u, .str = "abc" },
        { .name = "embedded NUL",  .r_addr = 0x70u, .str = "with\0embedded" },
        { .name = "26 a's",        .r_addr = 0x90u, .str = "aaaaaaaaaaaaaaaaaaaaaaaaaa" },
        { .name = "VF3tb",         .r_addr = 0xC0u, .str = "VF3tb" },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("strlen_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
