/* scene_clear_flag.c - SH-4 0x8C0624BA: the scene-table bit-clear, natively.
 *
 * A plain-C transcription of the readable port src/fight/gd_syscall_stub.c
 * (`vf3_scene_clear_flag_entry`) onto `vf3_native_aim`: the flat RAM and the
 * register file.
 *
 * A self-contained leaf (call-free, no FPU, no stack frame).  r4 = the
 * address of a scene record.  It scans the 4096-record scene object table at
 * 0x0C16CF6C (stride 24 bytes); when a record's address equals r4 it clears
 * bit 0 of that record's first halfword (`& 0xFFFE`) and stops scanning.
 * The original always walks the whole table, so regardless of whether r4 was
 * found the leaf leaves:
 *
 *   r1 = r7 = 0x1000
 *   r5 = r6 = 0x0C16CF6C + 24 * 0x1000   (one past the last record)
 *
 * r4 (the target) and every other register are untouched.  SR is untouched
 * (no comparison writes the T bit).  The return pops pr (the caller's return
 * address).
 *
 * See docs/re/native_scene_clear_flag.md. */
#include "scene_clear_flag.h"

#include <stdint.h>

#define R(n) (a->r[(n)])

void vf3_native_scene_clear_flag(vf3_native_aim *a)
{
    const uint32_t base = 0x0C16CF6Cu;   /* G_SCENE */
    const uint32_t target = R(4);

    for (uint32_t i = 0; i < 0x1000u; ++i) {
        const uint32_t rec = base + 24u * i;
        if (rec == target) {
            vf3_aim_set_u16(a, rec, (uint16_t)(vf3_aim_h16(a, rec) & 0xFFFEu));
            break;
        }
    }

    R(1) = 0x1000u;
    R(5) = base + 24u * 0x1000u;
    R(6) = base + 24u * 0x1000u;
    R(7) = 0x1000u;
}
