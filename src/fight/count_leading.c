/* count_leading.c - 0x8C0769C6  count the leading zero bits of r4 (32 for zero).
 *
 *   r4 = the word; returns r0 = the number of high bits clear before the first set one. A probe bit starts at
 *   bit 31 and walks down; r6 counts the bits passed, r5 is the probe left over and r3 a copy of r4. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

int vf3_count_leading_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    const uint32_t word = R(4);
    uint32_t probe = 0x80000000u, count = 0;
    int t;

    for (;;) {
        if (word & probe) { t = 0; break; }                 /* tst r5,r3 found a set bit: T = 0 */
        probe >>= 1;
        ++count;
        if (probe == 0) { t = 1; break; }                   /* tst r5,r5 */
    }
    R(3) = word;
    R(5) = probe;
    R(6) = count;
    R(0) = count;
    R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | (uint32_t)t;
    s->pc = R(VF3_REG_PR);
    return 1;
}
