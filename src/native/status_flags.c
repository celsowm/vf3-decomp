/* status_flags.c - SH-4 0x8C0961F4: the flags word of a record, natively.
 *
 * A plain-C transcription of the readable port src/fight/status_flags.c
 * (`vf3_status_flags_entry`).  It operates on `vf3_native_aim`: the flat RAM
 * and the register file.  A self-contained integer leaf - it calls nobody,
 * uses no FPU and keeps **no stack frame**.
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
 *   the field at +32  -> the mask in the literal pool at 0x0c09630a
 *
 * The order is the guest's, and so are the gaps: the record has no field at
 * +16.  The first bit is *assigned* (the guest zeroes the answer first), the
 * rest are or-ed in.  The T bit the caller sees is the last comparison's - so
 * it is set when the field at +32 has **no** bit in common with the mask.
 *
 * See docs/re/native_status_flags.md. */
#include "status_flags.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* the last bit's mask: the pool holds it, not a constant */
#define G_LAST_BIT 0x0c09630au

void vf3_native_status_flags(vf3_native_aim *a)
{
    const uint32_t rec  = R(5);   /* the record */
    const uint32_t mask = R(4);   /* the mask */
    uint32_t flags = 0u;
    int hit;

    /* the first field: the guest zeroes the answer and assigns the bit */
    R(3) = vf3_aim_u32(a, rec + 8u);
    hit = (R(3) & mask) != 0;
    set_t(a, !hit);
    if (hit) flags = 0x04u;

    /* the rest: the guest ors the bit in */
    R(3) = vf3_aim_u32(a, rec + 12u);
    hit = (R(3) & mask) != 0;
    set_t(a, !hit);
    if (hit) { R(1) = 0x08u; flags |= R(1); }

    R(3) = vf3_aim_u32(a, rec + 0u);
    hit = (R(3) & mask) != 0;
    set_t(a, !hit);
    if (hit) { R(1) = 0x01u; flags |= R(1); }

    R(3) = vf3_aim_u32(a, rec + 4u);
    hit = (R(3) & mask) != 0;
    set_t(a, !hit);
    if (hit) { R(1) = 0x02u; flags |= R(1); }

    R(3) = vf3_aim_u32(a, rec + 24u);
    hit = (R(3) & mask) != 0;
    set_t(a, !hit);
    if (hit) { R(1) = 0x10u; flags |= R(1); }

    R(3) = vf3_aim_u32(a, rec + 20u);
    hit = (R(3) & mask) != 0;
    set_t(a, !hit);
    if (hit) { R(1) = 0x20u; flags |= R(1); }

    R(3) = vf3_aim_u32(a, rec + 28u);
    hit = (R(3) & mask) != 0;
    set_t(a, !hit);
    if (hit) { R(1) = 0x40u; flags |= R(1); }

    /* the last field takes the mask out of the literal pool - and the pool
     * is only read when the field hits */
    R(3) = vf3_aim_u32(a, rec + 32u);
    hit = (R(3) & mask) != 0;
    set_t(a, !hit);
    if (hit) { R(1) = (uint32_t)vf3_aim_h16(a, G_LAST_BIT); flags |= R(1); }

    R(0) = flags;
    R(6) = flags;
}
