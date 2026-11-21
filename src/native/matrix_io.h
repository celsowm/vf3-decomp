/* matrix_io.h - native ports of the matrix store/load leaves
 * (0x8C03B620 / 0x8C03BD80), operating on the `vf3_native_aim` context.
 *
 * See matrix_io.c and docs/re/native_matrix_io.md. */
#ifndef VF3_NATIVE_MATRIX_IO_H
#define VF3_NATIVE_MATRIX_IO_H

#include "motion_aim.h"
#include "aim_math.h"

/* Run 0x8C03B620.  Self-contained leaf.  dest = r4, or the matrix stack top
 * (*(0x0C19D2EC)) when r4 == 0; XMTRX (16 words) is written there; r0 and r4
 * both become dest.  Every other register, SR and pr are untouched.  See
 * docs/re/native_matrix_io.md. */
void vf3_native_matrix_store(vf3_native_aim *a);

/* Run 0x8C03BD80.  Self-contained leaf.  src = r4, or the matrix stack top
 * (*(0x0C19D2EC)) when r4 == 0; XMTRX is loaded from the 16 words at src and
 * r4 becomes src + 64.  Every other register, SR and pr are untouched.  See
 * docs/re/native_matrix_io.md. */
void vf3_native_matrix_load(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_IO_H */
