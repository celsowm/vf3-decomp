/* status_flags.c - SH-4 0x8C0961F4: the flags word of a record.
 *
 * The engine keeps a record of a dozen words and asks this function for a
 * bitmask of the fields that are set.  The mask (r4) says which bits of a
 * field count as "set"; the record (r5) holds the fields.
 *
 * The guest reads eight fields of the record and puts one bit in the answer
 * for every field that has a bit in common with the mask:
 *
 *   the field at +8   -> 0x04
 *   the field at +12  -> 0x08
 *   the field at +0   -> 0x01
 *   the field at +4   -> 0x02
 *   the field at +24  -> 0x10
 *   the field at +20  -> 0x20
 *   the field at +28  -> 0x40
 *   the field at +32  -> the mask in the literal pool at 0x8C09630A
 *
 * The order is the guest's, and so are the gaps: the record has no field at
 * +16.  The first bit is *assigned* (the guest zeroes the answer first), the
 * rest are or-ed in.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the last bit: the pool holds the mask, not a constant */
#define G_LAST_BIT 0x0c09630au

static void set_t(vf3_matrix_state *s, int value)
{ R(17) = (R(17) & ~1u) | (value != 0); }

int vf3_status_flags_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t rec  = R(5);   /* the record */
    const uint32_t mask = R(4);   /* the mask */
    uint32_t flags = 0u;
    int hit;

    /* the first field: the guest zeroes the answer and assigns the bit */
    R(3) = vf3_mem_u32(ram, rec + 8u);
    hit = (R(3) & mask) != 0;
    set_t(s, !hit);
    if (hit) flags = 0x04u;

    /* the rest: the guest ors the bit in */
    R(3) = vf3_mem_u32(ram, rec + 12u);
    hit = (R(3) & mask) != 0;
    set_t(s, !hit);
    if (hit) { R(1) = 0x08u; flags |= R(1); }

    R(3) = vf3_mem_u32(ram, rec + 0u);
    hit = (R(3) & mask) != 0;
    set_t(s, !hit);
    if (hit) { R(1) = 0x01u; flags |= R(1); }

    R(3) = vf3_mem_u32(ram, rec + 4u);
    hit = (R(3) & mask) != 0;
    set_t(s, !hit);
    if (hit) { R(1) = 0x02u; flags |= R(1); }

    R(3) = vf3_mem_u32(ram, rec + 24u);
    hit = (R(3) & mask) != 0;
    set_t(s, !hit);
    if (hit) { R(1) = 0x10u; flags |= R(1); }

    R(3) = vf3_mem_u32(ram, rec + 20u);
    hit = (R(3) & mask) != 0;
    set_t(s, !hit);
    if (hit) { R(1) = 0x20u; flags |= R(1); }

    R(3) = vf3_mem_u32(ram, rec + 28u);
    hit = (R(3) & mask) != 0;
    set_t(s, !hit);
    if (hit) { R(1) = 0x40u; flags |= R(1); }

    /* the last field takes the mask out of the literal pool - and the pool
     * is only read when the bit is set */
    R(3) = vf3_mem_u32(ram, rec + 32u);
    hit = (R(3) & mask) != 0;
    set_t(s, !hit);
    if (hit) { R(1) = vf3_mem_u16(ram, G_LAST_BIT); flags |= R(1); }

    R(0) = flags;
    R(6) = flags;
    s->pc = R(16);
    return ram->oob == 0;
}
