#ifndef VF3_NATIVE_SPHERE_H
#define VF3_NATIVE_SPHERE_H

#include "motion_aim.h"

/* Native ports of the sphere / point-contact collision family the fight
 * engine uses to sweep a point against a capsule-like segment and a target's
 * segment table:
 *
 *   0x8C093A9C  sphere_resolve  - the callee of the other two
 *   0x8C09382A  sphere_segment  - sweep a point against one segment
 *   0x8C09363A  point_contact   - walk a target record's segment table
 *
 * The resolver, segment routine, and point-contact entry are implemented in
 * sphere.c. Integration into the higher-level native fight loop remains
 * outstanding.
 *
 * They run under the same FPSCR as the readable authority (e.g. 0 for
 * round-to-nearest / no FTZ, where the guest FP helpers reduce to plain IEEE
 * float ops, sqrtf, 1.0f/sqrtf and a double-accumulated dot).  The native
 * transcribes the same FR sequences so the register file and the FR bank end
 * in the same state the readable entry leaves them.
 *
 * See docs/re/native_sphere.md. */

/* 0x8C093A9C.  r4 = point (vec3, corrected in place), r5 = anchor (vec3),
 * r6 -> hit flags word, fr4 = dist (float).  d = point - anchor; when |d| <
 * dist the point is pushed out to dist along d (point = d*dist/|d| + anchor)
 * and bit 0x100 is OR-ed into [r6]; r0 is left as [r6] either way. */
void vf3_native_sphere_resolve(vf3_native_aim *a);

/* 0x8C09382A.  r4 -> point (vec3, moved in place), r5 -> vec3 receiving the
 * contact, r6 -> dist float, r7 -> limit float; stack [sp] / [sp+4] / [sp+8]:
 * the segment record pointer, the hit-flags word, and the record base.  See
 * the readable sphere_segment.c for the field layout. */
void vf3_native_sphere_segment(vf3_native_aim *a);

/* 0x8C09363A.  r4 -> mover, r5 -> target record, r6 -> point (vec3), r7 ->
 * centre (vec3); [sp+8] -> the hit-flags word.  See the readable
 * point_contact.c for the segment-table walk. */
void vf3_native_point_contact(vf3_native_aim *a);

#endif
