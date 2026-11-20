/* record_copy.h - native port of the record repack (0x8C043A7C), operating on
 * the `vf3_native_aim` context.  See record_copy.c and
 * docs/re/native_record_copy.md. */
#ifndef VF3_NATIVE_RECORD_COPY_H
#define VF3_NATIVE_RECORD_COPY_H

#include "aim_math.h"

/* Run 0x8C043A7C.  Copy twenty-four records from the table (pool 0x0c043b78)
 * into the destination array (pool 0x0c043b74).  The source's records are
 * 0x2c apart with the first at +0x28 of the table's cell; the destination's
 * are 0x18 apart.  Per record the source's bytes 0..3 and 8..11 and its words
 * 16 and 20 become the destination's bytes 0..3 and 4..7 and its words 8 and
 * 12.  The bytes are read sign-extended into the register they travel
 * through.  The loop's exit test is the T bit of a compare the body has
 * already bumped.  It calls nobody, uses no FPU and keeps **no stack frame**.
 * See docs/re/native_record_copy.md. */
void vf3_native_record_copy(vf3_native_aim *a);

#endif /* VF3_NATIVE_RECORD_COPY_H */
