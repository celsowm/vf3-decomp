/* range_init.c - SH-4 0x8C036A58: the fight engine's structure init, natively.
 *
 * A plain-C transcription of the readable port src/fight/range_init.c
 * (`vf3_range_init_entry`).  It operates on `vf3_native_aim`: the flat RAM and
 * the register file.  A self-contained leaf - it calls nobody, uses no FPU and
 * keeps **no stack frame** at all; its whole effect is the writes to the
 * structure and the register file.
 *
 * The engine keeps a forty-four byte structure and this function sets it up.
 * Most of it is zeroed, but four words in the middle carry a range.  The range's
 * four words sit at the structure's +8, +12, +16 and +20, and there are two
 * shapes:
 *
 *   the flag word is zero    ->  0, -1, 0, 0
 *   the flag word is not     -> -1, 0, -1, -1
 *
 * The flag word is the first word of whatever the pool points at (0x0c036af0),
 * so the branch is on the game's own state.  The word that lands in the
 * structure's +36 comes from the pool (0x0c036b0c) as well.
 *
 * Two details the port keeps: the branch's **delay slot** sets the marker on
 * both paths (so r5=0 and r6=-1 are set before the branch), the two paths do
 * **not** share their writes, and the T bit is set on the zero path and clear
 * on the non-zero one.  The structure's +36 word is stored in the `rts`'s delay
 * slot.  The pool's values are not recoverable offline, so the port reads the
 * same addresses the guest reads.
 *
 * See docs/re/native_range_init.md. */
#include "range_init.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* the literal pool: the pointer to the flag word, and the tail word */
#define G_FLAG 0x0c036af0u
#define G_TAIL 0x0c036b0cu

/* the four range words */
#define RANGE_A  8u
#define RANGE_B  12u
#define RANGE_C  16u
#define RANGE_D  20u

void vf3_native_range_init(vf3_native_aim *a)
{
    /* the zero and the marker */
    R(5) = 0u;
    R(6) = (uint32_t)(0u - 1u);

    /* the structure's first two words */
    vf3_aim_set_u32(a, R(4), R(5));
    vf3_aim_set_u32(a, R(4) + 4u, R(5));

    /* the word that decides the range's shape */
    R(2) = vf3_aim_u32(a, G_FLAG);
    R(3) = vf3_aim_u32(a, R(2));

    if (R(3) == 0u) {
        /* the flag is zero: the first and the third word are zero */
        vf3_aim_set_u32(a, R(4) + RANGE_A, R(5));
        vf3_aim_set_u32(a, R(4) + RANGE_B, R(6));
        vf3_aim_set_u32(a, R(4) + RANGE_C, R(5));
        vf3_aim_set_u32(a, R(4) + RANGE_D, R(5));
        set_t(a, 1);
    } else {
        /* the flag is not: the first, the third and the fourth word are the
         * marker */
        vf3_aim_set_u32(a, R(4) + RANGE_A, R(6));
        vf3_aim_set_u32(a, R(4) + RANGE_B, R(5));
        vf3_aim_set_u32(a, R(4) + RANGE_C, R(6));
        vf3_aim_set_u32(a, R(4) + RANGE_D, R(6));
        set_t(a, 0);
    }

    /* the four halfwords */
    R(0) = R(5);
    vf3_aim_set_u16(a, R(4) + 24u, (uint16_t)R(0));
    vf3_aim_set_u16(a, R(4) + 26u, (uint16_t)R(0));
    vf3_aim_set_u16(a, R(4) + 34u, (uint16_t)R(5));
    vf3_aim_set_u16(a, R(4) + 32u, (uint16_t)R(5));
    vf3_aim_set_u16(a, R(4) + 30u, (uint16_t)R(0));
    vf3_aim_set_u16(a, R(4) + 28u, (uint16_t)R(0));

    /* and the two words at the end */
    vf3_aim_set_u32(a, R(4) + 40u, R(0));
    R(3) = vf3_aim_u32(a, G_TAIL);
    vf3_aim_set_u32(a, R(4) + 36u, R(3));
}
