/* color_unpack.c - 0x8C0562E0  unpack three halfword-packed byte triples into scaled floats.
 *
 *   r4 -> the record (4 bytes skipped, then three halfwords). The 3-float vector at [0x0C19D5C8] is
 *   multiplied by the factor at 0x8C056508; the first two halfwords are packed (halfword 2 over halfword 1)
 *   into GBR+0x60, and each halfword's two bytes are converted to float and scaled by the vector. Six floats
 *   are stored at 0x0C16B82C and downwards (three, then 28 bytes back up for the last three).
 *
 *   Out: r4 advanced by 10, r1 = the last store address, the results in FR0..FR2, the scale in FR4..FR7.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

enum { SCALE_PTR = 0x0C19D5C8u, FACTOR = 0x0C056508u, OUT = 0x0C16B82Cu, PACK_GBR = 96u, PR_SZ = 0x00180000u };

#define FPUL        (s->v[VF3_REG_FPUL])
#define FLOAT(n)    (F(n) = vf3_fpu_float(FPUL, R(VF3_REG_FPSCR)))

static uint32_t sext16(const vf3_ram_map *ram, uint32_t addr)
{
    return (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, addr);
}

static void store_pre(vf3_matrix_state *s, const vf3_ram_map *ram, int n)
{
    R(1) -= 4;
    w32(ram, R(1), F(n));
}

int vf3_color_unpack_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!s->gbr_known || !vf3_fpu_supported(R(VF3_REG_FPSCR)) || (R(VF3_REG_FPSCR) & PR_SZ)) return 0;

    R(2) = SCALE_PTR;
    R(0) = 0x8C056508u;
    R(4) += 4;
    F(7) = m32(ram, FACTOR);
    R(5) = sext16(ram, R(4)); R(4) += 2;
    R(6) = sext16(ram, R(4)); R(4) += 2;
    F(4) = m32(ram, R(2)); R(2) += 4;
    F(5) = m32(ram, R(2)); R(2) += 4;
    F(6) = m32(ram, R(2));
    R(0) = (R(6) << 16) | (R(5) & 0xFFFFu);
    FMUL(4, 7);
    FMUL(5, 7);
    w32(ram, s->gbr + PACK_GBR, R(0));
    FMUL(6, 7);

    R(2) = R(5) & 0xFFu;
    FPUL = R(2);
    R(5) >>= 8;
    FLOAT(0);
    R(1) = OUT;
    R(5) &= 0xFFu;
    FPUL = R(5);
    FLOAT(1);
    FMUL(0, 6);
    R(5) = sext16(ram, R(4)); R(4) += 2;
    R(2) = R(6) & 0xFFu;
    FPUL = R(2);
    FLOAT(2);
    R(6) >>= 8;
    FMUL(1, 5);
    w32(ram, R(1), F(0));
    R(6) &= 0xFFu;
    FPUL = R(6);
    FLOAT(0);
    R(6) = sext16(ram, R(4)); R(4) += 2;
    R(2) = R(5) & 0xFFu;
    FMUL(2, 4);
    R(5) >>= 8;
    FPUL = R(2);
    R(5) &= 0xFFu;
    store_pre(s, ram, 1);
    FLOAT(1);
    FPUL = R(5);
    FMUL(0, 7);
    store_pre(s, ram, 2);
    R(6) &= 0xFFu;
    FLOAT(2);
    FPUL = R(6);
    store_pre(s, ram, 0);
    FLOAT(0);
    R(1) += 28;
    FMUL(1, 6);
    FMUL(2, 5);
    FMUL(0, 4);
    w32(ram, R(1), F(1));
    store_pre(s, ram, 2);
    store_pre(s, ram, 0);                               /* rts delay slot */
    s->pc = R(VF3_REG_PR);
    return 1;
}
