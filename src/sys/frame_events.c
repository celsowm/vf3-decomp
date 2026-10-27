/* sys/frame_events.c - the per-frame event model (see frame_events.h).
 *
 * The model is the one src/boot_sim.c grew for the loader's wait, with the
 * loader's own bits (the GD-ROM cycle clock, the state peeking) left to the
 * caller through callbacks.  The order of the events inside a slice is the
 * hardware's: the DMA ends and the TA lists end first, the ASIC handler runs
 * and turns them into the render stages, and the vblank pair comes last
 * (docs/re/boot_asic_order.md: the other order makes the list-end handler see
 * the previous frame's flag and skip the release, so the frame loop never
 * leaves its wait).
 */
#include "sys/frame_events.h"

#include <string.h>

#include "fight/native_tick.h"
#include "sys/maple_hle.h"

#define ASIC_VBLANK_IN   0x00000008u   /* SB_ISTNRM bit 3: the vertical blank */
#define ASIC_RENDER_END  0x00000004u   /* the end of a render (EoR) */
#define ASIC_DMA_END     0x00080000u   /* SH-4 DMAC channel 2 finished */
#define ASIC_MAPLE_END   0x00001000u   /* a Maple transfer finished */

/* The TA list-end bits: the game says which lists it expects in 0x0C16CDE8
 * and clears them in 0x0C16CDEC as they end. */
#define LIST_WAITED      0x0C16CDE8u
#define LIST_DONE        0x0C16CDECu
#define LIST_STAGE       0x0C16CDCCu
#define RENDER_WAIT      0x0C16CDF4u

static uint16_t pad_buttons = 0xFFFFu;   /* the stand-in pad: nothing pressed */

static uint32_t rd32(const uint8_t *ram, uint32_t addr)
{
    uint32_t v;
    const uint32_t off = (addr & 0x0FFFFFFFu) - 0x0C000000u;
    if (off + 4u > 0x01000000u) return 0;
    memcpy(&v, ram + off, 4);
    return v;
}

void vf3_frame_events_init(vf3_frame_events *ev, uint8_t *ram, uint32_t gbr,
                           vf3_frame_run_fn run, void *run_ctx)
{
    memset(ev, 0, sizeof *ev);
    ev->ram = ram;
    ev->gbr = gbr;
    ev->run = run;
    ev->run_ctx = run_ctx;
    ev->next = VF3_CYCLES_PER_FRAME;
    ev->cyc_per_insn = VF3_CYCLES_PER_INSN_Q16;
    ev->use_vblank_pair = 1;
    vf3_frame_events_default_handlers(ev);
}

void vf3_frame_events_default_handlers(vf3_frame_events *ev)
{
    ev->asic_entry = 0x8C06423Au;   /* the ASIC normal-interrupt handler */
    ev->vblank_a = 0x8C063D1Eu;     /* the vblank handler (saves the FPU state) */
    ev->vblank_b = 0x8C062E94u;     /* the second vblank handler */
}

/* The handlers run with the machine's registers; the interrupt itself does
 * not change them (the handler pushes what it needs), so the caller hands the
 * register file it wants the handler to start with. */
static int run_handler(vf3_frame_events *ev, uint32_t entry, const uint32_t regs[37])
{
    if (!ev->run || !entry) return 1;
    if (!ev->run(entry, regs, ev->run_ctx)) {
        ev->failed = 1;
        return 0;
    }
    return 1;
}

static void take_vblank(vf3_frame_events *ev, const uint32_t regs[37])
{
    if (!ev->vblank_through_asic) {
        if (ev->use_vblank_pair) {
            if (!run_handler(ev, ev->vblank_a, regs)) return;
            if (!run_handler(ev, ev->vblank_b, regs)) return;
        }
        return;
    }
    /* The real vblank-in is the ASIC's normal-interrupt bit 0x8: the handler
     * at 0x8C06423A calls the vblank handler 0x8C063D1E and then 0x8C05FCC4. */
    vf3_native_raise_asic(ASIC_VBLANK_IN);
}

/* The ASIC handler: it dispatches the pending events (the vblank-in, the TA
 * list ends, the end of a render) in the order the hardware raises them. */
static void dispatch_asic(vf3_frame_events *ev, const uint32_t regs[37])
{
    if (!vf3_native_asic_pending()) return;
    run_handler(ev, ev->asic_entry, regs);
    if (ev->asic2_entry && (vf3_native_asic_pending() & vf3_native_asic_iml2())) run_handler(ev, ev->asic2_entry, regs);
}

uint32_t vf3_frame_events_slice(vf3_frame_events *ev, unsigned steps, const uint32_t regs[37])
{
    /* The cycle clock runs on the Dreamcast's cycles, not on the port's
     * instructions: one guest step costs cyc_per_insn cycles (see the header). */
    const uint32_t cyc = (uint32_t)(((uint64_t)steps * ev->cyc_per_insn) >> 16);
    ev->now += cyc;
    vf3_native_tmu_advance(cyc);
    if (ev->clock) ev->clock(ev->clock_ctx, cyc);

    /* the events the frame produced, dispatched before the vblank pair */
    int dma_done = 0;
    for (unsigned n = vf3_native_take_dma2(); n; --n) {
        dma_done = 1;   /* a DMA transfer ended: the ASIC handler starts the next queued one */
        vf3_native_raise_asic(ASIC_DMA_END);
    }
    if (dma_done) {
        const uint32_t want = rd32(ev->ram, LIST_WAITED) & ~rd32(ev->ram, LIST_DONE);
        static const uint32_t bits[5] = { 0x80u, 0x100u, 0x200u, 0x400u, 0x200000u };
        for (unsigned i = 0; i < 5; ++i)
            if (want & (1u << i)) vf3_native_raise_asic(bits[i]);
    }
    {   /* the Maple: the list is answered at once (a stand-in pad on port A) */
        uint32_t list = 0;
        vf3_maple_pad pad = { pad_buttons, 0, 0, 0x80, 0x80, 0x80, 0x80 };
        for (unsigned n = vf3_native_take_maple(&list); n; --n) {
            vf3_maple_dma(ev->ram, VF3_NATIVE_RAM_BASE, VF3_NATIVE_RAM_LEN, list, &pad);
            vf3_native_raise_asic(ASIC_MAPLE_END);
        }
    }
    for (unsigned n = vf3_native_take_render(); n; --n) vf3_native_raise_asic(ASIC_RENDER_END);

    if (!ev->asic_first) {
        while (ev->now >= ev->next) {
            ev->next += VF3_CYCLES_PER_FRAME;
            ++ev->frames;
            take_vblank(ev, regs);
            if (ev->failed) return 0;
        }
    }
    dispatch_asic(ev, regs);
    if (ev->asic_first) {
        while (ev->now >= ev->next) {
            ev->next += VF3_CYCLES_PER_FRAME;
            ++ev->frames;
            take_vblank(ev, regs);
            if (ev->failed) return 0;
        }
    }
    if (ev->cap && ev->frames >= ev->cap) return 0;
    return steps;
}

unsigned vf3_frame_events_frames(const vf3_frame_events *ev) { return ev->frames; }
void vf3_frame_events_set_buttons(uint16_t buttons) { pad_buttons = buttons; }
uint64_t vf3_frame_events_cycles(const vf3_frame_events *ev) { return ev->now; }
