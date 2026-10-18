#pragma once
/* sys/bios_syscall.h - guest-visible calling convention of the BIOS GD-ROM syscall (vector 0x8C0000BC, r6 = 0).
 *
 * r7 selects the call: 0 REQ_CMD (r4 = command, r5 = pointer to 4 param words, returns the request id in r0),
 * 1 GET_CMD_STAT (r4 = request id, r5 = pointer to 4 result words, returns the status in r0),
 * 2 EXEC_SERVER, 3 INIT_SYSTEM. Anything else (r6 != 0 or an unmodelled r7) is reported unhandled. */
#include <stdint.h>

#include "sys/gdrom_hle.h"

typedef struct {
    void *ctx;
    uint32_t (*read32)(void *ctx, uint32_t addr);
    void (*write32)(void *ctx, uint32_t addr, uint32_t value);
} vf3_guest_mem;

/* run one syscall; returns 1 and stores r0 in *r0_out when handled, 0 otherwise */
int vf3_bios_gd_syscall(vf3_gdrom *gd, const vf3_guest_mem *mem, const uint32_t r[8], uint32_t *r0_out);
