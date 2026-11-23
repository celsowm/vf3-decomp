/* The stage-11 region selector at 0x8c087a40. */
#include "terrain_region.h"
#include "aim_math.h"
#include <fenv.h>
#include <stdint.h>

#define R(n) (a->r[n])
#define F(n) (a->fr[n])

static uint32_t half(vf3_native_aim *a, uint32_t p)
{
    return (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, p);
}

static float binary(vf3_native_aim *a, float x, float y, char op)
{
    int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = op == '*' ? x * y : op == '+' ? x + y : x - y;
    fesetround(saved);
    uint32_t bits = vf3_aim_ubits(z);
    if ((a->fpscr & 0x40000u) && !(bits & 0x7f800000u) && (bits & 0x7fffffu))
        bits &= 0x80000000u;
    return vf3_aim_fbits(bits);
}

static int condition(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
    return value;
}

void vf3_native_terrain_region(vf3_native_aim *a)
{
    R(3) = vf3_aim_u32(a, 0x0c087b60u);
    R(0) = half(a, 0x0c087b56u);
    R(4) = vf3_aim_u32(a, R(3));
    R(4) = vf3_aim_u32(a, R(4) + R(0));
    if (condition(a, R(4) == 0)) { R(0) = 0; return; }

    R(0) = 0x0c087b64u;
    R(3) = half(a, 0x0c087b58u);
    F(9) = vf3_aim_fbits(vf3_aim_u32(a, R(0)));
    R(0) = 0x0c087b68u;
    F(8) = vf3_aim_fbits(vf3_aim_u32(a, R(0)));
    R(6) = 8; R(4) += R(3); R(5) = 0;
    for (;;) {
        R(0) = half(a, 0x0c087b5au);
        F(6) = F(9);
        F(3) = vf3_aim_fbits(vf3_aim_u32(a, R(4) + R(0)));
        R(0) += 4;
        F(7) = vf3_aim_fbits(vf3_aim_u32(a, R(4) + R(0)));
        R(0) += 4;
        F(6) = binary(a, F(6), F(3), '*');
        F(10) = vf3_aim_fbits(vf3_aim_u32(a, R(4) + R(0)));
        F(3) = F(7); R(0) += 8; F(7) = F(9);
        F(7) = binary(a, F(7), F(3), '*');
        F(11) = vf3_aim_fbits(vf3_aim_u32(a, R(4) + R(0)));
        F(1) = binary(a, F(6), F(10), '+');
        F(0) = binary(a, F(7), F(11), '+');
        F(3) = F(1); F(1) = binary(a, F(4), F(3), '-');
        F(3) = F(0); F(0) = binary(a, F(5), F(3), '-');
        F(3) = F(6); F(6) = binary(a, F(10), F(3), '-');
        F(3) = F(7); F(7) = binary(a, F(11), F(3), '-');
        F(3) = F(6); F(6) = binary(a, F(4), F(3), '-');
        int inside = condition(a, F(8) > F(1));
        F(3) = F(7); F(7) = binary(a, F(5), F(3), '-');
        if (inside && condition(a, F(8) > F(0))) {
            R(0) = 0x0c087b6cu;
            F(3) = vf3_aim_fbits(vf3_aim_u32(a, R(0)));
            if (condition(a, F(6) > F(3))) {
                R(0) = 0x0c087b6cu;
                F(3) = vf3_aim_fbits(vf3_aim_u32(a, R(0)));
                if (condition(a, F(7) > F(3))) { R(0) = R(4); return; }
            }
        }
        ++R(5);
        R(2) = half(a, 0x0c087b5cu);
        int end = condition(a, (int32_t)R(5) >= (int32_t)R(6));
        R(4) += R(2);
        if (end) { R(0) = 0; return; }
    }
}
