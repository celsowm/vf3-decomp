/* quad_node.h - native port of the point-in-quad test 0x8C068FE4
 * (vf3_native_quad_node).  See quad_node.c and docs/re/native_quad_node.md. */
#ifndef VF3_NATIVE_QUAD_NODE_H
#define VF3_NATIVE_QUAD_NODE_H

#include "aim_math.h"

/* 0x8C068FE4: point-in-quad of one relative polygon node.  r4 -> node.  Its
 * only callee is the triangle winding test (0x8C068F92, already natively
 * ported as `vf3_native_tri_winding`), which the port calls directly, so the
 * guest call becomes a direct native call and the port stays self-contained
 * on vf3nativeview. */
void vf3_native_quad_node(vf3_native_aim *a);

#endif /* VF3_NATIVE_QUAD_NODE_H */
