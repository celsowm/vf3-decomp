/* terrain_probe.c - 0x8C06938C  look up the terrain under a stage position and report what it found.
 *
 *   r4 -> float the height goes to, r5 -> three floats the surface normal goes to, FR4 / FR5 = x / z.
 *   Returns 0 when the stage has no terrain table (the height then comes from 0x8C068DE4), otherwise a
 *   bit set: 1 = the position is outside the +-14 square, 2 = the 32 x 32 grid cell has no triangle that
 *   contains it, otherwise whatever 0x8C0692A6 reports for the triangle found; 4 is or-ed in on stage 13.
 *   On stage 11 the result is passed through 0x8C087ACE as well.
 *
 *   The grid at [[0x0C29BCC4] + 0x1F0] holds, per cell, an offset into the triangle lists at [0x0C113A0C]
 *   (-1 = empty). A list is 8-byte records; each is tested with 0x8C068FE4 until one contains the point.
 *
 *   Frame (40 bytes under six saved words): +0 / +4 x, z as passed (0x8C068D54 may rewrite them), +8 / +12
 *   z, x + the cell probe, +16 / +20 / +24 the normal that goes to r5, +28 / +32 / +36 what 0x8C0692A6 hands
 *   back. */
#include <string.h>
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SAVED = 24, FRAME = 40, GRID = 32, CELL_MISS = 0xFFFFFFFFu };

#define ST(o, v)  w32(ram, f + (o), (v))
#define LD(o)     m32(ram, f + (o))
#define LIT_14    0x41600000u
#define LIT_M14   0xC1600000u
#define LIT_16    0x41800000u
#define LIT_ONE   0x3F800000u
#define STAGE_BYTE 0x0C29B880u

static float bits_f(uint32_t b) { float x; memcpy(&x, &b, 4); return x; }

int vf3_terrain_probe_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED - FRAME;
    const uint32_t saved_r[4] = { R(14), R(13), R(12), R(11) }, saved_f15 = F(15);
    static const int pushed[4] = { 14, 13, 12, 11 };
    const uint32_t out_h = R(4), out_n = R(5);
    uint32_t result;

    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    w32(ram, sp0 - 20, saved_f15);
    w32(ram, sp0 - 24, pr0);
    R(13) = out_h; R(11) = out_n;
    R(12) = 15u & vf3_mem_u8(ram, STAGE_BYTE);
    R(15) = f;
    ST(0, F(4)); ST(4, F(5));

    R(4) = R(12); R(5) = f; R(6) = f + 4;
    if (!vf3_guest_call(s, ram, 0x8C068D54u, 0x8C0693B8u)) return 0;
    R(15) = f;

    const uint32_t grid = m32(ram, 0x0C29BCC4u + 0x1F0u);
    if (grid == 0) {
        R(0) = 4; R(4) = R(11);
        F(5) = LD(4); F(4) = LD(0);
        if (!vf3_guest_call(s, ram, 0x8C068DE4u, 0x8C0693CCu)) return 0;
        R(15) = f;
        w32(ram, R(13), F(0));
        result = 0;
        goto done;
    }

    F(15) = 0;
    const uint32_t xb = LD(0), zb = LD(4);
    const float x = bits_f(xb), z = bits_f(zb);
    int in_range = bits_f(LIT_14) > x && bits_f(LIT_14) > z && x > bits_f(LIT_M14) && z > bits_f(LIT_M14);
    int found = 0;

    if (!in_range) {
        w32(ram, R(13), F(15));
        R(14) = 1;
    } else {
        ST(12, xb);
        ST(8, zb);
        F(5) = xb; F(4) = LIT_16; FADD(5, 4);                       /* x + 16 */
        F(4) = zb; F(3) = LIT_16; FADD(4, 3);                       /* z + 16 */
        const uint32_t cell = ((uint32_t)(int32_t)fl(s, 5) & 31u) | (((uint32_t)(int32_t)fl(s, 4) & 31u) << 5);
        const uint32_t list = m32(ram, grid + cell * 4);
        if (list == CELL_MISS) {
            w32(ram, R(13), F(15));
            R(14) = 2;
        } else {
            R(14) = list + m32(ram, 0x0C113A0Cu);
            for (;;) {
                const uint32_t tri = m32(ram, R(14));
                if (tri == CELL_MISS) { w32(ram, R(13), F(15)); R(14) = 2; break; }
                R(4) = R(14);
                F(5) = LD(8); F(4) = LD(12);
                if (!vf3_guest_call(s, ram, 0x8C068FE4u, 0x8C06945Eu)) return 0;
                R(15) = f;
                R(7) = R(0);
                if (R(7) != 0) {
                    R(6) = f + 28; R(5) = R(13); R(4) = R(14);
                    F(5) = LD(8); F(4) = LD(12);
                    if (!vf3_guest_call(s, ram, 0x8C0692A6u, 0x8C069476u)) return 0;
                    R(15) = f;
                    R(14) = R(0);
                    ST(20, LD(28));
                    ST(24, LD(32));
                    ST(16, LD(36));
                    found = 1;
                    break;
                }
                R(14) += 8;
            }
        }
    }
    if (!found) {
        ST(24, LIT_ONE);
        ST(16, F(15));
        ST(20, F(15));
    }

    if (R(12) == 13) {
        R(14) |= 4;
    } else if (R(12) == 11) {
        const uint32_t spc = f - 8;
        w32(ram, f - 4, f + 16);
        w32(ram, spc, f + 28);
        R(15) = spc;
        R(5) = R(13); R(6) = spc + 16; R(7) = spc + 28; R(4) = spc + 20;
        if (!vf3_guest_call(s, ram, 0x8C087ACEu, 0x8C0694F0u)) return 0;
        R(15) = f;
    }

    w32(ram, R(11), LD(20));
    w32(ram, R(11) + 4, LD(24));
    w32(ram, R(11) + 8, LD(16));
    result = R(14);

done:
    R(0) = result;
    for (int i = 0; i < 4; ++i) R(pushed[i]) = saved_r[i];
    F(15) = saved_f15;
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
