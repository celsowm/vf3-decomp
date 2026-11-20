/* pair_verdict.c - SH-4 0x8C074E7C: two structures compared, and a word set,
 * natively.
 *
 * A plain-C transcription of the readable port src/fight/pair_verdict.c
 * (`vf3_pair_verdict_entry`).  It operates on `vf3_native_aim`: the flat RAM
 * and the register file.  A self-contained leaf - it calls nobody and uses no
 * FPU, but it keeps a **frame**: it saves r13 at sp-4 and restores it.
 *
 * The function is handed two structures - r4 and r5 - and writes a word into
 * the first one: zero, or minus one.
 *
 *   Both structures keep a word at the same offset, 0x48.  The second
 *   structure's word has to share a bit with the first mask in the pool
 *   (0x0c074f60) and must *not* share a bit with the second one (0x0c074f64)
 *   - that is the gate.  The first structure's word is then masked with two
 *   more (0x0c074f68 and 0x0c074f6c) and the byte the second structure holds
 *   at the offset in the pool (0x0c074f50) decides the rest.
 *
 * The byte can be 2, 4 or 5, and the first structure has to have a field
 * (the offset in the pool is 0x0c074f52) for the answer to be anything but
 * zero.  The last mask in the pool (0x0c074f70) has the last word.
 *
 * The port follows the guest's own decision tree, because the tree is what
 * the T bit follows too: the guest's last test is the one the caller sees.
 *
 * Three details the port has to keep: the byte is read *signed* and then
 * masked to eight bits by the delay slot of the first branch, so the value
 * the tree compares is the unsigned one; the two masks are and-ed with the
 * first structure's word in the delay slot of a branch, so they are and-ed
 * on both paths; and the saved r13 comes back in the delay slot of the
 * return.
 *
 * See docs/re/native_pair_verdict.md. */
#include "pair_verdict.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* the literal pool: the three offsets and the five masks */
#define OFF_BYTE   0x0c074f50u   /* the byte of the second structure */
#define OFF_FIELD  0x0c074f52u   /* the field of the first structure */
#define OFF_RESULT 0x0c074f54u   /* the word the answer goes into */
#define MASK_A     0x0c074f60u   /* the first gate */
#define MASK_B     0x0c074f64u   /* the second gate */
#define MASK_C     0x0c074f68u   /* the first mask of the first structure */
#define MASK_D     0x0c074f6cu   /* the second mask of the first structure */
#define MASK_E     0x0c074f70u   /* the last mask */

#define WORD_OFFSET 0x48u

#define MINUS_ONE 0xffffffffu

/* the guest's halfword: sixteen bits, sign extended */
static int32_t half(vf3_native_aim *a, uint32_t addr)
{
    return (int32_t)(int16_t)vf3_aim_h16(a, addr);
}

/* The guest's block at 0x8C074EB4: the field of the first structure has to
 * be *empty*, and the mask has to be clear of it.  It answers whether the
 * tree goes on; the T bit it leaves is the one of the last test it made. */
static int field_is_empty(vf3_native_aim *a)
{
    R(0) = (uint32_t)half(a, OFF_FIELD);
    R(3) = vf3_aim_u32(a, R(4) + R(0));
    set_t(a, R(3) == 0);
    if (R(3) != 0) return 0;
    set_t(a, R(7) == 0);
    return R(7) == 0;
}

/* The guest's block at 0x8C074ECC: the second mask decides, and the last
 * mask has the last word.  It answers the word to write. */
static uint32_t last_test(vf3_native_aim *a)
{
    set_t(a, R(1) == 0);
    if (R(1) != 0) return MINUS_ONE;
    R(2) = vf3_aim_u32(a, MASK_E);
    set_t(a, (R(6) & R(2)) == 0);
    return ((R(6) & R(2)) != 0) ? MINUS_ONE : 0u;
}

void vf3_native_pair_verdict(vf3_native_aim *a)
{
    const uint32_t sp = R(15);

    /* the guest saves r13 */
    vf3_aim_set_u32(a, sp - 4u, R(13));
    R(15) = sp - 4u;

    /* the word each of the two structures keeps at the same offset */
    R(0) = WORD_OFFSET;
    R(6) = vf3_aim_u32(a, R(4) + R(0));
    R(13) = 0u;
    R(7) = vf3_aim_u32(a, R(5) + R(0));

    /* the byte of the second structure, and the first of the masks */
    R(0) = (uint32_t)half(a, OFF_BYTE);
    R(3) = vf3_aim_u32(a, MASK_A);
    R(5) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(5) + R(0));

    /* the first gate: the word of the second structure and the first mask
     * have to share a bit */
    set_t(a, (R(3) & R(7)) == 0);
    R(5) &= 0xffu;                       /* the delay slot of the branch */

    if ((R(3) & R(7)) != 0) {
        /* the second gate: this one is the other way round - the word of the
         * second structure must *not* share a bit with the second mask */
        R(2) = vf3_aim_u32(a, MASK_B);
        set_t(a, (R(7) & R(2)) == 0);
        if ((R(7) & R(2)) == 0) {
            /* the two masks, and-ed with the word of the first structure */
            R(7) = vf3_aim_u32(a, MASK_C);
            R(1) = vf3_aim_u32(a, MASK_D);
            R(7) &= R(6);
            set_t(a, R(7) == 0);
            R(1) &= R(6);                /* the delay slot of the branch */

            if (R(7) == 0) {
                /* the first arm: the byte and the field decide */
                if (field_is_empty(a)) {
                    R(0) = R(5);
                    set_t(a, R(0) == 2u);
                    if (R(0) == 2u) {
                        R(13) = last_test(a);
                    } else {
                        R(0) = R(5);
                        set_t(a, R(0) == 5u);
                        if (R(0) == 5u) R(13) = last_test(a);
                    }
                }
            } else {
                /* the second arm: only a byte that is neither 4 nor 5 makes
                 * the answer minus one */
                int minus_one = 0;
                set_t(a, R(1) == 0);
                if (R(1) == 0) {
                    R(0) = R(5);
                    set_t(a, R(0) == 4u);
                    if (R(0) != 4u) {
                        R(0) = R(5);
                        set_t(a, R(0) == 5u);
                        if (R(0) != 5u) minus_one = 1;
                    }
                }
                if (minus_one) {
                    R(13) = MINUS_ONE;
                } else {
                    (void)field_is_empty(a);
                }
            }
        }
    }

    /* the answer goes into the first structure */
    R(0) = (uint32_t)half(a, OFF_RESULT);
    vf3_aim_set_u32(a, R(4) + R(0), R(13));

    /* the delay slot of the return puts the saved r13 back */
    R(13) = vf3_aim_u32(a, R(15));
    R(15) += 4u;
}
