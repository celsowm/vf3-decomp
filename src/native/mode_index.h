/* mode_index.h - native port of the mode-index switch (0x8C038990),
 * operating on the `vf3_native_aim` context.
 *
 * See mode_index.c and docs/re/native_mode_index.md. */
#ifndef VF3_NATIVE_MODE_INDEX_H
#define VF3_NATIVE_MODE_INDEX_H

#include "aim_math.h"

/* Run 0x8C038990.  The fight engine passes a mode **flag** in r4 and this leaf
 * turns it into an **index** into some table.  Eight flags are known: four are
 * constants (8, 16, 32, 64 -> index 0..3) and four live in the literal pool
 * (read at run time -> index 4..7).  A flag that is none of them is **left
 * alone** (the answer is the flag that came in).
 *
 * The guest compares the four constants against a **copy** of the flag it kept
 * in r0, and the four pool flags against the flag (r4) itself.  The T bit the
 * caller sees is the one of the comparison that answered: set on a hit, clear
 * when no flag matched.  This leaf has no calls, no FPU and no stack frame; the
 * only RAM it touches is the four pool halfwords (read as sign-extended i16).
 * See docs/re/native_mode_index.md. */
void vf3_native_mode_index(vf3_native_aim *a);

#endif /* VF3_NATIVE_MODE_INDEX_H */
