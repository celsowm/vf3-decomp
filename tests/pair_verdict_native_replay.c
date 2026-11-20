/* Differential replay of the native pair verdict (src/native/pair_verdict.c,
 * 0x8C074E7C) against the readable guest port (src/fight/pair_verdict.c,
 * `vf3_pair_verdict_entry`).
 *
 * Both sides run on the same flat RAM.  The leaf is handed two structures (r4
 * and r5) and writes a word into the first one: zero, or minus one, following
 * the guest's own decision tree (so the T bit it leaves is the one of the
 * last test it made).  It is integer-only and keeps a frame in which it saves
 * r13.
 *
 * The pool, the stack and the two structures sit at the game's own addresses,
 * spanned by one flat buffer.  The whole region is compared byte for byte,
 * together with the registers, the T bit and the written word against an
 * independent fixture model.  The scenarios cover every arm of the tree: both
 * gates, both arms, each byte value, a negative offset and a non-empty result
 * word. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "pair_verdict.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_pair_verdict_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define POOL_BASE 0x0c074f50u
#define POOL_LEN  0x24u
#define STACK_TOP 0x0c108000u
#define DATA_BASE 0x0c110000u
#define DATA_LEN  0x200u
#define CMP_HI    (DATA_BASE + DATA_LEN)
#define RAM_BASE  POOL_BASE
#define RAM_SIZE  (CMP_HI - RAM_BASE)

#define OFF_BYTE   (POOL_BASE + 0x00u)
#define OFF_FIELD  (POOL_BASE + 0x02u)
#define OFF_RESULT (POOL_BASE + 0x04u)
#define MASK_A     (POOL_BASE + 0x10u)
#define MASK_B     (POOL_BASE + 0x14u)
#define MASK_C     (POOL_BASE + 0x18u)
#define MASK_D     (POOL_BASE + 0x1cu)
#define MASK_E     (POOL_BASE + 0x20u)

#define WORD_OFFSET 0x48u
#define STRUCT_A  (DATA_BASE + 0x000u)
#define STRUCT_B  (DATA_BASE + 0x100u)

#define NWIN 3

struct scenario {
    const char *name;
    uint32_t word_a, word_b;
    uint8_t  byte;
    uint32_t field;
    int32_t  off_byte, off_field, off_result;
    uint32_t mask_a, mask_b, mask_c, mask_d, mask_e;
    uint32_t result;
};

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
static uint8_t  r8(uint32_t addr) { return ab(addr)[0]; }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void w16(uint32_t addr, uint16_t v)
{
    ab(addr)[0] = (uint8_t)v; ab(addr)[1] = (uint8_t)(v >> 8);
}
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);

    w16(OFF_BYTE,   (uint16_t)(int16_t)sc->off_byte);
    w16(OFF_FIELD,  (uint16_t)(int16_t)sc->off_field);
    w16(OFF_RESULT, (uint16_t)(int16_t)sc->off_result);
    w32(MASK_A, sc->mask_a);
    w32(MASK_B, sc->mask_b);
    w32(MASK_C, sc->mask_c);
    w32(MASK_D, sc->mask_d);
    w32(MASK_E, sc->mask_e);

    w32(STRUCT_A + WORD_OFFSET, sc->word_a);
    w32(STRUCT_B + WORD_OFFSET, sc->word_b);
    ab(STRUCT_B + (uint32_t)sc->off_byte)[0] = sc->byte;
    w32(STRUCT_A + (uint32_t)sc->off_field, sc->field);
    w32(STRUCT_A + (uint32_t)sc->off_result, sc->result);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = STRUCT_A;
    s->v[5] = STRUCT_B;
    s->v[15] = STACK_TOP;
    s->v[16] = 0x0c0abcdeu;
    s->v[17] = 0x301u;
    s->v[18] = 0;
    s->budget = 1000000u;

    memset(map, 0, sizeof *map);
    static const struct { uint32_t base, len; } W[NWIN] = {
        { POOL_BASE, POOL_LEN },
        { STACK_TOP - 4u, 0x20u },
        { DATA_BASE, DATA_LEN },
    };
    for (unsigned i = 0; i < NWIN; ++i) {
        win[i].base = W[i].base;
        win[i].len = W[i].len;
        win[i].data = ab(W[i].base);
    }
    map->wins = win;
    map->n = NWIN;
    map->oob = 0;
    map->device_read = NULL;
    map->device_write = NULL;
    map->device_context = NULL;
}

/* the fixture-based model; mirrored from the readable test's expect() */
static int field_block(const struct scenario *sc, uint32_t r7, int *t)
{
    *t = (sc->field == 0u);
    if (sc->field != 0u) return 0;
    *t = (r7 == 0u);
    return r7 == 0u;
}
static uint32_t deep_block(const struct scenario *sc, uint32_t r1, uint32_t r6, int *t)
{
    *t = (r1 == 0u);
    if (r1 != 0u) return 0xffffffffu;
    *t = ((r6 & sc->mask_e) == 0u);
    return ((r6 & sc->mask_e) != 0u) ? 0xffffffffu : 0u;
}
static int expect(const struct scenario *sc, uint32_t *written)
{
    const uint32_t r6 = sc->word_a;
    const uint32_t r7 = sc->word_b;
    const uint32_t r5 = sc->byte & 0xffu;
    uint32_t r13 = 0u;
    int t = 0;

    t = ((sc->mask_a & r7) == 0u);
    if (!t) {
        t = ((sc->mask_b & r7) == 0u);
        if (t) {
            const uint32_t c = sc->mask_c & r6;
            const uint32_t d = sc->mask_d & r6;
            t = (c == 0u);
            if (c == 0u) {
                if (field_block(sc, c, &t)) {
                    t = (r5 == 2u);
                    if (r5 == 2u) {
                        r13 = deep_block(sc, d, r6, &t);
                    } else {
                        t = (r5 == 5u);
                        if (r5 == 5u) r13 = deep_block(sc, d, r6, &t);
                    }
                }
            } else {
                int minus_one = 0;
                t = (d == 0u);
                if (d == 0u) {
                    t = (r5 == 4u);
                    if (r5 != 4u) {
                        t = (r5 == 5u);
                        if (r5 != 5u) minus_one = 1;
                    }
                }
                if (minus_one) r13 = 0xffffffffu;
                else (void)field_block(sc, c, &t);
            }
        }
    }
    *written = r13;
    return t;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    seed_all(sc);
    uint8_t *seed_shot = (uint8_t *)malloc(RAM_SIZE);
    memcpy(seed_shot, ram, RAM_SIZE);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[NWIN];
    setup_guest(&gs, &gmap, gwin);
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_pair_verdict_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        free(seed_shot);
        return 1;
    }

    uint8_t *gshot = (uint8_t *)malloc(RAM_SIZE);
    memcpy(gshot, ram, RAM_SIZE);

    /* ---- native side ---- */
    memcpy(ram, seed_shot, RAM_SIZE);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    for (unsigned i = 0; i < 16; ++i)
        memcpy(&a.fr[i], &gs.v[21u + i], 4);
    a.r[4] = STRUCT_A;
    a.r[5] = STRUCT_B;
    a.r[15] = STACK_TOP;
    a.pr = 0x0c0abcdeu;
    a.sr = 0x301u;
    a.fpscr = 0;
    a.fpul = gs.v[19];
    vf3_native_pair_verdict(&a);
    free(seed_shot);

    int bad = 0;

    /* RAM region */
    {
        int nb = 0;
        for (uint32_t ad = RAM_BASE; ad < CMP_HI; ad += 4) {
            uint32_t g = r32(ad), n = vf3_aim_u32(&a, ad);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", RAM_BASE, CMP_HI, nb ? "DIFFERS" : "match");
        bad |= nb;
    }
    free(gshot);

    /* registers + T bit + model */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i)
            if (a.r[i] != gs.v[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        if (a.pr != gs.v[16]) { fprintf(stderr, "  pr: %08x want %08x\n", a.pr, gs.v[16]); nb++; }
        if (a.fpul != gs.v[19]) { fprintf(stderr, "  fpul: %08x want %08x\n", a.fpul, gs.v[19]); nb++; }
        for (unsigned i = 0; i < 16; ++i) {
            uint32_t ub;
            memcpy(&ub, &a.fr[i], 4);
            if (ub != gs.v[21u + i]) { fprintf(stderr, "  fr%u differs\n", i); nb++; }
        }

        uint32_t written = 0;
        const int t_bit = expect(sc, &written);
        if (((a.sr & 1u) != 0) != (t_bit != 0)) {
            fprintf(stderr, "  T: native %u want %d\n", a.sr & 1u, t_bit);
            nb++;
        }
        const uint32_t result_addr = STRUCT_A + (uint32_t)sc->off_result;
        if (r32(result_addr) != written) {
            fprintf(stderr, "  result @%08x: native %08x want %08x\n",
                    result_addr, r32(result_addr), written);
            nb++;
        }
        printf("  regs+model: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)malloc(RAM_SIZE);
    if (!ram) return 2;

    static const struct scenario scenarios[] = {
        { "the first gate fails", 0x00000004u, 0x00000010u, 2u, 1u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the second gate fails", 0x00000004u, 0x00000003u, 2u, 1u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the first arm, the byte is 2", 0x00000010u, 0x00000001u, 2u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the first arm, the byte is 5", 0x00000010u, 0x00000001u, 5u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the first arm, the byte is 3", 0x00000010u, 0x00000001u, 3u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the first arm, the byte is 4", 0x00000010u, 0x00000001u, 4u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the first arm, the field is there", 0x00000010u, 0x00000001u, 2u, 1u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the first arm, the fourth mask is not clear", 0x00000008u, 0x00000001u, 2u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the first arm, the last mask is clear", 0x00000000u, 0x00000001u, 2u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the second arm, the byte is 3", 0x00000004u, 0x00000001u, 3u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the second arm, the byte is 4", 0x00000004u, 0x00000001u, 4u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the second arm, the byte is 5", 0x00000004u, 0x00000001u, 5u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the second arm, the byte is 2", 0x00000004u, 0x00000001u, 2u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the second arm, the field is there", 0x00000004u, 0x00000001u, 4u, 1u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the second arm, the fourth mask is not clear", 0x0000000cu, 0x00000001u, 3u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the byte is two hundred", 0x00000010u, 0x00000001u, 200u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "the byte is two hundred and fifty five", 0x00000010u, 0x00000001u, 255u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0u },
        { "a negative offset", 0x00000010u, 0x00000001u, 2u, 0u,
          (int32_t)-16, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u,
          0x00000008u, 0x00000010u, 0u },
        { "the result word is not empty", 0x00000010u, 0x00000001u, 2u, 0u,
          0x10, 0x14, 0x18, 0x00000001u, 0x00000002u, 0x00000004u, 0x00000008u,
          0x00000010u, 0x40u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("pair_verdict_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
