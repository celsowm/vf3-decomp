/* slot_scan.c - 0x8C0CC4DC  walk an object's table of 32-byte slots and run the active ones.
 *
 *   r4 -> object. The slot count is at +52 and the slots start at +0x200. A count of zero returns at once.
 *   Otherwise 0x8C03C4F0(0) and 0x8C03CCB0() prepare the pass, and for every slot whose halfword at +26 has
 *   bit 0 set, 0x8C03CBD0(slot) runs and then 0x8C0A7662(the signed halfword at slot + 28) follows. The
 *   routine leaves through a jump to 0x8C03C4A0(1).
 *
 *   Frame: none, just five saved registers and pr. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum { COUNT = 52, SLOTS = 0x200, SLOT_SIZE = 32, ACTIVE = 26, ARG = 28, ACTIVE_BIT = 1 };

int vf3_slot_scan_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 24;
    const uint32_t saved_r[5] = { R(14), R(13), R(12), R(11), R(10) };
    static const int pushed[5] = { 14, 13, 12, 11, 10 };
    const uint32_t obj = R(4);

    for (int i = 0; i < 5; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    w32(ram, sp0 - 24, pr0);
    R(15) = f;
    R(5) = obj;
    R(13) = m32(ram, obj + COUNT);
    R(14) = obj + SLOTS;

    if (R(13) != 0) {
        R(4) = 0;
        if (!vf3_guest_call(s, ram, 0x8C03C4F0u, 0x8C0CC4FAu)) return 0;
        R(15) = f;
        if (!vf3_guest_call(s, ram, 0x8C03CCB0u, 0x8C0CC500u)) return 0;
        R(15) = f;
        R(11) = 0x0C0A7662u; R(10) = 0x0C03CBD0u; R(12) = 1;
        while (R(13) != 0) {
            R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(14) + ACTIVE);
            if (R(0) & ACTIVE_BIT) {
                R(4) = R(14);
                if (!vf3_guest_call(s, ram, 0x8C03CBD0u, 0x8C0CC512u)) return 0;
                R(15) = f;
                R(0) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(14) + ARG);
                R(4) = R(0);
                if (!vf3_guest_call(s, ram, 0x8C0A7662u, 0x8C0CC518u)) return 0;
                R(15) = f;
            }
            R(13) -= 1;
            R(14) += SLOT_SIZE;
        }
        for (int i = 0; i < 5; ++i) R(pushed[i]) = saved_r[i];
        R(15) = sp0;
        R(VF3_REG_PR) = pr0;
        R(2) = 0x0C03C4A0u;
        R(4) = 1;
        if (!vf3_guest_call(s, ram, 0x8C03C4A0u, pr0)) return 0;
        s->pc = pr0;
        return 1;
    }
    for (int i = 0; i < 5; ++i) R(pushed[i]) = saved_r[i];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
