#pragma once
/* sys/bios_syscall.h - guest-visible calling convention of the BIOS GD-ROM syscall (pointer word at 0x8C0000BC -> REIOS entry 0x8C001006, r6 = 0).
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

/* Deterministic clock: the original advances transfers from a scheduler timer. A caller without one can let each
 * GET_CMD_STAT poll of the loader loop stand for one timer tick: with `gd_poll_clock` set (the default of
 * vf3_bios_gd_syscall_clocked), every GET_CMD_STAT that finds the drive BUSY first runs one vf3_gd_sched_step. */
/* Only every `polls`-th busy poll runs a scheduler step (default 1). The emulator's REIOS drive moved 5 sectors in 179 polls
 * of state 30 (docs/re/reios_exec_server.md), so a per-poll step runs far ahead of the real cadence. */
void vf3_bios_gd_set_poll_divider(uint32_t polls);
/* Cycle-based clock (overrides the divider): every busy poll costs `per_poll` SH-4 cycles and the drive runs one scheduler
 * step per `per_step` cycles. Measured on the emulator (state 30, VF3_GDLOG_TIME): polls 2688 cycles apart, one 5-sector
 * step every 1,000,000 cycles (5 ms at 200 MHz). */
void vf3_bios_gd_set_cycle_clock(uint32_t per_poll, uint32_t per_step);
/* Time that passes outside the polls (interrupt handlers, other work) also moves the drive. */
void vf3_bios_gd_advance_cycles(vf3_gdrom *gd, uint64_t cycles);
int vf3_bios_gd_syscall_clocked(vf3_gdrom *gd, const vf3_guest_mem *mem, const uint32_t r[8], uint32_t *r0_out);

/* run one syscall; returns 1 and stores r0 in *r0_out when handled, 0 otherwise */
int vf3_bios_gd_syscall(vf3_gdrom *gd, const vf3_guest_mem *mem, const uint32_t r[8], uint32_t *r0_out);
