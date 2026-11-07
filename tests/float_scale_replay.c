/* float_scale_replay.c - SH-4 0x8C039C50 / 0x8C039C70: the unsigned-32-to-float
 * scale, against the retained generated translation.
 *
 * Each entry reads one 32-bit value through a literal-pool pointer, converts
 * it to a float, folds the sign bit back in with the 2^32 addition when it is
 * set, scales by 1.28 read from the pool, and returns the truncated integer.
 * The two entries differ only in which pool pointer names the value, so they
 * share the scenarios; the second entry's test runs the same fixture with the
 * other pointer.
 *
 * Three arms, as in the other readable-port tests:
 *
 *   1. the generated chain - the reference;
 *   2. the readable port, called directly;
 *   3. the readable port, reached through the readable override (serving only
 *      the entry under test).
 *
 * All three compare the whole register file (the FP registers, FPUL and SR
 * with its T bit included), the return PC, the failed PC, the out-of-window
 * counter and every RAM byte.
 *
 * On top of the differential, every case is checked against a model computed
 * straight from the fixture's value through the SH-4 FPU helpers: the answer
 * in r0 and FPUL, the T bit, and the two FR registers.  The model does not
 * consult the translation.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_float_scale_a_entry(vf3_matrix_state *s, const vf3_ram_map *ram);
int vf3_float_scale_b_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY_A 0x0c039c50u
#define ENTRY_B 0x0c039c70u
#define RETURN_PC 0x0c0abcdeu

/* ---- the windows ---- */
#define POOL_BASE    0x0c039000u
#define POOL_LEN     0x1000u
#define DATA_BASE    0x0c300000u
#define DATA_LEN     0x1000u
#define NWIN 2

#define OFF_POOL 0u
#define OFF_DATA POOL_LEN
#define SHADOW_LEN (OFF_DATA + DATA_LEN)

#define P_P1_A  (POOL_BASE + 0xd4cu)  /* the first value's pointer */
#define P_PLUS  (POOL_BASE + 0xd50u)  /* 4294967296.0f */
#define P_SCALE (POOL_BASE + 0xd54u)  /* 1.28f */
#define P_P1_B  (POOL_BASE + 0xd58u)  /* the second value's pointer */

#define VAL_A_OFF 0x100u   /* the first value's slot, in the data window */
#define VAL_B_OFF 0x104u   /* the second value's slot, in the data window */

#define FPSCR 0x00040001u

struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[NWIN];
    vf3_ram_map map;
    uint32_t base[NWIN];
    uint32_t len[NWIN];
};

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

static uint32_t rd32(const struct run *r, uint32_t off)
{
    return (uint32_t)r->shadow[off] | ((uint32_t)r->shadow[off + 1] << 8) |
           ((uint32_t)r->shadow[off + 2] << 16) |
           ((uint32_t)r->shadow[off + 3] << 24);
}

static void setup(struct run *r, uint32_t val_a, uint32_t val_b)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the literal pool, with the image's real slots */
    w32(p + OFF_POOL, P_P1_A  - POOL_BASE, DATA_BASE + VAL_A_OFF);
    w32(p + OFF_POOL, P_PLUS  - POOL_BASE, 0x4f800000u);   /* 4294967296.0f */
    w32(p + OFF_POOL, P_SCALE - POOL_BASE, 0x3fa3d70au);   /* 1.28f */
    w32(p + OFF_POOL, P_P1_B  - POOL_BASE, DATA_BASE + VAL_B_OFF);

    /* the two values */
    w32(p + OFF_DATA, VAL_A_OFF, val_a);
    w32(p + OFF_DATA, VAL_B_OFF, val_b);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[15] = 0x0c108000u;      /* a caller frame; nothing is pushed */
    s->v[16] = RETURN_PC;
    s->v[17] = 0x60000000u;      /* sr, T clear */
    s->v[18] = FPSCR;
    s->budget = 1000000u;

    r->base[0] = POOL_BASE; r->len[0] = POOL_LEN;
    r->base[1] = DATA_BASE; r->len[1] = DATA_LEN;
    for (unsigned i = 0; i < NWIN; ++i) {
        r->wins[i].base = r->base[i];
        r->wins[i].len = r->len[i];
        r->wins[i].data = p + (i == 0 ? OFF_POOL : OFF_DATA);
    }
    r->map.wins = r->wins;
    r->map.n = NWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

/* ---- the arms ---- */

static uint32_t served_entry;

static int hook_only(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                     int *handled)
{
    if ((entry & 0x1fffffffu) != served_entry) { *handled = 0; return 0; }
    return vf3_readable_override(entry, s, ram, handled);
}

static int same(const struct run *a, const struct run *b, const char *what)
{
    if (memcmp(a->state.v, b->state.v, sizeof a->state.v)) {
        unsigned shown = 0;
        for (unsigned i = 0; i < 54 && shown < 8; ++i)
            if (a->state.v[i] != b->state.v[i]) {
                fprintf(stderr, "  %s: v%u %08x != %08x\n", what, i,
                        a->state.v[i], b->state.v[i]);
                ++shown;
            }
        return 0;
    }
    if (a->state.pc != b->state.pc || a->state.failed_pc != b->state.failed_pc) {
        fprintf(stderr, "  %s: pc %08x/%08x failed %08x/%08x\n", what,
                a->state.pc, b->state.pc, a->state.failed_pc, b->state.failed_pc);
        return 0;
    }
    if (a->map.oob != b->map.oob) {
        fprintf(stderr, "  %s: oob %u/%u\n", what, a->map.oob, b->map.oob);
        return 0;
    }
    if (memcmp(a->shadow, b->shadow, SHADOW_LEN)) {
        for (unsigned i = 0; i < SHADOW_LEN; ++i)
            if (a->shadow[i] != b->shadow[i]) {
                fprintf(stderr, "  %s: ram %u (addr %08x) %02x != %02x\n", what, i,
                        i < OFF_DATA ? POOL_BASE + i : DATA_BASE + (i - OFF_DATA),
                        a->shadow[i], b->shadow[i]);
                break;
            }
        return 0;
    }
    return 1;
}

static unsigned cases;

static int compare_one(uint32_t entry, uint32_t val_off, uint32_t val,
                       const char *name)
{
    struct run ref, port, hook;
    setup(&ref, val, val);
    setup(&port, val, val);
    setup(&hook, val, val);

    vf3_matrix_call_alias = 0u;
    vf3_matrix_call_alias_pc = 0xffffffffu;
    vf3_family_override = NULL;
    const int ok_ref = vf3_matrix_family(entry, &ref.state, &ref.map);
    const int ok_port = (entry == ENTRY_A)
        ? vf3_float_scale_a_entry(&port.state, &port.map)
        : vf3_float_scale_b_entry(&port.state, &port.map);
    served_entry = entry;
    vf3_family_override = hook_only;
    int handled = 0;
    const int ok_hook = vf3_readable_override(entry, &hook.state, &hook.map, &handled);
    vf3_family_override = NULL;

    if (!handled || ok_ref != ok_port || ok_ref != ok_hook ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "%s: %s differs (ok %d/%d/%d handled %d)\n",
                entry == ENTRY_A ? "float_scale" : "float_scale_b",
                name, ok_ref, ok_port, ok_hook, handled);
        return 0;
    }

    /* the outcome against the fixture itself, without the translation */
    {
        const int32_t v = (int32_t)rd32(&ref,
            entry == ENTRY_A ? (OFF_DATA + VAL_A_OFF) : (OFF_DATA + VAL_B_OFF));
        float f = vf3_bits_f32(vf3_fpu_float((uint32_t)v, FPSCR));
        if (v < 0) {
            const uint32_t plus = rd32(&ref, OFF_POOL + (P_PLUS - POOL_BASE));
            f = vf3_bits_f32(vf3_fpu_binary(vf3_f32_bits(f), plus, FPSCR, '+'));
        }
        const uint32_t scale = rd32(&ref, OFF_POOL + (P_SCALE - POOL_BASE));
        f = vf3_bits_f32(vf3_fpu_binary(vf3_f32_bits(f), scale, FPSCR, '*'));
        const uint32_t want = (uint32_t)vf3_fpu_ftrc(vf3_f32_bits(f));

        if (ref.state.v[0] != want || ref.state.v[53] != want) {
            fprintf(stderr, "%s: %s: r0/fpul %08x/%08x, expected %08x\n",
                    entry == ENTRY_A ? "float_scale" : "float_scale_b",
                    name, ref.state.v[0], ref.state.v[53], want);
            return 0;
        }
        if ((ref.state.v[17] & 1u) != ((uint32_t)(v >= 0) & 1u)) {
            fprintf(stderr, "%s: %s: the T bit is %u, expected %u\n",
                    entry == ENTRY_A ? "float_scale" : "float_scale_b",
                    name, ref.state.v[17] & 1u, (uint32_t)(v >= 0) & 1u);
            return 0;
        }
        if (ref.state.v[24] != vf3_f32_bits(f) ||   /* fr3 = v[21+3] */
            ref.state.v[23] != scale) {             /* fr2 = v[21+2] */
            fprintf(stderr, "%s: %s: fr3/fr2 %08x/%08x, expected fr3 %08x fr2 %08x\n",
                    entry == ENTRY_A ? "float_scale" : "float_scale_b", name,
                    ref.state.v[24], ref.state.v[23], vf3_f32_bits(f), scale);
            return 0;
        }
    }

    ++cases;
    return 1;
}

int main(void)
{
    const vf3_readable_entry *a = vf3_readable_find(ENTRY_A);
    const vf3_readable_entry *b = vf3_readable_find(ENTRY_B);
    if (!a || a->fn != vf3_float_scale_a_entry ||
        !b || b->fn != vf3_float_scale_b_entry) {
        fprintf(stderr, "float_scale: the ports are not registered\n");
        return 1;
    }

    /* values that cover the two paths of the sign-bit fold and the truncation */
    static const struct { const char *name; uint32_t val; } vals[] = {
        { "zero",               0x00000000u },
        { "a small positive",   0x00000005u },
        { "a small negative",   0xfffffffbU },
        { "one",                0x00000001u },
        { "a mid positive",     0x00000f00u },
        { "near int32 max",     0x7fffffffu },
        { "int32 min",          0x80000000u },
        { "near int32 min",     0x80000001u },
        { "a large negative",   0xffff0000u },
        { "one past the sign",  0x80010000u },
    };
    for (unsigned i = 0; i < sizeof vals / sizeof vals[0]; ++i) {
        if (!compare_one(ENTRY_A, VAL_A_OFF, vals[i].val, vals[i].name)) return 1;
        if (!compare_one(ENTRY_B, VAL_B_OFF, vals[i].val, vals[i].name)) return 1;
    }

    printf("float_scale: %u differential cases - PASS\n", cases);
    return 0;
}
