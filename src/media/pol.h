/* POL model package headers and tables (clean-room, see docs/formats/POL.md). */
#ifndef VF3_POL_H
#define VF3_POL_H

#include <stdint.h>

typedef struct {
    uint32_t hdr_marker;         /* +0x00, 0x200 */
    uint32_t build_stamp;        /* +0x04 */
    uint32_t sig;                /* +0x08, format meaning unresolved */
    uint16_t slot_count;         /* +0x0C */
    uint16_t texture_count;      /* +0x0E */
    uint32_t slot_table_offset;  /* +0x10 */
    uint32_t model_block_offset; /* +0x14, texture descriptors begin here */
    uint32_t geom_size;          /* +0x18, meaning unresolved */
    uint32_t tex_tag;            /* +0x1C, meaning unresolved */
} PolHeader;

typedef struct {
    uint32_t raw;
    uint32_t offset_candidate; /* raw with the low flag bit cleared */
    uint8_t tagged;            /* raw bit 0; preserve rather than interpret */
    uint8_t in_file;           /* candidate falls within this POL file */
    uint16_t reserved;
} PolSlot;

typedef struct {
    uint32_t slot_index;
    uint32_t start;
    uint32_t end; /* next tagged target, or end of file */
} PolSlotSpan;

typedef struct {
    uint32_t slot_index;
    uint32_t start;
    uint32_t end; /* next distinct slot target, or end of file */
    uint8_t tagged;
    uint8_t reserved[3];
} PolDataSpan;

typedef struct {
    uint16_t width;
    uint16_t height;
    uint32_t raw_flags;   /* format/usage meaning remains unresolved */
    uint32_t data_offset; /* byte offset into the companion .TEX file */
    uint32_t reserved;
} PolTextureDesc;

/* Return 0 on success. The fixed header is 0x30 bytes. */
int pol_header(const void *data, uint32_t size, PolHeader *out);

/* Read the slot table. Query required capacity with rows_out=NULL, cap=0;
 * returns -2 and sets count_out when the table is valid but the buffer is
 * too small. Returns -1 for invalid header/table bounds. */
int pol_slots(const void *data, uint32_t size, PolSlot *rows_out,
              uint32_t cap, uint32_t *count_out);

/* Return byte windows for tagged slot targets, sorted by file offset. Aliased
 * targets share a window. These windows identify where tagged targets stop
 * and the next one begins; their internal object/mesh format is not inferred
 * here. Capacity semantics match pol_slots. */
int pol_slot_spans(const void *data, uint32_t size, PolSlotSpan *rows_out,
                   uint32_t cap, uint32_t *count_out);

/* Return bounded byte windows for every nonzero slot, tagged or untagged.
 * Duplicate slot targets share a window. Rows are sorted by file offset then
 * slot index. Capacity semantics match pol_slots. */
int pol_data_spans(const void *data, uint32_t size, PolDataSpan *rows_out,
                   uint32_t cap, uint32_t *count_out);

/* Read the texture descriptors at model_block_offset. Descriptor order is
 * preserved; raw_flags are deliberately not decoded here. Capacity semantics
 * match pol_slots. */
int pol_textures(const void *data, uint32_t size, PolTextureDesc *rows_out,
                 uint32_t cap, uint32_t *count_out);

/* Walk candidate contiguous 3-float blocks (-8..8); cb(off, triple_count).
 * This is a reconnaissance helper, not POL object/mesh decoding. */
int pol_scan_floats(const void *data, uint32_t size, uint32_t min_len,
                    void (*cb)(uint32_t off, uint32_t triples, void *ctx),
                    void *ctx);

#endif
