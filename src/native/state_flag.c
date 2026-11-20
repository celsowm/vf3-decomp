/* state_flag.c - SH-4 0x8C0B0FD2: the fight engine's state flag, natively.
 *
 * A plain-C transcription of the readable port src/fight/state_flag.c
 * (`vf3_state_flag_entry`).  It operates on `vf3_native_aim`: the flat RAM and
 * the register file.  A self-contained integer leaf - it calls nobody, uses
 * no FPU and keeps **no stack frame**, but it reads the literal pool, the
 * state word and the T bit.
 *
 * The function sets **one of two bits** in a word it finds through r7 - a word
 * that belongs to the fight engine's state.  Which bit it sets depends on two
 * things: the band the value falls into, and one parity bit.
 *
 * The value comes out of a structure the caller hands over in r5: a halfword
 * at the offset the pool names (0x0c0b1070).  The guest subtracts r6 from it
 * and flips the sign bit with the pool's xor constant (0x0c0b1098), so the
 * value is signed and, in the game's own numbers, roughly the negated
 * difference between the halfword and r6.
 *
 * The bands are two, and they are mirror images of each other:
 *
 *   * the **middle band**, from the pool's middle bound (0x0c0b1074) up to
 *     the pool's low bound (0x0c0b1072) - both negative, -27300 to -5460 in
 *     the game's own pool;
 *   * the **high band**, from the pool's high bound (0x0c0b1078) up to the
 *     pool's second high bound (0x0c0b107a) - the same numbers, positive.
 *
 * A value between the two bands is in neither, and the function leaves the
 * word alone.  So does a value outside both bands.
 *
 * The parity bit is the low bit of two words the guest shifts out of the
 * structure r4 points at: the first word shifted right by 25 and the second
 * one - 72 bytes further on - shifted right by 10, and the two exclusive-ored.
 *
 * The two bands answer the **opposite way round**: in the middle band a zero
 * parity bit sets the low bit and a set one sets the high bit; in the high
 * band it is the other way round.  The gate's mask (0x0c0b1094) decides
 * whether anything happens at all: when the state word carries any of the
 * mask's bits the function does nothing - it does not even write the word
 * back.
 *
 * See docs/re/native_state_flag.md. */
#include "state_flag.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* the literal pool, read at run time */
#define POOL_TABLE    0x0c0b1070u
#define POOL_LOW      0x0c0b1072u
#define POOL_MID      0x0c0b1074u
#define POOL_BIT_LOW  0x0c0b1076u
#define POOL_HIGH     0x0c0b1078u
#define POOL_HIGH2    0x0c0b107au
#define POOL_BIT_HIGH 0x0c0b107cu
#define POOL_MASK     0x0c0b1094u
#define POOL_XOR      0x0c0b1098u

#define WORD_OFFSET 72u
#define COUNT_FIRST  0xffffffe7u   /* -25 */
#define COUNT_SECOND 0xfffffff6u   /* -10 */

static uint32_t sext16(uint32_t value)
{
    return (uint32_t)(int32_t)(int16_t)(uint16_t)value;
}

static uint32_t asr(uint32_t value, unsigned bits)
{
    if (bits == 0u) return value;
    if (value & 0x80000000u) return (value >> bits) | ~(0xffffffffu >> bits);
    return value >> bits;
}

static uint32_t shad(uint32_t value, uint32_t count)
{
    if (count & 0x80000000u) {
        const unsigned bits = (0u - count) & 31u;
        if (bits == 0u) return (value & 0x80000000u) ? 0xffffffffu : 0u;
        return asr(value, bits);
    }
    return value << (count & 31u);
}

static int32_t half(vf3_native_aim *a, uint32_t addr)
{
    return (int32_t)(int16_t)vf3_aim_h16(a, addr);
}

void vf3_native_state_flag(vf3_native_aim *a)
{
    /* ---- the gate ---- */
    R(2) = vf3_aim_u32(a, R(7));
    R(3) = vf3_aim_u32(a, POOL_MASK);
    set_t(a, (R(2) & R(3)) == 0u);
    if ((R(2) & R(3)) != 0u) return;

    /* ---- the value ---- */
    R(0) = (uint32_t)half(a, POOL_TABLE);
    R(2) = COUNT_FIRST;
    R(3) = vf3_aim_u32(a, POOL_XOR);
    R(1) = 1u;
    R(5) = (uint32_t)half(a, R(5) + R(0));
    R(0) = WORD_OFFSET;
    R(5) &= 0xffffu;
    R(5) -= R(6);
    R(5) ^= R(3);
    R(3) = (uint32_t)half(a, POOL_LOW);
    R(6) = sext16(R(5));

    /* ---- the parity bit ---- */
    R(5) = vf3_aim_u32(a, R(4));
    R(4) = vf3_aim_u32(a, R(4) + WORD_OFFSET);

    set_t(a, (int32_t)R(6) > (int32_t)R(3));
    R(5) = shad(R(5), R(2));
    R(2) = COUNT_SECOND;
    R(4) = shad(R(4), R(2));
    R(5) ^= R(4);
    R(5) &= R(1);

    if ((int32_t)R(6) > (int32_t)R(3)) {
        /* above the low bound: the high band, or nothing at all */
        R(0) = (uint32_t)half(a, POOL_HIGH);
        set_t(a, (int32_t)R(6) >= (int32_t)R(0));
        if ((int32_t)R(6) < (int32_t)R(0))
            return;                      /* below the band */;

        R(3) = (uint32_t)half(a, POOL_HIGH2);
        set_t(a, (int32_t)R(6) > (int32_t)R(3));
        if ((int32_t)R(6) > (int32_t)R(3))
            return;                      /* above the band */;

        set_t(a, R(5) == 0u);
        if (R(5) == 0u) {
            /* the high bit */
            R(2) = vf3_aim_u32(a, R(7));
            R(3) = (uint32_t)half(a, POOL_BIT_HIGH);
            R(2) |= R(3);
            vf3_aim_set_u32(a, R(7), R(2));
        } else {
            /* the low bit */
            R(1) = vf3_aim_u32(a, R(7));
            R(3) = (uint32_t)half(a, POOL_BIT_LOW);
            R(1) |= R(3);
            vf3_aim_set_u32(a, R(7), R(1));
        }
        return;
    }

    /* ---- the middle band ---- */
    R(2) = (uint32_t)half(a, POOL_MID);
    set_t(a, (int32_t)R(6) >= (int32_t)R(2));
    if ((int32_t)R(6) < (int32_t)R(2)) {
        /* below the middle bound: the high band again */
        R(0) = (uint32_t)half(a, POOL_HIGH);
        R(3) = (uint32_t)half(a, POOL_LOW);
        set_t(a, (int32_t)R(6) >= (int32_t)R(0));
        return;
    }

    set_t(a, R(5) == 0u);
    if (R(5) != 0u) {
        /* the high bit */
        R(2) = vf3_aim_u32(a, R(7));
        R(3) = (uint32_t)half(a, POOL_BIT_HIGH);
        R(2) |= R(3);
        vf3_aim_set_u32(a, R(7), R(2));
    } else {
        /* the low bit */
        R(1) = vf3_aim_u32(a, R(7));
        R(3) = (uint32_t)half(a, POOL_BIT_LOW);
        R(1) |= R(3);
        vf3_aim_set_u32(a, R(7), R(1));
    }
}
