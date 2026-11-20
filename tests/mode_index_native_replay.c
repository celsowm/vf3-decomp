/* Differential replay of the native mode-index switch
 * (src/native/mode_index.c, 0x8C038990) against the readable guest port
 * (src/fight/mode_index.c, `vf3_mode_index_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf calls nobody, uses no FPU and
 * keeps no stack frame: it reads the four pool flags (as sign-extended
 * halfwords), walks the flag in r4 through the four constants then the four
 * pool flags, and answers with the matching index (or leaves the flag alone
 * when none matches).
 *
 * The literal pool sits at the game's own address, spanned by one flat buffer.
 * The whole region is compared byte for byte, together with the registers
 * (r0..r7 and the callee-saved r8..r14, which the leaf must not move) and the
 * T bit.  The outcome (r4 and the T bit) is also checked against an
 * independent model - the mapping written into the test, not read from the
 * port. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "mode_index.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_mode_index_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0c038af0u
#define RAM_SIZE 0x10u

/* the literal pool: the four flags that are not constants */
#define G_CASE4 (RAM_BASE + 0x02u)
#define G_CASE5 (RAM_BASE + 0x04u)
#define G_CASE6 (RAM_BASE + 0x06u)
#define G_CASE7 (RAM_BASE + 0x08u)

#define POOL_FLAG4 0x0111u
#define POOL_FLAG5 0x0222u
#define POOL_FLAG6 0x0333u
#define POOL_FLAG7 0x8444u

#define CALLER_R8 0x76543210u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint16_t r16(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint16_t)p[0] | ((uint16_t)p[1] << 8);
}
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}

struct scenario {
    const char *name;
    uint32_t flag;
    uint32_t index;
};

static void seed_all(void)
{
    memset(ram, 0, RAM_SIZE);
    memset(ram, 0x77, RAM_SIZE);
    w16(G_CASE4, POOL_FLAG4);
    w16(G_CASE5, POOL_FLAG5);
    w16(G_CASE6, POOL_FLAG6);
    w16(G_CASE7, POOL_FLAG7);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t flag)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = flag;
    s->v[15] = 0x0c108000u;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

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
    printf("== %s\n", sc->name);

    seed_all();
    uint8_t seed_shot[RAM_SIZE];
    memcpy(seed_shot, ram, RAM_SIZE);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, sc->flag);
    memcpy(ram, seed_shot, RAM_SIZE);   /* setup_guest does not seed RAM */
    const int ok_guest = vf3_mode_index_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the guest's RAM before the native re-seeds */
    uint8_t *gshot = (uint8_t *)malloc(RAM_SIZE);
    memcpy(gshot, ram, RAM_SIZE);

    /* ---- native side ---- */
    memcpy(ram, seed_shot, RAM_SIZE);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[4] = sc->flag;
    a.r[15] = 0x0c108000u;
    a.sr = 0x301u;
    a.fpscr = 0;
    vf3_native_mode_index(&a);

    int bad = 0;
    /* the guest's RAM snapshot vs the native run */
    if (memcmp(gshot, ram, RAM_SIZE)) {
        for (unsigned i = 0; i < RAM_SIZE; ++i)
            if (gshot[i] != ram[i]) {
                fprintf(stderr, "  ram %u: %02x want %02x\n", i, ram[i], gshot[i]);
                break;
            }
        bad = 1;
    }
    free(gshot);

    /* the answer and the T bit, against an independent model */
    const int expect_t = (sc->index != sc->flag);
    const uint32_t want_r4 = sc->index;
    const uint32_t want_r0 = sc->index;
    if (a.r[4] != want_r4 || a.r[0] != want_r0) {
        fprintf(stderr, "  r4/r0: native %08x/%08x want %08x/%08x\n",
                a.r[4], a.r[0], want_r4, want_r0);
        bad = 1;
    }
    if (((a.sr & 1u) != 0) != expect_t) {
        fprintf(stderr, "  sr T: native %u want %d\n", a.sr & 1u, expect_t);
        bad = 1;
    }

    /* the guest's own registers should equal the model too */
    if (gs.v[4] != want_r4 || gs.v[0] != want_r0 ||
        ((gs.v[17] & 1u) != 0) != expect_t) {
        fprintf(stderr, "  guest regs diverge from model\n");
        bad = 1;
    }

    printf("  %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)malloc(RAM_SIZE);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { "eight",       8u,   0u },
        { "sixteen",     16u,  1u },
        { "thirty two",  32u,  2u },
        { "sixty four",  64u,  3u },
        { "pool four",   POOL_FLAG4, 4u },
        { "pool five",   POOL_FLAG5, 5u },
        { "pool six",    POOL_FLAG6, 6u },
        { "pool seven",  (uint32_t)(int32_t)(int16_t)POOL_FLAG7, 7u },
        { "unknown",     0x1234u, 0x1234u },
        { "unknown negative", 0x8444u, 0x8444u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("mode_index_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
