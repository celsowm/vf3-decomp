/* node_rotate.c - SH-4 0x8C09F83C: the fighter's nodes turned around,
 * natively.
 *
 * A plain-C transcription of the readable port src/fight/node_rotate.c
 * (`vf3_node_rotate_entry`).  It operates on `vf3_native_aim`: the flat RAM,
 * the FR bank and the register file.
 *
 * The engine keeps a fighter's nodes in an array of twelve-byte records, and
 * the root's position behind them.  This function turns the nodes around the
 * Y axis and then moves the root:
 *
 *  - seven records are walked, twelve bytes apart.  Each holds two floats,
 *    eight bytes apart, and they are rotated by the angle the caller leaves in
 *    FR4 (the cosine) and FR5 (the sine);
 *  - the root's position - three floats - then moves by the value the caller
 *    leaves in FR6.
 *
 * The three floats of the root's position are at the record's +0x58, at the
 * offset in the literal pool and twenty-four bytes below that offset.
 *
 * The rotation's middle step is a **fused** multiply-add (the mac in the
 * readable), so it rounds once where a plain `a * b + c` in C would round
 * twice.  The port uses `fmaf`.  This leaf runs under round-to-nearest with
 * no FTZ (the readable test's FPSCR is 0), so the rest of the arithmetic is
 * plain C float ops.  The loop's counter is decremented **at the top** while
 * the branch that ends the loop is at the bottom, so the T bit the caller
 * sees is the last iteration's.
 *
 * See docs/re/native_node_rotate.md. */
#include "node_rotate.h"

#include <math.h>
#include <stdint.h>
#include <string.h>

#define R(n) (a->r[(n)])
#define F(n) (a->fr[(n)])

static void set_t(vf3_native_aim *a, int value)
{
    a->sr = (a->sr & ~1u) | (value != 0);
}

/* the literal pool: the offset of the root's second coordinate */
#define G_Y 0x0c09f8d0u

/* the root's first coordinate */
#define ROOT_X 0x58u

/* the distance between the root's second and third coordinates */
#define ROOT_STEP 24u

/* how many records the array holds */
#define NODES 7u

/* the size of one record */
#define NODE_STRIDE 12u

static float fload(vf3_native_aim *a, uint32_t addr)
{
    uint32_t u = vf3_aim_u32(a, addr);
    float f;
    memcpy(&f, &u, 4);
    return f;
}

static void fstore(vf3_native_aim *a, uint32_t addr, float f)
{
    uint32_t u;
    memcpy(&u, &f, 4);
    vf3_aim_set_u32(a, addr, u);
}

 void vf3_native_node_rotate(vf3_native_aim *a)
{
    /* the seven records */
    R(6) = NODES;
    R(5) = R(4);
    for (;;) {
        R(7) = R(5);
        R(7) += 8u;
        F(8) = fload(a, R(7));            /* the record's second float */
        R(6) -= 1u;
        set_t(a, R(6) == 0);
        F(7) = F(4);                      /* the cosine */
        F(9) = fload(a, R(5));            /* the record's first float */
        F(7) = F(7) * F(8);               /* cos * second */
        F(2) = F(5);                      /* the sine */
        F(3) = F(8);
        F(2) = F(2) * F(9);               /* sin * first */
        F(8) = F(5);
        F(8) = F(8) * F(3);               /* sin * second */
        F(3) = F(7);
        F(0) = F(9);
        F(7) = F(2);
        F(7) = F(7) - F(3);               /* sin * first - cos * second */
        F(2) = F(8);
        F(2) = fmaf(F(0), F(4), F(2));    /* sin * second + first * cos, fused */
        F(8) = F(2);
        fstore(a, R(5), F(7));            /* first float of the record */
        fstore(a, R(7), F(8));            /* second float of the record */
        R(5) += NODE_STRIDE;
        if (R(6) == 0) break;
    }

    /* and the root's position moves by the caller's vector */
    R(0) = ROOT_X;
    F(7) = F(6);                          /* the move */
    F(4) = fload(a, R(4) + R(0));         /* the first coordinate */
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, G_Y);
    F(4) = F(4) + F(6);
    F(5) = fload(a, R(4) + R(0));         /* the second coordinate */
    R(0) += (uint32_t)(0u - ROOT_STEP);
    F(3) = fload(a, R(4) + R(0));         /* the third coordinate */
    R(0) = ROOT_X;
    F(5) = F(5) + F(6);
    fstore(a, R(4) + R(0), F(4));
    F(7) = F(7) + F(3);
    R(0) = (uint32_t)(int32_t)(int16_t)vf3_aim_h16(a, G_Y);
    fstore(a, R(4) + R(0), F(5));
    R(0) += (uint32_t)(0u - ROOT_STEP);
    fstore(a, R(4) + R(0), F(7));
}
