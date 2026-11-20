/* table_probe.h - native port of the indexed table probe (0x8C040378),
 * operating on the `vf3_native_aim` context.
 *
 * See table_probe.c and docs/re/native_table_probe.md. */
#ifndef VF3_NATIVE_TABLE_PROBE_H
#define VF3_NATIVE_TABLE_PROBE_H

#include "aim_math.h"

/* Run 0x8C040378.  A self-contained 62 B leaf, call-free, integer-only, no
 * FP.  r4 is an index.  The body stores r4 at sp-4 (a transient stack slot
 * that is part of the captured RAM; r15 is restored at the return, so it is
 * net unchanged), reads it back into r2, and returns a status in r0:
 *
 *   * r4 < 0   -> -1, T clear (r1 and r3 keep their entry values);
 *   * r4 >= 8  -> -1, T set   (r1 is left as 8, r3 = r4);
 *   * otherwise-> val = tbl[12 * r4] (stride twelve, base from the pool at
 *               0x0c0403bc), r1 = the table base, r3 = r4: val == 0xffffffff
 *               gives -2 with T set, any other entry gives 0 with T clear.
 *
 * See docs/re/native_table_probe.md. */
void vf3_native_table_probe(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_TABLE_PROBE_H */
