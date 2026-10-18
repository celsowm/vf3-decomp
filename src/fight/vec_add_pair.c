/* vec_add_pair.c - 0x8C092A70  add a 3-float vector into a destination, then add one more y component.
 *
 * r4 = object whose byte at +97 gates the add, r5 = vector A, r6 = vector B, r7 = destination vector D (all x, y, z floats).
 * Unless the global word at 0x0C29B868 has bit 0x04000000 set and the byte at r4 + 97 is 11, D += A + 24 bytes
 * (the vector 24 bytes into A, i.e. the third vector of a 12-byte-stride array). Then, unconditionally, D.y += B.y.
 * The routine is a leaf: it spills r5 / r6 / r7 to its 12-byte frame, and mirrors fr0 .. fr5. When the first add is
 * skipped r4 / r5 / fr0, fr1, fr4, fr5 are left as they came in; otherwise r4 = D and r5 = A + 36. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define SET_T(c) (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))

int vf3_vec_add_pair_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 12;
    const uint32_t a = R(5), b = R(6), d = R(7);
    w32(ram, f + 8, a);
    w32(ram, f + 4, b);
    w32(ram, f, d);
    R(1) = 0x0C29B868u;
    R(3) = 0x04000000u;
    R(2) = m32(ram, R(1));
    SET_T((R(2) & R(3)) == 0);
    int add_first = 1;
    if (!(R(VF3_REG_SR) & 1u)) {
        R(0) = 97;
        R(0) = vf3_mem_u8(ram, R(4) + R(0));
        SET_T(R(0) == 11);
        if (R(VF3_REG_SR) & 1u) add_first = 0;
    }
    if (add_first) {
        R(5) = a + 24;
        R(4) = d;
        F(0) = m32(ram, R(4)); R(4) += 4;
        F(3) = m32(ram, R(5)); R(5) += 4;
        F(1) = m32(ram, R(4)); R(4) += 4;
        F(4) = m32(ram, R(5)); R(5) += 4;
        F(2) = m32(ram, R(4)); R(4) += 4;
        F(5) = m32(ram, R(5)); R(5) += 4;
        FADD(0, 3);
        FADD(2, 5);
        FADD(1, 4);
        R(4) -= 4; w32(ram, R(4), F(2));
        R(4) -= 4; w32(ram, R(4), F(1));
        R(4) -= 4; w32(ram, R(4), F(0));
    }
    R(3) = b;
    R(0) = 4;
    R(1) = R(0) + R(3);
    R(2) = d;
    F(2) = m32(ram, R(2) + R(0));
    F(3) = m32(ram, R(1));
    FADD(2, 3);
    w32(ram, R(2) + R(0), F(2));
    R(15) = sp0;
    s->pc = pr0;
    return 1;
}
