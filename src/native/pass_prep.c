/* pass_prep.c - SH-4 0x8C09DBC0 (pass_prep), natively.
 *
 * A format_int-pattern sequencer: the readable port src/fight/pass_prep.c
 * calls four guest functions, and all four are natively ported, so the guest
 * calls become direct native calls.  The four, in order:
 *
 *   0x8C03C4F0  matrix push   -> vf3_native_matrix_push  (r4 = 0: no load)
 *   0x8C03C5B0  invert rigid  -> vf3_aim_invert_rigid    (in place)
 *   0x8C03B450  xform point   -> vf3_aim_xform_point
 *   0x8C03C4A0  matrix pop    -> vf3_native_matrix_pop   (r4 = 1: the tail)
 *
 * The frame is 72 bytes below the saved pr (f = sp0 - 76): arg0 at f, arg1
 * at f + 4.  pr is saved at sp0 - 4 and restored (with r15 = sp0) on the
 * way out.
 *
 * Net observable effect on XMTRX is a restore: push saves the entry XMTRX,
 * invert replaces it with the rigid inverse, xform transforms the point at
 * arg0 through the inverse into arg1, and pop loads XMTRX back off the
 * stack.  The matrix-stack control block is carried in the flat RAM by the
 * native push/pop, so the round trip is byte-for-byte comparable.
 *
 * See docs/re/native_pass_prep.md. */
#include "pass_prep.h"

#include "matrix_push.h"
#include "matrix_pop.h"
#include "aim_math.h"

#include <string.h>

#define R(n) (a->r[(n)])

enum { SAVED = 4, FRAME = 72 };

void vf3_native_pass_prep(vf3_native_aim *a)
{
    const uint32_t sp0 = R(15), pr0 = a->pr, f = sp0 - SAVED - FRAME;
    const uint32_t arg0 = R(4), arg1 = R(5);

    vf3_aim_set_u32(a, sp0 - 4u, pr0);
    R(15) = f;
    vf3_aim_set_u32(a, f, arg0);
    vf3_aim_set_u32(a, f + 4u, arg1);

    R(4) = 0;
    vf3_native_matrix_push(a);
    R(15) = f;
    {
        float inv[16];
        vf3_aim_invert_rigid(a->xm, inv);
        memcpy(a->xm, inv, sizeof inv);
    }
    R(15) = f;
    R(5) = arg1;
    R(4) = arg0;
    vf3_aim_xform_point(a, arg0, arg1);

    R(15) = sp0;
    a->pr = pr0;
    R(4) = 1;
    vf3_native_matrix_pop(a);

    R(15) = sp0;
    a->pr = pr0;
}
