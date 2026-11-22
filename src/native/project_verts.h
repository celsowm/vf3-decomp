/* project_verts.h - native port of the vertex project+light leaf 0x8C058EA0
 * on the `vf3_native_aim` context.
 *
 * See project_verts.c and docs/re/native_project_verts.md. */
#ifndef VF3_NATIVE_PROJECT_VERTS_H
#define VF3_NATIVE_PROJECT_VERTS_H

#include "motion_aim.h"

/* Run 0x8C058EA0 (project_verts).  A self-contained FP leaf (call-free): it
 * projects and lights a run of vertices into the 16-byte output records.
 *
 *   r4 = source stream (six floats per vertex: position xyz, normal xyz),
 *   r6 = vertex count, r7 -> the mode word (bit 2 selects the light-vector
 *   variant).  XMTRX = the view/projection matrix.
 *
 * Per vertex: (x, y, z, 1) goes through XMTRX, the reciprocal of w is formed,
 * and a 16-byte record is written to the output cursor:
 *
 *   +0 x/w   +4 y/w   +8 1/w   +C  max(dot(normal, light), 0) + ambient
 *
 * See project_verts.c for the register/FM side effects (r0..r6, SR.T) and
 * the RAM cursors it advances. */
void vf3_native_project_verts(vf3_native_aim *a);

#endif /* VF3_NATIVE_PROJECT_VERTS_H */
