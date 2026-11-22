/* vertex_lit.h - native port of the strip vertex-lighting leaf
 * 0x8C047EA0 on the `vf3_native_aim` context.
 *
 * See vertex_lit.c and docs/re/native_vertex_lit.md. */
#ifndef VF3_NATIVE_VERTEX_LIT_H
#define VF3_NATIVE_VERTEX_LIT_H

#include "motion_aim.h"

/* Run 0x8C047EA0 (vertex_lit).  A self-contained FP leaf (call-free, no stack
 * frame): it transforms one strip vertex record (r4) through XMTRX as
 * (x, y, z, 1), folds its lighting terms, and ends with T = (r12 > the
 * transformed w, as unsigned bits) and r4 = record + 32.  r8 selects how many
 * squarings the specular ladder runs.  On return r0 holds w, FR0..FR7 and
 * FR11 the lighting state, FR2 = FR15 + max(FR3, 0).  XMTRX, FR8..FR10 and
 * FR12..FR15 are untouched. */
int vf3_native_vertex_lit(vf3_native_aim *a);

#endif /* VF3_NATIVE_VERTEX_LIT_H */
