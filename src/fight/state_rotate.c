/* state_rotate.c - SH-4 0x8C06DEC6: turn the fighter's two vectors into a
 * rotated pair and a normalised one.
 *
 * The guest is called with no arguments of its own.  It reads a global that
 * points at the fighter's struct, rotates the struct's vector at the pool's
 * offset 256 by the angle the struct carries in its halfword at +30, and
 * writes two things back into the struct:
 *
 *  * at the pool's offset 984 the **rotated vector** - the vector at 256 turned
 *    by the angle;
 *  * at the pool's offset 968 the **normalised pair** - the struct's vectors at
 *    0x70, 0x78, 0xb8 and 0xc0, averaged and combined into one pair.
 *
 * The rotation is done by a helper (the address is in the pool) that takes the
 * angle and a two-float frame and rotates that frame: the helper is handed the
 * frame with the two floats -1.0 and 0.0, and it leaves the frame's cosine and
 * sine in them.  The port calls the helper the way the guest does, so the
 * helper's own register traffic is the helper's.
 *
 * The literal pool is read at run time, the way the guest reads it: the three
 * offsets, the pointer to the struct and the helper's address are the image's,
 * and this port does not bake them in.  The two constants the guest loads
 * through a PC-relative address (-1.0 and 0.5) are read from the image too.
 *
 * Details the port has to keep:
 *
 *   * the **T bit** is the guest's branch condition, and it is also part of the
 *     contract - the guest leaves it behind, and the port has to leave the same
 *     value behind.  The last test is the sign of the normalised pair: when it
 *     is positive the four floats go into the struct in one order, and when it
 *     is not they go in the other;
 *   * the **frame** is the guest's: the helper reads the two floats out of it
 *     and writes them back, and the port has to hand the helper the same
 *     frame;
 *   * the **register traffic** is the guest's too - the guest moves fr14 into
 *     fr7 and fr10, fr4 into fr11 and fr3, fr5 into fr2, fr10 into fr0 and
 *     fr11 into fr0 again, and it leaves all of that behind;
 *   * the **return** pops the saved registers - r14 in the delay slot of the
 *     `rts` - so the caller sees its own r14 back, and the guest leaves its
 *     return address in pr.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"

#include <string.h>

#define R(n) s->v[(n)]
#define FR(n) s->v[21 + (n)]

/* The guest's literal pool.  Every entry is read from RAM at run time. */
#define POOL_OFF_SRC    0x0c06dfc4u /* the offset of the vector to rotate */
#define POOL_OFF_ROT    0x0c06dfc6u /* where the rotated vector goes */
#define POOL_OFF_PAIR   0x0c06dfc8u /* where the normalised pair goes */
#define POOL_OBJECT     0x0c06dfccu /* the pointer to the fighter's struct */
#define POOL_HELPER     0x0c06dfe0u /* the rotation helper */

/* The two constants the guest reaches through a PC-relative address. */
#define CONST_NEG_ONE   0x0c06dfdcu /* -1.0 */
#define CONST_HALF      0x0c06dfe4u /* 0.5 */

/* the continuation the guest leaves in pr when it calls the helper */
#define CONT_HELPER     0x0c06def6u

/* the private frame: the two floats the helper rotates */
#define FRAME_LEN       8u

static void set_t(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}

static float as_float(uint32_t u)
{
    float f;
    memcpy(&f, &u, 4);
    return f;
}

/* A pool halfword: the guest reads it and sign extends it. */
static uint32_t pool_half(const vf3_ram_map *ram, uint32_t addr)
{
    return (uint32_t)(int32_t)(int16_t)(uint16_t)vf3_mem_u16(ram, addr);
}

int vf3_state_rotate_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* ---- the prologue: r14, fr15, fr14 and pr ---- */
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(14));
    R(15) -= (R(18) & 0x100000u) ? 8u : 4u; vf3_matrix_store(s, ram, 15, R(15));
    R(15) -= (R(18) & 0x100000u) ? 8u : 4u; vf3_matrix_store(s, ram, 14, R(15));
    R(3) = vf3_mem_u32(ram, POOL_OBJECT);
    R(15) -= 4u; vf3_mem_set_u32(ram, R(15), R(16));

    /* ---- the struct and the angle ---- */
    R(14) = vf3_mem_u32(ram, R(3));               /* the fighter's struct */
    FR(3) = 0u;
    R(0) = (uint32_t)(int32_t)(int16_t)(uint16_t)vf3_mem_u16(ram, R(14) + 30u);
    R(15) -= FRAME_LEN;                           /* the private frame */
    R(5) = R(15);
    R(6) = R(15);
    R(4) = R(0);                                  /* the angle */

    /* ---- the vector to rotate ---- */
    R(0) = pool_half(ram, POOL_OFF_SRC);
    vf3_matrix_load(s, ram, 15, R(14) + R(0));
    R(0) += 8u;
    vf3_matrix_load(s, ram, 14, R(14) + R(0));

    /* ---- the frame the helper rotates: -1.0 and 0.0 ---- */
    R(0) = 4u;
    vf3_matrix_store(s, ram, 3, R(15) + R(0));     /* the frame's second float */
    R(0) = CONST_NEG_ONE;
    vf3_matrix_load(s, ram, 3, R(0));
    vf3_matrix_store(s, ram, 3, R(15));            /* the frame's first float */

    /* ---- the helper: the delay slot first, then the call ---- */
    R(2) = vf3_mem_u32(ram, POOL_HELPER);
    R(5) += 4u;
    if (!vf3_guest_call(s, ram, R(2), CONT_HELPER)) return 0;

    /* ---- the frame now holds the cosine and the sine: the vector turns ---- */
    R(0) = 4u;
    vf3_matrix_load(s, ram, 2, R(15));
    vf3_matrix_load(s, ram, 3, R(15) + R(0));
    R(0) = pool_half(ram, POOL_OFF_ROT);
    FR(14) = vf3_fpu_binary(FR(14), FR(2), R(18), '+');
    FR(15) = vf3_fpu_binary(FR(15), FR(3), R(18), '+');
    vf3_matrix_store(s, ram, 15, R(14) + R(0));
    R(0) += 4u;
    vf3_matrix_store(s, ram, 14, R(14) + R(0));

    /* ---- the four vectors the normalised pair comes from ---- */
    R(0) = 0x70u;
    vf3_matrix_load(s, ram, 4, R(14) + R(0));
    R(0) = 0x78u;
    vf3_matrix_move(s, 7, 14);
    vf3_matrix_move(s, 11, 4);
    FR(11) = vf3_fpu_binary(FR(11), FR(15), R(18), '-');
    vf3_matrix_load(s, ram, 5, R(14) + R(0));
    FR(7) = vf3_fpu_binary(FR(7), FR(4), R(18), '*');
    R(0) += 0x40u;                                /* 0xb8 */
    vf3_matrix_move(s, 10, 14);
    FR(15) = vf3_fpu_binary(FR(15), FR(5), R(18), '*');
    vf3_matrix_load(s, ram, 8, R(14) + R(0));
    R(0) += 8u;                                   /* 0xc0 */
    FR(10) = vf3_fpu_binary(FR(10), FR(5), R(18), '-');
    vf3_matrix_move(s, 3, 7);
    vf3_matrix_load(s, ram, 6, R(14) + R(0));
    R(0) = CONST_HALF;
    vf3_matrix_move(s, 7, 15);
    FR(7) = vf3_fpu_binary(FR(7), FR(3), R(18), '-');
    vf3_matrix_move(s, 3, 4);
    FR(3) = vf3_fpu_binary(FR(3), FR(8), R(18), '+');
    vf3_matrix_load(s, ram, 9, R(0));

    /* ---- the frame holds the two averages ---- */
    R(0) = 4u;
    vf3_matrix_store(s, ram, 3, R(15) + R(0));
    R(0) = 4u;
    vf3_matrix_move(s, 2, 5);
    FR(2) = vf3_fpu_binary(FR(2), FR(6), R(18), '+');
    vf3_matrix_store(s, ram, 2, R(15));
    R(0) = 4u;
    vf3_matrix_load(s, ram, 1, R(15) + R(0));
    R(0) = 4u;
    FR(1) = vf3_fpu_binary(FR(1), FR(9), R(18), '*');
    vf3_matrix_store(s, ram, 1, R(15) + R(0));
    vf3_matrix_load(s, ram, 3, R(15));
    FR(3) = vf3_fpu_binary(FR(3), FR(9), R(18), '*');
    vf3_matrix_store(s, ram, 3, R(15));

    /* ---- the normalised pair ---- */
    vf3_matrix_move(s, 0, 10);
    FR(7) = vf3_fpu_mac(FR(0), FR(1), FR(7), R(18));
    vf3_matrix_move(s, 0, 11);
    vf3_matrix_move(s, 2, 7);
    FR(2) = vf3_fpu_mac(FR(0), FR(3), FR(2), R(18));
    FR(3) = 0u;
    vf3_matrix_move(s, 7, 2);
    set_t(s, as_float(FR(7)) > as_float(FR(3)));
    if (R(17) & 1u) {
        /* the pair is positive: the other order */
        R(0) = pool_half(ram, POOL_OFF_PAIR);
        vf3_matrix_store(s, ram, 8, R(14) + R(0));
        R(0) += 4u;
        vf3_matrix_store(s, ram, 6, R(14) + R(0));
        R(0) += 4u;
        vf3_matrix_store(s, ram, 4, R(14) + R(0));
        R(0) += 4u;
        vf3_matrix_store(s, ram, 5, R(14) + R(0));
    } else {
        R(0) = pool_half(ram, POOL_OFF_PAIR);
        vf3_matrix_store(s, ram, 4, R(14) + R(0));
        R(0) += 4u;
        vf3_matrix_store(s, ram, 5, R(14) + R(0));
        R(0) += 4u;
        vf3_matrix_store(s, ram, 8, R(14) + R(0));
        R(0) += 4u;
        vf3_matrix_store(s, ram, 6, R(14) + R(0));
    }

    /* ---- the epilogue ---- */
    R(15) += FRAME_LEN;
    R(16) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    vf3_matrix_load(s, ram, 14, R(15)); R(15) += (R(18) & 0x100000u) ? 8u : 4u;
    vf3_matrix_load(s, ram, 15, R(15)); R(15) += (R(18) & 0x100000u) ? 8u : 4u;
    R(14) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    s->pc = R(16);
    return ram->oob == 0;
}
