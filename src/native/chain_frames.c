/* chain_frames.c - SH-4 0x8C071694: give every node of a chain an orthonormal
 * side vector, natively.
 *
 * A plain-C transcription of the readable port src/fight/chain_frames.c
 * (`vf3_chain_frames_entry`) onto `vf3_native_aim`: the flat RAM (every guest
 * address resolves through `ram_base`) and the register file.  No guest SH-4
 * code runs - the two edge crosses per node and their normalisations are
 * plain-C float ops.
 *
 * The readable routes every FP op through the guest round-toward-zero helpers
 * and normalises with the SH-4's approximate fsrra; the native port uses plain
 * C `sqrtf` / `1/sqrtf` like the neighbouring capsule family.  chain_frames'
 * only outputs are the per-node +12 side vectors (floats), so they match the
 * readable within tolerance rather than bit for bit; the saved-register stack
 * and the contract registers (r8..r14, fr12..fr15, pr, SR's T bit cleared)
 * match bit for bit.  See docs/re/native_chain_frames.md. */
#include "chain_frames.h"

#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])

/* ---- ground-address decode (the guest's vf3_matrix_read masking) ---- */
static uint32_t mir(uint32_t addr)
{
    addr &= 0x1FFFFFFFu;
    if (addr >= 0x0c000000u && addr < 0x10000000u)
        addr = 0x0c000000u | (addr & 0x00ffffffu);
    return addr;
}
static uint32_t rd32(vf3_native_aim *a, uint32_t addr)
{
    return vf3_aim_u32(a, mir(addr));
}
static void ld3(vf3_native_aim *a, uint32_t addr, float o[3])
{
    uint32_t b = mir(addr);
    o[0] = vf3_aim_fbits(vf3_aim_u32(a, b));
    o[1] = vf3_aim_fbits(vf3_aim_u32(a, b + 4u));
    o[2] = vf3_aim_fbits(vf3_aim_u32(a, b + 8u));
}
static void st3(vf3_native_aim *a, uint32_t addr, const float o[3])
{
    uint32_t b = mir(addr);
    vf3_aim_set_u32(a, b, vf3_aim_ubits(o[0]));
    vf3_aim_set_u32(a, b + 4u, vf3_aim_ubits(o[1]));
    vf3_aim_set_u32(a, b + 8u, vf3_aim_ubits(o[2]));
}

/* ---- plain-C vec3 primitives (the readable's FR sequences) ---- */
static float sdot(const float a[3], const float b[3])
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}
static void ssub(const float a[3], const float b[3], float d[3])
{
    d[0] = a[0] - b[0]; d[1] = a[1] - b[1]; d[2] = a[2] - b[2];
}
static void sadd(const float a[3], const float b[3], float d[3])
{
    d[0] = a[0] + b[0]; d[1] = a[1] + b[1]; d[2] = a[2] + b[2];
}
static void scross(const float a[3], const float b[3], float c[3])
{
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
}
static void unit3(float v[3])
{
    const float il = 1.0f / sqrtf(sdot(v, v));
    v[0] *= il; v[1] *= il; v[2] *= il;
}
/* node + 12 = unit(cross_a + cross_b), the two crosses normalised first */
static void finish_node(vf3_native_aim *a, uint32_t node,
                        const float x1[3], const float x2[3])
{
    float n1[3] = { x1[0], x1[1], x1[2] };
    float n2[3] = { x2[0], x2[1], x2[2] };
    unit3(n1); unit3(n2);
    float out[3];
    sadd(n1, n2, out);
    unit3(out);
    st3(a, node + 12u, out);
}
/* the last-node form: a single cross straight into the node */
static void single_cross(vf3_native_aim *a, uint32_t node,
                         const float ea[3], const float eb[3])
{
    float c[3];
    scross(ea, eb, c);
    unit3(c);
    st3(a, node + 12u, c);
}

void vf3_native_chain_frames(vf3_native_aim *a, uint32_t sp0, uint32_t obj)
{
    const uint32_t NODE = 24u;

    /* entry values the epilogue restores */
    const uint32_t e8 = R(8), e9 = R(9), e10 = R(10), e11 = R(11);
    const uint32_t e12 = R(12), e13 = R(13), e14 = R(14);

    /* prologue: push the seven saved registers (frame 96 bytes below them;
     * the working area is kept as locals, not written to RAM) */
    uint32_t saved_r[7] = { e14, e13, e12, e11, e10, e9, e8 };
    for (int i = 0; i < 7; ++i) vf3_aim_set_u32(a, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    R(15) = sp0 - 28u - 96u;

    /* chain parameters */
    const uint32_t n = rd32(a, obj + 88u);
    const uint32_t m = rd32(a, obj + 92u);
    const uint32_t base = rd32(a, obj + 4u);

    /* the walk's live pointers (the readable's r8/r14/r11) and its frame
     * slots: s0/s4 the two neighbour pointers (frame+0 / +4), r20 the n-1 run
     * counter, r8 the head/run counter, r16 the phase counter. */
    uint32_t prev = base;
    uint32_t cur = base + NODE;
    uint32_t next = base + 2u * NODE;
    uint32_t s0 = base + NODE * n + NODE;       /* frame+0 */
    uint32_t s4 = base;                          /* frame+4 */
    uint32_t r20 = n - 1u;                       /* frame+20 */
    uint32_t r8 = n - 1u;                        /* frame+8 */
    uint32_t r16 = 0u;                           /* frame+16 */
    uint32_t r12 = m;                            /* frame+12 (m, later the E4 addr) */

    float E1[3], E2[3], E3[3], E4[3], X1[3], X2[3], cv[3];

    /* phase 1: the head nodes */
    if ((int32_t)(n - 1u) > 1) {
        for (;;) {
            ld3(a, s4, E1); ld3(a, cur, cv); ssub(E1, cv, E1);
            ld3(a, next, E2); ssub(E2, cv, E2);
            ld3(a, s0, E3); ssub(E3, cv, E3);
            scross(E3, E1, X1);
            scross(E2, E3, X2);
            finish_node(a, cur, X1, X2);
            s4 = cur;
            cur = next; next += NODE;
            s0 += NODE;
            uint32_t left = r8 - 1u; r8 = left;
            if (!((int32_t)left > 1)) break;
        }
    }

    /* phase 2: the first join */
    {
        ld3(a, s4, E1); ld3(a, cur, cv); ssub(E1, cv, E1);
        ld3(a, s0, E2); ssub(E2, cv, E2);
        single_cross(a, cur, E2, E1);
        s0 += NODE;
        cur = next;
        r16 = r12 - 1u;                          /* frame+16 = m - 1 */
        r12 = 0u;                                /* E4 address: no longer needed */
        next += NODE;
    }

    /* phases 3 / 4 / 5 around the shared run */
    for (;;) {
        if (!((int32_t)r16 > 1)) break;

        /* phase 3 */
        ld3(a, next, E1); ld3(a, cur, cv); ssub(E1, cv, E1);
        ld3(a, s0, E2); ssub(E2, cv, E2);
        ld3(a, prev, E3); ssub(E3, cv, E3);
        scross(E1, E2, X1);
        scross(E3, E1, X2);
        finish_node(a, cur, X1, X2);
        s4 = cur;
        cur = next; next += NODE;
        s0 += NODE;
        uint32_t run = r20;
        r8 = run;
        prev += NODE;
        if ((int32_t)run > 1) {
            for (;;) {                          /* phase 4: the counted run */
                ld3(a, s4, E1); ld3(a, cur, cv); ssub(E1, cv, E1);
                ld3(a, next, E2); ssub(E2, cv, E2);
                ld3(a, s0, E3); ssub(E3, cv, E3);
                ld3(a, prev, E4); ssub(E4, cv, E4);      /* E4 = prev - cur */
                scross(E3, E1, X1);
                scross(E4, E2, X2);
                finish_node(a, cur, X1, X2);
                s4 = cur;
                cur = next; next += NODE; prev += NODE;
                s0 += NODE;
                uint32_t left = r8 - 1u; r8 = left;
                if (!((int32_t)left > 1)) break;
            }
        }

        /* phase 5 */
        ld3(a, s4, E1); ld3(a, cur, cv); ssub(E1, cv, E1);
        ld3(a, s0, E2); ssub(E2, cv, E2);
        ld3(a, prev, E3); ssub(E3, cv, E3);
        scross(E1, E3, X1);
        scross(E2, E1, X2);
        finish_node(a, cur, X1, X2);
        uint32_t tail = s0;
        cur = next; next += NODE; prev += NODE;
        s0 = tail + NODE;
        r16 -= 1u;
    }

    /* phase 6: the second join */
    {
        ld3(a, next, E1); ld3(a, cur, cv); ssub(E1, cv, E1);
        ld3(a, prev, E2); ssub(E2, cv, E2);
        single_cross(a, cur, E2, E1);
        s0 = cur;
        cur = next; next += NODE;
        uint32_t second = r20;
        s4 = second;                             /* frame+4 becomes the run counter */
        prev += NODE;
        if ((int32_t)second > 1) {
            for (;;) {                          /* phase 7 */
                ld3(a, s0, E1); ld3(a, cur, cv); ssub(E1, cv, E1);
                ld3(a, next, E2); ssub(E2, cv, E2);
                ld3(a, prev, E3); ssub(E3, cv, E3);
                scross(E3, E2, X1);
                scross(E1, E3, X2);
                finish_node(a, cur, X1, X2);
                s0 = cur;
                cur = next;
                uint32_t left = s4 - 1u;
                next += NODE; prev += NODE;
                s4 = left;
                if (!((int32_t)left > 1)) break;
            }
        }
    }

    /* phase 8: the last node */
    {
        ld3(a, s0, E1); ld3(a, cur, cv); ssub(E1, cv, E1);
        ld3(a, prev, E2); ssub(E2, cv, E2);
        single_cross(a, cur, E1, E2);
    }

    /* epilogue: the last compare (cmp/gt) was false, so SR's T bit is clear */
    a->sr &= ~1u;
    a->r[15] = sp0;
    a->r[8] = e8; a->r[9] = e9; a->r[10] = e10; a->r[11] = e11;
    a->r[12] = e12; a->r[13] = e13; a->r[14] = e14;
    /* pr is preserved (chain_frames never touches it) */
}
