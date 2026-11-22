/* edge_probe.c - SH-4 0x8C06E31C (edge_probe), natively.
 *
 * A plain-C transcription of the readable port src/fight/edge_probe.c
 * (`vf3_edge_probe_entry`) onto `vf3_native_aim`.  The only guest callee is
 * the already-native atan_table (0x8C069624).
 *
 * r4 = fighter object: the angle is the signed halfword at +0x1394, the probe
 * origin the floats at +0x430/+0x438.  For each of four quarter-turn
 * directions a ray of length 100 is cast from the origin against the stage
 * outline (the vertex list at [[0x0C29BBA4] + 0x3C4]: a count, then one
 * (x,y) float pair per vertex).  The first edge the ray crosses wins; its
 * distance and direction are written to the object at the two offsets from
 * the halfword table at 0x0C119688.
 *
 * Frame (f = sp0 - 84): f+0 -origin.y, f+4 origin.x, f+8/f+16 cos/sin of the
 * heading, f+12/f+24/f+28 the edge side tests, f+20 the ray length, f+32 0.
 *
 * The fsca is reproduced with sinf/cosf of the angle in radians (the aim-math
 * convention), the fsrra with 1/sqrtf; the FP arithmetic uses plain floats.
 */
#include "edge_probe.h"

#include "atan_table.h"
#include "aim_math.h"

#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

#define TABLE_HW    0x0C119688u   /* the halfword table of result offsets */
#define OUTLINE_CELL 0x0C29BBA4u  /* -> the stage outline block */
#define OUTLINE_OFF 0x3C4u        /* to the vertex-list pointer */
#define SIGN        0x80000000u
#define QUARTER     0x4000
#define LIT_RAY     0x42C80000u   /* 100.0f */
#define LIT_EPSILON 0x33D6BF94u   /* 1e-7f */

static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static float bits2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

void vf3_native_edge_probe(vf3_native_aim *a)
{
    const uint32_t sp0 = R(15), pr0 = a->pr, f = sp0 - 84u;
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t saved_f[4] = { fbits(F(15)), fbits(F(14)), fbits(F(13)), fbits(F(12)) };
    const uint32_t obj = R(4);

    for (int i = 0; i < 7; ++i) vf3_aim_set_u32(a, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    for (int i = 0; i < 4; ++i) vf3_aim_set_u32(a, sp0 - 32u - 4u * (uint32_t)i, fbits(saved_f[i]));
    vf3_aim_set_u32(a, sp0 - 48u, pr0);

    uint32_t heading = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, obj + 0x1394u);   /* r11 */
    const uint32_t outline = vf3_aim_u32(a, OUTLINE_CELL);                           /* r8 */
    uint32_t table = TABLE_HW - 2u;                                                  /* r12 */

    /* f+20 ray, f+32 0, f+4 origin.x, f+0 -origin.y */
    vf3_aim_set_u32(a, f + 20u, LIT_RAY);
    vf3_aim_set_u32(a, f + 32u, 0);
    vf3_aim_set_u32(a, f + 4u, vf3_aim_u32(a, obj + 0x430u));
    vf3_aim_set_u32(a, f + 0u, vf3_aim_u32(a, obj + 0x438u) ^ SIGN);

    for (uint32_t left = 4; left > 0; ) {
        uint32_t dir = 0;                                          /* r4: the edge direction */

        /* fsca(-heading): F0 = sin, F1 = cos, stored at f+16/f+8 */
        {
            const uint32_t ang = (uint32_t)(uint32_t)(-(int32_t)heading) & 0xFFFFu;
            const double rad = (double)ang * (3.14159265358979323846 / 32768.0);
            F(0) = sinf((float)rad);
            F(1) = cosf((float)rad);
        }
        vf3_aim_set_u32(a, f + 16u, fbits(F(0)));
        vf3_aim_set_u32(a, f + 8u,  fbits(F(1)));

        F(11) = bits2f(vf3_aim_u32(a, f + 16u));
        F(10) = bits2f(vf3_aim_u32(a, f + 8u));
        F(3)  = bits2f(vf3_aim_u32(a, f + 20u));
        F(7)  = bits2f(vf3_aim_u32(a, f + 4u));
        F(11) = F(11) * F(3);
        F(4)  = bits2f(vf3_aim_u32(a, f + 0u));
        F(10) = F(10) * F(3);
        F(3)  = F(7);
        F(8)  = F(4);
        F(11) = F(11) + F(7);
        F(10) = F(10) + F(4);
        F(5)  = F(11);  F(5)  = F(5)  * F(4);
        F(9)  = F(11);  F(3)  = F(3)  * F(10);
        F(9)  = F(9)  - F(7);
        F(8)  = F(8)  - F(10);
        F(2)  = F(5);   F(5)  = F(3);  F(5) = F(5) - F(2);

        uint32_t v = vf3_aim_u32(a, outline + OUTLINE_OFF);        /* r4: vertex list */
        uint32_t nodes = vf3_aim_u32(a, v); v += 4;                 /* r5: count */
        F(15) = bits2f(vf3_aim_u32(a, v)); v += 4;
        F(6)  = bits2f(vf3_aim_u32(a, v)); v += 4;

        for (;;) {
            if (nodes == 0) { F(13) = bits2f(vf3_aim_u32(a, f + 32u)); dir = 0; break; }

            F(12) = F(15);
            vf3_aim_set_u32(a, f + 12u, fbits(F(6)));
            F(14) = bits2f(vf3_aim_u32(a, f + 12u));
            F(15) = bits2f(vf3_aim_u32(a, v)); v += 4;
            F(3)  = bits2f(vf3_aim_u32(a, f + 12u));
            F(6)  = bits2f(vf3_aim_u32(a, v)); v += 4;
            F(4)  = F(15); F(4) = F(4) * F(3);
            F(2)  = F(12); F(2) = F(2) * F(6);
            F(14) = F(14) - F(6);
            F(7)  = F(15); F(7) = F(7) - F(12);
            F(1)  = F(4);  F(4) = F(2); F(4) = F(4) - F(1);
            F(2)  = bits2f(vf3_aim_u32(a, f + 4u));
            F(0)  = F(14);
            F(1)  = bits2f(vf3_aim_u32(a, f + 0u));
            F(13) = F(4);  F(13) = fmaf(F(0), F(2), F(13));
            F(0)  = F(7);  F(2) = F(13); F(2) = fmaf(F(0), F(1), F(2)); F(13) = F(2);
            vf3_aim_set_u32(a, f + 28u, fbits(F(13)));
            F(13) = F(4);  F(0) = F(14); F(13) = fmaf(F(0), F(11), F(13));
            F(0)  = F(7);  F(1) = bits2f(vf3_aim_u32(a, f + 28u));
            F(2)  = F(13); F(2) = fmaf(F(0), F(10), F(2)); F(13) = F(2);
            F(1)  = F(1) * F(13);
            F(2)  = 0.0f;
            { const int miss = F(1) > F(2); vf3_aim_set_u32(a, f + 28u, fbits(F(1))); if (miss) goto next_edge; }

            F(0)  = F(8);  F(13) = F(5); F(13) = fmaf(F(0), F(12), F(13));
            F(2)  = bits2f(vf3_aim_u32(a, f + 12u));
            F(0)  = F(9);  F(3) = F(13); F(3) = fmaf(F(0), F(2), F(3)); F(13) = F(3);
            vf3_aim_set_u32(a, f + 24u, fbits(F(13)));
            F(0)  = F(8);  F(13) = F(5); F(13) = fmaf(F(0), F(15), F(13));
            F(0)  = F(9);
            F(2)  = bits2f(vf3_aim_u32(a, f + 24u));
            F(3)  = F(13); F(3) = fmaf(F(0), F(6), F(3)); F(13) = F(3);
            F(2)  = F(2) * F(13);
            F(3)  = 0.0f;
            { const int miss = F(2) > F(3); vf3_aim_set_u32(a, f + 24u, fbits(F(2))); if (miss) goto next_edge; }

            /* the ray crosses this edge: intersection, then its distance */
            F(10) = F(5); F(10) = F(10) * F(7);
            F(11) = F(9); F(11) = F(11) * F(14);
            F(3)  = F(9); F(3)  = F(3)  * F(4);
            F(9)  = F(8); F(9)  = F(9)  * F(7);
            F(2)  = F(10); F(5) = F(5)  * F(14); F(8) = F(8) * F(4);
            F(4)  = F(11); F(10) = F(3); F(10) = F(10) - F(2);
            F(6)  = F(9);  F(3) = F(11); F(6)  = F(6)  - F(3);
            F(2)  = bits2f(vf3_aim_u32(a, f + 0u));
            F(3)  = F(6);  F(6) = F(10); F(6)  = F(6) / F(3);
            F(3)  = F(5);  F(5) = F(8);  F(5)  = F(5)  - F(3);
            F(3)  = F(9);  F(4) = F(4)  - F(3);
            F(3)  = bits2f(vf3_aim_u32(a, f + 4u));
            F(5)  = F(5)  / F(4);
            F(4)  = F(6);  F(4) = F(4)  - F(3); F(4) = F(4) * F(4);
            F(5)  = F(5)  - F(2);
            F(0)  = F(5);  F(4) = fmaf(F(0), F(5), F(4));
            F(13) = F(4);
            F(4)  = bits2f(LIT_EPSILON);
            if (F(4) > F(13)) {
                F(1) = 0.0f;
            } else {
                F(1) = F(13);
                F(1) = 1.0f / sqrtf(F(1));
            }
            F(13) = F(13) * F(1);
            vf3_aim_set_u32(a, f + 8u, fbits(F(1)));
            F(4) = F(12); F(5) = F(14); F(4) = F(4) - F(15);

            R(8) = outline; R(9) = left; R(10) = 0x0C069624u; R(11) = heading;
            R(12) = table; R(13) = obj; R(14) = QUARTER; R(15) = f;
            vf3_native_atan_table(a);
            R(15) = f;
            dir = (uint32_t)(int32_t)(int16_t)R(0) + QUARTER;
            break;

        next_edge:
            --nodes;
        }

        table += 2u;
        const uint32_t dist_off = vf3_aim_h16(a, table); table += 2u;
        const uint32_t dir_off = vf3_aim_h16(a, table);
        --left;
        heading += QUARTER;
        vf3_aim_set_u32(a, obj + dist_off, fbits(F(13)));
        vf3_aim_set_u16(a, obj + dir_off, (uint16_t)dir);
    }

    a->sr &= ~1u;                                   /* the closing cmp/pl was false */
    R(15) = sp0;
    {
        static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };
        for (int i = 0; i < 7; ++i) R(pushed[i]) = saved_r[i];
    }
    F(15) = bits2f(saved_f[0]); F(14) = bits2f(saved_f[1]);
    F(13) = bits2f(saved_f[2]); F(12) = bits2f(saved_f[3]);
    a->pr = pr0;
}
