/* POL model package (clean-room, per docs/formats/POL.md).
 * Header nibble + section table + float-vertex blocks are characterized;
 * object chain semantics are work-in-progress upstream.
 */
#ifndef VF3_POL_H
#define VF3_POL_H

#include <stdint.h>

typedef struct {
    uint32_t hdr_marker;   /* 0x200 */
    uint32_t build_stamp;  /* 0x19981021 */
    uint32_t sig;          /* per-file: likely counts */
    uint16_t parts_lo;     /* +0x0C low */
    uint16_t parts_hi;     /* +0x0C high */
    uint32_t table_base;   /* +0x10, should be 0x30 */
    uint32_t table_span;   /* +0x14 */
    uint32_t geom_size;    /* +0x18 */
    uint32_t tex_tag;      /* +0x1C */
} PolHeader;

/* 0 on success */
int pol_header(const void *data, uint32_t size, PolHeader *out);

/* walk contiguous 3-float blocks (-8..8); cb(off, triple_count) */
int pol_scan_floats(const void *data, uint32_t size, uint32_t min_len,
                    void (*cb)(uint32_t off, uint32_t triples, void *ctx),
                    void *ctx);

#endif
