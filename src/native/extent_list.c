/* extent_list.c - SH-4 0x8C0CC432 (extent_list), natively.
 *
 * A plain-C transcription of the readable port src/fight/extent_list.c
 * (`vf3_extent_list_entry`) onto `vf3_native_aim`: the flat RAM, the FR bank
 * and the register file.
 *
 * The object's list of 32-byte extent records starts at object + 0x200; the
 * count lives at object + 0x34 and the three table pointers at +0x1C / +0x24 /
 * +0x28.  A record is live when bit 0 of its halfword at +0x1A is set.  Each
 * live record goes through frame_counter_step (0x8C0CC334, with r6 / r7 =
 * two of the tables, the third passed on the stack just below the frame, and
 * FR4 / FR5 = the object's +0x38 / +0x3C floats) and then extent_flip
 * (0x8C0CC3F0, FR4 = the object's +0x10 float).  Both callees are themselves
 * natively ported and are called directly, so this leaf has no guest calls.
 *
 * The dead stack words (the six saved registers, the three saved FP values and
 * the saved pr) and the flag slot are written back byte for byte, because they
 * are visible in RAM.  The frame sits at sp0 - 44; the third table is pushed
 * at sp0 - 48 for the frame_counter_step call.
 *
 * See docs/re/native_extent_list.md. */
#include "extent_list.h"

#include "frame_counter_step.h"
#include "extent_flip.h"

#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

void vf3_native_extent_list(vf3_native_aim *a)
{
    const uint32_t sp0 = R(15), pr0 = a->pr, obj = R(4), frame = sp0 - 44u;
    const uint32_t saved_r[6] = { R(14), R(13), R(12), R(11), R(10), R(9) };
    const uint32_t saved_f[3] = {
        vf3_aim_ubits(F(15)), vf3_aim_ubits(F(14)), vf3_aim_ubits(F(13))
    };
    static const int pushed[6] = { 14, 13, 12, 11, 10, 9 };

    for (int i = 0; i < 6; ++i) vf3_aim_set_u32(a, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    for (int i = 0; i < 3; ++i) vf3_aim_set_u32(a, sp0 - 24u - 4u * (uint32_t)(i + 1), saved_f[i]);
    vf3_aim_set_u32(a, sp0 - 40u, pr0);

    F(14) = vf3_aim_fbits(vf3_aim_u32(a, obj + 0x10));
    F(15) = vf3_aim_fbits(vf3_aim_u32(a, obj + 0x38));
    F(13) = vf3_aim_fbits(vf3_aim_u32(a, obj + 0x3C));
    uint32_t count = vf3_aim_u32(a, obj + 0x34);
    uint32_t rec = obj + 0x200u;
    const uint32_t tab_a = vf3_aim_u32(a, obj + 0x1Cu),
                   tab_b = vf3_aim_u32(a, obj + 0x24u),
                   tab_c = vf3_aim_u32(a, obj + 0x28u);
    R(0) = 0x3C;
    R(9) = tab_a; R(10) = tab_b; R(11) = tab_c; R(13) = count; R(14) = rec;
    R(15) = frame;

    if (count) {
        R(12) = 1;
        while (R(13)) {
            const uint32_t flags = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, R(14) + 0x1Au);
            R(0) = flags;
            vf3_aim_set_u32(a, frame, flags);
            if (flags & 1u) {
                R(15) = frame - 4u;
                vf3_aim_set_u32(a, frame - 4u, R(11));       /* the third table, on the stack */
                R(6) = R(9); R(5) = frame; R(7) = R(10); R(4) = R(14);
                F(5) = F(13); F(4) = F(15);
                vf3_native_frame_counter_step(a);
                R(15) = frame;
                F(4) = F(14); R(5) = frame; R(4) = R(14);
                vf3_native_extent_flip(a);
                R(0) = vf3_aim_u32(a, frame);
                vf3_aim_set_u16(a, R(14) + 0x1Au, (uint16_t)R(0));
            }
            R(13) -= 1;
            R(14) += 32u;
        }
    }

    a->sr |= 1u;                                            /* the last tst r13,r13 found it zero */
    for (int i = 0; i < 6; ++i) R(pushed[i]) = saved_r[i];
    F(15) = vf3_aim_fbits(saved_f[0]); F(14) = vf3_aim_fbits(saved_f[1]); F(13) = vf3_aim_fbits(saved_f[2]);
    R(15) = sp0;
    a->pr = pr0;
}
