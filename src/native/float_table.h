/* float_table.h - native port of the table-entry unpack into two structures
 * (0x8C06D792), operating on the `vf3_native_aim` context.  See float_table.c
 * and docs/re/native_float_table.md. */
#ifndef VF3_NATIVE_FLOAT_TABLE_H
#define VF3_NATIVE_FLOAT_TABLE_H

#include "aim_math.h"

/* Run 0x8C06D792.  Look a sixty-four-byte table entry up by the low **four**
 * bits of the index byte and unpack it into two structures: the entry's two
 * halfwords (+12/+14, swapped) go into the first structure at +34 and +32, and
 * the entry's three floats (+16/+20/+24) go into the second structure at the
 * signed halfword offset the pool holds, at eight bytes below it and at four
 * below that.  It calls nobody, keeps **no stack frame** and uses the FR bank.
 * See docs/re/native_float_table.md. */
void vf3_native_float_table(vf3_native_aim *a);

#endif /* VF3_NATIVE_FLOAT_TABLE_H */
