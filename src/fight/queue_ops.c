/* queue_ops.c - SH-4 0x8C038570 / 0x8C038590 / 0x8C0385C0: the fight engine's
 * queue of two parallel words.
 *
 * Three small functions share one struct and two global arrays:
 *
 *   0x8C038570  the **reset**: it empties the queue and seeds the struct with
 *               the arrays' first slots;
 *   0x8C038590  the **push**: it appends the struct's two words to the arrays,
 *               and refuses when the queue is full;
 *   0x8C0385C0  the **pop**: it takes the arrays' last slots back into the
 *               struct, and refuses when the queue is empty.
 *
 * The struct lives at a global's address, so the pool holds the *address* of
 * the struct and the *address* of each array.  All three are read from RAM at
 * run time, the way the guest reads them.
 *
 * The queue's shape:
 *
 *   * the **counter** is the halfword at the struct's offset 6.  It counts the
 *     entries, and the arrays are addressed from one: a push writes at the
 *     counter's *new* value, a pop reads at the counter's old one;
 *   * the queue holds **48** entries - that is the limit the push compares the
 *     counter against, and the arrays are 48 words long;
 *   * the struct keeps the two words it is carrying at its offsets 44 and 56,
 *     and a duplicate of each at 48 and 60.  The pop writes 44 and 56 only;
 *     the duplicates keep the values they had.
 *
 * Details the port has to keep:
 *
 *   * the **T bit** is the guest's branch condition and the guest leaves it
 *     behind.  The push compares the counter with the limit and the pop compares
 *     it with zero, and the bit the port leaves has to be the bit the guest
 *     left - the reset computes no comparison at all and must not touch it;
 *   * the push's comparison is `cmp/ge r3,r5`, so the T bit is (counter >=
 *     limit): the queue is full once the counter has *reached* the limit, not
 *     once it has passed it.  The corpus' own SR settles the direction - a push
 *     out of an empty queue takes it from 0x60000001 to 0x60000000;
 *   * the two arrays are **48 words apart**, so the first array's slot 48 *is*
 *     the second array's slot 0, and the queue's last slot aliases it;
 *   * a **`/s` branch runs its delay slot on both paths**, so the value the
 *     delay slot spills into r6 (the push) or r5 (the pop) is written whether
 *     the branch is taken or not;
 *   * the **halfword** the counter is read from is sign extended, and the
 *     counter is stored back as a halfword;
 *   * the **return** puts the answer in r0 through the delay slot of the `rts`
 *     - r6 for the push, r5 for the pop - so the port has to leave those two
 *     registers as the guest left them.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* The guest's literal pool.  Every entry is an address and is read at run time. */
#define POOL_STRUCT 0x0c0385f0u /* the address of the queue's struct */
#define POOL_ARRAY1 0x0c0385f4u /* the address of the first array */
#define POOL_ARRAY2 0x0c0385f8u /* the address of the second array */

/* the guest's own immediate: the queue's capacity */
#define QUEUE_LIMIT 48u

/* the struct's fields */
#define FIELD_COUNT 6u   /* the halfword: how many entries the queue holds */
#define FIELD_A     44u  /* the word the first array carries */
#define FIELD_A2    48u  /* its duplicate */
#define FIELD_B     56u  /* the word the second array carries */
#define FIELD_B2    60u  /* its duplicate */

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

/* the guest's halfword: sixteen bits, sign extended */
static uint32_t half(uint32_t v)
{
    return (uint32_t)(int32_t)(int16_t)(uint16_t)v;
}

/* 0x8C038570 - the reset.
 *
 * The counter goes back to zero and the struct takes the arrays' first slots:
 * the first array's into the struct's words at 44 and 48, the second array's
 * into the words at 56 and 60.  The last of those four stores is the delay
 * slot of the `rts`, so it happens before the function returns. */
int vf3_queue_reset_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(4) = vf3_mem_u32(ram, POOL_STRUCT);
    R(0) = 0u;
    vf3_mem_set_u16(ram, R(4) + FIELD_COUNT, (uint16_t)R(0));

    R(5) = vf3_mem_u32(ram, POOL_ARRAY1);
    R(5) = vf3_mem_u32(ram, R(5));
    vf3_mem_set_u32(ram, R(4) + FIELD_A, R(5));
    vf3_mem_set_u32(ram, R(4) + FIELD_A2, R(5));

    R(5) = vf3_mem_u32(ram, POOL_ARRAY2);
    R(5) = vf3_mem_u32(ram, R(5));
    vf3_mem_set_u32(ram, R(4) + FIELD_B, R(5));
    vf3_mem_set_u32(ram, R(4) + FIELD_B2, R(5));

    s->pc = R(16);
    return ram->oob == 0;
}

/* 0x8C038590 - the push.
 *
 * The queue is full when the counter has reached the limit, and then the push
 * answers -1 without touching anything.  Otherwise the counter goes up by one,
 * the struct's two words go into the arrays at the counter's new value, and
 * the answer is 0. */
int vf3_queue_push_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(4) = vf3_mem_u32(ram, POOL_STRUCT);
    R(3) = QUEUE_LIMIT;
    R(0) = half(vf3_mem_u16(ram, R(4) + FIELD_COUNT));
    R(5) = R(0);

    /* cmp/ge r3,r5: T = (r5 >= r3), so the queue is full once the counter
     * has *reached* the limit - the corpus' own SR goes 0x60000001 to
     * 0x60000000 on a push out of an empty queue. */
    set_t(s, (int32_t)R(5) >= (int32_t)R(3));
    R(6) = 0xffffffffu;             /* the delay slot, on both paths */

    if (R(17) & 1u) {
        /* the queue is full */
        R(0) = R(6);                 /* the delay slot of the `rts` */
        s->pc = R(16);
        return ram->oob == 0;
    }

    R(5) += 1u;
    R(0) = R(5);
    vf3_mem_set_u16(ram, R(4) + FIELD_COUNT, (uint16_t)R(0));

    R(0) = vf3_mem_u32(ram, POOL_ARRAY1);
    R(5) <<= 2;
    R(2) = vf3_mem_u32(ram, R(4) + FIELD_A);
    R(6) = R(5);
    vf3_mem_set_u32(ram, R(0) + R(5), R(2));

    R(2) = vf3_mem_u32(ram, R(4) + FIELD_B);
    R(0) = vf3_mem_u32(ram, POOL_ARRAY2);
    vf3_mem_set_u32(ram, R(0) + R(6), R(2));

    R(6) = 0u;
    R(0) = R(6);                     /* the delay slot of the `rts` */
    s->pc = R(16);
    return ram->oob == 0;
}

/* 0x8C0385C0 - the pop.
 *
 * The queue is empty when the counter is not above zero, and then the pop
 * answers -1 without touching anything.  Otherwise the arrays' slots at the
 * counter's value come back into the struct, the counter goes down by one, and
 * the answer is 0. */
int vf3_queue_pop_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(4) = vf3_mem_u32(ram, POOL_STRUCT);
    R(0) = half(vf3_mem_u16(ram, R(4) + FIELD_COUNT));
    R(1) = R(0);

    /* cmp/gt: the queue is empty when the counter is not above zero */
    set_t(s, (int32_t)R(1) > 0);
    R(5) = 0xffffffffu;             /* the delay slot, on both paths */

    if (!(R(17) & 1u)) {
        /* the queue is empty */
        R(0) = R(5);                 /* the delay slot of the `rts` */
        s->pc = R(16);
        return ram->oob == 0;
    }

    R(0) = vf3_mem_u32(ram, POOL_ARRAY2);
    R(5) = R(1);
    R(5) <<= 2;
    R(3) = vf3_mem_u32(ram, R(0) + R(5));
    vf3_mem_set_u32(ram, R(4) + FIELD_B, R(3));

    R(0) = vf3_mem_u32(ram, POOL_ARRAY1);
    R(3) = vf3_mem_u32(ram, R(0) + R(5));
    R(0) = R(1);
    R(0) += 0xffffffffu;            /* the counter goes down by one */
    R(5) = 0u;
    vf3_mem_set_u32(ram, R(4) + FIELD_A, R(3));
    vf3_mem_set_u16(ram, R(4) + FIELD_COUNT, (uint16_t)R(0));

    R(0) = R(5);                     /* the delay slot of the `rts` */
    s->pc = R(16);
    return ram->oob == 0;
}
