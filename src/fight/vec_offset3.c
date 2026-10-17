/* vec_offset3.c - 0x8C074854  add an (x, y, z) offset to a record's position and to every point of its 64-byte list.
 *
 * r4 = record. The offset is the three floats at +0x1488 .. +0x1490. The record's own vector at +0x10 .. +0x18 gets
 * it added, then the 25 points of 64 bytes each starting at +0x180 get it added at +0x30 / +0x34 / +0x38. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { OFFSET_AT = 0x1488, LIST_AT = 0x180, LIST_BYTES = 0x640, POINT_BYTES = 64 };

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))

int vf3_vec_offset3_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    R(0) = OFFSET_AT;
    R(5) = LIST_AT;
    F(4) = m32(ram, R(4) + R(0));
    R(0) += 4;
    F(5) = m32(ram, R(4) + R(0));
    R(0) += 4;
    F(6) = m32(ram, R(4) + R(0));
    R(0) = 16;
    F(3) = m32(ram, R(4) + R(0));
    R(5) += R(4);
    R(6) = LIST_BYTES;
    FADD(3, 4);
    R(6) += R(5);
    SET_T(R(5) == R(6));
    w32(ram, R(4) + R(0), F(3));
    R(0) = 20;
    F(2) = m32(ram, R(4) + R(0));
    FADD(2, 5);
    w32(ram, R(4) + R(0), F(2));
    R(0) = 24;
    F(3) = m32(ram, R(4) + R(0));
    FADD(3, 6);
    w32(ram, R(4) + R(0), F(3));
    if (R(5) != R(6)) {
        do {
            R(0) = 48;
            F(3) = m32(ram, R(5) + R(0));
            FADD(3, 4);
            w32(ram, R(5) + R(0), F(3));
            R(0) = 52;
            F(2) = m32(ram, R(5) + R(0));
            FADD(2, 5);
            w32(ram, R(5) + R(0), F(2));
            R(0) = 56;
            F(3) = m32(ram, R(5) + R(0));
            FADD(3, 6);
            w32(ram, R(5) + R(0), F(3));
            R(5) += POINT_BYTES;
            SET_T(R(5) == R(6));
        } while (R(5) != R(6));
    }
    s->pc = R(VF3_REG_PR);
    return 1;
}
