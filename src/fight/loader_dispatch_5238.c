/* loader_dispatch_5238.c - 0x8C035238  the loader state machine's virtual-call prologue.
 *
 *     push pr;  obj = [0x0C0EA2EC];  fn = [ [obj + 20] + 64 ];  fn();   -> falls into 0x8C035248
 *
 * Reached by the tail jump of the vtable trampoline (0x8C035CBA). After the call the code continues at 0x8C035248
 * with the pushed pr still on the stack, so the port ends with pc = 0x8C035248 and the stack as the original leaves it. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

#define OBJ_PTR 0x0C0EA2ECu
#define CONTINUE_PC 0x0C035248u

int vf3_loader_dispatch_5238_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t pr0 = R(VF3_REG_PR);
    R(2) = OBJ_PTR;
    R(0) = 64;
    R(15) -= 4;
    w32(ram, R(15), pr0);
    R(3) = m32(ram, R(2));
    R(1) = m32(ram, R(3) + 20);
    R(0) = m32(ram, R(1) + R(0));
    if (!vf3_guest_call(s, ram, R(0) & 0x0FFFFFFFu, CONTINUE_PC)) return 0;
    s->pc = CONTINUE_PC;
    return 1;
}
