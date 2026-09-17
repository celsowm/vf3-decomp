#include "dtpk.h"
#include <string.h>

static uint32_t rd32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

int dtpk_parse(const void *vdata, uint32_t size, Dtpk *out)
{
    const uint8_t *d = (const uint8_t *)vdata;
    uint32_t offs[DTPK_MAX_SECTIONS];
    int i, n;

    if (!d || size < 0x60)
        return -1;
    if (rd32(d) != DTPK_MAGIC)
        return -2;
    if (rd32(d + 8) != size)
        return -3;

    out->data = d;
    out->data_size = size;
    out->serial = rd32(d + 4);
    out->size = rd32(d + 8);
    out->tag = rd32(d + 0x10);

    for (i = 0; i < DTPK_MAX_SECTIONS; ++i)
        offs[i] = rd32(d + 0x20 + i * 4);

    /* collect non-zero sorted offsets (they appear in ascending order) */
    n = 0;
    for (i = 0; i < DTPK_MAX_SECTIONS; ++i) {
        if (offs[i] && offs[i] < size) {
            /* slots come pre-sorted; keep order */
            out->sections[n].offset = offs[i];
            out->sections[n].size = 0; /* fixed below */
            ++n;
        }
    }
    out->nsections = n;
    for (i = 0; i < n; ++i) {
        uint32_t end = (i + 1 < n) ? out->sections[i + 1].offset : size;
        if (end < out->sections[i].offset)
            return -4;
        out->sections[i].size = end - out->sections[i].offset;
    }
    return 0;
}

int dtpk_get(const Dtpk *p, int index, const uint8_t **ptr, uint32_t *size)
{
    if (!p || index < 0 || index >= p->nsections)
        return -1;
    *ptr = p->data + p->sections[index].offset;
    *size = p->sections[index].size;
    return 0;
}
