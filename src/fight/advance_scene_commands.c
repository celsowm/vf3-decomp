/* Small original scene commands; retain ABI-visible register and stack effects. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"

#define R(n) s->v[(n)]

static void save_return(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(15) -= 4;
    vf3_matrix_write(ram, R(15), R(16), 4);
}

static void restore_return(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(16) = vf3_matrix_read(ram, R(15), 4);
    R(15) += 4;
}

int vf3_advance_descriptor_flags(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* Four original selector words copied into a local stack table. */
    save_return(s, ram);
    R(15) -= 16;
    R(2) = 0x0c0d2be4;
    R(5) = R(15);
    R(3) = 0x0c042efc;
    R(1) = R(15);
    R(0) = 16;
    R(16) = 0x0c05c138;
    if (!vf3_matrix_family(R(3), s, ram)) return 0;
    if (s->pc != R(16)) return 0;

    R(0) = R(4);
    R(3) = 0xffff9fff;
    R(0) <<= 2;
    R(2) = 0x0c0ea9d4;
    R(4) = vf3_matrix_read(ram, R(5) + R(0), 4);
    R(5) = 0x0c16c918;
    R(0) = 13;
    R(6) = R(5) + 16;
    R(1) = vf3_matrix_read(ram, R(6) + 4, 4);
    R(4) <<= 13;
    R(1) = (R(1) & R(3)) | R(4);
    vf3_matrix_write(ram, R(6) + 4, R(1), 4);
    R(3) = vf3_matrix_read(ram, R(5) + 20, 4);
    vf3_matrix_write(ram, R(2) + 8, R(3), 4);
    R(15) += 16;
    restore_return(s, ram);
    R(0) = 0;
    s->pc = R(16);
    return ram->oob == 0;
}

int vf3_advance_scene_entry_reset(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* Reset entries 69 through 81 using the original shared entry helper. */
    save_return(s, ram);
    for (unsigned entry = 69; entry < 81; ++entry) {
        R(4) = entry;
        R(16) = 0x0c07ad9c + (entry - 69) * 4;
        if (!vf3_matrix_family(0x0c07b5f0, s, ram)) return 0;
        if (s->pc != R(16)) return 0;
    }
    R(4) = 81;
    restore_return(s, ram);
    return vf3_matrix_family(0x0c07b5f0, s, ram);
}

static int call_helper(vf3_matrix_state *s, const vf3_ram_map *ram,
                       uint32_t target, uint32_t continuation)
{
    R(16) = continuation;
    return vf3_matrix_family(target, s, ram) && s->pc == continuation;
}

static void push_float(vf3_matrix_state *s, const vf3_ram_map *ram,
                       unsigned pointer, unsigned floating)
{
    R(pointer) -= (R(18) & 0x100000u) ? 8 : 4;
    vf3_matrix_store(s, ram, floating, R(pointer));
}

static void load_float_next(vf3_matrix_state *s, const vf3_ram_map *ram,
                            unsigned floating, unsigned pointer)
{
    vf3_matrix_load(s, ram, floating, R(pointer));
    R(pointer) += (R(18) & 0x100000u) ? 8 : 4;
}

int vf3_advance_scene_selector(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(5) = 0x0c29b864;
    R(6) = 32;
    R(0) = (uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram, R(5) + 11, 1);
    R(4) = R(0) & 255u;
    R(17) = (R(17) & ~1u) | ((int32_t)R(4) >= (int32_t)R(6));
    if (!(R(17) & 1u)) goto finished;
    R(0) = 0x138;
    R(3) = vf3_matrix_read(ram, R(5) + R(0), 4);
    R(17) = (R(17) & ~1u) | ((R(3) & R(6)) == 0);
    if (R(17) & 1u) goto finished;
    R(0) = 0x13c;
    R(3) = 0x1000;
    R(2) = vf3_matrix_read(ram, R(5) + R(0), 4);
    R(17) = (R(17) & ~1u) | ((R(2) & R(3)) == 0);
    R(7) = 50;
    if (R(17) & 1u) {
        ++R(4);
        R(17) = (R(17) & ~1u) | ((int32_t)R(4) > (int32_t)R(7));
        if (R(17) & 1u) R(4) = R(6);
    } else {
        R(2) = vf3_matrix_read(ram, R(5) + R(0), 4);
        R(3) = 0x2000;
        R(17) = (R(17) & ~1u) | ((R(2) & R(3)) == 0);
        if (R(17) & 1u) goto finished;
        R(4) -= 3;
        R(17) = (R(17) & ~1u) | ((int32_t)R(4) >= (int32_t)R(6));
        if (!(R(17) & 1u)) R(4) = R(7);
    }
    R(0) = R(4);
    vf3_matrix_write(ram, R(5) + 11, R(0), 1);
finished:
    s->pc = R(16);
    return ram->oob == 0;
}

int vf3_advance_scene_commands(uint32_t entry, vf3_matrix_state *s,
                              const vf3_ram_map *ram)
{
    switch (entry & 0x1fffffffu) {
    case 0x0c03c220: /* Reset the selected transform, then reload the base. */
        save_return(s, ram);
        R(3) = 0x0c03c4f0;
        R(4) = 0x0c19d2fc;
        R(4) = vf3_matrix_read(ram, R(4) + 8, 4);
        if (!call_helper(s, ram, R(3), 0x0c03c22a)) return 0;
        restore_return(s, ram);
        return vf3_matrix_family(0x0c03c200, s, ram);

    case 0x0c045ce6: /* Two-word packed device command descriptor. */
        save_return(s, ram);
        R(6) <<= 8;
        R(7) <<= 16;
        R(15) -= 8;
        R(6) |= R(7);
        R(14) = R(15);
        R(7) = 2;
        vf3_matrix_write(ram, R(14), R(5), 4);
        R(3) = vf3_matrix_read(ram, R(15) + 16, 4);
        R(6) |= R(3);
        R(3) = 0;
        vf3_matrix_write(ram, R(14) + 4, R(6), 4);
        R(15) -= 4;
        vf3_matrix_write(ram, R(15), R(3), 4);
        R(6) = R(14);
        R(15) -= 4;
        vf3_matrix_write(ram, R(15), R(3), 4);
        R(2) = 0x0c044cc0;
        R(5) = 13;
        if (!call_helper(s, ram, R(2), 0x0c045d0a)) return 0;
        R(15) += 16;
        restore_return(s, ram);
        R(14) = vf3_matrix_read(ram, R(15), 4);
        R(15) += 4;
        break;

    case 0x0c045d3e: /* Command 252 has no payload or optional arguments. */
        save_return(s, ram);
        R(3) = 0;
        R(7) = R(3);
        for (unsigned argument = 0; argument < 2; ++argument) {
            R(15) -= 4;
            vf3_matrix_write(ram, R(15), R(3), 4);
        }
        R(5) = 252;
        R(2) = 0x0c044cc0;
        R(6) = R(3);
        if (!call_helper(s, ram, R(2), 0x0c045d50)) return 0;
        R(15) += 8;
        restore_return(s, ram);
        break;

    case 0x0c074788: /* Add the object's scalar offset to its sample ring. */
        R(0) = 0x13ac;
        R(6) = 0x150;
        vf3_matrix_load(s, ram, 4, R(4) + R(0));
        R(0) -= 32;
        R(5) = vf3_matrix_read(ram, R(4) + R(0), 4);
        R(0) = 0x148c;
        R(6) += R(5);
        vf3_matrix_load(s, ram, 3, R(4) + R(0));
        R(17) = (R(17) & ~1u) | (R(5) == R(6));
        R(24) = vf3_fpu_binary(R(24), R(25), R(18), '+');
        vf3_matrix_store(s, ram, 3, R(4) + R(0));
        if (!(R(17) & 1u)) {
            do {
                if (!s->budget--) { s->failed_pc = 0x0c0747a0; return 0; }
                R(0) = 4;
                vf3_matrix_load(s, ram, 3, R(5) + R(0));
                R(24) = vf3_fpu_binary(R(24), R(25), R(18), '+');
                vf3_matrix_store(s, ram, 3, R(5) + R(0));
                R(5) += 12;
                R(17) = (R(17) & ~1u) | (R(5) == R(6));
            } while (!(R(17) & 1u));
        }
        break;

    case 0x0c0935ce: /* Subtract reference coordinates before the shared tail. */
        push_float(s, ram, 4, 0);
        R(5) = R(15);
        R(4) = R(14);
        R(6) = R(11);
        R(4) += 92;
        R(6) += 48;
        R(5) += 4;
        load_float_next(s, ram, 0, 5);
        load_float_next(s, ram, 3, 6);
        load_float_next(s, ram, 1, 5);
        load_float_next(s, ram, 4, 6);
        R(21) = vf3_fpu_binary(R(21), R(24), R(18), '-');
        vf3_matrix_load(s, ram, 2, R(5));
        vf3_matrix_load(s, ram, 5, R(6));
        R(22) = vf3_fpu_binary(R(22), R(25), R(18), '-');
        R(23) = vf3_fpu_binary(R(23), R(26), R(18), '-');
        R(4) += 8;
        vf3_matrix_store(s, ram, 2, R(4));
        push_float(s, ram, 4, 1);
        return vf3_matrix_family(0x0c0935f4, s, ram);

    case 0x0c0c91ae: /* Reset scene selection and advance its state byte. */
        save_return(s, ram);
        R(3) = 0x0c29bcc4;
        R(14) = 0x0c29b864;
        R(15) -= 4;
        vf3_matrix_write(ram, R(15), R(3), 4);
        R(3) = 0x0c0c5d86;
        R(4) = 0xffffffff;
        if (!call_helper(s, ram, R(3), 0x0c0c91be)) return 0;
        R(0) = 0xba;
        R(3) = 0;
        R(2) = vf3_matrix_read(ram, R(15), 4);
        R(15) += 4;
        restore_return(s, ram);
        vf3_matrix_write(ram, R(2) + R(0), R(3), 2);
        R(0) = 16;
        R(2) = 91;
        vf3_matrix_write(ram, R(14) + R(0), R(2), 1);
        R(0) = (uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram, R(14) + 11, 1);
        ++R(0);
        vf3_matrix_write(ram, R(14) + 11, R(0), 1);
        R(3) = 0x0c09abc4;
        R(14) = vf3_matrix_read(ram, R(15), 4);
        R(15) += 4;
        return vf3_matrix_family(R(3), s, ram);

    default:
        s->failed_pc = entry;
        return 0;
    }
    s->pc = R(16);
    return ram->oob == 0;
}
