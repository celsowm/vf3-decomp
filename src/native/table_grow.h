/* table_grow.h - native port of the table grower (0x8C044C7C), operating on
 * the `vf3_native_aim` context.
 *
 * See table_grow.c and docs/re/native_table_grow.md. */
#ifndef VF3_NATIVE_TABLE_GROW_H
#define VF3_NATIVE_TABLE_GROW_H

#include "aim_math.h"

/* Run 0x8C044C7C.  Add N entries (r4) to two arrays behind one header:
 *
 *   * the *first* array holds strided entries.  Its pointer moves on by the
 *     stride (the header's field twelve bytes past the slot) and the new
 *     entries get the fill value out of the literal pool;
 *   * the *second* array holds plain entries.  Its count becomes N and its
 *     pointer moves on by N words.
 *
 * The header sits behind a global (0x0c044d44): the global holds the header's
 * address and the header's first word holds the base the slots are measured
 * from.  The three slots - the first array's (0x0c044d16), the fill value
 * (0x0c044d18) and the second array's (0x0c044d1a) - are halfwords in the
 * literal pool, read at run time.  The loop that fills the first array runs
 * only while the count is positive; the second array's count and pointer move
 * regardless (a negative count makes the pointer move *backwards*).  The
 * answer is 0.  The leaf touches no stack.  See docs/re/native_table_grow.md. */
void vf3_native_table_grow(vf3_native_aim *a);

#endif /* VF3_NATIVE_TABLE_GROW_H */
