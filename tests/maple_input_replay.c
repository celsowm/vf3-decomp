/* maple_input_replay.c - the host's pad must reach the guest in the wire's
 * format.
 *
 * The guest never sees the host's device: it asks the Maple model for the
 * pad's state and the model answers with the bytes the hardware would put on
 * the bus (src/sys/maple_hle.c).  The host's layer (src/host/sdl3_input.c)
 * turns the gamepad or the keyboard into that word.
 *
 * The test drives the Maple model the way the guest does - a GET_CONDITION
 * request in a transfer list - and requires:
 *   1. the reply's button word to be the wire's active-low word: a zero bit
 *      means the button is pressed and 0xFFFF means nothing is pressed;
 *   2. the bit positions to be the KOS numbering the reference uses (C=0,
 *      B=1, A=2, START=3, UP=4, DOWN=5, LEFT=6, RIGHT=7, Y=9, X=10);
 *   3. the bits a standard pad has no button for (the C and D buttons and the
 *      second D-pad) to read as released whatever the host asks - the
 *      reference's own mask, 0xF901;
 *   4. the analog axes to travel in the same reply, centred at 0x80.
 *
 *   vf3mapleinput
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "host/dc_wire.h"
#include "sys/maple_hle.h"

static int failures;
#define CHECK(c, ...) do { if (!(c)) { ++failures; printf("FAIL %s:%d: ", __FILE__, __LINE__); printf(__VA_ARGS__); printf("\n"); } } while (0)

#define RAM_BASE 0x0C000000u
#define RAM_LEN  0x00100000u

/* The transfer list: one block, the GET_CONDITION request, with the answer
 * written at RECV.  The list's layout is the one src/sys/maple_hle.c walks:
 * the header, the receive address, then the frame (the command, the sender,
 * the recipient and the length) and the payload. */
#define LIST_ADDR 0x0C0F0000u
#define RECV      0x0C0F1000u

static uint8_t g_ram[RAM_LEN];

/* The Maple wire's numbers (the KOS numbering the reference uses). */
#define BTN_C     0x0001u
#define BTN_B     0x0002u
#define BTN_A     0x0004u
#define BTN_START 0x0008u
#define BTN_UP    0x0010u
#define BTN_DOWN  0x0020u
#define BTN_LEFT  0x0040u
#define BTN_RIGHT 0x0080u
#define BTN_Y     0x0200u
#define BTN_X     0x0400u

/* The reference's mask: the bits a standard pad has no button for always read
 * as released (flycast's maple_sega_controller::getButtonState returns
 * `kcode | 0xF901`).  The C button, the D button, the Z button and the
 * second D-pad are among them. */
#define PAD_MASK  VF3_DC_BUTTON_MASK

static void put32(uint32_t addr, uint32_t v)
{
    memcpy(g_ram + (addr - RAM_BASE), &v, 4);
}

/* Build the transfer list and run the Maple model over it.
 *
 * The list's shape is the one src/sys/maple_hle.c walks: the header (bit 31
 * marks the last block, bits 17:16 the port and bits 7:0 the frame's word
 * count minus one), the receive address, then the frame (the command, the
 * recipient, the sender and the length).
 *
 * The recipient selects the device the way the reference does: the main unit
 * of the bus is at 0x20, and the expansion slots (the memory cards) at 0x01
 * and 0x02.  The pad is on the main unit, so the request goes to 0x20.
 */
static unsigned run_maple(const vf3_maple_pad *pad, uint16_t *buttons_out, uint8_t *axes_out)
{
    memset(g_ram, 0, sizeof g_ram);
    /* the list header: the last block, port 0, one frame word */
    put32(LIST_ADDR + 0u, 0x80000000u);
    put32(LIST_ADDR + 4u, RECV);
    /* the frame: GET_CONDITION (9), to the main unit (0x20), from the guest */
    put32(LIST_ADDR + 8u, 0x09u | (0x20u << 8));
    const unsigned n = vf3_maple_dma(g_ram, RAM_BASE, RAM_LEN, LIST_ADDR, pad);
    if (buttons_out) {
        uint16_t b;
        memcpy(&b, g_ram + (RECV + 8u - RAM_BASE), 2);
        *buttons_out = b;
    }
    if (axes_out) memcpy(axes_out, g_ram + (RECV + 12u - RAM_BASE), 4);
    return n;
}

int main(void)
{
    /* 1. nothing pressed: the word is 0xFFFF (every bit released) */
    {
        vf3_maple_pad pad = { 0xFFFFu, 0u, 0u, 0x80u, 0x80u, 0x80u, 0x80u };
        uint16_t buttons = 0;
        run_maple(&pad, &buttons, NULL);
        CHECK(buttons == 0xFFFFu, "nothing pressed: got %04x, want ffff", buttons);
    }

    /* 2. one button at a time: the pressed bit is the only zero one.
     *
     * The C button is not in the list: the reference's standard pad has no C
     * button, so the mask keeps it released (case 3 covers it). */
    {
        static const struct { uint16_t bit; const char *name; } cases[] = {
            { BTN_B, "B" }, { BTN_A, "A" }, { BTN_START, "START" },
            { BTN_UP, "UP" }, { BTN_DOWN, "DOWN" }, { BTN_LEFT, "LEFT" },
            { BTN_RIGHT, "RIGHT" }, { BTN_Y, "Y" }, { BTN_X, "X" },
        };
        for (size_t i = 0; i < sizeof cases / sizeof *cases; ++i) {
            /* the host's word: the buttons it holds down, inverted for the
             * wire (a zero bit is a pressed button) */
            const uint16_t wire = vf3_dc_wire_buttons(cases[i].bit);
            vf3_maple_pad pad = { wire, 0u, 0u, 0x80u, 0x80u, 0x80u, 0x80u };
            uint16_t buttons = 0;
            run_maple(&pad, &buttons, NULL);
            CHECK(buttons == wire, "%s pressed: got %04x, want %04x",
                  cases[i].name, buttons, wire);
            CHECK((buttons & cases[i].bit) == 0u, "%s: its bit is not zero", cases[i].name);
        }
    }

    /* 3. the buttons a standard pad has no button for always read released */
    {
        /* the host asks for the C button (bit 0), the D button (bit 11) and
         * the Z button (bit 8): the reference's mask keeps them released */
        const uint16_t wire = vf3_dc_wire_buttons((uint16_t)(BTN_C | 0x0800u | 0x0100u));
        vf3_maple_pad pad = { wire, 0u, 0u, 0x80u, 0x80u, 0x80u, 0x80u };
        uint16_t buttons = 0;
        run_maple(&pad, &buttons, NULL);
        CHECK((buttons & BTN_C) != 0u, "the C button reads released");
        CHECK((buttons & 0x0800u) != 0u, "the D button reads released");
        CHECK((buttons & 0x0100u) != 0u, "the Z button reads released");
        CHECK((buttons & 0xF000u) == 0xF000u, "the second D-pad reads released");
    }

    /* 4. two buttons at once: both are zero */
    {
        const uint16_t wire = vf3_dc_wire_buttons((uint16_t)(BTN_A | BTN_X));
        vf3_maple_pad pad = { wire, 0u, 0u, 0x80u, 0x80u, 0x80u, 0x80u };
        uint16_t buttons = 0;
        run_maple(&pad, &buttons, NULL);
        CHECK((buttons & (BTN_A | BTN_X)) == 0u, "A and X together: got %04x", buttons);
        CHECK(buttons == wire, "A and X together: got %04x, want %04x", buttons, wire);
    }

    /* 6. the triggers sit in the two bytes above the buttons, and the axes
     * follow them (the reference's answer: the buttons, then six axis bytes
     * - the right trigger, the left trigger, the X axis, the Y axis and two
     * the standard pad does not have). */
    {
        vf3_maple_pad pad = { 0xFFFFu, 0x20u, 0x40u, 0x11u, 0x22u, 0x33u, 0x44u };
        uint16_t buttons = 0;
        uint8_t axes[4];
        run_maple(&pad, &buttons, axes);
        CHECK(axes[0] == 0x11u, "joyx: got %02x, want 11", axes[0]);
        CHECK(axes[1] == 0x22u, "joyy: got %02x, want 22", axes[1]);
        CHECK(axes[2] == 0x33u, "joy2x: got %02x, want 33", axes[2]);
        CHECK(axes[3] == 0x44u, "joy2y: got %02x, want 44", axes[3]);
        /* the triggers are the two bytes between the buttons and the axes */
        const uint8_t *raw = g_ram + (RECV + 8u - RAM_BASE);
        CHECK(raw[2] == 0x20u, "rtrig: got %02x, want 20", raw[2]);
        CHECK(raw[3] == 0x40u, "ltrig: got %02x, want 40", raw[3]);
    }

    if (failures) {
        printf("maple_input_replay: %d failure(s)\n", failures);
        return 1;
    }
    printf("maple_input_replay: the pad reaches the guest in the wire's format\n");
    return 0;
}
