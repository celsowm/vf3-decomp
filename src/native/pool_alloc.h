#ifndef VF3_NATIVE_POOL_ALLOC_H
#define VF3_NATIVE_POOL_ALLOC_H

/* Native port of the sprite-pool allocator leaf 0x8C07B2BE
 * (vf3_native_pool_alloc). */
#include "aim_math.h"

/* Allocate the next free 68-byte entry out of a layer's pool.
 *
 *   r4 -> the layer: *(layer + 12) is the pool base, the u16 at layer + 42 is
 *          the rotating allocation cursor.
 *
 * Returns the entry's address in r0 (and r5), or 0 with the full-table
 * registers when the pool is exhausted.  Tail-transfer to pr (untouched).
 */
void vf3_native_pool_alloc(vf3_native_aim *a);

#endif /* VF3_NATIVE_POOL_ALLOC_H */
