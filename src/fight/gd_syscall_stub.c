/* gd_syscall_stub.c - 0x8C0430A0  the loader's GET_CMD_STAT syscall stub (0x8C0430B4, EXEC_SERVER, is the same code with
 * r7 = 2 and has no oracle case yet, so it is not registered).
 *
 * It loads r6 = 0 and r7 = 1, fetches the
 * BIOS entry from the pointer word at 0x8C0000BC into r0 and jumps to it, so the BIOS returns straight to the caller
 * with r4 / r5 as the arguments. The port makes that tail call as a guest call returning to the caller's pr.
 * Checked as the callee of the 0x8C0432DE wrapper replay (the stubs' own recorded exit is the BIOS entry). */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define BIOS_VECTOR_PTR 0x0C0000BCu

static int stub(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t call)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR);
    R(6) = 0;
    R(7) = call;
    R(0) = m32(ram, BIOS_VECTOR_PTR);
    if (!vf3_guest_call(s, ram, R(0) & 0x0FFFFFFFu, pr0)) return 0;
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}

int vf3_gd_get_cmd_stat_stub_entry(vf3_matrix_state *s, const vf3_ram_map *ram) { return stub(s, ram, 1); }

/* 0x8C0430B4 EXEC_SERVER: the same stub with r7 = 2, in the tail-jump form the jmp-boundary corpus records (pc = the BIOS
 * entry, pr and the stack untouched). */
int vf3_gd_exec_server_stub_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(6) = 0;
    R(7) = 2;
    R(0) = m32(ram, BIOS_VECTOR_PTR);
    s->pc = R(0);
    return 1;
}

/* 0x8C0434C8: calls 0x8C0430B4 and then forces r0 = 1 (the wrapper's `rts` delay slot). The BIOS call is made as a guest
 * call so the exec-server side effect happens, then the wrapper's return value and pr are restored. */
int vf3_gd_exec_server_wrapper_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR);
    R(6) = 0;
    R(7) = 2;
    R(0) = m32(ram, BIOS_VECTOR_PTR);
    if (!vf3_guest_call(s, ram, R(0) & 0x0FFFFFFFu, pr0)) return 0;
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    R(0) = 1;
    s->pc = pr0;
    return 1;
}

/* 0x8C0597CA: the render-callback slot's empty function (`rts`); it changes no register. */
int vf3_empty_rts_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    s->pc = R(VF3_REG_PR);
    return 1;
}

/* 0x8C0624BA: scan the 4096-record scene object table (0x0C16CF6C, stride 24) and clear bit 0 of the first
 * record whose address is r4. The original always walks the whole table, leaving r1=0x1000 and r5/r6 at the end. */
int vf3_scene_clear_flag_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t base = 0x0C16CF6Cu;
    const uint32_t target = R(4);
    for (uint32_t i = 0; i < 0x1000u; ++i) {
        const uint32_t rec = base + 24u * i;
        if (rec == target) {
            vf3_mem_set_u16(ram, rec, (uint16_t)(vf3_mem_u16(ram, rec) & 0xFFFEu));
            break;
        }
    }
    R(1) = 0x1000u;
    R(5) = base + 24u * 0x1000u;
    R(6) = base + 24u * 0x1000u;
    R(7) = 0x1000u;
    s->pc = R(VF3_REG_PR);
    return 1;
}
