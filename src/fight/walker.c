/* fight/walker.c — scene walker f_8c0b1a54 transliteration (M45).
 *
 * True-image structure (extract/analysis/scene_walker_true.txt,
 * docs/re/walker_m35.md, docs/re/scene_walker_m29.md):
 *   push pr, locals; jsr helperA(r4=0); jsr helperB(r4=saved r7);
 *   r0 = *(locals+24) = scene/state word;
 *   switch -> offset word; jsr @r12 (r4=*(r13+word)).
 * FRAME_SLOTS in frame.c are this kind of struct-offset word, NOT PCs.
 */
#include "walker.h"

uint16_t vf3_walker_slot(unsigned scene_word, int *is_tail)
{
    if (is_tail)
        *is_tail = 0;
    switch (scene_word) {
    case 1:  return 112;      /* r0 = 112 (imm) */
    case 5:  return 0x756C;   /* mov.w @+24 family (M35 walk) */
    case 9:  return 0x7662;   /* mov.w @+20 */
    case 14: return 0x8570;   /* mov.w @+16 */
    case 17: return 0xC4F0;   /* mov.w @(24,pc) @8C0B1AB8 */
    default:
        if (is_tail)
            *is_tail = 1;
        return 0;
    }
}

uint32_t vf3_walker_step(const VF3_Walker *w, unsigned scene_word,
                         uint32_t r7_saved, uint32_t *arg_out)
{
    uint32_t a = 0, b = 0;
    if (w) {
        if (w->helper_a)
            a = w->helper_a(0);
        if (w->helper_b)
            b = w->helper_b(r7_saved);
        (void)a; (void)b;
    }
    int tail = 0;
    uint16_t word = vf3_walker_slot(scene_word, &tail);
    uint32_t arg = 0;
    if (!tail && w && w->r13_base) {
        /* guest read *(r13 + word) via bound arena */
        extern uint32_t vf3_sys_rd32(gaddr);
        arg = vf3_sys_rd32(w->r13_base + word);
    } else if (tail && w) {
        /* 0x8c0b1ac4 tail: r2 = *(r14+4); jsr lit(r14) if nonzero.
         * Host model: leave arg 0, tail call handled by caller. */
        arg = 0;
    }
    if (arg_out)
        *arg_out = arg;
    if (w && w->scene_fn)
        return w->scene_fn(arg);
    return 0;
}
