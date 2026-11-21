/* matrix_push.c - SH-4 0x8C03C4F0 matrix_push, natively.
 *
 * A plain-C transcription of the readable port src/fight/matrix_lib.c
 * (`vf3_matrix_push_entry`) onto `vf3_native_aim`.  The guest keeps the
 * current transform (XMTRX) in the XF bank - v[37..52] in a readable state,
 * `a->xm[16]` here.
 *
 * A self-contained leaf (call-free, no stack frame, no FPU math).  It pushes
 * XMTRX on the matrix stack and optionally loads a new matrix:
 *
 *   - the stack's control block is at 0x0C19D2E4: word 0 = (limit<<16)|count
 *     (two int16), word 8 = the stack top;
 *   - XMTRX is written at the top, the top moves up by one matrix (64 B),
 *     and the count is incremented (the limit test only leaves its result in
 *     r0, without clamping the write);
 *   - with r4 != 0 the matrix at r4 then becomes XMTRX and r4 advances past
 *     it; SR.T ends as r4 == 0, or as "(r4 & 4) == 0" on the load path.
 *
 * No FPU, no FR, no stack frame.  r15 and all other registers except r0/r4
 * are untouched.  See docs/re/native_matrix_push.md. */
#include "matrix_push.h"

#include "aim_math.h"

#define R(n) (a->r[(n)])

#define MATRIX_WORDS 16
#define MATRIX_BYTES 64u
#define MATRIX_STACK_CTL 0x0C19D2E4u

void vf3_native_matrix_push(vf3_native_aim *a)
{
    const uint32_t top = vf3_aim_u32(a, MATRIX_STACK_CTL + 8u);
    const uint32_t ctl = vf3_aim_u32(a, MATRIX_STACK_CTL);

    for (int i = 0; i < MATRIX_WORDS; ++i)
        vf3_aim_set_u32(a, top + 4u * (uint32_t)i, vf3_aim_ubits(a->xm[i]));

    const int32_t count = (int16_t)(uint16_t)(ctl & 0xFFFFu);
    const int32_t limit = (int16_t)(uint16_t)(ctl >> 16);
    R(0) = (uint32_t)(limit > count);
    vf3_aim_set_u32(a, MATRIX_STACK_CTL + 8u, top + MATRIX_BYTES);
    vf3_aim_set_u16(a, MATRIX_STACK_CTL,
                    (uint16_t)((uint32_t)(count + 1) & 0xFFFFu));

    int t;
    if (R(4) == 0) {
        t = 1;
    } else {
        for (int i = 0; i < MATRIX_WORDS; ++i)
            a->xm[i] = vf3_aim_fbits(vf3_aim_u32(a, R(4) + 4u * (uint32_t)i));
        t = (R(4) & 4u) == 0;
        R(4) += MATRIX_BYTES;
    }
    a->sr = (a->sr & ~1u) | (uint32_t)t;
}
