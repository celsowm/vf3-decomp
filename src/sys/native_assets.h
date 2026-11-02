#pragma once
/* sys/native_assets.h - the port's own asset bundle (tools/make_native_assets.py).
 *
 * The bundle replaces every Dreamcast artefact the host used to need:
 *
 *   boot.state   the cold-boot machine state (registers + 16 MiB RAM)
 *   disc.vf3     a packed 2048-byte-sector image of the retail data track,
 *                addressed by the same FADs the guest asks the GD-ROM for
 *
 * Once built, `vf3sdl` starts with no --state, no --gdi, no BIOS ROM and no
 * emulator savestate; it only reads the files in this directory.
 */
#include <stdint.h>
#include <stdio.h>

#include "sys/gdrom_hle.h"

typedef struct {
    char dir[512];
    char boot_state[512];
    FILE *disc;
    uint64_t *index;       /* per-LBA offset from data_offset; UINT64_MAX = zero */
    uint32_t first_lba;
    uint32_t nsectors;
    uint64_t data_offset;
} vf3_native_assets;

/* Open <dir>/disc.vf3 and point boot_state at <dir>/boot.state.  0 on success. */
int vf3_native_assets_open(vf3_native_assets *assets, const char *dir);
void vf3_native_assets_close(vf3_native_assets *assets);

/* The GD-ROM sector callback: `fad` is the guest's FAD, as in vf3_gdi_read_sector. */
int vf3_native_assets_read_sector(void *ctx, uint32_t fad, uint8_t out[VF3_GD_SECTOR]);

/* The path of the bundle's boot state (valid while `assets` is open). */
const char *vf3_native_assets_boot_state(const vf3_native_assets *assets);
