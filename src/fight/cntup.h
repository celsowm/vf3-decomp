/* vf3 counter updater — SH-4 0x8C08B7EE (68 B) + callee-1 ladder.
 *
 * b7ee body (tools/sh4full.py; lits 0c29bb84 / 0c29bcc0 / 00080001):
 *   sts.l pr,@-r15 ; r15 -= 84 ; [r15] = r14
 *   r3 = [[0x0c29bb84]+16] ; [r15+76] = r3
 *   r2 = [[0x0c29bb84]+20] ; [r15+80] = r2
 *   r4 = [[0x0c29bb84]+40] ; r0 = [r4]
 *   if (r0 & 2) exit                         (guard 1)
 *   r2 = [0x0c29bcc0] ; if (r2 & 0x00080001) exit   (guard 2)
 *   r5 = r15+4 ; bsr 0x8C08B89C   (callee-1, CALLED — see below)
 *   r5 = r15+4 ; bsr 0x8C08BB14   (callee-2, DELEGATED — see below)
 *   [ [r15] +16 ] = [r15+4]       (final store; identical in all goldens)
 *   r15 += 84 ; pr = pop ; rts (delay: r14 = pop = caller word)
 *
 * callee-1 (0x8C08B89C, returns 0x8C08BB06) runs with r4 = task struct A
 * (the caller's r14), r5 = frame+4. It loads struct bases r6 = [F+76]
 * (struct C) and r14 = [F+80] (struct B), fans struct words out over its
 * frame, folds flag bits into [F+4], and performs the observable struct
 * writes (all other traffic is frame-local):
 *   [A+36] += 1                      (per-call counter)
 *   [A+38]  = old+1                  (per-call counter)
 *   [A+22]  = old-1, reload 0x0A at 0 (countdown; reload path reads
 *                             [A+46]/[B+97]/[A+0x85]/[A+0x86])
 *   [A+28]  = 0 ; [A+34] = 0         (cleared on the captured path)
 *
 * callee-1 is NOT modelled here: it is ported readably in
 * src/fight/state_ladder.c (registered in src/fight/readable.c) and called
 * from cntup.c, with the private frame handed over as a RAM window so the
 * ladder's own frame and stack traffic stay out of the checked windows.  The
 * replay below is therefore a replay of the *readable* ladder: the oracle
 * checks what the ladder writes to the task struct.  The ladder's frame
 * contents are not in a checked window, so they are not checked here; the
 * ladder's own proof is tests/state_ladder_replay.c (the retained generated
 * translation) and docs/re/state_ladder.md.
 *
 * Callee-2 (0x8C08BB14 + nested bsr/jsr incl. a RAM-vector dynamic call)
 * is a documented scope cut (walker2-gate / frameseq precedent): its exit
 * register residue (r0-r7 incl. constant r0 = 0x1B80, fr3, sr/T) is forced
 * from the oracle in the replay test, and its RAM footprint inside the
 * checked windows is verified byte-identical-empty across all 8 RAM cases
 * (win0 code / win1 struct outside the 3 words / win2 tables / win4-9 far
 * words: zero diffs). Its stack scribble is the reason the test runs on
 * the derived nowin3 cases (tools/cases_dropwin.py); the committed full
 * goldens_b7 capture retains the stack page for a future full port.
 *
 * NOTE on static analysis: disasm_*.calls.csv carries NO edge for either
 * bsr (Ghidra-side miss from seed-fragmented boundaries), so port_plan /
 * port_backlog list this function as leaf closure_ok — wrongly. The true
 * call sites are 0x8C08B818 -> 0x8C08B89C and 0x8C08B820 -> 0x8C08BB14.
 */
#ifndef VF3_FIGHT_CNTUP_H
#define VF3_FIGHT_CNTUP_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r14;   /* passthrough (callee-saved); caller-word pop forced
                       from the oracle in the test */
    uint32_t r15;   /* in_r15 + 4 (shared-epilogue double pop) */
    uint32_t pr;    /* == in_pr */
} vf3_cntup_out;

void vf3_cntup_8c08b7ee(uint32_t in_r14, uint32_t in_r15, uint32_t in_pr,
                        vf3_cntup_out *o, const vf3_ram_map *ram);

#endif /* VF3_FIGHT_CNTUP_H */
