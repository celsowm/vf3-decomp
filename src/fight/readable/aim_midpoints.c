/* aim_midpoints.c - SH-4 0x8C09E428: three angle midpoints and the
 * aim-frame half of the pose orchestration.
 *
 * r4 -> actor, r5 -> the caller's pointer (saved in the frame and handed
 * to the last two calls).  The frame is sixteen bytes under the two saved
 * words (r14, pr): frame +0 is the saved r5, and the three midpoints of
 * the actor's pose-field halfwords live at frame +8, +12 and +4:
 *
 *   frame +8  = mid(actor[0x1F86], actor[0x1F56])
 *   frame +12 = mid(actor[0x1F88], actor[0x1F58])
 *   frame +4  = mid(actor[0x1F8A], actor[0x1F5A])
 *
 * where mid(second, first) is the guest's exact halfword arithmetic:
 * both operands are zero-extended, the difference is sign-extended from
 * sixteen bits, shifted right **logically** (shlr, leaving the shifted-out
 * bit in SR.T), added to the second operand and masked back to sixteen
 * bits.  With a negative difference the logical shift of the sign-extended
 * value is what the guest computes, so this is not the signed average.
 *
 * Then, in order:
 *
 *   0x8C09D452 (pool 0x0C09E4B8) with r4 = frame+4, r5 = frame+12 and
 *     r6 = frame+8 - the three midpoints as **values**;
 *   rotate_z (0x8C03C940, pool 0x0C09E4BC) with the pool angle at
 *     0x0C09E4B0 (0x4000, a quarter turn);
 *   store_keep_translation (0x8C09D4E6) with r4 = the saved r5 pointer;
 *   matrix_copy (0x8C03B530, pool 0x0C09E4C0) with r4 = actor + the pool
 *     offset at 0x0C09E4B2 (0x400) and r5 = the saved r5 pointer again;
 *   and a **tail transfer** to matrix_pop (0x8C03C4A0, pool 0x0C09E4C4)
 *   with r4 = 1, after popping pr and restoring r14 in the jmp delay
 *   slot, so the pop runs in the caller's frame.
 *
 * The frame's +0 word (the saved r5) is stored before the first call and
 * re-read for the last two, and the three midpoint slots are written in
 * the order +8, +12, +4 - the port keeps all of that, because the caller's
 * stack is part of the captured RAM.  The first call is matrix_push
 * (0x8C03C4F0, pool 0x0C09E4B4) with r4 = 0.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the literal pool */
#define POOL_PUSH        0x0c09e4b4u
#define POOL_D452        0x0c09e4b8u
#define POOL_ROTATE_Z    0x0c09e4bcu
#define POOL_MATRIX_COPY 0x0c09e4c0u
#define POOL_MATRIX_POP  0x0c09e4c4u
#define POOL_OFF_A       0x0c09e4aau   /* 0x1F86 */
#define POOL_OFF_B       0x0c09e4acu   /* 0x1F58 */
#define POOL_OFF_C       0x0c09e4aeu   /* 0x1F5A */
#define POOL_Z_ANGLE     0x0c09e4b0u   /* 0x4000 */
#define POOL_COPY_OFF    0x0c09e4b2u   /* 0x400 */

/* the continuations the guest leaves in pr */
#define CONT_PUSH        0x0c09e438u
#define CONT_D452        0x0c09e488u
#define CONT_ROTATE_Z    0x0c09e490u
#define CONT_STORE       0x0c09e494u
#define CONT_COPY        0x0c09e49eu

#define SAVED 8u
#define FRAME 16u

/* mid(second, first) exactly as the guest computes it: zero-extend both
 * halfwords, sign-extend the difference from sixteen bits, shift it right
 * logically (T = the bit shifted out), add it to the second operand and
 * mask to sixteen bits. */
static uint32_t midpoint(vf3_matrix_state *s, const vf3_ram_map *ram,
                         uint32_t obj, uint32_t off_second,
                         uint32_t off_first)
{
    const uint32_t second = vf3_mem_u16(ram, obj + off_second);
    const uint32_t first = vf3_mem_u16(ram, obj + off_first);
    uint32_t diff = (uint32_t)(int32_t)(int16_t)((int32_t)first -
                                                (int32_t)second);
    R(17) = (R(17) & ~1u) | (diff & 1u);
    diff >>= 1;
    return (second + diff) & 0xffffu;
}

int vf3_aim_midpoints_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(16), saved_r14 = R(14), obj = R(4);
    const uint32_t f = sp0 - SAVED - FRAME;

    vf3_mem_set_u32(ram, sp0 - 4u, saved_r14);
    vf3_mem_set_u32(ram, sp0 - 8u, pr0);
    R(15) = f;
    R(14) = obj;
    R(4) = 0;
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_PUSH), CONT_PUSH))
        return 0;
    R(15) = f;

    /* the saved r5 goes in the frame's first word, before the midpoints */
    vf3_mem_set_u32(ram, f, R(5));

    /* frame +8: mid(0x1F86, 0x1F56) - the first operand comes first in the
     * guest's register order, the second is 48 bytes below it */
    {
        const uint32_t off = (uint32_t)(int32_t)(int16_t)
                                 vf3_mem_u16(ram, POOL_OFF_A);
        vf3_mem_set_u32(ram, f + 8u,
                        midpoint(s, ram, obj, off, off - 48u));
    }
    /* frame +12: mid(0x1F88, 0x1F58) */
    {
        const uint32_t off = (uint32_t)(int32_t)(int16_t)
                                 vf3_mem_u16(ram, POOL_OFF_B);
        vf3_mem_set_u32(ram, f + 12u,
                        midpoint(s, ram, obj, off + 48u, off));
    }
    /* frame +4: mid(0x1F8A, 0x1F5A) */
    {
        const uint32_t off = (uint32_t)(int32_t)(int16_t)
                                 vf3_mem_u16(ram, POOL_OFF_C);
        vf3_mem_set_u32(ram, f + 4u,
                        midpoint(s, ram, obj, off + 48u, off));
    }

    /* the three midpoints as values: r4 = +4, r5 = +12, r6 = +8 */
    R(6) = vf3_mem_u32(ram, f + 8u);
    R(5) = vf3_mem_u32(ram, f + 12u);
    R(4) = vf3_mem_u32(ram, f + 4u);
    R(3) = vf3_mem_u32(ram, POOL_D452);
    if (!vf3_guest_call(s, ram, R(3), CONT_D452)) return 0;
    R(15) = f;

    R(4) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, POOL_Z_ANGLE);
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_ROTATE_Z),
                        CONT_ROTATE_Z)) return 0;
    R(15) = f;

    /* store_keep_translation gets the saved r5 pointer from the frame */
    R(4) = vf3_mem_u32(ram, f);
    if (!vf3_guest_call(s, ram, 0x8C09D4E6u, CONT_STORE)) return 0;
    R(15) = f;

    /* matrix_copy: actor + the pool offset, and the saved r5 pointer */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, POOL_COPY_OFF);
    R(4) = obj + R(0);
    R(5) = vf3_mem_u32(ram, f);
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_MATRIX_COPY),
                        CONT_COPY)) return 0;
    R(15) = f;

    /* the tail transfer: restore the frame, pop pr, r4 = 1, restore r14
     * in the jmp delay slot and jump to matrix_pop */
    R(15) += FRAME;
    R(16) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    R(4) = 1u;
    R(2) = vf3_mem_u32(ram, POOL_MATRIX_POP);
    R(14) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    return vf3_guest_tail_call(s, ram, R(2), R(16));
}
