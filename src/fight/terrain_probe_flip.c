/* terrain_probe_flip.c - 0x8C06911C  the same terrain lookup as terrain_probe (0x8C06938C), for a mirrored z.
 *
 *   r4 -> three floats the surface normal goes to, FR4 / FR5 = x / z (z is negated on entry). Returns the
 *   same bit set: 0 = no terrain table (0x8C068DE4 fills the normal itself), 1 = outside the +-14 square,
 *   2 = no triangle in the grid cell, else the triangle's own word (shifted left once, masked with 0x1FFFC);
 *   4 is or-ed in on stage 13, and on stage 11 the normal is also run through 0x8C087ACE.
 *
 *   Unlike terrain_probe the triangle record itself carries the normal (floats at +20 / +24 / +28 of the
 *   record at [list entry + 4] + the triangle base), so there is no 0x8C0692A6 call.
 *
 *   Frame (32 bytes under five saved words): +0 / +4 x and -z, +8 / +12 / +16 the normal, +20 / +24 the
 *   probe copies of -z and x, +28 -z + 16. */
#include <string.h>
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SAVED = 20, FRAME = 32, CELL_MISS = 0xFFFFFFFFu, WORD_MASK = 0x1FFFCu };

#define ST(o, v)  w32(ram, f + (o), (v))
#define LD(o)     m32(ram, f + (o))
#define LIT_14    0x41600000u
#define LIT_M14   0xC1600000u
#define LIT_16    0x41800000u
#define LIT_ONE   0x3F800000u

static float bits_f(uint32_t b) { float x; memcpy(&x, &b, 4); return x; }

int vf3_terrain_probe_flip_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED - FRAME;
    const uint32_t saved_r[4] = { R(14), R(13), R(12), R(11) };
    static const int pushed[4] = { 14, 13, 12, 11 };
    const uint32_t out = R(4);
    uint32_t result;

    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    w32(ram, sp0 - 20, pr0);
    R(13) = out;
    R(12) = 15u & vf3_mem_u8(ram, 0x0C29B880u);
    R(15) = f;
    ST(0, F(4));
    F(5) ^= SIGN;
    ST(4, F(5));

    R(4) = R(12); R(5) = f; R(6) = f + 4;
    if (!vf3_guest_call(s, ram, 0x8C068D54u, 0x8C069146u)) return 0;
    R(15) = f;

    const uint32_t grid = m32(ram, 0x0C29BCC4u + 0x1F0u);
    if (grid == 0) {
        R(0) = 4; R(4) = R(13);
        F(5) = LD(4); F(4) = LD(0);
        if (!vf3_guest_call(s, ram, 0x8C068DE4u, 0x8C06915Au)) return 0;
        R(15) = f;
        result = 0;
        goto done;
    }

    const uint32_t xb = LD(0), zb = LD(4);
    const float x = bits_f(xb), z = bits_f(zb);
    const int in_range = bits_f(LIT_14) > x && bits_f(LIT_14) > z && x > bits_f(LIT_M14) && z > bits_f(LIT_M14);
    int found = 0;

    if (!in_range) {
        R(14) = 1;
    } else {
        ST(24, xb);
        ST(20, zb);
        F(5) = LIT_16; F(3) = xb; FADD(5, 3);                       /* x + 16 */
        F(4) = LIT_16; F(2) = zb; FADD(4, 2);                       /* z + 16 */
        ST(28, F(4));
        const uint32_t cell = ((uint32_t)(int32_t)fl(s, 5) & 31u) | (((uint32_t)(int32_t)fl(s, 4) & 31u) << 5);
        const uint32_t list = m32(ram, grid + cell * 4);
        if (list == CELL_MISS) {
            R(14) = 2;
        } else {
            R(11) = 0x0C113A0Cu;
            R(14) = list + m32(ram, R(11));
            for (;;) {
                if (m32(ram, R(14)) == CELL_MISS) { R(14) = 2; break; }
                F(5) = LD(20); F(4) = LD(24); R(4) = R(14);
                if (!vf3_guest_call(s, ram, 0x8C068FE4u, 0x8C0691EAu)) return 0;
                R(15) = f;
                if (R(0) != 0) {
                    const uint32_t rec = m32(ram, R(14) + 4) + m32(ram, R(11));
                    F(4) = m32(ram, rec + 20); F(5) = m32(ram, rec + 24); F(6) = m32(ram, rec + 28);
                    R(4) = m32(ram, rec);
                    ST(12, F(4)); ST(16, F(5)); ST(8, F(6));
                    R(14) = (R(4) << 1) & WORD_MASK;
                    found = 1;
                    break;
                }
                R(14) += 8;
            }
        }
    }
    if (!found) {
        ST(16, LIT_ONE);
        ST(8, 0);
        ST(12, 0);
    }

    if (R(12) == 13) {
        R(14) |= 4;
    } else if (R(12) == 11) {
        const uint32_t spc = f - 8;
        w32(ram, f - 4, f + 8);
        w32(ram, spc, f + 16);
        R(15) = spc;
        R(5) = spc + 36; R(6) = spc + 28; R(7) = spc + 20; R(4) = spc + 32;
        if (!vf3_guest_call(s, ram, 0x8C087ACEu, 0x8C06927Eu)) return 0;
        R(15) = f;
    }

    w32(ram, R(13), LD(12));
    w32(ram, R(13) + 4, LD(16));
    w32(ram, R(13) + 8, LD(8));
    result = R(14);

done:
    R(0) = result;
    for (int i = 0; i < 4; ++i) R(pushed[i]) = saved_r[i];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
