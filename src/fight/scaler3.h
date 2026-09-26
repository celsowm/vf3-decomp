/* vf3 scaler3 — scaled vector add helper, SH-4 0x8C092BC6 (46 B head)
 * + 0x8C092C04 body + 0x8C092C38 shared epilogue.
 *
 * Decoder-visible body (tools/sh4.py, literals resolved):
 *
 * 0x8C092BC6 (entry):
 *   fmov.s fr0,@-r4            ; spill fr0 to [r4-4]; r4 -= 4
 *   r0 = [r15+40]; T = ((r0 & 2) == 0); if (!T) ... fall to tail jmp
 *   bt 0x8C092BD6 (scale-load path)     ; T=1
 *   r3 = literal[0x8C092C38]; jmp @r3    ; T=0 (bit-1 set) -> epilogue
 * 0x8C092BD6 (scale load):
 *   r2 = [r15+4]; r0 = 20
 *   fr2 = 0.0 (fldi0)
 *   fr4 = *(float*)(r2+20)                ; loaded from OUTSIDE memory (see below)
 *   fr3 = fr4; fr4 += fr3 (= 2*scale)
 *   if (fr4 == 0) fall through to jmp: r3 = literal[0x8C092C38]; jmp @r3
 *   r1 = m[r15+0]; if (r1 == 0) fall through: r1 = literal; jmp @r1
 * body (0x8C092C04):
 *   r4 = r15+12 (scratch base); r5 = m[r15+36] (vec1 ptr)
 *   fr0 = [r5]; fr1 = [r5+4]; fr2 = [r5+8]   (r5 += 12 after)
 *   r4 += 12 (now r15+24)
 *   fr2 *= fr4; fr1 *= fr4; fr0 *= fr4  (scaled = 2s * vec1)
 *   [r15+20] = fr2; [r15+16] = fr1; [r15+12] = fr0  (auto-dec stores)
 *   r4 = m[r15+0] + 24   (dst ptr)
 *   r5 = r15+12
 *   fr0 = m[r4+0]; fr3 = m[r15+12] (= scaled_x)
 *   fr1 = m[r4+4]; fr4 = m[r15+16] (= scaled_y)
 *   fr2 = m[r4+8]; fr5 = m[r15+20] (= scaled_z)
 *   fr0 += fr3; fr2 += fr5; fr1 += fr4   (sum = vec2 + scaled)
 *   [ptr+32] = fr2; [ptr+28] = fr1; [ptr+24] = fr0 (auto-dec stores)
 * epilogue (0x8C092C38, shared across all paths):
 *   r15 += 24; rts
 *   (delay) r14 = m[r15-after+24]; r15 += 4    (net: r15 = in_r15 + 28)
 *
 * RAM-window scope (goldens_ab/f_0c092bc6.cases, windows:
 * 0x0c203700 len 0x1280, 0x0c207000 len 0x8d8, 0x0c31f540 len 0x894).
 * All body reads (vec1 ptr at [r15+36], dst ptr at [r15+0], vec1 vec load,
 * vec2 load at ptr+24..32, frame scratch) land inside the captured
 * windows. The one read that ESCAPES is scale = m[r2+20] where
 * r2 = m[r15+4] is in the caller's scratch page (0x0c0fxxxx range).
 * The port therefore takes `scale2x` as an explicit parameter (the test
 * derives it from the oracle for path-A/2 cases); this is documented as
 * the "callee-input" cut.
 *
 * Register semantics (verified against all 8 RAM cases):
 *   r0   = (path 1) m[in_r15+40]  OR  (paths 2..4) 20
 *   r1   = (path 1) in_r1  OR  (path 2) in_r1  OR  (path 3) lit 0x8C092C38
 *          OR  (path 4) m[in_r15+0]
 *   r2   = (path 1) in_r2  OR  (paths 2..4) m[in_r15+4]
 *   r3   = (paths 1..3) 0x8C092C38  OR  (path 4) in_r3 (unchanged)
 *   r4   = (all) in_r4 - 4 (spill consumed)
 *          (path 4 additionally: = m[in_r15+0] + 24 after body)
 *   r5   = (paths 1..3) in_r5  OR  (path 4) in_r15 + 24
 *   r14  = m[in_r15+24]   (epilogue pop)
 *   r15  = in_r15 + 28    ( epilogue ret+pop )
 *   sr T = path-dependent (see implementation)
 *   fr0..fr5 written only on path 4; fr2 cleared by fldi0 and fr4 *= 2 on
 *   path 2 (if scale == 0 they end 0); untouched on path 1.
 *
 * Memory writes (shadow-checked):
 *   [in_r4 - 4]         = in_fr0                   (all paths)
 *   [in_r15+12..20]     = scaled = 2s * vec1       (path 4 only)
 *   [m[in_r15+0]+24..32] = vec2 + scaled           (path 4 only)
 */
#ifndef VF3_FIGHT_SCALER3_H
#define VF3_FIGHT_SCALER3_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r0, r1, r2, r3, r4, r5, r14, r15;
    uint32_t sr_T;
    uint32_t fr0, fr1, fr2, fr3, fr4, fr5;
} vf3_scaler3_out;

/* path: 1 = bt-epilogue, 2 = scale0-epilogue, 3 = r1zero-epilogue,
 *       4 = full body
 * scale2x: 2 * m[m[in_r15+4] + 20] — needed only for paths 2 and 4.
 * in_r3: needed verbatim so path 4's "unchanged" output passes through. */
void vf3_scaler3_8c092bc6(uint32_t in_r1, uint32_t in_r3, uint32_t in_r4,
                          uint32_t in_r15,
                          uint32_t in_fr0_bits, uint32_t in_fr1_bits,
                          uint32_t in_fr2_bits, uint32_t in_fr3_bits,
                          uint32_t in_fr4_bits, uint32_t in_fr5_bits,
                          int path, float scale2x,
                          vf3_scaler3_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_SCALER3_H */
