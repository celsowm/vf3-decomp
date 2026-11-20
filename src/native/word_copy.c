/* word_copy.c - SH-4 0x8C042F08: the word copy, natively.
 *
 * A plain-C transcription of the readable port src/fight/word_copy.c
 * (`vf3_word_copy_entry`) onto `vf3_native_aim`: the flat RAM and the
 * register file.
 *
 * Copy r0 bytes (a multiple of 4, at most 64) from r2 to r1, one word at a
 * time.  The original is an unrolled chain entered through a jump table
 * indexed by the byte count, and it software-pipelines the copy through two
 * registers: r3 and r0.  The chain assumes the word waiting in the pipeline is
 * in r3 when the number of words is odd; when it is even the word waiting is
 * r0 itself, which still holds the count minus 4 (the jump leaves r0
 * decremented).  That quirk is kept: for an even word count the highest
 * destination word receives r0, not the source word.  r3 is saved to [sp0-4]
 * and restored; r0 ends as the last word loaded into it.  The body refuses
 * (returns 0) when the byte count is not a multiple of 4 or is more than 64,
 * writing nothing.
 *
 * See docs/re/native_word_copy.md. */
#include "word_copy.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static uint32_t rd32(vf3_native_aim *a, uint32_t addr)
{ return vf3_aim_u32(a, addr); }
static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t v)
{ vf3_aim_set_u32(a, addr, v); }

int vf3_native_word_copy(vf3_native_aim *a, uint32_t sp0)
{
    const uint32_t bytes = R(0), dst = R(1), src = R(2);
    const uint32_t words = bytes >> 2;
    if ((bytes & 3u) || words > 16) return 0;   /* outside the table */

    const uint32_t r3_in = R(3);
    wr32(a, sp0 - 4u, r3_in);                    /* push r3 */
    uint32_t r0 = bytes - 4u;                    /* the jump decrements it */
    uint32_t r3 = rd32(a, src + r0);             /* delay slot of the jump */

    if (words > 0) {
        uint32_t *held = (words & 1u) ? &r3 : &r0;   /* the register waiting to be stored */
        uint32_t *other = (words & 1u) ? &r0 : &r3;
        for (int j = (int)words - 2; j >= 0; --j) {
            *other = rd32(a, src + 4u * (uint32_t)j);
            wr32(a, dst + 4u * (uint32_t)(j + 1), *held);
            uint32_t *t = held; held = other; other = t;
        }
        wr32(a, dst, *held);
    }

    R(3) = r3_in;                                /* r3 comes back from the stack */
    R(0) = r0;
    return 1;
}
