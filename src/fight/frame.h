#pragma once
#include <stdint.h>
#include "task_vm.h"

/* Fight-scene frame driver (docs/evidence M7/M13/M19).
 * Pipeline: scene predicate -> per-frame walker -> task runner -> channels.
 * Composition of named pieces ported from 1ST_READ modules. */

struct VF3_FrameState;   /* opaque engine state (reconstructed live) */

typedef struct VF3_FrameCallbacks {
    /* motion: read one nittô frame of one part; fills quad+streams */
    int (*mt_step)(uint32_t part, float q4[4], uint8_t *mode, uint8_t *tag);
    /* task slot helper call (trace sites of task_run_C) */
    void (*task_call)(void *task_ctx, uint32_t slot_id, uint32_t r5,
                      uint32_t r6);
    /* sd slot-name lookup: returns static string per sd_ id */
    const char *(*sd_name)(uint16_t id);
    void *task_ctx;
} VF3_FrameCallbacks;

typedef struct VF3_FrameState {
    const uint8_t *scene_state;   /* scene byte lives at +3 */
    VF3_TaskFields *task;         /* r14-struct copy (live) */
    uint32_t        frame_no;
    uint32_t        scene_iter;
    const VF3_FrameCallbacks *cb;
} VF3_FrameState;

/* full 60Hz frame tick; returns predicate result (4==fight) */
int vf3_frame_step(VF3_FrameState *st);
