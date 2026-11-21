/* matrix_io.c - SH-4 0x8C03B620 matrix_store and 0x8C03BD80 matrix_load,
 * natively.
 *
 * A plain-C transcription of the readable ports src/fight/matrix_lib.c
 * (`vf3_matrix_store_entry` / `vf3_matrix_load_entry`) onto
 * `vf3_native_aim`.  The guest keeps the current transform (XMTRX) in the
 * XF bank - v[37..52] in a readable state, `a->xm[16]` here.
 *
 * Both are self-contained leaves (call-free, no FRU beyond the matrix bank
 * they already own, no stack frame).
 *
 * matrix_store (0x8C03B620):
 *   dest = r4;  if (dest == 0) dest = *(0x0C19D2EC);   (the matrix stack top)
 *   write XMTRX (16 words) to dest;
 *   r0 = dest;  r4 = dest;
 *
 * matrix_load (0x8C03BD80):
 *   src = r4;  if (src == 0) src = *(0x0C19D2EC);      (the matrix stack top)
 *   XMTRX = the 16 words at src;
 *   r4 = src + 64;
 *
 * Everything else is untouched: the other registers, SR, pr.  The return
 * pops pr (the caller's return address).
 *
 * See docs/re/native_matrix_io.md. */
#include "matrix_io.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

#define MATRIX_STACK_PTR 0x0C19D2ECu   /* *(0x0C19D2E4 + 8) */

void vf3_native_matrix_store(vf3_native_aim *a)
{
    const uint32_t dest = R(4) ? R(4) : vf3_aim_u32(a, MATRIX_STACK_PTR);
    for (int i = 0; i < 16; ++i)
        vf3_aim_set_u32(a, dest + 4u * (uint32_t)i, vf3_aim_ubits(a->xm[i]));
    R(0) = dest;
    R(4) = dest;
}

void vf3_native_matrix_load(vf3_native_aim *a)
{
    const uint32_t src = R(4) ? R(4) : vf3_aim_u32(a, MATRIX_STACK_PTR);
    for (int i = 0; i < 16; ++i)
        a->xm[i] = vf3_aim_fbits(vf3_aim_u32(a, src + 4u * (uint32_t)i));
    R(4) = src + 64u;
}
