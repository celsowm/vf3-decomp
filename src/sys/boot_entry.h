#ifndef VF3_BOOT_ENTRY_H
#define VF3_BOOT_ENTRY_H
#include "fight/matrix_family.h"

typedef enum {
    VF3_BOOT_OK = 0,
    VF3_BOOT_BAD_ENTRY,
    VF3_BOOT_BAD_IMAGE,
    VF3_BOOT_BAD_RAM,
    VF3_BOOT_UNSUPPORTED_CPU,
    VF3_BOOT_BUDGET
} vf3_boot_status;

typedef struct {
    vf3_boot_status status;
    uint32_t pc;                 /* handoff on success; validation site on failure */
    uint32_t instructions;
    uint32_t bytes_written;
} vf3_boot_result;

/* Original image-entry segments, never BIOS initializers. The caller supplies
 * the full existing CPU context and coherent RAM view. s->pc must identify the
 * segment entry (0C/8C/AC RAM alias). On success the exact JSR/JMP handoff is
 * returned in s->pc, without replacing PR with a harness sentinel. Unused CPU
 * fields, bank provenance and native continuation ownership are preserved.
 *
 * Validation is transactional: failures change neither CPU nor RAM. The whole
 * segment must fit the available native instruction budget. Instructions and
 * literal descriptors are read from caller RAM; no image-file fallback exists.
 * These functions do not model caches, MMU translation or asynchronous IRQs.
 * The caller must choose the architectural RAM view matching the input alias.
 * In particular, a cached CPU view is not raw physical RAM with dirty caches.
 */
vf3_boot_status vf3_boot_relocate(vf3_matrix_state *s, const vf3_ram_map *ram, vf3_boot_result *out);
vf3_boot_status vf3_boot_crt0(vf3_matrix_state *s, const vf3_ram_map *ram, vf3_boot_result *out);
#endif
