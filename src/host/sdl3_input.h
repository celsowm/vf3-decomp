/* host/sdl3_input.h - the host's input: an SDL3 gamepad or the keyboard, read
 * into the Dreamcast pad the Maple model answers with.
 *
 * The guest never sees the host's device.  It asks the Maple model for the
 * pad's state and the model answers with the bytes the hardware would put on
 * the bus (src/sys/maple_hle.c).  This module is the layer that turns the
 * host's device into those bytes; the wire's format is in host/dc_wire.h.
 */
#ifndef VF3_HOST_SDL3_INPUT_H
#define VF3_HOST_SDL3_INPUT_H

#include <stdint.h>

#include <SDL3/SDL.h>

#include "host/dc_wire.h"
#include "sys/maple_hle.h"

/* Open the host's input devices.  Returns 0 on success. */
int vf3_sdl3_input_open(void);
/* Read the devices and publish the pad.  Called once a frame, before the
 * guest runs the frame's slice. */
void vf3_sdl3_input_poll(void);
/* The host's events: the keyboard's buttons and the gamepad's arrival. */
void vf3_sdl3_input_event(const SDL_Event *ev);
/* The pad the guest's Maple model will answer with. */
const vf3_maple_pad *vf3_sdl3_input_pad(void);
/* Close the devices. */
void vf3_sdl3_input_close(void);

#endif
