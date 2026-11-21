#ifndef VF3_NATIVE_VERTEX_WRITER_H
#define VF3_NATIVE_VERTEX_WRITER_H

/* Native port of the first two TA-vertex writers of the triangle-strip builder
 * (0x8C056AA0 writer 0, 0x8C056AE0 writer 1). */
#include "motion_aim.h"

/* writer 0: the first vertex, written in place at the cursor (r12).  See
 * vertex_writer0.c. */
void vf3_native_vertex_writer0(vf3_native_aim *a);

/* writer 1: the second vertex, in the slot behind the cursor.  It flushes the
 * previous slot with a store-queue PREF and moves the cursor on by one slot. */
void vf3_native_vertex_writer1(vf3_native_aim *a);

#endif /* VF3_NATIVE_VERTEX_WRITER_H */
