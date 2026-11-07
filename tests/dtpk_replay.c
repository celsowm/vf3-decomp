#include "dtpk.h"
#include "asset_pack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void wr32(uint8_t *p, uint32_t value)
{
    p[0] = (uint8_t)value;
    p[1] = (uint8_t)(value >> 8);
    p[2] = (uint8_t)(value >> 16);
    p[3] = (uint8_t)(value >> 24);
}

static void init_pack(uint8_t *bytes, uint32_t size)
{
    memset(bytes, 0, size);
    wr32(bytes, DTPK_MAGIC);
    wr32(bytes + 8, size);
    wr32(bytes + 0x20, 0x60u);
}

static int rejected_cleanly(const uint8_t *bytes, uint32_t size,
                            const char *case_name)
{
    Dtpk pack;
    memset(&pack, 0xA5, sizeof pack);
    if (dtpk_parse(bytes, size, &pack) >= 0 || pack.data || pack.data_size ||
        pack.nsections != 0) {
        fprintf(stderr, "dtpk_replay: %s was accepted or left partial output\n",
                case_name);
        return 0;
    }
    return 1;
}

static int check_packed_audio(void)
{
    vf3_asset_pack archive;
    uint32_t packages = 0;
    if (vf3_asset_pack_open(&archive, "build/vf3_assets.vfa") != 0)
        return 0; /* Synthetic format checks still run without extracted data. */
    for (uint32_t i = 0; i < vf3_asset_pack_count(&archive); ++i) {
        const char *name = vf3_asset_pack_name(&archive, i);
        const uint64_t wide_size = vf3_asset_pack_size(&archive, i);
        uint8_t *bytes;
        size_t size;
        Dtpk pack;
        if (!name || strlen(name) < 4u || strcmp(name + strlen(name) - 4u, ".BIN") != 0)
            continue;
        if (wide_size > UINT32_MAX || wide_size > SIZE_MAX) {
            fprintf(stderr, "dtpk_replay: oversized packed binary %s\n", name);
            vf3_asset_pack_close(&archive);
            return -1;
        }
        size = (size_t)wide_size;
        bytes = (uint8_t *)malloc(size ? size : 1u);
        if (!bytes || vf3_asset_pack_read(&archive, name, bytes, size, NULL) != 0) {
            fprintf(stderr, "dtpk_replay: cannot read packed binary %s\n", name);
            free(bytes);
            vf3_asset_pack_close(&archive);
            return -1;
        }
        if (size >= 4u && memcmp(bytes, "DTPK", 4) == 0) {
            if (dtpk_parse(bytes, (uint32_t)size, &pack) != 0) {
                fprintf(stderr, "dtpk_replay: invalid packed audio container %s\n", name);
                free(bytes);
                vf3_asset_pack_close(&archive);
                return -1;
            }
            for (int section = 0; section < pack.nsections; ++section) {
                const uint8_t *data;
                uint32_t section_size;
                if (dtpk_get(&pack, section, &data, &section_size) != 0 ||
                    !data || !section_size) {
                    fprintf(stderr, "dtpk_replay: invalid section in %s\n", name);
                    free(bytes);
                    vf3_asset_pack_close(&archive);
                    return -1;
                }
            }
            ++packages;
        }
        free(bytes);
    }
    vf3_asset_pack_close(&archive);
    if (packages && packages != 69u) {
        fprintf(stderr, "dtpk_replay: expected 69 packed audio containers, found %u\n",
                packages);
        return -1;
    }
    if (packages)
        printf("dtpk_replay: %u packed DTPK assets pass section validation\n", packages);
    return 0;
}

int main(void)
{
    uint8_t bytes[0x68];
    Dtpk pack;
    const uint8_t *section = (const uint8_t *)1;
    uint32_t section_size = 99;

    init_pack(bytes, 0x64u);
    if (dtpk_parse(bytes, 0x64u, &pack) != 0 || pack.nsections != 1 ||
        pack.sections[0].offset != 0x60u || pack.sections[0].size != 4u ||
        dtpk_get(&pack, 0, &section, &section_size) != 0 ||
        section != bytes + 0x60u || section_size != 4u) {
        fputs("dtpk_replay: valid single-section pack failed\n", stderr);
        return 1;
    }

    pack.sections[0].size = UINT32_MAX;
    if (dtpk_get(&pack, 0, &section, &section_size) == 0 || section ||
        section_size != 0) {
        fputs("dtpk_replay: out-of-range section was exposed\n", stderr);
        return 1;
    }

    init_pack(bytes, 0x68u);
    wr32(bytes + 0x24, 0x60u);
    if (!rejected_cleanly(bytes, 0x68u, "duplicate offsets")) return 1;
    init_pack(bytes, 0x68u);
    wr32(bytes + 0x28, 0x64u);
    if (dtpk_parse(bytes, 0x68u, &pack) != 0 || pack.nsections != 2 ||
        pack.sections[0].size != 4u || pack.sections[1].size != 4u) {
        fputs("dtpk_replay: valid zero hole in directory was rejected\n", stderr);
        return 1;
    }
    init_pack(bytes, 0x68u);
    wr32(bytes + 0x24, 0x64u);
    wr32(bytes + 0x28, 0x62u);
    if (!rejected_cleanly(bytes, 0x68u, "descending offsets")) return 1;
    init_pack(bytes, 0x68u);
    wr32(bytes + 0x24, 0x68u);
    if (!rejected_cleanly(bytes, 0x68u, "offset at end of file")) return 1;
    init_pack(bytes, 0x68u);
    wr32(bytes + 0x20, 0);
    if (!rejected_cleanly(bytes, 0x68u, "empty directory")) return 1;
    init_pack(bytes, 0x68u);
    wr32(bytes + 8, 0x64u);
    if (!rejected_cleanly(bytes, 0x68u, "size mismatch")) return 1;
    init_pack(bytes, 0x68u);
    wr32(bytes, 0);
    if (!rejected_cleanly(bytes, 0x68u, "bad magic")) return 1;

    memset(&pack, 0xA5, sizeof pack);
    if (dtpk_parse(NULL, 0x68u, &pack) >= 0 || pack.data || pack.nsections) {
        fputs("dtpk_replay: null input did not clear output\n", stderr);
        return 1;
    }
    if (dtpk_parse(bytes, 0x68u, NULL) >= 0) {
        fputs("dtpk_replay: null output was accepted\n", stderr);
        return 1;
    }
    if (check_packed_audio() != 0)
        return 1;

    puts("dtpk_replay: offsets, section bounds, and failure cleanup pass");
    return 0;
}
