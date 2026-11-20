/* bit_alloc.h - native port of the first-free-bit allocator (0x8C038860),
 * operating on the `vf3_native_aim` context.
 *
 * See bit_alloc.c and docs/re/native_bit_alloc.md. */
#ifndef VF3_NATIVE_BIT_ALLOC_H
#define VF3_NATIVE_BIT_ALLOC_H

#include "aim_math.h"

/* Run 0x8C038860.  The fight engine's first free bit: it hands back the index
 * of the first free bit of a table of 32-bit words and takes that bit while
 * it is there.  A word of 0xffffffff is the table's end marker (an exhausted
 * slot), not a free bit.  The free bit is the lowest clear bit of the word,
 * and the answer is the bit's index in the whole table (word index * 32 +
 * bit number).  A table with no free bit answers -1 and writes nothing.
 *
 * The literal pool holds two pointers read at run time: POOL_COUNT (0x0c0389c8,
 * the address of the count) and POOL_TABLE (0x0c0389cc, the table, whose first
 * entry points at the words).  The guest keeps a frame of six callee-saved
 * registers (r8..r11, r13, r14) on the stack, which the port reproduces - the
 * frame bytes are part of the contract and visible in the RAM the test
 * compares.  The T bit the guest leaves is the last test it made; the port's
 * `set_t` writes a->sr.  See docs/re/native_bit_alloc.md. */
void vf3_native_bit_alloc(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_BIT_ALLOC_H */
