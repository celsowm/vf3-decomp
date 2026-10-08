/* Shared vertex weight response and the three packed vertex emitters.
 * Curve selection is an original RAM displacement into eleven entry slots.
 * Keep each float32 operation in its original order and rounding mode. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <string.h>
#define R(n) s->v[n]
#define F(n) s->v[21+(n)]
static float value(uint32_t bits)
{
    float result;
    memcpy(&result, &bits, 4);
    return result;
}
static void multiply(vf3_matrix_state *s, unsigned dst, unsigned src)
{
    F(dst) = vf3_fpu_binary(F(dst), F(src), R(18), '*');
}
int vf3_vertex_weight_curve(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    F(1) = 0;
    R(17) = (R(17) & ~1u) | (value(F(0)) > value(F(1)));
    multiply(s, 0, 0);
    F(1) = 0x3f800000;
    if (R(17) & 1u) {
        F(0) = vf3_fpu_binary(F(0), F(0), R(18), '+');
        R(17) = (R(17) & ~1u) | (value(F(0)) > value(F(1)));
        F(0) = vf3_fpu_binary(F(0), F(1), R(18), '-');
        if (R(17) & 1u) {
            multiply(s, 0, 0);
            R(0) = vf3_matrix_read(ram, 0x0c056cb8, 4);
            R(0) = vf3_matrix_read(ram, R(0), 4);
            vf3_matrix_move(s, 1, 0);
            switch (R(0)) {
            case 0: case 4: break;
            case 8: multiply(s, 0, 0); break;
            case 12: multiply(s, 1, 1); multiply(s, 0, 1); break;
            case 16: multiply(s, 0, 0); multiply(s, 0, 0); break;
            case 20:
                multiply(s, 1, 1); multiply(s, 1, 1); multiply(s, 0, 1); break;
            case 24:
                multiply(s, 1, 1); multiply(s, 0, 1); multiply(s, 0, 1); break;
            case 28:
                multiply(s, 1, 1); multiply(s, 0, 1);
                multiply(s, 1, 1); multiply(s, 0, 1); break;
            case 32: case 36: case 40:
                for (unsigned i = 0; i < (R(0) - 20) / 4; ++i) multiply(s, 0, 0);
                break;
            default: s->failed_pc = 0x0c056c82 + R(0); return 0;
            }
        }
    }
    s->pc = R(16);
    return ram->oob == 0;
}
static void store_float(vf3_matrix_state *s, const vf3_ram_map *ram, unsigned reg)
{
    R(12) -= (R(18) & 0x100000u) ? 8 : 4;
    vf3_matrix_store(s, ram, reg, R(12));
}
int vf3_weighted_vertex(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(15) -= 4;
    vf3_matrix_write(ram, R(15), R(16), 4);
    R(0) = vf3_matrix_read(ram, entry == 0x0c051b74 ? 0x0c051b98 :
                                  entry == 0x0c0521ac ? 0x0c0521d0 : 0x0c052854, 4);
    R(16) = entry + 8;
    vf3_matrix_move(s, 0, 12);
    if (!vf3_matrix_family(R(0), s, ram) || s->pc != R(16)) return 0;
    if (entry == 0x0c052824) {
        R(53) = F(8); R(0) = R(53);
        R(53) = F(9); R(1) = R(53);
        R(0) >>= 16;
        R(1) = (R(1) >> 16) | (R(0) << 16);
    }
    R(12) += 32;
    store_float(s, ram, 0);
    if (entry == 0x0c051b74) R(0) = 0;
    store_float(s, ram, 11);
    if (entry == 0x0c0521ac) {
        store_float(s, ram, 9);
        store_float(s, ram, 8);
    } else {
        R(12) -= 8;
        vf3_matrix_write(ram, R(12), entry == 0x0c051b74 ? R(0) : R(1), 4);
    }
    store_float(s, ram, 6); store_float(s, ram, 5); store_float(s, ram, 4);
    R(12) -= 4;
    vf3_matrix_write(ram, R(12), R(4), 4);
    R(16) = vf3_matrix_read(ram, R(15), 4);
    R(15) += 4;
    R(12) += 32;
    s->pc = R(16);
    return ram->oob == 0;
}
