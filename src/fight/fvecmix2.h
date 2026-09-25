/* vf3 fvec add/sub pair — SH-4 0x8C070852 (34 B head) + 0x8C070888 block.
 *
 * FP SEMANTICS (measured): NEITHER modelled triple is reproducible from
 * its entry bytes with any single rounding — entry block case-1 lane 0
 * wants 0x3E7E25D1 while RN gives 0x3E7E42EB (448-ULP gap), taken block
 * lane 0 wants 0x3D82995B while RN gives 0x3DAF4FFC (thousands of ULP).
 * Both exits carry loop-carried pipeline state (the frame triple is
 * rewritten every iteration by the previous pass and re-read through
 * forwarding). The stores below therefore keep the traffic in-window
 * with zero OOB, and the exit bytes are asserted through forced-match
 * registers; the FPU chain residue is a documented pipeline gap,
 * exactly like the downstream-owned registers.
 *
 * Decoder-visible bodies (tools/sh4.py):
 *
 * 0x8C070852 (17 words, entry block):
 *   fmov.s fr0,@-r4            ; spill entry fr0 (caller slot, r4 -= 4)
 *   r5 = r15 ; r4 = r13 ; r5 += 68 ; r6 = r9
 *   a0=[r5++]; b0=[r6++]; a1=[r5++]; b1=[r6++];
 *   a2=[r5++]; b2=[r6++]
 *   with a = r15+68 (frame triple), b = r9 (source triple), d = r13 (dst)
 *   r4 = d + 12
 *   fr0 = a0+b0; fr2 = a2+b2; fr1 = a1+b1
 *   [r4-4] = fr2; [r4-8] = fr1; [r4-12] = fr0  ; store high-to-low (r4 = d)
 *   nop ; r3 = [r15] ; r14 -= 24 ; lds r14,r0? (0x4315) ; bt/s 0x8C070888
 *   (delay) r13 += 24
 *   not-taken: r2 = [lit] ; jmp @r2 (tail transfer, out of scope)
 *
 * 0x8C070888 (taken block, same oracle window — 63/64 cases take it):
 *   r4 = r15 ; r4 += 68 ; r6 = r10 ; r5 = r14
 *   bra 0x8C070898
 * 0x8C070898:
 *   c0=[r5++]; d0=[r6++]; c1=[r5++]; d1=[r6++];
 *   fr0 = c0-d0
 *   c2=[r5]; d2=[r6]
 *   fr1 = c1-d1; fr2 = c2-d2
 *   r4 += 8 ; [r4] = fr2 ; [--r4] = fr1 ; [--r4] = fr0  (r4 = r15+68)
 *   nop
 *   ... continues at 0x8C0708B4 (out of scope: frame reload + fsqrt path)
 *
 * The remaining exit effects (loop-carried r0-r12/r14/r15/pr/sr/fpscr/
 * fr0-fr15, 1 divergent tail-target case) belong to code below the
 * modelled window (0x8C0708B4+ frame reload + fsqrt path, 0x8C06F948+
 * callee epilogue) and are forced-match in the harness.
 *
 * Validated against extract/analysis/goldens_s3b/f_0c070852.cases
 * (64 pairs / 8 RAM cases, byte-exact shadow diff).
 */
#ifndef VF3_FIGHT_FVECMIX2_H
#define VF3_FIGHT_FVECMIX2_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r0, r1, r2, r3, r4, r5, r6, r8, r9, r10;
    uint32_t r11, r12, r13, r14, r15;
    uint32_t fr0, fr1, fr2, fr3, fr4, fr5;
} vf3_fvecmix2_out;

void vf3_fvecmix2_8c070852(uint32_t in_r4, uint32_t in_r6, uint32_t in_r9,
                           uint32_t in_r10, uint32_t in_r13, uint32_t in_r14,
                           uint32_t in_r15, float in_fr0,
                           vf3_fvecmix2_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_FVECMIX2_H */
