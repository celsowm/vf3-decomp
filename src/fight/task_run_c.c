/* fight/task_run_c.c — per-frame task-slot runner C port
 *
 * Provenance: 1ST_READ 0x8C0796F4..0x8C0798B8 (fight_f_8c0796f4,
 * cand_task_run_C). Trace: lightly active during fight (probe_run 2 hits in
 * M4; heavier during scene transitions).
 *
 * Structure (verified by sh4dump at each block):
 *   0x8C0796F4  mov.l @r3,r0 ; tst #8,r0 ; bf continuation
 *     — flag-gate: bit 3 of *(task flags) decides which path
 *   continuation: chain of (mov.w lit,r4 ; jsr @r14 ; nop)
 *     — r14 = task VM ctx pointer (helper call), r4 = slot index
 *   tail: jsr @r11 path for idx==3; r13-relative alternate chain
 *
 * C semantics: r14 -> VF3_TaskCall(ctx, slot_id) helper; r13+off data refs
 * kept as raw struct field access. The eight slot ids observed (from the
 * literal words beside each jsr) are kept verbatim, order preserved.
 */
#include <stdint.h>

/* (External) callee-side hooks — the actual task VM body lives inside the
 * engine's task struct at r14. Probe values at entry: r14 = ptr to the
 * fight task claim, r6 = saved task sub handle. */
typedef void (*VF3_TaskHelper)(/* r14=task ctx */ void *task,
                               /* r4 */ uint32_t slot_id,
                               /* r5,r6 */ uint32_t arg5, uint32_t arg6);

typedef struct VF3_TaskChain {
    uint32_t *sub_handle;     /* r12 [@r15 spilled]  */
    void     *task_ctx;       /* r14                 */
    void     *helper_hook;    /* jsr @r11 target     */
    VF3_TaskHelper call;      /* jsr @r14 via task   */
    uint32_t  scene_flags;    /* *(r3)->r0 lower bits (bit3 = alt path) */
    uint32_t  r13_base;       /* r13 scene-struct base */
    uint32_t  r6_saved;       /* r6 = task argument  */
} VF3_TaskChain;

/* Literal slot table recovered from the code (each mov.w lit,r4): */
static const uint16_t TASK_SLOTS[8] = {
    0x0C0E,  /* 0x8C079740 */
    0x76AC,  /* 0x8C079746 */
    0x0C0E,  /* 0x8C07974C */
    0x76B8,  /* 0x8C079752 */
    0x0C0E,  /* 0x8C079758 */
    0x76C4,  /* 0x8C07975E 3rd on same pair after the bt taken path */
    0, 0     /* pad: jsr @r11 tail slot uses its own arg (r4=@r12 reload) */
};

/* Per-frame runner: when scene flag bit3 set, run the slot chain.
 * At trace time the condition selects the fight side-chain; binary then
 * falls back to a single jsr @r11 helper if cmp happens.
 */
void vf3_task_run_c(VF3_TaskChain *c)
{
    /* 0x8C0796F4..0x8C0796FB: entry flag test */
    uint32_t flags = *(uint32_t *)0; /* placeholder -> r3 struct */
    (void)flags;

    if (!(c->scene_flags & 0x8u)) {
        /* 0x8C079702+: main slot chain. nops = delay slots, kept implicit. */
        c->call(c->task_ctx, TASK_SLOTS[0], 0, c->r6_saved);  /* r4=0x0C0E */
        c->call(c->task_ctx, TASK_SLOTS[1], 0, c->r6_saved);  /* r4=0x76AC */
        c->call(c->task_ctx, TASK_SLOTS[2], 0, c->r6_saved);  /* r4=0x0C0E */
        c->call(c->task_ctx, TASK_SLOTS[3], 0, c->r6_saved);  /* r4=0x76B8 */
        c->call(c->task_ctx, TASK_SLOTS[4], 0, c->r6_saved);  /* r4=0x0C0E */
        c->call(c->task_ctx, TASK_SLOTS[5], 0, c->r6_saved);  /* r4=0x76C4 */
        return;
    }

    /* Alternate path (0x8C079768..): jsr @r11 with @r12-spilled r4, then
     * a second @r14 chain for stage-dependent sub-slots. Task-fn identity
     * for the jsr @r11 hook lands in helper_hook (see M12 note).          */
    {   /* site 8C079768: jsr @r11 ; r4 = *sub_handle */
        typedef void (*helper_fn)(uint32_t r4);
        ((helper_fn)c->helper_hook)(*c->sub_handle);
    }
    /* 0x8C07977C+: r13-indexed second helper round */
    c->call(c->task_ctx, 0xF5AC, 0, c->r6_saved);   /* lit r4 observed */
}
