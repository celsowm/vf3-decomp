/* tests/sdl3_input_replay.c - the host's keyboard reaches the guest in the
 * wire's format.
 *
 * The wire format itself has its own test (tests/maple_input_replay.c): that
 * one drives the Maple model and checks the bytes the guest would read.  This
 * one covers the layer *above* it: the SDL3 keyboard, the key map and the
 * publication into the pad the host hands the Maple model.
 *
 * The keyboard is the fallback for the machines with no gamepad, and it is the
 * only input device that can be exercised without a human at the pad: the test
 * feeds the input layer synthetic SDL events.
 *
 *   build/vf3sdlinput
 */
#include <stdio.h>
#include <string.h>

#include <SDL3/SDL.h>

#include "host/dc_wire.h"
#include "host/sdl3_input.h"

static int failures;

static void expect(const char *what, uint16_t got, uint16_t want)
{
    if (got == want) return;
    fprintf(stderr, "sdl3_input_replay: FAIL - %s: the wire says %04x, want %04x\n",
            what, got, want);
    ++failures;
}

/* The word the pad would answer with, after the input layer published it. */
static uint16_t wire_now(void)
{
    vf3_sdl3_input_poll();
    return vf3_sdl3_input_pad()->buttons;
}

static void key(SDL_Keycode code, int down)
{
    SDL_Event ev;
    memset(&ev, 0, sizeof ev);
    ev.type = down ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP;
    ev.key.key = code;
    vf3_sdl3_input_event(&ev);
}

/* The word the wire carries when only the button of `bit` is held down. */
static uint16_t only(uint16_t bit)
{
    return (uint16_t)((~bit) | VF3_DC_BUTTON_MASK);
}

int main(void)
{
    if (!SDL_Init(SDL_INIT_EVENTS)) {
        fprintf(stderr, "sdl3_input_replay: SDL_Init failed: %s\n", SDL_GetError());
        return 2;
    }

    /* nothing held down */
    expect("nothing pressed", wire_now(), 0xFFFFu);

    /* the arrows are the D-pad */
    key(SDLK_UP, 1);    expect("the up arrow", wire_now(), only(VF3_DC_BTN_UP));
    key(SDLK_UP, 0);
    key(SDLK_DOWN, 1);  expect("the down arrow", wire_now(), only(VF3_DC_BTN_DOWN));
    key(SDLK_DOWN, 0);
    key(SDLK_LEFT, 1);  expect("the left arrow", wire_now(), only(VF3_DC_BTN_LEFT));
    key(SDLK_LEFT, 0);
    key(SDLK_RIGHT, 1); expect("the right arrow", wire_now(), only(VF3_DC_BTN_RIGHT));
    key(SDLK_RIGHT, 0);
    expect("the arrows released", wire_now(), 0xFFFFu);

    /* Z, X, C and A are the A, B, X and Y buttons; Enter is Start */
    key(SDLK_Z, 1);     expect("the Z key", wire_now(), only(VF3_DC_BTN_A));
    key(SDLK_Z, 0);
    key(SDLK_X, 1);     expect("the X key", wire_now(), only(VF3_DC_BTN_B));
    key(SDLK_X, 0);
    key(SDLK_C, 1);     expect("the C key", wire_now(), only(VF3_DC_BTN_X));
    key(SDLK_C, 0);
    key(SDLK_A, 1);     expect("the A key", wire_now(), only(VF3_DC_BTN_Y));
    key(SDLK_A, 0);
    key(SDLK_RETURN, 1); expect("the Enter key", wire_now(), only(VF3_DC_BTN_START));
    key(SDLK_RETURN, 0);
    expect("the keys released", wire_now(), 0xFFFFu);

    /* two keys at once */
    key(SDLK_Z, 1);
    key(SDLK_RETURN, 1);
    expect("Z and Enter", wire_now(),
           (uint16_t)((~(VF3_DC_BTN_A | VF3_DC_BTN_START)) | VF3_DC_BUTTON_MASK));
    key(SDLK_Z, 0);
    key(SDLK_RETURN, 0);

    /* a key the map does not know changes nothing */
    key(SDLK_F7, 1);
    expect("an unmapped key", wire_now(), 0xFFFFu);
    key(SDLK_F7, 0);

    /* the axes read as the reference's untouched pad: centred, no trigger */
    {
        const vf3_maple_pad *pad = vf3_sdl3_input_pad();
        expect("the X axis", pad->joyx, 0x80u);
        expect("the Y axis", pad->joyy, 0x80u);
        expect("the second D-pad's X", pad->joy2x, 0x80u);
        expect("the second D-pad's Y", pad->joy2y, 0x80u);
        expect("the left trigger", pad->ltrig, 0u);
        expect("the right trigger", pad->rtrig, 0u);
    }

    SDL_Quit();
    if (failures) {
        fprintf(stderr, "sdl3_input_replay: %d check(s) failed\n", failures);
        return 1;
    }
    printf("sdl3_input_replay: the keyboard reaches the guest in the wire's format\n");
    return 0;
}
