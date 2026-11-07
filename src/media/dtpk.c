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
    Dtpk parsed = {0};
    uint32_t offs[DTPK_MAX_SECTIONS];
    int i, n;

    if (!out)
        return -1;
    memset(out, 0, sizeof *out);
    if (!d || size < 0x60)
        return -1;
    if (rd32(d) != DTPK_MAGIC)
        return -2;
    if (rd32(d + 8) != size)
        return -3;

    parsed.data = d;
    parsed.data_size = size;
    parsed.serial = rd32(d + 4);
    parsed.size = rd32(d + 8);
    parsed.tag = rd32(d + 0x10);

    for (i = 0; i < DTPK_MAX_SECTIONS; ++i)
        offs[i] = rd32(d + 0x20 + i * 4);

    /* Non-zero directory entries are sorted offsets; zero slots may be interleaved. */
    n = 0;
    for (i = 0; i < DTPK_MAX_SECTIONS; ++i) {
        if (!offs[i])
            continue;
        if ((n == 0 && offs[i] != 0x60u) || offs[i] < 0x60u ||
            offs[i] >= size ||
            (n && offs[i] <= parsed.sections[n - 1].offset))
            return -4;
        parsed.sections[n].offset = offs[i];
        ++n;
    }
    if (n == 0)
        return -4;
    parsed.nsections = n;
    for (i = 0; i < n; ++i) {
        uint32_t end = (i + 1 < n) ? parsed.sections[i + 1].offset : size;
        if (end <= parsed.sections[i].offset)
            return -4;
        parsed.sections[i].size = end - parsed.sections[i].offset;
    }
    *out = parsed;
    return 0;
}

int dtpk_get(const Dtpk *p, int index, const uint8_t **ptr, uint32_t *size)
{
    if (!ptr || !size)
        return -1;
    *ptr = NULL;
    *size = 0;
    if (!p || !p->data || p->data_size < 0x60u ||
        p->size != p->data_size || index < 0 || p->nsections <= 0 ||
        p->nsections > DTPK_MAX_SECTIONS || index >= p->nsections)
        return -1;
    if (p->sections[index].offset < 0x60u ||
        p->sections[index].offset >= p->data_size ||
        !p->sections[index].size ||
        p->sections[index].size > p->data_size - p->sections[index].offset)
        return -1;
    *ptr = p->data + p->sections[index].offset;
    *size = p->sections[index].size;
    return 0;
}
