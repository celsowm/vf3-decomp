/* tenpp_fill.c - SH-4 0x8C0C103C: the tenpp leaf structure filler, natively.
 *
 * A plain-C transcription of the readable port
 * src/fight/readable/tenpp_fill.c (`vf3_tenpp_fill_entry`).  A self-contained
 * 72 B leaf (0x0C0C103C..0x0C0C1080), call-free, no FPU, no stack frame.  It
 * operates on `vf3_native_aim`: the flat RAM and the register file.
 *
 * r4 is a node structure, r5 an auxiliary cell.  The body fills the node with
 * a fixed pattern and clears the cell:
 *
 *   * the word at r5+20 is cleared;
 *   * the five bytes at r4+16..+20 are set to 0xff (the widened byte r5 ends
 *     up 0xffffffff);
 *   * the halfwords r4+22, +24, +26, +28, +30 and r4+32, +34, +36, +38, +40
 *     are cleared;
 *   * the words r4+44, +48, +52, +56 are cleared, and r4+60 is cleared in the
 *     tail jump's delay slot.
 *
 * The scan leaves r0 = 0x28, r3 = r4+16, r5 = -1 (the widened 0xff) and r6 =
 * 0.  r4 (the node), the stack pointer and every other register, plus all of
 * SR, are untouched.  The return is a tail jump through r16 (the caller's
 * return address).
 *
 * See docs/re/native_tenpp_fill.md. */
#include "tenpp_fill.h"

#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])

static uint8_t *gb(vf3_native_aim *a, uint32_t addr)
{ return (uint8_t *)a->ram + (addr - a->ram_base); }
static void sw8(vf3_native_aim *a, uint32_t addr, uint8_t v)
{ gb(a, addr)[0] = v; }
static void sw16(vf3_native_aim *a, uint32_t addr, uint16_t v)
{ memcpy(gb(a, addr), &v, 2); }
static void sw32(vf3_native_aim *a, uint32_t addr, uint32_t v)
{ memcpy(gb(a, addr), &v, 4); }

void vf3_native_tenpp_fill(vf3_native_aim *a, uint32_t sp0)
{
    (void)sp0;
    const uint32_t r4 = R(4);
    uint32_t r3 = r4;
    const uint32_t r6 = 0u;

    /* 0x0c0c1040: the auxiliary cell's word at +20 is cleared. */
    sw32(a, R(5) + 20u, r6);

    /* 0x0c0c1046/0x0c0c1048: the node +16 and the four bytes above it are
     * set to the widened 0xff byte (r5 ends up 0xffffffff). */
    r3 += 0x10u;                                    /* r3 = r4 + 16 */
    sw8(a, r3, 0xffu);                              /* r4 + 16 */
    sw8(a, r4 + 0x11u, 0xffu);                      /* r4 + 17 */
    sw8(a, r4 + 0x12u, 0xffu);                      /* r4 + 18 */
    sw8(a, r4 + 0x13u, 0xffu);                      /* r4 + 19 */
    sw8(a, r4 + 0x14u, 0xffu);                      /* r4 + 20 */

    sw16(a, r4 + 22u, 0u);
    sw16(a, r4 + 24u, 0u);
    sw16(a, r4 + 26u, 0u);
    sw16(a, r4 + 28u, 0u);
    sw16(a, r4 + 30u, 0u);
    sw16(a, r4 + 0x20u, 0u);
    sw16(a, r4 + 0x22u, 0u);
    sw16(a, r4 + 0x24u, 0u);
    sw16(a, r4 + 0x26u, 0u);
    sw16(a, r4 + 0x28u, 0u);

    sw32(a, r4 + 44u, 0u);
    sw32(a, r4 + 48u, 0u);
    sw32(a, r4 + 52u, 0u);
    sw32(a, r4 + 56u, 0u);
    sw32(a, r4 + 60u, 0u);                          /* the tail jump's delay slot */

    /* the output registers the scan leaves behind */
    R(0) = 0x28u;
    R(3) = r4 + 0x10u;
    R(5) = 0xffffffffu;
    R(6) = r6;
}
