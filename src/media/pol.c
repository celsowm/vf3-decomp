#include "pol.h"

#include <stdlib.h>
#include <string.h>

static uint16_t rd16(const uint8_t *p)
{
    return (uint16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
}

static uint32_t rd32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

int pol_header(const void *vdata, uint32_t size, PolHeader *out)
{
    const uint8_t *d = (const uint8_t *)vdata;
    if (!d || !out || size < 0x30)
        return -1;
    out->hdr_marker = rd32(d + 0x00);
    out->build_stamp = rd32(d + 0x04);
    out->sig = rd32(d + 0x08);
    out->slot_count = rd16(d + 0x0C);
    out->texture_count = rd16(d + 0x0E);
    out->slot_table_offset = rd32(d + 0x10);
    out->model_block_offset = rd32(d + 0x14);
    out->geom_size = rd32(d + 0x18);
    out->tex_tag = rd32(d + 0x1C);
    return (out->hdr_marker == 0x200) ? 0 : -2;
}

int pol_slots(const void *vdata, uint32_t size, PolSlot *rows_out,
              uint32_t cap, uint32_t *count_out)
{
    const uint8_t *d = (const uint8_t *)vdata;
    PolHeader h;
    if (count_out)
        *count_out = 0;
    if (!d || pol_header(vdata, size, &h) != 0 ||
        h.slot_table_offset < 0x30 || h.slot_table_offset > size ||
        h.slot_count > (size - h.slot_table_offset) / 4u)
        return -1;
    if (count_out)
        *count_out = h.slot_count;
    if (h.slot_count > cap || (h.slot_count && !rows_out))
        return -2;
    for (uint32_t i = 0; i < h.slot_count; ++i) {
        const uint32_t raw = rd32(d + h.slot_table_offset + i * 4u);
        const uint32_t candidate = raw & ~1u;
        PolSlot *row = &rows_out[i];
        row->raw = raw;
        row->offset_candidate = candidate;
        row->tagged = (uint8_t)(raw & 1u);
        row->in_file = (uint8_t)(candidate >= 0x30u && candidate < size);
        row->reserved = 0;
    }
    return 0;
}

static int slot_span_compare(const void *a, const void *b)
{
    const PolSlotSpan *left = (const PolSlotSpan *)a;
    const PolSlotSpan *right = (const PolSlotSpan *)b;
    if (left->start < right->start) return -1;
    if (left->start > right->start) return 1;
    if (left->slot_index < right->slot_index) return -1;
    if (left->slot_index > right->slot_index) return 1;
    return 0;
}

int pol_slot_spans(const void *vdata, uint32_t size, PolSlotSpan *rows_out,
                   uint32_t cap, uint32_t *count_out)
{
    PolSlot *slots = NULL;
    PolSlotSpan *spans = NULL;
    uint32_t slot_count = 0, span_count = 0;
    int slot_rc;
    if (count_out)
        *count_out = 0;
    if (!vdata)
        return -1;
    slot_rc = pol_slots(vdata, size, NULL, 0, &slot_count);
    if ((slot_rc != -2 && slot_rc != 0) || (slot_rc == 0 && slot_count != 0))
        return -1;
    if (slot_count) {
        slots = (PolSlot *)malloc((size_t)slot_count * sizeof *slots);
        if (!slots || pol_slots(vdata, size, slots, slot_count, &slot_count) != 0) {
            free(slots);
            return -1;
        }
    }
    for (uint32_t i = 0; i < slot_count; ++i)
        span_count += slots[i].tagged != 0;
    if (count_out)
        *count_out = span_count;
    if (span_count) {
        spans = (PolSlotSpan *)malloc((size_t)span_count * sizeof *spans);
        if (!spans) {
            free(slots);
            return -1;
        }
        uint32_t at = 0;
        for (uint32_t i = 0; i < slot_count; ++i) {
            if (!slots[i].tagged)
                continue;
            if (!slots[i].in_file) {
                free(spans);
                free(slots);
                return -1;
            }
            spans[at].slot_index = i;
            spans[at].start = slots[i].offset_candidate;
            spans[at].end = size;
            ++at;
        }
        qsort(spans, span_count, sizeof *spans, slot_span_compare);
        for (uint32_t i = 0; i < span_count;) {
            uint32_t next = i + 1u;
            while (next < span_count && spans[next].start == spans[i].start)
                ++next;
            const uint32_t end = next < span_count ? spans[next].start : size;
            for (uint32_t j = i; j < next; ++j)
                spans[j].end = end;
            i = next;
        }
    }
    if (span_count > cap || (span_count && !rows_out)) {
        free(spans);
        free(slots);
        return -2;
    }
    if (span_count)
        memcpy(rows_out, spans, (size_t)span_count * sizeof *spans);
    free(spans);
    free(slots);
    return 0;
}

static int data_span_compare(const void *a, const void *b)
{
    const PolDataSpan *left = (const PolDataSpan *)a;
    const PolDataSpan *right = (const PolDataSpan *)b;
    if (left->start < right->start) return -1;
    if (left->start > right->start) return 1;
    if (left->slot_index < right->slot_index) return -1;
    if (left->slot_index > right->slot_index) return 1;
    return 0;
}

int pol_data_spans(const void *vdata, uint32_t size, PolDataSpan *rows_out,
                   uint32_t cap, uint32_t *count_out)
{
    PolSlot *slots = NULL;
    PolDataSpan *spans = NULL;
    uint32_t slot_count = 0, span_count = 0;
    int slot_rc;
    if (count_out)
        *count_out = 0;
    if (!vdata)
        return -1;
    slot_rc = pol_slots(vdata, size, NULL, 0, &slot_count);
    if ((slot_rc != -2 && slot_rc != 0) || (slot_rc == 0 && slot_count != 0))
        return -1;
    if (slot_count) {
        slots = (PolSlot *)malloc((size_t)slot_count * sizeof *slots);
        if (!slots || pol_slots(vdata, size, slots, slot_count, &slot_count) != 0) {
            free(slots);
            return -1;
        }
    }
    for (uint32_t i = 0; i < slot_count; ++i)
        span_count += slots[i].raw != 0;
    if (count_out)
        *count_out = span_count;
    if (span_count) {
        spans = (PolDataSpan *)malloc((size_t)span_count * sizeof *spans);
        if (!spans) {
            free(slots);
            return -1;
        }
        uint32_t at = 0;
        for (uint32_t i = 0; i < slot_count; ++i) {
            if (slots[i].raw == 0)
                continue;
            if (!slots[i].in_file) {
                free(spans);
                free(slots);
                return -1;
            }
            spans[at].slot_index = i;
            spans[at].start = slots[i].offset_candidate;
            spans[at].end = size;
            spans[at].tagged = slots[i].tagged;
            memset(spans[at].reserved, 0, sizeof spans[at].reserved);
            ++at;
        }
        qsort(spans, span_count, sizeof *spans, data_span_compare);
        for (uint32_t i = 0; i < span_count;) {
            uint32_t next = i + 1u;
            while (next < span_count && spans[next].start == spans[i].start)
                ++next;
            const uint32_t end = next < span_count ? spans[next].start : size;
            for (uint32_t j = i; j < next; ++j)
                spans[j].end = end;
            i = next;
        }
    }
    if (span_count > cap || (span_count && !rows_out)) {
        free(spans);
        free(slots);
        return -2;
    }
    if (span_count)
        memcpy(rows_out, spans, (size_t)span_count * sizeof *spans);
    free(spans);
    free(slots);
    return 0;
}

int pol_textures(const void *vdata, uint32_t size, PolTextureDesc *rows_out,
                 uint32_t cap, uint32_t *count_out)
{
    const uint8_t *d = (const uint8_t *)vdata;
    PolHeader h;
    if (count_out)
        *count_out = 0;
    if (!d || pol_header(vdata, size, &h) != 0 ||
        h.model_block_offset < 0x30 || h.model_block_offset > size ||
        h.texture_count > (size - h.model_block_offset) / 16u)
        return -1;
    if (count_out)
        *count_out = h.texture_count;
    if (h.texture_count > cap || (h.texture_count && !rows_out))
        return -2;
    for (uint32_t i = 0; i < h.texture_count; ++i) {
        const uint8_t *p = d + h.model_block_offset + i * 16u;
        const uint32_t dimensions = rd32(p);
        PolTextureDesc *row = &rows_out[i];
        row->width = (uint16_t)dimensions;
        row->height = (uint16_t)(dimensions >> 16);
        row->raw_flags = rd32(p + 4);
        row->data_offset = rd32(p + 8);
        row->reserved = rd32(p + 12);
    }
    return 0;
}

static int sane_triple(const uint8_t *d, float *x, float *y, float *z)
{
    float a, b, c;
    uint32_t ua = rd32(d), ub = rd32(d + 4), uc = rd32(d + 8);
    memcpy(&a, &ua, sizeof a);
    memcpy(&b, &ub, sizeof b);
    memcpy(&c, &uc, sizeof c);
    if (a < -8.f || a > 8.f) return 0;
    if (b < -8.f || b > 8.f) return 0;
    if (c < -8.f || c > 8.f) return 0;
    *x = a; *y = b; *z = c;
    return 1;
}

int pol_scan_floats(const void *vdata, uint32_t size, uint32_t min_len,
                    void (*cb)(uint32_t off, uint32_t triples, void *ctx),
                    void *ctx)
{
    const uint8_t *d = (const uint8_t *)vdata;
    uint32_t off = 0, found = 0;
    if (!d || !cb)
        return -1;
    while (size - off >= 12u) {
        float x, y, z;
        if (!sane_triple(d + off, &x, &y, &z) ||
            (x == 0.f && y == 0.f && z == 0.f)) {
            off += 4;
            continue;
        }
        uint32_t start = off, cnt = 0;
        off += 12;
        while (size - off >= 12u && sane_triple(d + off, &x, &y, &z)) {
            off += 12;
            cnt++;
        }
        if (cnt >= min_len) {
            cb(start, cnt, ctx);
            found++;
        }
    }
    return (int)found;
}
