/* state_ladder_replay.c - the readable fight-state ladder (SH-4 0x8C08B89C)
 * against the retained generated translation.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states, and it is still in the tree
 * (src/fight/vf3_fifth_leaf_unowned_adapter.c).  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run three times: once through the generated chain (the
 * reference), once called directly, and once through the readable override -
 * which is how the native tick reaches it.
 *
 * There is no oracle arm *in this test*: the ladder was never captured on its
 * own.  The oracle leg is closed elsewhere - through the caller.  The entry
 * 0x8C08B7EE, which calls the ladder, has a ten-window capture
 * (extract/analysis/goldens_b7/f_0c08b7ee.nowin3.cases) whose windows hold
 * the task struct, and src/fight/cntup.c now calls this port instead of
 * modelling the ladder a second time, so tests/cntup_replay.c replays the
 * *readable* ladder against the oracle.  What this test does is check the
 * outcome against a model of the guest that is written from the disassembly
 * and does not consult the generated translation at all - the flag word, the
 * task's counters and the frame the guest builds.
 *
 * The literal pool lives in ROM.  The image is not in this checkout, so the
 * test supplies the pool as a window carrying the values the real image holds
 * (0x1bce, 0x1b98, the six masks and the four struct offsets).  That is a
 * constant of the image, not captured state: the readable port reads the pool
 * at run time and the generated translation does the same, and both see the
 * same window.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <string.h>

int vf3_state_ladder_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY     0x0c08b89cu
#define RETURN_PC 0x0c0abcdeu

/* ---- the windows ---- */
#define POOL_BASE    0x0c08b9b0u
#define POOL_LEN     0x170u
#define TASK_BASE    0x0c300000u
#define TASK_LEN     0x100u
#define STATE_BASE   0x0c310000u
#define STATE_LEN    0x1c00u
#define FIGHTER_BASE 0x0c320000u
#define FIGHTER_LEN  0x1c00u
#define FRAME_BASE   0x0c400000u
#define FRAME_LEN    0x100u
#define STACK_TOP    0x0c108000u
#define STACK_BASE   (STACK_TOP - 0x40u)
#define STACK_LEN    0x60u

#define NWIN 6

#define OFF_POOL    0u
#define OFF_TASK    (OFF_POOL + POOL_LEN)
#define OFF_STATE   (OFF_TASK + TASK_LEN)
#define OFF_FIGHTER (OFF_STATE + STATE_LEN)
#define OFF_FRAME   (OFF_FIGHTER + FIGHTER_LEN)
#define OFF_STACK   (OFF_FRAME + FRAME_LEN)
#define SHADOW_LEN  (OFF_STACK + STACK_LEN)

/* ---- the pool's entries, and the values the image holds ---- */
#define P_LADDER   (POOL_BASE + 0x08u)   /* 0x0c08b9b8 - the ladder counter */
#define P_TRIGGER  (POOL_BASE + 0x0au)   /* 0x0c08b9ba - the fighter's trigger */
#define P_LOW      (POOL_BASE + 0x0cu)   /* 0x0c08b9bc */
#define P_MID      (POOL_BASE + 0x0eu)   /* 0x0c08b9be */
#define P_TOP      (POOL_BASE + 0x10u)   /* 0x0c08b9c0 */
#define P_FIGHTER  (POOL_BASE + 0x14u)   /* 0x0c08b9c4 */
#define P_STATE    (POOL_BASE + 0x18u)   /* 0x0c08b9c8 */
#define P_HIT      (POOL_BASE + 0x1cu)   /* 0x0c08b9cc */
#define P_BLOCK    (POOL_BASE + 0x20u)   /* 0x0c08b9d0 */
#define P_BURST    (POOL_BASE + 0x9cu)   /* 0x0c08ba4c */
#define P_LONG     (POOL_BASE + 0x9eu)   /* 0x0c08ba4e */
#define P_BURST2   (POOL_BASE + 0x158u)  /* 0x0c08bb08 */
#define P_TRIGGER2 (POOL_BASE + 0x15au)  /* 0x0c08bb0a */
#define P_LONG2    (POOL_BASE + 0x15cu)  /* 0x0c08bb0c */
#define P_GUARD    (POOL_BASE + 0x160u)  /* 0x0c08bb10 */

#define V_LADDER    0x1bceu   /* the ladder counter's offset in the state struct */
#define V_TRIGGER   0x1b98u   /* the trigger's offset in the fighter struct */
#define V_LOW       0x1000u
#define V_MID       0x4000u
#define V_TOP       0x80000000u
#define V_FIGHTER   0x00100000u
#define V_STATE     0x0003d000u
#define V_HIT       0x00020000u
#define V_BLOCK     0x00008000u
#define V_BURST     0x0085u
#define V_LONG      0x0086u
#define V_TRIGGER2  0x1a21u
#define V_GUARD     0x00800000u

/* the task struct's fields */
#define A_FLAGS     16u
#define A_COUNTER_A 20u
#define A_COUNTDOWN 22u
#define A_COUNTER_B 24u
#define A_PAIR_A    28u
#define A_COUNTER_C 30u
#define A_COUNTER_D 32u
#define A_ROLL      34u
#define A_PER_CALL  36u
#define A_PAIR_B    38u
#define A_RELOAD    46u
#define A_SHIFT     0x40u
#define A_BURST     0x85u
#define A_LONG      0x86u

/* the state struct's fields */
#define C_ZERO      0x00u
#define C_KIND      0x61u
#define C_FLAGS     0x48u
#define C_OTHER     0x4cu
#define C_MORE      0x50u
#define C_FLOAT     0x5cu
#define C_LADDER    0x1bceu

/* the fighter struct's fields */
#define B_STAGE     0x3bu
#define B_FLAGS     0x48u
#define B_OTHER     0x4cu
#define B_KIND      0x61u
#define B_TRIGGER   0x1b98u
#define B_TRIGGER2  0x1a21u

struct scenario {
    const char *name;
    uint32_t a_flags, a_counter_a, a_countdown, a_counter_b, a_pair_a;
    uint32_t a_counter_c, a_counter_d, a_roll, a_per_call, a_pair_b;
    uint32_t a_reload, a_shift, a_burst, a_long;
    uint32_t c_zero, c_kind, c_flags, c_other, c_more, c_ladder;
    uint32_t b_stage, b_flags, b_other, b_kind, b_trigger, b_trigger2;
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

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the literal pool, with the values the real image holds */
    w16(p + OFF_POOL, P_LADDER   - POOL_BASE, (uint16_t)V_LADDER);
    w16(p + OFF_POOL, P_TRIGGER  - POOL_BASE, (uint16_t)V_TRIGGER);
    w16(p + OFF_POOL, P_LOW      - POOL_BASE, (uint16_t)V_LOW);
    w16(p + OFF_POOL, P_MID      - POOL_BASE, (uint16_t)V_MID);
    w32(p + OFF_POOL, P_TOP      - POOL_BASE, V_TOP);
    w32(p + OFF_POOL, P_FIGHTER  - POOL_BASE, V_FIGHTER);
    w32(p + OFF_POOL, P_STATE    - POOL_BASE, V_STATE);
    w32(p + OFF_POOL, P_HIT      - POOL_BASE, V_HIT);
    w32(p + OFF_POOL, P_BLOCK    - POOL_BASE, V_BLOCK);
    w16(p + OFF_POOL, P_BURST    - POOL_BASE, (uint16_t)V_BURST);
    w16(p + OFF_POOL, P_LONG     - POOL_BASE, (uint16_t)V_LONG);
    w16(p + OFF_POOL, P_BURST2   - POOL_BASE, (uint16_t)V_BURST);
    w16(p + OFF_POOL, P_TRIGGER2 - POOL_BASE, (uint16_t)V_TRIGGER2);
    w16(p + OFF_POOL, P_LONG2    - POOL_BASE, (uint16_t)V_LONG);
    w32(p + OFF_POOL, P_GUARD    - POOL_BASE, V_GUARD);

    /* the task struct */
    w16(p + OFF_TASK, A_FLAGS,     (uint16_t)sc->a_flags);
    w16(p + OFF_TASK, A_COUNTER_A, (uint16_t)sc->a_counter_a);
    w16(p + OFF_TASK, A_COUNTDOWN, (uint16_t)sc->a_countdown);
    w16(p + OFF_TASK, A_COUNTER_B, (uint16_t)sc->a_counter_b);
    w16(p + OFF_TASK, A_PAIR_A,    (uint16_t)sc->a_pair_a);
    w16(p + OFF_TASK, A_COUNTER_C, (uint16_t)sc->a_counter_c);
    w16(p + OFF_TASK, A_COUNTER_D, (uint16_t)sc->a_counter_d);
    w16(p + OFF_TASK, A_ROLL,      (uint16_t)sc->a_roll);
    w16(p + OFF_TASK, A_PER_CALL,  (uint16_t)sc->a_per_call);
    w16(p + OFF_TASK, A_PAIR_B,    (uint16_t)sc->a_pair_b);
    p[OFF_TASK + A_RELOAD] = (uint8_t)sc->a_reload;
    p[OFF_TASK + A_SHIFT]  = (uint8_t)sc->a_shift;
    p[OFF_TASK + A_BURST]  = (uint8_t)sc->a_burst;
    p[OFF_TASK + A_LONG]   = (uint8_t)sc->a_long;

    /* the state struct */
    w32(p + OFF_STATE, C_ZERO,  sc->c_zero);
    p[OFF_STATE + C_KIND] = (uint8_t)sc->c_kind;
    w32(p + OFF_STATE, C_FLAGS, sc->c_flags);
    w32(p + OFF_STATE, C_OTHER, sc->c_other);
    w32(p + OFF_STATE, C_MORE,  sc->c_more);
    w32(p + OFF_STATE, C_FLOAT, 0x3fc00000u);      /* 1.5f */
    w16(p + OFF_STATE, C_LADDER, (uint16_t)sc->c_ladder);

    /* the fighter struct */
    p[OFF_FIGHTER + B_STAGE] = (uint8_t)sc->b_stage;
    w32(p + OFF_FIGHTER, B_FLAGS,   sc->b_flags);
    w32(p + OFF_FIGHTER, B_OTHER,   sc->b_other);
    p[OFF_FIGHTER + B_KIND] = (uint8_t)sc->b_kind;
    w32(p + OFF_FIGHTER, B_TRIGGER,  sc->b_trigger);
    p[OFF_FIGHTER + B_TRIGGER2] = (uint8_t)sc->b_trigger2;

    /* the caller's frame: it points at the two structs */
    w32(p + OFF_FRAME, 0x48u, STATE_BASE);
    w32(p + OFF_FRAME, 0x4cu, FIGHTER_BASE);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = TASK_BASE;                /* r4 - the task struct */
    s->v[5] = FRAME_BASE;               /* r5 - the caller's frame */
    s->v[15] = STACK_TOP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;                  /* sr, with the T bit set */
    s->v[18] = 0u;                      /* fpscr: single precision */
    s->budget = 1000000u;

    r->base[0] = POOL_BASE;    r->len[0] = POOL_LEN;
    r->base[1] = TASK_BASE;    r->len[1] = TASK_LEN;
    r->base[2] = STATE_BASE;   r->len[2] = STATE_LEN;
    r->base[3] = FIGHTER_BASE; r->len[3] = FIGHTER_LEN;
    r->base[4] = FRAME_BASE;   r->len[4] = FRAME_LEN;
    r->base[5] = STACK_BASE;   r->len[5] = STACK_LEN;
    for (unsigned i = 0; i < NWIN; ++i) {
        r->wins[i].base = r->base[i];
        r->wins[i].len = r->len[i];
        r->wins[i].data = p + (i == 0 ? OFF_POOL : i == 1 ? OFF_TASK
                             : i == 2 ? OFF_STATE : i == 3 ? OFF_FIGHTER
                             : i == 4 ? OFF_FRAME : OFF_STACK);
    }
    r->map.wins = r->wins;
    r->map.n = NWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
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

/* What the fixture says the guest has to leave behind.  Worked out from the
 * disassembly alone - the generated translation is not consulted. */
struct result {
    uint32_t flags;       /* the frame's word at F+0 */
    uint32_t counter_a;   /* A+20 */
    uint32_t countdown;   /* A+22 */
    uint32_t counter_b;   /* A+24 */
    uint32_t pair_a;      /* A+28 */
    uint32_t counter_c;   /* A+30 */
    uint32_t counter_d;   /* A+32 */
    uint32_t roll;        /* A+34 */
    uint32_t per_call;    /* A+36 */
    uint32_t pair_b;      /* A+38 */
    uint32_t burst;       /* A+0x85 */
    uint32_t long_byte;   /* A+0x86 */
};

static int32_t half(uint32_t v)
{
    return (int32_t)(int16_t)(uint16_t)v;
}

static void expect(const struct scenario *sc, struct result *e)
{
    /* the frame the guest builds: F+12 is the state struct's word at +0x48,
     * F+16 the fighter's word at +0x48, F+20 the state struct's word at
     * +0x4c and F+32 the state struct's word at +0. */
    const uint32_t f12 = sc->c_flags;
    const uint32_t f16 = sc->b_flags;
    const uint32_t f20 = sc->c_other;
    const uint32_t f32 = sc->c_zero;
    uint32_t flags = sc->a_flags & 0xfffffffdu;
    uint32_t r13;

    /* bit 1 */
    if ((f12 & V_STATE) != 0 || (f20 & V_FIGHTER) != 0)
        flags |= 0x02u;
    /* bit 2 and bit 4 */
    if ((f12 & V_HIT) != 0 || (f12 & V_BLOCK) != 0) {
        flags |= 0x04u;
    } else {
        flags &= 0xfffffffbu;
        if (half(sc->c_ladder) >= 1 && (f12 & V_TOP) != 0)
            flags |= 0x04u;
    }
    /* bit 3 */
    flags &= 0xfffffff7u;
    if (sc->b_stage == 26u)
        flags |= 0x08u;
    /* bit 4 */
    flags &= 0xffffffefu;
    if (sc->b_trigger == 0u)
        flags |= 0x10u;
    e->flags = flags;

    /* the counter at +32 */
    e->counter_d = sc->a_counter_d & 0xffffu;
    if (((f20 & V_FIGHTER) != 0 || (f12 & V_LOW) != 0) && (f32 & V_FIGHTER) != 0)
        e->counter_d = (e->counter_d + 1u) & 0xffffu;

    /* the pair at +28 and +38 */
    if ((f12 & V_MID) == 0) {
        if ((flags & 0x02u) == 0) {
            e->pair_a = 0u;
            e->pair_b = (uint16_t)((uint32_t)(half(sc->a_pair_b) + 1));
        } else {
            e->pair_a = 0u;
            e->pair_b = 0u;
        }
    } else {
        e->pair_a = (uint16_t)((uint32_t)(half(sc->a_pair_a) + 1));
        e->pair_b = 0u;
    }

    /* the countdown at +22 */
    if ((sc->a_countdown & 0xffffu) != 0) {
        e->countdown = (uint16_t)((sc->a_countdown & 0xffffu) - 1u);
    } else {
        const uint32_t reload = sc->a_reload & 0xffu;
        int satisfied;
        if (sc->b_kind == 12u || sc->b_kind == 0u)
            satisfied = (sc->a_burst & 0xffu) >= 3u;
        else
            satisfied = (sc->a_long & 0xffu) >= 38u;
        e->countdown = satisfied ? 0u : reload;
    }

    /* the per-call counter at +36 */
    if ((flags & 0x10u) == 0) {
        e->per_call = 0u;
        r13 = 0u;
    } else {
        r13 = (uint32_t)(half(sc->a_per_call) + 1);
        e->per_call = (uint16_t)r13;
    }

    /* the rolling counter at +34 */
    e->roll = sc->a_roll & 0xffffu;
    e->burst = sc->a_burst & 0xffu;
    e->long_byte = sc->a_long & 0xffu;
    if ((flags & 0x10u) == 0) {
        r13 = (uint32_t)(half(sc->a_roll) + 1);
        e->roll = (uint16_t)r13;
        if ((r13 & 63u) == 0)
            e->burst = (e->burst + 1u) & 0xffu;
        if (e->burst >= 1u && (f16 & V_GUARD) != 0 &&
            sc->b_trigger2 == 1u && sc->b_kind != 0u)
            e->long_byte = (e->long_byte + 1u) & 0xffu;
    } else {
        if (r13 >= 7u) {
            e->roll = 0u;
            r13 = 0u;
        }
    }

    /* the level: the threshold the burst byte picks */
    {
        const uint32_t burst = e->burst & 0xffu;
        const uint32_t threshold = (burst == 3u) ? 96u : 35u;
        if (r13 >= threshold)
            e->flags |= 0x20u;
    }

    /* the three saturating counters */
    {
        const uint32_t v = sc->a_counter_c & 0xffffu;
        e->counter_c = v ? (uint16_t)(v - 1u) : 0u;
    }
    e->counter_b = sc->a_counter_b & 0xffffu;
    e->counter_a = sc->a_counter_a & 0xffffu;
    if (half(sc->a_counter_b) - 1 >= 0) {
        e->counter_b = (uint16_t)((uint32_t)(half(sc->a_counter_b) - 1));
    } else if (half(sc->a_counter_a) - 1 >= 0) {
        e->counter_a = (uint16_t)((uint32_t)(half(sc->a_counter_a) - 1));
    }
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

static uint16_t shadow_u16(const struct run *r, uint32_t addr)
{
    for (unsigned i = 0; i < NWIN; ++i)
        if (addr >= r->base[i] && addr + 2 <= r->base[i] + r->len[i]) {
            const uint8_t *p = r->wins[i].data + (addr - r->base[i]);
            return (uint16_t)((uint32_t)p[0] | ((uint32_t)p[1] << 8));
        }
    fprintf(stderr, "  the shadow does not hold %08x\n", addr);
    return 0xdeadu;
}

static uint8_t shadow_u8(const struct run *r, uint32_t addr)
{
    for (unsigned i = 0; i < NWIN; ++i)
        if (addr >= r->base[i] && addr + 1 <= r->base[i] + r->len[i])
            return r->wins[i].data[addr - r->base[i]];
    fprintf(stderr, "  the shadow does not hold %08x\n", addr);
    return 0xdeu;
}

static unsigned cases;

static int check_fixture(const struct scenario *sc, const struct run *ref)
{
    struct result want;
    expect(sc, &want);

    if (shadow_u32(ref, FRAME_BASE) != want.flags) {
        fprintf(stderr, "state ladder: %s: the flag word is %08x, expected %08x\n",
                sc->name, shadow_u32(ref, FRAME_BASE), want.flags);
        return 0;
    }
    /* the frame the guest builds out of the two structs.  The guest's frame
     * offsets are decimal: 12, 16, 20, 24, 28 and 32 are the two structs'
     * words, 36 the float, 44 and 48 the task's byte and the mask. */
    if (shadow_u32(ref, FRAME_BASE + 12u) != sc->c_flags ||
        shadow_u32(ref, FRAME_BASE + 16u) != sc->b_flags ||
        shadow_u32(ref, FRAME_BASE + 20u) != sc->c_other ||
        shadow_u32(ref, FRAME_BASE + 24u) != sc->b_other ||
        shadow_u32(ref, FRAME_BASE + 28u) != sc->c_more ||
        shadow_u32(ref, FRAME_BASE + 32u) != sc->c_zero) {
        fprintf(stderr, "state ladder: %s: the frame's copies are wrong\n", sc->name);
        return 0;
    }
    if (shadow_u32(ref, FRAME_BASE + 36u) != 0x3fc00000u) {
        fprintf(stderr, "state ladder: %s: the float spill is %08x\n",
                sc->name, shadow_u32(ref, FRAME_BASE + 36u));
        return 0;
    }
    if (shadow_u8(ref, FRAME_BASE + 8u) != (uint8_t)sc->c_kind) {
        fprintf(stderr, "state ladder: %s: the kind byte is %02x\n",
                sc->name, shadow_u8(ref, FRAME_BASE + 8u));
        return 0;
    }
    if (shadow_u32(ref, FRAME_BASE + 44u) != (sc->a_shift & 0xffu)) {
        fprintf(stderr, "state ladder: %s: the task's byte is %08x\n",
                sc->name, shadow_u32(ref, FRAME_BASE + 44u));
        return 0;
    }
    /* the mask the guest builds out of that byte: the pool's top bit shifted
     * right by the byte's value */
    {
        const uint32_t count = 0u - (sc->a_shift & 0xffu);
        uint32_t mask;
        if ((count & 0x80000000u) == 0)
            mask = 0x80000000u << (count & 31u);
        else if ((count & 31u) == 0)
            mask = 0u;
        else
            mask = 0x80000000u >> ((0u - count) & 31u);
        if (shadow_u32(ref, FRAME_BASE + 48u) != mask) {
            fprintf(stderr, "state ladder: %s: the mask is %08x, expected %08x\n",
                    sc->name, shadow_u32(ref, FRAME_BASE + 48u), mask);
            return 0;
        }
    }
    /* the task's counters */
    if (shadow_u16(ref, TASK_BASE + A_COUNTER_A) != want.counter_a ||
        shadow_u16(ref, TASK_BASE + A_COUNTDOWN) != want.countdown ||
        shadow_u16(ref, TASK_BASE + A_COUNTER_B) != want.counter_b ||
        shadow_u16(ref, TASK_BASE + A_PAIR_A) != want.pair_a ||
        shadow_u16(ref, TASK_BASE + A_COUNTER_C) != want.counter_c ||
        shadow_u16(ref, TASK_BASE + A_COUNTER_D) != want.counter_d ||
        shadow_u16(ref, TASK_BASE + A_ROLL) != want.roll ||
        shadow_u16(ref, TASK_BASE + A_PER_CALL) != want.per_call ||
        shadow_u16(ref, TASK_BASE + A_PAIR_B) != want.pair_b) {
        fprintf(stderr, "state ladder: %s: the task's counters are wrong "
                "(%04x/%04x/%04x/%04x/%04x/%04x/%04x/%04x/%04x)\n", sc->name,
                shadow_u16(ref, TASK_BASE + A_COUNTER_A),
                shadow_u16(ref, TASK_BASE + A_COUNTDOWN),
                shadow_u16(ref, TASK_BASE + A_COUNTER_B),
                shadow_u16(ref, TASK_BASE + A_PAIR_A),
                shadow_u16(ref, TASK_BASE + A_COUNTER_C),
                shadow_u16(ref, TASK_BASE + A_COUNTER_D),
                shadow_u16(ref, TASK_BASE + A_ROLL),
                shadow_u16(ref, TASK_BASE + A_PER_CALL),
                shadow_u16(ref, TASK_BASE + A_PAIR_B));
        return 0;
    }
    if (shadow_u8(ref, TASK_BASE + A_BURST) != (uint8_t)want.burst ||
        shadow_u8(ref, TASK_BASE + A_LONG) != (uint8_t)want.long_byte) {
        fprintf(stderr, "state ladder: %s: the burst/long bytes are %02x/%02x\n",
                sc->name, shadow_u8(ref, TASK_BASE + A_BURST),
                shadow_u8(ref, TASK_BASE + A_LONG));
        return 0;
    }
    /* the saved registers are back, the stack is where it was */
    if (ref->state.v[11] != 0x76543210u + 11u ||
        ref->state.v[12] != 0x76543210u + 12u ||
        ref->state.v[13] != 0x76543210u + 13u ||
        ref->state.v[14] != 0x76543210u + 14u) {
        fprintf(stderr, "state ladder: %s: the saved registers are %08x/%08x/%08x/%08x\n",
                sc->name, ref->state.v[11], ref->state.v[12],
                ref->state.v[13], ref->state.v[14]);
        return 0;
    }
    if (ref->state.v[15] != STACK_TOP) {
        fprintf(stderr, "state ladder: %s: the stack is at %08x\n",
                sc->name, ref->state.v[15]);
        return 0;
    }
    if (ref->state.pc != RETURN_PC) {
        fprintf(stderr, "state ladder: %s: the return address is %08x\n",
                sc->name, ref->state.pc);
        return 0;
    }
    /* and the float the guest loaded */
    if (ref->state.v[24] != 0x3fc00000u) {
        fprintf(stderr, "state ladder: %s: fr3 is %08x\n", sc->name, ref->state.v[24]);
        return 0;
    }
    return 1;
}

static int compare(const struct scenario *sc)
{
    struct run ref, port, hook;
    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_state_ladder_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "state ladder: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "state ladder: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }
    if (!check_fixture(sc, &ref)) {
        fprintf(stderr, "state ladder: %s does not match the fixture\n", sc->name);
        return 0;
    }

    ++cases;
    return 1;
}

/* The common starting point: a task with live counters and a fighter that is
 * *not* ready (its trigger word is not zero, so the flag word's bit four
 * stays clear and the rolling counter rolls).  A scenario overrides only the
 * fields it is about - designated initializers, so a field that is left out is
 * zero and cannot be forgotten. */
#define BASE \
    .a_counter_a = 5, .a_countdown = 7, .a_counter_b = 5, .a_pair_a = 9, \
    .a_counter_c = 5, .a_counter_d = 5, .a_roll = 5, .a_per_call = 5, \
    .a_pair_b = 9, .a_reload = 3, .b_trigger = 4

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_state_ladder_entry) {
        fprintf(stderr, "state ladder: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        { .name = "a quiet fight", BASE },
        /* bit 1: the state struct's flags, then the fighter's */
        { .name = "the state struct is busy", BASE, .c_flags = 0x0003d000u },
        { .name = "the fighter is busy", BASE, .c_other = 0x00100000u },
        /* bit 2: the two masks that stop it from being cleared */
        { .name = "the hit flag is set", BASE, .c_flags = 0x00020000u },
        { .name = "the block flag is set", BASE, .c_flags = 0x00008000u },
        /* bit 4: the ladder's own counter */
        { .name = "the ladder counter is high", BASE,
          .c_flags = 0x80000000u, .c_ladder = 4u },
        { .name = "the ladder counter is low", BASE, .c_flags = 0x80000000u },
        { .name = "the ladder counter is one", BASE,
          .c_flags = 0x80000000u, .c_ladder = 1u },
        /* the flag word the task carries may already have bit two set */
        { .name = "the flag word starts with bit two", BASE,
          .a_flags = 0x00000004u },
        /* bit 3: the fighter's stage byte */
        { .name = "the fighter is at stage 26", BASE, .b_stage = 26u },
        /* bit 4: the fighter's trigger word */
        { .name = "the fighter's trigger is zero", BASE, .b_trigger = 0u },
        { .name = "the fighter's trigger is not", BASE, .b_trigger = 4u },
        /* the counter at +32 */
        { .name = "the counter at 32 ticks", BASE,
          .c_other = 0x00100000u, .c_zero = 0x00100000u },
        { .name = "the counter at 32 does not", BASE, .c_other = 0x00100000u },
        { .name = "the counter at 32 ticks on the low bit", BASE,
          .c_flags = 0x00001000u, .c_zero = 0x00100000u },
        /* the pair at +28 and +38 */
        { .name = "the pair counts up", BASE },
        { .name = "the pair is held", BASE, .c_flags = 0x0003d000u },
        { .name = "the pair steps", BASE, .c_flags = 0x00004000u },
        /* the countdown at +22 */
        { .name = "the countdown runs down", BASE },
        { .name = "the countdown reloads", BASE,
          .a_countdown = 0, .b_kind = 12u },
        { .name = "the countdown resets on the burst", BASE,
          .a_countdown = 0, .b_kind = 12u, .a_burst = 3u },
        { .name = "the burst byte is two", BASE,
          .a_countdown = 0, .b_kind = 12u, .a_burst = 2u },
        { .name = "the countdown resets on the long byte", BASE,
          .a_countdown = 0, .b_kind = 5u, .a_long = 38u },
        { .name = "the long byte is short", BASE,
          .a_countdown = 0, .b_kind = 5u, .a_long = 37u },
        /* the rolling counter at +34 */
        { .name = "the roller rolls over", BASE, .a_roll = 63u },
        { .name = "the roller ticks the long byte", BASE,
          .a_roll = 63u, .b_flags = 0x00800000u, .b_kind = 2u, .b_trigger2 = 1u },
        { .name = "the roller leaves the long byte alone", BASE,
          .a_roll = 63u, .b_flags = 0x00800000u, .b_kind = 0u, .b_trigger2 = 1u },
        { .name = "the fighter is ready", BASE, .b_trigger = 0u, .a_per_call = 6u },
        /* the saturating counters */
        { .name = "the counters run out", BASE,
          .a_counter_a = 0, .a_counter_b = 0, .a_counter_c = 0 },
        { .name = "the counters step", BASE,
          .a_counter_a = 4, .a_counter_b = 4, .a_counter_c = 4 },
        /* the mask the guest builds out of the task's byte at +0x40 */
        { .name = "a wide mask", BASE, .a_shift = 1u },
        { .name = "a narrow mask", BASE, .a_shift = 32u },
        /* the level, against the threshold the burst byte picks */
        { .name = "the roller reaches the level", BASE, .a_roll = 34u },
        { .name = "the burst byte picks the other threshold", BASE,
          .a_roll = 94u, .a_burst = 3u },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("state_ladder: %u differential cases - PASS\n", cases);
    return 0;
}
