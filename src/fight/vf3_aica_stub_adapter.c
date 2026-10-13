/* Captured REIOS GD-ROM BIOS service used by the 0x8c09635a replay path.
 *
 * Flycast's reios HLE trace records GDROM_GET_DRV_STAT (r6=0, r7=4) once in
 * each of the 15 complete state-29 owner captures. Every observed response is
 * r0=GDC_OK, status=GD_STAT_PAUSE (1), disc type=GdRom (128). Keep the service
 * narrow: the other words at 0x0c001008.. are separate firmware vectors, not
 * SH-4 RAM code or the copy loop previously assumed here.
 */
#include "fight/matrix_family.h"

int vf3_aica_stub_adapter(uint32_t entry, vf3_matrix_state *state,
                          const vf3_ram_map *ram)
{
    uint32_t *r = state->v;
    uint32_t pc = entry & 0x1fffffffu;

    if (pc != 0x0c001006u || state->budget == 0u) {
        state->failed_pc = entry;
        return 0;
    }
    --state->budget;

    /* GDROM_GET_DRV_STAT: group r6=0, function r7=4, output at *r4. */
    if (r[6] != 0u || r[7] != 4u) {
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
    return (pc & 0x1fffffffu) == 0x0c001006u;
}
