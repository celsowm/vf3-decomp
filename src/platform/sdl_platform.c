#include "platform/sdl_platform.h"
#include <SDL3/SDL.h>
#include <stdlib.h>
#include <string.h>

struct vf3_platform {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Gamepad *gamepads[VF3_HOST_PLAYERS];
    uint32_t ids[VF3_HOST_PLAYERS];
    bool keys[SDL_SCANCODE_COUNT];
    bool focused, running;
    SDL_InitFlags initialized;
};

static void discover_gamepads(vf3_platform *p)
{
    int count = 0, i, slot;
    SDL_JoystickID *ids = SDL_GetGamepads(&count);
    for (i = 0; ids && i < count; ++i) {
        slot = vf3_input_device_slot(p->ids, ids[i], 1);
        if (slot < 0 || p->gamepads[slot]) continue;
        p->gamepads[slot] = SDL_OpenGamepad(ids[i]);
        if (!p->gamepads[slot]) p->ids[slot] = 0;
    }
    SDL_free(ids);
}

vf3_platform *vf3_platform_create(const vf3_platform_config *config)
{
    vf3_platform *p = (vf3_platform *)calloc(1, sizeof *p);
    const SDL_InitFlags flags = SDL_INIT_VIDEO | SDL_INIT_GAMEPAD;
    SDL_WindowFlags window_flags = SDL_WINDOW_RESIZABLE;
    if (!p) { SDL_SetError("VF3 platform allocation failed"); return NULL; }
    if (!SDL_InitSubSystem(flags)) { free(p); return NULL; }
    p->initialized = flags;
    if (config && config->hidden) window_flags |= SDL_WINDOW_HIDDEN;
    p->window = SDL_CreateWindow(config && config->title ? config->title : "VF3 native platform",
                                VF3_FRAME_WIDTH, VF3_FRAME_HEIGHT, window_flags);
    if (!p->window) goto fail;
    p->renderer = SDL_CreateRenderer(p->window, NULL);
    if (!p->renderer) goto fail;
    if (!SDL_SetRenderLogicalPresentation(p->renderer, VF3_FRAME_WIDTH, VF3_FRAME_HEIGHT,
                                          SDL_LOGICAL_PRESENTATION_LETTERBOX)) goto fail;
    if (!SDL_SetRenderVSync(p->renderer, config && config->vsync ? 1 : 0)) goto fail;
    p->texture = SDL_CreateTexture(p->renderer, SDL_PIXELFORMAT_ARGB8888,
                                  SDL_TEXTUREACCESS_STREAMING, VF3_FRAME_WIDTH, VF3_FRAME_HEIGHT);
    if (!p->texture || !SDL_SetTextureScaleMode(p->texture, SDL_SCALEMODE_NEAREST) ||
        !SDL_SetTextureBlendMode(p->texture, SDL_BLENDMODE_NONE)) goto fail;
    p->running = true;
    /* A newly created hidden/background window may never receive FOCUS_LOST.
     * Initialize from the real window flags, then track focus transitions. */
    p->focused = (SDL_GetWindowFlags(p->window) & SDL_WINDOW_INPUT_FOCUS) != 0;
    discover_gamepads(p);
    return p;
fail: {
        char error[512];
        SDL_strlcpy(error, SDL_GetError(), sizeof error);
        vf3_platform_destroy(p);
        SDL_SetError("%s", error);
        return NULL;
    }
}

void vf3_platform_destroy(vf3_platform *p)
{
    int i;
    if (!p) return;
    for (i = 0; i < VF3_HOST_PLAYERS; ++i) {
        if (p->gamepads[i]) SDL_CloseGamepad(p->gamepads[i]);
    }
    if (p->texture) SDL_DestroyTexture(p->texture);
    if (p->renderer) SDL_DestroyRenderer(p->renderer);
    if (p->window) SDL_DestroyWindow(p->window);
    if (p->initialized) SDL_QuitSubSystem(p->initialized);
    free(p);
}

const char *vf3_platform_error(void) { return SDL_GetError(); }

static uint16_t keyboard_buttons(const vf3_platform *p, int player)
{
    static const SDL_Scancode keys[VF3_HOST_PLAYERS][9] = {
        {SDL_SCANCODE_Z, SDL_SCANCODE_X, SDL_SCANCODE_A, SDL_SCANCODE_S, SDL_SCANCODE_RETURN,
         SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT},
        {SDL_SCANCODE_V, SDL_SCANCODE_B, SDL_SCANCODE_F, SDL_SCANCODE_G, SDL_SCANCODE_RSHIFT,
         SDL_SCANCODE_I, SDL_SCANCODE_K, SDL_SCANCODE_J, SDL_SCANCODE_L}
    };
    static const uint16_t bits[9] = {VF3_PAD_A, VF3_PAD_B, VF3_PAD_X, VF3_PAD_Y, VF3_PAD_START,
                                    VF3_PAD_UP, VF3_PAD_DOWN, VF3_PAD_LEFT, VF3_PAD_RIGHT};
    uint16_t result = 0;
    int i;
    for (i = 0; i < 9; ++i) if (p->keys[keys[player][i]]) result |= bits[i];
    return result;
}

static void gamepad_input(SDL_Gamepad *gamepad, vf3_host_input *input)
{
    static const SDL_GamepadButton buttons[9] = {
        SDL_GAMEPAD_BUTTON_SOUTH, SDL_GAMEPAD_BUTTON_EAST, SDL_GAMEPAD_BUTTON_WEST,
        SDL_GAMEPAD_BUTTON_NORTH, SDL_GAMEPAD_BUTTON_START, SDL_GAMEPAD_BUTTON_DPAD_UP,
        SDL_GAMEPAD_BUTTON_DPAD_DOWN, SDL_GAMEPAD_BUTTON_DPAD_LEFT, SDL_GAMEPAD_BUTTON_DPAD_RIGHT
    };
    static const uint16_t bits[9] = {VF3_PAD_A, VF3_PAD_B, VF3_PAD_X, VF3_PAD_Y, VF3_PAD_START,
                                    VF3_PAD_UP, VF3_PAD_DOWN, VF3_PAD_LEFT, VF3_PAD_RIGHT};
    int i;
    if (!gamepad) return;
    for (i = 0; i < 9; ++i) if (SDL_GetGamepadButton(gamepad, buttons[i])) input->pressed |= bits[i];
    input->left_x = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFTX);
    input->left_y = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFTY);
    input->right_x = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_RIGHTX);
    input->right_y = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_RIGHTY);
    input->left_trigger = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFT_TRIGGER);
    input->right_trigger = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER);
}

int vf3_platform_poll(vf3_platform *p, vf3_maple_pad pads[VF3_HOST_PLAYERS])
{
    SDL_Event event;
    int i;
    if (!p || !pads) { SDL_SetError("VF3 poll requires platform and two pads"); return 0; }
    while (SDL_PollEvent(&event)) {
        const SDL_WindowID own = SDL_GetWindowID(p->window);
        switch (event.type) {
        case SDL_EVENT_QUIT: p->running = false; break;
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
            if (event.window.windowID == own) p->running = false;
            break;
        case SDL_EVENT_WINDOW_FOCUS_LOST:
            if (event.window.windowID == own) {
                p->focused = false;
                memset(p->keys, 0, sizeof p->keys);
            }
            break;
        case SDL_EVENT_WINDOW_FOCUS_GAINED:
            if (event.window.windowID == own) p->focused = true;
            break;
        case SDL_EVENT_KEY_DOWN:
        case SDL_EVENT_KEY_UP:
            if (event.key.windowID == own && p->focused &&
                event.key.scancode > SDL_SCANCODE_UNKNOWN && event.key.scancode < SDL_SCANCODE_COUNT) {
                p->keys[event.key.scancode] = event.type == SDL_EVENT_KEY_DOWN;
                if (event.type == SDL_EVENT_KEY_DOWN && event.key.scancode == SDL_SCANCODE_ESCAPE)
                    p->running = false;
            }
            break;
        case SDL_EVENT_GAMEPAD_ADDED: discover_gamepads(p); break;
        case SDL_EVENT_GAMEPAD_REMOVED:
            i = vf3_input_device_slot(p->ids, event.gdevice.which, 0);
            if (i >= 0) { SDL_CloseGamepad(p->gamepads[i]); p->gamepads[i] = NULL; }
            discover_gamepads(p);
            break;
        default: break;
        }
    }
    for (i = 0; i < VF3_HOST_PLAYERS; ++i) {
        vf3_host_input input = {0};
        if (p->focused && p->running) {
            input.pressed = keyboard_buttons(p, i);
            gamepad_input(p->gamepads[i], &input);
        }
        pads[i] = vf3_input_to_maple(&input);
    }
    return p->running ? 1 : 0;
}

int vf3_platform_present(vf3_platform *p, const uint32_t *pixels, int pitch)
{
    if (!p || !pixels || pitch < VF3_FRAME_WIDTH * (int)sizeof *pixels) {
        SDL_SetError("VF3 presentation requires a 640x480 ARGB8888 framebuffer and valid pitch");
        return 0;
    }
    return SDL_UpdateTexture(p->texture, NULL, pixels, pitch) &&
        SDL_SetRenderDrawColor(p->renderer, 0, 0, 0, 255) &&
        SDL_RenderClear(p->renderer) && SDL_RenderTexture(p->renderer, p->texture, NULL, NULL) &&
        SDL_RenderPresent(p->renderer);
}

uint64_t vf3_platform_time_ns(void) { return SDL_GetTicksNS(); }
void vf3_platform_sleep_ns(uint64_t duration) { SDL_DelayNS(duration); }
