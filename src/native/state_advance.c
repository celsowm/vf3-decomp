/* state_advance.c - SH-4 0x8C06BEA4: the entry counter steps forward, and the
 * kind flags are told about it, natively.
 *
 * A plain-C transcription of the readable port src/fight/state_advance.c
 * (`vf3_state_advance_entry`).  It operates on `vf3_native_aim`: the flat RAM
 * and the register file.  A self-contained leaf - it calls nobody and uses no
 * FPU, but it keeps a **frame** on the guest stack: it saves r12/r13/r14 at
 * sp-4/-8/-12 and restores them (r14 in the delay slot of the return).
 *
 * The function is handed two words - r4 (an entry counter, of which only the
 * low four bits are used) and r5 (a count) - and a kind in r6.  The counter
 * steps forward by one and wraps at sixteen, so the sequence the word holds is
 * 1, 2, ... 15, 0, 1, ...
 *
 * When the counter is at zero the guest does not step it: it counts down
 * instead.  With a count left the counter restarts at one and the count goes
 * down by one; with the count at zero the counter stays at zero and the count
 * stays at zero.  So the count is spent once per lap of the counter.
 *
 * The kind flags are a byte somewhere in memory: the pointer to it is in the
 * literal pool (0x0c06bfbc).  A table in the pool (0x0c06bfc0) says what kind
 * the current entry is - the byte at the counter's position.  The guest masks
 * the flags with the mask of the kind it is about (0x0c06bfac for the first
 * kind, 0x0c06bfae for the second), and sets that kind's bit if - and only if -
 * the table has a non-zero byte there.  The other kind's bit survives the mask.
 * On the counting path the flags are left alone.
 *
 * Three details the port keeps: the counter is masked to four bits before it is
 * used, but the value written back is the *masked* counter plus one, masked
 * again - so the high bits the word may have held are dropped; the flags byte is
 * read *signed* and the mask comes from the pool as a signed halfword, so both
 * are sign extended before they are and-ed; and the saved r14 comes back in the
 * delay slot of the return.
 *
 * See docs/re/native_state_advance.md. */
#include "state_advance.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

/* byte writer (the native aim API has set_u16/set_u32 but no set_u8) */
static inline void w8(vf3_native_aim *a, uint32_t addr, uint8_t v)
{ ((uint8_t *)a->ram)[addr - a->ram_base] = v; }

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* the literal pool */
#define MASK_A    0x0c06bfacu   /* the mask for the first kind  (a halfword) */
#define MASK_B    0x0c06bfaeu   /* the mask for the second kind (a halfword) */
#define FLAGS_PTR 0x0c06bfbcu   /* the word that points at the flags byte */
#define TABLE_PTR 0x0c06bfc0u   /* the word that points at the table */

/* the bit each kind owns in the flags byte */
#define KIND_A 1u
#define KIND_B 2u

/* the counter only has four bits */
#define COUNTER_BITS 15u

void vf3_native_state_advance(vf3_native_aim *a)
{
    const uint32_t sp = R(15);

    /* the guest saves r14, r13 and r12 */
    vf3_aim_set_u32(a, sp - 4u, R(14));
    vf3_aim_set_u32(a, sp - 8u, R(13));
    vf3_aim_set_u32(a, sp - 12u, R(12));
    R(15) = sp - 12u;

    /* the entry counter, the pointer to the flags and the count */
    R(7) = vf3_aim_u32(a, R(4));
    R(3) = vf3_aim_u32(a, FLAGS_PTR);
    R(2) = COUNTER_BITS;
    R(7) &= R(2);
    R(13) = vf3_aim_u32(a, R(5));

    /* the flags the guest starts from */
    R(14) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(3));

    /* the counter decides which way the guest goes */
    const int at_zero = (R(7) == 0);
    set_t(a, at_zero);
    R(12) = R(7);
    R(12) += 1u;                    /* the delay slot: it runs on both paths */

    if (at_zero) {
        /* the count runs down, and the counter waits for the next lap */
        set_t(a, R(13) == 0);
        if (R(13) != 0) {
            R(13) += 0xffffffffu;  /* the guest's "add #-1" */
            R(7) = R(12);          /* the delay slot of the branch */
        }
    } else {
        /* the table says what kind the current entry is */
        R(0) = vf3_aim_u32(a, TABLE_PTR);
        const int first_kind = (R(6) == 0);
        set_t(a, first_kind);
        R(2) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(0) + R(7));
        R(7) = R(2) & 0xffu;        /* the delay slot: the byte, unsigned */

        /* the mask of the kind this call is about */
        uint32_t mask;
        if (first_kind) {
            R(2) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, MASK_A);
            mask = R(2);
        } else {
            R(1) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, MASK_B);
            mask = R(1);
        }

        /* the table has to say something for the kind's bit to go in */
        const int known = (R(7) != 0);
        set_t(a, !known);
        R(14) &= mask;              /* the delay slot of the branch */
        if (known) {
            R(3) = first_kind ? KIND_A : KIND_B;
            R(14) |= R(3);
        }

        /* the flags go back, and the counter steps forward */
        R(2) = vf3_aim_u32(a, FLAGS_PTR);
        R(3) = COUNTER_BITS;
        R(7) = R(12);
        R(7) &= R(3);
        w8(a, R(2), (uint8_t)R(14));
    }

    /* the counter and the count go back where they came from */
    vf3_aim_set_u32(a, R(4), R(7));
    vf3_aim_set_u32(a, R(5), R(13));

    /* the saved registers come back: r12 and r13 by their own instructions,
     * r14 in the delay slot of the return */
    R(12) = vf3_aim_u32(a, R(15));
    R(15) += 4u;
    R(13) = vf3_aim_u32(a, R(15));
    R(15) += 4u;
    R(14) = vf3_aim_u32(a, R(15));
    R(15) += 4u;
}
