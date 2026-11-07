#include "asset_pack.h"

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define VF3_ASSET_MAGIC "VF3AST\0\0"
#define VF3_ASSET_VERSION 1u
#define VF3_ASSET_HEADER_BYTES 32u
#define VF3_ASSET_ENTRY_BYTES 112u
#define VF3_ASSET_MAX_FILES 65536u

static uint32_t rd32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static uint64_t rd64(const uint8_t *p)
{
    return (uint64_t)rd32(p) | ((uint64_t)rd32(p + 4) << 32);
}

static int seek64(FILE *f, uint64_t offset)
{
    if (offset > (uint64_t)INT64_MAX) return -1;
#ifdef _WIN32
    return _fseeki64(f, (__int64)offset, SEEK_SET);
#else
    if (offset > (uint64_t)LONG_MAX) return -1;
    return fseek(f, (long)offset, SEEK_SET);
#endif
}

static int file_size(FILE *f, uint64_t *out)
{
#ifdef _WIN32
    __int64 end;
    if (_fseeki64(f, 0, SEEK_END) != 0) return -1;
    end = _ftelli64(f);
    if (end < 0) return -1;
    *out = (uint64_t)end;
#else
    long end;
    if (fseek(f, 0, SEEK_END) != 0) return -1;
    end = ftell(f);
    if (end < 0) return -1;
    *out = (uint64_t)end;
#endif
    return 0;
}

static int name_compare(const char *a, const char *b)
{
    while (*a && *b) {
        unsigned char ca = (unsigned char)*a++;
        unsigned char cb = (unsigned char)*b++;
        if (ca >= 'a' && ca <= 'z') ca = (unsigned char)(ca - 'a' + 'A');
        if (cb >= 'a' && cb <= 'z') cb = (unsigned char)(cb - 'a' + 'A');
        if (ca != cb) return (int)ca - (int)cb;
    }
    return (int)(unsigned char)*a - (int)(unsigned char)*b;
}

int vf3_asset_pack_open(vf3_asset_pack *pack, const char *path)
{
    uint8_t header[VF3_ASSET_HEADER_BYTES];
    FILE *f = NULL;
    uint64_t index_offset, table_end, previous_end, archive_size;
    uint32_t count;
    int result = -1;

    if (!pack || !path || strlen(path) >= sizeof pack->path) return -1;
    memset(pack, 0, sizeof *pack);
    f = fopen(path, "rb");
    if (!f) return -1;
    if (file_size(f, &archive_size) != 0 || archive_size < sizeof header ||
        seek64(f, 0) != 0 || fread(header, 1, sizeof header, f) != sizeof header)
        goto done;
    if (memcmp(header, VF3_ASSET_MAGIC, 8) != 0 || rd32(header + 8) != VF3_ASSET_VERSION)
        goto done;

    count = rd32(header + 12);
    index_offset = rd64(header + 16);
    pack->data_offset = rd64(header + 24);
    if (!count || count > VF3_ASSET_MAX_FILES || index_offset != VF3_ASSET_HEADER_BYTES)
        goto done;
    if ((uint64_t)count > (UINT64_MAX - index_offset) / VF3_ASSET_ENTRY_BYTES)
        goto done;
    table_end = index_offset + (uint64_t)count * VF3_ASSET_ENTRY_BYTES;
    if (pack->data_offset < table_end || pack->data_offset > archive_size)
        goto done;

    pack->entries = (vf3_asset_entry *)calloc(count, sizeof *pack->entries);
    if (!pack->entries) goto done;
    if (seek64(f, index_offset) != 0) goto done;
    previous_end = pack->data_offset;
    for (uint32_t i = 0; i < count; ++i) {
        uint8_t raw[VF3_ASSET_ENTRY_BYTES];
        size_t name_len = 0;
        vf3_asset_entry *entry = &pack->entries[i];
        if (fread(raw, 1, sizeof raw, f) != sizeof raw) goto done;
        while (name_len < VF3_ASSET_NAME_CAP && raw[name_len]) ++name_len;
        if (!name_len || name_len == VF3_ASSET_NAME_CAP) goto done;
        for (size_t j = 0; j < name_len; ++j) {
            if (raw[j] < 0x21 || raw[j] > 0x7e || raw[j] == '/' || raw[j] == '\\')
                goto done;
        }
        memcpy(entry->name, raw, name_len);
        entry->offset = rd64(raw + 64);
        entry->size = rd64(raw + 72);
        memcpy(entry->sha256, raw + 80, sizeof entry->sha256);
        if (entry->offset < previous_end || entry->offset > archive_size ||
            entry->size > archive_size - entry->offset)
            goto done;
        if (i && name_compare(pack->entries[i - 1].name, entry->name) >= 0)
            goto done;
        previous_end = entry->offset + entry->size;
    }

    strcpy(pack->path, path);
    pack->file_size = archive_size;
    pack->count = count;
    result = 0;
done:
    fclose(f);
    if (result != 0) vf3_asset_pack_close(pack);
    return result;
}

void vf3_asset_pack_close(vf3_asset_pack *pack)
{
    if (!pack) return;
    free(pack->entries);
    memset(pack, 0, sizeof *pack);
}

uint32_t vf3_asset_pack_count(const vf3_asset_pack *pack)
{
    return pack ? pack->count : 0;
}

const char *vf3_asset_pack_name(const vf3_asset_pack *pack, uint32_t index)
{
    return pack && index < pack->count ? pack->entries[index].name : NULL;
}

uint64_t vf3_asset_pack_size(const vf3_asset_pack *pack, uint32_t index)
{
    return pack && index < pack->count ? pack->entries[index].size : 0;
}

int vf3_asset_pack_read(const vf3_asset_pack *pack, const char *name,
                        void *dst, size_t capacity, size_t *size_out)
{
    uint32_t lo = 0, hi;
    FILE *f;
    const vf3_asset_entry *entry = NULL;
    if (size_out) *size_out = 0;
    if (!pack || !pack->count || !name || (!dst && capacity)) return -3;
    hi = pack->count;
    while (lo < hi) {
        uint32_t mid = lo + (hi - lo) / 2;
        int cmp = name_compare(pack->entries[mid].name, name);
        if (cmp == 0) { entry = &pack->entries[mid]; break; }
        if (cmp < 0) lo = mid + 1;
        else hi = mid;
    }
    if (!entry) return -1;
    if (entry->size > SIZE_MAX) return -3;
    if (size_out) *size_out = (size_t)entry->size;
    if (entry->size > capacity) return -2;
    f = fopen(pack->path, "rb");
    if (!f) return -3;
    if (seek64(f, entry->offset) != 0 ||
        fread(dst, 1, (size_t)entry->size, f) != (size_t)entry->size) {
        fclose(f);
        return -3;
    }
    fclose(f);
    return 0;
}
