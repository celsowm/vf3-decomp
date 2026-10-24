/* halfword_frame.c - SH-4 0x8C09D4B0: the frame of halfwords and the three
 * calls it feeds.
 *
 * The function takes an object (r4) with three halfwords and an argument
 * (r5), puts them in a frame and calls three things with values derived
 * from it:
 *
 *  - the first handler - the pointer in the literal pool at 0x8C09D580 -
 *    gets the object's first halfword;
 *  - the second handler - the pointer at 0x8C09D584 - gets the argument
 *    plus the object's second halfword;
 *  - the third - the pointer at 0x8C09D588 - gets the object's third
 *    halfword.  That one is a *tail transfer*: the guest pops pr and jumps,
 *    so the call runs in the caller's frame and returns to the caller's
 *    caller.
 *
 * The frame holds four halfwords: the argument and the object's three.
 * The readable port keeps them in the same places, so the stack traffic it
 * leaves in RAM is the one the original left.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

/* the literal pool */
#define G_FIRST  0x0c09d580u   /* the first handler */
#define G_SECOND 0x0c09d584u   /* the second handler */
#define G_THIRD  0x0c09d588u   /* the third one: the tail transfer */

/* the continuations the guest leaves in pr */
#define CONT_FIRST  0x0c09d4ccu
#define CONT_SECOND 0x0c09d4d8u

/* the frame: the argument and the object's three halfwords, in the sixteen
 * bytes the guest reserves under the saved pr */
#define FRAME_AREA 16u

int vf3_halfword_frame_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp = R(15);

    /* the guest saves pr and reserves the frame */
    vf3_mem_set_u32(ram, sp - 4u, R(16));
    R(15) = sp - 20u;

    /* the frame: the argument first, then the object's halfwords */
    vf3_mem_set_u16(ram, R(15), (uint16_t)R(5));
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(4));
    vf3_mem_set_u16(ram, R(15) + 8u, (uint16_t)R(0));
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(4) + 2u);
    vf3_mem_set_u16(ram, R(15) + 4u, (uint16_t)R(0));
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(4) + 4u);
    vf3_mem_set_u16(ram, R(15) + 12u, (uint16_t)R(0));

    /* the first handler gets the object's first halfword */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(15) + 8u);
    R(4) = R(0);
    R(3) = vf3_mem_u32(ram, G_FIRST);
    R(4) &= 0xffffu;
    if (!vf3_guest_call(s, ram, R(3), CONT_FIRST)) return 0;

    /* the second handler gets the argument and the object's second halfword */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(15) + 4u);
    R(4) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(15));
    R(3) = vf3_mem_u32(ram, G_SECOND);
    R(0) &= 0xffffu;
    R(4) += R(0);
    if (!vf3_guest_call(s, ram, R(3), CONT_SECOND)) return 0;

    /* the third one gets the object's third halfword, and the call is a
     * tail transfer: the guest pops pr and jumps to it */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(15) + 12u);
    R(4) = R(0);
    R(3) = vf3_mem_u32(ram, G_THIRD);
    R(4) &= 0xffffu;
    R(15) += FRAME_AREA;
    R(16) = vf3_mem_u32(ram, R(15)); R(15) += 4u;
    return vf3_guest_tail_call(s, ram, R(3), R(16));
}
