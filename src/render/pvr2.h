/* render/pvr2.h - the PVR2 model: the Tile Accelerator's command stream in,
 * the framebuffer out.
 *
 * The game streams its display commands into the TA FIFO (the 32-byte blocks
 * the native tick collects).  The model decodes that stream and rasterises it
 * into a framebuffer the host can present.
 *
 * The PVR2 is a stateful device: its register file holds the frame buffer's
 * configuration (its size, its line stride, the clip rectangle) and its VRAM
 * holds the textures.  The game programs the registers once, at boot, before
 * the port's entry point, so the port is told the state rather than seeing
 * it written (docs/re/p3_ta_decoder.md).
 */
#ifndef VF3_RENDER_PVR2_H
#define VF3_RENDER_PVR2_H

#include <stdint.h>

#include "render/ta.h"

/* The Dreamcast's framebuffer mode the game uses: 640x480, and the frame
 * buffer's write control says "565 RGB 16 bit", so the framebuffer holds
 * RGB565 (the host converts it for the screen). */
#define VF3_PVR2_WIDTH   640
#define VF3_PVR2_HEIGHT  480
#define VF3_PVR2_PIXELS  (VF3_PVR2_WIDTH * VF3_PVR2_HEIGHT)

/* The PVR2's own memory: 8 MB of VRAM and a 32 KB register file. */
#define VF3_PVR2_VRAM_SIZE 0x00800000u
#define VF3_PVR2_REG_SIZE  0x00008000u

typedef struct {
    uint32_t words;          /* TA words seen since the last frame */
    uint32_t classes[8];     /* words per top-3-bit class (the TA command type) */
    uint32_t pixels;         /* pixels the last frame wrote */
    uint32_t triangles;      /* the triangles the last frame drew */
    uint32_t textured;       /* the primitives that were textured */
} vf3_pvr2_stats;

typedef struct {
    uint16_t *fb;          /* RGB565, VF3_PVR2_PIXELS entries (malloc'd) */
    float *depth;          /* the depth buffer, one float a pixel (1/w) */
    uint8_t *vram;           /* the PVR2's VRAM (malloc'd) */
    uint32_t *regs;          /* the PVR2's register file (malloc'd) */
    uint32_t reg_bytes;      /* how many of them the state dump carried */
    uint32_t vram_bytes;     /* how much VRAM it carried */

    /* The frame buffer's configuration, read out of the register file. */
    uint32_t fb_width;       /* the display's width in pixels */
    uint32_t fb_height;      /* the display's height in pixels */
    uint32_t fb_stride;      /* the bytes a line */
    uint32_t fb_base;        /* the frame buffer's address in the VRAM */
    uint32_t pack_mode;      /* 0: 16 bit, 1: 32 bit */
    uint32_t clip_x0, clip_x1, clip_y0, clip_y1;
    uint32_t alpha_ref;      /* the punch-through list's alpha reference */
    uint32_t ta_ol_base;     /* the object list's address in the VRAM */
    uint32_t ta_isp_base;    /* the ISP parameters' address in the VRAM */

    uint32_t *ta;            /* the TA words of the frame, in order (malloc'd) */
    uint32_t ta_words;       /* how many of them there are */
    uint32_t ta_cap;
    vf3_pvr2_stats stats;
} vf3_pvr2;

/* Allocate the framebuffer and clear the statistics. */
void vf3_pvr2_init(vf3_pvr2 *p);
void vf3_pvr2_free(vf3_pvr2 *p);
/* Load the PVR2's state (the register file and the VRAM) from a file the
 * reference emulator's instrument wrote.  Returns 0 on success. */
int vf3_pvr2_load_state(vf3_pvr2 *p, const char *path);
/* Read the frame buffer's configuration out of the register file. */
void vf3_pvr2_read_config(vf3_pvr2 *p);
/* One TA FIFO word: the game writes the FIFO in 32-byte bursts. */
void vf3_pvr2_ta_push(vf3_pvr2 *p, uint32_t word);
/* Begin a frame: the FIFO's words are the frame's commands. */
void vf3_pvr2_frame_begin(vf3_pvr2 *p);
/* End a frame: rasterise what the FIFO carried.  Returns the pixels written. */
unsigned vf3_pvr2_frame_end(vf3_pvr2 *p);
/* Rasterise a decoded list into the framebuffer.  Returns the pixels written. */
unsigned vf3_pvr2_rasterise(vf3_pvr2 *p, const vf3_ta_list *list);
/* The framebuffer, RGB565, VF3_PVR2_PIXELS entries. */
const uint16_t *vf3_pvr2_framebuffer(const vf3_pvr2 *p);
/* One pixel as the host wants it: 0xAARRGGBB. */
uint32_t vf3_pvr2_pixel(const vf3_pvr2 *p, unsigned x, unsigned y);
/* Write a word into the VRAM the way the hardware's bus does (the 64-bit
 * bus interleaves the two banks every 32 bits). */
void vf3_pvr2_vram_write(vf3_pvr2 *p, uint32_t addr, uint32_t value);
/* What the guest's writes do to the model: the physical address the writer
 * used (0x10800000+: the 64 bit view of the VRAM, 0x04000000+: the 32 bit
 * view) and a PVR2 register (offset from 0x005F8000). */
void vf3_pvr2_vram_store(vf3_pvr2 *p, uint32_t dest, uint32_t value);
void vf3_pvr2_reg_store(vf3_pvr2 *p, uint32_t off, uint32_t value);

#endif
