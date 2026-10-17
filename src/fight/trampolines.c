/* trampolines.c - 0x8C03ECB0 / 0x8C0A7662  two thin wrappers that run a fixed call sequence and tail-jump.
 *
 * Their outputs are whatever the nested callees leave in the registers, so both declare the full
 * caller-saved register file (r0..r7, T, FR0..FR15, XF0..XF15, FPUL) as output; the callees are run for real
 * through the guest-call dispatcher.
 *
 *   0x8C03ECB0 (r4 = argument): 0x8C03D260 with FR4 = FR5 = 0, 0x8C03EE40 (the table pair 0x0C1A58A0 / 0x0C0EA624),
 *   then a tail jump to 0x8C03EFF0 with r4 restored.
 *
 *   0x8C0A7662 (r4 = index): indices >= 0x10A4 and empty (0 / -1) slots of the table at 0x0C2A1C3C return at once.
 *   Otherwise 0x8C03C4F0(0) and 0x8C03C1C0(0x0C2A5F60) set up, then the record picks the drawing: bit 0 of its
 *   word +4 set -> 0x8C03ECB0(record); otherwise 0x8C03E8C0() and, when the record's address has any of the
 *   0x0F000000 bits, 0x8C0558A0(record). Ends with a tail jump to 0x8C03C4A0(1). */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SLOT_LIMIT = 0x10A4u, SLOT_TABLE = 0x0C2A1C3Cu, SETUP_ARG = 0x0C2A5F60u, FAR_BITS = 0x0F000000u };

#define SET_T(c)    (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((c) ? 1u : 0u))
#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; R(15) = f; } while (0)

int vf3_trampoline_3ecb0_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 8;
    w32(ram, sp0 - 4, pr0);
    R(15) = f;
    w32(ram, f, R(4));
    R(3) = 0x0C03D260u;
    F(5) = 0;
    F(4) = 0;
    CALL(0x8C03D260u, 0x8C03ECBEu);
    CALL(0x8C03EE40u, 0x8C03ECC2u);
    R(3) = 0x0C03EFF0u;
    R(4) = m32(ram, f);
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    if (!vf3_guest_call(s, ram, 0x8C03EFF0u, pr0)) return 0;
    R(15) = sp0;
    s->pc = pr0;
    return 1;
}

int vf3_trampoline_a7662_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - 8, saved_r14 = R(14);
    w32(ram, sp0 - 4, saved_r14);
    w32(ram, sp0 - 8, pr0);
    R(15) = f;
    R(3) = SLOT_LIMIT;
    SET_T((int32_t)R(4) >= (int32_t)R(3));
    if ((int32_t)R(4) >= (int32_t)R(3)) goto leave;
    R(0) = SLOT_TABLE;
    R(14) = R(4) << 2;
    R(14) = m32(ram, R(0) + R(14));
    SET_T(R(14) == 0);
    if (R(14) == 0) goto leave;
    R(0) = R(14);
    SET_T(R(0) == 0xFFFFFFFFu);
    if (R(0) == 0xFFFFFFFFu) goto leave;

    R(3) = 0x0C03C4F0u;
    R(4) = 0;
    CALL(0x8C03C4F0u, 0x8C0A7684u);
    R(2) = 0x0C03C1C0u;
    R(4) = SETUP_ARG;
    CALL(0x8C03C1C0u, 0x8C0A768Cu);
    R(0) = m32(ram, R(14) + 4);
    SET_T((R(0) & 1u) == 0);
    if (R(0) & 1u) {
        R(2) = 0x0C03ECB0u;
        R(4) = R(14);
        CALL(0x8C03ECB0u, 0x8C0A7698u);
    } else {
        R(2) = 0x0C03E8C0u;
        CALL(0x8C03E8C0u, 0x8C0A76A2u);
        R(3) = FAR_BITS;
        SET_T((R(14) & R(3)) == 0);
        if ((R(14) & R(3)) != 0) {
            R(3) = 0x0C0558A0u;
            R(4) = R(14);
            CALL(0x8C0558A0u, 0x8C0A76AEu);
        }
    }
    R(VF3_REG_PR) = pr0;
    R(3) = 0x0C03C4A0u;
    R(4) = 1;
    R(14) = saved_r14;
    R(15) = sp0;
    if (!vf3_guest_call(s, ram, 0x8C03C4A0u, pr0)) return 0;
    R(15) = sp0;
    s->pc = pr0;
    return 1;

leave:
    R(VF3_REG_PR) = pr0;
    R(14) = saved_r14;
    R(15) = sp0;
    s->pc = pr0;
    return 1;
}
