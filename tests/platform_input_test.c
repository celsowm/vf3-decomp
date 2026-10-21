#include "platform/sdl_platform.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK(expr) do { if (!(expr)) { fprintf(stderr, "%s:%d: %s (%s)\n", __FILE__, __LINE__, #expr, SDL_GetError()); return 1; } } while (0)

/* Drive the same two host samples through guest Maple requests. Distinct
 * player buttons must arrive at distinct receive buffers, active-low. */
static int maple_delivery(const vf3_maple_pad pads[2])
{
    uint8_t ram[256] = {0};
    vf3_maple_bus bus;
    const uint32_t words[8] = {
        1, 0x0c000080u, 0x01002009u, 0x01000000u,
        0x80010001u, 0x0c000090u, 0x01406009u, 0x01000000u
    };
    for (unsigned i = 0; i < 8; ++i)
        for (unsigned b = 0; b < 4; ++b) ram[4*i+b] = (uint8_t)(words[i] >> (8*b));
    vf3_maple_bus_init(&bus, 3);
    bus.pads[0] = pads[0]; bus.pads[1] = pads[1];
    vf3_maple_dma_result r = vf3_maple_dma_bus(ram, 0x0c000000u,
        sizeof ram, 0x0c000000u, &bus);
    CHECK(r.status == VF3_MAPLE_DMA_OK && r.blocks == 2);
    for (unsigned p = 0; p < 2; ++p) {
        const uint8_t *wire = ram+128+16*p;
        CHECK(wire[0] == 8 && wire[1] == 64*p && wire[2] == 32+64*p && wire[3] == 3);
        CHECK(((unsigned)wire[8] | (unsigned)wire[9]<<8) == pads[p].buttons);
        CHECK(wire[10] == pads[p].rtrig && wire[11] == pads[p].ltrig);
        CHECK(wire[12] == pads[p].joyx && wire[13] == pads[p].joyy);
    }
    return 0;
}

static int mapping(void)
{
    vf3_host_input input = {0};
    vf3_maple_pad p = vf3_input_to_maple(NULL);
    uint32_t slots[2] = {0, 0};
    CHECK(p.buttons == 0xffff && p.joyx == 128 && p.joyy == 128 && p.joy2x == 128 && p.joy2y == 128);
    CHECK(!p.rtrig && !p.ltrig);
    input.pressed = VF3_PAD_A | VF3_PAD_B | VF3_PAD_X | VF3_PAD_Y | VF3_PAD_START |
                    VF3_PAD_UP | VF3_PAD_DOWN | VF3_PAD_LEFT | VF3_PAD_RIGHT;
    p = vf3_input_to_maple(&input);
    CHECK(p.buttons == (uint16_t)~0x06feu);
    input.pressed = 0xffff;
    CHECK(vf3_input_to_maple(&input).buttons == (uint16_t)~0x06feu); /* unsupported wire bits stay high */
    input.left_x = -32768; input.left_y = 32767; input.right_x = 0; input.right_y = -1;
    input.left_trigger = 32767; input.right_trigger = -32768;
    p = vf3_input_to_maple(&input);
    CHECK(p.joyx == 0 && p.joyy == 255 && p.joy2x == 128 && p.joy2y == 127);
    CHECK(p.ltrig == 255 && p.rtrig == 0);
    input.left_trigger = 0; input.right_trigger = 32767;
    p = vf3_input_to_maple(&input); CHECK(p.ltrig == 0 && p.rtrig == 255);
    CHECK(vf3_input_device_slot(slots, 11, 1) == 0);
    CHECK(vf3_input_device_slot(slots, 22, 1) == 1);
    CHECK(vf3_input_device_slot(slots, 22, 1) == 1); /* duplicate arrival */
    CHECK(vf3_input_device_slot(slots, 33, 1) == -1); /* full */
    CHECK(vf3_input_device_slot(slots, 11, 0) == 0);
    CHECK(slots[0] == 0 && slots[1] == 22); /* P2 remains P2 */
    CHECK(vf3_input_device_slot(slots, 33, 1) == 0);
    CHECK(vf3_input_device_slot(slots, 99, 0) == -1);
    CHECK(vf3_input_device_slot(slots, 0, 1) == -1);
    return 0;
}

static int event(SDL_WindowID id, SDL_EventType type, SDL_Scancode key)
{
    SDL_Event e;
    SDL_zero(e);
    e.type = type;
    if (type == SDL_EVENT_KEY_DOWN || type == SDL_EVENT_KEY_UP) {
        e.key.windowID = id; e.key.scancode = key; e.key.down = type == SDL_EVENT_KEY_DOWN;
    } else e.window.windowID = id;
    return SDL_PushEvent(&e) ? 0 : 1;
}

static int virtual_gamepads(vf3_platform *platform, SDL_WindowID id)
{
    SDL_VirtualJoystickDesc desc;
    SDL_JoystickID ids[3], *existing;
    SDL_Joystick *joysticks[3];
    vf3_maple_pad pads[2];
    int i, count;
    existing = SDL_GetGamepads(&count);
    SDL_free(existing);
    if (count) {
        puts("virtual gamepad check skipped: physical gamepads already occupy host slots");
        return 0;
    }
    SDL_INIT_INTERFACE(&desc);
    desc.type = SDL_JOYSTICK_TYPE_GAMEPAD;
    desc.naxes = SDL_GAMEPAD_AXIS_COUNT;
    desc.nbuttons = SDL_GAMEPAD_BUTTON_COUNT;
    desc.axis_mask = (1u << SDL_GAMEPAD_AXIS_COUNT) - 1;
    desc.button_mask = (1u << SDL_GAMEPAD_BUTTON_COUNT) - 1;
    desc.name = "VF3 test virtual gamepad";
    for (i = 0; i < 3; ++i) {
        ids[i] = SDL_AttachVirtualJoystick(&desc);
        CHECK(ids[i] != 0);
        CHECK(SDL_IsGamepad(ids[i]));
        joysticks[i] = SDL_OpenJoystick(ids[i]);
        CHECK(joysticks[i] != NULL);
        CHECK(SDL_SetJoystickVirtualAxis(joysticks[i], SDL_GAMEPAD_AXIS_LEFT_TRIGGER, -32768));
        CHECK(SDL_SetJoystickVirtualAxis(joysticks[i], SDL_GAMEPAD_AXIS_RIGHT_TRIGGER, -32768));
        CHECK(vf3_platform_poll(platform, pads));
    }
    CHECK(SDL_SetJoystickVirtualButton(joysticks[0], SDL_GAMEPAD_BUTTON_SOUTH, true));
    CHECK(SDL_SetJoystickVirtualButton(joysticks[0], SDL_GAMEPAD_BUTTON_WEST, true));
    CHECK(SDL_SetJoystickVirtualButton(joysticks[0], SDL_GAMEPAD_BUTTON_DPAD_LEFT, true));
    CHECK(SDL_SetJoystickVirtualButton(joysticks[1], SDL_GAMEPAD_BUTTON_EAST, true));
    CHECK(SDL_SetJoystickVirtualAxis(joysticks[1], SDL_GAMEPAD_AXIS_LEFTX, -32768));
    CHECK(SDL_SetJoystickVirtualAxis(joysticks[1], SDL_GAMEPAD_AXIS_RIGHT_TRIGGER, 32767));
    CHECK(SDL_SetJoystickVirtualButton(joysticks[2], SDL_GAMEPAD_BUTTON_NORTH, true));
    SDL_UpdateJoysticks();
    CHECK(vf3_platform_poll(platform, pads));
    /* No focus event has occurred since creation. Held controller input must
     * remain neutral in the initially hidden window, without FOCUS_LOST. */
    CHECK(pads[0].buttons == 0xffff && pads[1].buttons == 0xffff);
    CHECK(pads[1].joyx == 128 && pads[1].rtrig == 0);
    CHECK(!event(id, SDL_EVENT_WINDOW_FOCUS_GAINED, SDL_SCANCODE_UNKNOWN));
    CHECK(vf3_platform_poll(platform, pads));
    CHECK(pads[0].buttons == (uint16_t)~0x0444u);
    CHECK(pads[1].buttons == (uint16_t)~0x0002u);
    CHECK(pads[1].joyx == 0 && pads[1].rtrig == 255 && pads[1].ltrig == 0);
    CHECK(!maple_delivery(pads));
    SDL_CloseJoystick(joysticks[0]);
    CHECK(SDL_DetachVirtualJoystick(ids[0]));
    CHECK(vf3_platform_poll(platform, pads));
    CHECK(pads[0].buttons == (uint16_t)~0x0200u); /* waiting third device gets free slot */
    CHECK(pads[1].buttons == (uint16_t)~0x0002u); /* second device remains player 2 */
    for (i = 1; i < 3; ++i) {
        SDL_CloseJoystick(joysticks[i]);
        CHECK(SDL_DetachVirtualJoystick(ids[i]));
    }
    CHECK(vf3_platform_poll(platform, pads));
    CHECK(pads[0].buttons == 0xffff && pads[1].buttons == 0xffff);
    return 0;
}

static int lifecycle(void)
{
    vf3_platform_config config = {"VF3 platform regression", 1, 0};
    vf3_platform *platform = vf3_platform_create(&config);
    vf3_maple_pad pads[2];
    SDL_Window **windows;
    SDL_WindowID id;
    SDL_Renderer *renderer;
    SDL_RendererLogicalPresentation mode;
    uint32_t *pixels;
    uint64_t before;
    int count, w, h;
    CHECK(platform != NULL);
    windows = SDL_GetWindows(&count);
    CHECK(windows && count == 1);
    id = SDL_GetWindowID(windows[0]);
    CHECK(!(SDL_GetWindowFlags(windows[0]) & SDL_WINDOW_INPUT_FOCUS));
    renderer = SDL_GetRenderer(windows[0]);
    SDL_free(windows);
    CHECK(SDL_GetRenderLogicalPresentation(renderer, &w, &h, &mode));
    CHECK(w == 640 && h == 480 && mode == SDL_LOGICAL_PRESENTATION_LETTERBOX);
    CHECK(vf3_platform_poll(platform, pads));
    CHECK(!virtual_gamepads(platform, id));
    CHECK(!event(id, SDL_EVENT_WINDOW_FOCUS_GAINED, SDL_SCANCODE_UNKNOWN));
    CHECK(!event(id, SDL_EVENT_KEY_DOWN, SDL_SCANCODE_Z));
    CHECK(!event(id, SDL_EVENT_KEY_DOWN, SDL_SCANCODE_UP));
    CHECK(!event(id, SDL_EVENT_KEY_DOWN, SDL_SCANCODE_V));
    CHECK(!event(id, SDL_EVENT_KEY_DOWN, SDL_SCANCODE_RSHIFT));
    CHECK(vf3_platform_poll(platform, pads));
    CHECK(pads[0].buttons == (uint16_t)~0x0014u);
    CHECK(pads[1].buttons == (uint16_t)~0x000cu);
    CHECK(!maple_delivery(pads));
    CHECK(!event(id, SDL_EVENT_KEY_UP, SDL_SCANCODE_Z));
    CHECK(vf3_platform_poll(platform, pads));
    CHECK(pads[0].buttons == (uint16_t)~0x0010u);
    CHECK(!event(id, SDL_EVENT_WINDOW_FOCUS_LOST, SDL_SCANCODE_UNKNOWN));
    CHECK(!event(id, SDL_EVENT_KEY_DOWN, SDL_SCANCODE_Z));
    CHECK(vf3_platform_poll(platform, pads));
    CHECK(pads[0].buttons == 0xffff && pads[1].buttons == 0xffff);
    CHECK(!event(id, SDL_EVENT_WINDOW_FOCUS_GAINED, SDL_SCANCODE_UNKNOWN));
    CHECK(vf3_platform_poll(platform, pads));
    CHECK(pads[0].buttons == 0xffff && pads[1].buttons == 0xffff); /* no stuck keys */
    CHECK(!event(id + 999, SDL_EVENT_KEY_DOWN, SDL_SCANCODE_Z));
    CHECK(vf3_platform_poll(platform, pads));
    CHECK(pads[0].buttons == 0xffff);
    pixels = (uint32_t *)calloc(640 * 480, sizeof *pixels);
    CHECK(pixels != NULL);
    CHECK(!vf3_platform_present(platform, pixels, 0));
    CHECK(vf3_platform_present(platform, pixels, 640 * 4));
    free(pixels);
    before = vf3_platform_time_ns();
    vf3_platform_sleep_ns(1000000);
    CHECK(vf3_platform_time_ns() >= before);
    CHECK(!event(id, SDL_EVENT_WINDOW_CLOSE_REQUESTED, SDL_SCANCODE_UNKNOWN));
    CHECK(!vf3_platform_poll(platform, pads));
    CHECK(pads[0].buttons == 0xffff && pads[1].buttons == 0xffff);
    vf3_platform_destroy(platform);
    platform = vf3_platform_create(&config);
    CHECK(platform != NULL); /* create/destroy may be repeated */
    vf3_platform_destroy(platform);
    vf3_platform_destroy(NULL);
    return 0;
}

int main(int argc, char **argv)
{
    (void)argc; (void)argv;
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1"); /* virtual devices with dummy video */
    if (mapping() || lifecycle()) return 1;
    puts("platform_input: wire mapping, stable slots, keyboard/focus/close, presentation and lifecycle passed");
    return 0;
}
