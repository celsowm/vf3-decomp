/* vf3 FPU range-reduction kernel — SH-4 0x8C03A6E0 (+0x8C03A140 entry).
 *
 * Off-baseline gap unit (no Ghidra function; U1 of the af734 cascade).
 * Two entries share one body:
 *   0x8C03A140: r14Adjust = extu.w r4; if (r14Adjust > 0x8000 signed)
 *               r14Adjust = 0x10000 - r14Adjust; r4 = 0x4000 - r14Adjust
 *               (r14 saved/restored around it); then falls into 0x8C03A6E0.
 *   0x8C03A6E0: r4 = extu.w r4; main kernel below.
 * Body (all FPU ops honour entry FPSCR: RM=1 truncate here; DN flush via
 * fpu_dn_fix; ftrc/float are mode-exact):
 *   fpul = r4; fr7=C0 fr2=C1 fr3=float(fpul) fr1=C2 fr5=C3 fr0=C4
 *     (C0..C4 = ROM floats at 0x8C03A91C..0x8C03A930: 2.0, 2pi, 65536,
 *     pi/2, 0.5)
 *   fr3 = fr2*fr3; fr3 /= fr1; fr4 = fr3; fr4 /= fr7; fr3 = fr4;
 *   fr3 /= fr5; fr3 += fr0; r6 = ftrc(fr3); fpul = r6;
 *   fr3 = float(fpul); fr3 *= fr5; fr5 = 0; fr4 -= fr3; fr6 = fr4;
 *   fr6 = fr4*fr6
 *   loop { fpul = r4; r4 -= 2; T = (r4 >= r5); fr2 = float(fpul);
 *          fr2 -= 0; fr5 = fr6; fr5 = fr2/fr5; } while (T)
 *   fr6 = 1; r3 = 1; fr3 = fr6; fr3 -= fr5; T = ((r3 & r6gpr) == 0)
 *   fr4 /= fr3; fr2 = fr7*fr2; fr0 = fr4; fr6 = fmac(fr0,fr4,fr6);
 *   fr4 = fr2
 *   T==0 (r6gpr odd) -> fr0 = -fr4, rts            (exit T=0)
 *   T==1            -> rts with fr0 = fr4          (exit T=1)
 * Exit: r3=1, r4 (loop var), r6 (ftrc int), fr0..fr7, sr(T); r0 = last
 * mova constant in the EXECUTION alias (0x0C03A92C — the oracle shows the
 * unit runs at the 0x0C P0 alias; values alias-free, high byte observed);
 *
 * Validated against extract/analysis/goldens_s8b/f_0c03a6e0.cases and
 * f_0c03a140.cases (64+64 pairs / 64+64 RAM cases, byte-exact shadow).
 */
#ifndef VF3_FIGHT_FDIVKER_H
#define VF3_FIGHT_FDIVKER_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r0, r1, r3, r4, r5, r6, r15;
    uint32_t fr0, fr1, fr2, fr3, fr4, fr5, fr6, fr7;
    uint32_t sr;
} vf3_fdivker_out;

void vf3_fdivker_8c03a6e0(uint32_t in_r1, uint32_t in_r4, uint32_t in_r5,
                          uint32_t in_r6, uint32_t in_r15, uint32_t in_sr,
                          uint32_t in_fpscr, vf3_fdivker_out *o,
                          const vf3_ram_map *ram);
/* 0x8C03A140 entry: extra r14 argument, computes r4 then shared body. */
void vf3_fdivker_8c03a140(uint32_t in_r1, uint32_t in_r4, uint32_t in_r14,
                          uint32_t in_r5, uint32_t in_r6, uint32_t in_r15,
                          uint32_t in_sr, uint32_t in_fpscr,
                          vf3_fdivker_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_FDIVKER_H */
