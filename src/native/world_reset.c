/* world_reset.c - SH-4 0x8C03E980 (world_reset), natively.
 *
 * A plain-C transcription of the readable port src/fight/matrix_extra.c
 * (`vf3_world_reset_entry`) onto `vf3_native_aim`.  The callees it sequences
 * (matrix_transpose 0x8C03CC30 and xform_vector 0x8C03B4B0) are already
 * native ports in this library, so the body runs entirely natively:
 *
 *   1. transpose XMTRX,
 *   2. transform the vector at 0x0C19D5B0 + 0x68 (rotation only, w = 0)
 *      into +0x80,
 *   3. transform the vector at 0x0C0EA600 into 0x0C058FE0,
 *   4. transpose XMTRX back (the tail call).
 *
 * The net XMTRX is therefore the identity of the two transposes (the 
 * transforms run in the transposed frame, exactly as the guest does).  The
 * register file and the frame are the guest's: the caller's PR is parked at
 * sp0-4, the frame is sp0-8, and world_reset ends with the caller's PR in
 * pr (the tail call convention).
 *
 * See docs/re/native_world_reset.md. */
#include "world_reset.h"

#include "xmtrx_transpose.h"
#include "xform_vector.h"

#include <string.h>

#define TABLE 0x0C19D5B0u
#define SRC2  0x0C0EA600u   /* the second transform's source (r4) */
#define DST2  0x0C058FE0u   /* the second transform's destination (r5) */

void vf3_native_world_reset(vf3_native_aim *a)
{
    /* 1. transpose XMTRX */
    vf3_native_matrix_transpose(a);

    /* 2. transform the vector at TABLE + 0x68 into TABLE + 0x80  */
    a->r[4] = TABLE + 0x68u;
    a->r[5] = TABLE + 0x80u;
    vf3_native_xform_vector(a);

    /* 3. transform the vector at 0x0C0EA600 into 0x0C058FE0 */
    a->r[4] = SRC2;
    a->r[5] = DST2;
    vf3_native_xform_vector(a);

    /* 4. transpose XMTRX back (the tail call) */
    vf3_native_matrix_transpose(a);
}
