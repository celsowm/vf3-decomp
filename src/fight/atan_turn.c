/* atan_turn.c - 0x8C039FD0  arctangent of fr4 as a 16-bit angle (65536 = one turn).
 *
 * fr4 = x. The argument is folded into [-1, 1] (u = 1/x when |x| > 1, else u = x) and atan(u) is evaluated as a
 * 13-term continued fraction in u^2:
 *     t = 0;  for n = 13 .. 2:  t = (n^2 * u^2) / (2n + t + 1)     (the loop runs while the new n >= 1)
 *     atan = u / (1 + t)
 * which is scaled to turns as (atan + 2pi) * 65536 / 2pi + 0.5, truncated and masked to 16 bits. For x > 1 the result
 * is 0x4000 - angle, for x < -1 it is 0xC000 - angle (the quadrant fold), otherwise the angle itself, all zero-extended
 * from 16 bits. Registers left: fr1 = 0.5, fr2 = 65536, fr3 = the scaled value (-1 once the quadrant test has run), fr5 = atan, fr6 = 1, fr7 = 2pi, fr8 =
 * the last n^2 helper, r3 = 0xFFFF, r4 = the masked angle, r5 = 1. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define TWO_PI_BITS  0x40C90FDAu
#define SCALE_BITS   0x47800000u
#define HALF_BITS    0x3F000000u

int vf3_atan_turn_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    if (!vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & 0x00180000u)) return 0;
    const uint32_t pr0 = R(VF3_REG_PR);
    const float x = fl(s, 4);
    const float one = 1.0f;

    float u = x;
    if (vf3_bits_f32(vf3_f32_bits(x) & 0x7FFFFFFFu) > one) u = vf3_f_div(s, one, x);
    float t = 0.0f, num = 0.0f, den = 0.0f, sq = 0.0f;
    int32_t n = 13;
    for (;;) {
        const int32_t cur = n;
        n -= 1;
        const float fn = vf3_f_from_int(s, cur);
        den = vf3_f_from_int(s, cur << 1);
        sq = vf3_f_mul(s, fn, fn);
        den = vf3_f_add(s, den, t);
        num = vf3_f_mul(s, sq, u);
        den = vf3_f_add(s, den, one);
        num = vf3_f_mul(s, num, u);
        t = vf3_f_div(s, num, den);       /* the delay slot, executed on the last pass too */
        set_fl(s, 8, fn);
        if (n < 1) break;
    }
    t = vf3_f_add(s, t, one);
    const float atan = vf3_f_div(s, u, t);
    const float two_pi = vf3_bits_f32(TWO_PI_BITS), scale = vf3_bits_f32(SCALE_BITS), half = vf3_bits_f32(HALF_BITS);
    float v = vf3_f_add(s, atan, two_pi);
    v = vf3_f_mul(s, v, scale);
    v = vf3_f_div(s, v, two_pi);
    v = vf3_f_add(s, v, half);
    const uint32_t raw = (uint32_t)vf3_f_trunc(v), ang = raw & 0xFFFFu;

    uint32_t r0;
    if (x > one) r0 = 0x4000u - ang;
    else if (vf3_bits_f32(0xBF800000u) > x) r0 = 0xC000u - ang;
    else r0 = ang;
    r0 &= 0xFFFFu;

    R(0) = r0;
    R(3) = 0xFFFFu;
    R(4) = ang;
    R(5) = 1;
    const int tflag = x > one ? 1 : (vf3_bits_f32(0xBF800000u) > x);
    R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | (uint32_t)tflag;
    set_fl(s, 1, half);
    set_fl(s, 2, scale);
    set_fl(s, 3, x > one ? v : -1.0f);        /* the x <= 1 path reloads fr3 with the -1 bound */
    set_fl(s, 5, atan);
    set_fl(s, 6, one);
    set_fl(s, 7, two_pi);
    R(VF3_REG_FPUL) = raw;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
