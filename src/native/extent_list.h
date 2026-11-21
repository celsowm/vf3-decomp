/* extent_list.h - native port of 0x8C0CC432 (extent_list), operating on the
 * `vf3_native_aim` context.  See extent_list.c and
 * docs/re/native_extent_list.md. */
#ifndef VF3_NATIVE_EXTENT_LIST_H
#define VF3_NATIVE_EXTENT_LIST_H

#include "aim_math.h"

/* Run 0x8C0CC432 (extent_list).  An orchestration leaf: it walks the object's
 * list of 32-byte extent records (starting at object + 0x200) and, for every
 * live record (bit 0 of its halfword at +0x1A), steps it through
 * frame_counter_step (0x8C0CC334) and then extent_flip (0x8C0CC3F0).  The two
 * callees ride the shared FR bank, the third table is passed on the caller's
 * stack (the slot just below the frame), and the flag halfword is written back
 * from the frame the two callees share.  Both callees are themselves natively
 * ported (frame_counter_step.c / extent_flip.c), so this leaf stays
 * self-contained.  The observable contract (the readable registry's mask) is
 * r0 and the T bit.  See docs/re/native_extent_list.md. */
void vf3_native_extent_list(vf3_native_aim *a);

#endif /* VF3_NATIVE_EXTENT_LIST_H */
