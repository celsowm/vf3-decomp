/* render/pvr2.c - the PVR2 model.
 *
 * The model owns the PVR2's memory (the VRAM and the register file) and
 * rasterises the Tile Accelerator's command stream into a framebuffer.
 *
 * What the hardware does, and what this file does:
 *
 *   - The TA's vertices are already in screen space: x and y are pixels and z
 *     is 1/w, so the *nearest* surface is the one with the largest z.
 *   - A polygon is a triangle strip; the strip ends on the vertex whose own
 *     control word carries the EndOfStrip bit.
 *   - The texture coordinates are interpolated with perspective: the value at
 *     a pixel is (sum of l_i * u_i * z_i) / (sum of l_i * z_i).
 *   - The colour is the vertex's own colour (or the face colour scaled by the
 *     vertex's intensity), modulated by the texture, and then blended with the
 *     framebuffer the way the TSP's two instruction fields say.
 *   - The clip rectangle comes from the PVR2's registers.
 *
 * The texture is read the way the hardware's texture control word says: the
 * address is in units of eight bytes and the texels follow each other in the
 * VRAM's linear order.  (The bank interleaving applies to the *guest's* view
 * of the VRAM window, not to the TA's view of a texture.)
 *
 * What it does not do yet: the fog, the mipmaps, the palette textures, the
 * YUV textures, the modifier volumes and the user clip rectangle.
 */
#include "render/pvr2.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The register file's offsets (the file is a byte array; the 32-bit
 * registers are little-endian). */
#define REG_FB_W_CTRL       0x48u
#define REG_FB_W_LINESTRIDE 0x4Cu
#define REG_FB_W_SOF1       0x60u
#define REG_FB_X_CLIP       0x68u
#define REG_FB_Y_CLIP       0x6Cu
#define REG_PT_ALPHA_REF    0x11Cu
#define REG_TA_OL_BASE      0x124u
#define REG_TA_ISP_BASE     0x128u

void vf3_pvr2_init(vf3_pvr2 *p)
{
    memset(p, 0, sizeof *p);
    p->fb = malloc((size_t)VF3_PVR2_PIXELS * sizeof *p->fb);
    p->depth = malloc((size_t)VF3_PVR2_PIXELS * sizeof *p->depth);
    p->vram = calloc(VF3_PVR2_VRAM_SIZE, 1);
    p->regs = calloc(VF3_PVR2_REG_SIZE / 4, sizeof *p->regs);
    if (p->fb) memset(p->fb, 0, (size_t)VF3_PVR2_PIXELS * sizeof *p->fb);
    if (p->depth) memset(p->depth, 0, (size_t)VF3_PVR2_PIXELS * sizeof *p->depth);
    /* the defaults the hardware comes up with: a 640x480 frame buffer at the
     * top of the VRAM, 16 bit pixels. */
    p->fb_width = VF3_PVR2_WIDTH;
    p->fb_height = VF3_PVR2_HEIGHT;
    p->fb_stride = VF3_PVR2_WIDTH * 2;
    p->fb_base = 0x00600000u;
    p->pack_mode = 0;
    p->clip_x0 = 0;
    p->clip_y0 = 0;
    p->clip_x1 = VF3_PVR2_WIDTH - 1;
    p->clip_y1 = VF3_PVR2_HEIGHT - 1;
}

void vf3_pvr2_free(vf3_pvr2 *p)
{
    free(p->fb);
    free(p->depth);
    free(p->vram);
    free(p->regs);
    free(p->ta);
    p->fb = NULL;
    p->depth = NULL;
    p->vram = NULL;
    p->regs = NULL;
    p->ta = NULL;
    p->ta_cap = p->ta_words = 0;
}

/* The reference emulator's instrument writes the state as: u32 register
 * bytes, u32 VRAM bytes, the register file, the VRAM.  The register file is
 * the emulator's byte array, so its 32-bit registers are little-endian. */
int vf3_pvr2_load_state(vf3_pvr2 *p, const char *path)
{
    FILE *f = fopen(path, "rb");
    if (!f) return -1;
    uint32_t header[2] = {0, 0};
    if (fread(header, 1, sizeof header, f) != sizeof header) { fclose(f); return -1; }
    const uint32_t reg_bytes = header[0];
    const uint32_t vram_bytes = header[1];
    if (reg_bytes > VF3_PVR2_REG_SIZE || vram_bytes > VF3_PVR2_VRAM_SIZE) {
        fclose(f);
        return -1;
    }
    p->reg_bytes = reg_bytes;
    p->vram_bytes = vram_bytes;
    if (fread(p->regs, 1, reg_bytes, f) != reg_bytes) { fclose(f); return -1; }
    if (vram_bytes && fread(p->vram, 1, vram_bytes, f) != vram_bytes) { fclose(f); return -1; }
    fclose(f);
    vf3_pvr2_read_config(p);
    return 0;
}

/* The register file is a byte array; its 32-bit registers are little-endian. */
static uint32_t reg32(const vf3_pvr2 *p, unsigned off)
{
    const uint8_t *b = (const uint8_t *)p->regs;
    if (off + 4 > p->reg_bytes) return 0;
    return (uint32_t)b[off] | ((uint32_t)b[off + 1] << 8) |
           ((uint32_t)b[off + 2] << 16) | ((uint32_t)b[off + 3] << 24);
}

void vf3_pvr2_read_config(vf3_pvr2 *p)
{
    p->pack_mode = reg32(p, REG_FB_W_CTRL) & 7u;
    /* the line stride counts units of eight bytes */
    p->fb_stride = (reg32(p, REG_FB_W_LINESTRIDE) & 0x1FFu) * 8u;
    p->fb_base = reg32(p, REG_FB_W_SOF1);
    const uint32_t xclip = reg32(p, REG_FB_X_CLIP);
    const uint32_t yclip = reg32(p, REG_FB_Y_CLIP);
    p->clip_x0 = xclip & 0x7FFu;
    p->clip_x1 = (xclip >> 16) & 0x7FFu;
    p->clip_y0 = yclip & 0x7FFu;
    p->clip_y1 = (yclip >> 16) & 0x7FFu;
    if (p->clip_x1 >= VF3_PVR2_WIDTH) p->clip_x1 = VF3_PVR2_WIDTH - 1;
    if (p->clip_y1 >= VF3_PVR2_HEIGHT) p->clip_y1 = VF3_PVR2_HEIGHT - 1;
    p->fb_width = p->clip_x1 - p->clip_x0 + 1u;
    p->fb_height = p->clip_y1 - p->clip_y0 + 1u;
    p->alpha_ref = reg32(p, REG_PT_ALPHA_REF) & 0xFFu;
    p->ta_ol_base = reg32(p, REG_TA_OL_BASE);
    p->ta_isp_base = reg32(p, REG_TA_ISP_BASE);
}

void vf3_pvr2_ta_push(vf3_pvr2 *p, uint32_t word)
{
    ++p->stats.words;
    ++p->stats.classes[(word >> 29) & 7u];
    if (p->ta_words == p->ta_cap) {
        p->ta_cap = p->ta_cap ? 2 * p->ta_cap : 4096;
        uint32_t *ta = realloc(p->ta, (size_t)p->ta_cap * sizeof *p->ta);
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
    p->stats.triangles = 0;
    p->stats.textured = 0;
    p->ta_words = 0;
}

/* The VRAM's 64-bit bus interleaves the two banks every 32 bits, so a
 * linear address does not land where it looks like it does.  This is the
 * *guest's* mapping of the VRAM window; the TA's textures are not interleaved
 * (see the file's header). */
static uint32_t vram_map(uint32_t offset)
{
    const uint32_t bank_bit = 0x400000u;
    const uint32_t mask = VF3_PVR2_VRAM_SIZE - 1u;
    const uint32_t static_bits = mask - (bank_bit * 2u - 1u) + 3u;
    const uint32_t offset_bits = (bank_bit - 1u) & ~3u;
    const uint32_t bank = (offset & bank_bit) / bank_bit;
    uint32_t rv = offset & static_bits;
    rv |= (offset & offset_bits) * 2u;
    rv |= bank * 4u;
    return rv & mask;
}

void vf3_pvr2_vram_write(vf3_pvr2 *p, uint32_t addr, uint32_t value)
{
    if (!p->vram) return;
    const uint32_t off = vram_map(addr & (VF3_PVR2_VRAM_SIZE - 1u));
    p->vram[off] = (uint8_t)(value >> 24);
    p->vram[off + 1] = (uint8_t)(value >> 16);
    p->vram[off + 2] = (uint8_t)(value >> 8);
    p->vram[off + 3] = (uint8_t)value;
}

/* ---------------------------------------------------------------- the rasteriser */

/* A vertex as the rasteriser works with it: the position, the texture
 * coordinates and the two colours, all as floats in 0..1. */
typedef struct {
    float x, y;          /* the screen position */
    float z;             /* 1/w: the depth */
    float u, v;          /* the texture coordinates */
    float r, g, b, a;    /* the base colour */
    float orr, og, ob, oa; /* the offset colour */
} rvertex;

/* The float-to-u8 conversion the hardware does: the value is clamped to the
 * 0..1 range and scaled by 255, with the fraction dropped. */
static uint8_t float_to_u8(float v)
{
    if (!(v == v)) return 255;         /* a NaN reads as white */
    if (v < 0.0f) v = 0.0f;
    if (v > 1.0f) v = 1.0f;
    return (uint8_t)(v * 255.0f);
}

/* The colour as the frame buffer's 5-6-5: rounded to the nearest level, the
 * way the reference's pixels sit (a plain shift lands one level low). */
static uint16_t pack565(float r, float g, float b)
{
    const uint32_t r5 = ((uint32_t)float_to_u8(r) * 31u + 127u) / 255u;
    const uint32_t g6 = ((uint32_t)float_to_u8(g) * 63u + 127u) / 255u;
    const uint32_t b5 = ((uint32_t)float_to_u8(b) * 31u + 127u) / 255u;
    return (uint16_t)(r5 << 11 | g6 << 5 | b5);
}

/* The texture's size, address and format, from the TSP and the texture
 * control word. */
typedef struct {
    uint32_t addr;       /* the texture's address in the VRAM, in bytes */
    uint32_t width, height;
    uint32_t bcx, bcy;   /* the log2 of the width and the height */
    uint32_t format;     /* the control word's PixelFmt */
    uint32_t bpp;        /* the bytes per texel */
    int textured;
    int clamp_u, clamp_v, flip_u, flip_v;
    uint32_t shad_instr;
    int ignore_alpha;
    int vq;              /* the texture is vector-quantised */
    uint32_t data_addr;  /* the quantised data, past the codebook */
    int mip;             /* the texture carries a mipmap chain */
    uint32_t filter;     /* 0: point, 1: bilinear, 2/3: trilinear */
    uint32_t mip_texels; /* the texels in front of the largest level */
    int linear;          /* scan order: rows follow each other, no twiddle */
    uint32_t stride;     /* the linear row length in texels (0: the width) */
    uint32_t pal_base;   /* the first palette entry of a palette texture */
} texinfo;

/* A vector-quantised texture keeps a codebook of 256 entries in front of it:
 * every entry holds the four texels of a two by two block, and the texture's
 * own data is one byte per block - the index into the codebook. */
#define VF3_VQ_CODEBOOK_SIZE 2048u
#define VF3_VQ_CODEBOOK_ENTRY 8u

static void read_texture(const vf3_pvr2 *p, const vf3_ta_prim *prim, texinfo *t)
{
    const uint32_t tsp = prim->param.tsp;
    const uint32_t tcw = prim->param.tcw;
    memset(t, 0, sizeof *t);
    const uint32_t tex_control = reg32(p, 0xE4u);
    t->width = 8u << ((tsp >> 3) & 7u);
    t->height = 8u << (tsp & 7u);
    t->bcx = 3u + ((tsp >> 3) & 7u);
    t->bcy = 3u + (tsp & 7u);
    /* the address is in units of eight bytes */
    t->addr = ((tcw & 0x1FFFFFu) << 3) & (VF3_PVR2_VRAM_SIZE - 1u);
    t->format = (tcw >> 27) & 7u;
    /* bit 30 marks a vector-quantised texture: the codebook sits at the
     * texture's address and the quantised data follows it */
    t->vq = ((tcw >> 30) & 1u) != 0;
    t->mip = (int)((tcw >> 31) & 1u);
    t->filter = (tsp >> 13) & 3u;
    t->linear = t->vq ? 0 : (int)((tcw >> 26) & 1u);
    t->pal_base = 0;
    if (t->format == 5 || t->format == 6) {
        t->linear = 0;
        const uint32_t sel = (tcw >> 21) & 0x3Fu;
        t->pal_base = (t->format == 5) ? (sel << 4) : ((sel & 0x30u) << 4);
    }
    t->stride = 0;
    if (t->linear && ((tcw >> 25) & 1u))
        t->stride = (tex_control & 0x1Fu) * 32u;
    t->data_addr = t->vq ? (t->addr + VF3_VQ_CODEBOOK_SIZE) : t->addr;
    if (t->mip && !t->linear) {
        /* the chain is stored smallest level first; the largest level sits
         * after the others.  Offsets in texels (bytes for a quantised one):
         * 3 + 1 + 4 + ... + 4^(k-1), and 1 + 1 + 4 + ... for the codebook's
         * index bytes, k being the log2 of the width. */
        const uint32_t k = t->bcx;
        uint32_t off = 0;
        if (t->vq) {
            off = 1;
            for (uint32_t j = 1; j < k; ++j) off += 1u << (2u * (j - 1u));
            t->data_addr += off;
        } else {
            off = 3;
            for (uint32_t j = 0; j < k; ++j) off += 1u << (2u * j);
            t->mip_texels = off;
        }
    }
    switch (t->format) {
    case 0: t->bpp = 2; break;   /* ARGB1555 */
    case 1: t->bpp = 2; break;   /* RGB565 */
    case 2: t->bpp = 2; break;   /* ARGB4444 */
    case 4: t->bpp = 2; break;   /* the bump map */
    case 5: t->bpp = 1; break;   /* the 4 bit palette */
    case 6: t->bpp = 1; break;   /* the 8 bit palette */
    default: t->bpp = 2; break;  /* YUV and the reserved format */
    }
    t->textured = vf3_ta_texture(prim->param.pcw) != 0;
    if (getenv("VF3_PVR_DEBUG") && t->textured)
        fprintf(stderr, "tex fmt %u vq %d mip %d lin %d %ux%u tcw %08x tsp %08x\n",
                t->format, t->vq, t->mip, t->linear, t->width, t->height, tcw, tsp, t->addr);
    if (getenv("VF3_PVR_DEBUG2")) fprintf(stderr, "col %u face %.2f %.2f %.2f %.2f off %d\n", vf3_ta_coltype(prim->param.pcw), prim->param.face[0], prim->param.face[1], prim->param.face[2], prim->param.face[3], (prim->param.pcw >> 2) & 1);
    t->clamp_u = (tsp >> 16) & 1u;
    t->clamp_v = (tsp >> 15) & 1u;
    t->flip_u = (tsp >> 18) & 1u;
    t->flip_v = (tsp >> 17) & 1u;
    t->shad_instr = (tsp >> 6) & 3u;
    t->ignore_alpha = (tsp >> 19) & 1u;
}

/* The Dreamcast's textures are stored "twiddled": the texels of a texture do
 * not follow each other in the VRAM in the order the picture does.  The bits
 * of the two coordinates are interleaved, the smaller dimension's bits first,
 * so that a texture's rows are scattered through its block of memory.
 *
 * This is the arithmetic the hardware does (and the reference emulator
 * reproduces): the address of the texel (x, y) of a texture whose width and
 * height are 2^bcx and 2^bcy is the sum of two contributions, one from the
 * x bits and one from the y bits. */
static uint32_t twiddle_slow(uint32_t x, uint32_t y, uint32_t x_sz, uint32_t y_sz)
{
    uint32_t rv = 0;
    uint32_t sh = 0;
    x_sz >>= 1;
    y_sz >>= 1;
    while (x_sz != 0 || y_sz != 0) {
        if (y_sz != 0) {
            rv |= (y & 1u) << sh;
            y_sz >>= 1;
            y >>= 1;
            sh++;
        }
        if (x_sz != 0) {
            rv |= (x & 1u) << sh;
            x_sz >>= 1;
            x >>= 1;
            sh++;
        }
    }
    return rv;
}

/* The index of the texel (x, y) inside its texture. */
static uint32_t twiddle_index(uint32_t x, uint32_t y, uint32_t bcx, uint32_t bcy)
{
    return twiddle_slow(x, 0, 1024, 1u << bcy) +
           twiddle_slow(0, y, 1u << bcx, 1024);
}

/* The colour of one texel, from the sixteen bits the texture stores. */
static uint32_t decode_texel(uint32_t format, uint32_t v)
{
    switch (format) {
    case 0: {   /* ARGB1555 */
        const uint32_t r = (v >> 10) & 0x1Fu;
        const uint32_t g = (v >> 5) & 0x1Fu;
        const uint32_t b = v & 0x1Fu;
        const uint32_t a = (v >> 15) & 1u;
        return (a ? 0xFF000000u : 0u) | ((r << 3 | r >> 2) << 16) | ((g << 3 | g >> 2) << 8) |
               (b << 3 | b >> 2);
    }
    case 1: {   /* RGB565 */
        const uint32_t r = (v >> 11) & 0x1Fu;
        const uint32_t g = (v >> 5) & 0x3Fu;
        const uint32_t b = v & 0x1Fu;
        return 0xFF000000u | ((r << 3 | r >> 2) << 16) | ((g << 2 | g >> 4) << 8) |
               (b << 3 | b >> 2);
    }
    case 2: {   /* ARGB4444 */
        const uint32_t a = (v >> 12) & 0xFu;
        const uint32_t r = (v >> 8) & 0xFu;
        const uint32_t g = (v >> 4) & 0xFu;
        const uint32_t b = v & 0xFu;
        return (a << 24) | ((r << 4 | r) << 16) | ((g << 4 | g) << 8) | (b << 4 | b);
    }
    default:
        return 0xFFFFFFFFu;
    }
}

/* A flipped axis mirrors every other repeat of the texture. */
static int mirror_coord(int c, int size, int flip)
{
    if (!flip) return c;
    int m = c % (2 * size);
    if (m < 0) m += 2 * size;
    return m >= size ? 2 * size - 1 - m : m;
}

/* One texel, as 0xAARRGGBB.  The texels are twiddled in the VRAM (see
 * twiddle_index), and the texture's address is in units of eight bytes.
 *
 * A vector-quantised texture is different: the twiddle picks a two by two
 * block, one byte of the texture says which of the codebook's 256 entries
 * that block is, and the entry holds the block's four texels. */
static uint32_t sample_texel(const vf3_pvr2 *p, const texinfo *t, int x, int y)
{
    if (!p->vram || t->width == 0 || t->height == 0) return 0xFF000000u;
    if (t->clamp_u) {
        if (x < 0) x = 0;
        if (x >= (int)t->width) x = (int)t->width - 1;
    } else {
        x %= (int)t->width;
        if (x < 0) x += (int)t->width;
    }
    if (t->clamp_v) {
        if (y < 0) y = 0;
        if (y >= (int)t->height) y = (int)t->height - 1;
    } else {
        y %= (int)t->height;
        if (y < 0) y += (int)t->height;
    }

    if (t->vq) {
        /* the twiddle picks the block, the block's byte picks the entry */
        const uint32_t block = twiddle_index((uint32_t)(x & ~1), (uint32_t)(y & ~1),
                                             t->bcx, t->bcy) >> 2;
        const uint32_t index = t->data_addr + block;
        if (index >= VF3_PVR2_VRAM_SIZE) return 0xFF000000u;
        const uint32_t code = p->vram[index];
        const uint32_t entry = t->addr + code * VF3_VQ_CODEBOOK_ENTRY;
        const uint32_t slot = (uint32_t)((x & 1) * 2 + (y & 1));
        if (entry + slot * 2u + 2u > VF3_PVR2_VRAM_SIZE) return 0xFF000000u;
        const uint32_t v = ((uint32_t)p->vram[entry + slot * 2u + 1u] << 8) |
                           p->vram[entry + slot * 2u];
        return decode_texel(t->format, v);
    }

    uint32_t index;
    if (t->linear)
        index = (uint32_t)y * (t->stride ? t->stride : t->width) + (uint32_t)x;
    else
        index = twiddle_index((uint32_t)x, (uint32_t)y, t->bcx, t->bcy);
    index += t->mip_texels;
    if (t->format == 5 || t->format == 6) {
        uint32_t pi;
        if (t->format == 5) {
            const uint32_t at = t->addr + (index >> 1);
            if (at >= VF3_PVR2_VRAM_SIZE) return 0xFF000000u;
            pi = (index & 1u) ? (p->vram[at] >> 4) : (p->vram[at] & 0xFu);
        } else {
            const uint32_t at = t->addr + index;
            if (at >= VF3_PVR2_VRAM_SIZE) return 0xFF000000u;
            pi = p->vram[at];
        }
        const uint32_t e = reg32(p, 0x1000u + (t->pal_base + pi) * 4u);
        switch (reg32(p, 0x108u) & 3u) {
        case 0: return decode_texel(0, e & 0xFFFFu);
        case 1: return decode_texel(1, e & 0xFFFFu);
        case 2: return decode_texel(2, e & 0xFFFFu);
        default: return e;
        }
    }
    const uint32_t base = t->addr + index * t->bpp;
    if (base + t->bpp > VF3_PVR2_VRAM_SIZE) return 0xFF000000u;
    const uint32_t v = ((uint32_t)p->vram[base + 1] << 8) | p->vram[base];
    return decode_texel(t->format, v);
}

/* A texel through the texture's addressing: flip, clamp or wrap. */
static uint32_t texel_at(const vf3_pvr2 *p, const texinfo *t, int x, int y)
{
    x = mirror_coord(x, (int)t->width, t->flip_u && !t->clamp_u);
    y = mirror_coord(y, (int)t->height, t->flip_v && !t->clamp_v);
    return sample_texel(p, t, x, y);
}

/* The texture at (u, v).  Point sampling takes the texel the coordinate
 * lands in; the bilinear filters weigh the four texels around it. */
static uint32_t sample_filtered(const vf3_pvr2 *p, const texinfo *t, float u, float v)
{
    const float fu = u * (float)t->width;
    const float fv = v * (float)t->height;
    if (t->filter == 0)
        return texel_at(p, t, (int)floorf(fu), (int)floorf(fv));
    const float bu = fu - 0.5f, bv = fv - 0.5f;
    const int x0 = (int)floorf(bu), y0 = (int)floorf(bv);
    const float ax = bu - (float)x0, ay = bv - (float)y0;
    const uint32_t c[4] = {
        texel_at(p, t, x0, y0), texel_at(p, t, x0 + 1, y0),
        texel_at(p, t, x0, y0 + 1), texel_at(p, t, x0 + 1, y0 + 1)
    };
    const float wgt[4] = {(1 - ax) * (1 - ay), ax * (1 - ay), (1 - ax) * ay, ax * ay};
    uint32_t out = 0;
    for (int sh = 0; sh < 32; sh += 8) {
        float acc = 0.0f;
        for (int k = 0; k < 4; ++k) acc += wgt[k] * (float)((c[k] >> sh) & 0xFFu);
        out |= (uint32_t)(acc + 0.5f) << sh;
    }
    return out;
}

/* The primitive's own settings, taken out of the parameter block once. */
typedef struct {
    uint32_t fog_ctrl;   /* 0: table, 1: per vertex, 2: none, 3: table (alpha only) */
    int textured;
    int gouraud;
    int offset;
    unsigned depth_mode;
    int z_write_dis;
    unsigned cull_mode;
    unsigned shad_instr;
    unsigned src_instr, dst_instr;
    int use_alpha;
    int colour_clamp;
    int ignore_alpha;
    unsigned list_type;
    uint32_t alpha_ref;
} primstate;

static void read_prim(const vf3_ta_prim *prim, const vf3_pvr2 *p, primstate *s)
{
    const uint32_t pcw = prim->param.pcw;
    const uint32_t isp = prim->param.isp_tsp;
    const uint32_t tsp = prim->param.tsp;
    memset(s, 0, sizeof *s);
    s->textured = vf3_ta_texture(pcw) != 0;
    s->gouraud = ((pcw >> 1) & 1u) != 0;
    s->offset = ((pcw >> 2) & 1u) != 0;
    s->depth_mode = (isp >> 29) & 7u;
    s->z_write_dis = ((isp >> 26) & 1u) != 0;
    s->cull_mode = (isp >> 27) & 3u;
    s->shad_instr = (tsp >> 6) & 3u;
    s->fog_ctrl = (tsp >> 22) & 3u;
    s->src_instr = (tsp >> 29) & 7u;
    s->dst_instr = (tsp >> 26) & 7u;
    s->use_alpha = ((tsp >> 20) & 1u) != 0;
    s->colour_clamp = ((tsp >> 21) & 1u) != 0;
    s->ignore_alpha = ((tsp >> 19) & 1u) != 0;
    s->list_type = prim->list_type;
    s->alpha_ref = p->alpha_ref;
}

/* The colour of a vertex: the packed colour, the float colour, or the face
 * colour scaled by the intensity.  The intensity does not touch the alpha. */
static void vertex_colour(const vf3_ta_prim *prim, const vf3_ta_vertex *v,
                           float *r, float *g, float *b, float *a)
{
    const unsigned col = vf3_ta_coltype(prim->param.pcw);
    if (col == 0) {
        const uint32_t c = v->colour;
        *r = (float)((c >> 16) & 0xFFu) / 255.0f;
        *g = (float)((c >> 8) & 0xFFu) / 255.0f;
        *b = (float)(c & 0xFFu) / 255.0f;
        *a = (float)((c >> 24) & 0xFFu) / 255.0f;
        return;
    }
    if (col == 1) {
        /* the float colour is kept as a packed colour by the decoder */
        const uint32_t c = v->colour;
        *r = (float)((c >> 16) & 0xFFu) / 255.0f;
        *g = (float)((c >> 8) & 0xFFu) / 255.0f;
        *b = (float)(c & 0xFFu) / 255.0f;
        *a = (float)((c >> 24) & 0xFFu) / 255.0f;
        return;
    }
    /* the intensity colour: the face colour scaled by the intensity */
    const float *face = prim->param.face;
    const uint32_t sat = float_to_u8(v->intensity);
    *r = face[1] * (float)sat / 256.0f;
    *g = face[2] * (float)sat / 256.0f;
    *b = face[3] * (float)sat / 256.0f;
    *a = face[0];
}

/* The offset colour of a vertex: the same, with the offset face colour. */
static void vertex_offset_colour(const vf3_ta_prim *prim, const vf3_ta_vertex *v,
                                  float *r, float *g, float *b, float *a)
{
    const unsigned col = vf3_ta_coltype(prim->param.pcw);
    if (col == 0 || col == 1) {
        const uint32_t c = v->offset_colour;
        *r = (float)((c >> 16) & 0xFFu) / 255.0f;
        *g = (float)((c >> 8) & 0xFFu) / 255.0f;
        *b = (float)(c & 0xFFu) / 255.0f;
        *a = (float)((c >> 24) & 0xFFu) / 255.0f;
        return;
    }
    const float *face = prim->param.face;
    const uint32_t sat = float_to_u8(v->offset_intensity);
    *r = face[5] * (float)sat / 256.0f;
    *g = face[6] * (float)sat / 256.0f;
    *b = face[7] * (float)sat / 256.0f;
    *a = face[4];
}

/* The depth test.  The depth buffer holds the interpolated 1/w, so the
 * nearest surface is the largest; the ISP's comparison is on that value, and
 * the game asks for "greater or equal" on the opaque list. */
static int depth_passes(unsigned mode, float frag, float stored)
{
    switch (mode) {
    case 0: return 0;                    /* never */
    case 1: return frag < stored;        /* less */
    case 2: return frag == stored;       /* equal */
    case 3: return frag <= stored;       /* less or equal */
    case 4: return frag > stored;        /* greater */
    case 5: return frag != stored;       /* not equal */
    case 6: return frag >= stored;       /* greater or equal */
    default: return 1;                   /* always */
    }
}

/* The blend: the source factor comes from the TSP's SrcInstr and the
 * destination factor from its DstInstr.  The framebuffer holds RGB565, so
 * the colours are read back as the 5-6-5 the hardware would have. */
static void blend(uint16_t *dst, float sr, float sg, float sb, float sa,
                  unsigned src_instr, unsigned dst_instr)
{
    const uint32_t d = *dst;
    const float dr = (float)(((d >> 11) & 0x1Fu) * 255u / 31u) / 255.0f;
    const float dg = (float)(((d >> 5) & 0x3Fu) * 255u / 63u) / 255.0f;
    const float db = (float)((d & 0x1Fu) * 255u / 31u) / 255.0f;
    const float da = 1.0f;

    float sf[4], df[4];
    switch (src_instr) {
    case 0: sf[0] = sf[1] = sf[2] = sf[3] = 0.0f; break;
    case 1: sf[0] = sf[1] = sf[2] = sf[3] = 1.0f; break;
    case 2: sf[0] = dr; sf[1] = dg; sf[2] = db; sf[3] = da; break;
    case 3: sf[0] = 1.0f - dr; sf[1] = 1.0f - dg; sf[2] = 1.0f - db; sf[3] = 1.0f - da; break;
    case 4: sf[0] = sf[1] = sf[2] = sa; sf[3] = sa; break;
    case 5: sf[0] = sf[1] = sf[2] = 1.0f - sa; sf[3] = 1.0f - sa; break;
    case 6: sf[0] = sf[1] = sf[2] = da; sf[3] = da; break;
    default: sf[0] = sf[1] = sf[2] = 1.0f - da; sf[3] = 1.0f - da; break;
    }
    switch (dst_instr) {
    case 0: df[0] = df[1] = df[2] = df[3] = 0.0f; break;
    case 1: df[0] = df[1] = df[2] = df[3] = 1.0f; break;
    case 2: df[0] = sr; df[1] = sg; df[2] = sb; df[3] = sa; break;
    case 3: df[0] = 1.0f - sr; df[1] = 1.0f - sg; df[2] = 1.0f - sb; df[3] = 1.0f - sa; break;
    case 4: df[0] = df[1] = df[2] = sa; df[3] = sa; break;
    case 5: df[0] = df[1] = df[2] = 1.0f - sa; df[3] = 1.0f - sa; break;
    case 6: df[0] = df[1] = df[2] = da; df[3] = da; break;
    default: df[0] = df[1] = df[2] = 1.0f - da; df[3] = 1.0f - da; break;
    }
    const float r = sr * sf[0] + dr * df[0];
    const float g = sg * sf[1] + dg * df[1];
    const float b = sb * sf[2] + db * df[2];
    const float a = sa * sf[3] + da * df[3];
    *dst = pack565(r, g, b);
}

/* The fog coefficient for a pixel of depth 1/w = z.  The density register
 * holds a mantissa (bits 15-8, over 128) and a signed four bit exponent; the
 * product with w picks one of the table's 128 entries (sixteen to the octave)
 * and the entry's second byte is blended towards the next entry's by the
 * fraction.  The exponent's offset is an empirical fit: the reference's sky
 * (w = 301, fog share 0.457) needs a density between 2^-4 and 2^-3 times the
 * mantissa for 0x890d. */
static float fog_coefficient(const vf3_pvr2 *p, float z)
{
    const uint32_t dens = reg32(p, 0xB8u);
    const int e = (((int)((dens & 0xFu) << 28)) >> 28) - 1;
    const float density = (float)((dens >> 8) & 0xFFu) / 128.0f * ldexpf(1.0f, e);
    float w = z > 0.0f ? 1.0f / z : 255.0f;
    float zz = w * density;
    if (zz < 1.0f) zz = 1.0f;
    if (zz > 255.99998f) zz = 255.99998f;
    const int ex = (int)floorf(log2f(zz));
    const float m = zz * 16.0f / ldexpf(1.0f, ex) - 16.0f;
    int idx = (int)m + ex * 16;
    if (idx > 127) idx = 127;
    const float frac = m - floorf(m);
    const uint32_t entry = reg32(p, 0x200u + (uint32_t)idx * 4u);
    const float hi = (float)((entry >> 8) & 0xFFu);
    const float lo = (float)(entry & 0xFFu);
    /* the table holds the *visibility*: the fog's share is what is left */
    return 1.0f - (hi * (1.0f - frac) + lo * frac) / 255.0f;
}

/* Draw one triangle. */
static void draw_triangle(vf3_pvr2 *p, const rvertex *a, const rvertex *b,
                          const rvertex *c, const texinfo *t, const primstate *s)
{
    float minx = a->x, maxx = a->x, miny = a->y, maxy = a->y;
    const rvertex *vs[3] = {a, b, c};
    for (int i = 1; i < 3; ++i) {
        if (vs[i]->x < minx) minx = vs[i]->x;
        if (vs[i]->x > maxx) maxx = vs[i]->x;
        if (vs[i]->y < miny) miny = vs[i]->y;
        if (vs[i]->y > maxy) maxy = vs[i]->y;
    }
    int x0 = (int)minx, x1 = (int)maxx + 1, y0 = (int)miny, y1 = (int)maxy + 1;
    if (x0 < (int)p->clip_x0) x0 = (int)p->clip_x0;
    if (y0 < (int)p->clip_y0) y0 = (int)p->clip_y0;
    if (x1 > (int)p->clip_x1 + 1) x1 = (int)p->clip_x1 + 1;
    if (y1 > (int)p->clip_y1 + 1) y1 = (int)p->clip_y1 + 1;
    if (x0 >= x1 || y0 >= y1) return;

    const float area = (b->x - a->x) * (c->y - a->y) - (b->y - a->y) * (c->x - a->x);
    if (area == 0.0f) return;
    const float inv = 1.0f / area;

    for (int y = y0; y < y1; ++y) {
        for (int x = x0; x < x1; ++x) {
            const float px = (float)x + 0.5f, py = (float)y + 0.5f;
            const float w0 = ((b->x - a->x) * (py - a->y) - (b->y - a->y) * (px - a->x)) * inv;
            const float w1 = ((c->x - b->x) * (py - b->y) - (c->y - b->y) * (px - b->x)) * inv;
            const float w2 = 1.0f - w0 - w1;
            if (w0 < 0.0f || w1 < 0.0f || w2 < 0.0f) continue;
            /* the barycentric weights: w1 belongs to a, w2 to b, w0 to c */
            const float l0 = w1, l1 = w2, l2 = w0;
            const float z = l0 * a->z + l1 * b->z + l2 * c->z;
            if (z <= 0.0f) continue;
            const uint32_t index = (uint32_t)y * VF3_PVR2_WIDTH + (uint32_t)x;
            if (!depth_passes(s->depth_mode, z, p->depth[index])) continue;

            /* the colour */
            float cr, cg, cb, ca;
            if (s->gouraud) {
                cr = l0 * a->r + l1 * b->r + l2 * c->r;
                cg = l0 * a->g + l1 * b->g + l2 * c->g;
                cb = l0 * a->b + l1 * b->b + l2 * c->b;
                ca = l0 * a->a + l1 * b->a + l2 * c->a;
            } else {
                cr = a->r; cg = a->g; cb = a->b; ca = a->a;
            }
            float orr = 0.0f, og = 0.0f, ob = 0.0f;
            if (s->offset) {
                if (s->gouraud) {
                    orr = l0 * a->orr + l1 * b->orr + l2 * c->orr;
                    og = l0 * a->og + l1 * b->og + l2 * c->og;
                    ob = l0 * a->ob + l1 * b->ob + l2 * c->ob;
                } else {
                    orr = a->orr; og = a->og; ob = a->ob;
                }
            }

            if (s->textured && t->textured) {
                /* the texture coordinate, interpolated with perspective */
                const float zz = z != 0.0f ? z : 1.0f;
                const float u = (l0 * a->u * a->z + l1 * b->u * b->z + l2 * c->u * c->z) / zz;
                const float v = (l0 * a->v * a->z + l1 * b->v * b->z + l2 * c->v * c->z) / zz;
                const uint32_t texel = sample_filtered(p, t, u, v);
                static int raw_cache = -1;
                if (raw_cache < 0) raw_cache = getenv("VF3_PVR_RAWTEX") != NULL;
                const int raw = raw_cache;
                const float tr = (float)((texel >> 16) & 0xFFu) / 255.0f;
                const float tg = (float)((texel >> 8) & 0xFFu) / 255.0f;
                const float tb = (float)(texel & 0xFFu) / 255.0f;
                const float ta = s->ignore_alpha ? 1.0f : (float)((texel >> 24) & 0xFFu) / 255.0f;
                switch (raw ? 0u : s->shad_instr) {
                case 0:                 /* the texture replaces the colour */
                    cr = tr; cg = tg; cb = tb; ca = ta;
                    break;
                case 1:                 /* the texture modulates the colour */
                    cr *= tr; cg *= tg; cb *= tb; ca = ta;
                    break;
                case 2:                 /* the texture is mixed in by its alpha */
                    cr = cr + (tr - cr) * ta;
                    cg = cg + (tg - cg) * ta;
                    cb = cb + (tb - cb) * ta;
                    ca = ta;
                    break;
                default:                /* the texture modulates everything */
                    cr *= tr; cg *= tg; cb *= tb; ca *= ta;
                    break;
                }
                if (s->offset) {
                    cr += orr; cg += og; cb += ob;
                }
            }
            if (s->fog_ctrl == 0 || s->fog_ctrl == 1) {
                float coef;
                uint32_t fc;
                if (s->fog_ctrl == 0) {
                    coef = fog_coefficient(p, z);
                    fc = reg32(p, 0xB0u);
                } else {
                    coef = l0 * a->oa + l1 * b->oa + l2 * c->oa;
                    fc = reg32(p, 0xB4u);
                }
                cr += ((float)((fc >> 16) & 0xFFu) / 255.0f - cr) * coef;
                cg += ((float)((fc >> 8) & 0xFFu) / 255.0f - cg) * coef;
                cb += ((float)(fc & 0xFFu) / 255.0f - cb) * coef;
            }
            if (s->colour_clamp) {
                cr = cr < 0.0f ? 0.0f : (cr > 1.0f ? 1.0f : cr);
                cg = cg < 0.0f ? 0.0f : (cg > 1.0f ? 1.0f : cg);
                cb = cb < 0.0f ? 0.0f : (cb > 1.0f ? 1.0f : cb);
                ca = ca < 0.0f ? 0.0f : (ca > 1.0f ? 1.0f : ca);
            }

            /* the punch-through list tests the alpha against the register */
            if (s->list_type == VF3_TA_LIST_PUNCH_THROUGH) {
                if (float_to_u8(ca) < s->alpha_ref) continue;
            }

            uint32_t out = ((uint32_t)float_to_u8(ca) << 24) |
                           ((uint32_t)float_to_u8(cr) << 16) |
                           ((uint32_t)float_to_u8(cg) << 8) |
                           (uint32_t)float_to_u8(cb);
            if (s->src_instr != 1 || s->dst_instr != 0) {
                uint16_t dst = p->fb[index];
                blend(&dst, cr, cg, cb, ca, s->src_instr, s->dst_instr);
                p->fb[index] = dst;
            } else {
                p->fb[index] = pack565(cr, cg, cb);
            }
            if (!s->z_write_dis) p->depth[index] = z;
            ++p->stats.pixels;
        }
    }
    ++p->stats.triangles;
}

/* Build the rasteriser's vertex from the decoder's. */
static void make_vertex(const vf3_ta_prim *prim, const vf3_ta_vertex *src,
                        rvertex *dst)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->u = src->u;
    dst->v = src->v;
    vertex_colour(prim, src, &dst->r, &dst->g, &dst->b, &dst->a);
    vertex_offset_colour(prim, src, &dst->orr, &dst->og, &dst->ob, &dst->oa);
}

/* Draw the strips of a polygon: a strip of n vertices is the triangles
 * (0,1,2), (1,2,3), ... */
static void draw_polygon(vf3_pvr2 *p, const vf3_ta_prim *prim,
                         const vf3_ta_vertex *verts)
{
    if (prim->count < 3) return;
    texinfo t;
    primstate s;
    read_texture(p, prim, &t);
    read_prim(prim, p, &s);
    if (getenv("VF3_PVR_DEBUG3"))
        fprintf(stderr, "prim list %u fmt %u %ux%u col %u shad %u src %u dst %u ua %d gour %d off %d v0 %08x oc %08x isp %08x\n",
                prim->list_type, t.format, t.width, t.height, vf3_ta_coltype(prim->param.pcw), s.shad_instr,
                s.src_instr, s.dst_instr, s.use_alpha, s.gouraud, s.offset, verts[0].colour,
                verts[0].offset_colour, prim->param.isp_tsp);

    rvertex *rv = malloc((size_t)prim->count * sizeof *rv);
    if (!rv) return;
    for (unsigned i = 0; i < prim->count; ++i)
        make_vertex(prim, &verts[i], &rv[i]);

    unsigned start = 0;
    for (unsigned i = 0; i < prim->count; ++i) {
        if (!verts[i].end_strip && i + 1 < prim->count) continue;
        const unsigned n = i - start + 1;
        for (unsigned k = 2; k < n; ++k)
            draw_triangle(p, &rv[start + k - 2], &rv[start + k - 1], &rv[start + k], &t, &s);
        start = i + 1;
    }
    free(rv);
}

/* The sprite's fourth corner: the hardware works out the plane through the
 * other three and puts the corner on it, with the texture coordinates that go
 * with it.  The reference does the same; this is its arithmetic. */
static void sprite_plane(rvertex *base)
{
    const rvertex *A = &base[2];
    const rvertex *B = &base[3];
    const rvertex *C = &base[1];
    rvertex *P = &base[0];
    const float AC_x = C->x - A->x, AC_y = C->y - A->y, AC_z = C->z - A->z;
    const float AB_x = B->x - A->x, AB_y = B->y - A->y, AB_z = B->z - A->z;
    const float AP_x = P->x - A->x, AP_y = P->y - A->y;
    const float k3 = AC_x * AB_y - AC_y * AB_x;
    if (k3 == 0.0f) return;
    const float k2 = (AP_x * AB_y - AP_y * AB_x) / k3;
    float k1 = 0.0f;
    if (AB_x == 0.0f) {
        if (AB_y == 0.0f) return;
        k1 = (P->y - A->y - k2 * AC_y) / AB_y;
    } else {
        k1 = (P->x - A->x - k2 * AC_x) / AB_x;
    }
    P->z = A->z + k1 * AB_z + k2 * AC_z;
    P->u = A->u + k1 * (B->u - A->u) + k2 * (C->u - A->u);
    P->v = A->v + k1 * (B->v - A->v) + k2 * (C->v - A->v);
}

/* A sprite is a rectangle: the hardware turns the four corners into a
 * triangle strip in the order (x3,y3), (x2,y2), (x0,y0), (x1,y1). */
static void draw_sprite(vf3_pvr2 *p, const vf3_ta_prim *prim,
                        const vf3_ta_vertex *verts)
{
    if (prim->count < 4) return;
    texinfo t;
    primstate s;
    read_texture(p, prim, &t);
    read_prim(prim, p, &s);
    if (getenv("VF3_PVR_DEBUG3"))
        fprintf(stderr, "sprite list %u fmt %u %ux%u shad %u src %u dst %u ua %d ign %d col %08x off %08x tsp %08x\n",
                prim->list_type, t.format, t.width, t.height, s.shad_instr, s.src_instr, s.dst_instr, s.use_alpha, s.ignore_alpha, verts[0].colour, verts[0].offset_colour, prim->param.tsp);
    /* the sprite's cull mode is flipped by the hardware */
    s.cull_mode ^= 1;

    rvertex rv[4];
    /* the decoder keeps the corners in the order they are in the stream:
     * (x0,y0,z0), (x1,y1,z1), (x2,y2,z2), (x3,y3).  The hardware's strip is
     * (x3,y3), (x2,y2,z2), (x0,y0,z0), (x1,y1,z1). */
    make_vertex(prim, &verts[0], &rv[2]);
    make_vertex(prim, &verts[1], &rv[3]);
    make_vertex(prim, &verts[2], &rv[1]);
    make_vertex(prim, &verts[3], &rv[0]);
    sprite_plane(rv);
    if (getenv("VF3_PVR_DEBUG3"))
        for (int k = 0; k < 4; ++k)
            fprintf(stderr, "  rv%d x %.1f y %.1f z %g u %.3f v %.3f c %.2f %.2f %.2f %.2f\n", k, rv[k].x, rv[k].y, rv[k].z, rv[k].u, rv[k].v, rv[k].r, rv[k].g, rv[k].b, rv[k].a);

    draw_triangle(p, &rv[0], &rv[1], &rv[2], &t, &s);
    draw_triangle(p, &rv[1], &rv[2], &rv[3], &t, &s);
    if (getenv("VF3_PVR_DEBUG3"))
        fprintf(stderr, "  -> pixels %u depth_mode %u cull %u zwd %d\n", p->stats.pixels, s.depth_mode, s.cull_mode, s.z_write_dis);
}

unsigned vf3_pvr2_rasterise(vf3_pvr2 *p, const vf3_ta_list *list)
{
    if (!p->fb) return 0;
    memset(p->fb, 0, (size_t)VF3_PVR2_PIXELS * sizeof *p->fb);
    memset(p->depth, 0, (size_t)VF3_PVR2_PIXELS * sizeof *p->depth);
    p->stats.pixels = 0;
    p->stats.triangles = 0;
    p->stats.textured = 0;
    /* Intensity mode 2 has no face colour of its own: the TA keeps the one
     * the last intensity mode 1 header carried and scales that. */
    float last_face[8] = {0};
    for (unsigned i = 0; i < list->count; ++i) {
        const vf3_ta_prim *prim = &list->prims[i];
        vf3_ta_prim shared;
        if (!prim->is_modvol && vf3_ta_coltype(prim->param.pcw) == 2) {
            memcpy(last_face, prim->param.face, sizeof last_face);
        } else if (!prim->is_modvol && vf3_ta_coltype(prim->param.pcw) == 3) {
            shared = *prim;
            memcpy(shared.param.face, last_face, sizeof last_face);
            prim = &shared;
        }
        if (prim->is_modvol) continue;
        const vf3_ta_vertex *verts = list->verts + prim->vstart;
        if (prim->is_sprite) draw_sprite(p, prim, verts);
        else draw_polygon(p, prim, verts);
        if (vf3_ta_texture(prim->param.pcw)) ++p->stats.textured;
    }
    return p->stats.pixels;
}

unsigned vf3_pvr2_frame_end(vf3_pvr2 *p)
{
    if (!p->fb) return 0;
    memset(p->fb, 0, (size_t)VF3_PVR2_PIXELS * sizeof *p->fb);
    p->stats.pixels = 0;
    return 0;
}

const uint16_t *vf3_pvr2_framebuffer(const vf3_pvr2 *p)
{
    return p->fb;
}

/* One pixel as the host wants it: 0xAARRGGBB, out of the framebuffer's 5-6-5. */
uint32_t vf3_pvr2_pixel(const vf3_pvr2 *p, unsigned x, unsigned y)
{
    if (!p->fb || x >= VF3_PVR2_WIDTH || y >= VF3_PVR2_HEIGHT) return 0xFF000000u;
    const uint32_t v = p->fb[y * VF3_PVR2_WIDTH + x];
    const uint32_t r = ((v >> 11) & 0x1Fu) * 255u / 31u;
    const uint32_t g = ((v >> 5) & 0x3Fu) * 255u / 63u;
    const uint32_t b = (v & 0x1Fu) * 255u / 31u;
    return 0xFF000000u | (r << 16) | (g << 8) | b;
}
