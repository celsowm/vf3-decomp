/* extent_list.c - 0x8C0CC432  step every live record in an object's list of 32-byte extent records.
 *
 *   r4 = object: +0x10 / +0x38 / +0x3C floats (the three values passed on in FR14, FR15, FR13), +0x34 the
 *   record count, +0x1C / +0x24 / +0x28 the three table pointers handed to the step routine. The records
 *   start at +0x200; a record is live when bit 0 of its halfword at +0x1A is set. Each live record goes
 *   through frame_counter_step (0x8C0CC334: r4 = record, r5 = scratch slot, r6 / r7 / [sp] = the tables,
 *   FR4 = FR15, FR5 = FR13) and then extent_flip (0x8C0CC3F0: r4 = record, r5 = the slot, FR4 = FR14), and
 *   the flag halfword is written back from the slot.
 *
 *   Frame: one word at -44 from the entry stack, the slot the flags travel through; the third table pointer
 *   is pushed below it for the first call. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum { RECORDS = 0x200, RECORD_SIZE = 32, SAVED = 40, FRAME_SLOT = 44 };

int vf3_extent_list_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), obj = R(4), frame = sp0 - FRAME_SLOT;
    const uint32_t saved_r[6] = { R(14), R(13), R(12), R(11), R(10), R(9) };
    const uint32_t saved_f[3] = { F(15), F(14), F(13) };
    static const int pushed[6] = { 14, 13, 12, 11, 10, 9 };

    for (int i = 0; i < 6; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    for (int i = 0; i < 3; ++i) w32(ram, sp0 - 24u - 4u * (uint32_t)(i + 1), saved_f[i]);
    w32(ram, sp0 - SAVED, pr0);

    F(14) = m32(ram, obj + 0x10);
    F(15) = m32(ram, obj + 0x38);
    F(13) = m32(ram, obj + 0x3C);
    uint32_t count = m32(ram, obj + 0x34);
    uint32_t rec = obj + RECORDS;
    const uint32_t tab_a = m32(ram, obj + 0x1C), tab_b = m32(ram, obj + 0x24), tab_c = m32(ram, obj + 0x28);
    R(0) = 0x3C;
    R(9) = tab_a; R(10) = tab_b; R(11) = tab_c; R(13) = count; R(14) = rec;
    R(15) = frame;

    if (count) {
        R(12) = 1;
        while (R(13)) {
            const uint32_t flags = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(14) + 0x1A);
            R(0) = flags;
            w32(ram, frame, flags);
            if (flags & 1u) {
                R(15) = frame - 4;
                w32(ram, frame - 4, R(11));                     /* the third table, passed on the stack */
                R(6) = R(9); R(5) = frame; R(7) = R(10); R(4) = R(14);
                F(5) = F(13); F(4) = F(15);
                if (!vf3_guest_call(s, ram, 0x8C0CC334u, 0x8C0CC482u)) return 0;
                R(15) = frame;
                F(4) = F(14); R(5) = frame; R(4) = R(14);
                if (!vf3_guest_call(s, ram, 0x8C0CC3F0u, 0x8C0CC48Au)) return 0;
                R(0) = m32(ram, frame);
                vf3_mem_set_u16(ram, R(14) + 0x1A, (uint16_t)R(0));
            }
            R(13) -= 1;
            R(14) += RECORD_SIZE;
        }
    }

    R(VF3_REG_SR) |= 1u;                                    /* the last tst r13,r13 found it zero */
    for (int i = 0; i < 6; ++i) R(pushed[i]) = saved_r[i];
    F(15) = saved_f[0]; F(14) = saved_f[1]; F(13) = saved_f[2];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
