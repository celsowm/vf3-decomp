/* vf3 tailcall fragment family (SH-4 epilogue idiom).
 *
 * 0x8C092F12 (10 B, 39743 hits): the epilogue leaves one function mid-stream:
 *   fmov.s fr0,@-r4     ; [r4-4] = fr0 (entry fr0 spilled to scratch)
 *   add #12,r15         ; caller frame: 12 bytes of the current frame
 *                        ; were only borrowed (pushed) slots
 *   mov.l @r15+,r13     ; unwind: pop r13
 *   rts                 ; (delay) mov.l @r15+,r14  unwind: pop r14
 *
 * The entry snapshot is taken at the fragment PC with the frame pointer
 * pointing at the borrowed slots, and the oracle exit two fetches after
 * rts (i.e. the second pop has retired). The differential test therefore
 * expects exactly: r4-4, r15+12, r13/r14 popped, plus the shadow-vs-exit
 * memory diff over the whole watched window (the pushed/popped words must
 * come back byte-identical because the pops are reads, not writes).
 *
 * pr/sr/fpscr/macl/mach/fr*: unchanged by the fragment, guaranteed by the
 * shared harness's full-37 compare against the oracle exit snapshot.
 */
#ifndef VF3_FIGHT_TAILCALL_H
#define VF3_FIGHT_TAILCALL_H

#include <stdint.h>

#include "fight/poly_classify.h" /* vf3_ram_map */

typedef struct {
    uint32_t r4, r13, r14, r15;
    uint32_t pr;
} vf3_tailcall_out;

/* Model 0x8C092F12 exactly: spill fr0 to [in_r4-4], unwind two pops from
 * the in_r15 frame, return via the rts delay-slot pop. pr_in is the entry
 * pr (unused, carried through for the harness compare). */
void vf3_tailcall_8c092f12(uint32_t in_r4, uint32_t in_r15, float in_fr0,
                           vf3_tailcall_out *o, uint32_t pr_in,
                           const vf3_ram_map *ram);

/* Model 0x8C092ABE exactly: spill fr0 to [in_r4-4], accumulate
 * [r2+4] += [r1] with r1 = 4 + mem32(in_r15+4), r2 = mem32(in_r15),
 * then unwind: r15 += 12. */
void vf3_tailcall_8c092abe(uint32_t in_r4, uint32_t in_r15, float in_fr0,
                           vf3_tailcall_out *o, const vf3_ram_map *ram);

/* Test-only public read used by the abe runner to refresh caller-owned
 * registers from the shadow after the fragment ran. */
uint32_t t_rd32pub(const vf3_ram_map *ram, uint32_t addr);

#endif /* VF3_FIGHT_TAILCALL_H */
