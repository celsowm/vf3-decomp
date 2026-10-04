/* Shared resource lookup entered indirectly by the 0x8c05cc38 updater. */
#include "fight/matrix_family.h"

#define R(n) s->v[(n)]

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

static int call(vf3_matrix_state *s, const vf3_ram_map *ram,
                uint32_t target, uint32_t return_pc)
{
    R(16) = return_pc;
    return vf3_matrix_family(target, s, ram) && s->pc == return_pc;
}

int vf3_advance_dynamic_06129c(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    /* Preserve the SH-4 callee-saved registers and local search result. */
    push(s, ram, R(14));
    R(14) = R(4);
    R(1) = R(14);
    push(s, ram, R(13));
    R(13) = R(5);
    push(s, ram, R(12));
    push(s, ram, R(8));
    push(s, ram, R(16));
    R(15) -= 4;
    vf3_matrix_write(ram, R(15), R(6), 4);

    /* Normalize the cursor through the shared signed-zero helper. */
    R(0) = 32;
    if (!call(s, ram, 0x0c042d7c, 0x0c0612b6)) return 0;
    R(4) = R(0);
    R(17) = (R(17) & ~1u) | (R(4) == 0);
    if (!(R(17) & 1u)) {
        R(3) = 32;
        R(3) -= R(4);
        R(14) += R(3);
    }

    /* Search the resource descriptor table for the requested word pair. */
    R(6) = R(13);
    R(7) = 0x2000;
    R(5) = R(14) << 1;
    R(4) = 0;
    if (!call(s, ram, 0x0c061e70, 0x0c0612ce)) return 0;
    R(14) = R(0);
    R(17) = (R(17) & ~1u) | (R(14) == 0);

    if (R(17) & 1u) {
        /* A miss writes back both adjacent words for the caller to retry. */
        R(12) = vf3_matrix_read(ram, R(13), 4);
        R(4) = R(12);
        if (!call(s, ram, 0x0c062dd2, 0x0c0612dc)) return 0;
        vf3_matrix_write(ram, R(13), R(0), 4);

        R(4) = R(12) + 4;
        R(8) = vf3_matrix_read(ram, R(15), 4);
        if (!call(s, ram, 0x0c062dd2, 0x0c0612e8)) return 0;
        vf3_matrix_write(ram, R(8), R(0), 4);
    }

    R(0) = R(14);

    /* RTS delay slot restores R14 after the ordinary epilogue. */
    R(15) += 4;
    R(16) = pop(s, ram);
    R(8) = pop(s, ram);
    R(12) = pop(s, ram);
    R(13) = pop(s, ram);
    R(14) = pop(s, ram);
    s->pc = R(16);
    return ram->oob == 0;
}
