/* record_kind.h - native port of the record kind byte (0x8C078044), operating
 * on the `vf3_native_aim` context.  See record_kind.c and
 * docs/re/native_record_kind.md. */
#ifndef VF3_NATIVE_RECORD_KIND_H
#define VF3_NATIVE_RECORD_KIND_H

#include "aim_math.h"

/* Run 0x8C078044.  Handed a record (r5) and an index into it (r7) and the flag
 * word the caller left in its frame (entry sp+0).  It steps the record's kind
 * byte (pool 0x0c07815A + index), state byte (0x0c07815C + index) and copies
 * the source byte (0x0c07815E) to the dest (0x0c078160 + index) and to +51.
 * The caller's gate word (entry sp+4) and mode word (entry sp+8) decide the
 * kind's fate.  See docs/re/native_record_kind.md for the full contract. */
void vf3_native_record_kind(vf3_native_aim *a);

#endif /* VF3_NATIVE_RECORD_KIND_H */
