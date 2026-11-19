/* body_capsule.c - SH-4 0x8C06F450: fit a fighter's capsule to the current
 * pose and run the node-chain collision once per chain, natively.
 *
 * A plain-C transcription of the readable port src/fight/body_capsule.c
 * (`vf3_body_capsule_entry`).  It operates on `vf3_native_aim`: the flat RAM
 * (every guest address resolves through `ram_base`), the FR bank, the matrix
 * (XMTRX) and the register file.  Float arithmetic is plain C (sqrtf/fmaf
 * instead of the guest's fsrra/fipr double-accumulate), so the written float
 * quads match the readable within tolerance rather than bit for bit; the
 * saved-register stack and the contract registers (r8..r14, fr12..fr15, pr,
 * sp and SR's T bit) match bit for bit.
 *
 * The ground-address convention: the guest memory map strips the SH-4's 29-bit
 * mirror (0x8C000000 -> 0x0C000000 and the area-3 RAM masks), so the literal
 * pool constants (0x8C06F6xx) and the in-RAM data (owner/rec/frame) all
 * resolve onto the flat RAM.  `mir` reproduces that decode before every
 * access.
 *
 * See docs/re/native_body_capsule.md. */
#include "body_capsule.h"
#include "capsule_chain.h"
#include "matrix.h"

#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (r[(n)])

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
static void wr32(vf3_native_aim *a, uint32_t addr, uint32_t v)
{
    vf3_aim_set_u32(a, mir(addr), v);
}
static uint16_t rdu16(vf3_native_aim *a, uint32_t addr)
{
    return vf3_aim_h16(a, mir(addr));
}
static uint8_t rdu8(vf3_native_aim *a, uint32_t addr)
{
    return vf3_aim_u8(a, mir(addr));
}
static float rdfl(vf3_native_aim *a, uint32_t addr)
{
    return vf3_aim_fbits(vf3_aim_u32(a, mir(addr)));
}
static void wrfl(vf3_native_aim *a, uint32_t addr, float v)
{
    vf3_aim_set_u32(a, mir(addr), vf3_aim_ubits(v));
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

/* ---- plain-C vec3 primitives (the inlined sequences of the readable) ---- */
static float l3(const float v[3])
{
    return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}
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
/* node + 12 = unit(cross_a + cross_b), the two crosses normalised first
 * (the chain_frames finish_node / single_cross) */
static void unit3(float v[3])
{
    float l2 = sdot(v, v);
    const float il = 1.0f / sqrtf(l2);
    v[0] *= il; v[1] *= il; v[2] *= il;
}
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
static void single_cross(vf3_native_aim *a, uint32_t node,
                         const float ea[3], const float eb[3])
{
    float c[3];
    scross(ea, eb, c);
    unit3(c);
    st3(a, node + 12u, c);
}

/* ---- matrix helpers ---- */
static void invert_xm(vf3_native_aim *a)
{
    float tmp[16];
    vf3_aim_invert_rigid(a->xm, tmp);   /* not in-place safe */
    memcpy(a->xm, tmp, sizeof tmp);
}
static void concat_at(vf3_native_aim *a, uint32_t addr)
{
    float m[16], out[16];
    memcpy(m, vf3_aim_p(a, mir(addr)), 64u);
    vf3_native_matrix_multiply(a->xm, m, out);
    memcpy(a->xm, out, 64u);
}

/* v = XMTRX * (x,y,z,w); store xyz at dst.  point -> w=1, direction -> w=0. */
static void xform_p1(vf3_native_aim *a, uint32_t src, uint32_t dst)
{
    float v[3], out[3];
    memcpy(v, vf3_aim_p(a, mir(src)), 12u);
    vf3_native_matrix_transform_point(a->xm, v, out);
    float *d = vf3_aim_p(a, mir(dst));
    d[0] = out[0]; d[1] = out[1]; d[2] = out[2];
}
static void xform_p0(vf3_native_aim *a, uint32_t src, uint32_t dst)
{
    float v[3], out[3];
    memcpy(v, vf3_aim_p(a, mir(src)), 12u);
    for (int r = 0; r < 3; ++r)
        out[r] = a->xm[r] * v[0] + a->xm[4 + r] * v[1] + a->xm[8 + r] * v[2];
    float *d = vf3_aim_p(a, mir(dst));
    d[0] = out[0]; d[1] = out[1]; d[2] = out[2];
}

/* ---- FIXUP_A: chain_frames (0x8C071694) strip walk ----
 * For each node N with neighbours P (previous), Q (next) and R (a neighbour
 * further along) it builds two edge vectors, crosses them with the third,
 * normalises both crosses, adds them and normalises the sum into N+12.  The
 * walk has eight phases over the closed strip; each differs only in which
 * neighbours it uses and in the order of the two crosses.  The readable runs
 * its frame temporaries (edges/crosses/counters) in RAM below the saved
 * block; the native port keeps them as locals (they are not compared), only
 * the node+12 side vectors (write to RAM, in the compared region) matter. */
static void fixup_a(vf3_native_aim *a, uint32_t obj)
{
    const uint32_t NODE = 24u;
    const uint32_t n = rd32(a, obj + 88u);
    const uint32_t m = rd32(a, obj + 92u);
    const uint32_t base = rd32(a, obj + 4u);

    /* prev = r8's frame slot, cur = r14, next = r11; s0/s4 are the two
     * pointer slots (frame+0 / frame+4), r20 the n-1 run counter, r8 the
     * head/run counter, r16 the phase counter. */
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
}

/* ---- FIXUP_B: negate_copy (0x8C072B02) ---- */
static void fixup_b(vf3_native_aim *a, uint32_t rec)
{
    int32_t count = (int32_t)rd32(a, rec);
    uint32_t src = rd32(a, rec + 4u), dst = rd32(a, rec + 8u);
    while (count > 0) {
        for (int i = 0; i < 6; ++i) {
            uint32_t v = rd32(a, src);
            if (i >= 3) v ^= 0x80000000u;        /* fneg: flip the sign bit */
            wr32(a, dst, v);
            src += 4u; dst += 4u;
        }
        --count;
    }
}

void vf3_native_body_capsule(vf3_native_aim *a, uint32_t sp0, uint32_t owner,
                             uint32_t rec)
{
    uint32_t r[16];
    for (int i = 0; i < 16; ++i) r[i] = a->r[i];
    R(4) = owner; R(5) = rec; R(15) = sp0;

    const uint32_t pr0 = a->pr;
    const uint32_t frame = sp0 - 52u - 116u;

    /* entry values the epilogue restores */
    const uint32_t e8 = R(8), e9 = R(9), e10 = R(10), e11 = R(11);
    const uint32_t e12 = R(12), e13 = R(13), e14 = R(14);
    const float ef15 = a->fr[15], ef14 = a->fr[14], ef13 = a->fr[13], ef12 = a->fr[12];

    /* ---- prologue: push the saved registers ---- */
    uint32_t saved_r[7] = { e14, e13, e12, e11, e10, e9, e8 };
    for (int i = 0; i < 7; ++i) wr32(a, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    wr32(a, sp0 - 32u, vf3_aim_ubits(ef15));
    wr32(a, sp0 - 36u, vf3_aim_ubits(ef14));
    wr32(a, sp0 - 40u, vf3_aim_ubits(ef13));
    wr32(a, sp0 - 44u, vf3_aim_ubits(ef12));
    wr32(a, sp0 - 48u, pr0);
    wr32(a, sp0 - 52u, 0);                       /* macl: not in the native model */
    R(14) = rec; R(11) = owner; R(13) = 0x0C29BCC4u;   /* SCALE_CELL */
    R(15) = frame;

    /* WORD_COPY: copy the constant axis vector (12 B) into frame+20 */
    for (int i = 0; i < 3; ++i) wr32(a, frame + 20u + 4u * (uint32_t)i,
                                     rd32(a, 0x0C0D3D68u + 4u * (uint32_t)i));

    /* MATRIX_LOAD m32(rec+12); MATRIX_POP_A (invert); MATRIX_PUSH(0) */
    vf3_aim_load(a, mir(rd32(a, rec + 12u)));
    invert_xm(a);
    vf3_aim_push(a, 0);
    /* SELECT_BONE m32(rec+108): XMTRX *= M(rec+108) */
    concat_at(a, rd32(a, rec + 108u));

    /* end point A / axis A through the first matrix block */
    const float axlen = rdfl(a, rec + 0xA4u);    /* the axis length as x */
    wrfl(a, frame + 8u, axlen); wrfl(a, frame + 12u, 0.0f); wrfl(a, frame + 16u, 0.0f);
    xform_p1(a, frame + 8u, rec + 0x8Cu);
    xform_p0(a, frame + 20u, rec + 116u);

    /* MATRIX_POP_B, SELECT_BONE m32(rec+112) */
    vf3_aim_pop(a);
    concat_at(a, rd32(a, rec + 112u));
    xform_p1(a, frame + 8u, rec + 0x98u);
    xform_p0(a, frame + 20u, rec + 0x80u);

    /* ---- chain parameters ---- */
    const uint32_t n = rd32(a, rec + 88u);       /* R10 */
    const uint32_t m = rd32(a, rec + 92u);       /* R3 */
    wr32(a, frame + 4u, m);
    float F14 = rdfl(a, rec + 100u);             /* node reach */
    const float LIT_TENTH = rdfl(a, 0x8C06F664u);
    float F13 = rdfl(a, rec + 84u) * LIT_TENTH;  /* link scale * tenth */
    const uint32_t owner72 = rd32(a, owner + 72u);
    float F15 = 0.0f;

    uint32_t r9 = 2u;
    if ((owner72 & 0x21000u) != 0u) {
        r9 = r9;                                 /* R9 stays 2 */
        float F3 = vf3_aim_fbits(vf3_aim_ubits(rdfl(a, 0x0C29BCC4u)) ^ 0x80000000u);
        wrfl(a, frame + 108u, F3);
        wrfl(a, frame + 112u, F15);
        const float LIT_FIVE = rdfl(a, 0x8C06F66Cu);
        const uint32_t o96 = rdu8(a, owner + 96u);
        float F3b = rdfl(a, 0x0C29BCC4u) * LIT_FIVE;
        if (o96 == 21u) F3b = vf3_aim_fbits(vf3_aim_ubits(F3b) ^ 0x80000000u);
        wrfl(a, frame + 104u, F3b);
    } else {
        wrfl(a, frame + 112u, F15);
        wrfl(a, frame + 104u, F15);
        const float LIT_EIGHT = rdfl(a, 0x8C06F670u);
        float F2 = rdfl(a, 0x0C29BCC4u) * LIT_EIGHT;
        F2 = vf3_aim_fbits(vf3_aim_ubits(F2) ^ 0x80000000u);
        wrfl(a, frame + 108u, F2);
    }

    /* ---- first chain / node pointers ---- */
    {
        const uint32_t o97 = rdu8(a, owner + 97u);
        if (o97 == 8u || o97 == 12u) r9 = 1u;
        const uint32_t start = rd32(a, rec + 4u) + (r9 - 1u) * n * 24u;
        R(12) = start;
        R(13) = start + n * 24u;                  /* end of the first chain */
        wr32(a, frame, rd32(a, rec + 12u));       /* frame[0] = matrix pointer */
    }
    const uint16_t owner62 = rdu16(a, owner + 62u);
    const int tail = (owner62 < 2u);

    uint32_t node = R(12), nbr = R(13), r8 = r9, i = 0u;

    if (!tail) {
        /* matrix setup for the chain loop */
        const uint32_t owner72b = rd32(a, owner + 72u);
        vf3_aim_push(a, 0);
        vf3_aim_load(a, mir(rd32(a, frame)));
        invert_xm(a);
        if ((0x21000u & owner72b) == 0u) xform_p0(a, frame + 104u, frame + 104u);
        concat_at(a, rec + 16u);

        const float LIT_STEP = rdfl(a, 0x8C06F6D8u);
        const float LIT_EPS = rdfl(a, 0x8C06F738u);
        const float F12 = 1.0f;

        for (;;) {
            if ((int32_t)r8 >= (int32_t)m) break;
            F13 += LIT_STEP;
            if (F13 > F12) F13 = F12;
            if ((int32_t)n > 0) {
                for (i = 0; (int32_t)i < (int32_t)n; ) {
                    float fv[3], nv[3], f56[3], f80[3], f92[3], f68[3], f44[3], f32[3];
                    ld3(a, nbr, nv); ld3(a, node, fv);
                    ssub(nv, fv, f56);                       /* frame+56 = nbr - node */
                    const float len = l3(f56);
                    if (LIT_EPS > len) {                     /* degenerate: (reach,0,0) */
                        f56[0] = F14; f56[1] = 0.0f; f56[2] = 0.0f;
                    } else {
                        const float il = F14 / sqrtf(sdot(f56, f56));
                        f56[0] *= il; f56[1] *= il; f56[2] *= il;
                    }
                    /* nbr = f56 + node */
                    float nd[3]; sadd(f56, fv, nd); st3(a, nbr, nd);
                    xform_p1(a, nbr, frame + 80u);           /* frame+80 = XMTRX*nbr */
                    ld3(a, nbr, nv); ld3(a, frame + 80u, f80);
                    ssub(f80, nv, f92);                      /* frame+92 = frame+80 - nbr */
                    f92[0] *= F13; f92[1] *= F13; f92[2] *= F13;
                    const float l92 = l3(f92);
                    (void)l92;                               /* length computed, unused below */
                    float f104[3]; ld3(a, frame + 104u, f104);
                    sadd(f92, f104, f68);                    /* frame+68 = frame+92 + frame+104 */
                    memcpy(f44, f56, 12u);                   /* frame+44 = frame+56 */
                    const float dotv = sdot(f44, f68);       /* v3_dot */
                    {
                        const float il = dotv / sqrtf(sdot(f44, f44));
                        f32[0] = f44[0] * il; f32[1] = f44[1] * il; f32[2] = f44[2] * il;
                    }
                    f68[0] -= f32[0]; f68[1] -= f32[1]; f68[2] -= f32[2];
                    sadd(f56, f68, f44);                     /* frame+44 = frame+56 + frame+68 */
                    {
                        const float il = F14 / sqrtf(sdot(f44, f44));
                        f44[0] *= il; f44[1] *= il; f44[2] *= il;
                    }
                    st3(a, frame + 80u, (const float[]){ fv[0] + f44[0], fv[1] + f44[1], fv[2] + f44[2] });
                    st3(a, nbr, (const float[]){ fv[0] + f44[0], fv[1] + f44[1], fv[2] + f44[2] });
                    i++; node += 24u; nbr += 24u;
                }
            }
            /* CAPSULE_CHAIN(owner, rec, array_end=nbr, part=r8) */
            vf3_native_capsule_chain(a, frame, owner, rec, nbr, (uint16_t)r8);
            r8 += 1u;
        }
        vf3_aim_pop(a);
        fixup_a(a, rec);
        fixup_b(a, rec);
        /* the guest path through capsule_chain / FIXUP_A / FIXUP_B / FINISH
         * leaves SR.T set (the chain loop's own comparisons, not the native
         * capsule_chain's deterministic clear, are the last word). */
        a->sr |= 1u;
    }

    /* FINISH: copy the matrix at m32(frame) (the rec+12 block) to rec+16 */
    vf3_aim_copy(a, rec + 16u, rd32(a, frame));

    /* ---- epilogue ---- */
    a->r[15] = sp0;
    a->r[8] = e8; a->r[9] = e9; a->r[10] = e10; a->r[11] = e11;
    a->r[12] = e12; a->r[13] = e13; a->r[14] = e14;
    a->fr[15] = ef15; a->fr[14] = ef14; a->fr[13] = ef13; a->fr[12] = ef12;
    a->pr = pr0;
    /* SR.T: the guest leaves the T bit set on both paths (the run through
     * FINISH / capsule_chain / negate_copy never clears it; the tail path
     * keeps the entry T bit).  The epilogue restores no SR, so the native
     * leaves the T bit at whatever the run left it at - here, unchanged from
     * entry.  The comparison is `(sr&1)==(guest v[17]&1)`, an equality, not a
     * fixed value. */
}
