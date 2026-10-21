/* Independent scalar TA/VRAM implementation, written from the published KOS
 * hardware interface and VF3's original emitters. No external renderer code.
 * This is a tested reference subset, not a cycle- or pixel-exact PVR emulator. */
#include "render/pvr_ta.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define TRIANGLE_LIMIT 65536u
#define REG_BASE 0x005f8000u
#define REG_BYTES 0x2000u
#define PIXELS ((size_t)VF3_PVR_WIDTH * VF3_PVR_HEIGHT)

struct vf3_pvr {
    uint8_t *vram;
    uint32_t *pixels, *scratch;
    float *depth;
    uint32_t regs[REG_BYTES / 4], lmmode[2];
    uint8_t reg_written[REG_BYTES / 4];
    uint8_t packet[64];
    unsigned pending, need;
    uint32_t packet_address;
    vf3_pvr_material material;
    vf3_pvr_vertex previous[2];
    unsigned strip_vertices;
    int have_header, have_face, list;
    float face[4], face_offset[4];
    vf3_pvr_triangle *triangles;
    size_t count, capacity;
    vf3_pvr_stats stats;
    vf3_pvr_error error;
};

static uint32_t rd32(const uint8_t *b)
{
    return (uint32_t)b[0] | (uint32_t)b[1] << 8 |
           (uint32_t)b[2] << 16 | (uint32_t)b[3] << 24;
}
static float as_float(uint32_t w) { float f; memcpy(&f, &w, 4); return f; }
static int fail(vf3_pvr *p, vf3_pvr_error_code code, uint32_t a,
                uint32_t pcw, const char *message)
{
    if (p && p->error.code == VF3_PVR_OK) {
        p->error.code = code; p->error.address = a; p->error.pcw = pcw;
        p->error.packet = p->stats.packets; p->error.message = message;
    }
    return -1;
}
static float clamp01(float f) { return f < 0 ? 0 : f > 1 ? 1 : f; }
static void unpack(uint32_t c, float out[4])
{
    unsigned i;
    for (i = 0; i < 4; ++i) out[i] = (float)((c >> (24 - 8 * i)) & 255) / 255.0f;
}
static uint32_t pack(const float c[4])
{
    unsigned i; uint32_t out = 0;
    for (i = 0; i < 4; ++i) out |= (uint32_t)(clamp01(c[i]) * 255.0f + 0.5f) << (24 - 8 * i);
    return out;
}

void vf3_pvr_begin_frame(vf3_pvr *p)
{
    uint64_t frames;
    if (!p) return;
    frames = p->stats.frames;
    memset(&p->stats, 0, sizeof p->stats); p->stats.frames = frames;
    memset(&p->error, 0, sizeof p->error); p->error.message = "no error";
    memset(&p->material, 0, sizeof p->material);
    p->pending = 0; p->need = 32; p->count = 0;
    p->have_header = p->have_face = 0; p->strip_vertices = 0; p->list = -1;
}
void vf3_pvr_reset(vf3_pvr *p)
{
    size_t i;
    if (!p) return;
    memset(p->vram, 0, VF3_PVR_VRAM_SIZE);
    memset(p->regs, 0, sizeof p->regs);
    memset(p->reg_written, 0, sizeof p->reg_written);
    p->lmmode[0] = p->lmmode[1] = 0;
    p->stats.frames = 0; vf3_pvr_begin_frame(p);
    for (i = 0; i < PIXELS; ++i) p->pixels[i] = p->scratch[i] = 0xff000000u;
    memset(p->depth, 0, PIXELS * sizeof *p->depth);
}
vf3_pvr *vf3_pvr_create(void)
{
    vf3_pvr *p = (vf3_pvr *)calloc(1, sizeof *p);
    if (!p) return NULL;
    p->vram = (uint8_t *)malloc(VF3_PVR_VRAM_SIZE);
    p->pixels = (uint32_t *)malloc(PIXELS * sizeof *p->pixels);
    p->scratch = (uint32_t *)malloc(PIXELS * sizeof *p->scratch);
    p->depth = (float *)malloc(PIXELS * sizeof *p->depth);
    if (!p->vram || !p->pixels || !p->scratch || !p->depth) {
        vf3_pvr_destroy(p); return NULL;
    }
    vf3_pvr_reset(p); return p;
}
void vf3_pvr_destroy(vf3_pvr *p)
{
    if (!p) return;
    free(p->vram); free(p->pixels); free(p->scratch); free(p->depth);
    free(p->triangles); free(p);
}
const uint32_t *vf3_pvr_framebuffer(const vf3_pvr *p) { return p ? p->pixels : NULL; }
const vf3_pvr_error *vf3_pvr_last_error(const vf3_pvr *p) { return p ? &p->error : NULL; }
vf3_pvr_stats vf3_pvr_get_stats(const vf3_pvr *p)
{
    vf3_pvr_stats s = {0};
    if (p) { s = p->stats; s.triangles = p->count; s.pending_bytes = p->pending; }
    return s;
}
const vf3_pvr_triangle *vf3_pvr_triangle_at(const vf3_pvr *p, size_t i)
{ return p && i < p->count ? &p->triangles[i] : NULL; }

static int append_triangle(vf3_pvr *p, const vf3_pvr_vertex *v)
{
    vf3_pvr_triangle *t;
    unsigned odd = (p->strip_vertices - 2u) & 1u;
    if (p->count == TRIANGLE_LIMIT)
        return fail(p, VF3_PVR_LIMIT, p->packet_address, p->material.pcw, "triangle budget exhausted");
    if (p->count == p->capacity) {
        size_t cap = p->capacity ? p->capacity * 2u : 256u;
        void *mem = realloc(p->triangles, cap * sizeof *p->triangles);
        if (!mem) return fail(p, VF3_PVR_NO_MEMORY, p->packet_address, p->material.pcw, "triangle allocation failed");
        p->triangles = (vf3_pvr_triangle *)mem; p->capacity = cap;
    }
    t = &p->triangles[p->count++]; t->material = p->material;
    t->v[0] = p->previous[odd]; t->v[1] = p->previous[1u - odd]; t->v[2] = *v;
    return 1;
}

static int decode_packet(vf3_pvr *p)
{
    uint32_t w[16], pcw;
    unsigned i, type, color;
    for (i = 0; i < p->need / 4; ++i) w[i] = rd32(p->packet + 4 * i);
    pcw = w[0]; type = pcw >> 29;
    if (type == 4) {
        vf3_pvr_material *m = &p->material;
        if (p->strip_vertices)
            return fail(p, VF3_PVR_BAD_STREAM, p->packet_address, pcw, "header interrupts an unfinished strip");
        if (((pcw >> 24) & 7) > 4 || ((pcw >> 24) & 1) || (pcw & 0x80))
            return fail(p, VF3_PVR_UNSUPPORTED, p->packet_address, pcw, "modifier volumes or invalid list");
        if (p->list >= 0 && p->list != (int)((pcw >> 24) & 7))
            return fail(p, VF3_PVR_BAD_STREAM, p->packet_address, pcw, "list changed before end-of-list");
        color = (pcw >> 4) & 3;
        if (color == 1)
            return fail(p, VF3_PVR_UNSUPPORTED, p->packet_address, pcw, "floating vertex color packets");
        if (pcw & 1)
            return fail(p, VF3_PVR_UNSUPPORTED, p->packet_address, pcw, "16-bit UV vertex packets");
        if (color == 3 && !p->have_face)
            return fail(p, VF3_PVR_BAD_STREAM, p->packet_address, pcw, "previous-intensity header without a face color");
        memset(m, 0, sizeof *m);
        m->pcw = pcw; m->isp = w[1]; m->tsp = w[2]; m->tcw = w[3];
        m->words = p->need / 4; memcpy(m->raw, w, p->need);
        if (color == 2) {
            unsigned at = p->need == 64 ? 8 : 4;
            for (i = 0; i < 4; ++i) {
                p->face[i] = as_float(w[at + i]);
                p->face_offset[i] = p->need == 64 ? as_float(w[12 + i]) : 0;
                if (!isfinite(p->face[i]) || !isfinite(p->face_offset[i]))
                    return fail(p, VF3_PVR_BAD_VERTEX, p->packet_address, pcw, "nonfinite face color");
            }
            p->have_face = 1;
        }
        if (color >= 2) {
            memcpy(m->face, p->face, sizeof m->face);
            memcpy(m->face_offset, p->face_offset, sizeof m->face_offset);
        }
        p->have_header = 1; p->list = (int)((pcw >> 24) & 7);
        ++p->stats.headers;
    } else if (type == 7) {
        vf3_pvr_vertex v;
        const vf3_pvr_material *m = &p->material;
        if (!p->have_header)
            return fail(p, VF3_PVR_BAD_STREAM, p->packet_address, pcw, "vertex without polygon header");
        memset(&v, 0, sizeof v); v.control = pcw;
        v.x = as_float(w[1]); v.y = as_float(w[2]); v.inv_z = as_float(w[3]);
        if (m->pcw & 8) {
            v.u = as_float((m->pcw & 1) ? w[4] & 0xffff0000u : w[4]);
            v.v = as_float((m->pcw & 1) ? w[4] << 16 : w[5]);
        }
        if (!isfinite(v.x) || !isfinite(v.y) || !isfinite(v.inv_z) ||
            !isfinite(v.u) || !isfinite(v.v) || v.inv_z <= 0 ||
            fabsf(v.x) > 32768 || fabsf(v.y) > 32768 ||
            fabsf(v.u) > 1048576 || fabsf(v.v) > 1048576)
            return fail(p, VF3_PVR_BAD_VERTEX, p->packet_address, pcw, "invalid or out-of-range vertex");
        color = (m->pcw >> 4) & 3;
        if (color == 0) { unpack(w[6], v.base); unpack(w[7], v.offset); }
        else {
            float base = as_float(w[6]), offset = as_float(w[7]);
            if (!isfinite(base) || ((m->pcw & 4) && !isfinite(offset)))
                return fail(p, VF3_PVR_BAD_VERTEX, p->packet_address, pcw, "nonfinite vertex intensity");
            /* Intensity multiplies RGB only; alpha comes from the face. */
            v.base[0] = m->face[0]; v.offset[0] = m->face_offset[0];
            for (i = 1; i < 4; ++i) {
                v.base[i] = m->face[i] * base;
                v.offset[i] = (m->pcw & 4) ? m->face_offset[i] * offset : 0;
            }
        }
        for (i = 0; i < 4; ++i) {
            if (!isfinite(v.base[i]) || ((m->pcw & 4) && !isfinite(v.offset[i])))
                return fail(p, VF3_PVR_BAD_VERTEX, p->packet_address, pcw, "vertex color overflow");
            /* The TA quantizes shading colors before storing ISP parameters. */
            v.base[i] = (float)(unsigned)(clamp01(v.base[i]) * 255.0f) / 255.0f;
            v.offset[i] = (m->pcw & 4) ? (float)(unsigned)(clamp01(v.offset[i]) * 255.0f) / 255.0f : 0;
        }
        if (p->strip_vertices >= 2 && append_triangle(p, &v) < 0) return -1;
        p->previous[0] = p->previous[1]; p->previous[1] = v;
        ++p->strip_vertices; ++p->stats.vertices;
        if (pcw & 0x10000000u) { p->strip_vertices = 0; ++p->stats.strips; }
    } else if (type == 0) {
        if (p->strip_vertices)
            return fail(p, VF3_PVR_BAD_STREAM, p->packet_address, pcw, "end-of-list before end-of-strip");
        if (p->list >= 0) p->stats.ended_lists |= 1u << (unsigned)p->list;
        p->have_header = 0; p->list = -1; ++p->stats.lists;
    } else {
        return fail(p, VF3_PVR_UNSUPPORTED, p->packet_address, pcw,
                    type == 5 ? "sprite packets" : "TA control parameter type");
    }
    ++p->stats.packets; return 1;
}

static int fifo_bytes(vf3_pvr *p, uint32_t a, const uint8_t *b, size_t len)
{
    size_t i;
    for (i = 0; i < len; ++i) {
        if (!p->pending) p->packet_address = a;
        p->packet[p->pending++] = b[i]; ++p->stats.bytes;
        if (p->pending == 32) {
            uint32_t pcw = rd32(p->packet);
            /* Intensity + offset color carries two face colors in block two.
             * This is the original VF3 0x8000002c header variant. */
            if ((pcw >> 29) == 4 && ((pcw >> 4) & 3) == 2 && (pcw & 4)) p->need = 64;
        }
        if (p->pending == p->need) {
            if (decode_packet(p) < 0) return -1;
            p->pending = 0; p->need = 32;
        }
    }
    return 1;
}

/* 64-bit interleaved storage is canonical. In the 32-bit view the high
 * address bit selects a 4 MiB bank; the low word address advances in that bank. */
static uint32_t bank32(uint32_t a)
{ return ((a & 0x003ffffcu) << 1) | ((a & 0x00400000u) >> 20) | (a & 3u); }

/* 1 FIFO, 2 VRAM64, 3 VRAM32, 4 unsupported YUV, 0 not ours, -1 hole. */
static int region(const vf3_pvr *p, uint32_t a, uint32_t *offset)
{
    if (a >= 0x04000000u && a < 0x08000000u) {
        *offset = a & 0x00ffffffu;
        if (*offset >= VF3_PVR_VRAM_SIZE) return -1;
        return (a & 0x01000000u) ? 3 : 2;
    }
    if (a >= 0x10000000u && a < 0x14000000u) {
        if ((a & 0x01000000u) == 0) return (a & 0x00800000u) ? 4 : 1;
        *offset = a & (VF3_PVR_VRAM_SIZE - 1u);
        return p->lmmode[(a >> 25) & 1u] ? 3 : 2;
    }
    return 0;
}
int vf3_pvr_write_block(vf3_pvr *p, uint32_t address, const uint8_t *bytes, size_t len)
{
    uint32_t a = address & 0x1fffffffu, off = 0;
    int r; size_t i;
    if (!p) return -1;
    r = region(p, a, &off);
    if (!r) return 0;
    if (p->error.code) return -1;
    if ((!bytes && len) || r < 0)
        return fail(p, VF3_PVR_BAD_ACCESS, address, 0, "invalid VRAM block access");
    if (r == 4) return fail(p, VF3_PVR_UNSUPPORTED, address, 0, "YUV converter writes");
    if (r == 1) return fifo_bytes(p, a, bytes, len);
    if (len > VF3_PVR_VRAM_SIZE - off)
        return fail(p, VF3_PVR_BAD_ACCESS, address, 0, "VRAM write crosses view boundary");
    for (i = 0; i < len; ++i) {
        uint32_t at = off + (uint32_t)i;
        p->vram[r == 3 ? bank32(at) : at] = bytes[i];
    }
    return 1;
}
int vf3_pvr_read(vf3_pvr *p, uint32_t address, unsigned size, uint32_t *value)
{
    uint32_t a = address & 0x1fffffffu, off = 0;
    unsigned i; int r;
    if (!p || !value) return -1;
    /* Beam position belongs to the runtime clock, never a raw register latch. */
    if (a == REG_BASE + 0x10c) return 0;
    r = region(p, a, &off);
    if (!r && a != 0x005f6884u && a != 0x005f6888u &&
        !(a >= REG_BASE && a < REG_BASE + REG_BYTES)) return 0;
    if (p->error.code) return -1;
    if (size != 1 && size != 2 && size != 4)
        return fail(p, VF3_PVR_BAD_ACCESS, address, 0, "invalid scalar width");
    if (r == 2 || r == 3) {
        if (size > VF3_PVR_VRAM_SIZE - off)
            return fail(p, VF3_PVR_BAD_ACCESS, address, 0, "VRAM read crosses view boundary");
        *value = 0;
        for (i = 0; i < size; ++i) *value |= (uint32_t)p->vram[r == 3 ? bank32(off + i) : off + i] << (8 * i);
        return 1;
    }
    if (r) return fail(p, VF3_PVR_BAD_ACCESS, address, 0, "read of write-only port or unmapped VRAM");
    if (size != 4 || (a & 3)) return fail(p, VF3_PVR_BAD_ACCESS, address, 0, "unaligned or partial register read");
    if (a == 0x005f6884u || a == 0x005f6888u) { *value = p->lmmode[(a - 0x005f6884u) / 4]; return 1; }
    if (a == REG_BASE) { *value = 0x17fd11dbu; return 1; }
    if (a == REG_BASE + 4) { *value = 0x11u; return 1; }
    off = (a - REG_BASE) / 4;
    if (!p->reg_written[off]) return 0; /* unknown reset/status values belong to runtime */
    *value = p->regs[off]; return 1;
}
int vf3_pvr_write(vf3_pvr *p, uint32_t address, unsigned size, uint32_t value)
{
    uint32_t a = address & 0x1fffffffu, off = 0;
    uint8_t bytes[4]; unsigned i; int r;
    if (!p) return -1;
    if (a == REG_BASE + 8 && size == 4 && (value & 1)) { vf3_pvr_begin_frame(p); return 1; }
    if (a == REG_BASE + 0x144 && size == 4 && (value & 0x80000000u)) { vf3_pvr_begin_frame(p); return 1; }
    r = region(p, a, &off);
    if (!r && a != 0x005f6884u && a != 0x005f6888u &&
        !(a >= REG_BASE && a < REG_BASE + REG_BYTES)) return 0;
    if (p->error.code) return -1;
    if ((size != 1 && size != 2 && size != 4) || ((r == 1 || !r) && (size != 4 || (a & 3))))
        return fail(p, VF3_PVR_BAD_ACCESS, address, 0, "invalid scalar width or alignment");
    if (r) {
        for (i = 0; i < size; ++i) bytes[i] = (uint8_t)(value >> (8 * i));
        return vf3_pvr_write_block(p, address, bytes, size);
    }
    if (a == 0x005f6884u || a == 0x005f6888u) {
        if (value & ~1u) return fail(p, VF3_PVR_UNSUPPORTED, address, 0, "reserved direct-path mode bits");
        p->lmmode[(a - 0x005f6884u) / 4] = value; return 1;
    }
    if (a == REG_BASE + 0x14) return vf3_pvr_render(p);
    if (a == REG_BASE + 0x160 && value)
        return fail(p, VF3_PVR_UNSUPPORTED, address, 0, "TA list continuation contexts");
    p->regs[(a - REG_BASE) / 4] = value; p->reg_written[(a - REG_BASE) / 4] = 1;
    return 1;
}

static int texture_valid(vf3_pvr *p, uint32_t tsp, uint32_t tcw)
{
    unsigned w = 8u << ((tsp >> 3) & 7), h = 8u << (tsp & 7);
    uint32_t base = (tcw & 0x001fffffu) * 8u;
    if (tcw & 0xc2000000u || ((tcw >> 27) & 7) > 2)
        return fail(p, VF3_PVR_UNSUPPORTED, base, p->material.pcw, "VQ, mipmap, stride or texture pixel format");
    if (tcw & 0x01f00000u)
        return fail(p, VF3_PVR_BAD_ACCESS, base, p->material.pcw, "texture address exceeds retail VRAM");
    if ((size_t)w * h * 2u > VF3_PVR_VRAM_SIZE - base)
        return fail(p, VF3_PVR_BAD_ACCESS, base, p->material.pcw, "texture exceeds VRAM boundary");
    return 1;
}
static uint32_t texture_pixel(const vf3_pvr *p, uint32_t tsp, uint32_t tcw, unsigned x, unsigned y)
{
    unsigned w = 8u << ((tsp >> 3) & 7), h = 8u << (tsp & 7);
    uint32_t index, base = (tcw & 0x000fffffu) * 8u;
    uint16_t raw;
    if (tcw & 0x04000000u) index = y * w + x;
    else {
        unsigned side = w < h ? w : h, bit, shift = 0;
        index = (x / side + y / side) * side * side;
        /* Rectangles are a sequence of square Morton blocks; Y is the low bit. */
        for (bit = 1; bit < side; bit <<= 1, shift += 2) {
            if (y & bit) index |= 1u << shift;
            if (x & bit) index |= 2u << shift;
        }
    }
    raw = (uint16_t)((uint16_t)p->vram[base + index * 2] | (uint16_t)p->vram[base + index * 2 + 1] << 8);
    switch ((tcw >> 27) & 7) {
    case 0: return (raw & 0x8000 ? 0xff000000u : 0) |
                   (uint32_t)((((raw >> 10) & 31) << 3) | ((raw >> 12) & 7)) << 16 |
                   (uint32_t)((((raw >> 5) & 31) << 3) | ((raw >> 7) & 7)) << 8 |
                   ((raw & 31) << 3) | ((raw >> 2) & 7);
    case 1: return 0xff000000u | (uint32_t)((((raw >> 11) & 31) << 3) | ((raw >> 13) & 7)) << 16 |
                   (uint32_t)((((raw >> 5) & 63) << 2) | ((raw >> 9) & 3)) << 8 |
                   ((raw & 31) << 3) | ((raw >> 2) & 7);
    default: return (uint32_t)((raw >> 12) * 17) << 24 | (uint32_t)(((raw >> 8) & 15) * 17) << 16 |
                   (uint32_t)(((raw >> 4) & 15) * 17) << 8 | (raw & 15) * 17;
    }
}
int vf3_pvr_texel(vf3_pvr *p, uint32_t tsp, uint32_t tcw, unsigned x, unsigned y, uint32_t *argb)
{
    if (!p || !argb) return -1;
    if (p->error.code) return -1;
    if (texture_valid(p, tsp, tcw) < 0) return -1;
    if (x >= (8u << ((tsp >> 3) & 7)) || y >= (8u << (tsp & 7)))
        return fail(p, VF3_PVR_BAD_ACCESS, 0, 0, "texel coordinates out of range");
    *argb = texture_pixel(p, tsp, tcw, x, y); return 1;
}

static unsigned wrap_texel(int x, unsigned size, int clamp, int flip)
{
    int period = (int)size * (flip ? 2 : 1);
    if (clamp) return x < 0 ? 0 : x >= (int)size ? size - 1 : (unsigned)x;
    x %= period; if (x < 0) x += period;
    return (unsigned)(x >= (int)size ? period - 1 - x : x);
}
static void sample(const vf3_pvr *p, const vf3_pvr_material *m, double u, double v, float out[4])
{
    unsigned w = 8u << ((m->tsp >> 3) & 7), h = 8u << (m->tsp & 7), i, j;
    int bilinear = ((m->tsp >> 13) & 3) == 1;
    double fx = u * w - (bilinear ? 0.5 : 0), fy = v * h - (bilinear ? 0.5 : 0);
    int x = (int)floor(fx), y = (int)floor(fy);
    double ax = bilinear ? fx - x : 0, ay = bilinear ? fy - y : 0;
    for (i = 0; i < 4; ++i) out[i] = 0;
    for (j = 0; j < (bilinear ? 4u : 1u); ++j) {
        unsigned sx = wrap_texel(x + (int)(j & 1), w, (m->tsp & 0x10000) != 0, (m->tsp & 0x40000) != 0);
        unsigned sy = wrap_texel(y + (int)(j >> 1), h, (m->tsp & 0x8000) != 0, (m->tsp & 0x20000) != 0);
        float color[4]; double weight = (j & 1 ? ax : 1 - ax) * (j & 2 ? ay : 1 - ay);
        unpack(texture_pixel(p, m->tsp, m->tcw, sx, sy), color);
        for (i = 0; i < 4; ++i) out[i] += (float)(color[i] * weight);
    }
}
static int compare_depth(unsigned mode, float a, float b)
{
    switch (mode) {
    case 0: return 0; case 1: return a < b; case 2: return a == b; case 3: return a <= b;
    case 4: return a > b; case 5: return a != b; case 6: return a >= b; default: return 1;
    }
}
static float blend_factor(unsigned mode, unsigned component, const float s[4], const float d[4], int destination)
{
    switch (mode) {
    case 0: return 0; case 1: return 1;
    case 2: return destination ? s[component] : d[component];
    case 3: return 1 - (destination ? s[component] : d[component]);
    case 4: return s[0]; case 5: return 1 - s[0]; case 6: return d[0]; default: return 1 - d[0];
    }
}
static int64_t edge(int64_t ax, int64_t ay, int64_t bx, int64_t by, int64_t x, int64_t y)
{ return (bx - ax) * (y - ay) - (by - ay) * (x - ax); }
static int top_left(int64_t ax, int64_t ay, int64_t bx, int64_t by)
{ return by < ay || (by == ay && bx > ax); }

static void raster(vf3_pvr *p, const vf3_pvr_triangle *t)
{
    const vf3_pvr_material *m = &t->material;
    const vf3_pvr_vertex *v[3] = {&t->v[0], &t->v[1], &t->v[2]};
    int64_t x[3], y[3], area; int minx, miny, maxx, maxy, px, py;
    unsigned i, cull = (m->isp >> 27) & 3;
    for (i = 0; i < 3; ++i) { x[i] = (int64_t)floor((double)v[i]->x * 256 + 0.5); y[i] = (int64_t)floor((double)v[i]->y * 256 + 0.5); }
    area = edge(x[0], y[0], x[1], y[1], x[2], y[2]);
    if (!area || (cull == 2 && area < 0) || (cull == 3 && area > 0)) return;
    if (cull && fabs((double)area / 65536.0) < as_float(p->regs[0x78 / 4])) return;
    if (area < 0) {
        const vf3_pvr_vertex *tmp = v[0]; int64_t k;
        v[0] = v[1]; v[1] = tmp;
        k = x[0]; x[0] = x[1]; x[1] = k; k = y[0]; y[0] = y[1]; y[1] = k; area = -area;
    }
    minx = (int)floor(fmin(fmin(v[0]->x, v[1]->x), v[2]->x));
    miny = (int)floor(fmin(fmin(v[0]->y, v[1]->y), v[2]->y));
    maxx = (int)ceil(fmax(fmax(v[0]->x, v[1]->x), v[2]->x));
    maxy = (int)ceil(fmax(fmax(v[0]->y, v[1]->y), v[2]->y));
    if (minx < 0) minx = 0;
    if (miny < 0) miny = 0;
    if (maxx > VF3_PVR_WIDTH) maxx = VF3_PVR_WIDTH;
    if (maxy > VF3_PVR_HEIGHT) maxy = VF3_PVR_HEIGHT;
    for (py = miny; py < maxy; ++py) for (px = minx; px < maxx; ++px) {
        int64_t sx = (int64_t)px * 256 + 128, sy = (int64_t)py * 256 + 128;
        int64_t e[3]; double b[3], invz, u, tv;
        float base[4], offset[4], tex[4], src[4], dst[4], out[4];
        size_t at = (size_t)py * VF3_PVR_WIDTH + (unsigned)px;
        unsigned j, env = (m->tsp >> 6) & 3;
        e[0] = edge(x[1], y[1], x[2], y[2], sx, sy);
        e[1] = edge(x[2], y[2], x[0], y[0], sx, sy);
        e[2] = edge(x[0], y[0], x[1], y[1], sx, sy);
        if (e[0] < 0 || e[1] < 0 || e[2] < 0 ||
            (!e[0] && !top_left(x[1], y[1], x[2], y[2])) ||
            (!e[1] && !top_left(x[2], y[2], x[0], y[0])) ||
            (!e[2] && !top_left(x[0], y[0], x[1], y[1]))) continue;
        for (i = 0; i < 3; ++i) b[i] = (double)e[i] / (double)area;
        invz = b[0] * v[0]->inv_z + b[1] * v[1]->inv_z + b[2] * v[2]->inv_z;
        if (!compare_depth(m->isp >> 29, (float)invz, p->depth[at])) continue;
        for (i = 0; i < 4; ++i) {
            base[i] = (m->pcw & 2) ? (float)((b[0] * v[0]->base[i] * v[0]->inv_z + b[1] * v[1]->base[i] * v[1]->inv_z + b[2] * v[2]->base[i] * v[2]->inv_z) / invz) : t->v[2].base[i];
            offset[i] = (m->pcw & 2) ? (float)((b[0] * v[0]->offset[i] * v[0]->inv_z + b[1] * v[1]->offset[i] * v[1]->inv_z + b[2] * v[2]->offset[i] * v[2]->inv_z) / invz) : t->v[2].offset[i];
        }
        if (!(m->tsp & 0x00100000u)) base[0] = 1;
        memcpy(src, base, sizeof src);
        if (m->pcw & 8) {
            u = tv = 0;
            for (j = 0; j < 3; ++j) { u += b[j] * v[j]->u * v[j]->inv_z; tv += b[j] * v[j]->v * v[j]->inv_z; }
            sample(p, m, u / invz, tv / invz, tex);
            if (m->tsp & 0x00080000u) tex[0] = 1;
            for (i = 1; i < 4; ++i)
                src[i] = env == 0 ? tex[i] : env == 2 ? tex[i] * tex[0] + base[i] * (1 - tex[0]) : tex[i] * base[i];
            src[0] = env == 0 || env == 1 ? tex[0] : env == 2 ? base[0] : tex[0] * base[0];
        }
        for (i = 1; i < 4; ++i) if (m->pcw & 4) src[i] += offset[i];
        for (i = 0; i < 4; ++i) src[i] = clamp01(src[i]);
        if (((m->pcw >> 24) & 7) == 4 && src[0] * 255 < (p->regs[0x11c / 4] & 255)) continue;
        unpack(p->scratch[at], dst);
        for (i = 0; i < 4; ++i)
            out[i] = src[i] * blend_factor(m->tsp >> 29, i, src, dst, 0) + dst[i] * blend_factor((m->tsp >> 26) & 7, i, src, dst, 1);
        p->scratch[at] = pack(out);
        if (!(m->isp & 0x04000000u)) p->depth[at] = (float)invz;
    }
}

int vf3_pvr_render(vf3_pvr *p)
{
    size_t i; uint32_t *swap;
    if (!p) return -1;
    if (p->error.code) return -1;
    if (p->pending || p->strip_vertices || p->list >= 0)
        return fail(p, VF3_PVR_BAD_STREAM, p->packet_address, p->material.pcw, "render of incomplete TA list");
    if (p->regs[0x8c / 4] || p->regs[0x60 / 4] & 0x01000000u)
        return fail(p, VF3_PVR_UNSUPPORTED, REG_BASE + 0x8c, 0, "background plane or render-to-texture");
    if (!isfinite(as_float(p->regs[0x78 / 4])) || as_float(p->regs[0x78 / 4]) < 0)
        return fail(p, VF3_PVR_BAD_ACCESS, REG_BASE + 0x78, 0, "invalid culling threshold");
    for (i = 0; i < p->count; ++i) {
        const vf3_pvr_material *m = &p->triangles[i].material;
        p->material = *m; /* precise error context */
        if (((m->pcw >> 24) & 7) == 2 || (m->pcw & 0x00030000u))
            return fail(p, VF3_PVR_UNSUPPORTED, 0, m->pcw, "translucent sorting or user clipping");
        if (((m->tsp >> 22) & 3) != 2 || (m->tsp & 0x03201000u))
            return fail(p, VF3_PVR_UNSUPPORTED, 0, m->pcw, "fog, color clamp, supersampling or secondary accumulation");
        if ((m->pcw & 8) && (((m->tsp >> 13) & 3) > 1 || texture_valid(p, m->tsp, m->tcw) < 0)) {
            if (!p->error.code) fail(p, VF3_PVR_UNSUPPORTED, 0, m->pcw, "trilinear filtering");
            return -1;
        }
    }
    for (i = 0; i < PIXELS; ++i) { p->scratch[i] = 0xff000000u; p->depth[i] = 0; }
    /* Hardware list order: opaque, then punch through. Translucency is rejected
     * until per-pixel sorting is implemented, never approximated by draw order. */
    for (i = 0; i < p->count; ++i) if (((p->triangles[i].material.pcw >> 24) & 7) == 0) raster(p, &p->triangles[i]);
    for (i = 0; i < p->count; ++i) if (((p->triangles[i].material.pcw >> 24) & 7) == 4) raster(p, &p->triangles[i]);
    swap = p->pixels; p->pixels = p->scratch; p->scratch = swap;
    ++p->stats.frames; return 1;
}
