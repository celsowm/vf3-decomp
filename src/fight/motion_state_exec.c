/* Readable port of the SH-4 motion state executor at 0x8c0357bc.
 *
 * The guest owns a state record at r4. It validates the record, derives a
 * bounded motion interval, calls the record's selected handler, then commits
 * the handler result back to the record and its pointed-to object.
 */
#include "fight/readable.h"

#define R(n) s->v[(n)]

static void set_t(vf3_matrix_state *s, int value)
{
    s->v[17] = (s->v[17] & ~1u) | (value != 0);
}

static void push(vf3_matrix_state *s, const vf3_ram_map *ram, unsigned reg)
{
    s->v[15] -= 4u;
    vf3_mem_set_u32(ram, s->v[15], s->v[reg]);
}

static uint32_t pop(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t value = vf3_mem_u32(ram, s->v[15]);
    s->v[15] += 4u;
    return value;
}

/* Follow a tail transfer from the indirect handler until it returns to the
 * guest continuation at 0x0c035834. */
static int call_handler(vf3_matrix_state *s, const vf3_ram_map *ram,
                        uint32_t target, uint32_t return_pc)
{
    unsigned hops;

    s->v[16] = return_pc;
    for (hops = 0; hops < 128u; ++hops) {
        uint32_t next;
        vf3_matrix_call_alias_pc = target & 0x1fffffffu;
        vf3_matrix_call_alias = target & 0xff000000u;
        if (!vf3_matrix_family(target, s, ram)) return 0;
        if ((s->pc & 0x1fffffffu) == (return_pc & 0x1fffffffu)) return 1;
        next = s->pc;
        if ((next & 0x1fffffffu) == (target & 0x1fffffffu)) return 0;
        target = next;
    }
    return 0;
}

int vf3_motion_state_exec_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t pointed_object;

    /* Preserve the guest's callee-saved registers and return address. */
    push(s, ram, 14);
    R(14) = R(4);
    push(s, ram, 13);
    push(s, ram, 12);
    push(s, ram, 11);
    push(s, ram, 10);
    push(s, ram, 16);
    R(13) = R(5);

    /* A missing state record or an already-active record is rejected. */
    set_t(s, R(14) == 0);
    if (R(17) & 1u) {
        R(0) = 0xfffffff6u;
        goto done;
    }
    R(0) = 0x48u;
    R(2) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(14) + R(0));
    set_t(s, R(2) == 0);
    if ((R(17) & 1u) == 0) {
        R(0) = 0xfffffff6u;
        goto done;
    }

    pointed_object = vf3_mem_u32(ram, R(14));
    R(2) = pointed_object;
    R(3) = vf3_mem_u32(ram, R(2) + 40u);
    set_t(s, R(3) == 0);
    if ((R(17) & 1u) == 0) {
        R(0) = 0;
        goto done;
    }

    R(3) = 0x1fu;
    set_t(s, (R(3) & R(6)) == 0);
    if ((R(17) & 1u) == 0) {
        R(0) = 0xfffffff2u;
        goto done;
    }

    R(10) = vf3_mem_u32(ram, R(14) + 20u);
    R(11) = 1u;
    R(4) = vf3_mem_u32(ram, R(14) + 8u);
    R(3) = vf3_mem_u32(ram, R(14) + 16u);
    R(10) += R(4);
    R(4) += R(3);
    set_t(s, (int32_t)R(10) >= (int32_t)R(4));
    R(12) = 0;
    if (R(17) & 1u) {
        vf3_mem_set_u32(ram, R(14) + 24u, R(12));
        goto status_one;
    }

    R(3) = R(13) + R(10);
    set_t(s, (int32_t)R(3) > (int32_t)R(4));
    if (R(17) & 1u) R(13) = R(4) - R(10);
    set_t(s, R(13) == 0);
    if (R(17) & 1u) {
        vf3_mem_set_u32(ram, R(14) + 24u, R(12));
        vf3_mem_set_u16(ram, R(14) + 0x4cu, (uint16_t)R(11));
        R(0) = R(13);
        goto done;
    }

    /* Mark the pointed-to object as in use, then call its selected handler. */
    vf3_mem_set_u32(ram, pointed_object + 36u, R(11));
    R(0) = 0x4au;
    R(7) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, R(14) + R(0));
    R(5) = R(13);
    R(3) = vf3_mem_u32(ram, pointed_object + 20u);
    R(1) = vf3_mem_u32(ram, R(3) + 4u);
    R(4) = R(10);
    /* The translated call returns immediately if the router cannot resolve
     * the handler. Preserve that partially executed guest state for the
     * caller's failure handling. */
    if (!call_handler(s, ram, R(1), 0x0c035834u)) return 0;
    R(4) = R(0);
    set_t(s, R(4) == 0);

    if (R(4) == 0) {
        pointed_object = vf3_mem_u32(ram, R(14));
        R(2) = pointed_object;
        vf3_mem_set_u32(ram, pointed_object + 36u, R(12));
        goto status_one;
    }

    pointed_object = vf3_mem_u32(ram, R(14));
    R(2) = pointed_object;
    vf3_mem_set_u32(ram, pointed_object + 40u, R(14));
    R(3) = 2u;
    vf3_mem_set_u32(ram, R(14) + 60u, R(4));
    vf3_mem_set_u32(ram, R(14) + 28u, R(13));
    R(0) = 0x4cu;
    vf3_mem_set_u16(ram, R(14) + R(0), (uint16_t)R(3));
    R(0) = 0x46u;
    vf3_mem_set_u16(ram, R(14) + 0x46u, (uint16_t)R(11));
    R(0) = 0x44u;
    vf3_mem_set_u16(ram, R(14) + R(0), (uint16_t)R(11));
    vf3_mem_set_u32(ram, R(14) + 24u, R(12));
    R(3) = vf3_mem_u32(ram, R(14));
    pointed_object = R(3);
    vf3_mem_set_u32(ram, pointed_object + 36u, R(12));
    R(0) = R(13);
    goto done;

status_one:
    R(0) = 0x4cu;
    vf3_mem_set_u16(ram, R(14) + 0x4cu, (uint16_t)R(11));
    R(0) = R(12);
    goto done;

done:
    /* Restore PR, r10-r14 and the original stack pointer. */
    R(16) = pop(s, ram);
    R(10) = pop(s, ram);
    R(11) = pop(s, ram);
    R(12) = pop(s, ram);
    R(13) = pop(s, ram);
    R(14) = pop(s, ram);
    s->pc = R(16);
    return ram->oob == 0;
}
