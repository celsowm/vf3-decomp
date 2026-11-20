/* Differential replay of the native fight-state ladder
 * (src/native/state_ladder.c, 0x8C08B89C) against the readable guest port
 * (src/fight/state_ladder.c, `vf3_state_ladder_entry`).
 *
 * Both sides run on the same flat RAM.  The pool, the task struct, the state
 * struct, the fighter struct, the caller's frame and the stack sit at the
 * game's own addresses, spanned by one flat buffer (the pool at 0x0c08b9b0,
 * the largest address the frame's end at 0x0c400100).  The whole region is
 * compared byte for byte, together with the registers, the FR bank, SR's T
 * bit and an independent fixture model that computes the flag word, the task's
 * counters and the frame the guest builds straight from the fixture.
 *
 * The leaf runs under single precision, round-to-nearest, no FTZ (FPSCR 0);
 * its arithmetic is integer except for one float copying through FR3. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/family_hooks.h"
#include "fight/readable_fp.h"
#include "state_ladder.h"
#include "aim_math.h"

#include <stdio.h>
#include <stdlib.h>
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

/* the flat buffer spans the whole guest address range, so every address is in
 * one contiguous space for both sides */
#define RAM_BASE     POOL_BASE
#define RAM_SIZE     ((FRAME_BASE + FRAME_LEN) - RAM_BASE)

#define OFF_POOL    (POOL_BASE - RAM_BASE)
#define OFF_TASK    (TASK_BASE - RAM_BASE)
#define OFF_STATE   (STATE_BASE - RAM_BASE)
#define OFF_FIGHTER (FIGHTER_BASE - RAM_BASE)
#define OFF_FRAME   (FRAME_BASE - RAM_BASE)
#define OFF_STACK   (STACK_BASE - RAM_BASE)

/* ---- the pool's entries, and the values the image holds ---- */
#define P_LADDER   (POOL_BASE + 0x08u)
#define P_TRIGGER  (POOL_BASE + 0x0au)
#define P_LOW      (POOL_BASE + 0x0cu)
#define P_MID      (POOL_BASE + 0x0eu)
#define P_TOP      (POOL_BASE + 0x10u)
#define P_FIGHTER  (POOL_BASE + 0x14u)
#define P_STATE    (POOL_BASE + 0x18u)
#define P_HIT      (POOL_BASE + 0x1cu)
#define P_BLOCK    (POOL_BASE + 0x20u)
#define P_BURST    (POOL_BASE + 0x9cu)
#define P_LONG     (POOL_BASE + 0x9eu)
#define P_BURST2   (POOL_BASE + 0x158u)
#define P_TRIGGER2 (POOL_BASE + 0x15au)
#define P_LONG2    (POOL_BASE + 0x15cu)
#define P_GUARD    (POOL_BASE + 0x160u)

#define V_LADDER    0x1bceu
#define V_TRIGGER   0x1b98u
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

static uint8_t *ram;

static uint8_t *ab(uint32_t addr) { return ram + (addr - RAM_BASE); }

static void w16(uint32_t addr, uint16_t v) { ab(addr)[0] = (uint8_t)v; ab(addr)[1] = (uint8_t)(v >> 8); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = ab(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static uint16_t r16(uint32_t addr)
{
    const uint8_t *p = ab(addr);
    return (uint16_t)((uint32_t)p[0] | ((uint32_t)p[1] << 8));
}
static uint8_t r8(uint32_t addr) { return ab(addr)[0]; }

static void seed_all(const struct scenario *sc)
{
    memset(ram, 0, RAM_SIZE);

    /* the literal pool, with the values the real image holds */
    w16(P_LADDER,   (uint16_t)V_LADDER);
    w16(P_TRIGGER,  (uint16_t)V_TRIGGER);
    w16(P_LOW,      (uint16_t)V_LOW);
    w16(P_MID,      (uint16_t)V_MID);
    w32(P_TOP,      V_TOP);
    w32(P_FIGHTER,  V_FIGHTER);
    w32(P_STATE,    V_STATE);
    w32(P_HIT,      V_HIT);
    w32(P_BLOCK,    V_BLOCK);
    w16(P_BURST,    (uint16_t)V_BURST);
    w16(P_LONG,     (uint16_t)V_LONG);
    w16(P_BURST2,   (uint16_t)V_BURST);
    w16(P_TRIGGER2, (uint16_t)V_TRIGGER2);
    w16(P_LONG2,    (uint16_t)V_LONG);
    w32(P_GUARD,    V_GUARD);

    /* the task struct */
    w16(TASK_BASE + A_FLAGS,     (uint16_t)sc->a_flags);
    w16(TASK_BASE + A_COUNTER_A, (uint16_t)sc->a_counter_a);
    w16(TASK_BASE + A_COUNTDOWN, (uint16_t)sc->a_countdown);
    w16(TASK_BASE + A_COUNTER_B, (uint16_t)sc->a_counter_b);
    w16(TASK_BASE + A_PAIR_A,    (uint16_t)sc->a_pair_a);
    w16(TASK_BASE + A_COUNTER_C, (uint16_t)sc->a_counter_c);
    w16(TASK_BASE + A_COUNTER_D, (uint16_t)sc->a_counter_d);
    w16(TASK_BASE + A_ROLL,      (uint16_t)sc->a_roll);
    w16(TASK_BASE + A_PER_CALL,  (uint16_t)sc->a_per_call);
    w16(TASK_BASE + A_PAIR_B,    (uint16_t)sc->a_pair_b);
    ab(TASK_BASE + A_RELOAD)[0] = (uint8_t)sc->a_reload;
    ab(TASK_BASE + A_SHIFT)[0]  = (uint8_t)sc->a_shift;
    ab(TASK_BASE + A_BURST)[0]  = (uint8_t)sc->a_burst;
    ab(TASK_BASE + A_LONG)[0]   = (uint8_t)sc->a_long;

    /* the state struct */
    w32(STATE_BASE + C_ZERO,  sc->c_zero);
    ab(STATE_BASE + C_KIND)[0] = (uint8_t)sc->c_kind;
    w32(STATE_BASE + C_FLAGS, sc->c_flags);
    w32(STATE_BASE + C_OTHER, sc->c_other);
    w32(STATE_BASE + C_MORE,  sc->c_more);
    w32(STATE_BASE + C_FLOAT, 0x3fc00000u);      /* 1.5f */
    w16(STATE_BASE + C_LADDER, (uint16_t)sc->c_ladder);

    /* the fighter struct */
    ab(FIGHTER_BASE + B_STAGE)[0] = (uint8_t)sc->b_stage;
    w32(FIGHTER_BASE + B_FLAGS,   sc->b_flags);
    w32(FIGHTER_BASE + B_OTHER,   sc->b_other);
    ab(FIGHTER_BASE + B_KIND)[0]  = (uint8_t)sc->b_kind;
    w32(FIGHTER_BASE + B_TRIGGER, sc->b_trigger);
    ab(FIGHTER_BASE + B_TRIGGER2)[0] = (uint8_t)sc->b_trigger2;

    /* the caller's frame: it points at the two structs */
    w32(FRAME_BASE + 0x48u, STATE_BASE);
    w32(FRAME_BASE + 0x4cu, FIGHTER_BASE);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win,
                        uint32_t in_v[54])
{
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 54; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = TASK_BASE;                /* r4 - the task struct */
    s->v[5] = FRAME_BASE;               /* r5 - the caller's frame */
    s->v[15] = STACK_TOP;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;                  /* sr, with the T bit set */
    s->v[18] = 0u;                      /* fpscr: single precision */
    s->budget = 1000000u;
    memcpy(in_v, s->v, 54 * sizeof(uint32_t));

    static const struct { uint32_t base, len; } W[6] = {
        { POOL_BASE, POOL_LEN }, { TASK_BASE, TASK_LEN },
        { STATE_BASE, STATE_LEN }, { FIGHTER_BASE, FIGHTER_LEN },
        { FRAME_BASE, FRAME_LEN }, { STACK_BASE, STACK_LEN },
    };
    for (unsigned i = 0; i < 6; ++i) {
        win[i].base = W[i].base;
        win[i].len = W[i].len;
        win[i].data = ab(W[i].base);
    }
    map->wins = win;
    map->n = 6;
    map->oob = 0;
    map->device_read = NULL;
    map->device_write = NULL;
    map->device_context = NULL;
}

static int32_t half(uint32_t v)
{
    return (int32_t)(int16_t)(uint16_t)v;
}

/* the fixture model - computes the flag word, the task's counters and the
 * frame word straight from the fixture, without consulting the translation. */
struct result {
    uint32_t flags, counter_a, countdown, counter_b, pair_a, counter_c;
    uint32_t counter_d, roll, per_call, pair_b, burst, long_byte;
};

static void expect(const struct scenario *sc, struct result *e)
{
    const uint32_t f12 = sc->c_flags;
    const uint32_t f16 = sc->b_flags;
    const uint32_t f20 = sc->c_other;
    const uint32_t f32 = sc->c_zero;
    uint32_t flags = sc->a_flags & 0xfffffffdu;
    uint32_t r13;

    if ((f12 & V_STATE) != 0 || (f20 & V_FIGHTER) != 0)
        flags |= 0x02u;
    if ((f12 & V_HIT) != 0 || (f12 & V_BLOCK) != 0) {
        flags |= 0x04u;
    } else {
        flags &= 0xfffffffbu;
        if (half(sc->c_ladder) >= 1 && (f12 & V_TOP) != 0)
            flags |= 0x04u;
    }
    flags &= 0xfffffff7u;
    if (sc->b_stage == 26u)
        flags |= 0x08u;
    flags &= 0xffffffefu;
    if (sc->b_trigger == 0u)
        flags |= 0x10u;
    e->flags = flags;

    e->counter_d = sc->a_counter_d & 0xffffu;
    if (((f20 & V_FIGHTER) != 0 || (f12 & V_LOW) != 0) && (f32 & V_FIGHTER) != 0)
        e->counter_d = (e->counter_d + 1u) & 0xffffu;

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

    if ((flags & 0x10u) == 0) {
        e->per_call = 0u;
        r13 = 0u;
    } else {
        r13 = (uint32_t)(half(sc->a_per_call) + 1);
        e->per_call = (uint16_t)r13;
    }

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

    {
        const uint32_t burst = e->burst & 0xffu;
        const uint32_t threshold = (burst == 3u) ? 96u : 35u;
        if (r13 >= threshold)
            e->flags |= 0x20u;
    }

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

static int compare_one(const struct scenario *sc)
{
    printf("== %s\n", sc->name);

    seed_all(sc);
    uint8_t *seed_shot = (uint8_t *)malloc(RAM_SIZE);
    memcpy(seed_shot, ram, RAM_SIZE);

    /* ---- guest side ---- */
    vf3_matrix_state gs;
    vf3_ram_map gmap;
    vf3_ram_win gwin[6];
    uint32_t in_v[54];
    setup_guest(&gs, &gmap, gwin, in_v);
    memcpy(ram, seed_shot, RAM_SIZE);
    const int ok_guest = vf3_state_ladder_entry(&gs, &gmap);
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        free(seed_shot);
        return 1;
    }
    uint8_t *guest_shot = (uint8_t *)malloc(RAM_SIZE);
    memcpy(guest_shot, ram, RAM_SIZE);

    /* ---- native side ---- */
    memcpy(ram, seed_shot, RAM_SIZE);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = (float *)ram;
    a.ram_base = RAM_BASE;
    for (unsigned i = 0; i < 16; ++i) a.r[i] = in_v[i];
    for (unsigned i = 0; i < 16; ++i)
        memcpy(&a.fr[i], &in_v[21u + i], 4);
    a.pr = in_v[16];
    a.sr = 0x301u;
    a.fpscr = 0;
    a.fpul = in_v[53];
    vf3_native_state_ladder(&a);
    free(seed_shot);

    int bad = 0;

    /* RAM region - compare the native's writes against the guest's snapshot,
     * byte for byte over the whole flat span */
    {
        int nb = 0;
        for (uint32_t ad = RAM_BASE; ad < FRAME_BASE + FRAME_LEN; ad += 4) {
            uint32_t n = vf3_aim_u32(&a, ad);          /* the native's RAM */
            const uint8_t *p = guest_shot + (ad - RAM_BASE);
            uint32_t g = (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
                         ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
            if (g != n) {
                if (nb < 10) fprintf(stderr, "  ram @%08x: got %08x want %08x\n", ad, n, g);
                nb++;
            }
        }
        printf("  ram[%08x..%08x): %s\n", RAM_BASE, FRAME_BASE + FRAME_LEN,
               nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    /* registers + FR bank + T bit + fixture model */
    {
        int nb = 0;
        for (unsigned i = 0; i < 16; ++i) {
            if (i == 4 || i == 16) continue;   /* r4 is the task pointer; pr is apart */
            if (a.r[i] != gs.v[i]) {
                fprintf(stderr, "  r%u: native %08x want %08x\n", i, a.r[i], gs.v[i]);
                nb++;
            }
        }
        for (unsigned i = 0; i < 16; ++i) {
            uint32_t ub;
            memcpy(&ub, &a.fr[i], 4);
            if (ub != gs.v[21u + i]) { fprintf(stderr, "  fr%u differs\n", i); nb++; }
        }
        if ((a.sr & 1u) != (gs.v[17] & 1u)) {
            fprintf(stderr, "  T bit %u vs %u\n", a.sr & 1u, gs.v[17] & 1u);
            nb++;
        }
        if (a.r[15] != gs.v[15]) { fprintf(stderr, "  r15 differs\n"); nb++; }

        struct result want;
        expect(sc, &want);
        if (r32(FRAME_BASE) != want.flags) {
            fprintf(stderr, "  flags %08x want %08x\n", r32(FRAME_BASE), want.flags);
            nb++;
        }
        if (r16(TASK_BASE + A_COUNTER_A) != (uint16_t)want.counter_a ||
            r16(TASK_BASE + A_COUNTDOWN) != (uint16_t)want.countdown ||
            r16(TASK_BASE + A_COUNTER_B) != (uint16_t)want.counter_b ||
            r16(TASK_BASE + A_PAIR_A) != (uint16_t)want.pair_a ||
            r16(TASK_BASE + A_COUNTER_C) != (uint16_t)want.counter_c ||
            r16(TASK_BASE + A_COUNTER_D) != (uint16_t)want.counter_d ||
            r16(TASK_BASE + A_ROLL) != (uint16_t)want.roll ||
            r16(TASK_BASE + A_PER_CALL) != (uint16_t)want.per_call ||
            r16(TASK_BASE + A_PAIR_B) != (uint16_t)want.pair_b) {
            fprintf(stderr, "  counters wrong\n");
            nb++;
        }
        if (r8(TASK_BASE + A_BURST) != (uint8_t)want.burst ||
            r8(TASK_BASE + A_LONG) != (uint8_t)want.long_byte) {
            fprintf(stderr, "  burst/long wrong\n");
            nb++;
        }
        /* the frame the guest builds: the copies, the float spill and the kind */
        if (r32(FRAME_BASE + 12u) != sc->c_flags ||
            r32(FRAME_BASE + 16u) != sc->b_flags ||
            r32(FRAME_BASE + 20u) != sc->c_other ||
            r32(FRAME_BASE + 24u) != sc->b_other ||
            r32(FRAME_BASE + 28u) != sc->c_more ||
            r32(FRAME_BASE + 32u) != sc->c_zero) {
            fprintf(stderr, "  frame copies wrong\n");
            nb++;
        }
        if (r32(FRAME_BASE + 36u) != 0x3fc00000u ||
            r32(FRAME_BASE + 44u) != (sc->a_shift & 0xffu)) {
            fprintf(stderr, "  float spill / shift byte wrong\n");
            nb++;
        }
        /* the mask the guest builds out of the task's byte at +0x40 */
        {
            const uint32_t count = 0u - (sc->a_shift & 0xffu);
            uint32_t mask;
            if ((count & 0x80000000u) == 0)
                mask = 0x80000000u << (count & 31u);
            else if ((count & 31u) == 0)
                mask = 0u;
            else
                mask = 0x80000000u >> ((0u - count) & 31u);
            if (r32(FRAME_BASE + 48u) != mask) {
                fprintf(stderr, "  mask %08x want %08x\n", r32(FRAME_BASE + 48u), mask);
                nb++;
            }
        }
        if (r8(FRAME_BASE + 8u) != (uint8_t)sc->c_kind) {
            fprintf(stderr, "  kind byte wrong\n");
            nb++;
        }
        printf("  regs+model: %s\n", nb ? "DIFFERS" : "match");
        bad |= (nb != 0);
    }

    free(guest_shot);
    return bad ? 1 : 0;
}

/* The common starting point: a task with live counters and a fighter that is
 * *not* ready (its trigger word is not zero, so the flag word's bit four
 * stays clear and the rolling counter rolls).  A scenario overrides only the
 * fields it is about. */
#define BASE \
    .a_counter_a = 5, .a_countdown = 7, .a_counter_b = 5, .a_pair_a = 9, \
    .a_counter_c = 5, .a_counter_d = 5, .a_roll = 5, .a_per_call = 5, \
    .a_pair_b = 9, .a_reload = 3, .b_trigger = 4

int main(void)
{
    ram = (uint8_t *)malloc(RAM_SIZE);
    if (!ram) return 2;
    /* touch every page once so the big flat buffer is really allocated */
    {
        for (size_t i = 0; i < RAM_SIZE; i += 4096) ram[i] = 0;
        ram[RAM_SIZE - 1] = 0;
    }

    static const struct scenario scenarios[] = {
        { .name = "a quiet fight", BASE },
        { .name = "the state struct is busy", BASE, .c_flags = 0x0003d000u },
        { .name = "the fighter is busy", BASE, .c_other = 0x00100000u },
        { .name = "the hit flag is set", BASE, .c_flags = 0x00020000u },
        { .name = "the block flag is set", BASE, .c_flags = 0x00008000u },
        { .name = "the ladder counter is high", BASE,
          .c_flags = 0x80000000u, .c_ladder = 4u },
        { .name = "the ladder counter is low", BASE, .c_flags = 0x80000000u },
        { .name = "the ladder counter is one", BASE,
          .c_flags = 0x80000000u, .c_ladder = 1u },
        { .name = "the flag word starts with bit two", BASE,
          .a_flags = 0x00000004u },
        { .name = "the fighter is at stage 26", BASE, .b_stage = 26u },
        { .name = "the fighter's trigger is zero", BASE, .b_trigger = 0u },
        { .name = "the fighter's trigger is not", BASE, .b_trigger = 4u },
        { .name = "the counter at 32 ticks", BASE,
          .c_other = 0x00100000u, .c_zero = 0x00100000u },
        { .name = "the counter at 32 does not", BASE, .c_other = 0x00100000u },
        { .name = "the counter at 32 ticks on the low bit", BASE,
          .c_flags = 0x00001000u, .c_zero = 0x00100000u },
        { .name = "the pair counts up", BASE },
        { .name = "the pair is held", BASE, .c_flags = 0x0003d000u },
        { .name = "the pair steps", BASE, .c_flags = 0x00004000u },
        { .name = "the countdown runs down", BASE },
        { .name = "the countdown reloads", BASE,
          .a_countdown = 0, .b_kind = 12u },
        { .name = "the countdown reloads on a zero kind", BASE,
          .a_countdown = 0, .b_kind = 0u, .a_burst = 3u },
        { .name = "the countdown resets on the burst", BASE,
          .a_countdown = 0, .b_kind = 12u, .a_burst = 3u },
        { .name = "the burst byte is two", BASE,
          .a_countdown = 0, .b_kind = 12u, .a_burst = 2u },
        { .name = "the countdown resets on the long byte", BASE,
          .a_countdown = 0, .b_kind = 5u, .a_long = 38u },
        { .name = "the long byte is short", BASE,
          .a_countdown = 0, .b_kind = 5u, .a_long = 37u },
        { .name = "the roller rolls over", BASE, .a_roll = 63u },
        { .name = "the roller ticks the long byte", BASE,
          .a_roll = 63u, .b_flags = 0x00800000u, .b_kind = 2u, .b_trigger2 = 1u },
        { .name = "the roller leaves the long byte alone", BASE,
          .a_roll = 63u, .b_flags = 0x00800000u, .b_kind = 0u, .b_trigger2 = 1u },
        { .name = "the fighter is ready", BASE, .b_trigger = 0u, .a_per_call = 6u },
        { .name = "the counters run out", BASE,
          .a_counter_a = 0, .a_counter_b = 0, .a_counter_c = 0 },
        { .name = "the counters step", BASE,
          .a_counter_a = 4, .a_counter_b = 4, .a_counter_c = 4 },
        { .name = "a wide mask", BASE, .a_shift = 1u },
        { .name = "a narrow mask", BASE, .a_shift = 32u },
        { .name = "the roller reaches the level", BASE, .a_roll = 34u },
        { .name = "the burst byte picks the other threshold", BASE,
          .a_roll = 94u, .a_burst = 3u },
    };

    int bad = 0;
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        bad |= compare_one(&scenarios[i]);

    free(ram);
    printf("state_ladder_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
