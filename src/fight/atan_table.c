/* atan_table.c - 0x8C069624  angle of the vector (FR4, FR5) as a 16-bit binary angle, from a lookup table.
 *
 *   FR4 = x, FR5 = y. Returns r0 = 0 for the zero vector. Otherwise the smaller absolute value is divided by
 *   the larger and scaled by 15000 to index the halfword table at 0x0C0EAF60 (the angle of that slope, up to
 *   0x2000). The octant is then folded back: 0x4000 - angle when |y| < |x| is false, and by the signs of y and
 *   x the result is -angle, 0x8000 - angle, angle - 0x8000 or the angle itself.
 *
 *   Leaves r4 = the signed angle, FPUL = the table index, FR2 / FR3 / FR6 / FR7 / FR8 as the original does. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { TABLE = 0x0C0EAF60u, SCALE_BITS = 0x466A6000u, QUARTER = 0x4000, HALF = 0x8000 };

int vf3_atan_table_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    F(3) = 0;
    if (fl(s, 5) == fl(s, 3) && fl(s, 4) == fl(s, 3)) { R(0) = 0; s->pc = R(VF3_REG_PR); return 1; }

    F(3) = 0;
    FMOV(6, 5);
    if (fl(s, 3) > fl(s, 5)) F(6) ^= SIGN;                  /* |y| */
    F(3) = 0;
    FMOV(7, 4);
    if (fl(s, 3) > fl(s, 4)) F(7) ^= SIGN;                  /* |x| */

    if (fl(s, 6) > fl(s, 7)) { FMOV(8, 7); FDIV(8, 6); }
    else                     { FMOV(8, 6); FDIV(8, 7); }

    FMOV(2, 8);
    F(3) = SCALE_BITS;
    FMUL(2, 3);
    {
        const float v = fl(s, 2);
        int32_t t = v >= 2147483648.0f ? INT32_MAX : v <= -2147483648.0f ? INT32_MIN : (int32_t)v;
        R(53) = (uint32_t)t;
    }
    int32_t a = (int16_t)vf3_mem_u16(ram, TABLE + (R(53) << 1));
    if (fl(s, 7) > fl(s, 6)) a = QUARTER - a;

    F(3) = 0;
    if (fl(s, 3) > fl(s, 5)) {                              /* y < 0 */
        if (fl(s, 3) > fl(s, 4)) a += (int16_t)HALF;
        else                     a = HALF - a;
    } else if (fl(s, 3) > fl(s, 4)) {                       /* y >= 0, x < 0 */
        a = -a;
    }
    R(4) = (uint32_t)a;
    R(0) = (uint32_t)a;
    s->pc = R(VF3_REG_PR);
    return 1;
}
