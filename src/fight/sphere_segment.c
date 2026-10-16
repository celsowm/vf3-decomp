/* sphere_segment.c - 0x8C09382A  sweep a point against a capsule-like segment and push it out to its surface.
 *
 *   r4 -> the point (vec3, moved in place), r5 -> vec3 receiving the segment origin / contact,
 *   r6 -> float (the push-out distance, read), r7 -> float (the limit, read), stack: three words
 *   at [sp] + [sp + 4] (the segment record) and [sp + 8] (the hit-flags word).
 *
 *   The segment record holds: +0 origin c, +12 / +24 two more vec3s (u = direction at +24, the end point at
 *   +12), +36 / +40 the push-out distance and limit (copied to *r6 / *r7), +44 / +48 the two squared-length
 *   limits. With d = p - c and t = u . d, the closest point on the line is P = c + u t and w = p - P.
 *
 *   If |w|^2 is not under *r7 the routine gives up. When the point lies before the start (u . (P - c) < 0) and
 *   t^2 is within the limit, 0x8C093A9C resolves the contact against the origin; when past the end
 *   (+44 < t^2) it resolves against the end point (+12) if t^2 is within +48; otherwise the point is
 *   pushed out along w by *r6 / |w| (zero for a tiny |w|) from P and bit 8 of the hit flags is set.
 *   Either way the answer vec3 at frame +48 is written to *r5.
 *
 *   Frame (60 bytes under nine saved words): +0 d / P - c, +12 u copy, +24 w, +36 P, +48 the answer vec3. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SAVED = 36, FRAME = 60, HIT_BIT = 0x100u };

#define LIT_TINY 0x33D6BF94u        /* 1e-7f */
#define LD(o)    m32(ram, f + (o))
#define ST(o, v) w32(ram, f + (o), (v))

int vf3_sphere_segment_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED - FRAME;
    const uint32_t saved_r[6] = { R(14), R(13), R(12), R(11), R(10), R(9) };
    const uint32_t saved_f[2] = { F(15), F(14) };
    static const int pushed[6] = { 14, 13, 12, 11, 10, 9 };

    for (int i = 0; i < 6; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    w32(ram, sp0 - 28, saved_f[0]);
    w32(ram, sp0 - 32, saved_f[1]);
    w32(ram, sp0 - 36, pr0);

    const uint32_t point = R(4), result = R(5), dist_at = R(6), limit_at = R(7);
    R(13) = point; R(10) = result; R(11) = dist_at; R(12) = limit_at;
    R(15) = f;
    R(9) = m32(ram, f + 104);
    R(14) = m32(ram, f + 96) + m32(ram, f + 100);
    const uint32_t seg = R(14);

    for (int i = 0; i < 3; ++i) { F(3) = m32(ram, seg + 4u * (uint32_t)i); ST(48 + 4 * i, F(3)); }
    for (int i = 0; i < 3; ++i) { F(3) = m32(ram, seg + 24u + 4u * (uint32_t)i); ST(12 + 4 * i, F(3)); }
    F(3) = m32(ram, seg + 36); w32(ram, dist_at, F(3));
    F(3) = m32(ram, seg + 40); w32(ram, limit_at, F(3));

    v3_sub(s, ram, f, point, seg);                          /* d = p - c */
    if (!v3_dot(s, ram, f + 12, f)) return 0;               /* t = u . d */
    F(15) = F(0);
    FMOV(4, 0);
    v3_scale(s, ram, f + 36, f + 12);                       /* u t */
    v3_add(s, ram, f + 36, f + 36, seg, 0);                 /* P = c + u t */
    v3_sub(s, ram, f + 24, point, f + 36);                  /* w = p - P */
    if (!v3_dot(s, ram, f + 24, f + 24)) return 0;
    FMOV(14, 0);

    F(3) = m32(ram, limit_at);
    if (GT(14, 3)) {                                        /* |w|^2 under the limit */
        F(3) = F(15);
        FMUL(15, 3);                                        /* t^2 */
        v3_sub(s, ram, f, f + 36, seg);                     /* P - c */
        if (!v3_dot(s, ram, f + 12, f)) return 0;
        F(3) = 0;
        if (fl(s, 3) > fl(s, 4)) {                          /* the foot is behind the start */
            F(3) = m32(ram, limit_at);
            if (!GT(3, 15)) {
                F(4) = m32(ram, dist_at); F(5) = m32(ram, limit_at);
                R(4) = point; R(5) = f + 48; R(6) = R(9);
                if (!vf3_guest_call(s, ram, 0x8C093A9Cu, 0x8C0939C0u)) return 0;
                R(15) = f;
            }
        } else {
            F(3) = m32(ram, seg + 44);
            if (GT(15, 3)) {                                /* t^2 under the first limit: push out along w */
                F(2) = LIT_TINY;
                F(4) = m32(ram, dist_at);
                if (GT(14, 2)) {
                    F(3) = 0;
                } else {
                    FMOV(3, 14);
                    if (!vf3_fpu_fsrra(F(3), R(VF3_REG_FPSCR), &F(3))) return 0;
                }
                FMUL(4, 3);
                v3_scale(s, ram, point, f + 24);
                v3_add(s, ram, point, point, f + 36, 0);
                w32(ram, R(9), m32(ram, R(9)) | HIT_BIT);
            } else {
                F(3) = m32(ram, seg + 48);
                if (!GT(3, 15)) {                           /* t^2 within the second limit */
                    for (int i = 0; i < 3; ++i) { F(3) = m32(ram, seg + 12u + 4u * (uint32_t)i); ST(48 + 4 * i, F(3)); }
                    F(5) = m32(ram, limit_at); F(4) = m32(ram, dist_at);
                    R(4) = point; R(5) = seg + 12; R(6) = R(9);
                    if (!vf3_guest_call(s, ram, 0x8C093A9Cu, 0x8C093A70u)) return 0;
                    R(15) = f;
                }
            }
        }
    }

    for (int i = 0; i < 3; ++i) { F(3) = LD(48 + 4 * i); w32(ram, result + 4u * (uint32_t)i, F(3)); }
    R(0) = 8;
    for (int i = 0; i < 6; ++i) R(pushed[i]) = saved_r[i];
    F(15) = saved_f[0]; F(14) = saved_f[1];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
