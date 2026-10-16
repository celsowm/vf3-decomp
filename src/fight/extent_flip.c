/* extent_flip.c - 0x8C0CC3F0  rewrite a three-float extent record, mirroring its y/z pair.
 *
 *   r4 -> six floats a0 a1 a2 b0 b1 b2; r5 -> flag word (bit 1 = keep as is); FR4 = a limit.
 *   Writes a0 = a0 + b0, a1 = a1 + b1 and a2 = -(-b2 - a2) = a2 + b2 (the sign flipped twice, so the
 *   result is a2 + b2 apart from the signs of zeros). Unless flag bit 1 is set, a1 + b1 is also floored at
 *   FR4: when it is not above FR4 it is replaced by FR4 and the flag word's bit 0 is cleared. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

int vf3_extent_flip_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t rec = R(4), flags_at = R(5);
    const uint32_t flags = m32(ram, flags_at);

    F(3) = m32(ram, rec);       F(6) = m32(ram, rec + 12); FADD(6, 3);          /* x */
    F(3) = m32(ram, rec + 4);   F(5) = m32(ram, rec + 16); FADD(5, 3);          /* y */
    F(3) = m32(ram, rec + 20);  F(2) = m32(ram, rec + 8);                       /* z */
    F(3) ^= SIGN;
    FMOV(7, 3);
    FSUB(7, 2);

    R(0) = flags;
    if (!(flags & 2u)) {
        const int over = GT(4, 5);                                              /* fcmp/gt FR4,FR5 */
        R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | (over ? 1u : 0u);
        if (!over) {
            R(2) = m32(ram, flags_at) & 0xFFFFFFFEu;
            R(3) = 0xFFFFFFFEu;
            FMOV(5, 4);
            w32(ram, flags_at, R(2));
        }
    } else {
        R(VF3_REG_SR) &= ~1u;                                                   /* tst #2 was false */
    }

    R(0) = 8;
    w32(ram, rec, F(6));
    w32(ram, rec + 4, F(5));
    F(7) ^= SIGN;
    w32(ram, rec + 8, F(7));
    s->pc = R(VF3_REG_PR);
    return 1;
}
