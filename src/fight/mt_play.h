/* fight/mt_play.h — MT motion channel evaluator (f_8c09d690 port). */
#ifndef VF3_MT_PLAY_H
#define VF3_MT_PLAY_H

#include <stdint.h>

typedef struct VF3MtTask {
    const uint8_t *hdr;        /* *(task + 0x1D00): motion instance header */
    uint16_t       cycle;      /* *(u16*)(task + 0x1A00): loop length (<<8) */
    /* RAM translation for the absolute u32 pointers stored in the header:
     * host_addr = ram + (hdr_word - ram_base). */
    const uint8_t *ram;
    uint32_t       ram_base;
} VF3MtTask;

/* Evaluate one motion instance for one frame: decode 63 channel op bytes at
 * hdr+12 and write 63 floats to (*out_pp), advancing the cursor by 63.
 * phase = current motion time in 1/256 units.  Returns 0 on success. */
int vf3_mt_eval_frame(const VF3MtTask *task, int32_t phase, float **out_pp);

#endif
