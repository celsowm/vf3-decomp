/* Differential replay of the native queue family (src/native/queue_ops.c,
 * 0x8C038570 reset / 0x8C038590 push / 0x8C0385C0 pop) against the readable
 * guest ports (src/fight/queue_ops.c).
 *
 * The three functions share one struct, two global arrays (one contiguous
 * space, 48 words apart) and the literal pool.  Both sides run on the same
 * flat RAM.  The leaves are call-free integer bodies with no FP and no stack
 * frame; all three tail-transfer to pr (untouched).
 *
 * The fixture lays out the pool, the struct (with garbage in the uncleaned
 * halves and distinct values in the four words), the arrays and the counter,
 * and runs each side from the same seed.  The pool/struct/data regions are
 * compared byte for byte, together with the contract registers, and the
 * expected result is verified against an independent model worked out from
 * the scenario. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "queue_ops.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_queue_reset_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_queue_push_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_queue_pop_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x1000000u     /* 16 MiB: covers pool, struct and arrays */

#define POOL_LO 0x0c038000u
#define POOL_HI 0x0c039000u
#define STRUCT_ADDR 0x0c16b880u
#define ARRAY1_ADDR 0x0c1a5720u
#define ARRAY2_ADDR 0x0c1a5900u     /* non-aliased: 64 words clear of array1 */
#define DATA_LO 0x0c1a5000u
#define DATA_HI 0x0c1a5a00u

#define P_STRUCT 0x0c0385f0u
#define P_ARRAY1 0x0c0385f4u
#define P_ARRAY2 0x0c0385f8u

#define FIELD_COUNT 6u
#define FIELD_A 44u
#define FIELD_A2 48u
#define FIELD_B 56u
#define FIELD_B2 60u

typedef enum { OP_RESET, OP_PUSH, OP_POP } op_t;

struct scenario {
    const char *name;
    op_t op;
    int16_t counter;   /* the queue's counter (halfword sign extended) */
    uint32_t a, a2, b, b2;   /* the struct's four words */
    uint32_t arr1[64];       /* the first array [0..48] */
    uint32_t arr2[64];       /* the second array [0..48] */
};

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }
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
static uint32_t r32(uint32_t addr)
{
    uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static int16_t r16(uint32_t addr)
{
    uint8_t *p = ab(addr);
    return (int16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t pr, uint32_t sr)
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = 0x0c47f000u;
    s->v[16] = pr;
    s->v[17] = sr;
    s->v[18] = 0x00024001u;      /* the corpus' own FPSCR */
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

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);
    w32(P_STRUCT, STRUCT_ADDR);
    w32(P_ARRAY1, ARRAY1_ADDR);
    w32(P_ARRAY2, ARRAY2_ADDR);

    /* the struct, with uncleaned halves left as garbage */
    for (uint32_t off = 0; off < 0x80; off += 4) w32(STRUCT_ADDR + off, 0xa5a5a5a5u);
    w16(STRUCT_ADDR + FIELD_COUNT, (uint16_t)sc->counter);
    w32(STRUCT_ADDR + FIELD_A, sc->a);
    w32(STRUCT_ADDR + FIELD_A2, sc->a2);
    w32(STRUCT_ADDR + FIELD_B, sc->b);
    w32(STRUCT_ADDR + FIELD_B2, sc->b2);

    /* the two arrays, as the one contiguous space the guest sees */
    for (unsigned i = 0; i < 64; ++i) {
        w32(ARRAY1_ADDR + 4u * i, sc->arr1[i]);
        w32(ARRAY2_ADDR + 4u * i, sc->arr2[i]);
    }
}

/* ---- independent model of each operation ---- */
static void model(struct scenario *out, const struct scenario *sc)
{
    memcpy(out, sc, sizeof *out);
    int32_t c = (int32_t)(int16_t)sc->counter;

    switch (sc->op) {
    case OP_RESET:
        out->counter = 0;
        out->a = sc->arr1[0]; out->a2 = sc->arr1[0];
        out->b = sc->arr2[0]; out->b2 = sc->arr2[0];
        break;
    case OP_PUSH:
        if (c >= 48) { out->a = sc->a; out->b = sc->b; /* untouched */ }
        else {
            out->counter = (int16_t)(c + 1);
            out->a = sc->a; out->a2 = sc->a2; out->b = sc->b; out->b2 = sc->b2;
            out->arr1[c + 1] = sc->a;   /* first array at the new value */
            out->arr2[c + 1] = sc->b;   /* second array at the new value */
        }
        break;
    case OP_POP:
        if (c <= 0) { out->a = sc->a; out->b = sc->b; /* untouched */ }
        else {
            out->counter = (int16_t)(c - 1);
            out->a = sc->arr1[c]; out->a2 = sc->a2;  /* pop writes 44 only */
            out->b = sc->arr2[c]; out->b2 = sc->b2;  /* pop writes 56 only */
            out->arr1[c] = sc->arr1[c]; out->arr2[c] = sc->arr2[c];
        }
        break;
    }
}

static int check_model(const struct scenario *sc, const struct scenario *want)
{
    int bad = 0;
    if ((int32_t)(int16_t)r16(STRUCT_ADDR + FIELD_COUNT) != (int32_t)want->counter) {
        fprintf(stderr, "  counter %d want %d\n", (int32_t)(int16_t)r16(STRUCT_ADDR + FIELD_COUNT), (int32_t)want->counter); bad++;
    }
    if (r32(STRUCT_ADDR + FIELD_A) != want->a) { fprintf(stderr, "  struct a %08x want %08x\n", r32(STRUCT_ADDR + FIELD_A), want->a); bad++; }
    if (r32(STRUCT_ADDR + FIELD_A2) != want->a2) { fprintf(stderr, "  struct a2 %08x want %08x\n", r32(STRUCT_ADDR + FIELD_A2), want->a2); bad++; }
    if (r32(STRUCT_ADDR + FIELD_B) != want->b) { fprintf(stderr, "  struct b %08x want %08x\n", r32(STRUCT_ADDR + FIELD_B), want->b); bad++; }
    if (r32(STRUCT_ADDR + FIELD_B2) != want->b2) { fprintf(stderr, "  struct b2 %08x want %08x\n", r32(STRUCT_ADDR + FIELD_B2), want->b2); bad++; }
    for (int i = 0; i < 64; ++i)
        if (r32(ARRAY1_ADDR + 4u * i) != want->arr1[i] ||
            r32(ARRAY2_ADDR + 4u * i) != want->arr2[i])
            { fprintf(stderr, "  array slot %d differs\n", i); break; }
    return bad;
}

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    const uint32_t pr = 0x0c038600u;
    const uint32_t sr = 0x60000001u;   /* T set; the push/pop clear or keep it */

    seed_all(sc);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin, pr, sr);
    vf3_family_override = vf3_readable_override;
    int ok_guest;
    switch (sc->op) {
    case OP_RESET: ok_guest = vf3_queue_reset_entry(&gs, &gmap); break;
    case OP_PUSH:  ok_guest = vf3_queue_push_entry(&gs, &gmap); break;
    default:       ok_guest = vf3_queue_pop_entry(&gs, &gmap); break;
    }
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }

    /* snapshot the compared regions */
    const size_t l0 = POOL_HI - POOL_LO, l1 = DATA_HI - DATA_LO;
    uint8_t *snap = (uint8_t *)malloc(l0 + l1 + 0x100);
    memcpy(snap, ab(POOL_LO), l0);
    memcpy(snap + l0, ab(DATA_LO), l1);

    const uint32_t g_r0 = gs.v[0], g_r4 = gs.v[4], g_r5 = gs.v[5], g_r6 = gs.v[6];
    const uint32_t g_sr = gs.v[17];

    /* ---- native side ---- */
    seed_all(sc);

    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = 0x76543210u + i;
    a.r[15] = 0x0c47f000u;
    a.pr = pr;
    a.sr = sr;
    a.fpscr = 0x00024001u;
    switch (sc->op) {
    case OP_RESET: vf3_native_queue_reset(&a); break;
    case OP_PUSH:  vf3_native_queue_push(&a); break;
    default:       vf3_native_queue_pop(&a); break;
    }

    int bad = 0;

    /* RAM regions: pool + data */
    {
        int nb = 0;
        for (uint32_t ad = POOL_LO; ad < POOL_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, snap + (ad - POOL_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) { if (nb < 10) fprintf(stderr, "  pool @%08x: got %08x want %08x\n", ad, n, g); nb++; }
        }
        for (uint32_t ad = DATA_LO; ad < DATA_HI; ad += 4) {
            uint32_t g, n;
            memcpy(&g, snap + l0 + (ad - DATA_LO), 4);
            n = vf3_aim_u32(&a, ad);
            if (g != n) { if (nb < 10) fprintf(stderr, "  data @%08x: got %08x want %08x\n", ad, n, g); nb++; }
        }
        printf("  ram: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* contract registers */
    {
        int nb = 0;
        if (a.r[0] != g_r0) { fprintf(stderr, "  r0: native %08x guest %08x\n", a.r[0], g_r0); nb++; }
        if (a.r[4] != g_r4) { fprintf(stderr, "  r4: native %08x guest %08x\n", a.r[4], g_r4); nb++; }
        if (a.r[5] != g_r5) { fprintf(stderr, "  r5: native %08x guest %08x\n", a.r[5], g_r5); nb++; }
        if (a.r[6] != g_r6) { fprintf(stderr, "  r6: native %08x guest %08x\n", a.r[6], g_r6); nb++; }
        if ((a.sr & 1u) != (g_sr & 1u)) { fprintf(stderr, "  sr T differs\n"); nb++; }
        if (a.pr != pr) { fprintf(stderr, "  pr changed\n"); nb++; }
        printf("  regs: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    /* independent model */
    {
        struct scenario want;
        model(&want, sc);
        int nb = check_model(sc, &want);
        printf("  model: %s\n", nb ? "DIFFERS" : "match");
        bad |= nb;
    }

    free(snap);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (uint8_t *)calloc(RAM_SIZE, 1);
    if (!ram) return 2;
    const char *err = load_image();
    if (err) {
        printf("queue_ops_native_replay: skipped (%s)\n", err);
        free(ram);
        return 0;
    }

    static const struct scenario scenarios[] = {
        /* reset: the counter zeroes and the struct takes the arrays' slot 0 */
        { .name = "reset/12", .op = OP_RESET, .counter = 12,
          .a = 0x11111111u, .a2 = 0x22222222u, .b = 0x33333333u, .b2 = 0x44444444u,
          .arr1 = { [0] = 0xaaaau | 0x55550000u, [3] = 7 },
          .arr2 = { [0] = 0xbbbbu | 0x66660000u } },
        /* push from empty: counter 0 -> 1, words go to slot 1 */
        { .name = "push/0", .op = OP_PUSH, .counter = 0,
          .a = 0x11111111u, .a2 = 0x22222222u, .b = 0x33333333u, .b2 = 0x44444444u,
          .arr1 = { [1] = 0xdeadbeefu }, .arr2 = { [1] = 0xcafef00du } },
        /* push mid-queue: counter 4 -> 5, slot 5 */
        { .name = "push/4", .op = OP_PUSH, .counter = 4,
          .a = 0x11111111u, .a2 = 0x22222222u, .b = 0x33333333u, .b2 = 0x44444444u,
          .arr1 = { [5] = 0x11112222u }, .arr2 = { [5] = 0x33334444u } },
        /* push full: counter 48 -> refused (-1), nothing moves */
        { .name = "push/48", .op = OP_PUSH, .counter = 48,
          .a = 0x11111111u, .a2 = 0x22222222u, .b = 0x33333333u, .b2 = 0x44444444u,
          .arr1 = { [1] = 0xaaaaaaaau }, .arr2 = { [1] = 0xbbbbbbbbu } },
        /* push at the limit edge from 47: writes slot 48 (the aliased second
         * array's slot 0) */
        { .name = "push/47", .op = OP_PUSH, .counter = 47,
          .a = 0x11111111u, .a2 = 0x22222222u, .b = 0x33333333u, .b2 = 0x44444444u,
          .arr1 = { [48] = 0x01020304u }, .arr2 = { [48] = 0x05060708u } },
        /* pop from a populated queue: counter 4 -> 3, slots 4 come back */
        { .name = "pop/4", .op = OP_POP, .counter = 4,
          .a = 0x11111111u, .a2 = 0x22222222u, .b = 0x33333333u, .b2 = 0x44444444u,
          .arr1 = { [4] = 0x99990000u }, .arr2 = { [4] = 0x77775555u } },
        /* pop to empty: counter 1 -> 0 */
        { .name = "pop/1", .op = OP_POP, .counter = 1,
          .a = 0x11111111u, .a2 = 0x22222222u, .b = 0x33333333u, .b2 = 0x44444444u,
          .arr1 = { [1] = 0x12345678u }, .arr2 = { [1] = 0xabcdef01u } },
        /* pop empty: counter 0 -> refused (-1), nothing moves */
        { .name = "pop/0", .op = OP_POP, .counter = 0,
          .a = 0x11111111u, .a2 = 0x22222222u, .b = 0x33333333u, .b2 = 0x44444444u,
          .arr1 = { [1] = 0xfffffff0u }, .arr2 = { [1] = 0x0fffffffu } },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("queue_ops_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
