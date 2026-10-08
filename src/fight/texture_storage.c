/* Texture storage in words, including optional mip levels and format overhead.
 * Descriptor dimensions are at +12/+16; bit zero at +24 enables mipmaps.
 * Guest registers and stack writes preserve the original callable ABI. */
#include "fight/matrix_family.h"
#define R(n) s->v[n]
static void flag(vf3_matrix_state *s, int value)
{
    R(17) = (R(17) & ~1u) | (value != 0);
}
static void push(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t value)
{
    R(15) -= 4;
    vf3_matrix_write(ram, R(15), value, 4);
}
static uint32_t pop(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t value = vf3_matrix_read(ram, R(15), 4);
    R(15) += 4;
    return value;
}
int vf3_texture_size_class(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if ((int32_t)R(4) >= (int32_t)R(5)) R(4) = R(5);
    R(0) = R(4);
    /* Preserve the original comparison order, including literal-register
     * side effects used by callers. Unrecognized dimensions use class 3. */
    static const uint32_t dimensions[] = {1,2,4,8,16,32,64,128,256,512,1024};
    unsigned index;
    for (index = 0; index < 11; ++index) {
        if (index >= 7) R(1) = dimensions[index];
        flag(s, R(0) == dimensions[index]);
        if (R(17) & 1u) break;
    }
    R(0) = index < 11 ? index : 3;
    s->pc = R(16);
    return ram->oob == 0;
}
int vf3_texture_storage(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (entry == 0x0c05f28au) {
        for (unsigned reg = 14; reg >= 11; --reg) push(s, ram, R(reg));
        R(11) = R(4);
    }
    push(s, ram, R(16));
    R(15) -= 8;
    R(13) = vf3_matrix_read(ram, R(11) + 12, 4);
    vf3_matrix_write(ram, R(15) + 4, R(13), 4);
    R(14) = vf3_matrix_read(ram, R(11) + 16, 4);
    R(13) >>= 1;
    vf3_matrix_write(ram, R(15), R(14), 4);
    flag(s, R(14) & 1u);
    R(14) >>= 1;
    R(5) = vf3_matrix_read(ram, R(15), 4);
    R(19) = R(13) * R(14);
    R(12) = R(19);
    R(4) = vf3_matrix_read(ram, R(15) + 4, 4);
    R(16) = 0x0c05f2ae;
    if (!vf3_matrix_family(0x0c05f0b8, s, ram) || s->pc != R(16)) return 0;
    R(5) = R(0);
    R(2) = vf3_matrix_read(ram, R(11) + 24, 4);
    R(4) = 1;
    R(6) = R(0) * 4;
    flag(s, !(R(2) & 1u));
    if (R(2) & 1u) {
        /* Each successive mip level halves both dimensions. The original
         * includes a final rectangular tail or two words for a square. */
        R(13) >>= 1;
        R(14) >>= 1;
        R(5) = R(13) < R(14) ? R(13) : R(14);
        flag(s, R(5) > 1);
        while (R(5) > 1) {
            if (!s->budget--) { s->failed_pc = 0x0c05f2ce; return 0; }
            R(19) = R(13) * R(14);
            R(3) = R(19);
            R(13) >>= 1;
            R(14) >>= 1;
            R(5) >>= 1;
            flag(s, R(5) > 1);
            R(12) += R(3);
        }
        flag(s, R(13) == R(14));
        if (R(13) == R(14)) R(12) += 2;
        else {
            R(19) = R(13) * R(14);
            R(13) = R(19);
            R(12) += R(13);
        }
        R(0) = 0x0c0d2ccc;
        R(12) += 10;
    } else R(0) = 0x0c0d2cb0;
    R(3) = vf3_matrix_read(ram, R(0) + R(6), 4);
    R(12) += R(3);
    R(0) = R(12);
    R(15) += 8;
    R(16) = pop(s, ram);
    for (unsigned reg = 11; reg <= 14; ++reg) R(reg) = pop(s, ram);
    s->pc = R(16);
    return ram->oob == 0;
}
