/* counter_advance.c - SH-4 0x8C08B338: the animation frame counters.
 *
 * The engine keeps three counters in a record - seven bits, two bits and four
 * bits wide - and one counter in a block.  This function advances them:
 *
 *  - the first counter steps by one and keeps seven bits;
 *  - the low bit of that *incremented* counter is carried into the two narrow
 *    counters and into the block's counter - so the wide counter's own wrap
 *    (127 to zero) carries nothing, and the narrow counters move on every
 *    other step;
 *  - the block's counter wraps at 127.
 *
 * A global says whether the counters move at all: the counters advance only
 * when the value it points at has *no* bit in common with the mask.
 *
 * The three globals are in the literal pool, so the port reads the same
 * addresses the guest reads.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the globals */
#define G_ENABLE 0x0c08b3f0u   /* the global that says "go" */
#define G_MASK   0x0c08b3ecu   /* the mask the global is tested against */
#define G_BLOCK  0x0c08b3f4u   /* the block the block's counter lives in */

/* the block counter's slot */
#define COUNTER_OFFSET 0x54u

/* the widths of the three record counters */
#define WIDE_MASK   0x7fu
#define NARROW_MASK 0x03u
#define FOUR_MASK   0x0fu

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

int vf3_counter_advance_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* the global says whether the counters move: they move only when its
     * value has no bit in common with the mask */
    R(1) = vf3_mem_u32(ram, G_ENABLE);
    R(3) = vf3_mem_u32(ram, G_MASK);
    R(2) = vf3_mem_u32(ram, R(1));
    set_t(s, (R(3) & R(2)) == 0);
    if ((R(3) & R(2)) != 0) {
        /* nothing to do */
        s->pc = R(16);
        return ram->oob == 0;
    }

    /* the first counter: seven bits wide, and the bit that falls out of it */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(4) + 12u);
    R(6) = 1u;
    R(3) = WIDE_MASK;
    R(5) = R(0);
    R(5) += 1u;
    R(6) &= R(5);
    R(5) &= R(3);
    R(0) = R(5);
    vf3_mem_set_u16(ram, R(4) + 12u, (uint16_t)R(0));

    /* the block's counter: it wraps at 127 */
    R(2) = vf3_mem_u32(ram, G_BLOCK);
    R(0) = COUNTER_OFFSET;
    R(1) = 0x7fu;
    R(7) = vf3_mem_u32(ram, R(2));
    R(5) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(7) + R(0));
    R(5) += R(6);
    R(3) = (uint32_t)(int32_t)(int16_t)R(5);
    set_t(s, (int32_t)R(3) >= (int32_t)R(1));
    if ((int32_t)R(3) >= (int32_t)R(1)) R(5) = 0u;
    vf3_mem_set_u16(ram, R(7) + R(0), (uint16_t)R(5));

    /* and the two narrow counters */
    R(3) = NARROW_MASK;
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(4) + 14u);
    R(2) = FOUR_MASK;
    R(5) = R(0);
    R(5) += R(6);
    R(5) &= R(3);
    R(0) = R(5);
    vf3_mem_set_u16(ram, R(4) + 14u, (uint16_t)R(0));

    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(4) + 16u);
    R(5) = R(0);
    R(5) += R(6);
    R(5) &= R(2);
    R(0) = R(5);
    vf3_mem_set_u16(ram, R(4) + 16u, (uint16_t)R(0));

    s->pc = R(16);
    return ram->oob == 0;
}
