/* negate_copy.c - 0x8C072B02  copy a list of vec3 pairs, the second vec3 of each pair negated.
 *
 *   r5 -> { count, src, dst }; every entry reads six floats and writes six: the first three copied as they
 *   are, the next three with the sign flipped (a fneg, so a NaN keeps its payload and a zero becomes -0). */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

int vf3_negate_copy_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    int32_t count = (int32_t)m32(ram, R(5));
    uint32_t src = m32(ram, R(5) + 4), dst = m32(ram, R(5) + 8);

    while (count > 0) {
        for (int i = 0; i < 6; ++i) {
            uint32_t v = m32(ram, src);
            F(3) = i < 3 ? v : v ^ SIGN;
            w32(ram, dst, F(3));
            src += 4; dst += 4;
        }
        --count;
    }
    R(7) = (uint32_t)count; R(4) = src; R(6) = dst;
    R(VF3_REG_SR) &= ~1u;                                   /* the last cmp/pl was false */
    s->pc = R(VF3_REG_PR);
    return 1;
}
