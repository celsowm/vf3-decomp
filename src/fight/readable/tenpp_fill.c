/* tenpp_fill.c - SH-4 0x8C0C103C: the tenpp leaf structure filler.
 *
 * A small self-contained leaf (72 B, call-free, no FPU, no stack frame) that
 * fills a node structure with a fixed pattern.  r4 is the node, r5 an
 * auxiliary cell.  The body:
 *
 *   * zeroes the word at r5+20;
 *   * sets the five bytes at the node +16..+20 to 0xff (r4+16, then the four
 *     sixteenth-pattern bytes r4+17..+20);
 *   * zeroes the halfwords r4+22, +24, +26, +28, +30 and r4+32, +34, +36,
 *     +38, +40;
 *   * zeroes the words r4+44, +48, +52, +56 and (in the tail jump's delay
 *     slot) r4+60.
 *
 * The output registers it leaves are the products of that scan: r0 holds the
 * last offset touched (0x28), r3 the node + 16 (0x10), r5 the 0xff byte
 * value widened to -1, and r6 the zero accumulator.  r4 (the node) and every
 * register and the stack pointer are left untouched, and no SR bit changes.
 * The return is a tail jump through r16 (the caller's return address), so the
 * port reproduces it by handing control back to R(16).
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

int vf3_tenpp_fill_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t r4 = R(4);
    uint32_t r3 = r4;
    uint32_t r6 = 0u;

    /* 0x0c0c1040: the auxiliary cell's word at +20 is cleared. */
    vf3_mem_set_u32(ram, R(5) + 20u, r6);

    /* 0x0c0c1046/0x0c0c1048: the node +16 and the four bytes above it are
     * set to the widened 0xff byte (r5 ends up 0xffffffff). */
    r3 += 0x10u;                                    /* r3 = r4 + 16 */
    vf3_mem_set_u8(ram, r3, 0xffu);                 /* r4 + 16 */
    vf3_mem_set_u8(ram, r4 + 0x11u, 0xffu);         /* r4 + 17 */
    vf3_mem_set_u8(ram, r4 + 0x12u, 0xffu);         /* r4 + 18 */
    vf3_mem_set_u8(ram, r4 + 0x13u, 0xffu);         /* r4 + 19 */
    vf3_mem_set_u8(ram, r4 + 0x14u, 0xffu);         /* r4 + 20 */

    vf3_mem_set_u16(ram, r4 + 22u, 0u);
    vf3_mem_set_u16(ram, r4 + 24u, 0u);
    vf3_mem_set_u16(ram, r4 + 26u, 0u);
    vf3_mem_set_u16(ram, r4 + 28u, 0u);
    vf3_mem_set_u16(ram, r4 + 30u, 0u);
    vf3_mem_set_u16(ram, r4 + 0x20u, 0u);
    vf3_mem_set_u16(ram, r4 + 0x22u, 0u);
    vf3_mem_set_u16(ram, r4 + 0x24u, 0u);
    vf3_mem_set_u16(ram, r4 + 0x26u, 0u);
    vf3_mem_set_u16(ram, r4 + 0x28u, 0u);

    vf3_mem_set_u32(ram, r4 + 44u, 0u);
    vf3_mem_set_u32(ram, r4 + 48u, 0u);
    vf3_mem_set_u32(ram, r4 + 52u, 0u);
    vf3_mem_set_u32(ram, r4 + 56u, 0u);
    vf3_mem_set_u32(ram, r4 + 60u, 0u);             /* the tail jump's delay slot */

    /* the output registers the scan leaves behind */
    R(0) = 0x28u;
    R(3) = r4 + 0x10u;
    R(5) = 0xffffffffu;
    R(6) = r6;

    s->pc = R(16);                                  /* the caller's return address */
    return ram->oob == 0;
}
