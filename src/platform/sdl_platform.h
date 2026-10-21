#ifndef VF3_SDL_PLATFORM_H
#define VF3_SDL_PLATFORM_H

#include <stdint.h>
#include "platform/input.h"

#define VF3_FRAME_WIDTH 640
#define VF3_FRAME_HEIGHT 480

typedef struct vf3_platform vf3_platform;
typedef struct {
    const char *title;
    int hidden;             /* for automated host checks */
    int vsync;             /* presentation only; never advances game state */
} vf3_platform_config;

/* Main-thread API. This platform consumes the SDL event queue. It has no game
 * loop, PVR renderer, audio mixer or emulation fallback. Each successful create
 * balances its SDL subsystem reference counts on destroy. */
vf3_platform *vf3_platform_create(const vf3_platform_config *config);
void vf3_platform_destroy(vf3_platform *platform);
const char *vf3_platform_error(void);
/* Returns 1 while running, 0 after quit/window close/Escape. Both pads are
 * updated on every call. Unfocused windows return neutral input. Keyboard
 * mapping: P1 arrows + Z(A), X(B), A(X), S(Y), Return(Start);
 * P2 I/K/J/L + V(A), B(B), F(X), G(Y), RShift(Start).
 * Gamepad face buttons map by position: south/east/west/north -> A/B/X/Y.
 * This supplies two pad states; the existing Maple bus still needs multiport
 * integration before the game can consume player 2. */
int vf3_platform_poll(vf3_platform *platform, vf3_maple_pad pads[VF3_HOST_PLAYERS]);
/* Exact 640x480 packed native uint32_t values 0xAARRGGBB; pitch is in bytes.
 * Content is letterboxed to 4:3 on resize, with nearest-neighbor sampling. */
int vf3_platform_present(vf3_platform *platform, const uint32_t *pixels, int pitch);
uint64_t vf3_platform_time_ns(void);
void vf3_platform_sleep_ns(uint64_t duration);

#endif
