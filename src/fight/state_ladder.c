/* state_ladder.c - SH-4 0x8C08B89C: the fight-state ladder.
 *
 * This is the second half of the counter updater (0x8C08B7EE, see
 * src/fight/cntup.c): the caller hands it a task struct and a frame, and it
 * does two jobs.
 *
 *   * it **folds the fight's flag words into one word**, the frame's word at
 *     F+0.  Six bits are decided there, each from a different pair of the
 *     caller's words:
 *
 *       bit 1  - the state struct's flags (F+12) carry any of the mask
 *                0x0003d000, or the fighter's flags (F+20) carry 0x00100000;
 *       bit 2  - cleared while the state struct's flags carry neither
 *                0x00020000 nor 0x00008000; then the ladder's own counter in
 *                the state struct (the halfword at the pool's offset) decides
 *                bit 4;
 *       bit 3  - set when the fighter struct's byte at +0x3b is 26;
 *       bit 4  - set when the fighter struct's word at the pool's offset is
 *                zero;
 *       bit 5  - set when the value the two counters below leave behind has
 *                reached a threshold that depends on the task's burst byte.
 *
 *   * it **steps the task's counters**: the per-call counter at A+36, the
 *     pair at A+28 and A+38, the countdown at A+22 (which reloads from the
 *     task's byte at +46 when it runs out), the rolling counter at A+34 (which
 *     ticks the burst byte at A+0x85 and, through it, the byte at A+0x86),
 *     and the three saturating counters at A+30, A+24 and A+20.
 *
 * The frame the guest builds is *its own*: it opens 52 bytes below the four
 * registers it saves, and it fills them from the task struct, from the state
 * struct and from the fighter struct - the two structs the caller's frame
 * points at.  The port reproduces that traffic exactly, because the caller
 * reads the frame back.
 *
 * The literal pool is read at run time, the way the guest reads it: the
 * offsets into the two structs and the six masks are the image's, and this
 * port does not bake them in.  The pool lives in ROM, so a replay has to
 * supply it as a window - see tests/state_ladder_replay.c.
 *
 * Details the port has to keep:
 *
 *   * the **T bit** is the guest's branch condition.  A plain `bf` branches
 *     when the T bit is *clear* and a plain `bt` when it is *set*, so the
 *     tests below read the other way round from what the mask suggests: the
 *     "the mask is absent" case is the one that carries on;
 *   * a **`/s` branch runs its delay slot on both paths**, so the value the
 *     delay slot spills into the guest's scratch word below the saved
 *     registers is written whether the branch is taken or not.  The port
 *     writes those words too - they are the guest's RAM, and the test
 *     compares it;
 *   * the **`shld`** at 0x8C08B8EE shifts the pool's top bit right by the
 *     task's byte at +0x40.  The count is negative, so the shift is a right
 *     shift; a count whose low five bits are zero gives **zero**, not the
 *     value itself;
 *   * the guest's **counter decrements saturate**: a counter that is already
 *     zero stays zero (A+30) or is left alone (A+24 and A+20), and the
 *     countdown at A+22 reloads instead;
 *   * the **return** pops the four saved registers - r14 in the delay slot
 *     of the `rts` - so the caller sees its own r11, r12, r13 and r14 back.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* The guest's literal pool.  Every entry is read from RAM at run time. */
#define POOL_LADDER_COUNTER  0x0c08b9b8u /* the ladder counter's offset in the state struct */
#define POOL_FIGHTER_TRIGGER 0x0c08b9bau /* the trigger's offset in the fighter struct */
#define POOL_LOW_FLAG        0x0c08b9bcu /* mask 0x00001000 */
#define POOL_MID_FLAG        0x0c08b9beu /* mask 0x00004000 */
#define POOL_TOP_BIT         0x0c08b9c0u /* mask 0x80000000 */
#define POOL_FIGHTER_BIT     0x0c08b9c4u /* mask 0x00100000 */
#define POOL_STATE_FLAGS     0x0c08b9c8u /* mask 0x0003d000 */
#define POOL_HIT_FLAG        0x0c08b9ccu /* mask 0x00020000 */
#define POOL_BLOCK_FLAG      0x0c08b9d0u /* mask 0x00008000 */
#define POOL_BURST_OFFSET    0x0c08ba4cu /* the burst byte's offset in the task struct */
#define POOL_LONG_OFFSET     0x0c08ba4eu /* the long byte's offset in the task struct */
#define POOL_BURST_OFFSET2   0x0c08bb08u /* the burst byte's offset, again */
#define POOL_TRIGGER2        0x0c08bb0au /* the second trigger's offset in the fighter struct */
#define POOL_LONG_OFFSET2    0x0c08bb0cu /* the long byte's offset, again */
#define POOL_GUARD_BIT       0x0c08bb10u /* mask 0x00800000 */

/* the task struct's fields */
#define TASK_FLAGS      16u   /* the word the flag word starts from */
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

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
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

int vf3_state_ladder_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
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
    r15 -= 4u; vf3_mem_set_u32(ram, r15, R(14));
    r15 -= 4u; vf3_mem_set_u32(ram, r15, R(13));
    r15 -= 4u; vf3_mem_set_u32(ram, r15, R(12));
    r15 -= 4u; vf3_mem_set_u32(ram, r15, R(11));

    state = vf3_mem_u32(ram, r5 + 0x48u);
    r6 = state;
    r0 = 0x4cu;
    fighter = vf3_mem_u32(ram, r5 + 0x4cu);
    r14 = fighter;
    r0 = 0x61u;

    r3 = vf3_mem_u32(ram, task + TASK_FLAGS);
    r15 -= 8u;                        /* the frame's 52 bytes live here */
    vf3_mem_set_u32(ram, r5 + 0u, r3);

    r2 = vf3_mem_u32(ram, state + 56u);
    vf3_mem_set_u32(ram, r5 + 4u, r2);
    r0 = (uint32_t)byte(vf3_mem_u8(ram, state + r0));
    vf3_mem_set_u8(ram, r5 + 8u, (uint8_t)r0);
    r0 = 0x48u;
    r3 = vf3_mem_u32(ram, state + r0);
    vf3_mem_set_u32(ram, r5 + 12u, r3);
    r2 = vf3_mem_u32(ram, fighter + r0);
    r0 = 0x4cu;
    vf3_mem_set_u32(ram, r5 + 16u, r2);
    r3 = vf3_mem_u32(ram, state + r0);
    vf3_mem_set_u32(ram, r5 + 20u, r3);
    r2 = vf3_mem_u32(ram, fighter + r0);
    r0 = 0x50u;
    vf3_mem_set_u32(ram, r5 + 24u, r2);
    r3 = vf3_mem_u32(ram, state + r0);
    r0 = 0x5cu;
    vf3_mem_set_u32(ram, r5 + 28u, r3);
    r2 = vf3_mem_u32(ram, state);
    vf3_mem_set_u32(ram, r5 + 32u, r2);
    vf3_matrix_load(s, ram, 3, state + r0);   /* fr3: the float at state+0x5c */
    r0 = 0x24u;
    vf3_matrix_store(s, ram, 3, r5 + r0);      /* and its spill into the frame */

    /* the mask the guest builds out of the task's byte at +0x40 */
    r0 = TASK_SHIFT;
    r3 = (uint32_t)byte(vf3_mem_u8(ram, task + r0));
    r3 &= 0xffu;
    vf3_mem_set_u32(ram, r5 + 44u, r3);
    r3 = 0u - r3;
    r2 = vf3_mem_u32(ram, POOL_TOP_BIT);
    r2 = shld(r2, r3);
    r3 = 0xfffffffdu;
    vf3_mem_set_u32(ram, r5 + 48u, r2);

    /* ---- bit 1: the state struct or the fighter says "in hit" ---- */
    r1 = vf3_mem_u32(ram, r5 + 0u);
    r1 &= r3;
    vf3_mem_set_u32(ram, r5 + 0u, r1);

    r1 = vf3_mem_u32(ram, r5 + 12u);
    r2 = vf3_mem_u32(ram, POOL_STATE_FLAGS);
    r7 = vf3_mem_u32(ram, POOL_FIGHTER_BIT);
    set_t(s, (r1 & r2) == 0);
    busy = (r1 & r2) != 0;
    if (!busy) {
        r3 = vf3_mem_u32(ram, r5 + 20u);
        set_t(s, (r3 & r7) == 0);
        busy = (r3 & r7) != 0;
    }
    if (busy) {
        r0 = vf3_mem_u32(ram, r5 + 0u);
        r0 |= FLAG_IN_HIT;
        vf3_mem_set_u32(ram, r5 + 0u, r0);
    }

    /* ---- bit 2 and bit 4: the state struct's flags and the ladder counter ---- */
    r3 = vf3_mem_u32(ram, POOL_HIT_FLAG);
    r13 = vf3_mem_u32(ram, r5 + 12u);
    set_t(s, (r3 & r13) == 0);
    busy = (r3 & r13) != 0;
    if (!busy) {
        r2 = vf3_mem_u32(ram, POOL_BLOCK_FLAG);
        set_t(s, (r2 & r13) == 0);
        busy = (r2 & r13) != 0;
        if (!busy) {
            /* the flag is quiet: clear bit 2 and ask the ladder's counter */
            r1 = vf3_mem_u32(ram, r5 + 0u);
            r3 = 0xfffffffbu;
            r1 &= r3;
            vf3_mem_set_u32(ram, r5 + 0u, r1);
            r1 = 1u;
            r0 = (uint32_t)half(vf3_mem_u16(ram, POOL_LADDER_COUNTER));
            r2 = (uint32_t)half(vf3_mem_u16(ram, state + r0));
            set_t(s, (int32_t)r2 >= (int32_t)r1);
            vf3_mem_set_u32(ram, r15, r2);   /* the delay slot's spill */
            if ((int32_t)r2 >= (int32_t)r1) {
                r3 = vf3_mem_u32(ram, POOL_TOP_BIT);
                set_t(s, (r13 & r3) == 0);
                busy = (r13 & r3) != 0;
            }
        }
    }
    if (busy) {
        r0 = vf3_mem_u32(ram, r5 + 0u);
        r0 |= FLAG_CLEARED;
        vf3_mem_set_u32(ram, r5 + 0u, r0);
    }

    /* ---- bit 3: the fighter's byte at +0x3b ---- */
    r1 = r14 + 0x38u;
    r2 = vf3_mem_u32(ram, r5 + 0u);
    r3 = 0xfffffff7u;
    r2 &= r3;
    vf3_mem_set_u32(ram, r5 + 0u, r2);
    r0 = (uint32_t)byte(vf3_mem_u8(ram, r1 + 3u));
    r0 &= 0xffu;
    set_t(s, r0 == 26u);
    vf3_mem_set_u32(ram, r15, r0);       /* the delay slot's spill */
    if (r0 == 26u) {
        r0 = vf3_mem_u32(ram, r5 + 0u);
        r0 |= FLAG_STAGE;
        vf3_mem_set_u32(ram, r5 + 0u, r0);
    }

    /* ---- bit 4: the fighter's word at the pool's offset ---- */
    r2 = vf3_mem_u32(ram, r5 + 0u);
    r3 = 0xffffffefu;
    r2 &= r3;
    vf3_mem_set_u32(ram, r5 + 0u, r2);
    r0 = (uint32_t)half(vf3_mem_u16(ram, POOL_FIGHTER_TRIGGER));
    r1 = vf3_mem_u32(ram, r14 + r0);
    r2 = r1;
    set_t(s, (r2 & r2) == 0);
    vf3_mem_set_u32(ram, r15, r1);       /* the delay slot's spill */
    r12 = 0x10u;
    if (r1 == 0) {
        r2 = vf3_mem_u32(ram, r5 + 0u);
        r2 |= r12;
        vf3_mem_set_u32(ram, r5 + 0u, r2);
    }

    /* ---- the task's counter at +32: it ticks when the fighter is busy ----
     * The guest reaches the frame's word at +32 either because the fighter's
     * own word carries its bit, or - when it does not - because the state
     * struct's word carries the low bit. */
    r3 = vf3_mem_u32(ram, r5 + 20u);
    set_t(s, (r3 & r7) == 0);
    busy = (r3 & r7) != 0;
    if (!busy) {
        r2 = vf3_mem_u32(ram, r5 + 12u);
        r3 = (uint32_t)half(vf3_mem_u16(ram, POOL_LOW_FLAG));
        set_t(s, (r2 & r3) == 0);
        busy = (r2 & r3) != 0;
    }
    if (busy) {
        r1 = vf3_mem_u32(ram, r5 + 32u);
        set_t(s, (r7 & r1) == 0);
        if ((r7 & r1) != 0) {
            r0 = TASK_COUNTER_D;
            r7 = (uint32_t)half(vf3_mem_u16(ram, task + r0));
            r7 &= 0xffffu;
            r7 += 1u;
            vf3_mem_set_u16(ram, task + r0, (uint16_t)r7);
        }
    }

    /* ---- the pair at +28 and +38 ---- */
    r0 = (uint32_t)half(vf3_mem_u16(ram, task + TASK_PAIR_A));
    r3 = (uint32_t)half(vf3_mem_u16(ram, POOL_MID_FLAG));
    r13 = r0;
    r2 = vf3_mem_u32(ram, r5 + 12u);
    r0 = TASK_PAIR_B;
    r11 = (uint32_t)half(vf3_mem_u16(ram, task + r0));
    set_t(s, (r2 & r3) == 0);
    r7 = 0u;
    if ((r2 & r3) == 0) {
        /* the state struct is quiet: the flag word decides */
        r0 = vf3_mem_u32(ram, r5 + 0u);
        set_t(s, (r0 & FLAG_IN_HIT) == 0);
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
    vf3_mem_set_u16(ram, task + TASK_PAIR_A, (uint16_t)r0);
    r0 = TASK_PAIR_B;
    vf3_mem_set_u16(ram, task + r0, (uint16_t)r11);

    /* ---- the countdown at +22: it counts down and reloads ---- */
    r0 = (uint32_t)half(vf3_mem_u16(ram, task + TASK_COUNTDOWN));
    r11 = r0 & 0xffffu;
    r11 += 0xffffffffu;
    set_t(s, (int32_t)r11 >= 0);
    r13 = r11;
    if ((int32_t)r11 < 0) {
        /* the countdown ran out: the reload value and the fighter's kind
         * decide whether the counter is reset or set to the reload value */
        r0 = TASK_RELOAD;
        r13 = (uint32_t)byte(vf3_mem_u8(ram, task + r0));
        r0 = FIGHTER_KIND;
        r11 = (uint32_t)byte(vf3_mem_u8(ram, fighter + r0));
        r13 &= 0xffu;
        r0 = r11 & 0xffu;
        set_t(s, r0 == 12u);
        r11 = r0;
        if (r0 == 12u || r11 == 0u) {
            r0 = (uint32_t)half(vf3_mem_u16(ram, POOL_BURST_OFFSET));
            r2 = 3u;
            r3 = (uint32_t)byte(vf3_mem_u8(ram, task + r0));
            r3 &= 0xffu;
            set_t(s, r3 >= r2);
            vf3_mem_set_u32(ram, r15, r3);   /* the delay slot's spill */
            if (r3 >= r2)
                r13 = r7;                  /* zero: the counter is reset */
        } else {
            r0 = (uint32_t)half(vf3_mem_u16(ram, POOL_LONG_OFFSET));
            r3 = TASK_PAIR_B;
            r2 = (uint32_t)byte(vf3_mem_u8(ram, task + r0));
            r2 &= 0xffu;
            set_t(s, r2 >= r3);
            vf3_mem_set_u32(ram, r15, r2);   /* the delay slot's spill */
            if (r2 >= r3)
                r13 = r7;                  /* zero: the counter is reset */
        }
    }
    r0 = r13;
    vf3_mem_set_u16(ram, task + TASK_COUNTDOWN, (uint16_t)r0);

    /* ---- the per-call counter at +36 ---- */
    r3 = vf3_mem_u32(ram, r5 + 0u);
    set_t(s, (r3 & r12) == 0);
    r13 = r7;
    if ((r3 & r12) != 0) {
        r0 = TASK_PER_CALL;
        r11 = (uint32_t)half(vf3_mem_u16(ram, task + r0));
        r11 += 1u;
        r13 = r11;
    }
    r0 = TASK_PER_CALL;
    vf3_mem_set_u16(ram, task + r0, (uint16_t)r13);

    /* ---- the rolling counter at +34 ---- */
    r3 = vf3_mem_u32(ram, r5 + 0u);
    set_t(s, (r12 & r3) == 0);
    busy = (r12 & r3) == 0;          /* the fighter is not ready: it rolls */
    if (busy) {
        r0 = TASK_ROLL;
        r13 = (uint32_t)half(vf3_mem_u16(ram, task + r0));
        r3 = 0x3fu;
        r13 += 1u;
        r3 &= r13;
        set_t(s, (r3 & r3) == 0);
        vf3_mem_set_u32(ram, r15, r3);       /* the delay slot's spill */
        r0 = (uint32_t)half(vf3_mem_u16(ram, POOL_BURST_OFFSET2));
        r12 = (uint32_t)byte(vf3_mem_u8(ram, task + r0));
        r12 &= 0xffu;
        if ((r3 & r3) == 0) {
            r12 += 1u;
            vf3_mem_set_u8(ram, task + r0, (uint8_t)r12);
        }
        r3 = 1u;
        set_t(s, r12 >= r3);
        if (r12 >= r3) {
            /* the burst byte has reached one: the fighter's own flags and
             * its trigger decide whether the long byte ticks too */
            r2 = vf3_mem_u32(ram, r5 + 16u);
            r3 = vf3_mem_u32(ram, POOL_GUARD_BIT);
            set_t(s, (r2 & r3) == 0);
            if ((r2 & r3) != 0) {
                r0 = (uint32_t)half(vf3_mem_u16(ram, POOL_TRIGGER2));
                r1 = (uint32_t)byte(vf3_mem_u8(ram, fighter + r0));
                r0 = FIGHTER_KIND;
                r1 &= 0xffu;
                vf3_mem_set_u32(ram, r15, r1);       /* the delay slot's spill */
                r3 = (uint32_t)byte(vf3_mem_u8(ram, fighter + r0));
                r3 &= 0xffu;
                vf3_mem_set_u32(ram, r15 + 4u, r3);  /* and the one above it */
                r0 = vf3_mem_u32(ram, r15);
                set_t(s, r0 == 1u);
                if (r0 == 1u) {
                    r3 = vf3_mem_u32(ram, r15 + 4u);
                    set_t(s, (r3 & r3) == 0);
                    if ((r3 & r3) != 0) {
                        r0 = (uint32_t)half(vf3_mem_u16(ram, POOL_LONG_OFFSET2));
                        r14 = (uint32_t)byte(vf3_mem_u8(ram, task + r0));
                        r14 &= 0xffu;
                        r14 += 1u;
                        vf3_mem_set_u8(ram, task + r0, (uint8_t)r14);
                    }
                }
            }
        }
        r0 = TASK_ROLL;
        vf3_mem_set_u16(ram, task + r0, (uint16_t)r13);
    } else {
        /* the fighter is ready: the counter is cleared once it is high */
        r2 = 7u;
        set_t(s, r13 >= r2);
        if (r13 >= r2) {
            r13 = r7;                  /* zero */
            r0 = TASK_ROLL;
            vf3_mem_set_u16(ram, task + r0, (uint16_t)r13);
        }
    }

    /* ---- bit 5: the level, against a threshold the burst byte picks ---- */
    r2 = vf3_mem_u32(ram, r5 + 0u);
    r3 = 0xffffffdfu;
    r2 &= r3;
    vf3_mem_set_u32(ram, r5 + 0u, r2);
    r2 = 0u;
    r0 = (uint32_t)half(vf3_mem_u16(ram, POOL_BURST_OFFSET2));
    r1 = (uint32_t)byte(vf3_mem_u8(ram, task + r0));
    r1 &= 0xffu;
    r1 += 0xfffffffdu;
    set_t(s, r1 > r2);
    vf3_mem_set_u32(ram, r15, r1);       /* the delay slot's spill */
    r14 = 0x60u;
    if (r1 > r2)
        r14 = 0x23u;
    set_t(s, r13 >= r14);
    if (r13 >= r14) {
        r0 = vf3_mem_u32(ram, r5 + 0u);
        r0 |= FLAG_LEVEL;
        vf3_mem_set_u32(ram, r5 + 0u, r0);
    }

    /* ---- the three saturating counters ---- */
    r0 = (uint32_t)half(vf3_mem_u16(ram, task + TASK_COUNTER_C));
    r5 = r0 & 0xffffu;
    r5 += 0xffffffffu;
    set_t(s, (int32_t)r5 >= 0);
    r6 = r5;
    if ((int32_t)r5 < 0)
        r6 = r7;                        /* zero: the counter stays at zero */
    r0 = r6;
    vf3_mem_set_u16(ram, task + TASK_COUNTER_C, (uint16_t)r0);

    r0 = (uint32_t)half(vf3_mem_u16(ram, task + TASK_COUNTER_B));
    r5 = r0;
    r5 += 0xffffffffu;
    set_t(s, (int32_t)r5 >= 0);
    r6 = r5;
    if ((int32_t)r5 >= 0) {
        r0 = r6;
        vf3_mem_set_u16(ram, task + TASK_COUNTER_B, (uint16_t)r0);
    } else {
        /* the counter at +24 is spent: the one at +20 takes its place */
        r0 = (uint32_t)half(vf3_mem_u16(ram, task + TASK_COUNTER_A));
        r5 = r0;
        r5 += 0xffffffffu;
        set_t(s, (int32_t)r5 >= 0);
        r6 = r5;
        if ((int32_t)r5 >= 0) {
            r0 = r6;
            vf3_mem_set_u16(ram, task + TASK_COUNTER_A, (uint16_t)r0);
        }
    }

    /* ---- the epilogue: the four saved registers come back ---- */
    r15 += 8u;
    r11 = vf3_mem_u32(ram, r15); r15 += 4u;
    r12 = vf3_mem_u32(ram, r15); r15 += 4u;
    r13 = vf3_mem_u32(ram, r15); r15 += 4u;
    {
        const uint32_t target = R(16);
        r14 = vf3_mem_u32(ram, r15); r15 += 4u;
        s->pc = target;
    }

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
    return ram->oob == 0;
}
