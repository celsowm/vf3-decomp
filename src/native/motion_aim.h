#ifndef VF3_NATIVE_MOTION_AIM_H
#define VF3_NATIVE_MOTION_AIM_H

#include <stdint.h>

/* Native port of the aim-frame builders the pose orchestration (0x8C09EAF2)
 * calls: 0x8C09E060 (aim_frame, three matrices into the block at actor+0x200
 * and +0x300) and 0x8C09E6B2 (aim_frame_b, the blocks at actor+0x480/+0x540).
 *
 * The guest builders run on XMTRX (the current transform), the FR bank and a
 * 0x40-byte matrix stack whose control block lives at 0x0C19D2E4.  The native
 * port keeps the same shape: `vf3_native_aim` carries a flat matrix RAM (every
 * guest address the builder touches resolves through `ram_base`), XMTRX, a
 * local matrix stack, the FR bank and the register file, so the arithmetic
 * (fsca/fsrra/ftrv/fmac) is reproduced with sinf/cosf/sqrtf and a float
 * multiply-add.
 *
 * See docs/re/motion_aim.md. */

typedef struct {
    float *ram;              /* flat matrix RAM, 4-byte words, little-endian */
    uint32_t ram_base;       /* the guest address of ram[0] */
    uint32_t f;              /* the builder's frame address (sp0 - 340) */
    float xm[16];            /* XMTRX, column-major */
    float stk[16][16];       /* the matrix stack */
    int sp;
    float fr[16];            /* the FR bank */
    uint32_t r[16];          /* r0..r15 */
    uint32_t pr, sr, fpscr;
    uint32_t fpul;           /* the FPUL register (guest r53) */
    uint32_t gbr;            /* the GBR register (guest r59 / VBR sibling) */
    uint32_t macl;           /* saved MACL value for integer multiply helpers */
} vf3_native_aim;

/* Run 0x8C09E060.  `record_a` is r4 (the kind record), `block_b` r5 (the
 * output block), `object` r6, `object7` r7, `fr4` the FR4 input.  The
 * caller's eight stack words (sp0+0..+28) must be in the flat RAM at
 * `f + 340` .. `f + 368`.  Returns 0 on success, -1 on a rejected argument,
 * -2 on a non-finite intermediate. */
int vf3_native_aim_frame(vf3_native_aim *aim, const float *record_a,
                         float *block_b, const float *object,
                         const float *object7, float fr4);

/* Run 0x8C09E6B2.  The registers differ from the first builder: `owner` is
 * r4 (a pointer parked in the frame at +20), `record_a` r5 (the record),
 * `object` r6 (only its address is used - it is the matrix-store target),
 * `object7` r7 (the object whose words 0..3 feed the two translates and the
 * clearance), `fr4` the FR4 input.  The caller's six stack words
 * (sp0+0..+20) must be in the flat RAM at `f + 348` .. `f + 372`. */
int vf3_native_aim_frame_b(vf3_native_aim *aim, const float *record_a,
                           const float *owner, const float *object,
                           const float *object7, float fr4);

#endif
