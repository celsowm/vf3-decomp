/* matrix_extra.c - more XMTRX routines of the matrix layer, and two routines built on them.
 *
 *   0x8C03B4B0  xform_vector     (x, y, z, 0) at r4 through XMTRX -> three floats at r5 (rotation only)
 *   0x8C03B5C0  invert_scaled    in-place inverse of a rotation+scale+translation XMTRX: axis
 *                                columns normalised by 1/|column|, transposed, translation = -(t . c_i)/|c_i|
 *   0x8C03CC30  transpose        full transpose of XMTRX
 *   0x8C03E980  world_reset      transpose XMTRX, transform the 0x0C19D5B0 + 0x68 vector into +0x80,
 *                                the 0x0C058FE0 vector into 0x0C0EA600, transpose back (tail call)
 *   0x8C03E8C0  bone_transforms  push a matrix, invert the current one, then for each of the 16
 *                                176-byte entries at 0x0C19D5B0 that is in use transform its +0x68
 *                                vector (rotation only) into +0x80 and its +0x5C point into +0x74
 *
 * The original reaches XMTRX with FRCHG and swaps off-diagonal pairs through FPUL; FPUL ends up
 * holding the last pair's first element, which the ports reproduce. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

static uint32_t *fr_bank(vf3_matrix_state *s) { return &VF3_FR(s, 0); }
static uint32_t *xf_bank(vf3_matrix_state *s) { return &s->v[VF3_REG_XF0]; }

static void swap_xf(vf3_matrix_state *s, int a, int b)
{
    uint32_t *xf = xf_bank(s);
    s->v[VF3_REG_FPUL] = xf[a];
    xf[a] = xf[b];
    xf[b] = s->v[VF3_REG_FPUL];
}

static float xf_f(vf3_matrix_state *s, int i) { return vf3_bits_f32(xf_bank(s)[i]); }

int vf3_xform_vector_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t *fr = fr_bank(s);
    for (int i = 0; i < 3; ++i) fr[4 + i] = vf3_mem_u32(ram, s->v[4] + 4u * (uint32_t)i);
    s->v[4] += 12;
    fr[7] = 0;
    if (!vf3_fpu_ftrv(xf_bank(s), fr + 4, s->v[VF3_REG_FPSCR], fr + 4)) return 0;
    for (int i = 0; i < 3; ++i) vf3_mem_set_u32(ram, s->v[5] + 4u * (uint32_t)i, fr[4 + i]);
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

int vf3_matrix_transpose_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    static const int pairs[6][2] = { { 1, 4 }, { 2, 8 }, { 3, 12 }, { 6, 9 }, { 7, 13 }, { 11, 14 } };
    for (int i = 0; i < 6; ++i) swap_xf(s, pairs[i][0], pairs[i][1]);
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

int vf3_matrix_invert_scaled_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    uint32_t *xf = xf_bank(s);
    const uint32_t fpscr = s->v[VF3_REG_FPSCR];

    /* t . column(i) for each axis column (the FIPR also adds FR15 * the column's w) */
    if (!vf3_fpu_fipr(xf + 12, xf + 0, fpscr, xf + 3)) return 0;
    if (!vf3_fpu_fipr(xf + 12, xf + 4, fpscr, xf + 7)) return 0;
    if (!vf3_fpu_fipr(xf + 12, xf + 8, fpscr, xf + 11)) return 0;
    xf[12] = xf[3]; xf[3] = vf3_f32_bits(vf3_f_sub(s, xf_f(s, 3), xf_f(s, 3)));
    xf[13] = xf[7]; xf[7] = vf3_f32_bits(vf3_f_sub(s, xf_f(s, 7), xf_f(s, 7)));
    xf[14] = xf[11]; xf[11] = vf3_f32_bits(vf3_f_sub(s, xf_f(s, 11), xf_f(s, 11)));

    /* |column|^2, translation sign flipped, then 1/|column| */
    if (!vf3_fpu_fipr(xf + 0, xf + 0, fpscr, xf + 3)) return 0;
    xf[12] ^= 0x80000000u;
    if (!vf3_fpu_fipr(xf + 4, xf + 4, fpscr, xf + 7)) return 0;
    xf[13] ^= 0x80000000u;
    if (!vf3_fpu_fipr(xf + 8, xf + 8, fpscr, xf + 11)) return 0;
    xf[14] ^= 0x80000000u;
    if (!vf3_fpu_fsrra(xf[3], fpscr, xf + 3)) return 0;
    if (!vf3_fpu_fsrra(xf[7], fpscr, xf + 7)) return 0;
    if (!vf3_fpu_fsrra(xf[11], fpscr, xf + 11)) return 0;

    const float inv[3] = { xf_f(s, 3), xf_f(s, 7), xf_f(s, 11) };
    static const int groups[3][4] = { { 0, 1, 2, 12 }, { 4, 5, 6, 13 }, { 8, 9, 10, 14 } };
    for (int g = 0; g < 3; ++g)
        for (int k = 0; k < 4; ++k)
            xf[groups[g][k]] = vf3_f32_bits(vf3_f_mul(s, xf_f(s, groups[g][k]), inv[g]));
    swap_xf(s, 1, 4);
    swap_xf(s, 2, 8);
    swap_xf(s, 6, 9);
    xf[3] = 0;
    xf[7] = vf3_f32_bits(vf3_f_sub(s, xf_f(s, 7), xf_f(s, 7)));
    xf[11] = 0;
    s->pc = s->v[VF3_REG_PR];
    return 1;
}

enum {
    TABLE = 0x0C19D5B0u, ENTRY_BYTES = 0xB0, ENTRIES = 16, VEC_IN = 104, VEC_OUT = 128,
    POINT_IN = 92, POINT_OUT = 116,
    XFORM_VECTOR = 0x8C03B4B0, XFORM_POINT = 0x8C03B450, TRANSPOSE = 0x8C03CC30,
    MATRIX_PUSH = 0x8C03C4F0, INVERT_SCALED = 0x8C03B5C0, MATRIX_POP = 0x8C03C4A0
};

int vf3_world_reset_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = s->v[15], pr0 = s->v[VF3_REG_PR], frame = sp0 - 8u;
    vf3_mem_set_u32(ram, sp0 - 4u, pr0);
    s->v[15] = frame;
    s->v[3] = 0x0C03CC30u;
    if (!vf3_guest_call(s, ram, TRANSPOSE, 0x8C03E98A)) return 0;
    s->v[15] = frame;
    s->v[5] = TABLE;
    vf3_mem_set_u32(ram, frame, TABLE);
    s->v[3] = 0x80;
    s->v[4] = vf3_mem_u32(ram, frame) + VEC_IN;
    s->v[2] = 0x0C03B4B0u;
    s->v[5] = TABLE + 0x80u;
    if (!vf3_guest_call(s, ram, XFORM_VECTOR, 0x8C03E99A)) return 0;
    s->v[15] = frame;
    s->v[3] = 0x0C03B4B0u;
    s->v[4] = 0x0C0EA600u;
    s->v[5] = 0x0C058FE0u;
    if (!vf3_guest_call(s, ram, XFORM_VECTOR, 0x8C03E9A4)) return 0;
    s->v[2] = 0x0C03CC30u;
    s->v[15] = sp0;
    s->v[VF3_REG_PR] = pr0;                               /* tail call with PR restored */
    return vf3_guest_call(s, ram, TRANSPOSE, pr0);
}

int vf3_bone_transforms_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* return addresses of the two calls in each of the four unrolled copies of the loop body */
    static const uint32_t ret_vector[4] = { 0x8C03E8F2, 0x8C03E912, 0x8C03E932, 0x8C03E952 };
    static const uint32_t ret_point[4] = { 0x8C03E8FC, 0x8C03E91C, 0x8C03E93C, 0x8C03E95C };
    const uint32_t sp0 = s->v[15], pr0 = s->v[VF3_REG_PR], frame = sp0 - 24u;
    const uint32_t saved[5] = { s->v[14], s->v[13], s->v[12], s->v[11], s->v[10] };

    for (int i = 0; i < 5; ++i) vf3_mem_set_u32(ram, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    vf3_mem_set_u32(ram, sp0 - 24u, pr0);
    s->v[15] = frame;

    s->v[3] = 0x0C03C4F0u; s->v[4] = 0;
    if (!vf3_guest_call(s, ram, MATRIX_PUSH, 0x8C03E8D2)) return 0;
    s->v[15] = frame;
    s->v[2] = 0x0C03B5C0u;
    if (!vf3_guest_call(s, ram, INVERT_SCALED, 0x8C03E8D8)) return 0;
    s->v[15] = frame;
    s->v[12] = 0x0C03B4B0u; s->v[11] = 0; s->v[14] = TABLE; s->v[10] = ENTRIES; s->v[13] = 0x0C03B450u;

    for (uint32_t i = 0; i < ENTRIES; ++i) {
        const uint32_t entry = TABLE + i * ENTRY_BYTES, k = i & 3u;
        const uint32_t used = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, entry);
        s->v[14] = entry;
        s->v[11] = i;
        if (k == 0) {
            s->v[3] = used;
        } else {
            s->v[2] = used;
            s->v[3] = ENTRY_BYTES;
        }
        if (used == 0) continue;
        s->v[5] = 0x80u + entry;
        s->v[4] = entry + VEC_IN;
        if (!vf3_guest_call(s, ram, XFORM_VECTOR, ret_vector[k])) return 0;
        s->v[15] = frame;
        s->v[5] = entry + POINT_OUT;
        s->v[4] = entry + POINT_IN;
        if (!vf3_guest_call(s, ram, XFORM_POINT, ret_point[k])) return 0;
        s->v[15] = frame;
    }
    s->v[14] = TABLE + ENTRIES * ENTRY_BYTES;
    s->v[11] = ENTRIES;
    s->v[3] = 0x0C03C4A0u;
    s->v[4] = 1;
    s->v[15] = sp0;
    for (int i = 0; i < 5; ++i) s->v[14 - i] = saved[i];
    s->v[VF3_REG_PR] = pr0;                               /* tail call to matrix_pop */
    return vf3_guest_call(s, ram, MATRIX_POP, pr0);
}
