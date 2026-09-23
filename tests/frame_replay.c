/* tests/frame_replay.c — vf3_frame_step harness against M13 captured facts.
 *
 * Drives the frame pipeline with synthetic+measured state and asserts the
 * exact invariants the trace shows:
 *   - predicate answers 4 once scene_state[3] == 0x0A
 *   - the 6-slot task ladder fires once per fight frame, in order
 *   - the ring counter ticks once per fight frame
 *   - an sd name resolves in-range for the slot round-robin (0xC7..0xCA)
 */
#include <stdio.h>
#include <string.h>

#include "../src/fight/frame.h"

typedef struct FrameLog {
    uint32_t calls[6];
    unsigned n_calls;
    unsigned mt_steps;
    uint16_t sd_last;
    unsigned sd_hits;
} FrameLog;

static FrameLog g_log;

static void task_call(void *ctx, uint32_t slot, uint32_t r5, uint32_t r6)
{
    (void)ctx; (void)r6;
    if (g_log.n_calls < 6)
        g_log.calls[g_log.n_calls++] = slot;
    g_log.sd_last = 0;
}

static int mt_step(uint32_t part, float q4[4], uint8_t *mode, uint8_t *tag)
{
    (void)part;
    static const float seq[4] = {0.00168f, 0.003f, 0.0f, 0.06f};   /* captured */
    memcpy(q4, seq, sizeof(seq));
    *mode = 2;  /* captured stream A */
    *tag  = 0x10; /* captured stream B */
    g_log.mt_steps++;
    return 0;
}

static const char *sd_name(uint16_t id)
{
    (void)id;
    g_log.sd_hits++;
    /* mirror of the table */
    return id == 0xC7 ? "sd_passing_far" :
           id == 0xC8 ? "sd_passing_far_off" :
           id == 0xC9 ? "sd_Ak_01" : "sd_Ak_02";
}

int main(void)
{
    VF3_TaskFields task;
    memset(&task, 0, sizeof(task));
    uint8_t scene_state[4] = {0, 0, 0, 0x0A};   /* fight */

    VF3_FrameCallbacks cb = {
        .mt_step = mt_step, .task_call = task_call,
        .sd_name = sd_name, .task_ctx = NULL,
    };
    VF3_FrameState st = {
        .scene_state = scene_state, .task = &task,
        .frame_no = 0, .scene_iter = 0, .cb = &cb,
    };

    int fails = 0;

    /* non-fight frame must be skipped */
    scene_state[3] = 0x07;
    if (vf3_frame_step(&st) != 1) {
        printf("FAIL: non-fight predicate\n");
        ++fails;
    }

    scene_state[3] = 0x0A;
    for (unsigned f = 0; f < 60; ++f) {
        g_log.n_calls = 0;
        if (vf3_frame_step(&st) != 4) {
            printf("FAIL frame %u: predicate\n", f);
            ++fails;
            break;
        }
        if (g_log.n_calls != 6) {
            printf("FAIL frame %u: %u task calls (want 6)\n", f, g_log.n_calls);
            ++fails;
            break;
        }
        if (g_log.calls[0] != 0x0C0E || g_log.calls[1] != 0x76AC) {
            printf("FAIL frame %u: wrong slot order\n", f);
            ++fails;
            break;
        }
        if (task.ring_counter != f + 1 || task.module_tick != f + 1) {
            printf("FAIL frame %u: counters %u/%u\n", f,
                   task.ring_counter, task.module_tick);
            ++fails;
            break;
        }
    }

    scene_state[3] = 0x07;
    if (vf3_frame_step(&st) != 1) ++fails;    /* re-check exit */

    printf("frame_replay: %s\n", fails ? "FAIL" : "PASS");
    return fails ? 1 : 0;
}
