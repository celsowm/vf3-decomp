/* Native TA/VRAM reference path. See docs/re/native_pvr.md for its deliberately
 * explicit supported subset. No SDL or emulator dependency. */
#ifndef VF3_PVR_TA_H
#define VF3_PVR_TA_H

#include <stddef.h>
#include <stdint.h>

#define VF3_PVR_WIDTH 640
#define VF3_PVR_HEIGHT 480
#define VF3_PVR_VRAM_SIZE 0x00800000u

typedef struct vf3_pvr vf3_pvr;
typedef enum {
    VF3_PVR_OK = 0, VF3_PVR_BAD_ACCESS, VF3_PVR_BAD_STREAM,
    VF3_PVR_UNSUPPORTED, VF3_PVR_BAD_VERTEX, VF3_PVR_LIMIT, VF3_PVR_NO_MEMORY
} vf3_pvr_error_code;
typedef struct {
    vf3_pvr_error_code code;
    uint32_t address, pcw;
    uint64_t packet;
    const char *message; /* static string; remains valid after reset */
} vf3_pvr_error;
typedef struct {
    uint64_t bytes, packets, headers, vertices, strips, lists, frames;
    size_t triangles;
    uint32_t ended_lists; /* bits of list IDs 0..4 */
    unsigned pending_bytes;
} vf3_pvr_stats;
typedef struct {
    float x, y, inv_z, u, v;
    float base[4], offset[4]; /* A,R,G,B, clamped/quantized TA colors in 0..1 */
    uint32_t control;        /* exact original vertex control word */
} vf3_pvr_vertex;
typedef struct {
    uint32_t pcw, isp, tsp, tcw;
    float face[4], face_offset[4];
    uint32_t raw[16];        /* exact header words, including reserved fields */
    unsigned words;
} vf3_pvr_material;
typedef struct {
    vf3_pvr_material material;
    vf3_pvr_vertex v[3];
} vf3_pvr_triangle;

vf3_pvr *vf3_pvr_create(void);
void vf3_pvr_destroy(vf3_pvr *pvr);
/* reset also clears VRAM/registers. begin_frame clears only TA scene/error,
 * retaining VRAM/registers and the last successfully presented framebuffer. */
void vf3_pvr_reset(vf3_pvr *pvr);
void vf3_pvr_begin_frame(vf3_pvr *pvr);

/* Bus operations: 1 handled, 0 address outside this device, -1 failure.
 * Scalar size is 1,2,4; registers/FIFO require 4. Block bytes are little-endian
 * guest bytes; FIFO blocks may split a packet at any byte boundary. FIFO
 * addresses select a port, not storage offsets; VRAM block addresses advance.
 * Errors are sticky until reset/begin_frame. Device instances share no state. */
int vf3_pvr_read(vf3_pvr *, uint32_t address, unsigned size, uint32_t *value);
int vf3_pvr_write(vf3_pvr *, uint32_t address, unsigned size, uint32_t value);
int vf3_pvr_write_block(vf3_pvr *, uint32_t address, const uint8_t *, size_t);

/* 1 success, -1 error. STARTRENDER (0x005f8014) also calls this. Render validates
 * every material before changing the visible framebuffer. The initial clear
 * is opaque black/depth zero; background-plane rendering is not implemented. */
int vf3_pvr_render(vf3_pvr *);
const uint32_t *vf3_pvr_framebuffer(const vf3_pvr *); /* 0xAARRGGBB */
const vf3_pvr_error *vf3_pvr_last_error(const vf3_pvr *);
vf3_pvr_stats vf3_pvr_get_stats(const vf3_pvr *);
/* Diagnostic decoded geometry. Pointer valid until another TA write/reset. */
const vf3_pvr_triangle *vf3_pvr_triangle_at(const vf3_pvr *, size_t index);
/* Decode one texture texel for fixtures/debugging; uses TSP dimensions and TCW.
 * Integer coordinates must be in range. Same unsupported-format checks as render. */
int vf3_pvr_texel(vf3_pvr *, uint32_t tsp, uint32_t tcw,
                  unsigned x, unsigned y, uint32_t *argb);

#endif
