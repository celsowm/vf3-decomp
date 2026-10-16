/* word_copy.c - 0x8C042F08  copy r0 bytes (a multiple of 4, at most 64) from r2 to r1, one word at a time.
 *
 *   The original is an unrolled chain entered through a jump table indexed by the byte count, and it
 *   software-pipelines the copy through two registers: r3 and r0. The chain assumes the word waiting in
 *   the pipeline is in r3 when the number of words is odd; when it is even the word waiting is r0 itself,
 *   which still holds the count minus 4 (the jump leaves r0 decremented). That quirk is kept: for an
 *   even word count the highest destination word receives r0, not the source word. r3 is saved and
 *   restored; r0 ends as the last word loaded into it. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

int vf3_word_copy_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t bytes = R(0), dst = R(1), src = R(2), sp = R(15);
    const uint32_t words = bytes >> 2;
    if ((bytes & 3u) || words > 16) return 0;               /* outside the table */

    w32(ram, sp - 4, R(3));                                 /* push r3 */
    uint32_t r0 = bytes - 4;                                /* the jump decrements it */
    uint32_t r3 = m32(ram, src + r0);                       /* delay slot of the jump */

    if (words > 0) {
        uint32_t *held = (words & 1u) ? &r3 : &r0;          /* the register waiting to be stored */
        uint32_t *other = (words & 1u) ? &r0 : &r3;
        for (int j = (int)words - 2; j >= 0; --j) {
            *other = m32(ram, src + 4u * (uint32_t)j);
            w32(ram, dst + 4u * (uint32_t)(j + 1), *held);
            uint32_t *t = held; held = other; other = t;
        }
        w32(ram, dst, *held);
    }

    R(0) = r0;                                              /* r3 comes back from the stack */
    s->pc = R(VF3_REG_PR);
    return 1;
}
