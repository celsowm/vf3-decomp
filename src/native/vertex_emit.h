#ifndef VF3_NATIVE_VERTEX_EMIT_H
#define VF3_NATIVE_VERTEX_EMIT_H

/* Native port of the transformed-vertex emitters of the strip transformers:
 * 0x8C048BE0 (vertex_emit_sq, into the store queue) and 0x8C048C20
 * (vertex_emit_ring, into the clip ring). */
#include "motion_aim.h"

/* emit into slot (r11 & 3) of the 4-slot ring at 0x0C1A5960.  Leaves r0 =
 * offset, r10 = the slot's low address.  See vertex_emit_ring.c. */
void vf3_native_vertex_emit_ring(vf3_native_aim *a);

#endif /* VF3_NATIVE_VERTEX_EMIT_H */
