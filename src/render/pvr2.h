/* render/pvr2.h - the PVR2 model: the Tile Accelerator's command stream in,
 * the framebuffer out.
 *
 * The game streams its display commands into the TA FIFO (the 32-byte bursts
 * the native tick collects as `ta` words).  The model decodes that stream and
 * rasterises it into a framebuffer the host can present.
 *
 * The decoder is not written yet.  The command layout comes from the KAMUI
 * headers of the Katana SDK (the SDK the game itself was built against), and
 * the set of commands the game actually emits is measured from the captured
 * stream - see docs/re/plan_sdl3_port.md, phase P3.  Until then the model
 * counts the stream and clears the framebuffer, so the host plumbing and the
 * measurement are in place and nothing pretends to be a frame.
 */
#ifndef VF3_RENDER_PVR2_H
#define VF3_RENDER_PVR2_H

#include <stdint.h>

/* The Dreamcast's framebuffer mode the game uses: 640x480, ARGB8888 here
 * (the hardware's RGB565 is converted on the way out). */
#define VF3_PVR2_WIDTH   640
#define VF3_PVR2_HEIGHT  480
#define VF3_PVR2_PIXELS  (VF3_PVR2_WIDTH * VF3_PVR2_HEIGHT)

typedef struct {
    uint32_t words;          /* TA words seen since the last frame */
    uint32_t classes[8];     /* words per top-3-bit class (the TA command type) */
    uint32_t pixels;         /* pixels the last frame wrote */
} vf3_pvr2_stats;

typedef struct {
    uint32_t *fb;            /* ARGB8888, VF3_PVR2_PIXELS entries (malloc'd) */
    vf3_pvr2_stats stats;
} vf3_pvr2;

/* Allocate the framebuffer and clear the statistics. */
void vf3_pvr2_init(vf3_pvr2 *p);
void vf3_pvr2_free(vf3_pvr2 *p);
/* One TA FIFO word: the game writes the FIFO in 32-byte bursts. */
void vf3_pvr2_ta_push(vf3_pvr2 *p, uint32_t word);
/* Begin a frame: the FIFO's words are the frame's commands. */
void vf3_pvr2_frame_begin(vf3_pvr2 *p);
/* End a frame: rasterise what the FIFO carried.  Returns the pixels written
 * (0 until the rasteriser exists). */
unsigned vf3_pvr2_frame_end(vf3_pvr2 *p);
/* The framebuffer, ARGB8888, VF3_PVR2_PIXELS entries. */
const uint32_t *vf3_pvr2_framebuffer(const vf3_pvr2 *p);

#endif
