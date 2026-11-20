/* byte_decode.h - native port of the word decoder (0x8C04538A), operating on
 * the `vf3_native_aim` context.
 *
 * See byte_decode.c and docs/re/native_byte_decode.md. */
#ifndef VF3_NATIVE_BYTE_DECODE_H
#define VF3_NATIVE_BYTE_DECODE_H

#include "aim_math.h"

/* Run 0x8C04538A.  The engine calls this with a word on the caller's stack
 * (r5).  The leaf pops that word, pushes it on its own stack (r15), and copies
 * its four bytes into the object (r4) at +8..+11 - in the natural order, or
 * turned around, depending on a table.  The first byte of the object (+8) then
 * decides the answer, written at the object's +20: -1 when the byte equals the
 * mark, the caller's *next* word when the byte is at or above the limit, zero
 * otherwise.  r15 restores to the entry sp.
 *
 * The mark, the limit, the table's base and the table are in the literal pool
 * (0x0c045448/4a/4c/454), read at run time; the table's base is a **signed
 * halfword** added to the table's first word.  The bytes are read back out of
 * the stack (the push is part of the contract).  This leaf calls nobody, uses
 * no FPU and keeps no callee-saved frame.  See docs/re/native_byte_decode.md. */
void vf3_native_byte_decode(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_BYTE_DECODE_H */
