#ifndef VF3_NATIVE_CLAMP_CELL_H
#define VF3_NATIVE_CLAMP_CELL_H

/* Native port of the clamp-cell leaf 0x8C055B28 (vf3_native_clamp_cell). */
#include "aim_math.h"

/* Clamp a cell value and store it scaled by four.
 *
 *   R(4) -> a cell whose halfword at +2 is the value.
 *
 * Clamps the sign-extended halfword at R(4)+2 to a cell number (0..9, with
 * 17 and above giving 10), stores four times it at the global 0x0C058FDC,
 * advances R(4) by 4, and tail-transfers to pr.  pr and r15 are untouched.
 */
void vf3_native_clamp_cell(vf3_native_aim *a);

#endif /* VF3_NATIVE_CLAMP_CELL_H */
