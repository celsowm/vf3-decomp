/* Stage-11 terrain correction, 0x8c087ace. */
#include "terrain_ext.h"
#include "terrain_region.h"
#include "aim_math.h"
#include "matrix_io.h"
#include "matrix_push.h"
#include "matrix_pop.h"
#include "xform_point.h"
#include <fenv.h>
#include <stdint.h>

#define R(n) (a->r[n])
#define F(n) (a->fr[n])

static float binary(vf3_native_aim *a, float x, float y, int multiply)
{
    int old = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = multiply ? x * y : x - y;
    fesetround(old);
    uint32_t u = vf3_aim_ubits(z);
    if ((a->fpscr & 0x40000u) && !(u & 0x7f800000u) && (u & 0x7fffffu))
        u &= 0x80000000u;
    return vf3_aim_fbits(u);
}

/* These two small wrappers transform either input FR4..6 as a point or the
 * three pointed-to floats as a vector. Their frames are guest-visible. */
static void transform(vf3_native_aim *a, int vector)
{
    uint32_t sp = R(15), frame = sp - 40;
    vf3_aim_set_u32(a, sp - 4, a->pr);
    vf3_aim_set_u32(a, frame + 8, R(4));
    vf3_aim_set_u32(a, frame + 4, R(5));
    vf3_aim_set_u32(a, frame, R(6));
    if (vector) {
        for (int i = 0; i < 3; ++i) {
            R(3) = vf3_aim_u32(a, frame + 8 - 4 * i);
            F(3) = vf3_aim_fbits(vf3_aim_u32(a, R(3)));
            vf3_aim_set_u32(a, frame + 24 + 4 * i, vf3_aim_ubits(F(3)));
        }
    } else {
        for (int i = 0; i < 3; ++i)
            vf3_aim_set_u32(a, frame + 24 + 4 * i, vf3_aim_ubits(F(4 + i)));
    }
    R(15) = frame; R(4) = frame + 24; R(5) = frame + 12;
    R(3) = vf3_aim_u32(a, vector ? 0x0c087798u : 0x0c087794u);
    a->pr = vector ? 0x0c087762u : 0x0c087714u;
    if (!vector) {
        vf3_native_xform_point(a);
    } else {
    float input[4];
    for (int i = 0; i < 3; ++i) input[i] = vf3_aim_fbits(vf3_aim_u32(a, R(4) + 4 * i));
    input[3] = vector ? 0.0f : 1.0f;
    R(4) += 12;
    int old = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    for (int row = 0; row < 4; ++row) {
        volatile double sum = (double)a->xm[row] * input[0];
        for (int col = 1; col < 4; ++col) sum += (double)a->xm[4 * col + row] * input[col];
        volatile float out = (float)sum;
        uint32_t bits = vf3_aim_ubits(out);
        if ((a->fpscr & 0x40000u) && !(bits & 0x7f800000u) && (bits & 0x7fffffu)) bits &= 0x80000000u;
        F(4 + row) = vf3_aim_fbits(bits);
    }
    fesetround(old);
    for (int i = 0; i < 3; ++i) vf3_aim_set_u32(a, frame + 12 + i * 4, vf3_aim_ubits(F(4 + i)));
    }
    R(0) = 12; R(2) = vf3_aim_u32(a, frame + 8);
    F(3) = vf3_aim_fbits(vf3_aim_u32(a, frame + 12));
    R(0) = 16; vf3_aim_set_u32(a, R(2), vf3_aim_ubits(F(3)));
    F(3) = vf3_aim_fbits(vf3_aim_u32(a, frame + 16));
    R(0) = 20; R(3) = vf3_aim_u32(a, frame + 4);
    vf3_aim_set_u32(a, R(3), vf3_aim_ubits(F(3)));
    F(3) = vf3_aim_fbits(vf3_aim_u32(a, frame + 20));
    R(3) = vf3_aim_u32(a, frame);
    R(15) = sp; a->pr = vf3_aim_u32(a, sp - 4);
    vf3_aim_set_u32(a, R(3), vf3_aim_ubits(F(3)));
}

void vf3_native_terrain_ext(vf3_native_aim *a)
{
    uint32_t sp = R(15);
    vf3_aim_set_u32(a, sp - 4, R(14)); vf3_aim_set_u32(a, sp - 8, R(13));
    vf3_aim_set_u32(a, sp - 12, R(12)); vf3_aim_set_u32(a, sp - 16, R(11));
    vf3_aim_set_u32(a, sp - 20, a->pr); vf3_aim_set_u32(a, sp - 24, R(7));
    R(13) = R(6); R(12) = R(4); R(11) = R(5); R(15) = sp - 24;
    F(5) = vf3_aim_fbits(vf3_aim_u32(a, R(13)));
    F(4) = vf3_aim_fbits(vf3_aim_u32(a, R(12)));
    a->pr = 0x0c087ae8u;
    vf3_native_terrain_region(a);
    R(14) = R(0); a->sr = (a->sr & ~1u) | (R(14) == 0);
    int found = R(14) != 0;
    if (found) {
        R(3) = vf3_aim_u32(a, 0x0c087b70u); R(4) = 0; a->pr = 0x0c087af4u;
        R(1) = vf3_aim_u32(a, 0x0c19d2ecu);
        vf3_native_matrix_push(a);
        R(2) = vf3_aim_u32(a, 0x0c087b74u); R(4) = R(14); a->pr = 0x0c087afau;
        vf3_native_matrix_load(a);
        R(0) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, 0x0c087b5eu);
        R(6) = R(13); R(5) = R(11);
        const unsigned regs[3] = {12, 11, 13};
        for (int i = 0; i < 3; ++i) {
            F(2) = vf3_aim_fbits(vf3_aim_u32(a, R(regs[i])));
            F(3) = vf3_aim_fbits(vf3_aim_u32(a, R(14) + R(0)));
            if (i < 2) R(0) += 4; else R(0) = 0x0c087b78u;
            F(2) = binary(a, F(2), F(3), 0);
            vf3_aim_set_u32(a, R(regs[i]), vf3_aim_ubits(F(2)));
        }
        F(3) = vf3_aim_fbits(vf3_aim_u32(a, R(0)));
        F(2) = binary(a, F(2), F(3), 1);
        vf3_aim_set_u32(a, R(13), vf3_aim_ubits(F(2)));
        F(5) = vf3_aim_fbits(vf3_aim_u32(a, R(11)));
        F(4) = vf3_aim_fbits(vf3_aim_u32(a, R(12))); F(6) = F(2);
        R(4) = R(12); a->pr = 0x0c087b2eu; transform(a, 0);
        R(5) = vf3_aim_u32(a, R(15) + 24); R(6) = vf3_aim_u32(a, R(15) + 28);
        R(4) = vf3_aim_u32(a, R(15)); a->pr = 0x0c087b36u; transform(a, 1);
        R(2) = vf3_aim_u32(a, 0x0c087b7cu);
    }
    R(15) = sp; a->pr = vf3_aim_u32(a, sp - 20);
    R(11) = vf3_aim_u32(a, sp - 16); R(12) = vf3_aim_u32(a, sp - 12);
    R(13) = vf3_aim_u32(a, sp - 8); R(14) = vf3_aim_u32(a, sp - 4);
    if (found) { R(4) = 1; vf3_native_matrix_pop(a); }
}
