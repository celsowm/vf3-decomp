/* matrix_copy.c - SH-4 0x8C03B530 matrix_copy, natively.
 *
 * A plain-C transcription of the readable port src/fight/matrix_lib.c
 * (`vf3_matrix_copy_entry`) onto `vf3_native_aim`.  The guest keeps the
 * current transform (XMTRX) in the XF bank - v[37..52] in a readable state,
 * `a->xm[16]` here.
 *
 * A self-contained leaf (call-free, no FPU math beyond the copied word's FR3
 * store, no stack frame - the r14 "push" only writes [sp-4] without moving
 * sp).  dst = r4, src = r5:
 *
 *   - a dead r14 push first: [sp-4] = r14.
 *   - if dst == 0:  if src == 0, do nothing more;  else XMTRX = matrix(src)
 *     and r4 = src + 64            (the matrix_load behaviour).
 *   - else if src == 0:  write XMTRX to dst, r0 = r4 = dst
 *                             (the matrix_store behaviour).
 *   - else:  copy the 16 words src -> dst; FR3 = the last copied word;
 *     r4 = 0, r5 = dst + 64, r6 = src + 64.
 *
 * r14, r15 and SR are restored/untouched (r14 keeps its entry value, r15 not
 * moved).  The return pops pr.  The null-dst/null-src arms are the native
 * matrix_load / matrix_store leaves already proved in matrix_io.c.
 *
 * See docs/re/native_matrix_copy.md. */
#include "matrix_copy.h"

#include "matrix_io.h"

#define R(n) (a->r[(n)])

#define MATRIX_WORDS 16
#define MATRIX_BYTES 64u

void vf3_native_matrix_copy(vf3_native_aim *a)
{
    const uint32_t dst = R(4), src = R(5);

    /* dead r14 push - writes [sp-4] without moving sp */
    vf3_aim_set_u32(a, R(15) - 4u, R(14));

    if (dst == 0) {
        if (src != 0) {
            R(4) = src;
            vf3_native_matrix_load(a);
        }
        return;
    }
    if (src == 0) {
        vf3_native_matrix_store(a);
        return;
    }

    uint32_t word = 0;
    for (int i = 0; i < MATRIX_WORDS; ++i) {
        word = vf3_aim_u32(a, src + 4u * (uint32_t)i);
        vf3_aim_set_u32(a, dst + 4u * (uint32_t)i, word);
    }
    a->fr[3] = vf3_aim_fbits(word);
    R(4) = 0u;
    R(5) = dst + MATRIX_BYTES;
    R(6) = src + MATRIX_BYTES;
}
