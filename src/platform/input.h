#ifndef VF3_PLATFORM_INPUT_H
#define VF3_PLATFORM_INPUT_H

#include <stdint.h>
#include "sys/maple_hle.h"

#define VF3_HOST_PLAYERS 2

/* Dreamcast controller wire bit positions; see docs/re/maple.md. */
enum {
    VF3_PAD_B = 1u << 1, VF3_PAD_A = 1u << 2, VF3_PAD_START = 1u << 3,
    VF3_PAD_UP = 1u << 4, VF3_PAD_DOWN = 1u << 5,
    VF3_PAD_LEFT = 1u << 6, VF3_PAD_RIGHT = 1u << 7,
    VF3_PAD_Y = 1u << 9, VF3_PAD_X = 1u << 10
};

/* Host-facing, active-high buttons and signed full-range stick axes. Trigger
 * range is 0..32767. No deadzone is imposed here: this conversion is lossless
 * apart from the Dreamcast's 8-bit quantization. Device calibration belongs
 * in the frontend; game logic receives the same neutral 128 as Maple. */
typedef struct {
    uint16_t pressed;
    int16_t left_x, left_y, right_x, right_y;
    int16_t left_trigger, right_trigger;
} vf3_host_input;

vf3_maple_pad vf3_input_to_maple(const vf3_host_input *input);
/* Stable device slots: removing player 1 does not move player 2. Zero is the
 * empty ID. Returns the assigned/removed slot, or -1 for absent/full/zero. */
int vf3_input_device_slot(uint32_t slots[VF3_HOST_PLAYERS], uint32_t id, int connected);

#endif
