#ifndef VF3_NATIVE_VERTEX_EMIT_SQ_H
#define VF3_NATIVE_VERTEX_EMIT_SQ_H

/* Native port of the store-queue transformed-vertex emitter of the strip
 * transformers: 0x8C048BE0 (vertex_emit_sq). */
#include "motion_aim.h"

/* perspective-scale y',z' and write the vertex into the store queue at r6.
 * See vertex_emit_sq.c. */
void vf3_native_vertex_emit_sq(vf3_native_aim *a);

#endif /* VF3_NATIVE_VERTEX_EMIT_SQ_H */
