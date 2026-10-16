/* edge_probe.c - 0x8C06E31C  probe the four quarter-turn directions around a body against the stage outline.
 *
 *   r4 = fighter object (angle at +0x1394 as a signed word, probe origin at +0x430 / +0x438). The outline is the
 *   vertex list at [[0x0C29BBA4] + 0x3C4]: a count, then one (x, y) float pair per vertex.
 *
 *   For each of four directions (the heading, then +0x4000, +0x8000, +0xC000) a ray of length 100 is cast from
 *   the origin; the edges of the outline are walked in order and the first one the ray crosses wins. The hit
 *   point's distance to the origin and the edge direction (angle through the 0x0C069624 helper, plus a quarter
 *   turn) are written to the object at the two offsets from the halfword table at 0x0C119688; no hit writes
 *   0.0 and 0. The routine leaves two dead slots of working data in its frame, which are written here too.
 *
 *   Frame (36 bytes under 48 saved): +0 -origin.y, +4 origin.x, +8 / +16 cos / sin of the heading, +12 / +24 /
 *   +28 the three edge side tests, +20 the ray length, +32 zero. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/sh4_fpu.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SAVED_BYTES = 48, FRAME_BYTES = 36, QUARTER = 0x4000 };

#define LIT_RAY      0x42C80000u    /* 100.0f */
#define LIT_EPSILON  0x33D6BF94u    /* 1e-7f */
#define LD(o)        m32(ram, f + (o))
#define ST(o, v)     w32(ram, f + (o), (v))

int vf3_edge_probe_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED_BYTES - FRAME_BYTES;
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t saved_f[4] = { F(15), F(14), F(13), F(12) };
    const uint32_t obj = R(4);

    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 32u - 4u * (uint32_t)i, saved_f[i]);
    w32(ram, sp0 - 48u, pr0);

    uint32_t heading = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, obj + 0x1394);      /* r11 */
    const uint32_t outline = m32(ram, 0x0C29BBA4u);                                    /* r8 */
    uint32_t table = 0x0C119688u - 2;                                                  /* r12 */
    uint32_t left;                                                                     /* r9 */

    ST(20, LIT_RAY);
    ST(32, 0);
    ST(4, m32(ram, obj + 0x430));
    ST(0, m32(ram, obj + 0x438) ^ SIGN);

    for (left = 4; left > 0; ) {
        uint32_t dir;                                       /* r4: the edge direction, 0 when nothing was hit */

        vf3_fpu_fsca((uint32_t)-(int32_t)heading, &F(0));
        ST(16, F(0)); ST(8, F(1));
        F(11) = LD(16); F(10) = LD(8); F(3) = LD(20); F(7) = LD(4);
        FMUL(11, 3); F(4) = LD(0); FMUL(10, 3);
        FMOV(3, 7); FMOV(8, 4); FADD(11, 7); FADD(10, 4);
        FMOV(5, 11); FMUL(5, 4); FMOV(9, 11); FMUL(3, 10); FSUB(9, 7); FSUB(8, 10);
        FMOV(2, 5); FMOV(5, 3); FSUB(5, 2);

        uint32_t v = m32(ram, outline + 0x3C4);             /* r4: walks the vertex list */
        uint32_t edges = m32(ram, v); v += 4;               /* r5 */
        F(15) = m32(ram, v); v += 4;
        F(6) = m32(ram, v); v += 4;

        for (;;) {
            if (edges == 0) { F(13) = LD(32); dir = 0; break; }

            FMOV(12, 15); ST(12, F(6)); F(14) = LD(12);
            F(15) = m32(ram, v); v += 4;
            F(3) = LD(12);
            F(6) = m32(ram, v); v += 4;
            FMOV(4, 15); FMUL(4, 3); FMOV(2, 12); FMUL(2, 6); FSUB(14, 6);
            FMOV(7, 15); FSUB(7, 12);
            FMOV(1, 4); FMOV(4, 2); FSUB(4, 1);
            F(2) = LD(4);
            FMOV(0, 14); F(1) = LD(0);
            FMOV(13, 4); FMAC(13, 2);
            FMOV(0, 7); FMOV(2, 13); FMAC(2, 1); FMOV(13, 2); ST(28, F(13));
            FMOV(13, 4); FMOV(0, 14); FMAC(13, 11);
            FMOV(0, 7); F(1) = LD(28); FMOV(2, 13); FMAC(2, 10); FMOV(13, 2);
            FMUL(1, 13); F(2) = 0;
            { const int miss = GT(2, 1); ST(28, F(1)); if (miss) goto next_edge; }

            FMOV(0, 8); FMOV(13, 5); FMAC(13, 12);
            F(2) = LD(12);
            FMOV(0, 9); FMOV(3, 13); FMAC(3, 2); FMOV(13, 3); ST(24, F(13));
            FMOV(0, 8); FMOV(13, 5); FMAC(13, 15);
            FMOV(0, 9); F(2) = LD(24); FMOV(3, 13); FMAC(3, 6); FMOV(13, 3);
            FMUL(2, 13); F(3) = 0;
            { const int miss = GT(3, 2); ST(24, F(2)); if (miss) goto next_edge; }

            /* the ray crosses this edge: intersection of the two lines, then its distance to the origin */
            FMOV(10, 5); FMUL(10, 7); FMOV(11, 9); FMUL(11, 14); FMOV(3, 9); FMUL(3, 4);
            FMOV(9, 8); FMUL(9, 7); FMOV(2, 10); FMUL(5, 14); FMUL(8, 4);
            FMOV(4, 11); FMOV(10, 3); FSUB(10, 2);
            FMOV(6, 9); FMOV(3, 11); FSUB(6, 3);
            F(2) = LD(0);
            FMOV(3, 6); FMOV(6, 10); FDIV(6, 3);
            FMOV(3, 5); FMOV(5, 8); FSUB(5, 3);
            FMOV(3, 9); FSUB(4, 3);
            F(3) = LD(4);
            FDIV(5, 4);
            FMOV(4, 6); FSUB(4, 3); FMUL(4, 4);
            FSUB(5, 2);
            FMOV(0, 5); FMAC(4, 5);
            FMOV(13, 4);
            F(4) = LIT_EPSILON;
            if (GT(13, 4)) F(1) = 0;
            else { FMOV(1, 13); if (!vf3_fpu_fsrra(F(1), R(VF3_REG_FPSCR), &F(1))) return 0; }
            FMUL(13, 1);
            ST(8, F(1));
            FMOV(4, 12); FMOV(5, 14); FSUB(4, 15);
            R(8) = outline; R(9) = left; R(10) = 0x0C069624u; R(11) = heading; R(12) = table; R(13) = obj;
            R(14) = QUARTER; R(15) = f;
            if (!vf3_guest_call(s, ram, 0x8C069624u, 0x8C06E4C4u)) return 0;
            R(15) = f;
            dir = (uint32_t)(int32_t)(int16_t)R(0) + QUARTER;
            break;

        next_edge:
            --edges;
        }

        table += 2;
        const uint32_t dist_off = vf3_mem_u16(ram, table);  table += 2;
        const uint32_t dir_off = vf3_mem_u16(ram, table);
        --left;
        heading += QUARTER;
        w32(ram, obj + dist_off, F(13));
        vf3_mem_set_u16(ram, obj + dir_off, (uint16_t)dir);
    }

    R(VF3_REG_SR) &= ~1u;                                   /* the closing cmp/pl was false */
    R(15) = sp0;
    {
        static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };
        for (int i = 0; i < 7; ++i) R(pushed[i]) = saved_r[i];
    }
    F(15) = saved_f[0]; F(14) = saved_f[1]; F(13) = saved_f[2]; F(12) = saved_f[3];
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
