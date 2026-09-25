/* vf3 fight-frame pixel/state walker pair:
 *   0x8C0748C0 (32 B, "gate": flag-gated vec3-format writer gateway),
 *   0x8C0748E0 (walker body: mixes a source triple into a destination
 *    triple with a type-tagged secondary accumulator).
 *
 * 0x8C0748C0 inputs: in_r5 (caller source pointer, saved to the frame),
 * in_r15 (frame). Literals (PC-relative):
 *   r1 = [0x8C0749B0] (T/gbr gate word ptr), r3 = [0x8C0749AC] (mask).
 * Behaviour:
 *   sts.l pr,@-r15 (push word kept); add #-4,r15; [r15] = r5 (save slot);
 *   flagword = [r1]; if (flagword & r3) {
 *     out.pr = caller's pr (bf skips both bsr calls, epilogue from 0x8C0748D8
 *     restores pr and returns)
 *   } else {
 *     out.pr = 0x8C0748D8 (fall-through onto the walker: two bsr calls back
 *     to back, then the shared epilogue from 0x8C0748D8)
 *   }
 * Either way the epilogue (add #4,r15; lds.l @r15+,pr; rts) leaves the
 * caller's frame unwound by 4: out.sp = in_r15 - 4. The two bsr 0x8C0748E0
 * walker calls between the flag test and the epilogue are DELIBERATELY
 * OUT OF SCOPE: their data structures (destination triple at r4+0x13A8 /
 * r4+0x1488, tagged word at r0-36) are outside every window the oracle
 * captured for this PC (verified OOB in all 8 cases), so they are
 * unverifiable from the current goldens. The C routine models only the
 * gate prologue + flag test + epilogue; the walker register/memory
 * traffic stays caller-owned in the harness. Recapture with
 * walker-covering windows is the documented next step for the tail.
 * The two frame slots sit inside the watched windows, so the combined
 * push+save is byte-checked by the shadow diff at the oracle exit.
 * (An earlier draft saved only one word and produced a systematic
 * single-byte residual at +0x49c; modelling both words fixed it.)
 *
 * 0x8C0748E0 walker (rts-point model; paired via vf3_pair_8c0748e0 on the
 * 0x8C0748DC/38 exit): inputs in_r4 (dst base), in_r5 (src base; the gate
 * loads it from the frame slot).
 *   r0 = 0x13A8; r6 = 0x0150; fr4 = dst[r0]; fr5 = dst[r0+4];
 *   fr6 = dst[r0+8]; r5w = src[r0-36]; r6 += r5w;
 *   fr3 = dst[0x1488]; if (r6 == r5w) {
 *     fr3 += fr4; dst[0x1488] = fr3; (r0 += 4)
 *     fr2 = dst[r0]; fr2 += fr5; dst[r0] = fr2; (r0 += 4)
 *     fr3 = dst[r0]; fr3 += fr6; *(r0,dst) = fr3; (delay slot)
 *   }
 * The (r6 == r5w) test compares the tagged words; the not-taken path
 * (long tail at 0x8C074910+, switch on a count, flag-gated secondary
 * mixes) is documented in the source and mirrored where the oracle
 * covers it.
 * STATUS: STUB. The equal-path body above is decoder-derived but has no
 * oracle coverage: dst[r4+0x13A8/0x1488] and src[r0-36] are outside the
 * windows captured for 0x8C0748C0 (OOB in all 8 cases), and no pair-cases
 * exist for the 0x8C0748E0 entry (0 hits in the fight trace). The C
 * routine keeps the visible shape for reference but returns 1
 * (unmodelled) so no harness can claim a PASS on it.
 */
#ifndef VF3_FIGHT_WALKER2_H
#define VF3_FIGHT_WALKER2_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t pr;      /* caller's pr (gate taken) or 0x8C0748D8 (fall-through) */
    uint32_t r4;      /* reloaded [r15] on the second bsr path (informational) */
    uint32_t sp;      /* exit r15: in_r15 - 4 after the shared epilogue */
} vf3_walker_gate_out;

typedef struct {
    uint32_t r0, r4, r5, r6;
    uint32_t fr2, fr3, fr4, fr5, fr6;
} vf3_walker_e0_regs;

void vf3_walker_gate_8c0748c0(uint32_t in_r5, uint32_t in_r15, uint32_t pr_in,
                              vf3_walker_gate_out *o, const vf3_ram_map *ram);

/* Walker from its rts interior point; fills the 0x8C0748DC/38-exit register
 * snapshot words on the equal path. Returns 0 on the equal path, 1 when the
 * tagged test fails (unmodelled tail, documented). */
int vf3_walker_8c0748e0(uint32_t in_r4, uint32_t in_r5,
                        vf3_walker_e0_regs *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_WALKER2_H */
