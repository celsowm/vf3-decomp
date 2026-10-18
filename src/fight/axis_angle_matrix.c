/* axis_angle_matrix.c - 0x8C03C750  axis-angle rotation: build the 3x3 matrix of "rotate by (sin, cos) around axis"
 * and hand it to the matrix loader 0x8C03C0E0.
 *
 * r4 = pointer to the unit axis (x, y, z), fr4 = sin, fr5 = cos. With k = 1 - cos the matrix is the usual Rodrigues
 * form: diagonal entries cos + k*a*a, off-diagonal k*a*b -/+ sin*c. The nine floats are written into a 4x4 frame at
 * f+4 (stride 4 words, the fourth column and the translation row zero, the corner f+0x40 = 1.0) and 0x8C03C0E0
 * loads it with r4 = f+4.
 *
 * The routine mirrors every float register it touches, so the register file and the frame it leaves are the original's.
 * Frame (f = sp - 84): f+0 k*x, f+4 .. f+2C the matrix floats, f+30 .. f+3C zero, f+40 1.0. fr13 .. fr15 are saved
 * on the stack across the call and restored. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)
#define STF(fr, off)  w32(ram, f + (off), F(fr))
#define ONE 0x3F800000u

int vf3_axis_angle_matrix_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 84;
    const uint32_t s15 = F(15), s14 = F(14), s13 = F(13);
    w32(ram, sp0 - 4, s15);
    w32(ram, sp0 - 8, s14);
    w32(ram, sp0 - 12, s13);
    w32(ram, sp0 - 16, (pr0 & 0x0FFFFFFFu) | 0x8C000000u);

    R(0) = 4;
    F(9) = ONE;
    FMOV(10, 9);
    FSUB(10, 5);                                       /* fr10 = 1 - cos */
    F(7) = m32(ram, R(4) + R(0));
    R(0) = 8;
    F(8) = m32(ram, R(4));
    F(6) = m32(ram, R(4) + R(0));
    FMOV(3, 10);
    FMUL(10, 7);
    FMUL(3, 8);
    R(15) = f;
    STF(3, 0);
    FMOV(13, 10); FMUL(13, 6);
    FMOV(10, 3);  FMUL(10, 6);
    FMOV(14, 4);  FMUL(14, 8);
    FMOV(15, 4);  FMUL(4, 6);
    FMOV(11, 3);  FMUL(15, 7);
    FMUL(11, 7);
    FMOV(2, 9);
    FMUL(8, 8);
    FMUL(7, 7);
    FMUL(6, 6);
    FSUB(2, 8);
    FMOV(0, 5);
    FMOV(1, 8);
    R(0) = 4;
    FMAC(1, 2);
    STF(1, 4);

    R(0) = 8;
    FMOV(3, 4); FADD(3, 11); FSUB(11, 4);
    STF(3, 8);
    R(0) = 12;
    FMOV(3, 10); FSUB(3, 15); FADD(15, 10);
    STF(3, 12);
    R(0) = 20;
    STF(11, 20);
    R(0) = 24;
    FMOV(3, 9); FSUB(3, 7); FMOV(2, 7); FMAC(2, 3);
    STF(2, 24);
    R(0) = 28;
    FMOV(3, 14); FADD(3, 13); FSUB(13, 14);
    STF(3, 28);
    R(0) = 36;
    STF(15, 36);
    R(0) = 40;
    STF(13, 40);
    R(0) = 44;
    FMOV(3, 9); FSUB(3, 6); FMOV(2, 6);
    R(4) = f + 4;
    FMAC(2, 3);
    STF(2, 44);

    F(3) = 0;
    R(0) = 56; w32(ram, R(4) + R(0), F(3));
    R(0) = 52; w32(ram, R(4) + R(0), F(3));
    R(0) = 48; w32(ram, R(4) + R(0), F(3));
    R(0) = 44; w32(ram, R(4) + R(0), F(3));
    R(0) = 28; w32(ram, R(4) + R(0), F(3));
    R(0) = 12; w32(ram, R(4) + R(0), F(3));
    R(0) = 64;
    R(4) = f;
    STF(9, 64);
    R(3) = 0x0C03C0E0u;
    R(4) += 4;
    CALL(0x0C03C0E0u, 0x8C03C808u);

    F(13) = s13;
    F(14) = s14;
    F(15) = s15;
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
