/* cache_wb_stub.c - 0x8C062E8E  ocbwb @r4; rts.
 *
 * Operand-cache write-back of the line holding r4. The cache is not modelled (RAM is always coherent in the port), so the
 * instruction has no architectural effect: every register is left as it was and control returns to the caller. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

int vf3_cache_wb_stub_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    (void)ram;
    s->pc = R(VF3_REG_PR);
    return 1;
}
