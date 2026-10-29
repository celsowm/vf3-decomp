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
#include "fight/matrix_family.h"

#define VF3_NATIVE_RAM_BASE 0x0C000000u
#define VF3_NATIVE_RAM_LEN  0x01000000u
#define VF3_NATIVE_SCHED_ENTRY 0x8C09616Au
/* a Maple transfer finished (SB_ISTNRM bit 12) */
#define ASIC_MAPLE_END   0x00001000u
/* the loader stubs jump through the pointer word at 0x8C0000BC; REIOS fills it with this entry */
#define VF3_BIOS_SYSCALL_VECTOR 0x0C001006u

typedef struct {
    int ok;                       /* the entry returned to its caller */
    uint32_t pc, failed_pc;       /* where it stopped when not ok */
    unsigned steps_budget_used;   /* guest basic-block budget consumed */
    unsigned budget_left;         /* the step budget still left when the run ended */
    unsigned readable_calls;      /* calls served by readable ports */
    unsigned unowned_calls;       /* calls into code nobody ported (each one is a failure) */
    uint32_t first_unowned;
    unsigned bios_calls;          /* BIOS GD-ROM syscalls served by the attached model */
    unsigned device_reads, device_writes, ta_words, oob;
    unsigned render_starts;       /* the STARTRENDER writes of the run (the frames the game drew) */
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
/* The stand-in pad's buttons: the Maple model answers the guest's DMA start
 * with them (the answer goes out when the guest writes SB_MDST, like the
 * reference). */
void vf3_native_set_maple_buttons(uint16_t buttons);
/* ASIC normal-interrupt status the model keeps: raise bits, read what is pending, count STARTRENDER writes. */
void vf3_native_raise_asic(uint32_t mask);
/* write one word of the modelled AICA sound RAM (offset from 0x00800000) before a run */
void vf3_native_aica_poke(uint32_t offset, uint32_t value);
/* frame clock: enable the TMU channel-0 counter and advance it as guest time passes */
void vf3_native_enable_tmu(void);
void vf3_native_tmu_advance(uint32_t cycles);
/* seed the counter with the value the captured state last sampled (TCNT0 counts down from 0xFFFFFFFF) */
void vf3_native_tmu_set(uint32_t tcnt);
/* 1 while a GD-ROM model is attached (BIOS GD calls are then served by it, EXEC_SERVER included) */
int vf3_native_gd_attached(void);
uint32_t vf3_native_asic_pending(void);
/* the ASIC normal-interrupt mask the game wrote to SB_IML2NRM (0x005F6910) */
uint32_t vf3_native_asic_iml2(void);
unsigned vf3_native_take_render(void);
/* Called when a run's step budget (vf3_native_set_budget) is used up: time passes, it returns the next budget (0: stop).
 * The hook gets the machine state, because the interrupt handlers it dispatches have to run with the registers the
 * guest had at that point. */
/* hands the display commands gathered so far to the caller and empties the buffer (valid until the next run) */
unsigned vf3_native_take_ta(const uint32_t **words);
/* the boot ROM image (2 MiB at 0x00000000), when the user supplies one: the game reads the BIOS font from it */
void vf3_native_set_bios(const uint8_t *image, size_t len);
void vf3_native_set_budget_hook(uint32_t (*hook)(vf3_matrix_state *s));
/* Limit a run to `steps` guest steps (a time slice); 0 restores the default. An exhausted run reports ok = 0 with failed_pc at the next step. */
void vf3_native_set_budget(unsigned steps);

/* Generated: is this a call target (as opposed to a seed in the middle of a function)? */
int vf3_native_call_target(uint32_t entry);

/* The PC of the function the guest is in (0 when no run is in progress).  The
 * watchdog in the host reads it to say where a boot that stopped making
 * progress is stuck. */
uint32_t vf3_native_current_pc(void);

/* A guest store into the PVR2's texture memory (the 64 bit view at 0x04000000
 * and the 32 bit view at 0x05000000, plus the Tile Accelerator's own window
 * at 0x11000000).  The model intercepts it: the hook gets the physical
 * address, the value and the access size.  It lives here and not
 * in matrix_family.h because touching that header rebuilds every generated
 * adapter. */
extern void (*vf3_vram_store_hook)(uint32_t dest, uint32_t value, unsigned size);
/* The system bus' long mode bits (SB_LMMODE0 at 0x005F6884, SB_LMMODE1 at
 * 0x005F6888): they pick the 32 bit or the 64 bit path of the PVR2's texture
 * memory window at 0x11000000. */
extern void (*vf3_pvr_lmmode_hook)(uint32_t mode0, uint32_t mode1);
/* The dispatcher resumed at a PC the guest reached through a tail transfer
 * (a register-indirect jump the module was not generated with), so the
 * ordinary entry hook never saw it.  The hook names that address. */
extern void (*vf3_family_tail_enter)(uint32_t entry, vf3_matrix_state *s,
                                      const vf3_ram_map *ram, int ok);

#endif
