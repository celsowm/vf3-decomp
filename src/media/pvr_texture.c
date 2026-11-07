#include "pvr_texture.h"

#include <stdint.h>

static uint32_t twiddled_index(uint32_t x, uint32_t y, uint32_t side)
{
    uint32_t index = 0;
    uint32_t bit = 0;
    while ((1u << bit) < side) {
        index |= ((y >> bit) & 1u) << (bit * 2u);
        index |= ((x >> bit) & 1u) << (bit * 2u + 1u);
        ++bit;
    }
    return index;
}

int vf3_pvr_texture_payload_size(const PolTextureDesc *desc, size_t *bytes_out)
{
    const uint8_t pixel_format = (uint8_t)(desc ? desc->raw_flags & 0xFFu : 0u);
    const uint8_t data_format = (uint8_t)(desc ? (desc->raw_flags >> 8) & 0xFFu : 0u);
    uint64_t pixels, bytes;
    if (!desc || !bytes_out || !desc->width || !desc->height ||
        pixel_format > 2u || desc->width != desc->height ||
        (desc->width & (desc->width - 1u)) != 0)
        return -1;
    pixels = (uint64_t)desc->width * desc->height;
    if (data_format == 1u) {
        bytes = pixels * 2u;
    } else if (data_format == 3u) {
        /* VQ stores a 256-entry 2x2 codebook followed by one byte per block. */
        bytes = 2048u + pixels / 4u;
    } else {
        return -1;
    }
    if (bytes > SIZE_MAX)
        return -1;
    *bytes_out = (size_t)bytes;
    return 0;
}

static uint8_t expand4(uint32_t value)
{
    return (uint8_t)((value << 4) | value);
}

static uint8_t expand5(uint32_t value)
{
    return (uint8_t)((value << 3) | (value >> 2));
}

static uint8_t expand6(uint32_t value)
{
    return (uint8_t)((value << 2) | (value >> 4));
}

static uint32_t decode_pixel(uint8_t format, uint16_t value)
{
    uint32_t a, r, g, b;
    switch (format) {
    case 0: /* ARGB1555. */
        a = (value & 0x8000u) ? 255u : 0u;
        r = expand5((value >> 10) & 31u);
        g = expand5((value >> 5) & 31u);
        b = expand5(value & 31u);
        break;
    case 1: /* RGB565. */
        a = 255u;
        r = expand5((value >> 11) & 31u);
        g = expand6((value >> 5) & 63u);
        b = expand5(value & 31u);
        break;
    case 2: /* ARGB4444. */
        a = expand4((value >> 12) & 15u);
        r = expand4((value >> 8) & 15u);
        g = expand4((value >> 4) & 15u);
        b = expand4(value & 15u);
        break;
    default:
        return 0;
    }
    return (a << 24) | (r << 16) | (g << 8) | b;
}

int vf3_pvr_texture_decode(const void *vtex_data, size_t tex_size,
                           const PolTextureDesc *desc, uint32_t *argb_out,
                           size_t pixel_capacity)
{
    const uint8_t *tex_data = (const uint8_t *)vtex_data;
    uint64_t pixel_count, byte_end;
    const uint8_t pixel_format = (uint8_t)(desc ? desc->raw_flags & 0xFFu : 0u);
    const uint8_t data_format = (uint8_t)(desc ? (desc->raw_flags >> 8) & 0xFFu : 0u);
    uint32_t width, height, side;
    size_t payload_size;
    if (!tex_data || !desc || !argb_out || !desc->width || !desc->height)
        return -1;
    if (vf3_pvr_texture_payload_size(desc, &payload_size) != 0)
        return -1;
    width = desc->width;
    height = desc->height;
    side = width;
    if ((side & (side - 1u)) != 0)
        return -1;
    pixel_count = (uint64_t)width * height;
    byte_end = (uint64_t)desc->data_offset + payload_size;
    if (pixel_count > SIZE_MAX || byte_end > tex_size)
        return -1;
    if ((size_t)pixel_count > pixel_capacity)
        return -2;

    for (uint32_t y = 0; y < height; ++y) {
        for (uint32_t x = 0; x < width; ++x) {
            uint16_t value;
            if (data_format == 3u) {
                const uint32_t block_index =
                    twiddled_index(x & ~1u, y & ~1u, side) >> 2;
                const size_t index_offset = (size_t)desc->data_offset +
                    2048u + block_index;
                const uint32_t code = tex_data[index_offset];
                const uint32_t slot = (x & 1u) * 2u + (y & 1u);
                const size_t source = (size_t)desc->data_offset + code * 8u +
                                      slot * 2u;
                value = (uint16_t)tex_data[source] |
                        (uint16_t)((uint16_t)tex_data[source + 1u] << 8);
            } else {
                const uint32_t source_index = twiddled_index(x, y, side);
                const size_t source = (size_t)desc->data_offset +
                                      (size_t)source_index * 2u;
                value = (uint16_t)tex_data[source] |
                        (uint16_t)((uint16_t)tex_data[source + 1u] << 8);
            }
            argb_out[(size_t)y * width + x] = decode_pixel(pixel_format, value);
        }
    }
    return 0;
}
