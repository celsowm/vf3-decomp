/* vertex_lit.c - 0x8C047EA0  transform one strip vertex and fold its lighting terms.
 *
 *   r4 -> a vertex record: position x, y, z at +0 (transformed by XMTRX as (x, y, z, 1)), a vector at +12
 *   (stored in FR2, FR0, FR1 order; used raw), then two words at +24 / +28 that go to r1 / r2. r8 selects how
 *   many squarings the specular term gets, r12 is the clip value, FV12 and FV8 are two vectors the caller left
 *   in the FP registers.
 *
 *   FR3 = FV0 . FV12 (diffuse), FR2 = FR15 + max(FR3, 0).
 *   r8 > 0: FR11 = FV0 . FV8 (a cosine). FR11 is squared; if it is positive, doubled (2c^2) and, when above 1,
 *           reduced by 1 and squared again; FR3 then collects that term and the power ladder below runs
 *           from the slot chosen by r8 (braf r8: 4 bytes per slot, entering a chain of squarings of FR3 /
 *           FR11 that ends in a multiply into FR3).
 *   r8 < 0: FR2 = 1.0;  r8 == 0: nothing more.
 *   The routine ends with T = (r12 > the transformed w, as unsigned bits) and r4 = record + 32. r0 holds w. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"
#include <string.h>

enum { SR_T = 1u, ONE = 0x3F800000u, LADDER = 0x8C047EF2u };

int vf3_vertex_lit_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t saved[sizeof s->v / sizeof s->v[0]];
    memcpy(saved, s->v, sizeof saved);
    const uint32_t fpscr = s->v[VF3_REG_FPSCR];
    const uint32_t p = R(4);
    const int32_t sel = (int32_t)R(8);

    F(4) = vf3_mem_u32(ram, p);
    F(5) = vf3_mem_u32(ram, p + 4);
    F(6) = vf3_mem_u32(ram, p + 8);
    F(7) = ONE;
    F(2) = vf3_mem_u32(ram, p + 12);
    F(0) = vf3_mem_u32(ram, p + 16);
    F(1) = vf3_mem_u32(ram, p + 20);
    if (!vf3_fpu_ftrv(&s->v[VF3_REG_XF0], &F(4), fpscr, &F(4))) goto unsupported;
    F(3) = 0;
    R(1) = vf3_mem_u32(ram, p + 24);
    R(2) = vf3_mem_u32(ram, p + 28);
    R(4) = p + 32;
    if (!vf3_fpu_fipr(&F(12), &F(0), fpscr, &F(3))) goto unsupported;

    s->v[VF3_REG_FPUL] = F(7);
    F(7) = ONE;
    FDIV(7, 4);
    F(11) = 0;
    const int lit = GT(11, 3);
    R(0) = s->v[VF3_REG_FPUL];
    F(4) = s->v[VF3_REG_FPUL];
    if (!vf3_fpu_fipr(&F(0), &F(8), fpscr, &F(11))) goto unsupported;
    FMOV(2, 15);
    if (lit) FADD(2, 3);
    F(3) = 0;

    if (sel <= 0) {
        if (sel < 0) F(2) = ONE;
        goto done;
    }
    F(0) = ONE;
    {
        const int positive = GT(3, 11);
        FMUL(11, 11);
        if (!positive) goto done;
    }
    FADD(11, 11);
    {
        const int above_one = GT(0, 11);
        FSUB(11, 0);
        if (!above_one) goto done;
    }
    FMUL(11, 11);
    FADD(3, 11);

    switch (LADDER + (uint32_t)sel) {
    case 0x8C047EF2u: case 0x8C047EF6u: goto done;
    case 0x8C047EFAu: FMUL(3, 3); goto done;
    case 0x8C047EFEu: FMUL(11, 11); goto l2a;
    case 0x8C047F02u: FMUL(3, 3); goto l40;
    case 0x8C047F06u: FMUL(11, 11); goto l20;
    case 0x8C047F0Au: FMUL(11, 11); goto l28;
    case 0x8C047F0Eu: FMUL(11, 11); goto l1e;
    case 0x8C047F12u: FMUL(3, 3); goto l3e;
    case 0x8C047F16u: FMUL(3, 3); goto l3c;
    case 0x8C047F1Au: FMUL(3, 3); goto l3a;
    case 0x8C047F1Eu: goto l1e;
    case 0x8C047F20u: goto l20;
    case 0x8C047F22u: goto l22;
    case 0x8C047F28u: goto l28;
    case 0x8C047F2Au: goto l2a;
    case 0x8C047F3Au: goto l3a;
    case 0x8C047F3Cu: goto l3c;
    case 0x8C047F3Eu: goto l3e;
    case 0x8C047F40u: goto l40;
    case 0x8C047F24u: case 0x8C047F2Cu: case 0x8C047F42u: goto done;
    default: goto unsupported;      /* a braf target the table does not cover */
    }
l1e: FMUL(3, 11);
l20: FMUL(11, 11);
l22: FMUL(3, 11);
    goto done;
l28: FMUL(3, 11);
l2a: FMUL(3, 11);
    goto done;
l3a: FMUL(3, 3);
l3c: FMUL(3, 3);
l3e: FMUL(3, 3);
l40: FMUL(3, 3);

done:
    s->v[VF3_REG_SR] = (s->v[VF3_REG_SR] & ~SR_T) | (R(12) > R(0) ? SR_T : 0u);
    s->pc = s->v[VF3_REG_PR];
    return 1;

unsupported:
    memcpy(s->v, saved, sizeof saved);
    return 0;
}
