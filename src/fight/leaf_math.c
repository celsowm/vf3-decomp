/* leaf_math.c - small leaf routines of the matrix / memory layer.
 *
 *   0x8C03C880  rotation about Y: XMTRX = XMTRX-composed rotation by the angle in r4 (65536 = turn)
 *   0x8C03C940  rotation about Z, same convention
 *   0x8C03B450  transform a point: (r4 -> x, y, z) * XMTRX -> r5 (three floats, w taken as 1)
 *   0x8C043018  memmove(dst = r4, src = r5, count = r6) -> r0 = dst, overlap safe
 *
 * The rotations build the two basis rows of the rotation from sin/cos (fsca), push each row
 * through the current XMTRX and write the four results straight back over the matching XMTRX
 * columns (the double moves with an odd register number target the extended bank). */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

enum { NEGATE = 0x80000000u, SR_T = 1u };

static uint32_t *fr_bank(vf3_matrix_state *s) { return &VF3_FR(s, 0); }
static uint32_t *xf_bank(vf3_matrix_state *s) { return &s->v[VF3_REG_XF0]; }

int vf3_rotate_y_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    uint32_t *fr = fr_bank(s), *xf = xf_bank(s);
    s->v[VF3_REG_FPUL] = s->v[4];
    vf3_fpu_fsca(s->v[VF3_REG_FPUL], fr + 4);          /* fr4 = sin, fr5 = cos */
    const uint32_t sin_a = fr[4], cos_a = fr[5];
    fr[0] = cos_a; fr[1] = 0; fr[2] = sin_a ^ NEGATE; fr[3] = 0;
    fr[6] = cos_a; fr[7] = 0;
    if (!vf3_fpu_ftrv(xf, fr + 0, s->v[VF3_REG_FPSCR], fr + 0)) return 0;
    fr[5] = 0;                                         /* second row (sin, 0, cos, 0) */
    if (!vf3_fpu_ftrv(xf, fr + 4, s->v[VF3_REG_FPSCR], fr + 4)) return 0;
    xf[0] = fr[0]; xf[1] = fr[1]; xf[2] = fr[2]; xf[3] = fr[3];
    xf[8] = fr[4]; xf[9] = fr[5]; xf[10] = fr[6]; xf[11] = fr[7];
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

int vf3_rotate_z_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    uint32_t *fr = fr_bank(s), *xf = xf_bank(s);
    s->v[VF3_REG_FPUL] = s->v[4];
    vf3_fpu_fsca(s->v[VF3_REG_FPUL], fr + 4);
    const uint32_t sin_a = fr[4], cos_a = fr[5];
    fr[2] = 0; fr[3] = 0; fr[6] = 0;
    fr[0] = cos_a; fr[1] = sin_a;
    fr[4] = sin_a ^ NEGATE;                            /* second row (-sin, cos, 0, 0) */
    if (!vf3_fpu_ftrv(xf, fr + 0, s->v[VF3_REG_FPSCR], fr + 0)) return 0;
    fr[7] = 0;
    if (!vf3_fpu_ftrv(xf, fr + 4, s->v[VF3_REG_FPSCR], fr + 4)) return 0;
    xf[0] = fr[0]; xf[1] = fr[1]; xf[2] = fr[2]; xf[3] = fr[3];
    xf[4] = fr[4]; xf[5] = fr[5]; xf[6] = fr[6]; xf[7] = fr[7];
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

int vf3_xform_point_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t *fr = fr_bank(s);
    for (int i = 0; i < 3; ++i) fr[4 + i] = vf3_mem_u32(ram, s->v[4] + 4u * (uint32_t)i);
    s->v[4] += 12;
    vf3_fr_set(s, 7, 1.0f);
    if (!vf3_fpu_ftrv(xf_bank(s), fr + 4, s->v[VF3_REG_FPSCR], fr + 4)) return 0;
    for (int i = 0; i < 3; ++i) vf3_mem_set_u32(ram, s->v[5] + 4u * (uint32_t)i, fr[4 + i]);
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

int vf3_mem_move_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t dst = s->v[4], src = s->v[5], count = s->v[6];
    if (dst != src) {
        if (dst < src) {
            for (uint32_t i = 0; i < count; ++i) vf3_mem_set_u8(ram, dst + i, vf3_mem_u8(ram, src + i));
        } else {
            for (uint32_t i = count; i-- > 0;) vf3_mem_set_u8(ram, dst + i, vf3_mem_u8(ram, src + i));
        }
    }
    s->v[0] = dst;
    s->v[VF3_REG_SR] |= SR_T;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}
