#include "../src/assets/asset_pack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    vf3_asset_pack pack;
    const char *needle = "ANAUNCE.BIN";
    const char *name;
    size_t size = 0;
    uint8_t *bytes;
    int saw_program = 0;
    int rc;

    if (argc != 2) {
        fprintf(stderr, "usage: vf3assetcheck <asset archive>\n");
        return 2;
    }
    if (vf3_asset_pack_open(&pack, argv[1]) != 0) {
        fprintf(stderr, "asset_pack_replay: cannot open or validate archive\n");
        return 1;
    }
    if (!vf3_asset_pack_count(&pack)) {
        vf3_asset_pack_close(&pack);
        fprintf(stderr, "asset_pack_replay: empty archive\n");
        return 1;
    }
    for (uint32_t i = 0; i < vf3_asset_pack_count(&pack); ++i) {
        name = vf3_asset_pack_name(&pack, i);
        if (!name) continue;
        if (!strcmp(name, "1ST_READ.BIN") || !strcmp(name, "SNDDRV.BIN") ||
            !strcmp(name, "RELOAD.BIN")) saw_program = 1;
    }
    if (saw_program) {
        vf3_asset_pack_close(&pack);
        fprintf(stderr, "asset_pack_replay: program or firmware leaked into asset pack\n");
        return 1;
    }

    rc = vf3_asset_pack_read(&pack, needle, NULL, 0, &size);
    if (rc != -2 || size < 4) {
        vf3_asset_pack_close(&pack);
        fprintf(stderr, "asset_pack_replay: expected undersized-read contract failed\n");
        return 1;
    }
    bytes = (uint8_t *)malloc(size);
    if (!bytes || vf3_asset_pack_read(&pack, "anaunce.bin", bytes, size, &size) != 0 ||
        memcmp(bytes, "DTPK", 4) != 0) {
        free(bytes);
        vf3_asset_pack_close(&pack);
        fprintf(stderr, "asset_pack_replay: DTPK asset lookup/read failed\n");
        return 1;
    }
    free(bytes);
    vf3_asset_pack_close(&pack);
    puts("asset_pack_replay: asset-only bundle opens and returns DTPK data");
    return 0;
}
