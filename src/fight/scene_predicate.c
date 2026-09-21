/* fight/scene_predicate.c — fight-scene predicate + scene frame walker
 *
 * Provenance: 1ST_READ 0x8C0B1AA8 (cand_is_scene0A) + 0x8C0B24FA
 * (cand_scene0A_frame_walker). Trace-verified 2026-09-19 (trace_fight1.bin):
 * record 0 of the fight trace is inside 0x8C0B1AC0; the scene-walker is the
 * only frame-loop ancestor that reaches fight code.
 *
 * Body: docs/evidence in docs/re/fight_dispatch_chain.md.
 */
#include <stdint.h>

/* Fight's per-frame root register conventions (established):
 *   r13 -> scene root struct (0x8C1D2D34 during fight; r13+8 = scene-state ptr)
 *   r14 -> call-injected per-task/work struct
 */
typedef struct VF3_FrameCtx {
    const uint8_t *scene_state; /* == *(r13+8) */
    void *task;                 /* r14 */
} VF3_FrameCtx;

/* --- 0x8C0B1AA8..0x8C0B1AC7 + sub-entry 0x8C0B1AC0 ----------------------
 * Entry block:
 *   8C0B1AA8  sts.l pr,@-r15
 *   8C0B1AAC  mov.l @(8,r13),r4        ; r4 = scene_state
 *   8C0B1AB2  add #3,r4
 *   8C0B1AB6  mov.b @r4,r4             ; scene id byte
 *   8C0B1ABA  mov r4,r0 ; cmp/eq #0xA  ; bt 0x8C0B1AFA (fight)
 * Sub-entry used by the walker (0x8C0B1AC0):
 *   mov #1,r0 ; mov #4,r0 ; rts ; nop   (r0 = status)
 * sh4 returns r0=4 when the containing call site took the branch with
 * r0==0x0A set (delay-slot controlled), r0=1 otherwise.
 * In C terms: return (scene_id == 0x0A) ? 4 : 1;
 * -------------------------------------------------------------------------*/
int vf3_scene_is_fight(const VF3_FrameCtx *ctx)
{
    /* scene id byte lives at scene_state[3] (SCENE id field; fight = 0x0A) */
    uint32_t scene_id = ctx->scene_state[3];
    return scene_id == 0x0A ? 4 : 1;
}
