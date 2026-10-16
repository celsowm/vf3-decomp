/* capsule_chain.c - 0x8C070008  keep a chain of 24-byte nodes out of a capsule and re-apply the link lengths.
 *
 *   r4 = owner object (bytes +96/+97 pick which of the first nodes are skipped), r5 = capsule record,
 *   r6 = end of the node array, r7 = int16 part number.
 *   Capsule record: +0x58 node-pair count, +0x60 link length, +0x74 / +0x80 the two axes (unit vectors),
 *   +0x8C / +0x98 the two end points, +0xA8 axis length, +0xAC radius.
 *
 *   The nodes are walked from both ends of the array towards the middle (r14 downwards, r13 upwards).
 *   Every node (a vec3 at its start) is tested against the capsule by two stages:
 *     stage A  (end point r10, axis r11) and stage B (end point r9 or r10, axis r12 or r11):
 *       d = node - end point; if d == 0 nothing; the component along the axis picks the case:
 *         behind the end point    -> the node is moved onto/along d by radius (end cap)
 *         beside the segment      -> the node is moved radially out of the cylinder (side)
 *         beyond the axis length  -> nothing
 *   After the stages each node is pulled back to its neighbour's link length (fr13) from its anchor
 *   (r8 for the downward walker, the running pointer at frame+4 for the upward one).
 *
 * The inlined vec3 helpers (sub/add/scale/normalise/length/dot/cross-length) are written out as the same
 * FR-register sequences as the original so the leftovers in FR0-FR12 and the stack temporaries at
 * frame+44 / +56 / +68 and the stage slots at frame+8 .. +36 are identical. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

#define R(n) (s->v[(n)])
#define F(n) VF3_FR(s, (n))
#define SIGN 0x80000000u

enum {
    SAVED_BYTES = 48, FRAME_BYTES = 92,
    DIV_ROUTINE = 0x8C042D7C, DIV_RET = 0x8C070044,
    V44 = 44, V56 = 56, V68 = 68
};

static uint32_t m32(const vf3_ram_map *ram, uint32_t a) { return vf3_mem_u32(ram, a); }
static void w32(const vf3_ram_map *ram, uint32_t a, uint32_t v) { vf3_mem_set_u32(ram, a, v); }
static float fl(const vf3_matrix_state *s, int n) { return vf3_fr_get(s, n); }
static void set_fl(vf3_matrix_state *s, int n, float v) { vf3_fr_set(s, n, v); }
static int fgt(const vf3_matrix_state *s, int a, int b) { return fl(s, a) > fl(s, b); }   /* fcmp/gt FRb,FRa */

/* dst = a - b */
static void v3_sub(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t d, uint32_t a, uint32_t b)
{
    R(4) = d; R(5) = a + 8; R(6) = b + 8;                 /* pointer registers as the inlined loop leaves them */
    F(0) = m32(ram, a); F(3) = m32(ram, b); F(1) = m32(ram, a + 4); F(4) = m32(ram, b + 4);
    set_fl(s, 0, vf3_f_sub(s, fl(s, 0), fl(s, 3)));
    F(2) = m32(ram, a + 8); F(5) = m32(ram, b + 8);
    set_fl(s, 1, vf3_f_sub(s, fl(s, 1), fl(s, 4)));
    set_fl(s, 2, vf3_f_sub(s, fl(s, 2), fl(s, 5)));
    w32(ram, d + 8, F(2)); w32(ram, d + 4, F(1)); w32(ram, d, F(0));
}

/* dst = a + b */
static void v3_add(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t d, uint32_t a, uint32_t b,
                   int in_place)
{
    R(4) = d; R(5) = in_place ? b + 12 : a + 12;
    if (!in_place) R(6) = b + 12;
    F(0) = m32(ram, a); F(3) = m32(ram, b); F(1) = m32(ram, a + 4); F(4) = m32(ram, b + 4);
    F(2) = m32(ram, a + 8); F(5) = m32(ram, b + 8);
    set_fl(s, 0, vf3_f_add(s, fl(s, 0), fl(s, 3)));
    set_fl(s, 2, vf3_f_add(s, fl(s, 2), fl(s, 5)));
    set_fl(s, 1, vf3_f_add(s, fl(s, 1), fl(s, 4)));
    w32(ram, d + 8, F(2)); w32(ram, d + 4, F(1)); w32(ram, d, F(0));
}

/* dst = a * FR4 */
static void v3_scale(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t d, uint32_t a)
{
    R(4) = d; R(5) = a + 12;
    F(0) = m32(ram, a); F(1) = m32(ram, a + 4); F(2) = m32(ram, a + 8);
    set_fl(s, 2, vf3_f_mul(s, fl(s, 2), fl(s, 4)));
    set_fl(s, 1, vf3_f_mul(s, fl(s, 1), fl(s, 4)));
    set_fl(s, 0, vf3_f_mul(s, fl(s, 0), fl(s, 4)));
    w32(ram, d + 8, F(2)); w32(ram, d + 4, F(1)); w32(ram, d, F(0));
}

/* dst = a / |a| * FR4  (fipr + fsrra) */
static int v3_normalize(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t d, uint32_t a)
{
    R(4) = d; R(5) = a + 12;
    F(0) = m32(ram, a); F(1) = m32(ram, a + 4); F(2) = m32(ram, a + 8);
    F(3) = 0;
    if (!vf3_fpu_fipr(&F(0), &F(0), R(VF3_REG_FPSCR), &F(3))) return 0;
    if (!vf3_fpu_fsrra(F(3), R(VF3_REG_FPSCR), &F(3))) return 0;
    set_fl(s, 3, vf3_f_mul(s, fl(s, 3), fl(s, 4)));
    set_fl(s, 2, vf3_f_mul(s, fl(s, 2), fl(s, 3)));
    set_fl(s, 1, vf3_f_mul(s, fl(s, 1), fl(s, 3)));
    set_fl(s, 0, vf3_f_mul(s, fl(s, 0), fl(s, 3)));
    w32(ram, d + 8, F(2)); w32(ram, d + 4, F(1)); w32(ram, d, F(0));
    return 1;
}

/* FR0 = |a|, FR3 left at 0 for the caller's comparison */
static int v3_length(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t a)
{
    R(4) = a + 12;
    F(0) = m32(ram, a); F(1) = m32(ram, a + 4); F(2) = m32(ram, a + 8);
    F(3) = 0;
    if (!vf3_fpu_fipr(&F(0), &F(0), R(VF3_REG_FPSCR), &F(3))) return 0;
    F(0) = F(3);
    F(0) = vf3_fpu_sqrt(F(0), R(VF3_REG_FPSCR));
    F(3) = 0;
    return 1;
}

/* FR0 = |a x b| */
static int v3_cross_length(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t a, uint32_t b)
{
    R(4) = a + 8; R(5) = b + 8;
    F(0) = m32(ram, a); F(5) = m32(ram, a + 4); F(6) = m32(ram, a + 8);
    F(8) = m32(ram, b); F(9) = m32(ram, b + 4); F(10) = m32(ram, b + 8);
    F(3) = F(5); set_fl(s, 3, vf3_f_mul(s, fl(s, 3), fl(s, 8)));
    F(2) = F(0); set_fl(s, 2, vf3_f_mul(s, fl(s, 2), fl(s, 10)));
    F(1) = F(6); set_fl(s, 1, vf3_f_mul(s, fl(s, 1), fl(s, 9)));
    F(3) ^= SIGN; set_fl(s, 3, vf3_f_mac(s, fl(s, 0), fl(s, 9), fl(s, 3)));
    F(2) ^= SIGN; F(0) = F(6); set_fl(s, 2, vf3_f_mac(s, fl(s, 0), fl(s, 8), fl(s, 2)));
    F(1) ^= SIGN; F(0) = F(5); set_fl(s, 1, vf3_f_mac(s, fl(s, 0), fl(s, 10), fl(s, 1)));
    F(0) = 0;
    if (!vf3_fpu_fipr(&F(0), &F(0), R(VF3_REG_FPSCR), &F(3))) return 0;
    F(0) = F(3);
    F(0) = vf3_fpu_sqrt(F(0), R(VF3_REG_FPSCR));
    return 1;
}

/* FR4 = FR0 = a . b ; FR3 = 0 */
static int v3_dot(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t a, uint32_t b)
{
    R(4) = a + 12; R(5) = b + 12;
    F(0) = m32(ram, a); F(1) = m32(ram, a + 4); F(2) = m32(ram, a + 8); F(3) = 0;
    F(4) = m32(ram, b); F(5) = m32(ram, b + 4); F(6) = m32(ram, b + 8); F(7) = 0;
    if (!vf3_fpu_fipr(&F(0), &F(4), R(VF3_REG_FPSCR), &F(7))) return 0;
    F(0) = F(7);
    F(3) = 0;
    F(4) = F(0);
    return 1;
}

typedef struct {
    vf3_matrix_state *s;
    const vf3_ram_map *ram;
    uint32_t frame;
    uint32_t end_a, axis_a;     /* r10 / r11 */
    uint32_t end_b, axis_b;     /* r9 / r12 */
} capsule;

/* Stage A: tests a node against the cylinder around (base, axis); the node's distance from the axis is
 * kept at frame+slot. Returns 0 on an FPU fault. */
static int stage_a(const capsule *c, uint32_t node, uint32_t base, uint32_t axis, uint32_t slot, int first)
{
    vf3_matrix_state *s = c->s; const vf3_ram_map *ram = c->ram;
    const uint32_t d = c->frame + V68, side = c->frame + V56;

    v3_sub(s, ram, d, node, base);
    if (!v3_length(s, ram, d)) return 0;
    F(12) = F(0);
    if (!(fl(s, 12) > fl(s, 3))) return 1;
    if (!v3_cross_length(s, ram, d, axis)) return 0;
    R(0) = slot;
    w32(ram, c->frame + slot, F(0));
    if (!fgt(s, 15, 0)) return 1;
    if (!v3_dot(s, ram, d, axis)) return 0;
    if (fgt(s, 3, 4)) {                                  /* behind the end point */
        if (!fgt(s, 15, 12)) return 1;
        if (first) {                                     /* the very first test pulls by (distance - radius) */
            F(4) = F(12);
            set_fl(s, 4, vf3_f_sub(s, fl(s, 4), fl(s, 15)));
            if (!v3_normalize(s, ram, d, d)) return 0;
            v3_add(s, ram, node, node, d, 1);
            return 1;
        }
        F(4) = F(15);
        if (!v3_normalize(s, ram, d, d)) return 0;
        v3_add(s, ram, node, d, base, 0);
        return 1;
    }
    if (!fgt(s, 14, 4)) return 1;                        /* beyond the axis length */
    v3_scale(s, ram, side, axis);
    v3_sub(s, ram, side, d, side);
    R(0) = slot;
    F(4) = F(15);
    F(3) = m32(ram, c->frame + slot);
    set_fl(s, 4, vf3_f_sub(s, fl(s, 4), fl(s, 3)));
    if (!v3_normalize(s, ram, side, side)) return 0;
    v3_add(s, ram, d, d, side, 1);
    v3_add(s, ram, node, d, base, 0);
    return 1;
}

/* Stage B: same test around (base, axis); the length to the end point is kept at frame+slot and the
 * cross-product length (fr12) gives the radial depth. */
static int stage_b(const capsule *c, uint32_t node, uint32_t base, uint32_t axis, uint32_t slot)
{
    vf3_matrix_state *s = c->s; const vf3_ram_map *ram = c->ram;
    const uint32_t d = c->frame + V68, side = c->frame + V56;

    v3_sub(s, ram, d, node, base);
    if (!v3_length(s, ram, d)) return 0;
    R(0) = slot;
    w32(ram, c->frame + slot, F(0));
    if (!fgt(s, 0, 3)) return 1;
    if (!v3_cross_length(s, ram, d, axis)) return 0;
    F(12) = F(0);
    if (!fgt(s, 15, 12)) return 1;
    if (!v3_dot(s, ram, d, axis)) return 0;
    if (fgt(s, 3, 4)) {                                  /* behind the end point: onto the sphere */
        R(0) = slot;
        F(3) = m32(ram, c->frame + slot);
        if (!fgt(s, 15, 3)) return 1;
        F(4) = F(15);
        if (!v3_normalize(s, ram, d, d)) return 0;
        v3_add(s, ram, node, d, base, 0);
        return 1;
    }
    if (!fgt(s, 14, 4)) return 1;
    v3_scale(s, ram, side, axis);
    v3_sub(s, ram, side, d, side);
    F(4) = F(15);
    set_fl(s, 4, vf3_f_sub(s, fl(s, 4), fl(s, 12)));
    if (!v3_normalize(s, ram, side, side)) return 0;
    v3_add(s, ram, d, d, side, 1);
    v3_add(s, ram, node, d, base, 0);
    return 1;
}

/* Pull `node` back to the link length (fr13) from `anchor`. */
static int link_length(const capsule *c, uint32_t node, uint32_t anchor)
{
    vf3_matrix_state *s = c->s; const vf3_ram_map *ram = c->ram;
    const uint32_t d = c->frame + V44;

    v3_sub(s, ram, d, node, anchor);
    if (!v3_length(s, ram, d)) return 0;
    if (!(fl(s, 0) > fl(s, 3))) return 1;
    F(4) = F(13);
    if (!v3_normalize(s, ram, d, d)) return 0;
    v3_add(s, ram, node, anchor, d, 0);
    return 1;
}

int vf3_capsule_chain_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), frame = sp0 - SAVED_BYTES - FRAME_BYTES;
    const uint32_t saved_r[7] = { R(14), R(13), R(12), R(11), R(10), R(9), R(8) };
    const uint32_t saved_f[4] = { F(15), F(14), F(13), F(12) };
    const uint32_t owner = R(4), rec = R(5), array_end = R(6);

    for (int i = 0; i < 7; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    for (int i = 0; i < 4; ++i) w32(ram, sp0 - 32u - 4u * (uint32_t)i, saved_f[i]);
    w32(ram, sp0 - 48u, pr0);
    R(15) = frame;
    w32(ram, frame + 40, 0);
    R(3) = 0;

    uint32_t node_lo = m32(ram, rec + 88);                 /* r14 (the pair count first) */
    R(14) = node_lo;
    R(0) = 168;
    w32(ram, frame, (uint32_t)((int32_t)node_lo >> 1));
    R(1) = node_lo;
    F(13) = m32(ram, rec + 96);
    F(14) = m32(ram, rec + 168);
    F(15) = m32(ram, rec + 172);

    R(3) = 0x0C042D7Cu;                                    /* remainder of count / 2 decides the layout */
    R(0) = 2;
    if (!vf3_guest_call(s, ram, DIV_ROUTINE, DIV_RET)) return 0;
    R(15) = frame;

    const uint32_t pairs = m32(ram, frame);
    uint32_t node_hi, anchor_lo, anchor_hi;                /* r13, r8, frame+4 */
    uint32_t flag;
    if (R(0) == 0) {                                       /* even: two walkers */
        anchor_lo = array_end - 24u * pairs;
        node_lo = anchor_lo;
        node_hi = array_end - 24u * (pairs + 1);
        anchor_hi = node_hi;
        flag = 1;
        R(1) = 24u * (pairs + 1);
    } else {                                               /* odd: one chain */
        R(1) = 24u * (pairs + 1);
        anchor_lo = array_end - R(1);
        node_lo = anchor_lo;
        node_hi = anchor_lo;
        anchor_hi = anchor_lo;
        flag = 0;
    }
    w32(ram, frame + 4, anchor_hi);
    w32(ram, frame + 40, flag);

    capsule c = { s, ram, frame, rec + 140, rec + 116, rec + 152, rec + 128 };
    const int part = (int16_t)(uint16_t)R(7);
    R(3) = 4;
    R(5) = (uint32_t)part;
    int skip_first = 0;
    if (!(part > 4) && vf3_mem_u8(ram, owner + 97) == 4) skip_first = 1;
    else if (!(part > 3) && vf3_mem_u8(ram, owner + 96) == 8) skip_first = 1;

    if (!skip_first) {
        if (!stage_a(&c, node_lo, c.end_a, c.axis_a, 12, 1)) return 0;
        if (!stage_b(&c, node_lo, c.end_b, c.axis_b, 20)) return 0;
    }
    if (flag == 1) {
        if (!stage_a(&c, node_hi, c.end_a, c.axis_a, 16, 0)) return 0;
        if (!stage_b(&c, node_hi, c.end_b, c.axis_b, 8)) return 0;
    }

    node_lo -= 24;
    node_hi += 24;
    if ((int32_t)m32(ram, frame) > 0) {
        for (;;) {
            if (!stage_b(&c, node_lo, c.end_a, c.axis_a, 24)) return 0;
            if (!stage_b(&c, node_lo, c.end_b, c.axis_b, 32)) return 0;
            if (!link_length(&c, node_lo, anchor_lo)) return 0;
            if (!stage_a(&c, node_hi, c.end_a, c.axis_a, 28, 0)) return 0;
            if (!stage_a(&c, node_hi, c.end_b, c.axis_b, 36, 0)) return 0;
            if (!link_length(&c, node_hi, m32(ram, frame + 4))) return 0;

            R(2) = m32(ram, frame + 4) + 24;
            w32(ram, frame + 4, R(2));
            node_hi += 24;
            anchor_lo -= 24;
            node_lo -= 24;
            const uint32_t left = m32(ram, frame) - 1;
            R(3) = left;
            w32(ram, frame, left);
            if (!((int32_t)left > 0)) break;
            R(1) = 0x0C070888u;
        }
    }

    R(VF3_REG_SR) &= ~1u;                                  /* the last test was cmp/pl: T clear on exit */
    R(15) = sp0;
    {
        static const int pushed[7] = { 14, 13, 12, 11, 10, 9, 8 };
        for (int i = 0; i < 7; ++i) R(pushed[i]) = saved_r[i];
    }
    F(15) = saved_f[0]; F(14) = saved_f[1]; F(13) = saved_f[2]; F(12) = saved_f[3];
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
