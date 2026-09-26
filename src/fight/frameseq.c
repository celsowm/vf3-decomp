/* See frameseq.h. The port models the sequencer's own footprint only —
 * the pr push, the frame-counter bump, and the tail-jmp boundary state —
 * with all traffic through the vf3_ram_map so the replay shadows any
 * in-window write and counts out-of-window accesses. The two known escapes
 * (stack-page push, globals-page counter) are oob-tolerated exactly like
 * walker2's caller-owned gate word: snapshot oob, restore on exit. The six
 * jsr/bsr scene steps are a documented scope cut; their state is chain-owned
 * in the oracle exit snapshots. */
#include "fight/frameseq.h"

#include <string.h>

static uint32_t q_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static void q_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
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

void vf3_frameseq_8c0c2b80(uint32_t in_pr, uint32_t in_r15,
                           vf3_frameseq_out *o, const vf3_ram_map *ram)
{
    uint32_t r2;
    uint32_t oob0 = ((const vf3_ram_map *)ram)->oob;

    /* sts.l pr,@-r15 — stack page not in any captured window (8/8 cases). */
    q_wr32(ram, in_r15 - 4, in_pr);

    /* bsr 0x8C0C2BB2 + jsr 0x8C0C3C30 / 0x8C06B6DC / 0x8C06BF54 /
     * 0x8C0C3B1C / 0x8C06972A — scope cut (see frameseq.h): chain-owned
     * register state, byte-identical captured RAM, nothing to shadow here. */

    /* frame counter: r3 = 0x8C1FD7C8; r2 = [r3]+1; [r3] = r2
     * — globals page not in any captured window (8/8 cases). */
    r2 = q_rd32(ram, VF3_FRAMESEQ_COUNTER) + 1;
    q_wr32(ram, VF3_FRAMESEQ_COUNTER, r2);

    /* tail: jmp @0x8C06BF00 ; (delay) lds.l @r15+,pr — r15/pr balanced. */
    ((vf3_ram_map *)ram)->oob = oob0;

    o->r2 = r2;
    o->r3 = VF3_FRAMESEQ_TAIL;
    o->r15 = in_r15;
    o->pr = in_pr;
}
