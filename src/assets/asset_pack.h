/* Offline-packed VF3 assets.  This reader has no GD-ROM, ISO9660, BIOS,
 * emulator-state, or guest-CPU dependency. */
#ifndef VF3_ASSET_PACK_H
#define VF3_ASSET_PACK_H

#include <stddef.h>
#include <stdint.h>

#define VF3_ASSET_NAME_CAP 64u

typedef struct {
    char name[VF3_ASSET_NAME_CAP];
    uint64_t offset;
    uint64_t size;
    uint8_t sha256[32];
} vf3_asset_entry;

typedef struct {
    char path[2048];
    uint64_t file_size;
    uint64_t data_offset;
    uint32_t count;
    vf3_asset_entry *entries;
} vf3_asset_pack;

/* Open and validate an offline VFA asset archive.  Returns 0 on success. */
int vf3_asset_pack_open(vf3_asset_pack *pack, const char *path);
void vf3_asset_pack_close(vf3_asset_pack *pack);

uint32_t vf3_asset_pack_count(const vf3_asset_pack *pack);
const char *vf3_asset_pack_name(const vf3_asset_pack *pack, uint32_t index);
uint64_t vf3_asset_pack_size(const vf3_asset_pack *pack, uint32_t index);

/* Case-insensitive ASCII lookup.  Returns 0 on success, -1 if absent,
 * -2 if capacity is insufficient, and -3 for an I/O error.  On -2, *size_out
 * receives the required size.  The archive must remain unchanged while open. */
int vf3_asset_pack_read(const vf3_asset_pack *pack, const char *name,
                        void *dst, size_t capacity, size_t *size_out);

#endif
