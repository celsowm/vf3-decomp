/* vf3 vector-length select/normalize head — SH-4 0x8C06F6F8 (88 B).
 *
 * Decoder-visible body (tools/sh4.py; FPU names resolved against
 * refs/dream-recomp/translator/src/sh4/decoder.cpp — note tools/sh4.py's
 * fipr mask 0xF33F is self-inconsistent dead code, see below):
 *   fmov.s fr0,@-r4            ; spill entry fr0; r4 -= 4
 *                              ; (r4entry = r15+60 in the oracle, so this
 *                              ;  parks fr0 into the [r15+56] vector slot)
 *   nop
 *   mov r15,r4 ; add #56,r4    ; r4 = frame+56
 *   fmov.s @r4+,fr0            ; fr0 = [frame+56] (the spilled entry fr0)
 *   fmov.s @r4+,fr1            ; fr1 = [frame+60]
 *   fmov.s @r4+,fr2            ; fr2 = [frame+64]
 *   fldi0 fr3                  ; fr3 = 0
 *   fipr fv0,fv0               ; 0xF0ED: fr3 = fr0^2+fr1^2+fr2^2 (|v|^2)
 *   fmov fr3,fr0 ; fsqrt fr0   ; fr0 = |v|
 *   nop
 *   mova @(36,pc),r0           ; r0 = 0x8C06F738 (literal pool)
 *   fmov.s @r0,fr3             ; fr3 = 1e-7 threshold (pool 0x33D6BF94)
 *   fcmp/gt fr0,fr3            ; T = (threshold > |v|)
 *   bf 0x8C06F728              ; |v| >= threshold -> normalize path
 *   --- small-|v| path (fall-through; UNTRIPPED in all 8 oracle RAM cases,
 *       tail target outside the 88 B -> gated) ---
 *   mov #56,r0 ; fmov.s fr14,@(r0,r15)   ; [frame+56] = fr14entry
 *   mov #60,r0 ; fmov.s fr15,@(r0,r15)   ; [frame+60] = fr15entry
 *   mov #64,r0 ; mov.l @(24,pc),r3       ; r3 = [0x8C06F73C] = 0x0C06F75C
 *   jmp @r3                                ; tail-jump out of bounds (gated)
 *   (delay) fmov.s fr15,@(r0,r15)          ; [frame+64] = fr15entry
 *   --- normalize path (0x8C06F728; taken by all 8 oracle RAM cases) ---
 *   mov r15,r4 ; mov r15,r5
 *   add #56,r4 ; fmov fr14,fr4 ; add #56,r5
 *   bra 0x8C06F740 ; (delay) nop
 *   fmov.s @r5+,fr0 ; fmov.s @r5+,fr1 ; fmov.s @r5+,fr2
 *   fldi0 fr3
 *   fipr fv0,fv0               ; 0xF0ED: fr3 = |v|^2
 *   fsrra fr3                  ; 0xF37D: fr3 ~= 1/sqrt(fr3) (approx, gated
 *                              ;  precision: dream-recomp/Flycast evaluate
 *                              ;  1/sqrtf; the SH-4 uses a hardware table)
 *   fmul fr4,fr3               ; fr3 = fr14entry * rsqrt(|v|^2)
 *   add #12,r4                 ; r4 = frame+68; falls through to 0x8C06F750
 *                              ; (next function: scale+store of the
 *                              ;  normalized triple — out of scope)
 *
 * Bytes 0x8C06F736..0x8C06F73E are literal pool, not code (the apparent
 * `bsr 0x8C06F664` at 0x8C06F738 is the threshold float's high half).
 * No jsr/bsr in bounds: leaf=1, out_calls=0, one tail jmp (sh4_tail=1 at
 * 0x8C06F724) per extract/analysis/sh4_calls.csv.
 *
 * Oracle: extract/analysis/goldens_ab/f_0c06f6f8.cases (64 lines, first 8
 * with RAM over 0x0C06F280+0x830, 0x0C2B02C0+0xED4, 0x0C31F540+0x870).
 * NOTE (2026-09-27): the batch exit snapshot is degenerate — all 64 lines
 * share one byte-identical out-vector and exit-RAM blob (md5
 * 3e5a1c6e16aee54aed4008e394ed6433) while entries vary, PR changes across
 * a leaf (0c06f6a6 -> 0c06f43a), and ~500 exit words lie outside any
 * in-bounds store. A full shadow+regs PASS is unachievable from the 88 B;
 * this port mirrors every in-bounds instruction/store exactly and the
 * replay test checks OOB==0 plus the in-bounds footprint. See the
 * g06f6f8_replay.c header for the evidence table.
 *
 * M59 (2026-09-28, re-pair with pr-match fork): recaptured
 * goldens_6f6f8full (69,309 pairs, 64 unique, 10 RAM cases over 10 windows).
 * Pairing improved but NOT fixed: 8 distinct out-vectors (was 1), 55/64
 * PR round-trip (outPR always 0c06f948; inPR 0c06f6a6 or 0c06f948).
 * Root cause scoped: the 88 B boundary is artificial — the pipeline runs
 * 0x8C06F6F8..0x8C06F98E+ (662 B to the first rts at 98e, code continues
 * past it: epilogue BSRF switch at 9de+, more tails at fb42/bb8). Per-call
 * instr walks (74k records entry->exit, 5257 in-chain pcs, ZERO rts with pc
 * in 0x6F000..0x70000 either alias) prove the paired exit fires at a
 * CALLER rts: entry r3 is always 0c06f6ae and the chain ends in
 * jmp @r3 (724/952) / jmp @r2 (938, r2 = 0c06f6c6 or 0xB) tail-transfers
 * into the caller, whose rts (target = entry pr 0c06f948) closes the pair
 * via pr-match. The 10 RAM cases fail only on r0 (port: mova 8c06f738,
 * oracle: 0x24 from the epilogue mov #36 at 0x8C06F9F6). Recipe: extend the
 * port through the epilogue switch to the caller-rts boundary with the
 * r2/r3-resolved tails (both entry-constant per case); tools/ac6f6f8_paths.py
 * + extract/analysis/ac6f6f8_paths.csv carry the executed-PC set
 * (287 pcs, 0x6F6F8..0x6F954 over 40 calls).
 */
#ifndef VF3_FIGHT_G06F6F8_H
#define VF3_FIGHT_G06F6F8_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r0, r4, r5;
    uint32_t fr0, fr1, fr2, fr3, fr4;
    uint32_t T;             /* fcmp/gt result (SR bit 0) */
    int gated;              /* 1 = small-|v| tail path taken (out of scope) */
    uint32_t tail_target;   /* jmp @r3 destination when gated */
} vf3_g06f6f8_out;

void vf3_g06f6f8_8c06f6f8(uint32_t in_r4, uint32_t in_r15,
                          float in_fr0, float in_fr14, float in_fr15,
                          uint32_t in_fpscr,
                          vf3_g06f6f8_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_G06F6F8_H */
