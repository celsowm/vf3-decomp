/* fight/mt_mount.c — MT pack mount model (M52/M53). */
#include "mt_mount.h"
#include <string.h>

static uint32_t rd32le(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static void wr32le(uint8_t *p, uint32_t v)
{
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

int vf3_mt_parse_slots(const uint8_t *file, uint32_t len,
                       uint32_t *slot_off, uint32_t nslots)
{
    if (!file || !slot_off || nslots < VF3_MT_SLOTS)
        return -1;
    if (len < VF3_MT_PAYLOAD)
        return -2;
    for (uint32_t s = 0; s < VF3_MT_SLOTS; s++) {
        uint32_t v = rd32le(file + s * 4);
        if (v && (v < VF3_MT_PAYLOAD || v >= len))
            return -3;
        slot_off[s] = v;
    }
    return 0;
}

int vf3_mt_mount_record(VF3MtMount *m, unsigned slot)
{
    uint32_t file_off, next_off, rec_len, res_off;
    unsigned s;
    if (!m || !m->file || !m->resident || slot >= VF3_MT_SLOTS ||
        m->file_len < VF3_MT_PAYLOAD)
        return -1;
    file_off = rd32le(m->file + slot * 4);
    if (file_off == 0)
        return -2;
    if (file_off < VF3_MT_PAYLOAD || file_off >= m->file_len)
        return -3;
    /* Slot numbers are an index, not a file-order list. Bound this record by
     * the nearest greater payload offset across the whole slot table. */
    next_off = m->file_len;
    for (s = 0; s < VF3_MT_SLOTS; s++) {
        uint32_t v = rd32le(m->file + s * 4);
        if (v && (v < VF3_MT_PAYLOAD || v >= m->file_len))
            return -3;
        if (v > file_off && v < next_off)
            next_off = v;
    }
    if (next_off <= file_off)
        return -3;
    rec_len = next_off - file_off;
    /* Synthetic placement retained for the old range-check fixture only.
     * M33 falsified this identity-offset model: the game scatters and rewrites
     * records. This helper is not the live loader and must not be used by the
     * native VFA asset path. */
    res_off = file_off;
    if ((uint64_t)res_off + rec_len > m->resident_len)
        return -4;
    memcpy(m->resident + res_off, m->file + file_off, rec_len);
    /* fix hdr abs ptrs if record looks like a motion header block:
     * hdr[0..2] file-abs -> resident-abs (ram_base + res_off delta). */
    if (rec_len >= 12 + VF3_MT_CHANNELS) {
        uint32_t c0 = rd32le(m->resident + res_off);
        uint32_t c1 = rd32le(m->resident + res_off + 4);
        uint32_t c2 = rd32le(m->resident + res_off + 8);
        /* only rewrite pointers that fall inside file bounds */
        if (c0 < m->file_len)
            wr32le(m->resident + res_off, m->ram_base + c0);
        if (c1 < m->file_len)
            wr32le(m->resident + res_off + 4, m->ram_base + c1);
        if (c2 < m->file_len)
            wr32le(m->resident + res_off + 8, m->ram_base + c2);
    }
    m->slot_map[slot] = res_off;
    return (int)rec_len;
}

int vf3_mt_mount_pack(VF3MtMount *m)
{
    int n = 0;
    unsigned s;
    if (!m || !m->file || !m->resident || m->file_len < VF3_MT_PAYLOAD)
        return -1;
    for (s = 0; s < VF3_MT_SLOTS; s++) {
        uint32_t v = (m->file_len >= 4) ? rd32le(m->file + s * 4) : 0;
        if (v == 0)
            continue;
        int rc = vf3_mt_mount_record(m, s);
        if (rc < 0)
            return rc;
        if (rc > 0)
            n++;
    }
    return n;
}

int vf3_mt_activate(VF3MtMount *m, unsigned slot,
                    const uint8_t *task_hdr, uint16_t task_cycle)
{
    if (!m || slot >= VF3_MT_SLOTS)
        return -1;
    if (m->slot_map[slot] == 0 && slot != 0)
        return -2;
    m->task_hdr = task_hdr;
    m->task_cycle = task_cycle;
    return 0;
}
