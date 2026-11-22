/* vertex_emit_ring.h - native port of the clip-ring vertex emitter 0x8C048C20
 * on the `vf3_native_aim` context.
 *
 * See vertex_emit_ring.c and docs/re/native_vertex_emit_ring.md. */
#ifndef VF3_NATIVE_VERTEX_EMIT_RING_H
#define VF3_NATIVE_VERTEX_EMIT_RING_H

#include "motion_aim.h"

/* Run 0x8C048C20 (vertex_emit_ring).  A tiny call-free leaf: it packs the
 * lit, transformed vertex (FR4..FR7, r1, r2, FR2, FR3) into slot r11&3 of the
 * 4-slot clip ring at 0x0C1A5960, and leaves r0 = slot*32, r10 = the slot's
 * low address.  Returns 1 on success, 0 on a rejected FPSCR (SZ already on). */
int vf3_native_vertex_emit_ring(vf3_native_aim *a);

#endif /* VF3_NATIVE_VERTEX_EMIT_RING_H */
