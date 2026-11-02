/* host/sdl3_input.c - the host's input: an SDL3 gamepad or the keyboard, read
 * into the Dreamcast pad the Maple model answers with.
 *
 * The guest never sees the host's device.  It asks the Maple model for the
 * pad's state (a GET_CONDITION request) and the model answers with the bytes
 * the hardware would put on the bus (src/sys/maple_hle.c).  This module is
 * the layer that turns the host's device into those bytes.
 *
 * The wire format (docs/re/maple.md):
 *   - the buttons are active low: a *zero* bit means the button is pressed and
 *     0xFFFF means nothing is pressed;
 *   - the bit positions are the KOS numbering the reference emulator uses
 *     (flycast's core/input/gamepad.h: DC_BTN_C is bit 0, DC_BTN_X is bit 10);
 *   - the analog axes are a byte each with 0x80 at the centre, and the
 *     triggers are 0x80 at rest.
 *
 * The reference's own pad forces the bits a standard pad has no button for
 * (the C and D buttons and the second D-pad) to "released":
 * maple_sega_controller::getButtonState returns `kcode | 0xF901`.  This
 * module applies the same mask, so the guest sees what the reference showed.
 *
 * The keyboard is a fallback for the machines with no gamepad: the arrows are
 * the D-pad, Z/X/C/A are the A, B, X and Y buttons and Enter is Start.
 */
#include "host/sdl3_input.h"

#include <SDL3/SDL.h>

#include <stdio.h>
#include <string.h>

/* The pad the guest's Maple model answers with.  The axes start centred
 * (0x80), the buttons released (0xFFFF) and the triggers at 0, the way an
 * untouched pad reads (flycast's getAnalogAxis returns the raw trigger value,
 * which is 0 at rest). */
static vf3_maple_pad g_pad = { 0xFFFFu, 0u, 0u, 0x80u, 0x80u, 0x80u, 0x80u };

static SDL_Gamepad *g_gamepad;
static SDL_JoystickID g_gamepad_id;   /* the instance the gamepad has */

/* The keyboard's state: the bits of the buttons the keys hold down.  They are
 * in the wire's numbering (a set bit means "pressed"), so the same mask
 * serves the gamepad and the keyboard. */
static uint16_t g_key_buttons;

/* The gamepad's buttons, in the wire's numbering (a set bit means pressed). */
static uint16_t g_gamepad_buttons;

const vf3_maple_pad *vf3_sdl3_input_pad(void) { return &g_pad; }

/* The keyboard's key map: the wire's bit and the SDL keycode. */
static const struct { SDL_Keycode key; uint16_t bit; } g_keymap[] = {
    { SDLK_UP,     VF3_DC_BTN_UP },
    { SDLK_DOWN,   VF3_DC_BTN_DOWN },
    { SDLK_LEFT,   VF3_DC_BTN_LEFT },
    { SDLK_RIGHT,  VF3_DC_BTN_RIGHT },
    { SDLK_Z,      VF3_DC_BTN_A },
    { SDLK_X,      VF3_DC_BTN_B },
    { SDLK_C,      VF3_DC_BTN_X },
    { SDLK_A,      VF3_DC_BTN_Y },
    { SDLK_RETURN, VF3_DC_BTN_START },
};

static void open_first_gamepad(void)
{
    if (g_gamepad) return;
    int count = 0;
    SDL_JoystickID *ids = SDL_GetGamepads(&count);
    if (!ids) return;
    for (int i = 0; i < count; ++i) {
        SDL_Gamepad *pad = SDL_OpenGamepad(ids[i]);
        if (pad) {
            g_gamepad = pad;
            g_gamepad_id = ids[i];
            fprintf(stderr, "vf3sdl: gamepad %s\n", SDL_GetGamepadName(pad));
            break;
        }
    }
    SDL_free(ids);
}

int vf3_sdl3_input_open(void)
{
    open_first_gamepad();
    return 0;
}

void vf3_sdl3_input_close(void)
{
    if (g_gamepad) { SDL_CloseGamepad(g_gamepad); g_gamepad = NULL; }
}

/* The gamepad's button bit, or 0 for a button the Dreamcast pad has no
 * counterpart for.  The Dreamcast's face buttons are A, B, X and Y; SDL's
 * face buttons are south, east, west and north, and the standard mapping
 * puts A on the south, B on the east, X on the west and Y on the north. */
static uint16_t gamepad_button_bit(SDL_GamepadButton b)
{
    switch (b) {
    case SDL_GAMEPAD_BUTTON_SOUTH:      return VF3_DC_BTN_A;
    case SDL_GAMEPAD_BUTTON_EAST:       return VF3_DC_BTN_B;
    case SDL_GAMEPAD_BUTTON_WEST:       return VF3_DC_BTN_X;
    case SDL_GAMEPAD_BUTTON_NORTH:      return VF3_DC_BTN_Y;
    case SDL_GAMEPAD_BUTTON_START:      return VF3_DC_BTN_START;
    case SDL_GAMEPAD_BUTTON_DPAD_UP:    return VF3_DC_BTN_UP;
    case SDL_GAMEPAD_BUTTON_DPAD_DOWN:  return VF3_DC_BTN_DOWN;
    case SDL_GAMEPAD_BUTTON_DPAD_LEFT:  return VF3_DC_BTN_LEFT;
    case SDL_GAMEPAD_BUTTON_DPAD_RIGHT: return VF3_DC_BTN_RIGHT;
    default: return 0;
    }
}

/* An axis value (-32768..32767) as the Dreamcast's byte (0x80 is the
 * centre). */
static uint8_t axis_byte(Sint16 v)
{
    int x = 128 + (v >> 8);
    if (x < 0) x = 0;
    if (x > 255) x = 255;
    return (uint8_t)x;
}

/* A trigger's value (0..32767) as the Dreamcast's byte: the reference's pad
 * reports the trigger as 0 at rest (flycast's getAnalogAxis returns the raw
 * trigger value), so the byte is the value scaled to 0..255. */
static uint8_t trigger_byte(Sint16 v)
{
    if (v <= 0) return 0;
    int x = (v * 255) / 32767;
    if (x > 255) x = 255;
    return (uint8_t)x;
}

void vf3_sdl3_input_poll(void)
{
    uint16_t pressed = g_key_buttons;

    /* the gamepad: the buttons and the axes */
    if (g_gamepad) {
        uint16_t bits = 0;
        for (int i = 0; i < SDL_GAMEPAD_BUTTON_COUNT; ++i) {
            if (!SDL_GetGamepadButton(g_gamepad, (SDL_GamepadButton)i)) continue;
            const uint16_t bit = gamepad_button_bit((SDL_GamepadButton)i);
            if (bit) bits |= bit;
        }
        g_gamepad_buttons = bits;
        pressed |= bits;

        g_pad.joyx = axis_byte(SDL_GetGamepadAxis(g_gamepad, SDL_GAMEPAD_AXIS_LEFTX));
        g_pad.joyy = axis_byte(SDL_GetGamepadAxis(g_gamepad, SDL_GAMEPAD_AXIS_LEFTY));
        /* The reference's standard pad reports no second D-pad: its two axes
         * read 0x80 whatever the host does (flycast's getAnalogAxis returns
         * 0x80 for the axes it does not have). */
        g_pad.joy2x = 0x80u;
        g_pad.joy2y = 0x80u;
        g_pad.ltrig = trigger_byte(SDL_GetGamepadAxis(g_gamepad, SDL_GAMEPAD_AXIS_LEFT_TRIGGER));
        g_pad.rtrig = trigger_byte(SDL_GetGamepadAxis(g_gamepad, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER));
    }

    /* The wire's word: the buttons are active low, and the bits the standard
     * pad has no button for (the C and D buttons and the second D-pad) always
     * read as released - the reference's own mask, 0xF901 (flycast's
     * maple_sega_controller::getButtonState returns `kcode | 0xF901`). */
    g_pad.buttons = vf3_dc_wire_buttons(pressed);
}

/* The keyboard's events: the host's event loop calls this for every event. */
void vf3_sdl3_input_event(const SDL_Event *ev)
{
    if (ev->type == SDL_EVENT_KEY_DOWN || ev->type == SDL_EVENT_KEY_UP) {
        const int down = ev->type == SDL_EVENT_KEY_DOWN;
        for (size_t i = 0; i < sizeof g_keymap / sizeof *g_keymap; ++i) {
            if (ev->key.key != g_keymap[i].key) continue;
            if (down) g_key_buttons |= g_keymap[i].bit;
            else g_key_buttons &= (uint16_t)~g_keymap[i].bit;
            return;
        }
    } else if (ev->type == SDL_EVENT_GAMEPAD_ADDED) {
        if (!g_gamepad) open_first_gamepad();
    } else if (ev->type == SDL_EVENT_GAMEPAD_REMOVED) {
        if (g_gamepad && ev->gdevice.which == g_gamepad_id) {
            SDL_CloseGamepad(g_gamepad);
            g_gamepad = NULL;
            g_gamepad_buttons = 0;
            g_pad.joyx = g_pad.joyy = g_pad.joy2x = g_pad.joy2y = 0x80u;
            g_pad.ltrig = g_pad.rtrig = 0x80u;
        }
    }
}
