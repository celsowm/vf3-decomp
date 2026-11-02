/* sys/native_assets.c - reader for the port's own asset bundle; see native_assets.h. */
#include "sys/native_assets.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define NATIVE_MAGIC "VF3DISC\0"
#define NATIVE_VERSION 1u
#define NATIVE_HEADER 48u
#define NATIVE_ZERO UINT64_MAX

static uint32_t rd32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static uint64_t rd64(const uint8_t *p)
{
    return (uint64_t)rd32(p) | ((uint64_t)rd32(p + 4) << 32);
}

static int join(char *out, size_t n, const char *dir, const char *name)
{
    const size_t d = strlen(dir);
    const size_t m = strlen(name);
    if (d + 1 + m + 1 > n) return -1;
    memcpy(out, dir, d);
    out[d] = '/';
    memcpy(out + d + 1, name, m + 1);
    return 0;
}

int vf3_native_assets_open(vf3_native_assets *a, const char *dir)
{
    uint8_t hdr[NATIVE_HEADER];
    memset(a, 0, sizeof *a);
    if (!dir || strlen(dir) >= sizeof a->dir) return -1;
    strcpy(a->dir, dir);
    if (join(a->boot_state, sizeof a->boot_state, dir, "boot.state") != 0) return -1;

    char path[600];
    if (join(path, sizeof path, dir, "disc.vf3") != 0) return -1;
    FILE *f = fopen(path, "rb");
    if (!f) return -1;
    if (fread(hdr, 1, sizeof hdr, f) != sizeof hdr || memcmp(hdr, NATIVE_MAGIC, 8) != 0) {
        fclose(f);
        return -1;
    }
    const uint32_t version = rd32(hdr + 8);
    const uint32_t sector_size = rd32(hdr + 12);
    const uint32_t first_lba = rd32(hdr + 16);
    const uint32_t nsectors = rd32(hdr + 20);
    const uint64_t index_offset = rd64(hdr + 32);
    const uint64_t data_offset = rd64(hdr + 40);
    if (version != NATIVE_VERSION || sector_size != VF3_GD_SECTOR || nsectors == 0 ||
        index_offset < NATIVE_HEADER || data_offset < index_offset + (uint64_t)nsectors * 8) {
        fclose(f);
        return -1;
    }
    uint64_t *index = malloc((size_t)nsectors * sizeof *index);
    if (!index) {
        fclose(f);
        return -1;
    }
#ifdef _WIN32
    if (_fseeki64(f, (long long)index_offset, SEEK_SET) != 0)
#else
    if (fseeko(f, (off_t)index_offset, SEEK_SET) != 0)
#endif
    {
        free(index);
        fclose(f);
        return -1;
    }
    size_t got = fread(index, sizeof *index, nsectors, f);
    if (got != nsectors) {
        free(index);
        fclose(f);
        return -1;
    }
    /* the file is little-endian; x86 hosts can read the table in place */
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    for (uint32_t i = 0; i < nsectors; ++i) {
        uint64_t v = 0;
        for (int b = 7; b >= 0; --b) v = (v << 8) | ((index[i] >> (b * 8)) & 0xFF);
        index[i] = v;
    }
#endif
    a->disc = f;
    a->index = index;
    a->first_lba = first_lba;
    a->nsectors = nsectors;
    a->data_offset = data_offset;
    return 0;
}

void vf3_native_assets_close(vf3_native_assets *a)
{
    if (a->disc) fclose(a->disc);
    free(a->index);
    memset(a, 0, sizeof *a);
}

int vf3_native_assets_read_sector(void *ctx, uint32_t fad, uint8_t out[VF3_GD_SECTOR])
{
    vf3_native_assets *a = ctx;
    if (!a || !a->disc || fad < 150u) return -1;
    const uint32_t lba = fad - 150u;
    if (lba < a->first_lba || lba - a->first_lba >= a->nsectors) return -1;
    const uint64_t off = a->index[lba - a->first_lba];
    if (off == NATIVE_ZERO) {
        memset(out, 0, VF3_GD_SECTOR);
        return 0;
    }
#ifdef _WIN32
    if (_fseeki64(a->disc, (long long)(a->data_offset + off), SEEK_SET) != 0) return -1;
#else
    if (fseeko(a->disc, (off_t)(a->data_offset + off), SEEK_SET) != 0) return -1;
#endif
    return fread(out, 1, VF3_GD_SECTOR, a->disc) == VF3_GD_SECTOR ? 0 : -1;
}

const char *vf3_native_assets_boot_state(const vf3_native_assets *a)
{
    return a->boot_state;
}
