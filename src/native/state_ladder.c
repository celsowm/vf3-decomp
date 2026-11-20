/* state_ladder.c - SH-4 0x8C08B89C: the fight-state ladder, natively.
 *
 * A plain-C transcription of the readable port src/fight/state_ladder.c
 * (`vf3_state_ladder_entry`) onto `vf3_native_aim`: the flat RAM, the register
 * file and the FR bank.
 *
 * This is the second half of the counter updater (0x8C08B7EE, src/fight/cntup.c):
 * the caller hands it a task struct and a frame, and it does two jobs.
 *
 *   * it **folds the fight's flag words into one word**, the frame's word at
 *     F+0.  Six bits are decided there, each from a different pair of the
 *     caller's words;
 *   * it **steps the task's counters** (the per-call counter, the pair, the
 *     countdown, the rolling counter and the three saturating counters).
 *
 * The frame the guest builds is *its own*: it opens 52 bytes below the four
 * registers it saves, and it fills them from the task, state and fighter
 * structs - the two structs the caller's frame points at.  The port reproduces
 * that traffic exactly, because the caller reads the frame back.
 *
 * The literal pool is read at run time, the way the guest reads it: the
 * offsets into the two structs and the six masks are the image's, and this
 * port does not bake them in.  A replay has to supply the pool as part of the
 * flat RAM - see tests/state_ladder_native_replay.c.
 *
 * Details the port has to keep:
 *
 *   * the **T bit** is the guest's branch condition (a plain `bf` branches when
 *     the T bit is clear);
 *   * a **`/s` branch runs its delay slot on both paths**, so the value the
 *     delay slot spills into the guest's scratch word is written whether the
 *     branch is taken or not - the port writes those words too;
 *   * the **`shld`** at 0x8C08B8EE shifts the pool's top bit right by the
 *     task's byte at +0x40: a negative count is a right shift, and a count
 *     whose low five bits are zero gives **zero**, not the value itself;
 *   * the guest's **counter decrements saturate**;
 *   * the **return** pops the four saved registers, so the caller sees its own
 *     r11, r12, r13 and r14 back.
 *
 * See docs/re/native_state_ladder.md. */
#include "state_ladder.h"

#include <stdint.h>
#include <string.h>

#include "aim_math.h"

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

/* The guest's literal pool.  Every entry is read from RAM at run time. */
#define POOL_LADDER_COUNTER  0x0c08b9b8u
#define POOL_FIGHTER_TRIGGER 0x0c08b9bau
#define POOL_LOW_FLAG        0x0c08b9bcu
#define POOL_MID_FLAG        0x0c08b9beu
#define POOL_TOP_BIT         0x0c08b9c0u
#define POOL_FIGHTER_BIT     0x0c08b9c4u
#define POOL_STATE_FLAGS     0x0c08b9c8u
#define POOL_HIT_FLAG        0x0c08b9ccu
#define POOL_BLOCK_FLAG      0x0c08b9d0u
#define POOL_BURST_OFFSET    0x0c08ba4cu
#define POOL_LONG_OFFSET     0x0c08ba4eu
#define POOL_BURST_OFFSET2   0x0c08bb08u
#define POOL_TRIGGER2        0x0c08bb0au
#define POOL_LONG_OFFSET2    0x0c08bb0cu
#define POOL_GUARD_BIT       0x0c08bb10u

/* the task struct's fields */
#define TASK_FLAGS      16u
#define TASK_COUNTER_A  20u
#define TASK_COUNTDOWN  22u
#define TASK_COUNTER_B  24u
#define TASK_PAIR_A     28u
#define TASK_COUNTER_C  30u
#define TASK_COUNTER_D  32u
#define TASK_ROLL       34u
#define TASK_PER_CALL   36u
#define TASK_PAIR_B     38u
#define TASK_RELOAD     46u
#define TASK_SHIFT      0x40u
#define TASK_BURST      0x85u
#define TASK_LONG       0x86u

/* the fighter struct's fields */
#define FIGHTER_STAGE   0x3bu
#define FIGHTER_KIND    0x61u

/* the flags the ladder folds into the frame's word at F+0 */
#define FLAG_IN_HIT    0x02u
#define FLAG_CLEARED   0x04u
#define FLAG_STAGE     0x08u
#define FLAG_READY     0x10u
#define FLAG_LEVEL     0x20u

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* the guest's halfword: sixteen bits, sign extended */
static int32_t half(uint32_t v)
{
    return (int32_t)(int16_t)(uint16_t)v;
}

/* the guest's byte: eight bits, sign extended */
static int32_t byte(uint32_t v)
{
    return (int32_t)(int8_t)(uint8_t)v;
}

static void set_u8(vf3_native_aim *a, uint32_t addr, uint8_t v)
{
    ((uint8_t *)vf3_aim_p(a, addr))[0] = v;
}

/* The guest's dynamic shift (SHLD).  The count is negative here, so the
 * shift is a right one - and a count whose low five bits are zero gives
 * zero, not the value. */
static uint32_t shld(uint32_t value, uint32_t count)
{
    if ((count & 0x80000000u) == 0)
        return value << (count & 31u);
    if ((count & 31u) == 0)
        return 0u;
    return value >> ((0u - count) & 31u);
}

void vf3_native_state_ladder(vf3_native_aim *a)
{
    const uint32_t entry_sp = R(15);
    const uint32_t task = R(4);        /* A: the task struct */
    uint32_t r0 = 0, r1 = 0, r2 = 0, r3 = 0;
    uint32_t r5, r6 = 0, r7 = 0, r11 = 0, r12 = 0, r13 = 0, r14 = 0;
    uint32_t r15 = entry_sp;
    uint32_t state;                    /* C: the state struct */
    uint32_t fighter;                  /* B: the fighter struct */
    int busy;                          /* a branch's outcome */

    r5 = R(5);                        /* F: the caller's frame */

    /* ---- the prologue: four registers saved, then the frame opened ---- */
    r0 = 0x48u;
    r15 -= 4u; vf3_aim_set_u32(a, r15, R(14));
    r15 -= 4u; vf3_aim_set_u32(a, r15, R(13));
    r15 -= 4u; vf3_aim_set_u32(a, r15, R(12));
    r15 -= 4u; vf3_aim_set_u32(a, r15, R(11));

    state = vf3_aim_u32(a, r5 + 0x48u);
    r6 = state;
    r0 = 0x4cu;
    fighter = vf3_aim_u32(a, r5 + 0x4cu);
    r14 = fighter;
    r0 = 0x61u;

    r3 = vf3_aim_u32(a, task + TASK_FLAGS);
    r15 -= 8u;                        /* the frame's 52 bytes live here */
    vf3_aim_set_u32(a, r5 + 0u, r3);

    r2 = vf3_aim_u32(a, state + 56u);
    vf3_aim_set_u32(a, r5 + 4u, r2);
    r0 = (uint32_t)byte(vf3_aim_u8(a, state + r0));
    set_u8(a, r5 + 8u, (uint8_t)r0);   /* a byte store */
    r0 = 0x48u;
    r3 = vf3_aim_u32(a, state + r0);
    vf3_aim_set_u32(a, r5 + 12u, r3);
    r2 = vf3_aim_u32(a, fighter + r0);
    r0 = 0x4cu;
    vf3_aim_set_u32(a, r5 + 16u, r2);
    r3 = vf3_aim_u32(a, state + r0);
    vf3_aim_set_u32(a, r5 + 20u, r3);
    r2 = vf3_aim_u32(a, fighter + r0);
    r0 = 0x50u;
    vf3_aim_set_u32(a, r5 + 24u, r2);
    r3 = vf3_aim_u32(a, state + r0);
    r0 = 0x5cu;
    vf3_aim_set_u32(a, r5 + 28u, r3);
    r2 = vf3_aim_u32(a, state);
    vf3_aim_set_u32(a, r5 + 32u, r2);
    /* fr3: the float at state+0x5c, and its spill into the frame (single) */
    memcpy(&F(3), vf3_aim_p(a, state + r0), 4);
    r0 = 0x24u;
    vf3_aim_set_u32(a, r5 + r0, vf3_aim_u32(a, state + 0x5cu));

    /* the mask the guest builds out of the task's byte at +0x40 */
    r0 = TASK_SHIFT;
    r3 = (uint32_t)byte(vf3_aim_u8(a, task + r0));
    r3 &= 0xffu;
    vf3_aim_set_u32(a, r5 + 44u, r3);
    r3 = 0u - r3;
    r2 = vf3_aim_u32(a, POOL_TOP_BIT);
    r2 = shld(r2, r3);
    r3 = 0xfffffffdu;
    vf3_aim_set_u32(a, r5 + 48u, r2);

    /* ---- bit 1: the state struct or the fighter says "in hit" ---- */
    r1 = vf3_aim_u32(a, r5 + 0u);
    r1 &= r3;
    vf3_aim_set_u32(a, r5 + 0u, r1);

    r1 = vf3_aim_u32(a, r5 + 12u);
    r2 = vf3_aim_u32(a, POOL_STATE_FLAGS);
    r7 = vf3_aim_u32(a, POOL_FIGHTER_BIT);
    set_t(a, (r1 & r2) == 0);
    busy = (r1 & r2) != 0;
    if (!busy) {
        r3 = vf3_aim_u32(a, r5 + 20u);
        set_t(a, (r3 & r7) == 0);
        busy = (r3 & r7) != 0;
    }
    if (busy) {
        r0 = vf3_aim_u32(a, r5 + 0u);
        r0 |= FLAG_IN_HIT;
        vf3_aim_set_u32(a, r5 + 0u, r0);
    }

    /* ---- bit 2 and bit 4: the state struct's flags and the ladder counter ---- */
    r3 = vf3_aim_u32(a, POOL_HIT_FLAG);
    r13 = vf3_aim_u32(a, r5 + 12u);
    set_t(a, (r3 & r13) == 0);
    busy = (r3 & r13) != 0;
    if (!busy) {
        r2 = vf3_aim_u32(a, POOL_BLOCK_FLAG);
        set_t(a, (r2 & r13) == 0);
        busy = (r2 & r13) != 0;
        if (!busy) {
            /* the flag is quiet: clear bit 2 and ask the ladder's counter */
            r1 = vf3_aim_u32(a, r5 + 0u);
            r3 = 0xfffffffbu;
            r1 &= r3;
            vf3_aim_set_u32(a, r5 + 0u, r1);
            r1 = 1u;
            r0 = (uint32_t)half(vf3_aim_h16(a, POOL_LADDER_COUNTER));
            r2 = (uint32_t)half(vf3_aim_h16(a, state + r0));
            set_t(a, (int32_t)r2 >= (int32_t)r1);
            vf3_aim_set_u32(a, r15, r2);   /* the delay slot's spill */
            if ((int32_t)r2 >= (int32_t)r1) {
                r3 = vf3_aim_u32(a, POOL_TOP_BIT);
                set_t(a, (r13 & r3) == 0);
                busy = (r13 & r3) != 0;
            }
        }
    }
    if (busy) {
        r0 = vf3_aim_u32(a, r5 + 0u);
        r0 |= FLAG_CLEARED;
        vf3_aim_set_u32(a, r5 + 0u, r0);
    }

    /* ---- bit 3: the fighter's byte at +0x3b ---- */
    r1 = r14 + 0x38u;
    r2 = vf3_aim_u32(a, r5 + 0u);
    r3 = 0xfffffff7u;
    r2 &= r3;
    vf3_aim_set_u32(a, r5 + 0u, r2);
    r0 = (uint32_t)byte(vf3_aim_u8(a, r1 + 3u));
    r0 &= 0xffu;
    set_t(a, r0 == 26u);
    vf3_aim_set_u32(a, r15, r0);       /* the delay slot's spill */
    if (r0 == 26u) {
        r0 = vf3_aim_u32(a, r5 + 0u);
        r0 |= FLAG_STAGE;
        vf3_aim_set_u32(a, r5 + 0u, r0);
    }

    /* ---- bit 4: the fighter's word at the pool's offset ---- */
    r2 = vf3_aim_u32(a, r5 + 0u);
    r3 = 0xffffffefu;
    r2 &= r3;
    vf3_aim_set_u32(a, r5 + 0u, r2);
    r0 = (uint32_t)half(vf3_aim_h16(a, POOL_FIGHTER_TRIGGER));
    r1 = vf3_aim_u32(a, r14 + r0);
    r2 = r1;
    set_t(a, (r2 & r2) == 0);
    vf3_aim_set_u32(a, r15, r1);       /* the delay slot's spill */
    r12 = 0x10u;
    if (r1 == 0) {
        r2 = vf3_aim_u32(a, r5 + 0u);
        r2 |= r12;
        vf3_aim_set_u32(a, r5 + 0u, r2);
    }

    /* ---- the task's counter at +32 ---- */
    r3 = vf3_aim_u32(a, r5 + 20u);
    set_t(a, (r3 & r7) == 0);
    busy = (r3 & r7) != 0;
    if (!busy) {
        r2 = vf3_aim_u32(a, r5 + 12u);
        r3 = (uint32_t)half(vf3_aim_h16(a, POOL_LOW_FLAG));
        set_t(a, (r2 & r3) == 0);
        busy = (r2 & r3) != 0;
    }
    if (busy) {
        r1 = vf3_aim_u32(a, r5 + 32u);
        set_t(a, (r7 & r1) == 0);
        if ((r7 & r1) != 0) {
            r0 = TASK_COUNTER_D;
            r7 = (uint32_t)half(vf3_aim_h16(a, task + r0));
            r7 &= 0xffffu;
            r7 += 1u;
            vf3_aim_set_u16(a, task + r0, (uint16_t)r7);
        }
    }

    /* ---- the pair at +28 and +38 ---- */
    r0 = (uint32_t)half(vf3_aim_h16(a, task + TASK_PAIR_A));
    r3 = (uint32_t)half(vf3_aim_h16(a, POOL_MID_FLAG));
    r13 = r0;
    r2 = vf3_aim_u32(a, r5 + 12u);
    r0 = TASK_PAIR_B;
    r11 = (uint32_t)half(vf3_aim_h16(a, task + r0));
    set_t(a, (r2 & r3) == 0);
    r7 = 0u;
    if ((r2 & r3) == 0) {
        /* the state struct is quiet: the flag word decides */
        r0 = vf3_aim_u32(a, r5 + 0u);
        set_t(a, (r0 & FLAG_IN_HIT) == 0);
        if ((r0 & FLAG_IN_HIT) == 0) {
            r13 = r7;                  /* zero */
            r11 += 1u;                 /* the pair's other half counts up */
        } else {
            r11 = r7;
            r13 = r7;
        }
    } else {
        r13 += 1u;
        r11 = r7;
    }
    r0 = r13;
    vf3_aim_set_u16(a, task + TASK_PAIR_A, (uint16_t)r0);
    r0 = TASK_PAIR_B;
    vf3_aim_set_u16(a, task + r0, (uint16_t)r11);

    /* ---- the countdown at +22: it counts down and reloads ---- */
    r0 = (uint32_t)half(vf3_aim_h16(a, task + TASK_COUNTDOWN));
    r11 = r0 & 0xffffu;
    r11 += 0xffffffffu;
    set_t(a, (int32_t)r11 >= 0);
    r13 = r11;
    if ((int32_t)r11 < 0) {
        /* the countdown ran out: the reload value and the fighter's kind
         * decide whether the counter is reset or set to the reload value */
        r0 = TASK_RELOAD;
        r13 = (uint32_t)byte(vf3_aim_u8(a, task + r0));
        r0 = FIGHTER_KIND;
        r11 = (uint32_t)byte(vf3_aim_u8(a, fighter + r0));
        r13 &= 0xffu;
        r0 = r11 & 0xffu;
        set_t(a, r0 == 12u);
        r11 = r0;
        if (r0 == 12u || r11 == 0u) {
            r0 = (uint32_t)half(vf3_aim_h16(a, POOL_BURST_OFFSET));
            r2 = 3u;
            r3 = (uint32_t)byte(vf3_aim_u8(a, task + r0));
            r3 &= 0xffu;
            set_t(a, r3 >= r2);
            vf3_aim_set_u32(a, r15, r3);   /* the delay slot's spill */
            if (r3 >= r2)
                r13 = r7;                  /* zero: the counter is reset */
        } else {
            r0 = (uint32_t)half(vf3_aim_h16(a, POOL_LONG_OFFSET));
            r3 = TASK_PAIR_B;
            r2 = (uint32_t)byte(vf3_aim_u8(a, task + r0));
            r2 &= 0xffu;
            set_t(a, r2 >= r3);
            vf3_aim_set_u32(a, r15, r2);   /* the delay slot's spill */
            if (r2 >= r3)
                r13 = r7;                  /* zero: the counter is reset */
        }
    }
    r0 = r13;
    vf3_aim_set_u16(a, task + TASK_COUNTDOWN, (uint16_t)r0);

    /* ---- the per-call counter at +36 ---- */
    r3 = vf3_aim_u32(a, r5 + 0u);
    set_t(a, (r3 & r12) == 0);
    r13 = r7;
    if ((r3 & r12) != 0) {
        r0 = TASK_PER_CALL;
        r11 = (uint32_t)half(vf3_aim_h16(a, task + r0));
        r11 += 1u;
        r13 = r11;
    }
    r0 = TASK_PER_CALL;
    vf3_aim_set_u16(a, task + r0, (uint16_t)r13);

    /* ---- the rolling counter at +34 ---- */
    r3 = vf3_aim_u32(a, r5 + 0u);
    set_t(a, (r12 & r3) == 0);
    busy = (r12 & r3) == 0;          /* the fighter is not ready: it rolls */
    if (busy) {
        r0 = TASK_ROLL;
        r13 = (uint32_t)half(vf3_aim_h16(a, task + r0));
        r3 = 0x3fu;
        r13 += 1u;
        r3 &= r13;
        set_t(a, (r3 & r3) == 0);
        vf3_aim_set_u32(a, r15, r3);       /* the delay slot's spill */
        r0 = (uint32_t)half(vf3_aim_h16(a, POOL_BURST_OFFSET2));
        r12 = (uint32_t)byte(vf3_aim_u8(a, task + r0));
        r12 &= 0xffu;
        if ((r3 & r3) == 0) {
            r12 += 1u;
            set_u8(a, task + r0, (uint8_t)r12);
        }
        r3 = 1u;
        set_t(a, r12 >= r3);
        if (r12 >= r3) {
            /* the burst byte has reached one: the fighter's own flags and
             * its trigger decide whether the long byte ticks too */
            r2 = vf3_aim_u32(a, r5 + 16u);
            r3 = vf3_aim_u32(a, POOL_GUARD_BIT);
            set_t(a, (r2 & r3) == 0);
            if ((r2 & r3) != 0) {
                r0 = (uint32_t)half(vf3_aim_h16(a, POOL_TRIGGER2));
                r1 = (uint32_t)byte(vf3_aim_u8(a, fighter + r0));
                r0 = FIGHTER_KIND;
                r1 &= 0xffu;
                vf3_aim_set_u32(a, r15, r1);       /* the delay slot's spill */
                r3 = (uint32_t)byte(vf3_aim_u8(a, fighter + r0));
                r3 &= 0xffu;
                vf3_aim_set_u32(a, r15 + 4u, r3);  /* and the one above it */
                r0 = vf3_aim_u32(a, r15);
                set_t(a, r0 == 1u);
                if (r0 == 1u) {
                    r3 = vf3_aim_u32(a, r15 + 4u);
                    set_t(a, (r3 & r3) == 0);
                    if ((r3 & r3) != 0) {
                        r0 = (uint32_t)half(vf3_aim_h16(a, POOL_LONG_OFFSET2));
                        r14 = (uint32_t)byte(vf3_aim_u8(a, task + r0));
                        r14 &= 0xffu;
                        r14 += 1u;
                        set_u8(a, task + r0, (uint8_t)r14);
                    }
                }
            }
        }
        r0 = TASK_ROLL;
        vf3_aim_set_u16(a, task + r0, (uint16_t)r13);
    } else {
        /* the fighter is ready: the counter is cleared once it is high */
        r2 = 7u;
        set_t(a, r13 >= r2);
        if (r13 >= r2) {
            r13 = r7;                  /* zero */
            r0 = TASK_ROLL;
            vf3_aim_set_u16(a, task + r0, (uint16_t)r13);
        }
    }

    /* ---- bit 5: the level, against a threshold the burst byte picks ---- */
    r2 = vf3_aim_u32(a, r5 + 0u);
    r3 = 0xffffffdfu;
    r2 &= r3;
    vf3_aim_set_u32(a, r5 + 0u, r2);
    r2 = 0u;
    r0 = (uint32_t)half(vf3_aim_h16(a, POOL_BURST_OFFSET2));
    r1 = (uint32_t)byte(vf3_aim_u8(a, task + r0));
    r1 &= 0xffu;
    r1 += 0xfffffffdu;
    set_t(a, r1 > r2);
    vf3_aim_set_u32(a, r15, r1);       /* the delay slot's spill */
    r14 = 0x60u;
    if (r1 > r2)
        r14 = 0x23u;
    set_t(a, r13 >= r14);
    if (r13 >= r14) {
        r0 = vf3_aim_u32(a, r5 + 0u);
        r0 |= FLAG_LEVEL;
        vf3_aim_set_u32(a, r5 + 0u, r0);
    }

    /* ---- the three saturating counters ---- */
    r0 = (uint32_t)half(vf3_aim_h16(a, task + TASK_COUNTER_C));
    r5 = r0 & 0xffffu;
    r5 += 0xffffffffu;
    set_t(a, (int32_t)r5 >= 0);
    r6 = r5;
    if ((int32_t)r5 < 0)
        r6 = r7;                        /* zero: the counter stays at zero */
    r0 = r6;
    vf3_aim_set_u16(a, task + TASK_COUNTER_C, (uint16_t)r0);

    r0 = (uint32_t)half(vf3_aim_h16(a, task + TASK_COUNTER_B));
    r5 = r0;
    r5 += 0xffffffffu;
    set_t(a, (int32_t)r5 >= 0);
    r6 = r5;
    if ((int32_t)r5 >= 0) {
        r0 = r6;
        vf3_aim_set_u16(a, task + TASK_COUNTER_B, (uint16_t)r0);
    } else {
        /* the counter at +24 is spent: the one at +20 takes its place */
        r0 = (uint32_t)half(vf3_aim_h16(a, task + TASK_COUNTER_A));
        r5 = r0;
        r5 += 0xffffffffu;
        set_t(a, (int32_t)r5 >= 0);
        r6 = r5;
        if ((int32_t)r5 >= 0) {
            r0 = r6;
            vf3_aim_set_u16(a, task + TASK_COUNTER_A, (uint16_t)r0);
        }
    }

    /* ---- the epilogue: the four saved registers come back ---- */
    r15 += 8u;
    r11 = vf3_aim_u32(a, r15); r15 += 4u;
    r12 = vf3_aim_u32(a, r15); r15 += 4u;
    r13 = vf3_aim_u32(a, r15); r15 += 4u;
    r14 = vf3_aim_u32(a, r15); r15 += 4u;

    R(0) = r0;
    R(1) = r1;
    R(2) = r2;
    R(3) = r3;
    R(5) = r5;
    R(6) = r6;
    R(7) = r7;
    R(11) = r11;
    R(12) = r12;
    R(13) = r13;
    R(14) = r14;
    R(15) = r15;
}
