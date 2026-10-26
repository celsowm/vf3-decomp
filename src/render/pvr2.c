/* render/pvr2.c - the PVR2 model.
 *
 * Phase P0 of docs/re/plan_sdl3_port.md: the model owns the framebuffer and
 * collects the Tile Accelerator command stream.  The decoder and the rasteriser
 * come in P3, once the SDK headers give the command layout and the captured
 * stream says which commands the game emits.
 *
 * Nothing here guesses: the histogram is over the raw top three bits of each
 * word, which is the TA command type field of the PVR2 command word, and the
 * framebuffer is cleared rather than filled with something that looks like a
 * frame.
 */
#include "render/pvr2.h"

#include <stdlib.h>
#include <string.h>

void vf3_pvr2_init(vf3_pvr2 *p)
{
    memset(p, 0, sizeof *p);
    p->fb = malloc((size_t)VF3_PVR2_PIXELS * sizeof *p->fb);
    if (p->fb) {
        /* opaque black */
        memset(p->fb, 0, (size_t)VF3_PVR2_PIXELS * sizeof *p->fb);
    }
}

void vf3_pvr2_free(vf3_pvr2 *p)
{
    free(p->fb);
    free(p->ta);
    p->fb = NULL;
    p->ta = NULL;
    p->ta_cap = p->ta_words = 0;
}

void vf3_pvr2_ta_push(vf3_pvr2 *p, uint32_t word)
{
    ++p->stats.words;
    ++p->stats.classes[(word >> 29) & 7u];
    /* the stream itself: the decoder needs the words in order, and the
     * capture tool needs them out of the host */
    if (p->ta_words == p->ta_cap) {
        p->ta_cap = p->ta_cap ? 2 * p->ta_cap : 4096;
        uint32_t *ta = realloc(p->ta, (size_t)p->ta_cap * sizeof *ta);
        if (!ta) { p->ta_cap = p->ta_words = 0; return; }
        p->ta = ta;
    }
    p->ta[p->ta_words++] = word;
}

void vf3_pvr2_frame_begin(vf3_pvr2 *p)
{
    p->stats.words = 0;
    memset(p->stats.classes, 0, sizeof p->stats.classes);
    p->stats.pixels = 0;
    p->ta_words = 0;
}

unsigned vf3_pvr2_frame_end(vf3_pvr2 *p)
{
    if (!p->fb) return 0;
    /* No rasteriser yet: the frame stays black.  P3 fills it from the
     * command stream this model has been counting. */
    memset(p->fb, 0, (size_t)VF3_PVR2_PIXELS * sizeof *p->fb);
    p->stats.pixels = 0;
    return 0;
}

const uint32_t *vf3_pvr2_framebuffer(const vf3_pvr2 *p)
{
    return p->fb;
}
