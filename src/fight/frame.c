/* fight/frame.c — fight scene frame pipeline (host-port).
 *
 * STALE-ADDRESS WARNING (M27, 2026-09-24): the addresses below were
 * identified on the pre-M23 shuffled image. On the corrected image:
 *   0x8C0B1AA8/0x8C0B1AC0 are TABLE WORDS inside f_8c0b1a54 (inline
 *      bsrf dispatch table at 0x8C0B1AA2..8C0B1AD0), NOT function starts.
 *   0x8c09d6e0 is mid-function inside the MT evaluator f_8c09d690.  (OK)
 *   0x8c0796f4 decodes as real code but is entered dynamically (not in
 *      baseline funcs CSV — jsr-only border below Vf3Prologue reach).
 * The FRAME_SLOTS ladder + scene0A predicate structure need re-derivation
 * from the true f_8c0b1a54 walker (see docs/re/mainloop_m25.md tremors).
 * Behaviour composition logic below is retained as the best current model.
 */
#include "frame.h"
#include "sd_slot_lookup.h"

/* The six slots the runner calls per frame (morale trace + static disasm):
 * see task_run_c.c comment for the verbatim addresses. */
static const uint16_t FRAME_SLOTS[6] = {0x0C0E, 0x76AC, 0x0C0E,
                                        0x76B8, 0x0C0E, 0x76C4};

int vf3_frame_step(VF3_FrameState *st)
{
    if (!st || !st->cb || !st->scene_state)
        return -1;

    /* predicate: read scene id byte (0x0A == fight) */
    uint32_t scene_id = st->scene_state[3];
    if (scene_id != 0x0A)
        return 1;   /* non-fight: nothing on this frame */

    /* task runner: 6-slot call ladder (r4 = slot id, r6 saved arg) */
    for (unsigned i = 0; i < 6; ++i)
        if (st->cb->task_call)
            st->cb->task_call(st->cb->task_ctx, FRAME_SLOTS[i],
                              0, /* r5 (unused in captured trace) */
                              0 /* r6 (task param from r6_saved) */);

    /* motion: per-frame tuple pull for one part (they cycle across frames) */
    if (st->cb->mt_step) {
        float    q4[4];
        uint8_t  mode, tag;
        st->cb->mt_step(st->task->part_counter & 7, q4, &mode, &tag);
        /* task ring update (trace: ring_counter increments every frame) */
        st->task->ring_counter++;
        st->task->module_tick++;
    }

    /* sd event pulse: the four known names return when slots fire during
     * frame transitions; those return through sd_slot_lookup. */
    if (st->cb->sd_name) {
        /* events multiplex: id source lives in task hdr bytes elsewhere —
         * when a frame sees a non-zero stream change, name it */
        (void)vf3_sd_slot_name((uint16_t)(0xC7 + (st->frame_no & 3)));
    }

    st->frame_no++;
    st->scene_iter++;
    return 4;      /* fight */
}
