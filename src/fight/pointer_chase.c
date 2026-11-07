/* pointer_chase.c - SH-4 0x8C035264: reads a pointer from a fixed literal pool
 * address, dereferences it, and reads a field at offset 40.
 *
 * The function:
 *   r3 = read(0x0c03548c)
 *   r0 = read(r3)
 *   r0 = read(r0 + 40)
 *   return (jump to r16)
 *
 * This is a leaf function with no calls, no FP, no stack traffic.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

int vf3_pointer_chase_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* the literal pool address holding the pointer to chase */
    const uint32_t pool_addr = 0x0c03548cu;

    /* r3 = read(pool_addr) */
    R(3) = vf3_mem_u32(ram, pool_addr);

    /* r0 = read(r3) */
    R(0) = vf3_mem_u32(ram, R(3));

    /* r0 = read(r0 + 40) */
    R(0) = vf3_mem_u32(ram, R(0) + 40u);

    /* return through r16 */
    s->pc = R(16);
    return ram->oob == 0;
}
