/* pack_expand.h - native port of the packed-attribute expansion (0x8C09D5AE),
 * operating on the `vf3_native_aim` context.
 *
 * See pack_expand.c and docs/re/native_pack_expand.md. */
#ifndef VF3_NATIVE_PACK_EXPAND_H
#define VF3_NATIVE_PACK_EXPAND_H

#include "aim_math.h"

/* Run 0x8C09D5AE.  r4 -> the record.  The function expands the **sixteen
 * packed bytes** the record's table entry points at into **sixteen groups of
 * four two-bit fields**, written to a destination the record carries.
 *
 * The pieces:
 *   * a **table** of twelve-byte entries.  The literal pool holds the address
 *     of a pointer (0x0c09d6dc), and the pointer the table's base.  The
 *     record's halfword at +60 says which entry the record uses (from one);
 *   * each entry carries three offsets from the table's base: the packed
 *     bytes, and two more places the record remembers;
 *   * the record also carries the destination: a pointer at the offset the
 *     pool names (0x0c09d6d0), to a block the expansion writes into.
 *
 * The pool's three entries are read at run time.  The guest pushes the record
 * on its stack and pops it again without using it (the stack pointer's round
 * trip is visible), then pushes the two remembered words before the loop.
 * The record keeps the packed byte twice: the byte moves up by 29, and the
 * record's own byte takes bit 14 of the source's head.  The loop ends with
 * the counter at 16, so the T bit left is set.  r15 restores to the entry sp.
 * See docs/re/native_pack_expand.md. */
void vf3_native_pack_expand(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_PACK_EXPAND_H */
