/* See cntup.h.  The counter updater's own body is modelled here; the ladder
 * it calls (0x8C08B89C) is not: it is ported readably in
 * src/fight/state_ladder.c and called from here, so the oracle's replay of
 * this entry is a replay of the readable ladder too.
 *
 * All stack traffic goes through a private frame so the harness OOB counter
 * only sees checked-window traffic; every map read in this file must hit
 * (nonzero OOB fails the replay). */
#include "fight/cntup.h"

#include "fight/matrix_family.h"

#include <string.h>

/* The ladder this file used to model is ported readably (state_ladder.c). */
int vf3_state_ladder_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

static uint32_t m_rd32(const vf3_ram_map *ram, uint32_t addr)
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

static void m_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
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

/* Private frame: covers [F-32, F+96); all offsets below are relative to the
 * b7ee frame base F = in_r15 - 88. */
typedef struct {
    uint8_t b[128];
} privframe;

static uint32_t p_rd32(privframe *f, int off)
{
    uint32_t v = 0;
    memcpy(&v, f->b + (off + 32), 4);
    return v;
}

static void p_wr32(privframe *f, int off, uint32_t v)
{
    memcpy(f->b + (off + 32), &v, 4);
}

/* The ladder (0x8C08B89C..0x8C08BB06) is ported readably in
 * src/fight/state_ladder.c, and this file calls it rather than modelling it a
 * second time.  The port reads and writes the caller's frame and the stack,
 * so the private frame is handed over as one window: the ladder's frame is
 * at F+4..F+52 and its stack traffic at [F-24, F) - both inside the private
 * frame's [F-32, F+96).  The oracle's row bound is 1024 windows, so the copy
 * below cannot overflow. */
#define CNTUP_MAXWIN 1024

static void callee1(uint32_t A, privframe *pf, uint32_t F,
                    const vf3_ram_map *ram)
{
    static vf3_ram_win wins[CNTUP_MAXWIN + 1];
    vf3_ram_map map;
    vf3_matrix_state s;
    int i;

    if (ram->n > CNTUP_MAXWIN)
        return;                       /* the oracle's bound: cannot happen */
    for (i = 0; i < ram->n; ++i)
        wins[i] = ram->wins[i];
    wins[ram->n].base = F - 32u;
    wins[ram->n].len = 128u;
    wins[ram->n].data = pf->b;
    map = *ram;
    map.wins = wins;
    map.n = ram->n + 1;

    memset(&s, 0, sizeof s);
    s.v[4] = A;                      /* r4: the task struct */
    s.v[5] = F + 4u;                 /* r5: the ladder's frame */
    s.v[15] = F;                     /* r15: the ladder's stack pointer */
    s.v[16] = 0x0c08b81cu;           /* pr: its return address */
    s.v[17] = 0x301u;                /* sr */
    s.v[18] = 0u;                    /* fpscr: single precision */
    s.budget = 1000000u;
    vf3_state_ladder_entry(&s, &map);
    /* the port counts its out-of-window accesses in the copy of the map */
    ((vf3_ram_map *)ram)->oob = map.oob;
}

void vf3_cntup_8c08b7ee(uint32_t in_r14, uint32_t in_r15, uint32_t in_pr,
                        vf3_cntup_out *o, const vf3_ram_map *ram)
{
    privframe pf;
    uint32_t r0, r2, r3, r4;
    uint32_t X = in_r15;

    memset(&pf, 0, sizeof(pf));
    p_wr32(&pf, 84, in_pr);         /* 8c08b7ee sts.l pr,@-r15 */
    /* 8c08b7f0-f2: r15 -= 84 -> frame base F */
    p_wr32(&pf, 0, in_r14);         /* 8c08b7f4 [F] = r14 */
    r4 = 0x0C29BB84u;               /* 8c08b7f6 lit */
    r3 = m_rd32(ram, r4 + 16);      /* 8c08b7f8 */
    p_wr32(&pf, 76, r3);            /* 8c08b7fa [F+76] */
    r2 = m_rd32(ram, r4 + 20);      /* 8c08b7fe */
    p_wr32(&pf, 80, r2);            /* 8c08b800 [F+80] */
    r4 = m_rd32(ram, r4 + 40);      /* 8c08b802 guard ptr */
    r0 = m_rd32(ram, r4);           /* 8c08b804 deref */
    if ((r0 & 2u) != 0)             /* 8c08b806-808 tst #2 + bf */
        goto done;
    /* 8c08b80a delay (r1 load) has no checked effect; folded below */
    r3 = 0x00080001u;               /* 8c08b80c lit */
    r2 = m_rd32(ram, 0x0C29BCC0u);  /* 8c08b80e deref */
    if ((r2 & r3) != 0)             /* 8c08b810-812 tst + bf */
        goto done;
    /* 8c08b814 delay (r5 = F+4) folded into the call */
    callee1(in_r14, &pf, in_r15 - 88u, ram);  /* 8c08b818 bsr 0x8C08B89C */
    /* 8c08b820 bsr 0x8C08BB14 (callee-2 + nested calls): DELEGATED,
     * see cntup.h. No checked-window traffic. */
    r2 = p_rd32(&pf, 4);            /* 8c08b824 [F+4] */
    r3 = p_rd32(&pf, 0);            /* 8c08b826 [F] */
    m_wr32(ram, r3 + 16, r2);       /* 8c08b828 final store */
done:
    /* 8c08b82a-30 epilogue: r15 += 84 (balanced), pr restored,
     * rts delay pops the caller word into r14 (caller-owned; the
     * replay test forces r14 from the oracle). */
    o->r14 = in_r14;
    o->r15 = X + 4;
    o->pr = in_pr;
}
