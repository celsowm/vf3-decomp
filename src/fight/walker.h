#pragma once
#include <stdint.h>
#include "../sys/mainloop.h"

/* fight/walker.h — scene walker f_8c0b1a54 + fight runner f_8c0796f4 (M45).
 *
 * Walker (true image, docs/re/walker_m35.md, scene_walker_m29.md):
 *   jsr helperA(0) + jsr helperB(saved r7) -> scene word at locals+24
 *   switch {1,5,9,14,17} -> word offset {112/0x70,mov.w+24,+20,+16,+12}
 *   default -> tail 0x8c0b1ac4 (r2=*(r14+4); jsr lit(r14) if nonzero)
 *   jsr @r12 with r4 = *(r13 + word)  (per-scene handler arg)
 *   block 0x8C0B1AA2.. = inline bsrf/word table (NOT fn entries).
 * Runner f_8c0796f4: dynamic-entry (jsr @rN only), boot-trace absent;
 *   entered with r4 = task handle forwarded as r14.
 */

typedef uint32_t (*VF3_SceneHandler)(uint32_t arg);
typedef uint32_t (*VF3_HelperFn)(uint32_t arg);

/* Walker config: host registry provides helpers + per-scene handler. */
typedef struct VF3_Walker {
    VF3_HelperFn   helper_a;   /* lit @0x8C0B1AC0 target */
    VF3_HelperFn   helper_b;   /* lit @0x8C0B1AB0 target */
    VF3_SceneHandler scene_fn; /* @r12 target (resolved per word) */
    gaddr          r13_base;   /* scene root (fight: 0x8C1D2D34) */
    gaddr          r14_task;   /* task struct base */
} VF3_Walker;

/* Map scene word -> struct-offset word (M35: 0xC4F0/0x756C/0x7662/0x8570
 * family; 1 -> 112). Returns 0 + uses tail path when unmapped. */
uint16_t vf3_walker_slot(unsigned scene_word, int *is_tail);

/* One walker step: runs helpers, selects slot, calls scene_fn(*(r13+word)).
 * Returns handler result; *arg_out receives the handler arg. */
uint32_t vf3_walker_step(const VF3_Walker *w, unsigned scene_word,
                         uint32_t r7_saved, uint32_t *arg_out);
