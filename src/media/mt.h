/* MT*.BIN motion-table reader (clean-room, per docs/formats/MT.md).
 * 8880-slot u32 table at +0; nonzero slots point to records. Slot numbers
 * are not ordered by file offset; a record ends at the next greater distinct
 * payload offset, or EOF. Several slots may alias the same record.
 */
#ifndef VF3_MT_H
#define VF3_MT_H

#include <stddef.h>
#include <stdint.h>

#define MT_SLOTS     8880
#define MT_MOTION_ROWS (MT_SLOTS / 3u)
#define MT_MOTION_CHANNELS 63u
#define MT_PAYLOAD_FLOOR 0x008AC0u
#define MT_HDR_BYTES 4

typedef struct {
    const uint8_t *data;
    uint32_t       size;
    uint32_t       first_record_off;
    uint32_t       count; /* nonzero slots */
} MtFile;

/* One source-level MT motion, selected by the one-based ID used at actor+60.
 * The three source offsets are kept for diagnostics. `ops` is expanded from
 * the packed 2-bit table; the stream slices borrow bytes from the MT asset. */
typedef struct {
    uint32_t motion_id;
    uint32_t source_offsets[3];
    uint16_t descriptor_word;
    uint8_t  ops[MT_MOTION_CHANNELS];
    const uint8_t *counts;
    size_t counts_size;
    const uint8_t *times;
    size_t times_size;
    const uint8_t *tuples;
    size_t tuples_size;
} MtMotionView;

/* Returns 0 on success, -1 for bad arguments/short table, -2 for an empty
 * table, and -3 when a nonzero slot points outside the payload. */
int      mt_parse(const void *data, uint32_t size, MtFile *out);
/* Resolve one slot. Returns 0 on success, -1 for bad arguments or -2 for an
 * empty slot, and -3 for a malformed table/record boundary. */
int      mt_record(const MtFile *f, uint32_t slot, uint32_t *off_out,
                   uint32_t *len_out);
/* Resolve one one-based runtime motion ID into its three source streams.
 * The MT slot table is addressed as 2,960 rows of three u32 offsets. The
 * evaluator pre-increments its cursor from source_offsets[0]+17, so the
 * returned counts slice begins at +18. This does not infer a cycle:
 * the frame period is runtime state (actor+0x1A00), not this file descriptor.
 * Returns 0 on success, -1 for invalid arguments/ID, -2 for an empty motion,
 * and -3 for malformed or truncated source streams. */
int      mt_motion_view(const MtFile *f, uint32_t motion_id,
                        MtMotionView *out);
/* Iterate in slot order: cb(slot, record_off, record_size). Returns 0 on
 * success, -1 for bad arguments/allocation failure, or -3 for malformed data. */
int      mt_each(const MtFile *f, void (*cb)(uint32_t slot, uint32_t off,
                                             uint32_t len, void *ctx),
                 void *ctx);

#endif
