/* state_resolve_replay.c - the readable fight-state resolver (SH-4 0x8C08E68C)
 * against the retained generated translation.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states, and it is still in the tree
 * (src/fight/fight_adapters_1.c).  The readable port has to leave the same
 * registers, the same RAM and the same return address as that translation.
 *
 * The port is run three times: once through the generated chain (the
 * reference), once called directly, and once through the readable override -
 * which is how the native tick reaches it.
 *
 * The literal pool lives in ROM.  The image is not in this checkout, so the
 * test supplies the pool as a window carrying the values the real image holds
 * (the two table addresses, the masks, the offsets into the records and the
 * helper's address).  That is a constant of the image, not captured state: the
 * readable port reads the pool at run time and the generated translation does
 * the same, and both see the same window.
 *
 * The helper the port calls (0x8C09553C) in turn calls two leaves through the
 * pool.  Those leaves are *not* what this test is about - they are generated
 * code the port never sees - so the test answers them with a stub: the first
 * one turns the argument it was given into a float, the second one does
 * nothing.  The stub is installed in all three arms, so the three arms see the
 * same helper, and the correction the helper hands back is a function of the
 * argument the *port* passes - which is what the test checks.
 *
 * The outcome is also checked against a model of the guest that is written
 * from the disassembly and does not consult the generated translation at all:
 * the record choice, the words the two records share with the output struct,
 * the three sources a vector can come from and the correction the helper adds.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"

#include <stdio.h>
#include <string.h>

int vf3_state_resolve_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY     0x0c08e68cu
#define RETURN_PC 0x0c0abcdeu

/* the helper's two leaves, as the image's pool names them */
#define CALLEE_A  0x0c03a6e0u
#define CALLEE_B  0x0c03a140u

/* ---- the windows ---- */
#define POOL_BASE    0x0c08e000u   /* the literal pool */
#define POOL_LEN     0x1000u
#define HPOOL_BASE   0x0c095000u   /* the helper's own pool */
#define HPOOL_LEN    0x1000u
#define TBL_BASE     0x0c29b000u   /* the two tables */
#define TBL_LEN      0x1000u
#define DATA_BASE    0x0c210000u   /* the two records and the output struct */
#define DATA_LEN     0x5000u
#define STACK_BASE   0x0c100000u
#define STACK_LEN    0x10000u

#define NWIN 6

#define OFF_POOL   0u
#define OFF_HPOOL  (OFF_POOL + POOL_LEN)
#define OFF_TBL    (OFF_HPOOL + HPOOL_LEN)
#define OFF_DATA   (OFF_TBL + TBL_LEN)
#define OFF_STACK  (OFF_DATA + DATA_LEN)
#define SHADOW_LEN (OFF_STACK + STACK_LEN)

/* ---- where things live ---- */
#define REC_A   DATA_BASE          /* the first table's entry at 16 */
#define REC_B   (DATA_BASE + 0x2000u) /* the first table's entry at 20 */
#define OUT     (DATA_BASE + 0x4000u) /* the output struct */
#define OUT_LEN 0xd0u
#define STACK_TOP 0x0c108000u

/* ---- the pool's entries, and the values the image holds ---- */
#define P_FLAG_128   (POOL_BASE + 0x756u)
#define P_FLAG_256   (POOL_BASE + 0x758u)
#define P_ROW_452    (POOL_BASE + 0x75au)
#define P_ROW_456    (POOL_BASE + 0x75cu)
#define P_OFF_6340   (POOL_BASE + 0x75eu)
#define P_OFF_6660   (POOL_BASE + 0x760u)
#define P_OFF_1072   (POOL_BASE + 0x762u)
#define P_TABLE      (POOL_BASE + 0x764u)
#define P_TABLE2     (POOL_BASE + 0x768u)
#define P_MASK_HI    (POOL_BASE + 0x76cu)
#define P_MASK_LO    (POOL_BASE + 0x770u)
#define P_OFF_496    (POOL_BASE + 0x848u)
#define P_OFF_6672_1 (POOL_BASE + 0x84au)
#define P_BIT_8192_1 (POOL_BASE + 0x84cu)
#define P_OFF_5268_1 (POOL_BASE + 0x84eu)
#define P_OFF_1072_2 (POOL_BASE + 0x850u)
#define P_F40_1      (POOL_BASE + 0x854u)
#define P_HELPER_1   (POOL_BASE + 0x858u)
#define P_MASK_LO_2  (POOL_BASE + 0x85cu)
#define P_OFF_496_2  (POOL_BASE + 0x8feu)
#define P_OFF_6672_2 (POOL_BASE + 0x900u)
#define P_BIT_8192_2 (POOL_BASE + 0x902u)
#define P_OFF_5268_2 (POOL_BASE + 0x904u)
#define P_OFF_196    (POOL_BASE + 0x906u)
#define P_F40_2      (POOL_BASE + 0x908u)
#define P_HELPER_2   (POOL_BASE + 0x90cu)

/* the helper's own pool */
#define HP_CALLEE_A  (HPOOL_BASE + 0x6f0u)
#define HP_CALLEE_B  (HPOOL_BASE + 0x6f4u)

/* the values the image holds */
#define V_TABLE      0x0c29bb84u
#define V_TABLE2     0x0c29bcc4u
#define V_MASK_HI    0x08000000u
#define V_MASK_LO    0x04000000u
#define V_HELPER     0x0c09553cu
#define V_F40        0x3eccccccu    /* the image's float at 0x0c08e854 */
#define V_ROW_452    452u
#define V_ROW_456    456u
#define V_OFF_496    496u
#define V_OFF_6340   6340u
#define V_OFF_6660   6660u
#define V_OFF_6672   6672u
#define V_OFF_5268   5268u
#define V_OFF_1072   1072u
#define V_BIT_8192   8192u

/* the records' fixed fields */
#define A_W6660 0x84800000u
#define A_H6672 0x0028u
#define A_H5268 0xc0f7u
#define A_H3E   9u
#define B_W6660 0x8c800000u
#define B_H6672 0x0040u
#define B_H5268 0x40f7u
#define B_H3E   9u

/* the three sources of each record: the record's own words at 0x10, the words
 * at 1072 and the words at 496 */
static const float A_SRC[3][3] = {
    { 1.0f, 2.0f, 3.0f },
    { 4.0f, 5.0f, 6.0f },
    { 7.0f, 8.0f, 9.0f },
};
static const float B_SRC[3][3] = {
    { 11.0f, 12.0f, 13.0f },
    { 14.0f, 15.0f, 16.0f },
    { 17.0f, 18.0f, 19.0f },
};

/* the guest's state at the entry */
#define FPSCR 0x00240001u

struct scenario {
    const char *name;
    uint32_t out_flags;     /* the output struct's word at 48 */
    uint32_t a_flags;       /* the first record's word at 0x48 */
    uint32_t a_count;       /* the first record's word at 0x4c */
    uint32_t a_6340;        /* the first record's word at 6340 */
    uint32_t b_flags;       /* the second record's word at 0x48 */
    uint32_t b_count;       /* the second record's word at 0x4c */
    uint32_t b_6340;        /* the second record's word at 6340 */
};

struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[NWIN];
    vf3_ram_map map;
    uint32_t base[NWIN];
    uint32_t len[NWIN];
};

static void w16(uint8_t *p, uint32_t off, uint16_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
}

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

static void wf32(uint8_t *p, uint32_t off, float f)
{
    uint32_t b;
    memcpy(&b, &f, 4);
    w32(p, off, b);
}

/* The output struct's gap: the guest writes a halfword at 0x5a and the next
 * word at 0x70, so nothing in between is ever written.  The fixture fills it,
 * so a store that is wider than the guest's shows up in the comparison. */
#define GAP_OFF 0x5cu
#define GAP_LEN 20u

static void fill_gap(uint8_t *p, uint32_t off)
{
    for (uint32_t i = 0; i < GAP_LEN; ++i)
        p[off + i] = (uint8_t)(0xa0u + i);
}

/* the record's image, as the guest sees it */
static void build_record(uint8_t *p, uint32_t off, uint32_t flags, uint32_t count,
                         uint32_t w6340, uint32_t w6660, uint32_t h6672,
                         uint32_t h5268, uint32_t h3e, const float src[3][3])
{
    w32(p + off, 0x48u, flags);
    w32(p + off, 0x4cu, count);
    w32(p + off, 6340u, w6340);
    w32(p + off, 6660u, w6660);
    w16(p + off, 6672u, (uint16_t)h6672);
    w16(p + off, 5268u, (uint16_t)h5268);
    w16(p + off, 0x3eu, (uint16_t)h3e);
    for (unsigned i = 0; i < 3; ++i) {
        wf32(p + off, 0x10u + 4u * i, src[0][i]);
        wf32(p + off, 1072u + 4u * i, src[1][i]);
        wf32(p + off, 496u + 4u * i, src[2][i]);
    }
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the literal pool, with the values the real image holds */
    w16(p + OFF_POOL, P_FLAG_128   - POOL_BASE, 128u);
    w16(p + OFF_POOL, P_FLAG_256   - POOL_BASE, 256u);
    w16(p + OFF_POOL, P_ROW_452    - POOL_BASE, (uint16_t)V_ROW_452);
    w16(p + OFF_POOL, P_ROW_456    - POOL_BASE, (uint16_t)V_ROW_456);
    w16(p + OFF_POOL, P_OFF_6340   - POOL_BASE, (uint16_t)V_OFF_6340);
    w16(p + OFF_POOL, P_OFF_6660   - POOL_BASE, (uint16_t)V_OFF_6660);
    w16(p + OFF_POOL, P_OFF_1072   - POOL_BASE, (uint16_t)V_OFF_1072);
    w32(p + OFF_POOL, P_TABLE      - POOL_BASE, V_TABLE);
    w32(p + OFF_POOL, P_TABLE2     - POOL_BASE, V_TABLE2);
    w32(p + OFF_POOL, P_MASK_HI    - POOL_BASE, V_MASK_HI);
    w32(p + OFF_POOL, P_MASK_LO    - POOL_BASE, V_MASK_LO);
    w16(p + OFF_POOL, P_OFF_496    - POOL_BASE, (uint16_t)V_OFF_496);
    w16(p + OFF_POOL, P_OFF_6672_1 - POOL_BASE, (uint16_t)V_OFF_6672);
    w16(p + OFF_POOL, P_BIT_8192_1 - POOL_BASE, (uint16_t)V_BIT_8192);
    w16(p + OFF_POOL, P_OFF_5268_1 - POOL_BASE, (uint16_t)V_OFF_5268);
    w16(p + OFF_POOL, P_OFF_1072_2 - POOL_BASE, (uint16_t)V_OFF_1072);
    w32(p + OFF_POOL, P_F40_1      - POOL_BASE, V_F40);
    w32(p + OFF_POOL, P_HELPER_1   - POOL_BASE, V_HELPER);
    w32(p + OFF_POOL, P_MASK_LO_2  - POOL_BASE, V_MASK_LO);
    w16(p + OFF_POOL, P_OFF_496_2  - POOL_BASE, (uint16_t)V_OFF_496);
    w16(p + OFF_POOL, P_OFF_6672_2 - POOL_BASE, (uint16_t)V_OFF_6672);
    w16(p + OFF_POOL, P_BIT_8192_2 - POOL_BASE, (uint16_t)V_BIT_8192);
    w16(p + OFF_POOL, P_OFF_5268_2 - POOL_BASE, (uint16_t)V_OFF_5268);
    w16(p + OFF_POOL, P_OFF_196    - POOL_BASE, 196u);
    w32(p + OFF_POOL, P_F40_2      - POOL_BASE, V_F40);
    w32(p + OFF_POOL, P_HELPER_2   - POOL_BASE, V_HELPER);

    /* the helper's own pool: the two leaves it calls */
    w32(p + OFF_HPOOL, HP_CALLEE_A - HPOOL_BASE, CALLEE_A);
    w32(p + OFF_HPOOL, HP_CALLEE_B - HPOOL_BASE, CALLEE_B);

    /* the two tables */
    w32(p + OFF_TBL, V_TABLE + 16u - TBL_BASE, REC_A);
    w32(p + OFF_TBL, V_TABLE + 20u - TBL_BASE, REC_B);
    w32(p + OFF_TBL, V_TABLE2 + V_ROW_452 - TBL_BASE, REC_A);
    w32(p + OFF_TBL, V_TABLE2 + V_ROW_456 - TBL_BASE, REC_B);

    /* the two records */
    build_record(p + OFF_DATA, REC_A - DATA_BASE, sc->a_flags, sc->a_count,
                 sc->a_6340, A_W6660, A_H6672, A_H5268, A_H3E, A_SRC);
    build_record(p + OFF_DATA, REC_B - DATA_BASE, sc->b_flags, sc->b_count,
                 sc->b_6340, B_W6660, B_H6672, B_H5268, B_H3E, B_SRC);

    /* the output struct's flag word */
    w32(p + OFF_DATA, OUT - DATA_BASE + 48u, sc->out_flags);
    fill_gap(p + OFF_DATA, OUT - DATA_BASE + GAP_OFF);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = OUT;                 /* r4 - the output struct */
    s->v[15] = STACK_TOP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;              /* sr, with the T bit set */
    s->v[18] = FPSCR;
    s->v[21] = 0x40400000u;         /* fr0 - 3.0f */
    s->budget = 1000000u;

    r->base[0] = POOL_BASE;   r->len[0] = POOL_LEN;
    r->base[1] = HPOOL_BASE;  r->len[1] = HPOOL_LEN;
    r->base[2] = TBL_BASE;    r->len[2] = TBL_LEN;
    r->base[3] = DATA_BASE;   r->len[3] = DATA_LEN;
    r->base[4] = STACK_BASE;  r->len[4] = STACK_LEN;
    for (unsigned i = 0; i < NWIN; ++i) {
        r->wins[i].base = r->base[i];
        r->wins[i].len = r->len[i];
        r->wins[i].data = p + (i == 0 ? OFF_POOL : i == 1 ? OFF_HPOOL
                             : i == 2 ? OFF_TBL : i == 3 ? OFF_DATA : OFF_STACK);
    }
    r->map.wins = r->wins;
    r->map.n = NWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

/* ---- the stub the helper's leaves are answered with ---- */
static int stub_leaf(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                     int *handled)
{
    (void)ram;
    if (entry == CALLEE_A) {
        /* the first leaf answers with the argument it was given, as a float */
        *handled = 1;
        s->v[21] = vf3_fpu_float(s->v[4], s->v[18]);
        s->pc = s->v[16];
        return 1;
    }
    if (entry == CALLEE_B) {
        *handled = 1;
        s->pc = s->v[16];
        return 1;
    }
    *handled = 0;
    return 0;
}

static int hook_stub(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                     int *handled)
{
    return stub_leaf(entry, s, ram, handled);
}

static int hook_readable(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram,
                         int *handled)
{
    if (stub_leaf(entry, s, ram, handled)) return 1;
    if (*handled) return 1;
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
                fprintf(stderr, "  %s: ram %u %02x != %02x\n", what, i,
                        a->shadow[i], b->shadow[i]);
                break;
            }
        return 0;
    }
    return 1;
}

/* ---- the model of the guest ---- */
static uint32_t rec_flags_of(unsigned i, const struct scenario *sc)
{
    return i ? sc->b_flags : sc->a_flags;
}

static uint32_t rec_count_of(unsigned i, const struct scenario *sc)
{
    return i ? sc->b_count : sc->a_count;
}

static uint32_t rec_6340_of(unsigned i, const struct scenario *sc)
{
    return i ? sc->b_6340 : sc->a_6340;
}

static uint32_t rec_6660_of(unsigned i)
{
    return i ? B_W6660 : A_W6660;
}

static uint32_t rec_6672_of(unsigned i)
{
    return i ? B_H6672 : A_H6672;
}

static uint32_t rec_5268_of(unsigned i)
{
    return i ? B_H5268 : A_H5268;
}

static uint32_t rec_3e_of(unsigned i)
{
    return i ? B_H3E : A_H3E;
}

static const float (*rec_src_of(unsigned i))[3]
{
    return i ? B_SRC : A_SRC;
}

/* The three sources, as the guest numbers them: the record's own words at
 * 0x10, the words at 1072 and the words at 496. */
static unsigned source_of(uint32_t flag_bit0, uint32_t both, uint32_t rec_flags,
                          uint32_t mask_lo)
{
    if (flag_bit0 == 0u && (both & 4u) == 0u) return 2u;   /* the third source */
    if (rec_flags & V_MASK_HI) return 2u;                   /* the third source */
    if (rec_flags & mask_lo) return 1u;                     /* the second source */
    return 0u;                                             /* the first source */
}

/* Does the vector get a correction?  The guest skips the helper when the
 * record's count does not carry the bit 8192, and it skips it when the two
 * counts do not differ in that bit and their shared word carries the high
 * mask. */
static int correction_of(uint32_t count, uint32_t r7, uint32_t r8)
{
    if ((count & V_BIT_8192) == 0u) return 0;
    if (r8 != 0u) return 1;
    return (r7 & V_MASK_HI) == 0u;
}

/* What the helper hands back.
 *
 * The helper is given the record's word at 5268 - a halfword, negated - and it
 * turns it into a float.  It then multiplies that float by the frame's fourth
 * word (the caller spills fr12 into it, so it is zero) and by the frame's
 * first word (the 0.4, negated when the count carries the high mask):
 *
 *   frame[0] = 0 * T1 + T1 * C          (the helper writes it back)
 *   frame[4] = T1 * 0 - T1 * C
 *
 * and the caller adds the frame's first word to the vector's first component
 * and the frame's fourth word to its third.
 */
struct correction {
    uint32_t first;     /* the frame's word at 0 */
    uint32_t fourth;    /* the frame's word at 4 */
};

static struct correction helper_result(uint32_t rec_5268, uint32_t count)
{
    const int32_t arg = (int32_t)(int16_t)(uint16_t)
        (0u - (uint32_t)(int32_t)(int16_t)(uint16_t)rec_5268);
    const uint32_t t1 = vf3_fpu_float((uint32_t)arg, FPSCR);
    const uint32_t c = (count & V_MASK_HI) ? (V_F40 ^ 0x80000000u) : V_F40;
    const uint32_t zero = 0u;
    const uint32_t tc = vf3_fpu_binary(t1, c, FPSCR, '*');
    const uint32_t td = vf3_fpu_binary(t1, zero, FPSCR, '*');
    struct correction out;
    out.first = vf3_fpu_mac(zero, t1, tc, FPSCR);
    out.fourth = vf3_fpu_binary(td, tc, FPSCR, '-');
    return out;
}

/* What the guest has to leave in the output struct.  Worked out from the
 * disassembly alone - the generated translation is not consulted. */
static void expect(const struct scenario *sc, uint8_t *out)
{
    unsigned rec[2];
    uint32_t both, r7, r8;
    uint32_t v1[3], v1c[3], v2[3], v2c[3];
    uint32_t src1, src2;

    memset(out, 0, OUT_LEN);

    /* the gap the guest never writes, filled the same way the fixture fills it */
    fill_gap(out, GAP_OFF);

    /* the output struct's flag word: the guest only reads it */
    w32(out, 48u, sc->out_flags);

    /* the record choice */
    rec[0] = 0u; rec[1] = 1u;
    if (sc->out_flags & 0x40u) {
        /* the row at 452 holds the first record, which is not the table's
         * entry at 20 - so both records become the entry at 16 */
        rec[0] = 0u; rec[1] = 0u;
    } else if ((sc->out_flags & 0x80u) || (sc->out_flags & 0x100u)) {
        /* the row at 456 holds the table's entry at 20 - so both records
         * become the entry at 20 */
        rec[0] = 1u; rec[1] = 1u;
    }

    /* the words the two records share with the output struct */
    w32(out, 0x34u, rec_6340_of(rec[0], sc));
    w32(out, 0x38u, rec_6340_of(rec[1], sc));
    w32(out, 0x3cu, rec_flags_of(rec[0], sc));
    w32(out, 0x40u, rec_count_of(rec[0], sc));
    w32(out, 0x44u, rec_6660_of(rec[0]));
    w32(out, 0x48u, rec_flags_of(rec[1], sc));
    w32(out, 0x4cu, rec_count_of(rec[1], sc));
    w32(out, 0x50u, rec_6660_of(rec[1]));
    w16(out, 0x54u, (uint16_t)rec_6672_of(rec[0]));
    w16(out, 0x56u, (uint16_t)rec_3e_of(rec[0]));
    w16(out, 0x58u, (uint16_t)rec_6672_of(rec[1]));
    w16(out, 0x5au, (uint16_t)rec_3e_of(rec[1]));

    /* the two counts: the "both" word and the difference */
    both = rec_6340_of(rec[1], sc) & rec_6340_of(rec[0], sc);
    r7 = rec_count_of(rec[0], sc) ^ rec_count_of(rec[1], sc);
    r8 = V_BIT_8192 & r7;

    /* the first vector */
    src1 = source_of(sc->out_flags & 1u, both, rec_flags_of(rec[0], sc), V_MASK_LO);
    for (unsigned i = 0; i < 3; ++i) {
        uint32_t bits;
        float f = rec_src_of(rec[0])[src1][i];
        memcpy(&bits, &f, 4);
        if (i == 2u) bits ^= 0x80000000u;        /* the guest negates the third */
        v1[i] = bits;
    }
    /* the second vector */
    src2 = source_of(sc->out_flags & 1u, both, rec_flags_of(rec[1], sc), V_MASK_LO);
    for (unsigned i = 0; i < 3; ++i) {
        uint32_t bits;
        float f = rec_src_of(rec[1])[src2][i];
        memcpy(&bits, &f, 4);
        if (i == 2u) bits ^= 0x80000000u;
        v2[i] = bits;
    }

    /* the corrections */
    memcpy(v1c, v1, sizeof v1);
    memcpy(v2c, v2, sizeof v2);
    if (correction_of(rec_count_of(rec[0], sc), r7, r8)) {
        const struct correction h = helper_result(rec_5268_of(rec[0]),
                                                  rec_count_of(rec[0], sc));
        v1c[0] = vf3_fpu_binary(v1[0], h.first, FPSCR, '+');
        v1c[1] = vf3_fpu_binary(v1[1], 0u, FPSCR, '+');
        v1c[2] = vf3_fpu_binary(v1[2], h.fourth, FPSCR, '+');
    }
    if (correction_of(rec_count_of(rec[1], sc), r7, r8)) {
        const struct correction h = helper_result(rec_5268_of(rec[1]),
                                                  rec_count_of(rec[1], sc));
        v2c[0] = vf3_fpu_binary(v2[0], h.first, FPSCR, '+');
        v2c[1] = vf3_fpu_binary(v2[1], 0u, FPSCR, '+');
        v2c[2] = vf3_fpu_binary(v2[2], h.fourth, FPSCR, '+');
    }

    /* the vectors the guest leaves behind */
    w32(out, 0x70u, v1[0]);  w32(out, 0x74u, v1[1]);  w32(out, 0x78u, v1[2]);
    w32(out, 0x7cu, v1c[0]); w32(out, 0x80u, v1c[1]); w32(out, 0x84u, v1c[2]);
    w32(out, 0xb8u, v2[0]);  w32(out, 0xbcu, v2[1]);  w32(out, 0xc0u, v2[2]);
    w32(out, 0xc4u, v2c[0]); w32(out, 0xc8u, v2c[1]); w32(out, 0xccu, v2c[2]);
}

static uint32_t shadow_u32(const struct run *r, uint32_t addr)
{
    for (unsigned i = 0; i < NWIN; ++i)
        if (addr >= r->base[i] && addr + 4 <= r->base[i] + r->len[i]) {
            const uint8_t *p = r->wins[i].data + (addr - r->base[i]);
            return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
                   ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
        }
    fprintf(stderr, "  the shadow does not hold %08x\n", addr);
    return 0xdeadbeefu;
}

static int check_fixture(const struct scenario *sc, const struct run *ref)
{
    uint8_t want[OUT_LEN];
    expect(sc, want);

    for (unsigned i = 0; i < OUT_LEN; ++i) {
        const uint8_t got = ref->wins[3].data[(OUT - DATA_BASE) + i];
        if (got != want[i]) {
            fprintf(stderr, "state resolve: %s: the output struct's byte %u is "
                    "%02x, expected %02x\n", sc->name, i, got, want[i]);
            return 0;
        }
    }
    /* the saved registers are back and the stack is where it was */
    if (ref->state.v[11] != 0x76543210u + 11u ||
        ref->state.v[12] != 0x76543210u + 12u ||
        ref->state.v[13] != 0x76543210u + 13u ||
        ref->state.v[14] != 0x76543210u + 14u) {
        fprintf(stderr, "state resolve: %s: the saved registers are %08x/%08x/%08x/%08x\n",
                sc->name, ref->state.v[11], ref->state.v[12],
                ref->state.v[13], ref->state.v[14]);
        return 0;
    }
    if (ref->state.v[15] != STACK_TOP) {
        fprintf(stderr, "state resolve: %s: the stack is at %08x\n",
                sc->name, ref->state.v[15]);
        return 0;
    }
    if (ref->state.pc != RETURN_PC) {
        fprintf(stderr, "state resolve: %s: the return address is %08x\n",
                sc->name, ref->state.pc);
        return 0;
    }
    /* and the record the guest picked is the one the model picked */
    if (shadow_u32(ref, V_TABLE + 16u) != REC_A ||
        shadow_u32(ref, V_TABLE + 20u) != REC_B) {
        fprintf(stderr, "state resolve: %s: the tables are wrong\n", sc->name);
        return 0;
    }
    return 1;
}

static unsigned cases;

static int compare(const struct scenario *sc)
{
    struct run ref, port, hook;
    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    vf3_family_override = hook_stub;
    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_state_resolve_entry(&port.state, &port.map);
    int handled = 0;
    vf3_family_override = hook_readable;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map, &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "state resolve: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "state resolve: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }
    if (!check_fixture(sc, &ref)) {
        fprintf(stderr, "state resolve: %s does not match the fixture\n", sc->name);
        return 0;
    }

    ++cases;
    return 1;
}

/* The common starting point: the two records agree on everything but their
 * counts, and the output struct's flag word is clear.  A scenario overrides
 * only the fields it is about - designated initializers, so a field that is
 * left out is zero and cannot be forgotten. */
#define BASE \
    .a_6340 = 0x00010004u, .b_6340 = 0x00020008u

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_state_resolve_entry) {
        fprintf(stderr, "state resolve: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        /* the record choice: the output struct's flag word */
        { .name = "no flag, the two records", BASE },
        { .name = "the flag 0x40 picks the row at 452", BASE, .out_flags = 0x40u },
        { .name = "the flag 0x80 picks the row at 456", BASE, .out_flags = 0x80u },
        { .name = "the flag 0x100 picks the row at 456", BASE, .out_flags = 0x100u },
        { .name = "the flag 0x40 wins over the flag 0x80", BASE,
          .out_flags = 0x40u | 0x80u },
        /* the flag bit 0x04 is not one of the three the guest tests, and it is
         * the only bit that tells the mask 0x100 apart from the row 452 - the
         * two live next to each other in the pool */
        { .name = "the flag bit 0x04 picks no row", BASE, .out_flags = 0x04u },
        /* the source of a vector */
        { .name = "the flag bit 0 is set", BASE, .out_flags = 1u },
        { .name = "the both word carries the bit 2", BASE,
          .a_6340 = 0x00010006u, .b_6340 = 0x00020006u },
        { .name = "the first record carries the high mask", BASE,
          .a_flags = V_MASK_HI, .a_6340 = 0x00010006u, .b_6340 = 0x00020006u },
        { .name = "the first record carries the low mask", BASE,
          .a_flags = V_MASK_LO, .a_6340 = 0x00010006u, .b_6340 = 0x00020006u },
        { .name = "the second record carries the low mask", BASE,
          .b_flags = V_MASK_LO, .a_6340 = 0x00010006u, .b_6340 = 0x00020006u },
        { .name = "both records carry the low mask", BASE,
          .a_flags = V_MASK_LO, .b_flags = V_MASK_LO,
          .a_6340 = 0x00010006u, .b_6340 = 0x00020006u },
        { .name = "the flag bit 0 beats the both word", BASE, .out_flags = 1u,
          .a_6340 = 0x00010006u, .b_6340 = 0x00020006u },
        /* the correction */
        { .name = "the first record asks for a correction", BASE,
          .a_count = V_BIT_8192 },
        { .name = "the correction's 0.4 is negated", BASE,
          .a_count = V_BIT_8192 | V_MASK_HI },
        { .name = "the second record asks for a correction", BASE,
          .b_count = V_BIT_8192 },
        { .name = "both records ask for a correction", BASE,
          .a_count = V_BIT_8192, .b_count = V_BIT_8192 },
        { .name = "the counts differ in the high mask, so no correction", BASE,
          .a_count = V_BIT_8192, .b_count = V_BIT_8192 | V_MASK_HI },
        { .name = "the second record's 0.4 is negated", BASE,
          .b_count = V_BIT_8192 | V_MASK_HI },
        { .name = "the correction comes with the row at 456", BASE,
          .out_flags = 0x80u, .b_count = V_BIT_8192 },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("state_resolve: %u differential cases - PASS\n", cases);
    return 0;
}
