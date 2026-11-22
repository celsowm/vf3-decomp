/* clip_emit_slot.h - native port of the clip-emit slot helper 0x8C048C80 on
 * the `vf3_native_aim` context.
 *
 * See clip_emit_slot.c and docs/re/native_clip_emit_slot.md. */
#ifndef VF3_NATIVE_CLIP_EMIT_SLOT_H
#define VF3_NATIVE_CLIP_EMIT_SLOT_H

#include "motion_aim.h"

/* Run 0x8C048C80 (clip_emit_slot).  A self-contained, call-free FP leaf: it
 * pushes ring slot r0&3 to the store queue at r6, scaling its y' and z' by
 * the reciprocal 1/x' first, and writes the strip's control word (the slot's
 * own address, or 0xF0000000 when SR.T is set) in the first slot word.
 * See clip_emit_slot.c for the full contract.  Returns 1 on success, 0 on a
 * rejected FPSCR (unsupported or SZ already on). */
int vf3_native_clip_emit_slot(vf3_native_aim *a);

#endif /* VF3_NATIVE_CLIP_EMIT_SLOT_H */
