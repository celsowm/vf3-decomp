/* Bounded native decoding for the sample spans in VO_* DTPK packages.
 * The 16-byte voice descriptor layout is shared with tools/dtpk_samples.py;
 * unknown descriptor words remain uninterpreted. */
#include "voice_sample.h"

#include "aica_adpcm.h"
#include "dtpk.h"

#include <stdlib.h>

enum { VOICE_DESCRIPTOR_BYTES = 16, VOICE_ADDRESS_MASK = 0x00ffffffu };

static uint32_t read_u32le(const uint8_t *data)
{
    return (uint32_t)data[0] | ((uint32_t)data[1] << 8) |
           ((uint32_t)data[2] << 16) | ((uint32_t)data[3] << 24);
}

int vf3_native_voice_decode_sample(const void *package, uint32_t package_size,
                                   uint32_t sample_index, int16_t **pcm,
                                   size_t *sample_count)
{
    const uint8_t *section;
    uint32_t section_size;
    uint32_t data_start, previous_end, count;
    Dtpk dtpk;
    AicaState decoder;
    int16_t *decoded;

    if (!package || !pcm || !sample_count)
        return -1;
    *pcm = NULL;
    *sample_count = 0;
    if (dtpk_parse(package, package_size, &dtpk) != 0 ||
        dtpk_get(&dtpk, dtpk.nsections - 1, &section, &section_size) != 0 ||
        section_size < VOICE_DESCRIPTOR_BYTES)
        return -2;

    const uint32_t first_length = read_u32le(section);
    const uint32_t first_end = read_u32le(section + 4) & VOICE_ADDRESS_MASK;
    if (!first_length || first_end < first_length)
        return -2;
    data_start = first_end - first_length;
    const uint32_t section_start = (uint32_t)(section - (const uint8_t *)package);
    const uint32_t section_end = section_start + section_size;
    if (data_start < section_start || data_start > section_end)
        return -2;
    const uint32_t descriptor_span = data_start - section_start;
    count = descriptor_span / VOICE_DESCRIPTOR_BYTES;
    if (!count || count > section_size / VOICE_DESCRIPTOR_BYTES)
        return -2;
    previous_end = data_start;

    if (sample_index >= count)
        return -2;
    for (uint32_t index = 0; index < count; ++index) {
        const uint8_t *record = section + index * VOICE_DESCRIPTOR_BYTES;
        const uint32_t length = read_u32le(record);
        const uint32_t end = read_u32le(record + 4) & VOICE_ADDRESS_MASK;
        if (!length || end < length || end - length != previous_end ||
            end > section_end)
            return -2;
        previous_end = end;
    }

    const uint8_t *record = section + sample_index * VOICE_DESCRIPTOR_BYTES;
    const uint32_t length = read_u32le(record);
    const uint32_t end = read_u32le(record + 4) & VOICE_ADDRESS_MASK;
    const uint32_t start = end - length;
    if ((size_t)length > SIZE_MAX / (2u * sizeof *decoded))
        return -2;
    const size_t frames = (size_t)length * 2u;
    decoded = (int16_t *)malloc(frames * sizeof *decoded);
    if (!decoded)
        return -3;
    aica_adpcm_init(&decoder);
    if (aica_adpcm_decode(&decoder, (const uint8_t *)package + start,
                          length, decoded, frames) != frames) {
        free(decoded);
        return -2;
    }
    *pcm = decoded;
    *sample_count = frames;
    return 0;
}
