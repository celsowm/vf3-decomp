/* entry_copy.h - native port of the table-entry copy into two places
 * (0x8C06D7D6), operating on the `vf3_native_aim` context.  See entry_copy.c
 * and docs/re/native_entry_copy.md. */
#ifndef VF3_NATIVE_ENTRY_COPY_H
#define VF3_NATIVE_ENTRY_COPY_H

#include "aim_math.h"

/* Run 0x8C06D7D6.  Look a sixty-four-byte table entry up by the whole index
 * byte (256 entries) and copy some of its fields into the structure the pool
 * points at, twice: once at each of the two signed halfword offsets the pool
 * holds (so they can point below the structure).  The three bytes at the
 * entry's +5/+6/+7 go into the structure at each offset and at +1/+2; the
 * entry's five floats go to two groups (FR5 from +28 at off-20, FR8 from +32
 * at off-16, FR6 from +36 at off-4; FR7 from +24 at off-12, FR4 from +16 at
 * off-16).  It calls nobody, keeps **no stack frame** and uses the FR bank.
 * See docs/re/native_entry_copy.md. */
void vf3_native_entry_copy(vf3_native_aim *a);

#endif /* VF3_NATIVE_ENTRY_COPY_H */
