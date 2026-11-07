/* Offline MT sampler for the native source-level evaluator.
 *
 * Reads one extracted MT asset from VFA and prints the 63 evaluated channels
 * at selected Q8 phases. This is an analysis tool, not a runtime
 * dependency of vf3port.
 */
#include "asset_pack.h"
#include "motion.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    uint16_t pose_fields[VF3_NATIVE_POSE_FIELDS];
    uint32_t motion_id, cycle_value, start_frame, frame_count, frame_step = 1;
    uint32_t phase_override = 0;
    int print_pose_fields = 0;
    int has_phase_override = 0;
    int has_frame_step = 0;
    int result = 1, pack_open = 0;

    if (argc < 7 ||
        !parse_u32(argv[3], &motion_id) ||
        !parse_u32(argv[4], &cycle_value) ||
        !parse_u32(argv[5], &start_frame) ||
        !parse_u32(argv[6], &frame_count) ||
        cycle_value > UINT16_MAX || frame_count == 0) {
        fprintf(stderr, "usage: %s <vfa> <MT*.BIN> <motion-id> <cycle> "
                        "<start-frame> <frame-count> [frame-step] "
                        "[--phase-q8 phase] [--pose-fields]\n",
                argv[0]);
        return 2;
    }
    for (int arg = 7; arg < argc; ++arg) {
        if (strcmp(argv[arg], "--pose-fields") == 0) {
            if (print_pose_fields) {
                fprintf(stderr, "mt_motion_dump: duplicate --pose-fields\n");
                return 2;
            }
            print_pose_fields = 1;
        } else if (strcmp(argv[arg], "--phase-q8") == 0) {
            if (has_phase_override || arg + 1 >= argc ||
                !parse_u32(argv[++arg], &phase_override) ||
                phase_override > INT32_MAX) {
                fprintf(stderr, "mt_motion_dump: --phase-q8 needs one nonnegative "
                                "signed-32-bit phase\n");
                return 2;
            }
            has_phase_override = 1;
        } else if (!has_frame_step &&
                   parse_u32(argv[arg], &frame_step) && frame_step != 0) {
            has_frame_step = 1;
        } else {
            fprintf(stderr, "mt_motion_dump: unexpected argument %s\n", argv[arg]);
            return 2;
        }
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
        const uint64_t base_phase = has_phase_override
            ? phase_override : (uint64_t)start_frame * 0x100u;
        const uint64_t max_delta = (uint64_t)INT32_MAX - base_phase;
        uint64_t phase_delta;
        if (base_phase > INT32_MAX ||
            (sample != 0 &&
             (uint64_t)sample > max_delta / frame_step / 0x100u)) {
            fprintf(stderr, "mt_motion_dump: phase exceeds signed-32-bit range\n");
            goto done;
        }
        phase_delta = (uint64_t)sample * frame_step * 0x100u;
        const uint64_t phase = base_phase + phase_delta;
        const uint64_t frame = phase / 0x100u;
        if (phase > INT32_MAX ||
            (print_pose_fields
                ? vf3_native_motion_eval_pose_fields(&stream, (int32_t)phase,
                                                     values, pose_fields)
                : vf3_native_motion_eval(&stream, (int32_t)phase, values)) != 0) {
            fprintf(stderr, "mt_motion_dump: evaluation failed at phase 0x%llx\n",
                    (unsigned long long)phase);
            goto done;
        }
        printf("frame=%llu phase_q8=%llu", (unsigned long long)frame,
               (unsigned long long)phase);
        for (size_t channel = 0; channel < VF3_NATIVE_MOTION_CHANNELS; ++channel)
            printf(" % .8g", (double)values[channel]);
        if (print_pose_fields) {
            printf(" pose_fields=");
            for (size_t field = 0; field < VF3_NATIVE_POSE_FIELDS; ++field)
                printf(" %d", (int)(int16_t)pose_fields[field]);
        }
        putchar('\n');
    }
    result = 0;
done:
    free(asset);
    if (pack_open)
        vf3_asset_pack_close(&pack);
    return result;
}
