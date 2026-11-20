/* Differential replay of the native record flag-40 probe
 * (src/native/record_flag40.c, 0x8C04B9BE) against the readable guest port
 * (src/fight/small_leaves.c, `vf3_record_flag40_entry`).
 *
 * Both sides seed the same flat RAM (the record, plus the aux byte the second
 * word points at) and the same register file, then run the leaf.  The
 * function is call-free, no-FPU and no-stack.  The output registers (r0, r1)
 * and SR's T bit are compared against the guest, every other register equal
 * to its entry value, and an independent fixture model computes the answer
 * straight from the record. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "record_flag40.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_record_flag40_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x110000u

#define REC_BASE 0x0c110000u   /* the record (kind, ptr) */
#define AUX_BASE 0x0c118000u   /* the byte the record's second word points at */
#define SC_AUX_ADDR (AUX_BASE + 16u)   /* the byte the read lands on */
#define LOW_END  0x0c100000u
#define HI_END   0x0c11a000u

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
    uint32_t kind;       /* the record's first word */
    uint32_t aux;        /* the value written at [AUX_BASE + 16] */
};

#define RETURN_PC 0x0c0432e4u

/* the fixture model: what the body should produce (r1_in = the entry r1) */
static void model(const struct scenario *sc, uint32_t r1_in, uint32_t *r0, uint32_t *r1, uint32_t *t)
{
    *t = (sc->kind == 1u) ? 1u : 0u;
    if (sc->kind == 1u) {
        *r0 = 0;
        *r1 = r1_in;         /* r1 untouched on this path */
    } else {
        *r1 = 16;
        *r0 = (sc->aux & 0x40u);
    }
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc, uint32_t in_v[54])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = REC_BASE;              /* r4: the record */
    s->v[0] = 0xdeadbeefu;           /* r0/r1: clobbered */
    s->v[1] = 0xabcdef01u;
    s->v[16] = RETURN_PC;            /* pr */
    s->v[17] = 0x60000000u;          /* sr, T clear */
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
    printf("== %s (kind %u aux %02x)\n", sc->name, sc->kind, (unsigned)(sc->aux & 0xff));

    /* seed the record and the aux region */
    memset(ram, 0x5a, RAM_SIZE);
    w32(REC_BASE, sc->kind);
    w32(REC_BASE + 4u, AUX_BASE);
    *ab(SC_AUX_ADDR) = (uint8_t)(sc->aux & 0xff);
    for (int i = 0; i < 16; ++i) *ab(AUX_BASE + (uint32_t)i) = 0x91;   /* other bytes */

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[54];
    setup_guest(&gs, &gmap, gwin, sc, in_v);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_record_flag40_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    uint8_t *gshot = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(gshot, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);

    /* re-seed */
    memset(ram, 0x5a, RAM_SIZE);
    w32(REC_BASE, sc->kind);
    w32(REC_BASE + 4u, AUX_BASE);
    *ab(SC_AUX_ADDR) = (uint8_t)(sc->aux & 0xff);

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    vf3_native_record_flag40(&a);

    uint32_t mr0, mr1, mt;
    model(sc, in_v[1], &mr0, &mr1, &mt);

    int bad = 0;

    /* output registers + T vs the guest */
    if (a.r[0] != gs.v[0]) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], gs.v[0]); bad++; }
    if (a.r[1] != gs.v[1]) { fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], gs.v[1]); bad++; }
    if ((a.sr & 1u) != (gs.v[17] & 1u)) {
        fprintf(stderr, "  T bit: native %u guest %u\n", a.sr & 1u, gs.v[17] & 1u); bad++;
    }

    /* every other register untouched vs entry */
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 0 || i == 1) continue;
        if (a.r[i] != in_v[i]) { fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++; }
    }

    /* the independent fixture model */
    if (a.r[0] != mr0 || a.r[1] != mr1) {
        fprintf(stderr, "  model r0/r1 want %08x/%08x\n", mr0, mr1); bad++;
    }
    if ((a.sr & 1u) != mt) { fprintf(stderr, "  model T want %u\n", mt); bad++; }

    free(gshot);
    printf("  record_flag40: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "kind 1 -> 0",         .kind = 1u,          .aux = 0x40u },
        { .name = "kind 1 clears r1",    .kind = 1u,          .aux = 0xffu },
        { .name = "kind 0 bit set",      .kind = 0u,          .aux = 0x40u },
        { .name = "kind 0 bit clear",    .kind = 0u,          .aux = 0x00u },
        { .name = "kind 0 other bit",    .kind = 0u,          .aux = 0x80u },
        { .name = "kind 2",              .kind = 2u,          .aux = 0x7fu },
        { .name = "kind 0x40000001",     .kind = 0x40000001u, .aux = 0x40u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("record_flag40_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
