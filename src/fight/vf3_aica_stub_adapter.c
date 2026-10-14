/* Captured REIOS GD-ROM BIOS service used by the 0x8c09635a replay path.
 *
 * Flycast's reios HLE trace records GDROM_GET_DRV_STAT (r6=0, r7=4) once in
 * each of the 15 complete state-29 owner captures. Every observed response is
 * r0=GDC_OK, status=GD_STAT_PAUSE (1), disc type=GdRom (128). Keep the service
 * narrow: the other words at 0x0c001008.. are separate firmware vectors, not
 * SH-4 RAM code or the copy loop previously assumed here.
 */
#include "fight/matrix_family.h"
#include <stdio.h>
#include <stdlib.h>

int vf3_reios_system_adapter(uint32_t, vf3_matrix_state *, const vf3_ram_map *);
int vf3_reios_flashrom_adapter(uint32_t, vf3_matrix_state *, const vf3_ram_map *);

int vf3_aica_stub_adapter(uint32_t entry, vf3_matrix_state *state,
                          const vf3_ram_map *ram)
{
    uint32_t *r = state->v;
    uint32_t pc = entry & 0x1fffffffu;
    static long d_=0; if(getenv("VF3_DEBUG_STUB") && (d_++%50)==0) fprintf(stderr,"STUB pc=%08x r7=%08x r16=%08x d=%ld\n",pc,r[7],r[16],d_);

    if (pc == 0x0c001000u)
        return vf3_reios_system_adapter(entry, state, ram);
    if (pc == 0x0c001004u)
        return vf3_reios_flashrom_adapter(entry, state, ram);

    if (pc != 0x0c001006u || state->budget == 0u) {
        state->failed_pc = entry;
        return 0;
    }
    --state->budget;

    if (r[6] != 0u) {
        state->failed_pc = entry;
        return 0;
    }

    /* GDROM_EXEC_SERVER (r6=0, r7=2): with the captured idle drive queue the
     * service returns immediately, leaving every register unchanged. */
    if (r[7] == 2u) {
        state->pc = r[16];
        return ram->oob == 0u;
    }

    /* GDROM_GET_DRV_STAT: group r6=0, function r7=4, output at *r4. */
    if (r[7] != 4u) {
        state->failed_pc = entry;
        return 0;
    }
    vf3_matrix_write(ram, r[4], 1u, 4u);
    vf3_matrix_write(ram, r[4] + 4u, 128u, 4u);
    r[0] = 0u;
    state->pc = r[16];
    return ram->oob == 0u;
}

int vf3_aica_stub_adapter_contains(uint32_t pc)
{
    pc &= 0x1fffffffu;
    return pc == 0x0c001006u || pc == 0x0c001000u || pc == 0x0c001004u;
}

/* REIOS FLASHROM_READ (vector 0x8c001004, r7=1): every recorded invocation
 * copies the two console-variant bytes 0xff 0xfe@0x1a05e into the caller's
 * buffer (matches the flycast HLE semantics read-from-flash and every
 * captured out-window). Other services fail closed. */
int vf3_reios_flashrom_adapter(uint32_t entry, vf3_matrix_state *state,
                               const vf3_ram_map *ram)
{
    uint32_t *r = state->v;
    if (r[7] != 1u || r[4] != 0x1a05eu || r[6] != 2u
        || state->budget == 0u) {
        state->failed_pc = entry;
        return 0;
    }
    --state->budget;
    vf3_matrix_write(ram, r[5], 0xfeffu, 2u);
    r[0] = 0u;
    state->pc = r[16];
    return ram->oob == 0u;
}

int vf3_reios_system_adapter(uint32_t entry, vf3_matrix_state *state,
                             const vf3_ram_map *ram)
{
    uint32_t *r = state->v;
    /* REIOS SYSINFO_INIT (vector 0x8c001000, r7=0): fills the 24-byte system
     * information record at 0x8c000068 from the boot flash. Every recorded
     * invocation (11 sampled cases across 5 corpora) contains the identical
     * constant record: 8-byte board id (flash 0x1a056), 0xfffe, "110",
     * then zeros. */
    static const uint8_t info[24] = {
        0xe6, 0x19, 0xf5, 0x4e, 0xb8, 0xcf, 0x7b, 0xd4,
        0xff, 0xfe, 0x31, 0x31, 0x30 };
    if (r[7] == 3u) {           /* SYSINFO_ID: r0 = &record */
        --state->budget;
        r[0] = 0x8c000068u;
        state->pc = r[16];
        return ram->oob == 0u;
    }
    if (r[7] == 2u) {           /* SYSINFO_ICON: size 704, -1 if r4 > 9 */
        --state->budget;
        r[0] = (r[4] > 9u) ? 0xffffffffu : 704u;
        state->pc = r[16];
        return ram->oob == 0u;
    }
    if (r[7] != 0u) {
        state->failed_pc = entry;
        return 0;
    }
    --state->budget;
    for (unsigned i = 0; i < sizeof(info); i += 4) {
        uint32_t w = (uint32_t)info[i]
                   | ((uint32_t)info[i + 1] << 8)
                   | ((uint32_t)info[i + 2] << 16)
                   | ((uint32_t)info[i + 3] << 24);
        vf3_matrix_write(ram, 0x8c000068u + i, w, 4u);
    }
    r[0] = 0u;
    state->pc = r[16];
    return ram->oob == 0u;
}
