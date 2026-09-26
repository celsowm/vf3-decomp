/* vf3 frameseq — per-frame scene-step sequencer, SH-4 0x8C0C2B80 (50 B).
 *
 * Decoder-visible body (tools/sh4.py, literals resolved from the pool at
 * 0x8C0C2C48..0x8C0C2C60):
 *
 * 0x8C0C2B80 (entry):
 *   sts.l pr,@-r15                     ; [r15-4] = pr; r15 -= 4
 *   bsr  0x8C0C2BB2                    ; f_8c0c2bb4 (r14/macl frame helper)
 *   jsr  @lit 0x8C0C3C30               ; scene step 1 (f_8c0c3c3e region)
 *   jsr  @lit 0x8C06B6DC               ; scene step 2 (f_8c06b6f0 region)
 *   jsr  @lit 0x8C06BF54               ; scene step 3 (f_8c06bf54 body)
 *   jsr  @lit 0x8C0C3B1C               ; scene step 4 (gate-test helper)
 *   jsr  @lit 0x8C06972A               ; scene step 5 (f_8c069702+e0 body)
 *   r3 = lit 0x8C1FD7C8                ; frame counter address (globals page)
 *   r2 = [r3]; r2 += 1; [r3] = r2      ; frame counter bump
 *   jmp @lit 0x8C06BF00                ; tail-chain into f_8c06bf00
 *   (delay) lds.l @r15+,pr             ; pr = [r15]; r15 += 4 (balanced)
 *
 * The function is a straight-line call chain: no data-dependent branches.
 * All observable register/MEM consequences after it leave via the tail
 * target, which is why the oracle exit snapshots are chain-owned (below).
 *
 * RAM-window scope (goldens_ab/f_0c0c2b80.cases, 20 pairs / 8 RAM cases,
 * windows: 0x0c03ae40 len 0x810, 0x0c0a0f80 len 0x824, 0x0c0c2780 len 0x800):
 *   entry RAM == exit RAM BYTE-IDENTICAL in all 8 cases — neither this
 *   body nor any callee in the chain writes a captured byte. The body's own
 *   two memory touches escape every window in every case:
 *     1. [in_r15-4] = in_pr      (stack page 0x0C31Fxxx — not captured)
 *     2. m[0x0C1FD7C8] += 1      (globals page 0x0C1FDxxx — not captured)
 *   Both are kept as faithful ram-map traffic with the oob probe snapshotted
 *   and restored around the call (walker2 gate-word precedent); a future
 *   wider-window recapture makes them checkable with no port change.
 *
 * The 6 jsr/bsr callees are NOT modelled (walker2-style cut): the oracle
 * exit snapshot retires after the whole call chain (incl. the tail target
 * and whatever it calls), so out r0..r7/r14/r15/pr and fr2..fr4 are
 * chain-owned constants of the scenario (all 20 pairs share one in-template
 * and one out-template; e.g. out pr = 0x0C0C2C20, out r15 = in_r15 - 28,
 * out fr2 = 0x3FA00000 / fr3 = 0xB8D1B717 / fr4 = 0x43000000). The replay
 * test forces exactly that chain-owned set from the oracle and genuinely
 * checks the passthrough remainder (r2/r8..r13/sr/fpscr/macl/mach/fr0/fr1/
 * fr5..fr15) plus the byte-identical RAM windows: the port must corrupt no
 * captured byte and perform no unexpected out-of-window access.
 *
 * Register semantics at the TAIL-JMP boundary (modelled; this is NOT the
 * oracle exit snapshot and the test deliberately does not assert it):
 *   r2  = old m[0x8C1FD7C8] + 1        (counter value after bump)
 *   r3  = 0x8C06BF00                   (tail target)
 *   r15 = in_r15                       (push/pop balanced)
 *   pr  = in_pr                        (restored by the delay-slot pop)
 */
#ifndef VF3_FIGHT_FRAMESEQ_H
#define VF3_FIGHT_FRAMESEQ_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

enum {
    VF3_FRAMESEQ_COUNTER = 0x8C1FD7C8u, /* [lit 0x8C0C2C5C] frame counter */
    VF3_FRAMESEQ_TAIL    = 0x8C06BF00u  /* [lit 0x8C0C2C60] tail target   */
};

typedef struct {
    uint32_t r2;    /* counter value after the bump (m[0x8C1FD7C8]+1) */
    uint32_t r3;    /* tail target 0x8C06BF00 */
    uint32_t r15;   /* balanced: == in_r15 */
    uint32_t pr;    /* restored: == in_pr */
} vf3_frameseq_out;

void vf3_frameseq_8c0c2b80(uint32_t in_pr, uint32_t in_r15,
                           vf3_frameseq_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_FRAMESEQ_H */
