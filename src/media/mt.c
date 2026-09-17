#include "mt.h"

static uint32_t rd32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

int mt_parse(const void *vdata, uint32_t size, MtFile *out)
{
    const uint8_t *d = (const uint8_t *)vdata;
    uint32_t i, n = 0, first = 0;
    if (!d || size < MT_PAYLOAD_FLOOR + 4)
        return -1;
    for (i = 0; i < MT_SLOTS; ++i) {
        uint32_t v = rd32(d + i * 4);
        if (v && v < size) {
            if (!first)
                first = v;
            ++n;
        }
    }
    if (!n)
        return -2;
    out->data = d;
    out->size = size;
    out->first_record_off = first;
    out->count = n;
    return 0;
}

void mt_each(const MtFile *f, void (*cb)(uint32_t slot, uint32_t off,
                                         uint32_t len, void *ctx),
             void *ctx)
{
    uint32_t prev_off = 0;
    uint32_t i;
    uint32_t last = 0;
    for (i = 0; i < MT_SLOTS; ++i) {
        uint32_t off = rd32(f->data + i * 4);
        if (!off || off >= f->size)
            continue;
        if (prev_off) {
            cb(last, prev_off, off - prev_off, ctx);
        }
        prev_off = off;
        last = i;
    }
    if (prev_off) {
        cb(last, prev_off, f->size - prev_off, ctx);
    }
}
