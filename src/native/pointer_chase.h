#ifndef VF3_NATIVE_POINTER_CHASE_H
#define VF3_NATIVE_POINTER_CHASE_H

/* Native port of the pointer-chase leaf 0x8C035264
 * (vf3_native_pointer_chase). */
#include "aim_math.h"

/* Chase a pointer and read a field at offset 40.
 *
 * Reads a pointer from the literal pool at 0x0c03548c, dereferences it to get
 * an object, reads the word at object+40, and tail-transfers to pr (r16).
 * The leaf is a tail transfer, so pr is left untouched and the C port simply
 * returns; r0 ends up the field value, r3 the pool-loaded pointer.
 */
void vf3_native_pointer_chase(vf3_native_aim *a);

#endif /* VF3_NATIVE_POINTER_CHASE_H */
