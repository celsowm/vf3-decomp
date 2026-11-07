#include "mt.h"

#include <stdlib.h>
#include <string.h>

static uint32_t rd32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

int mt_parse(const void *vdata, uint32_t size, MtFile *out)
{
    const uint8_t *d = (const uint8_t *)vdata;
    uint32_t i, n = 0, first = 0;
    if (!out)
        return -1;
    memset(out, 0, sizeof *out);
    if (!d || size < MT_PAYLOAD_FLOOR)
        return -1;
    for (i = 0; i < MT_SLOTS; ++i) {
        uint32_t v = rd32(d + i * 4);
        if (!v)
            continue;
        if (v < MT_PAYLOAD_FLOOR || v >= size)
            return -3;
        if (!first || v < first)
            first = v;
        ++n;
    }
    if (!n)
        return -2;
    out->data = d;
    out->size = size;
    out->first_record_off = first;
    out->count = n;
    return 0;
}

int mt_record(const MtFile *f, uint32_t slot, uint32_t *off_out,
              uint32_t *len_out)
{
    uint32_t off, next_off, i;
    if (!f || !f->data || !off_out || !len_out || slot >= MT_SLOTS ||
        f->size < MT_PAYLOAD_FLOOR)
        return -1;
    off = rd32(f->data + slot * 4u);
    if (!off)
        return -2;
    if (off < MT_PAYLOAD_FLOOR || off >= f->size)
        return -3;
    next_off = f->size;
    for (i = 0; i < MT_SLOTS; ++i) {
        const uint32_t candidate = rd32(f->data + i * 4u);
        if (!candidate)
            continue;
        if (candidate < MT_PAYLOAD_FLOOR || candidate >= f->size)
            return -3;
        if (candidate > off && candidate < next_off)
            next_off = candidate;
    }
    if (next_off <= off)
        return -3;
    *off_out = off;
    *len_out = next_off - off;
    return 0;
}

int mt_motion_view(const MtFile *f, uint32_t motion_id, MtMotionView *out)
{
    MtMotionView view;
    uint32_t first_slot, record_off[3], record_len[3];
    uint32_t keyed_channels = 0;
    uint64_t time_bytes = 0, tuple_bytes = 0;
    uint32_t count_index = 0;

    if (!out)
        return -1;
    memset(out, 0, sizeof *out);
    memset(&view, 0, sizeof view);
    if (!f || !f->data || f->size < MT_PAYLOAD_FLOOR ||
        motion_id == 0 || motion_id > MT_MOTION_ROWS)
        return -1;

    first_slot = (motion_id - 1u) * 3u;
    for (uint32_t part = 0; part < 3u; ++part) {
        const uint32_t slot = first_slot + part;
        const uint32_t offset = rd32(f->data + slot * 4u);
        if (offset == 0u) {
            if (part == 0u &&
                rd32(f->data + (first_slot + 1u) * 4u) == 0u &&
                rd32(f->data + (first_slot + 2u) * 4u) == 0u)
                return -2;
            return -3;
        }
        if (mt_record(f, slot, &record_off[part], &record_len[part]) != 0 ||
            record_off[part] != offset)
            return -3;
        view.source_offsets[part] = offset;
    }

    /* 0x8c09d5ae reads the descriptor word, then unpacks 16 opcode bytes
     * beginning at +2. The evaluator's count cursor pre-increments the
     * pointer it receives, so count bytes begin at +18 (the pointer itself is
     * +17). */
    if (record_len[0] < 18u)
        return -3;
    view.descriptor_word = (uint16_t)((uint16_t)f->data[record_off[0]] |
        ((uint16_t)f->data[record_off[0] + 1u] << 8));
    for (uint32_t byte_index = 0; byte_index < 16u; ++byte_index) {
        const uint8_t packed = f->data[record_off[0] + 2u + byte_index];
        for (uint32_t field = 0; field < 4u; ++field) {
            const uint32_t channel = byte_index * 4u + field;
            const uint8_t op = (uint8_t)((packed >> (6u - field * 2u)) & 3u);
            if (channel < MT_MOTION_CHANNELS) {
                view.ops[channel] = op;
                if (op >= 2u)
                    ++keyed_channels;
            }
        }
    }
    if (keyed_channels > record_len[0] - 18u)
        return -3;

    view.motion_id = motion_id;
    view.counts = f->data + record_off[0] + 18u;
    view.counts_size = keyed_channels;
    for (uint32_t channel = 0; channel < MT_MOTION_CHANNELS; ++channel) {
        const uint8_t op = view.ops[channel];
        uint32_t count = 0;
        if (op >= 2u)
            count = view.counts[count_index++];
        time_bytes += count;
        if (op == 1u)
            tuple_bytes += 4u;
        else if (op == 2u)
            tuple_bytes += ((uint64_t)count + 2u) * 4u;
        else if (op >= 3u)
            /* The exact-key branch advances by 12*count+16 bytes; the
             * interpolation branch advances by 12*count+8. Bound for either. */
            tuple_bytes += (uint64_t)count * 12u + 16u;
        if (time_bytes > SIZE_MAX || tuple_bytes > SIZE_MAX)
            return -3;
    }
    if (time_bytes > record_len[1] || tuple_bytes > record_len[2])
        return -3;

    view.times = f->data + record_off[1];
    view.times_size = (size_t)time_bytes;
    view.tuples = f->data + record_off[2];
    view.tuples_size = (size_t)tuple_bytes;
    *out = view;
    return 0;
}

typedef struct {
    uint32_t slot;
    uint32_t off;
    uint32_t len;
} MtRow;

static int row_by_offset(const void *a, const void *b)
{
    const MtRow *left = (const MtRow *)a;
    const MtRow *right = (const MtRow *)b;
    if (left->off < right->off) return -1;
    if (left->off > right->off) return 1;
    if (left->slot < right->slot) return -1;
    if (left->slot > right->slot) return 1;
    return 0;
}

static int row_by_slot(const void *a, const void *b)
{
    const MtRow *left = (const MtRow *)a;
    const MtRow *right = (const MtRow *)b;
    if (left->slot < right->slot) return -1;
    if (left->slot > right->slot) return 1;
    return 0;
}

int mt_each(const MtFile *f, void (*cb)(uint32_t slot, uint32_t off,
                                        uint32_t len, void *ctx),
            void *ctx)
{
    MtRow *rows;
    uint32_t n = 0;
    if (!f || !f->data || !cb || f->size < MT_PAYLOAD_FLOOR)
        return -1;
    rows = (MtRow *)malloc((size_t)MT_SLOTS * sizeof *rows);
    if (!rows)
        return -1;
    for (uint32_t slot = 0; slot < MT_SLOTS; ++slot) {
        const uint32_t off = rd32(f->data + slot * 4u);
        if (!off)
            continue;
        if (off < MT_PAYLOAD_FLOOR || off >= f->size) {
            free(rows);
            return -3;
        }
        rows[n].slot = slot;
        rows[n].off = off;
        rows[n].len = 0;
        ++n;
    }
    if (!n) {
        free(rows);
        return 0;
    }
    qsort(rows, n, sizeof *rows, row_by_offset);
    for (uint32_t i = 0; i < n;) {
        uint32_t end = i + 1;
        while (end < n && rows[end].off == rows[i].off)
            ++end;
        const uint32_t next_off = end < n ? rows[end].off : f->size;
        if (next_off <= rows[i].off) {
            free(rows);
            return -3;
        }
        for (uint32_t j = i; j < end; ++j)
            rows[j].len = next_off - rows[j].off;
        i = end;
    }
    qsort(rows, n, sizeof *rows, row_by_slot);
    for (uint32_t i = 0; i < n; ++i)
        cb(rows[i].slot, rows[i].off, rows[i].len, ctx);
    free(rows);
    return 0;
}
