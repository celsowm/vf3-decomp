/* sys/arm7.h - the AICA's sound CPU: an ARM7TDMI machine model.
 *
 * The AICA carries an ARM7TDMI that runs the game's sound firmware
 * (SNDDRV.BIN, uploaded by the SH-4 into the sound RAM).  The firmware is the
 * only writer of the AICA's register file: it polls the SH-4 mailbox in the
 * sound RAM, turns commands into channel setups and programs the SGC's slots.
 * Without it the register file stays zero and the mixer has nothing to play
 * (docs/re/aica_audio_model.md).
 *
 * This module is the CPU, not the chip: it executes ARMv4T (ARM and Thumb)
 * over a bus the caller supplies.  On the AICA that bus is the 2 MiB sound
 * RAM at 0x00000000 and the register file at 0x00800000 (offset & 0x7FFF);
 * src/fight/native_tick.c wires those to aica_ram[] and the register model.
 *
 * The model is a machine like the PVR2's: our own implementation, checked
 * against the reference's ARM trace (tools/emu is the reference, never
 * linked).
 */
#ifndef VF3_SYS_ARM7_H
#define VF3_SYS_ARM7_H

#include <stdint.h>

/* The CPU's CPSR mode field. */
enum {
    VF3_ARM_MODE_USR = 0x10,
    VF3_ARM_MODE_FIQ = 0x11,
    VF3_ARM_MODE_IRQ = 0x12,
    VF3_ARM_MODE_SVC = 0x13,
    VF3_ARM_MODE_ABT = 0x17,
    VF3_ARM_MODE_UND = 0x1B,
    VF3_ARM_MODE_SYS = 0x1F
};

/* The bus the CPU runs on.  `read` answers a little-endian value of `size`
 * bytes (1, 2 or 4); `write` stores one.  An address the bus does not decode
 * reads as zero and ignores writes, like the open bus it is. */
typedef struct {
    void *context;
    uint32_t (*read)(void *context, uint32_t address, unsigned size);
    void (*write)(void *context, uint32_t address, uint32_t value, unsigned size);
} vf3_arm7_bus;

typedef struct {
    uint32_t r[16];
    uint32_t cpsr, spsr;
    /* the banked registers: index 0 USR/SYS, 1 FIQ, 2 IRQ, 3 SVC, 4 ABT, 5 UND */
    uint32_t bank_r13[6], bank_r14[6], bank_spsr[6];
    /* FIQ banks r8..r12; usr_r8 keeps the non-FIQ five while FIQ runs. */
    uint32_t fiq_r8[5];
    uint32_t usr_r8[5];
    vf3_arm7_bus bus;
    uint64_t cycles;          /* cycles retired since the reset */
    uint64_t instructions;    /* instructions retired since the reset */
    int32_t arm7_clock_ticks; /* the carried cycle phase, like flycast's
                               * arm7ClockTicks: the ARM7 runs while this is
                               * negative after each sample's budget is
                               * subtracted, so the leftover phase carries
                               * across samples (seeded from CYCL_CNT) */
    int irq_line;             /* the AICA's IRQ input, level triggered */
    int fiq_line;
    int halted;               /* the firmware stopped the CPU (a `b .` in a wait) */
    uint32_t last_pc;
    uint32_t last_insn;
    unsigned range_errors;    /* fetches or data accesses outside the RAM */
    unsigned exceptions;      /* vectors taken */
    /* a small history for the tests and the watchdog */
    uint32_t trace_pc[64];
    unsigned trace_at;
} vf3_arm7;

/* Attach a bus and reset to the ARM7's reset state (SVC mode, IRQ and FIQ
 * masked, ARM state, PC at the reset vector).  The bus struct is copied. */
void vf3_arm7_init(vf3_arm7 *cpu, const vf3_arm7_bus *bus);

/* The reset the AICA performs when the SH-4 releases ARMRST: the CPU starts
 * at 0x00000000 in SVC mode with both interrupts masked. */
void vf3_arm7_reset(vf3_arm7 *cpu);

/* Account an AICA slice of `cycles` ticks, running ARM7 blocks until the
 * carried phase is nonnegative. The returned retired charge can be below the
 * request when a prior block left positive phase, or overshoot it by the last
 * block's cost. A halted CPU can spend fewer cycles. */
uint32_t vf3_arm7_run(vf3_arm7 *cpu, uint32_t cycles);

/* One instruction (for tests and single-stepping).  Returns the cycles it
 * took. */
uint32_t vf3_arm7_step(vf3_arm7 *cpu);

/* Close the optional VF3_ARMSEQ executed-PC capture file (build/arm_seq.bin),
 * if one was opened.  Safe to call always. */
void vf3_arm7_seq_close(void);

/* The interrupt lines the AICA's controller drives. */
void vf3_arm7_set_irq(vf3_arm7 *cpu, int level);
void vf3_arm7_set_fiq(vf3_arm7 *cpu, int level);

/* The CPU's registers, for a save state and for tests. */
uint32_t vf3_arm7_reg(const vf3_arm7 *cpu, unsigned n);

/* A PC histogram over the firmware's own code (everything below 0x10000).
 * The firmware is 0xCF7C bytes, so a 64-KiB array of 4-byte-aligned PCs is
 * the whole instrumented region.  The driver's handlers live between 0x1E00
 * and 0x3700, so the histogram is how the port's boot is compared with the
 * reference's recorded trace.  The histogram is cheap (one branch and one
 * increment per retired instruction) and is always collected. */
void vf3_arm7_pc_hist_reset(void);
/* Print the firmware PCs ranked by how often the ARM7 executed them, to
 * stderr, then reset the histogram.  `top` is how many to print. */
void vf3_arm7_pc_hist_dump(unsigned top);

#endif
