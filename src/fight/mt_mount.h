#pragma once
#include <stdint.h>

/* fight/mt_mount.h — MT pack mount: file -> per-record resident (M52/M53).
 *
 * M33 falsified uniform +0x27B0: resident is per-record scattered, not a
 * full file image. File header maps at dump+0x39C3 only at header; 64-B
 * probes scatter (+0x29A6C/+0x24194/+0x28C60/+0x3A34/+0x2C514), ~1681 absent
 * (table/encoding rewrites). Slot table: 8880 u32 (tools/mtmap.py).
 * Evaluator layout: docs/re/mt_vm.md (hdr[0..2] abs ptrs, ops[63] @hdr+12).
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

/* Build slot->file_off table from the 8880-entry header (mtmap.py rule). */
int vf3_mt_parse_slots(const uint8_t *file, uint32_t len,
                       uint32_t *slot_off, uint32_t nslots);
/* Mount one record: cut [off,next_off), copy to resident, fix hdr abs ptrs. */
int vf3_mt_mount_record(VF3MtMount *m, unsigned slot);
/* Full pack pass (slot-table + per-record loop). */
int vf3_mt_mount_pack(VF3MtMount *m);
/* Bind task linkage (task+0x1D00 hdr, task+0x1A00 cycle). */
int vf3_mt_activate(VF3MtMount *m, unsigned slot,
                    const uint8_t *task_hdr, uint16_t task_cycle);
