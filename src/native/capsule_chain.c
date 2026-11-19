/* capsule_chain.c - SH-4 0x8C070008: keep a chain of 24-byte nodes out of a
 * capsule and re-apply the link lengths, natively.
 *
 * A plain-C transcription of the readable port src/fight/capsule_chain.c
 * (`vf3_capsule_chain_entry`).  It operates on `vf3_native_aim`: the flat
 * RAM (every guest address resolves through `ram_base`), the FR bank and the
 * register file.  The float arithmetic is plain C (sqrtf instead of the
 * guest's fsrra/fipr double-accumulate), so node positions match the
 * readable within float tolerance rather than bit for bit.
 *
 *   r4 = owner object (bytes +96/+97 pick which of the first nodes are
 *   skipped), r5 = capsule record (node count, link length, two axes, two
 *   end points, axis length, radius), r6 = end of the node array, r7 = int16
 *   part number.  The nodes are walked from both ends of the array towards
 *   the middle (even count: two walkers; odd count: one chain).  Each node
 *   is tested against the capsule by two stages (behind the end cap -> moved
 *   onto the sphere; beside the segment -> moved radially out of the
 *   cylinder; beyond the axis length -> untouched) and then pulled back to
 *   its neighbour's link length.
 *
 * The function keeps a 140-byte frame under the entry sp: r14..r8 at
 * sp0-4..sp0-28, fr15..fr12 at sp0-32..sp0-44, pr at sp0-48.  On exit r8..r14,
 * fr12..fr15, pr and sp are restored and SR's T bit is cleared.  See
 * docs/re/native_capsule_chain.md. */
#include "capsule_chain.h"

#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (r[(n)])

#define SAVED_BYTES 48u
#define FRAME_BYTES 92u

/* ---- plain-C vec3 primitives (the inlined sequences of the readable) ---- */

static float ldf(vf3_native_aim *a, uint32_t addr)
{
    return vf3_aim_fbits(vf3_aim_u32(a, addr));
}
static void stf(vf3_native_aim *a, uint32_t addr, float v)
{
    vf3_aim_set_u32(a, addr, vf3_aim_ubits(v));
}
static void ld3(vf3_native_aim *a, uint32_t addr, float o[3])
{
    o[0] = ldf(a, addr); o[1] = ldf(a, addr + 4u); o[2] = ldf(a, addr + 8u);
}
static void st3(vf3_native_aim *a, uint32_t addr, const float o[3])
{
    stf(a, addr, o[0]); stf(a, addr + 4u, o[1]); stf(a, addr + 8u, o[2]);
}
static float l3(const float v[3])
{
    return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

/* d = a - b (the readable's v3_sub) */
static void ssub(const float a[3], const float b[3], float d[3])
{
    d[0] = a[0] - b[0]; d[1] = a[1] - b[1]; d[2] = a[2] - b[2];
}
static void scross(const float a[3], const float b[3], float c[3])
{
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
}
static float sdot(const float a[3], const float b[3])
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

/* Stage A: the node's distance from the axis is kept at frame+slot.  The
 * guest bails (returns 1 = keep going, no move) on the comparison arm that
 * is not taken; the native reproduces the same arm selection. */
static void stage_a(vf3_native_aim *a, uint32_t node, uint32_t base,
                    uint32_t axis, float radius, float axislen, int first)
{
    float pn[3], pb[3], ax[3], d[3], cx[3], side[3];
    ld3(a, node, pn); ld3(a, base, pb); ld3(a, axis, ax);

    ssub(pn, pb, d);                       /* d = node - base */
    const float len = l3(d);
    if (!(len > 0.0f)) return;

    scross(d, ax, cx);                     /* |d x axis| */
    const float cross = l3(cx);
    if (!(radius > cross)) return;

    const float dot = sdot(d, ax);
    if (dot < 0.0f) {                      /* behind the end point */
        if (!(radius > len)) return;
        if (first) {                       /* pull by (len - radius) along d */
            const float f = len - radius;
            const float il = 1.0f / len;
            side[0] = pn[0] + d[0] * (il * f);
            side[1] = pn[1] + d[1] * (il * f);
            side[2] = pn[2] + d[2] * (il * f);
            st3(a, node, side);
        } else {                           /* onto the sphere: d/|d| * radius + base */
            const float il = radius / len;
            side[0] = d[0] * il + pb[0];
            side[1] = d[1] * il + pb[1];
            side[2] = d[2] * il + pb[2];
            st3(a, node, side);
        }
        return;
    }
    if (!(axislen > dot)) return;          /* beyond the axis length */

    /* beside the segment: move radially out of the cylinder */
    side[0] = d[0] - (ax[0] * dot);
    side[1] = d[1] - (ax[1] * dot);
    side[2] = d[2] - (ax[2] * dot);
    const float f = radius - cross;
    const float sl = l3(side);
    const float il = (sl > 0.0f) ? f / sl : 0.0f;
    d[0] = d[0] + side[0] * il;            /* d = d + unit(side)*(radius-cross) */
    d[1] = d[1] + side[1] * il;
    d[2] = d[2] + side[2] * il;
    side[0] = d[0] + pb[0];                /* node = d + base */
    side[1] = d[1] + pb[1];
    side[2] = d[2] + pb[2];
    st3(a, node, side);
}

/* Stage B: same test around (base, axis); the length to the end point is
 * kept at frame+slot and the cross-product length gives the radial depth. */
static void stage_b(vf3_native_aim *a, uint32_t node, uint32_t base,
                    uint32_t axis, float radius, float axislen)
{
    float pn[3], pb[3], ax[3], d[3], cx[3], side[3];
    ld3(a, node, pn); ld3(a, base, pb); ld3(a, axis, ax);

    ssub(pn, pb, d);                       /* d = node - base */
    const float len = l3(d);
    if (!(len > 0.0f)) return;

    scross(d, ax, cx);                     /* |d x axis| */
    const float cross = l3(cx);
    if (!(radius > cross)) return;

    const float dot = sdot(d, ax);
    if (dot < 0.0f) {                      /* behind the end point: onto the sphere */
        if (!(radius > len)) return;
        const float il = radius / len;
        side[0] = d[0] * il + pb[0];
        side[1] = d[1] * il + pb[1];
        side[2] = d[2] * il + pb[2];
        st3(a, node, side);
        return;
    }
    if (!(axislen > dot)) return;          /* beyond the axis length */

    /* beside the segment */
    side[0] = d[0] - (ax[0] * dot);
    side[1] = d[1] - (ax[1] * dot);
    side[2] = d[2] - (ax[2] * dot);
    const float f = radius - cross;
    const float sl = l3(side);
    const float il = (sl > 0.0f) ? f / sl : 0.0f;
    d[0] = d[0] + side[0] * il;
    d[1] = d[1] + side[1] * il;
    d[2] = d[2] + side[2] * il;
    side[0] = d[0] + pb[0];
    side[1] = d[1] + pb[1];
    side[2] = d[2] + pb[2];
    st3(a, node, side);
}

/* Pull `node` back to the link length from `anchor`. */
static void link_length(vf3_native_aim *a, uint32_t node, uint32_t anchor,
                        float link)
{
    float pn[3], pa[3], d[3];
    ld3(a, node, pn); ld3(a, anchor, pa);
    ssub(pn, pa, d);                       /* d = node - anchor */
    const float len = l3(d);
    if (!(len > 0.0f)) return;
    const float il = link / len;
    d[0] = pa[0] + d[0] * il;              /* node = anchor + d/|d| * link */
    d[1] = pa[1] + d[1] * il;
    d[2] = pa[2] + d[2] * il;
    st3(a, node, d);
}

void vf3_native_capsule_chain(vf3_native_aim *a, uint32_t sp0, uint32_t owner,
                              uint32_t rec, uint32_t array_end, uint16_t part_in)
{
    uint32_t r[16];
    for (int i = 0; i < 16; ++i) r[i] = a->r[i];
    R(4) = owner; R(5) = rec; R(6) = array_end; R(7) = part_in; R(15) = sp0;

    const uint32_t frame = sp0 - SAVED_BYTES - FRAME_BYTES;

    /* the entry register / float / pr values the frame will restore */
    uint32_t saved_r[7];
    for (int i = 0; i < 7; ++i) saved_r[i] = R(14 - (uint32_t)i);   /* r14..r8 */
    uint32_t saved_f[4];
    for (int i = 0; i < 4; ++i)
        memcpy(&saved_f[i], &a->fr[15 - i], 4);                      /* fr15..fr12 */
    const uint32_t pr0 = a->pr;

    /* ---- prologue: push the saved registers ---- */
    for (int i = 0; i < 7; ++i)
        vf3_aim_set_u32(a, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    for (int i = 0; i < 4; ++i)
        vf3_aim_set_u32(a, sp0 - 32u - 4u * (uint32_t)i, saved_f[i]);
    vf3_aim_set_u32(a, sp0 - 48u, pr0);
    R(15) = frame;
    vf3_aim_set_u32(a, frame + 40u, 0);

    const uint32_t count = vf3_aim_u32(a, rec + 88u);               /* node count */
    const int32_t pairs = (int32_t)count >> 1;
    vf3_aim_set_u32(a, frame, (uint32_t)pairs);
    const float link = ldf(a, rec + 96u);
    const float axislen = ldf(a, rec + 168u);
    const float radius = ldf(a, rec + 172u);

    const uint32_t r0_mod = count & 1u;    /* the division helper's remainder */

    uint32_t node_lo, node_hi, anchor_lo, anchor_hi, flag;
    if (r0_mod == 0u) {                    /* even: two walkers */
        anchor_lo = array_end - 24u * (uint32_t)pairs;
        node_lo = anchor_lo;
        node_hi = array_end - 24u * ((uint32_t)pairs + 1u);
        anchor_hi = node_hi;
        flag = 1u;
    } else {                               /* odd: one chain */
        anchor_lo = array_end - 24u * ((uint32_t)pairs + 1u);
        node_lo = anchor_lo;
        node_hi = anchor_lo;
        anchor_hi = anchor_lo;
        flag = 0u;
    }
    vf3_aim_set_u32(a, frame + 4u, anchor_hi);
    vf3_aim_set_u32(a, frame + 40u, flag);

    const uint32_t end_a = rec + 140u, axis_a = rec + 116u;
    const uint32_t end_b = rec + 152u, axis_b = rec + 128u;

    const int32_t part = (int32_t)(int16_t)part_in;
    int skip_first = 0;
    if (!(part > 4) && vf3_aim_u8(a, owner + 97u) == 4u) skip_first = 1;
    else if (!(part > 3) && vf3_aim_u8(a, owner + 96u) == 8u) skip_first = 1;

    if (!skip_first) {
        stage_a(a, node_lo, end_a, axis_a, radius, axislen, 1);
        stage_b(a, node_lo, end_b, axis_b, radius, axislen);
    }
    if (flag == 1u) {
        stage_a(a, node_hi, end_a, axis_a, radius, axislen, 0);
        stage_b(a, node_hi, end_b, axis_b, radius, axislen);
    }

    node_lo -= 24u;
    node_hi += 24u;
    if (pairs > 0) {
        for (;;) {
            stage_b(a, node_lo, end_a, axis_a, radius, axislen);
            stage_b(a, node_lo, end_b, axis_b, radius, axislen);
            link_length(a, node_lo, anchor_lo, link);
            stage_a(a, node_hi, end_a, axis_a, radius, axislen, 0);
            stage_a(a, node_hi, end_b, axis_b, radius, axislen, 0);
            link_length(a, node_hi, vf3_aim_u32(a, frame + 4u), link);

            vf3_aim_set_u32(a, frame + 4u, vf3_aim_u32(a, frame + 4u) + 24u);
            node_hi += 24u;
            anchor_lo -= 24u;
            node_lo -= 24u;
            const int32_t left = (int32_t)vf3_aim_u32(a, frame) - 1;
            vf3_aim_set_u32(a, frame, (uint32_t)left);
            if (!(left > 0)) break;
        }
    }

    /* ---- epilogue: the last test was cmp/pl, so T is clear ---- */
    a->sr &= ~1u;
    a->r[15] = sp0;
    for (int i = 0; i < 7; ++i) a->r[8 + i] = saved_r[6 - i];       /* r8..r14 */
    a->fr[15] = *(const float *)&saved_f[0];
    a->fr[14] = *(const float *)&saved_f[1];
    a->fr[13] = *(const float *)&saved_f[2];
    a->fr[12] = *(const float *)&saved_f[3];
    a->pr = pr0;
}
