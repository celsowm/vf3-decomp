/* unit_triple.c - 0x8C09DC34  turn a scene-helper triple into two angle calls and two lengths.
 *
 *   r4 is handed on to pass_prep (0x8C09DBC0, r5 = the frame's triple), r5 -> float out (the xz length),
 *   r6 -> float out (1 / |abc|). pass_prep fills a vector (a, b, c) at frame +8 / +12 / +16.
 *   With q = a^2 + b^2 + ... in the original's order (FR4 = b, FR5 = a), n = FR3 (the squared length of
 *   (a, b)), m = n + c^2 and inv(x) = fsrra(x), or zero when x is below 1e-7:
 *
 *     FR6 = inv(n), FR13 = inv(m)
 *     0x8C03C970(FR4 = FR6 * b, FR5 = FR6 * a)          the heading of (a, b)
 *     0x8C03C8B0(FR4 = -(FR13 * c), FR5 = sqrt(n) * FR13)   the pitch
 *     *r5 = sqrt(m) (zero for a tiny m) and *r6 = FR13, written last.
 *
 *   Frame (20 bytes under four FR saves and pr): +0 / +4 the out pointers r6 / r5, +8 / +12 / +16 the vector. */
#include <string.h>
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SAVED = 20, FRAME = 20, MOVA = 0x0C09DD5Cu };

#define LIT 0x33D6BF94u                                     /* 1e-7f */

static float lit(void) { const uint32_t b = LIT; float x; memcpy(&x, &b, 4); return x; }

/* FRd = 1 / sqrt(FRm) if FRm >= 1e-7, else 0 (the original's fcmp/gt + fsrra) */
static int inv_sqrt(vf3_matrix_state *s, int d, int m)
{
    if (lit() > fl(s, m)) { F(d) = 0; return 1; }
    FMOV(d, m);
    return vf3_fpu_fsrra(F(d), R(VF3_REG_FPSCR), &F(d));
}

int vf3_unit_triple_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED - FRAME;
    const uint32_t saved_f[4] = { F(15), F(14), F(13), F(12) };

    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_f[i]);
    w32(ram, sp0 - 20, pr0);
    R(15) = f;
    w32(ram, f + 4, R(5));
    R(5) = f + 8;
    w32(ram, f, R(6));
    if (!vf3_guest_call(s, ram, 0x8C09DBC0u, 0x8C09DC4Au)) return 0;
    R(15) = f;

    F(5) = m32(ram, f + 8);
    F(4) = m32(ram, f + 12);
    F(0) = F(5);
    FMOV(3, 4);
    FMUL(3, 4);
    F(12) = m32(ram, f + 16);
    R(0) = MOVA;
    F(2) = LIT;
    FMAC(3, 5);                                             /* FR3 = b^2 + a^2 */
    FMOV(15, 3);
    FMOV(14, 15);
    if (!inv_sqrt(s, 6, 15)) return 0;

    FMOV(0, 12);
    FMAC(14, 12);                                           /* FR14 = FR3 + c^2 */
    F(3) = LIT;
    const int tiny_m = fl(s, 3) > fl(s, 14);
    FMOV(3, 4);                                             /* delay slot, after the compare */
    if (tiny_m) F(13) = 0;
    else { FMOV(13, 14); if (!vf3_fpu_fsrra(F(13), R(VF3_REG_FPSCR), &F(13))) return 0; }

    FMOV(4, 6);
    FMUL(4, 3);
    FMOV(3, 5);
    FMOV(5, 6);
    FMUL(5, 3);
    if (!vf3_guest_call(s, ram, 0x8C03C970u, 0x8C09DC96u)) return 0;
    R(15) = f;

    FMOV(3, 13);
    FMUL(3, 12);
    R(0) = MOVA;
    FMOV(4, 3);
    F(3) = LIT;
    F(4) ^= SIGN;
    if (lit() > fl(s, 15)) F(2) = 0;
    else F(2) = vf3_fpu_sqrt(F(15), R(VF3_REG_FPSCR));
    FMOV(5, 2);
    FMUL(5, 13);
    R(3) = 0x0C03C8B0u;
    if (!vf3_guest_call(s, ram, 0x8C03C8B0u, 0x8C09DCB6u)) return 0;
    R(15) = f;

    R(0) = MOVA;
    R(2) = m32(ram, f + 4);
    F(2) = LIT;
    if (lit() > fl(s, 14)) F(3) = 0;
    else F(3) = vf3_fpu_sqrt(F(14), R(VF3_REG_FPSCR));
    w32(ram, R(2), F(3));
    R(3) = m32(ram, f);
    w32(ram, R(3), F(13));

    for (int i = 0; i < 4; ++i) F(15 - i) = saved_f[i];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
