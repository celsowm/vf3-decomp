/* point_contact.c - 0x8C09363A  resolve a point against one collision record's segment table.
 *
 *   r4 -> the mover (flags halfword at +16, a float at +0x88), r5 -> the target record (a float at +36 and a
 *   kind byte at +54), r6 -> vec3 (the point, moved in place), r7 -> vec3 (the centre), and on the stack at
 *   [sp + 8] a pointer to the hit-flags word. Bits 0x1100 of the flags are cleared first.
 *
 *   When bit 0 of the mover's flags is clear and its height (+0x88) is above the point's y, the point is
 *   snapped onto the circle of radius sqrt(r^2 - dy^2) around the centre (r = [r5 + 36], dy = height - y of
 *   the centre), the height is stored as the new y and bit 0x1000 is set; the routine is finished.
 *
 *   Otherwise the target's kind byte picks a segment list at 0x0C0FC660 + kind * 32 (when the mover's bit 0
 *   is set, a kind other than 0 or 9 becomes 6). Each entry is two halfwords (a count
 *   and an offset); a negative count ends the list. A non-zero count runs sphere_segment (0x8C09382A) on
 *   the record at [sp + 4] + offset; a zero count calls 0x8C093A9C with the two floats at +12 / +16 of the
 *   record at [sp] + offset, then the list goes on.
 *
 *   Frame (20 bytes under four saved words and pr): +0 / +4 the two floats for 0x8C093A9C, +0 / +4 / +8 the
 *   sphere_segment out vec3 pointers (r6 = +0, r7 = +4, r5 = +8) while it runs. */
#include <string.h>
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SAVED = 20, FRAME = 20, SEG_TABLE = 0x0C0FC660u, HIT_CLEAR = 0xFFFFEEFFu, HIT_SET = 0x1000u };

#define LIT 0x33D6BF94u                                         /* 1e-7f */

int vf3_point_contact_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED - FRAME;
    const uint32_t saved_r[4] = { R(14), R(13), R(12), R(11) };
    static const int pushed[4] = { 14, 13, 12, 11 };

    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    w32(ram, sp0 - 20, pr0);
    R(15) = f;

    const uint32_t mover = R(4), target = R(5), point = R(6), centre = R(7);
    R(12) = m32(ram, f + 48);
    const uint32_t hit = R(12);
    w32(ram, hit, m32(ram, hit) & HIT_CLEAR);
    R(14) = point;

    uint32_t kind;
    if (!(vf3_mem_u16(ram, mover + 16) & 1u)) {
        F(4) = m32(ram, mover + 0x88);
        F(3) = m32(ram, point + 4);
        if (GT(3, 4)) {
            F(5) = m32(ram, centre + 4);
            F(6) = m32(ram, target + 36);
            F(9) = LIT;
            FSUB(5, 4);
            FMOV(3, 6); FMUL(3, 6);
            FMOV(2, 5); FMUL(2, 5);
            FMOV(5, 3); FSUB(5, 2);
            F(3) = m32(ram, centre);
            if (GT(5, 9)) F(6) = 0;
            else { FMOV(6, 5); F(6) = vf3_fpu_sqrt(F(6), R(VF3_REG_FPSCR)); }
            F(5) = m32(ram, point);
            F(7) = m32(ram, point + 8);
            FSUB(5, 3);
            F(3) = m32(ram, centre + 8);
            FSUB(7, 3);
            FMOV(3, 5); FMUL(3, 5);
            FMOV(0, 7); FMAC(3, 7);
            FMOV(8, 3);
            if (GT(3, 9)) F(3) = 0;
            else { FMOV(3, 8); if (!vf3_fpu_fsrra(F(3), R(VF3_REG_FPSCR), &F(3))) return 0; }
            FMUL(6, 3);
            F(3) = m32(ram, centre);
            FMOV(0, 5); FMAC(3, 6);
            w32(ram, point, F(3));
            F(2) = m32(ram, centre + 8);
            FMOV(0, 6); FMAC(2, 7);
            w32(ram, point + 8, F(2));
            w32(ram, point + 4, F(4));
            w32(ram, hit, m32(ram, hit) | HIT_SET);
            goto done;
        }
        kind = vf3_mem_u8(ram, target + 54);
    } else {
        kind = vf3_mem_u8(ram, target + 54);
        if (kind != 9 && kind != 0) kind = 6;
    }

    R(11) = SEG_TABLE + kind * 32u;
    for (;;) {
        const int32_t count = (int16_t)vf3_mem_u16(ram, R(11));
        const uint32_t off = vf3_mem_u16(ram, R(11) + 2);
        R(11) += 4;
        if (count < 0) break;
        if (count != 0) {
            w32(ram, f - 4, hit);
            w32(ram, f - 8, off);
            w32(ram, f - 12, m32(ram, f + 44));
            R(15) = f - 12;
            R(4) = point; R(5) = f + 8; R(6) = f; R(7) = f + 4;
            if (!vf3_guest_call(s, ram, 0x8C09382Au, 0x8C09371Cu)) return 0;
            R(15) = f;
        } else {
            R(13) = m32(ram, f + 40) + off;
            F(3) = m32(ram, R(13) + 12);
            w32(ram, f, F(3));
            F(3) = m32(ram, R(13) + 16);
            w32(ram, f + 4, F(3));
            F(4) = m32(ram, f);
            F(5) = F(3);
            R(4) = point; R(5) = R(13); R(6) = hit;
            if (!vf3_guest_call(s, ram, 0x8C093A9Cu, 0x8C093740u)) return 0;
            R(15) = f;
        }
    }

done:
    for (int i = 0; i < 4; ++i) R(pushed[i]) = saved_r[i];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
