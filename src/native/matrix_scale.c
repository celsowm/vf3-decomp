/* matrix_scale.c - SH-4 0x8C03CB70 matrix_scale, natively.
 *
 * A plain-C transcription of the readable port src/fight/leaf_math.c
 * (`vf3_matrix_scale_entry`) onto `vf3_native_aim`.  The guest keeps the
 * current transform (XMTRX) in the XF bank - v[37..52] in a readable state,
 * `a->xm[16]` here - and the FR bank in v[21..36], `a->fr[16]` here.
 *
 * A self-contained leaf (call-free, no stack frame - the FR pushes only
 * write sp-4/sp-8/sp-12 without moving sp).  It scales the three axis
 * columns of XMTRX by (FR4, FR5, FR6), using XF15 as a scratch slot for
 * each scale and FPUL to park XF15's entry value:
 *
 *   - push FR6, FR5, FR4 to sp-4, sp-8, sp-12;  FPUL = XF15 (entry value);
 *   - for each axis: XF15 = FR(4+axis); multiply the four words of the
 *     column by that scale (FPU-exact toward-zero + FTZ per the FPSCR);
 *   - XF15 = FPUL (restored to its entry value).
 *
 * The multiplies go through the FPSCr-exact `fbin('*')` wrapper, so they
 * match `vf3_f_mul()` bit for bit.  No general register or r15 moves; SR is
 * untouched.  FR4..FR6 keep their entry values.  The return pops pr.
 *
 * See docs/re/native_matrix_scale.md. */
#include "matrix_scale.h"

#include "aim_math.h"
#include <fenv.h>

#define R(n) (a->r[(n)])

/* ---- FPSCR-aware FPU wrappers (as terrain_plane_hit.c) ---- */
static inline float flush(vf3_native_aim *a, float f)
{
    if (a->fpscr & 0x40000u) {
        uint32_t u = vf3_aim_ubits(f);
        if (!(u & 0x7F800000u) && (u & 0x7FFFFFu)) u &= 0x80000000u;
        f = vf3_aim_fbits(u);
    }
    return f;
}
static inline float fmul(vf3_native_aim *a, float x, float y)
{
    const int saved = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z = x * y;
    fesetround(saved);
    return flush(a, z);
}

void vf3_native_matrix_scale(vf3_native_aim *a)
{
    const uint32_t sp = R(15);
    const uint32_t saved_xf15 = vf3_aim_ubits(a->xm[15]);

    for (int i = 0; i < 3; ++i)
        vf3_aim_set_u32(a, sp - 4u * (uint32_t)(i + 1), vf3_aim_ubits(a->fr[6 - i]));
    a->fpul = saved_xf15;

    for (int axis = 0; axis < 3; ++axis) {
        const float scale = a->fr[4 + axis];
        for (int i = 0; i < 4; ++i)
            a->xm[4 * axis + i] = fmul(a, a->xm[4 * axis + i], scale);
    }

    a->xm[15] = vf3_aim_fbits(a->fpul);
}
