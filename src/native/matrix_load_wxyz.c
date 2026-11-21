/* matrix_load_wxyz.c - SH-4 0x8C03EFB0 matrix_load_wxyz, natively.
 *
 * A plain-C transcription of the readable port src/fight/matrix_lib.c
 * (`vf3_matrix_load_wxyz_entry`) onto `vf3_native_aim`.  The guest keeps the
 * current transform (XMTRX) in the XF bank - v[37..52] in a readable state,
 * `a->xm[16]` here.
 *
 * A self-contained leaf (call-free, no stack frame, no FPU math).  Loads the
 * matrix at r4 into XMTRX with every column rotated to (w, x, y) and a
 * negated w behind it: a column (a b c d) becomes (d a b -d), where the
 * third word c is read from RAM but dropped.  r4 advances by 64 bytes.
 *
 * No general register besides r4; r15 and SR untouched.  The return pops pr.
 * See docs/re/native_matrix_load_wxyz.md. */
#include "matrix_load_wxyz.h"

#include "aim_math.h"

#define R(n) (a->r[(n)])

#define MATRIX_BYTES 64u

void vf3_native_matrix_load_wxyz(vf3_native_aim *a)
{
    const uint32_t src = R(4);
    for (int c = 0; c < 4; ++c) {
        const uint32_t av = vf3_aim_u32(a, src + 16u * (uint32_t)c);
        const uint32_t b = vf3_aim_u32(a, src + 16u * (uint32_t)c + 4u);
        const uint32_t cc = vf3_aim_u32(a, src + 16u * (uint32_t)c + 8u);
        const uint32_t d = vf3_aim_u32(a, src + 16u * (uint32_t)c + 12u);
        (void)cc;
        a->xm[4 * c] = vf3_aim_fbits(d);
        a->xm[4 * c + 1] = vf3_aim_fbits(av);
        a->xm[4 * c + 2] = vf3_aim_fbits(b);
        a->xm[4 * c + 3] = vf3_aim_fbits(d ^ 0x80000000u);
    }
    R(4) = src + MATRIX_BYTES;
}
