/* vertex_classify.h - native port of the strip point-classify leaf
 * 0x8C048EC0 on the `vf3_native_aim` context.
 *
 * See vertex_classify.c and docs/re/native_vertex_classify.md. */
#ifndef VF3_NATIVE_VERTEX_CLASSIFY_H
#define VF3_NATIVE_VERTEX_CLASSIFY_H

#include "motion_aim.h"

/* Run 0x8C048EC0 (vertex_classify).  A self-contained FP leaf (call-free, no
 * stack frame): it transforms three consecutive strip point records through
 * XMTRX as (x, y, z, 1) and records, in r9's lowest three bits, which lie
 * behind the clip plane (r12).  On return r4 and r1 are the original record
 * pointer, r0 and FPUL the third (first) point's transformed w, and r9 holds
 * the three rotated outcode bits (the last one shifted into T, i.e. SR bit
 * 0).  FR0..FR3 hold the second point transformed, FR4..FR7 the first.
 * XMTRX is untouched. */
int vf3_native_vertex_classify(vf3_native_aim *a);

#endif /* VF3_NATIVE_VERTEX_CLASSIFY_H */
