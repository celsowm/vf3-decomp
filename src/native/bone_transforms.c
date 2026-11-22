/* bone_transforms.c - SH-4 0x8C03E8C0 (bone_transforms), natively.
 *
 * A plain-C transcription of the readable port src/fight/matrix_extra.c
 * (`vf3_bone_transforms_entry`) onto `vf3_native_aim`.  The driver sequences
 * five callees that are already native in this library, so the body runs
 * entirely natively:
 *
 *   1. matrix_push (0x8C03C4F0)  - push XMTRX (r4 = 0),
 *   2. matrix_invert_scaled (0x8C03B5C0) - invert XMTRX in place,
 *   3. per used entry of the sixteen-record TABLE (0x0C19D5B0, stride 0xB0):
 *        - xform_vector (0x8C03B4B0): entry+VEC_IN -> entry+VEC_OUT,
 *        - xform_point (0x8C03B450):  entry+POINT_IN -> entry+POINT_OUT,
 *   4. matrix_pop (0x8C03C4A0) as the tail call (r4 = 1).
 *
 * An entry is "used" when its sign-extended u16 tag at the record start is
 * non-zero.  The register file and the frame are the guest's: the saved r14,
 * r13, r12, r11, r10 sit at sp0-4..sp0-20, pr0 at sp0-24 (the frame), and
 * the port restores them and hands control to matrix_pop with pr in pr.
 *
 * See docs/re/native_bone_transforms.md. */
#include "bone_transforms.h"

#include "matrix_push.h"
#include "matrix_invert_scaled.h"
#include "xform_vector.h"
#include "matrix_pop.h"

#include "aim_math.h"

#define R(n) (a->r[(n)])

#define TABLE       0x0C19D5B0u
#define ENTRY_BYTES 0xB0u
#define ENTRIES     16
#define VEC_IN      104u
#define VEC_OUT     128u
#define POINT_IN    92u
#define POINT_OUT   116u

void vf3_native_bone_transforms(vf3_native_aim *a)
{
    const uint32_t sp0 = R(15), pr0 = a->pr, frame = sp0 - 24u;
    const uint32_t saved[5] = { R(14), R(13), R(12), R(11), R(10) };

    for (int i = 0; i < 5; ++i) vf3_aim_set_u32(a, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    vf3_aim_set_u32(a, sp0 - 24u, pr0);
    R(15) = frame;

    /* 1. matrix_push (0x8C03C4F0), r4 = 0: push XMTRX, do not load */
    R(3) = 0x0C03C4F0u; R(4) = 0;
    vf3_native_matrix_push(a);
    R(15) = frame;

    /* 2. matrix_invert_scaled (0x8C03B5C0) */
    R(2) = 0x0C03B5C0u;
    vf3_native_matrix_invert_scaled(a);
    R(15) = frame;

    R(12) = 0x0C03B4B0u; R(11) = 0; R(14) = TABLE; R(10) = ENTRIES; R(13) = 0x0C03B450u;

    /* 3. the sixteen records */
    for (uint32_t i = 0; i < ENTRIES; ++i) {
        const uint32_t entry = TABLE + i * ENTRY_BYTES, k = i & 3u;
        const uint32_t used = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, entry);
        R(14) = entry;
        R(11) = i;
        if (k == 0) R(3) = used;
        else { R(2) = used; R(3) = ENTRY_BYTES; }
        if (used == 0) continue;

        /* xform_vector (0x8C03B4B0): r4 = entry+VEC_IN, r5 = entry+VEC_OUT */
        R(5) = VEC_OUT + entry;
        R(4) = entry + VEC_IN;
        vf3_native_xform_vector(a);
        R(15) = frame;

        /* xform_point (0x8C03B450): r4 = entry+POINT_IN, r5 = entry+POINT_OUT */
        R(5) = entry + POINT_OUT;
        R(4) = entry + POINT_IN;
        vf3_aim_xform_point(a, entry + POINT_IN, entry + POINT_OUT);
        R(15) = frame;
    }

    /* 4. matrix_pop (0x8C03C4A0), r4 = 1, as the tail call */
    R(14) = TABLE + ENTRIES * ENTRY_BYTES;
    R(11) = ENTRIES;
    R(3) = 0x0C03C4A0u;
    R(4) = 1;
    R(15) = sp0;
    for (int i = 0; i < 5; ++i) R(14 - i) = saved[i];
    a->pr = pr0;
    vf3_native_matrix_pop(a);
}
