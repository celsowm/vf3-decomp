/* queue_flush.c - 0x8C03FFD0  prime the store-queue address registers and submit an object's staged work.
 *
 *   r4 -> object. The entry first runs 0x8C03D260 with FR4 = FR5 = 0, then falls into the shared body at
 *   0x8C040010: a negative first word or a zero pointer at +24 means nothing is staged and it returns.
 *   Otherwise both QACR registers (0xFF000038 / 0xFF00003C) are set to 12 and the staging steps run:
 *   0x8C03C4F0(0), 0x8C03EFB0(0x0C19D518), 0x8C03C0E0(0x0C19D4D8). The job record at 0x0C1A58A0 gets the
 *   entry [0x0C0EA690 + 4 * [0x0C0EA390]], a zero, and 0x20000000 at +8; 0x8C04A1A0(object, record) submits
 *   it, and the routine leaves through a jump to 0x8C03C4A0(1).
 *
 *   Frame: the entry keeps r4 in a 4-byte slot under pr; the body's pushes of r14 and pr then overwrite
 *   those two slots. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum {
    QACR0 = 0xFF000038u, QACR1 = 0xFF00003Cu, QACR_VALUE = 12, STAGED_PTR = 24,
    JOB = 0x0C1A58A0u, JOB_FLAGS = 0x0C1A58A8u, JOB_FLAGS_VALUE = 0x20000000u,
    JOB_INDEX = 0x0C0EA390u, JOB_TABLE = 0x0C0EA690u
};

int vf3_queue_flush_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), r14_0 = R(14), f = sp0 - 8;
    const uint32_t obj = R(4);

    w32(ram, sp0 - 4, pr0);
    R(15) = f;
    w32(ram, f, obj);
    F(5) = 0; F(4) = 0;
    if (!vf3_guest_call(s, ram, 0x8C03D260u, 0x8C03FFDEu)) return 0;
    R(4) = m32(ram, f);
    R(VF3_REG_PR) = pr0;

    w32(ram, sp0 - 4, r14_0);
    R(14) = R(4);
    R(3) = m32(ram, obj);
    w32(ram, sp0 - 8, pr0);
    R(15) = f;

    if ((int32_t)R(3) >= 0) {
        R(1) = m32(ram, obj + STAGED_PTR);
        R(3) = QACR0;
        if (R(1) != 0) {
            w32(ram, QACR0, QACR_VALUE);
            w32(ram, QACR1, QACR_VALUE);
            R(4) = 0;
            if (!vf3_guest_call(s, ram, 0x8C03C4F0u, 0x8C040032u)) return 0;
            R(15) = f;
            R(4) = 0x0C19D518u;
            if (!vf3_guest_call(s, ram, 0x8C03EFB0u, 0x8C04003Au)) return 0;
            R(15) = f;
            R(4) = 0x0C19D4D8u;
            if (!vf3_guest_call(s, ram, 0x8C03C0E0u, 0x8C040042u)) return 0;
            R(15) = f;

            w32(ram, JOB, m32(ram, JOB_TABLE + 4 * m32(ram, JOB_INDEX)));
            w32(ram, JOB + 4, 0);
            w32(ram, JOB_FLAGS, JOB_FLAGS_VALUE);
            R(4) = obj; R(5) = JOB; R(14) = obj;
            if (!vf3_guest_call(s, ram, 0x8C04A1A0u, 0x8C040064u)) return 0;

            R(VF3_REG_PR) = pr0;
            R(14) = r14_0;
            R(15) = sp0;
            R(3) = 0x0C03C4A0u;
            R(4) = 1;
            if (!vf3_guest_call(s, ram, 0x8C03C4A0u, pr0)) return 0;
            s->pc = pr0;
            return 1;
        }
    }
    R(14) = r14_0;
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
