/* Offline MT sampler for the native source-level evaluator.
 *
 * Reads one extracted MT asset from VFA and prints the 63 evaluated channels
 * at selected whole-frame phases. This is an analysis tool, not a runtime
 * dependency of vf3port.
 */
#include "asset_pack.h"
#include "motion.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

static int parse_u32(const char *text, uint32_t *out)
{
    char *end = NULL;
    unsigned long value;
    errno = 0;
    value = strtoul(text, &end, 0);
    if (errno || !text[0] || !end || *end || value > UINT32_MAX)
        return 0;
    *out = (uint32_t)value;
    return 1;
}

static int load_asset(vf3_asset_pack *pack, const char *name,
                      uint8_t **data_out, size_t *size_out)
{
    size_t size = 0;
    uint8_t *data;
    if (vf3_asset_pack_read(pack, name, NULL, 0, &size) != -2 ||
        !size || size > UINT32_MAX)
        return 0;
    data = (uint8_t *)malloc(size);
    if (!data)
        return 0;
    if (vf3_asset_pack_read(pack, name, data, size, NULL) != 0) {
        free(data);
        return 0;
    }
    *data_out = data;
    *size_out = size;
    return 1;
}

int main(int argc, char **argv)
{
    vf3_asset_pack pack;
    uint8_t *asset = NULL;
    size_t asset_size = 0;
    MtFile file;
    MtMotionView storage;
    vf3_native_motion_stream stream;
    float values[VF3_NATIVE_MOTION_CHANNELS];
    uint32_t motion_id, cycle_value, start_frame, frame_count, frame_step = 1;
    int result = 1, pack_open = 0;

    if (argc < 7 || argc > 8 ||
        !parse_u32(argv[3], &motion_id) ||
        !parse_u32(argv[4], &cycle_value) ||
        !parse_u32(argv[5], &start_frame) ||
        !parse_u32(argv[6], &frame_count) ||
        (argc == 8 && !parse_u32(argv[7], &frame_step)) ||
        cycle_value > UINT16_MAX || frame_count == 0 || frame_step == 0) {
        fprintf(stderr, "usage: %s <vfa> <MT*.BIN> <motion-id> <cycle> "
                        "<start-frame> <frame-count> [frame-step]\n", argv[0]);
        return 2;
    }
    if (vf3_asset_pack_open(&pack, argv[1]) != 0) {
        fprintf(stderr, "mt_motion_dump: cannot open VFA archive %s\n", argv[1]);
        goto done;
    }
    pack_open = 1;
    if (!load_asset(&pack, argv[2], &asset, &asset_size) ||
        mt_parse(asset, (uint32_t)asset_size, &file) != 0) {
        fprintf(stderr, "mt_motion_dump: cannot parse asset %s\n", argv[2]);
        goto done;
    }
    if (vf3_native_motion_load(&file, motion_id, (uint16_t)cycle_value,
                               &storage, &stream) != 0) {
        fprintf(stderr, "mt_motion_dump: motion 0x%x is absent or malformed in %s\n",
                motion_id, argv[2]);
        goto done;
    }

    printf("asset=%s motion=0x%x cycle=%u descriptor=0x%04x "
           "source=%06x,%06x,%06x counts=%zu times=%zu tuples=%zu\n",
           argv[2], motion_id, cycle_value, storage.descriptor_word,
           storage.source_offsets[0], storage.source_offsets[1],
           storage.source_offsets[2], storage.counts_size,
           storage.times_size, storage.tuples_size);
    for (uint32_t sample = 0; sample < frame_count; ++sample) {
        const uint64_t frame = (uint64_t)start_frame +
                               (uint64_t)sample * frame_step;
        const uint64_t phase = frame * 0x100u;
        if (phase > INT32_MAX ||
            vf3_native_motion_eval(&stream, (int32_t)phase, values) != 0) {
            fprintf(stderr, "mt_motion_dump: evaluation failed at frame %llu\n",
                    (unsigned long long)frame);
            goto done;
        }
        printf("frame=%llu", (unsigned long long)frame);
        for (size_t channel = 0; channel < VF3_NATIVE_MOTION_CHANNELS; ++channel)
            printf(" % .8g", (double)values[channel]);
        putchar('\n');
    }
    result = 0;
done:
    free(asset);
    if (pack_open)
        vf3_asset_pack_close(&pack);
    return result;
}
