/* vec_offset.c - 0x8C074702  add an (x, z) offset to a position and to every point of its list.
 *
 * r4 = record. The offset is the two floats at +0x13A8 / +0x13B0. The record's own position at +0x1488 / +0x1490
 * gets it added; the list begins at the pointer stored at +0x138C and has 0x150 bytes of 12-byte points, each of
 * which gets the same offset on x (+0) and z (+8). */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { OFF_X = 0x13A8, POS_X = 0x1488, LIST_BYTES = 0x150 };

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))

int vf3_vec_offset_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    R(0) = OFF_X;
    R(6) = LIST_BYTES;
    F(4) = m32(ram, R(4) + R(0));
    R(0) += 8;
    F(5) = m32(ram, R(4) + R(0));
    R(0) -= 36;
    R(5) = m32(ram, R(4) + R(0));
    R(0) = POS_X;
    R(6) += R(5);
    F(3) = m32(ram, R(4) + R(0));
    SET_T(R(5) == R(6));
    FADD(3, 4);
    w32(ram, R(4) + R(0), F(3));
    R(0) += 8;
    F(2) = m32(ram, R(4) + R(0));
    FADD(2, 5);
    w32(ram, R(4) + R(0), F(2));
    if (R(5) != R(6)) {
        do {
            R(0) = 8;
            F(3) = m32(ram, R(5));
            FADD(3, 4);
            w32(ram, R(5), F(3));
            F(2) = m32(ram, R(5) + R(0));
            FADD(2, 5);
            w32(ram, R(5) + R(0), F(2));
            R(5) += 12;
            SET_T(R(5) == R(6));
        } while (R(5) != R(6));
    }
    s->pc = R(VF3_REG_PR);
    return 1;
}
