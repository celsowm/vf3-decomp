/* tri_winding.h - native port of the triangle winding test (0x8C068F92),
 * operating on the `vf3_native_aim` context.
 *
 * See tri_winding.c and docs/re/native_tri_winding.md. */
#ifndef VF3_NATIVE_TRI_WINDING_H
#define VF3_NATIVE_TRI_WINDING_H

#include "aim_math.h"

/* Run 0x8C068F92.  A pure-FR, call-free, no-stack, no-RAM leaf.  It reads the
 * three points as (x,y) pairs in FR4/FR5, FR6/FR7 and FR8/FR9 and returns
 * 2 for a counter-clockwise winding (positive area), 1 for a degenerate
 * (zero area) triangle and 4 for a negative (or NaN) area.  Only r0 is a
 * result; every other register (including the FR bank) is scratch and may
 * be left anywhere except r0.  pr and the stack pointer are untouched.
 * See docs/re/native_tri_winding.md. */
void vf3_native_tri_winding(vf3_native_aim *a);

#endif /* VF3_NATIVE_TRI_WINDING_H */
