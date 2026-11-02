/* host/dc_wire.h - the Dreamcast pad's wire format, in one place.
 *
 * The guest never sees the host's device: it asks the Maple model for the
 * pad's state and the model answers with the bytes the hardware would put on
 * the bus (src/sys/maple_hle.c).  This header is the contract between the
 * host's input layer (src/host/sdl3_input.c) and that model.
 *
 * The wire format (docs/re/maple.md):
 *   - the buttons are active low: a *zero* bit means the button is pressed and
 *     0xFFFF means nothing is pressed;
 *   - the bit positions are the KOS numbering the reference emulator uses
 *     (flycast's core/input/gamepad.h: DC_BTN_C is bit 0, DC_BTN_X is bit 10);
 *   - the axes are a byte each with 0x80 at the centre; the triggers are 0 at
 *     rest (the reference's pad reports the raw trigger value) and the second
 *     D-pad's axes are always 0x80 (the reference's standard pad has none).
 *
 * The reference's own pad forces the bits a standard pad has no button for
 * (the C and D buttons and the second D-pad) to "released":
 * maple_sega_controller::getButtonState returns `kcode | 0xF901`.  The mask
 * keeps that behaviour, so the guest sees what the reference showed.
 */
#ifndef VF3_HOST_DC_WIRE_H
#define VF3_HOST_DC_WIRE_H

#include <stdint.h>

/* The button bits, in the wire's numbering (a bit that is *set* here means
 * the button is released; the host inverts them). */
#define VF3_DC_BTN_C     0x0001u
#define VF3_DC_BTN_B     0x0002u
#define VF3_DC_BTN_A     0x0004u
#define VF3_DC_BTN_START 0x0008u
#define VF3_DC_BTN_UP    0x0010u
#define VF3_DC_BTN_DOWN  0x0020u
#define VF3_DC_BTN_LEFT  0x0040u
#define VF3_DC_BTN_RIGHT 0x0080u
#define VF3_DC_BTN_Z     0x0100u
#define VF3_DC_BTN_Y     0x0200u
#define VF3_DC_BTN_X     0x0400u

/* The bits the reference's standard pad never reports: the C button, the D
 * button, the Z button and the second D-pad (0xF901 - flycast's
 * maple_sega_controller::getButtonState).  They always read as released. */
#define VF3_DC_BUTTON_MASK 0xF901u

/* The wire's word for the buttons the host holds down.
 *
 * The host's `pressed` mask uses the wire's bit positions and sets the bit of
 * a pressed button; the wire is active low, so the word is the complement.
 * The reference's mask is applied last, so the buttons a standard pad has no
 * button for read as released whatever the host asks.
 */
static inline uint16_t vf3_dc_wire_buttons(uint16_t pressed)
{
    return (uint16_t)((~pressed) | VF3_DC_BUTTON_MASK);
}

#endif
