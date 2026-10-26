/* sys/frame_events.h - the per-frame event model: the clock, the vblank and
 * the ASIC events that end a frame.
 *
 * The Dreamcast's frame is 3,336,670 SH-4 clocks: the TMU's channel 0 counts
 * the CPU clock divided by 256, and it drops by 13,033 ticks per frame
 * (docs/re/boot_frame_clock.md).  The game's frame loop (0x8C059B48) arms a
 * render and then waits on the flag at 0x0C16CDF4; the wait is released by
 * the ASIC's list-end handler (0x8C063F70), which the PVR's list-end event
 * raises.  So a frame only ends if the model delivers three kinds of event:
 *
 *   - the vblank-in (ASIC normal-interrupt bit 0x8) at the frame boundary,
 *   - the DMA ends and the TA list ends (ASIC bits 0x80/0x100/0x200/0x400/
 *     0x200000), which the handler turns into the render stages,
 *   - the end of the render itself (ASIC bit 0x4, the EoR event).
 *
 * The model runs the game's own handlers for those events; it never fabricates
 * what they do.  It is the same model src/boot_sim.c uses for the loader's
 * wait, extracted so the SDL3 host and the boot tool share one implementation.
 */
#ifndef VF3_FRAME_EVENTS_H
#define VF3_FRAME_EVENTS_H

#include <stdint.h>

/* 3,336,670 SH-4 clocks per frame (1/60 s at the NTSC field rate). */
#define VF3_CYCLES_PER_FRAME 3336670u

/* What one emulated guest instruction costs on the cycle clock, in Q16.
 *
 * The port emulates one guest instruction per step, but the Dreamcast's frame
 * is a fixed number of *cycles*, not of instructions.  The reference emulator
 * ran the fight scene at 5,441 frames and 9,481,693,829 instructions
 * (extract/analysis/p1/hits_fight.csv): 1,742,588 instructions per frame in
 * 3,336,670 cycles, so the clock has to charge 1.9146 cycles per instruction.
 * Without that the port's frame would carry twice the game work the
 * reference's frame carries, and the frame boundary would drift away from the
 * reference's (docs/re/p2_frame_loop.md).
 *
 * The factor is a frame average: the SH-4 spends 1 cycle on most ALU work and
 * 2 on a load, a store or a branch, and this code is a mix of the two.  The
 * exact cost per instruction is P3 work (the translator would have to charge
 * it per block).
 */
#define VF3_CYCLES_PER_INSN_Q16 125486u

/* Run a guest entry point (an interrupt handler) with the given register file.
 * Returns 0 when the handler could not be run. */
typedef int (*vf3_frame_run_fn)(uint32_t entry, const uint32_t regs[37], void *ctx);
/* Time passes for another clock (the GD-ROM drive's cycle clock). */
typedef void (*vf3_frame_clock_fn)(void *ctx, uint32_t cycles);

typedef struct {
    uint8_t *ram;                 /* the game's RAM: the handlers write into it */
    uint32_t gbr;
    vf3_frame_run_fn run;          /* runs an interrupt handler */
    void *run_ctx;
    vf3_frame_clock_fn clock;      /* optional: another clock to advance */
    void *clock_ctx;
    uint32_t asic_entry;           /* the ASIC interrupt handler (0x8C06423A) */
    uint32_t vblank_a;             /* the first vblank handler (0x8C063D1E) */
    uint32_t vblank_b;             /* the second vblank handler (0x8C062E94) */
    int asic_first;                /* the ASIC events before the vblank pair */
    int vblank_through_asic;       /* the vblank-in through ASIC bit 0x8 */
    int use_vblank_pair;           /* the vblank pair as its own event */
    uint64_t now;                  /* the cycle clock */
    uint64_t next;                 /* the next frame boundary */
    uint32_t cyc_per_insn;         /* what one guest step costs (Q16) */
    unsigned frames;               /* the vblanks taken */
    unsigned cap;                  /* the vblank cap (0: none) */
    int failed;                    /* a handler could not be run */
} vf3_frame_events;

void vf3_frame_events_init(vf3_frame_events *ev, uint8_t *ram, uint32_t gbr,
                           vf3_frame_run_fn run, void *run_ctx);
/* The handlers the model dispatches to.  The default is the game's own:
 * the ASIC handler at 0x8C06423A (which calls the vblank handler 0x8C063D1E
 * and then 0x8C05FCC4), the vblank pair (0x8C063D1E, 0x8C062E94). */
void vf3_frame_events_default_handlers(vf3_frame_events *ev);
/* The budget hook: the guest's step budget ran out.  Time passes, the events
 * that came due are dispatched, and the next budget is returned (0: stop).
 * The handlers run with `regs`, the register file the guest had at that
 * point (the interrupt itself does not change the registers). */
uint32_t vf3_frame_events_slice(vf3_frame_events *ev, unsigned steps, const uint32_t regs[37]);
/* The vblanks taken so far. */
unsigned vf3_frame_events_frames(const vf3_frame_events *ev);
/* The clock, in SH-4 clocks since the model started. */
uint64_t vf3_frame_events_cycles(const vf3_frame_events *ev);

#endif
