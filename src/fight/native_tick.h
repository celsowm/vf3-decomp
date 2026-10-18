/* native_tick.h - run one fight scheduler tick on host code only.
 *
 * The tick is vf3_matrix_family() on the scheduler entry (0x8C09616A) with the guest RAM image
 * the tick started from. Everything that executes is C in this tree: the readable ports of
 * readable.c where there is one, the generated adapters otherwise. There is no oracle and no
 * recorded effect to replay: a call nobody owns fails the tick (and is reported), it is never
 * papered over. This is the shipping-side twin of tests/tick_mixed.c, which runs the same code
 * next to the recompiled reference and the recorded device log.
 *
 * Hardware as the tick sees it (measured on 13 captured fight ticks): no device register is
 * ever read; the only writes outside RAM are QACR0/QACR1, the store-queue stores (folded to
 * 0x00xxxxxx) and the 32-byte PREF bursts into the Tile Accelerator, which are collected as
 * the tick's display-list words. */
#ifndef VF3_NATIVE_TICK_H
#define VF3_NATIVE_TICK_H

#include <stddef.h>
#include <stdint.h>

#include "sys/gdrom_hle.h"

#define VF3_NATIVE_RAM_BASE 0x0C000000u
#define VF3_NATIVE_RAM_LEN  0x01000000u
#define VF3_NATIVE_SCHED_ENTRY 0x8C09616Au
/* the loader stubs jump through the pointer word at 0x8C0000BC; REIOS fills it with this entry */
#define VF3_BIOS_SYSCALL_VECTOR 0x0C001006u

typedef struct {
    int ok;                       /* the entry returned to its caller */
    uint32_t pc, failed_pc;       /* where it stopped when not ok */
    unsigned steps_budget_used;   /* guest basic-block budget consumed */
    unsigned readable_calls;      /* calls served by readable ports */
    unsigned unowned_calls;       /* calls into code nobody ported (each one is a failure) */
    uint32_t first_unowned;
    unsigned bios_calls;          /* BIOS GD-ROM syscalls served by the attached model */
    unsigned device_reads, device_writes, ta_words, oob;
    const uint32_t *ta;           /* the TA FIFO words, in order; valid until the next run */
    uint32_t regs[54];            /* register file at exit, layout of matrix_family.h */
} vf3_native_tick_result;

/* Load the entry state of pair `pair` from a tools/tick_capture.py recording:
 * the 37 registers and the 16 MiB RAM image. *ram is malloc'd. Returns 1 on success. */
int vf3_native_load_snapshot(const char *path, unsigned pair, uint32_t regs[37], uint8_t **ram);
/* The extended (XF) bank of the last loaded entry, and the one the next run starts with. */
void vf3_native_get_xf(uint32_t xf[16]);
void vf3_native_set_xf(const uint32_t xf[16]);
/* The RAM and registers the recorded run ended with (the hardware reference for a whole-run comparison). */
int vf3_native_load_exit(const char *path, unsigned pair, uint32_t regs[37], uint8_t **ram);

/* Run the tick from `regs` on `ram` (modified in place). `gbr` is the global-state block the
 * fight tasks address with @(disp,GBR); the capture format does not carry it. */
int vf3_native_tick_run(uint8_t *ram, const uint32_t regs[37], uint32_t entry, uint32_t gbr,
                        vf3_native_tick_result *out);

/* Serve calls to the BIOS GD-ROM vector (VF3_BIOS_SYSCALL_VECTOR, r6 = 0) from `gd` instead of reporting them as
 * unowned code; sector transfers land in the RAM image of the running tick. Pass NULL to detach. The caller steps the
 * transfer with vf3_gd_sched_step() between ticks (the model has no clock). */
void vf3_native_attach_gdrom(vf3_gdrom *gd);
/* Called after every served BIOS poll; the callback may start a nested run (an interrupt taken inside the poll). */
void vf3_native_set_poll_hook(void (*hook)(void *), void *ctx);
/* End the run when control reaches `pc` (a loop head) instead of at a return to the caller; 0 restores the default. */
void vf3_native_set_stop(uint32_t pc);
/* A second address that also ends the run (e.g. the function return of a loop body); 0 clears it. */
void vf3_native_set_extra_stop(uint32_t pc);
/* Number of DMAC channel-2 transfers the guest started since the last call (the caller models their end interrupt). */
unsigned vf3_native_take_dma2(void);
/* Maple DMA starts since the last call; *list receives the transfer-list address (SB_MDSTAR). */
unsigned vf3_native_take_maple(uint32_t *list);
/* ASIC normal-interrupt status the model keeps: raise bits, read what is pending, count STARTRENDER writes. */
void vf3_native_raise_asic(uint32_t mask);
/* write one word of the modelled AICA sound RAM (offset from 0x00800000) before a run */
void vf3_native_aica_poke(uint32_t offset, uint32_t value);
uint32_t vf3_native_asic_pending(void);
unsigned vf3_native_take_render(void);
/* Called when a run's step budget (vf3_native_set_budget) is used up: time passes, it returns the next budget (0: stop). */
void vf3_native_set_budget_hook(uint32_t (*hook)(void));
/* Limit a run to `steps` guest steps (a time slice); 0 restores the default. An exhausted run reports ok = 0 with failed_pc at the next step. */
void vf3_native_set_budget(unsigned steps);

/* Generated: is this a call target (as opposed to a seed in the middle of a function)? */
int vf3_native_call_target(uint32_t entry);

#endif
