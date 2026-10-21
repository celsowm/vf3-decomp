/* Standalone reference tests; define VF3_PVR_TEST_EMITTERS and link vf3core
 * to include the real VF3 header/vertex -> store queue -> TA integration. */
#include "render/pvr_ta.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef VF3_PVR_TEST_EMITTERS
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/native_tick.h"
#include "render/pvr_native.h"
int vf3_poly_header_sq_entry(vf3_matrix_state *, const vf3_ram_map *);
int vf3_vertex_emit_sq_entry(vf3_matrix_state *, const vf3_ram_map *);
#endif

static unsigned failures, checks;
#define CHECK(c) do { ++checks; if (!(c)) { fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #c); ++failures; } } while (0)
#define FIFO 0x10000000u
#define NO_FOG 0x20800000u
static uint32_t bits(float f) { uint32_t w; memcpy(&w, &f, 4); return w; }
static void put(uint8_t *b, uint32_t w)
{ b[0] = (uint8_t)w; b[1] = (uint8_t)(w >> 8); b[2] = (uint8_t)(w >> 16); b[3] = (uint8_t)(w >> 24); }
static void header(uint8_t *b, uint32_t pcw, uint32_t isp, uint32_t tsp, uint32_t tcw)
{
    unsigned i; memset(b, 0, 64);
    put(b, pcw); put(b + 4, isp); put(b + 8, tsp); put(b + 12, tcw);
    if (((pcw >> 4) & 3) == 2) {
        unsigned at = pcw & 4 ? 32 : 16;
        for (i = 0; i < 4; ++i) put(b + at + 4 * i, bits(1));
    }
}
static void vertex(uint8_t *b, float x, float y, float z, uint32_t color, int end)
{
    memset(b, 0, 32); put(b, end ? 0xffffffffu : 0xe1030060u);
    put(b + 4, bits(x)); put(b + 8, bits(y)); put(b + 12, bits(z)); put(b + 24, color);
}
static int words(vf3_pvr *p, const uint8_t *b, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i += 4) {
        uint32_t w = (uint32_t)b[i] | (uint32_t)b[i + 1] << 8 | (uint32_t)b[i + 2] << 16 | (uint32_t)b[i + 3] << 24;
        if (vf3_pvr_write(p, FIFO + i, 4, w) != 1) return 0;
    }
    return 1;
}
static void finish(vf3_pvr *p) { uint8_t zero[32] = {0}; CHECK(vf3_pvr_write_block(p, FIFO, zero, sizeof zero) == 1); }
static void tri(vf3_pvr *p, float z, uint32_t color)
{
    uint8_t b[32];
    vertex(b, 8, 8, z, color, 0); CHECK(words(p, b, 32));
    vertex(b, 40, 8, z, color, 0); CHECK(words(p, b, 32));
    vertex(b, 8, 40, z, color, 1); CHECK(words(p, b, 32));
}
static uint32_t pixel(vf3_pvr *p, unsigned x, unsigned y)
{ return vf3_pvr_framebuffer(p)[y * VF3_PVR_WIDTH + x]; }

static void bus_test(vf3_pvr *p)
{
    uint32_t v = 0; uint8_t data[8] = {0,1,2,3,4,5,6,7};
    vf3_pvr_reset(p);
    CHECK(vf3_pvr_write_block(p, 0xa4000000u, data, sizeof data) == 1);
    CHECK(vf3_pvr_read(p, 0x06000000u, 4, &v) == 1 && v == 0x03020100u);
    CHECK(vf3_pvr_read(p, 0x05000000u, 4, &v) == 1 && v == 0x03020100u);
    CHECK(vf3_pvr_read(p, 0x05400000u, 4, &v) == 1 && v == 0x07060504u);
    CHECK(vf3_pvr_write(p, 0xa5000004u, 4, 0x12345678u) == 1);
    CHECK(vf3_pvr_read(p, 0x04000008u, 4, &v) == 1 && v == 0x12345678u);
    CHECK(vf3_pvr_write(p, 0x005f6888u, 4, 1) == 1);
    CHECK(vf3_pvr_write(p, 0x13400004u, 4, 0xabcd5678u) == 1);
    CHECK(vf3_pvr_read(p, 0x0400000cu, 4, &v) == 1 && v == 0xabcd5678u);
    CHECK(vf3_pvr_write(p, 0x110303c1u, 1, 0xab) == 1);
    CHECK(vf3_pvr_write(p, 0x110303c2u, 2, 0xcdef) == 1);
    CHECK(vf3_pvr_read(p, 0x040303c0u, 4, &v) == 1 && v == 0xcdefab00u);
    vf3_pvr_begin_frame(p);
    CHECK(vf3_pvr_read(p, 0x040303c0u, 4, &v) == 1 && v == 0xcdefab00u);
    CHECK(vf3_pvr_read(p, 0x005f810cu, 4, &v) == 0); /* clock-owned */
    CHECK(vf3_pvr_read(p, 0x005f8134u, 4, &v) == 0); /* no invented status */
    CHECK(vf3_pvr_write(p, 0x005f811cu, 4, 128) == 1);
    CHECK(vf3_pvr_read(p, 0x005f811cu, 4, &v) == 1 && v == 128);
    CHECK(vf3_pvr_write(p, 0x0c000000u, 4, 0) == 0);
    CHECK(vf3_pvr_read(p, 0x0c000000u, 4, &v) == 0);
    CHECK(vf3_pvr_write_block(p, 0x047fffffu, data, 2) == -1);
    CHECK(vf3_pvr_last_error(p)->code == VF3_PVR_BAD_ACCESS);
    CHECK(vf3_pvr_write(p, 0x04000000u, 4, 0) == -1); /* sticky */
    CHECK(vf3_pvr_write(p, 0x005f8144u, 4, 0x80000000u) == 1); /* recover */
    CHECK(vf3_pvr_read(p, 0x04000000u, 4, &v) == 1 && v == 0x03020100u);
    CHECK(vf3_pvr_write(p, 0x04800000u, 4, 0) == -1);
    vf3_pvr_begin_frame(p);
    CHECK(vf3_pvr_write(p, FIFO, 2, 0) == -1);
    vf3_pvr_begin_frame(p);
    CHECK(vf3_pvr_write(p, 0x10800000u, 4, 0) == -1);
    CHECK(vf3_pvr_last_error(p)->code == VF3_PVR_UNSUPPORTED);
    vf3_pvr_reset(p);
}

static void parser_test(vf3_pvr *p)
{
    uint8_t stream[192], b[64]; size_t split;
    const vf3_pvr_triangle *t;
    /* Original on-disc header (AKI/ST01), exact PCW/ISP/TSP/TCW. Materials are
     * parsed independently of unsupported raster state such as fog. */
    header(stream, 0x8000002cu, 0x83000000u, 0x20082440u, 0x04000000u);
    put(stream + 32, bits(0.75f)); put(stream + 48, bits(0.5f));
    put(stream + 52, bits(0.25f));
    vertex(stream + 64, 8, 8, 1, bits(0.5f), 0);
    put(stream + 64 + 16, bits(0.25f)); put(stream + 64 + 20, bits(0.75f));
    put(stream + 64 + 28, bits(0.5f));
    vertex(stream + 96, 40, 8, 1, bits(0.5f), 0);
    vertex(stream + 128, 8, 40, 1, bits(0.5f), 1);
    memset(stream + 160, 0, 32);
    for (split = 0; split <= sizeof stream; ++split) {
        vf3_pvr_begin_frame(p);
        CHECK(vf3_pvr_write_block(p, FIFO, stream, split) == 1);
        CHECK(vf3_pvr_write_block(p, FIFO, stream + split, sizeof stream - split) == 1);
        CHECK(vf3_pvr_get_stats(p).triangles == 1);
        CHECK(vf3_pvr_get_stats(p).pending_bytes == 0);
        CHECK(vf3_pvr_get_stats(p).packets == 5);
        CHECK(vf3_pvr_get_stats(p).ended_lists == 1);
    }
    t = vf3_pvr_triangle_at(p, 0);
    CHECK(t != NULL);
    if (t) {
        CHECK(t->material.words == 16 && t->material.raw[0] == 0x8000002cu);
        CHECK(t->material.raw[8] == bits(0.75f) && t->material.raw[12] == bits(0.5f));
        CHECK(t->v[0].u == 0.25f && t->v[0].v == 0.75f);
        CHECK(t->v[0].control == 0xe1030060u && t->v[2].control == 0xffffffffu);
        CHECK(t->v[0].base[0] == 191.0f / 255.0f); /* alpha NOT multiplied by intensity */
        CHECK(t->v[0].base[1] == 127.0f / 255.0f);
        CHECK(t->v[0].offset[1] == 31.0f / 255.0f);
    }
    CHECK(vf3_pvr_render(p) == -1); /* original header asks for table fog */
    CHECK(vf3_pvr_last_error(p)->code == VF3_PVR_UNSUPPORTED);
    vf3_pvr_begin_frame(p);
    CHECK(vf3_pvr_write_block(p, FIFO, stream, 32) == 1);
    CHECK(vf3_pvr_get_stats(p).headers == 0 && vf3_pvr_get_stats(p).pending_bytes == 32);
    CHECK(vf3_pvr_render(p) == -1); /* truncated 64-byte header */
    vf3_pvr_begin_frame(p);
    vertex(b, 8, 8, 1, 0xffffffffu, 1); CHECK(vf3_pvr_write_block(p, FIFO, b, 32) == -1);
    vf3_pvr_begin_frame(p);
    header(b, 0x80000000u, 0xe0000000u, NO_FOG, 0); CHECK(words(p, b, 32));
    vertex(b, 8, 8, 1, 0xffffffffu, 0); put(b + 4, 0x7fc00000u);
    CHECK(vf3_pvr_write_block(p, FIFO, b, 32) == -1);
    CHECK(vf3_pvr_last_error(p)->code == VF3_PVR_BAD_VERTEX);
    vf3_pvr_begin_frame(p);
    header(b, 0x80000030u, 0, 0, 0); CHECK(vf3_pvr_write_block(p, FIFO, b, 32) == -1);
    vf3_pvr_begin_frame(p);
    header(b, 0xa0000000u, 0, 0, 0); CHECK(vf3_pvr_write_block(p, FIFO, b, 32) == -1);
    CHECK(vf3_pvr_last_error(p)->code == VF3_PVR_UNSUPPORTED);
    vf3_pvr_begin_frame(p);
    header(b, 0x80000009u, 0, 0, 0); CHECK(vf3_pvr_write_block(p, FIFO, b, 32) == -1);
    vf3_pvr_begin_frame(p);
    header(b, 0x80000000u, 0, 0, 0); CHECK(words(p, b, 32));
    vertex(b, 8, 8, 1, 0xffffffffu, 0); CHECK(words(p, b, 32));
    memset(b, 0, 32); CHECK(vf3_pvr_write_block(p, FIFO, b, 32) == -1);
    vf3_pvr_reset(p);
}

static void texture_test(vf3_pvr *p)
{
    uint8_t b[256] = {0}; uint32_t c = 0;
    /* Known 2x2 corner in an 8x8 square: (0,0),(0,1),(1,0),(1,1).
     * This independently fixes Y-even/X-odd Morton bit ordering. */
    b[0] = 0; b[1] = 0xf8; b[2] = 0xe0; b[3] = 7;
    b[4] = 0x1f; b[5] = 0; b[6] = b[7] = 0xff;
    b[128] = 0xe0; b[129] = 7;
    CHECK(vf3_pvr_write_block(p, 0x11000000u, b, sizeof b) == 1);
    CHECK(vf3_pvr_texel(p, 0, 0x08000000u, 0, 0, &c) == 1 && c == 0xffff0000u);
    CHECK(vf3_pvr_texel(p, 0, 0x08000000u, 0, 1, &c) == 1 && c == 0xff00ff00u);
    CHECK(vf3_pvr_texel(p, 0, 0x08000000u, 1, 0, &c) == 1 && c == 0xff0000ffu);
    CHECK(vf3_pvr_texel(p, 0, 0x08000000u, 1, 1, &c) == 1 && c == 0xffffffffu);
    CHECK(vf3_pvr_texel(p, 8, 0x08000000u, 8, 0, &c) == 1 && c == 0xff00ff00u); /* 16x8 */
    CHECK(vf3_pvr_texel(p, 1, 0x08000000u, 0, 8, &c) == 1 && c == 0xff00ff00u); /* 8x16 */
    CHECK(vf3_pvr_texel(p, 0, 0x0c000000u, 2, 0, &c) == 1 && c == 0xff0000ffu); /* row order */
    CHECK(vf3_pvr_write(p, 0x11000000u, 2, 0xfc00) == 1);
    CHECK(vf3_pvr_texel(p, 0, 0, 0, 0, &c) == 1 && c == 0xffff0000u);
    CHECK(vf3_pvr_write(p, 0x11000000u, 2, 0x8f12) == 1);
    CHECK(vf3_pvr_texel(p, 0, 0x10000000u, 0, 0, &c) == 1 && c == 0x88ff1122u);
    CHECK(vf3_pvr_texel(p, 0, 0x48000000u, 0, 0, &c) == -1);
    CHECK(vf3_pvr_last_error(p)->code == VF3_PVR_UNSUPPORTED);
    vf3_pvr_begin_frame(p);
    CHECK(vf3_pvr_texel(p, 0, 0x080fffffu, 0, 0, &c) == -1);
    CHECK(vf3_pvr_last_error(p)->code == VF3_PVR_BAD_ACCESS);
    vf3_pvr_begin_frame(p);
    CHECK(vf3_pvr_texel(p, 0, 0x08100000u, 0, 0, &c) == -1);
    vf3_pvr_reset(p);
}

static void raster_test(vf3_pvr *p)
{
    uint8_t b[64]; unsigned x, y, covered; uint32_t saved;
    header(b, 0x80000000u, 0x80000000u, NO_FOG, 0); CHECK(words(p, b, 32));
    tri(p, 1, 0xffff0000u); tri(p, 0.5f, 0xff0000ffu); finish(p);
    CHECK(vf3_pvr_write(p, 0x005f8014u, 4, 1) == 1);
    CHECK(pixel(p, 10, 10) == 0xffff0000u && pixel(p, 50, 50) == 0xff000000u);
    CHECK(vf3_pvr_get_stats(p).frames == 1);
    saved = pixel(p, 10, 10);
    vf3_pvr_begin_frame(p);
    header(b, 0x82000000u, 0x80000000u, NO_FOG, 0); CHECK(words(p, b, 32));
    tri(p, 1, 0xffffffffu); finish(p);
    CHECK(vf3_pvr_render(p) == -1 && pixel(p, 10, 10) == saved);
    vf3_pvr_begin_frame(p);
    /* A four-vertex strip covers the square exactly once, including its shared
     * diagonal. Additive red makes overlaps visible; holes remain black. */
    header(b, 0x80000000u, 0xe0000000u, NO_FOG | 0x04000000u, 0); CHECK(words(p, b, 32));
    vertex(b, 8, 8, 1, 0xff400000u, 0); CHECK(words(p, b, 32));
    vertex(b, 40, 8, 1, 0xff400000u, 0); CHECK(words(p, b, 32));
    vertex(b, 8, 40, 1, 0xff400000u, 0); CHECK(words(p, b, 32));
    vertex(b, 40, 40, 1, 0xff400000u, 1); CHECK(words(p, b, 32)); finish(p);
    CHECK(vf3_pvr_get_stats(p).triangles == 2);
    CHECK(vf3_pvr_render(p) == 1);
    covered = 0;
    for (y = 0; y < 48; ++y) for (x = 0; x < 48; ++x) {
        uint32_t expected = x >= 8 && x < 40 && y >= 8 && y < 40 ? 0xff400000u : 0xff000000u;
        CHECK(pixel(p, x, y) == expected); if (pixel(p, x, y) != 0xff000000u) ++covered;
    }
    CHECK(covered == 1024);
    vf3_pvr_begin_frame(p);
    /* Flat shading's provoking color belongs to the third vertex. */
    header(b, 0x80000000u, 0xe0000000u, NO_FOG, 0); CHECK(words(p, b, 32));
    vertex(b, 8, 8, 1, 0xffff0000u, 0); CHECK(words(p, b, 32));
    vertex(b, 40, 8, 1, 0xff00ff00u, 0); CHECK(words(p, b, 32));
    vertex(b, 8, 40, 1, 0xff0000ffu, 1); CHECK(words(p, b, 32)); finish(p);
    CHECK(vf3_pvr_render(p) == 1 && pixel(p, 10, 10) == 0xff0000ffu);
    vf3_pvr_begin_frame(p);
    header(b, 0x80000000u, 0xf8000000u, NO_FOG, 0); CHECK(words(p, b, 32));
    tri(p, 1, 0xffffffffu); finish(p); CHECK(vf3_pvr_render(p) == 1);
    CHECK(pixel(p, 10, 10) == 0xff000000u); /* clockwise culled */
    vf3_pvr_begin_frame(p);
    /* Textured intensity header64: red texel at (0,0), 50% intensity, no offset. */
    CHECK(vf3_pvr_write(p, 0x11000000u, 2, 0xf800) == 1);
    header(b, 0x8000002cu, 0x83000000u, NO_FOG | 0x40u, 0x08000000u);
    CHECK(words(p, b, 64)); tri(p, 1, bits(0.5f)); finish(p);
    CHECK(vf3_pvr_render(p) == 1 && pixel(p, 10, 10) == 0xff7f0000u);
    vf3_pvr_reset(p);
}

static uint32_t sample_triangle(vf3_pvr *p, uint32_t pcw, uint32_t tsp,
                                uint32_t tcw, float u, float v)
{
    uint8_t b[64]; unsigned i;
    vf3_pvr_begin_frame(p);
    header(b, pcw, 0x82000000u, NO_FOG | tsp, tcw); CHECK(words(p, b, 32));
    for (i = 0; i < 3; ++i) {
        vertex(b, i == 1 ? 40 : 8, i == 2 ? 40 : 8, 1, 0xffffffffu, i == 2);
        put(b + 16, bits(u)); put(b + 20, bits(v)); CHECK(words(p, b, 32));
    }
    finish(p); CHECK(vf3_pvr_render(p) == 1); return pixel(p, 10, 10);
}
static void sampling_test(vf3_pvr *p)
{
    uint8_t b[64]; unsigned i;
    /* Four texels at a bilinear footprint, plus a distinctive repeat edge. */
    CHECK(vf3_pvr_write(p, 0x11000000u, 4, 0x07e0f800u) == 1);
    CHECK(vf3_pvr_write(p, 0x11000004u, 4, 0xffff001fu) == 1);
    CHECK(vf3_pvr_write(p, 0x11000054u, 2, 0xffe0) == 1); /* (7,0) yellow */
    CHECK(sample_triangle(p, 0x80000008u, 0, 0x08000000u, 0.0625f, 0.0625f) == 0xffff0000u);
    CHECK(sample_triangle(p, 0x80000008u, 0x2000, 0x08000000u, 0.125f, 0.125f) == 0xff808080u);
    CHECK(sample_triangle(p, 0x80000008u, 0, 0x08000000u, -0.0625f, 0.0625f) == 0xffffff00u);
    CHECK(sample_triangle(p, 0x80000008u, 0x10000, 0x08000000u, -0.0625f, 0.0625f) == 0xffff0000u);
    CHECK(sample_triangle(p, 0x80000008u, 0x40000, 0x08000000u, -0.0625f, 0.0625f) == 0xffff0000u);
    CHECK(sample_triangle(p, 0x80000008u, 0x40000, 0x08000000u, 1.0625f, 0.0625f) == 0xffffff00u);
    CHECK(sample_triangle(p, 0x80000008u, 0, 0x08000000u, 1.0625f, 0.0625f) == 0xffff0000u);
    /* Punch-through uses texture alpha and the actual alpha-reference latch. */
    CHECK(vf3_pvr_write(p, 0x005f811cu, 4, 128) == 1);
    CHECK(vf3_pvr_write(p, 0x11000000u, 2, 0x7c00) == 1);
    CHECK(sample_triangle(p, 0x84000008u, 0, 0, 0, 0) == 0xff000000u);
    CHECK(sample_triangle(p, 0x84000008u, 0x80000, 0, 0, 0) == 0xffff0000u);
    CHECK(vf3_pvr_write(p, 0x11000000u, 2, 0xfc00) == 1);
    CHECK(sample_triangle(p, 0x84000008u, 0, 0, 0, 0) == 0xffff0000u);
    /* At pixel(4,4), affine U lands in column 2; perspective U in column 4. */
    vf3_pvr_begin_frame(p);
    CHECK(vf3_pvr_write(p, 0x11000004u, 2, 0x001f) == 1);
    CHECK(vf3_pvr_write(p, 0x11000008u, 2, 0xf800) == 1);
    header(b, 0x80000008u, 0x82000000u, NO_FOG, 0x0c000000u); CHECK(words(p, b, 32));
    for (i = 0; i < 3; ++i) {
        vertex(b, i == 1 ? 16 : 0, i == 2 ? 16 : 0, i == 1 ? 4 : 1, 0xffffffffu, i == 2);
        put(b + 16, bits(i == 1 ? 1 : 0)); CHECK(words(p, b, 32));
    }
    finish(p); CHECK(vf3_pvr_render(p) == 1 && pixel(p, 4, 4) == 0xffff0000u);
    vf3_pvr_reset(p);
}

static void depth_test(vf3_pvr *p)
{
    static const unsigned expected[8] = {0,1,2,3,4,5,6,7};
    uint8_t b[64]; unsigned mode, candidate;
    for (mode = 0; mode < 8; ++mode) for (candidate = 0; candidate < 3; ++candidate) {
        vf3_pvr_begin_frame(p);
        header(b, 0x80000000u, 0xe0000000u, NO_FOG, 0); CHECK(words(p, b, 32));
        tri(p, 1, 0xffff0000u);
        header(b, 0x80000000u, mode << 29, NO_FOG, 0); CHECK(words(p, b, 32));
        tri(p, candidate == 0 ? 0.5f : candidate == 1 ? 1 : 2, 0xff0000ffu);
        finish(p); CHECK(vf3_pvr_render(p) == 1);
        CHECK(pixel(p, 10, 10) == ((expected[mode] & (1u << candidate)) ? 0xff0000ffu : 0xffff0000u));
    }
    vf3_pvr_begin_frame(p);
    header(b, 0x80000000u, 0xe4000000u, NO_FOG, 0); CHECK(words(p, b, 32));
    tri(p, 2, 0xffff0000u); /* must not write depth */
    header(b, 0x80000000u, 0x80000000u, NO_FOG, 0); CHECK(words(p, b, 32));
    tri(p, 1, 0xff0000ffu); finish(p);
    CHECK(vf3_pvr_render(p) == 1 && pixel(p, 10, 10) == 0xff0000ffu);
    vf3_pvr_reset(p);
}

#ifdef VF3_PVR_TEST_EMITTERS
typedef struct { vf3_pvr *p; unsigned errors; } emitter_bus;
typedef struct { uint32_t address[16], value[16]; unsigned count; } sq_probe;
static void probe_write(void *ctx, uint32_t a, unsigned n, uint32_t v)
{
    sq_probe *probe = (sq_probe *)ctx;
    if (probe->count < 16) {
        probe->address[probe->count] = a; probe->value[probe->count] = v;
    }
    ++probe->count; CHECK(n == 4);
}
static void sq_reset_test(void)
{
    vf3_ram_map map; sq_probe probe; unsigned i;
    memset(&map, 0, sizeof map); memset(&probe, 0, sizeof probe);
    map.device_write = probe_write; map.device_context = &probe;
    CHECK(vf3_native_reset() == 1); vf3_sq_model = 1;
    vf3_matrix_write(&map, 0xff000038u, 0x10, 4);
    vf3_matrix_write(&map, 0xff00003cu, 0x10, 4);
    for (i = 0; i < 16; ++i) vf3_matrix_write(&map, 0xe0000000u + 4 * i, 0x12340000u + i, 4);
    probe.count = 0;
    vf3_matrix_pref(&map, 0xe0000000u); vf3_matrix_pref(&map, 0xe0000020u);
    CHECK(probe.count == 16);
    for (i = 0; i < 16; ++i) {
        CHECK(probe.address[i] == FIFO + 4 * i);
        CHECK(probe.value[i] == 0x12340000u + i);
    }
    CHECK(vf3_native_reset() == 1);
    CHECK(vf3_sq_model == 0); vf3_sq_model = 1;
    probe.count = 0;
    vf3_matrix_pref(&map, 0xe0000000u); vf3_matrix_pref(&map, 0xe0000020u);
    CHECK(probe.count == 16);
    for (i = 0; i < 16; ++i) {
        CHECK(probe.address[i] == 4 * i); /* QACR AREA reset, both queues */
        CHECK(probe.value[i] == 0);      /* old SQ payload must not survive */
    }
    CHECK(vf3_native_reset() == 1);
}
static void emitter_write(void *ctx, uint32_t a, unsigned n, uint32_t v)
{
    emitter_bus *bus = (emitter_bus *)ctx;
    if (vf3_pvr_write(bus->p, a, n, v) < 0) ++bus->errors;
}
static int run_emitter(uint8_t *ram, vf3_matrix_state *s, const vf3_ram_map *map,
                       uint32_t entry, int native)
{
    if (native) {
        vf3_native_tick_result result;
        int ok = vf3_native_tick_run(ram, s->v, entry, s->gbr, &result);
        CHECK(result.device_errors == 0 && result.oob == 0);
        CHECK(result.ta_words == (entry == 0x0c055e00u ? 16u : 8u));
        memcpy(s->v, result.regs, sizeof s->v);
        return ok;
    }
    return entry == 0x0c055e00u ? vf3_poly_header_sq_entry(s, map) : vf3_vertex_emit_sq_entry(s, map);
}
static void original_emitter_test(vf3_pvr *p, int native)
{
    uint8_t *ram = (uint8_t *)calloc(1, 0x01000000u);
    vf3_matrix_state s = {0}; vf3_ram_win win;
    vf3_ram_map map; emitter_bus bus = {p, 0};
    uint32_t source = 0x0c200000u, sq_state = 0x0c1b0000u, template = 0x0c16b820u;
    uint32_t raw_header[4] = {0x8000002cu, 0x83000000u, NO_FOG | 0x40u, 0x08000000u};
    unsigned i; const vf3_pvr_triangle *t;
    CHECK(ram != NULL); if (!ram) return;
    CHECK(vf3_native_reset() == 1);
    if (native) CHECK(vf3_native_attach_pvr(p) == 1);
    win.data = ram; win.base = 0x0c000000u; win.len = 0x01000000u;
    memset(&map, 0, sizeof map); map.wins = &win; map.n = 1;
    map.device_write = emitter_write; map.device_context = &bus;
    s.gbr = 0x0c16b880u; s.gbr_known = 1; s.v[4] = source; s.v[16] = 0xdead0000u;
    vf3_matrix_write(&map, 0x0c16ca08u, sq_state, 4);
    vf3_matrix_write(&map, sq_state, FIFO, 4);
    vf3_matrix_write(&map, s.gbr + 72, 0xe0000000u, 4);
    for (i = 0; i < 4; ++i) {
        vf3_matrix_write(&map, source + 4 + 4 * i, raw_header[i], 4);
        vf3_matrix_write(&map, template + 4 * i, bits(1), 4);
        vf3_matrix_write(&map, template + 16 + 4 * i, 0, 4);
    }
    vf3_sq_model = 1;
    CHECK(run_emitter(ram, &s, &map, 0x0c055e00u, native) == 1);
    CHECK(vf3_pvr_get_stats(p).headers == 1 && vf3_pvr_get_stats(p).pending_bytes == 0);
    CHECK(s.v[12] == 0xe0000040u);
    s.v[6] = s.v[12]; s.v[3] = 3;
    for (i = 0; i < 3; ++i) {
        s.v[1] = bits(0.25f); s.v[2] = bits(0.75f);
        s.v[VF3_REG_FR0 + 4] = 0;
        s.v[VF3_REG_FR0 + 5] = bits(i == 1 ? 40 : 8);
        s.v[VF3_REG_FR0 + 6] = bits(i == 2 ? 40 : 8);
        s.v[VF3_REG_FR0 + 7] = bits(1);
        s.v[VF3_REG_FR0 + 2] = bits(0.5f);
        s.v[VF3_REG_FR0 + 3] = 0;
        CHECK(run_emitter(ram, &s, &map, 0x0c048be0u, native) == 1);
        CHECK(vf3_pvr_get_stats(p).headers == 1);
        CHECK(vf3_pvr_get_stats(p).vertices == i + 1u);
    }
    finish(p); CHECK(bus.errors == 0 && map.oob == 0);
    CHECK(vf3_pvr_get_stats(p).triangles == 1);
    t = vf3_pvr_triangle_at(p, 0);
    CHECK(t && t->material.raw[0] == raw_header[0]);
    if (t) {
        CHECK(t->v[0].control == 0xe0000040u);
        CHECK(t->v[2].control == 0xf000004au); /* emitter arithmetic shift, not a canned command */
        CHECK(t->v[1].x == 40 && t->v[2].y == 40);
        CHECK(t->v[0].u == 0.25f && t->v[0].v == 0.75f);
    }
    CHECK(vf3_native_reset() == 1);
    free(ram); vf3_pvr_reset(p);
}
#endif

static void asset_test(vf3_pvr *p, const char *dir)
{
    char path[2048]; FILE *f; uint8_t data[8192]; uint32_t c = 0; size_t got;
    snprintf(path, sizeof path, "%s/MKAO_AKI.TEX", dir);
    f = fopen(path, "rb"); CHECK(f != NULL); if (!f) return;
    got = fread(data, 1, sizeof data, f); fclose(f);
    CHECK(got == sizeof data); if (got != sizeof data) return;
    CHECK(data[0] == 0x64 && data[1] == 0x69); /* pinned source prefix */
    CHECK(vf3_pvr_write_block(p, 0x11000000u, data, sizeof data) == 1);
    CHECK(vf3_pvr_texel(p, 27, 0x08000000u, 0, 0, &c) == 1 && c == 0xff6b2c21u);
    CHECK(vf3_pvr_texel(p, 27, 0x08000000u, 0, 1, &c) == 1 && c == 0xff945d52u);
    CHECK(vf3_pvr_texel(p, 27, 0x08000000u, 1, 0, &c) == 1 && c == 0xff733429u);
    snprintf(path, sizeof path, "%s/MKAO_AKI.POL", dir);
    f = fopen(path, "rb"); CHECK(f != NULL); if (!f) return;
    if (fseek(f, 0x35b30, SEEK_SET) != 0) { CHECK(0); fclose(f); return; }
    got = fread(data, 1, 16, f); fclose(f);
    CHECK(got == 16); if (got != 16) return;
    CHECK(data[0] == 0x2c && data[3] == 0x80);
    CHECK(data[7] == 0x83 && data[11] == 0x20 && data[15] == 4);
    puts("pvr_ta: original AKI POL header + TEX texels checked (not a captured frame)");
}
int main(int argc, char **argv)
{
    vf3_pvr *p = vf3_pvr_create();
    CHECK(p != NULL); if (!p) return 1;
    bus_test(p); parser_test(p); texture_test(p); raster_test(p); sampling_test(p); depth_test(p);
#ifdef VF3_PVR_TEST_EMITTERS
    sq_reset_test();
    original_emitter_test(p, 0);
    original_emitter_test(p, 1); /* header survives three separate native runs */
#else
    puts("pvr_ta: original emitter integration not compiled into this standalone test");
#endif
    if (argc == 3 && !strcmp(argv[1], "--assets")) asset_test(p, argv[2]);
    else if (argc != 1) { fprintf(stderr, "usage: %s [--assets gamedata-directory]\n", argv[0]); ++failures; }
    vf3_pvr_destroy(p);
    printf("pvr_ta: %u checks, %u failures\n", checks, failures);
    return failures ? 1 : 0;
}
