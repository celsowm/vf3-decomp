/* vec_add_pair.h - native port of 0x8C092A70 (vec_add_pair), operating on the
 * `vf3_native_aim` context.  See vec_add_pair.c and docs/re/native_vec_add_pair.md. */
#ifndef VF3_NATIVE_VEC_ADD_PAIR_H
#define VF3_NATIVE_VEC_ADD_PAIR_H

#include "aim_math.h"

/* Run 0x8C092A70 (vec_add_pair).  A self-contained FP leaf (call-free, uses a
 * 12-byte frame for r5/r6/r7).  Unless the global word at 0x0C29B868 has bit
 * 0x04000000 set and the byte at r4+97 is 11, D += A + 24 (the vector 24 bytes
 * into the 12-byte-stride array at A); then, unconditionally, D.y += B.y.
 * r4 = object, r5 = A, r6 = B, r7 = D.  See docs/re/native_vec_add_pair.md. */
void vf3_native_vec_add_pair(vf3_native_aim *a);

#endif /* VF3_NATIVE_VEC_ADD_PAIR_H */
