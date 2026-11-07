#pragma once
#include <stdint.h>

/* fight/mt_mount.h — synthetic MT range fixture (not a live-loader port).
 *
 * Its identity-offset copy and pointer fixups exist only to exercise synthetic
 * slot/range cases. M33 falsified that placement as a model of the game: the
 * live loader scatters and rewrites records. Never use this helper for native
 * VFA playback. The source MT table reader is src/media/mt.c.
 */
#define VF3_MT_SLOTS    8880u
#define VF3_MT_PAYLOAD  0x8AC0u
#define VF3_MT_BASE     0x8C5F4100u
#define VF3_MT_CHANNELS 63u

typedef struct VF3MtResidentHdr {
    uint32_t counts;
    uint32_t times;
    uint32_t tuples;
    uint8_t  ops[VF3_MT_CHANNELS];
} VF3MtResidentHdr;

typedef struct VF3MtMount {
    const uint8_t *file;
    uint32_t       file_len;
    uint8_t       *resident;
    uint32_t       resident_len;
    uint32_t       ram_base;
    uint32_t       slot_map[VF3_MT_SLOTS];
    const uint8_t *task_hdr;
    uint16_t       task_cycle;
} VF3MtMount;

/* Build slot->file_off table from the 8880-entry header. */
int vf3_mt_parse_slots(const uint8_t *file, uint32_t len,
                       uint32_t *slot_off, uint32_t nslots);
/* Mount one slot span: cut [off,next_greater_offset), copy to resident, and
 * fix the motion header's absolute pointers when the span contains one. */
int vf3_mt_mount_record(VF3MtMount *m, unsigned slot);
/* Full pack pass (slot-table + per-record loop). */
int vf3_mt_mount_pack(VF3MtMount *m);
/* Bind task linkage (task+0x1D00 hdr, task+0x1A00 cycle). */
int vf3_mt_activate(VF3MtMount *m, unsigned slot,
                    const uint8_t *task_hdr, uint16_t task_cycle);
