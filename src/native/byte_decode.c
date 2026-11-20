/* byte_decode.c - SH-4 0x8C04538A: the fight engine's word decoder, natively.
 *
 * A plain-C transcription of the readable port src/fight/byte_decode.c
 * (`vf3_byte_decode_entry`).  It operates on `vf3_native_aim`: the flat RAM
 * and the register file.  A self-contained leaf - it calls nobody, uses no FPU
 * and keeps no callee-saved frame.
 *
 * The engine calls this with a word on the caller's stack (r5).  The function
 * pops that word, pushes it on its own stack (r15), and copies its four bytes
 * into the object (r4) at +8..+11 - in the natural order, or turned around,
 * depending on what a table says.
 *
 * The first byte of the object (+8) then decides the answer, which the function
 * writes at the object's +20:
 *
 *  - the byte equals the mark: the answer is -1;
 *  - the byte is at or above the limit: the answer is the *next* word on the
 *    caller's stack;
 *  - otherwise the answer is zero.
 *
 * The mark, the limit, the table's base and the table are in the literal pool,
 * so the port reads the same addresses the guest reads.  The table's base is a
 * **signed halfword** added to the table's first word, so a negative base
 * reads below the table.
 *
 * Two details the port keeps: the bytes are read back **out of the stack** (the
 * push is part of the contract), and each of the three answer arms ends in a
 * branch whose **delay slot is the store** (and the T bit).
 *
 * See docs/re/native_byte_decode.md. */
#include "byte_decode.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

/* byte writer (the native aim API has set_u16/set_u32 but no set_u8) */
static inline void w8(vf3_native_aim *a, uint32_t addr, uint8_t v)
{ ((uint8_t *)a->ram)[addr - a->ram_base] = v; }

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* the literal pool */
#define G_MARK  0x0c045448u   /* the byte that means "no value" */
#define G_BASE  0x0c04544au   /* the table's base */
#define G_LIMIT 0x0c04544cu   /* the byte at or above which the caller's word is the answer */
#define G_TABLE 0x0c045454u   /* the table */

/* the table's entry that asks for the bytes to be turned around */
#define TURNED 1u

/* where the object keeps the bytes and the answer */
#define OBJ_BYTES  8u
#define OBJ_ANSWER 20u

void vf3_native_byte_decode(vf3_native_aim *a, uint32_t sp0)
{
    /* the caller's word is popped and pushed on our own stack: the bytes are
     * read back from there */
    R(3) = vf3_aim_u32(a, R(5));
    R(5) += 4u;
    R(15) -= 4u;
    vf3_aim_set_u32(a, R(15), R(3));

    /* the table says whether the bytes are turned around */
    R(2) = vf3_aim_u32(a, G_TABLE);
    R(1) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, G_BASE);
    R(0) = vf3_aim_u32(a, R(2));
    R(0) = vf3_aim_u32(a, R(1) + R(0));
    set_t(a, R(0) == TURNED);

    if (R(0) == TURNED) {
        /* turned around: the first byte goes last */
        R(6) = R(15);
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(6)); R(6) += 1u;
        w8(a, R(4) + OBJ_BYTES + 3u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(6)); R(6) += 1u;
        w8(a, R(4) + OBJ_BYTES + 2u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(6)); R(6) += 1u;
        w8(a, R(4) + OBJ_BYTES + 1u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(6));
        w8(a, R(4) + OBJ_BYTES, (uint8_t)R(0));
    } else {
        /* the natural order */
        R(6) = R(15);
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(6)); R(6) += 1u;
        w8(a, R(4) + OBJ_BYTES, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(6)); R(6) += 1u;
        w8(a, R(4) + OBJ_BYTES + 1u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(6)); R(6) += 1u;
        w8(a, R(4) + OBJ_BYTES + 2u, (uint8_t)R(0));
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(6));
        w8(a, R(4) + OBJ_BYTES + 3u, (uint8_t)R(0));
    }

    /* the byte at +8 decides the answer */
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_aim_u8(a, R(4) + OBJ_BYTES);
    R(3) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, G_MARK);
    R(0) &= 0xffu;
    set_t(a, R(0) == R(3));
    if (R(0) == R(3)) {
        /* the mark: there is no value */
        R(1) = 0xffffffffu;
        vf3_aim_set_u32(a, R(4) + OBJ_ANSWER, R(1));
    } else {
        R(2) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, G_LIMIT);
        set_t(a, (int32_t)R(0) >= (int32_t)R(2));
        if ((int32_t)R(0) >= (int32_t)R(2)) {
            /* the caller's next word is the answer */
            R(1) = vf3_aim_u32(a, R(5));
            vf3_aim_set_u32(a, R(4) + OBJ_ANSWER, R(1));
        } else {
            R(0) = 0u;
            vf3_aim_set_u32(a, R(4) + OBJ_ANSWER, R(0));
        }
    }

    R(0) = 0u;
    R(15) += 4u;
    (void)sp0;
}
