/* matrix_set_translation.c - SH-4 0x8C03CBD0: set the XMTRX translation, natively.
 *
 * A plain-C transcription of the readable port vf3_matrix_set_translation_entry
 * (src/fight/leaf_math.c) onto `vf3_native_aim`.  A call-free, no-stack,
 * integer-only leaf (the three source floats travel as raw 32-bit words):
 *
 *   r4 -> three floats  ->  XMTRX[12] = r4[0], XMTRX[13] = r4[1], XMTRX[14] = r4[2]
 *   r4 += 12
 *
 * XF0..15 are the XMTRX bank (a->xm[16]).  No other register, no SR bit and no
 * FR bank cell is touched.  The native `vf3_aim_set_translation` helper copies
 * the same three words but is a pose-callee utility that does not advance r4
 * and carries no register contract, so this leaf is written out on its own.
 *
 * See docs/re/native_matrix_set_translation.md. */
#include "matrix_set_translation.h"

#include "aim_math.h"

void vf3_native_matrix_set_translation(vf3_native_aim *a)
{
    const uint32_t src = a->r[4];
    a->xm[12] = vf3_aim_fbits(vf3_aim_u32(a, src));
    a->xm[13] = vf3_aim_fbits(vf3_aim_u32(a, src + 4u));
    a->xm[14] = vf3_aim_fbits(vf3_aim_u32(a, src + 8u));
    a->r[4] = src + 12u;
}
