/* fight/sd_slot_lookup.c — id -> sound-variant string lookup ("sd" slots)
 *
 * Provenance: 1ST_READ 0x8C068F86 (cand_sd_slot_lookup), 241 bytes.
 * Trace evidence (probe_dispatch3.bin, M10): 1411 hits over 240 frames with
 * r14 = 0x0CBEFBE0 constant (frame struct), r4..r6 = varying slot indices.
 *
 * Id/name map recovered from the (id,ptr) table at 0x8C068FC0 probing
 * runtime strings (RAM dump shots/ram_r15_372088506.bin):
 *   0xC7 -> "sd_passing_far"
 *   0xC8 -> "sd_passing_far_off"
 *   0xC9 -> "sd_Ak_01"
 *   0xCA -> "sd_Ak_02"
 * This lookup is the SH-side name for the sound driver "variant slot" used
 * when fight actions trigger sounds; the loop body is a 4-way braf switch
 * (period-4 u16 offsets 0x640/0x6ab/0x6b9/0x6bd).
 */
#include "sd_slot_lookup.h"

#include <stddef.h>

typedef struct {
    uint16_t id;
    const char *tag;   /* runtime-mirror name ("sd_..." signature) */
} SD_Slot;

static const SD_Slot SD_SLOTS[4] = {
    {0xC7, "sd_passing_far"},
    {0xC8, "sd_passing_far_off"},
    {0xC9, "sd_Ak_01"},
    {0xCA, "sd_Ak_02"},
};

/* SD slot table base, observed in RAM (fight state): 0x8C0D533C. The map
 * is tiny query surface; the binary keeps the (id,ptr) index adjacent to the
 * function (0x8C068FC0) — static layout, entries {u32 id, void* name_ptr}. */

const char *vf3_sd_slot_name(uint16_t id)
{
    for (size_t i = 0; i < sizeof(SD_SLOTS) / sizeof(SD_SLOTS[0]); ++i)
        if (SD_SLOTS[i].id == id)
            return SD_SLOTS[i].tag;
    return NULL;
}
