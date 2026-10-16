/* vec_shift.c - 0x8C0748E0  add one offset vector to an object's position and to its 28 point records.
 *
 *   r4 -> object. The offset (x, y, z) is at +0x13A8 / +0x13AC / +0x13B0 and is added to the vec3 at
 *   +0x1488; the point-record pointer at +0x138C then walks 0x150 bytes (28 vec3s, 12 bytes each) and every
 *   vec3 on the way gets the same offset added.
 *
 *   No frame, nothing saved. Leaves r0 = 8, r5 = r6 = the end pointer and T set. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { OFFSET = 0x13A8, POINTS_PTR = 0x138C, POSITION = 0x1488, POINTS_LEN = 0x150 };

/* the vec3 at addr += (FR4, FR5, FR6), through FR3 / FR2 / FR3 as the original does */
static void add_offset(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t addr)
{
    F(3) = m32(ram, addr);     FADD(3, 4); w32(ram, addr, F(3));
    F(2) = m32(ram, addr + 4); FADD(2, 5); w32(ram, addr + 4, F(2));
    F(3) = m32(ram, addr + 8); FADD(3, 6); w32(ram, addr + 8, F(3));
}

int vf3_vec_shift_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t obj = R(4);

    F(4) = m32(ram, obj + OFFSET);
    F(5) = m32(ram, obj + OFFSET + 4);
    F(6) = m32(ram, obj + OFFSET + 8);
    R(5) = m32(ram, obj + POINTS_PTR);
    R(6) = R(5) + POINTS_LEN;
    add_offset(s, ram, obj + POSITION);
    R(0) = 8;
    R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | (R(5) == R(6));

    if (R(5) != R(6)) {
        do {
            add_offset(s, ram, R(5));
            R(5) += 12;
        } while (R(5) != R(6));
        R(VF3_REG_SR) |= 1u;
    }
    s->pc = R(VF3_REG_PR);
    return 1;
}
