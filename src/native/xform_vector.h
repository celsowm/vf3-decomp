/* xform_vector.h - native port of the xform-vector leaf 0x8C03B4B0 on the
 * `vf3_native_aim` context.
 *
 * See xform_vector.c and docs/re/native_xform_vector.md. */
#ifndef VF3_NATIVE_XFORM_VECTOR_H
#define VF3_NATIVE_XFORM_VECTOR_H

#include "motion_aim.h"

/* Run 0x8C03B4B0 (xform_vector).  Self-contained FP leaf (call-free, no
 * stack): it treats the three floats at r4 as a vector, runs it through
 * XMTRX as (x, y, z, 0) via ftrv (rotation only - the w=0 drops the
 * translation) and writes the three results out to r5.  FR4..FR7 end as the
 * transformed vector; r4 advances by 12; r5, FR8..FR15 and r15/SR are
 * untouched. */
int vf3_native_xform_vector(vf3_native_aim *a);

#endif /* VF3_NATIVE_XFORM_VECTOR_H */
