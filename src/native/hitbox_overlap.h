/* hitbox_overlap.h - native port of the fight engine's fighter-vs-fighter
 * capsule overlap scan (0x8C073AAC), in the same spirit as the capsule_chain
 * and body_capsule family: plain C on the `vf3_native_aim` context, no guest
 * SH-4 code at run time.
 *
 * See hitbox_overlap.c and docs/re/native_hitbox_overlap.md. */
#ifndef VF3_NATIVE_HITBOX_OVERLAP_H
#define VF3_NATIVE_HITBOX_OVERLAP_H

#include "aim_math.h"

/* Run 0x8C073AAC.  `out` is r4 (a result block: +48 closest distance as a
 * float, +52 number of overlapping pairs as a byte), `A` r5 and `B` r6 the
 * two fighter objects.  Each holds 28 capsules: a 12-byte segment at the
 * pointer in +0x138C (second end at +0x1390), shared radius tables into the
 * float array at +0x12AC, and a per-capsule hit word at +0x131C that the
 * routine fills in.  On exit the hit words, the radius array(s), the minimum
 * distance and the pair count are written and the saved registers (r8..r14,
 * fr12..fr15, pr) restored. */
void vf3_native_hitbox_overlap(vf3_native_aim *a, uint32_t sp0, uint32_t out,
                               uint32_t A, uint32_t B);

#endif /* VF3_NATIVE_HITBOX_OVERLAP_H */
