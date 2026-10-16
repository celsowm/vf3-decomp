/* chain_frames.c - 0x8C071694  give every node of a chain an orthonormal side vector.
 *
 *   r4 = chain object: +4 node array, +88 node count n, +92 second count m.
 *   Nodes are 24 bytes: a vec3 position at +0 and the vec3 this routine writes at +12.
 *
 *   For each node N with neighbours P (previous) and Q / R (the next ones; some are the next-but-one node
 *   or the node before P, depending on the phase) it builds two edge vectors, crosses them with the third,
 *   normalises both crosses, adds them and normalises the sum into N+12. The walk has eight phases because
 *   the chain is a closed strip: the head nodes (phase 1, n-2 of them), the join (2), a run that alternates
 *   between the shared tail (3, 5) and a counted run (4), the second join (6), the second run (7) and the
 *   last node (8). Each phase differs only in which neighbours it uses and in the order of the two crosses;
 *   the helpers write the original's FR sequences so FR0-FR10 and r4-r6 end up identical.
 *
 *   Frame (96 bytes below seven saved registers): +0 / +4 neighbour pointers, +8 / +16 / +20 counters,
 *   +12 the count m and later the address of the scratch vector at +84, +24 / +36 the two crosses,
 *   +48 / +60 / +72 / +84 the edge vectors. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum { SAVED_BYTES = 28, FRAME_BYTES = 96, E1 = 48, E2 = 60, E3 = 72, E4 = 84, X1 = 36, X2 = 24, NODE = 24 };

typedef struct {
    vf3_matrix_state *s;
    const vf3_ram_map *ram;
    uint32_t f;                 /* frame */
    uint32_t prev, cur, next;   /* r8 (node before the previous), r14, r11 */
} walk;

#define S (w->s)
#define RAM (w->ram)

static uint32_t rd(const walk *w, uint32_t off) { return m32(RAM, w->f + off); }
static void wr(const walk *w, uint32_t off, uint32_t v) { w32(RAM, w->f + off, v); }

/* node + 12 = unit(cross_a + cross_b), with the two crosses normalised first */
static int finish_node(const walk *w, uint32_t node)
{
    if (!v3_unit(S, RAM, w->f + X1)) return 0;
    if (!v3_unit(S, RAM, w->f + X2)) return 0;
    v3_add(S, RAM, node + 12, w->f + X1, w->f + X2, 0);
    return v3_unit(S, RAM, node + 12);
}

/* the last-node form: a single cross straight into the node */
static int single_cross(const walk *w, uint32_t node, uint32_t a, uint32_t b)
{
    v3_cross(S, RAM, node + 12, a, b);
    return v3_unit(S, RAM, node + 12);
}

int vf3_chain_frames_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15);
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t obj = R(4);
    walk W, *w = &W;
    const uint32_t f = sp0 - SAVED_BYTES - FRAME_BYTES;

    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    R(15) = f;
    W.s = s; W.ram = ram; W.f = f;

    const uint32_t n = m32(ram, obj + 88), m = m32(ram, obj + 92), base = m32(ram, obj + 4);
    wr(w, 12, m);
    W.prev = base;                                          /* r8 */
    W.cur = base + NODE;                                    /* r14 */
    W.next = base + 2 * NODE;                               /* r11 */
    wr(w, 0, base + NODE * n + NODE);
    wr(w, 4, base);
    wr(w, 20, n - 1);
    wr(w, 8, n - 1);
    R(9) = 1;

    /* phase 1: the head nodes */
    if ((int32_t)(n - 1) > 1) {
        for (;;) {
            v3_sub(s, ram, f + E1, rd(w, 4), W.cur);
            v3_sub(s, ram, f + E2, W.next, W.cur);
            v3_sub(s, ram, f + E3, rd(w, 0), W.cur);
            v3_cross(s, ram, f + X1, f + E3, f + E1);
            v3_cross(s, ram, f + X2, f + E2, f + E3);
            if (!finish_node(w, W.cur)) return 0;
            wr(w, 4, W.cur);
            W.cur = W.next; W.next += NODE;
            wr(w, 0, rd(w, 0) + NODE);
            const uint32_t left = rd(w, 8) - 1;
            wr(w, 8, left);
            if (!((int32_t)left > 1)) break;
        }
    }

    /* phase 2: the join */
    v3_sub(s, ram, f + E1, rd(w, 4), W.cur);
    v3_sub(s, ram, f + E2, rd(w, 0), W.cur);
    if (!single_cross(w, W.cur, f + E2, f + E1)) return 0;
    wr(w, 0, rd(w, 0) + NODE);
    W.cur = W.next;
    wr(w, 16, rd(w, 12) - 1);
    wr(w, 12, f + E4);
    W.next += NODE;

    for (;;) {                                              /* phases 3 / 4 / 5 around the compare at 0x071D92 */
        if (!((int32_t)rd(w, 16) > 1)) break;

        /* phase 3 */
        v3_sub(s, ram, f + E1, W.next, W.cur);
        v3_sub(s, ram, f + E2, rd(w, 0), W.cur);
        v3_sub(s, ram, f + E3, W.prev, W.cur);
        v3_cross(s, ram, f + X1, f + E1, f + E2);
        v3_cross(s, ram, f + X2, f + E3, f + E1);
        if (!finish_node(w, W.cur)) return 0;
        wr(w, 4, W.cur);
        W.cur = W.next; W.next += NODE;
        wr(w, 0, rd(w, 0) + NODE);
        const uint32_t run = rd(w, 20);
        wr(w, 8, run);
        W.prev += NODE;

        if ((int32_t)run > 1) {
            for (;;) {                                      /* phase 4: the counted run */
                v3_sub(s, ram, f + E1, rd(w, 4), W.cur);
                v3_sub(s, ram, f + E2, W.next, W.cur);
                v3_sub(s, ram, f + E3, rd(w, 0), W.cur);
                v3_sub(s, ram, rd(w, 12), W.prev, W.cur);
                v3_cross(s, ram, f + X1, f + E3, f + E1);
                v3_cross(s, ram, f + X2, rd(w, 12), f + E2);
                if (!finish_node(w, W.cur)) return 0;
                wr(w, 4, W.cur);
                W.cur = W.next; W.next += NODE; W.prev += NODE;
                wr(w, 0, rd(w, 0) + NODE);
                const uint32_t left = rd(w, 8) - 1;
                wr(w, 8, left);
                if (!((int32_t)left > 1)) break;
            }
        }

        /* phase 5 */
        v3_sub(s, ram, f + E1, rd(w, 4), W.cur);
        v3_sub(s, ram, f + E2, rd(w, 0), W.cur);
        v3_sub(s, ram, f + E3, W.prev, W.cur);
        v3_cross(s, ram, f + X1, f + E1, f + E3);
        v3_cross(s, ram, f + X2, f + E2, f + E1);
        if (!finish_node(w, W.cur)) return 0;
        const uint32_t tail = rd(w, 0);
        W.cur = W.next; W.next += NODE; W.prev += NODE;
        wr(w, 0, tail + NODE);
        wr(w, 16, rd(w, 16) - 1);
    }

    /* phase 6: the second join */
    v3_sub(s, ram, f + E1, W.next, W.cur);
    v3_sub(s, ram, f + E2, W.prev, W.cur);
    if (!single_cross(w, W.cur, f + E2, f + E1)) return 0;
    wr(w, 0, W.cur);
    W.cur = W.next; W.next += NODE;
    const uint32_t second = rd(w, 20);
    wr(w, 4, second);
    W.prev += NODE;

    if ((int32_t)second > 1) {
        for (;;) {                                          /* phase 7 */
            v3_sub(s, ram, f + E1, rd(w, 0), W.cur);
            v3_sub(s, ram, f + E2, W.next, W.cur);
            v3_sub(s, ram, f + E3, W.prev, W.cur);
            v3_cross(s, ram, f + X1, f + E3, f + E2);
            v3_cross(s, ram, f + X2, f + E1, f + E3);
            if (!finish_node(w, W.cur)) return 0;
            wr(w, 0, W.cur);
            W.cur = W.next;
            const uint32_t left = rd(w, 4) - 1;
            W.next += NODE; W.prev += NODE;
            wr(w, 4, left);
            if (!((int32_t)left > 1)) break;
        }
    }

    /* phase 8: the last node */
    v3_sub(s, ram, f + E1, rd(w, 0), W.cur);
    v3_sub(s, ram, f + E2, W.prev, W.cur);
    if (!single_cross(w, W.cur, f + E1, f + E2)) return 0;

    R(VF3_REG_SR) &= ~1u;                                   /* the last compare was cmp/gt, false */
    R(15) = sp0;
    {
        static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };
        for (int i = 0; i < 7; ++i) R(pushed[i]) = saved_r[i];
    }
    s->pc = R(VF3_REG_PR);
    return 1;
}
