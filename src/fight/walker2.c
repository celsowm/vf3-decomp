/* See walker2.h. All FPU adds honour the game's FPSCR.RM=1 (truncate);
 * the rest is integer moves. All traffic goes through the replay map so
 * the test diffs the shadow against the oracle exit windows.
 *
 * SCOPE (oracle-anchored): this routine models ONLY the gate prologue,
 * the T/gbr flag test, and the shared epilogue of SH-4 0x8C0748C0.
 * It deliberately does NOT model the two bsr 0x8C0748E0 walker calls:
 * their data structures (a destination triple at r4+0x13A8/0x1488 and a
 * tagged word at r0-36) sit outside every window the oracle captured for
 * this PC, so they are unverifiable from the current goldens. Evidence:
 * case 1 entry/exit diffs concentrate on r0-r6/fr2-fr6 only, the slot and
 * frame-pointer traffic is fully inside win2, and the second reload's
 * [r15] differs from entry r4 (0x0C1FEFE4 vs slot 0x0C20138C).
 * A whole-window diff of entry vs exit RAM isolates the walker writes;
 * recapture with walker-covering windows is the documented next step
 * (see walker2.h). */
#include "fight/walker2.h"

#include <stdio.h>
#include <string.h>

#include "fight/fpu_tz.h"

enum { W2_GATE_WORD = 0x0C29BCC0u, W2_GATE_MASK = 0x00080001u };

static uint32_t w_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            uint32_t v = 0;
            memcpy(&v, w->data + (canon - w->base), 4);
            return v;
        }
    }
    m->oob++;
    return 0;
}

static void w_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            memcpy(w->data + (canon - w->base), &v, 4);
            return;
        }
    }
    m->oob++;
}

static float w_rdflt(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t bits = w_rd32(ram, addr);
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

static uint32_t w_oob_probe(const vf3_ram_map *ram)
{
    vf3_ram_map *m = (vf3_ram_map *)ram;
    return m->oob;
}

static void w_wrflt(const vf3_ram_map *ram, uint32_t addr, float f)
{
    uint32_t bits;
    memcpy(&bits, &f, 4);
    w_wr32(ram, addr, bits);
}

void vf3_walker_gate_8c0748c0(uint32_t in_r5, uint32_t in_r15, uint32_t pr_in,
                              vf3_walker_gate_out *o, const vf3_ram_map *ram)
{
    uint32_t push = in_r15 - 4;   /* sts.l pr,@-r15 */
    uint32_t sp = in_r15 - 8;     /* add #-4,r15: frame base for the callee */
    uint32_t slash_sp = in_r15 - 4; /* add #4,r15: net -4 after bsr/unwind */
    uint32_t r1 = 0x8C0749B0u, r3 = 0x00080001u;
    uint32_t flagword, oob0;

    /* sts.l pr,@-r15 ; mov.l r5,@r15 after the second decrement: the push
     * word keeps pr, the save slot keeps r5, both inside win2. */
    w_wr32(ram, push, pr_in);
    w_wr32(ram, sp, in_r5);   /* mov.l r5,@r15 */
    o->r4 = in_r5;            /* informational: value the callee sees */
    oob0 = w_oob_probe(ram);
    flagword = w_rd32(ram, r1 & 0x0FFFFFFFu);
    ((vf3_ram_map *)ram)->oob = oob0; /* gate word is caller-owned */
    o->r4 = in_r5;            /* informational: value the callee sees */
    if ((flagword & r3) != 0) {
        o->pr = pr_in;        /* bf taken: skips both bsr calls */
        o->sp = slash_sp;     /* epilogue: add #4 / lds.l @r15+,pr / rts */
    } else {
        o->pr = 0x0C0748D8u;  /* fall-through: two bsr calls, then the
                               * shared epilogue from 0x8C0748D8 (note the
                               * P2 0x0C alias, matching the oracle pr) */
        o->sp = slash_sp;     /* unwind removes the callee's push; the
                               * net frame across the oracle window is -4 */
    }
}

int vf3_walker_8c0748e0(uint32_t in_r4, uint32_t in_r5,
                        vf3_walker_e0_regs *o, const vf3_ram_map *ram)
{
    /* STUB (documented, unmodelled): the equal-path FMAC triple and the
     * tagged-word walker tail at 0x8C074910+ live outside the oracle
     * windows captured for 0x8C0748C0 (entry r4+0x13A8/0x1488 are OOB in
     * all 8 cases). Keep the decoder-visible shape here for reference,
     * but report "not taken" so no harness can claim a PASS on it.
     * Recapture with walker-covering RAM windows is required first. */
    uint32_t r0 = 0x13A8u, r6 = 0x0150u;
    uint32_t r5w;
    float fr4, fr5, fr6, fr3, fr2;

    fr4 = w_rdflt(ram, in_r4 + r0);
    r0 += 4;
    fr5 = w_rdflt(ram, in_r4 + r0);
    r0 += 4;
    fr6 = w_rdflt(ram, in_r4 + r0);
    r0 -= 36;
    r5w = w_rd32(ram, in_r5 + r0);
    r6 += r5w;
    fr3 = w_rdflt(ram, in_r4 + 0x1488u);
    if (r6 != r5w)
        return 1;
    fr3 = fadd_tz(fr4, fr3);
    w_wrflt(ram, in_r4 + 0x1488u, fr3);
    r0 += 4;
    fr2 = w_rdflt(ram, in_r4 + r0);
    fr2 = fadd_tz(fr5, fr2);
    w_wrflt(ram, in_r4 + r0, fr2);
    r0 += 4;
    fr3 = w_rdflt(ram, in_r4 + r0);
    fr3 = fadd_tz(fr6, fr3);
    w_wrflt(ram, in_r4 + r0, fr3);

    o->r0 = r0;
    o->r4 = in_r4;
    o->r5 = in_r5;
    o->r6 = r6;
    o->fr2 = fpu_f32_to_bits(fr2);
    o->fr3 = fpu_f32_to_bits(fr3);
    o->fr4 = fpu_f32_to_bits(fr4);
    o->fr5 = fpu_f32_to_bits(fr5);
    o->fr6 = fpu_f32_to_bits(fr6);
    return 0;
}
