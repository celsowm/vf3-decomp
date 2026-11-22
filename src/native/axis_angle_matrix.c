/* axis_angle_matrix.c - SH-4 0x8C03C750 (axis_angle_matrix), natively.
 *
 * A plain-C transcription of the readable port src/fight/axis_angle_matrix.c
 * (`vf3_axis_angle_matrix_entry`) onto `vf3_native_aim`.  It builds the
 * Rodrigues rotation matrix of "rotate by (sin, cos) around axis" into a
 * 16-float frame at f+4, then hands it to matrix_concat (0x8C03C0E0), which
 * is already native here.
 *
 * r4 = pointer to the unit axis (x, y, z), fr4 = sin, fr5 = cos; k = 1 - cos.
 * The diagonal is cos + k*a*a, the off-diagonals k*a*b -/+ sin*c; the fourth
 * column and the translation row are zero, the corner (f+0x40) is 1.0.  The
 * frame (f = sp0 - 84) holds k*x at f+0 and the matrix floats at f+4 .. f+2C,
 * with f+30..f+3C zero and f+40 = 1.0.
 *
 * The FR bank is restored to its entry values (fr13, fr14, fr15 are saved on
 * the stack across the call and restored).  The tail call to matrix_concat
 * runs natively with r4 = f+4. */
#include "axis_angle_matrix.h"

#include "matrix_concat.h"
#include "aim_math.h"

#include <math.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define FR(n) (a->fr[(n)])

#define ONE 0x3F800000u

void vf3_native_axis_angle_matrix(vf3_native_aim *a)
{
    const uint32_t sp0 = R(15), pr0 = a->pr, f = sp0 - 84u;
    const uint32_t s15 = vf3_aim_ubits(FR(15));
    const uint32_t s14 = vf3_aim_ubits(FR(14));
    const uint32_t s13 = vf3_aim_ubits(FR(13));
    vf3_aim_set_u32(a, sp0 - 4u,  s15);
    vf3_aim_set_u32(a, sp0 - 8u,  s14);
    vf3_aim_set_u32(a, sp0 - 12u, s13);
    vf3_aim_set_u32(a, sp0 - 16u, (pr0 & 0x0FFFFFFFu) | 0x8C000000u);

    const uint32_t axp = a->r[4];
    const float   sin = FR(4), cosv = FR(5);

    /* The Rodrigues build, following the guest's FR op order exactly. */
    float fr10 = 1.0f - cosv;          /* k = 1 - cos */
    float fr7  = *vf3_aim_p(a, axp + 4u);
    float fr8  = *vf3_aim_p(a, axp);
    float fr6  = *vf3_aim_p(a, axp + 8u);
    float fr3  = fr10;                 /* k */
    fr10 = fr10 * fr7;                 /* k*y */
    fr3  = fr3  * fr8;                 /* k*x */
    *vf3_aim_p(a, f) = fr3;            /* frame f+0 = k*x */

    float fr13 = fr10; fr13 = fr13 * fr6;    /* k*y*z */
    float fr10b = fr3; fr10b = fr10b * fr6;  /* k*x*z */
    float fr14 = sin;  fr14 = fr14 * fr8;    /* sin*x */
    float fr15 = sin;                /* sin */
    float fr4  = sin;  fr4  = fr4  * fr6;    /* sin*z */
    float fr11 = fr3;  fr15 = fr15 * fr7;    /* sin*y */
    fr11 = fr11 * fr7;                       /* k*x*y */

    float fr2 = 1.0f;                       /* fr9 = 1.0 */
    float x2 = fr8 * fr8, y2 = fr7 * fr7, z2 = fr6 * fr6;
    fr2 = fr2 - x2;                          /* 1 - x2 */
    float fr0 = cosv;                        /* cos */
    float fr1 = x2;
    fr1 = fr1 + fr0 * fr2;                   /* x2 + cos*(1-x2) */
    *vf3_aim_p(a, f + 4u) = fr1;

    fr3 = fr4;                               /* sin*z */
    fr3 = fr3 + fr11;                        /* sin*z + k*x*y */
    fr11 = fr11 - fr4;                       /* k*x*y - sin*z */
    *vf3_aim_p(a, f + 8u) = fr3;
    fr3 = fr10b;                             /* k*x*z */
    fr3 = fr3 - fr15;                        /* k*x*z - sin*y */
    fr15 = fr10b + fr15;                     /* k*x*z + sin*y */
    *vf3_aim_p(a, f + 12u) = fr3;
    *vf3_aim_p(a, f + 20u) = fr11;

    fr3 = 1.0f - y2;                         /* 1 - y2 */
    fr2 = y2;
    fr2 = fr2 + fr0 * fr3;                   /* y2 + cos*(1-y2) */
    *vf3_aim_p(a, f + 24u) = fr2;

    fr3 = fr14; fr3 = fr3 + fr13;            /* sin*x + k*y*z */
    fr13 = fr13 - fr14;                      /* k*y*z - sin*x */
    *vf3_aim_p(a, f + 28u) = fr3;
    *vf3_aim_p(a, f + 36u) = fr15;
    *vf3_aim_p(a, f + 40u) = fr13;

    fr3 = 1.0f - z2;                         /* 1 - z2 */
    fr2 = z2;
    fr2 = fr2 + fr0 * fr3;                   /* z2 + cos*(1-z2) */
    *vf3_aim_p(a, f + 44u) = fr2;

    /* zero the fourth column and the translation row, corner = 1.0.
     * r4 = f+4 in the guest, so these land at f+16, f+32, f+48, f+52,
     * f+56 and f+60; f+44 keeps the (3,3) element z2 + cos*(1-z2). */
    *vf3_aim_p(a, f + 60u) = 0.0f;
    *vf3_aim_p(a, f + 56u) = 0.0f;
    *vf3_aim_p(a, f + 52u) = 0.0f;
    *vf3_aim_p(a, f + 48u) = 0.0f;
    *vf3_aim_p(a, f + 32u) = 0.0f;
    *vf3_aim_p(a, f + 16u) = 0.0f;
    *vf3_aim_p(a, f + 64u) = 1.0f;

    /* tail call to matrix_concat (0x8C03C0E0) with r4 = f + 4.  The readable
     * keeps R(15) = f across the call, so the concat's push slots (f-4..-12)
     * land below the frame, clear of the saved registers at sp0-4..-12. */
    R(15) = f;
    R(4) = f + 4u;
    vf3_native_matrix_concat(a);

    /* restore the FR bank and the stack */
    FR(13) = vf3_aim_fbits(s13);
    FR(14) = vf3_aim_fbits(s14);
    FR(15) = vf3_aim_fbits(s15);
    R(15) = sp0;
    a->pr = pr0;
    (void)ONE;
}
