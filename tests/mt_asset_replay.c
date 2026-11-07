/* Verify native MT table/record parsing from the asset-only VFA archive. */
#include "asset_pack.h"
#include "mt.h"
#include "motion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { EXPECTED_MT_ASSETS = 91, EXPECTED_SLOT_REFS = 209925 };

typedef struct {
    const MtFile *file;
    uint32_t rows;
    uint32_t previous_slot;
    uint32_t first_slot, first_off, first_len;
    uint32_t last_slot, last_off, last_len;
    uint32_t min_len, max_len;
    int have_slot;
    int bad;
} record_stats;

static void put_u32le(uint8_t *p, uint32_t value)
{
    p[0] = (uint8_t)value;
    p[1] = (uint8_t)(value >> 8);
    p[2] = (uint8_t)(value >> 16);
    p[3] = (uint8_t)(value >> 24);
}

static void record_row(uint32_t slot, uint32_t off, uint32_t len, void *ctx)
{
    record_stats *stats = (record_stats *)ctx;
    if (!stats || slot >= MT_SLOTS || off < MT_PAYLOAD_FLOOR ||
        off >= stats->file->size || !len || len > stats->file->size - off ||
        (stats->have_slot && slot <= stats->previous_slot)) {
        if (stats) stats->bad = 1;
        return;
    }
    if (!stats->rows) {
        stats->first_slot = slot;
        stats->first_off = off;
        stats->first_len = len;
        stats->min_len = len;
        stats->max_len = len;
    } else {
        if (len < stats->min_len) stats->min_len = len;
        if (len > stats->max_len) stats->max_len = len;
    }
    stats->last_slot = slot;
    stats->last_off = off;
    stats->last_len = len;
    stats->previous_slot = slot;
    stats->have_slot = 1;
    ++stats->rows;
}

static int check_failure_clears_view(void)
{
    uint8_t *file = (uint8_t *)calloc(MT_PAYLOAD_FLOOR + 16u, 1u);
    MtFile parsed;
    int fails = 0;
    if (!file) return 1;
    memset(&parsed, 0xA5, sizeof parsed);
    if (mt_parse(NULL, MT_PAYLOAD_FLOOR, &parsed) != -1 || parsed.data ||
        parsed.size || parsed.first_record_off || parsed.count) {
        fputs("mt_asset_replay: null-input failure retained stale MtFile data\n",
              stderr);
        ++fails;
    }
    memset(&parsed, 0xA5, sizeof parsed);
    if (mt_parse(file, MT_PAYLOAD_FLOOR, &parsed) != -2 || parsed.data ||
        parsed.size || parsed.first_record_off || parsed.count) {
        fputs("mt_asset_replay: empty-table failure retained stale MtFile data\n",
              stderr);
        ++fails;
    }
    put_u32le(file, 0x10u);
    memset(&parsed, 0xA5, sizeof parsed);
    if (mt_parse(file, MT_PAYLOAD_FLOOR + 16u, &parsed) != -3 || parsed.data ||
        parsed.size || parsed.first_record_off || parsed.count) {
        fputs("mt_asset_replay: malformed-table failure retained stale MtFile data\n",
              stderr);
        ++fails;
    }

    memset(file, 0, MT_PAYLOAD_FLOOR + 16u);
    put_u32le(file + 4u, MT_PAYLOAD_FLOOR);
    put_u32le(file + 8u, MT_PAYLOAD_FLOOR); /* alias */
    put_u32le(file + 12u, MT_PAYLOAD_FLOOR + 8u);
    if (mt_parse(file, MT_PAYLOAD_FLOOR + 16u, &parsed) != 0 ||
        parsed.count != 3u) {
        fputs("mt_asset_replay: valid aliased synthetic table rejected\n", stderr);
        ++fails;
    } else {
        uint32_t off, len;
        if (mt_record(&parsed, 1u, &off, &len) != 0 ||
            off != MT_PAYLOAD_FLOOR || len != 8u ||
            mt_record(&parsed, 2u, &off, &len) != 0 ||
            off != MT_PAYLOAD_FLOOR || len != 8u ||
            mt_record(&parsed, 3u, &off, &len) != 0 ||
            off != MT_PAYLOAD_FLOOR + 8u || len != 8u) {
            fputs("mt_asset_replay: aliased record boundaries are incorrect\n",
                  stderr);
            ++fails;
        }
    }
    free(file);
    return fails;
}

static int check_known_motion(const char *name, const MtFile *file)
{
    uint32_t motion_id;
    uint16_t descriptor;
    size_t counts_size, times_size, tuples_size;
    MtMotionView view;
    vf3_native_motion_stream stream;
    float first[VF3_NATIVE_MOTION_CHANNELS];
    float second[VF3_NATIVE_MOTION_CHANNELS];
    int32_t phases[3];

    if (strcmp(name, "MTAKIJAC.BIN") == 0) {
        motion_id = 0x41au;
        descriptor = 0x003cu;
        counts_size = 9u;
        times_size = 13u;
        tuples_size = 404u;
    } else if (strcmp(name, "MTJACLAU.BIN") == 0) {
        motion_id = 0x956u;
        descriptor = 0x0050u;
        counts_size = 10u;
        times_size = 12u;
        tuples_size = 400u;
    } else {
        return 0;
    }

    if (mt_motion_view(file, motion_id, &view) != 0 ||
        view.motion_id != motion_id || view.descriptor_word != descriptor ||
        view.counts_size != counts_size || view.times_size != times_size ||
        view.tuples_size != tuples_size) {
        fprintf(stderr, "mt_asset_replay: %s motion 0x%x stream map differs\n",
                name, motion_id);
        return 1;
    }
    if (vf3_native_motion_load(file, motion_id, 60u, &view, &stream) != 0) {
        fprintf(stderr, "mt_asset_replay: %s motion 0x%x could not be bound\n",
                name, motion_id);
        return 1;
    }
    phases[0] = 0x100;
    phases[1] = (int32_t)view.times[0] << 8;
    phases[2] = ((int32_t)stream.cycle << 8) - 0x100;
    for (size_t i = 0; i < sizeof phases / sizeof phases[0]; ++i) {
        if (vf3_native_motion_eval(&stream, phases[i], first) != 0 ||
            vf3_native_motion_eval(&stream, phases[i], second) != 0 ||
            memcmp(first, second, sizeof first) != 0) {
            fprintf(stderr,
                    "mt_asset_replay: %s motion 0x%x failed at phase 0x%x\n",
                    name, motion_id, (unsigned)phases[i]);
            return 1;
        }
    }
    printf("  %s motion 0x%x: %zu counts, %zu key times, %zu tuple bytes\n",
           name, motion_id, view.counts_size, view.times_size, view.tuples_size);
    return 0;
}

int main(int argc, char **argv)
{
    const char *path = argc > 1 ? argv[1] : "build/vf3_assets.vfa";
    vf3_asset_pack pack;
    uint32_t assets = 0, slot_refs = 0, min_len = UINT32_MAX, max_len = 0;
    int fails = check_failure_clears_view();

    if (vf3_asset_pack_open(&pack, path) != 0) {
        fprintf(stderr, "mt_asset_replay: cannot open VFA pack %s\n", path);
        return 2;
    }
    for (uint32_t i = 0; i < vf3_asset_pack_count(&pack); ++i) {
        const char *name = vf3_asset_pack_name(&pack, i);
        const uint64_t size64 = vf3_asset_pack_size(&pack, i);
        uint8_t *bytes;
        size_t size;
        MtFile file;
        record_stats stats;
        if (!name || strncmp(name, "MT", 2u) != 0 ||
            strlen(name) < 4u || strcmp(name + strlen(name) - 4u, ".BIN") != 0)
            continue;
        ++assets;
        if (size64 > UINT32_MAX || size64 > SIZE_MAX) {
            fprintf(stderr, "mt_asset_replay: %s is too large for MT reader\n", name);
            ++fails;
            continue;
        }
        size = (size_t)size64;
        bytes = (uint8_t *)malloc(size);
        if (!bytes || vf3_asset_pack_read(&pack, name, bytes, size, NULL) != 0) {
            fprintf(stderr, "mt_asset_replay: cannot read %s from VFA\n", name);
            free(bytes);
            ++fails;
            continue;
        }
        if (mt_parse(bytes, (uint32_t)size, &file) != 0) {
            fprintf(stderr, "mt_asset_replay: %s has an invalid MT table\n", name);
            free(bytes);
            ++fails;
            continue;
        }
        fails += check_known_motion(name, &file);
        memset(&stats, 0, sizeof stats);
        stats.file = &file;
        if (mt_each(&file, record_row, &stats) != 0 || stats.bad ||
            stats.rows != file.count || !stats.rows) {
            fprintf(stderr,
                    "mt_asset_replay: %s record walk failed (rows=%u, slots=%u)\n",
                    name, stats.rows, file.count);
            ++fails;
        } else {
            uint32_t off, len;
            if (mt_record(&file, stats.first_slot, &off, &len) != 0 ||
                off != stats.first_off || len != stats.first_len ||
                mt_record(&file, stats.last_slot, &off, &len) != 0 ||
                off != stats.last_off || len != stats.last_len) {
                fprintf(stderr, "mt_asset_replay: %s slot lookup disagrees with walk\n",
                        name);
                ++fails;
            }
            slot_refs += stats.rows;
            if (stats.min_len < min_len) min_len = stats.min_len;
            if (stats.max_len > max_len) max_len = stats.max_len;
        }
        free(bytes);
    }
    vf3_asset_pack_close(&pack);
    if (assets != EXPECTED_MT_ASSETS || slot_refs != EXPECTED_SLOT_REFS) {
        fprintf(stderr,
                "mt_asset_replay: expected %u MT assets / %u slot refs, found %u / %u\n",
                EXPECTED_MT_ASSETS, EXPECTED_SLOT_REFS, assets, slot_refs);
        ++fails;
    }
    if (!fails)
        printf("mt_asset_replay: %u VFA MT assets, %u records, record sizes %u..%u bytes: PASS\n",
               assets, slot_refs, min_len, max_len);
    return fails ? 1 : 0;
}
