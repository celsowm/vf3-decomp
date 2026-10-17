/* seven_pass.c - 0x8C09DA72  run the seven-segment pass for one object.
 *
 *   r4 -> object. The pass builds a vector at frame +0 (zero, or the object's vector at +0x1D04 when flag
 *   0x20000000 of its first word is set) and a second one at frame +36 from the object's +16 / +20 / +24.
 *   Unless the object's flags (+72) have 0x29000, its mode byte (+97) lowers the second vector's y by a
 *   fixed amount: 6 -> 0.0300, 8 -> 0.0600, 11 -> 0.0550, 12 -> 0.0200.
 *
 *   After the setup calls 0x8C03C4F0(0), 0x8C03CCB0(), 0x8C03CC90(frame + 36) and 0x8C03C880(the halfword
 *   at +30), seven segments run: 0x8C03CEE0(frame + 24, r12, frame) over the records from +0x1D04 (12 bytes
 *   apart), then, unless the flag-stage test below holds, 0x8C03B450(frame + 24, r11) over the records from
 *   +0x1EFC. The test: [0x0C29BCCC] has bit 0x800 set, the object's first word has 0x40000 and not 0x8000,
 *   and its flags have 0x21000; then the frame float at +28 is zeroed before the second call. Ends with
 *   0x8C03C4A0(1).
 *
 *   Frame (48 bytes under nine saved words): +0 vector, +24 scratch, +28 zeroed float, +36 second vector. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum {
    SAVED = 36, FRAME = 48, FLAGS = 72, MODE = 97, SEG_A = 0x1D04, SEG_B = 0x1EFC, VEC = 0x1D04,
    FLAG_STAGE = 0x20000000, FLAGS_SKIP = 0x29000, SEGMENTS = 7, SEG_STRIDE = 12,
    STAGE_WORD = 0x0C29BCCCu
};

static const uint32_t DROP_BITS[4] = { 0x3CF5C28Fu, 0x3D75C28Fu, 0x3D6147AEu, 0x3CA3D70Au };   /* modes 6, 8, 11, 12 */

int vf3_seven_pass_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED - FRAME;
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };
    const uint32_t saved_f15 = F(15);
    const uint32_t obj = R(4);

    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    w32(ram, sp0 - 32, saved_f15);
    w32(ram, sp0 - 36, pr0);
    R(14) = obj; R(12) = obj + SEG_A; R(11) = obj + SEG_B;
    R(15) = f;
    w32(ram, f + 36, m32(ram, obj + 16));
    w32(ram, f + 40, m32(ram, obj + 20));
    w32(ram, f + 44, m32(ram, obj + 24));

    if (!(m32(ram, obj + FLAGS) & FLAGS_SKIP)) {
        static const int modes[4] = { 6, 8, 11, 12 };
        const uint32_t mode = vf3_mem_u8(ram, obj + MODE);
        for (int i = 0; i < 4; ++i) {
            if (mode != (uint32_t)modes[i]) continue;
            F(3) = DROP_BITS[i];
            F(2) = m32(ram, f + 40);
            FSUB(2, 3);
            w32(ram, f + 40, F(2));
            break;
        }
    }

    F(15) = 0;
    if (m32(ram, obj) & FLAG_STAGE) {
        w32(ram, f, m32(ram, obj + VEC));
        w32(ram, f + 4, m32(ram, obj + VEC + 4));
        w32(ram, f + 8, m32(ram, obj + VEC + 8));
    } else {
        w32(ram, f, 0); w32(ram, f + 4, 0); w32(ram, f + 8, 0);
    }

    R(4) = 0;
    if (!vf3_guest_call(s, ram, 0x8C03C4F0u, 0x8C09DB46u)) return 0;
    R(15) = f;
    if (!vf3_guest_call(s, ram, 0x8C03CCB0u, 0x8C09DB4Cu)) return 0;
    R(15) = f;
    R(4) = f + 36;
    if (!vf3_guest_call(s, ram, 0x8C03CC90u, 0x8C09DB54u)) return 0;
    R(15) = f;
    R(4) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, obj + 30);
    if (!vf3_guest_call(s, ram, 0x8C03C880u, 0x8C09DB5Cu)) return 0;
    R(15) = f;

    R(10) = 0x21000; R(13) = SEGMENTS; R(9) = 0x800; R(8) = 0x8000;
    for (;;) {
        R(4) = f + 24; R(6) = f; R(5) = R(12);
        if (!vf3_guest_call(s, ram, 0x8C03CEE0u, 0x8C09DB70u)) return 0;
        R(15) = f;
        R(12) += SEG_STRIDE;
        const uint32_t stage = m32(ram, STAGE_WORD);
        if ((stage & 0x800u) && !(m32(ram, obj) & 0x8000u) && (m32(ram, obj) & 0x40000u) &&
            (m32(ram, obj + FLAGS) & 0x21000u))
            w32(ram, f + 28, F(15));
        R(4) = f + 24; R(5) = R(11);
        if (!vf3_guest_call(s, ram, 0x8C03B450u, 0x8C09DB9Eu)) return 0;
        R(15) = f;
        R(13) -= 1;
        R(11) += SEG_STRIDE;
        if (R(13) == 0) break;
    }
    R(4) = 1;
    if (!vf3_guest_call(s, ram, 0x8C03C4A0u, 0x8C09DBAAu)) return 0;

    for (int i = 0; i < 7; ++i) R(pushed[i]) = saved_r[i];
    F(15) = saved_f15;
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
