/* Differential replay of the native scene-table bit-clear
 * (src/native/scene_clear_flag.c, 0x8C0624BA) against the readable guest
 * port (src/fight/gd_syscall_stub.c, `vf3_scene_clear_flag_entry`).
 *
 * Both sides seed the same flat RAM (the 4096-record scene table, stride 24,
 * at 0x0C16CF6C) and the same register file, then run the leaf.  The
 * function is call-free, no-FPU and no-stack.  The output registers
 * (r1, r5, r6, r7), the bit-0 clear of the found record (or none found), and
 * that every other register is equal to its entry value are compared against
 * the guest.  An independent fixture model computes the answer straight from
 * the table. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "scene_clear_flag.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_scene_clear_flag_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x200000u

#define TABLE_BASE 0x0C16CF6Cu   /* the scene object table (stride 24) */
#define TABLE_END  (TABLE_BASE + 24u * 0x1000u)   /* one past the last record */
#define LOW_END   0x0C160000u
#define HI_END    0x0C190000u

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint16_t r16(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
}
static void w16(uint32_t addr, uint16_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}

struct scenario {
    const char *name;
    uint32_t target;      /* r4: the record address to find */
    uint16_t found_word;  /* the first halfword of the found record (if on-table) */
};

#define RETURN_PC 0x0c062eacu /*(irrelevant; leaf pops pr)*/

/* the fixture model: what the body should produce */
static int model(const struct scenario *sc, uint16_t *word_out, uint32_t *r1,
                 uint32_t *r5, uint32_t *r6, uint32_t *r7, int *found)
{
    *r1 = 0x1000u;
    *r5 = TABLE_END;
    *r6 = TABLE_END;
    *r7 = 0x1000u;
    /* is sc->target one of the 4096 record addresses? */
    if (sc->target >= TABLE_BASE && sc->target < TABLE_END &&
        ((sc->target - TABLE_BASE) % 24u) == 0u) {
        *found = 1;
        *word_out = (uint16_t)(sc->found_word & 0xFFFEu);
    } else {
        *found = 0;
        *word_out = sc->found_word;
    }
    return 0;
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        const struct scenario *sc, uint32_t in_v[37])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = sc->target;        /* r4: the record address */
    for (unsigned i = 0; i < 37; ++i) in_v[i] = s->v[i];
    s->v[16] = RETURN_PC;        /* pr */
    s->v[17] = 0x60000000u;      /* sr */
    s->v[18] = 0x00024001u;      /* fpscr */
    s->budget = 4000000u;

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
    printf("== %s (target %08x word %04x)\n", sc->name, sc->target,
           (unsigned)sc->found_word);

    /* seed the table (all records distinct, first words varied) */
    memset(ram, 0x5a, RAM_SIZE);
    for (uint32_t i = 0; i < 0x1000u; ++i) {
        const uint32_t rec = TABLE_BASE + 24u * i;
        /* found_word only lands if sc->target is exactly this record's address */
        if (rec == sc->target) w16(rec, sc->found_word);
        else                  w16(rec, (uint16_t)(0x8000u + (i & 0x3ffu)));
    }

    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    uint32_t in_v[37];
    setup_guest(&gs, &gmap, gwin, sc, in_v);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_scene_clear_flag_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    uint8_t *gshot = (uint8_t *)malloc(HI_END - LOW_END);
    memcpy(gshot, ram + (LOW_END - RAM_BASE), HI_END - LOW_END);

    /* re-seed */
    memset(ram, 0x5a, RAM_SIZE);
    for (uint32_t i = 0; i < 0x1000u; ++i) {
        const uint32_t rec = TABLE_BASE + 24u * i;
        if (rec == sc->target) w16(rec, sc->found_word);
        else                   w16(rec, (uint16_t)(0x8000u + (i & 0x3ffu)));
    }

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    a.pr = RETURN_PC;
    a.sr = 0x60000000u;
    a.fpscr = 0x00024001u;
    vf3_native_scene_clear_flag(&a);

    uint16_t mword;
    uint32_t mr1, mr5, mr6, mr7;
    int mfound;
    model(sc, &mword, &mr1, &mr5, &mr6, &mr7, &mfound);

    int bad = 0;

    /* output registers vs the guest */
    if (a.r[1] != gs.v[1]) { fprintf(stderr, "  r1: native %08x guest %08x\n", a.r[1], gs.v[1]); bad++; }
    if (a.r[5] != gs.v[5]) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], gs.v[5]); bad++; }
    if (a.r[6] != gs.v[6]) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], gs.v[6]); bad++; }
    if (a.r[7] != gs.v[7]) { fprintf(stderr, "  r7: native %08x guest %08x\n", a.r[7], gs.v[7]); bad++; }

    /* every other register untouched vs entry */
    for (unsigned i = 0; i < 16; ++i) {
        if (i == 1 || i == 5 || i == 6 || i == 7) continue;
        if (a.r[i] != in_v[i]) { fprintf(stderr, "  r%u: native %08x entry %08x\n", i, a.r[i], in_v[i]); bad++; }
    }

    /* the RAM region matches the guest (the bit clear of the found record) */
    if (memcmp(ram + (LOW_END - RAM_BASE), gshot, HI_END - LOW_END) != 0) {
        fprintf(stderr, "  RAM region differs from guest\n"); bad++;
    }

    /* the independent fixture model */
    if (a.r[1] != mr1 || a.r[5] != mr5 || a.r[6] != mr6 || a.r[7] != mr7) {
        fprintf(stderr, "  model regs want %08x/%08x/%08x/%08x\n", mr1, mr5, mr6, mr7); bad++;
    }
    const uint16_t nword = (sc->target >= TABLE_BASE && sc->target < TABLE_END &&
                            ((sc->target - TABLE_BASE) % 24u) == 0u)
                           ? r16(sc->target) : sc->found_word;
    if (nword != mword) { fprintf(stderr, "  model word want %04x\n", mword); bad++; }
    if (mfound) {
        if (sc->target < TABLE_BASE || sc->target >= TABLE_END) { /* unreachable */ }
        const uint16_t got = r16(sc->target);
        if (got != mword) { fprintf(stderr, "  cleared word got %04x want %04x\n", got, mword); bad++; }
    }

    free(gshot);
    printf("  scene_clear_flag: %s\n", bad ? "DIFFERS" : "match");
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { .name = "found first record",     .target = TABLE_BASE,
          .found_word = 0xFFFFu },
        { .name = "found a middle record",  .target = TABLE_BASE + 24u * 0x555u,
          .found_word = 0xFFFFu },
        { .name = "found last record",      .target = TABLE_BASE + 24u * 0xFFFu,
          .found_word = 0x0001u },
        { .name = "found, bit0 already clear", .target = TABLE_BASE + 24u * 0x123u,
          .found_word = 0x0000u },
        { .name = "found, only high bits",  .target = TABLE_BASE + 24u * 0x222u,
          .found_word = 0xFFFEu },
        { .name = "not found (between)",    .target = TABLE_BASE + 5u,
          .found_word = 0xFFFFu },
        { .name = "not found (below)', regs set regardless", .target = TABLE_BASE - 24u,
          .found_word = 0xFFFFu },
        { .name = "not found (above)",      .target = TABLE_END,
          .found_word = 0xFFFFu },
        { .name = "target 0",               .target = 0u,
          .found_word = 0xFFFFu },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("scene_clear_flag_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
