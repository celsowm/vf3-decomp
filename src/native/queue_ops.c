/* queue_ops.c - SH-4 0x8C038570 / 0x8C038590 / 0x8C0385C0: the fight engine's
 * queue of two parallel words, natively.
 *
 * Plain-C transcriptions of the readable port src/fight/queue_ops.c
 * (`vf3_queue_reset_entry` / `vf3_queue_push_entry` / `vf3_queue_pop_entry`).
 * They operate on `vf3_native_aim`: the flat RAM and the register file.
 * Self-contained integer leaves (call-free, no FP, no stack frame), so there
 * are no guest callees to inline and no FPU wrappers.
 *
 * The three share one struct and two global arrays, whose addresses the
 * literal pool holds (0x0c0385f0 -> the struct, 0x0c0385f4 -> the first
 * array, 0x0c0385f8 -> the second).  The struct's halfword at +6 is the
 * counter; the words at 44/48 and 56/60 carry the pair the arrays hold; the
 * capacity is 48.
 *
 *   reset  - the counter goes back to zero and the struct takes the arrays'
 *            first slots (their values at +0);
 *   push   - the counter goes up by one and the struct's two words go into
 *            the arrays at the new value; refuses -1 once the counter has
 *            reached the limit;
 *   pop    - the arrays' slots at the old value come back into the struct (44
 *            and 56 only; the duplicates 48 and 60 keep their values) and the
 *            counter goes down by one; refuses -1 when the counter is not
 *            above zero.
 *
 * All three tail-transfer to pr, so the C ports leave pr untouched and simply
 * return.  See docs/re/native_queue_ops.md. */
#include "queue_ops.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

/* the guest's literal pool slots, read at run time */
#define POOL_STRUCT 0x0c0385f0u
#define POOL_ARRAY1 0x0c0385f4u
#define POOL_ARRAY2 0x0c0385f8u

/* the guest's own immediate: the queue's capacity */
#define QUEUE_LIMIT 48u

/* the struct's fields */
#define FIELD_COUNT 6u
#define FIELD_A     44u
#define FIELD_A2    48u
#define FIELD_B     56u
#define FIELD_B2    60u

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (uint32_t)(value != 0);
}

/* the guest's halfword: sixteen bits, sign extended */
static uint32_t half(vf3_native_aim *a, uint32_t addr)
{
    return (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, addr);
}

void vf3_native_queue_reset(vf3_native_aim *a)
{
    R(4) = vf3_aim_u32(a, POOL_STRUCT);
    R(0) = 0u;
    vf3_aim_set_u16(a, R(4) + FIELD_COUNT, (uint16_t)R(0));

    R(5) = vf3_aim_u32(a, POOL_ARRAY1);
    R(5) = vf3_aim_u32(a, R(5));
    vf3_aim_set_u32(a, R(4) + FIELD_A, R(5));
    vf3_aim_set_u32(a, R(4) + FIELD_A2, R(5));

    R(5) = vf3_aim_u32(a, POOL_ARRAY2);
    R(5) = vf3_aim_u32(a, R(5));
    vf3_aim_set_u32(a, R(4) + FIELD_B, R(5));
    vf3_aim_set_u32(a, R(4) + FIELD_B2, R(5));

    /* tail-transfer to pr: the C return leaves pr untouched */
}

void vf3_native_queue_push(vf3_native_aim *a)
{
    R(4) = vf3_aim_u32(a, POOL_STRUCT);
    R(3) = QUEUE_LIMIT;
    R(0) = half(a, R(4) + FIELD_COUNT);
    R(5) = R(0);

    /* cmp/ge r3,r5: T = (r5 >= r3), so the queue is full once the counter
     * has *reached* the limit. */
    set_t(a, (int32_t)R(5) >= (int32_t)R(3));
    R(6) = 0xffffffffu;             /* the delay slot, on both paths */

    if (a->sr & 1u) {
        /* the queue is full */
        R(0) = R(6);                 /* the delay slot of the `rts` */
        return;
    }

    R(5) += 1u;
    R(0) = R(5);
    vf3_aim_set_u16(a, R(4) + FIELD_COUNT, (uint16_t)R(0));

    R(0) = vf3_aim_u32(a, POOL_ARRAY1);
    R(5) <<= 2;
    R(2) = vf3_aim_u32(a, R(4) + FIELD_A);
    R(6) = R(5);
    vf3_aim_set_u32(a, R(0) + R(5), R(2));

    R(2) = vf3_aim_u32(a, R(4) + FIELD_B);
    R(0) = vf3_aim_u32(a, POOL_ARRAY2);
    vf3_aim_set_u32(a, R(0) + R(6), R(2));

    R(6) = 0u;
    R(0) = R(6);                     /* the delay slot of the `rts` */
}

void vf3_native_queue_pop(vf3_native_aim *a)
{
    R(4) = vf3_aim_u32(a, POOL_STRUCT);
    R(0) = half(a, R(4) + FIELD_COUNT);
    R(1) = R(0);

    /* cmp/gt: the queue is empty when the counter is not above zero */
    set_t(a, (int32_t)R(1) > 0);
    R(5) = 0xffffffffu;             /* the delay slot, on both paths */

    if (!(a->sr & 1u)) {
        /* the queue is empty */
        R(0) = R(5);                 /* the delay slot of the `rts` */
        return;
    }

    R(0) = vf3_aim_u32(a, POOL_ARRAY2);
    R(5) = R(1);
    R(5) <<= 2;
    R(3) = vf3_aim_u32(a, R(0) + R(5));
    vf3_aim_set_u32(a, R(4) + FIELD_B, R(3));

    R(0) = vf3_aim_u32(a, POOL_ARRAY1);
    R(3) = vf3_aim_u32(a, R(0) + R(5));
    R(0) = R(1);
    R(0) += 0xffffffffu;            /* the counter goes down by one */
    R(5) = 0u;
    vf3_aim_set_u32(a, R(4) + FIELD_A, R(3));
    vf3_aim_set_u16(a, R(4) + FIELD_COUNT, (uint16_t)R(0));

    R(0) = R(5);                     /* the delay slot of the `rts` */
}
