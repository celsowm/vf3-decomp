#ifndef VF3_NATIVE_TEX_CELL_LOAD_H
#define VF3_NATIVE_TEX_CELL_LOAD_H

/* Native port of the texture-cell loader leaf 0x8C07B4D4
 * (vf3_native_tex_cell_load). */
#include "aim_math.h"

/* Load a texture cell's scratch geometry out of the cell tables.
 *
 *   r4 = cell id -> fills the cell scratch block at 0x0C1B9620, the
 *   reciprocal-scaled UV pair, and leaves r0 = SCRATCH.  Tail-transfer to pr
 *   (untouched).
 */
void vf3_native_tex_cell_load(vf3_native_aim *a);

#endif /* VF3_NATIVE_TEX_CELL_LOAD_H */
