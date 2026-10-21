#include "platform/input.h"

static uint8_t axis(int16_t value)
{
    return (uint8_t)(((int32_t)value + 32768) / 256);
}

static uint8_t trigger(int16_t value)
{
    return value <= 0 ? 0 : (uint8_t)((uint32_t)value * 255u / 32767u);
}

vf3_maple_pad vf3_input_to_maple(const vf3_host_input *input)
{
    vf3_maple_pad pad = {0xffffu, 0, 0, 128, 128, 128, 128};
    const uint16_t valid = VF3_PAD_A | VF3_PAD_B | VF3_PAD_X | VF3_PAD_Y |
        VF3_PAD_START | VF3_PAD_UP | VF3_PAD_DOWN | VF3_PAD_LEFT | VF3_PAD_RIGHT;
    if (!input) return pad;
    pad.buttons = (uint16_t)~(input->pressed & valid);
    pad.rtrig = trigger(input->right_trigger);
    pad.ltrig = trigger(input->left_trigger);
    pad.joyx = axis(input->left_x);
    pad.joyy = axis(input->left_y);
    pad.joy2x = axis(input->right_x);
    pad.joy2y = axis(input->right_y);
    return pad;
}

int vf3_input_device_slot(uint32_t slots[VF3_HOST_PLAYERS], uint32_t id, int connected)
{
    int i;
    if (!id) return -1;
    for (i = 0; i < VF3_HOST_PLAYERS; ++i) {
        if (slots[i] == id) {
            if (!connected) slots[i] = 0;
            return i;
        }
    }
    if (connected) {
        for (i = 0; i < VF3_HOST_PLAYERS; ++i) {
            if (!slots[i]) { slots[i] = id; return i; }
        }
    }
    return -1;
}
