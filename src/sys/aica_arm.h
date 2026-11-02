/* sys/aica_arm.h - the AICA's ARM7 firmware, with the chip's timers and its
 * interrupt controller.
 *
 * The AICA has three pieces that only work together:
 *
 *   - the ARM7 (sys/arm7.h) runs the game's sound firmware out of the sound
 *     RAM.  It is the only writer of the register file's channel slots: the
 *     SH-4 uploads the image, releases the reset and then talks to the driver
 *     through the mailbox in the sound RAM;
 *   - the three timers count at the sample rate divided by 1 << md.  Timer B
 *     is the firmware's own tick: the driver enables it in SCIEB and its
 *     interrupt runs the sequencer;
 *   - three interrupt controllers in series.  The SCI* registers collect the
 *     chip's events, the e68k latch holds the first pending one until the
 *     firmware accepts it through REG_M, and that latch is the ARM7's FIQ
 *     input.
 *
 * The model follows the reference's own chip (flycast's aica.cpp,
 * aica_mem.cpp and arm7/arm_mem.cpp): a sample is 512 ARM7 cycles followed by
 * one step of the timers, the SAMPLE_DONE flags and the mixer.  The register
 * file and the sound RAM stay in sys/aica_model.h; this module is the CPU's
 * window on them.
 *
 * The firmware image is SNDDRV.BIN (53,120 bytes at sound RAM offset 0).  Its
 * start-up publishes "INIT" at sound RAM + 0x5C, which is the word the SH-4's
 * loader polls; after that it scans the 64 channel slots and services the
 * SH-4's command ring at sound RAM + 0x400.
 */
#ifndef VF3_SYS_AICA_ARM_H
#define VF3_SYS_AICA_ARM_H

#include <stdint.h>

#include "sys/aica_mixer.h"
#include "sys/aica_model.h"
#include "sys/arm7.h"

/* One of the chip's three timers, the way the reference keeps it: the counter
 * itself lives in the register file (the byte at the timer's base), the step
 * and its countdown live here. */
typedef struct {
    uint32_t c_step;
    uint32_t m_step;
} vf3_aica_timer;

/* The ARM7 and the chip around it. */
typedef struct vf3_aica_arm {
    vf3_arm7 cpu;
    vf3_aica_model *model;
    vf3_aica_mixer *mixer;

    vf3_aica_timer timer[3];

    /* The three interrupt controllers.  `aica_reg_L` is the level of the
     * newest pending interrupt, `reg_L` the one the e68k latch captured, and
     * `e68k_out` the latch itself (the ARM7's FIQ line). */
    uint32_t aica_reg_L;
    uint32_t reg_L;
    int aica_interr;
    int e68k_out;

    int running;              /* ARMRST released */
    uint64_t samples;         /* sample steps since the reset */
    uint64_t reg_writes;      /* register-file writes the firmware made */
    uint64_t channel_writes;  /* of those, the ones into the 64 channel slots */
    unsigned fiq_count;       /* rises of the e68k latch (the FIQ line) */
    uint32_t last_pc;         /* the firmware's last executed instruction */
} vf3_aica_arm;

/* Attach the chip's register file and mixer.  The CPU is reset; the sound RAM
 * and the register file are left as the caller has them (the SH-4 uploads the
 * firmware before it releases the ARM7). */
void vf3_aica_arm_init(vf3_aica_arm *a, vf3_aica_model *model,
                       vf3_aica_mixer *mixer);

/* The reset ARMRST performs: the CPU starts at 0 in SVC mode with both
 * interrupts masked, and the interrupt controller's latches are cleared.  The
 * register file, the sound RAM and the timers' registers survive. */
void vf3_aica_arm_reset(vf3_aica_arm *a);

/* Release the reset and run the firmware until it publishes "INIT" at sound
 * RAM + 0x5C, or `max_cycles` are spent.  Returns 1 when the signature is
 * there.  The CPU keeps running through vf3_aica_arm_sample() afterwards. */
int vf3_aica_arm_release(vf3_aica_arm *a, uint32_t max_cycles);

/* One sample: 512 ARM7 cycles, one step of the timers and the SAMPLE_DONE
 * flags, the interrupt update and one stereo frame from the mixer.  This is
 * the reference's `arm::run(1)` and `timeStep()` together. */
void vf3_aica_arm_sample(vf3_aica_arm *a, int16_t *right, int16_t *left);

/* A write into the register file, from either side of the chip.  The channel
 * slots go to the mixer (the key-on trigger lives there); the timers restart
 * their countdown when their control byte changes; the interrupt registers
 * keep their read-only and write-one-to-clear behaviour.  `offset` is the
 * offset in the 8 KiB file. */
void vf3_aica_arm_note_write(vf3_aica_arm *a, uint32_t offset, uint32_t value,
                             unsigned size);

/* The two words the guest's loader waits for: the firmware's "INIT"
 * signature and the free-size limit it publishes next to it. */
uint32_t vf3_aica_arm_word(const vf3_aica_arm *a, uint32_t offset);

#endif
