#ifndef VF3_DRIVER_QUEUE_H
#define VF3_DRIVER_QUEUE_H
#include <stdint.h>

/* Recovered SNDDRV A0 handoff only. This interface neither advances hardware
 * nor interprets voices, and does not replace the ARM CPU or DSP. */
typedef struct vf3_driver_memory {
    void *context;
    uint32_t (*read32)(void *,uint32_t);
    void (*write32)(void *,uint32_t,uint32_t);
    void (*write8)(void *,uint32_t,uint8_t);
} vf3_driver_memory;
enum vf3_driver_handoff_result {
    VF3_DRIVER_EMPTY=0,VF3_DRIVER_HANDED_OFF=1,
    VF3_DRIVER_UNSUPPORTED=-1,VF3_DRIVER_INVALID_INPUT=-2
};
int vf3_driver_handoff_a0(const vf3_driver_memory *memory);
#endif
