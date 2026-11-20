/* move_cap.h - native port of the capped move (0x8C08DD5C), operating on the
 * `vf3_native_aim` context.  See move_cap.c and docs/re/native_move_cap.md. */
#ifndef VF3_NATIVE_MOVE_CAP_H
#define VF3_NATIVE_MOVE_CAP_H

#include "aim_math.h"

/* Run 0x8C08DD5C.  Two positions - the object's at the start of the frame
 * (r4, r5) and the one it has now (the two words r6 and r7 point at).  Moves
 * the current position by the difference, but never by more than the longest
 * movement in the literal pool.  A self-contained FP leaf that keeps a small
 * frame, restores r14, and runs under round-to-nearest (no FTZ). */
void vf3_native_move_cap(vf3_native_aim *a);

#endif /* VF3_NATIVE_MOVE_CAP_H */
