/* matrix_concat_save.h - native port of the concatenate-save leaf 0x8C03C140
 * and the parent leaf 0x8C03C200 on the `vf3_native_aim` context.
 *
 * See matrix_concat_save.c and docs/re/native_matrix_concat_save.md. */
#ifndef VF3_NATIVE_MATRIX_CONCAT_SAVE_H
#define VF3_NATIVE_MATRIX_CONCAT_SAVE_H

#include "motion_aim.h"

/* Run 0x8C03C140 (matrix_concat_save).  Self-contained FP leaf: XMTRX becomes
 * XMTRX * M(r4), where M is the 16 floats at r4, and the banks end up
 * swapped (the old XMTRX shows in FR0..FR11, FPSCR.FR toggles).  The caller's
 * FR12..FR15 are preserved (kept in registers, then put straight back into
 * the new FR bank); the stack pointer makes a round trip of 16 bytes.  r4
 * advances by 64 bytes; r15 and SR are untouched. */
int vf3_native_matrix_concat_save(vf3_native_aim *a);

/* Run 0x8C03C200 (matrix_concat_parent).  r4 is derived as one matrix (64
 * bytes) below the matrix stack top, then matrix_concat_save runs. */
int vf3_native_matrix_concat_parent(vf3_native_aim *a);

#endif /* VF3_NATIVE_MATRIX_CONCAT_SAVE_H */
