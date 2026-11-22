/* edge_probe.h - native port of 0x8C06E31C (edge_probe) on the
 * `vf3_native_aim` context.
 *
 * See edge_probe.c and docs/re/native_edge_probe.md. */
#ifndef VF3_NATIVE_EDGE_PROBE_H
#define VF3_NATIVE_EDGE_PROBE_H

#include "motion_aim.h"

/* Run 0x8C06E31C (edge_probe).  r4 = fighter object (angle at +0x1394 as a
 * signed word, probe origin at +0x430/+0x438).  For each of four quarter-turn
 * directions a ray of length 100 is cast from the origin against the stage
 * outline; the first edge it crosses wins and its distance and direction are
 * written to the object at the offsets from the halfword table at 0x0C119688.
 * The only guest callee is the already-native atan_table (0x8C069624). */
void vf3_native_edge_probe(vf3_native_aim *a);

#endif /* VF3_NATIVE_EDGE_PROBE_H */
