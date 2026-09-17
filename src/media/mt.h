/* MT*.BIN motion-table loader (clean-room, per docs/formats/MT.md).
 * 8880-slot u32 table at +0; nonzero slots point to records;
 * record size = next-slot offset - this slot (or EOF).
 */
#ifndef VF3_MT_H
#define VF3_MT_H

#include <stddef.h>
#include <stdint.h>

#define MT_SLOTS     8880
#define MT_PAYLOAD_FLOOR 0x008AC0u
#define MT_HDR_BYTES 4

typedef struct {
    const uint8_t *data;
    uint32_t       size;
    uint32_t       first_record_off;
    uint32_t       count; /* nonzero slots */
} MtFile;

int      mt_parse(const void *data, uint32_t size, MtFile *out);
/* Iterate: callcb(slot, record_off, record_size) in order. */
void     mt_each(const MtFile *f, void (*cb)(uint32_t slot, uint32_t off,
                                             uint32_t len, void *ctx),
                 void *ctx);

#endif
