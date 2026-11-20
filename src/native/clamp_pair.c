/* clamp_pair.c - SH-4 0x8C08DCB0: two numbers, limited into ranges, into four
 * places, natively.
 *
 * A plain-C transcription of the readable port src/fight/clamp_pair.c
 * (`vf3_clamp_pair_entry`).  It operates on `vf3_native_aim`: the flat RAM and
 * the register file.  A self-contained leaf - it calls nobody and uses no FPU,
 * but it keeps a **frame**: it saves r13/r14 at sp-4/-8 and restores them.
 *
 * The function takes two numbers - r4 and r5 - and writes four limited values:
 *
 *   r4 into the range [pool 0x0c08dd48, pool 0x0c08dd4a]  -> r6 and the word
 *     the caller's frame word 0 points at
 *   r5 into the range [pool 0x0c08dd4c, pool 0x0c08dd4e]  -> r7
 *   r5 into the range [pool 0x0c08dd50, pool 0x0c08dd52]  -> the word the
 *     caller's frame word 1 points at
 *
 * The last two destinations are not registers: the caller leaves two words in
 * its own frame (at the entry sp, which the leaf reads back at r15+8 and
 * r15+12 after its own two-word push), and those words are the addresses to
 * write the limits to.  The limits themselves are signed halfwords in the
 * literal pool, so the port reads the same addresses the guest reads.
 *
 * Three details the port keeps: the guest tests the *low* bound first and only
 * then the high one, so a value below the low bound is never tested against the
 * high one; the T bit the caller sees is the one of the last comparison the
 * guest made, which is the one of the last limit; and the limited values travel
 * in r13, r14, r1 and r4, which the guest puts back from the stack at the end.
 *
 * See docs/re/native_clamp_pair.md. */
#include "clamp_pair.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* the literal pool: the six bounds */
#define X_LO  0x0c08dd48u   /* the first range's low bound  */
#define X_HI  0x0c08dd4au   /* the first range's high bound */
#define Y1_LO 0x0c08dd4cu   /* the second range's low bound  */
#define Y1_HI 0x0c08dd4eu   /* the second range's high bound */
#define Y2_LO 0x0c08dd50u   /* the third range's low bound  */
#define Y2_HI 0x0c08dd52u   /* the third range's high bound */

/* a bound from the pool: the guest reads it as a signed halfword */
static int32_t bound(vf3_native_aim *a, uint32_t addr)
{
    return (int32_t)(int16_t)vf3_aim_h16(a, addr);
}

/* the guest's limit: a value below the low bound becomes the low bound, a value
 * above the high bound becomes the high bound.  The low bound is tested first,
 * so the high one is never tested for a value below the low bound. */
static int32_t limit(vf3_native_aim *a, int32_t value, int32_t low, int32_t high)
{
    if (value >= low) {
        const int above = (value > high);
        set_t(a, above);
        if (above) value = high;
    } else {
        set_t(a, 0);
        value = low;
    }
    return value;
}

void vf3_native_clamp_pair(vf3_native_aim *a)
{
    const uint32_t sp = R(15);

    /* the guest saves r14 and r13 */
    vf3_aim_set_u32(a, sp - 4u, R(14));
    vf3_aim_set_u32(a, sp - 8u, R(13));
    R(15) = sp - 8u;

    /* the copies the guest makes of its two numbers: r1 and r13 hold the first
     * one, r14 and r4 the second */
    R(1) = R(4);
    R(13) = R(4);
    R(14) = R(5);
    R(4) = R(5);

    /* the first limit: the first number into the first range, into r13 */
    R(0) = (uint32_t)bound(a, X_LO);
    R(5) = (uint32_t)bound(a, X_HI);
    R(13) = (uint32_t)limit(a, (int32_t)R(13), (int32_t)R(0), (int32_t)R(5));

    /* the second: the second number into the second range, into r14 */
    R(5) = (uint32_t)bound(a, Y1_LO);
    R(0) = (uint32_t)bound(a, Y1_HI);
    R(14) = (uint32_t)limit(a, (int32_t)R(14), (int32_t)R(5), (int32_t)R(0));

    /* the third: the first number into the first range again, into r1 */
    R(5) = (uint32_t)bound(a, X_LO);
    R(0) = (uint32_t)bound(a, X_HI);
    R(1) = (uint32_t)limit(a, (int32_t)R(1), (int32_t)R(5), (int32_t)R(0));

    /* and the fourth: the second number into the third range, into r4 */
    R(5) = (uint32_t)bound(a, Y2_LO);
    R(0) = (uint32_t)bound(a, Y2_HI);
    R(4) = (uint32_t)limit(a, (int32_t)R(4), (int32_t)R(5), (int32_t)R(0));

    /* the four writes: the two register destinations first, then the two the
     * caller left in its frame */
    vf3_aim_set_u32(a, R(6), R(13));
    vf3_aim_set_u32(a, R(7), R(14));
    R(3) = vf3_aim_u32(a, R(15) + 8u);
    vf3_aim_set_u32(a, R(3), R(1));
    R(3) = vf3_aim_u32(a, R(15) + 12u);
    vf3_aim_set_u32(a, R(3), R(4));

    /* the guest puts the saved registers back.  The last one is the delay slot
     * of the return, so it is read even though the return has already
     * started. */
    R(13) = vf3_aim_u32(a, R(15));
    R(15) += 4u;
    R(14) = vf3_aim_u32(a, R(15));
    R(15) += 4u;
}
