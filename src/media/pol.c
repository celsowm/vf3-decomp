#include "pol.h"

static uint32_t rd32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

int pol_header(const void *vdata, uint32_t size, PolHeader *out)
{
    const uint8_t *d = (const uint8_t *)vdata;
    if (!d || size < 0x30)
        return -1;
    out->hdr_marker = rd32(d + 0x00);
    out->build_stamp = rd32(d + 0x04);
    out->sig = rd32(d + 0x08);
    out->parts_lo = (uint16_t)rd32(d + 0x0C);
    out->parts_hi = (uint16_t)(rd32(d + 0x0C) >> 16);
    out->table_base = rd32(d + 0x10);
    out->table_span = rd32(d + 0x14);
    out->geom_size = rd32(d + 0x18);
    out->tex_tag = rd32(d + 0x1C);
    return (out->hdr_marker == 0x200) ? 0 : -2;
}

static int sane_triple(const uint8_t *d, float *x, float *y, float *z)
{
    float a, b, c;
    /* conservative float read */
    uint32_t ua = rd32(d), ub = rd32(d + 4), uc = rd32(d + 8);
    a = *(float *)&ua;
    b = *(float *)&ub;
    c = *(float *)&uc;
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
    while (off + 12 <= size) {
        float x, y, z;
        if (!sane_triple(d + off, &x, &y, &z) || (x == 0.f && y == 0.f &&
                                                  z == 0.f)) {
            off += 4;
            continue;
        }
        uint32_t start = off, cnt = 0;
        off += 12;
        while (off + 12 <= size && sane_triple(d + off, &x, &y, &z)) {
            off += 12;
            cnt++;
        }
        if (cnt >= min_len) {
            cb(start, cnt, ctx);
            found++;
        }
    }
    return found;
}
